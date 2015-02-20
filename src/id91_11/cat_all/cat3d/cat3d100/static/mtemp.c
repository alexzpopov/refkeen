#include "be_cross.h"

static unsigned char mtemp_tmp[] = {
 BE_Cross_SwapGroup16LE(0xcd, 0xab)
 BE_Cross_SwapGroup32LE(0x85, 0x01, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x53, 0x03, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x20, 0x06, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x6f, 0x08, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x0d, 0x0b, 0x00, 0x00) BE_Cross_SwapGroup32LE(0xa2, 0x0d, 0x00, 0x00) BE_Cross_SwapGroup32LE(0xaf, 0x10, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x9f, 0x13, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0xc4, 0x14, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x82, 0x17, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x61, 0x1a, 0x00, 0x00) BE_Cross_SwapGroup32LE(0xf8, 0x1c, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x8b, 0x20, 0x00, 0x00) BE_Cross_SwapGroup32LE(0xbf, 0x23, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x78, 0x26, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x3e, 0x29, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x59, 0x2c, 0x00, 0x00) BE_Cross_SwapGroup32LE(0xac, 0x2e, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x8a, 0x31, 0x00, 0x00) BE_Cross_SwapGroup32LE(0xa6, 0x37, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00) BE_Cross_SwapGroup32LE(0x00, 0x00, 0x00, 0x00)
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff,
 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

unsigned char *maphead = mtemp_tmp;
