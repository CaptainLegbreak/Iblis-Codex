#include "D2BNClient.h"
#include "D2BnCryptTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2BigPowModStrc;
struct D2BnDnsArgsStrc;
class BNGatewayAccess;
struct D2BnPacketHeaderStrc;
struct D2CriticalSectionStrc;
struct D2BigLoginRecordStrc;
struct D2BigPairStrc;

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern long volatile gnConnected_00881BF0; // 0x00881BF0
static __declspec(noinline) long sub_0051BEB0_ExchangeConnected(long nComparand, long nExchange);
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" int __cdecl isdigit(int c); // 0x00686F0F
extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName); // 0x006B0192
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454
extern "C" int __cdecl rand(); // 0x00687461
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __cdecl sub_00518D40_Log(const char* szFormat, ...); // 0x00518D40
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480
extern "C" const char gszSemicolon_006CDA54[]; // 0x006CDA54
int __fastcall sub_005202F0_QueueText(int nId, const char* szText); // 0x005202F0

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

extern BNGatewayAccess gBnGatewayAccess_00881838; // 0x00881838
extern int gbDnsPending_008818E0; // 0x008818E0
int __fastcall sub_0051A660_SendLogonResponse2(const char* szName, const char* szPassword); // 0x0051A660
int __fastcall sub_0051A740_SendCreateAccount2(const char* szName, const char* szPassword); // 0x0051A740
int __cdecl sub_0051AF20_SendPacket10(); // 0x0051AF20
int __fastcall sub_005204A0_SetError(int nError); // 0x005204A0
int __cdecl sub_00520B10(); // 0x00520B10
int __cdecl sub_00520B20(); // 0x00520B20
int __fastcall sub_00521F60_SendLogon(const char* szName, const char* szPassword); // 0x00521F60
int __fastcall sub_00522130_SendCreateAccount(const char* szName, const char* szPassword); // 0x00522130

struct D2BnPacketHeaderStrc
{
    unsigned char f_0;
    unsigned char nId;
    unsigned short nLength;
};

typedef int (__fastcall* D2BnPacketHandler)(const void* pData, int nSize);

int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DCC0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
extern D2BnPacketHandler gpfPacketHandlers_0072FFB0[]; // 0x0072FFB0
extern long volatile gnDnsDone_00881BFC; // 0x00881BFC
extern int gnSlotArrayA_00882128[94]; // 0x00882128
extern "C" char* __cdecl strchr(const char* s, int c); // 0x00687740
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern int gdwGlobal_00881C04; // 0x00881C04
extern D2CriticalSectionStrc gMessageLock_00882004; // 0x00882004
extern int gnBnState_0088201C; // 0x0088201C
extern D2BigLoginRecordStrc gtLoginRecord_00882680; // 0x00882680
extern D2BigPairStrc gtBigPair_0088273C; // 0x0088273C
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
int __fastcall FOG_SOCKET_WSAStartup(); // 0x0040D890
void __fastcall sub_0051C0E0_ResolveHost(char* szResult, const char* szHost); // 0x0051C0E0
void __fastcall sub_0051C190(char* szText, int nSize); // 0x0051C190
int __stdcall sFastestConnect(char* szServerList); // 0x0051CA90
void __fastcall sub_0051EA40_SetStatus(int nStatus); // 0x0051EA40
int __fastcall sub_00520520_SetState(int nState); // 0x00520520

// 0x0051BEB0
static long sub_0051BEB0_ExchangeConnected(long nComparand, long nExchange)
{
    return InterlockedCompareExchange(&gnConnected_00881BF0, nExchange, nComparand);
}

long __fastcall ExchangeConnectedContext(long nExchange, long nComparand)
{
    return sub_0051BEB0_ExchangeConnected(nComparand, nExchange);
}

unsigned long gnDnsAddr_00881C08; // 0x00881C08

char* gapDnsAddrList_00881C0C[2]; // 0x00881C0C

D2HostentStrc gDnsHostent_00881C14; // 0x00881C14

