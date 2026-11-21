#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#include "D2Win32Types.h"
#include "D2NetTypes.h"

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

struct _iobuf;

struct D2InspectorInfoStrc;

struct D2CrashSubmitInfoStrc;

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

struct AsyncData
{
    void* hFile;
    void* pMemPool;
    D2OverlappedStrc tOverlapped;
    AsyncDataLoadFileCallback pAsyncOpDesc;
    AsyncDataEventSlot* pEventSlot;
    void* ptBuffer;
    unsigned int nFileSize;
    unsigned int nPriority;
    unsigned int dwFlags;
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

int __fastcall sub_004068F0(void* pArg); // 0x004068F0

int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940

void* __fastcall sub_0040A080_PoolAlloc(void* pPool, int nSize, const char* szFile, int nLine); // 0x0040A080

AsyncDataEventSlot* __cdecl sub_0040A550_AsyncDataGetEventSlot(); // 0x0040A550

void __fastcall sub_0040A4C0_AsyncDataFinish(AsyncData* pAsyncData); // 0x0040A4C0

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* lpSystemTime); // 0x006CC1D4

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

void __fastcall sub_00403070_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7); // 0x00403070

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

typedef unsigned int size_t;

typedef char* va_list;

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

struct D2ThreadEntryStrc
{
    unsigned long dwSize;
    unsigned long cntUsage;
    unsigned long th32ThreadID;
    unsigned long th32OwnerProcessID;
    long tpBasePri;
    long tpDeltaPri;
    unsigned long dwFlags;
};

struct D2CmdArgStrc
{
    char szSection[0x1B];
    char szKey[0x1B];
    char szCommand[0x1B];
    unsigned char nType;
    int nIndex;
    int nDefault;
};

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

struct FSafeSock
{
    int bConnected;
    int bConnecting;
    unsigned int nSocket;
    D2CriticalSectionStrc tCriticalSection;
    void* hThread;
    unsigned long nThreadId;
    int bStopping;
    unsigned long nFogErrorCode;
    unsigned long nWSALastError;
    char szName[64];
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

// build: symbol _strrchr 0x00682990
extern "C" char* __cdecl strrchr(const char* szString, int nChar);

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1

extern "C" void* __cdecl malloc(size_t nSize);                                                              // 0x00683EFD

extern "C" _iobuf* __cdecl _wfopen(const wchar_t* szFileName, const wchar_t* szMode);                       // 0x00685EED

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();                             // 0x006CC1EC

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C

extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC

extern "C" __declspec(dllimport) void* __stdcall OpenProcess(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwProcessId); // 0x006CC1E8

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int nVirtualKey);                         // 0x006CC460

extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();                                        // 0x006CC24C

extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);                            // 0x006CC268

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pCount);         // 0x006CC25C

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pFrequency);   // 0x006CC254

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258

extern "C" void* __stdcall CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long dwProcessId);      // 0x006B1446

extern "C" int __stdcall Thread32First(void* hSnapshot, D2ThreadEntryStrc* pEntry);                        // 0x006B156C

extern "C" int __stdcall Thread32Next(void* hSnapshot, D2ThreadEntryStrc* pEntry);                         // 0x006B1572

extern "C" unsigned long __stdcall GetModuleFileNameExA(void* hProcess, void* hModule, char* szFileName, unsigned long nSize); // 0x006B13C2

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData);                // 0x006B0132

extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags);          // 0x006B017A

extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168

extern "C" int __stdcall closesocket(unsigned int nSocket);                                                 // 0x006B012C

extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186

extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet);                            // 0x006B0180

extern "C" int __stdcall getpeername(unsigned int nSocket, void* pAddress, int* pnLength);                 // 0x006B018C

extern "C" int __stdcall ioctlsocket(unsigned int nSocket, long nCommand, unsigned long* pArgument);       // 0x006B015C

void __fastcall sub_00403070_DumpThread(unsigned long dwThreadId, int nArg2, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6, int nArg7); // 0x00403070

void __cdecl sub_00409020_LogPoolError(const char* szFormat, ...);                                          // 0x00409020

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660

unsigned __int64 __cdecl sub_0040E850_ReadTimeStampCounter(); // 0x0040E850

extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0

extern D2CmdArgStrc gaCmdArguments[58];                                                                     // 0x00705040

extern D2ServiceStatusStrc gD2ServerServiceStatus;                                                          // 0x007065FC

void* ghD2ServerServiceStatus;                                                                              // 0x0074C714

extern int gbD2ServerStopEvent;                                                                             // 0x007065C0

extern unsigned char gabHuffmanCodeLength_007076C0[256];                                                    // 0x007076C0

