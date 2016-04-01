#include "common.h"
#include "memgfx.h"
#include "gemfont.h"

/*	formerly known as sailfnt.c mgSmallFont() now mgSmallFont()	*/
static char const rcsid[] = "$Id: mgSail8.c,v 1.2 2010/03/31 00:07:46 kent Exp $";

/* static char sail_name[] = "SAIL.FNT"; */

static UBYTE sail_data[] = {
	0x00,0xc5, 0x14,0x23, 0xe6,0x04, 0x11,0x00, 
	0x00,0x00, 0x00,0x02, 0x30,0x87, 0x1c,0x13, 
	0xe7,0x3e, 0x71,0xc0, 0x00,0x00, 0x00,0x1c, 
	0x71,0xcf, 0x1c,0xf3, 0xef,0x9c, 0x89,0xc0, 
	0xa2,0x82, 0x28,0x9c, 0xf1,0xcf, 0x1c,0xfa, 
	0x28,0xa2, 0x8a,0x27, 0x9c,0x81, 0xc2,0x00, 
	0x20,0x08, 0x00,0x08, 0x03,0x80, 0x80,0x41, 
	0x10,0x30, 0x00,0x00, 0x00,0x00, 0x00,0x40, 
	0x00,0x00, 0x00,0x00, 0x0c,0x21, 0x80,0x00, 
	0x00,0xc5, 0x3e,0x7b, 0x2a,0x04, 0x20,0x8a, 
	0x88,0x00, 0x00,0x04, 0x49,0x88, 0xa2,0x32, 
	0x08,0x02, 0x8a,0x22, 0x04,0x10, 0x04,0x22, 
	0x8a,0x28, 0xa2,0x8a, 0x08,0x22, 0x88,0x80, 
	0xa4,0x83, 0x6c,0xa2, 0x8a,0x28, 0xa2,0x22, 
	0x28,0xa2, 0x52,0x20, 0x90,0x40, 0x47,0x00, 
	0x21,0xcb, 0x0e,0x69, 0xc4,0x1e, 0xb0,0x00, 
	0x12,0x13, 0x4b,0x1c, 0xb1,0xab, 0x1e,0xfa, 
	0x28,0xa2, 0x8a,0x2f, 0x90,0x20, 0x44,0x00, 
	0x00,0xc5, 0x14,0xa0, 0x44,0x08, 0x40,0x47, 
	0x08,0x00, 0x00,0x04, 0x58,0x80, 0x8c,0x53, 
	0xcf,0x04, 0x72,0x22, 0x04,0x23, 0xe2,0x02, 
	0xbb,0xef, 0x20,0x8b, 0xcf,0x20, 0xf8,0x80, 
	0xa8,0x82, 0xaa,0xa2, 0xf2,0x2f, 0x18,0x22, 
	0x28,0xaa, 0x21,0xc1, 0x10,0x20, 0x4a,0x80, 
	0x10,0x2c, 0x90,0x9a, 0x2f,0x22, 0xc8,0xc3, 
	0x14,0x12, 0xac,0xa2, 0xca,0x6c, 0xa0,0x42, 
	0x28,0xa2, 0x52,0x21, 0x10,0x20, 0x4a,0x80, 
	0x00,0xc0, 0x14,0x70, 0x8a,0x80, 0x40,0x4d, 
	0xbe,0x03, 0xe0,0x08, 0x68,0x87, 0x02,0xf8, 
	0x28,0x84, 0x89,0xe0, 0x00,0x40, 0x01,0x0c, 
	0xba,0x28, 0xa0,0x8a, 0x08,0x26, 0x88,0x80, 
	0xb8,0x82, 0xa9,0xa2, 0x82,0xaa, 0x04,0x22, 
	0x25,0x2a, 0x50,0x82, 0x10,0x20, 0x42,0x00, 
	0x01,0xe8, 0x90,0x8b, 0xe4,0x22, 0x88,0x41, 
	0x18,0x12, 0xa8,0xa2, 0x8a,0x28, 0x1c,0x42, 
	0x25,0x2a, 0x22,0x22, 0x20,0x20, 0x21,0x00, 
	0x00,0x00, 0x3e,0x29, 0x69,0x00, 0x40,0x47, 
	0x08,0x20, 0x02,0x08, 0x48,0x88, 0x22,0x12, 
	0x28,0x88, 0x88,0x22, 0x04,0x23, 0xe2,0x00, 
	0x82,0x28, 0xa2,0x8a, 0x08,0x22, 0x88,0x88, 
	0xa4,0x82, 0x28,0xa2, 0x82,0x69, 0x22,0x22, 
	0x25,0x36, 0x88,0x84, 0x10,0x10, 0x42,0x00, 
	0x02,0x2c, 0x90,0x9a, 0x04,0x1c, 0x88,0x41, 
	0x14,0x12, 0xa8,0xa2, 0xca,0x68, 0x02,0x42, 
	0x65,0x2a, 0x51,0xe4, 0x10,0x20, 0x40,0x00, 
	0x00,0xc0, 0x14,0xf2, 0x6e,0x80, 0x20,0x8a, 
	0x88,0x20, 0x02,0x10, 0x31,0xcf, 0x9c,0x11, 
	0xc7,0x08, 0x71,0xc2, 0x04,0x10, 0x04,0x08, 
	0x72,0x2f, 0x1c,0xf3, 0xe8,0x1c, 0x89,0xc7, 
	0x22,0xfa, 0x28,0x9c, 0x81,0xc8, 0x9c,0x21, 
	0xc2,0x22, 0x88,0x87, 0x90,0x08, 0x42,0x00, 
	0x01,0xab, 0x0e,0x69, 0xc4,0x02, 0x88,0x41, 
	0x12,0x12, 0xa8,0x9c, 0xb1,0xa8, 0x3c,0x31, 
	0xa2,0x14, 0x88,0x2f, 0x90,0x20, 0x40,0x00, 
	0x00,0x00, 0x00,0x20, 0x00,0x00, 0x11,0x00, 
	0x00,0x40, 0x00,0x00, 0x00,0x00, 0x00,0x00, 
	0x00,0x00, 0x00,0x00, 0x08,0x00, 0x00,0x00, 
	0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 
	0x00,0x00, 0x00,0x00, 0x00,0x20, 0x00,0x00, 
	0x00,0x00, 0x00,0x00, 0x1c,0x01, 0xc0,0x3e, 
	0x00,0x00, 0x00,0x00, 0x00,0x3c, 0x00,0x06, 
	0x00,0x00, 0x00,0x00, 0x80,0x20, 0x00,0x00, 
	0x00,0x00, 0x01,0xc0, 0x0c,0x21, 0x80,0x00, 
	};

