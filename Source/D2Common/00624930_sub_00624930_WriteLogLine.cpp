struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct _iobuf;
typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&(v) + _INTSIZEOF(v))

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list va); // 0x00413A80
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" int __cdecl fflush(_iobuf* pFile);                                                              // 0x00688927
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* sz);

extern D2CriticalSectionStrc gLogLock_0096CA30;                                                             // 0x0096CA30
extern _iobuf* gpLogFile_0096CA48;                                                                          // 0x0096CA48
extern int gbLogEnabled_0096CA4C;                                                                           // 0x0096CA4C

// 0x00624930
void __cdecl sub_00624930_WriteLogLine(int nGame, int nFrame, int nClient, int nType, int nSize, const char* szFormat, ...)
{
    if (!gpLogFile_0096CA48)
    {
        return;
    }
    if (!gbLogEnabled_0096CA4C)
    {
        return;
    }

    EnterCriticalSection(&gLogLock_0096CA30);

    char szBuffer[500];
    SStrPrintf(szBuffer, 500, "Game:%02d\tFrame:%d\tClient:%02d\t", nGame, nFrame, nClient);
    if (nType == 1)
    {
        strcat(szBuffer, "Type:System\t");
    }
    else
    {
        strcat(szBuffer, "Type:Game\t");
    }

    const int nLength = strlen(szBuffer);
    char* pCursor = &szBuffer[nLength];
    int nRemaining = 500 - nLength;
    const int nWritten = SStrPrintf(pCursor, nRemaining, "Size:%d\n", nSize);
    nRemaining -= nWritten;
    pCursor += nWritten;

    va_list va;
    va_start(va, szFormat);
    SStrVPrintf(pCursor, nRemaining, szFormat, va);
    strcat(pCursor, "\n\n");

    fwrite(szBuffer, strlen(szBuffer), 1, gpLogFile_0096CA48);
    fflush(gpLogFile_0096CA48);
    LeaveCriticalSection(&gLogLock_0096CA30);
}