// 0x0051BEE0
unsigned long __stdcall sub_0051BEE0(void* pArguments)
{
    D2BnDnsArgsStrc* pArgs = (D2BnDnsArgsStrc*)pArguments;
    char* szOut = pArgs->szResult;
    const char* szHost = pArgs->f_4;
    D2HostentStrc* pHost;
    if (isdigit(*szHost))
    {
        const unsigned long nAddr = inet_addr(szHost);
        if (nAddr == 0xFFFFFFFF)
        {
            sub_00518D40_Log("ERROR GetServersList: inet_addr failed to convert IP (%d)", WSAGetLastError());
            return 0;
        }
        gDnsHostent_00881C14.h_addr_list = gapDnsAddrList_00881C0C;
        gapDnsAddrList_00881C0C[0] = (char*)&gnDnsAddr_00881C08;
        gapDnsAddrList_00881C0C[1] = 0;
        pHost = &gDnsHostent_00881C14;
        gnDnsAddr_00881C08 = nAddr;
    }
    else
    {
        pHost = gethostbyname(szHost);
        if (!pHost)
        {
            sub_00518D40_Log("ERROR GetServersList: gethostbyname failed to get server list (%d)", WSAGetLastError());
            return 0;
        }
    }

    char** ppList = pHost->h_addr_list;
    int nCount = 0;
    sub_0051A480_DebugLog(&gszEmptyAssertText);
    sub_0051A480_DebugLog("Original servlist:");
    while (ppList[nCount])
    {
        sub_0051A480_DebugLog("%d --> %s", nCount, inet_ntoa(*(D2InAddrStrc*)ppList[nCount]));
        ++nCount;
    }
    sub_0051A480_DebugLog(&gszEmptyAssertText);
    sub_0051A480_DebugLog("Scrambled servlist:");

    srand(GetTickCount());
    for (int j = 0; j < nCount - 1; ++j)
    {
        const int k = rand() * (nCount - 1 - j) / 0x8000 + j;
        D2_ASSERT(j <= k, 0x1AD);
        sub_0051A480_DebugLog("%d <-> %d SWAP", j, k);
        const unsigned long nTemp = ((D2InAddrStrc*)ppList[j])->s_addr;
        ((D2InAddrStrc*)ppList[j])->s_addr = ((D2InAddrStrc*)ppList[k])->s_addr;
        ((D2InAddrStrc*)ppList[k])->s_addr = nTemp;
    }
    sub_0051A480_DebugLog(&gszEmptyAssertText);

    char* p = szOut;
    for (char** pp = pHost->h_addr_list; *pp; ++pp)
    {
        p += SStrCopy(p, inet_ntoa(*(D2InAddrStrc*)*pp), 0x7FFFFFFF);
        p += SStrCopy(p, gszSemicolon_006CDA54, 0x7FFFFFFF);
    }
    if (p > szOut)
        p[-1] = 0;
    return 1;
}

// 0x0051C170
int __cdecl sub_0051C170_PostBnServerIniMessage()
{
    return sub_0051E3D0_PostMessage("bnserver-D2DV.ini", 0x80000004);
}

// 0x0051C6B0
int __fastcall sub_0051C6B0_QueueTextLine(const char* szText)
{
    return sub_005202F0_QueueText(1, szText);
}

// 0x0051CA20
char __cdecl sub_0051CA20_GetGatewayLetter()
{
    return 'G';
}

// 0x0051C180
BNGatewayAccess* __cdecl sub_0051C180_GetBnGatewayAccess()
{
    gBnGatewayAccess_00881838.Load();
    return &gBnGatewayAccess_00881838;
}

// 0x0051C210
void __fastcall sub_0051C210_GetConnectionState(int* pState)
{
    D2_ASSERT(pState, 0x280);
    *pState = gbDnsPending_008818E0;
}

// 0x0051C240
int __fastcall sub_0051C240_Logon(const char* szName, const char* szPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x3A);
        sub_0051A660_SendLogonResponse2(szName, szPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x54);
        return sub_00521F60_SendLogon(szName, szPassword);
    }
    return 0;
}

// 0x0051C290
int __cdecl sub_0051C290_GetLogonInfo()
{
    if (sub_00520AE0())
    {
        sub_005204A0_SetError(0x12);
        return 0;
    }
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return sub_00520BF0_IsReplyReceived(0x3A);
    case 1:
        return sub_00520BF0_IsReplyReceived(0x54);
    }
    return 0;
}

// 0x0051C2D0
int __fastcall sub_0051C2D0_CreateAccount(const char* szName, const char* szPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x3D);
        sub_0051A740_SendCreateAccount2(szName, szPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x52);
        return sub_00522130_SendCreateAccount(szName, szPassword);
    }
    return 0;
}

// 0x0051C320
int __fastcall sub_0051C320_GetCreateAccountResult(int* pResult)
{
    *pResult = sub_00520B10();
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return sub_00520BF0_IsReplyReceived(0x3D);
    case 1:
        return sub_00520BF0_IsReplyReceived(0x52);
    }
    return 0;
}

// 0x0051C3B0
int __fastcall sub_0051C3B0_GetChangePasswordResult(int* pResult)
{
    *pResult = sub_00520B20();
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return sub_00520BF0_IsReplyReceived(0x31);
    case 1:
        return sub_00520BF0_IsReplyReceived(0x56);
    }
    return 0;
}

// 0x0051C460
int __cdecl sub_0051C460_LeaveChat()
{
    sub_0051AF20_SendPacket10();
    return 1;
}

