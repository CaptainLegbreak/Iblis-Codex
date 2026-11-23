#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#include "D2Win32Types.h"
#include "D2NetTypes.h"

int __stdcall SFileCloseFile(void* pArg);    // 0x004198D0

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

void __fastcall LOGMANAGER_SetLogPrefix(const char* szName); // 0x0040F5A0

void __cdecl LOGMANAGER_CloseLogFilesNow(); // 0x0040F8A0

extern bool gbMiniDumpEnabled; // 0x0098A6B1

extern D2CriticalSectionStrc gtSymbolLock; // 0x0098A6F0

extern D2CriticalSectionStrc gtDbgHelpRequestLock; // 0x0098A6C4

extern void* ghDbgHelp; // 0x0098A680

extern void* gpMiniDumpRequest; // 0x0098A6E4

extern void* gpfnCrashHandler; // 0x00992B10

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

void __cdecl LOGMANAGER_CloseLogFiles(); // 0x0040F960

const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile); // 0x00408000

int __fastcall ERRORMANAGER_ReportNestedError(const char* szFile, int nLine, const char* szMessage); // 0x004088C0

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

int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0

int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940


AsyncDataEventSlot* __cdecl ASYNCDATA_GetEventSlot(); // 0x0040A550

void __fastcall ASYNCDATA_Finish(AsyncData* pAsyncData); // 0x0040A4C0

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

void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7); // 0x00403070

void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext); // 0x004032F0

void __fastcall ERRORMANAGER_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId); // 0x00403A20

void __fastcall ERRORMANAGER_ReportPrint(void* pContext, const char* szText); // 0x00407980

bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo); // 0x00401790

extern long volatile gnCrashReportBusy; // 0x007076BC

D2InspectorInfoStrc gtInspectorInfo; // 0x0074D868

bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag); // 0x00408660

char gszTextBuffer[0x400]; // 0x0098A280

void* gpCrashContext; // 0x00992B14

D2ExceptionFilterFn gpfnPreviousFilter; // 0x00992B18

int gnSourcePrefixLength; // 0x0074F0D4

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

void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, int nArg2, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6, int nArg7); // 0x00403070

void __cdecl MAINMENUS_LogPoolError(const char* szFormat, ...);                                          // 0x00409020

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660

unsigned __int64 __cdecl AUTOMAP_ReadTimeStampCounter(); // 0x0040E850

extern "C" const char gszNewline[];                                                                // 0x006FFCB0

extern D2CmdArgStrc gaCmdArguments[58];                                                                     // 0x00705040

extern D2ServiceStatusStrc gD2ServerServiceStatus;                                                          // 0x007065FC

void* ghD2ServerServiceStatus;                                                                              // 0x0074C714

extern int gbD2ServerStopEvent;                                                                             // 0x007065C0

extern unsigned char gabHuffmanCodeLength[256];                                                    // 0x007076C0

unsigned char gabHuffmanCode[256];                                                                 // 0x0075B6A0

const unsigned char* gapHuffmanDecode[256];                                                        // 0x0075AFA0

extern unsigned int gadwHuffmanMask[32];                                                           // 0x007077C0

extern "C" int __stdcall WSACleanup();                                                                      // 0x006B0138

extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName);                                      // 0x006B0192

extern "C" int __stdcall gethostname(char* szName, int nNameLength);                                        // 0x006B0198

extern char gszResolvedHostIP[];                                                                   // 0x0075D040

extern "C" unsigned short __stdcall htons(unsigned short nValue);                                           // 0x006B0156

extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E

extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol);                            // 0x006B016E

struct D2CrashInputStrc;

#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); LOGMANAGER_CloseLogFiles(); exit(-1); }

void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __cdecl ERRORMANAGER_StartDbgHelpThread(); // 0x004016A0

void __fastcall ERRORMANAGER_SetReportText(const char* szText); // 0x00401740

void __fastcall ERRORMANAGER_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused); // 0x00403F60

int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60

void __cdecl ERRORMANAGER_LogSystemInfo(); // 0x004076B0

void __cdecl AUTOMAP_CaptureSystemInfo(); // 0x00407DE0

void __cdecl ERRORMANAGER_ExitHandler(); // 0x00407F20

int __fastcall ERRORMANAGER_CrashHandler(D2CrashInputStrc* pInput); // 0x004082E0

int __cdecl sub_0040D5B0_LoadImageHlp(); // 0x0040D5B0

void __cdecl EXCEPTIONS_InitLogSystem(); // 0x00410540

int __cdecl sub_00410960_IsPlatformNT(); // 0x00410960

void __cdecl SYSTEM_InitTimeBase(); // 0x004109D0

void __cdecl sub_00411210_InitTimer(); // 0x00411210

void __fastcall sub_0041C0E0_SetCallback(void* pfnHandler); // 0x0041C0E0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern D2CriticalSectionStrc gtLock_0074C830; // 0x0074C830

extern D2CriticalSectionStrc gtLock_0074D848; // 0x0074D848

extern int gbErrorMgrInit; // 0x0074F0D0

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern D2PoolDirectoryStrc gtPoolManager; // 0x0074F0E8

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220

extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C

extern "C" unsigned char _BitScanReverse(unsigned long* pIndex, unsigned long nMask);

extern "C" unsigned char _BitScanForward(unsigned long* pIndex, unsigned long nMask);

void* __fastcall ERRORMANAGER_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x00409770

extern const unsigned int gadwLowBitMasks[]; // 0x006CD490

