#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
struct D2QOverlappedStrc;
struct D2QWriteNodeStrc;
struct D2LargeIntegerStrc;
struct D2QAcceptStatsStrc;
struct D2QMsg006C23B0Strc;
struct D2QConn006C23B0Strc;
struct D2SockAddrInStrc;
struct D2QClientStrc;
struct T006BE350;
struct D2QueueServerStrc;
struct D2QServerReqStrc;

struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };

struct D2SockAddrInStrc
{
    unsigned int dwFamilyPort;
    unsigned int f_4;
    unsigned int aZero[2];
};

struct D2QAcceptStatsStrc
{
    D2LargeIntegerStrc aTimes[9];
    int f_48;
    int nAcceptErrors;
    int nRejected;
    int nPostErrors;
    int nAccepted;
    char unk_5C[0xB0 - 0x5C];
};

typedef void (__fastcall* D2QAcceptCallback)(T006BE350* pServer, unsigned int nId, const char* szFile, int nLine);

struct D2QClientStrc
{
    unsigned int nId;
    int f_4;
    int nReferences;
    int bClosing;
    void* hSocket;
    int nSlot;
    char unk_18[0x2C - 0x18];
    D2CriticalSectionStrc tLock;
    D2QOverlappedStrc tRead;
    D2QOverlappedStrc tWrite;
    D2QWriteNodeStrc* pWriteQueue;
    D2SockAddrInStrc tLocalAddr;
    D2SockAddrInStrc tPeerAddr;
    char unk_98[0x9C - 0x98];
    unsigned int nLastTick;
    char unk_A0[0xA8 - 0xA0];
    unsigned int nReadBytes;
    unsigned long nBytesRead;
    unsigned char pBuffer[0x5B4];
};

struct T006BE350
{
    char unk_000[0x8B4];
    D2CriticalSectionStrc tStatsLock;
    char unk_8CC[0x91C - 0x8CC];
    D2QAcceptStatsStrc aStats[3];
    char unk_B2C[0xB90 - 0xB2C];
    unsigned int hListenSockets[4];
    char unk_BA0[0xBC4 - 0xBA0];
    D2QAcceptCallback pfnOnAccept;
    char unk_BC8[0xC08 - 0xBC8];
    void* hPorts[4];
    int __thiscall sub_006BE980_Refresh(unsigned int nKey);                                                 // 0x006BE980
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress);                                        // 0x006BF660
};

extern "C" __declspec(dllimport) int __stdcall GetQueuedCompletionStatus(void* hPort, unsigned long* pBytes, unsigned long* pKey, D2QOverlappedStrc** ppOverlapped, unsigned long nTimeout);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nBytes, unsigned long* pWritten, D2QOverlappedStrc* pOverlapped);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nBytes, unsigned long* pRead, D2QOverlappedStrc* pOverlapped);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __cdecl sub_006BE2F0_Nop(const char* szText, const char* szFormat, ...); // 0x006BE2F0
void __cdecl sub_006BE300_Log(const char* szTag, const char* szFormat, ...); // 0x006BE300
D2QClientStrc* __fastcall sub_006BE540_Find(T006BE350* pServer, unsigned int nKey); // 0x006BE540
long __fastcall sub_006BE640_AddReference(T006BE350* pServer, D2QClientStrc* pClient); // 0x006BE640
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCounter);
extern "C" __declspec(dllimport) void* __stdcall CreateIoCompletionPort(unsigned int hFile, void* hPort, unsigned int nKey, unsigned int nThreads);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __stdcall ioctlsocket(unsigned int s, long nCommand, unsigned long* pArg); // 0x006B015C
extern "C" int __stdcall WSAGetLastError(void); // 0x006B0168
extern "C" char* __stdcall inet_ntoa(unsigned int nAddress); // 0x006B013E
int __fastcall sub_0040D880(unsigned int s); // 0x0040D880
void __cdecl sub_00410660_LogWritePrefixed(const char* szChannel, const char* szFormat, ...); // 0x00410660
int __fastcall sub_006BE9F0_CheckRecordThreshold(T006BE350* pServer, const unsigned int* pAddress); // 0x006BE9F0
int __fastcall sub_006C0800_BanByAddress(T006BE350* pServer, unsigned int* pAddress, const char* szFile, int nLine); // 0x006C0800
void __fastcall sub_006BFEA0_RecordAddress(T006BE350* pServer, const char* szFile, unsigned int nAddress, int nLine); // 0x006BFEA0
D2QClientStrc* __fastcall QSrvAddClient(T006BE350* pServer, unsigned int s, unsigned int nAddress); // 0x006BFB70
extern "C" const char gszHack_006FC4A8[]; // 0x006FC4A8
static __declspec(noinline) int sub_006C2280_PostRead(T006BE350* pServer, D2QClientStrc* pClient);
extern "C" void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B380
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2QMsg006C23B0Strc
{
    unsigned int nSize;
    D2QMsg006C23B0Strc* pNext;
    unsigned char pData[1];
};

