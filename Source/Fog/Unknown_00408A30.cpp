#include "Fog.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct T00408A30
{
    void* pMemory;
    char unk0x04[0x0C];
    T00408A30* pNext;
};

struct T00408A30_2
{
    D2CriticalSectionStrc tLock;
    char unk0x18[0x10];
    T00408A30* pFirstBlock;
    int nUnk0x2C;
};

struct D2PoolSystemStrc
{
    int bFreePoolAlloc;
    D2CriticalSectionStrc tLock;
    int nPools;
    T00408A30_2 aPools[40];
    int nLargeOverflow;
    int nUnk0x7A4;
    void* pUnk0x7A8;
    int* apLargeBlocks[1023];
    int nCount;
    char unk0x17AC[0x20];
};

struct T00408A30_1
{
    int bInit;
    D2CriticalSectionStrc tLock;
    D2PoolSystemStrc aSystems[8];
    int nUnk0xBE7C;
    unsigned int anFreeIndex[8];
    int nFreeCount;
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

struct D2WSADataStrc
{
    char data[0x190];
};

struct D2InAddrStrc
{
    unsigned long s_addr;
};

struct D2SockAddrInStrc
{
    short sin_family;
    unsigned short sin_port;
    D2InAddrStrc sin_addr;
    char sin_zero[8];
};

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

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);  // 0x006CC1C8
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1C4
extern "C" int __stdcall closesocket(unsigned int nSocket);                                                 // 0x006B012C
extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData);                // 0x006B0132
extern "C" int __stdcall WSACleanup();                                                                      // 0x006B0138
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" unsigned short __stdcall htons(unsigned short nValue);                                           // 0x006B0156
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol);                            // 0x006B016E
extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags);                // 0x006B0174
extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags);          // 0x006B017A
extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName);                                      // 0x006B0192
extern "C" int __stdcall gethostname(char* szName, int nNameLength);                                        // 0x006B0198

void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960
void __cdecl sub_0040F8A0_CloseLogFilesNow();                                                               // 0x0040F8A0
void __fastcall sub_0040F000_GetLogDirectory(char* szDirectory, int nSize);                                 // 0x0040F000
void __fastcall sub_0040F3D0_SweepLogFile(const D2FileTimeStrc* pNow, const char* szFile);                  // 0x0040F3D0
int __cdecl SStrPrintf(char* szDest, size_t nSize, const char* szFormat, ...);                              // 0x00413A40
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
T00408A30_1 gtPoolManager_0074F0E8;                                                                   // 0x0074F0E8
extern char gszResolvedHostIP_0075D040[];                                                                   // 0x0075D040
extern D2CriticalSectionStrc gtLogLock_0075E850;                                                            // 0x0075E850
unsigned long gdwLastLogSweep_0075E874;                                                                     // 0x0075E874

// 0x00408A30
void __cdecl FOG_DisplayAssert(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(5, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}

// 0x00408A90
void __cdecl FOG_DisplayWarning(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(7, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}

// 0x00408AC0
void __cdecl sub_00408AC0_DisplayDeadlock(unsigned long dwThreadId, int nTicks)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(10, (const char*)dwThreadId, 2175, "Deadlocked in thread %X for %d ticks", dwThreadId, nTicks);
    sub_0040F960_CloseLogFiles();
}

// 0x00408AF0
void __cdecl FOG_DisplayError(int nCategory, const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(nCategory, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}

// 0x00409C80
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!gtPoolManager_0074F0E8.bInit)
    {
        return;
    }
    if (!pSystem)
    {
        pSystem = &gtPoolManager_0074F0E8.aSystems[0];
    }
    if (!pSystem->nPools)
    {
        return;
    }
    for (int i = 0; i < pSystem->nPools; i++)
    {
        T00408A30_2* pPool = &pSystem->aPools[i];
        T00408A30* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            T00408A30* pNext = pBlock->pNext;
            VirtualFree(pBlock->pMemory, 0, 0x8000);
            free(pBlock);
            pBlock = pNext;
        }
        DeleteCriticalSection(&pPool->tLock);
    }
    free(pSystem->pUnk0x7A8);
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
    EnterCriticalSection(&gtPoolManager_0074F0E8.tLock);
    gtPoolManager_0074F0E8.anFreeIndex[gtPoolManager_0074F0E8.nFreeCount] = ((unsigned int)pSystem - (unsigned int)&gtPoolManager_0074F0E8.aSystems[0]) / sizeof(D2PoolSystemStrc);
    gtPoolManager_0074F0E8.nFreeCount++;
    LeaveCriticalSection(&gtPoolManager_0074F0E8.tLock);
    if (pSystem == &gtPoolManager_0074F0E8.aSystems[0])
    {
        gtPoolManager_0074F0E8.bInit = 0;
        DeleteCriticalSection(&gtPoolManager_0074F0E8.tLock);
    }
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
    sprintf(gszResolvedHostIP_0075D040, gszStringFormat_006FFC58, inet_ntoa(tLocal.sin_addr));
    WSACleanup();
    return gszResolvedHostIP_0075D040;
}

