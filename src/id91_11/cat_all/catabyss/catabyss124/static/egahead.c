#include "be_cross.h"

static unsigned char EGAHEAD_ABS[] = {
 BE_Cross_SwapGroup24LE(0x00, 0x00, 0x00) BE_Cross_SwapGroup24LE(0xcf, 0x02, 0x00) BE_Cross_SwapGroup24LE(0xd7, 0x02, 0x00) BE_Cross_SwapGroup24LE(0xe8, 0x02, 0x00) BE_Cross_SwapGroup24LE(0xd7, 0x07, 0x00)
 BE_Cross_SwapGroup24LE(0x48, 0x33, 0x00) BE_Cross_SwapGroup24LE(0xbc, 0x4c, 0x00) BE_Cross_SwapGroup24LE(0x97, 0x50, 0x00) BE_Cross_SwapGroup24LE(0xca, 0x55, 0x00) BE_Cross_SwapGroup24LE(0x29, 0x5e, 0x00)
 BE_Cross_SwapGroup24LE(0xa8, 0x66, 0x00) BE_Cross_SwapGroup24LE(0x7d, 0x6e, 0x00) BE_Cross_SwapGroup24LE(0x5c, 0x77, 0x00) BE_Cross_SwapGroup24LE(0xe0, 0x80, 0x00) BE_Cross_SwapGroup24LE(0x86, 0x88, 0x00)
 BE_Cross_SwapGroup24LE(0xda, 0x90, 0x00) BE_Cross_SwapGroup24LE(0x2f, 0x98, 0x00) BE_Cross_SwapGroup24LE(0xb0, 0x9a, 0x00) BE_Cross_SwapGroup24LE(0xbd, 0x9a, 0x00) BE_Cross_SwapGroup24LE(0xac, 0x9d, 0x00)
 BE_Cross_SwapGroup24LE(0xa7, 0xa0, 0x00) BE_Cross_SwapGroup24LE(0x97, 0xa3, 0x00) BE_Cross_SwapGroup24LE(0x32, 0xa6, 0x00) BE_Cross_SwapGroup24LE(0xa5, 0xa8, 0x00) BE_Cross_SwapGroup24LE(0x38, 0xaa, 0x00)
 BE_Cross_SwapGroup24LE(0x73, 0xaa, 0x00) BE_Cross_SwapGroup24LE(0xaa, 0xaa, 0x00) BE_Cross_SwapGroup24LE(0xdd, 0xaa, 0x00) BE_Cross_SwapGroup24LE(0x11, 0xab, 0x00) BE_Cross_SwapGroup24LE(0x45, 0xab, 0x00)
 BE_Cross_SwapGroup24LE(0x52, 0xab, 0x00) BE_Cross_SwapGroup24LE(0xd2, 0xae, 0x00) BE_Cross_SwapGroup24LE(0x4f, 0xb2, 0x00) BE_Cross_SwapGroup24LE(0xcc, 0xb5, 0x00) BE_Cross_SwapGroup24LE(0x62, 0xb9, 0x00)
 BE_Cross_SwapGroup24LE(0xda, 0xbc, 0x00) BE_Cross_SwapGroup24LE(0x00, 0xc0, 0x00) BE_Cross_SwapGroup24LE(0x4c, 0xc3, 0x00) BE_Cross_SwapGroup24LE(0x26, 0xc7, 0x00) BE_Cross_SwapGroup24LE(0x38, 0xcb, 0x00)
 BE_Cross_SwapGroup24LE(0xea, 0xcd, 0x00) BE_Cross_SwapGroup24LE(0xd9, 0xd0, 0x00) BE_Cross_SwapGroup24LE(0xa1, 0xd3, 0x00) BE_Cross_SwapGroup24LE(0x52, 0xd6, 0x00) BE_Cross_SwapGroup24LE(0x0c, 0xd9, 0x00)
 BE_Cross_SwapGroup24LE(0xab, 0xdb, 0x00) BE_Cross_SwapGroup24LE(0xa5, 0xde, 0x00) BE_Cross_SwapGroup24LE(0x4e, 0xe1, 0x00) BE_Cross_SwapGroup24LE(0xab, 0xe3, 0x00) BE_Cross_SwapGroup24LE(0x1b, 0xe6, 0x00)
 BE_Cross_SwapGroup24LE(0xc0, 0xe8, 0x00) BE_Cross_SwapGroup24LE(0xf8, 0xe9, 0x00) BE_Cross_SwapGroup24LE(0xdf, 0xeb, 0x00) BE_Cross_SwapGroup24LE(0xf2, 0xee, 0x00) BE_Cross_SwapGroup24LE(0x88, 0xf2, 0x00)
 BE_Cross_SwapGroup24LE(0xef, 0xf6, 0x00) BE_Cross_SwapGroup24LE(0x47, 0xfa, 0x00) BE_Cross_SwapGroup24LE(0xa1, 0xfd, 0x00) BE_Cross_SwapGroup24LE(0xd4, 0x00, 0x01) BE_Cross_SwapGroup24LE(0x36, 0x04, 0x01)
 BE_Cross_SwapGroup24LE(0x4b, 0x08, 0x01) BE_Cross_SwapGroup24LE(0x00, 0x0d, 0x01) BE_Cross_SwapGroup24LE(0x17, 0x12, 0x01) BE_Cross_SwapGroup24LE(0xc6, 0x15, 0x01) BE_Cross_SwapGroup24LE(0x9a, 0x19, 0x01)
 BE_Cross_SwapGroup24LE(0x96, 0x1c, 0x01) BE_Cross_SwapGroup24LE(0x75, 0x1e, 0x01) BE_Cross_SwapGroup24LE(0xf9, 0x22, 0x01) BE_Cross_SwapGroup24LE(0xb7, 0x27, 0x01) BE_Cross_SwapGroup24LE(0x69, 0x2c, 0x01)
 BE_Cross_SwapGroup24LE(0x52, 0x31, 0x01) BE_Cross_SwapGroup24LE(0xc7, 0x34, 0x01) BE_Cross_SwapGroup24LE(0x40, 0x38, 0x01) BE_Cross_SwapGroup24LE(0xbd, 0x3b, 0x01) BE_Cross_SwapGroup24LE(0xd8, 0x3e, 0x01)
 BE_Cross_SwapGroup24LE(0x6e, 0x41, 0x01) BE_Cross_SwapGroup24LE(0x75, 0x44, 0x01) BE_Cross_SwapGroup24LE(0xe9, 0x46, 0x01) BE_Cross_SwapGroup24LE(0xf5, 0x48, 0x01) BE_Cross_SwapGroup24LE(0x13, 0x4a, 0x01)
 BE_Cross_SwapGroup24LE(0x24, 0x4b, 0x01) BE_Cross_SwapGroup24LE(0x39, 0x4d, 0x01) BE_Cross_SwapGroup24LE(0x9f, 0x4f, 0x01) BE_Cross_SwapGroup24LE(0x60, 0x52, 0x01) BE_Cross_SwapGroup24LE(0x84, 0x55, 0x01)
 BE_Cross_SwapGroup24LE(0x8c, 0x58, 0x01) BE_Cross_SwapGroup24LE(0x98, 0x5b, 0x01) BE_Cross_SwapGroup24LE(0xaa, 0x5e, 0x01) BE_Cross_SwapGroup24LE(0xa6, 0x61, 0x01) BE_Cross_SwapGroup24LE(0x6b, 0x64, 0x01)
 BE_Cross_SwapGroup24LE(0x4f, 0x67, 0x01) BE_Cross_SwapGroup24LE(0xe2, 0x6a, 0x01) BE_Cross_SwapGroup24LE(0xaa, 0x6d, 0x01) BE_Cross_SwapGroup24LE(0xee, 0x6f, 0x01) BE_Cross_SwapGroup24LE(0x47, 0x72, 0x01)
 BE_Cross_SwapGroup24LE(0x9a, 0x74, 0x01) BE_Cross_SwapGroup24LE(0xee, 0x76, 0x01) BE_Cross_SwapGroup24LE(0xf7, 0x78, 0x01) BE_Cross_SwapGroup24LE(0x1f, 0x7b, 0x01) BE_Cross_SwapGroup24LE(0x4f, 0x7d, 0x01)
 BE_Cross_SwapGroup24LE(0x39, 0x7f, 0x01) BE_Cross_SwapGroup24LE(0xe6, 0x80, 0x01) BE_Cross_SwapGroup24LE(0x7c, 0x82, 0x01) BE_Cross_SwapGroup24LE(0x9b, 0x85, 0x01) BE_Cross_SwapGroup24LE(0x9d, 0x88, 0x01)
 BE_Cross_SwapGroup24LE(0x9a, 0x8b, 0x01) BE_Cross_SwapGroup24LE(0xb0, 0x8e, 0x01) BE_Cross_SwapGroup24LE(0xdc, 0x91, 0x01) BE_Cross_SwapGroup24LE(0xb6, 0x95, 0x01) BE_Cross_SwapGroup24LE(0xb2, 0x99, 0x01)
 BE_Cross_SwapGroup24LE(0x69, 0x9d, 0x01) BE_Cross_SwapGroup24LE(0xde, 0xa0, 0x01) BE_Cross_SwapGroup24LE(0x90, 0xa3, 0x01) BE_Cross_SwapGroup24LE(0x0f, 0xa6, 0x01) BE_Cross_SwapGroup24LE(0x39, 0xa7, 0x01)
 BE_Cross_SwapGroup24LE(0x62, 0xa8, 0x01) BE_Cross_SwapGroup24LE(0x88, 0xa9, 0x01) BE_Cross_SwapGroup24LE(0xb0, 0xaa, 0x01) BE_Cross_SwapGroup24LE(0xde, 0xab, 0x01) BE_Cross_SwapGroup24LE(0x04, 0xad, 0x01)
 BE_Cross_SwapGroup24LE(0x63, 0xb0, 0x01) BE_Cross_SwapGroup24LE(0x0c, 0xb2, 0x01) BE_Cross_SwapGroup24LE(0xb5, 0xb3, 0x01) BE_Cross_SwapGroup24LE(0x39, 0xb6, 0x01) BE_Cross_SwapGroup24LE(0xd9, 0xb8, 0x01)
 BE_Cross_SwapGroup24LE(0x46, 0xba, 0x01) BE_Cross_SwapGroup24LE(0x48, 0xbb, 0x01) BE_Cross_SwapGroup24LE(0x55, 0xbc, 0x01) BE_Cross_SwapGroup24LE(0x57, 0xbd, 0x01) BE_Cross_SwapGroup24LE(0x63, 0xbe, 0x01)
 BE_Cross_SwapGroup24LE(0x40, 0xbf, 0x01) BE_Cross_SwapGroup24LE(0x1f, 0xc0, 0x01) BE_Cross_SwapGroup24LE(0xfd, 0xc0, 0x01) BE_Cross_SwapGroup24LE(0xdd, 0xc1, 0x01) BE_Cross_SwapGroup24LE(0xbc, 0xc2, 0x01)
 BE_Cross_SwapGroup24LE(0x9c, 0xc3, 0x01) BE_Cross_SwapGroup24LE(0x85, 0xc4, 0x01) BE_Cross_SwapGroup24LE(0x6d, 0xc5, 0x01) BE_Cross_SwapGroup24LE(0x52, 0xc6, 0x01) BE_Cross_SwapGroup24LE(0x38, 0xc7, 0x01)
 BE_Cross_SwapGroup24LE(0x84, 0xc8, 0x01) BE_Cross_SwapGroup24LE(0x60, 0xcb, 0x01) BE_Cross_SwapGroup24LE(0xa3, 0xcc, 0x01) BE_Cross_SwapGroup24LE(0x50, 0xcd, 0x01) BE_Cross_SwapGroup24LE(0xfc, 0xcd, 0x01)
 BE_Cross_SwapGroup24LE(0x7b, 0xcf, 0x01) BE_Cross_SwapGroup24LE(0x67, 0xd1, 0x01) BE_Cross_SwapGroup24LE(0x2e, 0xd3, 0x01) BE_Cross_SwapGroup24LE(0x5b, 0xd7, 0x01) BE_Cross_SwapGroup24LE(0x50, 0xdb, 0x01)
 BE_Cross_SwapGroup24LE(0x6d, 0xdf, 0x01) BE_Cross_SwapGroup24LE(0x64, 0xe3, 0x01) BE_Cross_SwapGroup24LE(0xc8, 0xe7, 0x01) BE_Cross_SwapGroup24LE(0xb7, 0xec, 0x01) BE_Cross_SwapGroup24LE(0xf5, 0xf0, 0x01)
 BE_Cross_SwapGroup24LE(0x34, 0xf5, 0x01) BE_Cross_SwapGroup24LE(0xff, 0xf9, 0x01) BE_Cross_SwapGroup24LE(0x91, 0xfd, 0x01) BE_Cross_SwapGroup24LE(0x46, 0x00, 0x02) BE_Cross_SwapGroup24LE(0xbc, 0x03, 0x02)
 BE_Cross_SwapGroup24LE(0x28, 0x07, 0x02) BE_Cross_SwapGroup24LE(0x9e, 0x0a, 0x02) BE_Cross_SwapGroup24LE(0x08, 0x0e, 0x02) BE_Cross_SwapGroup24LE(0xd0, 0x11, 0x02) BE_Cross_SwapGroup24LE(0xfa, 0x15, 0x02)
 BE_Cross_SwapGroup24LE(0x9c, 0x19, 0x02) BE_Cross_SwapGroup24LE(0x54, 0x1d, 0x02) BE_Cross_SwapGroup24LE(0x59, 0x21, 0x02) BE_Cross_SwapGroup24LE(0x81, 0x24, 0x02) BE_Cross_SwapGroup24LE(0x33, 0x27, 0x02)
 BE_Cross_SwapGroup24LE(0x51, 0x2a, 0x02) BE_Cross_SwapGroup24LE(0x68, 0x2d, 0x02) BE_Cross_SwapGroup24LE(0x62, 0x2f, 0x02) BE_Cross_SwapGroup24LE(0xda, 0x31, 0x02) BE_Cross_SwapGroup24LE(0x82, 0x33, 0x02)
 BE_Cross_SwapGroup24LE(0x20, 0x35, 0x02) BE_Cross_SwapGroup24LE(0xc1, 0x36, 0x02) BE_Cross_SwapGroup24LE(0x83, 0x38, 0x02) BE_Cross_SwapGroup24LE(0x26, 0x3a, 0x02) BE_Cross_SwapGroup24LE(0xcc, 0x3b, 0x02)
 BE_Cross_SwapGroup24LE(0x66, 0x3d, 0x02) BE_Cross_SwapGroup24LE(0xc9, 0x3e, 0x02) BE_Cross_SwapGroup24LE(0xfb, 0x42, 0x02) BE_Cross_SwapGroup24LE(0x2d, 0x47, 0x02) BE_Cross_SwapGroup24LE(0x19, 0x4a, 0x02)
 BE_Cross_SwapGroup24LE(0x1a, 0x4d, 0x02) BE_Cross_SwapGroup24LE(0xcc, 0x4f, 0x02) BE_Cross_SwapGroup24LE(0xed, 0x51, 0x02) BE_Cross_SwapGroup24LE(0x23, 0x54, 0x02) BE_Cross_SwapGroup24LE(0x6d, 0x56, 0x02)
 BE_Cross_SwapGroup24LE(0x9e, 0x58, 0x02) BE_Cross_SwapGroup24LE(0x7c, 0x5a, 0x02) BE_Cross_SwapGroup24LE(0xcc, 0x5b, 0x02) BE_Cross_SwapGroup24LE(0xdc, 0x5b, 0x02) BE_Cross_SwapGroup24LE(0x13, 0x5f, 0x02)
 BE_Cross_SwapGroup24LE(0xb4, 0x62, 0x02) BE_Cross_SwapGroup24LE(0x82, 0x66, 0x02) BE_Cross_SwapGroup24LE(0x3c, 0x6a, 0x02) BE_Cross_SwapGroup24LE(0x3c, 0x6e, 0x02) BE_Cross_SwapGroup24LE(0x15, 0x72, 0x02)
 BE_Cross_SwapGroup24LE(0x94, 0x77, 0x02) BE_Cross_SwapGroup24LE(0xae, 0x7c, 0x02) BE_Cross_SwapGroup24LE(0x32, 0x82, 0x02) BE_Cross_SwapGroup24LE(0x4b, 0x87, 0x02) BE_Cross_SwapGroup24LE(0xd8, 0x8b, 0x02)
 BE_Cross_SwapGroup24LE(0xb7, 0x8f, 0x02) BE_Cross_SwapGroup24LE(0x4b, 0x93, 0x02) BE_Cross_SwapGroup24LE(0x26, 0x98, 0x02) BE_Cross_SwapGroup24LE(0x63, 0x9c, 0x02) BE_Cross_SwapGroup24LE(0x8d, 0xa1, 0x02)
 BE_Cross_SwapGroup24LE(0x45, 0xa6, 0x02) BE_Cross_SwapGroup24LE(0x06, 0xab, 0x02) BE_Cross_SwapGroup24LE(0x11, 0xaf, 0x02) BE_Cross_SwapGroup24LE(0xb7, 0xb4, 0x02) BE_Cross_SwapGroup24LE(0x04, 0xba, 0x02)
 BE_Cross_SwapGroup24LE(0x7a, 0xbf, 0x02) BE_Cross_SwapGroup24LE(0xac, 0xc3, 0x02) BE_Cross_SwapGroup24LE(0x93, 0xc8, 0x02) BE_Cross_SwapGroup24LE(0xab, 0xcc, 0x02) BE_Cross_SwapGroup24LE(0x65, 0xd1, 0x02)
 BE_Cross_SwapGroup24LE(0x9a, 0xd7, 0x02) BE_Cross_SwapGroup24LE(0xcd, 0xde, 0x02) BE_Cross_SwapGroup24LE(0xd1, 0xe3, 0x02) BE_Cross_SwapGroup24LE(0x1a, 0xe9, 0x02) BE_Cross_SwapGroup24LE(0x9e, 0xef, 0x02)
 BE_Cross_SwapGroup24LE(0x29, 0xf7, 0x02) BE_Cross_SwapGroup24LE(0x01, 0xfd, 0x02) BE_Cross_SwapGroup24LE(0x76, 0x01, 0x03) BE_Cross_SwapGroup24LE(0xc3, 0x05, 0x03) BE_Cross_SwapGroup24LE(0x9d, 0x0a, 0x03)
 BE_Cross_SwapGroup24LE(0x5c, 0x0f, 0x03) BE_Cross_SwapGroup24LE(0x19, 0x15, 0x03) BE_Cross_SwapGroup24LE(0x98, 0x1a, 0x03) BE_Cross_SwapGroup24LE(0x84, 0x20, 0x03) BE_Cross_SwapGroup24LE(0x43, 0x26, 0x03)
 BE_Cross_SwapGroup24LE(0x96, 0x2b, 0x03) BE_Cross_SwapGroup24LE(0x09, 0x30, 0x03) BE_Cross_SwapGroup24LE(0x8c, 0x33, 0x03) BE_Cross_SwapGroup24LE(0xbc, 0x36, 0x03) BE_Cross_SwapGroup24LE(0xfe, 0x3b, 0x03)
 BE_Cross_SwapGroup24LE(0xed, 0x40, 0x03) BE_Cross_SwapGroup24LE(0x2c, 0x46, 0x03) BE_Cross_SwapGroup24LE(0xb5, 0x4a, 0x03) BE_Cross_SwapGroup24LE(0x59, 0x50, 0x03) BE_Cross_SwapGroup24LE(0xbf, 0x55, 0x03)
 BE_Cross_SwapGroup24LE(0x1f, 0x5c, 0x03) BE_Cross_SwapGroup24LE(0x76, 0x61, 0x03) BE_Cross_SwapGroup24LE(0xf4, 0x66, 0x03) BE_Cross_SwapGroup24LE(0x46, 0x6c, 0x03) BE_Cross_SwapGroup24LE(0x9f, 0x71, 0x03)
 BE_Cross_SwapGroup24LE(0x2d, 0x76, 0x03) BE_Cross_SwapGroup24LE(0x70, 0x7a, 0x03) BE_Cross_SwapGroup24LE(0x23, 0x7e, 0x03) BE_Cross_SwapGroup24LE(0x48, 0x82, 0x03) BE_Cross_SwapGroup24LE(0xea, 0x85, 0x03)
 BE_Cross_SwapGroup24LE(0x84, 0x8a, 0x03) BE_Cross_SwapGroup24LE(0x72, 0x8e, 0x03) BE_Cross_SwapGroup24LE(0x62, 0x94, 0x03) BE_Cross_SwapGroup24LE(0xf6, 0x99, 0x03) BE_Cross_SwapGroup24LE(0xc4, 0x9d, 0x03)
 BE_Cross_SwapGroup24LE(0x38, 0xa1, 0x03) BE_Cross_SwapGroup24LE(0x1e, 0xa5, 0x03) BE_Cross_SwapGroup24LE(0x95, 0xa8, 0x03) BE_Cross_SwapGroup24LE(0x6a, 0xae, 0x03) BE_Cross_SwapGroup24LE(0x27, 0xb3, 0x03)
 BE_Cross_SwapGroup24LE(0x6e, 0xb7, 0x03) BE_Cross_SwapGroup24LE(0x37, 0xbc, 0x03) BE_Cross_SwapGroup24LE(0x82, 0xc0, 0x03) BE_Cross_SwapGroup24LE(0xc5, 0xc6, 0x03) BE_Cross_SwapGroup24LE(0x10, 0xcd, 0x03)
 BE_Cross_SwapGroup24LE(0xd4, 0xd2, 0x03) BE_Cross_SwapGroup24LE(0xad, 0xd8, 0x03) BE_Cross_SwapGroup24LE(0x1e, 0xde, 0x03) BE_Cross_SwapGroup24LE(0x05, 0xe3, 0x03) BE_Cross_SwapGroup24LE(0x5a, 0xe8, 0x03)
 BE_Cross_SwapGroup24LE(0x60, 0xed, 0x03) BE_Cross_SwapGroup24LE(0xa6, 0xf2, 0x03) BE_Cross_SwapGroup24LE(0x2b, 0xf8, 0x03) BE_Cross_SwapGroup24LE(0x7f, 0xfd, 0x03) BE_Cross_SwapGroup24LE(0x43, 0x02, 0x04)
 BE_Cross_SwapGroup24LE(0x05, 0x07, 0x04) BE_Cross_SwapGroup24LE(0x6d, 0x0b, 0x04) BE_Cross_SwapGroup24LE(0x99, 0x0f, 0x04) BE_Cross_SwapGroup24LE(0x02, 0x15, 0x04) BE_Cross_SwapGroup24LE(0xac, 0x19, 0x04)
 BE_Cross_SwapGroup24LE(0x6f, 0x1d, 0x04) BE_Cross_SwapGroup24LE(0x83, 0x20, 0x04) BE_Cross_SwapGroup24LE(0x3f, 0x24, 0x04) BE_Cross_SwapGroup24LE(0x52, 0x27, 0x04) BE_Cross_SwapGroup24LE(0xcf, 0x2a, 0x04)
 BE_Cross_SwapGroup24LE(0x40, 0x2f, 0x04) BE_Cross_SwapGroup24LE(0xca, 0x33, 0x04) BE_Cross_SwapGroup24LE(0x5f, 0x38, 0x04) BE_Cross_SwapGroup24LE(0xb9, 0x3c, 0x04) BE_Cross_SwapGroup24LE(0x10, 0x41, 0x04)
 BE_Cross_SwapGroup24LE(0xea, 0x45, 0x04) BE_Cross_SwapGroup24LE(0xcd, 0x49, 0x04) BE_Cross_SwapGroup24LE(0x93, 0x4e, 0x04) BE_Cross_SwapGroup24LE(0x6f, 0x52, 0x04) BE_Cross_SwapGroup24LE(0xe5, 0x56, 0x04)
 BE_Cross_SwapGroup24LE(0xbf, 0x5a, 0x04) BE_Cross_SwapGroup24LE(0x12, 0x5f, 0x04) BE_Cross_SwapGroup24LE(0xa6, 0x63, 0x04) BE_Cross_SwapGroup24LE(0xda, 0x67, 0x04) BE_Cross_SwapGroup24LE(0x72, 0x6c, 0x04)
 BE_Cross_SwapGroup24LE(0xab, 0x70, 0x04) BE_Cross_SwapGroup24LE(0x4e, 0x75, 0x04) BE_Cross_SwapGroup24LE(0xb4, 0x79, 0x04) BE_Cross_SwapGroup24LE(0xe6, 0x7d, 0x04) BE_Cross_SwapGroup24LE(0xe8, 0x82, 0x04)
 BE_Cross_SwapGroup24LE(0x57, 0x87, 0x04) BE_Cross_SwapGroup24LE(0x93, 0x8b, 0x04) BE_Cross_SwapGroup24LE(0x9e, 0x8f, 0x04) BE_Cross_SwapGroup24LE(0xb2, 0x8f, 0x04) BE_Cross_SwapGroup24LE(0x09, 0x96, 0x04)
 BE_Cross_SwapGroup24LE(0x29, 0x96, 0x04) BE_Cross_SwapGroup24LE(0x09, 0x9c, 0x04) BE_Cross_SwapGroup24LE(0x4e, 0x9d, 0x04) BE_Cross_SwapGroup24LE(0x6f, 0x9d, 0x04) BE_Cross_SwapGroup24LE(0xee, 0x9d, 0x04)
 BE_Cross_SwapGroup24LE(0x68, 0x9e, 0x04) BE_Cross_SwapGroup24LE(0xd3, 0x9e, 0x04) BE_Cross_SwapGroup24LE(0x44, 0x9f, 0x04) BE_Cross_SwapGroup24LE(0xa6, 0x9f, 0x04) BE_Cross_SwapGroup24LE(0xf1, 0x9f, 0x04)
 BE_Cross_SwapGroup24LE(0x55, 0xa0, 0x04) BE_Cross_SwapGroup24LE(0xb9, 0xa0, 0x04) BE_Cross_SwapGroup24LE(0x1c, 0xa1, 0x04) BE_Cross_SwapGroup24LE(0x82, 0xa1, 0x04) BE_Cross_SwapGroup24LE(0xe6, 0xa1, 0x04)
 BE_Cross_SwapGroup24LE(0x5c, 0xa2, 0x04) BE_Cross_SwapGroup24LE(0xa9, 0xa2, 0x04) BE_Cross_SwapGroup24LE(0xf6, 0xa2, 0x04) BE_Cross_SwapGroup24LE(0x42, 0xa3, 0x04) BE_Cross_SwapGroup24LE(0x8e, 0xa3, 0x04)
 BE_Cross_SwapGroup24LE(0xdc, 0xa3, 0x04) BE_Cross_SwapGroup24LE(0x32, 0xa4, 0x04) BE_Cross_SwapGroup24LE(0x9a, 0xa4, 0x04) BE_Cross_SwapGroup24LE(0xe1, 0xa4, 0x04) BE_Cross_SwapGroup24LE(0x44, 0xa5, 0x04)
 BE_Cross_SwapGroup24LE(0x8e, 0xa5, 0x04) BE_Cross_SwapGroup24LE(0xf2, 0xa5, 0x04) BE_Cross_SwapGroup24LE(0x5d, 0xa6, 0x04) BE_Cross_SwapGroup24LE(0xc7, 0xa6, 0x04) BE_Cross_SwapGroup24LE(0x3a, 0xa7, 0x04)
 BE_Cross_SwapGroup24LE(0xa4, 0xa7, 0x04) BE_Cross_SwapGroup24LE(0x24, 0xa8, 0x04) BE_Cross_SwapGroup24LE(0x7b, 0xa8, 0x04) BE_Cross_SwapGroup24LE(0xd4, 0xa8, 0x04) BE_Cross_SwapGroup24LE(0x21, 0xa9, 0x04)
 BE_Cross_SwapGroup24LE(0x9b, 0xa9, 0x04) BE_Cross_SwapGroup24LE(0x14, 0xaa, 0x04) BE_Cross_SwapGroup24LE(0x90, 0xaa, 0x04) BE_Cross_SwapGroup24LE(0x04, 0xab, 0x04) BE_Cross_SwapGroup24LE(0x6b, 0xab, 0x04)
 BE_Cross_SwapGroup24LE(0xee, 0xab, 0x04) BE_Cross_SwapGroup24LE(0x4f, 0xac, 0x04) BE_Cross_SwapGroup24LE(0xa8, 0xac, 0x04) BE_Cross_SwapGroup24LE(0x04, 0xad, 0x04) BE_Cross_SwapGroup24LE(0x75, 0xad, 0x04)
 BE_Cross_SwapGroup24LE(0xf1, 0xad, 0x04) BE_Cross_SwapGroup24LE(0x6b, 0xae, 0x04) BE_Cross_SwapGroup24LE(0xec, 0xae, 0x04) BE_Cross_SwapGroup24LE(0x41, 0xaf, 0x04) BE_Cross_SwapGroup24LE(0xa1, 0xaf, 0x04)
 BE_Cross_SwapGroup24LE(0x17, 0xb0, 0x04) BE_Cross_SwapGroup24LE(0x82, 0xb0, 0x04) BE_Cross_SwapGroup24LE(0xe8, 0xb0, 0x04) BE_Cross_SwapGroup24LE(0x31, 0xb1, 0x04) BE_Cross_SwapGroup24LE(0x96, 0xb1, 0x04)
 BE_Cross_SwapGroup24LE(0xfc, 0xb1, 0x04) BE_Cross_SwapGroup24LE(0x74, 0xb2, 0x04) BE_Cross_SwapGroup24LE(0xdc, 0xb2, 0x04) BE_Cross_SwapGroup24LE(0x51, 0xb3, 0x04) BE_Cross_SwapGroup24LE(0xc1, 0xb3, 0x04)
 BE_Cross_SwapGroup24LE(0x0a, 0xb4, 0x04) BE_Cross_SwapGroup24LE(0x57, 0xb4, 0x04) BE_Cross_SwapGroup24LE(0x9f, 0xb4, 0x04) BE_Cross_SwapGroup24LE(0x13, 0xb5, 0x04) BE_Cross_SwapGroup24LE(0x75, 0xb5, 0x04)
 BE_Cross_SwapGroup24LE(0xdb, 0xb5, 0x04) BE_Cross_SwapGroup24LE(0x43, 0xb6, 0x04) BE_Cross_SwapGroup24LE(0xac, 0xb6, 0x04) BE_Cross_SwapGroup24LE(0x18, 0xb7, 0x04) BE_Cross_SwapGroup24LE(0x87, 0xb7, 0x04)
 BE_Cross_SwapGroup24LE(0xf1, 0xb7, 0x04) BE_Cross_SwapGroup24LE(0x4e, 0xb8, 0x04) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xb7, 0xb8, 0x04) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff)
 BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xf8, 0xb8, 0x04) BE_Cross_SwapGroup24LE(0x2f, 0xb9, 0x04) BE_Cross_SwapGroup24LE(0x81, 0xb9, 0x04)
 BE_Cross_SwapGroup24LE(0xd4, 0xb9, 0x04) BE_Cross_SwapGroup24LE(0x1f, 0xba, 0x04) BE_Cross_SwapGroup24LE(0x77, 0xba, 0x04) BE_Cross_SwapGroup24LE(0xc1, 0xba, 0x04) BE_Cross_SwapGroup24LE(0x0b, 0xbb, 0x04)
 BE_Cross_SwapGroup24LE(0x5b, 0xbb, 0x04) BE_Cross_SwapGroup24LE(0xb6, 0xbb, 0x04) BE_Cross_SwapGroup24LE(0x07, 0xbc, 0x04) BE_Cross_SwapGroup24LE(0x52, 0xbc, 0x04) BE_Cross_SwapGroup24LE(0xab, 0xbc, 0x04)
 BE_Cross_SwapGroup24LE(0xf3, 0xbc, 0x04) BE_Cross_SwapGroup24LE(0x4e, 0xbd, 0x04) BE_Cross_SwapGroup24LE(0xa9, 0xbd, 0x04) BE_Cross_SwapGroup24LE(0x03, 0xbe, 0x04) BE_Cross_SwapGroup24LE(0x53, 0xbe, 0x04)
 BE_Cross_SwapGroup24LE(0xa8, 0xbe, 0x04) BE_Cross_SwapGroup24LE(0xf9, 0xbe, 0x04) BE_Cross_SwapGroup24LE(0x43, 0xbf, 0x04) BE_Cross_SwapGroup24LE(0x87, 0xbf, 0x04) BE_Cross_SwapGroup24LE(0xdb, 0xbf, 0x04)
 BE_Cross_SwapGroup24LE(0x2e, 0xc0, 0x04) BE_Cross_SwapGroup24LE(0x89, 0xc0, 0x04) BE_Cross_SwapGroup24LE(0xe2, 0xc0, 0x04) BE_Cross_SwapGroup24LE(0x2f, 0xc1, 0x04) BE_Cross_SwapGroup24LE(0x78, 0xc1, 0x04)
 BE_Cross_SwapGroup24LE(0xaf, 0xc1, 0x04) BE_Cross_SwapGroup24LE(0xe6, 0xc1, 0x04) BE_Cross_SwapGroup24LE(0x1d, 0xc2, 0x04) BE_Cross_SwapGroup24LE(0x54, 0xc2, 0x04) BE_Cross_SwapGroup24LE(0x8b, 0xc2, 0x04)
 BE_Cross_SwapGroup24LE(0xc2, 0xc2, 0x04) BE_Cross_SwapGroup24LE(0xf9, 0xc2, 0x04) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0xff, 0xff, 0xff) BE_Cross_SwapGroup24LE(0x34, 0xc3, 0x04)
 BE_Cross_SwapGroup24LE(0xbe, 0xc3, 0x04) BE_Cross_SwapGroup24LE(0x38, 0xc4, 0x04) BE_Cross_SwapGroup24LE(0xc0, 0xc4, 0x04) BE_Cross_SwapGroup24LE(0x43, 0xc5, 0x04) BE_Cross_SwapGroup24LE(0xb5, 0xc5, 0x04)
 BE_Cross_SwapGroup24LE(0x27, 0xc6, 0x04) BE_Cross_SwapGroup24LE(0x96, 0xc6, 0x04) BE_Cross_SwapGroup24LE(0xfc, 0xc6, 0x04) BE_Cross_SwapGroup24LE(0x66, 0xc7, 0x04) BE_Cross_SwapGroup24LE(0xc9, 0xc7, 0x04)
 BE_Cross_SwapGroup24LE(0x32, 0xc8, 0x04) BE_Cross_SwapGroup24LE(0xbc, 0xc8, 0x04) BE_Cross_SwapGroup24LE(0x41, 0xc9, 0x04) BE_Cross_SwapGroup24LE(0xc9, 0xc9, 0x04) BE_Cross_SwapGroup24LE(0x51, 0xca, 0x04)
 BE_Cross_SwapGroup24LE(0xd4, 0xca, 0x04) BE_Cross_SwapGroup24LE(0x5d, 0xcb, 0x04) BE_Cross_SwapGroup24LE(0xdf, 0xcb, 0x04) BE_Cross_SwapGroup24LE(0x69, 0xcc, 0x04) BE_Cross_SwapGroup24LE(0xca, 0xcc, 0x04)
 BE_Cross_SwapGroup24LE(0x30, 0xcd, 0x04) BE_Cross_SwapGroup24LE(0x9b, 0xcd, 0x04) BE_Cross_SwapGroup24LE(0xfe, 0xcd, 0x04) BE_Cross_SwapGroup24LE(0x66, 0xce, 0x04) BE_Cross_SwapGroup24LE(0xa0, 0xce, 0x04)
 BE_Cross_SwapGroup24LE(0x12, 0xcf, 0x04) BE_Cross_SwapGroup24LE(0x6a, 0xcf, 0x04) BE_Cross_SwapGroup24LE(0xe4, 0xcf, 0x04) BE_Cross_SwapGroup24LE(0x5c, 0xd0, 0x04) BE_Cross_SwapGroup24LE(0xc5, 0xd0, 0x04)
 BE_Cross_SwapGroup24LE(0x4f, 0xd1, 0x04) BE_Cross_SwapGroup24LE(0xd5, 0xd1, 0x04) BE_Cross_SwapGroup24LE(0x59, 0xd2, 0x04) BE_Cross_SwapGroup24LE(0xe2, 0xd2, 0x04) BE_Cross_SwapGroup24LE(0x66, 0xd3, 0x04)
 BE_Cross_SwapGroup24LE(0xd5, 0xd3, 0x04) BE_Cross_SwapGroup24LE(0x3d, 0xd4, 0x04) BE_Cross_SwapGroup24LE(0x85, 0xd4, 0x04) BE_Cross_SwapGroup24LE(0xfe, 0xd4, 0x04) BE_Cross_SwapGroup24LE(0x61, 0xd5, 0x04)
 BE_Cross_SwapGroup24LE(0xd0, 0xd5, 0x04) BE_Cross_SwapGroup24LE(0x38, 0xd6, 0x04) BE_Cross_SwapGroup24LE(0x80, 0xd6, 0x04) BE_Cross_SwapGroup24LE(0xf9, 0xd6, 0x04) BE_Cross_SwapGroup24LE(0x5c, 0xd7, 0x04)
 BE_Cross_SwapGroup24LE(0xd1, 0xd7, 0x04) BE_Cross_SwapGroup24LE(0x4c, 0xd8, 0x04) BE_Cross_SwapGroup24LE(0xbd, 0xd8, 0x04) BE_Cross_SwapGroup24LE(0x18, 0xd9, 0x04) BE_Cross_SwapGroup24LE(0x7d, 0xd9, 0x04)
 BE_Cross_SwapGroup24LE(0xe2, 0xd9, 0x04) BE_Cross_SwapGroup24LE(0x4e, 0xda, 0x04) BE_Cross_SwapGroup24LE(0xbe, 0xda, 0x04) BE_Cross_SwapGroup24LE(0x22, 0xdb, 0x04) BE_Cross_SwapGroup24LE(0x93, 0xdb, 0x04)
 BE_Cross_SwapGroup24LE(0x0c, 0xdc, 0x04) BE_Cross_SwapGroup24LE(0x65, 0xdc, 0x04) BE_Cross_SwapGroup24LE(0xdd, 0xdc, 0x04) BE_Cross_SwapGroup24LE(0x52, 0xdd, 0x04) BE_Cross_SwapGroup24LE(0xca, 0xdd, 0x04)
 BE_Cross_SwapGroup24LE(0x4d, 0xde, 0x04) BE_Cross_SwapGroup24LE(0xce, 0xde, 0x04) BE_Cross_SwapGroup24LE(0x3c, 0xdf, 0x04) BE_Cross_SwapGroup24LE(0xac, 0xdf, 0x04) BE_Cross_SwapGroup24LE(0x21, 0xe0, 0x04)
 BE_Cross_SwapGroup24LE(0x95, 0xe0, 0x04) BE_Cross_SwapGroup24LE(0x10, 0xe1, 0x04) BE_Cross_SwapGroup24LE(0x8b, 0xe1, 0x04) BE_Cross_SwapGroup24LE(0xf5, 0xe1, 0x04) BE_Cross_SwapGroup24LE(0x6b, 0xe2, 0x04)
 BE_Cross_SwapGroup24LE(0xe0, 0xe2, 0x04) BE_Cross_SwapGroup24LE(0x7a, 0xe5, 0x04) BE_Cross_SwapGroup24LE(0xd1, 0xe7, 0x04) BE_Cross_SwapGroup24LE(0x0d, 0xea, 0x04) BE_Cross_SwapGroup24LE(0x86, 0xec, 0x04)
 BE_Cross_SwapGroup24LE(0x01, 0xef, 0x04) BE_Cross_SwapGroup24LE(0xc3, 0xf0, 0x04) BE_Cross_SwapGroup24LE(0xfd, 0xf2, 0x04) BE_Cross_SwapGroup24LE(0x56, 0xf5, 0x04) BE_Cross_SwapGroup24LE(0xa2, 0xf7, 0x04)
 BE_Cross_SwapGroup24LE(0xc6, 0xf9, 0x04) BE_Cross_SwapGroup24LE(0x20, 0xfc, 0x04) BE_Cross_SwapGroup24LE(0x6e, 0xfe, 0x04) BE_Cross_SwapGroup24LE(0x99, 0x00, 0x05) BE_Cross_SwapGroup24LE(0x27, 0x03, 0x05)
 BE_Cross_SwapGroup24LE(0x8b, 0x05, 0x05) BE_Cross_SwapGroup24LE(0x5a, 0x07, 0x05) BE_Cross_SwapGroup24LE(0x91, 0x0a, 0x05) BE_Cross_SwapGroup24LE(0x71, 0x0c, 0x05) BE_Cross_SwapGroup24LE(0x55, 0x0e, 0x05)
 BE_Cross_SwapGroup24LE(0x82, 0x10, 0x05) BE_Cross_SwapGroup24LE(0x7a, 0x20, 0x05)
};

uint32_t *EGAhead = (uint32_t *)EGAHEAD_ABS;
