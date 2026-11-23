#include "Fog.h"
#include "D2FogTypes.h"
#include "D2NetTypes.h"
#include "D2Primitives.h"
#include "D2GameTypes.h"

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

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

struct D2ThreadNameInfoStrc
{
    unsigned long dwType;
    const char* szName;
    unsigned long dwThreadID;
    unsigned long dwFlags;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2UnicodeStringStrc
{
    unsigned short Length;
    unsigned short MaximumLength;
    wchar_t* Buffer;
};

struct D2ListEntryStrc
{
    D2ListEntryStrc* Flink;
    D2ListEntryStrc* Blink;
};

struct D2LdrEntryStrc
{
    D2ListEntryStrc InLoadOrderLinks;
    D2ListEntryStrc InMemoryOrderLinks;
    D2ListEntryStrc InInitializationOrderLinks;
    D2ModuleStrc* DllBase;
    void* EntryPoint;
    unsigned long SizeOfImage;
    D2UnicodeStringStrc FullDllName;
};

struct D2LdrDataStrc
{
    char unk0x00[0x14];
    D2ListEntryStrc InMemoryOrderModuleList;
};

struct D2PebStrc
{
    char unk0x00[0x0C];
    D2LdrDataStrc* Ldr;
};

struct D2TebStrc
{
    char unk0x00[0x30];
    D2PebStrc* ProcessEnvironmentBlock;
};

struct D2ModeIfaceStrc
{
    int (__fastcall* pfnRun)(int nArg);
};

struct D2ModeEntryStrc
{
    D2ModeIfaceStrc* (__fastcall* pfnCreate)(void* pContext);
    void (__cdecl* pfnRelease)();
};

struct D2ServiceTableEntryStrc
{
    char* szServiceName;
    void (__stdcall* pfnServiceProc)(unsigned long dwArgc, char** argv);
};

struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct D2SidAuthorityStrc
{
    unsigned char Value[6];
};

struct D2ProcessEntryStrc
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
    char szExeFile[260];
};

typedef long (__stdcall* D2KnownFolderPathFn)(const D2GuidStrc* pFolderId, unsigned long dwFlags, void* hToken, wchar_t** pwszPath);

typedef int (__stdcall* D2AllocateAndInitializeSidFn)(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid);

typedef int (__stdcall* D2InitializeAclFn)(void* pAcl, unsigned long nAclLength, unsigned long dwAclRevision);

typedef int (__stdcall* D2AddAccessDeniedAceFn)(void* pAcl, unsigned long dwAceRevision, unsigned long dwAccessMask, void* pSid);

typedef unsigned long (__stdcall* D2SetSecurityInfoFn)(void* hObject, int nObjectType, unsigned long dwSecurityInfo, void* pOwner, void* pGroup, void* pDacl, void* pSacl);

typedef void* HKEY;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

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

int __stdcall sub_00419980(const char* szFileName, void** phFile); // 0x00419980

int __stdcall SFileReadFileEx2(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0

int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370

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

void __stdcall sub_0040EA00_WriteProcessorReport(); // 0x0040EA00

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610

extern int gnOsKind; // 0x0074D890

extern float gfOsVersion; // 0x0074D894

void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

void __cdecl MAINMENUS_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740

extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile); // 0x00408000

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660

extern int gbWritingCrashReport; // 0x0074F0C8

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

int __cdecl sub_0040B500_UnloadImageHlp();                                                                  // 0x0040B500

void __cdecl LOGMANAGER_CloseLogFilesNow();                                                               // 0x0040F8A0

void __cdecl sub_004107A0_DeleteTimeLock();                                                                 // 0x004107A0

void __cdecl sub_0040FFD0_ShutdownLogSystem();                                                              // 0x0040FFD0

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

unsigned int __fastcall EXCEPTIONS_GetLogFilePaths(char** apszFiles, unsigned int nCount);                     // 0x0040EB90

int __stdcall sub_00525150();                                                                       // 0x00525150

int __stdcall STRTABLE_GetSystemLanguage();                                                                   // 0x005251C0

extern D2InspectorInfoStrc gtInspectorInfo;                                                       // 0x0074D868

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

struct D2CrashInputStrc
{
    const char* szSummary;
    const char* szDetail;
    D2StackFrameStrc* pFrames;
    int nFrames;
    int nSkip;
    unsigned long dwThreadId;
    D2ExceptionPointersStrc* pException;
};

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

// 0x00401000
static int __cdecl ERRORMANAGER_ConvertLocalTime(tm* pTm, const __int64* pTime)
{
    return _localtime64_s(pTm, pTime);
}

// calling-convention shim (not game code)
int __cdecl sub_M126_Emit_00401000(tm* pTm, const __int64* pTime)
{
    return ERRORMANAGER_ConvertLocalTime(pTm, pTime);
}

bool __stdcall sub_K01_Emit_00403FA0(const char* szPath, char* szOut, size_t nSize)
{
    return ERRORMANAGER_CopyPathIfHasDirectory(szPath, szOut, nSize);
}

