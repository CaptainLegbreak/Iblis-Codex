#include "D2Win.h"

extern "C" const char gszPathFormat_006D4124[];                                                             // 0x006D4124
extern "C" const char szPalDat_006DC7FC[];                                                                  // 0x006DC7FC

int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName);           // 0x004FB1E0
void __fastcall sub_005055D0_ApplyPalette();                                                                // 0x005055D0

// 0x004FB500
int __stdcall D2Win_10028(const char* pszPalDatFilename, const char* pszPalPL2Filename)
{
    if (!pszPalDatFilename)
    {
        char szPalDatFilename[260];
        char szPalPL2Filename[260];
        wsprintfA(szPalDatFilename, gszPathFormat_006D4124, szDataGlobal_006D4118, szPalDat_006DC7FC);
        wsprintfA(szPalPL2Filename, gszPathFormat_006D4124, szDataGlobal_006D4118, "palette\\act1\\pal.pl2");
        sub_004FB1E0_LoadPaletteFiles(szPalDatFilename, szPalPL2Filename);
    }
    else
    {
        sub_004FB1E0_LoadPaletteFiles(pszPalDatFilename, pszPalPL2Filename);
    }

    sub_005055D0_ApplyPalette();
    return 1;
}

#include "gen/data/Source/D2Win/Unknown_004FB500.inc"
