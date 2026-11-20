#include "D2BNClient.h"
#include "D2Primitives.h"
#include "D2NetTypes.h"
#include "D2BnCryptTypes.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

class BNGatewayAccess
{
public:
    const char* __stdcall DNS(int nGateway);                                                                 // 0x00518040
    void __stdcall Load();                                                                                   // 0x005186D0
    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
};

struct D2BigPowModStrc;

struct D2BnAuthInfoPacketStrc
{
    unsigned int nProtocol;
    unsigned int nPlatform;
    unsigned int f_8;
    unsigned int nVersion;
    unsigned int f_10;
    unsigned int f_14;
    int f_18;
    unsigned int nLcid;
    unsigned int nLangId;
    unsigned int nCountryAbbrev;
    char szCountry[0x100];
};

struct D2BnLogonPacketStrc
{
    unsigned char abPublic[0x20];
    char szName[0x100];
};

struct D2BnCreateAccountPacketStrc
{
    unsigned char abSalt[0x20];
    unsigned char abVerifier[0x20];
    char szName[0x100];
};

struct D2BnUpgradeInputStrc
{
    unsigned int nTick;
    unsigned int f_4;
    unsigned char abDigest[0x14];
};

struct D2BnUpgradePacketStrc
{
    unsigned int nTick;
    unsigned char abProof[0x14];
    unsigned char abVerifier[0x40];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(void);                    // 0x006CC354

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
char* __stdcall sub_004141E0_StrUpper(char* szString);                                                      // 0x004141E0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_0051C9E0_GetSockName(void* pAddress, int* pnLength); // 0x0051C9E0
int __fastcall sub_0051DDD0_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2);   // 0x0051DDD0
void __cdecl sub_005234D0_LockCDKeys();                                                                     // 0x005234D0
void __cdecl sub_005239C0_UnlockCDKeys();                                                                   // 0x005239C0
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260

extern "C" const char gszKernel32_006CD6E4[];                                                               // 0x006CD6E4
extern BNGatewayAccess gBnGatewayAccess_00881838;                                                           // 0x00881838
extern int gdwGlobal_00882538;                                                                              // 0x00882538
extern char gszAccountName_00882540[0x100];                                                                 // 0x00882540
unsigned char gabNewVerifier_00882640[0x40];                                                                // 0x00882640
D2BigLoginRecordStrc gtLoginRecord_00882680;                                                                // 0x00882680
D2BigPairStrc gtBigPair_0088273C;                                                                           // 0x0088273C

// 0x0051BA00
int __fastcall sub_0051BA00_SetEmail(const char* szEmail)
{
    char szBuffer[0x100];
    D2_ASSERT(szEmail, 0x55D);
    unsigned int nLength = SStrLen(szEmail);
    D2_ASSERT(nLength < 0x100, 0x565);
    memcpy(szBuffer, szEmail, nLength);
    szBuffer[nLength] = 0;
    return sub_0051C5C0_SendPacket(0x59, szBuffer, nLength + 1) >= 0;
}

// 0x0051BAA0
int __fastcall sub_0051BAA0_ResetPassword(const char* szAccountName, const char* szEmail)
{
    char szBuffer[0x200];
    D2_ASSERT(szAccountName, 0x578);
    D2_ASSERT(*szAccountName, 0x579);
    if (szEmail && *szEmail)
    {
        unsigned int nAccount = SStrLen(szAccountName) + 1;
        D2_ASSERT(nAccount <= 0x100, 0x581);
        memcpy(szBuffer, szAccountName, nAccount);
        unsigned int nEmail = SStrLen(szEmail) + 1;
        D2_ASSERT(nEmail <= 0x100, 0x588);
        memcpy(&szBuffer[nAccount], szEmail, nEmail);
        return sub_0051C5C0_SendPacket(0x5A, szBuffer, nEmail + nAccount) >= 0;
    }
    return 0;
}

// 0x0051C190
void __fastcall sub_0051C190(char* szText, int nSize)
{
    char szBuffer[0x100];
    *szText = 0;
    gBnGatewayAccess_00881838.Load();
    SStrCopy(szText, gBnGatewayAccess_00881838.DNS(gBnGatewayAccess_00881838.m_nCurGateway), nSize);
    if (SRegLoadString("Diablo II", "BNETIP", 0, szBuffer, 0x100))
        SStrCopy(szText, szBuffer, nSize);
}

