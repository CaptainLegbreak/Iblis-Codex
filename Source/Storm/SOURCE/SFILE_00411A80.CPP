#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2CriticalSectionStrc;
struct D2FogBlockStrc;
struct D2Storm416A90Strc;
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
struct D2StormRequestCallbackStrc;
struct D2StormCryptFuncsStrc;
struct D2StormSignatureKeyStrc;
struct D2StormRecord419000Strc;

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long dwSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
extern unsigned long gnFlag2_00776CBC; // 0x00776CBC
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0
extern unsigned long gnFlag0_007784C4; // 0x007784C4
extern int gbHeapInitialized_007788D0; // 0x007788D0
extern char gszBasePath_00778F28[]; // 0x00778F28
extern unsigned short gwValue_0077905C;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];

extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __fastcall sub_0041D810_Crc32(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810
void __cdecl sub_004158E0_InitBasePath(); // 0x004158E0
int __cdecl sub_00418B50(); // 0x00418B50
void* __cdecl StormGetInstance(); // 0x0041BEF0
void __cdecl sub_0041A880_StartThread(); // 0x0041A880
void __cdecl sub_00419C00_PumpStreams();
int __stdcall SFileCloseFile(void* pArg); // 0x004198D0
int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);
int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0
unsigned int __stdcall sub_00416AD0_ReadBlocks(D2StormFileRecStrc* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize);
void __stdcall CheckRequests(D2StormArchiveRecStrc* pLastArchive, unsigned int nLastOffset, D2StormRequestStrc** ppDue, D2StormRequestStrc** ppNear, int* pnDistance); // 0x0041A450
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern unsigned int* gpCryptTable_00779048; // 0x00779048
extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030
extern "C" const char gszSFileCpp_006CF084[]; // 0x006CF084
extern const D2StormSignatureKeyStrc gaSignatureKeys_006CF07C[]; // 0x006CF07C
extern D2StormArchiveListStrc gArchiveList_00708354; // 0x00708354
extern D2StormEventListStrc gEventList_00708378; // 0x00708378
extern int gbThreadStop_00778F24; // 0x00778F24
extern void* ghStormEvent_00779054; // 0x00779054
extern unsigned int gnStreamChunk_00779038; // 0x00779038
extern unsigned char* gpStreamBuffer_00779050; // 0x00779050
static int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec); // 0x00415930
static D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex); // 0x004155B0
static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, D2StormArchiveRecStrc* pArchive, const char* szName); // 0x004155D0
static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut); // 0x00415B00
static int __stdcall sub_00417F10_FindFile(void* hArchive, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath);
void __cdecl sub_00415B90_InitCryptTable(); // 0x00415B90

struct D2StormRecord419000Strc
{
    D2StormLinkStrc f_0;

    ~D2StormRecord419000Strc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

extern "C" const char gszStormFileRecTypeName[]; // 0x007083C0
extern "C" const char gszStormEventRecTypeName[]; // 0x007083D8

inline void* operator new(unsigned int, void* pWhere) throw();

// 0x00411A80
void __fastcall sub_00411A80_ReleaseBlock(D2FogBlockStrc** ppLink)
{
    D2FogBlockStrc* pBlock = *ppLink;
    *ppLink = pBlock->pNext;
    VirtualFree(pBlock, 0, 0x8000);
}

// 0x00411CD0
void __cdecl SMemInitialize()
{
    if (!gbHeapInitialized_007788D0)
    {
        SRegLoadValue("Internal", "Debug Memory", 0, &gnFlag0_007784C4);
        SRegLoadValue("Internal", "Protect Memory", 0, &gnFlag2_00776CBC);
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            InitializeCriticalSection(pLock);
            ++pLock;
        }
        while (--n);
        gbHeapInitialized_007788D0 = 1;
    }
}

// 0x004158E0
void __cdecl sub_004158E0_InitBasePath()
{
    GetModuleFileNameA(GetModuleHandleA(0), gszBasePath_00778F28, 0x104);
    char* pSeparator = (char*)SStrChrR(gszBasePath_00778F28, '\\');
    if (pSeparator)
        *pSeparator = 0;
    SStrPack(gszBasePath_00778F28, "\\", 0x104);
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    tLink.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x004177A0
char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    tLink.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
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

// 0x004177D0
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

// 0x00417A30
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

static D2StormRequestStrc* gpCurrentRequest_0077902C; // 0x0077902C

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

static inline D2StormArchiveRecStrc* ArchiveHead()
{
    return (int)gpArchiveHead_0070835C > 0 ? gpArchiveHead_0070835C : 0;
}

static inline char* EventHead()
{
    return (int)gpEventHead_00708380 > 0 ? gpEventHead_00708380 : 0;
}

static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec)
{
    *ppRec = (D2StormArchiveRecStrc*)hArchive;
    return 1;
}

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

static __declspec(noinline) D2StormBlockStrc* sub_004155B0_GetBlockEntry(D2StormArchiveRecStrc* pArchive, int nHashIndex)
{
    return &pArchive->pBlockTable[pArchive->pHashTable[nHashIndex].nBlockIndex];
}

static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, D2StormArchiveRecStrc* pArchive, const char* szName)
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

static int sub_00415940_PathPresent(const char* szPath)
{
    return ~(GetFileAttributesA(szPath) >> 4) & 1;
}

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
    wsprintfA(szBuffer, gszPathJoinFormat_006CE200, gszBasePath_00778F28, szName);
    _fullpath(szOut, szBuffer, 0x104);
}

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
            if (*szName != 0x5C && !strstr(szName, gszDriveRoot_006CF09C) && !strstr(szName, gszUncPrefix_006CF098))
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

