#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2MultiTypes.h"

struct Unicode;
struct D2MultiChannelUserStrc;
struct D2LaunchFuncsStrc;

struct Unicode
{
    unsigned short wChar;
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);                      // 0x00526F20
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
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" size_t __cdecl strlen(const char* szString);
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __stdcall CHATDLG_RemoveTableString(Unicode* pText); // 0x00446A90
void __fastcall COMCALLBACK_PrependNumberText(Unicode* pText, int nValue); // 0x00447940
void __fastcall COMCALLBACK_AppendNumberText(Unicode* pText, int nValue); // 0x00447870
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor); // 0x0043E610
void __fastcall COMCALLBACK_SplitName(const char* szName, char* szTitle, char* szOut); // 0x00447560
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern D2MultiChannelUserStrc* gpChannelUsers_00798F34; // 0x00798F34
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40

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

// 0x00447B00
static void __stdcall COMCALLBACK_PrintChannelLine(const char* szText, int nPrefix, const char* szName, int nColor)
{
    Unicode wszName[0x240];
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszName[i].wChar = 0;
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    Unicode::win2Unicode(wszName, szName, 0x240);
    Unicode::win2Unicode(wszText, szText, 0x240);
    CHATDLG_RemoveTableString(wszName);
    CHATDLG_RemoveTableString(wszText);
    COMCALLBACK_PrependNumberText(wszName, nPrefix);
    COMCALLBACK_AppendNumberText(wszName, nColor);
    sub_00526700(wszName, wszText);
    sub_0043E610_PrintText(wszName, nColor);
}

// 0x004481B0
static void __stdcall COMCALLBACK_PrintNamedLine(const char* szText, int nPrefix, const char* szName, int nColor)
{
    char szBuffer[0x100];
    sprintf(szBuffer, "<%s> ", szName);
    COMCALLBACK_PrintChannelLine(szText, nPrefix, szBuffer, nColor);
}

// 0x004481F0
void __fastcall COMCALLBACK_PrintOwnLine(const char* szText)
{
    char szName[0x100];
    char szOut[0x100];
    char szPlain[0x100];
    char szTitle[0x100];
    SStrCopy(szName, gpLaunchFuncs_0077B09C->pfnGetUserName(), 0x7FFFFFFF);
    int nPrefix = 4;
    int nColor = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
        do
        {
            if (!strcmp(SkipStarPrefix_Inl(pUser->szName), szName))
            {
                SStrCopy(szName, pUser->szName, 0x7FFFFFFF);
                if (pUser->dwFlags & 2)
                    nPrefix = 0;
                else if (pUser->dwFlags & 1)
                    nPrefix = nColor = 3;
                else if (pUser->dwFlags & 8)
                    nPrefix = nColor = 3;
                break;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }
    COMCALLBACK_SplitName(szName, szTitle, szPlain);
    if (strlen(szPlain))
    {
        if (strlen(szTitle))
            sprintf(szOut, "<%s%s> ", szTitle, szPlain);
        else
            sprintf(szOut, "<%s> ", szPlain);
    }
    else
    {
        sprintf(szOut, "<%s> ", szName);
    }
    COMCALLBACK_PrintChannelLine(szText, nPrefix, szOut, nColor);
}

// 0x00448370
int __stdcall COMCALLBACK_OnChannelTalk(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szOut[0x100];
    COMCALLBACK_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
        return 1;

    int nPrefix = 4;
    int nColor = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
        do
        {
            if (!strcmp(pUser->szName, szSender))
            {
                if (pUser->dwFlags & 2)
                    nPrefix = 0;
                else if (pUser->dwFlags & 1)
                    nPrefix = nColor = 3;
                else if (pUser->dwFlags & 8)
                    nPrefix = nColor = 3;
                break;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
            sprintf(szOut, "%s%s", szTitle, szName);
        else
            strcpy(szOut, szName);
        COMCALLBACK_PrintNamedLine(szMessage, nPrefix, szOut, nColor);
    }
    else
    {
        COMCALLBACK_PrintNamedLine(szMessage, nPrefix, szSender, nColor);
    }
    return 1;
}

// 0x00448680
static void COMCALLBACK_PrintEmote(const char* szName, const char* szMessage)
{
    char szText[0x1F4];
    Unicode wszText[0x240];
    sprintf(szText, "*%s %s*", szName, szMessage);
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    CHATDLG_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 5);
}

// 0x004486F0
int __stdcall COMCALLBACK_OnEmote(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szOut[0x100];
    COMCALLBACK_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
    {
        return 1;
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szOut, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szOut, szName);
        }
        COMCALLBACK_PrintEmote(szOut, szMessage);
    }
    else
    {
        COMCALLBACK_PrintEmote(szSender, szMessage);
    }
    return 1;
}

char gszLastWhisperer_0077B0D0[256]; // 0x0077B0D0

// 0x00448810
static void __stdcall COMCALLBACK_PrintWhisper(const char* szSender, const char* szAccount, const char* szMessage)
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
    CHATDLG_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 2);
}

// 0x00448920
int __stdcall COMCALLBACK_OnWhisper(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szAccount[0x100];
    COMCALLBACK_SplitName(szSender, szTitle, szName);
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
        COMCALLBACK_PrintWhisper(SkipStarPrefix_Inl(szSender), szAccount, szMessage);
    }
    else
    {
        COMCALLBACK_PrintWhisper(SkipStarPrefix_Inl(szSender), 0, szMessage);
    }
    return 1;
}
