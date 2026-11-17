struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };

struct D2QOverlappedStrc
{
    unsigned long nInternal;
    unsigned long nInternalHigh;
    unsigned long nOffset;
    unsigned long nOffsetHigh;
    void* hEvent;
    unsigned int nFlags;
};

struct D2QWriteNodeStrc
{
    unsigned int nSize;
    D2QWriteNodeStrc* pNext;
    unsigned char pData[1];
};

struct D2SockAddrInStrc
{
    unsigned int dwFamilyPort;
    unsigned int f_4;
    unsigned int aZero[2];
};

struct D2LargeIntegerStrc
{
    unsigned int f_0;
    int f_4;
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

struct T006BE350;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                 // 0x0040B3C0
unsigned int __cdecl sub_00410A80_GetTime();                                                                // 0x00410A80
void __cdecl sub_006BE2F0_Nop(const char* szText, const char* szFormat, ...);                               // 0x006BE2F0
void __cdecl sub_006BE300_Log(const char* szTag, const char* szFormat, ...);                                // 0x006BE300
D2QClientStrc* __fastcall sub_006BE540_Find(T006BE350* pServer, unsigned int nKey);                     // 0x006BE540
long __fastcall sub_006BE640_AddReference(T006BE350* pServer, D2QClientStrc* pClient);                  // 0x006BE640
void __fastcall sub_006C0360_Release(T006BE350* pServer, D2QClientStrc* pClient);                       // 0x006C0360
void __fastcall sub_006C0420_Disconnect(T006BE350* pServer, unsigned int nId, const char* szFile, int nLine); // 0x006C0420
void __fastcall sub_006C08A0_Dispatch(T006BE350* pServer, D2QClientStrc* pClient);                      // 0x006C08A0
extern "C" const char gszQServerNTFile_006FC8A0[];                                                          // 0x006FC8A0

#define QS_IS_READ(f) (((f) & 1) == 1)
#define QS_IS_WRITE(f) (((f) & 3) == 2)

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCounter);
extern "C" __declspec(dllimport) void* __stdcall CreateIoCompletionPort(unsigned int hFile, void* hPort, unsigned int nKey, unsigned int nThreads);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" unsigned int __stdcall accept(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen);           // 0x006C9B6A
extern "C" int __stdcall ioctlsocket(unsigned int s, long nCommand, unsigned long* pArg);                   // 0x006B015C
extern "C" int __stdcall WSAGetLastError(void);                                                             // 0x006B0168
extern "C" char* __stdcall inet_ntoa(unsigned int nAddress);                                                // 0x006B013E
int __stdcall sub_006B018C_GetSockAddr(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen);             // 0x006B018C
int __stdcall sub_006B0144_GetSockAddr(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen);             // 0x006B0144
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
int __fastcall sub_0040D880_CloseSocket(unsigned int s);                                                    // 0x0040D880
void __cdecl sub_00410660_Log(const char* szChannel, const char* szFormat, ...);                            // 0x00410660
int __fastcall sub_006BE9F0_CheckRecordThreshold(T006BE350* pServer, const unsigned int* pAddress);     // 0x006BE9F0
int __fastcall sub_006C0800_BanByAddress(T006BE350* pServer, unsigned int* pAddress, const char* szFile, int nLine); // 0x006C0800
int __fastcall sub_006BFFA0_CheckReconnects(T006BE350* pServer, unsigned int* pAddress);               // 0x006BFFA0
void __fastcall sub_006BFEA0_RecordAddress(T006BE350* pServer, const char* szFile, unsigned int nAddress, int nLine); // 0x006BFEA0
D2QClientStrc* __fastcall sub_006BFB70_AddClient(T006BE350* pServer, unsigned int s, unsigned int nAddress); // 0x006BFB70
extern "C" const char gszHack_006FC4A8[];                                                                   // 0x006FC4A8

static __declspec(noinline) int sub_006C2280_PostRead(T006BE350* pServer, D2QClientStrc* pClient);

// 0x006C2280
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
        if (GetLastError() == 0x3E5)
        {
            bOk = 1;
        }
        else
        {
            sub_006C0360_Release(pServer, pClient);
            sub_006C0420_Disconnect(pServer, pClient->nId, gszQServerNTFile_006FC8A0, 0x430);
            return 0;
        }
    }
    LeaveCriticalSection(pLock);
    return bOk;
}

// 0x006C2420
static unsigned int __stdcall sub_006C2420_Accept(int nSlot, int* pAddrLen, T006BE350* pServer, D2SockAddrInStrc* pAddr)
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
        sub_00410660_Log(gszHack_006FC4A8, "[sQSNTAccept]               *** Deleted socket %d (%s) - %s ***", (unsigned int)pAddrLen, inet_ntoa(pAddr->f_4), szReason);
        sub_0040D880_CloseSocket((unsigned int)pAddrLen);
        return (unsigned int)-1;
    }

    D2QClientStrc* pClient = sub_006BFB70_AddClient(pServer, (unsigned int)pAddrLen, pAddr->f_4);
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

unsigned int __fastcall sub_Emit_006C2420(T006BE350* pServer, int nSlot)
{
    D2SockAddrInStrc tAddr;
    int nAddrLen;
    return sub_006C2420_Accept(nSlot, &nAddrLen, pServer, &tAddr);
}
