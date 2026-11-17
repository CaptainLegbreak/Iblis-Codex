#pragma pack(push, 2)
struct T0047BAD0
{
    const char* szName;
    short nCode;
    int bArgument;
    int bAlways;
};
#pragma pack(pop)

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                 // 0x00687330
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted); // 0x00413B80
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30

extern T0047BAD0 gtChatCommands_00712F7C[3];                                                       // 0x00712F7C
extern "C" const char gszSpace_006FFC44[];                                                                  // 0x006FFC44

// 0x0047BAD0
int __stdcall sub_0047BAD0_ParseChatCommand(const char** ppText, char* pCode, char* szArgument)
{
    char szText[0x100];
    char szToken[0x104];
    const char* pText = szText;
    *szArgument = 0;
    strncpy(szText, *ppText, 0x100);
    const int nTextLen = SStrLen(pText);
    for (int i = 0; i < 3; i++)
    {
        const int nNameLen = SStrLen(gtChatCommands_00712F7C[i].szName);
        if (!gtChatCommands_00712F7C[i].bAlways && !sub_0044DB30())
            continue;

        if (gtChatCommands_00712F7C[i].nCode == 3)
        {
            if (nTextLen < nNameLen)
                continue;
            if (SStrCmpI(pText, gtChatCommands_00712F7C[i].szName, nNameLen))
                continue;
            *pCode = gtChatCommands_00712F7C[i].nCode;
            return 1;
        }

        if (nTextLen <= nNameLen)
            continue;
        if (SStrCmpI(pText, gtChatCommands_00712F7C[i].szName, nNameLen))
            continue;
        if (!pText[nNameLen])
            continue;

        pText += nNameLen;
        if (gtChatCommands_00712F7C[i].bArgument)
        {
            SStrTokenize(&pText, szToken, 0x100, gszSpace_006FFC44, 0);
            if (!strlen(pText))
                return 0;
            if (strlen(szToken) >= 0x32)
                return 0;
            SStrCopy(szArgument, szToken, 0x7FFFFFFF);
            *ppText += strlen(szToken) + nNameLen + 1;
        }
        else
        {
            *ppText += nNameLen;
        }
        *pCode = gtChatCommands_00712F7C[i].nCode;
        return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/0047BAD0_sub_0047BAD0_ParseChatCommand.inc"
