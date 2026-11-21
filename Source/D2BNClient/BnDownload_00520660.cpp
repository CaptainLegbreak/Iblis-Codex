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

int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0

int __fastcall sub_0051E3B0_SetCheckRevisionValue(const char* szValue);                                    // 0x0051E3B0

void __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910

int __fastcall sub_00520210_QueueMessage(int nId, const void* pData, unsigned int nLength);                // 0x00520210

int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0

extern "C" const char szConfiguration_006DEC7C[];                                                           // 0x006DEC7C

extern int gdwGlobal_0072FFA8;                                                                              // 0x0072FFA8

int gdwGlobal_008822A0; // 0x008822A0

int gdwGlobal_008822A4; // 0x008822A4

int gdwGlobal_00882318;                                                                                     // 0x00882318

int gdwGlobal_00882350;                                                                                     // 0x00882350

int gdwGlobal_0088236C;                                                                                     // 0x0088236C

int gdwGlobal_0088239C;                                                                                     // 0x0088239C

extern "C" int __cdecl rand(); // 0x00687461

extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454

int __cdecl sub_0051BCF0_SendBuffer(); // 0x0051BCF0

int __fastcall sub_0051E370_SetText(const char* szText, int nLength); // 0x0051E370

int __fastcall sub_00520520_SetState(int nState); // 0x00520520

int __fastcall sub_00520550_SetStateArg(void* pArg); // 0x00520550

int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned long nSize); // 0x00415000

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define CHECK(p,line) if(!(p)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}

struct D2BigPowModStrc;

struct D2BnReportStrc;

struct D2BnTokenReplyStrc;

struct D2BnAuthInfoStrc;

struct D2BigLoginRecordStrc;

struct D2BnAccountLogonStrc;

struct D2BigPairStrc;

struct D2IdeaUserKeyStrc;

struct D2CipherKeyView;

int gnSlotArrayA_00882128[94]; // 0x00882128

extern "C" int gnSlotArrayB_008822A8[94]; // 0x008822A8

extern "C" int gnFlag_00882528; // 0x00882528

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

struct D2BnReportStrc
{
    int nResult;
    int unk0x04;
    D2FileTimeStrc tFileTime;
    char szText[1];
};

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

void __fastcall sub_0051BDC0_SetReply(const void* pData, unsigned int nSize); // 0x0051BDC0

void __fastcall sub_0051BE20_SetReply(const void* pData, unsigned int nSize); // 0x0051BE20

void __fastcall sub_0051BD60_SetReply(const void* pData, unsigned int nSize); // 0x0051BD60

int __fastcall sub_005202F0_QueueText(int nId, const char* szText); // 0x005202F0

int __fastcall sub_00520630_SetText(const char* szText); // 0x00520630

struct D2BnTokenReplyStrc
{
    int nResult;
    unsigned int nToken;
};

void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480

int __fastcall sub_005224C0_CheckServerProof(const unsigned char* pServerProof); // 0x005224C0

void __cdecl sub_005224F0_ClearPassword(); // 0x005224F0

int __fastcall sub_005223F0_SendUpgradeProof(unsigned int nServerToken); // 0x005223F0

int __cdecl sub_005224E0(); // 0x005224E0

int __fastcall sub_005223A0(int bFlag); // 0x005223A0

int __fastcall sub_00522310_SendChangeProof(const unsigned char* pSalt, const unsigned char* pServerKey); // 0x00522310

int __cdecl sub_00522050_SendAccountLogon(); // 0x00522050

void __fastcall sub_0051AB30_SetAdUrlReply(const void* pData, unsigned int nSize); // 0x0051AB30

void __fastcall sub_0051B3E0_SetSizedReply(const void* pData, unsigned int nSize); // 0x0051B3E0

void __fastcall sub_0051B820_SetReply(const void* pData, unsigned int nSize); // 0x0051B820

void __fastcall sub_0051CA80_SetFlag(int nValue); // 0x0051CA80

int __fastcall sub_0051E3D0_SendPacket33(const char* szText, int nCode); // 0x0051E3D0

int __fastcall sub_0051D860_ParseNewsInfo(const void* pData); // 0x0051D860

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

extern int gnGlobal_008823B0; // 0x008823B0

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int __fastcall sub_005220B0_SendLogonProof(const unsigned char* pSalt, const unsigned char* pServerKey); // 0x005220B0

extern "C" long __cdecl _time32(long* pTime);

