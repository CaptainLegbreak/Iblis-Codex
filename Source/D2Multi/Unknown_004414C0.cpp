#include "D2Multi.h"

struct D2LaunchCharInfoStrc;
struct T0043E860;
struct Unicode;
struct Character;

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x000[0x1EF];
    unsigned short wFlags1EF;
    char unk0x1F1[0x22D - 0x1F1];
    unsigned char nByte22D;
    unsigned char unk_22E[0x195];
    unsigned int nWordHash;
    int nWordLength;
};

#pragma pack(pop)

extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
void __stdcall sub_004413E0_Enable(int bEnable); // 0x004413E0

struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
};

struct Unicode
{
    unsigned short wChar;
};
unsigned int __stdcall sub_00414150_HashPath(const char* szPath); // 0x00414150
extern "C" int __cdecl isalnum(int c); // 0x006870FB
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
const char* __fastcall sub_00446820_SkipNamePrefix(const char* szName); // 0x00446820
void __fastcall sub_0043EA70_ShowMessage(const Unicode* pTitle, const Unicode* pText); // 0x0043EA70
int __stdcall sub_0043E900_FindCdKeyInText(const char* szText); // 0x0043E900
int __cdecl sub_00442810_SendChatBuffer(); // 0x00442810
extern T0043E860* gpSelectedChannelUser_00798F48; // 0x00798F48

struct Character { signed char value; };

enum { FIRST_PRINTABLE = 32, AFTER_PRINTABLE = 128 };

// 0x004414C0
void __cdecl sub_004414C0_UpdateEnable()
{
    if ((gpCharInfo_0077BBD8->wFlags1EF & 8) && (gpCharInfo_0077BBD8->wFlags1EF & 4))
    {
        return;
    }

    int bEnable = 0;
    if (gpCharInfo_0077BBD8->nByte22D && !sub_00449B30_QueryAddress())
    {
        bEnable = 1;
    }

    sub_004413E0_Enable(bEnable);
}

char gszChatBuffer_0077AE40[0x200]; // 0x0077AE40

static __declspec(noinline) int __stdcall sub_0043E860_FindHashedWord(unsigned int nHash, int nLength, char* szText)
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
        const unsigned int nValue = sub_00414150_HashPath(&szText[i]);
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
    SMemZero(gszChatBuffer_0077AE40, sizeof(gszChatBuffer_0077AE40));
    if (bWhisper && !bCommand && gpSelectedChannelUser_00798F48)
        sprintf(gszChatBuffer_0077AE40, "/whisper *%s %s", sub_00446820_SkipNamePrefix(gpSelectedChannelUser_00798F48->szName), szText);
    else
        strcpy(gszChatBuffer_0077AE40, szText);

    if (sub_0043E860_FindHashedWord(gpCharInfo_0077BBD8->nWordHash, gpCharInfo_0077BBD8->nWordLength, szText))
    {
        sub_0043EA70_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B37), D2LANG_GetStringFromTblIndex(0x2B38));
        gszChatBuffer_0077AE40[0] = 0;
        return 0;
    }

    if (sub_0043E900_FindCdKeyInText(szText))
    {
        sub_0043EA70_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B7A), D2LANG_GetStringFromTblIndex(0x2B7B));
        gszChatBuffer_0077AE40[0] = 0;
        return 0;
    }

    return sub_00442810_SendChatBuffer();
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
