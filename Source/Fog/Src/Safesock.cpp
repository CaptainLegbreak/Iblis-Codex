#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#include "D2Win32Types.h"
#include "D2NetTypes.h"
#include "D2Primitives.h"
#include "D2StormLink.h"
#include "D2Win32System.h"
#include "D2FogTypes.h"
#include "D2CmdArg.h"
#include "D2FogSystemInfo.h"

int __stdcall SFileCloseFile(void* pArg);    // 0x004198D0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct AsyncDataEventSlot;

struct D2CriticalSectionStrc;

struct D2MiniDumpRequestStrc;

struct D2FogSystemInfoStrc;

struct D2ProcessEntryWStrc;

struct D2StartupInfoWStrc;

struct D2ProcessInformationStrc;

struct D2OverlappedStrc;

struct AsyncDataLoadFileCallback;

struct AsyncData;

struct _iobuf;

struct D2InspectorInfoStrc;

struct D2CrashSubmitInfoStrc;

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

extern D2MiniDumpRequestStrc* gpMiniDumpRequest; // 0x0098A6E4

extern void* gpfnCrashHandler; // 0x00992B10

extern D2FogSystemInfoStrc gtSystemInfo_0074D88C; // 0x0074D88C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


extern "C" int __stdcall Process32FirstW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1524

extern "C" int __stdcall Process32NextW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1530



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
    const char* szLocale;
    const char* szFrom;
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

void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...);                                          // 0x00409020

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...);                // 0x00410660

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

char gszResolvedHostIP[256];                                                                       // 0x0075D040

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

int __cdecl EXCEPTIONS_LoadImageHlp(); // 0x0040D5B0

void __cdecl LOGMANAGER_InitLogSystem(); // 0x00410540

int __cdecl SYSTEM_IsPlatformNT(); // 0x00410960

void __cdecl SYSTEM_InitTimeBase(); // 0x004109D0

void __cdecl sub_00411210_InitTimer(); // 0x00411210

void __fastcall SetErrorReportCallback(void* pfnHandler); // 0x0041C0E0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern D2CriticalSectionStrc gtLock_0074C830; // 0x0074C830

extern D2CriticalSectionStrc gtLock_0074D848; // 0x0074D848

extern int gbErrorMgrInit; // 0x0074F0D0

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

D2PoolDirectoryStrc gtPoolManager;                                                                   // 0x0074F0E8

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220

extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C

extern "C" unsigned char _BitScanReverse(unsigned long* pIndex, unsigned long nMask);

extern "C" unsigned char _BitScanForward(unsigned long* pIndex, unsigned long nMask);

void* __fastcall ERRORMANAGER_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x00409770

extern const unsigned int gadwLowBitMasks[]; // 0x006CD490

int __fastcall ERRORMANAGER_FindZeroBit(unsigned int nWord); // 0x00409220

void* __fastcall ERRORMANAGER_PoolAlloc(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x0040A080

static D2MemPoolBlockStrc* __stdcall ERRORMANAGER_FindPoolBlock(void* pMemory, D2PoolSystemStrc* pSystem); // 0x004099D0

static void ERRORMANAGER_MoveBlockToFront(D2MemPoolRecStrc* pPool, D2MemPoolBlockStrc* pBlock); // 0x00409A60

void __fastcall ERRORMANAGER_PoolFree(D2PoolSystemStrc* pSystem, void** ppMemory, const char* szFile, int nLine); // 0x00409AB0

int sgfAsyncDataEnabled; // 0x0075AF94

bool __fastcall sub_00402820_WriteMiniDump(const char* szPath, const char* szComment, void* pExceptionPointers, unsigned long dwThreadId); // 0x00402820

void __cdecl ERRORMANAGER_ForceCrash(); // 0x00407970

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);

extern "C" int __stdcall setsockopt(unsigned int nSocket, int nLevel, int nOption, const char* pValue, int nLength); // 0x006B0162

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern "C" const char gszUnknownUpper[];                                                           // 0x006CCED8

extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385

extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E

extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1C4

extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags);                // 0x006B0174

void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize);                                 // 0x0040F000

void __fastcall LOGMANAGER_SweepLogFile(const D2FileTimeStrc* pNow, const char* szFile);                  // 0x0040F3D0

extern D2CriticalSectionStrc gtLogLock;                                                            // 0x0075E850

struct FSafeSock;

struct D2LogMsgListStrc;

class CCritSect;

extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5