int __fastcall sub_00409220_FindZeroBit(unsigned int nWord); // 0x00409220

static int ERRORMANAGER_GetPoolIndex(int nSize);

void* __fastcall sub_0040A080_PoolAlloc(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x0040A080

static D2MemPoolBlockStrc* __stdcall sub_004099D0_FindBlock(void* pMemory, D2PoolSystemStrc* pSystem);

static void sub_00409A60_MoveBlockToFront(D2MemPoolRecStrc* pPool, D2MemPoolBlockStrc* pBlock);

void __fastcall sub_00409AB0_PoolFree(D2PoolSystemStrc* pSystem, void** ppMemory, const char* szFile, int nLine);

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
void __fastcall ERRORMANAGER_TerminateCurrentProcess(unsigned int nExitCode)
{
    TerminateProcess(GetCurrentProcess(), nExitCode);
}

int sgfAsyncDataEnabled; // 0x0075AF94

// 0x004013D0
int __cdecl ERRORMANAGER_GetProcessThreadCount()
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
unsigned long __cdecl ERRORMANAGER_GetCurrentThreadId()
{
    return GetCurrentThreadId();
}

// 0x00401740
void __fastcall ERRORMANAGER_SetReportText(const char* szText)
{
    char* pDest = gszTextBuffer;
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
        gszTextBuffer[0] = 0;
    }
}

// build: symbol ?strrchr@@YAPADPADH@Z 0x00401A30
char* __cdecl strrchr(char* szString, int nChar)
{
    return strrchr((const char*)szString, nChar);
}

// 0x00401A40
void* __stdcall ERRORMANAGER_LockSymbols(void* pArg)
{
    EnterCriticalSection(&gtSymbolLock);
    return pArg;
}

// 0x00402C10
int __cdecl ERRORMANAGER_CompareUInt(const void* p1, const void* p2)
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
void __fastcall ERRORMANAGER_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId)
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
                ERRORMANAGER_DumpThread(tEntry.th32ThreadID, 0, pfnPrint, pContext, 1, 1, 0);
                pfnPrint(pContext, gszNewline);
            }
        }
        while (Thread32Next(hSnapshot, &tEntry));
    }
    CloseHandle(hSnapshot);
}

bool __fastcall sub_00402820_WriteMiniDump(const char* szPath, const char* szComment, void* pExceptionPointers, unsigned long dwThreadId); // 0x00402820

// 0x00403F60
void __fastcall ERRORMANAGER_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused)
{
    gpfnCrashHandler = pfnHandler;
    gpCrashContext = pContext;
    if (!pfnHandler)
    {
        if (gpfnPreviousFilter)
        {
            SetUnhandledExceptionFilter(gpfnPreviousFilter);
            gpfnPreviousFilter = 0;
        }
    }
    else
    {
        gpfnPreviousFilter = SetUnhandledExceptionFilter(sub_00403E90_UnhandledExceptionFilter);
    }
}

// 0x00404210
bool __fastcall ERRORMANAGER_CreateProcessUtf8(const char* szApplicationName, const char* szCommandLine)
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
_iobuf* __stdcall ERRORMANAGER_OpenFileForWriteUtf8(const char* szPath)
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
bool __fastcall ERRORMANAGER_CreateDirectoryWide(wchar_t* wszPath)
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
    if (!ERRORMANAGER_CreateDirectoryWide(wszPath))
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
int __fastcall ERRORMANAGER_IsCmdSeparator(char c)
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

// 0x00407360
T004013C0* __cdecl FOG_GetSystemInfo()
{
    return gtSystemInfo_0074D88C.f_0 ? &gtSystemInfo_0074D88C : 0;
}

// 0x00407440
void __fastcall ERRORMANAGER_JulianDayToDate(long nJulian, int* pYear, int* pMonth, int* pDay)
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
    LOGMANAGER_SetLogPrefix(szLogPrefix);
}

// 0x00407A20
bool __fastcall ERRORMANAGER_GetProcessImageName(unsigned long dwProcessId, char* szName, unsigned long nSize)
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

// 0x004080B0
static __declspec(noinline) void __stdcall ERRORMANAGER_DebugPrintV(unsigned int nFlags, const char* szFormat, va_list args)
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
// build: symbol ?MAINMENUS_LogWritePrefixed@* 0x00410740
        MAINMENUS_LogWritePrefixed("LOG", gszPercentS_006FFC58, szBuffer);
    }
    if (nFlags & 0x18)
    {
        GetKeyState(0x14);
    }
}

// 0x004081A0
void __cdecl ERRORMANAGER_DebugPrintf(const char* szFormat, ...)
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
void __cdecl ERRORMANAGER_DebugPrintfIfCapsLock(const char* szFormat, ...)
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
void __cdecl ERRORMANAGER_DebugPrintFlags(unsigned int nFlags, const char* szFormat, ...)
{
    ERRORMANAGER_DebugPrintV(nFlags, szFormat, (va_list)(&szFormat + 1));
}

// 0x004082C0
void __cdecl ERRORMANAGER_DebugPrintLog(const char* szFormat, ...)
{
    ERRORMANAGER_DebugPrintV(1, szFormat, (va_list)(&szFormat + 1));
}

