typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" size_t __cdecl strlen(const char* szString);
char* __stdcall SStrChr(const char* szString, char nChar);                                                  // 0x00413490
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText);                                              // 0x00446A90
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor);                                          // 0x0043E610
void __fastcall sub_00447560_SplitName(const char* szName, char* szTitle, char* szOut);                     // 0x00447560

static const char* SkipStarPrefix_Inl(const char* szName)
{
    const char* p = SStrChr(szName, '*');
    if (p)
    {
        p++;
        if (*p)
        {
            return p;
        }
    }
    return szName;
}

// 0x00448A60
static void sub_00448A60_PrintWhisperSent(const char* szName, const char* szText)
{
    char szLine[0x1F4];
    Unicode wszLine[0x240];
    sprintf(szLine, "You whisper to %s: %s", szName, szText);
    for (int i = 0; i < 0x240; i++)
        wszLine[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszLine, szLine, 0x240);
    sub_00446A90_RemoveTableString(wszLine);
    sub_0043E610_PrintText(wszLine, 2);
}

// 0x00448AD0
int __stdcall sub_00448AD0_OnWhisperSent(const char* szTarget, const char* szText)
{
    char szName[0x100];
    char szTitle[0x100];
    char szAccount[0x100];
    sub_00447560_SplitName(szTarget, szTitle, szName);
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szAccount, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szAccount, szName);
        }
        sub_00448A60_PrintWhisperSent(szAccount, szText);
    }
    else
    {
        sub_00448A60_PrintWhisperSent(SkipStarPrefix_Inl(szTarget), szText);
    }
    return 1;
}
