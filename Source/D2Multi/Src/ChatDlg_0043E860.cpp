#include "D2MultiTypes.h"
#include "D2Unicode.h"
#pragma pack(push, 1)
#pragma pack(pop)

struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
};

unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall sub_00414150_HashPath(const char* szPath);                                           // 0x00414150
extern "C" int __cdecl isalnum(int c);                                                                      // 0x006870FB
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
const char* __fastcall sub_00446820_SkipNamePrefix(const char* szName); // 0x00446820
void __fastcall sub_0043EA70_ShowMessage(const Unicode* pTitle, const Unicode* pText);                      // 0x0043EA70
int __stdcall sub_0043E900_FindCdKeyInText(const char* szText);                                             // 0x0043E900
int __cdecl sub_00442810_SendChatBuffer();                                                                  // 0x00442810

extern T0043E860* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern char gszChatBuffer_0077AE40[0x200];                                                                  // 0x0077AE40

static int __stdcall sub_0043E860_FindHashedWord(char* szText, unsigned int nHash, int nLength);
static int __declspec(noinline) __stdcall sub_0043E860_FindHashedWord(char* szText, unsigned int nHash, int nLength);

// 0x0043E860
static int __stdcall sub_0043E860_FindHashedWord(char* szText, unsigned int nHash, int nLength)
{
    if (!nLength)
        return 0;

    const int nTextLength = SStrLen(szText);
    for (int i = 0; i <= nTextLength - nLength; ++i)
    {
        if (i > 0 && isalnum(szText[i - 1]))
            continue;

        if (i < nTextLength - nLength && isalnum((szText + i)[nLength]))
            continue;

        const unsigned char c = (szText + i)[nLength];
        (szText + i)[nLength] = 0;
        const unsigned int nValue = sub_00414150_HashPath(szText + i);
        (szText + i)[nLength] = c;
        if (nValue == nHash)
            return 1;
    }

    return 0;
}

int __fastcall sub_004428D0_SendChatText(char* szText, int bWhisper)
{
    const int bCommand = szText[0] == '/';
    SMemZero(gszChatBuffer_0077AE40, sizeof(gszChatBuffer_0077AE40));
    if (bWhisper && !bCommand && gpSelectedChannelUser_00798F48)
        sprintf(gszChatBuffer_0077AE40, "/whisper *%s %s", sub_00446820_SkipNamePrefix(gpSelectedChannelUser_00798F48->szName), szText);
    else
        strcpy(gszChatBuffer_0077AE40, szText);

    if (sub_0043E860_FindHashedWord(szText, gpCharInfo_0077BBD8->nWordHash, gpCharInfo_0077BBD8->nWordLength))
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