// 0x00401100
bool crashy::Report::OpenReport(const char* szFileName)
{
    __int64 nTime = _time64(0);
    tm tTime;
    _localtime64_s(&tTime, &nTime);
    if (!gszLogDirectory[0])
    {
        if (!ERRORMANAGER_GetTempPathUtf8(gszLogDirectory))
        {
            return false;
        }
        if (!ERRORMANAGER_AppendPathSeparator(gszLogDirectory))
        {
            return false;
        }
    }
    if ((size_t)(ERRORMANAGER_FormatText(m_szText408, 0x400, "%s/%04d-%02d-%02d %02d.%02d.%02d", gszLogDirectory, tTime.tm_year + 0x76C, tTime.tm_mon + 1, tTime.tm_mday, tTime.tm_hour, tTime.tm_min, tTime.tm_sec) + 1) > 0x400)
    {
        return false;
    }
    if (!ERRORMANAGER_CreateDirectoryUtf8(m_szText408))
    {
        return false;
    }
    if ((size_t)(ERRORMANAGER_FormatText(m_szText08, 0x400, "%s/%s", m_szText408, szFileName) + 1) > 0x400)
    {
        return false;
    }
    m_pFile = ERRORMANAGER_OpenFileForWriteUtf8(m_szText08);
    return m_pFile != 0;
}

// 0x00401480
static unsigned char __stdcall ERRORMANAGER_GetStackRange(void** ppBase, unsigned long* pEnd, const void* pAddress)
{
    D2MemoryBasicInfoStrc tInfo;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.State != 0x1000)
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.Protect != 4)
        return 0;
    *pEnd = (unsigned long)tInfo.BaseAddress + tInfo.RegionSize;
    if (*pEnd <= (unsigned long)pAddress)
        return 0;
    *ppBase = tInfo.AllocationBase;
    if (!VirtualQuery(tInfo.AllocationBase, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.BaseAddress != *ppBase)
        return 0;
    unsigned long dwEnd = (unsigned long)*ppBase + tInfo.RegionSize;
    if (tInfo.State == 0x1000)
    {
        if (dwEnd != *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    if (tInfo.State == 0x2000)
    {
        if (dwEnd >= *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    return 0;
}

// 0x00401540
static unsigned char __stdcall ERRORMANAGER_GetThreadStack(unsigned long* pStackSize, unsigned long dwThreadId, unsigned long* pStackTop, unsigned long* pStackPointer)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    tContext.ContextFlags = 0x10001;
    if (GetCurrentThreadId() == dwThreadId)
    {
        RtlCaptureContext(&tContext);
    }
    else
    {
        hThread = OpenThread(0x4A, 0, dwThreadId);
        if (!hThread)
            return 0;
        if (SuspendThread(hThread) == -1)
            return 0;
        if (!GetThreadContext(hThread, &tContext))
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
            return 0;
        }
    }
    *pStackPointer = tContext.Esp;
    void* pBase;
    unsigned long dwEnd;
    unsigned char bResult = ERRORMANAGER_GetStackRange(&pBase, &dwEnd, (const void*)tContext.Esp);
    if (bResult)
    {
        *pStackTop = dwEnd;
        *pStackSize = dwEnd - (unsigned long)pBase;
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return bResult;
}

// 0x00401640
static bool __stdcall ERRORMANAGER_GetThreadName(int threadId,char* output) {
 if(gdwMainThreadId==threadId) strncpy_s(output,OUTPUT_SIZE,gszMainThread,(unsigned int)-1);
 else output[0]=0;
 return true;
}

bool __fastcall EmitThreadName(int threadId,char* output) {
 return ERRORMANAGER_GetThreadName(threadId,output);
}

// 0x00401680
int __cdecl ERRORMANAGER_GetMainThreadId()
{
    return gdwMainThreadId;
}

int D2ThreadContextStrc::sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    if (this)
    {
        tContext = *this;
    }
    else
    {
        tContext.ContextFlags = 0x10001;
        if (GetCurrentThreadId() == dwThreadId)
        {
            RtlCaptureContext(&tContext);
        }
        else
        {
            hThread = OpenThread(0x4A, 0, dwThreadId);
            if (!hThread)
                return 0;
            if (SuspendThread(hThread) == -1)
                return 0;
            if (!GetThreadContext(hThread, &tContext))
            {
                ResumeThread(hThread);
                CloseHandle(hThread);
                return 0;
            }
        }
    }
    unsigned int nCount = 0;
    unsigned long dwPc = tContext.Eip;
    unsigned long dwFrame = tContext.Ebp;
    unsigned long dwStack = tContext.Esp;
    unsigned long dwStackTop;
    unsigned long dwStackSize;
    unsigned long dwStackPointer;
    if (!ERRORMANAGER_GetThreadStack(&dwStackSize, dwThreadId, &dwStackTop, &dwStackPointer))
    {
        if (hThread)
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
        }
        return 0;
    }
    __try
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            if (i >= (unsigned int)nSkipFrames)
            {
                pFrames[nCount].dwPc = dwPc;
                pFrames[nCount].dwStack = dwStack;
                pFrames[nCount].dwFrame = dwFrame;
                nCount++;
                if (nCount >= 0x80)
                    break;
            }
            if (dwFrame <= dwStack)
                break;
            if (dwFrame + 8 > dwStackTop)
                break;
            unsigned long dwNext = *(unsigned long*)dwFrame;
            if (dwNext & 3)
                break;
            if (dwNext <= dwFrame)
                break;
            dwStack = dwFrame + 4;
            dwPc = *(unsigned long*)dwStack;
            dwFrame = dwNext;
        }
    }
    __except (1)
    {
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return nCount;
}

