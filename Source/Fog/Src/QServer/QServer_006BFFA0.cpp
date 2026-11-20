struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct D2QServerNodeStrc
{
    int nKey;
    unsigned int dwTime;
    unsigned int nCount;
    D2QServerNodeStrc* pNext;
};

struct D2QueueServerStrc
{
    char unk0x000[0x84C];
    D2QServerNodeStrc* pHead;
    D2QServerNodeStrc* pTail;
    D2CriticalSectionStrc tLock;
    char unk0x86C[0x884 - 0x86C];
    int nLimit;
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

__declspec(noinline) static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer);
static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer); // 0x006BF260

// 0x006BF260
static int sub_006BF260_ExpireNodes(D2QueueServerStrc* pServer)
{
    const unsigned int dwTickCount = GetTickCount();
    EnterCriticalSection(&pServer->tLock);

    while (pServer->pHead)
    {
        D2QServerNodeStrc* pNode = pServer->pHead;
        if (dwTickCount - pNode->dwTime <= 15000)
        {
            break;
        }

        pServer->pHead = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x980, 0);
    }

    D2QServerNodeStrc* pPrevious = pServer->pHead;
    if (pPrevious)
    {
        for (D2QServerNodeStrc* pNode = pPrevious->pNext; pNode; )
        {
            if (dwTickCount - pNode->dwTime > 15000)
            {
                pPrevious->pNext = pNode->pNext;
                FOG_Free(pNode, ".\\Src\\QServer\\QServer.cpp", 0x993, 0);
                pNode = pPrevious->pNext;
            }
            else
            {
                pPrevious = pNode;
                pNode = pNode->pNext;
            }
        }
    }

    LeaveCriticalSection(&pServer->tLock);
    return 1;
}

// 0x006BFFA0
int __fastcall sub_006BFFA0_CheckKeyFlood(D2QueueServerStrc* pServer, const int* pKey)
{
    if (pServer->nLimit < 1)
    {
        return 1;
    }

    const int nKey = *pKey;
    const unsigned int dwTickCount = GetTickCount();
    const unsigned int nMaxCount = 2 * pServer->nLimit + 3;
    sub_006BF260_ExpireNodes(pServer);
    EnterCriticalSection(&pServer->tLock);

    for (D2QServerNodeStrc* pNode = pServer->pHead; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (dwTickCount - pNode->dwTime < 15000)
            {
                ++pNode->nCount;
                if (pNode->nCount > nMaxCount)
                {
                    LeaveCriticalSection(&pServer->tLock);
                    return 0;
                }
            }
            else
            {
                pNode->dwTime = dwTickCount;
                pNode->nCount = 1;
            }
        }
    }

    D2QServerNodeStrc* pNew = (D2QServerNodeStrc*)FOG_Alloc(sizeof(D2QServerNodeStrc), ".\\Src\\QServer\\QServer.cpp", 0x553, 0);
    pNew->nKey = nKey;
    pNew->dwTime = dwTickCount;
    pNew->nCount = 1;
    pNew->pNext = 0;
    if (!pServer->pHead)
    {
        pServer->pHead = pNew;
    }
    else
    {
        pServer->pTail->pNext = pNew;
    }

    pServer->pTail = pNew;
    LeaveCriticalSection(&pServer->tLock);
    return 1;
}
