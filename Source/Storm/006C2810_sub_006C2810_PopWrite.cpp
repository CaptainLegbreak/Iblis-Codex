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
};

struct T006BE350;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                 // 0x0040B3C0
void __fastcall sub_006C0360_Release(T006BE350* pServer, D2QClientStrc* pClient);                       // 0x006C0360
extern "C" const char gszQServerNTFile_006FC8A0[];                                                          // 0x006FC8A0

static __declspec(noinline) int sub_006C2810_PopWrite(D2QClientStrc* pClient);

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
