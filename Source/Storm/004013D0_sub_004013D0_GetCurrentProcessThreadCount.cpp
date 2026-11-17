typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ProcessEntryWStrc
{
    unsigned long dwSize;
    unsigned long cntUsage;
    unsigned long th32ProcessID;
    unsigned long th32DefaultHeapID;
    unsigned long th32ModuleID;
    unsigned long cntThreads;
    unsigned long th32ParentProcessID;
    long pcPriClassBase;
    unsigned long dwFlags;
    wchar_t szExeFile[260];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();                             // 0x006CC1EC
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" void* __stdcall CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long dwProcessId);      // 0x006B1446
extern "C" int __stdcall Process32FirstW(void* hSnapshot, D2ProcessEntryWStrc* pEntry);                   // 0x006B1524
extern "C" int __stdcall Process32NextW(void* hSnapshot, D2ProcessEntryWStrc* pEntry);                    // 0x006B1530

struct D2StartupInfoWStrc
{
    unsigned long cb;
    wchar_t* lpReserved;
    wchar_t* lpDesktop;
    wchar_t* lpTitle;
    unsigned long dwX;
    unsigned long dwY;
    unsigned long dwXSize;
    unsigned long dwYSize;
    unsigned long dwXCountChars;
    unsigned long dwYCountChars;
    unsigned long dwFillAttribute;
    unsigned long dwFlags;
    unsigned short wShowWindow;
    unsigned short cbReserved2;
    unsigned char* lpReserved2;
    void* hStdInput;
    void* hStdOutput;
    void* hStdError;
};

struct D2ProcessInformationStrc
{
    void* hProcess;
    void* hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
};

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall CreateProcessW(const wchar_t* wszApplicationName, wchar_t* wszCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const wchar_t* wszCurrentDirectory, D2StartupInfoWStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC2C4

typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58
extern const char* gaszErrorTypeNames_00706654[];                                                           // 0x00706654
extern int gdwGlobal_0074F0C8;                                                                              // 0x0074F0C8
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...);              // 0x00410740
void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile);                                    // 0x00408000
int __fastcall sub_004088C0_ReportNestedError(const char* szFile, int nLine, const char* szMessage);         // 0x004088C0
bool __cdecl sub_004013A0_IsDebuggerAttached();                                                             // 0x004013A0
void __fastcall sub_00408660_ShowErrorReport(const char* szText, const char* szMessage, int nArg3, int nArg4, int nLine, int nArg6); // 0x00408660

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

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" void __cdecl free(void* pMemory);                                                                // 0x00683FC0

struct D2OverlappedStrc
{
    unsigned long Internal;
    unsigned long InternalHigh;
    unsigned long Offset;
    unsigned long OffsetHigh;
    void* hEvent;
};

struct AsyncDataLoadFileCallback
{
    unsigned long (__stdcall* callback)(void* pFileData, size_t nDataLength, AsyncDataLoadFileCallback* pCallbackData);
    unsigned long userData[4];
    void* pData;
    size_t nFileSize;
};

struct AsyncDataEventSlot;

struct AsyncData
{
    void* hFile;
    void* pMemPool;
    D2OverlappedStrc tOverlapped;
    AsyncDataLoadFileCallback pAsyncOpDesc;
    AsyncDataEventSlot* pEventSlot;
    void* pBuffer;
    unsigned int nFileSize;
    unsigned int nPriority;
    unsigned int nFlags;
    unsigned int nPreviousPriority;
    AsyncData* pNextPostponedPriorityChange;
};

struct AsyncDataEventSlot
{
    void* hEvent;
    unsigned long bSlotAvailable;
    AsyncData* pAsyncOp;
};