int __fastcall FOG_SOCKET_WSAStartup(); // 0x0040D890

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0040FED0_DeleteAll();                                          // 0x0040FED0
};

FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking); // 0x0040D8E0

extern int gnLogQueued; // 0x0075D140

extern int gnLogQueuedBytes; // 0x0075D144

int gbLogInitialized; // 0x0075D2EC

unsigned long gnLogThreadId; // 0x0075E834

extern D2CriticalSectionStrc gtLogQueueLock; // 0x0075E838

extern D2LogMsgListStrc gtLogMsgQueue_0075E868; // 0x0075E868

extern D2CriticalSectionStrc gtTimeLock; // 0x0075E880

int __stdcall ERRORMANAGER_MeasureCpuMHz(); // 0x0040E870

extern "C" const char gszIntel386[]; // 0x006CE074

extern "C" const char gszIntel486[]; // 0x006CE080

extern "C" const char gszCpuSpeedFormat[]; // 0x006CE08C

extern "C" const char gszCpuVersionFormat[]; // 0x006CE0A8

extern "C" const char gszCpuVendorFormat[]; // 0x006CE0EC

class CCritSect
{
public:
    CCritSect();                                                                                            // 0x0040EB50
    ~CCritSect();                                                                                           // 0x0040EB60
    void Enter();
    void Leave();

    D2CriticalSectionStrc tLock;
};

struct D2ImageHlpLineStrc;

struct D2PeDosHeaderStrc;

struct D2PeNtHeadersStrc;

struct D2PeSectionStrc;

struct D2ImageHlpAddressStrc;

struct D2ImageHlpStackFrameStrc;

struct D2ImageHlpSymbolStrc;

struct D2ImageHlpModuleStrc;

struct D2CrashDumpEntryStrc;

struct D2SystemTimeStrc;

struct D2ModuleInfoStrc;

struct D2MemoryBasicInfoStrc;

unsigned long __stdcall sub_004101C0_LogThreadProc(void* pParam); // 0x004101C0

extern D2SystemTimeStrc gLogStartTime_0075D288; // 0x0075D288


extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4

int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220

D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleListToolhelp(unsigned long dwPid); // 0x0040B690

extern int (__stdcall* gpfnImageHlpSymCleanup)(void* hProcess); // 0x0075CFDC

extern unsigned long (__stdcall* gpfnImageHlpSymGetOptions)(); // 0x0075CFF0

extern int (__stdcall* gpfnImageHlpSymInitialize)(void* hProcess, const char* szSearchPath, int bInvadeProcess); // 0x0075CFF8

extern unsigned long (__stdcall* gpfnSymLoadModule)(void* hProcess, void* hFile, const char* szImageName, const char* szModuleName, unsigned long dwBase, unsigned long dwSize); // 0x0075CFFC

extern unsigned long (__stdcall* gpfnImageHlpSymSetOptions)(unsigned long dwOptions); // 0x0075D004

extern int gbImageHlpLoaded; // 0x0075D014

extern "C" void* __fastcall FOG_AllocPool(void* pool,int size,const char* file,int line,int flags);

extern "C" void* gpSmackFrameBuffer; // 0x009897D0

extern "C" const char gszExceptionsCppFile[]; // 0x006CD628





typedef int (__stdcall* StackWalkFn)(unsigned long dwMachine, void* hProcess, void* hThread, D2ImageHlpStackFrameStrc* pFrame, void* pContext, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase, void* pfnTranslateAddress);

typedef int (__stdcall* SymGetSymFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol);

typedef int (__stdcall* SymGetModuleInfoFn)(void* hProcess, unsigned long dwAddress, D2ImageHlpModuleStrc* pModuleInfo);

typedef int (__stdcall* SymGetLineFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);

extern "C" const char gszEmptyString_006FFC44[]; // 0x006FFC44

int __cdecl s_DoSymInitialize(); // 0x0040C620

int __fastcall EXCEPTIONS_ReleaseSymbols(int all); // 0x0040C720

int (__stdcall* gpfnSymGetLineFromAddr)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine); // 0x0075CFE4

extern void* gpfnSymFunctionTableAccess; // 0x0075CFE0

extern void* gpfnSymGetModuleBase; // 0x0075CFE8

extern SymGetModuleInfoFn gpfnSymGetModuleInfo; // 0x0075CFEC

extern SymGetSymFromAddrFn gpfnSymGetSymFromAddr; // 0x0075CFF4

extern StackWalkFn gpfnStackWalk; // 0x0075D008

extern unsigned int gnStackWalkDepth; // 0x0075D018

