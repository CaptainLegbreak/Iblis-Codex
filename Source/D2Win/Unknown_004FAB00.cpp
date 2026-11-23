#include "D2Win.h"
#include "D2Win32Types.h"

struct D2Palette256Strc;

int __cdecl WINDOW_GetWindow(); // 0x004F59A0
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332
void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC
extern "C" const char gszExpansionMpq[]; // 0x006CD3A0
extern "C" const char gszPatchD2Mpq[]; // 0x006DC728
extern "C" const char gszD2SfxMpq[]; // 0x006DC764
extern "C" const char gszD2DataMpq[]; // 0x006DC770
extern D2ArchiveHandleStrc* gpD2CharMPQ; // 0x007D5610
extern D2ArchiveHandleStrc* gpD2XTalkMPQ; // 0x007D5618
extern D2ArchiveHandleStrc* gpD2MusicMPQ; // 0x007D5628

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
extern int gbPaletteFlash; // 0x0072DE50
extern tagPALETTEENTRY gatRGBAPalette[]; // 0x0081E668
extern D2Palette256Strc gatShadowsLightGammaPalette[49]; // 0x0081EA68
extern int gbTextBoxSmallGap; // 0x00841B70

// 0x004FAB00
int __cdecl sub_004FAB00_ShowInsertExpansionDisc()
{
    return MessageBoxA((void*)WINDOW_GetWindow(), "Insert Expansion Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB30
int __cdecl sub_004FAB30_ShowInsertPlayDisc()
{
    return MessageBoxA((void*)WINDOW_GetWindow(), "Insert Play Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB60
int __cdecl sub_004FAB60_ShowInsertDisc()
{
    return MessageBoxA((void*)WINDOW_GetWindow(), "Insert Cinematics Disc", "Diablo II", 0x31) == 1;
}

D2ArchiveHandleStrc* gpD2XMusicMPQ; // 0x007D5604

D2ArchiveHandleStrc* gpD2SfxMPQ; // 0x007D5608

D2ArchiveHandleStrc* gpD2DeltaMPQ; // 0x007D560C

D2ArchiveHandleStrc* gpD2VideoMPQ; // 0x007D5614

D2ArchiveHandleStrc* gpD2DataMPQ; // 0x007D561C

D2ArchiveHandleStrc* gpD2kfixupMPQ; // 0x007D5620

D2ArchiveHandleStrc* gpD2SpeechMPQ; // 0x007D5624

D2ArchiveHandleStrc* gpD2PatchMPQ; // 0x007D5630

D2ArchiveHandleStrc* gpD2ExpMPQ; // 0x007D5634

// 0x004FAB90
int __cdecl ARCHIVE_LoadArchives()
{
    gpD2DataMPQ = sub_00517332_LoadMpqFile(gszD2DataMpq, 0, 0, 1000);
    gpD2SfxMPQ = sub_00517332_LoadMpqFile(gszD2SfxMpq, 0, 0, 1000);
    gpD2SpeechMPQ = sub_00517332_LoadMpqFile("d2speech.mpq", 0, 0, 1000);
    gpD2DeltaMPQ = sub_00517332_LoadMpqFile("d2delta.mpq", 0, 0, 1000);
    gpD2kfixupMPQ = sub_00517332_LoadMpqFile("d2kfixup.mpq", 0, 0, 1000);
    gpD2PatchMPQ = sub_00517332_LoadMpqFile(gszPatchD2Mpq, 0, 0, 5000);
    gpD2ExpMPQ = sub_00517332_LoadMpqFile(gszExpansionMpq, 0, 0, 3000);

// build: symbol ?FOG_IsExpansion@* 0x00408F20
    return sub_00406D20() || gpD2DataMPQ && gpD2SfxMPQ && gpD2SpeechMPQ && (!FOG_IsExpansion() || gpD2ExpMPQ);
}

// 0x004FB1C0
void __fastcall sub_004FB1C0_CopyRowTable(unsigned char (*pRows)[0x100])
{
    memcpy(pRows, gatShadowsLightGammaPalette, sizeof(gatShadowsLightGammaPalette));
}

int gnPaletteFlashCount; // 0x007D5638

unsigned char gabStatesPalette[128][0x100]; // 0x007D6468

int gbPaletteFlashWaiting; // 0x00841B68

unsigned long gdwPaletteFlashTick; // 0x00841B6C

// 0x004FB0C0
unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex)
{
    return gabStatesPalette[nIndex];
}

// 0x004FB0D0
void __stdcall D2Win_10179()
{
    if (!gbPaletteFlash)
    {
        return;
    }

    if (gbPaletteFlashWaiting)
    {
        if (GetTickCount() - gdwPaletteFlashTick <= 2000)
        {
            return;
        }

        gdwPaletteFlashTick = GetTickCount();

        --gnPaletteFlashCount;
        if (gnPaletteFlashCount > 0)
        {
            D2GFX_SetPalette(gatRGBAPalette);
            return;
        }

        gbPaletteFlashWaiting = 0;
    }

    gbPaletteFlash = 0;
    D2GFX_SetPalette(gatRGBAPalette);
}

// 0x004FB130
void __fastcall D2Win_10176(int bTimed)
{
    if (bTimed)
    {
        gbPaletteFlashWaiting = 1;
        gdwPaletteFlashTick = GetTickCount();
        gnPaletteFlashCount = 2;
        gbPaletteFlash = 1;
        D2GFX_SetPalette(gatRGBAPalette);
    }
    else
    {
        gbPaletteFlashWaiting = 0;
        gbPaletteFlash = 0;
        D2GFX_SetPalette(gatRGBAPalette);
    }
}

// 0x004FB590
void __fastcall sub_004FB590(int nValue)
{
    gbTextBoxSmallGap = nValue;
}

// 0x004FAC80
void* __stdcall D2Win_GetArchive()
{
    return 0;
}

#include "gen/data/Source/D2Win/Unknown_004FAB00.inc"
