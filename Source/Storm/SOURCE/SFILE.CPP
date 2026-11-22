#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#include "D2StormSha1.h"

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

struct D2FileStrc;
struct D2StormFileSubStrc;
struct D2MemoryStatusStrc;
struct D2OsVersionInfoStrc;
struct D2CriticalSectionStrc;
struct D2StormBufferInfoStrc;
struct D2Storm415140Strc;
struct D2SFileRecordViewStrc;
struct D2SFileOtherRecordViewStrc;
struct D2StormRequestCallbackStrc;
struct D2StormCryptFuncsStrc;
struct D2StormSignatureKeyStrc;
struct D2StormBlockEntryStrc;
struct D2StormQuadStrc;
struct D2Storm416A90Strc;
struct PairStrc_00416810;
struct PairStrc_00416890;
struct PairStrc_004168B0;
struct PairStrc_00416960;
struct PairStrc_004169A0;
struct PairStrc_0041C390;
struct PairStrc_0041E8F0;
struct PairStrc_004203E0;
struct PairStrc_00426920;
struct D2IdentityView;
struct Link;
struct D2SFileStormLinkM114Strc;
struct D2SFileNodeM114Strc;
struct D2SFileStormListM114Strc;
struct D2SFileOwnerM114Strc;
struct D2SFileArchiveM114Strc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct D2StormList00418490Strc;
struct D2StormList004185B0Strc;
struct D2StormHashBufferStrc;
struct CBitOutput;
class THuffmannTree;
struct D2StormHuffLinkSlotStrc;
struct CHuffman;
struct D2StormHandlerStrc;
struct D2StormWndRecStrc;
struct D2StormNodeListBStrc;

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

struct D2StormBufferInfoStrc
{
    char* pbInBuffer;
    unsigned int nInPos;
    char* pbOutBuffer;
    unsigned int f_C;
    unsigned int nInSize;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl fprintf(D2FileStrc* pFile, const char* szFormat, ...); // 0x00684C94
extern "C" char* __cdecl _strupr(char* szString); // 0x006862A2
extern "C" char* __cdecl _strlwr(char* szString); // 0x006864E1
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo); // 0x006CC1F0
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus); // 0x006CC1F4
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo); // 0x006CC1F8
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern char gaTimerTable_0075E8A0[0x18000]; // 0x0075E8A0
extern unsigned long gnTimerStartTick_007768A0; // 0x007768A0
extern int gnFlag3_007788CC; // 0x007788CC
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern char gszBasePath_00778F28[]; // 0x00778F28
extern unsigned short gwValue_0077905C; // 0x0077905C
void __cdecl sub_004158E0_InitBasePath(); // 0x004158E0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __stdcall SMemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0

struct Link {
    Link* previous;
    char* next;
    char* sub_00417770();
};

struct D2Storm415140Strc
{
    int f_0;
    int f_4;
    int f_8;
    int nFieldC;

    D2Storm415140Strc(int nValue0, int nValue4, int nValue8, int nValueC);
};

struct D2SFileRecordViewStrc
{
    char unk0x00[0x144];
    int dwField144;
    int dwField148;
    int dwField14C;
    int dwField150;
};

struct D2SFileOtherRecordViewStrc
{
    char unk0x00[0x4C];
    int dwField4C;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
void __fastcall sub_0041D810_Crc32(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810
int __cdecl sub_00418B50(); // 0x00418B50
void* __cdecl StormGetInstance(); // 0x0041BEF0
void __cdecl sub_0041A880_StartThread(); // 0x0041A880
void __cdecl sub_00419C00_PumpStreams();
int __stdcall SFileCloseFile(void* pArg); // 0x004198D0
int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile); // 0x004192F0
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0
unsigned int __stdcall InternalReadAligned(FILEREC* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize); // 0x00416AD0
void __stdcall CheckRequests(ARCHIVEREC* pLastArchive, unsigned int nLastOffset, REQUEST** ppDue, REQUEST** ppNear, int* pnDistance); // 0x0041A450
extern unsigned int* gpCryptTable_00779048; // 0x00779048
extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030
extern const D2StormSignatureKeyStrc gaSignatureKeys_006CF07C[]; // 0x006CF07C
extern D2StormArchiveListStrc gArchiveList_00708354; // 0x00708354
extern D2StormEventListStrc gEventList_00708378; // 0x00708378
extern int gbThreadStop_00778F24; // 0x00778F24
extern void* ghStormEvent_00779054; // 0x00779054
extern unsigned int gnStreamChunk_00779038; // 0x00779038
extern unsigned char* gpStreamBuffer_00779050; // 0x00779050
extern "C" const char gszSFileCpp_006CF084[]; // 0x006CF084

struct D2StormBlockEntryStrc
{
    unsigned int nOffset;
    unsigned int nPackedSize;
    unsigned int nFileSize;
    unsigned int dwFlags;
};

struct D2StormQuadStrc
{
    int n00;
    int n04;
    int n08;
    int n0C;
};

struct D2StormFileSubStrc
{
    int pad00;
    int nSizeLow;
    unsigned int nSize;
    unsigned char unk_0C[0x4];
    __int64 nFileTime;
    int nValue;
    D2StormQuadStrc tQuad;
    unsigned char unk_2C[0x4];
};

extern D2StormStreamListStrc gDdaList_00708384; // 0x00708384
extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, __int64* pCreation, __int64* pAccess, __int64* pWrite);
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

struct PairStrc_00416810
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00416890
{
    int nFirst;
    int nSecond;
};

struct PairStrc_004168B0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00416960
{
    int nFirst;
    int nSecond;
};

struct PairStrc_004169A0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0041C390
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0041E8F0
{
    int nFirst;
    int nSecond;
};

extern int gdwGlobal_007792F4; // 0x007792F4

struct PairStrc_004203E0
{
    int nFirst;
    int nSecond;
};

struct PairStrc_00426920
{
    int nFirst;
    int nSecond;
};

extern char gData_006D17C8[]; // 0x006D17C8
extern char gData_006D3870[]; // 0x006D3870

struct D2IdentityView {
 D2StormLinkStrc link;
};

enum { NO_NODE = 0 };

struct D2SFileStormLinkM114Strc
{
    D2SFileStormLinkM114Strc* m_prevlink;
    char* m_next;

    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
    char* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
    char* sub_00417790_Next();
    char* sub_004178A0_Next();
    char* sub_004179A0_Next();
};

struct D2SFileNodeM114Strc
{
    char unk0x00[0x24];
    int nKey;
};

struct D2SFileStormListM114Strc
{
    D2SFileStormLinkM114Strc m_terminator;

    D2SFileNodeM114Strc* Head()
    {
        return (D2SFileNodeM114Strc*)m_terminator.Next();
    }
};

struct D2SFileOwnerM114Strc
{
    D2SFileStormListM114Strc* pList;
};

struct D2SFileArchiveM114Strc
{
    D2SFileOwnerM114Strc* pOwner;
    char unk0x04[0x20];
    int nKey;
};

extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2StormList00418490Strc : D2StormListBaseStrc { int sub_00418490_IsEmpty(); };

struct D2StormList004185B0Strc : D2StormListBaseStrc { int sub_004185B0_IsEmpty(); };

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority); // 0x006CC264
extern "C" void __cdecl __debugbreak();
unsigned long __stdcall CdThreadProc(void* pParam); // 0x0041A550
void __stdcall sub_0041C0F0_AppendExeMsgSource(unsigned short wFacility); // 0x0041C0F0

struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
};

struct CBitOutput
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    void sub_0041D9A0_Flush();
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0

    unsigned int adwData[0x3474 / 4];
};

struct CHuffman : THuffmannTree
{
    D2StormHuffLinkSlotStrc f_3474[0x80];

    CHuffman();
};


extern D2StormNodeListStrc gStormList_00708354; // 0x00708354
extern void* ghStormThread_00779034; // 0x00779034
extern int gnStormDirectFlags_00779058; // 0x00779058

struct D2StormHandlerStrc
{
    D2StormLinkStrc f_0;
    int unk0x08;

    D2StormHandlerStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
    ~D2StormHandlerStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormWndRecStrc
{
    D2StormLinkStrc f_0;
    int unk0x08;

    D2StormWndRecStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
    ~D2StormWndRecStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormNodeListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void sub_00420540_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);                       // 0x00420540
    char* sub_00420820_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_00420970_DeleteNode(char* pNode);
};

