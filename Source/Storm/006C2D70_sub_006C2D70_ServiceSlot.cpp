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

struct D2QClientStrc
{
    unsigned int nId;
    int f_4;
    int nReferences;
    int bClosing;
    void* hSocket;
    char unk_14[0x2C - 0x14];
    D2CriticalSectionStrc tLock;
    D2QOverlappedStrc tRead;
    D2QOverlappedStrc tWrite;
    D2QWriteNodeStrc* pWriteQueue;
    char unk_78[0x9C - 0x78];
    unsigned int nLastTick;
    char unk_A0[0xA8 - 0xA0];
    unsigned int nReadBytes;
    unsigned long nBytesRead;
    unsigned char pBuffer[0x5B4];
};

struct T006BE350
{
    char unk_000[0xC08];
    void* hPorts[4];
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

static __declspec(noinline) int sub_006C2760_PostWrite(T006BE350* pServer, D2QClientStrc* pClient);
static __declspec(noinline) int sub_006C2280_PostRead(T006BE350* pServer, D2QClientStrc* pClient);

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
