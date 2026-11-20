#include "D2Win.h"

struct T004F51E0;
struct D2Palette256Strc;

int __cdecl sub_004F59A0(); // 0x004F59A0
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332
void __fastcall sub_005173AC_Unload(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC
extern "C" const char gszExpansionMpq_006CD3A0[]; // 0x006CD3A0
extern "C" const char szPatchD2Mpq_006DC728[]; // 0x006DC728
extern "C" const char szD2SfxMpq_006DC764[]; // 0x006DC764
extern "C" const char szD2DataMpq_006DC770[]; // 0x006DC770
extern D2ArchiveHandleStrc* gpD2CharMPQ; // 0x007D5610
extern D2ArchiveHandleStrc* gpD2XTalkMPQ; // 0x007D5618
extern D2ArchiveHandleStrc* gpD2MusicMPQ; // 0x007D5628

struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette); // 0x004F63D0
extern int dword_6F8BE008; // 0x0072DE50
extern T004F51E0 gRGBAPalette_0081E668[]; // 0x0081E668
extern D2Palette256Strc gShadowsLightGammaPalette_0081EA68[49]; // 0x0081EA68
extern int gdwGlobal_00841B70; // 0x00841B70

// 0x004FAB00
int __cdecl sub_004FAB00_ShowInsertExpansionDisc()
{
    return MessageBoxA((void*)sub_004F59A0(), "Insert Expansion Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB30
int __cdecl sub_004FAB30_ShowInsertPlayDisc()
{
    return MessageBoxA((void*)sub_004F59A0(), "Insert Play Disc", "Diablo II", 0x31) == 1;
}

// 0x004FAB60
int __cdecl sub_004FAB60_ShowInsertDisc()
{
    return MessageBoxA((void*)sub_004F59A0(), "Insert Cinematics Disc", "Diablo II", 0x31) == 1;
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
    gpD2DataMPQ = sub_00517332_LoadMpqFile(szD2DataMpq_006DC770, 0, 0, 1000);
    gpD2SfxMPQ = sub_00517332_LoadMpqFile(szD2SfxMpq_006DC764, 0, 0, 1000);
    gpD2SpeechMPQ = sub_00517332_LoadMpqFile("d2speech.mpq", 0, 0, 1000);
    gpD2DeltaMPQ = sub_00517332_LoadMpqFile("d2delta.mpq", 0, 0, 1000);
    gpD2kfixupMPQ = sub_00517332_LoadMpqFile("d2kfixup.mpq", 0, 0, 1000);
    gpD2PatchMPQ = sub_00517332_LoadMpqFile(szPatchD2Mpq_006DC728, 0, 0, 5000);
    gpD2ExpMPQ = sub_00517332_LoadMpqFile(gszExpansionMpq_006CD3A0, 0, 0, 3000);

    return sub_00406D20() || gpD2DataMPQ && gpD2SfxMPQ && gpD2SpeechMPQ && (!sub_00408F20_HasExpansionMpq() || gpD2ExpMPQ);
}

// 0x004FAC80
void* __stdcall D2Win_GetArchive()
{
    return 0;
}

// 0x004FAD70
void __cdecl ARCHIVE_UnloadExpansionArchives()
{
    if (gpD2MusicMPQ)
    {
        sub_005173AC_Unload(gpD2MusicMPQ);
        gpD2MusicMPQ = 0;
    }

    if (gpD2CharMPQ)
    {
        sub_005173AC_Unload(gpD2CharMPQ);
        gpD2CharMPQ = 0;
    }

    if (gpD2VideoMPQ)
    {
        sub_005173AC_Unload(gpD2VideoMPQ);
        gpD2VideoMPQ = 0;
    }

    if (gpD2XMusicMPQ)
    {
        sub_005173AC_Unload(gpD2XMusicMPQ);
        gpD2XMusicMPQ = 0;
    }

    if (gpD2XTalkMPQ)
    {
        sub_005173AC_Unload(gpD2XTalkMPQ);
        gpD2XTalkMPQ = 0;
    }

    if (gpD2XVideoMPQ)
    {
        sub_005173AC_Unload(gpD2XVideoMPQ);
        gpD2XVideoMPQ = 0;
    }
}

// 0x004FAE00
void __cdecl ARCHIVE_FreeArchives()
{
    if (gpD2DataMPQ)
    {
        sub_005173AC_Unload(gpD2DataMPQ);
        gpD2DataMPQ = 0;
    }

    if (gpD2SpeechMPQ)
    {
        sub_005173AC_Unload(gpD2SpeechMPQ);
        gpD2SpeechMPQ = 0;
    }

    if (gpD2SfxMPQ)
    {
        sub_005173AC_Unload(gpD2SfxMPQ);
        gpD2SfxMPQ = 0;
    }

    if (gpD2DeltaMPQ)
    {
        sub_005173AC_Unload(gpD2DeltaMPQ);
        gpD2DeltaMPQ = 0;
    }

    if (gpD2kfixupMPQ)
    {
        sub_005173AC_Unload(gpD2kfixupMPQ);
        gpD2kfixupMPQ = 0;
    }

    if (gpD2ExpMPQ)
    {
        sub_005173AC_Unload(gpD2ExpMPQ);
        gpD2ExpMPQ = 0;
    }

    if (gpD2XMusicMPQ)
    {
        sub_005173AC_Unload(gpD2XMusicMPQ);
        gpD2XMusicMPQ = 0;
    }

    if (gpD2PatchMPQ)
    {
        sub_005173AC_Unload(gpD2PatchMPQ);
        gpD2PatchMPQ = 0;
    }

    ARCHIVE_UnloadExpansionArchives();
}

int dword_6F90E290; // 0x007D5638

unsigned char gStatesPalette_6F9626C0[128][0x100]; // 0x007D6468

int dword_6F96A7C0; // 0x00841B68

unsigned long dword_6F96A7C4; // 0x00841B6C

// 0x004FB0C0
unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex)
{
    return gStatesPalette_6F9626C0[nIndex];
}

// 0x004FB0D0
void __stdcall D2Win_10179()
{
    if (!dword_6F8BE008)
    {
        return;
    }

    if (dword_6F96A7C0)
    {
        if (GetTickCount() - dword_6F96A7C4 <= 2000)
        {
            return;
        }

        dword_6F96A7C4 = GetTickCount();

        --dword_6F90E290;
        if (dword_6F90E290 > 0)
        {
            D2GFX_SetPalette(gRGBAPalette_0081E668);
            return;
        }

        dword_6F96A7C0 = 0;
    }

    dword_6F8BE008 = 0;
    D2GFX_SetPalette(gRGBAPalette_0081E668);
}

// 0x004FB130
void __fastcall D2Win_10176(int bTimed)
{
    if (bTimed)
    {
        dword_6F96A7C0 = 1;
        dword_6F96A7C4 = GetTickCount();
        dword_6F90E290 = 2;
        dword_6F8BE008 = 1;
        D2GFX_SetPalette(gRGBAPalette_0081E668);
    }
    else
    {
        dword_6F96A7C0 = 0;
        dword_6F8BE008 = 0;
        D2GFX_SetPalette(gRGBAPalette_0081E668);
    }
}

// 0x004FB1C0
void __fastcall sub_004FB1C0_CopyRowTable(unsigned char (*pRows)[0x100])
{
    memcpy(pRows, gShadowsLightGammaPalette_0081EA68, sizeof(gShadowsLightGammaPalette_0081EA68));
}

// 0x004FB590
void __fastcall sub_004FB590(int nValue)
{
    gdwGlobal_00841B70 = nValue;
}

#include "gen/data/Source/D2Win/Unknown_004FAB00.inc"
