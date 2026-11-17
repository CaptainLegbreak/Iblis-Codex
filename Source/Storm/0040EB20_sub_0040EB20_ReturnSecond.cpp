struct D2FileStrc;

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

struct D2StormBufferInfoStrc
{
    char* pbInBuffer;
    unsigned int nInPos;
    char* pbOutBuffer;
    unsigned int f_C;
    unsigned int nInSize;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl fprintf(D2FileStrc* pFile, const char* szFormat, ...);                               // 0x00684C94
extern "C" char* __cdecl _strupr(char* szString);                                                           // 0x006862A2
extern "C" char* __cdecl _strlwr(char* szString);                                                           // 0x006864E1
extern "C" __declspec(dllimport) int __stdcall GetComputerNameA(char* szBuffer, unsigned long* pnSize);     // 0x006CC1D8
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo);                     // 0x006CC1F0
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus);            // 0x006CC1F4
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo);                   // 0x006CC1F8
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency);             // 0x006CC254
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

D2SystemTimeStrc gLogStartTime_0075D288;                                                                    // 0x0075D288
int gnTimerTicksPerMs_0075E89C;                                                                             // 0x0075E89C
int gnTimerTicksPerUs_0075E898;                                                                             // 0x0075E898
extern char gaTimerTable_0075E8A0[0x18000];                                                                 // 0x0075E8A0
extern unsigned long gnTimerStartTick_007768A0;                                                             // 0x007768A0
unsigned int gnPageSize_00776CB8;                                                                           // 0x00776CB8
int gnFlag0_007784C4;                                                                                       // 0x007784C4
extern int gnFlag3_007788CC;                                                                                // 0x007788CC
int gnFlag2_00776CBC;                                                                                       // 0x00776CBC
int gnFlag1_007784C0;                                                                                       // 0x007784C0
extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern char gszBasePath_00778F28[];                                                                         // 0x00778F28
int gnValueA_00779060;                                                                                      // 0x00779060
int gnValueB_00779064;                                                                                      // 0x00779064
extern int gnValue_00708350;                                                                                // 0x00708350
int gnValue_0077904C;                                                                                       // 0x0077904C
extern int gnValueA_0070834C;                                                                               // 0x0070834C
int gnValueB_00779030;                                                                                      // 0x00779030
extern unsigned short gwValue_0077905C;                                                                     // 0x0077905C

void __cdecl sub_004158E0_InitBasePath();                                                                   // 0x004158E0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x0041D2A0

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc* sub_0040F4F0_NextLink(int nLinkOffset);
};

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_0040F880_Link(char* pNode);
    void sub_0040FBB0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    void sub_0040FC60_UnlinkNode(char* pNode);
};

struct D2Storm415140Strc
{
    int f_0;
    int f_4;
    int f_8;
    int nFieldC;

    D2Storm415140Strc(int nValue0, int nValue4, int nValue8, int nValueC);
};

template <class T>
inline T StormPowInt(T x, int nExp)
{
    unsigned int nBits;
    if (nExp >= 0)
        nBits = (unsigned int)nExp;
    else
        nBits = (unsigned int)-nExp;
    for (T z = T(1); ; x *= x)
    {
        if ((nBits & 1) != 0)
            z *= x;
        if ((nBits >>= 1) == 0)
            return nExp < 0 ? T(1) / z : z;
    }
}

// 0x0040EB20
int __cdecl sub_0040EB20_ReturnSecond(int, int nValue)
{
    return nValue;
}

// 0x0040ECC0
void __fastcall sub_0040ECC0_LogWriteHeader(D2FileStrc* pFile, const D2SystemTimeStrc* pTime)
{
    char szComputerName[0x40];
    unsigned long nSize = sizeof(szComputerName);
    if (!GetComputerNameA(szComputerName, &nSize))
        szComputerName[0] = 0;
    fprintf(pFile, "---------------------------------------------------------------\n");
    fprintf(pFile, "%s %04d-%02d-%02d\n", szComputerName, pTime->wYear, pTime->wMonth, pTime->wDay);
    fprintf(pFile, "---------------------------------------------------------------\n");
}