// 0x00409770
void* __fastcall ERRORMANAGER_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    int* pBlock = (int*)malloc(nSize + 4);
    if (!pBlock)
    {
        MAINMENUS_LogPoolError("(3) Pool Blocks overflowed at %d", pSystem->nPoolBlocks);
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
void __fastcall ERRORMANAGER_PoolFreeLarge(D2PoolSystemStrc* pSystem, int* pBlock, const char* szFile, int nLine)
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

void __cdecl ERRORMANAGER_ForceCrash(); // 0x00407970

// 0x0040B1B0
int __fastcall FOG_CompressPacket(unsigned char* pOut, int nOutSize, const unsigned char* pIn, int nInSize)
{
    unsigned char* pStart = pOut;
    unsigned char nAcc = 0;
    int nFree = 8;
    while (nInSize)
    {
        const unsigned char c = *pIn;
        nInSize--;
        pIn++;
        int nBits = gabHuffmanCodeLength[c];
        const unsigned int nCode = gabHuffmanCode[c];
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
int __fastcall FOG_DecompressPacket(unsigned char* pOut, int nOutSize, const unsigned char* pIn, unsigned int nInSize)
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
        const unsigned char* pEntry = gapHuffmanDecode[nWindow >> 24];
        const unsigned int nLookup = pEntry[0];
        const unsigned char c = pEntry[((nWindow >> (24 - nLookup)) & gadwHuffmanMask[nLookup]) + 1];
        const int nLength = gabHuffmanCodeLength[c];
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

// 0x004068F0
int __fastcall FOG_FCloseFile(void* pArg)
{
    return SFileCloseFile(pArg);
}

// 0x00406960
void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile)
{
    return CreateFileA(szFileName, dwDesiredAccess, dwShareMode, pSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

// 0x00406990
int __fastcall FOG_DeleteFileA(const char* szFileName)
{
    return DeleteFileA(szFileName);
}

// 0x004069A0
int __fastcall FOG_CloseFile(void* hFile)
{
    return CloseHandle(hFile);
}

// 0x004069B0
int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped)
{
    return ReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped);
}

// 0x004069D0
int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped)
{
    return WriteFile(hFile, pBuffer, nToWrite, pnWritten, pOverlapped);
}

// 0x004069F0
unsigned long __fastcall FOG_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod)
{
    return SetFilePointer(hFile, nDistance, pnDistanceHigh, dwMoveMethod);
}

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool OpenReport(const char* szFileName);                         // 0x00401100
    bool sub_004011F0_Close();                                              // 0x004011F0
    bool sub_00401220_AddFile(const char* szPath, bool bFlag);              // 0x00401220
    int sub_00401380(const char* szFormat, ...);                                  // 0x00401380
    bool WriteInspectorHeader();                               // 0x00407A80

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[16][0x400];
};
}

int gbWritingCrashReport; // 0x0074F0C8

// 0x00408900
void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...)
{
    char szMessage[0x1000];
    char szText[0x1000];
    const int nErrorType = nType;
    if (nErrorType == 10)
    {
        szFile = ".\\Src\\ErrorManager.cpp";
    }
    if (ERRORMANAGER_ReportNestedError(szFile, nLine, szFormat))
    {
        return;
    }
    gbWritingCrashReport = 1;
    if (!szFormat)
    {
        szFormat = "<no reason given>";
    }
    MAINMENUS_LogWritePrefixed(&gszEmptyAssertText, gszStringFormat, "---finished error callback---\n");
    LOGMANAGER_CloseLogFiles();
    int bFatal = nErrorType == 5 || nErrorType == 6 || nErrorType == 2;
    if (!sub_004013A0_IsDebuggerAttached())
    {
        va_list args;
        va_start(args, szFormat);
        SStrPrintf(szMessage, sizeof(szMessage), szFormat, args);
// build: symbol ?gaszErrorTypeNames@* 0x00706654
        SStrPrintf(szText, sizeof(szText), "[%s] (%s) failed at %s(%i)", gaszErrorTypeNames[nErrorType], szMessage, ERRORMANAGER_StripSourcePath(szFile), nLine);
        ERRORMANAGER_ShowErrorReport(szText, szMessage, 0, 0, nLine, 0);
    }
    if (!bFatal)
    {
        gbWritingCrashReport = 0;
    }
}

// 0x00408000
const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile)
{
    if (gnSourcePrefixLength == 0)
    {
        const int nLength = SStrLen(".\\Src\\ErrorManager.cpp");
        gnSourcePrefixLength = nLength - SStrLen("Fog\\Src\\ErrorManager.cpp");
        if (gnSourcePrefixLength < 0)
        {
            gnSourcePrefixLength = 0;
        }
    }
    if (SStrLen(szFile) > (unsigned int)gnSourcePrefixLength)
    {
        return szFile + gnSourcePrefixLength;
    }
    return szFile;
}

// 0x00408660
bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag)
{
    crashy::Report tReport;
    const long nBusy = InterlockedIncrement(&gnCrashReportBusy);
    if (nBusy != 0)
    {
        gbWritingCrashReport = 0;
        InterlockedDecrement(&gnCrashReportBusy);
        return false;
    }

    gbWritingCrashReport = 1;
    if (!tReport.OpenReport("Crash.txt"))
    {
        gbWritingCrashReport = 0;
        InterlockedDecrement(&gnCrashReportBusy);
        return false;
    }

    tReport.WriteInspectorHeader();
    tReport.sub_00401380("<Inspector.Summary:>\n%s\n<:Inspector.Summary>\n", szSummary);
    if (nLine > 0)
    {
        tReport.sub_00401380("<Inspector.LineNumber>%u\n", nLine);
    }
    tReport.sub_00401380("<Inspector.Assertion:>\n");
    const unsigned long dwThreadId = GetCurrentThreadId();
    ERRORMANAGER_DumpThread(dwThreadId, 0, ERRORMANAGER_ReportPrint, &tReport, nBusy, 1, 4);
    tReport.sub_00401380("<:Inspector.Assertion>\n");
    tReport.sub_00401380("Registers:\n");
    sub_004032F0_DumpRegisters(dwThreadId, ERRORMANAGER_ReportPrint, &tReport);
    tReport.sub_00401380("Threads:\n");
    ERRORMANAGER_DumpOtherThreads(ERRORMANAGER_ReportPrint, &tReport, dwThreadId);

    const char** ppszEnd = ppszFiles + nFiles;
    for (const char** ppszFile = ppszFiles; ppszFile != ppszEnd; ++ppszFile)
    {
        tReport.sub_00401220_AddFile(*ppszFile, true);
    }
    tReport.sub_004011F0_Close();

    D2CrashSubmitInfoStrc tInfo;
    memset(&tInfo, 0, sizeof(tInfo));
    tInfo.szName = gtInspectorInfo.szUnused04;
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
    gbWritingCrashReport = 0;
    InterlockedDecrement(&gnCrashReportBusy);
    return bResult;
}

