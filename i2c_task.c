// #define DEBUG_I2C
// #define DEBUG_LEDS

	/* Freescale includes. */
#include <fsl_device_registers.h>
#include <fsl_debug_console.h>
#include <fsl_i2c.h>
#include <fsl_i2c_freertos.h>

	/* FreeRTOS kernel includes. */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>

	/* Board config */
#include "board_cfg/board.h"
#include "board_cfg/clock_config.h"
#include "board_cfg/pin_mux.h"

#include "i2c_task.h"
#include "ssd1362_i2c_driver.h"

// #define I2C_DELAY 750

static uint8_t g_master_buff[I2C_DATA_LENGTH];
static i2c_master_handle_t *g_m_handle;

static i2c_rtos_handle_t master_rtos_handle;
static i2c_master_config_t masterConfig;
static i2c_master_transfer_t masterXfer;
static uint32_t sourceClock;

void i2c_task_initialize(void)
{
	CLOCK_SetRootMux(I2C_MASTER_CLK_ROOT, I2C_MASTER_ROOT_MUX_SYS_PLL_DIV); /* Set I2C source to SysPLL1 Div5 160MHZ */
	CLOCK_SetRootDivider(I2C_MASTER_CLK_ROOT, 1U, 10U);                  /* Set root clock to 160MHZ / 10 = 16MHZ */

	NVIC_SetPriority(I2C_MASTER_IRQN, 3);

	/*
		masterConfig.baudRate_Bps = 100000U;
		masterConfig.enableStopHold = false;
		masterConfig.glitchFilterWidth = 0U;
		masterConfig.enableMaster = true;
	*/
	I2C_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate_Bps = I2C_BAUDRATE;
	sourceClock = I2C_MASTER_CLK_FREQ;

	status_t status = I2C_RTOS_Init(&master_rtos_handle, I2C_MASTER, &masterConfig, sourceClock);
	if (status != kStatus_Success)
	{
		PRINTF("I2C master: error during init, 0x%x\r\n", status);
	}

	g_m_handle = &master_rtos_handle.drv_handle;

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = I2C_MASTER_SLAVE_ADDR_7BIT;
	masterXfer.direction      = kI2C_Write;
	// masterXfer.subaddress     = 0x11; // 10 - register autoincrement, 01 - write from register
	// masterXfer.subaddressSize = 1;
masterXfer.subaddressSize = 0;
	masterXfer.data           = g_master_buff;
	masterXfer.dataSize       = 0;
	masterXfer.flags          = kI2C_TransferDefaultFlag;

PRINTF("I2C master: init\r\n"); // $$
}

void i2c_task_task(void *pvParameters)
{
	PRINTF("I2C task started.\r\n");

	ssd1362_i2c_driver_initialize(true);

	while (true)
	{
		//i2c_task_write_command();
		// ssd1362_i2c_driver();

		vTaskDelay(pdMS_TO_TICKS(20));
// vTaskDelay(pdMS_TO_TICKS(2000)); // $$
	}

	vTaskSuspend(NULL);
}

bool i2c_task_write_command(uint8_t *command, size_t command_size)
{
	int j = 0;
	for (int i = 0; i < command_size; i++)		// $$ bezsensowne kopiowanie
		g_master_buff[j++] = command[i];

#ifdef DEBUG_I2C
#endif

	masterXfer.direction = kI2C_Write;
	masterXfer.dataSize = command_size;

// PRINTF("I2C master: before write %d %x %x\r\n", j, g_master_buff[0], g_master_buff[1]);
	status_t status = I2C_RTOS_Transfer(&master_rtos_handle, &masterXfer);
	if (status != kStatus_Success)
	{
		PRINTF("I2C master: error during write transaction, 0x%x\r\n", status);
		return false;
	}

	// PRINTF("I2C master: wrote bytes\r\n");
#ifdef DEBUG_I2C
#endif
	return true;
}
