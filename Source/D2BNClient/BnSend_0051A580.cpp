#include "D2BNClient.h"

#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}

struct D2BnHashInputStrc;
struct D2BnLogonResponsePacketStrc;
struct D2BnCreateAccountPacketStrc;
struct D2BnChangePasswordPacketStrc;
struct D2BnReportVersionPacketStrc;
struct D2BnJoinChannelPacketStrc;
struct D2BnStartAdvexPacketStrc;
struct D2BnNotifyJoinPacketStrc;
struct D2BnReadUserDataPacketStrc;

struct D2BnHashInputStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char abDigest[20];
};

struct D2BnLogonResponsePacketStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char abProof[20];
    char szName[0x100];
};

struct D2BnCreateAccountPacketStrc
{
    unsigned char f_0[20];
    char szName[0x100];
};

struct D2BnChangePasswordPacketStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char abOldProof[20];
    unsigned char abNewHash[20];
    char szName[0x100];
};

struct D2BnReportVersionPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    unsigned int f_C;
    unsigned int f_10;
    char f_14[0x100];
};

struct D2BnJoinChannelPacketStrc
{
    unsigned int dwFlags;
    char szChannel[0x100];
};

struct D2BnStartAdvexPacketStrc
{
    unsigned int dwState;
    unsigned int dwUptime;
    unsigned int dwGameType;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    char aData[0x100];
};

struct D2BnNotifyJoinPacketStrc
{
    unsigned int dwProduct;
    unsigned int dwVersion;
    char aData[0x200];
};

struct D2BnReadUserDataPacketStrc
{
    unsigned int nAccounts;
    unsigned int nKeys;
    unsigned int nCookie;
    char aData[4];
};
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char* szString);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
extern "C" void __cdecl sub_00408A60(const char* text,const char* file,int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int code); // 0x00681E09
extern "C" void* __cdecl memcpy(void* dest,const void* source,unsigned int count); // 0x006829C0
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

int gdwGlobal_008818BC; // 0x008818BC

// 0x0051A580
int __fastcall sub_0051A580_SendLogonResponse(const char* szName, const char* szPassword)
{
    D2BnLogonResponsePacketStrc tPacket;
    D2BnHashInputStrc tInput;
    char szLower[0x100];
    sub_00520C00_ClearReply(0x29);
    SStrCopy(szLower, szPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tInput.f_0 = GetTickCount();
    tInput.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tInput.abDigest, szLower, nLength);
    tPacket.f_0 = tInput.f_0;
    tPacket.f_4 = tInput.f_4;
    sub_005209D0_HashData(tPacket.abProof, &tInput, sizeof(tInput));
    sub_0051C5C0_SendPacket(0x29, &tPacket, SStrCopy(tPacket.szName, szName, 0x100) + 0x1D);
    return 1;
}

// 0x0051A660
int __fastcall sub_0051A660_SendLogonResponse2(const char* szName, const char* szPassword)
{
    D2BnLogonResponsePacketStrc tPacket;
    D2BnHashInputStrc tInput;
    char szLower[0x100];
    sub_00520C00_ClearReply(0x3A);
    SStrCopy(szLower, szPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tInput.f_0 = GetTickCount();
    tInput.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tInput.abDigest, szLower, nLength);
    tPacket.f_0 = tInput.f_0;
    tPacket.f_4 = tInput.f_4;
    sub_005209D0_HashData(tPacket.abProof, &tInput, sizeof(tInput));
    sub_0051C5C0_SendPacket(0x3A, &tPacket, SStrCopy(tPacket.szName, szName, 0x100) + 0x1D);
    return 1;
}

