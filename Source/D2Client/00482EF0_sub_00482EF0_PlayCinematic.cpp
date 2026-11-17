extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ConfigStrc;

struct D2AuxLevelEntryStrc
{
    int nType;
    const char* szFile;
    char bLocalized;
    char bFormat;
    char unk0x0A[2];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);         // 0x004192F0
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
int __cdecl sub_00525150();                                                                         // 0x00525150
void __fastcall FOG_GetInstallPath(char* szPath, int nBufferSize);                                          // 0x00406BA0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __fastcall sub_00478590(char nValue);                                                                  // 0x00478590
void __fastcall sub_00482CA0_RaiseAuxLevel(int nIndex);                                                     // 0x00482CA0
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion);                 // 0x004FAD10
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame);                // 0x004F5D90
int __cdecl sub_004F9050();                                                                                 // 0x004F9050
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
void __stdcall D2Win_10004(int nResolution);                                                                // 0x004F9060
int __fastcall D2Win_10177(unsigned char nAct);                                                             // 0x004FB480
void __fastcall sub_00460480(int bExpansion);                                                               // 0x00460480
int __cdecl sub_00460500();                                                                                 // 0x00460500
int __cdecl sub_00460680();                                                                                 // 0x00460680
int __cdecl sub_004605A0();                                                                                 // 0x004605A0
void __cdecl sub_00477DD0();                                                                                // 0x00477DD0
void __cdecl sub_00481830();                                                                                // 0x00481830
void __cdecl sub_004DCA30();                                                                                // 0x004DCA30
void __cdecl sub_004FAD70();                                                                                // 0x004FAD70
void __cdecl sub_004DC0A0();                                                                                // 0x004DC0A0
void __fastcall sub_0044D530(int nValue);                                                                   // 0x0044D530
void __cdecl sub_0044D510();                                                                                // 0x0044D510
void __cdecl sub_0044DD60();                                                                                // 0x0044DD60

extern "C" const char gszDataLocal_006D41A8[];                                                              // 0x006D41A8
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gsz640x146_006D4214[];                                                                // 0x006D4214
extern "C" const char gsz640x292_006D421C[];                                                                // 0x006D421C
extern int gnAuxLevelEntries_00721D94;                                                                      // 0x00721D94
extern D2AuxLevelEntryStrc gaAuxLevelEntries_00721D98[];                                                    // 0x00721D98
extern D2ConfigStrc* gpConfig_007A0438;                                                                     // 0x007A0438
char gbCinematicStop_007BC9D4;                                                                              // 0x007BC9D4
char gbCinematicPlaying_007BC9D5;                                                                           // 0x007BC9D5
char gbCinematicWide_007BC9D6;                                                                              // 0x007BC9D6
char gbCinematicBusy_007BC9D7;                                                                              // 0x007BC9D7
char gbCinematicChain_007BC9D8;                                                                             // 0x007BC9D8

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
    if (sub_00525150())
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
    if (ARCHIVE_LoadVideoArchives(bExpansion ? (void*)sub_00460500 : (void*)sub_00460680, 0, bExpansion))
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
        if (ARCHIVE_LoadVideoArchives((void*)sub_00460500, 0, 1))
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
    ARCHIVE_LoadExpansionArchives(sub_00460500, sub_004605A0, 0, gpConfig_007A0438);
    gbCinematicBusy_007BC9D7 = 0;
}

#include "gen/data/Source/D2Client/00482EF0_sub_00482EF0_PlayCinematic.inc"
