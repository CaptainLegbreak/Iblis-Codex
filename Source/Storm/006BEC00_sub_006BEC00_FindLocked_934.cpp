struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
struct D2HashNode006BEC00Strc
{
    unsigned int nKey;
    D2HashNode006BEC00Strc* pNext;
};
struct D2HashTable006BEC00Strc
{
    unsigned char unk_00[0x0C];
    unsigned int nMask;
    unsigned char unk_10[4];
    D2HashNode006BEC00Strc** ppBuckets;
    unsigned char unk_18[4];
    D2CriticalSectionStrc* pLocks;
};

// 0x006BEC00
D2HashNode006BEC00Strc* __fastcall sub_006BEC00_FindLocked(D2HashTable006BEC00Strc* pTable, unsigned int nKey, D2CriticalSectionStrc** ppLock)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2HashNode006BEC00Strc* pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            *ppLock = &pTable->pLocks[nBucket];
            return pNode;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return 0;
}
