#include "Fog.h"
#include "D2FogTypes.h"
#include "D2NetTypes.h"
#include "D2Primitives.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"
#include "D2Win32System.h"
#include "D2CmdArg.h"
#include "D2FogSystemInfo.h"

typedef unsigned int size_t;

typedef char* va_list;

struct _iobuf;

struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

extern "C" __int64 __cdecl _time64(__int64* pTime);                                                         // 0x0068568B

extern "C" int __cdecl _localtime64_s(tm* pTm, const __int64* pTime);                                       // 0x006856E9

extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathW(unsigned long nBufferLength, wchar_t* wszBuffer); // 0x006CC2BC

extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194

bool __stdcall ERRORMANAGER_CreateDirectoryUtf8(const char* szPath);                                                // 0x004045F0

_iobuf* __stdcall ERRORMANAGER_OpenFileForWriteUtf8(const char* szPath);                                    // 0x004043C0

char gszLogDirectory[0x400];                                                                       // 0x00992708

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool OpenReport(const char* szFileName);                         // 0x00401100
    bool sub_004011F0_Close();                                              // 0x004011F0
    bool sub_00401210_IsOpen();                                             // 0x00401210
    bool sub_00401220_AddFile(const char* szPath, bool bCopy);              // 0x00401220
    int sub_00401380(const char* szFormat, ...);                            // 0x00401380
    bool WriteInspectorHeader();                               // 0x00407A80

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[16][0x400];
};
}

extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext);             // 0x006CC290

extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C

extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread);                         // 0x006CC288

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);                          // 0x006CC28C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HostentStrc;

struct D2ThreadNameInfoStrc;

struct D2UnicodeStringStrc;

struct D2ListEntryStrc;

struct D2LdrEntryStrc;

struct D2LdrDataStrc;

struct D2PebStrc;

struct D2TebStrc;

struct D2ModeIfaceStrc;

struct D2ModeEntryStrc;

struct D2ServiceTableEntryStrc;

struct D2GuidStrc;

struct D2SidAuthorityStrc;

struct D2ProcessEntryStrc;

void __cdecl sub_00402980_StartDbgHelpWorker(); // 0x00402980


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0










struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};



typedef long (__stdcall* D2KnownFolderPathFn)(const D2GuidStrc* pFolderId, unsigned long dwFlags, void* hToken, wchar_t** pwszPath);

typedef int (__stdcall* D2AllocateAndInitializeSidFn)(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid);

typedef int (__stdcall* D2InitializeAclFn)(void* pAcl, unsigned long nAclLength, unsigned long dwAclRevision);

typedef int (__stdcall* D2AddAccessDeniedAceFn)(void* pAcl, unsigned long dwAceRevision, unsigned long dwAccessMask, void* pSid);

typedef unsigned long (__stdcall* D2SetSecurityInfoFn)(void* hObject, int nObjectType, unsigned long dwSecurityInfo, void* pOwner, void* pGroup, void* pDacl, void* pSacl);

typedef void* HKEY;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

extern "C" double __cdecl floor(double x); // 0x00683080

extern "C" unsigned long __readfsdword(unsigned long nOffset);

extern "C" __declspec(dllimport) int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006CC564

extern "C" __declspec(dllimport) D2HostentStrc* __stdcall gethostbyname(const char* szName); // 0x006CC57C

extern "C" __declspec(dllimport) int __stdcall WSACleanup(); // 0x006CC58C

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent(); // 0x006CC284

extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleW(const wchar_t* wszModuleName); // 0x006CC2DC

extern "C" __declspec(dllimport) long __stdcall RegOpenKeyA(HKEY hKey, const char* szSubKey, HKEY* phResult); // 0x006CC040

extern "C" __declspec(dllimport) long __stdcall RegCreateKeyA(HKEY hKey, const char* szSubKey, HKEY* phResult); // 0x006CC03C

extern "C" __declspec(dllimport) long __stdcall RegEnumValueA(HKEY hKey, unsigned long dwIndex, char* szValueName, unsigned long* pcchValueName, unsigned long* pReserved, unsigned long* pType, unsigned char* pData, unsigned long* pcbData); // 0x006CC038

extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(HKEY hKey, const char* szValueName, unsigned long dwReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY hKey); // 0x006CC030

