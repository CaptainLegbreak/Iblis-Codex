struct D2CriticalSection006BF580Strc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSection006BF580Strc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSection006BF580Strc* pLock);

struct D2QEntry006BF580Strc
{
    unsigned char unk_000[0x5BC];
    D2QEntry006BF580Strc* pNext;
};

struct D2QServer006BF580Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSection006BF580Strc pLock;
    unsigned char unk_86C[0x04];
    D2QEntry006BF580Strc** ppBuckets;
    unsigned char unk_874[0x08];
    int nBuckets;
};

// 0x006BF580
int __stdcall sub_006BF580_CountEntries(D2QServer006BF580Strc* pServer)
{
    int nCount = 0;
    if (!pServer)
    {
        return 0;
    }
    EnterCriticalSection(&pServer->pLock);
    for (int i = 0; i < pServer->nBuckets; ++i)
    {
        for (D2QEntry006BF580Strc* pEntry = pServer->ppBuckets[i]; pEntry; pEntry = pEntry->pNext)
        {
            ++nCount;
        }
    }
    LeaveCriticalSection(&pServer->pLock);
    return nCount;
}