void __stdcall SMemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0


extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200

extern "C" const char gszReadBinary_006CDC90[]; // 0x006CDC90

D2CriticalSectionStrc gtImageHlpLock; // 0x0075CFBC

int gnSymInitCount; // 0x0075CFD4

static void __stdcall EXCEPTIONS_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize); // 0x0040C520

char gszAddressText[32]; // 0x0075D020

int ganLogNewFile[20]; // 0x0075D298

char gaszLogFilePaths[20][0x104]; // 0x0075D340

int gnLogQueueCount; // 0x0075E870

struct D2ToolhelpModuleEntryStrc;


typedef void* (__stdcall* CreateToolhelp32SnapshotFn)(unsigned long dwFlags, unsigned long dwProcessId);

typedef int (__stdcall* Module32Fn)(void* hSnapshot, D2ToolhelpModuleEntryStrc* pEntry);

typedef int (__stdcall* EnumProcessModulesFn)(void* hProcess, void** phModules, unsigned long nSize, unsigned long* pnNeeded);

typedef unsigned long (__stdcall* GetModuleNameFn)(void* hProcess, void* hModule, char* szName, unsigned long nSize);

typedef int (__stdcall* GetModuleInformationFn)(void* hProcess, void* hModule, D2PsapiModuleInfoStrc* pInfo, unsigned long nSize);

extern "C" const char gszExceptionsCpp_006CD628[]; // 0x006CD628


extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

#pragma intrinsic(strlen)

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

void __cdecl LOGMANAGER_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740

char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote); // 0x004113E0

D2ModuleInfoStrc* __fastcall EXCEPTIONS_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList); // 0x0040BCB0

extern const char gszStackEipLine[]; // 0x006CD938

extern const char gszLogLineFormat[]; // 0x006CD90C

extern const char gszStackStringLine[]; // 0x006CD8C8

extern const char gszStackSymbolLine[]; // 0x006CD890

extern const char gszStackPad_006FFC44[]; // 0x006FFC44

static int __stdcall EXCEPTIONS_GetLineFromAddrRetry(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine); // 0x0040B600

static D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleList(void* hProcess, unsigned long dwPid); // 0x0040BC50

static D2ModuleInfoStrc* __stdcall EXCEPTIONS_LoadModuleSymbols(unsigned long dwPid, void* hProcess); // 0x0040C0F0

static char* EXCEPTIONS_ComposeSymbolPath(char* szPath); // 0x0040C290

extern "C" void __fastcall EXCEPTIONS_FreeModuleList(D2ModuleInfoStrc* pList);                                  // 0x0040B660

void __fastcall EXCEPTIONS_DumpAnnotatedStack(void* hProcess, D2ThreadContextStrc* pContext, D2ModuleInfoStrc* pModules); // 0x0040BCF0


char gszImageHlpSymSearchPath[4096]; // 0x0075BFB8

int gbSymQuiet; // 0x0075CFB8

