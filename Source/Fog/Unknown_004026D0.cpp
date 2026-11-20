#include "D2GameTypes.h"

struct D2MiniDumpExceptionInfoStrc
{
    unsigned long dwThreadId;
    void* pExceptionPointers;
    int bClientPointers;
};

struct D2MiniDumpUserStreamStrc
{
    unsigned long dwType;
    unsigned long dwBufferSize;
    void* pBuffer;
};

struct D2MiniDumpUserStreamInfoStrc
{
    unsigned long dwUserStreamCount;
    D2MiniDumpUserStreamStrc* pUserStreamArray;
};

struct D2MiniDumpRequestInfoStrc
{
    void* pExceptionPointers;
    unsigned long dwThreadId;
    char* szComment;
};

struct D2MiniDumpRequestStrc
{
    void* hFile;
    D2MiniDumpRequestInfoStrc tInfo;
    bool bResult;
};

typedef int (__stdcall* D2MiniDumpWriteDumpFn)(void* hProcess, unsigned long dwProcessId, void* hFile, int nDumpType, D2MiniDumpExceptionInfoStrc* pExceptionParam, D2MiniDumpUserStreamInfoStrc* pUserStreamParam, void* pCallbackParam);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId(); // 0x006CC1EC
extern "C" unsigned int __cdecl strlen(const char* szString);

extern D2MiniDumpWriteDumpFn gpfnMiniDumpWriteDump_0098A6E0; // 0x0098A6E0
extern D2MiniDumpRequestStrc* gpMiniDumpRequest_0098A6E4; // 0x0098A6E4
extern D2CriticalSectionStrc gtSymbolLock_0098A6F0; // 0x0098A6F0
extern void* ghProcess_0074C6F0; // 0x0074C6F0

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock_0098A6F0);
}

// build: context D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: context D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
struct D2SymbolLockGuardStrc
{
    D2SymbolLockGuardStrc() { EnterCriticalSection(&gtSymbolLock_0098A6F0); }
    ~D2SymbolLockGuardStrc() { LeaveCriticalSection(&gtSymbolLock_0098A6F0); }
};

// 0x004026D0
void __cdecl sub_004026D0_WriteMiniDump()
{
    D2MiniDumpRequestStrc* pRequest = gpMiniDumpRequest_0098A6E4;
    D2MiniDumpRequestInfoStrc* pInfo = &gpMiniDumpRequest_0098A6E4->tInfo;
    D2MiniDumpExceptionInfoStrc tExceptionInfo;
    tExceptionInfo.dwThreadId = gpMiniDumpRequest_0098A6E4->tInfo.dwThreadId;
    tExceptionInfo.pExceptionPointers = gpMiniDumpRequest_0098A6E4->tInfo.pExceptionPointers;

    D2MiniDumpUserStreamStrc tStream;
    D2MiniDumpUserStreamInfoStrc tStreamInfo;
    unsigned long dwCount = 0;
    tExceptionInfo.bClientPointers = 0;
    char* szComment = gpMiniDumpRequest_0098A6E4->tInfo.szComment;
    if (szComment)
    {
        tStream.dwType = 0x1000;
        tStream.dwBufferSize = strlen(szComment) + 1;
        tStream.pBuffer = szComment;
        dwCount = 1;
    }
    tStreamInfo.dwUserStreamCount = dwCount;
    tStreamInfo.pUserStreamArray = &tStream;

    D2SymbolLockGuardStrc tLock;
    if (!gpfnMiniDumpWriteDump_0098A6E0)
    {
        pRequest->bResult = false;
    }
    else
    {
        pRequest->bResult = gpfnMiniDumpWriteDump_0098A6E0(ghProcess_0074C6F0, GetCurrentProcessId(), pRequest->hFile, 0x40,
            pInfo->pExceptionPointers ? &tExceptionInfo : 0, &tStreamInfo, 0) != 0;
    }
}
