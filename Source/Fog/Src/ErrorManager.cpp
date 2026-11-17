#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct AsyncDataEventSlot;
struct D2CriticalSectionStrc;
struct D2DbgHelpRequestStrc;
struct T004013C0;
struct D2ProcessEntryWStrc;
struct D2StartupInfoWStrc;
struct D2ProcessInformationStrc;
struct D2OverlappedStrc;
struct AsyncDataLoadFileCallback;
struct AsyncData;
struct _SYSTEMTIME;
struct _iobuf;
struct D2ThreadContextStrc;
struct D2PoolSystemStrc;
struct D2InspectorInfoStrc;
struct D2CrashSubmitInfoStrc;
// build: context sub_00406BA0_GetModuleDirectoryAndSave

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2DbgHelpRequestStrc
{
    void* hFile;
    void* pExceptionPointers;
    unsigned long dwThreadId;
    const char* szComment;
    bool bResult;
};

struct T004013C0
{
    int f_0;
    int nOsKind;
    float fOsVersion;
    unsigned int nTotalMemory;
};

typedef long (__stdcall* D2ExceptionFilterFn)(void* pExceptionPointers);

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode); // 0x006CC274
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall CreateFileW(const wchar_t* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC298
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) D2ExceptionFilterFn __stdcall SetUnhandledExceptionFilter(D2ExceptionFilterFn pfnFilter); // 0x006CC2B4
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryW(const wchar_t* szPath, void* pSecurityAttributes); // 0x006CC2C8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesW(const wchar_t* szFileName); // 0x006CC2B8
extern "C" wchar_t* __cdecl wcsrchr(const wchar_t* szString, wchar_t nChar); // 0x00685DF7
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
bool __cdecl sub_00401B00_LoadDbgHelp(); // 0x00401B00
long __stdcall sub_00403E90_UnhandledExceptionFilter(void* pExceptionPointers); // 0x00403E90
void __fastcall sub_0040F5A0_SetLogPrefix(const char* szName); // 0x0040F5A0
void __cdecl sub_0040F8A0_CloseLogFilesNow(); // 0x0040F8A0
extern bool gbMiniDumpEnabled_0098A6B1; // 0x0098A6B1
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0; // 0x0098A6F0
extern D2CriticalSectionStrc gtDbgHelpRequestLock_0098A6C4; // 0x0098A6C4
extern void* ghDbgHelp_0098A680; // 0x0098A680
extern void* gpDbgHelpRequest_0098A6E4; // 0x0098A6E4
extern void* gpfnCrashHandler_00992B10; // 0x00992B10
extern T004013C0 gtSystemInfo_0074D88C; // 0x0074D88C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

extern "C" int __stdcall Process32FirstW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1524
extern "C" int __stdcall Process32NextW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1530

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

extern "C" __declspec(dllimport) int __stdcall CreateProcessW(const wchar_t* wszApplicationName, wchar_t* wszCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const wchar_t* wszCurrentDirectory, D2StartupInfoWStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC2C4

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
void __cdecl sub_0040F960_CloseLogFiles(); // 0x0040F960
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile); // 0x00408000
int __fastcall sub_004088C0_ReportNestedError(const char* szFile, int nLine, const char* szMessage); // 0x004088C0
bool __cdecl sub_004013A0_IsDebuggerAttached(); // 0x004013A0

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

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall sub_004068E0(const char* szFileName, void** phFile); // 0x004068E0
void __fastcall sub_004068F0(void* hFile); // 0x004068F0
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh); // 0x00406930
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940
void* __fastcall sub_0040A080_PoolAlloc(void* pPool, int nSize, const char* szFile, int nLine); // 0x0040A080
AsyncDataEventSlot* __cdecl sub_0040A550_AsyncDataGetEventSlot(); // 0x0040A550
void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData); // 0x0040A4C0

struct _SYSTEMTIME
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(_SYSTEMTIME* lpSystemTime); // 0x006CC1D4
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...); // 0x006831DB
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args); // 0x00682F22
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

struct D2CrashSubmitInfoStrc
{
    const char* szName;
    int nUnk04;
    int nUnk08;
    unsigned int dwFlags;
    const char* apszLines[16];
    int nLines;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend); // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204
void __fastcall sub_00403070_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6, int nArg7); // 0x00403070
void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext); // 0x004032F0
void __fastcall sub_00403A20_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId); // 0x00403A20
void __fastcall sub_00407980_ReportPrint(void* pContext, const char* szText); // 0x00407980
bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo); // 0x00401790
extern long volatile gnReportBusy_007076BC; // 0x007076BC
extern D2InspectorInfoStrc gtInspectorInfo_0074D868; // 0x0074D868

bool __fastcall sub_00408660_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag);

char gszTextBuffer_0098A280[0x400]; // 0x0098A280