extern "C" __declspec(dllimport) long __stdcall RegDeleteKeyA(HKEY hKey, const char* szSubKey); // 0x006CC02C

extern "C" __declspec(dllimport) int __stdcall SetCurrentDirectoryA(const char* szPath); // 0x006CC140

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C

extern "C" __declspec(dllimport) void* __stdcall FreeSid(void* pSid); // 0x006CC044

extern "C" __declspec(dllimport) unsigned long __stdcall GetVersion(); // 0x006CC138

extern "C" __declspec(dllimport) void* __stdcall OpenSCManagerA(const char* szMachineName, const char* szDatabaseName, unsigned long dwDesiredAccess); // 0x006CC028

extern "C" __declspec(dllimport) void* __stdcall OpenServiceA(void* hSCManager, const char* szServiceName, unsigned long dwDesiredAccess); // 0x006CC04C

extern "C" __declspec(dllimport) int __stdcall CloseServiceHandle(void* hSCObject); // 0x006CC01C

extern "C" __declspec(dllimport) int __stdcall StartServiceCtrlDispatcherA(const D2ServiceTableEntryStrc* pServiceTable); // 0x006CC020

extern "C" __declspec(dllimport) void __stdcall CoTaskMemFree(void* pMemory); // 0x006CC5F0

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4

extern "C" int __stdcall Process32First(void* hSnapshot, D2ProcessEntryStrc* pEntry); // 0x006B1440

extern "C" int __stdcall Process32Next(void* hSnapshot, D2ProcessEntryStrc* pEntry); // 0x006B143A

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

bool __fastcall ERRORMANAGER_CreateDirectoryWide(wchar_t* wszPath); // 0x00404560

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** argv); // 0x004065E0

extern "C" const char gszInternalCheckHost[]; // 0x006FF994

extern "C" const D2GuidStrc gtKnownFolderId; // 0x006CCA6C

extern const double gdDaysPerYear; // 0x006CCC08

extern const double gdDaysPerMonth; // 0x006CCC10

extern char gszServiceName[]; // 0x007065DC

extern D2ModeEntryStrc gaModeTable[]; // 0x00706554

extern int gnMode_0074C704; // 0x0074C704

extern void* gpModeContext_0074C718; // 0x0074C718

struct D2FileTimeStrc;

struct D2FindDataStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0

extern int gnGenericRle; // 0x008F03C8

int __stdcall SFileOpenFile(const char* szFileName, void** phFile); // 0x00419980

int __stdcall SFileReadFileEx2(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0

int __stdcall SFileGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C

extern "C" __declspec(dllimport) int __stdcall MoveFileA(const char* szExisting, const char* szNew); // 0x006CC1D0

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC

extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData); // 0x006CC1C8

extern "C" __declspec(dllimport) int __stdcall RemoveDirectoryA(const char* szPathName); // 0x006CC1C0

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

int __fastcall ERRORMANAGER_GetJulianDay(int nYear, int nMonth, int nDay); // 0x00407370

void __fastcall ERRORMANAGER_JulianDayToDate(long nJulian, int* pYear, int* pMonth, int* pDay); // 0x00407440

int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60

void __stdcall ERRORMANAGER_WriteProcessorReport(); // 0x0040EA00

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

extern int gnOsKind; // 0x0074D890

extern float gfOsVersion; // 0x0074D894

void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

void __cdecl LOGMANAGER_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740

extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile); // 0x00408000

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660

int gbWritingCrashReport; // 0x0074F0C8

D2ModeIfaceStrc* gpModeIface; // 0x0074C700

int gbRunningAsService; // 0x0074C720

char szSRegReadBuf[260]; // 0x0074C728

unsigned long gdwTotalPhys; // 0x0074D898

#define OUTPUT_SIZE 0x80

extern int gdwMainThreadId;  // 0x00992B1C

extern "C" const char gszMainThread[];  // 0x006FF988

extern "C" int __cdecl strncpy_s(char*,unsigned int,const char*,unsigned int);  // 0x006859D2

struct D2PoolSystemStrc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void __cdecl FOG_AsyncDataDestroy();                                                                        // 0x0040A440

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80