// 0x00406B20
int __fastcall ERRORMANAGER_AppendBackslash(char* szPath, unsigned int nSize)
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
int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize)
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
char* __cdecl ERRORMANAGER_Sprintf(char* szDest, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    vsprintf(szDest, szFormat, args);
    return szDest;
}

// 0x00407330
char* __cdecl ERRORMANAGER_SprintfN(char* szDest, int nSize, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    _vsnprintf(szDest, nSize, szFormat, args);
    szDest[nSize - 1] = 0;
    return szDest;
}

// 0x0040E870
int __cdecl ERRORMANAGER_MeasureCpuMHz()
{
    int nPriority = GetThreadPriority(GetCurrentThread());
    if (nPriority != 0x7FFFFFFF)
    {
        SetThreadPriority(GetCurrentThread(), nPriority);
    }
    const unsigned long dwStart = GetTickCount();
    __int64 tCount1;
    QueryPerformanceCounter(&tCount1);
    const __int64 nTsc1 = AUTOMAP_ReadTimeStampCounter();
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
    const __int64 nTsc2 = AUTOMAP_ReadTimeStampCounter();
    GetTickCount();
    __int64 tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (int)((nTsc2 - nTsc1) * tFrequency / (tCount2 - tCount1) / 1000000);
}

// 0x00408B20
void __fastcall ERRORMANAGER_ShowErrorBox(int nType, const char* szFile, int nLine, const char* szFormat, va_list args)
{
    char szCaption[0x100];
    char szMessage[0x1000];
    char szText[0x1000];
    char szBoxText[0x1000];
    if (szFile)
    {
        SStrPrintf(szMessage, 0x1000, "--------  FILE: %s    LINE: %d  --------\n\n", ERRORMANAGER_StripSourcePath(szFile), nLine);
// build: symbol ?gszStringFormat@* 0x006FFC58
        LOGMANAGER_LogWritePrefixedNoNewline(&gszEmptyAssertText, gszStringFormat, szMessage);
    }
    FOG_ASSERT(szFormat, 0x8DE);
    _vsnprintf(szMessage, 0x1000, szFormat, args);
    szMessage[0xFFF] = 0;
    if (szFile)
    {
// build: symbol ?gaszErrorTypeNames@* 0x00706654
        SStrPrintf(szText, 0x1000, "%s\nLocation : %s, line #%d\nExpression : %s", gaszErrorTypeNames[nType], ERRORMANAGER_StripSourcePath(szFile), nLine, szMessage);
    }
    else
    {
        strcpy(szText, szMessage);
    }
    SStrPrintf(szCaption, 0x100, "%s Error", "Diablo II");
    strcpy(szBoxText, szText);
    strcat(szText, "\n");
// build: symbol ?MAINMENUS_LogWritePrefixed@* 0x00410740
    MAINMENUS_LogWritePrefixed(&gszEmptyAssertText, gszStringFormat, szText);
    LOGMANAGER_CloseLogFiles();
    MessageBoxA(0, szBoxText, szCaption, 0x30);
}

char gszVersion[4096]; // 0x0074C848

char gszInspectorVersion[4096]; // 0x0074D8C8

int gbIsPlatformNT; // 0x0074F0CC

unsigned long gdwRegValue; // 0x0074F0E0

static int gbExpansionChecked; // 0x0074F0DC

static int gbExpansionMpq; // 0x0074F0D8

static int FOG_FileExists(const char* szFile)
{
    return GetFileAttributesA(szFile) != (unsigned long)-1;
}

// 0x00408F20
int __cdecl FOG_IsExpansion()
{
    if (!gbExpansionChecked)
    {
        char szPath[0x104];
        gbExpansionChecked = 1;
        FOG_GetInstallPath(szPath, 0x104);
        SStrPack(szPath, gszExpansionMpq, 0x104);
        int bExists = FOG_FileExists(szPath);
        if (!bExists)
        {
            SStrCopy(szPath, gszExpansionMpq, 0x104);
            bExists = FOG_FileExists(szPath);
        }
        if (bExists)
            gbExpansionMpq = 1;
    }
    return gbExpansionMpq;
}

// 0x00409000
int __fastcall ERRORMANAGER_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

static inline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : ERRORMANAGER_GetBitWidth(nValue - 1);
}

// 0x004091B0
static int ERRORMANAGER_GetPoolIndex(int nSize)
{
    if (nSize <= 0x10)
    {
        return 0;
    }
    return Log2Ceil(nSize) - 4;
}

