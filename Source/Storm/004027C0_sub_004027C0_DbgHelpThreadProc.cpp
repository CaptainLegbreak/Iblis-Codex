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

struct D2ThreadContextStrc
{
    unsigned long dwContextFlags;
    char unk0x04[0xB4];
    unsigned long dwEip;
    char unk0xBC[0x08];
    unsigned long dwEsp;
    char unk0xC8[0x204];
};

struct D2ExceptionPointersStrc
{
    void* pExceptionRecord;
    D2ThreadContextStrc* pContextRecord;
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();                                        // 0x006CC24C
extern "C" __declspec(dllimport) int __stdcall DuplicateHandle(void* hSourceProcess, void* hSource, void* hTargetProcess, void** phTarget, unsigned long dwAccess, int bInherit, unsigned long dwOptions); // 0x006CC248
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin);                                     // 0x00684A2A
extern "C" long __cdecl ftell(_iobuf* pFile);                                                               // 0x00684935
extern "C" size_t __cdecl fread(void* pBuffer, size_t nSize, size_t nCount, _iobuf* pFile);                 // 0x00684782
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40

void __cdecl sub_00401A70_SetMiniDumpThreadName();                                                          // 0x00401A70
void __cdecl sub_004026D0_LockedDbgHelpCall();                                                              // 0x004026D0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __fastcall sub_0040CC10_WalkThreadStack(void* hThread, D2ThreadContextStrc* pContext);                 // 0x0040CC10
_iobuf* __fastcall sub_0040EBD0_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize); // 0x0040EBD0
void __fastcall sub_0040F000_GetLogDirectory(char* szDirectory, int nSize);                                 // 0x0040F000
void __fastcall sub_0040F470_LookupLog(const char* szName);                                                 // 0x0040F470
void __cdecl sub_00410040_LogMemoryDump(const char* szPrefix, const char* szTitle, unsigned long dwAddress, unsigned int nSize, int nArg5, int nArg6, int nArg7); // 0x00410040
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...);              // 0x00410740

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern char gszLogPrefix_00708018[];                                                                        // 0x00708018
extern int gbImageHlpLoaded_0075D014;                                                                       // 0x0075D014
D2CriticalSectionStrc gtLogLock_0075E850;                                                                   // 0x0075E850
extern void* ghDbgHelpDoneEvent_0098A6BC;                                                                   // 0x0098A6BC
extern void* ghDbgHelpWorkEvent_0098A6C0;                                                                   // 0x0098A6C0
void* gpDbgHelpRequest_0098A6E4;                                                                            // 0x0098A6E4

// 0x004027C0
unsigned long __stdcall sub_004027C0_DbgHelpThreadProc(void* pParam)
{
    volatile int nDummy = 0;
    nDummy;
    sub_00401A70_SetMiniDumpThreadName();
    WaitForSingleObject(ghDbgHelpWorkEvent_0098A6C0, 0xFFFFFFFF);
    while (gpDbgHelpRequest_0098A6E4)
    {
        sub_004026D0_LockedDbgHelpCall();
        SetEvent(ghDbgHelpDoneEvent_0098A6BC);
        WaitForSingleObject(ghDbgHelpWorkEvent_0098A6C0, 0xFFFFFFFF);
    }
    return 0;
}

// 0x0040ABF0
void __fastcall sub_0040ABF0_HeapSiftDown(int* pHeap, int nCount, int nIndex)
{
    int nValue = pHeap[nIndex];
    int nHalf = nCount / 2;
    nCount -= 1;
    while (nIndex < nHalf)
    {
        int nChild = 2 * nIndex + 1;
        if (nChild < nCount && pHeap[nChild] < pHeap[nChild + 1])
            nChild += 1;
        if (nValue > pHeap[nChild])
            break;
        pHeap[nIndex] = pHeap[nChild];
        nIndex = nChild;
    }
    pHeap[nIndex] = nValue;
}

