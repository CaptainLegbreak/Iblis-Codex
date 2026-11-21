#include "Fog.h"
#include "D2NetTypes.h"
#include "D2FogTypes.h"
#include "D2Primitives.h"

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

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

extern "C" double __cdecl floor(double x); // 0x00683080

extern "C" unsigned long __readfsdword(unsigned long nOffset);

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

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

extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194

extern "C" __declspec(dllimport) void __stdcall CoTaskMemFree(void* pMemory); // 0x006CC5F0

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4

extern "C" int __stdcall Process32First(void* hSnapshot, D2ProcessEntryStrc* pEntry); // 0x006B1440

extern "C" int __stdcall Process32Next(void* hSnapshot, D2ProcessEntryStrc* pEntry); // 0x006B143A

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

void __fastcall sub_00403100_PrintFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nFrames, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6); // 0x00403100

bool __fastcall sub_00404560_UseWidePath(wchar_t* wszPath); // 0x00404560

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** argv); // 0x004065E0

extern "C" const char gszInternalCheckHost_006FF994[]; // 0x006FF994

extern "C" const D2GuidStrc gtKnownFolderId_006CCA6C; // 0x006CCA6C

extern const double gdDaysPerYear_006CCC08; // 0x006CCC08

extern const double gdDaysPerMonth_006CCC10; // 0x006CCC10

extern char gszServiceName_007065DC[]; // 0x007065DC

extern D2ModeEntryStrc gaModeTable_00706554[]; // 0x00706554

extern int gnMode_0074C704; // 0x0074C704

extern void* gpModeContext_0074C718; // 0x0074C718

struct D2FileTimeStrc;

struct D2FindDataStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0

extern int gdwGlobal_008F03C8; // 0x008F03C8

int __stdcall sub_00419980(const char* szFileName, void** phFile); // 0x00419980

int __stdcall sub_0041AAD0_StormReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0

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

unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

int __fastcall sub_00407370_JulianDay(int nYear, int nMonth, int nDay); // 0x00407370

void __fastcall sub_00407440_JulianToDate(long nJulian, int* pYear, int* pMonth, int* pDay); // 0x00407440

int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60

void __stdcall sub_0040EA00_WriteProcessorReport(); // 0x0040EA00

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610

extern int gnOsKind_0074D890; // 0x0074D890

extern float gfOsVersion_0074D894; // 0x0074D894

void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...); // 0x00410740

extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

const char* __fastcall sub_00408000_StripSourcePath(const char* szFile); // 0x00408000

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660

extern int gdwGlobal_0074F0C8; // 0x0074F0C8

D2ModeIfaceStrc* gpModeIface_0074C700; // 0x0074C700

int gbD2ServerStopEvent_0074C720; // 0x0074C720

char szSRegReadBuf[260]; // 0x0074C728

unsigned long gdwTotalPhys_0074D898; // 0x0074D898

// 0x004016A0
void __cdecl sub_004016A0_StartDbgHelpThread()
{
    sub_00402980_StartDbgHelpWorker();
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004016C0
bool __cdecl sub_004016C0_IsInternalCheckLoopback()
{
    D2WSADataStrc tData;
    if (WSAStartup(0x202, &tData))
    {
        return false;
    }
    bool bResult = false;
    D2HostentStrc* pHost = gethostbyname(gszInternalCheckHost_006FF994);
    if (pHost && pHost->h_addrtype == 2 && *(unsigned long*)pHost->h_addr_list[0] == 0x0100007F)
    {
        bResult = true;
    }
    WSACleanup();
    return bResult;
}

// 0x00401A70
void __cdecl sub_00401A70_SetMiniDumpThreadName()
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
void __fastcall sub_00403070_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6, int nArg7)
{
    D2StackFrameStrc aFrames[0x80];
    int nFrames = pThreadContext->sub_00405060_CaptureFrames(dwThreadId, aFrames, nArg7);
    if (nFrames > 0)
    {
        if (nFrames > 0x80)
        {
            nFrames = 0x80;
        }
        sub_00403100_PrintFrames(dwThreadId, aFrames, nFrames, pfnPrint, pContext, nArg5, nArg6);
    }
}

// 0x004045F0
bool __stdcall sub_004045F0_UseUtf8Path(const char* szPath)
{
    wchar_t wszPath[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104))
    {
        return false;
    }
    return sub_00404560_UseWidePath(wszPath);
}