void* gpCrashContext_00992B14; // 0x00992B14

D2ExceptionFilterFn gpfnPreviousFilter_00992B18; // 0x00992B18

int gnSourcePrefixLength_0074F0D4; // 0x0074F0D4

// 0x004013C0
void __fastcall sub_004013C0_TerminateCurrentProcess(unsigned int nExitCode)
{
    TerminateProcess(GetCurrentProcess(), nExitCode);
}

int gbAsyncDataEnabled_0075AF94; // 0x0075AF94

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

// 0x00401690
unsigned long __cdecl sub_00401690_GetCurrentThreadId()
{
    return GetCurrentThreadId();
}

// 0x00401740
void __fastcall sub_00401740_SetText(const char* szText)
{
    char* pDest = gszTextBuffer_0098A280;
    const char* pSource = szText;
    size_t nLeft = 0x400;
    if (nLeft != 0 && --nLeft != 0)
    {
        do
        {
            if ((*pDest++ = *pSource++) == 0)
            {
                break;
            }
        }
        while (--nLeft != 0);
    }
    if (nLeft == 0)
    {
        *pDest = 0;
        while (*pSource++)
        {
        }
    }
    if ((size_t)(pSource - szText - 1) >= 0x400)
    {
        gszTextBuffer_0098A280[0] = 0;
    }
}

// build: context sub_00402820_WriteMiniDump
bool __fastcall sub_00402820_WriteMiniDump(const char* szPath, const char* szComment, void* pExceptionPointers, unsigned long dwThreadId)
{
    wchar_t wszPath[0x104];
    if (!gbMiniDumpEnabled_0098A6B1)
    {
        return false;
    }
    EnterCriticalSection(&gtSymbolLock_0098A6F0);
    if (!ghDbgHelp_0098A680 && !sub_00401B00_LoadDbgHelp())
    {
        LeaveCriticalSection(&gtSymbolLock_0098A6F0);
        return false;
    }
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
    if (MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104) <= 0)
    {
        return false;
    }
    void* hFile = CreateFileW(wszPath, 0x40000000, 0, 0, 2, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return false;
    }
    EnterCriticalSection(&gtDbgHelpRequestLock_0098A6C4);
    D2DbgHelpRequestStrc tRequest;
    tRequest.hFile = hFile;
    tRequest.dwThreadId = dwThreadId ? dwThreadId : GetCurrentThreadId();
    tRequest.szComment = szComment;
    tRequest.pExceptionPointers = pExceptionPointers;
    tRequest.bResult = false;
    gpDbgHelpRequest_0098A6E4 = &tRequest;
    SetEvent(ghDbgHelpWorkEvent_0098A6C0);
    WaitForSingleObject(ghDbgHelpDoneEvent_0098A6BC, (unsigned long)-1);
    gpDbgHelpRequest_0098A6E4 = 0;
    LeaveCriticalSection(&gtDbgHelpRequestLock_0098A6C4);
    CloseHandle(hFile);
    return tRequest.bResult;
}

// 0x00403F60
void __fastcall sub_00403F60_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused)
{
    gpfnCrashHandler_00992B10 = pfnHandler;
    gpCrashContext_00992B14 = pContext;
    if (!pfnHandler)
    {
        if (gpfnPreviousFilter_00992B18)
        {
            SetUnhandledExceptionFilter(gpfnPreviousFilter_00992B18);
            gpfnPreviousFilter_00992B18 = 0;
        }
    }
    else
    {
        gpfnPreviousFilter_00992B18 = SetUnhandledExceptionFilter(sub_00403E90_UnhandledExceptionFilter);
    }
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

// 0x00404560
bool __fastcall sub_00404560_UseWidePath(wchar_t* wszPath)
{
    if (CreateDirectoryW(wszPath, 0))
    {
        return true;
    }
    const unsigned long dwAttributes = GetFileAttributesW(wszPath);
    if (dwAttributes != (unsigned long)-1)
    {
        return (dwAttributes & 0x10) != 0;
    }
    wchar_t* pSeparator = wcsrchr(wszPath, L'\\');
    if (wcsrchr(wszPath, L'/') > pSeparator)
    {
        pSeparator = wcsrchr(wszPath, L'/');
    }
    if (!pSeparator)
    {
        return false;
    }
    *pSeparator = 0;
    if (!sub_00404560_UseWidePath(wszPath))
    {
        return false;
    }
    *pSeparator = L'\\';
    return CreateDirectoryW(wszPath, 0) != 0;
}

// 0x00406990
int __fastcall sub_00406990_DeleteFile(const char* szFileName)
{
    return DeleteFileA(szFileName);
}

// 0x004069A0
int __fastcall sub_004069A0_CloseFile(void* hFile)
{
    return CloseHandle(hFile);
}

// 0x00406B20
int __fastcall sub_00406B20_AppendBackslash(char* szPath, unsigned int nSize)
{
    if (szPath && nSize)
    {
        const unsigned int nLength = SStrLen(szPath);
        if (nLength > 0 && szPath[nLength - 1] == '\\')
        {
            return 1;
        }
        if (nLength + 1 != nSize)
        {
            szPath[nLength] = '\\';
            szPath[nLength + 1] = 0;
            return 1;
        }
    }
    return 0;
}

// 0x00406B60
int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, unsigned int nSize)
{
    const unsigned long nLength = GetModuleFileNameA(0, szPath, nSize);
    if (nLength && nLength != nSize)
    {
        char* pSlash = (char*)SStrChrR(szPath, '\\');
        if (pSlash)
        {
            pSlash[1] = 0;
        }
        return 1;
    }
    return 0;
}