// 0x004016A0
void __cdecl ERRORMANAGER_StartDbgHelpThread()
{
    sub_00402980_StartDbgHelpWorker();
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004016C0
bool __cdecl ERRORMANAGER_IsInternalCheckLoopback()
{
    D2WSADataStrc tData;
    if (WSAStartup(0x202, &tData))
    {
        return false;
    }
    bool bResult = false;
    D2HostentStrc* pHost = gethostbyname(gszInternalCheckHost);
    if (pHost && pHost->h_addrtype == 2 && *(unsigned long*)pHost->h_addr_list[0] == 0x0100007F)
    {
        bResult = true;
    }
    WSACleanup();
    return bResult;
}

// 0x00401A70
void __cdecl ERRORMANAGER_SetMiniDumpThreadName()
{
    if (IsDebuggerPresent() == 1)
    {
        D2ThreadNameInfoStrc tInfo;
        tInfo.dwType = 0x1000;
        tInfo.szName = "MiniDump Thread";
        tInfo.dwThreadID = -1;
        tInfo.dwFlags = 0;
        __try
        {
            RaiseException(0x406D1388, 0, 4, (unsigned long*)&tInfo);
        }
        __except (-1)
        {
        }
    }
}

// 0x00403070
void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7)
{
    D2StackFrameStrc aFrames[0x80];
    int nFrames = pThreadContext->sub_00405060_CaptureFrames(dwThreadId, aFrames, nArg7);
    if (nFrames > 0)
    {
        if (nFrames > 0x80)
        {
            nFrames = 0x80;
        }
        sub_00403100_PrintFrames(dwThreadId, aFrames, nFrames, pfnPrint, pContext, bSymbols, bHeader);
    }
}

// 0x00403FA0
static bool __stdcall ERRORMANAGER_CopyPathIfHasDirectory(const char* szPath, char* szOut, size_t nSize)
{
    const char* pSep = 0;
    const char* p = strrchr(szPath, '/');
    if (p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, '\\');
    if (p && p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, ':');
    if (p && p > pSep)
    {
        pSep = p;
    }
    if (!pSep)
    {
        *szOut = 0;
    }
    else if (ERRORMANAGER_StrLCopy(szOut, szPath, nSize) >= nSize)
    {
        return false;
    }
    return true;
}

static __forceinline size_t StrLCopy(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        size_t n = nSize - 1;
        if (n)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--n);
        }
        if (!n)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

bool crashy::Report::sub_00401220_AddFile(const char* szPath, bool bCopy)
{
    if (m_nLineCount >= 16)
    {
        return false;
    }
    char szCopy[0x400];
    const char* szSource;
    if (bCopy)
    {
        if (!m_szText408[0])
        {
            return false;
        }
        const size_t nLength = StrLCopy(szCopy, m_szText408, 0x400);
        if (nLength >= 0x400)
        {
            return false;
        }
        char* pName = szCopy + nLength;
        *pName++ = '/';
        if (!ERRORMANAGER_CopyFileName(szPath, pName, szCopy + 0x400 - pName))
        {
            return false;
        }
        ERRORMANAGER_CopyFileUtf8(szPath, szCopy);
        szSource = szCopy;
    }
    else
    {
        if (strlen(szPath) >= 0x400)
        {
            return false;
        }
        szSource = szPath;
    }
    StrLCopy(m_aszLines[m_nLineCount], szSource, 0x400);
    m_nLineCount++;
    return true;
}

// 0x00404010
static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize)
{
    const char* pSep = 0;
    const char* p = strrchr(szPath, '/');
    if (p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, '\\');
    if (p && p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, ':');
    if (p && p > pSep)
    {
        pSep = p;
    }
    if (pSep)
    {
        szPath = pSep + 1;
    }
    return StrLCopy(szOut, szPath, nSize) < nSize ? true : false;
}

// 0x004040B0
static bool ERRORMANAGER_AppendPathSeparator(char* szPath)
{
    char* pEnd = szPath + strlen(szPath);
    if (pEnd == szPath + 0x400)
    {
        return false;
    }
    if (pEnd != szPath && pEnd[-1] != '/' && pEnd[-1] != '\\')
    {
        *pEnd = '\\';
    }
    return ERRORMANAGER_StrLCopy(szPath, "BlizzardError", 0x400) < 0x400;
}

// 0x00404110
static __declspec(noinline) size_t ERRORMANAGER_StrLCopy(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        size_t n = nSize - 1;
        if (n)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--n);
        }
        if (!n)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

// 0x004041F0
static int ERRORMANAGER_FormatText(char* szDest, size_t nSize, const char* szFormat, ...)
{
    const int nResult = _vsnprintf(szDest, nSize - 1, szFormat, (va_list)(&szFormat + 1));
    szDest[nSize - 1] = 0;
    return nResult;
}

// 0x00404450
static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest)
{
    wchar_t wszSource[0x104];
    wchar_t wszDest[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szSource, -1, wszSource, 0x104))
    {
        return false;
    }
    if (!MultiByteToWideChar(0xFDE9, 0, szDest, -1, wszDest, 0x104))
    {
        return false;
    }
    return CopyFileW(wszSource, wszDest, 1) != 0;
}

// 0x004044F0
static bool ERRORMANAGER_GetTempPathUtf8(char* szOut)
{
    wchar_t wszPath[0x104];
    const unsigned long nLength = GetTempPathW(0x104, wszPath);
    if (!nLength)
    {
        return false;
    }
    return WideCharToMultiByte(0xFDE9, 0, wszPath, nLength + 1, szOut, 0x400, 0, 0) != 0;
}

