#ifndef __FONT_H
#define __FONT_H

#include <fsl_device_registers.h>

typedef struct
{
	const uint8_t RealWidth;
	const uint8_t RealHeight;
	const uint8_t Width;
	const uint8_t Height;
	const uint8_t XSpacing;
	const uint8_t YSpacing;
	const uint8_t Mirror;
	const uint8_t FontWidthBytesAtEndOfLine;
	const uint8_t Colors;
	const uint8_t* FontTable;
	const uint8_t* FontTableWidth;
} Font;

#endif /* __FONT_H */