// 0x0040EBD0
_iobuf* __fastcall sub_0040EBD0_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize)
{
    char szPath[0x104];
    GetLocalTime(pTime);
    SStrPrintf(szPath, sizeof(szPath), "%s%s%02d%02d%02d.txt", gszLogPrefix_00708018, szName, pTime->wYear % 100, pTime->wMonth, pTime->wDay);
    if (szPathOut)
    {
        SStrCopy(szPathOut, szPath, nPathOutSize);
    }
    if (pbNew)
    {
        *pbNew = 1;
        if (*szMode == 'a')
        {
            _iobuf* pFile = fopen(szPath, "r");
            if (pFile)
            {
                fclose(pFile);
                *pbNew = 0;
            }
        }
    }
    return fopen(szPath, szMode);
}

// 0x0040F970
void __cdecl sub_0040F970_SweepOldLogFiles()
{
    if (gdwLastLogSweep_0075E874 && GetTickCount() - gdwLastLogSweep_0075E874 < 86400000)
    {
        return;
    }
    gdwLastLogSweep_0075E874 = GetTickCount();
    LeaveCriticalSection(&gtLogLock_0075E850);
    sub_0040F8A0_CloseLogFilesNow();
    EnterCriticalSection(&gtLogLock_0075E850);
    D2SystemTimeStrc tNow;
    GetLocalTime(&tNow);
    D2FileTimeStrc ftNow;
    SystemTimeToFileTime(&tNow, &ftNow);
    char szDirectory[0x104];
    sub_0040F000_GetLogDirectory(szDirectory, sizeof(szDirectory));
    char szPattern[0x104];
    SStrPrintf(szPattern, sizeof(szPattern), "%sd2*.txt", szDirectory);
    D2FindDataStrc tFind;
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        do
        {
            char szFile[0x104];
            SStrPrintf(szFile, sizeof(szFile), "%s%s", szDirectory, tFind.cFileName);
            sub_0040F3D0_SweepLogFile(&ftNow, szFile);
        }
        while (FindNextFileA(hFind, &tFind));
        FindClose(hFind);
    }
}

// 0x00410CF0
void __stdcall sub_00410CF0_NotBits(const unsigned char* pIn, unsigned char* pOut, int nBits)
{
    const int nBytes = (nBits + 7) / 8;
    const int nAligned = 4 * (nBytes / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = ~*(const int*)&pIn[i];
    }
    switch (nBytes - nAligned)
    {
    case 3:
        pOut[i + 2] = ~pIn[i + 2];
    case 2:
        pOut[i + 1] = ~pIn[i + 1];
    case 1:
        pOut[i] = ~pIn[i];
    }
}

// 0x00411320
void __stdcall sub_00411320_CapitalizeWords(char* szText)
{
    int bNewWord = 1;
    if (!szText)
    {
        return;
    }
    int i = 0;
    const int nLength = strlen(szText);
    while (i < nLength)
    {
        D2_ASSERT(i < 0x400, 120);
        const char c = szText[i];
        if (c == ' ')
        {
            bNewWord = 1;
            ++i;
            continue;
        }
        if (bNewWord)
        {
            bNewWord = 0;
            szText[i] = toupper(c);
        }
        else
        {
            szText[i] = tolower(c);
        }
        ++i;
    }
}

#include "gen/data/Source/Fog/Unknown_00408A30.inc"