// 0x0040ACA0
void __fastcall sub_0040ACA0_CalcCodeLengths(int* pA, int nCount)
{
    int nRoot, nLeaf, nNext, nAvail, nUsed, nDepth;
    if (nCount == 0)
        return;
    if (nCount == 1)
    {
        pA[0] = 0;
        return;
    }
    pA[0] += pA[1];
    nRoot = 0;
    nLeaf = 2;
    for (nNext = 1; nNext < nCount - 1; nNext++)
    {
        if (nLeaf >= nCount || pA[nRoot] < pA[nLeaf])
        {
            pA[nNext] = pA[nRoot];
            pA[nRoot++] = nNext;
        }
        else
            pA[nNext] = pA[nLeaf++];
        if (nLeaf >= nCount || (nRoot < nNext && pA[nRoot] < pA[nLeaf]))
        {
            pA[nNext] += pA[nRoot];
            pA[nRoot++] = nNext;
        }
        else
            pA[nNext] += pA[nLeaf++];
    }
    pA[nCount - 2] = 0;
    for (nNext = nCount - 3; nNext >= 0; nNext--)
        pA[nNext] = pA[pA[nNext]] + 1;
    nAvail = 1;
    nUsed = nDepth = 0;
    nRoot = nCount - 2;
    nNext = nCount - 1;
    while (nAvail > 0)
    {
        while (nRoot >= 0 && pA[nRoot] == nDepth)
        {
            nUsed++;
            nRoot--;
        }
        while (nAvail > nUsed)
        {
            pA[nNext--] = nDepth;
            nAvail--;
        }
        nAvail = 2 * nUsed;
        nDepth++;
        nUsed = 0;
    }
}

// 0x0040B540
void __fastcall sub_0040B540_DumpThreadStackAndCode(void* hThread)
{
    D2ThreadContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.dwContextFlags = 0x10007;
    GetThreadContext(hThread, &tContext);
    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "Stack bytes:\n");
    sub_00410040_LogMemoryDump("ERR", &gszEmptyAssertText, tContext.dwEsp, 0x1000, 0, 1, 0);
    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "Code bytes:\n");
    sub_00410040_LogMemoryDump("ERR", &gszEmptyAssertText, tContext.dwEip, 0x20, 0, 1, 0);
}

// 0x0040D540
void __cdecl sub_0040D540_SETranslator(unsigned int nCode, D2ExceptionPointersStrc* pExceptionInfo)
{
    if (!gbImageHlpLoaded_0075D014)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ExceptionHandler: imagehlp.dll not loaded");
        return;
    }
    void* hThread;
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &hThread, 0, 0, 2);
    sub_0040CC10_WalkThreadStack(hThread, pExceptionInfo->pContextRecord);
    CloseHandle(hThread);
}

// 0x0040F5A0
void __fastcall sub_0040F5A0_SetLogPrefix(const char* szName)
{
    char szDirectory[0x104];
    sub_0040F000_GetLogDirectory(szDirectory, 0x104);
    SStrPrintf(gszLogPrefix_00708018, 0x104, "%s%s", szDirectory, szName);
}

// 0x0040F600
long __fastcall sub_0040F600_MeasureLogFile(const char* szName)
{
    D2SystemTimeStrc tTime;
    EnterCriticalSection(&gtLogLock_0075E850);
    sub_0040F470_LookupLog(szName);
    long nSize = 0;
    _iobuf* pFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "r", 0, 0, 0);
    if (pFile)
    {
        fseek(pFile, 0, 2);
        nSize = ftell(pFile);
        fclose(pFile);
    }
    LeaveCriticalSection(&gtLogLock_0075E850);
    return nSize;
}

// 0x0040F670
char* __fastcall sub_0040F670_ReadLogRange(const char* szName, long nStart, long nEnd)
{
    D2SystemTimeStrc tTime;
    long nLength = nEnd - nStart;
    char* pBuffer = (char*)FOG_Alloc(nLength + 1, ".\\Src\\LogManager.cpp", 0x10A, 0);
    memset(pBuffer, 0, nLength + 1);
    EnterCriticalSection(&gtLogLock_0075E850);
    sub_0040F470_LookupLog(szName);
    _iobuf* pFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "r", 0, 0, 0);
    if (pFile)
    {
        if (!fseek(pFile, nStart, 0))
            fread(pBuffer, 1, nLength, pFile);
        fclose(pFile);
    }
    LeaveCriticalSection(&gtLogLock_0075E850);
    return pBuffer;
}

// 0x00410C40
void __stdcall sub_00410C40_OrBits(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    const int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] | *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] | pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] | pB[i + 1];
    case 1:
        pOut[i] = pA[i] | pB[i];
    }
}
