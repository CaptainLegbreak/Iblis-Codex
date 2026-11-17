struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormFileSubStrc;

struct D2StormFileRecStrc
{
    char pad00[0x08];
    char szName[0x108];
    int nKind;
    int nValue;
    D2StormFileSubStrc* f_118;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x00416230
int __stdcall sub_00416230_GetFileName(void* hFile, char* szBuffer, unsigned int nSize)
{
    if (szBuffer)
        *szBuffer = 0;
    if (!szBuffer)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    SStrCopy(szBuffer, pRec->szName, nSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}
