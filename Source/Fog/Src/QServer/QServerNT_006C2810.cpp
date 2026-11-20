#include "Fog.h"
struct D2HashNode006BE540Strc;
struct D2HashTable006BE540Strc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CriticalSectionStrc;
struct D2QOverlappedStrc;
struct D2QWriteNodeStrc;
struct D2LargeIntegerStrc;
struct D2QAcceptStatsStrc;
struct D2QThreadArgStrc;
struct D2FdSetStrc;
struct D2TimevalStrc;
union D2QTickStrc;
struct D2HackListStrc;

struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };

struct D2SockAddrInStrc
{
    unsigned int dwFamilyPort;
    unsigned int f_4;
    char aZero[8];
};

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

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

#pragma pack(push, 4)
struct D2QAcceptStatsStrc
{
    __int64 tTotal;
    __int64 aStages[9];
    __int64 aTimes[9];
    int f_48;
    int nAcceptErrors;
    int nRejected;
    int nPostErrors;
    int nAccepted;
    char unk_AC[0xB0 - 0xAC];
};

#pragma pack(pop)
typedef void (__fastcall* D2QAcceptCallback)(T006BE350* pServer, unsigned int nId, const char* szFile, int nLine);

struct T006BE350
{
    char unk_000[0x854];
    D2CriticalSectionStrc tLock;
    char unk_86C[0x8B4 - 0x86C];
    D2CriticalSectionStrc tStatsLock;
    D2QAcceptStatsStrc aStats[3];
    char unk_ADC[0xB90 - 0xADC];
    unsigned int hListenSockets[4];
    char unk_BA0[0xBC4 - 0xBA0];
    D2QAcceptCallback pfnOnAccept;
    char unk_BC8[0xBD8 - 0xBC8];
    void* hAcceptThreads[4];
    char unk_BE8[0xBF8 - 0xBE8];
    int bStopAccept[4];
    void* hPorts[4];

    int __thiscall sub_006BE980_Refresh(unsigned int nKey);                                                 // 0x006BE980
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress);                                        // 0x006BF660
};
static __declspec(noinline) int sub_006C2810_PopWrite(D2QClientStrc* pClient);

extern "C" __declspec(dllimport) int __stdcall GetQueuedCompletionStatus(void* hPort, unsigned long* pBytes, unsigned long* pKey, D2QOverlappedStrc** ppOverlapped, unsigned long nTimeout);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nBytes, unsigned long* pWritten, D2QOverlappedStrc* pOverlapped);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nBytes, unsigned long* pRead, D2QOverlappedStrc* pOverlapped);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __cdecl sub_006BE2F0_Nop(const char* unused1, const char* unused2, int unused3); // 0x006BE2F0
void __cdecl sub_006BE300_Nop(const char* unused1, const char* unused2, int unused3); // 0x006BE300
D2HashNode006BE540Strc* __fastcall sub_006BE540_Find(D2HashTable006BE540Strc* pTable, unsigned int nKey); // 0x006BE540
long __fastcall sub_006BE640_AddReference(T006BE350* pServer, D2QClientStrc* pClient); // 0x006BE640
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pCounter);
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
extern "C" const char gszDeletedSocketFmt_006FC8C0[]; // 0x006FC8C0
extern "C" const char gszHackList_006FC938[]; // 0x006FC938
extern "C" const char gszLoggedTwice_006FC920[]; // 0x006FC920
extern "C" const char gszSpamming_006FC900[]; // 0x006FC900
static __declspec(noinline) int sub_006C2280_PostRead(T006BE350* pServer, D2QClientStrc* pClient);

struct D2QThreadArgStrc
{
    T006BE350* pServer;
    int nSlot;
};

struct D2FdSetStrc
{
    unsigned int nCount;
    unsigned int aSockets[64];
};

struct D2TimevalStrc
{
    int nSeconds;
    int nMicroseconds;
};

