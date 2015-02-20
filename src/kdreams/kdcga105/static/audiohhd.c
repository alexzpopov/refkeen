#include <stdint.h>

static uint32_t AUDIOHHD_KDR[] = {
 0x00000000, 0x0000000a, 0x00000014, 0x00000028,
 0x00000036, 0x0000004c, 0x0000007b, 0x0000009e,
 0x000000c5, 0x00000122, 0x00000143, 0x0000015e,
 0x000001bd, 0x00000223, 0x00000298, 0x000002aa,
 0x000002bb, 0x000002dc, 0x000002fd, 0x0000038b,
 0x000003b2, 0x000003e1, 0x0000043c, 0x000004ee,
 0x00000519, 0x00000543, 0x0000055c, 0x00000562,
 0x00000568, 0x0000057f, 0x00000596, 0x000005c8,
 0x000005e4, 0x0000060d, 0x00000645, 0x00000690,
 0x000006d0, 0x00000741, 0x00000780, 0x000007b9,
 0x00000857, 0x000008c0, 0x0000096a, 0x000009a4,
 0x000009c2, 0x000009f4, 0x00000a23, 0x00000ac6,
 0x00000b10, 0x00000b74, 0x00000bd5, 0x00000cbd,
 0x00000cf9, 0x00000d33, 0x00000d89, 0x00000d99,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x000011dc, 0x000011dc, 0x000011dc, 0x000011dc,
 0x00000daa,
};

unsigned char *audiohead = (unsigned char *)AUDIOHHD_KDR;
