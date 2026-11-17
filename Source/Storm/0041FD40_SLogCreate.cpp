typedef unsigned int size_t;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct T0041FA40
{
    void* hLog;
    T0041FA40* pNext;
    void* hFile;
    unsigned long nUsed;
    unsigned long nPended;
    int nIndent;
    int bTimestamp;
    char szBuffer[0x10000];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x006CC19C
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340

extern D2CriticalSectionStrc gaSLogLocks_00779238[4];                                                       // 0x00779238
extern T0041FA40* gapSLogBuckets_00779298[4];                                                              // 0x00779298
static unsigned long gnSLogLastHandle_00779230;                                                             // 0x00779230

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEKEEP(x) nValid = (x) ? nValid : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

static __declspec(noinline) T0041FA40* __stdcall sub_0041FA80_LockLog(unsigned long* pIndex, int bCreate, void* hLog);
static __declspec(noinline) void sub_0041FCE0_UnlockLog(unsigned long nIndex);

// 0x0041FA80
static T0041FA40* __stdcall sub_0041FA80_LockLog(unsigned long* pIndex, int bCreate, void* hLog)
{
    if (!hLog)
    {
        *pIndex = (unsigned long)-1;
        return 0;
    }
    unsigned long nIndex = (unsigned long)hLog & 3;
    EnterCriticalSection(&gaSLogLocks_00779238[nIndex]);
    *pIndex = nIndex;
    T0041FA40** ppNext = &gapSLogBuckets_00779298[nIndex];
    for (T0041FA40* p = *ppNext; p; p = *ppNext)
    {
        if (p->hLog == hLog)
            return p;
        ppNext = &p->pNext;
    }
    if (!bCreate)
    {
        LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    T0041FA40* pLog = (T0041FA40*)VirtualAlloc(0, sizeof(T0041FA40), 0x1000, 4);
    *ppNext = pLog;
    if (!pLog)
    {
        LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    pLog->hLog = hLog;
    pLog->pNext = 0;
    pLog->hFile = (void*)-1;
    pLog->nUsed = 0;
    pLog->nPended = 0;
    return pLog;
}

// 0x0041FCE0
static void sub_0041FCE0_UnlockLog(unsigned long nIndex)
{
    LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
}

// 0x0041FD40
int __stdcall SLogCreate(const char* szFileName, unsigned long dwFlags, void** phLog)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATEKEEP(*szFileName);
    if (!phLog)
        nValid = 0;
    if (phLog)
        *phLog = 0;
    VALIDATEEND;
    void* hFile = CreateFileA(szFileName, 0x40000000, 3, 0, 2, 0x80, 0);
    if (hFile == (void*)-1)
        return 0;
    void* hLog = (void*)++gnSLogLastHandle_00779230;
    *phLog = hLog;
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 1, hLog);
    if (!pLog)
    {
        *phLog = 0;
        return 0;
    }
    pLog->hFile = hFile;
    pLog->bTimestamp = 1;
    pLog->nIndent = 0;
    sub_0041FCE0_UnlockLog(nIndex);
    return 1;
}