struct D2QConn006C23B0Strc
{
    unsigned char unk_00[0x74];
    D2QMsg006C23B0Strc* pMsgHead;
};

static __declspec(noinline) void __stdcall sub_006C23B0_QueueMessage(D2QConn006C23B0Strc* pConn, unsigned int nSize, const void* pData);
static __declspec(noinline) int sub_006C2760_PostWrite(T006BE350* pServer, D2QClientStrc* pClient);

struct D2QueueServerStrc
{
    char unk_000[0x854];
    D2CriticalSectionStrc tLock;
    char unk_86C[0xC18 - 0x86C];
    int bInitialized;
    char unk_C1C[0xC3C - 0xC1C];
    int nSlots[1];
};

struct D2QServerReqStrc
{
    D2QueueServerStrc* pServer;
    int nSlot;
};
void __fastcall sub_00407F90_ThreadHookNop1(int n); // 0x00407F90
void __fastcall sub_006C2D70(D2QueueServerStrc* pServer, int nSlot, int nWait); // 0x006C2D70
extern const char gszQServerFile[]; // 0x006FC8A0

static unsigned int __stdcall sQSNTAccept(int nSlot, int* pAddrLen, T006BE350* pServer, D2SockAddrInStrc* pAddr);

// 0x006C2280
static int sub_006C2280_PostRead(T006BE350* pServer, D2QClientStrc* ptClient)
{
    D2CriticalSectionStrc* pLock = &ptClient->tLock;
    EnterCriticalSection(pLock);
    unsigned char* pBuffer = &ptClient->pBuffer[ptClient->nReadBytes];
    unsigned long nRoom = sizeof(ptClient->pBuffer) - ptClient->nReadBytes;
    if (!nRoom)
    {
        sub_006C0420_Disconnect(pServer, ptClient->nId, gszQServerNTFile_006FC8A0, 0x3ED);
        LeaveCriticalSection(pLock);
        return 0;
    }
    D2_ASSERT(!(ptClient->tRead.nFlags & 4), 0x3F5);
    ptClient->tRead.nFlags |= 4;
    D2_ASSERT(!ptClient->tRead.hEvent, 0x3F8);
    if (ptClient->hSocket == (void*)-1)
    {
        unsigned int nId = ptClient->nId;
        LeaveCriticalSection(pLock);
        sub_006C0420_Disconnect(pServer, nId, gszQServerNTFile_006FC8A0, 0x408);
        sub_006C0360_Release(pServer, ptClient);
        return 0;
    }
    sub_006BE640_AddReference(pServer, ptClient);
    int bOk = ReadFile(ptClient->hSocket, pBuffer, nRoom, &ptClient->nBytesRead, &ptClient->tRead);
    if (!bOk)
    {
        if (GetLastError() == 0x3E5)
        {
            bOk = 1;
        }
        else
        {
            sub_006C0360_Release(pServer, ptClient);
            sub_006C0420_Disconnect(pServer, ptClient->nId, gszQServerNTFile_006FC8A0, 0x430);
            return 0;
        }
    }
    LeaveCriticalSection(pLock);
    return bOk;
}

unsigned int __fastcall sub_Emit_006C2420(T006BE350* pServer, int nSlot)
{
    D2SockAddrInStrc tAddr;
    int nAddrLen;
    return sQSNTAccept(nSlot, &nAddrLen, pServer, &tAddr);
}

// 0x006C23B0
static void __stdcall sub_006C23B0_QueueMessage(D2QConn006C23B0Strc* pConn, unsigned int nSize, const void* pData)
{
    D2QMsg006C23B0Strc* pMsg = (D2QMsg006C23B0Strc*)FOG_Alloc(nSize + 8, ".\\Src\\QServer\\QServerNT.cpp", 0x440, 0);
    memcpy(pMsg->pData, pData, nSize);
    pMsg->nSize = nSize;
    pMsg->pNext = 0;
    if (!pConn->pMsgHead)
    {
        pConn->pMsgHead = pMsg;
        return;
    }
    D2QMsg006C23B0Strc* pLast = pConn->pMsgHead;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pMsg;
}