int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
int __stdcall SFileReadFileEx2(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0

inline void* operator new(unsigned int, void* pWhere) throw();
static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, ARCHIVEREC** ppRec);
static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, FILEREC** ppRec);

D2SystemTimeStrc gLogStartTime_0075D288; // 0x0075D288

int gnTimerTicksPerMs_0075E89C; // 0x0075E89C

int gnTimerTicksPerUs_0075E898; // 0x0075E898





int gnValueA_00779060; // 0x00779060

int gnValueB_00779064; // 0x00779064

int gnValue_0077904C; // 0x0077904C

int gnValueB_00779030; // 0x00779030

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




// 0x00413F30
unsigned int __fastcall bjhash(const unsigned char* k, unsigned int nLength, unsigned int nInitVal)
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
char* __stdcall SStrUpper(char* szString)
{
    return _strupr(szString);
}

// 0x00414200
char* __stdcall SStrLower(char* szString)
{
    return _strlwr(szString);
}

double __fastcall sub_00414220_PowInt(double x, int nExp); // 0x00414220

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
unsigned int __cdecl DecompressLzw_BufferRead(char* pBuffer, unsigned int* pnSize, D2StormBufferInfoStrc* pInfo)
{
    unsigned int nAvail = pInfo->nInSize - pInfo->nInPos;
    unsigned int nToRead = *pnSize < nAvail ? *pnSize : nAvail;
    SMemCopy(pBuffer, pInfo->pbInBuffer + pInfo->nInPos, nToRead);
    pInfo->nInPos += nToRead;
    return nToRead;
}

// 0x00415210
void __cdecl DecompressLzw_BufferWrite(char* pBuffer, unsigned int* pnSize, D2StormBufferInfoStrc* pInfo)
{
    SMemCopy(pInfo->pbOutBuffer + pInfo->f_C, pBuffer, *pnSize);
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
int __stdcall SFileGetBasePath(char* szBuffer, unsigned int nBufferSize)
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
int __stdcall SFileSetIoErrorMode(int nValueA, int nValueB)
{
    gnValueA_0070834C = nValueA;
    gnValueB_00779030 = nValueB;
    return 1;
}

// 0x004166D0
void __stdcall SFileSetLocale(unsigned short nValue)
{
    gwValue_0077905C = nValue;
}

#include "gen/data/Source/Storm/SOURCE/SFILE.inc"

// 0x00415190
int __fastcall sub_00415190_HasField14C(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord && pRecord->dwField14C)
    {
        return 1;
    }
    return 0;
}

// 0x004151B0
int __fastcall sub_004151B0_HasField150(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord && pRecord->dwField150)
    {
        return 1;
    }
    return 0;
}

// 0x00415730
void __fastcall sub_00415730_IncField148(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField148;
    }
}

// 0x00415740
static inline void sub_00415740_IncField144(D2SFileRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField144;
    }
}

// 0x00415750
static inline void sub_00415750_IncField4C(D2SFileOtherRecordViewStrc* pRecord)
{
    if (pRecord)
    {
        ++pRecord->dwField4C;
    }
}

void __fastcall sub_M103_Emit_00415740(D2SFileRecordViewStrc* pRecord, D2SFileOtherRecordViewStrc* pOther)
{
    sub_00415740_IncField144(pRecord);
    sub_00415750_IncField4C(pOther);
}

static REQUEST* gpCurrentRequest_0077902C; // 0x0077902C

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

static inline ARCHIVEREC* ArchiveHead()
{
    return (int)gpArchiveHead_0070835C > 0 ? gpArchiveHead_0070835C : 0;
}

static inline char* EventHead()
{
    return (int)gpEventHead_00708380 > 0 ? gpEventHead_00708380 : 0;
}

// 0x004152D0
static void sub_004152D0_DecryptBlock(unsigned int nKey, unsigned int* pData, unsigned int nBytes)
{
    unsigned int nSeed = 0xEEEEEEEE;
    unsigned int nCount = nBytes >> 2;
    while (nCount--)
    {
        nSeed += gpCryptTable_00779048[0x400 + (nKey & 0xFF)];
        *pData ^= nKey + nSeed;
        nSeed = *pData + nSeed + (nSeed << 5) + 3;
        ++pData;
        nKey = ((~nKey << 0x15) + 0x11111111) | (nKey >> 0x0B);
    }
}

// 0x00415330
static unsigned int __stdcall sub_00415330_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int nSeed1 = 0x7FED7FED;
    unsigned int nSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        unsigned int nChar = (unsigned char)toupper(*szString++);
        nSeed1 = gpCryptTable_00779048[(nHashType << 8) + nChar] ^ (nSeed1 + nSeed2);
        nSeed2 = nChar + nSeed2 + (nSeed2 << 5) + nSeed1 + 3;
    }
    return nSeed1;
}

// 0x004154B0
static int __stdcall ReadFileChecked(unsigned int* pnFilePos, void* pBuffer, unsigned int nSize, const char* szName, unsigned long* pnRead, unsigned int nOffset, void* hFile)
{
    int nRetry = 0;
    for (;;)
    {
        if (nOffset != -1)
            SetFilePointer(hFile, nOffset, 0, 0);
        const int bRead = ReadFile(hFile, pBuffer, nSize, pnRead, 0);
        *pnFilePos = *pnRead + nOffset;
        if (bRead)
        {
            if (*pnRead == nSize)
                return 1;
            sub_0041C340_SetLastError(0x26);
            return 0;
        }
        const unsigned long dwError = GetLastError();
        switch (gnValueA_0070834C)
        {
        case 0:
            return 0;
        case 1:
            if (!gpfnReadErrorCallback_00779030)
                return 0;
            if (!gpfnReadErrorCallback_00779030(szName, dwError, nRetry++))
                return 0;
            break;
        case 2:
            SErrDisplayError(dwError, szName, -4, 0, 0, 1);
            break;
        }
    }
}

// 0x00415560
static int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, unsigned int nOffset, FILEREC* pFile)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    ReadFileChecked(&nFilePos, pBuffer, nSize, pFile->szName, &nRead, nOffset, pFile->hFile);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
}

// 0x004155B0
static D2StormBlockStrc* sub_004155B0_GetBlockEntry(ARCHIVEREC* pArchive, int nHashIndex)
{
    return &pArchive->pBlockTable[pArchive->pHashTable[nHashIndex].nBlockIndex];
}

static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, ARCHIVEREC* pArchive, const char* szName)
{
    const unsigned int nHash = sub_00415330_HashString(0, szName);
    const unsigned int nName1 = sub_00415330_HashString(1, szName);
    const unsigned int nName2 = sub_00415330_HashString(2, szName);
    const unsigned int nMask = pArchive->pHeader->nHashEntries - 1;
    unsigned int nIndex = nMask & nHash;
    D2StormHashEntryStrc* pEntry = &pArchive->pHashTable[nIndex];
    const unsigned int nStart = nIndex;
    int nBest = -1;
    while (pEntry->nBlockIndex != -1)
    {
        if (pEntry->nName1 == nName1 && pEntry->nName2 == nName2 && pEntry->nBlockIndex != -2)
        {
            if (pEntry->wLocale == wLocale && pEntry->nPlatform == nPlatform)
                return nIndex;
            if ((!pEntry->wLocale || pEntry->wLocale == wLocale) && (!pEntry->nPlatform || pEntry->nPlatform == nPlatform))
                nBest = nIndex;
        }
        nIndex = (nIndex + 1) & nMask;
        if (nIndex == nStart)
            break;
        pEntry = &pArchive->pHashTable[nIndex];
    }
    return nBest;
}

static void sub_004157C0_FillStreamBuffer(REQUEST* pRequest)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    unsigned long nLocked;
    if (pRequest->pBuffer->Lock(pRequest->soundbufferoffset, gnStreamChunk_00779038, (void**)&pRequest->pDest, &nLocked, 0, 0, 0) >= 0
        && nLocked == gnStreamChunk_00779038)
    {
        unsigned int nCopy = nLocked;
        if (pRequest->nRead < nCopy)
            nCopy = pRequest->nRead;
        SMemCopy(pRequest->pDest, gpStreamBuffer_00779050, nCopy);
        if (nCopy < nLocked)
            SMemFill(pRequest->pDest + nCopy, nLocked - nCopy, pRequest->stream->nFill);
        pRequest->pBuffer->Unlock(pRequest->pDest, nLocked, 0, 0);
        const unsigned int nWritten = nLocked - pRequest->stream->waveheadersize;
        pRequest->stream->writecursor = nWritten + pRequest->location;
        if (pRequest->stream->writecursor > pRequest->stream->nSize)
            pRequest->stream->nCounter = pRequest->stream->writecursor - pRequest->stream->nSize;
        AUDIOSTREAM* pStream = pRequest->stream;
        if (pStream->fillstatus == 1)
        {
            const unsigned int nQueued = pRequest->nBytes - pStream->waveheadersize + pRequest->location;
            unsigned int nNeeded = 0x10000;
            if (pStream->nSize <= 0x10000)
                nNeeded = pStream->nSize;
            if (nNeeded >= pStream->soundbuffersize)
                nNeeded = pStream->soundbuffersize;
            if (nQueued >= nNeeded)
            {
                pRequest->stream->pBuffer->Play(0, 0, 1);
                pRequest->stream->fillstatus = 2;
            }
        }
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
}