// 0x004045F0
bool __stdcall ERRORMANAGER_CreateDirectoryUtf8(const char* szPath)
{
    wchar_t wszPath[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104))
    {
        return false;
    }
    return ERRORMANAGER_CreateDirectoryWide(wszPath);
}

inline D2TebStrc* D2_NtCurrentTeb()
{
    return (D2TebStrc*)__readfsdword(0x18);
}

// 0x00404E60
bool __fastcall ERRORMANAGER_EnumLoadedModules(void* pContext)
{
    if (!GetModuleHandleW(L"ntdll.dll"))
    {
        return false;
    }
    __try
    {
        D2LdrDataStrc* pLdr = D2_NtCurrentTeb()->ProcessEnvironmentBlock->Ldr;
        D2ListEntryStrc* pHead = &pLdr->InMemoryOrderModuleList;
        for (D2ListEntryStrc* pLink = pHead->Flink; pLink != pHead; pLink = pLink->Flink)
        {
            D2LdrEntryStrc* pEntry = (D2LdrEntryStrc*)((char*)pLink - 8);
            if (!pEntry->DllBase->sub_00404AB0_VisitModule(pContext, pEntry->FullDllName.Buffer, pEntry->FullDllName.Length))
            {
                break;
            }
        }
    }
    __except (1)
    {
    }
    return true;
}

// 0x004059D0
int __stdcall ERRORMANAGER_RunModeInterface(int nArg)
{
    if (gnMode_0074C704 < 1 || gnMode_0074C704 > 5)
    {
        return 0;
    }
    D2_ASSERT(gaModeTable[gnMode_0074C704].pfnCreate, 307);
    D2_ASSERT(gaModeTable[gnMode_0074C704].pfnRelease, 308);
    gpModeIface = gaModeTable[gnMode_0074C704].pfnCreate(gpModeContext_0074C718);
    const int nResult = gpModeIface->pfnRun(nArg);
    gaModeTable[gnMode_0074C704].pfnRelease();
    return nResult;
}

// 0x00405F00
void __fastcall SaveCmdLine(const char** argv)
{
    char szSRegWriteBuf[0x800];
    unsigned long bUseCmdLine = 0;
    if (*argv && strlen(*argv))
    {
        sprintf(szSRegWriteBuf, "%s -skiptobnet", *argv);
        SRegSaveString("Diablo II", "CmdLine", 0, szSRegWriteBuf);
    }
    else
    {
        SRegLoadValue("Diablo II", "UseCmdLine", 0, &bUseCmdLine);
        if (bUseCmdLine)
        {
            SRegLoadString("Diablo II", "CmdLine", 0, szSRegReadBuf, 0x400);
            *argv = szSRegReadBuf;
        }
        else
        {
            memcpy(szSRegWriteBuf, "-skiptobnet", sizeof("-skiptobnet"));
            SRegSaveString("Diablo II", "CmdLine", 0, szSRegWriteBuf);
        }
    }
    bUseCmdLine = 0;
    SRegSaveValue("Diablo II", "UseCmdLine", 0, 0);
    if (gbRunningAsService)
    {
        SRegLoadString("Diablo II", "SvcCmdLine", 0, szSRegReadBuf, 0x400);
        *argv = szSRegReadBuf;
    }
}

// 0x00406040
void __cdecl MoveBetaSettingsToRelease()
{
    HKEY hBeta;
    if (0 == RegOpenKeyA((HKEY)0x80000002, "SOFTWARE\\Blizzard Entertainment\\Diablo II Beta", &hBeta))
    {
        HKEY hKey;
        RegCreateKeyA((HKEY)0x80000002, "SOFTWARE\\Blizzard Entertainment\\Diablo II", &hKey);
        int i = 0;
        unsigned long cchValue;
        unsigned long cbData;
        char szValue[0x104];
        unsigned char bData[0x400];
        unsigned long dwRegType;
        do
        {
            cchValue = 0x104;
            cbData = 0x400;
            if (0 != RegEnumValueA(hBeta, i++, szValue, &cchValue, 0, &dwRegType, bData, &cbData))
            {
                break;
            }
        }
        while (0 == RegSetValueExA(hKey, szValue, 0, dwRegType, bData, cbData));
        RegCloseKey(hKey);
        RegCloseKey(hBeta);
        RegDeleteKeyA((HKEY)0x80000002, "SOFTWARE\\Blizzard Entertainment\\Diablo II Beta");
    }
    char szPath[0x104] = { 0 };
    FOG_GetInstallPath(szPath, 0x104);
    if (gbRunningAsService)
    {
        SetCurrentDirectoryA(szPath);
    }
}