// 0x0040ED40
void __fastcall sub_0040ED40_LogWriteStartup(D2FileStrc* pFile)
{
    char szComputerName[0x40];
    unsigned long nSize = sizeof(szComputerName);
    if (!GetComputerNameA(szComputerName, &nSize))
        szComputerName[0] = 0;
    fprintf(pFile, "---------------------------------------------------------------\n");
    fprintf(pFile, "%s Realm startup at %04d-%02d-%02d %02d:%02d:%02d.%03u\n", szComputerName, gLogStartTime_0075D288.wYear,
        gLogStartTime_0075D288.wMonth, gLogStartTime_0075D288.wDay, gLogStartTime_0075D288.wHour,
        gLogStartTime_0075D288.wMinute, gLogStartTime_0075D288.wSecond, gLogStartTime_0075D288.wMilliseconds);
    fprintf(pFile, "---------------------------------------------------------------\n");
}

// 0x0040F4F0
D2StormLinkStrc* D2StormLinkStrc::sub_0040F4F0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0040F880
D2StormLinkStrc* D2StormFixedListStrc::sub_0040F880_Link(char* pNode)
{
    return Link(pNode);
}

// 0x0040FBB0
void D2StormFixedListStrc::sub_0040FBB0_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x0040FC60
void D2StormFixedListStrc::sub_0040FC60_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00410930
void __cdecl sub_00410930_GetMemoryStatus(D2MemoryStatusStrc* pStatus)
{
    memset(pStatus, 0, sizeof(*pStatus));
    pStatus->dwLength = sizeof(*pStatus);
    GlobalMemoryStatus(pStatus);
}

// 0x00410960
int __cdecl sub_00410960_IsPlatformNT()
{
    D2OsVersionInfoStrc versionInfo;
    memset(&versionInfo, 0, sizeof(versionInfo));
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    if (!GetVersionExA(&versionInfo))
        return 0;
    return versionInfo.dwPlatformId == 2;
}

// 0x00411210
void __cdecl sub_00411210_InitTimer()
{
    __int64 nFrequency;
    QueryPerformanceFrequency(&nFrequency);
    gnTimerTicksPerMs_0075E89C = (int)(nFrequency / 1000);
    gnTimerTicksPerUs_0075E898 = (int)(nFrequency / 1000000);
    memset(gaTimerTable_0075E8A0, 0, sizeof(gaTimerTable_0075E8A0));
    gnTimerStartTick_007768A0 = GetTickCount();
}

// 0x00411700
int __stdcall sub_00411700_ToByte(unsigned char nValue)
{
    return nValue;
}

// 0x00411A20
void __cdecl sub_00411A20_InitPageSize()
{
    T004013C0 systemInfo;
    GetSystemInfo(&systemInfo);
    gnPageSize_00776CB8 = 1;
    while (gnPageSize_00776CB8 < systemInfo.dwPageSize)
        gnPageSize_00776CB8 *= 2;
}

// 0x00411D40
void __stdcall sub_00411D40_SetFlags(unsigned int dwValues, unsigned int dwMask)
{
    if (dwMask & 1)
        gnFlag0_007784C4 = dwValues & 1;
    if (dwMask & 8)
        gnFlag3_007788CC = (dwValues >> 3) & 1;
    if (dwMask & 4)
        gnFlag2_00776CBC = (dwValues >> 2) & 1;
    if (dwMask & 2)
        gnFlag1_007784C0 = (dwValues >> 1) & 1;
}

#define STORM_LOOKUP2_MIX(a, b, c) \
{ \
    a -= b; a -= c; a ^= (c >> 13); \
    b -= c; b -= a; b ^= (a << 8); \
    c -= a; c -= b; c ^= (b >> 13); \
    a -= b; a -= c; a ^= (c >> 12); \
    b -= c; b -= a; b ^= (a << 16); \
    c -= a; c -= b; c ^= (b >> 5); \
    a -= b; a -= c; a ^= (c >> 3); \
    b -= c; b -= a; b ^= (a << 10); \
    c -= a; c -= b; c ^= (b >> 15); \
}

