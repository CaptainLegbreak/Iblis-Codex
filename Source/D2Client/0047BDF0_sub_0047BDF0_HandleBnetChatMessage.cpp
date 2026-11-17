extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* a, const char* b);
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

struct D2BnetChatPacketStrc
{
    int nType;
    char unk0x04[0x14];
    char szName[0x1D0];
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x24];
    int (__fastcall* pfnGetMessage)(int* pResult, D2BnetChatPacketStrc* pPacket);
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
};

D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify();                                                       // 0x0044B7B0
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList();                                                   // 0x00611560
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
void __fastcall sub_0049E3A0_PrintChatLine(const Unicode* pText, char nColor);                                  // 0x0049E3A0
extern "C" const char gszNameAccountFormat_006D72C0[];                                                      // 0x006D72C0
extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58

static const char* sub_0047BD60_GetAccountPart(const char* szName)
{
    const char* p = SStrChr(szName, 0x2A);
    if (p && *++p)
        return p;
    return szName;
}

// 0x0047BD80

static __declspec(noinline) void sub_0047BD80_CopyCharPart(const char* szSource, char* szDest)
{
    if (*szSource != 0x2A)
    {
        const char* p = SStrChr(szSource, 0x2A);
        if (p)
        {
            memcpy(szDest, szSource, p - szSource);
            szDest[p - szSource] = 0;
            return;
        }
        SStrCopy(szDest, szSource, 0x7FFFFFFF);
        return;
    }
    SStrCopy(szDest, szSource, 0x7FFFFFFF);
}

// 0x0047BDF0
int __cdecl sub_0047BDF0_HandleBnetChatMessage()
{
    D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
    if (!pNotify)
        return 0;

    int nResult;
    D2BnetChatPacketStrc tPacket;
    if (!pNotify->pfnGetMessage(&nResult, &tPacket))
        return 0;

    if (nResult == 0)
    {
        Unicode wszLine[0x154];
        Unicode wszText[0x154];
        Unicode wszOut[0x154];
        const int nType = tPacket.nType;
        const char* szSender = tPacket.szName;
        const char* szText = szSender + strlen(szSender) + 1;
        if (sub_00611560_GetSquelchList()->IsNameSquelched(szSender))
            return 1;
        if (sub_00611560_GetSquelchList()->IsTextSquelched(szText))
            return 1;

        switch (nType)
        {
        case 4:
        case 6:
        case 10:
        {
            char szName[0x154];
            char szFormatted[0x154];
            sub_0047BD80_CopyCharPart(szSender, szName);
            if (szName[0] && (szName[0] != 0x2A || strcmp(sub_0047BD60_GetAccountPart(szName), sub_0047BD60_GetAccountPart(szSender))))
                sprintf(szFormatted, gszNameAccountFormat_006D72C0, szName, sub_0047BD60_GetAccountPart(szSender));
            else
                sprintf(szFormatted, gszStringFormat_006FFC58, szName);
            sub_00526E40_Utf8ToUnicode(wszLine, szFormatted, 0x154);
            sub_00526E40_Utf8ToUnicode(wszText, szText, 0x154);
            wszLine[0x153].wChar = 0;
            wszText[0x153].wChar = 0;
            if (nType == 10)
                sub_005269D0(0x153, wszOut, D2LANG_GetStringFromTblIndex(0x14D5), wszLine, wszText);
            else
                sub_005269D0(0x153, wszOut, D2LANG_GetStringFromTblIndex(0x14D4), wszLine, wszText);
            wszOut[0x153].wChar = 0;
            sub_0049E3A0_PrintChatLine(wszOut, 2);
            break;
        }
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 9:
        case 21:
        case 22:
        case 23:
            break;
        default:
        {
            char szPrefix[20];
            strcpy(szPrefix, "<BattleNet>: ");
            sub_00526E40_Utf8ToUnicode(wszLine, szPrefix, 0x154);
            sub_00526E40_Utf8ToUnicode(wszText, szText, 0x154);
            wszLine[0x153].wChar = 0;
            wszText[0x153].wChar = 0;
            if (sub_00526800(wszText) + sub_00526800(wszLine) >= 0x154)
            {
                const int nLength = sub_00526800(wszLine);
                if (nLength < 0x153)
                    wszText[0x153 - nLength].wChar = 0;
                else
                    wszText[0].wChar = 0;
            }
            sub_00526700(wszLine, wszText);
            wszLine[0x153].wChar = 0;
            sub_0049E3A0_PrintChatLine(wszLine, 3);
            break;
        }
        }
    }
    return 1;
}
