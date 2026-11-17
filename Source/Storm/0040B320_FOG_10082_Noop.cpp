typedef unsigned int size_t;

struct _iobuf;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
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

struct D2InAddrStrc
{
    unsigned long s_addr;
};

struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    D2TSLinkStrc* pNext;

    D2TSLinkStrc* NextLink(int nLinkOffset)
    {
        const int nNext = (int)pNext;
        if (nNext < 0)
        {
            return (D2TSLinkStrc*)~nNext;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        }
        return (D2TSLinkStrc*)(nNext + nLinkOffset);
    }

    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    D2TSLinkStrc* Head()
    {
        return (int)tTerminator.pNext > 0 ? tTerminator.pNext : 0;
    }

    void sub_0040FD00_UnlinkAll();
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pnThreadId); // 0x006CC250
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pTime);                      // 0x006CC1D4

extern "C" int __stdcall closesocket(unsigned int nSocket);                                                 // 0x006B012C
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned long __stdcall sub_004101C0_LogThreadProc(void* pParam);                                           // 0x004101C0

char gszAddressText_0075D020[32];                                                                           // 0x0075D020
extern char gaszLogNames_0075D148[20][0x10];                                                                // 0x0075D148
extern D2SystemTimeStrc gLogStartTime_0075D288;                                                             // 0x0075D288
int ganLogNewFile_0075D298[20];                                                                             // 0x0075D298
extern void* ghLogThread_0075D2E8;                                                                          // 0x0075D2E8
int gbLogInitialized_0075D2EC;                                                                              // 0x0075D2EC
char gaszLogFilePaths_0075D340[20][0x104];                                                                  // 0x0075D340
extern _iobuf* gapLogFiles_0075E790[20];                                                                    // 0x0075E790
extern int gbLogThreadStop_0075E830;                                                                        // 0x0075E830
unsigned long gnLogThreadId_0075E834;                                                                       // 0x0075E834
extern D2CriticalSectionStrc gtLogQueueLock_0075E838;                                                       // 0x0075E838
extern D2CriticalSectionStrc gtLogLock_0075E850;                                                            // 0x0075E850
int gnLogQueueCount_0075E870;                                                                               // 0x0075E870

// 0x0040B320
void __cdecl FOG_10082_Noop()
{
}

// 0x0040C220
int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize)
{
    szPath[0] = 0;
    if (!GetModuleFileNameA(0, szPath, nSize))
    {
        return 0;
    }
    int i;
    for (i = (int)strlen(szPath) - 1; i > 0; i--)
    {
        if (szPath[i] == '\\' || szPath[i] == '/' || szPath[i] == ':')
        {
            break;
        }
    }
    if (i <= 0)
    {
        return 0;
    }
    if (szPath[i] == ':')
    {
        i += 1;
    }
    szPath[i] = 0;
    return 1;
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

// 0x0040E080
char* __fastcall sub_0040E080_AddressToString(int nAddress)
{
    D2InAddrStrc tAddress;
    tAddress.s_addr = nAddress;
    return strcpy(gszAddressText_0075D020, inet_ntoa(tAddress));
}

// 0x0040EB90
unsigned int __fastcall sub_0040EB90_GetLogFiles(char** apszFiles, unsigned int nCount)
{
    unsigned int i;
    for (i = 0; i < nCount; i++)
    {
        if (i >= 20)
        {
            break;
        }
        apszFiles[i] = gaszLogFilePaths_0075D340[i];
    }
    return i;
}

// 0x0040F470
void __fastcall sub_0040F470_LookupLog(const char* szName)
{
    for (int i = 0; i < 20; i++)
    {
        if (gapLogFiles_0075E790[i] && !strcmp(gaszLogNames_0075D148[i], szName))
        {
            if (gapLogFiles_0075E790[i])
            {
                fclose(gapLogFiles_0075E790[i]);
                gapLogFiles_0075E790[i] = 0;
            }
            return;
        }
    }
}

// 0x0040F8A0
void __cdecl sub_0040F8A0_CloseLogFilesNow()
{
    D2_ASSERT(gbLogInitialized_0075D2EC, 456);
    const unsigned long dwStart = GetTickCount();
    while (GetTickCount() - dwStart < 1000)
    {
        EnterCriticalSection(&gtLogQueueLock_0075E838);
        const int nQueued = gnLogQueueCount_0075E870 > 0 ? gnLogQueueCount_0075E870 : 0;
        LeaveCriticalSection(&gtLogQueueLock_0075E838);
        if (!nQueued)
        {
            break;
        }
        Sleep(10);
    }
    for (int i = 0; i < 20; i++)
    {
        EnterCriticalSection(&gtLogLock_0075E850);
        if (gapLogFiles_0075E790[i])
        {
            fclose(gapLogFiles_0075E790[i]);
            gapLogFiles_0075E790[i] = 0;
        }
        LeaveCriticalSection(&gtLogLock_0075E850);
    }
}

// 0x0040FD00
void D2TSListStrc::sub_0040FD00_UnlinkAll()
{
    D2TSLinkStrc* pNode;
    while ((pNode = Head()) != 0)
    {
        pNode->Unlink();
    }
}

// 0x00410540
void __cdecl sub_00410540_InitLogSystem()
{
    gbLogThreadStop_0075E830 = 0;
    ghLogThread_0075D2E8 = CreateThread(0, 0, sub_004101C0_LogThreadProc, 0, 0, &gnLogThreadId_0075E834);
    gbLogInitialized_0075D2EC = 1;
    GetLocalTime(&gLogStartTime_0075D288);
    for (unsigned int i = 0; i < 20; i++)
    {
        ganLogNewFile_0075D298[i] = 1;
    }
    for (unsigned int i = 0; i < 20; i++)
    {
        gaszLogFilePaths_0075D340[i][0] = 0;
    }
}