// 0x00415940
static __declspec(noinline) int sub_00415940_PathPresent(const char* szPath)
{
    return ~(GetFileAttributesA(szPath) >> 4) & 1;
}

// 0x00415A80
static void __stdcall sub_00415A80_BuildPath(int bStripPath, const char* szName, char* szOut)
{
    if (!gszBasePath_00778F28[0])
        sub_004158E0_InitBasePath();
    if (bStripPath)
    {
        const char* szSlash = SStrChrR(szName, 0x5C);
        if (szSlash)
            szName = szSlash + 1;
    }
    char szBuffer[0x104];
    wsprintfA(szBuffer, "%s%s", gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

// 0x00415B00
static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut)
{
    int bResult = 0;
    if (nFlags & 3)
    {
        if (nFlags & 2)
        {
            sub_00415A80_BuildPath(1, szName, szOut);
            bResult = sub_00415940_PathPresent(szOut);
            if (bResult)
                return bResult;
        }
        if (nFlags & 1)
        {
            if (*szName != 0x5C && !strstr(szName, ":\\") && !strstr(szName, "\\\\"))
            {
                sub_00415A80_BuildPath(0, szName, szOut);
                return sub_00415940_PathPresent(szOut);
            }
            SStrCopy(szOut, szName, 0x104);
            return sub_00415940_PathPresent(szOut);
        }
    }
    return bResult;
}

// 0x00416FB0
static unsigned int sub_00416FB0_LoadBlock(unsigned int nOffset, FILEREC* pFile)
{
    if (pFile->archive->pCachedFile == pFile && pFile->archive->nCachedOffset == nOffset)
        return pFile->archive->nCachedSize;
    unsigned int nSize = pFile->archive->sectorsize;
    D2StormBlockStrc* pBlock = pFile->pBlock;
    if (nOffset + nSize > pBlock->nFileSize && !(pBlock->dwFlags & 0xFF00))
        nSize = pBlock->nFileSize - nOffset;
    pFile->archive->pCachedFile = pFile;
    pFile->archive->nCachedOffset = nOffset;
    pFile->archive->nCachedSize = InternalReadAligned(pFile, nOffset, pFile->archive->pBlockBuffer, nSize);
    return pFile->archive->nCachedSize;
}

static unsigned int __stdcall InternalReadUnaligned(unsigned char* pBuffer, unsigned int nSize, FILEREC* pFile, unsigned int nPosition)
{
    const unsigned int nFileSize = pFile->pBlock->nFileSize;
    if (nFileSize <= nPosition)
        return 0;
    nSize = nSize < nFileSize - nPosition ? nSize : nFileSize - nPosition;
    if (pFile->bCrc && !nPosition)
    {
        sub_0041D810_Crc32(0, 0, &pFile->nCrc, 1);
        pFile->nCrcPos = 0;
        pFile->nCrcState = 2;
    }
    unsigned int nHead = 0;
    if (nPosition & (pFile->archive->sectorsize - 1))
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nHead = sub_00416FB0_LoadBlock(~(pFile->archive->sectorsize - 1) & nPosition, pFile);
        unsigned int nCopy = nSize;
        if (nCopy >= pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition))
            nCopy = pFile->archive->sectorsize - ((pFile->archive->sectorsize - 1) & nPosition);
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer + ((pFile->archive->sectorsize - 1) & nPosition), nCopy);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            sub_0041D810_Crc32(pBuffer, nCopy, &pFile->nCrc, 2);
            pFile->nCrcPos += nCopy;
        }
        pBuffer += nCopy;
        nSize -= nCopy;
        if (nHead != pFile->archive->sectorsize || !nSize)
        {
            const unsigned int nSkip = (pFile->archive->sectorsize - 1) & nPosition;
            if (nHead < nSkip)
                return 0;
            return nCopy < nHead - nSkip ? nCopy : nHead - nSkip;
        }
        nHead = nCopy;
        nPosition += nCopy;
    }
    unsigned int nMiddle = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        const unsigned int nAligned = ~(pFile->archive->sectorsize - 1) & nSize;
        nMiddle = InternalReadAligned(pFile, nPosition, pBuffer, nAligned);
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            sub_0041D810_Crc32(pBuffer, nMiddle, &pFile->nCrc, 2);
            pFile->nCrcPos += nMiddle;
        }
        pBuffer += nAligned;
        nSize -= nAligned;
        nPosition += nAligned;
        if (nAligned != nMiddle || !nSize)
            return nMiddle + nHead;
    }
    unsigned int nTail = 0;
    if (nSize)
    {
        if (pFile->bCrc && pFile->nCrcState != 1 && pFile->nCrcPos != nPosition)
            pFile->nCrcState = 1;
        nTail = sub_00416FB0_LoadBlock(nPosition, pFile);
        SMemCopy(pBuffer, pFile->archive->pBlockBuffer, nSize);
        if (nSize < nTail)
            nTail = nSize;
        if (pFile->bCrc && pFile->nCrcState == 2)
        {
            sub_0041D810_Crc32(pBuffer, nTail, &pFile->nCrc, 2);
            pFile->nCrcPos += nTail;
        }
    }
    return nMiddle + nTail + nHead;
}

