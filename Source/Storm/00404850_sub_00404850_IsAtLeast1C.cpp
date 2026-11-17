typedef unsigned char BOOLEAN;

struct _iobuf;

struct D2OsVersionInfoStrc
{
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

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

struct T004013C0
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

struct D2CharSaveIdStrc
{
    unsigned char f_0[0x10];
};

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    char unk0x0C[0x08];
    char szName[0x10];
    unsigned int dwFlags;
    unsigned char nClass;
    unsigned char nUnk0x29;
    unsigned char nUnk0x2A;
    unsigned char nUnk0x2B;
    long nCreateTime;
    long nSaveTime;
    char unk0x34[0x54];
    D2CharSaveIdStrc tId;
    int anUnk0x98[4];
    char unk0xA8[0xA7];
};

struct D2AutomapNodeStrc
{
    int nValue;
    int nData[5];
    D2AutomapNodeStrc* pNext;
};

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo);                   // 0x006CC1F8
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus);            // 0x006CC1F4
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo);                     // 0x006CC1F0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink);                                         // 0x00411A80
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void __stdcall sub_006BBF40_PutPackedWord(unsigned char* pStream, unsigned short nValue);                   // 0x006BBF40

int gnOsKind_0074D890;                                                                                      // 0x0074D890
float gfOsVersion_0074D894;                                                                                 // 0x0074D894
extern unsigned long gdwTotalPhys_0074D898;                                                                 // 0x0074D898
extern T004013C0 gtSystemInfo_0074D8A0;                                                              // 0x0074D8A0
int gbSystemInfoDone_0074D88C;                                                                              // 0x0074D88C
extern _iobuf* gapLogFiles_0075E790[20];                                                                    // 0x0075E790
extern unsigned long gadwLogOpenTick_0075E7E0[20];                                                          // 0x0075E7E0
extern unsigned long gadwLogWriteTick_0075D2F0[20];                                                         // 0x0075D2F0
extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100];                                                       // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                              // 0x00776CC0
int gabFreeBlockDirty_007784C8[0x100];                                                                      // 0x007784C8
int gnFreeBlockSweep_007788C8;                                                                              // 0x007788C8
extern D2CharSaveHeaderStrc gtCharSaveHeader_0077AC10;                                                      // 0x0077AC10
extern D2CharSaveIdStrc gtCharSaveId_0070CCC8;                                                              // 0x0070CCC8
extern D2AutomapNodeStrc* gpAutomapNodes_007A5160;                                                          // 0x007A5160

// 0x00404850
BOOLEAN __stdcall sub_00404850_IsAtLeast1C(unsigned int nValue)
{
    return nValue >= 0x1C;
}

// 0x00407DE0
void __cdecl sub_00407DE0_CaptureSystemInfo()
{
    D2OsVersionInfoStrc tVersion;
    D2MemoryStatusStrc tMemory;
    tVersion.dwOSVersionInfoSize = sizeof(tVersion);
    if (GetVersionExA(&tVersion))
    {
        float fMinor = (float)tVersion.dwMinorVersion;
        while (fMinor > 1.0)
        {
            fMinor = fMinor / 10.0;
        }
        gfOsVersion_0074D894 = (float)((float)tVersion.dwMajorVersion + fMinor / 100.0);
        switch (tVersion.dwPlatformId)
        {
        case 2:
            gnOsKind_0074D890 = 1;
            if (tVersion.dwMajorVersion >= 5)
            {
                if (tVersion.dwMinorVersion >= 2)
                {
                    gnOsKind_0074D890 = 4;
                }
                else
                {
                    gnOsKind_0074D890 = tVersion.dwMinorVersion < 1 ? 2 : 3;
                }
            }
            break;
        case 3:
            gnOsKind_0074D890 = 0;
            break;
        default:
            gnOsKind_0074D890 = 0;
            break;
        }
    }
    GlobalMemoryStatus(&tMemory);
    gdwTotalPhys_0074D898 = tMemory.dwTotalPhys;
    GetSystemInfo(&gtSystemInfo_0074D8A0);
    gbSystemInfoDone_0074D88C = 1;
}

// 0x0040E850
unsigned __int64 __cdecl sub_0040E850_ReadTimeStampCounter()
{
    unsigned __int64 nTicks;
    __asm
    {
        rdtsc
        mov dword ptr nTicks[0], eax
        mov dword ptr nTicks[4], edx
    }
    return nTicks;
}