// 0x004061C0
int __cdecl ERRORMANAGER_DenyProcessAccess()
{
    D2SidAuthorityStrc tAuthority = { { 0, 0, 0, 0, 0, 1 } };
    void* hProcess = GetCurrentProcess();
    void* pSid = 0;
    int bResult = 0;
    unsigned char aAcl[0x200];
    void* hAdvapi = LoadLibraryA("advapi32.dll");
    if (hAdvapi)
    {
        D2AllocateAndInitializeSidFn pfnAllocSid = (D2AllocateAndInitializeSidFn)GetProcAddress(hAdvapi, "AllocateAndInitializeSid");
        if (pfnAllocSid)
        {
            D2InitializeAclFn pfnInitAcl = (D2InitializeAclFn)GetProcAddress(hAdvapi, "InitializeAcl");
            if (pfnInitAcl)
            {
                D2AddAccessDeniedAceFn pfnAddDenied = (D2AddAccessDeniedAceFn)GetProcAddress(hAdvapi, "AddAccessDeniedAce");
                if (pfnAddDenied)
                {
                    D2SetSecurityInfoFn pfnSetSec = (D2SetSecurityInfoFn)GetProcAddress(hAdvapi, "SetSecurityInfo");
                    if (pfnSetSec)
                    {
                        if (pfnAllocSid(&tAuthority, 1, 0, 0, 0, 0, 0, 0, 0, 0, &pSid)
                            && pfnInitAcl(aAcl, sizeof(aAcl), 2)
                            && pfnAddDenied(aAcl, 2, 0xF01FFFFE, pSid)
                            && !pfnSetSec(hProcess, 6, 0x80000004, 0, 0, aAcl, 0))
                        {
                            bResult = 1;
                        }
                    }
                }
            }
        }
        FreeLibrary(hAdvapi);
    }
    if (pSid)
    {
        FreeSid(pSid);
    }
    return bResult;
}

// 0x00406650
int __cdecl ERRORMANAGER_StartServiceDispatcher()
{
    if (!(GetVersion() & 0x80000000))
    {
        void* hManager = OpenSCManagerA(0, 0, 0xF003F);
        if (hManager)
        {
            void* hService = OpenServiceA(hManager, gszServiceName, 0xF01FF);
            if (hService)
            {
                CloseServiceHandle(hService);
            }
            CloseServiceHandle(hManager);
            if (hService)
            {
                D2ServiceTableEntryStrc aTable[] = {
                    { gszServiceName, D2ServerServiceMain },
                    { 0, 0 }
                };
                return StartServiceCtrlDispatcherA(aTable) != 0;
            }
        }
    }
    return 0;
}

// 0x004067C0
int __cdecl ERRORMANAGER_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

// 0x004067D0
bool __stdcall ERRORMANAGER_GetKnownFolderPathA(char* szPath, int nSize)
{
    void* hShell = GetModuleHandleA("Shell32.dll");
    D2KnownFolderPathFn pfnGet = (D2KnownFolderPathFn)GetProcAddress(hShell, "SHGetKnownFolderPath");
    if (!pfnGet)
    {
        return false;
    }
    wchar_t* wszPath;
    if (pfnGet(&gtKnownFolderId, 0x8000, 0, &wszPath) < 0)
    {
        return false;
    }
    int bUsedDefault = 0;
    const int nResult = WideCharToMultiByte(0, 0x400, wszPath, -1, szPath, nSize, 0, &bUsedDefault);
    CoTaskMemFree(wszPath);
    return nResult && !bUsedDefault;
}

int __cdecl D2CMPToggleCelDrawMode()
{
    return gnGenericRle = (gnGenericRle == 0);
}

// 0x004076B0
void __cdecl ERRORMANAGER_LogSystemInfo()
{
    D2SystemTimeStrc tTime;
    unsigned long nSize;
    char szPath[0x1000];
    char szOs[0x1000];
    char szComputer[0x40];

    sub_00410610_WriteLogLine("------------------------------------------------------");
    GetLocalTime(&tTime);
    sub_00410610_WriteLogLine("%04d-%02d-%02d %02d:%02d:%02d", tTime.wYear, tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond);

    switch (gnOsKind)
    {
    case 1:
        memcpy(szOs, "Windows NT", sizeof("Windows NT"));
        break;
    case 2:
        memcpy(szOs, "Windows 2000", sizeof("Windows 2000"));
        break;
    case 3:
        memcpy(szOs, "Windows XP", sizeof("Windows XP"));
        break;
    case 4:
        memcpy(szOs, "Windows .Net", sizeof("Windows .Net"));
        break;
    case 9:
        memcpy(szOs, "MacOS", sizeof("MacOS"));
        break;
    case 10:
        memcpy(szOs, "MacOS X", sizeof("MacOS X"));
        break;
    default:
        memcpy(szOs, "unknown", sizeof("unknown"));
        break;
    }

    sub_00410610_WriteLogLine("%s running under %s (Version %.3f)", "Diablo II", szOs, gfOsVersion);
    sub_0040EA00_WriteProcessorReport();
    sub_00410610_WriteLogLine("Total Physical Memory: %.2fMB", (float)gdwTotalPhys / 1048576.0);

    if (EXCEPTIONS_GetAppPath(szPath, sizeof(szPath)))
    {
        sub_00410610_WriteLogLine("Application Path: %s", szPath);
    }

    sub_00410610_WriteLogLine("Local IP: %s", FOG_GetHostIPAddress());

    nSize = sizeof(szComputer);
    if (!GetComputerNameA(szComputer, &nSize))
    {
        szComputer[0] = 0;
    }

    sub_00410610_WriteLogLine("Computer name: %s", szComputer);
    sub_00410610_WriteLogLine("------------------------------------------------------");
    sub_00410610_WriteLogLine(&gszEmptyAssertText);
}

// 0x00407970
void __cdecl ERRORMANAGER_ForceCrash()
{
    int* pNull = 0;
    *pNull = 0;
}