static int sub_00406BA0_GetModuleDirectoryAndSave(char* szPath, unsigned int nSize)
{
    const unsigned long nLength = GetModuleFileNameA(0, szPath, nSize);
    if (nLength && nLength != nSize)
    {
        char* pSlash = (char*)SStrChrR(szPath, '\\');
        if (pSlash)
        {
            pSlash[1] = 0;
        }
        SRegSaveString("Diablo II", "InstallPath", 0, szPath);
        return 1;
    }
    return 0;
}

// 0x00406BA0
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize)
{
    if (!SRegLoadString("Diablo II", "InstallPath", 0, szPath, nSize))
    {
        szPath[0] = 0;
    }
    if (GetFileAttributesA(szPath) == (unsigned long)-1)
    {
        szPath[0] = 0;
    }
    if ((szPath[0] || sub_00406BA0_GetModuleDirectoryAndSave(szPath, nSize)) && nSize)
    {
        const unsigned int nLength = SStrLen(szPath);
        if (nLength > 0 && szPath[nLength - 1] == '\\')
        {
            return 1;
        }
        if (nLength + 1 != nSize)
        {
            szPath[nLength] = '\\';
            szPath[nLength + 1] = 0;
            return 1;
        }
    }
    return 0;
}

// 0x00407360
T004013C0* __cdecl sub_00407360_GetSystemInfo()
{
    return gtSystemInfo_0074D88C.f_0 ? &gtSystemInfo_0074D88C : 0;
}

// 0x00407440
void __fastcall sub_00407440_JulianToDate(long nJulian, int* pYear, int* pMonth, int* pDay)
{
    long ja;
    if (nJulian >= 588829)
    {
        const long jalpha = (long)(((double)(nJulian - 1867216) - 0.25) / 36524.25);
        ja = nJulian + 1 + jalpha - (long)(0.25 * jalpha);
    }
    else
    {
        ja = nJulian;
    }
    const long jb = ja + 1524;
    const long jc = (long)(6680.0 + ((double)(jb - 2439870) - 122.1) / 365.25);
    const long jd = (long)(365 * jc + (0.25 * jc));
    const long je = (long)((jb - jd) / 30.6001);
    *pDay = jb - jd - (long)(30.6001 * je);
    *pMonth = je - 1;
    if (*pMonth > 12)
    {
        *pMonth -= 12;
    }
    *pYear = jc - 4715;
    if (*pMonth > 2)
    {
        *pYear -= 1;
    }
    if (*pYear <= 0)
    {
        *pYear -= 1;
    }
}

// 0x00407960
void __fastcall FOG_SetLogPrefix(const char* szLogPrefix)
{
    sub_0040F5A0_SetLogPrefix(szLogPrefix);
}

// build: context sub_00407970_ForceCrash
void __cdecl sub_00407970_ForceCrash()
{
    *(int*)0 = 0;
}

// 0x00408000
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile)
{
    if (gnSourcePrefixLength_0074F0D4 == 0)
    {
        const int nLength = SStrLen(".\\Src\\ErrorManager.cpp");
        gnSourcePrefixLength_0074F0D4 = nLength - SStrLen("Fog\\Src\\ErrorManager.cpp");
        if (gnSourcePrefixLength_0074F0D4 < 0)
        {
            gnSourcePrefixLength_0074F0D4 = 0;
        }
    }
    if (SStrLen(szFile) > (unsigned int)gnSourcePrefixLength_0074F0D4)
    {
        return szFile + gnSourcePrefixLength_0074F0D4;
    }
    return szFile;
}

// 0x00408050
void __cdecl sub_00408050_Empty()
{
}

// 0x00408060
void __cdecl sub_00408060_Empty()
{
}

// 0x00408070
void __cdecl sub_00408070_Empty()
{
}

// 0x00408080
void __cdecl sub_00408080_Empty()
{
}

