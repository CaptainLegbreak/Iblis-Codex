typedef unsigned int size_t;
typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

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

struct T0041FA40
{
    void* hLog;
    T0041FA40* pNext;
    void* hFile;
    unsigned long nUsed;
    unsigned long nPended;
    int nIndent;
    int f_18;
    char szBuffer[0x10000];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) int __stdcall FlushFileBuffers(void* hFile);                               // 0x006CC328
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0

extern D2CriticalSectionStrc gaSLogLocks_00779238[4];                                                       // 0x00779238
extern T0041FA40* gapSLogBuckets_00779298[4];                                                              // 0x00779298
static unsigned long gnSLogTimeLength_007792A8;                                                             // 0x007792A8
static char gszSLogTime_007792B0[0x40];                                                                     // 0x007792B0
static unsigned long gdwSLogLastTick_007792F0;                                                              // 0x007792F0
extern int gbSLogDebugOutput_007790AC;                                                                      // 0x007790AC
extern "C" const char gszSLogNewline_006CFF08[];                                                            // 0x006CFF08
extern "C" const char gszDot_006CCAD8[];                                                                    // 0x006CCAD8
extern "C" const char gszSpace_006FFC44[];                                                                  // 0x006FFC44

static __declspec(noinline) void sub_0041FA40_FlushLog(T0041FA40* pLog)
{
    unsigned long dwWritten;
    if (pLog->nUsed)
    {
        WriteFile(pLog->hFile, pLog->szBuffer, pLog->nUsed, &dwWritten, 0);
        FlushFileBuffers(pLog->hFile);
        pLog->nUsed = 0;
        pLog->nPended = 0;
    }
}

static __declspec(noinline) T0041FA40* __stdcall sub_0041FA80_LockLog(unsigned long* pIndex, int bCreate, void* hLog)
{
    if (!hLog)
    {
        *pIndex = (unsigned long)-1;
        return 0;
    }
    unsigned long nIndex = (unsigned long)hLog & 3;
    EnterCriticalSection(&gaSLogLocks_00779238[nIndex]);
    *pIndex = nIndex;
    T0041FA40** ppNext = &gapSLogBuckets_00779298[nIndex];
    for (T0041FA40* p = *ppNext; p; p = *ppNext)
    {
        if (p->hLog == hLog)
            return p;
        ppNext = &p->pNext;
    }
    if (!bCreate)
    {
        LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    T0041FA40* pLog = (T0041FA40*)VirtualAlloc(0, sizeof(T0041FA40), 0x1000, 4);
    *ppNext = pLog;
    if (!pLog)
    {
        LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    pLog->hLog = hLog;
    pLog->pNext = 0;
    pLog->hFile = (void*)-1;
    pLog->nUsed = 0;
    pLog->nPended = 0;
    return pLog;
}

static __declspec(noinline) void sub_0041FB40_AppendIndent(T0041FA40* pLog)
{
    int nIndent = pLog->nIndent;
    if (nIndent > 0)
    {
        if (nIndent >= 0x80)
            nIndent = 0x80;
        memset(pLog->szBuffer + pLog->nUsed, ' ', nIndent);
        pLog->szBuffer[pLog->nUsed + nIndent] = 0;
        pLog->nUsed += nIndent;
    }
}

static __declspec(noinline) void sub_0041FB80_AppendNewline(T0041FA40* pLog)
{
    SMemCopy(pLog->szBuffer + pLog->nUsed, gszSLogNewline_006CFF08, 3);
    pLog->nUsed += 2;
}

// 0x0041FBA0
static __declspec(noinline) void __stdcall sub_0041FBA0_AppendTimestamp(int bText, T0041FA40* pLog)
{
    if (!pLog->f_18)
        return;
    unsigned long dwTick = GetTickCount();
    if (dwTick != gdwSLogLastTick_007792F0)
    {
        gdwSLogLastTick_007792F0 = dwTick;
        D2SystemTimeStrc tTime;
        GetLocalTime(&tTime);
        wsprintfA(gszSLogTime_007792B0, "%u/%u %02u:%02u:%02u.%03u  ", tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
        gnSLogTimeLength_007792A8 = SStrLen(gszSLogTime_007792B0);
    }
    if (bText)
    {
        SMemCopy(pLog->szBuffer + pLog->nUsed, gszSLogTime_007792B0, gnSLogTimeLength_007792A8 + 1);
    }
    else
    {
        SMemFill(pLog->szBuffer + pLog->nUsed, gnSLogTimeLength_007792A8, ' ');
        pLog->szBuffer[pLog->nUsed + gnSLogTimeLength_007792A8] = 0;
    }
    pLog->nUsed += gnSLogTimeLength_007792A8;
    sub_0041FB40_AppendIndent(pLog);
}

static __declspec(noinline) void sub_0041FC80_UnlinkLog(T0041FA40* pLog, unsigned long nIndex)
{
    T0041FA40** ppNext = &gapSLogBuckets_00779298[nIndex];
    for (T0041FA40* p = *ppNext; p; p = *ppNext)
    {
        if (p == pLog)
        {
            *ppNext = p->pNext;
            VirtualFree(p, 0, 0x8000);
            break;
        }
        ppNext = &p->pNext;
    }
    LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
}

static __declspec(noinline) void sub_0041FCE0_UnlockLog(unsigned long nIndex)
{
    LeaveCriticalSection(&gaSLogLocks_00779238[nIndex]);
}

void __stdcall SLogClose(void* hLog)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        sub_0041FA40_FlushLog(pLog);
        CloseHandle(pLog->hFile);
        sub_0041FC80_UnlinkLog(pLog, nIndex);
    }
}

void __stdcall SLogDump(void* hLog, const void* pData, unsigned long nSize)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    for (unsigned long nOffset = 0; nOffset < nSize; nOffset += 8)
    {
        sub_0041FBA0_AppendTimestamp(0, pLog);
        wsprintfA(pLog->szBuffer + pLog->nUsed, "%04x: ", nOffset);
        pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
        for (unsigned long i = nOffset; i < nOffset + 8; ++i)
        {
            if (i < nSize)
            {
                wsprintfA(pLog->szBuffer + pLog->nUsed, "%02x ", ((const unsigned char*)pData)[i]);
                pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
            }
            else
            {
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, "   ", 0x7FFFFFFF);
            }
            if ((i & 3) == 3)
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, "  ", 0x7FFFFFFF);
        }
        for (unsigned long i = nOffset; i < nOffset + 8; ++i)
        {
            char c = (i < nSize) ? ((const char*)pData)[i] : 0;
            if (c >= ' ' && c <= '~')
            {
                wsprintfA(pLog->szBuffer + pLog->nUsed, "%c", c);
                pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
            }
            else
            {
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, c ? gszDot_006CCAD8 : gszSpace_006FFC44, 0x7FFFFFFF);
            }
            if ((i & 7) == 3)
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, gszSpace_006FFC44, 0x7FFFFFFF);
        }
        sub_0041FB80_AppendNewline(pLog);
    }
    if (gbSLogDebugOutput_007790AC)
        OutputDebugStringA(pLog->szBuffer + pLog->nPended);
    pLog->nPended = pLog->nUsed;
    if (pLog->nUsed >= 0xC000)
        sub_0041FA40_FlushLog(pLog);
    sub_0041FCE0_UnlockLog(nIndex);
}