int __fastcall sub_M289_Emit_004091B0(int nUnused, int nSize)
{
    return ERRORMANAGER_GetPoolIndex(nSize);
}

// 0x00409200
static int ERRORMANAGER_GetPoolBlockSize(int nIndex)
{
    if (!nIndex)
    {
        return 0x10;
    }
    return 1 << (nIndex + 4);
}

int __fastcall sub_M126_Emit_00409200(int a, int nIndex, int nUnused)
{
    return ERRORMANAGER_GetPoolBlockSize(nIndex) + a;
}

// 0x004099C0
static D2PoolSystemStrc* ERRORMANAGER_GetPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    return pSystem;
}

D2PoolSystemStrc* __fastcall sub_M126_Emit_004099C0(int a, D2PoolSystemStrc* pSystem, int nUnused)
{
    return ERRORMANAGER_GetPoolSystem(pSystem);
}

// 0x004095D0
void __cdecl sub_004095D0_Nop()
{
}

// 0x00409C70
void __cdecl sub_00409C70_Nop()
{
}

void __cdecl sub_0047B4D0_Nop()
{
}

void __cdecl sub_004BF9C0_Nop()
{
}

void __cdecl GLIDE_DebugFillBackBuffer()
{
}

// 0x00408A90
void __cdecl FOG_DisplayWarning(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(7, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408AC0
void __cdecl ERRORMANAGER_DisplayDeadlock(unsigned long dwThreadId, int nTicks)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(10, (const char*)dwThreadId, 2175, "Deadlocked in thread %X for %d ticks", dwThreadId, nTicks);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408AF0
void __cdecl FOG_DisplayError(int nCategory, const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(nCategory, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408A30
void __cdecl FOG_DisplayAssert(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(5, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00409490
static void __stdcall sub_00409490_RemoveBlockRecord(D2PoolSystemStrc* pSystem, D2MemPoolBlockStrc* pBlock)
{
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    void* pMemory = pBlock->pMemory;
    int nMid;
    while (nLow < nHigh)
    {
        nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory > pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else if (pMemory < pRecords[nMid].pMemory)
        {
            nHigh = nMid;
        }
        else
        {
            goto found;
        }
    }
    LeaveCriticalSection(pLock);
    D2_ASSERT(0, 0x2BF);
found:
    if (nMid < pSystem->nPoolBlocks - 1)
    {
        memmove(&pRecords[nMid], &pRecords[nMid + 1], (pSystem->nPoolBlocks - nMid - 1) * sizeof(D2PoolRecordStrc));
    }
    pSystem->nPoolBlocks--;
    D2MemPoolRecStrc* pPool = pBlock->pPool;
    pSystem->nCount = pSystem->nCount - pPool->nChunkSize - (((pPool->nBlocksPerChunk + 0x1F) >> 5) * 4 + sizeof(D2MemPoolBlockStrc));
    if (pSystem->nPoolBlocks + 0x40 < pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks -= 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
// build: symbol ?MAINMENUS_LogPoolError@* 0x00409020
            MAINMENUS_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x2B4);
        }
    }
    LeaveCriticalSection(pLock);
}

// 0x00409B80
void __cdecl sub_00409B80_FreeUnusedPoolBlocks(D2PoolSystemStrc* pArg)
{
    D2PoolSystemStrc* pSystem = pArg;
    if (!pArg)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!pSystem->nPools)
    {
        return;
    }
    EnterCriticalSection(&pSystem->tLock);
    for (int i = 0; i < pSystem->nPools; i++)
    {
        D2MemPoolRecStrc* pPool = &pSystem->aPools[i];
        EnterCriticalSection(&pPool->tLock);
        D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            D2MemPoolBlockStrc* pNext = pBlock->pNext;
            if (!pBlock->nUsed)
            {
                if (pBlock->pPrev)
                {
                    pBlock->pPrev->pNext = pNext;
                }
                if (pBlock->pNext)
                {
                    pBlock->pNext->pPrev = pBlock->pPrev;
                }
                if (pPool->pFirstBlock == pBlock)
                {
                    pPool->pFirstBlock = pBlock->pNext;
                }
                if (pPool->pLastBlock == pBlock)
                {
                    pPool->pLastBlock = pBlock->pPrev;
                }
                pPool->nBlocks--;
                sub_00409490_RemoveBlockRecord(pSystem, pBlock);
                VirtualFree(pBlock->pMemory, 0, 0x8000);
                free(pBlock);
            }
            pBlock = pNext;
        }
        LeaveCriticalSection(&pPool->tLock);
    }
    LeaveCriticalSection(&pSystem->tLock);
}

// 0x004099D0
static D2MemPoolBlockStrc* __stdcall sub_004099D0_FindBlock(void* pMemory, D2PoolSystemStrc* pSystem)
{
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    EnterCriticalSection(&pSystem->tLock);
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    while (nLow < nHigh)
    {
        const int nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory >= pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid;
        }
    }
    const int nIndex = nLow - 1;
    D2MemPoolBlockStrc* pBlock = (nIndex >= 0 && nIndex < pSystem->nPoolBlocks) ? pRecords[nIndex].pBlock : 0;
    LeaveCriticalSection(&pSystem->tLock);
    return pBlock;
}

// 0x00409A60
static void sub_00409A60_MoveBlockToFront(D2MemPoolRecStrc* pPool, D2MemPoolBlockStrc* pBlock)
{
    D2MemPoolBlockStrc* pPrev = pBlock->pPrev;
    if (pPrev && pPrev->nUsed >= pPool->nBlocksPerChunk)
    {
        pPrev->pNext = pBlock->pNext;
        if (pBlock->pNext)
        {
            pBlock->pNext->pPrev = pBlock->pPrev;
        }
        else
        {
            pPool->pLastBlock = pBlock->pPrev;
        }
        pBlock->pNext = pPool->pFirstBlock;
        pPool->pFirstBlock->pPrev = pBlock;
        pPool->pFirstBlock = pBlock;
        pBlock->pPrev = 0;
    }
}

// 0x00409AB0
void __fastcall sub_00409AB0_PoolFree(D2PoolSystemStrc* pSystem, void** ppMemory, const char* szFile, int nLine)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!*ppMemory)
    {
        return;
    }
    D2MemPoolBlockStrc* pBlock = sub_004099D0_FindBlock(*ppMemory, pSystem);
    if (pBlock && *ppMemory >= pBlock->pMemory)
    {
        D2MemPoolRecStrc* pPool = pBlock->pPool;
        const int nIndex = ((char*)*ppMemory - (char*)pBlock->pMemory) / pPool->nBlockSize;
        if (nIndex >= pPool->nBlocksPerChunk)
        {
            sub_00409810_FreeLarge(pSystem, *ppMemory, szFile, nLine);
            return;
        }
        EnterCriticalSection(&pPool->tLock);
        if (pBlock->pUsedBits[nIndex >> 5] & gdwBitMasks[nIndex & 31])
        {
            pBlock->pUsedBits[nIndex >> 5] &= gdwInvBitMasks[nIndex & 31];
            pBlock->nUsed--;
            sub_00409A60_MoveBlockToFront(pPool, pBlock);
        }
        LeaveCriticalSection(&pPool->tLock);
        return;
    }
    sub_00409810_FreeLarge(pSystem, *ppMemory, szFile, nLine);
}