int gbAsyncDataEnabled_0075AF94;                                                                            // 0x0075AF94
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall sub_004068E0(const char* szFileName, void** phFile);                                          // 0x004068E0
void __fastcall sub_004068F0(void* hFile);                                                                // 0x004068F0
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh);                                       // 0x00406930
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod);  // 0x00406940
void* __fastcall sub_0040A080_PoolAlloc(void* pPool, int nSize, const char* szFile, int nLine);             // 0x0040A080
AsyncDataEventSlot* __cdecl sub_0040A550_AsyncDataGetEventSlot();                                           // 0x0040A550
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData);                                        // 0x0040A4C0

// 0x004013D0
int __cdecl sub_004013D0_GetCurrentProcessThreadCount()
{
    const unsigned long dwProcessId = GetCurrentProcessId();
    void* hSnapshot = CreateToolhelp32Snapshot(0x0F, 0);
    D2ProcessEntryWStrc tEntry = { 0 };
    tEntry.dwSize = sizeof(tEntry);
    int bFound = Process32FirstW(hSnapshot, &tEntry);
    while (bFound && tEntry.th32ProcessID != dwProcessId)
    {
        bFound = Process32NextW(hSnapshot, &tEntry);
    }
    CloseHandle(hSnapshot);
    if (bFound)
    {
        return tEntry.cntThreads;
    }
    return -1;
}

// 0x00404210
bool __fastcall sub_00404210_CreateProcessUtf8(const char* szApplicationName, const char* szCommandLine)
{
    wchar_t wszCmdLine[0x8000];
    wchar_t wszApp[0x400];
    if (!szCommandLine || MultiByteToWideChar(0xFDE9, 0, szCommandLine, -1, wszCmdLine, 0x8000))
    {
        if (!szApplicationName || MultiByteToWideChar(0xFDE9, 0, szApplicationName, -1, wszApp, 0x400))
        {
            D2ProcessInformationStrc tInfo;
            D2StartupInfoWStrc tStartup = { sizeof(tStartup) };
            memset(&tInfo, 0, sizeof(tInfo));
            if (CreateProcessW(szApplicationName ? wszApp : 0, szCommandLine ? wszCmdLine : 0, 0, 0, 0, 0, 0, 0, &tStartup, &tInfo))
            {
                CloseHandle(tInfo.hProcess);
                CloseHandle(tInfo.hThread);
                return true;
            }
        }
    }
    return false;
}

// 0x00408900
void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...)
{
    char szMessage[0x1000];
    char szText[0x1000];
    const int nErrorType = nType;
    if (nErrorType == 10)
    {
        szFile = ".\\Src\\ErrorManager.cpp";
    }
    if (sub_004088C0_ReportNestedError(szFile, nLine, szFormat))
    {
        return;
    }
    gdwGlobal_0074F0C8 = 1;
    if (!szFormat)
    {
        szFormat = "<no reason given>";
    }
    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStringFormat_006FFC58, "---finished error callback---\n");
    sub_0040F960_CloseLogFiles();
    int bFatal = nErrorType == 5 || nErrorType == 6 || nErrorType == 2;
    if (!sub_004013A0_IsDebuggerAttached())
    {
        va_list args;
        va_start(args, szFormat);
        SStrPrintf(szMessage, sizeof(szMessage), szFormat, args);
        SStrPrintf(szText, sizeof(szText), "[%s] (%s) failed at %s(%i)", gaszErrorTypeNames_00706654[nErrorType], szMessage, sub_00408000_StripSourcePath(szFile), nLine);
        sub_00408660_ShowErrorReport(szText, szMessage, 0, 0, nLine, 0);
    }
    if (!bFatal)
    {
        gdwGlobal_0074F0C8 = 0;
    }
}

// 0x00409810
void __fastcall sub_00409810_PoolFreeLarge(D2PoolSystemStrc* pSystem, int* pBlock, const char* szFile, int nLine)
{
    pBlock -= 1;
    const int nBucket = (int)pBlock % 1023;
    int* pPrev = 0;
    EnterCriticalSection(&pSystem->tLock);
    for (int* pEntry = pSystem->apLargeBlocks[nBucket]; pEntry; pEntry = (int*)*pEntry)
    {
        if (pEntry == pBlock)
        {
            if (!pPrev)
            {
                pSystem->apLargeBlocks[nBucket] = (int*)*pEntry;
            }
            else
            {
                *pPrev = *pEntry;
            }
            LeaveCriticalSection(&pSystem->tLock);
            free(pBlock);
            return;
        }
        pPrev = pEntry;
    }
    LeaveCriticalSection(&pSystem->tLock);
    free(pBlock);
}

