#include "font.h"
#include "fonts16.h"

Font Font16 =
{
	.RealWidth = 10,
	.Width = 16,
	.Height = 16,
	.XSpacing = 2,
	.Mirror = 0,
	.FontWidthBytesAtEndOfLine = 1,
	.FontTable = (const uint8_t*)FontTable16
};

/// Generated in TheDotFactory.exe

const uint16_t FontTable16[] = 
{
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, // <space>
	0x0000, 0x0000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0000, 0xc000, 0xc000, 0x0002, // !
	0x0000, 0xcc00, 0xcc00, 0xcc00, 0xcc00, 0xcc00, 0xcc00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0006, // "
	0x0660, 0x0660, 0x06e0, 0x0cc0, 0x0cc0, 0x3ff8, 0x3ff8, 0x0cc0, 0x1980, 0x1980, 0xffe0, 0xffe0, 0x1980, 0x3b00, 0x3300, 0x3300, 0x000d, // #
	0x0800, 0x0800, 0x3f00, 0x7f80, 0xc880, 0xc800, 0xc800, 0x7c00, 0x3f00, 0x0b80, 0x0980, 0x0980, 0x8b80, 0xff00, 0x7e00, 0x0800, 0x0009, // $
	0x60c0, 0x9180, 0x9180, 0x9300, 0x9300, 0x6600, 0x0600, 0x0c00, 0x0c00, 0x1800, 0x1980, 0x3240, 0x3240, 0x6240, 0x6240, 0xc180, 0x000a, // %
	0x1e00, 0x3f00, 0x7380, 0x6180, 0x6180, 0x7300, 0x3e60, 0x3c60, 0x6e60, 0xc760, 0xc3e0, 0xc1e0, 0xc0e0, 0xe0f0, 0x7fb8, 0x3e1c, 0x000e, // &
	0x0000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0002, // '
	0x3000, 0x3000, 0x6000, 0x6000, 0xe000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xe000, 0x6000, 0x6000, 0x3000, 0x3000, 0x0004, // (
	0xc000, 0xc000, 0x6000, 0x6000, 0x7000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x7000, 0x6000, 0x6000, 0xc000, 0xc000, 0x0004, // )
	0x0000, 0x0000, 0x0000, 0x1800, 0x9900, 0xdb00, 0x7e00, 0x1800, 0x7e00, 0xdb00, 0x9900, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0008, // *
	0x0000, 0x0000, 0x0000, 0x0000, 0x1800, 0x1800, 0x1800, 0xff00, 0xff00, 0x1800, 0x1800, 0x1800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0008, // +
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6000, 0x6000, 0x6000, 0xc000, 0xc000, 0x0003, // ,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfc00, 0xfc00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0006, // -
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc000, 0xc000, 0xc000, 0x0002, // .
	0x0600, 0x0600, 0x0c00, 0x0c00, 0x0c00, 0x1800, 0x1800, 0x1800, 0x3000, 0x3000, 0x3000, 0x6000, 0x6000, 0x6000, 0xc000, 0xc000, 0x0007, // /
	0x1e00, 0x3f00, 0x6180, 0x6180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x6180, 0x6180, 0x3f00, 0x1e00, 0x000a, // 0
	0x0c00, 0x0c00, 0x7c00, 0x7c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x0c00, 0x7f80, 0x7f80, 0x0009, // 1
	0x7e00, 0xff00, 0x8380, 0x0180, 0x0180, 0x0180, 0x0180, 0x0300, 0x0600, 0x0e00, 0x1c00, 0x3800, 0x7000, 0xc000, 0xffc0, 0xffc0, 0x000a, // 2
	0x7e00, 0xff00, 0x8380, 0x0180, 0x0180, 0x0300, 0x1e00, 0x1e00, 0x0300, 0x0180, 0x0180, 0x0180, 0x0180, 0x8300, 0xff00, 0x7c00, 0x0009, // 3
	0x0180, 0x0380, 0x0780, 0x0d80, 0x1980, 0x3180, 0x6180, 0xc180, 0xffe0, 0xffe0, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x000b, // 4
	0x7f80, 0x7f80, 0x6000, 0x6000, 0x6000, 0x6000, 0x7e00, 0x7f00, 0x0380, 0x0180, 0x0180, 0x0180, 0x0180, 0x8300, 0xff00, 0x7c00, 0x0009, // 5
	0x0f80, 0x1f80, 0x3800, 0x6000, 0x6000, 0xc000, 0xdf00, 0xff80, 0xe1c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xe0c0, 0x6180, 0x3f80, 0x1e00, 0x000a, // 6
	0xffc0, 0xffc0, 0x00c0, 0x0180, 0x0180, 0x0300, 0x0300, 0x0600, 0x0600, 0x0c00, 0x0c00, 0x1800, 0x1800, 0x3000, 0x3000, 0x6000, 0x000a, // 7
	0x3f00, 0x7f80, 0xe1c0, 0xc0c0, 0xc0c0, 0xe0c0, 0x7980, 0x3e00, 0x6780, 0xc1c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xe180, 0x7f80, 0x1e00, 0x000a, // 8
	0x1e00, 0x7f00, 0x6180, 0xc1c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xe1c0, 0x7fc0, 0x3ec0, 0x00c0, 0x0180, 0x0180, 0x0700, 0x7e00, 0x7c00, 0x000a, // 9
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc000, 0xc000, 0x0000, 0x0000, 0xc000, 0xc000, 0x0000, 0x0000, 0x0002, // :
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x6000, 0x6000, 0x0000, 0x6000, 0x6000, 0x6000, 0xc000, 0x0003, // ;
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x01e0, 0x07c0, 0x3e00, 0xf800, 0xc000, 0xf800, 0x3e00, 0x07c0, 0x01e0, 0x0020, 0x000b, // <
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0x0000, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0008, // =
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8000, 0xf000, 0x7c00, 0x0f80, 0x03e0, 0x0060, 0x03e0, 0x0f80, 0x7c00, 0xf000, 0x8000, 0x000b, // >
	0x7c00, 0xfe00, 0x8700, 0x0300, 0x0300, 0x0300, 0x0600, 0x0e00, 0x3c00, 0x3000, 0x3000, 0x3000, 0x3000, 0x0000, 0x3000, 0x3000, 0x0008, // ?
	0x1fc0, 0x3ff0, 0x6038, 0xc01c, 0xc7cc, 0xcfce, 0xd8c6, 0xd8c6, 0xd8c6, 0xd8c6, 0xd8c6, 0xcfc6, 0xc7fc, 0x60fc, 0x3000, 0x1c00, 0x000f, // @
	0x0700, 0x0700, 0x0d80, 0x0d80, 0x0d80, 0x18c0, 0x18c0, 0x18c0, 0x3060, 0x3060, 0x3fe0, 0x7ff0, 0x6030, 0x6030, 0xe038, 0xc018, 0x000d, // A
	0xfe00, 0xff80, 0xc180, 0xc180, 0xc180, 0xc300, 0xfe00, 0xff80, 0xc180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc180, 0xff80, 0xfe00, 0x000a, // B
	0x0f80, 0x3fe0, 0x3860, 0x6020, 0x6000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xe000, 0x6020, 0x7860, 0x3fe0, 0x0f80, 0x000b, // C
	0xfe00, 0xff00, 0xc380, 0xc0c0, 0xc0c0, 0xc060, 0xc060, 0xc060, 0xc060, 0xc060, 0xc060, 0xc0c0, 0xc0c0, 0xc380, 0xff00, 0xfe00, 0x000b, // D
	0xff80, 0xff80, 0xc000, 0xc000, 0xc000, 0xc000, 0xff00, 0xff00, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xff80, 0xff80, 0x0009, // E
	0xff80, 0xff80, 0xc000, 0xc000, 0xc000, 0xc000, 0xff80, 0xff80, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0009, // F
	0x0fc0, 0x1ff0, 0x3870, 0x6010, 0x6000, 0xc000, 0xc000, 0xc000, 0xc1f0, 0xc1f0, 0xc030, 0x6030, 0x6030, 0x3830, 0x3ff0, 0x0fc0, 0x000c, // G
	0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xffc0, 0xffc0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x000a, // H
	0xfc00, 0xfc00, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0xfc00, 0xfc00, 0x0006, // I
	0x3f00, 0x3f00, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0700, 0xfe00, 0xfc00, 0x0008, // J
	0xc1c0, 0xc380, 0xc700, 0xc600, 0xcc00, 0xdc00, 0xf800, 0xf000, 0xf800, 0xdc00, 0xcc00, 0xc600, 0xc700, 0xc300, 0xc180, 0xc1c0, 0x000a, // K
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xff00, 0xff00, 0x0008, // L
	0xe070, 0xe070, 0xf0f0, 0xf0f0, 0xd0b0, 0xd9b0, 0xd930, 0xc930, 0xcf30, 0xc630, 0xc630, 0xc630, 0xc030, 0xc030, 0xc030, 0xc030, 0x000c, // M
	0xe0c0, 0xe0c0, 0xf0c0, 0xd0c0, 0xd8c0, 0xd8c0, 0xc8c0, 0xccc0, 0xc4c0, 0xc6c0, 0xc6c0, 0xc3c0, 0xc3c0, 0xc1c0, 0xc1c0, 0xc1c0, 0x000a, // N
	0x0f80, 0x3fe0, 0x7070, 0x6030, 0xe038, 0xc018, 0xc018, 0xc018, 0xc018, 0xc018, 0xc018, 0xe038, 0x6030, 0x7070, 0x3fe0, 0x0f80, 0x000d, // O
	0xfe00, 0xff80, 0xc180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc180, 0xff00, 0xfe00, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x000a, // P
	0x0f80, 0x3fe0, 0x7070, 0x6030, 0xe038, 0xc018, 0xc018, 0xc018, 0xc018, 0xc018, 0xc018, 0xe038, 0x6070, 0x7070, 0x3ff8, 0x0f98, 0x000d, // Q
	0xfe00, 0xff00, 0xc380, 0xc180, 0xc180, 0xc180, 0xc180, 0xc300, 0xfe00, 0xfc00, 0xce00, 0xc700, 0xc300, 0xc180, 0xc1c0, 0xc0e0, 0x000b, // R
	0x3f00, 0x7f80, 0xe080, 0xc000, 0xc000, 0xc000, 0xf000, 0x7e00, 0x1f80, 0x01c0, 0x00c0, 0x00c0, 0x80c0, 0xc180, 0xff80, 0x3e00, 0x000a, // S
	0xfff0, 0xfff0, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x000c, // T
	0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xc030, 0xe070, 0x70e0, 0x3fc0, 0x1f80, 0x000c, // U
	0xc018, 0x6030, 0x6030, 0x6030, 0x3060, 0x3060, 0x3060, 0x18c0, 0x18c0, 0x18c0, 0x0d80, 0x0d80, 0x0d80, 0x0700, 0x0700, 0x0700, 0x000d, // V
	0xc183, 0xc183, 0xe187, 0xe187, 0x63c6, 0x63c6, 0x63c6, 0x6246, 0x6666, 0x6666, 0x766c, 0x342c, 0x3c3c, 0x3c3c, 0x1c38, 0x1818, 0x0010, // W
	0xc030, 0x6060, 0x30c0, 0x30c0, 0x1980, 0x1980, 0x0f00, 0x0600, 0x0600, 0x0f00, 0x1980, 0x1980, 0x30c0, 0x30c0, 0x6060, 0xc030, 0x000c, // X
	0xe070, 0x6060, 0x70e0, 0x30c0, 0x3980, 0x1980, 0x0f00, 0x0f00, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x000c, // Y
	0xffc0, 0xffc0, 0x00c0, 0x0180, 0x0300, 0x0300, 0x0600, 0x0c00, 0x0c00, 0x1800, 0x3000, 0x3000, 0x6000, 0xc000, 0xffc0, 0xffc0, 0x000a, // Z
	0xf800, 0xf800, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xf800, 0xf800, 0x0005, // [
	0xc000, 0xc000, 0x6000, 0x6000, 0x6000, 0x3000, 0x3000, 0x3000, 0x1800, 0x1800, 0x1800, 0x0c00, 0x0c00, 0x0c00, 0x0600, 0x0600, 0x0007, // \
	0xf800, 0xf800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0xf800, 0xf800, 0x0005, // ]
	0x1c00, 0x1c00, 0x3600, 0x6300, 0x6300, 0xc180, 0x8080, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0009, // ^
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0x0008, // _
	0xc000, 0x6000, 0x6000, 0x3000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004, // `
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7e00, 0x7f00, 0x0180, 0x0180, 0x1f80, 0x7f80, 0xe180, 0xc180, 0xc380, 0xff80, 0x3d80, 0x0009, // a
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xcf00, 0xff80, 0xe180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc180, 0xff80, 0x000a, // b
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1f00, 0x7f80, 0x6080, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x6080, 0x7f80, 0x1f00, 0x0009, // c
	0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x1ec0, 0x7fc0, 0x60c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x61c0, 0x7fc0, 0x000a, // d
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1f00, 0x7f80, 0x61c0, 0xc0c0, 0xffc0, 0xffc0, 0xc000, 0xc000, 0x6040, 0x7fc0, 0x1f80, 0x000a, // e
	0x1e00, 0x3e00, 0x7000, 0x6000, 0x6000, 0x6000, 0xfc00, 0xfc00, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x0007, // f
	0x0000, 0x1ec0, 0x3fc0, 0x60c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x61c0, 0x7fc0, 0x3ec0, 0x00c0, 0x4180, 0x7f80, 0x7e00, 0x000a, // g
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xde00, 0xff00, 0xe380, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0x0009, // h
	0x0000, 0x0000, 0xc000, 0xc000, 0x0000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0002, // i
	0x1800, 0x1800, 0x0000, 0x7800, 0x7800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0xf000, 0x0005, // j
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc300, 0xc600, 0xcc00, 0xd800, 0xf000, 0xf800, 0xd800, 0xcc00, 0xc600, 0xc700, 0x0008, // k
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0002, // l
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xde3c, 0xff7e, 0xe3c7, 0xc183, 0xc183, 0xc183, 0xc183, 0xc183, 0xc183, 0xc183, 0xc183, 0x0010, // m
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xde00, 0xff00, 0xe380, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0x0009, // n
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1e00, 0x7f80, 0x6180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x6180, 0x7f80, 0x1e00, 0x000a, // o
	0x0000, 0xdf00, 0xff80, 0xe180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc180, 0xff80, 0xfe00, 0xc000, 0xc000, 0xc000, 0xc000, 0x000a, // p
	0x0000, 0x1ec0, 0x7fc0, 0x60c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x61c0, 0x7fc0, 0x3ec0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x000a, // q
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xce00, 0xfe00, 0xe000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0007, // r
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3e00, 0x7f00, 0xc100, 0xc000, 0xf000, 0x7e00, 0x1f00, 0x0300, 0x8300, 0xfe00, 0x7c00, 0x0008, // s
	0x0000, 0x0000, 0x6000, 0x6000, 0x6000, 0xfc00, 0xfc00, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x7c00, 0x3c00, 0x0006, // t
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xe380, 0x7f80, 0x3d80, 0x0009, // u
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc180, 0x6300, 0x6300, 0x6300, 0x3600, 0x3600, 0x3600, 0x1c00, 0x1c00, 0x1c00, 0x0800, 0x0009, // v
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc186, 0xc386, 0x638c, 0x62cc, 0x66cc, 0x66cc, 0x3448, 0x3c78, 0x3c78, 0x1830, 0x1830, 0x000f, // w
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc180, 0x6300, 0x3600, 0x3600, 0x1c00, 0x1c00, 0x1c00, 0x3600, 0x3600, 0x6300, 0xc180, 0x0009, // x
	0x0000, 0xc180, 0x6300, 0x6300, 0x6300, 0x3600, 0x3600, 0x3600, 0x1c00, 0x1c00, 0x1c00, 0x1800, 0x1800, 0x3800, 0x3000, 0x3000, 0x0009, // y
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xfe00, 0xfe00, 0x0c00, 0x0c00, 0x1800, 0x3800, 0x3000, 0x6000, 0xe000, 0xfe00, 0xfe00, 0x0007, // z
	0x1800, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x6000, 0xc000, 0xc000, 0x6000, 0x3000, 0x3000, 0x3000, 0x3000, 0x3000, 0x1800, 0x0005, // {
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x0002, // |
	0xc000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x3000, 0x1800, 0x1800, 0x3000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0xc000, 0x0005, // }
	0x3c18, 0x7e18, 0xe738, 0xc3f0, 0xc1e0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000d, // ~
	0x0700, 0x0700, 0x0d80, 0x0d80, 0x0d80, 0x18c0, 0x18c0, 0x18c0, 0x3060, 0x3fe0, 0x3fe0, 0x6030, 0x6030, 0x6030, 0x6070, 0x00c0, 0x000c, // �
	0x0380, 0x0700, 0x0f80, 0x3fe0, 0x7860, 0x6020, 0xe000, 0xc000, 0xc000, 0xc000, 0xc000, 0xe000, 0x6020, 0x7860, 0x3fe0, 0x0f80, 0x000b, // �
	0xff80, 0xff80, 0xc000, 0xc000, 0xc000, 0xc000, 0xff00, 0xff00, 0xc000, 0xc000, 0xc000, 0xc000, 0xff80, 0xff80, 0x0e00, 0x0700, 0x0009, // �
	0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xcc00, 0xfc00, 0xf000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xff00, 0xff00, 0x0008, // �
	0xe6c0, 0xecc0, 0xf0c0, 0xd0c0, 0xd8c0, 0xd8c0, 0xc8c0, 0xccc0, 0xc4c0, 0xc6c0, 0xc6c0, 0xc3c0, 0xc3c0, 0xc1c0, 0xc1c0, 0xc1c0, 0x000a, // �
	0x0380, 0x0700, 0x0fc0, 0x3fe0, 0x7070, 0x6030, 0xe038, 0xc018, 0xc018, 0xc018, 0xc018, 0xe038, 0x6030, 0x7070, 0x3fe0, 0x0f80, 0x000d, // �
	0x0e00, 0x1c00, 0x3e00, 0x7f00, 0xe180, 0xc080, 0xc000, 0xf000, 0x7e00, 0x1f80, 0x01c0, 0x00c0, 0x80c0, 0xc1c0, 0x7f80, 0x3f00, 0x000a, // �
	0x0c00, 0x0c00, 0xffc0, 0xffc0, 0x0180, 0x0300, 0x0300, 0x0600, 0x0c00, 0x0c00, 0x1800, 0x3000, 0x3000, 0x6000, 0xffc0, 0xffc0, 0x000a, // �
	0x0700, 0x0e00, 0xffc0, 0xffc0, 0x0180, 0x0300, 0x0300, 0x0600, 0x0c00, 0x0c00, 0x1800, 0x3000, 0x3000, 0x6000, 0xffc0, 0xffc0, 0x000a, // �
	0x0000, 0x0000, 0x0000, 0x7e00, 0x7f00, 0x0180, 0x0180, 0x1f80, 0x7f80, 0xe180, 0xc180, 0xc380, 0xff80, 0x3d80, 0x0300, 0x0600, 0x0009, // �
	0x0000, 0x0000, 0x0700, 0x0e00, 0x0000, 0x1f00, 0x7f80, 0x6080, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0x6080, 0x7f80, 0x1f00, 0x0009, // �
	0x0000, 0x0000, 0x0000, 0x1f00, 0x7f80, 0x61c0, 0xc0c0, 0xffc0, 0xffc0, 0xc000, 0xc000, 0x6040, 0x7fc0, 0x1f80, 0x0700, 0x0380, 0x000a, // �
	0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6800, 0x7800, 0xf000, 0xe000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x6000, 0x0005, // �
	0x0000, 0x0000, 0x0e00, 0x1c00, 0x0000, 0xde00, 0xff00, 0xe380, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0xc180, 0x0009, // �
	0x0000, 0x0000, 0x0700, 0x0e00, 0x0000, 0x1e00, 0x7f80, 0x6180, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0xc0c0, 0x6180, 0x7f80, 0x1e00, 0x000a, // �
	0x0000, 0x0000, 0x0e00, 0x1c00, 0x0000, 0x3e00, 0x7f00, 0xc100, 0xc000, 0xf000, 0x7e00, 0x1f00, 0x0300, 0x8300, 0xfe00, 0x7c00, 0x0008, // �
	0x0000, 0x0000, 0x1800, 0x1800, 0x0000, 0xfe00, 0xfe00, 0x0c00, 0x0c00, 0x1800, 0x3800, 0x3000, 0x6000, 0xe000, 0xfe00, 0xfe00, 0x0007, // �
	0x0000, 0x0000, 0x1c00, 0x3800, 0x0000, 0xfe00, 0xfe00, 0x0c00, 0x0c00, 0x1800, 0x3800, 0x3000, 0x6000, 0xe000, 0xfe00, 0xfe00, 0x0007, // �
};
