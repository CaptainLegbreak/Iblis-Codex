// build: context sub_00406BA0_GetModuleDirectoryAndSave

typedef unsigned int size_t;

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

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode);    // 0x006CC274
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) void* __stdcall CreateFileW(const wchar_t* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC298
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) D2ExceptionFilterFn __stdcall SetUnhandledExceptionFilter(D2ExceptionFilterFn pfnFilter); // 0x006CC2B4
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryW(const wchar_t* szPath, void* pSecurityAttributes); // 0x006CC2C8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesW(const wchar_t* szFileName);     // 0x006CC2B8
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);       // 0x006CC1B0

extern "C" wchar_t* __cdecl wcsrchr(const wchar_t* szString, wchar_t nChar);                                // 0x00685DF7
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
const char* __stdcall SStrChrR(const char* szString, char nChar);                                           // 0x004134D0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
long __stdcall sub_00403E90_UnhandledExceptionFilter(void* pExceptionPointers);                             // 0x00403E90
void __fastcall sub_0040F5A0_SetLogPrefix(const char* szName);                                              // 0x0040F5A0
void __cdecl sub_0040F8A0_CloseLogFilesNow();                                                               // 0x0040F8A0

char gszTextBuffer_0098A280[0x400];                                                                         // 0x0098A280
extern bool gbMiniDumpEnabled_0098A6B1;                                                                     // 0x0098A6B1
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
extern D2CriticalSectionStrc gtDbgHelpRequestLock_0098A6C4;                                                 // 0x0098A6C4
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern void* ghDbgHelpWorkEvent_0098A6C0;                                                                   // 0x0098A6C0
extern void* ghDbgHelpDoneEvent_0098A6BC;                                                                   // 0x0098A6BC
extern void* gpDbgHelpRequest_0098A6E4;                                                                     // 0x0098A6E4
extern void* gpfnCrashHandler_00992B10;                                                                     // 0x00992B10
void* gpCrashContext_00992B14;                                                                              // 0x00992B14
D2ExceptionFilterFn gpfnPreviousFilter_00992B18;                                                            // 0x00992B18
extern T004013C0 gtSystemInfo_0074D88C;                                                              // 0x0074D88C
int gnSourcePrefixLength_0074F0D4;                                                                          // 0x0074F0D4

// 0x004013C0
void __fastcall sub_004013C0_TerminateCurrentProcess(unsigned int nExitCode)
{
    TerminateProcess(GetCurrentProcess(), nExitCode);
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

// 0x0040F960
void __cdecl sub_0040F960_CloseLogFiles()
{
    sub_0040F8A0_CloseLogFilesNow();
}