// 0x006C2420
static unsigned int __stdcall sQSNTAccept(int nSlot, int* pAddrLen, T006BE350* pServer, D2SockAddrInStrc* pAddr)
{
    memset(&pServer->aStats[nSlot].aTimes[0], 0, sizeof(pServer->aStats[nSlot].aTimes));
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[0]);
    *pAddrLen = 0x10;
    memset(pAddr, 0, sizeof(D2SockAddrInStrc));

    D2CriticalSectionStrc* pLock = &pServer->tStatsLock;
    EnterCriticalSection(pLock);
    ++pServer->aStats[nSlot].f_48;
    LeaveCriticalSection(pLock);

    pAddrLen = (int*)accept(pServer->hListenSockets[nSlot], pAddr, pAddrLen);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[1]);
    if ((unsigned int)pAddrLen == (unsigned int)-1)
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nAcceptErrors;
        LeaveCriticalSection(pLock);
        WSAGetLastError();
        return (unsigned int)-1;
    }

    int nReason = 0;
    if (pServer->sub_006BE980_Refresh(pAddr->f_4))
        nReason = 1;
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[2]);

    if (!nReason && sub_006BE9F0_CheckRecordThreshold(pServer, &pAddr->f_4))
    {
        sub_006C0800_BanByAddress(pServer, &pAddr->f_4, gszQServerNTFile_006FC8A0, 0x4A9);
        nReason = 2;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[3]);

    if (!nReason && !sub_006BFFA0_CheckReconnects(pServer, &pAddr->f_4) && !pServer->sub_006BF660_CheckAddress(pAddr->f_4))
    {
        sub_006BFEA0_RecordAddress(pServer, gszQServerNTFile_006FC8A0, pAddr->f_4, 0x4B2);
        nReason = 3;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[4]);

    if (nReason)
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nRejected;
        LeaveCriticalSection(pLock);
        const char* szReason = nReason == 1 ? "user on hack list" : (nReason == 2 ? "user logged on twice" : "user spamming with reconnects");
        sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[sQSNTAccept]               *** Deleted socket %d (%s) - %s ***", (unsigned int)pAddrLen, inet_ntoa(pAddr->f_4), szReason);
        sub_0040D880((unsigned int)pAddrLen);
        return (unsigned int)-1;
    }

    D2QClientStrc* ptClient = QSrvAddClient(pServer, (unsigned int)pAddrLen, pAddr->f_4);
    ptClient->nSlot = nSlot;
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[5]);

    unsigned long nNonBlocking = 1;
    ioctlsocket((unsigned int)pAddrLen, 0x8004667E, &nNonBlocking);
    nReason = 0x10;
    sub_006B018C_GetSockAddr((unsigned int)pAddrLen, &ptClient->tPeerAddr, &nReason);
    SMemZero(ptClient->tPeerAddr.aZero, 8);
    nReason = 0x10;
    sub_006B0144_GetSockAddr((unsigned int)pAddrLen, &ptClient->tLocalAddr, &nReason);
    SMemZero(ptClient->tLocalAddr.aZero, 8);
    D2_ASSERT((unsigned int)ptClient->hSocket == (unsigned int)pAddrLen, 0x4E4);
    CreateIoCompletionPort((unsigned int)pAddrLen, pServer->hPorts[nSlot], ptClient->nId, 0);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[6]);

    if (!sub_006C2280_PostRead(pServer, ptClient))
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nPostErrors;
        LeaveCriticalSection(pLock);
        return (unsigned int)-1;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[7]);

    if (pServer->pfnOnAccept)
        pServer->pfnOnAccept(pServer, ptClient->nId, gszQServerNTFile_006FC8A0, 0x4F9);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[8]);

    EnterCriticalSection(pLock);
    ++pServer->aStats[nSlot].nAccepted;
    LeaveCriticalSection(pLock);
    return (unsigned int)pAddrLen;
}

// calling-convention shim (not game code)
void __stdcall shim_11(D2QConn006C23B0Strc* pConn, unsigned int nSize, const void* pData)
{
    sub_006C23B0_QueueMessage(pConn, nSize, pData);
}

// 0x006C2760
static int sub_006C2760_PostWrite(T006BE350* pServer, D2QClientStrc* pClient)
{
    if (!pClient->pWriteQueue)
        return 1;

    sub_006BE640_AddReference(pServer, pClient);
    void* hSocket = pClient->hSocket;
    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
    D2_ASSERT(hSocket != (void*)-1, 0x518);

    unsigned long nWritten;
    int bOk = WriteFile(hSocket, pNode->pData, pNode->nSize, &nWritten, &pClient->tWrite);
    unsigned long nError = GetLastError();
    if (!bOk)
    {
        if (nError != 0x3E5)
        {
            sub_006C0360_Release(pServer, pClient);
            sub_006C0420_Disconnect(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x527);
            return 0;
        }
    }
    else if (nError != 0x3E5)
    {
        return 1;
    }
    pClient->tWrite.nFlags |= 4;
    return 1;
}