int __cdecl EXCEPTIONS_UnloadImageHlp();                                                                  // 0x0040B500

void __cdecl LOGMANAGER_CloseLogFilesNow();                                                               // 0x0040F8A0

void __cdecl SYSTEM_DeleteTimeLock();                                                                 // 0x004107A0

void __cdecl LOGMANAGER_ShutdownLogSystem();                                                              // 0x0040FFD0

extern "C" const char gszStringFormat[];                                                           // 0x006FFC58

D2CriticalSectionStrc gtLock_0074C830;                                                                      // 0x0074C830

D2CriticalSectionStrc gtLock_0074D848;                                                                      // 0x0074D848

int gbErrorMgrInit;                                                                                // 0x0074F0D0

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C

extern "C" __declspec(dllimport) int __stdcall CopyFileW(const wchar_t* wszExistingFile, const wchar_t* wszNewFile, int bFailIfExists); // 0x006CC2CC

static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize); // 0x00404010

static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest); // 0x00404450

static size_t ERRORMANAGER_StrLCopy(char* szDest, const char* szSource, size_t nSize); // 0x00404110

static bool ERRORMANAGER_AppendPathSeparator(char* szPath); // 0x004040B0

static int ERRORMANAGER_FormatText(char* szDest, size_t nSize, const char* szFormat, ...); // 0x004041F0

static bool ERRORMANAGER_GetTempPathUtf8(char* szOut); // 0x004044F0

static bool __stdcall ERRORMANAGER_CopyPathIfHasDirectory(const char* szPath, char* szOut, size_t nSize); // 0x00403FA0

extern "C" __declspec(dllimport) int __stdcall AllocateAndInitializeSid(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid); // 0x006CC014

extern "C" __declspec(dllimport) int __stdcall CheckTokenMembership(void* hToken, void* pSid, int* pbIsMember); // 0x006CC050

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();                             // 0x006CC1EC

bool __fastcall ERRORMANAGER_GetProcessImageName(unsigned long dwProcessId, char* szName, unsigned long nSize); // 0x00407A20

unsigned long __fastcall ERRORMANAGER_FindParentProcessId(unsigned long dwProcessId);                         // 0x00407990

unsigned int __fastcall LOGMANAGER_GetLogFilePaths(char** apszFiles, unsigned int nCount);                     // 0x0040EB90

int __stdcall sub_00525150();                                                                       // 0x00525150

int __stdcall STRTABLE_GetSystemLanguage();                                                                   // 0x005251C0

D2InspectorInfoStrc gtInspectorInfo; // 0x0074D868

char gszProcessPath[2048];                                                                         // 0x0074E8C8

extern const char* const gaszLanguageNames[];                                                      // 0x00706618

extern "C" const char gszUnknownUpper[];                                                           // 0x006CCED8

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

bool __stdcall ERRORMANAGER_GetKnownFolderPathA(char* szPath, int nSize);                                   // 0x004067D0

int __fastcall ERRORMANAGER_AppendBackslash(char* szPath, size_t nSize);                                // 0x00406B20

int __fastcall ERRORMANAGER_MoveDirectoryTree(const char* szPathA, const char* szPathB);                         // 0x00406DE0

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

struct D2ThreadContextStrc;

struct D2CrashSubmitInfoStrc
{
    const char* szName;
    int nUnk04;
    int nUnk08;
    unsigned int dwFlags;
    const char* apszLines[16];
    int nLines;
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C

void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7); // 0x00403070

void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext); // 0x004032F0

void __fastcall ERRORMANAGER_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId); // 0x00403A20

void __fastcall ERRORMANAGER_ReportPrint(void* pContext, const char* szText);                               // 0x00407980

bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo);                // 0x00401790

extern long volatile gnReportBusy;                                                                 // 0x007076B8

extern "C" const char gszCrashFile[];                                                              // 0x006CD1C0

extern "C" const char gszFmtSummary[];                                                             // 0x006CD1E8

extern "C" const char gszFmtLineNumber[];                                                          // 0x006CD1CC

extern "C" const char gszAssertionBegin[];                                                         // 0x006CD170

extern "C" const char gszAssertionEnd[];                                                           // 0x006CD158

extern "C" const char gszRegisters[];                                                              // 0x006CD14C

