#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"

struct D2LaunchCharInfoStrc;
struct D2MultiChannelUserStrc;
struct Unicode;
struct Character;

extern D2LaunchCharInfoStrc* gpCharInfo; // 0x0077BBD8
void __stdcall CHATDLG_EnableConnection(int bEnable); // 0x004413E0

unsigned int __stdcall SStrHashHT(const char* szPath); // 0x00414150
extern "C" int __cdecl isalnum(int c); // 0x006870FB
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
const char* __fastcall CHATDLG_SkipNamePrefix(const char* szName); // 0x00446820
void __fastcall CHATDLG_ShowMessage(const Unicode* pTitle, const Unicode* pText); // 0x0043EA70
int __stdcall MAINMENUS_FindCdKeyInText(const char* szText); // 0x0043E900
int __cdecl CHATDLG_SendChatBuffer(); // 0x00442810
extern D2MultiChannelUserStrc* gpSelectedChannelUser; // 0x00798F48

struct Character { signed char value; };

enum { FIRST_PRINTABLE = 32, AFTER_PRINTABLE = 128 };

// 0x004414C0
void __cdecl sub_004414C0_UpdateEnable()
{
    if (((*(unsigned short*)gpCharInfo->wFlags) & 8) && ((*(unsigned short*)gpCharInfo->wFlags) & 4))
    {
        return;
    }

    int bEnable = 0;
    if (gpCharInfo->nByte22D && !sub_00449B30_QueryAddress())
    {
        bEnable = 1;
    }

    CHATDLG_EnableConnection(bEnable);
}

char gszChatBuffer[0x200]; // 0x0077AE40

static int __stdcall sub_0043E860_FindHashedWord(unsigned int nHash, int nLength, char* szText)
{
    if (!nLength)
        return 0;

    const int nTextLength = SStrLen(szText);
    for (int i = 0; i <= nTextLength - nLength; ++i)
    {
        if (i > 0 && isalnum(szText[i - 1]))
            continue;

        if (i < nTextLength - nLength && isalnum(szText[i + nLength]))
            continue;

        const unsigned char c = szText[i + nLength];
        szText[i + nLength] = 0;
        const unsigned int nValue = SStrHashHT(&szText[i]);
        szText[i + nLength] = c;
        if (nValue == nHash)
            return 1;
    }

    return 0;
}

// 0x004428D0
int __fastcall sub_004428D0_SendChatText(char* szText, int bWhisper)
{
    const int bCommand = szText[0] == '/';
    SMemZero(gszChatBuffer, sizeof(gszChatBuffer));
    if (bWhisper && !bCommand && gpSelectedChannelUser)
        sprintf(gszChatBuffer, "/whisper *%s %s", CHATDLG_SkipNamePrefix(gpSelectedChannelUser->szName), szText);
    else
        strcpy(gszChatBuffer, szText);

    if (sub_0043E860_FindHashedWord(gpCharInfo->nWordHash, gpCharInfo->nWordLength, szText))
    {
        CHATDLG_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B37), D2LANG_GetStringFromTblIndex(0x2B38));
        gszChatBuffer[0] = 0;
        return 0;
    }

    if (MAINMENUS_FindCdKeyInText(szText))
    {
        CHATDLG_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B7A), D2LANG_GetStringFromTblIndex(0x2B7B));
        gszChatBuffer[0] = 0;
        return 0;
    }

    return CHATDLG_SendChatBuffer();
}

// 0x00442A70
void __fastcall sub_00442A70_SetFlagBits12(unsigned int* pFlags, int nValue)
{
    *pFlags = (*pFlags & 0xFFFF8FFF) | (nValue << 12);
}

// 0x00442A80
int __fastcall sub_00442A80_IsNightmareOpen(unsigned int nFlags)
{
    if (nFlags & 0x20)
        return (nFlags & 0x1F00) >= 0x500;
    return (nFlags & 0x1F00) >= 0x400;
}

// 0x00442AB0
int __fastcall sub_00442AB0_IsHellOpen(unsigned int nFlags)
{
    if (nFlags & 0x20)
        return (nFlags & 0x1F00) >= 0xA00;
    return (nFlags & 0x1F00) >= 0x800;
}

// 0x00443540
int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar)
{
    switch (*pChar)
    {
    case ' ':
    case '\'':
    case '-':
    case '_':
        return 1;
    }
    if (*pChar >= '0' && *pChar <= '9')
        return 1;
    if (*pChar >= 'A' && *pChar <= 'Z')
        return 1;
    if (*pChar >= 'a' && *pChar <= 'z')
        return 1;
    return 0;
}

// 0x004435D0
int __stdcall sub_004435D0(void* unused1,void* unused2,const Character* text)
{
    return text->value>=FIRST_PRINTABLE && text->value<AFTER_PRINTABLE;
}