// 0x00407980
void __fastcall ERRORMANAGER_ReportPrint(void* pContext, const char* szText)
{
    ((crashy::Report*)pContext)->sub_00401380(gszStringFormat, szText);
}

// 0x00407990
unsigned long __fastcall ERRORMANAGER_FindParentProcessId(unsigned long dwProcessId)
{
    unsigned long dwParent = 0;
    void* hSnapshot = CreateToolhelp32Snapshot(2, 0);
    D2ProcessEntryStrc tEntry;
    tEntry.dwSize = sizeof(tEntry);
    if (Process32First(hSnapshot, &tEntry))
    {
        do
        {
            if (tEntry.th32ProcessID == dwProcessId)
            {
                break;
            }
        }
        while (Process32Next(hSnapshot, &tEntry));
    }
    if (tEntry.th32ProcessID == dwProcessId)
    {
        dwParent = tEntry.th32ParentProcessID;
    }
    CloseHandle(hSnapshot);
    return dwParent;
}

// 0x00407F20
void __cdecl ERRORMANAGER_ExitHandler()
{
    if (gbErrorMgrInit)
    {
        FOG_AsyncDataDestroy();
        FOG_DestroyMemoryPoolSystem(0);
        sub_0040B500_UnloadImageHlp();
        LOGMANAGER_CloseLogFilesNow();
        sub_004107A0_DeleteTimeLock();
        sub_0040FFD0_ShutdownLogSystem();
        gbErrorMgrInit = 0;
        DeleteCriticalSection(&gtLock_0074C830);
        DeleteCriticalSection(&gtLock_0074D848);
    }
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

// 0x00407F80
void __fastcall ERRORMANAGER_RegisterThread(unsigned int nId, void* hThread)
{
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

// 0x00407F90
void __fastcall ERRORMANAGER_UnregisterThread(unsigned int nId)
{
}

// 0x00407FC0
static void __stdcall ERRORMANAGER_LogPrefixedText(const char* szPrefix, const char* szText, int bFlag)
{
    if (bFlag)
    {
        LOGMANAGER_LogWritePrefixedNoNewline(szPrefix, gszPercentS_006FFC58, szText);
    }
    else
    {
        MAINMENUS_LogWritePrefixed(szPrefix, gszPercentS_006FFC58, szText);
    }
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
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
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
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00407A80
bool crashy::Report::WriteInspectorHeader()
{
    if (!sub_00401210_IsOpen())
    {
        return false;
    }

    sub_00401380("<Application>%s\n", gtInspectorInfo.szApplication);
    sub_00401380("<Inspector.ProjectId>%d\n", gtInspectorInfo.f_0);
    sub_00401380("<Inspector.Module>%s\n", gtInspectorInfo.szModule);
    sub_00401380("<Inspector.Milestone>%s\n", gtInspectorInfo.szMilestone);
    sub_00401380("<Inspector.BuildNumber>%s\n", gtInspectorInfo.szBuildNumber);
    sub_00401380("<Inspector.Platform>%s\n", gtInspectorInfo.f_18);
    sub_00401380("<Inspector.IssueType>%s\n", "Exception");
    sub_00401380("<Inspector.Priority>%s\n", "1 - Critical");
    sub_00401380("<Inspector.PrimaryAssignment>%s\n", gtInspectorInfo.szPrimaryAssignment);
    sub_00401380("<Inspector.Assignments>%s\n", gtInspectorInfo.szAssignments);

    int bIsAdmin = 0;
    D2SidAuthorityStrc tNtAuthority = { { 0, 0, 0, 0, 0, 5 } };
    void* pSid;
    if (AllocateAndInitializeSid(&tNtAuthority, 2, 0x20, 0x220, 0, 0, 0, 0, 0, 0, &pSid))
    {
        bIsAdmin = CheckTokenMembership(0, pSid, &bIsAdmin);
        sub_00401380("<Process.UserIsAdmin> %s\n", bIsAdmin ? "TRUE" : "FALSE");
        FreeSid(pSid);
    }
    sub_00401380("<Process.Elevated> %s\n", gszUnknownUpper);

    unsigned long dwProcessId = GetCurrentProcessId();
    bool bFound = ERRORMANAGER_GetProcessImageName(dwProcessId, gszProcessPath, 0x800);
    sub_00401380("<Process.Path> %s\n", bFound ? gszProcessPath : "Unknown");
    const char* szSlash = strrchr(gszProcessPath, '\\');
    const char* szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.Name> %s\n", (szName && bFound) ? szName : "Unknown");

    unsigned long dwParentId = ERRORMANAGER_FindParentProcessId(dwProcessId);
    bFound = ERRORMANAGER_GetProcessImageName(dwParentId, gszProcessPath, 0x800);
    sub_00401380("<Process.ParentProcessPath> %s\n", bFound ? gszProcessPath : "Unknown");
    szSlash = strrchr(gszProcessPath, '\\');
    szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.ParentProcessName> %s\n", (szName && bFound) ? szName : "Unknown");

    unsigned long dwGrandParentId = ERRORMANAGER_FindParentProcessId(dwParentId);
    bFound = ERRORMANAGER_GetProcessImageName(dwGrandParentId, gszProcessPath, 0x800);
    sub_00401380("<Process.GrandParentProcessPath> %s\n", bFound ? gszProcessPath : "Unknown");
    szSlash = strrchr(gszProcessPath, '\\');
    szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.GrandParentProcessName> %s\n", (szName && bFound) ? szName : "Unknown");

    sub_00401380("<Locale.Game> %s\n", gaszLanguageNames[sub_00525150()]);
    sub_00401380("<Locale.System> %s\n", gaszLanguageNames[STRTABLE_GetSystemLanguage()]);
    sub_00401380("<Game.Type> %s\n", "Client");
    sub_00401380("<Game.Build> %s\n", "79b7ae8fe1e97d05d57ebdc4b65bf012d38c797e");

    char* apszFiles[0x15];
    memset(apszFiles, 0, sizeof(apszFiles));
    EXCEPTIONS_GetLogFilePaths(apszFiles, 0x15);
    for (unsigned int i = 0; i < 0x15; ++i)
    {
        if (apszFiles[i] && *apszFiles[i])
        {
            sub_00401220_AddFile(apszFiles[i], true);
        }
    }
    return true;
}

// 0x004068E0
int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile)
{
    return sub_00419980(szFileName, phFile);
}

// 0x00406900
int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6)
{
    return SFileReadFileEx2(hFile, pBuffer, nToRead, pnRead, pOverlapped, nArg6, nArg7);
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &f_8[f_4++];
}

// 0x00406930
int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh)
{
    return sub_00416370_StormGetFileSize(hFile, pnSizeHigh);
}

