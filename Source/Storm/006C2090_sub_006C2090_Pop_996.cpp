struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
struct D2QueueMessage006C2090Strc
{
    unsigned short nLength;
    unsigned char unk_02[2];
    D2QueueMessage006C2090Strc* pNext;
    unsigned char pData[1];
};
struct D2Queue006C2090Strc
{
    int f_0;
    D2CriticalSectionStrc tLock;
    D2QueueMessage006C2090Strc* pHead;
    D2QueueMessage006C2090Strc* pTail;
};

// 0x006C2090
int __fastcall sub_006C2090_Pop(D2Queue006C2090Strc* pQueue, void* pDest, unsigned short nMaxLength)
{
    int nLength;
    EnterCriticalSection(&pQueue->tLock);
    D2QueueMessage006C2090Strc* pMessage = pQueue->pHead;
    if (pMessage)
    {
        if (pMessage->nLength > nMaxLength)
        {
            pQueue->f_0 = 1;
            nLength = 0;
        }
        else
        {
            memcpy(pDest, pMessage->pData, pMessage->nLength);
            nLength = pMessage->nLength;
        }
        D2QueueMessage006C2090Strc* pNext = pMessage->pNext;
        FOG_Free(pQueue->pHead, ".\\Src\\D2QSQueue.cpp", 0x78, 0);
        pQueue->pHead = pNext;
        if (!pNext)
        {
            pQueue->pTail = 0;
        }
    }
    else
    {
        nLength = 0;
    }
    LeaveCriticalSection(&pQueue->tLock);
    return nLength;
}