// build: symbol ?strrchr@@YAPADPADH@Z 0x00401A30
char* __cdecl strrchr(char* szString, int nChar)
{
    return strrchr((const char*)szString, nChar);
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

// 0x0040DF60
const char* __fastcall FOG_GetHostIPAddress()
{
    D2WSADataStrc tData;
    D2SockAddrInStrc tLocal;
    char szHost[0x100];
    tLocal.sin_addr.s_addr = 0;
    WSAStartup(0x101, &tData);
    if (gethostname(szHost, sizeof(szHost)) != -1)
    {
        D2HostentStrc* pHost = gethostbyname(szHost);
        if (pHost)
        {
            tLocal.sin_addr.s_addr = *(unsigned long*)pHost->h_addr_list[0];
        }
    }
    if (!tLocal.sin_addr.s_addr)
    {
        const unsigned int nSocket = socket(2, 2, 0);
        if (nSocket != -1)
        {
            D2SockAddrInStrc tRemote;
            tRemote.sin_family = 2;
            tRemote.sin_port = htons(7);
            tRemote.sin_addr.s_addr = inet_addr("24.105.29.30");
            if (connect(nSocket, &tRemote, sizeof(tRemote)) != -1)
            {
                int nLength = sizeof(tLocal);
                getsockname(nSocket, &tLocal, &nLength);
            }
            closesocket(nSocket);
        }
    }
// build: symbol ?gszStringFormat@* 0x006FFC58
    sprintf(gszResolvedHostIP, gszStringFormat, inet_ntoa(tLocal.sin_addr));
    WSACleanup();
    return gszResolvedHostIP;
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
        LOGMANAGER_WriteLogLine("ERROR: Disconnecting socket due to WSAETIMEDOUT\n");
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
int __fastcall FOG_SOCKET_GetSockName(FSafeSock* pSafeSock, void* pAddress, int* pnLength)
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
int __fastcall FOG_SOCKET_SetNonBlocking(FSafeSock* pSafeSock)
{
    unsigned long nArgument = 1;
    return ioctlsocket(pSafeSock->nSocket, 0x8004667E, &nArgument);
}

// 0x0040E200
int __fastcall FOG_SOCKET_SetBlocking(FSafeSock* pSafeSock)
{
    unsigned long nArgument = 0;
    return ioctlsocket(pSafeSock->nSocket, 0x8004667E, &nArgument);
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

void __cdecl sub_0047B4D0_Nop()
{
}

void __cdecl sub_004BF9C0_Nop()
{
}

void __cdecl GLSPRITE_DebugFillBackBuffer()
{
}

void* __fastcall ERRORMANAGER_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine); // 0x0040A1F0

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224

// 0x0040D8E0
FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking)
{
    FSafeSock* pSafeSock = (FSafeSock*)FOG_Alloc(sizeof(FSafeSock), ".\\Src\\Safesock.cpp", 204, 0);
    memset(pSafeSock, 0, sizeof(FSafeSock));
    if (szName)
    {
        SStrCopy(pSafeSock->szName, szName, sizeof(pSafeSock->szName));
    }
    else
    {
        SStrCopy(pSafeSock->szName, gszUnknownUpper, sizeof(pSafeSock->szName));
    }
    InitializeCriticalSection(&pSafeSock->tCriticalSection);

    D2WSADataStrc tWSAData;
    const int nStartupError = WSAStartup(0x101, &tWSAData);
    if (nStartupError)
    {
        pSafeSock->nWSALastError = nStartupError;
        pSafeSock->nFogErrorCode = 1;
        DeleteCriticalSection(&pSafeSock->tCriticalSection);
        FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 223, 0);
        return 0;
    }

    const unsigned int nSocket = socket(2, 1, 0);
    pSafeSock->nSocket = nSocket;
    if (nSocket == -1)
    {
        pSafeSock->nWSALastError = WSAGetLastError();
        pSafeSock->nFogErrorCode = 2;
        DeleteCriticalSection(&pSafeSock->tCriticalSection);
        FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 243, 0);
        return 0;
    }

    int bNoDelay = 1;
    setsockopt(nSocket, 6, 1, (const char*)&bNoDelay, 4);
    int bKeepAlive = 1;
    setsockopt(nSocket, 0xFFFF, 8, (const char*)&bKeepAlive, 4);
    int nSendTimeout = 3000;
    setsockopt(nSocket, 0xFFFF, 0x1005, (const char*)&nSendTimeout, 4);

    if (bNonBlocking & 1)
    {
        unsigned long nArgument = 1;
        ioctlsocket(nSocket, 0x8004667E, &nArgument);
    }

    pSafeSock->bConnecting = 1;
    D2SockAddrInStrc tAddress;
    memset(&tAddress, 0, sizeof(tAddress));
    tAddress.sin_family = 2;
    tAddress.sin_port = htons(nPortNumber);
    tAddress.sin_addr.s_addr = inet_addr(szHostAddress);
    if (connect(nSocket, &tAddress, sizeof(tAddress)) == -1)
    {
        const int nError = WSAGetLastError();
        if (!(bNonBlocking & 1) || (nError != 0x2733 && nError != 0x2734))
        {
            pSafeSock->nWSALastError = nError;
            pSafeSock->nFogErrorCode = 3;
            DeleteCriticalSection(&pSafeSock->tCriticalSection);
            FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 291, 0);
            return 0;
        }
    }

    if (!(bNonBlocking & 1))
    {
        pSafeSock->bConnected = 1;
        pSafeSock->bConnecting = 0;
    }

    if (!gszResolvedHostIP[0] || !inet_addr(gszResolvedHostIP))
    {
        D2SockAddrInStrc tLocal;
        int nLength = sizeof(tLocal);
        if (getsockname(nSocket, &tLocal, &nLength) != -1)
        {
            strcpy(gszResolvedHostIP, inet_ntoa(tLocal.sin_addr));
        }
    }

    if (pThreadProc)
    {
        pSafeSock->hThread = CreateThread(0, 0, pThreadProc, lpParameter, 0, &pSafeSock->nThreadId);
    }
    return pSafeSock;
}