// 0x0051A740
int __fastcall sub_0051A740_SendCreateAccount2(const char* szName, const char* szPassword)
{
    D2BnCreateAccountPacketStrc tPacket;
    char szLower[0x100];
    SStrCopy(szLower, szPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    sub_005209D0_HashData(tPacket.f_0, szLower, nLength);
    sub_0051C5C0_SendPacket(0x3D, &tPacket, SStrCopy(tPacket.szName, szName, 0x100) + 0x15);
    return 1;
}

// 0x0051A7D0
int __fastcall sub_0051A7D0_ChangePasswordLegacy(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    D2BnChangePasswordPacketStrc tPacket;
    D2BnHashInputStrc tInput;
    char szLower[0x100];
    SStrCopy(szLower, szOldPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tInput.f_0 = GetTickCount();
    tInput.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tInput.abDigest, szLower, nLength);
    SStrCopy(szLower, szNewPassword, 0x100);
    nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tPacket.f_0 = tInput.f_0;
    tPacket.f_4 = tInput.f_4;
    sub_005209D0_HashData(tPacket.abOldProof, &tInput, sizeof(tInput));
    sub_005209D0_HashData(tPacket.abNewHash, szLower, nLength);
    sub_0051C5C0_SendPacket(0x31, &tPacket, SStrCopy(tPacket.szName, szAccountName, 0x100) + 0x31);
    return 1;
}

// 0x0051A8F0
int __fastcall sub_0051A8F0_HandleLogon(unsigned int dwExeVersion, unsigned int dwExeHash, const char* szExeInfo)
{
    D2BnReportVersionPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = 0xE;
    tPacket.f_C = dwExeVersion;
    tPacket.f_10 = dwExeHash;
    SStrCopy(tPacket.f_14, szExeInfo, 0x100);
    return sub_0051C5C0_SendPacket(7, &tPacket, strlen(tPacket.f_14) + 0x15) >= 0;
}

// 0x0051ACA0
int __fastcall sub_0051ACA0_SendString(const char* szChannel, int bFlag, int bNoExpansion)
{
    D2BnJoinChannelPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    if (szChannel && *szChannel)
    {
        tPacket.dwFlags = bFlag ? 2 : 0;
        SStrCopy(tPacket.szChannel, szChannel, 0x100);
    }
    else
    {
        tPacket.dwFlags = 1;
        if (sub_0051BEC0_IsExpansion() && !bNoExpansion)
            tPacket.dwFlags |= 4;
        SStrCopy(tPacket.szChannel, "Diablo II", 0x100);
    }
    sub_0051C5C0_SendPacket(0xC, &tPacket, strlen(tPacket.szChannel) + 5);
    return 1;
}

// 0x0051B0E0
int __fastcall sub_0051B0E0_SendStartAdvex3(const char* szGameName, const char* szPassword, const char* szStatstring, int nGameType)
{
    D2BnStartAdvexPacketStrc tPacket;
    tPacket.dwState = 0;
    tPacket.dwUptime = 0;
    tPacket.dwGameType = nGameType;
    tPacket.dwUnknown0C = 0;
    tPacket.f_10 = 0;
    if (!szGameName)
        szGameName = &gszEmptyAssertText;
    if (!szPassword)
        szPassword = &gszEmptyAssertText;
    if (!szStatstring)
        szStatstring = &gszEmptyAssertText;
    if (*szPassword)
        tPacket.dwState = 1;
    char* pText = tPacket.aData;
    pText += SStrCopy(pText, szGameName, 0x100) + 1;
    pText += SStrCopy(pText, szPassword, 0x100) + 1;
    unsigned int nLength = SStrCopy(pText, szStatstring, 0x100);
    nLength += (pText - tPacket.aData) + 0x15;
    sub_0051C5C0_SendPacket(0x1C, &tPacket, nLength);
    return 1;
}

// 0x0051B320
int __fastcall sub_0051B320_SendNotifyJoin(const char* szGameName, const char* szPassword)
{
    D2BnNotifyJoinPacketStrc tPacket;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = 0xE;
    char* pText = tPacket.aData;
    pText += SStrCopy(pText, szGameName, 0x100) + 1;
    unsigned int nLength = SStrCopy(pText, szPassword, 0x100);
    nLength += (pText - tPacket.aData) + 9;
    sub_0051C5C0_SendPacket(0x22, &tPacket, nLength);
    return 1;
}

// 0x0051B870
int __fastcall sub_0051B870_SendReadUserData(const char* szAccount, unsigned int nKeys, unsigned int nCookie, const char* const* ppKeys)
{
    unsigned int nSize = SStrLen(szAccount) + 1;
    for (unsigned int i = 0; i < nKeys; ++i)
        nSize += SStrLen(ppKeys[i]) + 1;

    D2BnReadUserDataPacketStrc* pPacket = (D2BnReadUserDataPacketStrc*)FOG_Alloc(nSize + 0xC, ".\\BnSend.cpp", 0x506, 0);
    pPacket->nAccounts = 1;
    pPacket->nKeys = nKeys;
    pPacket->nCookie = nCookie;
    char* pText = pPacket->aData;
    pText += SStrCopy(pText, szAccount, 0x7FFFFFFF) + 1;
    for (unsigned int i = 0; i < nKeys; ++i)
        pText += SStrCopy(pText, ppKeys[i], 0x7FFFFFFF) + 1;

    sub_00520C00_ClearReply(0x26);
    int bResult = sub_0051C5C0_SendPacket(0x26, pPacket, pText - (char*)pPacket) >= 0;
    FOG_Free(pPacket, ".\\BnSend.cpp", 0x521, 0);
    return bResult != 0;
}

// 0x0051BB90
int __fastcall sub_0051BB90_SendStrings(const char* first,const char* second,const char* third)
{
 char buffer[768];
 D2_ASSERT(first,1433);
 D2_ASSERT(*first,1434);
 if(!second || !*second || !third || !*third) return 0;
 unsigned int firstSize=SStrLen(first)+1;
 D2_ASSERT(firstSize<=256,1444);
 memcpy(buffer,first,firstSize);
 char* cursor=buffer+firstSize;
 char** ppCursor=&cursor;
 unsigned int secondSize=SStrLen(second)+1;
 D2_ASSERT(secondSize<=256,1452);
 memcpy(*ppCursor,second,secondSize);
 *ppCursor+=secondSize;
 unsigned int thirdSize=SStrLen(third)+1;
 D2_ASSERT(thirdSize<=256,1460);
 memcpy(*ppCursor,third,thirdSize);
 return sub_0051C5C0_SendPacket(0x5B,buffer,thirdSize+secondSize+firstSize)>=0;
}
