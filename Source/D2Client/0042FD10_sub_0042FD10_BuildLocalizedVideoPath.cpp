struct D2ConfigStrc;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);         // 0x004192F0
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
int __cdecl sub_00525150();                                                                         // 0x00525150
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_004317D0_FlushInput();                                                                     // 0x004317D0
int __cdecl sub_004F9050();                                                                                 // 0x004F9050
int __cdecl sub_0040EB10();                                                                                 // 0x0040EB10
void __stdcall sub_004F5D90_PlayVideo(const char* szFile, int nMode, int nArg);                             // 0x004F5D90
void __stdcall D2Win_10004(int nResolution);                                                                // 0x004F9060
int __stdcall sub_00431600_ShowLevelScreen(int nUnused);                                                    // 0x00431600
void __cdecl sub_0042FB20();                                                                                // 0x0042FB20
void __cdecl sub_004FAD70();                                                                                // 0x004FAD70
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion);                 // 0x004FAD10
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
int __cdecl sub_00431A00_ShowDiscMessage();                                                                 // 0x00431A00
int __cdecl sub_00434220_PlayDisc();                                                                        // 0x00434220
int __cdecl sub_004342E0_ExpansionDisc();                                                                   // 0x004342E0

extern "C" const char gszDataLocal_006D41A8[];                                                              // 0x006D41A8
extern D2ConfigStrc* gpConfig_007795D4;                                                                     // 0x007795D4

static int sub_0042FCE0_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    sub_004198D0(hFile);
    return 1;
}

// 0x0042FD10
static void sub_0042FD10_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    sub_00525260(szLang, 0);
    sprintf(szOut, szFormat, gszDataLocal_006D41A8, szLang, szFile);
    if (sub_0042FCE0_ArchiveFilePresent(szOut))
        return;
    if (sub_00525150())
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "ENG", szFile);
        sub_0042FCE0_ArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "CHI", szFile);
        sub_0042FCE0_ArchiveFilePresent(szOut);
    }
}

// 0x00431870
static void __stdcall sub_00431870_PlayVideo(int nArg, const char* szFormat)
{
    char szPath[0x104];
    char szSize[8];
    sub_0042F480_Reset();
    sub_0042F3F0_DestroyControls();
    sub_004317D0_FlushInput();
    if (sub_004F9050())
    {
        int nMode = 0;
        if (!sub_0040EB10())
        {
            strcpy(szSize, "640x292");
        }
        else
        {
            nMode = 2;
            strcpy(szSize, "640x146");
        }
        sub_0042FD10_BuildLocalizedVideoPath(szPath, szFormat, szSize);
        sub_004F5D90_PlayVideo(szPath, nMode, 0);
        D2Win_10004(1);
    }
    sub_004317D0_FlushInput();
    sub_00431600_ShowLevelScreen(nArg);
}

// 0x00433640
void __cdecl sub_00433640_PlayIntroVideo()
{
    char szPath[0x104];
    char szSize[8];
    sub_004317D0_FlushInput();
    int nMode = 0;
    if (!sub_0040EB10())
    {
        strcpy(szSize, "640x292");
    }
    else
    {
        nMode = 2;
        strcpy(szSize, "640x146");
    }
    sub_0042FD10_BuildLocalizedVideoPath(szPath, "%s\\video\\%s\\d2intro%s.bik", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    sub_0042FB20();
}

// 0x00434320
int __stdcall sub_00434320_PlayD2Intro(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\d2intro%s.bik");
    return 1;
}

// 0x00434380
int __stdcall sub_00434380_PlayAct2Start(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act02start%s.bik");
    return 1;
}

// 0x004343E0
int __stdcall sub_004343E0_PlayAct3Start(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act03start%s.bik");
    return 1;
}

// 0x00434440
int __stdcall sub_00434440_PlayAct4Start(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act04start%s.bik");
    return 1;
}

// 0x004344A0
int __stdcall sub_004344A0_PlayAct4End(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadVideoArchives((void*)sub_00431A00_ShowDiscMessage, 0, 0))
    {
        sub_004FAD70();
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\Act04end%s.bik");
    return 1;
}

// 0x00434500
int __stdcall sub_00434500_PlayXIntro(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\D2x_Intro_%s.bik");
    return 1;
}

// 0x00434560
int __stdcall sub_00434560_PlayXOutro(int nArg)
{
    sub_004FAD70();
    if (!ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
    sub_00431870_PlayVideo(nArg, "%s\\video\\%s\\D2x_Out_%s.bik");
    return 1;
}