// 0x004080B0
static __declspec(noinline) void __stdcall sub_004080B0_DebugPrintV(unsigned int nFlags, const char* szFormat, va_list args)
{
    char szBuffer[0x1000];
    szBuffer[0] = 0;
    if (nFlags & 4)
    {
        _SYSTEMTIME tTime;
        GetLocalTime(&tTime);
        _snprintf(szBuffer, 0x1000, "%02d:%02d:%02d.%03d    ", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
    }
    const size_t nLength = strlen(szBuffer);
    _vsnprintf(&szBuffer[nLength], 0x1000 - nLength, szFormat, args);
    szBuffer[0xFFF] = 0;
    if (!(nFlags & 2))
    {
        OutputDebugStringA(szBuffer);
    }
    if (nFlags & 1)
    {
        sub_00410740_LogWritePrefixed00("LOG", gszPercentS_006FFC58, szBuffer);
    }
    if (nFlags & 0x18)
    {
        GetKeyState(0x14);
    }
}

// 0x004082A0
void __cdecl sub_004082A0_DebugPrintf(unsigned int nFlags, const char* szFormat, ...)
{
    sub_004080B0_DebugPrintV(nFlags, szFormat, (va_list)(&szFormat + 1));
}

// 0x004082C0
void __cdecl sub_004082C0_DebugPrintfLog(const char* szFormat, ...)
{
    sub_004080B0_DebugPrintV(1, szFormat, (va_list)(&szFormat + 1));
}

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool sub_00401100_Open(const char* szFileName);                         // 0x00401100
    bool sub_004011F0_Close();                                              // 0x004011F0
    bool sub_00401220_AddFile(const char* szPath, bool bFlag);              // 0x00401220
    int sub_00401380(const char* szFormat, ...);                                  // 0x00401380
    bool sub_00407A80_WriteInspectorHeader();                               // 0x00407A80

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[16][0x400];
};
}

int gdwGlobal_0074F0C8; // 0x0074F0C8

// 0x00408660
bool __fastcall sub_00408660_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag)
{
    crashy::Report tReport;
    const long nBusy = InterlockedIncrement(&gnReportBusy_007076BC);
    if (nBusy != 0)
    {
        gdwGlobal_0074F0C8 = 0;
        InterlockedDecrement(&gnReportBusy_007076BC);
        return false;
    }

    gdwGlobal_0074F0C8 = 1;
    if (!tReport.sub_00401100_Open("Crash.txt"))
    {
        gdwGlobal_0074F0C8 = 0;
        InterlockedDecrement(&gnReportBusy_007076BC);
        return false;
    }

    tReport.sub_00407A80_WriteInspectorHeader();
    tReport.sub_00401380("<Inspector.Summary:>\n%s\n<:Inspector.Summary>\n", szSummary);
    if (nLine > 0)
    {
        tReport.sub_00401380("<Inspector.LineNumber>%u\n", nLine);
    }
    tReport.sub_00401380("<Inspector.Assertion:>\n");
    const unsigned long dwThreadId = GetCurrentThreadId();
    sub_00403070_DumpThread(dwThreadId, 0, sub_00407980_ReportPrint, &tReport, nBusy, 1, 4);
    tReport.sub_00401380("<:Inspector.Assertion>\n");
    tReport.sub_00401380("Registers:\n");
    sub_004032F0_DumpRegisters(dwThreadId, sub_00407980_ReportPrint, &tReport);
    tReport.sub_00401380("Threads:\n");
    sub_00403A20_DumpOtherThreads(sub_00407980_ReportPrint, &tReport, dwThreadId);

    const char** ppszEnd = ppszFiles + nFiles;
    for (const char** ppszFile = ppszFiles; ppszFile != ppszEnd; ++ppszFile)
    {
        tReport.sub_00401220_AddFile(*ppszFile, true);
    }
    tReport.sub_004011F0_Close();

    D2CrashSubmitInfoStrc tInfo;
    memset(&tInfo, 0, sizeof(tInfo));
    tInfo.szName = gtInspectorInfo_0074D868.szUnused04;
    if (bFlag)
    {
        tInfo.dwFlags |= 1;
    }
    for (int i = 0; i < tReport.m_nLineCount; i++)
    {
        if (i < sizeof(tInfo.apszLines) / sizeof(tInfo.apszLines[0]))
        {
            tInfo.apszLines[i] = tReport.m_aszLines[i];
            tInfo.nLines++;
        }
    }

    const bool bResult = sub_00401790_SubmitReport(tReport.m_szText08, &tInfo);
    gdwGlobal_0074F0C8 = 0;
    InterlockedDecrement(&gnReportBusy_007076BC);
    return bResult;
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

// 0x0040F960
void __cdecl sub_0040F960_CloseLogFiles()
{
    sub_0040F8A0_CloseLogFilesNow();
}

#include "gen/data/Source/Fog/Src/ErrorManager.inc"
