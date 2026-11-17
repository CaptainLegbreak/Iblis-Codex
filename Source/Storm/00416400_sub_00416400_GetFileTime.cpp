struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormQuadStrc
{
    int n00;
    int n04;
    int n08;
    int n0C;
};

struct D2StormFileSubStrc
{
    int pad00;
    int nSizeLow;
    char pad08[0x08];
    __int64 nFileTime;
    int nValue;
    D2StormQuadStrc tQuad;
};

struct D2StormFileRecStrc
{
    char pad00[0x110];
    int nKind;
    int nValue;
    D2StormFileSubStrc* f_118;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, __int64* pCreation, __int64* pAccess, __int64* pWrite);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
char gszBasePath_00778F28[260];                                                                             // 0x00778F28

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x00416400
int __stdcall sub_00416400_GetFileTime(void* hFile, __int64* pFileTime)
{
    VALIDATEBEGIN;
    VALIDATE(pFileTime);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return GetFileTime((void*)pRec->nKind, 0, 0, pFileTime);
    }

    *pFileTime = pRec->f_118->nFileTime;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nValid ? 1 : 0;
}

// 0x004164B0
int __stdcall sub_004164B0_SetBasePath(const char* szPath)
{
    VALIDATEBEGIN;
    VALIDATE(szPath);
    VALIDATEEND;

    if (!*szPath)
    {
        gszBasePath_00778F28[0] = 0;
    }
    else
    {
        const int bBackslash = szPath[SStrLen(szPath) - 1] == '\\';
        if (SStrLen(szPath) + !bBackslash + 1 > 0x104)
        {
            sub_0041C340_SetLastError(0xA1);
            return 0;
        }

        EnterCriticalSection(&gBasePathLock_00779068);
        SStrCopy(gszBasePath_00778F28, szPath, 0x104);
        if (!bBackslash)
            sub_00413800(gszBasePath_00778F28, "\\", 0x104);
        LeaveCriticalSection(&gBasePathLock_00779068);
    }

    return nValid ? 1 : 0;
}
