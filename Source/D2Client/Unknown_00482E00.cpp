#include "D2Client.h"
#include "D2Structs.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2AuxLevelEntryStrc;
struct Unicode;
struct D2InventoryGridInfoStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2AuxLevelEntryStrc
{
    int nType;
    const char* szFile;
    char bLocalized;
    char bFormat;
    char unk0x0A[2];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_00478590(char nValue); // 0x00478590
void __fastcall sub_00482CA0_RaiseAuxLevel(int nIndex); // 0x00482CA0
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion); // 0x004FAD10
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480
void __fastcall sub_00460480(int bExpansion); // 0x00460480
int __cdecl sub_00460500_RunPopup(); // 0x00460500
int __cdecl sub_00460680_RunOkCancel(); // 0x00460680
int __cdecl sub_004605A0_RunPopup(); // 0x004605A0
void __cdecl sub_00477DD0(); // 0x00477DD0
void __cdecl sub_00481830(); // 0x00481830
void __cdecl sub_004DC0A0(); // 0x004DC0A0
void __fastcall sub_0044D530(int nValue); // 0x0044D530
void __cdecl sub_0044D510(); // 0x0044D510
void __cdecl sub_0044DD60(); // 0x0044DD60
extern "C" const char gsz640x146_006D4214[]; // 0x006D4214
extern "C" const char gsz640x292_006D421C[]; // 0x006D421C
extern int gnAuxLevelEntries_00721D94; // 0x00721D94
extern D2AuxLevelEntryStrc gaAuxLevelEntries_00721D98[]; // 0x00721D98
extern D2ConfigStrc* gpConfig_007A0438; // 0x007A0438
extern char gbCinematicStop_007BC9D4; // 0x007BC9D4
extern char gbCinematicPlaying_007BC9D5; // 0x007BC9D5
extern char gbCinematicWide_007BC9D6; // 0x007BC9D6
extern char gbCinematicBusy_007BC9D7; // 0x007BC9D7
extern char gbCinematicChain_007BC9D8; // 0x007BC9D8

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0


void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, int nFlags); // 0x0046EFD0
extern int gnScreenHeight_007A521C; // 0x007A521C
extern int gnScreenWidth_007A5220; // 0x007A5220
extern unsigned char gabGridColors_007BCAD8[]; // 0x007BCAD8
static __declspec(noinline) void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY);

// 0x00482E00
static int sub_00482E00_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    sub_004198D0(hFile);
    return 1;
}

// 0x00482E30
static void sub_00482E30_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    sub_00525260(szLang, 0);
    sprintf(szOut, szFormat, gszDataLocal_006D41A8, szLang, szFile);
    if (sub_00482E00_ArchiveFilePresent(szOut))
        return;
    if (STRTABLE_GetLanguage())
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "ENG", szFile);
        sub_00482E00_ArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "CHI", szFile);
        sub_00482E00_ArchiveFilePresent(szOut);
    }
}

char gbCinematicStop_007BC9D4; // 0x007BC9D4

char gbCinematicPlaying_007BC9D5; // 0x007BC9D5

char gbCinematicWide_007BC9D6; // 0x007BC9D6

char gbCinematicBusy_007BC9D7; // 0x007BC9D7

char gbCinematicChain_007BC9D8; // 0x007BC9D8

