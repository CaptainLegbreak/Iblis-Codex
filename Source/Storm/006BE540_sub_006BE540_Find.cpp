struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
struct D2HashNode006BE540Strc
{
    unsigned int nKey;
    D2HashNode006BE540Strc* pNext;
};
struct D2HashTable006BE540Strc
{
    unsigned char unk_00[0x0C];
    unsigned int nMask;
    unsigned char unk_10[4];
    D2HashNode006BE540Strc** ppBuckets;
    unsigned char unk_18[4];
    D2CriticalSectionStrc* pLocks;
};

// 0x006BE540
D2HashNode006BE540Strc* __fastcall sub_006BE540_Find(D2HashTable006BE540Strc* pTable, unsigned int nKey)
{
    if (!pTable)
    {
        return 0;
    }
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2HashNode006BE540Strc* pNode;
    for (pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            break;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return pNode;
}