__forceinline D2TebStrc* D2_NtCurrentTeb()
{
    return (D2TebStrc*)__readfsdword(0x18);
}

// 0x00404E60
bool __fastcall sub_00404E60_EnumLoadedModules(void* pContext)
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
int __stdcall sub_004059D0_RunModeInterface(int nArg)
{
    if (gnMode_0074C704 < 1 || gnMode_0074C704 > 5)
    {
        return 0;
    }
    D2_ASSERT(gaModeTable_00706554[gnMode_0074C704].pfnCreate, 307);
    D2_ASSERT(gaModeTable_00706554[gnMode_0074C704].pfnRelease, 308);
    gpModeIface_0074C700 = gaModeTable_00706554[gnMode_0074C704].pfnCreate(gpModeContext_0074C718);
    const int nResult = gpModeIface_0074C700->pfnRun(nArg);
    gaModeTable_00706554[gnMode_0074C704].pfnRelease();
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
    if (gbD2ServerStopEvent_0074C720)
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
    if (gbD2ServerStopEvent_0074C720)
    {
        SetCurrentDirectoryA(szPath);
    }
}

// 0x004061C0
int __cdecl sub_004061C0_DenyProcessAccess()
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
int __cdecl sub_00406650_StartServiceDispatcher()
{
    if (!(GetVersion() & 0x80000000))
    {
        void* hManager = OpenSCManagerA(0, 0, 0xF003F);
        if (hManager)
        {
            void* hService = OpenServiceA(hManager, gszServiceName_007065DC, 0xF01FF);
            if (hService)
            {
                CloseServiceHandle(hService);
            }
            CloseServiceHandle(hManager);
            if (hService)
            {
                D2ServiceTableEntryStrc aTable[] = {
                    { gszServiceName_007065DC, D2ServerServiceMain },
                    { 0, 0 }
                };
                return StartServiceCtrlDispatcherA(aTable) != 0;
            }
        }
    }
    return 0;
}

// 0x004067C0
int __cdecl sub_004067C0_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

// 0x004067D0
bool __stdcall sub_004067D0_GetKnownFolderPathA(char* szPath, int nSize)
{
    void* hShell = GetModuleHandleA("Shell32.dll");
    D2KnownFolderPathFn pfnGet = (D2KnownFolderPathFn)GetProcAddress(hShell, "SHGetKnownFolderPath");
    if (!pfnGet)
    {
        return false;
    }
    wchar_t* wszPath;
    if (pfnGet(&gtKnownFolderId_006CCA6C, 0x8000, 0, &wszPath) < 0)
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
    return gdwGlobal_008F03C8 = (gdwGlobal_008F03C8 == 0);
}

// 0x004068E0
int __fastcall sub_004068E0(const char* szFileName, void** phFile)
{
    return sub_00419980(szFileName, phFile);
}

// 0x00406900
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6)
{
    return sub_0041AAD0_StormReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped, nArg6, nArg7);
}

// 0x00406930
int __fastcall sub_00406930(void* hFile, unsigned int* pnSizeHigh)
{
    return sub_00416370_StormGetFileSize(hFile, pnSizeHigh);
}

// 0x00406940
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod)
{
    return SFileSetFilePointer(hFile, nOffset, pnOffsetHigh, nMethod);
}

// 0x00406A10
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath)
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

// 0x00406C40
int __fastcall sub_00406C40_GetBlizzardDataPath(char* szOutPath, int nSize)
{
    char szPath[0x104];
    if (SHGetFolderPathA(0, 0x1C, 0, 0, szPath) < 0)
        return 0;
    sub_00413800(szPath, "\\Blizzard Entertainment", 0x7FFFFFFF);
    if (!FOG_AppendBackslash(szPath, nSize))
        return 0;
    if (!sub_00406A10_CreateDirectoryTree(szPath))
        return 0;
    SStrCopy(szOutPath, szPath, nSize);
    return SStrLen(szOutPath) == SStrLen(szPath);
}

// 0x00406DE0
int __fastcall sub_00406DE0_MoveDirectoryTree(const char* szSrc, const char* szDst)
{
    char szDir[0x104];
    SStrCopy(szDir, szDst, 0x7FFFFFFF);
    char* pCut = strrchr(szDir, '\\') + 1;
    char cSaved = *pCut;
    *pCut = 0;
    sub_00406A10_CreateDirectoryTree(szDir);
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
        sub_00406A10_CreateDirectoryTree(szDir);
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
                nResult |= sub_00406DE0_MoveDirectoryTree(szSrcFind, szDstFind);
            }
        } while (FindNextFileA(hFind, &tData));
    }
    FindClose(hFind);
    RemoveDirectoryA(szSrc);
    return nResult;
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