void* __fastcall sub_0040A1F0_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine);

// 0x00409220
int __fastcall sub_00409220_FindZeroBit(unsigned int dwMask)
{
    __asm
    {
        mov ebx, dwMask
        not ebx
        bsf eax, ebx
        mov dwMask, eax
    }
    return dwMask;
}

// 0x00409240
static int sub_00409240_FindFreeSlot(int nCount, const unsigned int* pBits)
{
    int nWords = nCount >> 5;
    int nBase = 0;
    for (;;)
    {
        switch (nWords)
        {
        default:
            if (pBits[7] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[7]) + nBase + 0xE0;
        case 7:
            if (pBits[6] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[6]) + nBase + 0xC0;
        case 6:
            if (pBits[5] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[5]) + nBase + 0xA0;
        case 5:
            if (pBits[4] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[4]) + nBase + 0x80;
        case 4:
            if (pBits[3] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[3]) + nBase + 0x60;
        case 3:
            if (pBits[2] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[2]) + nBase + 0x40;
        case 2:
            if (pBits[1] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[1]) + nBase + 0x20;
        case 1:
            if (pBits[0] != 0xFFFFFFFF)
                return sub_00409220_FindZeroBit(pBits[0]) + nBase;
        case 0:
            break;
        }
        if (nWords <= 8)
        {
            break;
        }
        nWords -= 8;
        pBits += 8;
        nBase += 0x100;
    }
    const int nRest = nCount & 0x1F;
    if (nRest && pBits[nWords] != gadwLowBitMasks[nRest])
    {
        return sub_00409220_FindZeroBit(pBits[nWords]) + nBase + nWords * 32;
    }
    return -1;
}

// 0x00409370
static void __stdcall sub_00409370_InsertBlockRecord(D2MemPoolBlockStrc* pBlock, D2PoolSystemStrc* pSystem)
{
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    if (pSystem->nPoolBlocks >= pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks += 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
// build: symbol ?MAINMENUS_LogPoolError@* 0x00409020
            MAINMENUS_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x261);
        }
    }
    pSystem->nCount += pBlock->pPool->nChunkSize + ((pBlock->pPool->nBlocksPerChunk + 0x1F) >> 5) * 4 + sizeof(D2MemPoolBlockStrc);
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    void* pMemory = pBlock->pMemory;
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    while (nLow < nHigh)
    {
        const int nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory > pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid;
        }
    }
    if (nLow < pSystem->nPoolBlocks)
    {
        memmove(&pRecords[nLow + 1], &pRecords[nLow], (pSystem->nPoolBlocks - nLow) * sizeof(D2PoolRecordStrc));
    }
    pRecords[nLow].pBlock = pBlock;
    pRecords[nLow].pMemory = pBlock->pMemory;
    pSystem->nPoolBlocks++;
    LeaveCriticalSection(pLock);
}

// 0x004095E0
static D2MemPoolBlockStrc* __stdcall sub_004095E0_NewBlock(D2MemPoolRecStrc* pPool, D2PoolSystemStrc* pSystem)
{
    if (pSystem->nPoolBlocks >= pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks += 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
            MAINMENUS_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x2FF);
        }
    }
    const int nBitsSize = ((pPool->nBlocksPerChunk + 0x1F) >> 5) * 4;
    D2MemPoolBlockStrc* pBlock = (D2MemPoolBlockStrc*)malloc(nBitsSize + sizeof(D2MemPoolBlockStrc));
    void* pMemory = VirtualAlloc(0, pPool->nChunkSize, 0x1000, 4);
    if (pBlock && pMemory)
    {
        memset(&pBlock->nUsed, 0, sizeof(pBlock->nUsed) + sizeof(pBlock->pPrev) + sizeof(pBlock->pNext));
        pBlock->pUsedBits = (unsigned int*)(pBlock + 1);
        memset(pBlock->pUsedBits, 0, nBitsSize);
        pBlock->pMemory = pMemory;
        pBlock->pPool = pPool;
        pPool->nBlocks++;
        sub_00409370_InsertBlockRecord(pBlock, pSystem);
        return pBlock;
    }
    MAINMENUS_LogPoolError("(2) nPoolBlocks = %d/%d  nBlockSize = %d  nUsageTableSize = %d", pSystem->nPoolBlocks, pSystem->nMaxPoolBlocks, pPool->nChunkSize, nBitsSize);
    D2_ASSERT(0, 0x320);
    return 0;
}

