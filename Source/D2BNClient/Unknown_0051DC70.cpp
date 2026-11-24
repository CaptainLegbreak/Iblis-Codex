#include "D2BNClient.h"

#define NULL 0

struct D2CDKeyInfoStrc;
struct D2CDKeyHash16Strc;
struct D2CDKeyHash26Strc;
struct D2AuthCheck2Strc;
struct D2AuthCheck1Strc;

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6
extern "C" int __cdecl tolower(int nChar); // 0x0068523E
extern const char gacCDKeyMap[]; // 0x006DF238
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

struct D2CDKeyInfoStrc
{
    unsigned int f_0;
    int f_4;
    int nValue1;
    int f_C;
    unsigned char abDigest[20];
};

struct D2CDKeyHash16Strc
{
    unsigned int f_0;
    unsigned int f_4;
    int f_8;
    int nValue1;
    int f_10;
    int nValue3;
};

struct D2CDKeyHash26Strc
{
    unsigned int f_0;
    unsigned int f_4;
    int f_8;
    int nValue1;
    unsigned char abPrivate[12];
};

struct D2AuthCheck2Strc
{
    unsigned int f_0;
    unsigned int nKeys;
    unsigned int f_8;
    D2CDKeyInfoStrc aKeys[2];
    char f_54[0x100];
};

struct D2AuthCheck1Strc
{
    unsigned int f_0;
    unsigned int nKeys;
    unsigned int f_8;
    D2CDKeyInfoStrc aKeys[1];
    char f_30[0x100];
};

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __cdecl BNCLIENT_GetServerToken(); // 0x0051A550
int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0
int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
void __fastcall BNSEND_ComputeShaDigest(unsigned char* pDigest, const unsigned char* pData, unsigned int nLength); // 0x0051DC80
int __fastcall sub_0051DDD0_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2); // 0x0051DDD0
int __cdecl GAME_GetExeHash(); // 0x00523A00
const char* __cdecl GAME_GetExeInfo(); // 0x00523AA0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern unsigned int gdwClientToken; // 0x00881C48
void __cdecl GRID_LockCDKeys(); // 0x005234D0
int __stdcall sub_0051E0B0_SendAuthCheck(); // 0x0051E0B0
void __cdecl GRID_UnlockCDKeys(); // 0x005239C0
int __fastcall BNMESSQUEUE_SetState(int nState); // 0x00520520

// 0x0051DC70
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// 0x0051DD10
static unsigned int sub_0051DD10_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

// 0x0051DD20
static int sub_0051DD20_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// 0x0051DD40
static int sub_0051DD40_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return sub_0051DD10_NibbleToHex(tolower(n)) + sub_0051DD10_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return sub_0051DD20_HexToNibble((char)tolower(n)) * 16 + sub_0051DD20_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return sub_0051DD40_MapKeyChar((unsigned char)tolower(n)) * 24 + sub_0051DD40_MapKeyChar((unsigned char)tolower(n + 1));
}

// 0x0051DCD0
static void __stdcall sub_0051DCD0_EncodeChar(char* pChar, unsigned int* pBits, int nFlag)
{
    const char ch = (char)toupper(*pChar);
    *pChar = ch;
    if (ch <= 0x37)
    {
        *pChar = (char)((*pBits & 7) ^ ch);
        *pBits >>= 3;
    }
    else if (ch < 0x41)
    {
        *pChar = (char)((nFlag & 1) ^ ch);
    }
}

extern "C" void __stdcall sub_K08_EmitEncodeChar(char* pText, unsigned int* pBits, int nFlag)
{
    sub_0051DCD0_EncodeChar(pText, pBits, nFlag);
    sub_0051DCD0_EncodeChar(pText + 1, pBits, nFlag);
}

// 0x0051DD50
static void sub_0051DD50_DecodeKeyPairs(char* szKey, unsigned int* pValue)
{
    unsigned int nBit = 1;
    *pValue = 0;
    for (int i = 0; i < 16; i += 2, nBit <<= 1)
    {
        unsigned int nPair = gacCDKeyMap[(unsigned char)szKey[i]] * 24 + gacCDKeyMap[(unsigned char)szKey[i + 1]];
        if (nPair >= 0x100)
        {
            nPair -= 0x100;
            *pValue |= nBit;
        }

        unsigned int nHigh = (nPair >> 4) & 0xF;
        if (nHigh >= 10)
        {
            nHigh += 0x37;
        }
        else
        {
            nHigh += 0x30;
        }
        szKey[i] = nHigh;

        unsigned int nLow = nPair & 0xF;
        if (nLow >= 10)
        {
            nLow += 0x37;
        }
        else
        {
            nLow += 0x30;
        }
        szKey[i + 1] = nLow;
    }
}

#include "gen/data/Source/D2BNClient/Unknown_0051DC70.inc"

