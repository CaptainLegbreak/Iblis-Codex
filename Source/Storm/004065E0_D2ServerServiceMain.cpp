typedef unsigned int size_t;
typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

struct D2ServiceStatusStrc
{
    unsigned long dwServiceType;
    unsigned long dwCurrentState;
    unsigned long dwControlsAccepted;
    unsigned long dwWin32ExitCode;
    unsigned long dwServiceExitCode;
    unsigned long dwCheckPoint;
    unsigned long dwWaitHint;
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2PoolSystemStrc
{
    int bFreePoolAlloc;
    D2CriticalSectionStrc tLock;
    int nUnk0x1C;
    char unk0x20[0x780];
    int nLargeOverflow;
    char unk0x7A4[0x08];
    int* apLargeBlocks[1023];
    int nCount;
};

struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

struct D2MenuCallbackArgStrc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    unsigned int nArg;
};

typedef int (__stdcall* D2GetDiskFreeSpaceExFn)(const char* szDirectory, unsigned __int64* pnFreeToCaller, unsigned __int64* pnTotal, unsigned __int64* pnTotalFree);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void* __stdcall RegisterServiceCtrlHandlerA(const char* szServiceName, void (__stdcall* pfnHandler)(unsigned long dwCtrlCode)); // 0x006CC024
extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                   // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pBuffer);            // 0x006CC1F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode);   // 0x006CC2E0

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1
extern "C" void* __cdecl realloc(void* pMemory, size_t nSize);                                              // 0x00683BA5

void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode);                                        // 0x00406410
int __fastcall GameInit(unsigned long dwNumServicesArgs, const char* lpServiceArgVectors[]);                // 0x004064C0
int __cdecl sub_00406650_StartServiceDispatcher();                                                          // 0x00406650
int __cdecl sub_004061C0_DenyProcessAccess();                                                               // 0x004061C0
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                          // 0x00407050
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660
char* __fastcall sub_00411540_FormatNumber(char* szBuffer, unsigned int nBufferSize, __int64 nValue); // 0x00411540
int __stdcall sub_00415F70(int nFlags);                                                             // 0x00415F70
void __stdcall sub_00415F90_SetValue(int nValue);                                                           // 0x00415F90
int __stdcall sub_004164B0_SetBasePath(const char* szPath);                                                 // 0x004164B0
int __stdcall sub_004166B0_SetPair(int nValueA, int nValueB);                                               // 0x004166B0
int __stdcall sub_0041BFC0_SetOption(int nOption, void* pData, unsigned int nSize);                        // 0x0041BFC0
void __cdecl sub_0041C1A0_LockErrorState();                                                                 // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState();                                                               // 0x0041C1E0
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall SMemZero(void* pLocation, unsigned int nLength);                                             // 0x0041D300
int __stdcall sub_004269C0_RegisterHandler(unsigned long dwId, void* pContext);                             // 0x004269C0
void __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2);                 // 0x004307A0
int __stdcall sub_00431600(int nArg);                                                                       // 0x00431600

extern "C" const char gszPercentS_006FFC58[];                                                               // 0x006FFC58
extern "C" const char gszKernel32_006CD6E4[];                                                               // 0x006CD6E4
extern char gszServiceName_007065DC[];                                                                      // 0x007065DC
extern D2ServiceStatusStrc gD2ServerServiceStatus;                                                          // 0x007065FC
extern void* ghD2ServerServiceStatus;                                                                       // 0x0074C714
extern void* ghCurrentProcess_0074C718;                                                                     // 0x0074C718
int gnCmdShow_0074C71C;                                                                                     // 0x0074C71C
extern int gbD2ServerStopEvent_0074C720;                                                                    // 0x0074C720
extern int gnStormDirectFlags_0074C82C;                                                                     // 0x0074C82C
void* gpStormOwnerA_007790C0;                                                                               // 0x007790C0
extern void* gpStormOwnerB_007790C4;                                                                        // 0x007790C4
extern unsigned long gdwStormOwnerThread_007790C8;                                                          // 0x007790C8
extern int gnFlag_007798D0;                                                                                 // 0x007798D0

// 0x004065E0
void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** lpszArgv)
{
    gbD2ServerStopEvent_0074C720 = 1;
    ghD2ServerServiceStatus = RegisterServiceCtrlHandlerA(gszServiceName_007065DC, D2ServerServiceHandlerProc);
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    GameInit(dwArgc, (const char**)lpszArgv);
    gD2ServerServiceStatus.dwCurrentState = 1;
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    gbD2ServerStopEvent_0074C720 = 0;
}

// 0x004066E0
extern "C" int __stdcall WinMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nShowCmd)
{
    ghCurrentProcess_0074C718 = hInstance;
    gnCmdShow_0074C71C = nShowCmd;
    if (!sub_00406650_StartServiceDispatcher())
    {
        const char* argv[2];
        argv[0] = "d2server";
        argv[1] = lpCmdLine;
        sub_004061C0_DenyProcessAccess();
        GameInit(2, argv);
    }
    return 0;
}

// 0x00406870
void __fastcall sub_00406870_InitStorm(int nDirectFlags, int nValue)
{
    sub_004164B0_SetBasePath(".\\");
    sub_00415F70(nDirectFlags);
    sub_004166B0_SetPair(0, 0);
    sub_00415F90_SetValue(nValue);
    gnStormDirectFlags_0074C82C = nDirectFlags;
    int nChunkSize = 0x8000;
    sub_0041BFC0_SetOption(2, &nChunkSize, 4);
    int bEnable = 1;
    sub_0041BFC0_SetOption(1, &bEnable, 4);
    sub_0041BFC0_SetOption(3, &bEnable, 4);
}