// 0x0040A620
AsyncData* __fastcall FOG_AsyncDataLoadFileEx(void* pMemPool, const char* szFileName, int bAllowAsync, long nFileOffset, int nFileSize, void* pBuffer, AsyncDataLoadFileCallback* pAsyncOpDesc, int nPriority, const char* szFile, int nLine)
{
    AsyncData* pAsync = (AsyncData*)sub_0040B430(pMemPool, sizeof(AsyncData), ".\\Src\\AsyncData.cpp", 296, 0);
    memset(pAsync, 0, sizeof(AsyncData));
    pAsync->nFlags = 0x41737960;
    if (!sub_004068E0(szFileName, &pAsync->hFile))
    {
        FOG_FreeServerMemory(pMemPool, pAsync, ".\\Src\\AsyncData.cpp", 309, 0);
        return 0;
    }
    pAsync->pMemPool = pMemPool;
    pAsync->nPriority = nPriority;
    if (nFileOffset)
    {
        D2_ASSERT(sub_00406940_mpqSetFilePointer(pAsync->hFile, nFileOffset, 0, 0) != -1, 322);
    }
    if (nFileSize <= 0)
    {
        pAsync->nFileSize = sub_00406930(pAsync->hFile, 0);
    }
    else
    {
        pAsync->nFileSize = nFileSize;
    }
    if (pBuffer)
    {
        pAsync->nFlags &= ~2;
    }
    else
    {
        pBuffer = sub_0040A080_PoolAlloc(pMemPool, pAsync->nFileSize, szFile, nLine);
        pAsync->nFlags |= 2;
    }
    pAsync->pBuffer = pBuffer;
    if (pAsyncOpDesc)
    {
        pAsyncOpDesc = (AsyncDataLoadFileCallback*)memcpy(&pAsync->pAsyncOpDesc, pAsyncOpDesc, sizeof(*pAsyncOpDesc));
    }
    if (bAllowAsync && gbAsyncDataEnabled_0075AF94)
    {
        pAsync->pEventSlot = sub_0040A550_AsyncDataGetEventSlot();
        if (!pAsync->pEventSlot)
        {
            if (pAsync->hFile)
            {
                sub_004068F0(pAsync->hFile);
                pAsync->hFile = 0;
            }
            if (pAsync->nFlags & 2)
            {
                FOG_FreeServerMemory(pMemPool, pAsync->pBuffer, ".\\Src\\AsyncData.cpp", 388, 0);
            }
            FOG_FreeServerMemory(pMemPool, pAsync, ".\\Src\\AsyncData.cpp", 390, 0);
            return 0;
        }
        pAsync->pEventSlot->pAsyncOp = pAsync;
        pAsync->tOverlapped.hEvent = pAsync->pEventSlot->hEvent;
        pAsync->tOverlapped.Offset = nFileOffset;
        sub_00406900(pAsync->hFile, pAsync->pBuffer, pAsync->nFileSize, 0, &pAsync->tOverlapped, (int)pAsyncOpDesc, nPriority);
        return pAsync;
    }
    sub_00406900(pAsync->hFile, pAsync->pBuffer, pAsync->nFileSize, 0, 0, 0, nPriority);
    if (pAsyncOpDesc && pAsyncOpDesc->callback)
    {
        pAsyncOpDesc->callback(pAsync->pBuffer, pAsync->nFileSize, pAsyncOpDesc);
    }
    sub_0040A4C0_AsyncDataFinish(pAsync);
    return pAsync;
}

#include "gen/data/Source/Storm/004013D0_sub_004013D0_GetCurrentProcessThreadCount.inc"
