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

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();                                         // 0x006CC284
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) void* __stdcall CreateFileW(const wchar_t* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC298
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
extern bool gbMiniDumpEnabled_0098A6B1;                                                                     // 0x0098A6B1
D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                                // 0x0098A6F0
extern D2CriticalSectionStrc gtDbgHelpRequestLock_0098A6C4;                                                 // 0x0098A6C4
extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern void* ghDbgHelpWorkEvent_0098A6C0;                                                                   // 0x0098A6C0
extern void* ghDbgHelpDoneEvent_0098A6BC;                                                                   // 0x0098A6BC
extern void* gpDbgHelpRequest_0098A6E4;                                                                     // 0x0098A6E4

// 0x004013A0
int __cdecl sub_004013A0_IsDebuggerAttached()
{
    return !(IsDebuggerPresent() - 1);
}

// 0x00402820
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
    void* hFile = CreateFileW(wszPath, 0x40000000, 3, 0, 2, 0x80, 0);
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