// 0x006C2D70
int __fastcall sub_006C2D70_ServiceSlot(T006BE350* pServer, int nSlot, unsigned long nTimeout)
{
    unsigned long nBytes;
    unsigned long nKey;
    D2QOverlappedStrc* pOverlapped;
    int nResult = 0;
    unsigned long nStart = GetTickCount();
    for (;; nTimeout = 0)
    {
        if (nStart - GetTickCount() > 100)
            break;
        D2QClientStrc* pClient = 0;
        int bOk = GetQueuedCompletionStatus(pServer->hPorts[nSlot], &nBytes, &nKey, &pOverlapped, nTimeout);
        int bRead = 0;
        int bWrite = 0;
        if (bOk || pOverlapped)
        {
            pClient = sub_006BE540_Find(pServer, nKey);
            if (!pClient)
                continue;

            D2QClientStrc* pOwner = 0;
            unsigned int nFlags = pOverlapped->nFlags;
            bRead = QS_IS_READ(nFlags);
            bWrite = QS_IS_WRITE(nFlags);
            if (bRead)
                pOwner = (D2QClientStrc*)((char*)pOverlapped - 0x44);
            else if (bWrite)
                pOwner = (D2QClientStrc*)((char*)pOverlapped - 0x5C);
            if (pClient != pOwner)
                sub_006BE2F0_Nop(&gszEmptyAssertText, "GQCS1b nClientId %d does not match overlapped ptClient 0x%08X %d", nKey, pClient, nFlags);
        }

        {
            unsigned long nError = GetLastError();
            if (bOk)
            {
                if (!nBytes)
                {
                    sub_006BE300_Log("QSRV", "[NTRdQ]          0 bytes on client %d refcount=%d %s", pClient->nId, pClient->nReferences,
                                     bRead ? "READ" : (bWrite ? "WRITE" : "*UNKNOWN*"));
                    if (pClient->hSocket != (void*)-1)
                        sub_006C0420_Disconnect(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x35D);
                    sub_006C0360_Release(pServer, pClient);
                }
                else if (bWrite)
                {
                    EnterCriticalSection(&pClient->tLock);
                    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
                    if (pNode)
                        pClient->pWriteQueue = pNode->pNext;
                    pClient->tWrite.nFlags &= ~4;
                    LeaveCriticalSection(&pClient->tLock);
                    if (pNode)
                        FOG_Free(pNode, gszQServerNTFile_006FC8A0, 0x578, 0);
                    EnterCriticalSection(&pClient->tLock);
                    if (!pClient->bClosing)
                        sub_006C2760_PostWrite(pServer, pClient);
                    LeaveCriticalSection(&pClient->tLock);
                    sub_006C0360_Release(pServer, pClient);
                }
                else if (bRead)
                {
                    EnterCriticalSection(&pClient->tLock);
                    pClient->tRead.nFlags &= ~4;
                    pClient->nReadBytes += nBytes;
                    pClient->nLastTick = sub_00410A80_GetTime();
                    LeaveCriticalSection(&pClient->tLock);
                    sub_006C08A0_Dispatch(pServer, pClient);
                    nResult = 1;
                    if (!pClient->bClosing)
                        sub_006C2280_PostRead(pServer, pClient);
                    sub_006C0360_Release(pServer, pClient);
                }
                else
                {
                    sub_006BE300_Log("QSRV", "WARNING: IO Completion on unknown overlapped structure.");
                    sub_006BE300_Log("QSRV", "  IOCP = 0x%08X/0x%08X, ptClient = 0x%08X/0x%08X.",
                                     (char*)pOverlapped - 0x44, pOverlapped, pClient, &pClient->tRead);
                }
            }
            else
            {
                if (pOverlapped && pClient)
                {
                    sub_006BE300_Log("QSRV", "[NTRdQ]          I/O err %d on client %d refcount=%d", nError, pClient->nId, pClient->nReferences);
                    sub_006C0420_Disconnect(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x3BD);
                    sub_006C0360_Release(pServer, pClient);
                }
                else
                {
                    if (nError == 0x102)
                        break;
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x3C8);
                    exit(-1);
                }
            }
        }
    }
    return nResult;
}

// 0x006C3030
int __stdcall sub_006C3030_ReleaseSlot(D2QServerReqStrc* pReq)
{
    D2QueueServerStrc* pServer = pReq->pServer;
    int nSlot = pReq->nSlot;
    FOG_Free(pReq, ".\\Src\\QServer\\QServerNT.cpp", 686, 0);
    if (!pServer->bInitialized)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 687);
        exit(-1);
    }
    while (!pServer->nSlots[nSlot])
    {
        sub_006C2D70(pServer, nSlot, 50);
    }
    EnterCriticalSection(&pServer->tLock);
    pServer->nSlots[nSlot] = 0;
    LeaveCriticalSection(&pServer->tLock);
    sub_00407F90_ThreadHookNop1(0);
    return 1;
}
