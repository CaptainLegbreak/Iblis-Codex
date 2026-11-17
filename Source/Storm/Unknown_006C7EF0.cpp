#include "Storm.h"

struct D2PaletteColorStrc;
struct D2RgbQuad006C8110Strc;

struct D2PaletteColorStrc { unsigned char blue, green, red, reserved; };

extern int gnWidth_007C9138; // 0x007C9138
extern unsigned char* gpPixels_007C9154; // 0x007C9154
extern D2PaletteColorStrc gaPalette_00989C40[256]; // 0x00989C40

struct D2RgbQuad006C8110Strc
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

// 0x006C7EF0
int __fastcall sub_006C7EF0_ConvertPalette(unsigned char* buffer)
{
    unsigned char* row = gpPixels_007C9154;
    for (int y = 0; y < gnHeight_007C913C; ++y) {
        unsigned char* source = row;
        unsigned char* destination = buffer;
        for (int x = 0; x < gnWidth_007C9138; ++x) {
            D2PaletteColorStrc* color = &gaPalette_00989C40[*source];
            *destination++ = color->red;
            *destination++ = color->green;
            *destination = color->blue;
            ++source;
            ++destination;
        }
        row += gnWidth_007C9138;
        buffer += 3 * gnWidth_007C9138;
    }
    return 1;
}

D2RgbQuad006C8110Strc gaColors_00989C40[256]; // 0x00989C40

// 0x006C8110
unsigned char __fastcall sub_006C8110_FindNearestColor(int nRed, int nBlue, int nGreen)
{
    unsigned char nIndex = 0;
    int nBest = 10000;
    for (int i = 1; i < 256; ++i)
    {
        int nDiff = gaColors_00989C40[i].rgbRed - nRed;
        if (nDiff < 0)
            nDiff = -nDiff;
        const int nRedDiff = nDiff;
        nDiff = gaColors_00989C40[i].rgbGreen - nGreen;
        if (nDiff < 0)
            nDiff = -nDiff;
        const int nGreenDiff = nDiff;
        nDiff = gaColors_00989C40[i].rgbBlue - nBlue;
        if (nDiff < 0)
            nDiff = -nDiff;
        nDiff += nGreenDiff;
        if (nDiff + nRedDiff < nBest)
        {
            nBest = nDiff + nRedDiff;
            nIndex = (unsigned char)i;
        }
    }
    return nIndex;
}
