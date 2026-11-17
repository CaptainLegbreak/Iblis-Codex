struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
struct D2ServerNode006BE980Strc
{
    unsigned int nKey;
    unsigned char f_4[4];
    int nTimer8;
    D2ServerNode006BE980Strc* pNext;
};
struct D2Server006BE980Strc
{
    unsigned char unk_000[0x894];
    D2CriticalSectionStrc tLock;
    D2ServerNode006BE980Strc** ppBuckets;
    unsigned int f_8B0;

    int sub_006BE980_Refresh(unsigned int nKey);
};

// 0x006BE980
int D2Server006BE980Strc::sub_006BE980_Refresh(unsigned int nKey)
{
    EnterCriticalSection(&tLock);
    for (D2ServerNode006BE980Strc* pNode = ppBuckets[nKey % f_8B0]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (pNode->nTimer8)
            {
                pNode->nTimer8 = 120;
                LeaveCriticalSection(&tLock);
                return 1;
            }
            LeaveCriticalSection(&tLock);
            return 0;
        }
    }
    LeaveCriticalSection(&tLock);
    return 0;
}