extern "C" const char gszThreads[];                                                                // 0x006CD140

struct D2StackFrameStrc;

struct D2ExceptionPointersStrc { void* pRecord; D2ThreadContextStrc* pContext; };


void __fastcall sub_00403100_PrintFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, unsigned int nFrames, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader); // 0x00403100

void __fastcall sub_00402EE0_DumpModules(D2CrashPrintFn pfnPrint,void* pContext); // 0x00402EE0

unsigned long __cdecl ERRORMANAGER_GetCurrentThreadId(); // 0x00401690

void __fastcall ERRORMANAGER_TerminateCurrentProcess(unsigned int nCode); // 0x004013C0

bool __fastcall sub_00402820_WriteMiniDump(const char* szPath,const char* szComment,void* pExceptionPointers,unsigned long dwThreadId); // 0x00402820

extern const char gszCrashSummary[]; // 0x006CD1A8

extern const char gszCrashDetail[]; // 0x006CD1A0

extern const char gszCrashNewline[]; // 0x006CD188

extern const char gszModules[]; // 0x006CD124

extern const char gszMore1[]; // 0x006CD108

extern const char gszMore2[]; // 0x006CD0F0

extern const char gszMore3[]; // 0x006CD0D4

extern const char gszMore4[]; // 0x006CD0C4

extern const char gszMinidump[]; // 0x006CD0B4

extern const char gszMore5[]; // 0x006CD09C

int __stdcall SFileCloseFile(void* pArg);    // 0x004198D0

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

struct D2InspectorInfoStrc;

struct D2CrashSubmitInfoStrc;

typedef long (__stdcall* D2ExceptionFilterFn)(void* pExceptionPointers);

extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode); // 0x006CC274

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void* __stdcall CreateFileW(const wchar_t* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC298

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) D2ExceptionFilterFn __stdcall SetUnhandledExceptionFilter(D2ExceptionFilterFn pfnFilter); // 0x006CC2B4

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryW(const wchar_t* szPath, void* pSecurityAttributes); // 0x006CC2C8

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesW(const wchar_t* szFileName); // 0x006CC2B8

extern "C" wchar_t* __cdecl wcsrchr(const wchar_t* szString, wchar_t nChar); // 0x00685DF7

const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0

bool __cdecl sub_00401B00_LoadDbgHelp(); // 0x00401B00

long __stdcall sub_00403E90_UnhandledExceptionFilter(void* pExceptionPointers); // 0x00403E90

void __fastcall LOGMANAGER_SetLogPrefix(const char* szName); // 0x0040F5A0

extern bool gbMiniDumpEnabled; // 0x0098A6B1

extern D2CriticalSectionStrc gtSymbolLock; // 0x0098A6F0

extern D2CriticalSectionStrc gtDbgHelpRequestLock; // 0x0098A6C4

extern void* ghDbgHelp; // 0x0098A680

extern D2MiniDumpRequestStrc* gpMiniDumpRequest; // 0x0098A6E4

extern void* gpfnCrashHandler; // 0x00992B10

extern D2FogSystemInfoStrc gtSystemInfo_0074D88C; // 0x0074D88C



extern "C" int __stdcall Process32FirstW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1524

extern "C" int __stdcall Process32NextW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1530



extern "C" __declspec(dllimport) int __stdcall CreateProcessW(const wchar_t* wszApplicationName, wchar_t* wszCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const wchar_t* wszCurrentDirectory, D2StartupInfoWStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC2C4

void __cdecl LOGMANAGER_CloseLogFiles(); // 0x0040F960

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

extern long volatile gnCrashReportBusy; // 0x007076BC

bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag); // 0x00408660

char gszTextBuffer[0x400]; // 0x0098A280

void* gpCrashContext; // 0x00992B14

D2ExceptionFilterFn gpfnPreviousFilter; // 0x00992B18

int gnSourcePrefixLength; // 0x0074F0D4

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

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1

extern "C" void* __cdecl malloc(size_t nSize);                                                              // 0x00683EFD

extern "C" _iobuf* __cdecl _wfopen(const wchar_t* szFileName, const wchar_t* szMode);                       // 0x00685EED

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


extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags);          // 0x006B017A

extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168

extern "C" int __stdcall closesocket(unsigned int nSocket);                                                 // 0x006B012C

extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186

extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet);                            // 0x006B0180

extern "C" int __stdcall getpeername(unsigned int nSocket, void* pAddress, int* pnLength);                 // 0x006B018C

extern "C" int __stdcall ioctlsocket(unsigned int nSocket, long nCommand, unsigned long* pArgument);       // 0x006B015C


void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...);                                          // 0x00409020

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

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

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

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

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern D2PoolDirectoryStrc gtPoolManager; // 0x0074F0E8

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

inline D2TebStrc* D2_NtCurrentTeb()
{
    return (D2TebStrc*)__readfsdword(0x18);
}

int __cdecl D2CMPToggleCelDrawMode()
{
    return gnGenericRle = (gnGenericRle == 0);
}

static int __fastcall FOG_AppendBackslash(char* szPath, int nSize)
{
    if (!szPath || !nSize)
        return 0;
    unsigned int nLen = SStrLen(szPath);
    if (nLen <= 0 || szPath[nLen - 1] != '\\')
    {
        if (nLen + 1 == nSize)
            return 0;
        szPath[nLen] = '\\';
        szPath[nLen + 1] = 0;
    }
    return 1;
}

static bool AppendPathSeparator_Inl(char* szPath, size_t nSize)
{
    if (!nSize)
    {
        return false;
    }
    const size_t nLength = SStrLen(szPath);
    if (nLength > 0 && szPath[nLength - 1] == '\\')
    {
        return true;
    }
    if (nLength + 1 == nSize)
    {
        return false;
    }
    szPath[nLength] = '\\';
    szPath[nLength + 1] = 0;
    return true;
}

// 0x004082E0
int __fastcall ERRORMANAGER_CrashHandler(D2CrashInputStrc* pInput)
{
    D2ThreadContextStrc* pThread = pInput->pException->pContext;
    const long nBusy = InterlockedIncrement(&gnReportBusy);
    if (nBusy == 0)
    {
        gbWritingCrashReport = 1;
        crashy::Report report;
        if (!report.OpenReport(gszCrashFile))
        {
            gbWritingCrashReport = 0;
        }
        else
        {
            report.WriteInspectorHeader();
            report.sub_00401380(gszCrashSummary,pInput->szSummary);
            if (pInput->szDetail[0]) report.sub_00401380(gszCrashDetail,pInput->szDetail);
            report.sub_00401380(gszCrashNewline);
            report.sub_00401380(gszAssertionBegin);
            int nSkip = 0;
            if (!pThread && !pInput->pFrames)
            {
                nSkip = pInput->nSkip;
                if (pInput->dwThreadId == ERRORMANAGER_GetCurrentThreadId()) nSkip += 2;
            }
            if (pInput->pFrames)
                sub_00403100_PrintFrames(pInput->dwThreadId,pInput->pFrames,pInput->nFrames,ERRORMANAGER_ReportPrint,&report,0,1);
            else
                ERRORMANAGER_DumpThread(pInput->dwThreadId,pThread,ERRORMANAGER_ReportPrint,&report,0,1,nSkip);
            report.sub_00401380(gszAssertionEnd);
            report.sub_00401380(gszRegisters);
            sub_004032F0_DumpRegisters(pInput->dwThreadId,ERRORMANAGER_ReportPrint,&report);
            report.sub_00401380(gszThreads);
            ERRORMANAGER_DumpOtherThreads(ERRORMANAGER_ReportPrint,&report,pInput->dwThreadId);
            report.sub_00401380(gszModules);
            sub_00402EE0_DumpModules(ERRORMANAGER_ReportPrint,&report);
            report.sub_00401380(gszMore1);
            report.sub_00401380(gszMore2);
            report.sub_00401380(gszMore3);
            if (pInput->pFrames)
                sub_00403100_PrintFrames(pInput->dwThreadId,pInput->pFrames,pInput->nFrames,ERRORMANAGER_ReportPrint,&report,0,0);
            else
                ERRORMANAGER_DumpThread(pInput->dwThreadId,pThread,ERRORMANAGER_ReportPrint,&report,0,0,nSkip);
            report.sub_00401380(gszMore4);
            SStrCopy(gszProcessPath,report.m_szText408,0x800);
            SStrPack(gszProcessPath,gszMinidump,0x800);
            if (sub_00402820_WriteMiniDump(gszProcessPath,&gszEmptyAssertText,pInput->pException,0))
                report.sub_00401220_AddFile(gszProcessPath,false);
            report.sub_00401380(gszMore5);
            report.sub_004011F0_Close();
            D2CrashSubmitInfoStrc info;
            memset(&info,0,sizeof(info));
            info.szName=gtInspectorInfo.szUnused04;
            for (int i=0;i<report.m_nLineCount;++i)
            {
                if (i < sizeof(info.apszLines)/sizeof(info.apszLines[0]))
                {
                    info.apszLines[i]=report.m_aszLines[i];
                    ++info.nLines;
                }
            }
            sub_00401790_SubmitReport(report.m_szText08,&info);
            gbWritingCrashReport=0;
        }
        InterlockedDecrement(&gnReportBusy);
        ERRORMANAGER_TerminateCurrentProcess(-1);
    }
    return 2;
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

int sgfAsyncDataEnabled; // 0x0075AF94

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

void __cdecl ERRORMANAGER_ForceCrash(); // 0x00407970

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


// 0x004088C0
int __fastcall ERRORMANAGER_ReportNestedError(const char* szFile, int nLine, const char* szMessage)
{
    if (gbWritingCrashReport)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "\n***** ENCOUNTERED ERROR DURING ERROR HANDLING!!!\n%s,%d\n%s\n*****", ERRORMANAGER_StripSourcePath(szFile), nLine, szMessage);
        return 1;
    }
    return 0;
}

