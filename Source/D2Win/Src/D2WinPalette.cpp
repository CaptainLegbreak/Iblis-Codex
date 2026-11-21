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
void __cdecl sub_004FB010_SetPaletteTables(); // 0x004FB010
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0

extern const char gszD2WinPaletteSourceFile_006DC828[]; // 0x006DC828
extern unsigned char gStandardColorsPalette_007D563C[39]; // 0x007D563C
extern D2Palette256Strc gStandardShiftsPalette_007D5668[13]; // 0x007D5668
extern unsigned char gbyPaletteMap_007D6368[256]; // 0x007D6368
extern unsigned char gStatesPalette_6F9626C0[128][256]; // 0x007D6468
extern unsigned char gScreenPalette_007DE468[65536]; // 0x007DE468
extern D2TransPaletteStrc gTransPalette_007EE468[3]; // 0x007EE468
extern unsigned char gDarkenPalette_0081E468[256]; // 0x0081E468
extern unsigned char gbyPaletteMap_0081E568[256]; // 0x0081E568
extern tagPALETTEENTRY gRGBAPalette_0081E668[256]; // 0x0081E668
extern D2Palette256Strc gShadowsLightGammaPalette_0081EA68[49]; // 0x0081EA68
extern D2Palette256Strc gLightPalette_00820A68[16]; // 0x00820A68
extern unsigned char gPalette_00821A68[256]; // 0x00821A68
extern unsigned char gLuminancePalette_00821B68[65536]; // 0x00821B68
extern unsigned char gDarkBlendPalette_00831B68[65536]; // 0x00831B68

// 0x004FB180
unsigned char __stdcall sub_004FB180_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return GetClosestColor((const unsigned char*)gRGBAPalette_0081E668, 0x100, nRed, nGreen, nBlue);
}

// 0x004FB1E0
int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName)
{
    tagPALETTEENTRY tPalette[256];
    unsigned char* pDat = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szDatFileName, 0, gszD2WinPaletteSourceFile_006DC828, 99);
    unsigned char* pColor = pDat;
    for (unsigned int i = 0; i < 256; ++i)
    {
        tPalette[i].peRed = *pColor++;
        tPalette[i].peGreen = *pColor++;
        tPalette[i].peBlue = *pColor++;
        tPalette[i].peFlags = 0;
    }

    unsigned char* pTables = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPL2FileName, 0, gszD2WinPaletteSourceFile_006DC828, 114);
    memcpy(gRGBAPalette_0081E668, pTables, sizeof(gRGBAPalette_0081E668));
    memcpy(gTransPalette_007EE468, pTables + 0x3500, sizeof(gTransPalette_007EE468));
    memcpy(gShadowsLightGammaPalette_0081EA68, pTables + 0x400, sizeof(gShadowsLightGammaPalette_0081EA68));
    memcpy(gLuminancePalette_00821B68, pTables + 0x43500, sizeof(gLuminancePalette_00821B68));
    memcpy(gScreenPalette_007DE468, pTables + 0x33500, sizeof(gScreenPalette_007DE468));
    memcpy(gLightPalette_00820A68, pTables + 0x2400, sizeof(gLightPalette_00820A68));
    memcpy(gPalette_00821A68, pTables + 0x3400, sizeof(gPalette_00821A68));
    memcpy(gStatesPalette_6F9626C0, pTables + 0x53500, sizeof(gStatesPalette_6F9626C0));
    memcpy(gDarkBlendPalette_00831B68, pTables + 0x5B500, sizeof(gDarkBlendPalette_00831B68));
    memcpy(gDarkenPalette_0081E468, pTables + 0x6B500, sizeof(gDarkenPalette_0081E468));
    memcpy(gStandardColorsPalette_007D563C, pTables + 0x6B600, sizeof(gStandardColorsPalette_007D563C));
    memcpy(gStandardShiftsPalette_007D5668, pTables + 0x6B627, sizeof(gStandardShiftsPalette_007D5668));

    for (unsigned int i = 0; i < 256; ++i)
        gRGBAPalette_0081E668[i].peFlags = 5;

    tagPALETTEENTRY* pEntry = gRGBAPalette_0081E668;
    for (unsigned int i = 0; i < 256; ++i)
    {
        const int nScaledRed = 170 * pEntry->peRed / 100;
        const int nRed = D2_MIN(255, nScaledRed);
        const int nScaledGreen = 170 * pEntry->peGreen / 100;
        const int nGreen = D2_MIN(255, nScaledGreen);
        const int nBlue = D2_MIN(255, 170 * pEntry->peBlue / 100);
        gbyPaletteMap_007D6368[i] = sub_004FB180_FindPaletteIndex(nRed, nGreen, nBlue);
        gbyPaletteMap_0081E568[i] = sub_004FB180_FindPaletteIndex(pEntry->peRed, 0, 0);
        ++pEntry;
    }

    sub_004FB010_SetPaletteTables();
    D2GFX_SetPalette(gRGBAPalette_0081E668);
    FOG_Free(pDat, gszD2WinPaletteSourceFile_006DC828, 150, 0);
    FOG_Free(pTables, gszD2WinPaletteSourceFile_006DC828, 153, 0);
    return 1;
}

#include "gen/data/Source/D2Win/Src/D2WinPalette.inc"