// 0x00409700
static int __stdcall sub_00409700_GetFreeSlot(D2MemPoolBlockStrc** ppBlock, D2MemPoolRecStrc* pPool, D2PoolSystemStrc* pSystem)
{
    D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
    if (!pBlock)
    {
        pBlock = sub_004095E0_NewBlock(pPool, pSystem);
        if (pBlock)
        {
            pPool->pLastBlock = pBlock;
            pPool->pFirstBlock = pBlock;
        }
        *ppBlock = pBlock;
        return 0;
    }
    if (pBlock->nUsed < pPool->nBlocksPerChunk)
    {
        const int nSlot = sub_00409240_FindFreeSlot(pPool->nBlocksPerChunk, pBlock->pUsedBits);
        if (nSlot >= 0)
        {
            *ppBlock = pBlock;
            return nSlot;
        }
    }
    pBlock = sub_004095E0_NewBlock(pPool, pSystem);
    if (pBlock)
    {
        pBlock->pNext = pPool->pFirstBlock;
        pPool->pFirstBlock->pPrev = pBlock;
        pPool->pFirstBlock = pBlock;
    }
    *ppBlock = pBlock;
    return 0;
}

// 0x0040A080
void* __fastcall sub_0040A080_PoolAlloc(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!gtPoolManager.bInit)
    {
        sub_00409DD0_InitPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    }
    if (pSystem->bFreePoolAlloc)
    {
        return ERRORMANAGER_PoolAllocLarge(pSystem, nSize, szFile, nLine);
    }
    const int nIndex = ERRORMANAGER_GetPoolIndex(nSize);
    if (nIndex >= pSystem->nPools)
    {
        return ERRORMANAGER_PoolAllocLarge(pSystem, nSize, szFile, nLine);
    }
    D2MemPoolRecStrc* pPool = &pSystem->aPools[nIndex];
    EnterCriticalSection(&pPool->tLock);
    D2MemPoolBlockStrc* pBlock;
    const int nSlot = sub_00409700_GetFreeSlot(&pBlock, pPool, pSystem);
    D2_ASSERT(nSlot < pPool->nBlocksPerChunk, 0x4F3);
    if (!pBlock)
    {
        LeaveCriticalSection(&pPool->tLock);
        D2_ASSERT(0, 0x4F8);
    }
    pBlock->nUsed++;
    D2_ASSERT(!(pBlock->pUsedBits[nSlot >> 5] & gdwBitMasks[nSlot & 31]), 0x4FF);
    pBlock->pUsedBits[nSlot >> 5] |= gdwBitMasks[nSlot & 31];
    if (pBlock->nUsed >= pPool->nBlocksPerChunk && pBlock->pNext && pBlock->pNext->nUsed < pPool->nBlocksPerChunk)
    {
        if (!pBlock->pPrev)
        {
            pPool->pFirstBlock = pBlock->pNext;
        }
        else
        {
            pBlock->pPrev->pNext = pBlock->pNext;
        }
        if (pBlock->pNext)
        {
            pBlock->pNext->pPrev = pBlock->pPrev;
        }
        D2_ASSERT(pPool->pLastBlock, 0x50D);
        pPool->pLastBlock->pNext = pBlock;
        pBlock->pPrev = pPool->pLastBlock;
        pPool->pLastBlock = pBlock;
        pBlock->pNext = 0;
    }
    void* pResult = (char*)pBlock->pMemory + pPool->nBlockSize * nSlot;
    LeaveCriticalSection(&pPool->tLock);
    return pResult;
}

// 0x0040A1F0
void* __fastcall sub_0040A1F0_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine)
{
    D2PoolSystemStrc* pSystem = pPool;
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!pMemory)
    {
        void* pNew = sub_0040A080_PoolAlloc(pPool, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x62D);
        return pNew;
    }
    D2MemPoolBlockStrc* pBlock = sub_004099D0_FindBlock(pMemory, pSystem);
    if (!pBlock)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x635);
        return pNew;
    }
    if (pMemory < pBlock->pMemory)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x63C);
        return pNew;
    }
    D2MemPoolRecStrc* pBlockPool = pBlock->pPool;
    const int nIndex = ((char*)pMemory - (char*)pBlock->pMemory) / pBlockPool->nBlockSize;
    if (nIndex >= pBlockPool->nBlocksPerChunk)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x648);
        return pNew;
    }
    EnterCriticalSection(&pBlockPool->tLock);
    if (pBlock->pUsedBits[nIndex >> 5] & gdwBitMasks[nIndex & 31])
    {
        void* pResult;
        const int nElementSize = pBlockPool->nBlockSize;
        if (nElementSize >= nSize)
        {
            pResult = pMemory;
            LeaveCriticalSection(&pBlockPool->tLock);
        }
        else
        {
            LeaveCriticalSection(&pBlockPool->tLock);
            pResult = sub_0040A080_PoolAlloc(pPool, nSize, szFile, nLine);
            D2_ASSERT(pResult, 0x68B);
            memcpy(pResult, pMemory, nElementSize);
            sub_00409AB0_PoolFree(pPool, &pMemory, szFile, nLine);
        }
        return pResult;
    }
    LeaveCriticalSection(&pBlockPool->tLock);
    D2_ASSERT(0, 0x6A0);
    return 0;
}

