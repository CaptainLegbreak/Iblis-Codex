struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2A0

extern unsigned int gnPercent_00881C50;                                                                     // 0x00881C50
extern int gbStopDownload_00881C54;                                                                         // 0x00881C54
extern char gszDownloadArchive_00881C58[];                                                                  // 0x00881C58
char gszAdList_00881D60[1];                                                                                 // 0x00881D60
extern char gszCheckRevisionValue_00881E60[];                                                               // 0x00881E60
D2CriticalSectionStrc gDownloadLock_00881F64;                                                               // 0x00881F64

// 0x0051E370
int __fastcall sub_0051E370_SetAdList(const void* pSource, unsigned int nSize)
{
    EnterCriticalSection(&gDownloadLock_00881F64);
    SMemCopy(gszAdList_00881D60, pSource, nSize);
    gnPercent_00881C50 = 0;
    LeaveCriticalSection(&gDownloadLock_00881F64);
    return 1;
}

// 0x0051E3B0
int __fastcall sub_0051E3B0_SetCheckRevisionValue(const char* szValue)
{
    SStrCopy(gszCheckRevisionValue_00881E60, szValue, 0x104);
    return 1;
}

// 0x0051E5D0
void __cdecl sub_0051E5D0_SetStopFlag()
{
    gbStopDownload_00881C54 = 1;
}

// 0x0051EA40
void __fastcall sub_0051EA40_SetStatus(int nStatus)
{
    EnterCriticalSection(&gDownloadLock_00881F64);
    gszAdList_00881D60[0] = 0;
    gszAdList_00881D60[1] = 0;
    gnPercent_00881C50 = nStatus;
    LeaveCriticalSection(&gDownloadLock_00881F64);
}

// 0x0051EA80
int __fastcall sub_0051EA80_SetArchiveName(const char* szName)
{
    SStrCopy(gszDownloadArchive_00881C58, szName, 0x7FFFFFFF);
    return 1;
}

// 0x0051EAA0
int __cdecl sub_0051EAA0_HasName()
{
    return gszDownloadArchive_00881C58[0] != 0;
}
