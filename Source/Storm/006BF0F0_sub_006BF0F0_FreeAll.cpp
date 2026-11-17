extern "C" int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0

struct D2CriticalSection006BF0F0Strc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSection006BF0F0Strc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSection006BF0F0Strc* pLock);

struct D2QEntry006BF0F0Strc
{
    unsigned char unk_00[0x0C];
    D2QEntry006BF0F0Strc* pNext;
};

struct D2QServer006BF0F0Strc
{
    unsigned char unk_000[0x890];
    int nCount;
    D2CriticalSection006BF0F0Strc pLock;
    D2QEntry006BF0F0Strc** ppBuckets;
    unsigned int nBuckets;
};

static __declspec(noinline) void sub_006BF0F0_FreeAll(D2QServer006BF0F0Strc* pServer);

// 0x006BF0F0
static void sub_006BF0F0_FreeAll(D2QServer006BF0F0Strc* pServer)
{
    EnterCriticalSection(&pServer->pLock);
    for (unsigned int i = 0; i < pServer->nBuckets; ++i)
    {
        D2QEntry006BF0F0Strc* pEntry = pServer->ppBuckets[i];
        while (pEntry)
        {
            D2QEntry006BF0F0Strc* pFree = pEntry;
            pEntry = pEntry->pNext;
            FOG_Free(pFree, ".\\Src\\QServer\\QServer.cpp", 0x8BE, 0);
        }
        pServer->ppBuckets[i] = 0;
    }
    pServer->nCount = 0;
    LeaveCriticalSection(&pServer->pLock);
}

// calling-convention shim (not game code)
void __stdcall shim_9(D2QServer006BF0F0Strc* pServer)
{
    sub_006BF0F0_FreeAll(pServer);
}