// 0x00409020
void __cdecl sub_00409020_LogPoolError(const char* szFormat, ...)
{
    char szText[0x1000];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "--------------------------------------------------------");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: Out of memory!");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, gszPercentS_006FFC58, szText);
    D2MemoryStatusStrc tStatus;
    GlobalMemoryStatus(&tStatus);
    char szNumber[0x20];
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total physical:     %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwTotalPhys));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available physical: %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwAvailPhys));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total page:         %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwTotalPageFile));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available page:     %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwAvailPageFile));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total virtual:      %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwTotalVirtual));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available virtual:  %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwAvailVirtual));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
}

// 0x004098B0
void* __fastcall sub_004098B0_PoolReallocLarge(D2PoolSystemStrc* pSystem, int* pBlock, int nSize, const char* szFile, int nLine)
{
    pBlock -= 1;
    const int nBucket = (int)pBlock % 1023;
    int* pPrevious = 0;
    EnterCriticalSection(&pSystem->tLock);
    int* pCurrent = pSystem->apLargeBlocks[nBucket];
    while (pCurrent)
    {
        if (pCurrent == pBlock)
        {
            if (!pPrevious)
            {
                pSystem->apLargeBlocks[nBucket] = (int*)*pCurrent;
            }
            else
            {
                *pPrevious = *pCurrent;
            }
            int* pNewBlock = (int*)realloc(pBlock, nSize + 4);
            if (!pNewBlock)
            {
                sub_00409020_LogPoolError("Unable to allocate free block of %s", nSize);
                D2_ASSERT(pNewBlock, 1057);
            }
            const int nNewBucket = (int)pNewBlock % 1023;
            *pNewBlock = (int)pSystem->apLargeBlocks[nNewBucket];
            pSystem->apLargeBlocks[nNewBucket] = pNewBlock;
            LeaveCriticalSection(&pSystem->tLock);
            return pNewBlock + 1;
        }
        pPrevious = pCurrent;
        pCurrent = (int*)*pCurrent;
    }
    LeaveCriticalSection(&pSystem->tLock);
    return 0;
}

// 0x00410700
void __cdecl sub_00410700_LogWrite00(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 354);
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(&gszEmptyAssertText, 0, 0, szFormat, args);
}

// 0x00410740
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 371);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 0, 0, szFormat, args);
}

// 0x004107F0
unsigned __int64 __cdecl sub_004107F0_GetSaveDiskFreeSpace()
{
    char szPath[0x400];
    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    void* hKernel = LoadLibraryA(gszKernel32_006CD6E4);
    if (hKernel)
    {
        D2GetDiskFreeSpaceExFn pfnGetDiskFreeSpaceEx = (D2GetDiskFreeSpaceExFn)GetProcAddress(hKernel, "GetDiskFreeSpaceExA");
        if (pfnGetDiskFreeSpaceEx)
        {
            unsigned __int64 nTotalFree = 0;
            unsigned __int64 nTotal = 0;
            unsigned __int64 nFreeToCaller = 0;
            pfnGetDiskFreeSpaceEx(szPath, &nFreeToCaller, &nTotal, &nTotalFree);
            FreeLibrary(hKernel);
            return nFreeToCaller;
        }
    }
    for (unsigned int i = 0; i < sizeof(szPath); i++)
    {
        if (szPath[i] == '\\')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    unsigned long nSectorsPerCluster = 0;
    unsigned long nBytesPerSector = 0;
    unsigned long nFreeClusters = 0;
    unsigned long nTotalClusters = 0;
    GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
    return nFreeClusters * nBytesPerSector * nSectorsPerCluster;
}

// 0x0041D160
void __cdecl sub_0041D160_DisplayAppFatal(const char* szFormat, ...)
{
    const char* szFile = 0;
    int nLine = 0;
    sub_0041C1A0_LockErrorState();
    if (gdwStormOwnerThread_007790C8 == GetCurrentThreadId())
    {
        szFile = (const char*)gpStormOwnerA_007790C0;
        nLine = (int)gpStormOwnerB_007790C4;
        SMemZero(&gpStormOwnerA_007790C0, 12);
    }
    sub_0041C1E0_UnlockErrorState();
    char szText[0x400];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    SErrDisplayError(0x85100084, szFile, nLine, szText, 0, 1);
    ExitProcess(1);
}

// 0x00420320
int __stdcall sub_00420320_RegisterHandlers(void* pContext)
{
    sub_004269C0_RegisterHandler(0x534D5348, pContext);
    sub_004269C0_RegisterHandler(0x534D5349, pContext);
    sub_004269C0_RegisterHandler(0x534D534A, pContext);
    sub_004269C0_RegisterHandler(0x534D5347, pContext);
    return 1;
}

// 0x004308A0
int __stdcall sub_004308A0_ExpansionNotice6(D2MenuCallbackArgStrc* pArg)
{
    if (!sub_00408F20_HasExpansionMpq())
    {
        return 0;
    }
    sub_004307A0(pArg->nArg, 6, 0x2772, 0x57F7);
    return 1;
}

// 0x004308E0
int __stdcall sub_004308E0_ExpansionNotice5(D2MenuCallbackArgStrc* pArg)
{
    if (!sub_00408F20_HasExpansionMpq())
    {
        return 0;
    }
    sub_004307A0(pArg->nArg, 5, 0x2771, 0x57F6);
    return 1;
}

// 0x00431930
int __stdcall sub_00431930_RunAndSetFlag(int nArg)
{
    sub_00431600(nArg);
    gnFlag_007798D0 = 1;
    return 1;
}