static WORD sail_ch_ofst[] = {
0, 6, 12, 18, 24, 30, 36, 42,
48, 54, 60, 66, 72, 78, 84, 90,
96, 102, 108, 114, 120, 126, 132, 138,
144, 150, 156, 162, 168, 174, 180, 186,
192, 198, 204, 210, 216, 222, 228, 234,
240, 246, 252, 258, 264, 270, 276, 282,
288, 294, 300, 306, 312, 318, 324, 330,
336, 342, 348, 354, 360, 366, 372, 378,
384, 390, 396, 402, 408, 414, 420, 426,
432, 438, 444, 450, 456, 462, 468, 474,
480, 486, 492, 498, 504, 510, 516, 522,
528, 534, 540, 546, 552, 558, 564, 570,
576, 582, 588,
};

static struct font_hdr sail_font =
	{
	STPROP, 0, "SAIL.FNT", ' ',127,  
	0,0,0,0,0,	/* *_dist */
	6, 6,  /*widths... */
	0,0,0,0,0,0,	/* through skew_m */
	0, /*flags */
	NULL, /* hz_ofst */
	sail_ch_ofst,
	sail_data,
	72, 7,	/* frm_wdt,frm_hgt */
	NULL,	/* next font */
	0, -1,	/* x/y offset */
	9,	/* lineHeight */
	9,	/* psHeight */
	};

MgFont *mgSmallFont()
{
return &sail_font;
}

