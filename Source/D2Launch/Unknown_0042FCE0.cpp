#include "D2Launch.h"

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

// 0x0042FCE0
static int sub_0042FCE0_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    SFileCloseFile(hFile);
    return 1;
}

// build: symbol ?MAINMENUS_BuildLocalizedVideoPath@* 0x0042FD10
static void MAINMENUS_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(szLang, 0);
    sprintf(szOut, szFormat, gszDataLocal_006D41A8, szLang, szFile);
    if (sub_0042FCE0_ArchiveFilePresent(szOut))
        return;
    if (STRTABLE_GetLanguage())
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

void __fastcall sub_J02_EmitLaunchVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    MAINMENUS_BuildLocalizedVideoPath(szOut, szFormat, szFile);
    MAINMENUS_BuildLocalizedVideoPath(szOut + 1, szFormat, szFile);
}