void __fastcall sub_0051D350_CopyElement(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
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
int __fastcall sub_00407370_JulianDay(int nYear, int nMonth, int nDay)
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
    int nJul = (int)(floor(gdDaysPerYear_006CCC08 * nJulYear) + floor(gdDaysPerMonth_006CCC10 * nJulMonth) + nDay + 1720995.0);
    if (nDay + 31 * (nMonth + 12 * nYear) >= 588829)
    {
        const int nAdjust = (int)(0.01 * nJulYear);
        nJul += 2 - nAdjust - (int)((-0.25) * nAdjust);
    }
    return nJul;
}

// 0x00407570
void __fastcall sub_00407570_DeleteOldDatedLogs(const char* szPrefix)
{
    D2SystemTimeStrc tTime;
    char szDir[0x1000];
    char szFile[0x1000];
    GetLocalTime(&tTime);
    szDir[0] = 0;
    if (sub_0040C220_GetAppPath(szDir, 0x1000))
    {
        sub_00413800(szDir, "\\", 0x1000);
        sub_00406A10_CreateDirectoryTree(szDir);
    }
    int nYear = tTime.wYear;
    int nMonth = tTime.wMonth;
    int nDay = tTime.wDay;
    int nJulianDay = sub_00407370_JulianDay(nYear, nMonth, nDay) - 5;
    for (int i = 0; i < 10; i++)
    {
        sub_00407440_JulianToDate(nJulianDay, &nYear, &nMonth, &nDay);
        SStrPrintf(szFile, 0x1000, "%s%s%02d%02d%02d.txt", szDir, szPrefix, nYear % 100, nMonth, nDay);
        DeleteFileA(szFile);
        nJulianDay--;
    }
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

// 0x004076B0
void __cdecl sub_004076B0_LogSystemInfo()
{
    D2SystemTimeStrc tTime;
    unsigned long nSize;
    char szPath[0x1000];
    char szOs[0x1000];
    char szComputer[0x40];

    sub_00410610_WriteLogLine("------------------------------------------------------");
    GetLocalTime(&tTime);
    sub_00410610_WriteLogLine("%04d-%02d-%02d %02d:%02d:%02d", tTime.wYear, tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond);

    switch (gnOsKind_0074D890)
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

    sub_00410610_WriteLogLine("%s running under %s (Version %.3f)", "Diablo II", szOs, gfOsVersion_0074D894);
    sub_0040EA00_WriteProcessorReport();
    sub_00410610_WriteLogLine("Total Physical Memory: %.2fMB", (float)gdwTotalPhys_0074D898 / 1048576.0);

    if (sub_0040C220_GetAppPath(szPath, sizeof(szPath)))
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

// 0x00407990
unsigned long __fastcall sub_00407990_FindOwnerProcess(unsigned long dwProcessId)
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

// 0x00407F80
void __fastcall sub_00407F80_ThreadHookNop2(unsigned int nId, void* hThread)
{
}

// 0x00407F90
void __fastcall sub_00407F90_ThreadHookNop1(unsigned int nId)
{
}

// 0x00407FC0
static void __stdcall sub_00407FC0_LogPrefixedText(const char* szPrefix, const char* szText, int bFlag)
{
    if (bFlag)
    {
        sub_004106B0_LogWritePrefixed0(szPrefix, gszPercentS_006FFC58, szText);
    }
    else
    {
        sub_00410740_LogWritePrefixed00(szPrefix, gszPercentS_006FFC58, szText);
    }
}

void __stdcall sub_K01_Emit_00407FC0(const char* szPrefix, const char* szText, int bFlag)
{
    sub_00407FC0_LogPrefixedText(szPrefix, szText, bFlag);
}

// 0x004088C0
int __fastcall sub_004088C0_ReportNestedError(const char* szFile, int nLine, const char* szMessage)
{
    if (gdwGlobal_0074F0C8)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "\n***** ENCOUNTERED ERROR DURING ERROR HANDLING!!!\n%s,%d\n%s\n*****", sub_00408000_StripSourcePath(szFile), nLine, szMessage);
        return 1;
    }
    return 0;
}

// 0x00413740
void __cdecl sub_00413740_Nop()
{
}

#include "gen/data/Source/Fog/Src/ErrorManager_004016A0.inc"