unsigned char gabHuffmanCode_0075B6A0[256];                                                                 // 0x0075B6A0

const unsigned char* gapHuffmanDecode_0075AFA0[256];                                                        // 0x0075AFA0

extern unsigned int gadwHuffmanMask_007077C0[32];                                                           // 0x007077C0

// build: context sub_00406BA0_GetModuleDirectoryAndSave

struct D2DbgHelpRequestStrc
{
    void* hFile;
    void* pExceptionPointers;
    unsigned long dwThreadId;
    const char* szComment;
    bool bResult;
};

// 0x004013C0
void __fastcall sub_004013C0_TerminateCurrentProcess(unsigned int nExitCode)
{
    TerminateProcess(GetCurrentProcess(), nExitCode);
}

int sgfAsyncDataEnabled; // 0x0075AF94

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

// build: symbol ?strrchr@@YAPADPADH@Z 0x00401A30
char* __cdecl strrchr(char* szString, int nChar)
{
    return strrchr((const char*)szString, nChar);
}

// 0x00401A40
void* __stdcall sub_00401A40_LockSymbols(void* pArg)
{
    EnterCriticalSection(&gtSymbolLock_0098A6F0);
    return pArg;
}

// 0x00402C10
int __cdecl sub_00402C10_CompareUInt(const void* p1, const void* p2)
{
    const unsigned int a = *(const unsigned int*)p1;
    const unsigned int b = *(const unsigned int*)p2;
    if (a > b)
    {
        return 1;
    }
    if (a < b)
    {
        return -1;
    }
    return 0;
}

// 0x00403A20
void __fastcall sub_00403A20_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId)
{
    D2ThreadEntryStrc tEntry = {};
    tEntry.dwSize = sizeof(tEntry);
    void* hSnapshot = CreateToolhelp32Snapshot(4, 0);
    if (hSnapshot == (void*)-1)
    {
        return;
    }
    const unsigned long dwProcessId = GetCurrentProcessId();
    if (Thread32First(hSnapshot, &tEntry))
    {
        do
        {
            if (tEntry.th32OwnerProcessID == dwProcessId && tEntry.th32ThreadID != dwSkipThreadId)
            {
                sub_00403070_DumpThread(tEntry.th32ThreadID, 0, pfnPrint, pContext, 1, 1, 0);
                pfnPrint(pContext, gszNewline_006FFCB0);
            }
        }
        while (Thread32Next(hSnapshot, &tEntry));
    }
    CloseHandle(hSnapshot);
}

bool __fastcall sub_00402820_WriteMiniDump(const char* szPath, const char* szComment, void* pExceptionPointers, unsigned long dwThreadId); // 0x00402820

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

// 0x004043C0
_iobuf* __stdcall sub_004043C0_OpenUtf8FileForWrite(const char* szPath)
{
    wchar_t wszPath[0x104];
    wchar_t wszMode[0x20];
    if (!MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104))
    {
        return 0;
    }
    if (!MultiByteToWideChar(0xFDE9, 0, "w", -1, wszMode, 0x20))
    {
        return 0;
    }
    return _wfopen(wszPath, wszMode);
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

// 0x00405570
int __stdcall GetCmdIndex(const char* s)
{
    for (size_t i = 0; i < ARRAY_SIZE(gaCmdArguments); i++)
    {
        if (0 == strcmp(gaCmdArguments[i].szCommand, s))
        {
            return (int)i;
        }
    }
    return -1;
}

