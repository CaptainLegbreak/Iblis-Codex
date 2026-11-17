struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __fastcall sub_006BE190_BuildGammaTable(int nGamma, void* pTable, double dScale, int nArg, int nEntries, int nMask); // 0x006BE190

extern int gnDDrawGammaScale_0072F7C8;                                                                      // 0x0072F7C8
extern int gnDDrawGamma_0072F7CC;                                                                           // 0x0072F7CC
extern T004F51E0 gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8
T004F51E0 gaDDrawSavedPalette_00880D40[256];                                                       // 0x00880D40
int gbPaletteDirty_00881298;                                                                                // 0x00881298

// 0x00510160
void __fastcall sub_00510160_DDrawSetPalette(T004F51E0* pPalette)
{
    memcpy(gaDDrawSavedPalette_00880D40, pPalette, sizeof(gaDDrawSavedPalette_00880D40));

    unsigned char abGamma[256];
    sub_006BE190_BuildGammaTable(gnDDrawGamma_0072F7CC, abGamma, gnDDrawGammaScale_0072F7C8, 1, 256, 0xFF);
    for (int i = 0; i < 256; ++i)
    {
        gaDDrawPalette_007C8CC8[i].peRed = abGamma[gaDDrawSavedPalette_00880D40[i].peRed];
        gaDDrawPalette_007C8CC8[i].peGreen = abGamma[gaDDrawSavedPalette_00880D40[i].peGreen];
        gaDDrawPalette_007C8CC8[i].peBlue = abGamma[gaDDrawSavedPalette_00880D40[i].peBlue];
    }

    gbPaletteDirty_00881298 = 1;
}

#include "gen/data/Source/D2Win/00510160_sub_00510160_DDrawSetPalette.inc"
