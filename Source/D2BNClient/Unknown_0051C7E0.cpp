#include "D2BNClient.h"

#define FD_ZERO(set) (((D2FdSetStrc*)(set))->fd_count = 0)
#define FD_SET(fd, set) do { \
    if (((D2FdSetStrc*)(set))->fd_count < 64) \
        ((D2FdSetStrc*)(set))->fd_array[((D2FdSetStrc*)(set))->fd_count++] = (fd); \
} while (0)
struct D2BnCheckAdReplyStrc;
struct D2CriticalSectionStrc;
struct D2FdSetStrc;
struct D2TimevalStrc;
struct D2SockAddrInStrc;
struct D2BnStateStrc;
struct D2BnServerEntryStrc;

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnCheckAdReplyStrc
{
    unsigned int nAdId;
    unsigned int nExtension;
    unsigned char pData[1];
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
int __fastcall sub_0051C760_SplitPackets(unsigned char* pBuffer, int nLength); // 0x0051C760
extern "C" unsigned int __cdecl strlen(const char* szString);
extern long volatile gnConnected_00881BF0; // 0x00881BF0
extern int gbReady_00881BF8; // 0x00881BF8
extern unsigned int gnVersion_0088252C; // 0x0088252C

struct D2FdSetStrc
{
    unsigned int fd_count;
    unsigned int fd_array[64];
};

struct D2TimevalStrc
{
    long tv_sec;
    long tv_usec;
};

struct D2SockAddrInStrc
{
    short sin_family;
    unsigned short sin_port;
    D2InAddrStrc sin_addr;
    char sin_zero[8];
};

struct D2BnServerEntryStrc
{
    char szAddress[0x100];
    FSafeSock* pSafeSock;
    int nUnused;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet); // 0x006B0180
extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186
FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking); // 0x0040D8E0
int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DCC0
int __fastcall FOG_SOCKET_SetBlockingMode(FSafeSock* pSafeSock, int bNonBlocking); // 0x0040E1A0
void __cdecl sub_00518D40_Log(const char* szFormat, ...); // 0x00518D40
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480
unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter); // 0x0051C7E0
void __fastcall sub_0051EA40_SetStatus(int nStatus); // 0x0051EA40
int __fastcall sub_00520520_SetState(int nState); // 0x00520520
int __fastcall sub_005205F0_GetState(D2BnStateStrc* pState); // 0x005205F0
extern "C" int __fastcall sub_00520C20_GetSlotB(unsigned char nSlot); // 0x00520C20
int __stdcall sub_00521BF0(); // 0x00521BF0
int __cdecl sub_00521DC0_SendAuthCheck();
extern long volatile gnDnsDone_00881BFC; // 0x00881BFC

long volatile gnReceiveThreads_00881BF4; // 0x00881BF4

long volatile gnDnsDone_00881BFC; // 0x00881BFC

// 0x0051C7E0
unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter)
{
    char aBuffer[0x2000 + 1];
    int nResult = 1;
    if (InterlockedIncrement(&gnReceiveThreads_00881BF4) > 1)
    {
        InterlockedDecrement(&gnReceiveThreads_00881BF4);
        return 1;
    }
    while (!InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0) && !gbReady_00881BF8)
        Sleep(10);
    unsigned long dwLastTick = GetTickCount();
    int nUsed = 0;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    while (pSafeSock && !pSafeSock->bStopping && !InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        const int bReady = FOG_SOCKET_Select(pSafeSock);
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
        if (!pSafeSock || pSafeSock->bStopping || InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
            break;
        if (bReady)
        {
            const int nReceived = FOG_SOCKET_Receive(pSafeSock, &aBuffer[nUsed], 0x2000 - nUsed);
            if (nReceived <= 0)
            {
                sub_00520AD0_SetDisconnected();
                nResult = 0;
                break;
            }
            nUsed = sub_0051C760_SplitPackets((unsigned char*)aBuffer, nReceived + nUsed);
        }
        const unsigned long dwTick = GetTickCount();
        if (dwTick - dwLastTick >= 180000)
        {
            sub_0051C5C0_SendPacket(0, 0, 0);
            dwLastTick = dwTick;
        }
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    }
    InterlockedDecrement(&gnReceiveThreads_00881BF4);
    return nResult;
}

// 0x00521150
int __fastcall sub_00521150(const D2BnCheckAdReplyStrc* pPacket, unsigned int nSize)
{
    const unsigned int nAdId = pPacket->nAdId;
    if (nSize >= 0x11 && nAdId != gnVersion_0088252C)
    {
        const unsigned char* pData = pPacket->pData;
        const char* szFileName = (const char*)(pData + sizeof(D2FileTimeStrc));
        gnVersion_0088252C = nAdId;
        const char* szLink = szFileName + strlen(szFileName) + 1;
        if (*szFileName && *szLink)
            sub_0051F910_Report(0x80000003, 5, nAdId, pPacket->nExtension, (const D2FileTimeStrc*)pData, szFileName, szLink);
    }
    return 1;
}

int gbDnsPending_008818E0; // 0x008818E0

long volatile gnConnected_00881BF0; // 0x00881BF0

int gbReady_00881BF8; // 0x00881BF8

int __cdecl sub_0051CA30_IsReady()
{
    D2BnStateStrc tState;
    sub_005205F0_GetState(&tState);
    if (!sub_00520AE0() && tState.nState == 0 && InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0))
        return 1;
    return 0;
}

