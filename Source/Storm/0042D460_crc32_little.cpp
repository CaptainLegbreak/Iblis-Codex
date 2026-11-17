// Altered from the original zlib source.
extern const unsigned long crc_table[8][256];                                                               // 0x006D17C8

#define DOLIT4 c ^= *buf4++; \
        c = crc_table[3][c & 0xff] ^ crc_table[2][(c >> 8) & 0xff] ^ \
            crc_table[1][(c >> 16) & 0xff] ^ crc_table[0][c >> 24]
#define DOLIT32 DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4

// 0x0042D460
static unsigned long crc32_little(unsigned long crc, const unsigned char* buf, unsigned len)
{
    register unsigned long c;
    register const unsigned long* buf4;

    c = (unsigned long)crc;
    c = ~c;
    while (len && ((int)buf & 3)) {
        c = crc_table[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
        len--;
    }

    buf4 = (const unsigned long*)(const void*)buf;
    while (len >= 32) {
        DOLIT32;
        len -= 32;
    }
    while (len >= 4) {
        DOLIT4;
        len -= 4;
    }
    buf = (const unsigned char*)buf4;

    if (len) do {
        c = crc_table[0][(c ^ *buf++) & 0xff] ^ (c >> 8);
    } while (--len);
    c = ~c;
    return (unsigned long)c;
}

// 0x0042DC00
unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len)
{
    if (buf == 0) return 0UL;
    return crc32_little(crc, buf, len);
}

#include "gen/data/Source/Storm/0042D460_crc32_little.inc"
