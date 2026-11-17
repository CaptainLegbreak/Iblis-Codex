struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
struct D2HashNode006BEF40Strc
{
    unsigned int nKey;
    D2HashNode006BEF40Strc* pNext;
    unsigned char f_8[8];
    int nValue;
};
struct D2HashTable006BEF40Strc
{
    unsigned char unk_00[0x0C];
    unsigned int nMask;
    unsigned char unk_10[4];
    D2HashNode006BEF40Strc** ppBuckets;
    unsigned char unk_18[4];
    D2CriticalSectionStrc* pLocks;
};

// 0x006BEF40
int __stdcall sub_006BEF40_GetValue(D2HashTable006BEF40Strc* pTable, unsigned int nKey)
{
    const unsigned int nBucket = pTable->nMask & nKey;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    for (D2HashNode006BEF40Strc* pNode = pTable->ppBuckets[nBucket]; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            const int nValue = pNode->nValue;
            LeaveCriticalSection(&pTable->pLocks[nBucket]);
            return nValue;
        }
    }
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    return -1;
}