// 0x0040DBD0
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    pSafeSock->bStopping = 1;
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    if (pSafeSock->hThread)
    {
        WaitForSingleObject(pSafeSock->hThread, 5000);
    }
    if (pSafeSock->hThread)
    {
        CloseHandle(pSafeSock->hThread);
        pSafeSock->hThread = 0;
    }
    if (pSafeSock->nSocket != (unsigned int)-1)
    {
        const unsigned int nSocket = pSafeSock->nSocket;
        pSafeSock->nSocket = (unsigned int)-1;
        pSafeSock->bConnected = 0;
        if (closesocket(nSocket) == -1)
        {
            pSafeSock->nWSALastError = WSAGetLastError();
            pSafeSock->nFogErrorCode = 5;
        }
    }
    DeleteCriticalSection(&pSafeSock->tCriticalSection);
    FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 387, 0);
}

// 0x0040DC60
int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength)
{
    if (!pSafeSock || pSafeSock->bStopping)
    {
        return 0;
    }
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    const int nReceived = recv(pSafeSock->nSocket, pBuffer, nBufferLength, 0);
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    if (nReceived <= 0)
    {
        pSafeSock->nWSALastError = WSAGetLastError();
        pSafeSock->nFogErrorCode = 4;
    }
    return nReceived;
}

// 0x0040DCC0
int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength)
{
    if (!pSafeSock || pSafeSock->bStopping)
    {
        return 0;
    }
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    const int nSent = send(pSafeSock->nSocket, pBuffer, nBufferLength, 0);
    int nResult;
    if (nSent == nBufferLength)
    {
        nResult = nSent;
    }
    else if (nSent == -1)
    {
        pSafeSock->nWSALastError = WSAGetLastError();
        if (pSafeSock->nWSALastError == 0x2733)
        {
            nResult = 0;
        }
        else
        {
            pSafeSock->nFogErrorCode = 4;
            nResult = -1;
        }
    }
    else
    {
        pSafeSock->nWSALastError = WSAGetLastError();
        pSafeSock->nFogErrorCode = 4;
        nResult = 0;
    }
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    return nResult;
}

// 0x0040DDD0
void __fastcall FOG_SOCKET_Lock(FSafeSock* pSafeSock)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
}

// 0x0040DDE0
void __fastcall FOG_SOCKET_Unlock(FSafeSock* pSafeSock)
{
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
}

// 0x0040E0B0
int __fastcall FOG_SOCKET_GetError(FSafeSock* pSafeSock, unsigned long* pFogError, unsigned long* pWSALastError)
{
    *pFogError = pSafeSock->nFogErrorCode;
    *pWSALastError = pSafeSock->nWSALastError;
    return 1;
}

// 0x0040E0D0
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName)
{
    int bStarted = 0;
    int a, b, c, d;
    if (sscanf(szHostName, "%d.%d.%d.%d", &a, &b, &c, &d) == 4)
    {
        return szHostName;
    }
    D2HostentStrc* pHost = gethostbyname(szHostName);
    if (!pHost || !pHost->h_addr_list || !pHost->h_addr_list[0])
    {
        if (WSAGetLastError() != 0x276D || !FOG_SOCKET_WSAStartup())
        {
            return 0;
        }
        pHost = gethostbyname(szHostName);
        if (!pHost || !pHost->h_addr_list || !pHost->h_addr_list[0])
        {
            WSACleanup();
            return 0;
        }
        bStarted = 1;
    }
    strcpy(gszResolvedHostIP, inet_ntoa(*(D2InAddrStrc*)pHost->h_addr_list[0]));
    if (bStarted)
    {
        WSACleanup();
    }
    return gszResolvedHostIP;
}

void* ghLogThread; // 0x0075D2E8

int gbLogThreadStop; // 0x0075E830

// 0x0040E230
FSafeSock* __fastcall FOG_SOCKET_Connect(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName)
{
    return FOG_SOCKET_ConnectEx(szHostAddress, nPortNumber, pThreadProc, lpParameter, szName, 0);
}

// 0x0040E080
char* __fastcall FOG_inet_ntoa(int nAddress)
{
    D2InAddrStrc tAddress;
    tAddress.s_addr = nAddress;
    return strcpy(gszAddressText, inet_ntoa(tAddress));
}

// 0x0040D880
int __fastcall FOG_SOCKET_CloseSocket(unsigned int s)
{
    return closesocket(s);
}

// 0x0040D8D0
int __cdecl sub_0040D8D0()
{
    return WSACleanup();
}