// 0x0051DDD0
int __fastcall sub_0051DDD0_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2)
{
    *pProduct = 0;
    *pValue1 = 0;
    *pValue2 = 0;
    if (!szKey)
    {
        return 0;
    }

    char szBuffer[0x20];
    SStrCopy(szBuffer, szKey, 0x20);

    unsigned int nValue;
    sub_0051DD50_DecodeKeyPairs(szBuffer, &nValue);

    unsigned int nChecksum = 3;
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        const char c = tolower(szBuffer[i]);
        const int nDigit = c >= 0x61 ? c - 0x57 : c - 0x30;
        nChecksum += (nChecksum * 2) ^ nDigit;
    }

    if ((unsigned char)nChecksum != nValue)
    {
        return 0;
    }

    for (int i = 15; i >= 0; --i)
    {
        const int j = (i + 7) & 15;
        const char c = szBuffer[i];
        szBuffer[i] = szBuffer[j];
        szBuffer[j] = c;
    }

    nValue = 0x13AC9741;
    for (int i = 15; i >= 0; --i)
    {
        const char c = toupper(szBuffer[i]);
        szBuffer[i] = c;
        if (c <= 0x37)
        {
            szBuffer[i] = (nValue & 7) ^ c;
            nValue >>= 3;
        }
        else if (c < 0x41)
        {
            szBuffer[i] = (i & 1) ^ c;
        }
    }

    char szPart2[7];
    char szPart3[9];
    SStrCopy((char*)&nValue, szBuffer, 3);
    SStrCopy(szPart2, &szBuffer[2], 7);
    SStrCopy(szPart3, &szBuffer[8], 9);
    *pProduct = strtoul((char*)&nValue, NULL, 0x10);
    *pValue1 = strtoul(szPart2, NULL, 0x10);
    *pValue2 = strtoul(szPart3, NULL, 0x10);
    return 1;
}

// 0x0051DFC0
static int __stdcall sub_0051DFC0_BuildCDKeyInfo(D2CDKeyInfoStrc* pInfo, const char* szKey, unsigned int dwClientToken, unsigned int dwServerToken)
{
    D2CDKeyHash26Strc tHash26;
    int nValue1;
    D2CDKeyHash16Strc tHash16;
    switch (SStrLen(szKey))
    {
    case 0x10:
        tHash16.f_0 = dwClientToken;
        tHash16.f_4 = dwServerToken;
        if (!sub_0051DDD0_DecodeCDKey16(&tHash16.f_8, &nValue1, szKey, &tHash16.nValue3))
            return 0;

        tHash16.nValue1 = nValue1;
        tHash16.f_10 = 0;
        pInfo->f_0 = SStrLen(szKey);
        pInfo->f_4 = tHash16.f_8;
        pInfo->nValue1 = tHash16.nValue1;
        pInfo->f_C = tHash16.f_10;
        sub_005209D0_HashData(pInfo->abDigest, &tHash16, 0x18);
        return 1;

    case 0x1A:
        tHash26.f_0 = dwClientToken;
        tHash26.f_4 = dwServerToken;
        if (!szKey)
            return 0;

        sub_00522AE0_DecodeCDKey(szKey, &tHash26.f_8, &nValue1, tHash26.abPrivate);
        tHash26.nValue1 = nValue1;
        pInfo->f_0 = SStrLen(szKey);
        pInfo->f_4 = tHash26.f_8;
        pInfo->nValue1 = tHash26.nValue1;
        pInfo->f_C = 0;
        BNSEND_ComputeShaDigest(pInfo->abDigest, (const unsigned char*)&tHash26, 0x1A);
        return 1;
    }

    return 0;
}

unsigned int gdwClientToken; // 0x00881C48

// 0x0051E0B0
int __stdcall sub_0051E0B0_SendAuthCheck()
{
    const char* szExeInfo = GAME_GetExeInfo();
    const char* szKey0 = sub_00523AB0_GetCDKey(0);
    const char* szKey1 = sub_00523AB0_GetCDKey(1);
    const unsigned int dwExeHash = GAME_GetExeHash();
    gdwClientToken += _time32(0);
    gdwClientToken += GetTickCount();
    if (sub_0051BEC0_IsExpansion())
    {
        D2AuthCheck2Strc tPacket;
        if (!sub_0051DFC0_BuildCDKeyInfo(&tPacket.aKeys[0], szKey0, gdwClientToken, BNCLIENT_GetServerToken()))
            return 0;
        if (!sub_0051DFC0_BuildCDKeyInfo(&tPacket.aKeys[1], szKey1, gdwClientToken, BNCLIENT_GetServerToken()))
            return 0;

        tPacket.f_0 = gdwClientToken;
        tPacket.nKeys = 2;
        tPacket.f_8 = dwExeHash;
        if (BNSEND_SendPacket(0x42, &tPacket, SStrCopy(tPacket.f_54, szExeInfo, 0x100) + 0x55) < 0)
            return 0;
    }
    else
    {
        D2AuthCheck1Strc tPacket;
        tPacket.f_0 = gdwClientToken;
        tPacket.nKeys = 1;
        tPacket.f_8 = dwExeHash;
        if (!sub_0051DFC0_BuildCDKeyInfo(&tPacket.aKeys[0], szKey0, gdwClientToken, BNCLIENT_GetServerToken()))
            return 0;

        if (BNSEND_SendPacket(0x42, &tPacket, SStrCopy(tPacket.f_30, szExeInfo, 0x100) + 0x31) < 0)
            return 0;
    }

    return 1;
}

// 0x0051E340
int __fastcall sub_0051E340_BuildCDKeyInfoForSlot(D2CDKeyInfoStrc* pInfo, unsigned int dwClientToken, int nSlot)
{
    return sub_0051DFC0_BuildCDKeyInfo(pInfo, sub_00523AB0_GetCDKey(nSlot), dwClientToken, BNCLIENT_GetServerToken());
}

// 0x0051E240
int __cdecl sub_0051E240_CheckAuth()
{
    GRID_LockCDKeys();
    const int nResult = sub_0051E0B0_SendAuthCheck();
    GRID_UnlockCDKeys();
    if (!nResult)
        BNMESSQUEUE_SetState(3);
    return nResult;
}