void __stdcall SLogFlush(void* hLog)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        sub_0041FA40_FlushLog(pLog);
        sub_0041FCE0_UnlockLog(nIndex);
    }
}

void __cdecl SLogFlushAll()
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        EnterCriticalSection(&gaSLogLocks_00779238[i]);
        for (T0041FA40* p = gapSLogBuckets_00779298[i]; p; p = p->pNext)
            sub_0041FA40_FlushLog(p);
        LeaveCriticalSection(&gaSLogLocks_00779238[i]);
    }
}

void __cdecl SLogPend(void* hLog, const char* szFormat, ...)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    pLog->nUsed = pLog->nPended;
    sub_0041FBA0_AppendTimestamp(1, pLog);
    va_list args;
    va_start(args, szFormat);
    vsprintf(pLog->szBuffer + pLog->nUsed, szFormat, args);
    pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
    sub_0041FB80_AppendNewline(pLog);
    sub_0041FCE0_UnlockLog(nIndex);
}

int __stdcall sub_004200E0_SLogSetAbsIndent(void* hLog, int nIndent)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return 0;
    int nOld = pLog->nIndent;
    pLog->nIndent = nIndent;
    sub_0041FCE0_UnlockLog(nIndex);
    return nOld;
}

int __stdcall sub_00420120_SLogSetIndent(void* hLog, int nDelta)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return 0;
    int nOld = pLog->nIndent;
    pLog->nIndent = nOld + nDelta;
    sub_0041FCE0_UnlockLog(nIndex);
    return nOld;
}

void __stdcall sub_00420160_SLogSetTimestamp(void* hLog, int bTimestamp)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        pLog->f_18 = bTimestamp;
        sub_0041FCE0_UnlockLog(nIndex);
    }
}

void __cdecl SLogWrite(void* hLog, const char* szFormat, ...)
{
    unsigned long nIndex;
    T0041FA40* pLog = sub_0041FA80_LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    sub_0041FBA0_AppendTimestamp(1, pLog);
    va_list args;
    va_start(args, szFormat);
    vsprintf(pLog->szBuffer + pLog->nUsed, szFormat, args);
    pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
    sub_0041FB80_AppendNewline(pLog);
    if (gbSLogDebugOutput_007790AC)
        OutputDebugStringA(pLog->szBuffer + pLog->nPended);
    pLog->nPended = pLog->nUsed;
    if (pLog->nUsed >= 0xC000)
        sub_0041FA40_FlushLog(pLog);
    sub_0041FCE0_UnlockLog(nIndex);
}