extern "C" int __cdecl tolower(int nChar);

extern const char gacCDKeyMap_006DF238[];

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144

extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C

extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(void); // 0x006CC354

extern "C" const char gszKernel32_006CD6E4[]; // 0x006CD6E4

struct D2BnAccountLogonStrc
{
    unsigned char abPublic[0x20];
    char szAccountName[0x100];
};

extern D2BigLoginRecordStrc gtLoginRecord_00882680; // 0x00882680

void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0

void __cdecl sub_00524740_ClearKeySchedules(); // 0x00524740

void __cdecl sub_005241A0_ClearHashContexts(); // 0x005241A0

extern unsigned char gabNewVerifier_00882640[0x40]; // 0x00882640

extern D2BigPairStrc gtBigPair_0088273C; // 0x0088273C

extern unsigned char gaSubstitutionBox_006DFF20[30][16]; // 0x006DFF20

extern unsigned char gaCdKeyCharMap_006E0100[256]; // 0x006E0100

unsigned int __fastcall sub_005225E0(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry); // 0x005225E0

void __fastcall sub_00522650(const char* szKey, unsigned char* pOut); // 0x00522650

void __stdcall sub_00522980(unsigned int* pKey); // 0x00522980

__declspec(noinline) static unsigned int __fastcall sub_005226D0_PermuteKeyBits(int nUnused, unsigned int* pKey);

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall sub_00524280_InitHashContext(int nIndex); // 0x00524280

void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest); // 0x00524200

void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey); // 0x00524780

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

struct D2CipherKeyView {
 void Init(int); // 0x00522C30
};

void __fastcall sub_005241C0_GetDigest(int,void*); // 0x005241C0

void __fastcall sub_00524760_CipherBlock(int,const unsigned short*,unsigned short*); // 0x00524760

static unsigned int sub_00523280_CountTerminatedBytes(unsigned int maxLength, unsigned int length, const unsigned char* data);

int gdwGlobal_00882528; // 0x00882528

int gdwGlobal_008823F0; // 0x008823F0

int gdwGlobal_008823FC; // 0x008823FC

char gData_00882428[256]; // 0x00882428

int gnGlobal_008823EC; // 0x008823EC

char gszAccountName_00882540[0x100]; // 0x00882540

int gdwGlobal_00882538; // 0x00882538

// 0x00520660
int __fastcall sub_00520660_HandleReply0F(const void* pData, unsigned int nSize)
{
    sub_00520210_QueueMessage(0, pData, nSize);
    return 1;
}

// 0x00520B30
int __cdecl sub_00520B30_ResetReplies()
{
    for (int i = 0; i < 94; ++i)
        gnSlotArrayB_008822A8[i] = 0;
    for (int i = 0; i < 94; ++i)
        gnSlotArrayA_00882128[i] = 0;
    gdwGlobal_0072FFA8 = 0xFF;
    gnFlag_00882528 = 0;
    sub_00520520_SetState(0);
    return 1;
}

// 0x00520B70
int __fastcall sub_00520B70_WaitForReply(unsigned char nReply)
{
    const unsigned long dwStart = GetTickCount();
    while (!gnSlotArrayA_00882128[nReply])
    {
        if (gdwGlobal_00882528)
        {
            sub_005204A0_SetError(0x12);
            return 0;
        }
        if (GetTickCount() - dwStart > 45000)
        {
            sub_005204A0_SetError(0x11);
            return 0;
        }
        Sleep(10);
    }
    return 1;
}

// 0x00520BF0
int __fastcall sub_00520BF0_IsReplyReceived(unsigned char nReply)
{
    return gnSlotArrayA_00882128[nReply];
}

// 0x00520C50
int __fastcall sub_00520C50_HandleReply2A(const int* pData, unsigned int nSize)
{
    gdwGlobal_00882350 = pData[0];
    return 1;
}

// 0x00520C60
int __fastcall sub_00520C60_HandleReply3D(const int* pData, unsigned int nSize)
{
    gdwGlobal_008822A4 = pData[0];
    gdwGlobal_0088239C = 1;
    return 1;
}

// 0x00520C80
int __fastcall sub_00520C80_HandleReply31(const int* pData, unsigned int nSize)
{
    gdwGlobal_008822A0 = pData[0];
    gdwGlobal_0088236C = 1;
    if (!gdwGlobal_008822A0)
        sub_005204A0_SetError(0xE);
    return 1;
}

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