// 0x00417F10
static int __stdcall sub_00417F10_FindFile(void* hArchive, const char* szName, unsigned int nFlags, D2StormArchiveRecStrc** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    D2StormArchiveRecStrc* pOnly = 0;
    if (!hArchive || sub_00415930_GetArchiveRec(hArchive, &pOnly))
    {
        D2StormArchiveRecStrc* pArchive = ArchiveHead();
        do
        {
            if (pOnly && pArchive != pOnly)
                continue;
            if (pArchive && pArchive->nRefs > 0)
                continue;
            D2StormArchiveRecStrc* pSearch = pArchive;
            if (pArchive && pArchive->pPatch)
                pSearch = pArchive->pPatch;
            const char* szLookup = szName;
            char szPrefixed[0x104];
            if (pArchive && pArchive->szPrefix[0])
            {
                char* szEnd = szPrefixed + SStrCopy(szPrefixed, pArchive->szPrefix, 0x104);
                szEnd += SStrCopy(szEnd, gszBackslash_006FF9B8, 0x104);
                SStrCopy(szEnd, szName, 0x104);
                szLookup = szPrefixed;
            }
            char szDiskPath[0x104];
            if ((nFlags & 3) && (!pSearch || !pSearch->bNoDiskSearch)
                && sub_00415B00_FindDiskFile(nFlags, szLookup, szDiskPath))
            {
                if (szFoundPath)
                    SStrCopy(szFoundPath, szDiskPath, 0x104);
                bResult = 2;
                goto Done;
            }
            if (pArchive)
            {
                const int nIndex = sub_004155D0_FindHashEntry(gwLocale_0077905C, gnPlatform_0077905E, pSearch, szLookup);
                if (nIndex != -1)
                {
                    bResult = 1;
                    D2StormBlockStrc* pBlock = sub_004155B0_GetBlockEntry(pSearch, nIndex);
                    const int bValid = (pBlock->dwFlags & 0x80000000) && (!(nFlags & 4) || !(pBlock->dwFlags & 0x1FF00));
                    if (!bValid)
                    {
                        bResult = 0;
                        sub_0041C340_SetLastError(0x3EE);
                    }
                    else
                    {
                        if (ppArchive)
                            *ppArchive = pSearch;
                        if (ppBlock)
                            *ppBlock = pBlock;
                    }
                    goto Done;
                }
            }
        }
        while (pArchive && (pArchive = (D2StormArchiveRecStrc*)pArchive->tLink.Next()) != 0);
        sub_0041C340_SetLastError(2);
    }
Done:
    return bResult;
}

// build: context SFileFileExistsEx
int __stdcall SFileFileExistsEx(void* hArchive, const char* szFileName, int nFlags)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();
    int nResult = sub_00417F10_FindFile(hArchive, szFileName, nFlags, 0, 0, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

// 0x00418640
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

// 0x00418900
void D2StormList00708354Strc::sub_00418900_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x00418940
void D2StormList00708360Strc::sub_00418940_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x00418980
void D2StormList0070836CStrc::sub_00418980_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x004189C0
void D2StormList00708378Strc::sub_004189C0_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x00418A00
void D2StormList00708384Strc::sub_00418A00_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// build: symbol ??_GD2StormArchiveRecStrc@@QAEPAXI@Z 0x00418B20
// build: symbol ??_GD2StormFileRecStrc@@QAEPAXI@Z 0x00419150
// build: symbol ??_GD2StormRecord419000Strc@@QAEPAXI@Z 0x00419000
inline D2StormRecord419000Strc::~D2StormRecord419000Strc()
{
    f_0.Unlink();
}


void sub_F21_EmitScalarDeletingDestructors(D2StormArchiveRecStrc* pArchive, D2StormFileRecStrc* pFile, D2StormRecord419000Strc* pRecord)
{
    delete pArchive;
    delete pFile;
    delete pRecord;
}

// build: context D2StormFileRecStrc::D2StormFileRecStrc
inline D2StormFileRecStrc::D2StormFileRecStrc()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
    pBuffer0x10C = 0;
    hFile = (void*)-1;
    pArchive = 0;
    pBuffer0x12C = 0;
    pBuffer0x138 = 0;
}

// 0x00418F20
char* D2StormFixedListStrc::sub_00418F20_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormFileRecStrc) + nExtraBytes, gszStormFileRecTypeName, -2, nFlags | 8);
    D2StormFileRecStrc* pRecord = pMemory ? new (pMemory) D2StormFileRecStrc : 0;
    if (nLinkType)
        sub_00417B80_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00419690
char* D2StormFixedListStrc::sub_00419690_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormLinkStrc*)pNode)->Unlink();
    SMemFree(pNode, gszStormEventRecTypeName, -2, 0);
    return pNext;
}

// build: context D2StormAudioStreamStrc::D2StormAudioStreamStrc
inline D2StormAudioStreamStrc::D2StormAudioStreamStrc()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00419700
char* D2StormFixedListStrc::sub_00419700_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormAudioStreamStrc) + nExtraBytes, gszStormAudioStreamTypeName, -2, nFlags | 8);
    D2StormAudioStreamStrc* pRecord = pMemory ? new (pMemory) D2StormAudioStreamStrc : 0;
    if (nLinkType)
        sub_00417D80_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

#include "gen/data/Source/Storm/SOURCE/SFILE_00411A80.inc"