// 0x00406940
int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod)
{
    return SFileSetFilePointer(hFile, nOffset, pnOffsetHigh, nMethod);
}

// 0x00406A10
int __fastcall FOG_CreatePathHierarchy(const char* szPath)
{
    int bResult = 1;
    if (!szPath || !*szPath)
    {
        return 0;
    }
    char szDir[0x104];
    const char* pSep = SStrChr(szPath + 1, '\\');
    while (pSep)
    {
        const size_t nLen = pSep - szPath;
        if (nLen >= sizeof(szDir))
        {
            bResult = 0;
            break;
        }
        memcpy(szDir, szPath, nLen);
        szDir[nLen] = 0;
        if (!CreateDirectoryA(szDir, 0))
        {
            const unsigned long dwError = GetLastError();
            if (dwError != 0xB7 && dwError != 5 || !(GetFileAttributesA(szDir) & 0x10))
            {
                bResult = 0;
                break;
            }
        }
        pSep = SStrChr(pSep + 1, '\\');
    }
    return bResult;
}

// 0x00406C40
int __fastcall ERRORMANAGER_GetBlizzardDataPath(char* szOutPath, int nSize)
{
    char szPath[0x104];
    if (SHGetFolderPathA(0, 0x1C, 0, 0, szPath) < 0)
        return 0;
    SStrPack(szPath, "\\Blizzard Entertainment", 0x7FFFFFFF);
    if (!FOG_AppendBackslash(szPath, nSize))
        return 0;
    if (!FOG_CreatePathHierarchy(szPath))
        return 0;
    SStrCopy(szOutPath, szPath, nSize);
    return SStrLen(szOutPath) == SStrLen(szPath);
}

// 0x00406D30
static bool ERRORMANAGER_GetDefaultSavePath(char* szOutPath, unsigned int nMaxLen)
{
    char szPath[0x104];
    if (!nMaxLen)
    {
        return false;
    }
    D2_ASSERT(szOutPath, 68);
    if (ERRORMANAGER_GetKnownFolderPathA(szOutPath, nMaxLen))
    {
        ERRORMANAGER_AppendBackslash(szOutPath, nMaxLen);
        SStrPack(szOutPath, "Diablo II", nMaxLen);
    }
    else
    {
        if (SHGetFolderPathA(0, 5, 0, 0, szPath))
        {
            return false;
        }
        ERRORMANAGER_AppendBackslash(szOutPath, nMaxLen);
        SStrPack(szOutPath, "Diablo II\\Save", nMaxLen);
    }
    return true;
}

// 0x00406DE0
int __fastcall ERRORMANAGER_MoveDirectoryTree(const char* szSrc, const char* szDst)
{
    char szDir[0x104];
    SStrCopy(szDir, szDst, 0x7FFFFFFF);
    char* pCut = strrchr(szDir, '\\') + 1;
    char cSaved = *pCut;
    *pCut = 0;
    FOG_CreatePathHierarchy(szDir);
    *pCut = cSaved;
    if (MoveFileA(szSrc, szDst))
        return 2;
    unsigned long dwAttr = GetFileAttributesA(szSrc);
    if (dwAttr == (unsigned long)-1)
        return GetLastError() == 2 ? 2 : 1;
    if (!(dwAttr & 0x10))
        return 1;
    dwAttr = GetFileAttributesA(szDst);
    if (!(dwAttr & 0x10))
        return 1;
    if (dwAttr == (unsigned long)-1)
    {
        if (GetLastError() != 2)
            return 1;
        FOG_AppendBackslash(szDir, sizeof(szDir));
        FOG_CreatePathHierarchy(szDir);
    }
    char szSrcFind[0x104];
    char szDstFind[0x104];
    int nResult = 0;
    int nSrcLen = SStrPrintf(szSrcFind, 0x104, "%s\\*", szSrc) - 1;
    int nDstLen = SStrPrintf(szDstFind, 0x104, "%s\\", szDst);
    D2FindDataStrc tData;
    void* hFind = FindFirstFileA(szSrcFind, &tData);
    if (hFind != (void*)-1)
    {
        do
        {
            if (strcmp(tData.cFileName, ".") && strcmp(tData.cFileName, ".."))
            {
                SStrCopy(szSrcFind + nSrcLen, tData.cFileName, 0x104 - nSrcLen);
                SStrCopy(szDstFind + nDstLen, tData.cFileName, 0x104 - nDstLen);
                nResult |= ERRORMANAGER_MoveDirectoryTree(szSrcFind, szDstFind);
            }
        } while (FindNextFileA(hFind, &tData));
    }
    FindClose(hFind);
    RemoveDirectoryA(szSrc);
    return nResult;
}

