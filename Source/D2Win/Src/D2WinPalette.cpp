#include "D2Win.h"
#include "D2Win32Types.h"

struct D2Palette256Strc
{
    unsigned char data[256];
};

struct D2TransPaletteStrc
{
    unsigned char data[65536];
};

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0
void* __stdcall D2Win_GetArchive(); // 0x004FAC80
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nRed, int nGreen, int nBlue); // 0x00605210
void __cdecl PALETTE_ApplyPaletteTables(); // 0x004FB010
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0

extern const char gszD2WinPaletteSourceFile[]; // 0x006DC828
extern unsigned char gabStandardColorsPalette[39]; // 0x007D563C
extern D2Palette256Strc gatStandardShiftsPalette[13]; // 0x007D5668
extern unsigned char gabPaletteRemap[256]; // 0x007D6368
extern unsigned char gabStatesPalette[128][256]; // 0x007D6468
extern unsigned char gabScreenPalette[65536]; // 0x007DE468
extern D2TransPaletteStrc gatTransPalette[3]; // 0x007EE468
extern unsigned char gabDarkenPalette[256]; // 0x0081E468
extern unsigned char gabRedPaletteMap[256]; // 0x0081E568
extern tagPALETTEENTRY gatRGBAPalette[256]; // 0x0081E668
extern D2Palette256Strc gatShadowsLightGammaPalette[49]; // 0x0081EA68
extern D2Palette256Strc gatLightPalette[16]; // 0x00820A68
extern unsigned char gabPalette[256]; // 0x00821A68
extern unsigned char gabLuminancePalette[65536]; // 0x00821B68
extern unsigned char gabDarkBlendPalette[65536]; // 0x00831B68

// 0x004FB180
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return GetClosestColor((const unsigned char*)gatRGBAPalette, 0x100, nRed, nGreen, nBlue);
}

// 0x004FB1E0
int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName)
{
    tagPALETTEENTRY tPalette[256];
    unsigned char* pDat = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szDatFileName, 0, gszD2WinPaletteSourceFile, 99);
    unsigned char* pColor = pDat;
    for (unsigned int i = 0; i < 256; ++i)
    {
        tPalette[i].peRed = *pColor++;
        tPalette[i].peGreen = *pColor++;
        tPalette[i].peBlue = *pColor++;
        tPalette[i].peFlags = 0;
    }

    unsigned char* pTables = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPL2FileName, 0, gszD2WinPaletteSourceFile, 114);
    memcpy(gatRGBAPalette, pTables, sizeof(gatRGBAPalette));
    memcpy(gatTransPalette, pTables + 0x3500, sizeof(gatTransPalette));
    memcpy(gatShadowsLightGammaPalette, pTables + 0x400, sizeof(gatShadowsLightGammaPalette));
    memcpy(gabLuminancePalette, pTables + 0x43500, sizeof(gabLuminancePalette));
    memcpy(gabScreenPalette, pTables + 0x33500, sizeof(gabScreenPalette));
    memcpy(gatLightPalette, pTables + 0x2400, sizeof(gatLightPalette));
    memcpy(gabPalette, pTables + 0x3400, sizeof(gabPalette));
    memcpy(gabStatesPalette, pTables + 0x53500, sizeof(gabStatesPalette));
    memcpy(gabDarkBlendPalette, pTables + 0x5B500, sizeof(gabDarkBlendPalette));
    memcpy(gabDarkenPalette, pTables + 0x6B500, sizeof(gabDarkenPalette));
    memcpy(gabStandardColorsPalette, pTables + 0x6B600, sizeof(gabStandardColorsPalette));
    memcpy(gatStandardShiftsPalette, pTables + 0x6B627, sizeof(gatStandardShiftsPalette));

    for (unsigned int i = 0; i < 256; ++i)
        gatRGBAPalette[i].peFlags = 5;

    tagPALETTEENTRY* pEntry = gatRGBAPalette;
    for (unsigned int i = 0; i < 256; ++i)
    {
        const int nScaledRed = 170 * pEntry->peRed / 100;
        const int nRed = D2_MIN(255, nScaledRed);
        const int nScaledGreen = 170 * pEntry->peGreen / 100;
        const int nGreen = D2_MIN(255, nScaledGreen);
        const int nBlue = D2_MIN(255, 170 * pEntry->peBlue / 100);
        gabPaletteRemap[i] = sub_004FB180_FindPaletteIndex(nRed, nGreen, nBlue);
        gabRedPaletteMap[i] = sub_004FB180_FindPaletteIndex(pEntry->peRed, 0, 0);
        ++pEntry;
    }

    PALETTE_ApplyPaletteTables();
    D2GFX_SetPalette(gatRGBAPalette);
    FOG_Free(pDat, gszD2WinPaletteSourceFile, 150, 0);
    FOG_Free(pTables, gszD2WinPaletteSourceFile, 153, 0);
    return 1;
}

#include "gen/data/Source/D2Win/Src/D2WinPalette.inc"