// 0x004055D0
int __fastcall sub_004055D0_IsCmdSeparator(char c)
{
    const char aSeparators[4] = { ' ', '\t', '\n', ':' };
    for (int i = 0; i < 4; i++)
    {
        if (aSeparators[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00406410
void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode)
{
    switch (dwCtrlCode)
    {
    case 1:
    case 5:
        gD2ServerServiceStatus.dwCurrentState = 3;
        SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
        gbD2ServerStopEvent = 1;
        return;
    case 4:
        SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
        return;
    default:
        break;
    }
}

// 0x00406960
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile)
{
    return CreateFileA(szFileName, dwDesiredAccess, dwShareMode, pSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
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

// 0x004069B0
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped)
{
    return ReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped);
}

// 0x004069D0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped)
{
    return WriteFile(hFile, pBuffer, nToWrite, pnWritten, pOverlapped);
}

// 0x004069F0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod)
{
    return SetFilePointer(hFile, nDistance, pnDistanceHigh, dwMoveMethod);
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

// 0x00407310
char* __cdecl sub_00407310_Sprintf(char* szDest, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    vsprintf(szDest, szFormat, args);
    return szDest;
}

// 0x00407330
char* __cdecl sub_00407330_SprintfN(char* szDest, int nSize, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    _vsnprintf(szDest, nSize, szFormat, args);
    szDest[nSize - 1] = 0;
    return szDest;
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

// 0x00407A20
bool __fastcall sub_00407A20_GetProcessImageName(unsigned long dwProcessId, char* szName, unsigned long nSize)
{
    bool bResult;
    void* hProcess = OpenProcess(0x410, 0, dwProcessId);
    if (hProcess && GetModuleFileNameExA(hProcess, 0, szName, nSize))
    {
        bResult = true;
    }
    else
    {
        bResult = false;
    }
    CloseHandle(hProcess);
    return bResult;
}

void __cdecl sub_00407970_ForceCrash(); // 0x00407970

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
        D2SystemTimeStrc tTime;
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

// 0x004081A0
void __cdecl sub_004081A0_DebugPrintf(const char* szFormat, ...)
{
    char szBuffer[0x1000];
    szBuffer[0] = 0;
    const size_t nLength = strlen(szBuffer);
    va_list args;
    va_start(args, szFormat);
    _vsnprintf(&szBuffer[nLength], sizeof(szBuffer) - nLength, szFormat, args);
    szBuffer[sizeof(szBuffer) - 1] = 0;
    OutputDebugStringA(szBuffer);
}

// 0x00408220
void __cdecl sub_00408220_DebugPrintfIfCapsLock(const char* szFormat, ...)
{
    if (GetAsyncKeyState(0x14) & 1)
    {
        char szBuffer[0x1000];
        szBuffer[0] = 0;
        const size_t nLength = strlen(szBuffer);
        va_list args;
        va_start(args, szFormat);
        _vsnprintf(&szBuffer[nLength], sizeof(szBuffer) - nLength, szFormat, args);
        szBuffer[sizeof(szBuffer) - 1] = 0;
        OutputDebugStringA(szBuffer);
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

// 0x00409770
void* __fastcall sub_00409770_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    int* pBlock = (int*)malloc(nSize + 4);
    if (!pBlock)
    {
        sub_00409020_LogPoolError("(3) Pool Blocks overflowed at %d", pSystem->nPoolBlocks);
        D2_ASSERT(pBlock, 904);
    }
    const int nBucket = (int)pBlock % 1023;
    EnterCriticalSection(&pSystem->tLock);
    *pBlock = (int)pSystem->apLargeBlocks[nBucket];
    pSystem->apLargeBlocks[nBucket] = pBlock;
    LeaveCriticalSection(&pSystem->tLock);
    return pBlock + 1;
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



// 0x0040B1B0
int __fastcall sub_0040B1B0(unsigned char* pOut, int nOutSize, const unsigned char* pIn, int nInSize)
{
    unsigned char* pStart = pOut;
    unsigned char nAcc = 0;
    int nFree = 8;
    while (nInSize)
    {
        const unsigned char c = *pIn;
        nInSize--;
        pIn++;
        int nBits = gabHuffmanCodeLength_007076C0[c];
        const unsigned int nCode = gabHuffmanCode_0075B6A0[c];
        while (nBits >= nFree)
        {
            nBits -= nFree;
            if (nOutSize-- == 0)
            {
                return 0;
            }
            *pOut++ = (unsigned char)(nCode >> nBits) | nAcc;
            nFree = 8;
            nAcc = 0;
        }
        if (nBits)
        {
            nFree -= nBits;
            nAcc |= (unsigned char)(nCode << nFree);
        }
    }
    if (nFree < 8)
    {
        if (nOutSize-- == 0)
        {
            return 0;
        }
        *pOut++ = nAcc;
    }
    return pOut - pStart;
}

// 0x0040B260
int __fastcall sub_0040B260(unsigned char* pOut, int nOutSize, const unsigned char* pIn, unsigned int nInSize)
{
    unsigned char* pStart = pOut;
    unsigned int nWindow = 0;
    int nEmpty = 32;
    for (;;)
    {
        while (nEmpty >= 8 && nInSize > 0)
        {
            nEmpty -= 8;
            nWindow |= *pIn << nEmpty;
            nInSize--;
            pIn++;
        }
        const unsigned char* pEntry = gapHuffmanDecode_0075AFA0[nWindow >> 24];
        const unsigned int nLookup = pEntry[0];
        const unsigned char c = pEntry[((nWindow >> (24 - nLookup)) & gadwHuffmanMask_007077C0[nLookup]) + 1];
        const int nLength = gabHuffmanCodeLength_007076C0[c];
        nEmpty += nLength;
        if (nEmpty > 32)
        {
            return pOut - pStart;
        }
        if (nOutSize-- == 0)
        {
            return 0;
        }
        *pOut++ = c;
        nWindow <<= nLength;
    }
}

// 0x0040D890
int __fastcall FOG_SOCKET_WSAStartup()
{
    D2WSADataStrc tData;
    return WSAStartup(0x101, &tData) == 0;
}

// 0x0040DD80
int __fastcall FOG_SOCKET_SendNoLock(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength)
{
    int nSent = send(pSafeSock->nSocket, pBuffer, nBufferLength, 0);
    const int nError = WSAGetLastError();
    if (nSent == -1 && nError == 0x274C)
    {
        nSent = 0;
        sub_00410610_WriteLogLine("ERROR: Disconnecting socket due to WSAETIMEDOUT\n");
        closesocket(pSafeSock->nSocket);
    }
    return nSent;
}

// 0x0040DDF0
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock)
{
    if (!pSafeSock || pSafeSock->bStopping || !pSafeSock->bConnected)
    {
        return 0;
    }
    D2FdSetStrc tRead;
    D2FdSetStrc tExcept;
    D2TimevalStrc tTimeout;
    tRead.fd_count = 1;
    tRead.fd_array[0] = pSafeSock->nSocket;
    tExcept.fd_count = 1;
    tExcept.fd_array[0] = pSafeSock->nSocket;
    tTimeout.tv_sec = 0;
    tTimeout.tv_usec = 100000;
    const int nResult = select(0x40, &tRead, 0, &tExcept, &tTimeout);
    if (pSafeSock->bStopping || !pSafeSock->bConnected || !nResult)
    {
        return 0;
    }
    if (nResult == -1)
    {
        pSafeSock->nWSALastError = WSAGetLastError();
        pSafeSock->nFogErrorCode = 4;
        return 0;
    }
    if (__WSAFDIsSet(pSafeSock->nSocket, &tExcept))
    {
        return 0;
    }
    if (__WSAFDIsSet(pSafeSock->nSocket, &tRead))
    {
        return 1;
    }
    D2_ASSERT(false, 558);
    return 0;
}

// 0x0040DEE0
int __fastcall FOG_SOCKET_GetPeerName(FSafeSock* pSafeSock, void* pAddress, int* pnLength)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    const int nResult = getpeername(pSafeSock->nSocket, pAddress, pnLength);
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    return nResult != -1;
}

// 0x0040DF20
int __fastcall sub_0040DF20_SOCKET_GetSockName(FSafeSock* pSafeSock, void* pAddress, int* pnLength)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    const int nResult = getsockname(pSafeSock->nSocket, (D2SockAddrInStrc*)pAddress, pnLength);
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    return nResult != -1;
}

// 0x0040E1A0
int __fastcall FOG_SOCKET_SetBlockingMode(FSafeSock* pSafeSock, int bNonBlocking)
{
    unsigned long nArgument = bNonBlocking;
    ioctlsocket(pSafeSock->nSocket, 0x8004667E, &nArgument);
    return 1;
}

// 0x0040E1D0
int __fastcall sub_0040E1D0_SOCKET_SetNonBlocking(FSafeSock* pSafeSock)
{
    unsigned long nArgument = 1;
    return ioctlsocket(pSafeSock->nSocket, 0x8004667E, &nArgument);
}

// 0x0040E200
int __fastcall sub_0040E200_SOCKET_SetBlocking(FSafeSock* pSafeSock)
{
    unsigned long nArgument = 0;
    return ioctlsocket(pSafeSock->nSocket, 0x8004667E, &nArgument);
}

// 0x0040E870
int __cdecl sub_0040E870_MeasureCpuMHz()
{
    int nPriority = GetThreadPriority(GetCurrentThread());
    if (nPriority != 0x7FFFFFFF)
    {
        SetThreadPriority(GetCurrentThread(), nPriority);
    }
    const unsigned long dwStart = GetTickCount();
    __int64 tCount1;
    QueryPerformanceCounter(&tCount1);
    const __int64 nTsc1 = sub_0040E850_ReadTimeStampCounter();
    while (GetTickCount() - dwStart < 10)
    {
        Sleep(0);
    }
    nPriority = GetThreadPriority(GetCurrentThread());
    if (nPriority != 0x7FFFFFFF)
    {
        SetThreadPriority(GetCurrentThread(), nPriority);
    }
    __int64 tCount2;
    QueryPerformanceCounter(&tCount2);
    const __int64 nTsc2 = sub_0040E850_ReadTimeStampCounter();
    GetTickCount();
    __int64 tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (int)((nTsc2 - nTsc1) * tFrequency / (tCount2 - tCount1) / 1000000);
}

#include "gen/data/Source/Fog/Src/ErrorManager.inc"