// 0x00409FF0
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (pSystem->nPools)
    {
        EnterCriticalSection(&pSystem->tLock);
        pSystem->bFreePoolAlloc = bFreePoolAlloc;
        LeaveCriticalSection(&pSystem->tLock);
    }
}

// 0x0040A040
int __cdecl sub_0040A040_GetPoolSystemCount(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    EnterCriticalSection(&pSystem->tLock);
    int nCount = pSystem->nCount;
    LeaveCriticalSection(&pSystem->tLock);
    return nCount;
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224

// 0x00409DD0
int __cdecl sub_00409DD0_InitPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused)
{
    if (!ppPoolSystem)
    {
        memset(&gtPoolManager, 0, sizeof(gtPoolManager));
        InitializeCriticalSection(&gtPoolManager.tLock);
        gtPoolManager.bInit = 1;
    }
    EnterCriticalSection(&gtPoolManager.tLock);
    D2PoolSystemStrc* pSystem;
    if (gtPoolManager.nFreeCount)
    {
        --gtPoolManager.nFreeCount;
        pSystem = &gtPoolManager.aSystems[gtPoolManager.anFreeIndex[gtPoolManager.nFreeCount]];
    }
    else
    {
        if (gtPoolManager.nUsed >= 8)
        {
            LeaveCriticalSection(&gtPoolManager.tLock);
            MAINMENUS_LogPoolError("Insufficient pre-allocated pool systems");
            RaiseException(0xE0000001, 0, 0, 0);
            return 0;
        }
        pSystem = &gtPoolManager.aSystems[gtPoolManager.nUsed];
        ++gtPoolManager.nUsed;
    }
    LeaveCriticalSection(&gtPoolManager.tLock);

    memset(pSystem, 0, sizeof(*pSystem));
    if (ppPoolSystem)
    {
        *ppPoolSystem = pSystem;
    }
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    InitializeCriticalSection(pLock);
    EnterCriticalSection(pLock);
    if (szName)
    {
        SStrCopy(pSystem->szName, szName, sizeof(pSystem->szName));
        pSystem->szName[sizeof(pSystem->szName) - 1] = 0;
    }

    int nValue = ERRORMANAGER_GetPoolIndex(nSize);
    const int nPools = nValue + 1;
    D2_ASSERT(nPools <= 40, 0x866);
    pSystem->nPools = nPools;
    pSystem->pRecords = 0;
    for (int i = 0; i < nPools; ++i)
    {
        InitializeCriticalSection(&pSystem->aPools[i].tLock);
        int nBlockSize;
        if (i == 0)
        {
            nBlockSize = 0x10;
        }
        else
        {
            nBlockSize = 1 << (i + 4);
        }
        pSystem->aPools[i].nBlockSize = nBlockSize;
        if (nBlockSize > 1000000 || (nBlockSize << 8) >= 0x40000)
        {
            nValue = 0x80000 / nBlockSize;
        }
        else
        {
            nValue = 0x100;
            if ((nBlockSize << 8) < 0x10000)
            {
                nValue = 0x10000 / nBlockSize;
            }
        }
        pSystem->aPools[i].nBlocksPerChunk = nValue;
        pSystem->aPools[i].nChunkSize = nBlockSize * nValue;
    }
    memset(pSystem->apLargeBlocks, 0, sizeof(pSystem->apLargeBlocks));
    LeaveCriticalSection(pLock);
    return 0;
}

// 0x00409C80
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!gtPoolManager.bInit)
    {
        return;
    }
    if (!pSystem)
    {
        pSystem = &gtPoolManager.aSystems[0];
    }
    if (!pSystem->nPools)
    {
        return;
    }
    for (int i = 0; i < pSystem->nPools; i++)
    {
        D2MemPoolRecStrc* pPool = &pSystem->aPools[i];
        D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            D2MemPoolBlockStrc* pNext = pBlock->pNext;
            VirtualFree(pBlock->pMemory, 0, 0x8000);
            free(pBlock);
            pBlock = pNext;
        }
        DeleteCriticalSection(&pPool->tLock);
    }
    free(pSystem->pRecords);
    for (int j = 0; j < 1023; j++)
    {
        int* pEntry = pSystem->apLargeBlocks[j];
        while (pEntry)
        {
            int* pNext = (int*)*pEntry;
            free(pEntry);
            pEntry = pNext;
        }
    }
    DeleteCriticalSection(&pSystem->tLock);
    memset(pSystem, 0, sizeof(D2PoolSystemStrc));
    EnterCriticalSection(&gtPoolManager.tLock);
    gtPoolManager.anFreeIndex[gtPoolManager.nFreeCount] = ((unsigned int)pSystem - (unsigned int)&gtPoolManager.aSystems[0]) / sizeof(D2PoolSystemStrc);
    gtPoolManager.nFreeCount++;
    LeaveCriticalSection(&gtPoolManager.tLock);
    if (pSystem == &gtPoolManager.aSystems[0])
    {
        gtPoolManager.bInit = 0;
        DeleteCriticalSection(&gtPoolManager.tLock);
    }
}

#include "gen/data/Source/Fog/Src/ErrorManager.inc"
