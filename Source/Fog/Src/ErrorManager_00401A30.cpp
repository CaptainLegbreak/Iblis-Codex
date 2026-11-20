#include "D2GameTypes.h"
#include "D2NetTypes.h"
typedef unsigned int size_t;
typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

struct _iobuf;

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
    char unk0x08[0x34];
    void* ptBuffer;
    unsigned int nFileSize;
    unsigned int nPriority;
    unsigned int dwFlags;
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

struct D2FdSetStrc
{
    unsigned int fd_count;
    unsigned int fd_array[64];
};

union D2LargeIntegerStrc
{
    struct
    {
        unsigned long LowPart;
        long HighPart;
    };
    __int64 QuadPart;
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// build: symbol _strrchr 0x00682990
extern "C" char* __cdecl strrchr(const char* szString, int nChar);
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1
extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22
extern "C" void* __cdecl malloc(size_t nSize);                                                              // 0x00683EFD
extern "C" _iobuf* __cdecl _wfopen(const wchar_t* szFileName, const wchar_t* szMode);                       // 0x00685EED

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();                             // 0x006CC1EC
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) void* __stdcall OpenProcess(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwProcessId); // 0x006CC1E8
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int nVirtualKey);                         // 0x006CC460
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();                                        // 0x006CC24C
extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);                            // 0x006CC268
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount);         // 0x006CC25C
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(D2LargeIntegerStrc* pFrequency);   // 0x006CC254
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
extern "C" int __stdcall getsockname(unsigned int nSocket, void* pAddress, int* pnLength);                 // 0x006B0144
extern "C" int __stdcall ioctlsocket(unsigned int nSocket, long nCommand, unsigned long* pArgument);       // 0x006B015C

void __fastcall sub_00403070_DumpThread(unsigned long dwThreadId, int nArg2, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6, int nArg7); // 0x00403070
const char* __fastcall sub_00408000_StripSourcePath(const char* szFile);                                    // 0x00408000
void __cdecl sub_00409020_LogPoolError(const char* szFormat, ...);                                          // 0x00409020
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660
unsigned __int64 __cdecl sub_0040E850_ReadTimeStampCounter(); // 0x0040E850

extern D2CriticalSectionStrc gtSymbolLock_0098A6F0;                                                         // 0x0098A6F0
extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0
extern D2CmdArgStrc gaCmdArguments[58];                                                                     // 0x00705040
extern D2ServiceStatusStrc gD2ServerServiceStatus;                                                          // 0x007065FC
void* ghD2ServerServiceStatus;                                                                              // 0x0074C714
extern int gbD2ServerStopEvent;                                                                             // 0x007065C0
extern int gdwGlobal_0074F0C8;                                                                              // 0x0074F0C8
extern unsigned char gabHuffmanCodeLength_007076C0[256];                                                    // 0x007076C0
unsigned char gabHuffmanCode_0075B6A0[256];                                                                 // 0x0075B6A0
const unsigned char* gapHuffmanDecode_0075AFA0[256];                                                        // 0x0075AFA0
extern unsigned int gadwHuffmanMask_007077C0[32];                                                           // 0x007077C0

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

// 0x00409770
void* __fastcall sub_00409770_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    int* pBlock = (int*)malloc(nSize + 4);
    if (!pBlock)
    {
        sub_00409020_LogPoolError("(3) Pool Blocks overflowed at %d", pSystem->nLargeOverflow);
        D2_ASSERT(pBlock, 904);
    }
    const int nBucket = (int)pBlock % 1023;
    EnterCriticalSection(&pSystem->tLock);
    *pBlock = (int)pSystem->apLargeBlocks[nBucket];
    pSystem->apLargeBlocks[nBucket] = pBlock;
    LeaveCriticalSection(&pSystem->tLock);
    return pBlock + 1;
}

// 0x0040AA80
void __fastcall sub_0040AA80_AsyncDataReplaceBuffer(AsyncData* ptAsyncData, int nUnused, void* pBuffer, unsigned int nBufferSize)
{
    D2_ASSERT(ptAsyncData, 638);
    D2_ASSERT((ptAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 639);
    D2_ASSERT(ptAsyncData->dwFlags & 1, 641);
    FOG_FreePool(ptAsyncData->pMemPool, ptAsyncData->ptBuffer, ".\\Src\\AsyncData.cpp", 644, 0);
    ptAsyncData->ptBuffer = pBuffer;
    ptAsyncData->nFileSize = nBufferSize;
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
    const int nResult = getsockname(pSafeSock->nSocket, pAddress, pnLength);
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
    D2LargeIntegerStrc tCount1;
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
    D2LargeIntegerStrc tCount2;
    QueryPerformanceCounter(&tCount2);
    const __int64 nTsc2 = sub_0040E850_ReadTimeStampCounter();
    GetTickCount();
    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (int)((nTsc2 - nTsc1) * tFrequency.QuadPart / (tCount2.QuadPart - tCount1.QuadPart) / 1000000);
}

#include "gen/data/Source/Fog/Src/ErrorManager_00401A30.inc"
