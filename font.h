#ifndef __FONT_H
#define __FONT_H

#include <fsl_device_registers.h>

struct Font
{
	const uint8_t RealWidth;
	const uint8_t Width;
	const uint8_t Height;
	const uint8_t XSpacing;
	const uint8_t Mirror;
	const uint8_t FontWidthBytesAtEndOfLine;
	const uint16_t* FontTable;
};

#endif /* __FONT_H */
