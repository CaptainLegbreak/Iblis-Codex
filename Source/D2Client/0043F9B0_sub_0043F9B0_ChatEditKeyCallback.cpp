struct D2WinControlStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
};

extern "C" unsigned int __cdecl strlen(const char* szText);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __fastcall sub_00446840_CopyNamePrefix(const char* szName, char* szOut);                               // 0x00446840
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FFE10
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70

extern int gnHistoryIndex_0070CD74;                                                                         // 0x0070CD74
extern char gaszHistory_0077B1D8[10][0x100];                                                                // 0x0077B1D8
extern int gnHistoryCount_0077BD50;                                                                         // 0x0077BD50
extern D2WinControlStrc* gpChatEdit_0077BD94;                                                               // 0x0077BD94
extern T0043E860* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

// 0x0043F9B0
int __stdcall sub_0043F9B0_ChatEditKeyCallback(void* pArg, int nCursor, const char* pKey)
{
    if (*pKey == 0x0E)
    {
        char szText[0x100];
        char szName[0x100];
        char szLeft[0x100];
        char szRight[0x100];

        const Unicode* pEditText = sub_004FDD90_GetEditText(gpChatEdit_0077BD94);
        if (pEditText && gpSelectedChannelUser_00798F48)
        {
            sub_00446840_CopyNamePrefix(gpSelectedChannelUser_00798F48->szName, szName);
            Unicode wszText[0x100];
            sub_00526F70(szText, pEditText, 0x100);
            const int nTextLength = strlen(szText);
            if ((int)strlen(szName) + nTextLength > 0xFF)
            {
                return 0;
            }

            strncpy(szLeft, szText, nCursor);
            szLeft[nCursor] = 0;
            strncpy(szRight, &szText[nCursor], nTextLength - nCursor);
            szRight[nTextLength - nCursor] = 0;
            sprintf(szText, "%s%s%s", szLeft, szName, szRight);
            sub_00526F20(wszText, szText, 0x100);
            sub_004FF5A0_SetEditText(gpChatEdit_0077BD94, wszText);
        }
        return 0;
    }

    if (*pKey == 9)
    {
        if (gnHistoryCount_0077BD50)
        {
            ++gnHistoryIndex_0070CD74;
            if (gnHistoryIndex_0070CD74 >= gnHistoryCount_0077BD50)
            {
                gnHistoryIndex_0070CD74 = 0;
            }
            sub_004FFE10_SetTextA(gpChatEdit_0077BD94, gaszHistory_0077B1D8[gnHistoryIndex_0070CD74]);
        }
        return 0;
    }

    return 1;
}