static __forceinline int CheckCDKeySlot(int nSlot, int* pProduct, int* pValue1, int* pValue2, char* pKeyBlock)
{
    const char* szKey = sub_00523AB0_GetCDKey(nSlot);
    unsigned int nLength = SStrLen(szKey);
    if (nLength != 0x10)
    {
        if (nLength != 0x1A)
            return 0;
        if (!szKey)
            return 0;
        sub_00522AE0_DecodeCDKey(szKey, pProduct, pValue1, pKeyBlock);
        return 1;
    }
    return sub_0051DDD0_DecodeCDKey16(pProduct, pValue1, szKey, pValue2);
}

// 0x0051E270
int __stdcall sub_0051E270_CheckCDKeys()
{
    int nProduct;
    int nValue1;
    int nValue2;
    char aKeyBlock[12];
    sub_005234D0_LockCDKeys();
    int bResult = CheckCDKeySlot(0, &nProduct, &nValue1, &nValue2, aKeyBlock);
    if (bResult && sub_0051BEC0_IsExpansion())
        bResult = CheckCDKeySlot(1, &nProduct, &nValue1, &nValue2, aKeyBlock);
    sub_005239C0_UnlockCDKeys();
    return bResult;
}

static unsigned int GetUILanguageId()
{
    void* hKernel = LoadLibraryA(gszKernel32_006CD6E4);
    if (hKernel)
    {
        unsigned short (__stdcall* pfnGetUILanguage)() = (unsigned short (__stdcall*)())GetProcAddress(hKernel, "GetSystemDefaultUILanguage");
        if (pfnGetUILanguage)
        {
            unsigned short nLangId = pfnGetUILanguage();
            FreeLibrary(hKernel);
            return nLangId;
        }
        FreeLibrary(hKernel);
    }
    return GetSystemDefaultLangID();
}

// 0x00521BF0
int __stdcall sub_00521BF0()
{
    D2BnAuthInfoPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.nProtocol = 0;
    tPacket.nPlatform = 0x49583836;
    tPacket.f_8 = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.nVersion = 0xE;
    sub_00525260(&tPacket.f_10, 3);

    D2SockAddrInStrc tAddress;
    int nLength = 0x10;
    tPacket.f_14 = sub_0051C9E0_GetSockName(&tAddress, &nLength) ? tAddress.sin_addr.s_addr : 0;

    D2FileTimeStrc tLocalFileTime;
    D2FileTimeStrc tSystemFileTime;
    D2SystemTimeStrc tSystemTime;
    D2SystemTimeStrc tLocalTime;
    GetSystemTime(&tSystemTime);
    GetLocalTime(&tLocalTime);
    SystemTimeToFileTime(&tSystemTime, &tSystemFileTime);
    SystemTimeToFileTime(&tLocalTime, &tLocalFileTime);
    tPacket.f_18 = (int)((*(__int64*)&tSystemFileTime - *(__int64*)&tLocalFileTime) / 600000000);
    tPacket.nLcid = GetUserDefaultLCID();
    tPacket.nLangId = GetUILanguageId();

    char szAbbrev[0x40];
    GetLocaleInfoA(0x400, 7, szAbbrev, sizeof(szAbbrev));
    szAbbrev[3] = 0;
    tPacket.nCountryAbbrev = *(unsigned int*)szAbbrev;
    GetLocaleInfoA(0x400, 0x1002, tPacket.szCountry, sizeof(tPacket.szCountry));
    sub_0051C5C0_SendPacket(0x50, &tPacket, SStrLen(tPacket.szCountry) + 0x29);
    return 1;
}

