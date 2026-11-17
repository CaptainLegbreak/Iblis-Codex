#include "D2Client.h"

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __cdecl sub_00525150();                                                                         // 0x00525150

// 0x0042FCE0
static int sub_0042FCE0_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    sub_004198D0(hFile);
    return 1;
}

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

void __fastcall sub_J02_EmitLaunchVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    sub_0042FD10_BuildLocalizedVideoPath(szOut, szFormat, szFile);
    sub_0042FD10_BuildLocalizedVideoPath(szOut + 1, szFormat, szFile);
}
