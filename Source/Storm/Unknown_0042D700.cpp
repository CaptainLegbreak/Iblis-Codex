#include "Storm.h"
#define DOBIG4 c ^= *++buf4; \
        c = crc_table[4][c & 0xff] ^ crc_table[5][(c >> 8) & 0xff] ^ \
            crc_table[6][(c >> 16) & 0xff] ^ crc_table[7][c >> 24]
#define DOBIG32 DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4

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

// 0x0042D700
static unsigned long __stdcall crc32_big(unsigned long crc, const unsigned char* buf, unsigned len)
{
    register unsigned long c;
    register const unsigned long* buf4;

    c = ZSWAP32((unsigned long)crc);
    c = ~c;
    while (len && ((int)buf & 3)) {
        c = crc_table[4][(c >> 24) ^ *buf++] ^ (c << 8);
        len--;
    }

    buf4 = (const unsigned long*)(const void*)buf;
    buf4--;
    while (len >= 32) {
        DOBIG32;
        len -= 32;
    }
    while (len >= 4) {
        DOBIG4;
        len -= 4;
    }
    buf4++;
    buf = (const unsigned char*)buf4;

    if (len) do {
        c = crc_table[4][(c >> 24) ^ *buf++] ^ (c << 8);
    } while (--len);
    c = ~c;
    return (unsigned long)(ZSWAP32(c));
}

// build: context crc32
unsigned long __fastcall crc32(unsigned long crc, const unsigned char* buf, unsigned int len)
{
    if (buf == 0) return 0UL;
    {
        unsigned long endian;
        endian = 1;
        if (*((unsigned char*)(&endian)))
            return crc32_little(crc, buf, len);
        else
            return crc32_big(crc, buf, len);
    }
}