// 0x00482EF0
void __fastcall sub_00482EF0_PlayCinematic(int nIndex)
{
    int nMode;
    int bPlayed;
    int bLoaded;
    int bExpansion;
    char szName[0x104];
    char szFile[0x104];

    D2_ASSERT(nIndex < gnAuxLevelEntries_00721D94, 0xEF);
    gbCinematicBusy_007BC9D7 = 1;
    sub_00482CA0_RaiseAuxLevel(nIndex);
    if (gbCinematicPlaying_007BC9D5)
        return;

    if (nIndex >= gnAuxLevelEntries_00721D94)
    {
        sub_00478590(0x48);
        gbCinematicBusy_007BC9D7 = 0;
        return;
    }

    nMode = 0;
    if (gaAuxLevelEntries_00721D98[nIndex].bFormat)
    {
        if (gbCinematicWide_007BC9D6)
        {
            sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x292_006D421C);
        }
        else
        {
            nMode = 2;
            sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x146_006D4214);
        }
    }
    else
    {
        strcpy(szName, gaAuxLevelEntries_00721D98[nIndex].szFile);
    }

    sub_00481830();
    sub_004DCA30();
    sub_004FAD70();

    bExpansion = 0;
    bPlayed = bLoaded = 0;
    if (nIndex == 7)
    {
        bExpansion = 1;
        char szPath[0x104];
        FOG_GetInstallPath(szPath, 0x104);
        strcat(szPath, "d2game.dll");
        void* hFile = CreateFileA(szPath, 0, 1, 0, 3, 0x80, 0);
        if (hFile != (void*)-1)
        {
            CloseHandle(hFile);
        }
        else
        {
            sub_0044D530(0);
            goto lMissing;
        }
    }
    else if (nIndex == 6)
    {
        bExpansion = 1;
    }

    sub_00460480(bExpansion);
    if (ARCHIVE_LoadVideoArchives(bExpansion ? (void*)sub_00460500_RunPopup : (void*)sub_00460680_RunOkCancel, 0, bExpansion))
    {
        bLoaded = 1;
        if (gaAuxLevelEntries_00721D98[nIndex].bLocalized)
            sub_00482E30_BuildLocalizedVideoPath(szFile, "%s\\video\\%s\\%s", szName);
        else
            sprintf(szFile, "%s\\video\\%s", szDataGlobal_006D4118, szName);

        gbCinematicPlaying_007BC9D5 = 1;
        sub_004DC0A0();
        sub_00455F20(0x12, 0, 0);
        if (sub_004F9050())
        {
            if (gbCinematicStop_007BC9D4)
                WINDOW_OpenSmackCutscene(szFile, nMode, 0);
            else
                WINDOW_OpenSmackCutscene(szFile, nMode, (void*)sub_00477DD0);
            bPlayed = 1;
        }

        if (nIndex != 5 || !gbCinematicChain_007BC9D8)
        {
            D2Win_10004(D2GFX_GetResolutionMode());
            sub_00455F20(0x12, 1, 0);
            gbCinematicPlaying_007BC9D5 = 0;
        }
    }

    if (gbCinematicChain_007BC9D8)
    {
        if (bLoaded)
            sub_004FAD70();
        if (bPlayed)
            D2Win_10004(D2GFX_GetResolutionMode());

        sub_00460480(1);
        if (ARCHIVE_LoadVideoArchives((void*)sub_00460500_RunPopup, 0, 1))
        {
            nIndex = 6;
            if (gbCinematicWide_007BC9D6)
            {
                sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x292_006D421C);
            }
            else
            {
                nMode = 2;
                sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x146_006D4214);
            }

            if (gaAuxLevelEntries_00721D98[nIndex].bLocalized)
                sub_00482E30_BuildLocalizedVideoPath(szFile, "%s\\video\\%s\\%s", szName);
            else
                sprintf(szFile, "%s\\video\\%s", szDataGlobal_006D4118, szName);

            if (sub_004F9050())
            {
                WINDOW_OpenSmackCutscene(szFile, nMode, (void*)sub_00477DD0);
                sub_00482CA0_RaiseAuxLevel(nIndex);
            }
        }

        D2Win_10004(D2GFX_GetResolutionMode());
        sub_00455F20(0x12, 1, 0);
        gbCinematicPlaying_007BC9D5 = 0;
        gbCinematicChain_007BC9D8 = 0;
        D2Win_10177(4);
    }

    sub_00478590(0x48);
    if (gbCinematicStop_007BC9D4)
    {
        gbCinematicStop_007BC9D4 = 0;
        sub_0044DD60();
    }
    else if (nIndex == 7)
    {
lMissing:
        sub_0044D530(0);
        gbCinematicStop_007BC9D4 = 0;
        sub_0044D510();
        sub_0044DD60();
    }

    sub_004FAD70();
    ARCHIVE_LoadExpansionArchives(sub_00460500_RunPopup, sub_004605A0_RunPopup, 0, gpConfig_007A0438);
    gbCinematicBusy_007BC9D7 = 0;
}

#include "gen/data/Source/D2Client/Unknown_00482E00.inc"

// 0x004834E0
void __fastcall sub_004834E0_ReplaceToken(Unicode* pText, int nIndex, const Unicode* pInsert)
{
    Unicode wszBuffer[400];
    const int nDigit = nIndex + '0';
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength - 1; ++i)
    {
        if (pText[i].wChar == '%' && pText[i + 1].wChar == nDigit)
        {
            sub_00526700(wszBuffer, pInsert);
            const Unicode* pEnd = &wszBuffer[sub_00526800(wszBuffer) - 1];
            const int bSpace = pEnd->wChar == ' ';
            Unicode* pDest = pText;
            const Unicode* pRest;
            if (!(bSpace && pDest[i + 2].wChar == ' '))
            {
                pRest = &pDest[i + 2];
                sub_00526700(wszBuffer, pRest);
            }
            else
            {
                pRest = &pDest[i + 3];
                sub_00526700(wszBuffer, pRest);
            }
            sub_005267E0(pDest, wszBuffer);
            return;
        }
        wszBuffer[i] = pText[i];
    }
}

// 0x004839D0
static void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY)
{
    for (int nRow = nY; nRow < nY + nHeight; ++nRow)
    {
        for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
        {
            const int nLeft = pGrid->nGridBoxWidth * nColumn + pGrid->nGridLeft;
            const int nTop = pGrid->nGridBoxHeight * nRow + pGrid->nGridTop;
            if (nLeft >= 0 && nLeft < gnScreenWidth_007A5220 && nTop >= 0 && nTop < gnScreenHeight_007A521C)
            {
                sub_0046EFD0_DrawFramedBox(nLeft, nTop, pGrid->nGridBoxWidth, pGrid->nGridBoxHeight, gabGridColors_007BCAD8[nColor], 0);
            }
        }
    }
}

// build: context sub_004839D0_Shim
// calling-convention shim (not game code)
void __fastcall sub_004839D0_Shim(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight)
{
    sub_004839D0_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
    sub_004839D0_DrawGridCells(pGrid, nY, 0, nHeight, nWidth, nX);
}