// 0x0040F350
void __cdecl sub_0040F350_CloseStaleLogs()
{
    char szPath[0x104];
    int bLog = 0;
    szPath[0] = 0;
    unsigned long nNow = GetTickCount();
    for (int i = 0; i < 20; ++i)
    {
        if (gapLogFiles_0075E790[i])
        {
            if (nNow - gadwLogOpenTick_0075E7E0[i] > 15000 || nNow - gadwLogWriteTick_0075D2F0[i] > 5000)
            {
                if (bLog)
                {
                    OutputDebugStringA(szPath);
                }
                fclose(gapLogFiles_0075E790[i]);
                gapLogFiles_0075E790[i] = 0;
            }
        }
    }
}

// 0x00412000
void __cdecl sub_00412000_ReleaseFreeBlocks()
{
    int i = 0;
    gnFreeBlockSweep_007788C8 = 0;
    D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
    int n = 0x100;
    do
    {
        if (gabFreeBlockDirty_007784C8[i])
        {
            EnterCriticalSection(pLock);
            gabFreeBlockDirty_007784C8[i] = 0;
            D2FogBlockStrc** ppLink = &gapFreeBlocks_007768B8[i];
            while (*ppLink)
            {
                D2FogBlockStrc* pBlock = *ppLink;
                if (!pBlock->bInUse && pBlock->dwSize < 0x80000000)
                    sub_00411A80_ReleaseBlock(ppLink);
                else
                    ppLink = &pBlock->pNext;
            }
            LeaveCriticalSection(pLock);
        }
        ++i;
        ++pLock;
    } while (--n);
}

// 0x00414220
double __fastcall sub_00414220_PowInt(double x, int nExp)
{
    const double one = 1.0;
    unsigned int nBits = nExp >= 0 ? (unsigned int)nExp : (unsigned int)-nExp;
    double z = one;
    for (;;)
    {
        if (nBits & 1)
            z *= x;
        nBits >>= 1;
        if (nBits == 0)
            break;
        x *= x;
    }
    return nExp < 0 ? one / z : z;
}

// 0x0043C540
void __fastcall sub_0043C540(const char* szName, unsigned char nClass, unsigned char* pStream, unsigned short wFlags)
{
    memset(&gtCharSaveHeader_0077AC10, 0, 0x14F);
    gtCharSaveHeader_0077AC10.dwMagic = 0xAA55AA55;
    gtCharSaveHeader_0077AC10.dwVersion = 0x60;
    SStrCopy(gtCharSaveHeader_0077AC10.szName, szName, 0x7FFFFFFF);
    gtCharSaveHeader_0077AC10.nClass = nClass;
    gtCharSaveHeader_0077AC10.nUnk0x2B = 1;
    gtCharSaveHeader_0077AC10.dwFlags = wFlags | 1;
    gtCharSaveHeader_0077AC10.nCreateTime = _time32(0);
    gtCharSaveHeader_0077AC10.nSaveTime = gtCharSaveHeader_0077AC10.nCreateTime;
    gtCharSaveHeader_0077AC10.dwSize = 0x14F;
    gtCharSaveHeader_0077AC10.nUnk0x29 = 0x10;
    gtCharSaveHeader_0077AC10.nUnk0x2A = 0x1E;
    if (nClass == 6 || nClass == 5)
        gtCharSaveHeader_0077AC10.dwFlags |= 0x20;
    sub_006BBF40_PutPackedWord(pStream, 0xE);
    pStream += 2;
    gtCharSaveHeader_0077AC10.tId = gtCharSaveId_0070CCC8;
    for (int i = 0; i < 11; ++i)
        *pStream++ = gtCharSaveId_0070CCC8.f_0[i];
    *pStream++ = nClass + 1;
    memset(gtCharSaveHeader_0077AC10.anUnk0x98, 0xFF, sizeof(gtCharSaveHeader_0077AC10.anUnk0x98));
    memset(pStream, -1, 11);
    pStream += 11;
    const unsigned short wSavedFlags = (unsigned short)gtCharSaveHeader_0077AC10.dwFlags;
    *pStream++ = 1;
    sub_006BBF40_PutPackedWord(pStream, wSavedFlags);
    pStream += 2;
    sub_006BBF40_PutPackedWord(pStream, 0);
    pStream += 2;
    *pStream++ = 0xFF;
    *pStream++ = 0xFF;
    *pStream++ = 0xFF;
    *pStream = 0;
}

// 0x00458CF0
void __stdcall sub_00458CF0_PushNode(int nValue)
{
    D2AutomapNodeStrc* pNode = (D2AutomapNodeStrc*)FOG_Alloc(sizeof(D2AutomapNodeStrc), ".\\UI\\automap.cpp", 0x5ED, 0);
    D2AutomapNodeStrc* pHead = gpAutomapNodes_007A5160;
    memset(pNode->nData, 0, sizeof(pNode->nData));
    pNode->nValue = nValue;
    pNode->pNext = pHead;
    gpAutomapNodes_007A5160 = pNode;
}

#include "gen/data/Source/Storm/00404850_sub_00404850_IsAtLeast1C.inc"