int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult)
{
    if (SFileAuthenticateArchiveEx(hArchive, pnResult, 0, 0, 0, 0))
        return 1;
    if (pnResult)
        *pnResult = 0;
    ARCHIVEREC* pArchive;
    if (!sub_00415930_GetArchiveRec(hArchive, &pArchive))
        return 0;
    int bResult = 0;
    if (sub_004155D0_FindHashEntry(0, 0, pArchive, "(signature)") == -1)
    {
        if (pnResult)
            *pnResult = 1;
        sub_0041C340_SetLastError(0x4DC);
        return 0;
    }
    D2StormCryptFuncsStrc* pFuncs = 0;
    unsigned int hHash = 0;
    unsigned int hKey = 0;
    void* hMapping = 0;
    unsigned int hProv = 0;
    unsigned char* pView = 0;
    void* hLibrary = LoadLibraryA("advapi32.dll");
    if (hLibrary)
    {
        pFuncs = (D2StormCryptFuncsStrc*)SMemAlloc(sizeof(D2StormCryptFuncsStrc), ".\\SOURCE\\SFILE.CPP", 0xA74, 0);
        if (!(pFuncs->pfnAcquireContext = (D2CryptAcquireContextFn)GetProcAddress(hLibrary, "CryptAcquireContextA")))
            goto cleanup;
        if (!(pFuncs->pfnCreateHash = (D2CryptCreateHashFn)GetProcAddress(hLibrary, "CryptCreateHash")))
            goto cleanup;
        if (!(pFuncs->pfnDestroyHash = (D2CryptDestroyFn)GetProcAddress(hLibrary, "CryptDestroyHash")))
            goto cleanup;
        if (!(pFuncs->pfnDestroyKey = (D2CryptDestroyFn)GetProcAddress(hLibrary, "CryptDestroyKey")))
            goto cleanup;
        if (!(pFuncs->pfnHashData = (D2CryptHashDataFn)GetProcAddress(hLibrary, "CryptHashData")))
            goto cleanup;
        if (!(pFuncs->pfnImportKey = (D2CryptImportKeyFn)GetProcAddress(hLibrary, "CryptImportKey")))
            goto cleanup;
        if (!(pFuncs->pfnReleaseContext = (D2CryptReleaseContextFn)GetProcAddress(hLibrary, "CryptReleaseContext")))
            goto cleanup;
        if (!(pFuncs->pfnSignHash = (D2CryptSignHashFn)GetProcAddress(hLibrary, "CryptSignHashA")))
            goto cleanup;
        if (!(pFuncs->pfnVerifySignature = (D2CryptVerifySignatureFn)GetProcAddress(hLibrary, "CryptVerifySignatureA")))
            goto cleanup;
        if (!pFuncs->pfnAcquireContext(&hProv, "Blizzard_Storm", "Microsoft Base Cryptographic Provider v1.0", 1, 0)
            && !pFuncs->pfnAcquireContext(&hProv, "Blizzard_Storm", "Microsoft Base Cryptographic Provider v1.0", 1, 8))
            goto cleanup;
        hMapping = CreateFileMappingA(pArchive->hFile, 0, 0x8000002, 0, 0, 0);
        if (!hMapping)
            goto cleanup;
        pView = (unsigned char*)MapViewOfFile(hMapping, 4, 0, 0, 0);
        if (!pView)
            goto cleanup;
        const int nIndex = sub_004155D0_FindHashEntry(0, 0, pArchive, "(signature)");
        if (nIndex == -1)
            goto cleanup;
        D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pArchive, nIndex);
        if ((pBlock->dwFlags & 0x1FF00) || pBlock->nFileSize <= 8 || !pBlock->nOffset)
        {
            if (pnResult)
                *pnResult = 2;
            goto cleanup;
        }
        const unsigned int nKeyIndex = *(unsigned int*)(pBlock->nOffset + pView);
        if (nKeyIndex >= 1)
        {
            if (pnResult)
                *pnResult = 3;
            goto cleanup;
        }
        void* hResInfo = FindResourceA(StormGetInstance(), gaSignatureKeys_006CF07C[nKeyIndex].szResourceName, "#256");
        void* hResData = LoadResource(StormGetInstance(), hResInfo);
        void* pKey = LockResource(hResData);
        if (pKey)
            pFuncs->pfnImportKey(hProv, pKey, SizeofResource(StormGetInstance(), hResInfo), 0, 0, &hKey);
        FreeResource(hResData);
        if (!hKey)
            goto cleanup;
        if (!pFuncs->pfnCreateHash(hProv, 0x8003, 0, 0, &hHash))
            goto cleanup;
        if (!pFuncs->pfnHashData(hHash, pView + pArchive->nArchiveOffset, pBlock->nOffset - pArchive->nArchiveOffset, 0))
            goto cleanup;
        unsigned char* pZero = (unsigned char*)SMemAlloc(pBlock->nFileSize, ".\\SOURCE\\SFILE.CPP", 0xACA, 8);
        const int bHashed = pFuncs->pfnHashData(hHash, pZero, pBlock->nFileSize, 0);
        SMemFree(pZero, ".\\SOURCE\\SFILE.CPP", 0xACF, 0);
        if (!bHashed)
            goto cleanup;
        const unsigned int nArchiveSize = pArchive->pHeader->nArchiveSize;
        const unsigned int nSignatureEnd = pBlock->nOffset + pBlock->nFileSize;
        const unsigned int nArchiveOffset = pArchive->nArchiveOffset;
        if (nSignatureEnd < nArchiveSize + nArchiveOffset)
        {
            if (!pFuncs->pfnHashData(hHash, pView + nSignatureEnd, nArchiveSize - pBlock->nOffset - pBlock->nFileSize + nArchiveOffset, 0))
                goto cleanup;
        }
        if (pFuncs->pfnVerifySignature(hHash, pView + pBlock->nOffset + 8, pBlock->nFileSize - 8, hKey, 0, 0))
        {
            bResult = 1;
            if (pnResult)
                *pnResult = gaSignatureKeys_006CF07C[nKeyIndex].nResult;
        }
        else
        {
            if (pnResult)
                *pnResult = 2;
        }
    }
cleanup:
    if (hHash)
        pFuncs->pfnDestroyHash(hHash);
    if (hKey)
        pFuncs->pfnDestroyKey(hKey);
    if (pView)
        UnmapViewOfFile(pView);
    if (hMapping)
        CloseHandle(hMapping);
    if (hProv)
    {
        pFuncs->pfnReleaseContext(hProv, 0);
        pFuncs->pfnAcquireContext(&hProv, "Blizzard_Storm", "Microsoft Base Cryptographic Provider v1.0", 1, 0x10);
    }
    if (pFuncs)
        SMemFree(pFuncs, ".\\SOURCE\\SFILE.CPP", 0xAF8, 0);
    if (hLibrary)
        FreeLibrary(hLibrary);
    if (!bResult)
        sub_0041C340_SetLastError(0x4DC);
    return bResult;
}

int __fastcall GetFileBlockEntry(void* hArchive, D2StormBlockStrc** ppBlock, const char* szName, unsigned int nFlags, ARCHIVEREC** ppArchive, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    ARCHIVEREC* pOnly = 0;
    if (hArchive && !sub_00415930_GetArchiveRec(hArchive, &pOnly))
        return bResult;
    ARCHIVEREC* pArchive = ArchiveHead();
    do
    {
        if (pOnly && pArchive != pOnly)
            continue;
        if (pArchive && pArchive->nRefs > 0)
            continue;
        ARCHIVEREC* pSearch = pArchive;
        if (pArchive && pArchive->pPatch)
            pSearch = pArchive->pPatch;
        const char* szLookup = szName;
        char szPrefixed[0x104];
        if (pArchive && pArchive->szPrefix[0])
        {
            char* szEnd = szPrefixed + SStrCopy(szPrefixed, pArchive->szPrefix, 0x104);
            szEnd += SStrCopy(szEnd, "\\", 0x104);
            SStrCopy(szEnd, szName, 0x104);
            szLookup = szPrefixed;
        }
        char szDiskPath[0x104];
        if ((nFlags & 3) && (!pSearch || !pSearch->bNoDiskSearch)
            && sub_00415B00_FindDiskFile(nFlags, szLookup, szDiskPath))
        {
            if (szFoundPath)
                SStrCopy(szFoundPath, szDiskPath, 0x104);
            return 2;
        }
        if (pArchive)
        {
            const int nIndex = sub_004155D0_FindHashEntry(gwLocale_0077905C, gnPlatform_0077905E, pSearch, szLookup);
            if (nIndex != -1)
            {
                bResult = 1;
                D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pSearch, nIndex);
                if ((int)pBlock->dwFlags >= 0 || ((nFlags & 4) && (pBlock->dwFlags & 0x1FF00)))
                {
                    sub_0041C340_SetLastError(0x3EE);
                    bResult = 0;
                }
                else
                {
                    if (ppArchive)
                        *ppArchive = pSearch;
                    if (ppBlock)
                        *ppBlock = pBlock;
                }
                return bResult;
            }
        }
    }
    while (pArchive && (pArchive = (ARCHIVEREC*)pArchive->tLink.Next()) != 0);
    sub_0041C340_SetLastError(2);
    return 0;
}