// 0x0051C5C0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize)
{
    D2BnPacketHeaderStrc tHeader;
    char aBuffer[0x2000];
    tHeader.f_0 = 0xFF;
    tHeader.nId = nId;
    tHeader.nLength = (unsigned short)(nSize + 4);
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (!pSafeSock || InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        sub_00520AD0_SetDisconnected();
        return 0;
    }
    if (!pData)
        nSize = 0;
    unsigned int nTotal = nSize + 4;
    SMemCopy(aBuffer, &tHeader, 4);
    if (pData && nTotal < 0x2000)
        SMemCopy(aBuffer + 4, pData, nSize);
    return FOG_SOCKET_Send(pSafeSock, aBuffer, nTotal);
}

// 0x00521B00
int __fastcall sub_00521B00(unsigned char nId, const void* pData, int nSize)
{
    int nResult = 0;
    if (nId < 0x5E)
    {
        if (gpfPacketHandlers_0072FFB0[nId])
            nResult = gpfPacketHandlers_0072FFB0[nId](pData, nSize);
        gnSlotArrayA_00882128[nId] = 1;
    }
    return nResult;
}

#include "gen/data/Source/D2BNClient/BnSend_0051BEB0.inc"

// 0x0051C6C0
void __fastcall sub_0051C6C0_QueueTextLines(const char* szText)
{
    char szLine[288];

    const char* pEnd = strchr(szText, '\r');
    while (pEnd)
    {
        const int nLength = D2_MIN(pEnd - szText, 287);
        memcpy(szLine, szText, nLength);
        szLine[nLength] = 0;
        sub_005202F0_QueueText(1, szLine);
        szText = pEnd + 1;
        if (pEnd[1] == '\n')
            ++szText;
        pEnd = strchr(szText, '\r');
    }
}

char gData_00882028[256]; // 0x00882028

// 0x0051CA80
void __fastcall sub_0051CA80_SetFlag(int nValue)
{
    gdwGlobal_00881C04 = nValue;
}

// 0x005204D0
int __fastcall sub_005204D0_SetErrorText(int nError, const char* szText)
{
    EnterCriticalSection(&gMessageLock_00882004);
    if (!gnBnState_0088201C)
    {
        gnBnState_0088201C = nError;
        SStrCopy(gszEmptyStateText_00881F80, szText, 0x80);
    }
    LeaveCriticalSection(&gMessageLock_00882004);
    return 1;
}

// 0x00520630
int __fastcall sub_00520630_SetText(const char* szText)
{
    SStrCopy(gData_00882028, szText, 0x100);
    return 1;
}

// 0x005224C0
int __fastcall sub_005224C0_CheckServerProof(const unsigned char* pServerProof)
{
    return gtBigPair_0088273C.sub_00528890_CompareServerProof(&gtLoginRecord_00882680, pServerProof);
}

// 0x005224F0
void __cdecl sub_005224F0_ClearPassword()
{
    sub_0041D300_ZeroMemory(gtLoginRecord_00882680.szPassword, sizeof(gtLoginRecord_00882680.szPassword));
}

char gszBnetHost_008818E8[0x100]; // 0x008818E8

char gszBnetAddress_008819E8[0x100]; // 0x008819E8

long volatile gnSendBusy_00881C00; // 0x00881C00

// 0x0051D0A0
unsigned long __cdecl BattleConnectFastest(void* pParameter)
{
    sub_0051A480_DebugLog("BattleConnectFastest()");
    if (InterlockedIncrement(&gnSendBusy_00881C00) > 1)
    {
        InterlockedDecrement(&gnSendBusy_00881C00);
        return 0;
    }

    sub_0051EA40_SetStatus(0x66);
    sub_0051C190(gszBnetHost_008818E8, 0x100);
    sub_0051A480_DebugLog("   connect to: %s", gszBnetHost_008818E8);
    sub_00518C70_LogIndent(2, 4);
    sub_00518D40_Log("querying gateway %s", gszBnetHost_008818E8);
    gszBnetAddress_008819E8[0] = 0;
    if (FOG_SOCKET_WSAStartup())
        sub_0051C0E0_ResolveHost(gszBnetAddress_008819E8, gszBnetHost_008818E8);

    if (!gszBnetAddress_008819E8[0])
    {
        InterlockedDecrement(&gnSendBusy_00881C00);
        sub_00520520_SetState(0xC);
        sub_0051A480_DebugLog("   failed to get server list");
        sub_00518C70_LogIndent(2, -4);
        return 0;
    }

    sub_00520520_SetState(0);
    sFastestConnect(gszBnetAddress_008819E8);
    sub_00518C70_LogIndent(2, -4);
    if (!InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0) && !InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
        sub_00520520_SetState(0xC);

    InterlockedDecrement(&gnSendBusy_00881C00);
    return 1;
}