// 0x00413F30
unsigned int __fastcall sub_00413F30_HashLookup2(const unsigned char* k, unsigned int nLength, unsigned int nInitVal)
{
    unsigned int a, b, c, len;
    len = nLength;
    a = b = 0x9E3779B9;
    c = nInitVal;
    while (len >= 12)
    {
        a += (k[0] + ((unsigned int)k[1] << 8) + ((unsigned int)k[2] << 16) + ((unsigned int)k[3] << 24));
        b += (k[4] + ((unsigned int)k[5] << 8) + ((unsigned int)k[6] << 16) + ((unsigned int)k[7] << 24));
        c += (k[8] + ((unsigned int)k[9] << 8) + ((unsigned int)k[10] << 16) + ((unsigned int)k[11] << 24));
        STORM_LOOKUP2_MIX(a, b, c);
        k += 12;
        len -= 12;
    }
    c += nLength;
    switch (len)
    {
    case 11: c += ((unsigned int)k[10] << 24);
    case 10: c += ((unsigned int)k[9] << 16);
    case 9: c += ((unsigned int)k[8] << 8);
    case 8: b += ((unsigned int)k[7] << 24);
    case 7: b += ((unsigned int)k[6] << 16);
    case 6: b += ((unsigned int)k[5] << 8);
    case 5: b += k[4];
    case 4: a += ((unsigned int)k[3] << 24);
    case 3: a += ((unsigned int)k[2] << 16);
    case 2: a += ((unsigned int)k[1] << 8);
    case 1: a += k[0];
    }
    STORM_LOOKUP2_MIX(a, b, c);
    return c;
}

// 0x004141E0
char* __stdcall sub_004141E0_StrUpper(char* szString)
{
    return _strupr(szString);
}

// 0x00414200
char* __stdcall sub_00414200_StrLower(char* szString)
{
    return _strlwr(szString);
}

// build: context sub_00414220_PowInt
double __fastcall sub_00414220_PowInt(double x, int nExp)
{
    return StormPowInt(x, nExp);
}

// 0x00414260
double __cdecl sub_00414260_PowInt(double x, int nExp)
{
    return StormPowInt(x, nExp);
}

// 0x00415140
D2Storm415140Strc::D2Storm415140Strc(int nValue0, int nValue4, int nValue8, int nValueC)
{
    f_0 = nValue0;
    f_4 = nValue4;
    f_8 = nValue8;
    nFieldC = nValueC;
}

// 0x004151D0
unsigned int __cdecl sub_004151D0_ReadBuffer(char* pBuffer, unsigned int* pnSize, D2StormBufferInfoStrc* pInfo)
{
    unsigned int nAvail = pInfo->nInSize - pInfo->nInPos;
    unsigned int nToRead = *pnSize < nAvail ? *pnSize : nAvail;
    sub_0041D2A0_MemCopy(pBuffer, pInfo->pbInBuffer + pInfo->nInPos, nToRead);
    pInfo->nInPos += nToRead;
    return nToRead;
}

// 0x00415210
void __cdecl sub_00415210_WriteBuffer(char* pBuffer, unsigned int* pnSize, D2StormBufferInfoStrc* pInfo)
{
    sub_0041D2A0_MemCopy(pInfo->pbOutBuffer + pInfo->f_C, pBuffer, *pnSize);
    pInfo->f_C += *pnSize;
}

// 0x00415EC0
void __stdcall sub_00415EC0_SetPair(int nValueA, int nValueB)
{
    gnValueA_00779060 = nValueA;
    gnValueB_00779064 = nValueB;
}

// 0x00415F90
void __stdcall sub_00415F90_SetValue(int nValue)
{
    gnValue_00708350 = nValue;
}

// 0x004160A0
int __stdcall sub_004160A0_GetBasePath(char* szBuffer, unsigned int nBufferSize)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!gszBasePath_00778F28[0])
        sub_004158E0_InitBasePath();
    SStrCopy(szBuffer, gszBasePath_00778F28, nBufferSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004164A0
void __stdcall sub_004164A0_SetValue(int nValue)
{
    gnValue_0077904C = nValue;
}

// 0x004166B0
int __stdcall sub_004166B0_SetPair(int nValueA, int nValueB)
{
    gnValueA_0070834C = nValueA;
    gnValueB_00779030 = nValueB;
    return 1;
}

// 0x004166D0
void __stdcall sub_004166D0_SetWord(unsigned short nValue)
{
    gwValue_0077905C = nValue;
}

#include "gen/data/Source/Storm/0040EB20_sub_0040EB20_ReturnSecond.inc"