// 0x00520D50
int __fastcall sub_00520D50_HandleReply28(const int* pData, unsigned int nSize)
{
    sub_0051A540_SetValue(pData[0]);
    return 1;
}

// 0x00520D60
int __fastcall sub_00520D60_HandleReply1C(const int* pData, unsigned int nSize)
{
    if (!pData[0])
        gdwGlobal_00882318 = 1;
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

// 0x00520DA0
int __fastcall sub_00520DA0_HandleReply29(const int* pData, unsigned int nSize)
{
    gdwGlobal_0072FFA8 = pData[0] == 0;
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

// 0x00520FC0
int __fastcall sub_00520FC0_HandleReply25(const void* pData, unsigned int nSize)
{
    sub_0051C5C0_SendPacket(0x25, pData, nSize);
    return 1;
}

// 0x005210A0
int __fastcall sub_005210A0_SaveServerList(const void* pData, unsigned int nSize)
{
    SRegSaveString(szConfiguration_006DEC7C, "Server List", 2, (const char*)pData + 4);
    return 1;
}

// 0x005210C0
int __fastcall sub_005210C0_SetReply(const void* pData, unsigned int nSize)
{
    sub_0051BDC0_SetReply(pData, nSize);
    return 1;
}

// 0x005210D0
int __fastcall sub_005210D0_SetReply(const void* pData, unsigned int nSize)
{
    sub_0051BE20_SetReply(pData, nSize);
    return 1;
}

// 0x005210F0
int __fastcall sub_005210F0_ShowText(const void* pData, unsigned int nSize)
{
    sub_005202F0_QueueText(2, (const char*)pData);
    sub_00520630_SetText((const char*)pData);
    return 1;
}

// 0x00521110
int __fastcall sub_00521110_Report(const void* pData, unsigned int nSize)
{
    const D2BnReportStrc* pReport = (const D2BnReportStrc*)pData;
    const int nResult = pReport->nResult;
    const D2FileTimeStrc* pFileTime = &pReport->tFileTime;
    const char* szText = (const char*)(pFileTime + 1);
    const int nSubType = (nResult == 0x80000005 || nResult == 0x80000006) ? 2 : 4;
    sub_0051F910_Report(nResult, nSubType | 1, 0, 0, pFileTime, szText, 0);
    return 1;
}

// 0x005211D0
int __fastcall sub_005211D0_SetReply(const void* pData, unsigned int nSize)
{
    sub_0051BD60_SetReply(pData, nSize);
    return 1;
}

// 0x005211E0
int __fastcall sub_005211E0_QueryAdUrl(const void* pData, unsigned int nSize)
{
    sub_0051AB30_SetAdUrlReply(pData, nSize);
    return 1;
}

// 0x005211F0
int __fastcall sub_005211F0_LogonRealmEx(const void* pData, unsigned int nSize)
{
    sub_0051B3E0_SetSizedReply(pData, nSize);
    return 1;
}

// 0x00521200
int __fastcall sub_00521200_ReadUserData(const void* pData, unsigned int nSize)
{
    sub_0051B820_SetReply(pData, nSize);
    return 1;
}

// 0x00521210
int __fastcall sub_00521210_NewsInfo(const void* pData, unsigned int nSize)
{
    return sub_0051D860_ParseNewsInfo(pData);
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

static int BNAUTH_IsValidAuthCheck(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 5)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 4; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 0)
        return 0;
    return 1;
}

// 0x005212D0
int __fastcall sub_005212D0_HandleAuthCheck(const unsigned char* pData, unsigned int nSize)
{
    if (!BNAUTH_IsValidAuthCheck(pData, nSize))
    {
        sub_0051A480_DebugLog("INVALID: AuthCheck");
        return 0;
    }

    unsigned int nResult = *(const unsigned int*)pData;
    unsigned int nCode = nResult & 0xFF0F;
    const char* szInfo = (const char*)pData + 4;

    switch (nCode)
    {
    case 0:
    case 0x100:
    case 0x102:
        sub_0051BCF0_SendBuffer();
        break;
    }

    gData_00882428[0] = 0;
    gnGlobal_008823B0 = 0;
    SRegSaveData("Patch", "Patches", 0x82, &gszEmptyAssertText, 1);

    switch (nCode)
    {
    case 0x100:
    {
        char szPatches[0x100];
        unsigned int nLength = SStrCopy(szPatches, szInfo, 0xFE) + 1;
        szPatches[nLength] = 0;
        ++nLength;
        sub_0051E370_SetText(szPatches, nLength);
        SRegSaveData("Patch", "Patches", 0x82, szPatches, nLength);
        D2FileTimeStrc tFileTime;
        tFileTime.dwLowDateTime = 0;
        tFileTime.dwHighDateTime = 0;
        sub_0051F910_Report(0x80000002, 2, 0, 0, &tFileTime, szPatches, 0);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("Downloading Upgrade");
        break;
    }
    case 0:
        gnGlobal_008823B0 = 1;
        gnGlobal_008823EC = 1;
        sub_0051A480_DebugLog("User has latest version and a valid cdkey");
        break;
    case 0x101:
        sub_005204A0_SetError(1);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("User has unknown version");
        break;
    case 0x102:
        sub_005204A0_SetError(1);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("User must revert to an older version");
        break;
    case 0x200:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 7 : 3);
        sub_0051A480_DebugLog("User has an invalid cdkey (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x203:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 9 : 5);
        sub_0051A480_DebugLog("CD Key is for another product (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x202:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 8 : 4);
        sub_0051A480_DebugLog("CD Key is disabled (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x201:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 10 : 6);
        SStrCopy(gData_00882428, szInfo, 0x100);
        sub_00520550_SetStateArg(gData_00882428);
        sub_0051A480_DebugLog("CD Key is in use by %s (%ld)", gData_00882428, (nResult >> 4) & 0xF);
        break;
    }
    }
    return 1;
}

// 0x005215B0
int __fastcall sub_005215B0_AuthAccountCreate(const void* pData, unsigned int nSize)
{
    if (nSize < 4)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountCreate");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        gdwGlobal_008822A4 = 0;
        sub_0051A480_DebugLog("Account created");
        break;
    case 4:
        gdwGlobal_008822A4 = 4;
        sub_0051A480_DebugLog("Create failed: Name is in use");
        break;
    case 7:
        gdwGlobal_008822A4 = 1;
        sub_0051A480_DebugLog("Create failed: Name blank");
        break;
    case 8:
        gdwGlobal_008822A4 = 2;
        sub_0051A480_DebugLog("Create failed: Name contains bad characters");
        break;
    case 9:
        gdwGlobal_008822A4 = 3;
        sub_0051A480_DebugLog("Create failed: Name contains bad words");
        break;
    case 10:
        gdwGlobal_008822A4 = 6;
        sub_0051A480_DebugLog("Create failed: Name doesn't have alpha characters");
        break;
    case 11:
        gdwGlobal_008822A4 = 7;
        sub_0051A480_DebugLog("Create failed: Name contains adjacent punctuation");
        break;
    case 12:
        gdwGlobal_008822A4 = 8;
        sub_0051A480_DebugLog("Create failed: Name contains too much punctuation");
        break;
    default:
        gdwGlobal_008822A4 = 4;
        sub_0051A480_DebugLog("Create failed: unknown result");
        break;
    }
    gdwGlobal_008823F0 = 1;
    return 1;
}

// 0x005216B0
int __fastcall sub_005216B0_AuthAccountLogon(const void* pData, unsigned int nSize)
{
    if (nSize < 0x44)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountLogon");
        return 0;
    }

    switch (*(const int*)pData)
    {
    case 0:
        sub_0051A480_DebugLog("Logon requires proof");
        return sub_005220B0_SendLogonProof((const unsigned char*)pData + 4, (const unsigned char*)pData + 0x24);
    case 1:
        sub_0051A480_DebugLog("Logon failed: Account unknown");
        sub_005204A0_SetError(0x0D);
        gdwGlobal_0072FFA8 = 1;
        return 1;
    case 5:
        sub_0051A480_DebugLog("Logon requires upgrade");
        if (!sub_005223A0(1))
        {
            sub_005204A0_SetError(0x12);
            return 0;
        }
        return 1;
    default:
        sub_0051A480_DebugLog("Logon failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521760
int __fastcall sub_00521760_AuthAccountLogonProof(const void* pData, unsigned int nSize)
{
    if (nSize < 0x18)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountLogonProof");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        if (sub_005224C0_CheckServerProof((const unsigned char*)pData + 4))
        {
            sub_0051A480_DebugLog("Logon Proof success");
            gdwGlobal_0072FFA8 = 0;
            return 1;
        }
        sub_0051A480_DebugLog("Logon Proof failed: Server didn't know our password but told us it did!");
        sub_005204A0_SetError(0x12);
        return 0;
    case 2:
        sub_0051A480_DebugLog("Logon Proof failed: Invalid password");
        sub_005204A0_SetError(0x0E);
        gdwGlobal_0072FFA8 = 2;
        return 1;
    default:
        sub_0051A480_DebugLog("Logon Proof failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521800
int __fastcall sub_00521800_AuthAccountChange(const void* pData, unsigned int nSize)
{
    if (nSize < 0x44)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountChange");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        sub_0051A480_DebugLog("Change requires proof");
        return sub_00522310_SendChangeProof((const unsigned char*)pData + 4, (const unsigned char*)pData + 0x24);
    case 1:
        sub_0051A480_DebugLog("Change failed: Account unknown");
        sub_005204A0_SetError(0x0D);
        return 1;
    case 5:
        sub_0051A480_DebugLog("Change requires upgrade");
        return sub_005223A0(0);
    default:
        sub_0051A480_DebugLog("Change failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x005218A0
int __fastcall sub_005218A0_AuthAccountChangeProof(const void* pData, unsigned int nSize)
{
    if (nSize < 0x18)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountChangeProof");
        return 0;
    }
    const int nResult = *(const int*)pData;
    sub_005224F0_ClearPassword();
    switch (nResult)
    {
    case 0:
        if (sub_005224C0_CheckServerProof((const unsigned char*)pData + 4))
        {
            sub_0051A480_DebugLog("Change Proof success");
            gdwGlobal_008823FC = 1;
            return 1;
        }
        sub_0051A480_DebugLog("Change Proof failed: Server didn't know our password but told us it did!");
        sub_005204A0_SetError(0x12);
        return 0;
    case 2:
        sub_0051A480_DebugLog("Change Proof failed: Invalid password");
        gdwGlobal_008823FC = 1;
        sub_005204A0_SetError(0x0E);
        return 1;
    default:
        sub_0051A480_DebugLog("Change Proof failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521950
int __fastcall sub_00521950_AuthAccountUpgrade(const void* pData, unsigned int nSize)
{
    if (nSize < 8)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountUpgrade");
        return 0;
    }
    const D2BnTokenReplyStrc* pReply = (const D2BnTokenReplyStrc*)pData;
    const unsigned int nToken = pReply->nToken;
    if (pReply->nResult)
    {
        sub_0051A480_DebugLog("Upgrade Failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
    sub_0051A480_DebugLog("Upgrade requires proof");
    sub_005223F0_SendUpgradeProof(nToken);
    return 1;
}

// 0x005219B0
int __fastcall sub_005219B0_AuthAccountUpgradeProof(const void* pData, unsigned int nSize)
{
    if (nSize < 4)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountUpgradeProof");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        if (sub_005224E0())
        {
            sub_0051A480_DebugLog("Upgrade Proof success, logging in");
            return sub_00522050_SendAccountLogon();
        }
        sub_0051A480_DebugLog("Upgrade Proof success, password changed");
        sub_005224F0_ClearPassword();
        gdwGlobal_008822A0 = 0;
        gdwGlobal_008823FC = 1;
        return 1;
    case 2:
        if (sub_005224E0())
        {
            sub_0051A480_DebugLog("Upgrade Proof Failed: Invalid password during logon");
            sub_005224F0_ClearPassword();
            gdwGlobal_0072FFA8 = 2;
            sub_005204A0_SetError(0x0E);
            return 1;
        }
        sub_0051A480_DebugLog("Upgrade Proof Failed: Invalid password during change");
        sub_005224F0_ClearPassword();
        gdwGlobal_008822A0 = 2;
        gdwGlobal_008823FC = 1;
        sub_005204A0_SetError(0x0E);
        return 1;
    default:
        sub_0051A480_DebugLog("Upgrade Proof failed: Unknown Result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521AB0
int __fastcall sub_00521AB0_SetEmail(const void* pData, unsigned int nSize)
{
    sub_0051CA80_SetFlag(1);
    return 1;
}

// 0x00521AC0
int __fastcall sub_00521AC0_OptionalWork(const void* pData, unsigned int nSize)
{
    if (pData && *(const char*)pData && nSize)
        sub_0051E3D0_SendPacket33((const char*)pData, 0x80000005);
    return 1;
}

// 0x00521AE0
int __fastcall sub_00521AE0_RequiredWork(const void* pData, unsigned int nSize)
{
    if (pData && *(const char*)pData && nSize)
        sub_0051E3D0_SendPacket33((const char*)pData, 0x80000006);
    return 1;
}

// 0x00521B40
static long sub_0051DC70_GetTime(long* pTime)
{
    return _time32(pTime);
}

static unsigned int sub_0051DD10_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

static int sub_0051DD20_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

static int sub_0051DD40_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap_006DF238[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return sub_0051DC70_GetTime(pTime);
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

// 0x00521BA0
unsigned int __cdecl sub_00521BA0_GetUILanguageId()
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

// 0x00522050
int __cdecl sub_00522050_SendAccountLogon()
{
    D2BnAccountLogonStrc tPacket;
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord_00882680.abPublic, sizeof(tPacket.abPublic));
    const unsigned int nLength = SStrCopy(tPacket.szAccountName, gszAccountName_00882540, sizeof(tPacket.szAccountName));
    sub_0051C5C0_SendPacket(0x53, &tPacket, sizeof(tPacket.abPublic) + nLength + 1);
    return 1;
}

// 0x005223A0
int __fastcall sub_005223A0_SendAccountUpgrade(int bRetry)
{
    if (bRetry && (unsigned int)++gdwGlobal_00882538 > 1)
        return 0;

    gtBigPair_0088273C.sub_00528660_MakeVerifier(gtLoginRecord_00882680.szName, gtLoginRecord_00882680.szPassword, gabNewVerifier_00882640, gabNewVerifier_00882640 + 0x20);
    sub_0051C5C0_SendPacket(0x57, 0, 0);
    return 1;
}

// 0x00522500
unsigned int __fastcall sub_00522500_GetNibble(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = (nIndex & 7) * 4;
    return (pKey[3 - (nIndex >> 3)] & (0xF << nShift)) >> nShift;
}

inline unsigned int GetNibble(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    return (pKey[nWord] & (0xF << nShift)) >> nShift;
}

inline void SetNibble(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    pKey[nWord] = (pKey[nWord] & ~(0xF << nShift)) | ((nValue & 0xF) << nShift);
}

// 0x00522530
void __fastcall sub_00522530_SetNibble(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    pKey[nWord] = (pKey[nWord] & ~(0xF << nShift)) | ((nValue & 0xF) << nShift);
}

// 0x00522570
unsigned int __fastcall sub_00522570_GetBit(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = nIndex & 0x1F;
    return (pKey[3 - (nIndex >> 5)] & (1 << nShift)) >> nShift;
}

// 0x005225A0
void __fastcall sub_005225A0_SetBit(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = nIndex & 0x1F;
    const unsigned int nWord = 3 - (nIndex >> 5);
    pKey[nWord] = (pKey[nWord] & ~(1 << nShift)) | ((nValue & 1) << nShift);
}

// 0x005225E0
unsigned int __fastcall sub_005225E0(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry)
{
    pSource += nWords;
    pDest += nWords;
    while (nWords > 0)
    {
        --nWords;
        const unsigned __int64 nResult = (unsigned __int64)*--pSource * nMultiplier + nCarry;
        *--pDest = (unsigned int)nResult;
        nCarry = (unsigned int)(nResult >> 32);
    }
    return nCarry;
}

// 0x00522650
void __fastcall sub_00522650(const char* szKey, unsigned char* pOut)
{
    int nBase = 5;
    unsigned int nPosition = 0x21;
    for (unsigned int i = 0; i < 26; ++i)
    {
        const unsigned int nFirst = (nPosition + 0x7B5) % 0x34;
        nPosition = (nFirst + 0x7B5) % 0x34;
        const int nValue = gaCdKeyCharMap_006E0100[(unsigned char)szKey[i]];
        pOut[nFirst] = nValue / nBase;
        pOut[nPosition] = nValue % nBase;
    }
}

// 0x00522980
void __stdcall sub_00522980(unsigned int* pKey)
{
    for (int i = 29; i >= 0; --i)
    {
        unsigned char nValue = (unsigned char)GetNibble(pKey, i);
        for (int j = 29; j > i; --j)
            nValue = gaSubstitutionBox_006DFF20[i][(unsigned char)GetNibble(pKey, j) ^ gaSubstitutionBox_006DFF20[i][nValue]];
        for (int j = i - 1; j >= 0; --j)
            nValue = gaSubstitutionBox_006DFF20[i][(unsigned char)GetNibble(pKey, j) ^ gaSubstitutionBox_006DFF20[i][nValue]];
        SetNibble(pKey, i, gaSubstitutionBox_006DFF20[i][nValue]);
    }
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

// 0x00522BC0
void __fastcall sub_00522BC0_FillRandomBytes(char* szBuffer, int nSize)
{
    srand(0x150B);
    for (int i = 0; i < nSize - 1; )
    {
        const char c = (char)rand();
        if (c)
        {
            szBuffer[i] = c;
            i += 1;
        }
    }
    srand(_time32(0));
    szBuffer[nSize - 1] = 0;
}

// 0x00522C20
void __cdecl sub_00522C20_ClearCryptState()
{
    sub_00524740_ClearKeySchedules();
    sub_005241A0_ClearHashContexts();
}

// 0x00522C30
void __fastcall sub_00522C30_InitCipherKeys(const char* szKey, int nUnused, volatile int bEncrypt)
{
    unsigned char abRandom[0x70];
    unsigned char abBlock[0x40];
    unsigned char abDigest[20];

    D2_ASSERT(szKey, 0x4E);

    srand(0x4FA7);
    unsigned char* pRandom = abRandom;
    int nCount = 0x70;
    while (nCount--)
    {
        *pRandom++ = (unsigned char)rand();
    }
    srand(_time32(0));

    int j = 0;
    for (int i = 0; i < 0x40; ++i)
    {
        if (!szKey[j])
        {
            j = 0;
        }
        abBlock[i] = szKey[j];
        ++j;
    }

    sub_00524280_InitHashContext(0);
    sub_00524200_HashBlock(0, abBlock, (unsigned int*)abDigest);
    sub_005241A0_ClearHashContexts();

    for (unsigned int i = 0; i < 0x70; ++i)
    {
        abRandom[i] ^= abDigest[i % 20];
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_00524780_SetKey(i, bEncrypt, (const D2IdeaUserKeyStrc*)&abRandom[i * 16]);
        sub_00524280_InitHashContext(i);
        sub_00524200_HashBlock(i, &abRandom[0x30], 0);
    }
}

// 0x00522E10
unsigned int __fastcall sub_00522E10_Decrypt(unsigned char* data,unsigned int size,unsigned int key)
{
 struct { unsigned char input[64],output[64]; } buffers;
 unsigned char digest[20];
 CHECK(data,0x91);
 const unsigned int& keyValue=key;
 const char* checkedKey=(const char*)keyValue;
 CHECK(checkedKey,0x92);
 ((D2CipherKeyView*)checkedKey)->Init(0);
 if(size<=8)return 0;
 size-=8;
 if(size&63)return 0;
 unsigned int remaining=size;
 int blockIndex=0;
 while(remaining){
  memcpy(buffers.input,data,64);
  sub_005241C0_GetDigest(0,digest);
  if(!(blockIndex&7)){
   for(int i=0;i<64;i+=8)sub_00524760_CipherBlock(0,(const unsigned short*)&buffers.input[i],(unsigned short*)&buffers.output[i]);
  }else memcpy(buffers.output,buffers.input,64);
  for(int i=0;i<64;++i)buffers.input[i]=buffers.output[i]-digest[(63-i)%20];
  if(!(blockIndex&15))sub_00524200_HashBlock(0,buffers.input,0);
  ++blockIndex;
  memcpy(data,buffers.input,64);
  remaining-=64;
  data+=64;
 }
 if(data[4]>0){
  sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return 0;
 }
 sub_005241C0_GetDigest(0,digest);
 if(*(unsigned int*)data!=*(unsigned int*)digest){
  sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return 0;
 }
 size+=data[5];
 size-=64;
 sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return size;
}

// 0x00523280
static unsigned int sub_00523280_CountTerminatedBytes(unsigned int maxLength, unsigned int length, const unsigned char* data)
{
    unsigned int count = 0;
    if (length >= maxLength)
        length = maxLength;
    if (!length)
        return 0;
    do
    {
        --length;
        ++count;
        if (!(*data++))
            return count;
    } while (length);
    return 0;
}

unsigned int __fastcall CountTerminatedBytesContext(unsigned int length, const unsigned char* data, unsigned int maxLength)
{
    return sub_00523280_CountTerminatedBytes(maxLength, length, data);
}

#include "gen/data/Source/D2BNClient/BnDownload_00520660.inc"
