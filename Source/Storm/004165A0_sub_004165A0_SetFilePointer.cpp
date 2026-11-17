struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormFileSubStrc
{
    int pad00;
    int nSizeLow;
    unsigned int nSize;
};

struct D2StormFileRecStrc
{
    char pad00[0x110];
    int nKind;
    int nValue;
    D2StormFileSubStrc* f_118;
    int pad11C;
    unsigned int nPosition;
    char pad124[0x18];
    int n13C;
    int n140;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x004165A0
unsigned long __stdcall sub_004165A0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod)
{
    if (pnDistanceHigh && *pnDistanceHigh)
    {
        sub_0041C340_SetLastError(0x57);
        return (unsigned long)-1;
    }

    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return (unsigned long)-1;
    }

    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return SetFilePointer((void*)pRec->nKind, nDistance, 0, dwMoveMethod);
    }

    switch (dwMoveMethod)
    {
    case 0:
        pRec->nPosition = nDistance;
        break;

    case 1:
        if (nDistance < 0 && pRec->nPosition < (unsigned long)-nDistance)
        {
            pRec->nPosition = 0;
        }
        else
        {
            pRec->nPosition += nDistance;
        }
        break;

    case 2:
        if (nDistance < 0 && pRec->f_118->nSize < (unsigned long)-nDistance)
        {
            pRec->nPosition = 0;
        }
        else
        {
            pRec->nPosition = pRec->f_118->nSize + nDistance;
        }
        break;
    }

    pRec->n13C = 0;
    pRec->n140 = 0;
    const unsigned long nResult = pRec->nPosition;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}