union D2QTickStrc
{
    struct
    {
        unsigned int nFraction;
        unsigned int nTick;
    };
    unsigned __int64 nQuad;
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds);
extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);
extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186
void __cdecl sub_006BF750_Nop(); // 0x006BF750
void __fastcall sub_00407F90_ThreadHookNop1(unsigned int nId); // 0x00407F90

struct D2HackListStrc
{
    void __thiscall sub_006BE700_ExpireEntries();                                                           // 0x006BE700
};

extern "C" int __cdecl abs(int n);

// 0x006C2810
static int sub_006C2810_PopWrite(D2QClientStrc* pClient)
{
    EnterCriticalSection(&pClient->tLock);
    D2QWriteNodeStrc* pNode = pClient->pWriteQueue;
    if (pNode)
        pClient->pWriteQueue = pNode->pNext;
    pClient->tWrite.nFlags &= ~4;
    LeaveCriticalSection(&pClient->tLock);
    if (pNode)
        FOG_Free(pNode, gszQServerNTFile_006FC8A0, 0x578, 0);
    return 1;
}

void __fastcall sub_Emit_006C2810(T006BE350* pServer, D2QClientStrc* pClient)
{
    sub_006C2810_PopWrite(pClient);
    EnterCriticalSection(&pClient->tLock);
    LeaveCriticalSection(&pClient->tLock);
    sub_006C0360_Release(pServer, pClient);
}

static int sub_006C2280_PostRead(T006BE350* pServer, D2QClientStrc* pClient)
{
    D2CriticalSectionStrc* pLock = &pClient->tLock;
    EnterCriticalSection(pLock);
    unsigned char* pBuffer = &pClient->pBuffer[pClient->nReadBytes];
    unsigned long nRoom = sizeof(pClient->pBuffer) - pClient->nReadBytes;
    if (!nRoom)
    {
        sub_006C0420_Disconnect(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x3ED);
        LeaveCriticalSection(pLock);
        return 0;
    }
    D2_ASSERT(!(pClient->tRead.nFlags & 4), 0x3F5);
    pClient->tRead.nFlags |= 4;
    D2_ASSERT(!pClient->tRead.hEvent, 0x3F8);
    if (pClient->hSocket == (void*)-1)
    {
        unsigned int nId = pClient->nId;
        LeaveCriticalSection(pLock);
        sub_006C0420_Disconnect(pServer, nId, gszQServerNTFile_006FC8A0, 0x408);
        sub_006C0360_Release(pServer, pClient);
        return 0;
    }
    sub_006BE640_AddReference(pServer, pClient);
    int bOk = ReadFile(pClient->hSocket, pBuffer, nRoom, &pClient->nBytesRead, &pClient->tRead);
    if (!bOk)
    {
        if (GetLastError() != 0x3E5)
        {
            sub_006C0360_Release(pServer, pClient);
            sub_006C0420_Disconnect(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x430);
            return 0;
        }
        bOk = 1;
    }
    LeaveCriticalSection(pLock);
    return bOk;
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
        const char* szReason = nReason == 1 ? gszHackList_006FC938 : (nReason == 2 ? gszLoggedTwice_006FC920 : gszSpamming_006FC900);
        sub_00410660_LogWritePrefixed(gszHack_006FC4A8, gszDeletedSocketFmt_006FC8C0, (unsigned int)pAddrLen, inet_ntoa(pAddr->f_4), szReason);
        sub_0040D880((unsigned int)pAddrLen);
        return (unsigned int)-1;
    }

    D2QClientStrc* pClient = QSrvAddClient(pServer, (unsigned int)pAddrLen, pAddr->f_4);
    pClient->nSlot = nSlot;
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[5]);

    unsigned long nNonBlocking = 1;
    ioctlsocket((unsigned int)pAddrLen, 0x8004667E, &nNonBlocking);
    nReason = 0x10;
    sub_006B018C_GetSockAddr((unsigned int)pAddrLen, &pClient->tPeerAddr, &nReason);
    SMemZero(pClient->tPeerAddr.aZero, 8);
    nReason = 0x10;
    sub_006B0144_GetSockAddr((unsigned int)pAddrLen, &pClient->tLocalAddr, &nReason);
    SMemZero(pClient->tLocalAddr.aZero, 8);
    D2_ASSERT((unsigned int)pClient->hSocket == (unsigned int)pAddrLen, 0x4E4);
    CreateIoCompletionPort((unsigned int)pAddrLen, pServer->hPorts[nSlot], pClient->nId, 0);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[6]);

    if (!sub_006C2280_PostRead(pServer, pClient))
    {
        EnterCriticalSection(pLock);
        ++pServer->aStats[nSlot].nPostErrors;
        LeaveCriticalSection(pLock);
        return (unsigned int)-1;
    }
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[7]);

    if (pServer->pfnOnAccept)
        pServer->pfnOnAccept(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x4F9);
    QueryPerformanceCounter(&pServer->aStats[nSlot].aTimes[8]);

    EnterCriticalSection(pLock);
    ++pServer->aStats[nSlot].nAccepted;
    LeaveCriticalSection(pLock);
    return (unsigned int)pAddrLen;
}