// 0x00407050
int __fastcall FOG_GetSavePath(char* szPath, int nSize)
{
    char szSavePath[0x104];
    char szNewPath[0x104];
    szPath[0] = 0;
    if (!SRegLoadString("Diablo II", "NewSavePath", 1, szPath, nSize) && GetLastError() == 2
        && SRegLoadString("Diablo II", "Save Path", 0, szSavePath, 0x104))
    {
        const size_t nLength = strlen(szSavePath);
        if (szSavePath[nLength - 1] == '\\')
        {
            szSavePath[nLength - 1] = 0;
        }
        const unsigned long dwAttributes = GetFileAttributesA(szSavePath);
        if (dwAttributes != (unsigned long)-1 && (dwAttributes & 0x10))
        {
            if (ERRORMANAGER_GetDefaultSavePath(szNewPath, 0x104))
            {
                if (ERRORMANAGER_MoveDirectoryTree(szSavePath, szNewPath) == 1)
                {
                    SStrCopy(szPath, szSavePath, nSize);
                }
                else
                {
                    AppendPathSeparator_Inl(szNewPath, 0x104);
                    SRegSaveString("Diablo II", "NewSavePath", 1, szNewPath);
                    SStrCopy(szPath, szNewPath, nSize);
                }
            }
        }
    }
    if (GetFileAttributesA(szPath) == (unsigned long)-1)
    {
        szPath[0] = 0;
    }
    if (!szPath[0])
    {
        ERRORMANAGER_GetDefaultSavePath(szPath, nSize);
        AppendPathSeparator_Inl(szPath, nSize);
        SRegSaveString("Diablo II", "NewSavePath", 1, szPath);
    }
    if (!AppendPathSeparator_Inl(szPath, nSize))
    {
        return 0;
    }
    return FOG_CreatePathHierarchy(szPath);
}

// 0x00407260
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

// 0x00407370
int __fastcall ERRORMANAGER_GetJulianDay(int nYear, int nMonth, int nDay)
{
    int nJulYear = nYear;
    if (nJulYear == 0)
    {
        return 0;
    }
    if (nJulYear < 0)
    {
        ++nJulYear;
    }
    int nJulMonth;
    if (nMonth > 2)
    {
        nJulMonth = nMonth + 1;
    }
    else
    {
        --nJulYear;
        nJulMonth = nMonth + 13;
    }
    int nJul = (int)(floor(gdDaysPerYear * nJulYear) + floor(gdDaysPerMonth * nJulMonth) + nDay + 1720995.0);
    if (nDay + 31 * (nMonth + 12 * nYear) >= 588829)
    {
        const int nAdjust = (int)(0.01 * nJulYear);
        nJul += 2 - nAdjust - (int)((-0.25) * nAdjust);
    }
    return nJul;
}

// 0x00407570
void __fastcall ERRORMANAGER_DeleteOldDatedLogs(const char* szPrefix)
{
    D2SystemTimeStrc tTime;
    char szDir[0x1000];
    char szFile[0x1000];
    GetLocalTime(&tTime);
    szDir[0] = 0;
    if (EXCEPTIONS_GetAppPath(szDir, 0x1000))
    {
        SStrPack(szDir, "\\", 0x1000);
        FOG_CreatePathHierarchy(szDir);
    }
    int nYear = tTime.wYear;
    int nMonth = tTime.wMonth;
    int nDay = tTime.wDay;
    int nJulianDay = ERRORMANAGER_GetJulianDay(nYear, nMonth, nDay) - 5;
    for (int i = 0; i < 10; i++)
    {
        ERRORMANAGER_JulianDayToDate(nJulianDay, &nYear, &nMonth, &nDay);
        SStrPrintf(szFile, 0x1000, "%s%s%02d%02d%02d.txt", szDir, szPrefix, nYear % 100, nMonth, nDay);
        DeleteFileA(szFile);
        nJulianDay--;
    }
}

void __stdcall sub_K01_Emit_00407FC0(const char* szPrefix, const char* szText, int bFlag)
{
    ERRORMANAGER_LogPrefixedText(szPrefix, szText, bFlag);
}

// 0x004088C0
int __fastcall ERRORMANAGER_ReportNestedError(const char* szFile, int nLine, const char* szMessage)
{
    if (gbWritingCrashReport)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "\n***** ENCOUNTERED ERROR DURING ERROR HANDLING!!!\n%s,%d\n%s\n*****", ERRORMANAGER_StripSourcePath(szFile), nLine, szMessage);
        return 1;
    }
    return 0;
}

// 0x00413740
void __cdecl sub_00413740_Nop()
{
}

#include "gen/data/Source/Fog/Src/ErrorManager_004016A0.inc"
