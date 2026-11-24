#include "Fog.h"
#include "D2GameTypes.h"


struct D2TimeStampStrc
{
    long nTime;
    unsigned long nTick;
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);                            // 0x006CC268
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
void __fastcall sub_004107B0_AtomicStore64(void* pDest, const void* pSource);                               // 0x004107B0
void __fastcall sub_004107D0_Read64Locked(void* pDest, const void* pSource);                                // 0x004107D0
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC1FC
D2CriticalSectionStrc gtTimeLock;                                                                   // 0x0075E880
D2TimeStampStrc gtTimeBase;                                                                        // 0x0075E878

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270
int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050
extern "C" const char gszKernel32[]; // 0x006CD6E4
typedef int (__stdcall* D2GetDiskFreeSpaceExFn)(const char* szDirectory, unsigned __int64* pnFreeToCaller, unsigned __int64* pnTotal, unsigned __int64* pnTotalFree);

// 0x004109D0
void __cdecl SYSTEM_InitTimeBase()
{
    InitializeCriticalSection(&gtTimeLock);
    __int64 nShared = 0;
    __int64 nTest = 666;
    __int64 nRead = -1;
    sub_004107B0_AtomicStore64(&nShared, &nTest);
    sub_004107D0_Read64Locked(&nRead, &nShared);
    D2_ASSERT(nRead == 666, 0x3C);
    D2TimeStampStrc tNow;
    tNow.nTime = _time32(0);
    tNow.nTick = GetTickCount();
    sub_004107B0_AtomicStore64(&gtTimeBase, &tNow);
}

// 0x00410A80
long __cdecl FOG_GetSyncTime()
{
    const unsigned long nTick = GetTickCount();
    D2TimeStampStrc tBase;
    sub_004107D0_Read64Locked(&tBase, &gtTimeBase);
    if (nTick - tBase.nTick > 30000)
    {
        const int nPriority = GetThreadPriority(GetCurrentThread());
        if (nPriority != 0x7FFFFFFF)
        {
            SetThreadPriority(GetCurrentThread(), nPriority);
        }
        D2TimeStampStrc tNow;
        tNow.nTime = _time32(0);
        tNow.nTick = GetTickCount();
        sub_004107B0_AtomicStore64(&gtTimeBase, &tNow);
    }
    return (nTick - tBase.nTick) / 1000 + tBase.nTime;
}

struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

struct D2OsVersionInfoStrc
{
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus); // 0x006CC1F4
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo); // 0x006CC1F8
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

// 0x004107A0
void __cdecl sub_004107A0_DeleteTimeLock()
{
    DeleteCriticalSection(&gtTimeLock);
}

// 0x004107B0
__declspec(naked) void __fastcall sub_004107B0_AtomicStore64(void* pDest, const void* pSource)
{
    __asm
    {
        push ebx
        push edi
        mov edi, ecx
        mov ebx, [edx]
        mov ecx, [edx + 4]
        mov eax, [edi]
        mov edx, [edi + 4]
    retry:
        lock cmpxchg8b qword ptr [edi]
        jne retry
        pop edi
        pop ebx
        ret
    }
}

// 0x004107D0
__declspec(naked) void __fastcall sub_004107D0_Read64Locked(void* pDest, const void* pSource)
{
    __asm
    {
        push ebx
        push esi
        mov esi, edx
        mov eax, ebx
        mov edx, ecx
        lock cmpxchg8b qword ptr [esi]
        mov [ecx], eax
        mov [ecx + 4], edx
        pop esi
        pop ebx
        ret
    }
}

// 0x004107F0
unsigned __int64 __cdecl SYSTEM_GetSaveDiskFreeSpace()
{
    char szPath[0x400];
    FOG_GetSavePath(szPath, sizeof(szPath));
    void* hKernel = LoadLibraryA(gszKernel32);
    if (hKernel)
    {
        D2GetDiskFreeSpaceExFn pfnGetDiskFreeSpaceEx = (D2GetDiskFreeSpaceExFn)GetProcAddress(hKernel, "GetDiskFreeSpaceExA");
        if (pfnGetDiskFreeSpaceEx)
        {
            unsigned __int64 nTotalFree = 0;
            unsigned __int64 nTotal = 0;
            unsigned __int64 nFreeToCaller = 0;
            pfnGetDiskFreeSpaceEx(szPath, &nFreeToCaller, &nTotal, &nTotalFree);
            FreeLibrary(hKernel);
            return nFreeToCaller;
        }
    }
    for (unsigned int i = 0; i < sizeof(szPath); i++)
    {
        if (szPath[i] == '\\')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    unsigned long nSectorsPerCluster = 0;
    unsigned long nBytesPerSector = 0;
    unsigned long nFreeClusters = 0;
    unsigned long nTotalClusters = 0;
    GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
    return nFreeClusters * nBytesPerSector * nSectorsPerCluster;
}
// 0x00410930
void __cdecl SYSTEM_GetMemoryStatus(D2MemoryStatusStrc* pStatus)
{
    memset(pStatus, 0, sizeof(*pStatus));
    pStatus->dwLength = sizeof(*pStatus);
    GlobalMemoryStatus(pStatus);
}

// 0x00410960
int __cdecl SYSTEM_IsPlatformNT()
{
    D2OsVersionInfoStrc versionInfo;
    memset(&versionInfo, 0, sizeof(versionInfo));
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    if (!GetVersionExA(&versionInfo))
        return 0;
    return versionInfo.dwPlatformId == 2;
}