// 0x00408A60
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408CE0
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile)
{
    char szPath[0x1000];
    if (gbErrorMgrInit)
    {
        if (bLogToFile)
        {
            ERRORMANAGER_LogSystemInfo();
        }
        return;
    }
    ERRORMANAGER_StartDbgHelpThread();
    ERRORMANAGER_SetCrashHandler(ERRORMANAGER_CrashHandler, 0, 0);
    if (ERRORMANAGER_GetModuleDirectory(szPath, 0x1000))
    {
        ERRORMANAGER_SetReportText(szPath);
    }
    gtInspectorInfo.nProjectId = 0x108;
    gtInspectorInfo.szUnused04 = "Diablo II";
    gtInspectorInfo.szApplication = "Diablo II";
    gtInspectorInfo.szModule = "Diablo II";
    sprintf(gszInspectorVersion, "D2 %i.%i%c", 1, 14, 'd');
    gtInspectorInfo.szMilestone = gszInspectorVersion;
    gtInspectorInfo.szBuildNumber = "77";
    gtInspectorInfo.szPlatform = "Windows";
    gtInspectorInfo.szPrimaryAssignment = ".ClassicErrorReporter";
    gtInspectorInfo.szAssignments = ".ClassicErrorReporter";
    if (szVersion)
    {
        SStrCopy(gszVersion, szVersion, 0x1000);
    }
    gbIsPlatformNT = SYSTEM_IsPlatformNT();
    InitializeCriticalSection(&gtLock_0074C830);
    InitializeCriticalSection(&gtLock_0074D848);
    gbErrorMgrInit = 1;
    SYSTEM_InitTimeBase();
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "TraceUnfreedMemory", 0, &dwValue);
    gdwRegValue = dwValue;
// build: symbol ?FOG_CreateNewPoolSystem@* 0x00409DD0
    FOG_CreateNewPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    sub_00411210_InitTimer();
    for (int i = 0; i < 0x20; ++i)
    {
        const unsigned int nMask = 1 << i;
        FOG_ASSERT(gdwBitMasks_006CE268[i] == nMask, 0x576);
        FOG_ASSERT(gdwInvBitMasks[i] == ~nMask, 0x577);
    }
    AUTOMAP_CaptureSystemInfo();
    LOGMANAGER_InitLogSystem();
    if (bLogToFile)
    {
        ERRORMANAGER_LogSystemInfo();
    }
    atexit(ERRORMANAGER_ExitHandler);
    EXCEPTIONS_LoadImageHlp();
// build: symbol ?ERRORMANAGER_ShowErrorReport@* 0x00408660
    SetErrorReportCallback(ERRORMANAGER_ShowErrorReport);
}