// 0x006C2860
unsigned long __stdcall sub_006C2860_AcceptThread(D2QThreadArgStrc* pArg)
{
    T006BE350* pServer = pArg->pServer;
    int nSlot = pArg->nSlot;
    FOG_Free(pArg, gszQServerNTFile_006FC8A0, 0x10D, 0);

    D2QTickStrc tNext;
    tNext.nTick = GetTickCount();
    while (!pServer->bStopAccept[nSlot])
    {
        unsigned int nNow = GetTickCount();
        if (abs(tNext.nTick - nNow) > 2000)
        {
            tNext.nTick = nNow;
        }

        if ((int)(tNext.nTick - nNow) > 0)
        {
            Sleep(10);
        }
        else
        {
            ((D2HackListStrc*)pServer)->sub_006BE700_ExpireEntries();
            if (!nSlot)
            {
                sub_006BF750_Nop();
            }

            D2FdSetStrc tRead;
            tRead.aSockets[0] = pServer->hListenSockets[nSlot];
            tRead.nCount = 1;
            D2TimevalStrc tTimeout;
            tTimeout.nSeconds = 0;
            tTimeout.nMicroseconds = 0;
            int nResult = select(0x40, &tRead, 0, 0, &tTimeout);
            if (nResult == -1)
            {
                sub_00407F90_ThreadHookNop1(0);
                return 1;
            }

            if (nResult)
            {
                __int64 tStart;
                QueryPerformanceCounter(&tStart);
                int nPriority = GetThreadPriority(pServer->hAcceptThreads[nSlot]);
                if (nPriority != 0x7FFFFFFF)
                {
                    SetThreadPriority(pServer->hAcceptThreads[nSlot], nPriority);
                }

                D2SockAddrInStrc tAddr;
                int nAddrLen;
                sQSNTAccept(nSlot, &nAddrLen, pServer, &tAddr);

                __int64 tEnd;
                QueryPerformanceCounter(&tEnd);
                EnterCriticalSection(&pServer->tStatsLock);
                pServer->aStats[nSlot].tTotal += tEnd - tStart;
                __int64* pTimes = pServer->aStats[nSlot].aTimes;
                __int64* pStages = pServer->aStats[nSlot].aStages;
                for (int i = 1; i < 9; ++i)
                {
                    if (!pTimes[i])
                    {
                        pTimes[i] = pTimes[i - 1];
                    }
                }
                for (int i = 8; i > 0; --i)
                {
                    pStages[i] += pTimes[i] - pTimes[i - 1];
                }
                LeaveCriticalSection(&pServer->tStatsLock);

                tNext.nQuad += 0x8B21642C8ui64;
                Sleep(0);
            }
            else
            {
                Sleep(20);
            }
        }
    }

    EnterCriticalSection(&pServer->tLock);
    pServer->bStopAccept[nSlot] = 0;
    LeaveCriticalSection(&pServer->tLock);
    sub_00407F90_ThreadHookNop1(0);
    return 1;
}