unsigned long __stdcall CdThreadProc(void* pParam)
{
    ARCHIVEREC* pLastArchive = 0;
    unsigned int nLastOffset = 0;
    unsigned long nLastTime = GetTickCount();
    while (!gbThreadStop_00778F24)
    {
        const unsigned long nNow = GetTickCount();
        unsigned long nWait = 0;
        if (gnReadRate_0077904C)
            nWait = gnReadUnit_00708348 * 1000 / gnReadRate_0077904C;
        EnterCriticalSection(&gBasePathLock_00779068);
        for (char* pNode = EventHead(); (int)pNode > 0; )
        {
            SetEvent(((EVENTREC*)pNode)->hEvent);
            pNode = gEventList_00708378.sub_00419690_DeleteNode(pNode);
        }
        sub_00419C00_PumpStreams();
        REQUEST* pNear;
        int nDistance;
        REQUEST* pDue;
        CheckRequests(pLastArchive, nLastOffset, &pDue, &pNear, &nDistance);
        REQUEST* pRequest = pNear;
        if (!pRequest || nDistance > 1000)
        {
            pRequest = pDue;
            if (!pRequest || nNow - nLastTime < nWait)
            {
                LeaveCriticalSection(&gBasePathLock_00779068);
                if (pRequest)
                    nWait = nWait - nNow + nLastTime;
                else
                    nWait = 0xFA;
                WaitForSingleObject(ghStormEvent_00779054, nWait);
                continue;
            }
        }
        pLastArchive = pRequest->pFile->archive;
        nLastOffset = pRequest->nFileOffset;
        gpCurrentRequest_0077902C = pRequest;
        nLastTime = nNow;
        pRequest->tLink.Unlink();
        LeaveCriticalSection(&gBasePathLock_00779068);
        unsigned char* pDest = !gpCurrentRequest_0077902C->pBuffer ? gpCurrentRequest_0077902C->pDest : gpStreamBuffer_00779050;
        if (pDest)
        {
            if (gpCurrentRequest_0077902C->pFile->hFile == INVALID_FILE_HANDLE)
            {
                gpCurrentRequest_0077902C->nRead = InternalReadUnaligned(pDest, gpCurrentRequest_0077902C->nBytes, gpCurrentRequest_0077902C->pFile, gpCurrentRequest_0077902C->location);
                FILEREC* pFile = gpCurrentRequest_0077902C->pFile;
                if (pFile->bCrc && pFile->nCrcState == 2 && pFile->nCrcPos == pFile->pBlock->nFileSize)
                {
                    sub_0041D810_Crc32(0, 0, &pFile->nCrc, 4);
                    gpCurrentRequest_0077902C->pFile->nCrcState = 4;
                }
            }
            else
            {
                sub_00415560_ReadFileRec(pDest, gpCurrentRequest_0077902C->nBytes, &gpCurrentRequest_0077902C->nRead, gpCurrentRequest_0077902C->location, gpCurrentRequest_0077902C->pFile);
            }
        }
        else
        {
            gpCurrentRequest_0077902C->nRead = 0;
        }
        if (gpCurrentRequest_0077902C->pBuffer)
        {
            if (gpCurrentRequest_0077902C->nRead)
            {
                sub_004157C0_FillStreamBuffer(gpCurrentRequest_0077902C);
            }
            else if (gpCurrentRequest_0077902C->nBytes)
            {
                gpCurrentRequest_0077902C->pBuffer->Stop();
                if (gpCurrentRequest_0077902C->stream)
                    gpCurrentRequest_0077902C->stream->fillstatus = 4;
            }
        }
        if (gpCurrentRequest_0077902C->pCallback && gpCurrentRequest_0077902C->pCallback->pfnDone)
        {
            FILEREC* pFile = gpCurrentRequest_0077902C->pFile;
            if (pFile->bCrc && pFile->nCrcState == 4 && pFile->nCrc != pFile->pBlock->nCrc)
                SErrDisplayError(0x85100083, pFile->szName, -4, 0, 0, 1);
            gpCurrentRequest_0077902C->pCallback->pfnDone(gpCurrentRequest_0077902C->nDestSize, gpCurrentRequest_0077902C->nRead + gpCurrentRequest_0077902C->pDest - gpCurrentRequest_0077902C->nDestSize, gpCurrentRequest_0077902C->pCallback);
        }
        void* hEvent = gpCurrentRequest_0077902C->hEvent;
        EnterCriticalSection(&gBasePathLock_00779068);
        if (gpCurrentRequest_0077902C->bDelete)
        {
            REQUEST* pDone = gpCurrentRequest_0077902C;
            pDone->~REQUEST();
            SMemFree(pDone, "delete", -1, 0);
        }
        gpCurrentRequest_0077902C = 0;
        LeaveCriticalSection(&gBasePathLock_00779068);
        if (hEvent)
            SetEvent(hEvent);
    }
    gbThreadStop_00778F24 = 0;
    return 0;
}

int __fastcall s_OpenArchive(ARCHIVEREC* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive)
{
    unsigned char* pBuffer = (unsigned char*)SMemAlloc(0x1000, ".\\SOURCE\\SFILE.CPP", 0x10C2, 0);
    unsigned int nBufferStart = 0;
    unsigned int nBufferSize = 0;
    for (;;)
    {
        if (pArchive->nArchiveOffset >= nBufferStart + nBufferSize)
        {
            nBufferStart = pArchive->nArchiveOffset;
            SetFilePointer(pArchive->hFile, nBufferStart, 0, 0);
            unsigned long nRead = 0;
            ReadFile(pArchive->hFile, pBuffer, 0x1000, &nRead, 0);
            if (nRead < sizeof(D2StormMpqHeaderStrc) || pArchive->nArchiveOffset + sizeof(D2StormMpqHeaderStrc) >= pArchive->nArchiveLimit)
            {
                pArchive->~ARCHIVEREC();
                SMemFree(pArchive, "delete", -1, 0);
                sub_0041C340_SetLastError(0x8510006C);
                SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x10DF, 0);
                return 0;
            }
            nBufferSize = nRead;
        }
        SMemCopy(pArchive->pHeader, pBuffer + pArchive->nArchiveOffset - nBufferStart, sizeof(D2StormMpqHeaderStrc));
        if (pArchive->pHeader->dwSignature == 0x1A51504D && pArchive->pHeader->nHeaderSize >= sizeof(D2StormMpqHeaderStrc))
            break;
        pArchive->nArchiveOffset += 0x200;
    }
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1106, 0);
    pArchive->sectorsize = 0x200 << pArchive->pHeader->nSectorShift;
    pArchive->pBlockBuffer = (unsigned char*)SMemAlloc(pArchive->sectorsize, ".\\SOURCE\\SFILE.CPP", 0x110B, 0);
    pArchive->pHashTable = (D2StormHashEntryStrc*)SMemAlloc(pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), ".\\SOURCE\\SFILE.CPP", 0x1114, 0);
    unsigned long nRead;
    ReadFileChecked(&pArchive->nFilePos, pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc), pArchive->szName, &nRead, pArchive->pHeader->nHashOffset + pArchive->nArchiveOffset, pArchive->hFile);
    unsigned int nKey = sub_00415330_HashString(3, "(hash table)");
    sub_004152D0_DecryptBlock(nKey, (unsigned int*)pArchive->pHashTable, pArchive->pHeader->nHashEntries * sizeof(D2StormHashEntryStrc));
    pArchive->pBlockTable = (D2StormBlockStrc*)SMemAlloc(pArchive->pHeader->nBlockEntries * sizeof(D2StormBlockStrc), ".\\SOURCE\\SFILE.CPP", 0x1133, 0);
    ReadFileChecked(&pArchive->nFilePos, pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4, pArchive->szName, &nRead, pArchive->pHeader->nBlockOffset + pArchive->nArchiveOffset, pArchive->hFile);
    nKey = sub_00415330_HashString(3, "(block table)");
    sub_004152D0_DecryptBlock(nKey, (unsigned int*)pArchive->pBlockTable, pArchive->pHeader->nBlockEntries << 4);
    pArchive->pBlockTable->sub_004156A0_ExpandEntries(pArchive->pHeader->nBlockEntries);
    if (pArchive->nArchiveOffset)
    {
        for (unsigned int i = 0; i < pArchive->pHeader->nBlockEntries; ++i)
        {
            if (pArchive->pBlockTable[i].nOffset)
                pArchive->pBlockTable[i].nOffset += pArchive->nArchiveOffset;
        }
    }
    ARCHIVEREC* pExisting;
    for (pExisting = gArchiveList_00708354.Head(); pExisting; pExisting = (ARCHIVEREC*)pExisting->tLink.Next())
    {
        if (pExisting->nPriority <= pArchive->nPriority)
            break;
    }
    gArchiveList_00708354.LinkBefore(pArchive, pExisting);
    if (pArchive->nMode)
    {
        sub_0041A880_StartThread();
    }
    else if ((nFlags & 1) && !bKeepOnFail)
    {
        SFileCloseArchive(pArchive);
        sub_0041C340_SetLastError(0x0F);
        return 0;
    }
    *phArchive = pArchive;
    LeaveCriticalSection(&gBasePathLock_00779068);
    pArchive->ReadAdditionalAttributes(pArchive->pBlockTable, pArchive->pHeader->nBlockEntries);
    EnterCriticalSection(&gBasePathLock_00779068);
    return 1;
}

