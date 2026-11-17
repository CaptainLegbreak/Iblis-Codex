typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" size_t __cdecl strlen(const char* szString);
char* __stdcall SStrChr(const char* szString, char nChar);                                                  // 0x00413490
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText);                                              // 0x00446A90
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor);                                          // 0x0043E610
void __fastcall sub_00447560_SplitName(const char* szName, char* szTitle, char* szOut);                     // 0x00447560
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList();                                                   // 0x00611560
char gszLastWhisperer_0077B0D0[256];                                                                        // 0x0077B0D0

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

// 0x00448810
static void __stdcall sub_00448810(const char* szSender, const char* szAccount, const char* szMessage)
{
    char szText[0x1F4];
    Unicode wszText[0x240];
    strcpy(gszLastWhisperer_0077B0D0, szSender);
    if (*szAccount && (*szAccount != '*' || strcmp(SkipStarPrefix_Inl(szAccount), SkipStarPrefix_Inl(szSender))))
    {
        sprintf(szText, "%s (*%s) whispers: %s", szAccount, szSender, szMessage);
    }
    else
    {
        sprintf(szText, "%s whispers: %s", szAccount, szMessage);
    }
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 2);
}

// 0x00448920
int __stdcall sub_00448920_OnWhisper(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szAccount[0x100];
    sub_00447560_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
    {
        return 1;
    }
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
        sub_00448810(SkipStarPrefix_Inl(szSender), szAccount, szMessage);
    }
    else
    {
        sub_00448810(SkipStarPrefix_Inl(szSender), 0, szMessage);
    }
    return 1;
}