// 0x00521F60
int __fastcall sub_00521F60_SendLogon(const char* szName, const char* szPassword)
{
    D2BnLogonPacketStrc tPacket;
    char szPasswordUpper[0x100];
    char szNameUpper[0x100];
    gdwGlobal_00882538 = 0;
    SStrCopy(gszAccountName_00882540, szName, 0x100);
    sub_0041D300_ZeroMemory(&gtLoginRecord_00882680, sizeof(gtLoginRecord_00882680));
    SStrCopy(szNameUpper, szName, 0x100);
    sub_004141E0_StrUpper(szNameUpper);
    SStrCopy(szPasswordUpper, szPassword, 0x100);
    sub_004141E0_StrUpper(szPasswordUpper);
    gtBigPair_0088273C.sub_005286D0_InitLogin(&gtLoginRecord_00882680, szNameUpper, szPasswordUpper);
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord_00882680.abPublic, sizeof(tPacket.abPublic));
    unsigned int nLength = SStrCopy(tPacket.szName, szName, 0x100);
    sub_0051C5C0_SendPacket(0x53, &tPacket, nLength + 0x21);
    return 1;
}

// 0x00522130
int __fastcall sub_00522130_SendCreateAccount(const char* szName, const char* szPassword)
{
    D2BnCreateAccountPacketStrc tPacket;
    char szPasswordUpper[0x100];
    char szNameUpper[0x100];
    SStrCopy(szNameUpper, szName, 0x100);
    sub_004141E0_StrUpper(szNameUpper);
    SStrCopy(szPasswordUpper, szPassword, 0x100);
    sub_004141E0_StrUpper(szPasswordUpper);
    gtBigPair_0088273C.sub_00528660_MakeVerifier(szNameUpper, szPasswordUpper, tPacket.abSalt, tPacket.abVerifier);
    unsigned int nLength = SStrCopy(tPacket.szName, szName, 0x7FFFFFFF);
    sub_0051C5C0_SendPacket(0x52, &tPacket, nLength + 0x41);
    return 1;
}

// 0x005221F0
int __fastcall sub_005221F0_ChangePasswordProof(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    D2BnLogonPacketStrc tPacket;
    char szOldUpper[0x100];
    char szNewUpper[0x100];
    char szAccountUpper[0x100];
    gdwGlobal_00882538 = 0;
    sub_0041D300_ZeroMemory(&gtLoginRecord_00882680, sizeof(gtLoginRecord_00882680));
    SStrCopy(szAccountUpper, szAccountName, 0x100);
    sub_004141E0_StrUpper(szAccountUpper);
    SStrCopy(szOldUpper, szOldPassword, 0x100);
    sub_004141E0_StrUpper(szOldUpper);
    SStrCopy(szNewUpper, szNewPassword, 0x100);
    sub_004141E0_StrUpper(szNewUpper);
    gtBigPair_0088273C.sub_00528660_MakeVerifier(szAccountUpper, szNewUpper, gabNewVerifier_00882640, &gabNewVerifier_00882640[0x20]);
    gtBigPair_0088273C.sub_005286D0_InitLogin(&gtLoginRecord_00882680, szAccountUpper, szOldUpper);
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord_00882680.abPublic, sizeof(tPacket.abPublic));
    unsigned int nLength = SStrCopy(tPacket.szName, szAccountName, 0x100);
    sub_0051C5C0_SendPacket(0x55, &tPacket, nLength + 0x21);
    return 0;
}

// 0x005223F0
int __fastcall sub_005223F0_SendUpgradeProof(unsigned int nServerToken)
{
    D2BnUpgradePacketStrc tPacket;
    D2BnUpgradeInputStrc tInput;
    char szPassword[0x100];
    tInput.nTick = GetTickCount();
    tInput.f_4 = nServerToken;
    CharLowerBuffA(szPassword, SStrCopy(szPassword, gtLoginRecord_00882680.szPassword, 0x100));
    sub_005209D0_HashData(tInput.abDigest, szPassword, SStrLen(szPassword));
    tPacket.nTick = tInput.nTick;
    sub_005209D0_HashData(tPacket.abProof, &tInput, sizeof(tInput));
    sub_0041D2A0_MemCopy(tPacket.abVerifier, gabNewVerifier_00882640, sizeof(tPacket.abVerifier));
    sub_0041D300_ZeroMemory(gabNewVerifier_00882640, sizeof(gabNewVerifier_00882640));
    sub_0051C5C0_SendPacket(0x58, &tPacket, sizeof(tPacket));
    return 0;
}
