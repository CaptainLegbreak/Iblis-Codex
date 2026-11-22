#include "D2Primitives.h"

#include "D2BNClient.h"

#include "D2BnCryptTypes.h"

typedef unsigned int size_t;

extern "C" size_t __cdecl strlen(const char* szString);

#pragma intrinsic(strlen)

struct D2BnClientIdReplyStrc
{
    unsigned int dwRegistrationVersion;
    unsigned int dwRegistrationAuthority;
    unsigned int dwClientId;
    unsigned int f_C;
};

struct D2BnStartVersioningStrc
{
    D2FileTimeStrc tFileTime;
    char szFileName[4];
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl sub_00518C70_StartLogging(int nMode, int nValue);                                               // 0x00518C70

void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40

void __fastcall sub_0051A540_SetValue(int nValue);                                                          // 0x0051A540

int __fastcall sub_0051E3B0_SetCheckRevisionValue(const char* szValue);                                    // 0x0051E3B0

void __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910

extern "C" const char szConfiguration_006DEC7C[];                                                           // 0x006DEC7C

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

struct D2BnAuthInfoStrc;

struct D2BnAuthInfoStrc
{
    unsigned int dwLogonType;
    unsigned int f_4;
    unsigned int f_8;
    D2FileTimeStrc tFileTime;
    char szFileName[4];
};

void __fastcall sub_0051A560_SetValue(int nValue); // 0x0051A560

int __fastcall sub_0051EA80_SetArchiveName(const char* szName); // 0x0051EA80

unsigned int __fastcall sub_005225E0(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry); // 0x005225E0

void __fastcall sub_00522650(const char* szKey, unsigned char* pOut); // 0x00522650

void __stdcall sub_00522980(unsigned int* pKey); // 0x00522980

__declspec(noinline) static unsigned int __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey);

// 0x00520CB0
int __fastcall sub_00520CB0_HandleClientId(const D2BnClientIdReplyStrc* pData, unsigned int nSize)
{
    if (!pData || nSize < 0x10)
    {
        sub_00518D40_Log("ERROR BDClientId: invalid response");
        return 0;
    }

    unsigned int nRegistrationVersion = pData->dwRegistrationVersion;
    unsigned int nRegistrationAuthority = pData->dwRegistrationAuthority;
    unsigned int nClientId = pData->dwClientId;
    unsigned int nClientToken = pData->f_C;
    SRegSaveValue(szConfiguration_006DEC7C, "Registration Version", 2, nRegistrationVersion);
    SRegSaveValue(szConfiguration_006DEC7C, "Registration Authority", 2, nRegistrationAuthority);
    SRegSaveValue(szConfiguration_006DEC7C, "Client ID", 2, nClientId);
    SRegSaveValue(szConfiguration_006DEC7C, "Client Token", 2, nClientToken);
    sub_00518C70_StartLogging(2, 4);
    sub_00518D40_Log("client acknowledged");
    sub_00518C70_StartLogging(2, -4);
    return 1;
}

// 0x00520D70
int __fastcall sub_00520D70_HandleLogonAck(const int* pData, unsigned int nSize)
{
    sub_0051A540_SetValue(pData[1]);
    sub_00518C70_StartLogging(2, 4);
    sub_00518D40_Log("logon acknowledged");
    sub_00518C70_StartLogging(2, -4);
    return 1;
}

// 0x00520F60
int __fastcall sub_00520F60_HandleStartVersioning(const D2BnStartVersioningStrc* pData, unsigned int nSize)
{
    const char* szFileName = pData->szFileName;
    if (sizeof(D2FileTimeStrc) + strlen(szFileName) + 1 < nSize)
        sub_0051E3B0_SetCheckRevisionValue(szFileName + strlen(szFileName) + 1);
    sub_0051F910_Report(0x80000001, 3, 0, 0, &pData->tFileTime, szFileName, 0);
    return 1;
}

static int BNAUTH_IsValidAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 0x16)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 0x14; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 1)
        return 0;
    return 1;
}

// 0x00521220
int __fastcall sub_00521220_HandleAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (!BNAUTH_IsValidAuthInfo(pData, nSize))
        return 0;

    const D2BnAuthInfoStrc* pInfo = (const D2BnAuthInfoStrc*)pData;
    D2FileTimeStrc tFileTime = pInfo->tFileTime;
    unsigned int nLogonType = pInfo->dwLogonType;
    unsigned int nServerToken = pInfo->f_4;
    const char* szFileName = pInfo->szFileName;
    const char* szValue = szFileName + SStrLen(szFileName) + 1;
    sub_0051A540_SetValue(nServerToken);
    sub_0051A560_SetValue(nLogonType);
    sub_0051E3B0_SetCheckRevisionValue(szValue);
    sub_0051EA80_SetArchiveName(&gszEmptyAssertText);
    sub_0051F910_Report(0x80000001, 3, 0, 0, &tFileTime, szFileName, 0);
    return 1;
}

static unsigned int __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey)
{
    const unsigned int nResult = pKey[0] >> (pKey[1] & 0x1F);
    pKey[2] ^= nResult;
    return nResult;
}

// 0x00522AE0
void __fastcall sub_00522AE0_DecodeCdKey26(const char* szKey, unsigned int* pProduct, unsigned int* pPublic, unsigned char* pPrivate)
{
    if (!szKey || !pPrivate)
    {
        return;
    }

    unsigned char aDigits[52];
    sub_00522650(szKey, aDigits);

    unsigned int aKey[4] = { 0 };
    for (int i = 52; i > 0; --i)
    {
        sub_005225E0(4, 5, aKey, aKey, aDigits[i - 1]);
    }

    sub_00522980(aKey);
    sub_005226D0_PermuteKeyBits(0, aKey);

    *pProduct = aKey[0] >> 10;
    *pPublic = ((aKey[0] & 0x3FF) << 16) | (aKey[1] >> 16);
    *(unsigned short*)pPrivate = (unsigned short)aKey[1];
    *(unsigned int*)(pPrivate + 2) = aKey[2];
    *(unsigned int*)(pPrivate + 6) = aKey[3];
}