int __stdcall SFileOpenFileAsArchive(void* hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive)
{
    void* hFile;
    if (!SFileOpenFileEx(hMpq, szName, sub_00418B50(), &hFile))
        return 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pFile;
    sub_00415950_GetFileRec(hFile, &pFile);
    if (pFile->hFile != INVALID_FILE_HANDLE)
    {
        SFileCloseFile(hFile);
        LeaveCriticalSection(&gBasePathLock_00779068);
        char szPath[0x104];
        sub_00415B00_FindDiskFile(sub_00418B50(), szName, szPath);
        return SFileOpenArchive(szName, nPriority, nFlags, phArchive);
    }
    if (pFile->pBlock->dwFlags & 0x1FF00)
    {
        SFileCloseFile(hFile);
        sub_0041C340_SetLastError(0x3EE);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    void* pMemory = SMemAlloc(sizeof(ARCHIVEREC), gszTypeNameArchiveRec_00708398, -2, 8);
    ARCHIVEREC* pArchive = pMemory ? new (pMemory) ARCHIVEREC : 0;
    SStrCopy(pArchive->szName, szName, 0x104);
    pArchive->hFile = pFile->archive->hFile;
    pArchive->nMode = pFile->archive->nMode;
    pArchive->bNoDiskSearch = (nFlags >> 2) & 1;
    pArchive->nPriority = nPriority;
    pArchive->nRefs = 0;
    pArchive->bNested = 1;
    pArchive->hNestedFile = hFile;
    pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), ".\\SOURCE\\SFILE.CPP", 0x11AD, 0);
    pArchive->nArchiveOffset = pFile->pBlock->nOffset;
    pArchive->nArchiveLimit = pFile->pBlock->nFileSize + pFile->pBlock->nOffset;
    s_OpenArchive(pArchive, nFlags, pArchive->nMode, phArchive);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00415390
static void sub_00415390_PrepareCryptTable(unsigned int dwSeed)
{
    if (!gpCryptTable_00779048)
    {
        gpCryptTable_00779048 = (unsigned int*)SMemAlloc(0x1400, gszSFileCpp_006CF084, 832, 0);
    }

    unsigned int* pTable = gpCryptTable_00779048;
    for (unsigned int i = 0; i < 0x100; ++i)
    {
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x100];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x200];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x300];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x400];
            *pEntry = dwValue;
        }
    }
}

// 0x00415B90
void __cdecl sub_00415B90_InitCryptTable()
{
    if (!gpCryptTable_00779048)
    {
        sub_00415390_PrepareCryptTable(0x100001);
    }
}

// 0x004156A0
void D2StormBlockStrc::sub_004156A0_ExpandEntries(unsigned int nCount)
{
    D2StormBlockEntryStrc* pSrc = (D2StormBlockEntryStrc*)this + nCount - 1;
    D2StormBlockStrc* pRec = this + nCount - 1;
    if (nCount > 1)
    {
        unsigned int* pClear = &pRec->unk0x1C[2];
        unsigned int nLeft = nCount - 1;
        do
        {
            memmove(pRec, pSrc, sizeof(D2StormBlockEntryStrc));
            --pSrc;
            pClear[-4] = 0;
            pClear[-5] = 0;
            pClear[-3] = 0;
            pClear[-2] = 0;
            pClear[-1] = 0;
            pClear[0] = 0;
            pClear[1] = 0;
            --pRec;
            pClear -= sizeof(D2StormBlockStrc) / sizeof(unsigned int);
        } while (--nLeft);
    }
    if (nCount)
    {
        pRec->unk0x14 = 0;
        pRec->unk0x10 = 0;
        pRec->nCrc = 0;
        pRec->unk0x1C[0] = 0;
        pRec->unk0x1C[1] = 0;
        pRec->unk0x1C[2] = 0;
        pRec->unk0x1C[3] = 0;
    }
}

D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068

// 0x00415930
static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, ARCHIVEREC** ppRec)
{
    *ppRec = (ARCHIVEREC*)hArchive;
    return 1;
}

// 0x00415950
static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, FILEREC** ppRec)
{
    *ppRec = (FILEREC*)hFile;
    return 1;
}

// 0x00415F10
int __stdcall sub_00415F10_AdjustArchiveRefs(void* hArchive, int bRelease)
{
    ARCHIVEREC* pRec;
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    pRec->nRefs += bRelease ? -1 : 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00415FA0
int __stdcall SFileGetArchiveInfo(void* hArchive, int* pnInfo, int* pbKind3)
{
    if (pnInfo)
        *pnInfo = 0;
    if (pbKind3)
        *pbKind3 = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    ARCHIVEREC* pRec;
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pnInfo)
        *pnInfo = pRec->nInfo;
    if (pbKind3)
        *pbKind3 = pRec->nKind == 3;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416160
int __stdcall sub_00416160_GetFileSubValue(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    const int nValue = pRec->f_118->nValue;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nValue;
}

// 0x004161C0
int __stdcall sub_004161C0_GetFileSubQuad(void* hFile, D2StormQuadStrc* pQuad)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    *pQuad = pRec->f_118->tQuad;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416320
int __stdcall SFileGetFileCompressedSize(void* hFile, int* pnSizeHigh)
{
    int nResult = 0;
    if (pnSizeHigh)
        *pnSizeHigh = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (sub_00415950_GetFileRec(hFile, &pRec) && pRec->nKind == -1)
        nResult = pRec->f_118->nSizeLow;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

// 0x004181F0
int __stdcall SFileDdaGetVolume(void* hFile, int* pnVolume, int* pnPan)
{
    if (pnVolume)
        *pnVolume = 0;
    if (pnPan)
        *pnPan = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    AUDIOSTREAM* pNode;
    for (pNode = gDdaList_00708384.Head(); pNode; pNode = (AUDIOSTREAM*)pNode->tLink.Next())
    {
        if (pNode->pFile == pRec)
            break;
    }
    if (!pNode)
    {
        sub_0041C340_SetLastError(0x85100072);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pNode->nVolume == 0x7FFFFFFF)
        pNode->pBuffer->GetVolume((long*)&pNode->nVolume);
    if (pNode->nPan == 0x7FFFFFFF)
        pNode->pBuffer->GetPan((long*)&pNode->nPan);
    if (pnVolume)
        *pnVolume = pNode->nVolume;
    if (pnPan)
        *pnPan = pNode->nPan;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004182D0
int __stdcall SFileDdaSetVolume(void* hFile, int nVolume, int nPan)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    AUDIOSTREAM* pNode;
    for (pNode = gDdaList_00708384.Head(); pNode; pNode = (AUDIOSTREAM*)pNode->tLink.Next())
    {
        if (pNode->pFile == pRec)
            break;
    }
    if (!pNode)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        sub_0041C340_SetLastError(0x85100072);
        return 0;
    }
    if (nVolume != 0x7FFFFFFF && nVolume != pNode->nVolume)
    {
        pNode->nVolume = nVolume;
        pNode->pBuffer->SetVolume(nVolume);
    }
    if (nPan != 0x7FFFFFFF && nPan != pNode->nPan)
    {
        pNode->nPan = nPan;
        pNode->pBuffer->SetPan(nPan);
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416030
int __stdcall SFileGetArchiveName(void* hArchive, char* szBuffer, unsigned int nBufferSize)
{
    if (szBuffer)
        *szBuffer = 0;
    if (!szBuffer)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    ARCHIVEREC* pRec;
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    SStrCopy(szBuffer, pRec->szFileName, nBufferSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004160F0
int __stdcall SFileGetFileArchive(void* hFile, int* pValue)
{
    if (pValue) *pValue = 0;
    if (!pValue) {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec)) {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    *pValue = pRec->nValue;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416230
int __stdcall sub_00416230_GetFileName(void* hFile, char* szBuffer, unsigned int nSize)
{
    if (szBuffer)
        *szBuffer = 0;
    if (!szBuffer)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    SStrCopy(szBuffer, pRec->szName, nSize);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004162A0
int __stdcall SFileGetFileName(void* hFile, char* dest, unsigned int size)
{
 if (dest)
  *dest = 0;
 if (!dest) { sub_0041C340_SetLastError(0x57); return 0; }
 EnterCriticalSection(&gBasePathLock_00779068);
 FILEREC* rec;
 if (!sub_00415950_GetFileRec(hFile, &rec)) {
  LeaveCriticalSection(&gBasePathLock_00779068);
  return 0;
 }
 SStrCopy(dest, rec->fullName ? rec->fullName : rec->name, size);
 LeaveCriticalSection(&gBasePathLock_00779068);
 return 1;
}

char gszBasePath_00778F28[260]; // 0x00778F28

// 0x00416400
int __stdcall sub_00416400_GetFileTime(void* hFile, __int64* pFileTime)
{
    VALIDATEBEGIN;
    VALIDATE(pFileTime);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return GetFileTime((void*)pRec->nKind, 0, 0, pFileTime);
    }

    *pFileTime = pRec->f_118->nFileTime;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nValid ? 1 : 0;
}

// 0x004164B0
int __stdcall SFileSetBasePath(const char* szPath)
{
    VALIDATEBEGIN;
    VALIDATE(szPath);
    VALIDATEEND;

    if (!*szPath)
    {
        gszBasePath_00778F28[0] = 0;
    }
    else
    {
        const int bBackslash = szPath[SStrLen(szPath) - 1] == '\\';
        if (SStrLen(szPath) + !bBackslash + 1 > 0x104)
        {
            sub_0041C340_SetLastError(0xA1);
            return 0;
        }

        EnterCriticalSection(&gBasePathLock_00779068);
        SStrCopy(gszBasePath_00778F28, szPath, 0x104);
        if (!bBackslash)
            SStrPack(gszBasePath_00778F28, "\\", 0x104);
        LeaveCriticalSection(&gBasePathLock_00779068);
    }

    return nValid ? 1 : 0;
}

// 0x00416570
void __stdcall SFileSetDataChunkSize(int nChunkSize)
{
    VALIDATEBEGIN;
    VALIDATE(!(nChunkSize & (nChunkSize - 1)));
    VALIDATEENDVOID;
    if (nValid)
        gnReadUnit_00708348 = nChunkSize;
}

// 0x00416710
int __stdcall SFileUnloadFile(void* pBuffer)
{
    VALIDATEBEGIN;
    VALIDATE(pBuffer);
    VALIDATEEND;
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1407, 0);
    return nValid ? 1 : 0;
}

// 0x004165A0
unsigned long __stdcall SFileSetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod)
{
    if (pnDistanceHigh && *pnDistanceHigh)
    {
        sub_0041C340_SetLastError(0x57);
        return (unsigned long)-1;
    }

    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return (unsigned long)-1;
    }

    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return SetFilePointer((void*)pRec->nKind, nDistance, 0, dwMoveMethod);
    }

    switch (dwMoveMethod)
    {
    case 0:
        pRec->nPosition = nDistance;
        break;

    case 1:
        if (nDistance < 0 && pRec->nPosition < (unsigned long)-nDistance)
        {
            pRec->nPosition = 0;
        }
        else
        {
            pRec->nPosition += nDistance;
        }
        break;

    case 2:
        if (nDistance < 0 && pRec->f_118->nSize < (unsigned long)-nDistance)
        {
            pRec->nPosition = 0;
        }
        else
        {
            pRec->nPosition = pRec->f_118->nSize + nDistance;
        }
        break;
    }

    pRec->n13C = 0;
    pRec->n140 = 0;
    const unsigned long nResult = pRec->nPosition;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

unsigned short gwValue_0077905C; // 0x0077905C

// 0x004166F0
unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

// 0x00416750
void __stdcall sub_00416750_Nop()
{
}

// 0x00416760
void __stdcall sub_00416760_Nop()
{
}

// 0x004167A0
char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x004167B0
D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    tLink.Unlink();
}

// 0x004167F0
char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416800
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00416820
char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416830
char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416840
char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00416850
char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00416860
char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

// 0x00416880
char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x004168F0
D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    tLink.Unlink();
}

// 0x004169F0
void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A00
void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A10
void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A20
void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A30
void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00416A90
int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

// 0x00416AB0
int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

// 0x00416770
D2StormLinkStrc* D2StormLinkStrc::sub_00416770_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004168C0
D2StormLinkStrc* D2StormLinkStrc::sub_004168C0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00416930
D2StormLinkStrc* D2StormLinkStrc::sub_00416930_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00416970
D2StormLinkStrc* D2StormLinkStrc::sub_00416970_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004169B0
D2StormLinkStrc* D2StormLinkStrc::sub_004169B0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00417A10
D2StormLinkStrc* D2StormFixedListStrc::sub_00417A10_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417A50
D2StormLinkStrc* D2StormFixedListStrc::sub_00417A50_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417A70
void D2StormFixedListStrc::sub_00417A70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417B20
char* D2StormFixedListStrc::sub_00417B20_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417B60
D2StormLinkStrc* D2StormFixedListStrc::sub_00417B60_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417B80
void D2StormFixedListStrc::sub_00417B80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417C50
D2StormLinkStrc* D2StormFixedListStrc::sub_00417C50_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417C70
void D2StormFixedListStrc::sub_00417C70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417D20
char* D2StormFixedListStrc::sub_00417D20_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417D60
D2StormLinkStrc* D2StormFixedListStrc::sub_00417D60_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417D80
void D2StormFixedListStrc::sub_00417D80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417E30
char* D2StormFixedListStrc::sub_00417E30_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417E90
void D2StormFixedListStrc::sub_00417E90_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004184B0
void D2StormFixedListStrc::sub_004184B0_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00418560
void D2StormFixedListStrc::sub_00418560_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004185D0
char* D2StormFixedListStrc::sub_004185D0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x004185F0
void D2StormFixedListStrc::sub_004185F0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00418660
void D2StormFixedListStrc::sub_00418660_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004186D0
char* D2StormFixedListStrc::sub_004186D0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x004186F0
char* D2StormFixedListStrc::sub_004186F0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x00418710
void D2StormFixedListStrc::sub_00418710_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}