// 0x0051CA90
int __stdcall sFastestConnect(char* szServerList)
{
    D2BnServerEntryStrc aServers[32];

    sub_0051A480_DebugLog("sFastestConnect()");
    memset(aServers, 0, sizeof(aServers));
    sub_0051EA40_SetStatus(0x66);
    if (!szServerList)
        return 1;

    gbReady_00881BF8 = 0;
    gbDnsPending_008818E0 = 2;
    Sleep(10);
    sub_00518D40_Log("searching for the fastest server");

    char* szToken = strtok(szServerList, " ,;");
    int nServers = 0;
    unsigned long dwLastTick = GetTickCount() - 5000;
    D2TimevalStrc tTimeout;
    tTimeout.tv_sec = 1;
    tTimeout.tv_usec = 0;
    int nRetries = 0;
    FSafeSock* pConnected = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (!pConnected)
    {
        D2BnServerEntryStrc* pEntry = aServers;
        do
        {
        if (InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
            break;

        if (GetTickCount() - dwLastTick >= 5000)
        {
            dwLastTick = GetTickCount();
            if (szToken && *szToken && nServers < 32)
            {
                sub_0051A480_DebugLog("  Try to connect to %s", szToken);
                strcpy(pEntry->szAddress, szToken);
                pEntry->pSafeSock = FOG_SOCKET_ConnectEx(pEntry->szAddress, 6112, sub_0051C7E0_ReceiveThread, 0, "Client->BNet", 1);
                ++nServers;
                ++pEntry;
                szToken = strtok(0, " ,;");
            }
        }

        D2FdSetStrc tWrite;
        D2FdSetStrc tExcept;
        FD_ZERO(&tWrite);
        FD_ZERO(&tExcept);
        int nActive = 0;
        for (int i = 0; i < nServers; ++i)
        {
            if (aServers[i].pSafeSock)
            {
                unsigned int nSocket = aServers[i].pSafeSock->nSocket;
                FD_SET(nSocket, &tWrite);
                FD_SET(nSocket, &tExcept);
                ++nActive;
            }
        }

        if (!nActive)
        {
            if (!szToken || !*szToken)
                break;
            Sleep(10);
            continue;
        }

        int nResult = select(0x40, 0, &tWrite, &tExcept, &tTimeout);
        if (!nResult)
        {
            if (nRetries++ > 60)
                break;
        }
        else if (nResult == -1)
        {
            WSAGetLastError();
        }
        else
        {
            for (int i = 0; i < nServers; ++i)
            {
                if (aServers[i].pSafeSock && __WSAFDIsSet(aServers[i].pSafeSock->nSocket, &tExcept))
                {
                    FOG_SOCKET_Destroy(aServers[i].pSafeSock);
                    aServers[i].pSafeSock = 0;
                }
            }

            for (int i = 0; i < nServers; ++i)
            {
                if (aServers[i].pSafeSock && __WSAFDIsSet(aServers[i].pSafeSock->nSocket, &tWrite))
                {
                    if (!InterlockedCompareExchange(&gnConnected_00881BF0, (long)aServers[i].pSafeSock, 0))
                    {
                        pConnected = aServers[i].pSafeSock;
                        pConnected->bConnected = 1;
                        pConnected->bConnecting = 0;
                    }
                    break;
                }
            }

            if (pConnected)
                break;
        }
        } while (!(pConnected = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0)));
    }

    for (int i = 0; i < nServers; ++i)
    {
        if (aServers[i].pSafeSock && aServers[i].pSafeSock != pConnected)
        {
            FOG_SOCKET_Destroy(aServers[i].pSafeSock);
            aServers[i].pSafeSock = 0;
        }
    }

    if (!pConnected)
    {
        sub_00518D40_Log("no servers found");
        return 0;
    }

    gbReady_00881BF8 = 1;
    if (!sub_0051CA30_IsReady())
    {
        sub_0051A480_DebugLog("  Error, not connected.");
        return 0;
    }

    int nLength = 16;
    D2SockAddrInStrc tAddress;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (pSafeSock && FOG_SOCKET_GetPeerName(pSafeSock, &tAddress, &nLength))
        sub_00518D40_Log("Connected to server %s", inet_ntoa(tAddress.sin_addr));

    gbDnsPending_008818E0 = 3;
    Sleep(10);
    sub_00518D40_Log("accessing accounts");
    FOG_SOCKET_SetBlockingMode(pConnected, 0);
    char nByte = 1;
    if (FOG_SOCKET_Send(pConnected, &nByte, 1) <= 0)
    {
        sub_0051A480_DebugLog("  Failed send.");
        return 0;
    }

    sub_00520C00_ClearReply(0x50);
    sub_00521BF0();
    if (!sub_00520B70_WaitForReply(0x50) && !sub_0051CA30_IsReady())
    {
        FOG_SOCKET_Destroy(pConnected);
        InterlockedCompareExchange(&gnConnected_00881BF0, 0, (long)pConnected);
        return 0;
    }

    if (sub_00520AE0())
    {
        sub_00520520_SetState(0xB);
        return 1;
    }

    gbDnsPending_008818E0 = 4;
    Sleep(10);
    sub_00518D40_Log("Checking for the latest version");
    sub_0051EA40_SetStatus(0x66);
    sub_00520C00_ClearReply(0x51);
    if (!sub_00521DC0_SendAuthCheck())
        return 0;
    if (!sub_00520B70_WaitForReply(0x51))
        return 0;

    D2BnStateStrc tState;
    sub_005205F0_GetState(&tState);
    if (!tState.nState && sub_00520C20_GetSlotB(0x51))
    {
        sub_0051E3D0_PostMessage("bnserver-D2DV.ini", 0x80000004);
        sub_00518D40_Log("Connected to Battle.net");
    }
    return 1;
}