// 0x00416810
void __fastcall sub_00416810(PairStrc_00416810* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00416890
void __fastcall sub_00416890(PairStrc_00416890* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x004168B0
void __fastcall sub_004168B0(PairStrc_004168B0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00416960
void __fastcall sub_00416960(PairStrc_00416960* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x004169A0
void __fastcall sub_004169A0(PairStrc_004169A0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}




// 0x0041E8F0
void __fastcall sub_0041E8F0(PairStrc_0041E8F0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}


// 0x004203E0
void __fastcall sub_004203E0(PairStrc_004203E0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00426920
void __fastcall sub_00426920(PairStrc_00426920* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0042D450
void* __cdecl sub_0042D450()
{
    return gData_006D17C8;
}

// 0x0042DC30
void* __cdecl sub_0042DC30()
{
    return gData_006D3870;
}

// 0x0042DC40
int __cdecl sub_0042DC40()
{
    return 85;
}

// 0x004168A0
D2StormLinkStrc* __fastcall sub_004168A0_Identity(D2IdentityView* value) {return &value->link;}

// 0x004169E0
D2StormLinkStrc* __fastcall sub_004169E0_Identity(D2IdentityView* value) {return &value->link;}

// 0x00416A40
D2StormLinkStrc* __fastcall sub_00416A40_Identity(D2IdentityView* value) {return &value->link;}

// 0x00416A50
extern "C" void* __fastcall sub_00416A50(void* value) { return value; }

// 0x00416A60
D2StormLinkStrc* __fastcall sub_00416A60_Identity(D2IdentityView* value) {return &value->link;}

// 0x00416A70
extern "C" void* __fastcall sub_00416A70(void* value) { return value; }

// 0x00416A80
D2StormLinkStrc* __fastcall sub_00416A80_Identity(D2IdentityView* value) {return &value->link;}

// 0x00417770
char* Link::sub_00417770() { return (int)next<=NO_NODE ? 0 : next; }

// 0x00417790
char* D2SFileStormLinkM114Strc::sub_00417790_Next()
{
    return MaskNext();
}

// 0x004178A0
char* D2SFileStormLinkM114Strc::sub_004178A0_Next()
{
    return MaskNext();
}

// 0x004179A0
char* D2SFileStormLinkM114Strc::sub_004179A0_Next()
{
    return MaskNext();
}

// 0x00417EE0
static inline int sub_00417EE0_IsNotListHead(D2SFileArchiveM114Strc* pArchive)
{
    if (pArchive->nKey && pArchive->pOwner->pList->Head() && pArchive->nKey == pArchive->pOwner->pList->Head()->nKey)
    {
        return 0;
    }
    return 1;
}

int __stdcall sub_M114_Emit_00417EE0(D2SFileArchiveM114Strc* pArchive)
{
    return sub_00417EE0_IsNotListHead(pArchive) + 5;
}

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

// 0x004177C0
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x004179F0
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00417E50
void D2StormLinkStrc::sub_00417E50()
{
    Unlink();
}

// 0x00418470
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

static D2StormLinkStrc* STORM_LinkNextLink(D2StormLinkStrc* pLink, int nLinkOffset)
{
    if ((int)pLink->m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)pLink->m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)pLink - pLink->m_prevlink->m_next;
    return (D2StormLinkStrc*)(pLink->m_next + nLinkOffset);
}

static char* STORM_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

static void STORM_LinkUnlink(D2StormLinkStrc* pLink)
{
    if (pLink->m_prevlink)
    {
        STORM_LinkNextLink(pLink, -1)->m_prevlink = pLink->m_prevlink;
        pLink->m_prevlink->m_next = pLink->m_next;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
    }
}

// build: symbol ??1ARCHIVEREC@@QAE@XZ 0x00418A50
// 0x00418490
int D2StormList00418490Strc::sub_00418490_IsEmpty()
{
    return STORM_LinkNext(&m_terminator) == 0;
}

// 0x004185B0
int D2StormList004185B0Strc::sub_004185B0_IsEmpty()
{
    return STORM_LinkNext(&m_terminator) == 0;
}

// 0x00418C60
D2StormList00708354Strc::~D2StormList00708354Strc()
{
    sub_00418900_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418CC0
D2StormList00708360Strc::~D2StormList00708360Strc()
{
    sub_00418940_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418D00
D2StormList0070836CStrc::~D2StormList0070836CStrc()
{
    sub_00418980_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418D40
D2StormList00708378Strc::~D2StormList00708378Strc()
{
    sub_004189C0_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418DA0
D2StormList00708384Strc::~D2StormList00708384Strc()
{
    sub_00418A00_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418E60
FILEREC::FILEREC()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
    pBuffer0x10C = 0;
    hFile = (void*)-1;
    archive = 0;
    pBuffer0x12C = 0;
    pBuffer0x138 = 0;
}

// 0x00418E90
void __fastcall RemoveArchiveRef(ARCHIVEREC* pArch)
{
    if (pArch && !--pArch->nRefCount)
        delete pArch;
}

unsigned long gdwStormThreadId_00779040; // 0x00779040



// 0x00418A50
ARCHIVEREC::~ARCHIVEREC()
{
    if (!this || !bMapped)
    {
        if (hFile != (void*)-1 && !bNoClose)
            CloseHandle(hFile);
        if (pBuffer0x128)
            SMemFree(pBuffer0x128, ".\\SOURCE\\SFILE.CPP", 0x260, 0);
        if (pBuffer0x138)
            SMemFree(pBuffer0x138, ".\\SOURCE\\SFILE.CPP", 0x261, 0);
        if (pBuffer0x13C)
            SMemFree(pBuffer0x13C, ".\\SOURCE\\SFILE.CPP", 0x269, 0);
        if (pBuffer0x140)
            SMemFree(pBuffer0x140, ".\\SOURCE\\SFILE.CPP", 0x26A, 0);
    }
    tLink.Unlink();
}

// 0x00418B50
int __cdecl sub_00418B50()
{
    int nFlags = 0;
    if (gnStormDirectFlags_00779058 & 1)
        nFlags |= 1;
    if (gnStormDirectFlags_00779058 & 2)
        nFlags |= 2;
    if (!gStormList_00708354.Head() && !gnStormDirectFlags_00779058)
        nFlags |= 1;
    return nFlags;
}

// 0x00419070
FILEREC::~FILEREC()
{
    if (hFile != (void*)-1)
        CloseHandle(hFile);
    if (archive)
        archive->nUnk0x11C = 0;
    if (pBuffer0x12C)
        SMemFree(pBuffer0x12C, ".\\SOURCE\\SFILE.CPP", 0x14B, 0);
    if (pBuffer0x138)
        SMemFree(pBuffer0x138, ".\\SOURCE\\SFILE.CPP", 0x14C, 0);
    ARCHIVEREC* pArch = archive;
    if (pArch && !--pArch->nRefCount)
        delete pArch;
    if (pBuffer0x10C)
        SMemFree(pBuffer0x10C, ".\\SOURCE\\SFILE.CPP", 0x14E, 0);
    tLink.Unlink();
}

// 0x0041A880
void __cdecl sub_0041A880_StartThread()
{
    if (!ghStormThread_00779034)
    {
        ghStormEvent_00779054 = CreateEventA(0, 0, 0, 0);
        ghStormThread_00779034 = CreateThread(0, 0, CdThreadProc, 0, 0, &gdwStormThreadId_00779040);
        SetThreadPriority(ghStormThread_00779034, 1);
    }
}







// 0x0041D410
unsigned int __fastcall sub_0041D410_GetWindow(D2StormHashBufferStrc* pBuffer)
{
    return pBuffer->nWindow;
}

// 0x0041D9A0
void CBitOutput::sub_0041D9A0_Flush()
{
    while (nBitCount)
    {
        if (f_4)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            f_4--;
        }
        nBitBuffer >>= 8;
        nBitCount -= nBitCount > 8 ? 8 : nBitCount;
    }
}

// 0x0041EE40
void D2StormNodeListStrc::sub_0041EE40_UnlinkAll()
{
    while (char* pNode = Head())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x0041F950
CHuffman::CHuffman()
{
    for (int i = 0; i < 0x80; ++i)
        f_3474[i].nData[0] = 0;
}

// 0x00425D90
void Sha1::Initialize()
{
    nBitCount = 0;
    aState[0] = 0x67452301;
    aState[1] = 0xEFCDAB89;
    aState[2] = 0x98BADCFE;
    aState[3] = 0x10325476;
    aState[4] = 0xC3D2E1F0;
}

// build: symbol ??_GAUDIOSTREAM@@QAEPAXI@Z 0x00419A50
// build: symbol ??_GREQUEST@@QAEPAXI@Z 0x0041A0E0
// 0x00419A50
inline void AUDIOSTREAM::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0041A0E0
inline void REQUEST::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

inline D2StormHandlerStrc::~D2StormHandlerStrc()
{
    f_0.Unlink();
}

// build: symbol ??_GD2StormWndRecStrc@@QAEPAXI@Z 0x00420880
inline D2StormWndRecStrc::~D2StormWndRecStrc()
{
    f_0.Unlink();
}

// 0x00418EC0
char* D2StormFixedListStrc::sub_00418EC0_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(ARCHIVEREC) + nExtraBytes, gszTypeNameArchiveRec_00708398, -2, nFlags | 8);
    ARCHIVEREC* pRecord = pMemory ? new (pMemory) ARCHIVEREC : 0;
    if (nLinkType)
        sub_004184B0_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00419630
char* D2StormFixedListStrc::sub_00419630_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(REQUEST) + nExtraBytes, gszTypeNameRequest_007083F0, -2, nFlags | 8);
    REQUEST* pRecord = pMemory ? new (pMemory) REQUEST : 0;
    if (nLinkType)
        sub_00417A70_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00419B90
char* D2StormFixedListStrc::sub_00419B90_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((AUDIOSTREAM*)pNode)->~AUDIOSTREAM();
    SMemFree(pNode, gszStormAudioStreamTypeName, -2, 0);
    return pNext;
}

// 0x0041A2C0
char* D2StormFixedListStrc::sub_0041A2C0_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((REQUEST*)pNode)->~REQUEST();
    SMemFree(pNode, gszTypeNameRequest_007083F0, -2, 0);
    return pNext;
}



// 0x00420820
char* D2StormNodeListBStrc::sub_00420820_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormWndRecStrc) + nExtraBytes, gszTypeNameWndRec_00708850, -2, nFlags | 8);
    D2StormWndRecStrc* pRecord = pMemory ? new (pMemory) D2StormWndRecStrc : 0;
    if (nLinkType)
        sub_00420540_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00420970
char* D2StormNodeListBStrc::sub_00420970_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormWndRecStrc*)pNode)->~D2StormWndRecStrc();
    SMemFree(pNode, gszTypeNameWndRec_00708850, -2, 0);
    return pNext;
}

// 0x0041AF60
int __stdcall SFileLoadFileEx2(void* hMpq, const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, int nFlags, void* pOverlapped, int nArg8)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    if (ppBuffer)
        *ppBuffer = 0;
    else
        nValid = 0;
    VALIDATEEND;
    if (pSize)
        *pSize = 0;
    void* pBuffer = 0;
    void* hFile = 0;
    if (SFileOpenFileEx(hMpq, szFileName, nFlags, &hFile))
    {
        unsigned int nSize = sub_00416370_StormGetFileSize(hFile, 0);
        pBuffer = SMemAlloc(nSize + nExtraSize, ".\\SOURCE\\SFILE.CPP", 0xFEA, 0);
        if (SFileReadFileEx2(hFile, pBuffer, nSize, 0, pOverlapped, nArg8, 0))
        {
            if (nExtraSize)
                SMemZero(nSize + (char*)pBuffer, nExtraSize);
            *ppBuffer = pBuffer;
            if (pSize)
                *pSize = nSize;
        }
        else if (pBuffer)
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0x1000, 0);
    }
    if (hFile)
        SFileCloseFile(hFile);
    return *ppBuffer != 0;
}
