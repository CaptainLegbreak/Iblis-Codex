#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"


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

void __fastcall CrcBuffer(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags); // 0x0041D810

void __cdecl sub_004158E0_InitBasePath(); // 0x004158E0

int __cdecl sub_00418B50(); // 0x00418B50

void* __cdecl StormGetInstance(); // 0x0041BEF0

void __cdecl sub_0041A880_StartThread(); // 0x0041A880

void __cdecl sub_00419C00_PumpStreams();

int __stdcall SFileCloseFile(void* pArg); // 0x004198D0

int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80

int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0

int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);

int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00415BB0

unsigned int __stdcall InternalReadAligned(FILEREC* pFile, unsigned int nOffset, unsigned char* pBuffer, unsigned int nSize); // 0x00416AD0

void __stdcall CheckRequests(ARCHIVEREC* pLastArchive, unsigned int nLastOffset, REQUEST** ppDue, REQUEST** ppNear, int* pnDistance); // 0x0041A450

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

static int sub_00415930_GetArchiveRec(void* hArchive, ARCHIVEREC** ppRec); // 0x00415930

static D2StormBlockStrc* sub_004155B0_GetBlockEntry(ARCHIVEREC* pArchive, int nHashIndex); // 0x004155B0

static int __stdcall sub_004155D0_FindHashEntry(unsigned short wLocale, unsigned char nPlatform, ARCHIVEREC* pArchive, const char* szName); // 0x004155D0

static int __stdcall sub_00415B00_FindDiskFile(unsigned int nFlags, const char* szName, char* szOut); // 0x00415B00

static int __stdcall GetFileBlockEntry(void* hArchive, const char* szName, unsigned int nFlags, ARCHIVEREC** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath); // 0x00417F10

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

static REQUEST* gpCurrentRequest_0077902C; // 0x0077902C

struct D2StormSoundBuffer;

extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* lpRootPathName, unsigned long* lpSectorsPerCluster, unsigned long* lpBytesPerSector, unsigned long* lpNumberOfFreeClusters, unsigned long* lpTotalNumberOfClusters); // 0x006CC270

extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(const char* lpRootPathName, char* lpVolumeNameBuffer, unsigned long nVolumeNameSize, unsigned long* lpVolumeSerialNumber, unsigned long* lpMaximumComponentLength, unsigned long* lpFileSystemFlags, char* lpFileSystemNameBuffer, unsigned long nFileSystemNameSize); // 0x006CC2E8

extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(const char* lpRootPathName);         // 0x006CC2EC

unsigned int __fastcall bjhash(const unsigned char* k, unsigned int nLength, unsigned int nInitVal); // 0x00413F30

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

extern char* gpStormExplodeWork;                                                                            // 0x0077903C

D2CriticalSectionStrc gStormExplodeLock;                                                                    // 0x00779080

unsigned int __cdecl sub_004151D0_ExplodeRead(char* pBuffer, unsigned int* pnSize, void* pParam);          // 0x004151D0

void __cdecl sub_00415210_ExplodeWrite(char* pBuffer, unsigned int* pnSize, void* pParam);                 // 0x00415210

extern "C" unsigned int __cdecl sub_006B01B0_Explode(unsigned int (__cdecl* pRead)(char*, unsigned int*, void*), void (__cdecl* pWrite)(char*, unsigned int*, void*), char* pWork, void* pParam); // 0x006B01B0

int __stdcall SFileReadFileEx2(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0

int __stdcall SFileLoadFileEx2(void* hMpq, const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, int nFlags, void* pOverlapped, int nArg8); // 0x0041AF60

int __stdcall SFileDdaBeginEx(void* hFile, unsigned int nBufferSize, unsigned int nFlags, unsigned int nOffset, int nVolume, int nPan, D2StormSoundBuffer* pBuffer); // 0x0041B280

struct D2StormHashBufferStrc;

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile);

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh);

void __fastcall SSignatureVerifyStream_Begin(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize); // 0x0041D3B0

unsigned int __fastcall sub_0041D410_GetWindow(D2StormHashBufferStrc* pBuffer);

void __fastcall sub_0041D420_HashBuffered(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize);

int __fastcall SSignatureVerifyStream_Finish(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus); // 0x0041D6D0

extern "C" const unsigned char gabSignatureModulus_006CEF78[0x100];                                         // 0x006CEF78

extern "C" const unsigned char gabSignatureExponent_006CF078[4];                                            // 0x006CF078

void* gpDirectSound_00778F20;                                                                               // 0x00778F20

int gnStormDirectFlags_00779058;                                                                            // 0x00779058

inline REQUEST* D2StormRequestListStrc::NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(REQUEST) + nExtraBytes, gszTypeNameRequest_007083F0, -2, nFlags | 8);
    REQUEST* pRecord = pMemory ? new (pMemory) REQUEST : 0;
    if (nLinkType)
        LinkNode((char*)pRecord, nLinkType, 0);
    return pRecord;
}

extern D2StormStreamListStrc gDdaList_00708384;                                                             // 0x00708384

extern D2StormRequestListStrc gRequestList_00708360;                                                        // 0x00708360

extern int gbStreamsPaused_00779044;                                                                        // 0x00779044

extern AUDIOSTREAM* gpDdaHead_0070838C;                                                               // 0x0070838C

struct D2StormLinkStrc;

extern D2StormNodeListStrc gStormList_00708354; // 0x00708354

extern D2StormFixedListStrc gFileList_0070836C; // 0x0070836C

int __stdcall sub_00415960_CheckVolume(const char* szPath);                                                 // 0x00415960

int __fastcall s_OpenArchive(ARCHIVEREC* pArchive, unsigned int nFlags, int bKeepOnFail, void** phArchive); // 0x0041B6B0

static int sub_00415940_PathPresent(const char* szPath);                                // 0x00415940

static void __stdcall sub_00415A80_BuildPath(int bStripPath, const char* szName, char* szOut); // 0x00415A80

typedef void (__stdcall* SFILEOPENCALLBACK)(const char* szFileName, void* pParam);

extern "C" const char gszSFileSourceFile_006CF084[]; // 0x006CF084

extern SFILEOPENCALLBACK gpfnOpenFileCallback_00779060; // 0x00779060

extern void* gpOpenFileCallbackParam_00779064; // 0x00779064

extern unsigned int gnFileCrc_007790B0; // 0x007790B0

char* __stdcall SStrDup(const char* szString); // 0x00414310


static unsigned int __stdcall sub_00415330_HashString(unsigned int nHashType, const char* szString);

static int sub_00415950_GetFileRec(void* hFile, FILEREC** ppRec);

int __stdcall SFileOpenFileAsArchive(void* hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive);



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

char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
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

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
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

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return f_4;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

// 0x004177D0
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
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

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
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

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

// 0x00417A30
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

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

static int sub_00415930_GetArchiveRec(void* hArchive, ARCHIVEREC** ppRec)
{
    *ppRec = (ARCHIVEREC*)hArchive;
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
static int __stdcall GetFileBlockEntry(void* hArchive, const char* szName, unsigned int nFlags, ARCHIVEREC** ppArchive, D2StormBlockStrc** ppBlock, char* szFoundPath)
{
    if (ppArchive)
        *ppArchive = 0;
    if (ppBlock)
        *ppBlock = 0;
    int bResult = 0;
    ARCHIVEREC* pOnly = 0;
    if (!hArchive || sub_00415930_GetArchiveRec(hArchive, &pOnly))
    {
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
        while (pArchive && (pArchive = (ARCHIVEREC*)pArchive->tLink.Next()) != 0);
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
    int nResult = GetFileBlockEntry(hArchive, szFileName, nFlags, 0, 0, 0);
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

// 0x00418900
void D2StormList00708354Strc::sub_00418900_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x00418940
void D2StormList00708360Strc::sub_00418940_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x00418980
void D2StormList0070836CStrc::sub_00418980_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x004189C0
void D2StormList00708378Strc::sub_004189C0_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x00418A00
void D2StormList00708384Strc::sub_00418A00_UnlinkAll()
{
    while (char* pNode = m_terminator.Next())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// build: symbol ??_GARCHIVEREC@@QAEPAXI@Z 0x00418B20
// build: symbol ??_GFILEREC@@QAEPAXI@Z 0x00419150
// build: symbol ??_GD2StormRecord419000Strc@@QAEPAXI@Z 0x00419000
inline D2StormRecord419000Strc::~D2StormRecord419000Strc()
{
    f_0.Unlink();
}

void sub_F21_EmitScalarDeletingDestructors(ARCHIVEREC* pArchive, FILEREC* pFile, D2StormRecord419000Strc* pRecord)
{
    delete pArchive;
    delete pFile;
    delete pRecord;
}

// build: context FILEREC::FILEREC
inline FILEREC::FILEREC()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
    pBuffer0x10C = 0;
    hFile = (void*)-1;
    archive = 0;
    pBuffer0x12C = 0;
    pBuffer0x138 = 0;
}

// 0x00418F20
char* D2StormFixedListStrc::sub_00418F20_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(FILEREC) + nExtraBytes, gszStormFileRecTypeName, -2, nFlags | 8);
    FILEREC* pRecord = pMemory ? new (pMemory) FILEREC : 0;
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

// build: context AUDIOSTREAM::AUDIOSTREAM
inline AUDIOSTREAM::AUDIOSTREAM()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x00419700
char* D2StormFixedListStrc::sub_00419700_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(AUDIOSTREAM) + nExtraBytes, gszStormAudioStreamTypeName, -2, nFlags | 8);
    AUDIOSTREAM* pRecord = pMemory ? new (pMemory) AUDIOSTREAM : 0;
    if (nLinkType)
        sub_00417D80_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

static int sub_00415950_GetFileRec(void* hFile, FILEREC** ppRec)
{
    *ppRec = (FILEREC*)hFile;
    return 1;
}

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

static int __stdcall sub_00415560_ReadFileRec(void* pBuffer, unsigned int nSize, unsigned int* pnRead, unsigned int nOffset, FILEREC* pFile)
{
    unsigned int nFilePos;
    unsigned long nRead = 0;
    ReadFileChecked(&nFilePos, pBuffer, nSize, pFile->szName, &nRead, nOffset, pFile->hFile);
    if (pnRead)
        *pnRead = nRead;
    return nRead == nSize;
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
        CrcBuffer(0, 0, &pFile->nCrc, 1);
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
            CrcBuffer(pBuffer, nCopy, &pFile->nCrc, 2);
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
            CrcBuffer(pBuffer, nMiddle, &pFile->nCrc, 2);
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
            CrcBuffer(pBuffer, nTail, &pFile->nCrc, 2);
            pFile->nCrcPos += nTail;
        }
    }
    return nMiddle + nTail + nHead;
}

// 0x004172F0
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
        if (pBlock->nOffset + pBlock->nFileSize < pArchive->pHeader->nArchiveSize + pArchive->nArchiveOffset)
        {
            if (!pFuncs->pfnHashData(hHash, pView + pBlock->nOffset + pBlock->nFileSize, pArchive->pHeader->nArchiveSize - pBlock->nOffset - pBlock->nFileSize + pArchive->nArchiveOffset, 0))
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
                    CrcBuffer(0, 0, &pFile->nCrc, 4);
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

// 0x00414150
unsigned int __stdcall SStrHashHT(const char* szPath)
{
    char szBuffer[0x400];
    char* p = szBuffer;
    unsigned int nLength = 0;
    unsigned int c;
    while ((c = (unsigned char)*szPath) != 0)
    {
        ++szPath;
        if (nLength >= 0x3FF)
            break;
        if (c - 'a' <= 25)
            c -= 0x20;
        else if (c == '/')
            c = '\\';
        *p++ = (char)c;
        ++nLength;
    }
    *p = 0;
    return bjhash((const unsigned char*)szBuffer, nLength, 0);
}

struct D2StormExplodeParamStrc
{
    const char* pSource;
    unsigned int nSourcePos;
    char* pDest;
    unsigned int nDestPos;
    unsigned int nSourceSize;
};

// 0x00415240
int __stdcall sub_00415240_Explode(char* pDest, const char* pSource, unsigned int nSourceSize)
{
    EnterCriticalSection(&gStormExplodeLock);
    if (!gpStormExplodeWork)
        gpStormExplodeWork = (char*)SMemAlloc(0x3134, ".\\SOURCE\\SFILE.CPP", 0x2C9, 0);
    D2StormExplodeParamStrc tParam;
    tParam.pSource = pSource;
    tParam.nSourcePos = 0;
    tParam.pDest = pDest;
    tParam.nDestPos = 0;
    tParam.nSourceSize = nSourceSize;
    sub_006B01B0_Explode(sub_004151D0_ExplodeRead, sub_00415210_ExplodeWrite, gpStormExplodeWork, &tParam);
    LeaveCriticalSection(&gStormExplodeLock);
    return 1;
}

// 0x00415960
int __stdcall sub_00415960_CheckVolume(const char* szPath)
{
    char szRoot[4];
    SStrCopy(szRoot, szPath, 4);
    unsigned int nDriveType = GetDriveTypeA(szRoot);
    char szFileSystem[0x104];
    unsigned long dwFlags = 0;
    SMemZero(szFileSystem, 0x104);
    if (!GetVolumeInformationA(szRoot, 0, 0, 0, 0, &dwFlags, szFileSystem, 0x104))
        return 0;
    unsigned long dwSectorsPerCluster = 0;
    unsigned long dwBytesPerSector = 0;
    unsigned long dwFreeClusters = 0;
    unsigned long dwTotalClusters = 0;
    if (!GetDiskFreeSpaceA(szRoot, &dwSectorsPerCluster, &dwBytesPerSector, &dwFreeClusters, &dwTotalClusters))
        return 0;
    unsigned int nKey = (dwFlags & 4) ^ *(unsigned int*)szFileSystem ^ dwFreeClusters ^ dwBytesPerSector ^ nDriveType;
    unsigned short wKey = (unsigned short)((nKey >> 16) ^ nKey);
    return wKey == 0x1F00 || wKey == 0x805;
}

// 0x00415760
static unsigned int sub_00415760_UpdatePlayed(AUDIOSTREAM* pStream)
{
    unsigned long nPlay = 0;
    unsigned long nWrite = 0;
    if (pStream->pBuffer->GetCurrentPosition(&nPlay, &nWrite) < 0)
        return -1;
    unsigned int nWritten = pStream->writecursor;
    int nAhead = nWritten % pStream->soundbuffersize - nPlay;
    if (nAhead <= 0)
        nAhead += pStream->soundbuffersize;
    unsigned int nPlayed = nWritten - nAhead;
    if (nPlayed >= pStream->nSize)
        nPlayed = pStream->nSize;
    pStream->nPlayed = nPlayed;
    return nPlay;
}

// 0x00418140
int __stdcall SFileDdaGetPos(void* hFile, unsigned int* pnPlayed, unsigned int* pnSize)
{
    int bResult = 0;
    unsigned int nSize = 0;
    unsigned int nPlayed = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (sub_00415950_GetFileRec(hFile, &pRec))
    {
        AUDIOSTREAM* pStream;
        for (pStream = gDdaList_00708384.Head(); pStream; pStream = (AUDIOSTREAM*)pStream->tLink.Next())
        {
            if (pStream->pFile == pRec)
                break;
        }
        if (!pStream)
        {
            sub_0041C340_SetLastError(0x85100072);
        }
        else
        {
            nSize = pStream->nSize;
            const int nState = pStream->fillstatus;
            if (nState == 4)
            {
                sub_0041C340_SetLastError(0x85100072);
            }
            else
            {
                bResult = 1;
                if (nState != 0 && nState != 1)
                {
                    sub_00415760_UpdatePlayed(pStream);
                    nPlayed = pStream->nPlayed;
                }
            }
        }
    }
    if (pnPlayed)
        *pnPlayed = nPlayed;
    if (pnSize)
        *pnSize = nSize;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return bResult;
}

// 0x00415EE0
extern "C" int __stdcall SFileDdaInitialize(int nValue)
{
    VALIDATEBEGIN;
    VALIDATE(nValue);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return nValid;
    }
    gpDirectSound_00778F20 = (void*)nValue;
    return nValid ? 1 : 0;
}

// 0x00415F70
int __stdcall sub_00415F70(int nFlags)
{
    gnStormDirectFlags_00779058 = nFlags;
    return 1;
}

// 0x00419980
int __stdcall sub_00419980(const char* szFileName, void** phFile)
{
    return SFileOpenFileEx(0, szFileName, sub_00418B50(), phFile);
}

// 0x0041B650
int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped)
{
    return SFileLoadFileEx2(0, szFileName, ppBuffer, pSize, nExtraSize, sub_00418B50(), pOverlapped, 0);
}

// 0x0041BA30
int __stdcall SFileDdaBegin(void* hFile, int nBufferSize, unsigned int nFlags)
{
    return SFileDdaBeginEx(hFile, nBufferSize, nFlags, 0, 0x7FFFFFFF, 0x7FFFFFFF, 0);
}

// 0x00415BB0
int __stdcall SFileAuthenticateArchiveEx(void* hArchive, unsigned int* pnResult, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (!nArg3 && !nArg5)
    {
        nArg3 = (int)gabSignatureModulus_006CEF78;
        nArg4 = 0x100;
        nArg5 = (int)gabSignatureExponent_006CF078;
        nArg6 = 4;
    }
    if (!pnResult)
    {
        unsigned int nDummy;
        pnResult = &nDummy;
    }
    *pnResult = 0;
    ARCHIVEREC* pArchive;
    if (!sub_00415930_GetArchiveRec(hArchive, &pArchive))
    {
        return 0;
    }
    D2StormHashBufferStrc* pHash = 0;
    SSignatureVerifyStream_Begin(&pHash, nArg4, nArg6);
    EnterCriticalSection(&gBasePathLock_00779068);
    char* pBuffer = (char*)SMemAlloc(0x10000, ".\\SOURCE\\SFILE.CPP", 0xB33, 0);
    unsigned long nPosition = SetFilePointer(pArchive->hFile, 0, 0, 1);
    if (nPosition != (unsigned long)-1 && SetFilePointer(pArchive->hFile, pArchive->nArchiveOffset, 0, 0) != (unsigned long)-1)
    {
        unsigned int nRemaining = sub_0041D410_GetWindow(pHash) + pArchive->pHeader->nArchiveSize;
        while (nRemaining)
        {
            unsigned int nChunk = nRemaining > 0x10000 ? 0x10000 : nRemaining;
            unsigned long nRead = 0;
            nRemaining -= nChunk;
            if (!ReadFile(pArchive->hFile, pBuffer, nChunk, &nRead, 0) || nRead != nChunk)
            {
                goto done;
            }
            sub_0041D420_HashBuffered(pHash, pBuffer, nChunk);
        }
        SetFilePointer(pArchive->hFile, nPosition, 0, 0);
    }
done:
    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB59, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    unsigned int nResult = SSignatureVerifyStream_Finish(pHash, (const void*)nArg3, (const void*)nArg5) ? 5 : 1;
    *pnResult = nResult;
    return nResult == 5;
}

// 0x00415D50
unsigned int __stdcall sub_00415D50_ChecksumFile(const char* szFileName)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    void* hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0x8000000, 0);
    if (hFile == (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    unsigned int nCrc = 0;
    unsigned long nSize = GetFileSize(hFile, 0);
    if (nSize != (unsigned long)-1)
    {
        unsigned char* pBuffer = (unsigned char*)SMemAlloc(0x1000, ".\\SOURCE\\SFILE.CPP", 0xB83, 0);
        CrcBuffer(0, 0, &nCrc, 1);
        while (nSize > 0)
        {
            unsigned long nChunk = nSize < 0x1000 ? nSize : 0x1000;
            unsigned long nRead;
            ReadFile(hFile, pBuffer, nChunk, &nRead, 0);
            if (nChunk != nRead)
            {
                if (pBuffer)
                {
                    SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB8D, 0);
                }
                CloseHandle(hFile);
                LeaveCriticalSection(&gBasePathLock_00779068);
                return 0;
            }
            CrcBuffer(pBuffer, nChunk, &nCrc, 2);
            nSize -= nChunk;
        }
        CrcBuffer(0, 0, &nCrc, 4);
        if (pBuffer)
        {
            SMemFree(pBuffer, ".\\SOURCE\\SFILE.CPP", 0xB97, 0);
        }
    }
    CloseHandle(hFile);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nCrc;
}

// 0x0041B680
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped)
{
    return SFileLoadFileEx2(hMpq, szFileName, ppBuffer, (unsigned int*)pnSize, nExtraBytes, nFlags, pOverlapped, 0);
}

static inline AUDIOSTREAM* DdaHead()
{
    return (int)gpDdaHead_0070838C > 0 ? gpDdaHead_0070838C : 0;
}

// 0x0041B050
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped)
{
    return SFileReadFileEx2(hFile, pBuffer, nToRead, pnRead, pOverlapped, 0, 0);
}

// 0x0041B080
int __stdcall SFileReadFileEx(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6)
{
    return SFileReadFileEx2(hFile, pBuffer, nToRead, pnRead, pOverlapped, 0, nArg6);
}

static REQUEST* __stdcall IssueRequest(unsigned int nPosition, void* pDest, unsigned int nDestSize, D2StormSoundBufferStrc* pBuffer, unsigned int nBufferOffset, AUDIOSTREAM* pStream, unsigned int nBytes, unsigned int nDelay, int nArg9, int nUser, int nArg11, int bSignal, void* pCallback, FILEREC* pFile)
{
    int bValid = (pDest || pBuffer) ? -1 : 0;
    if (!bValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    EnterCriticalSection(&gBasePathLock_00779068);
    REQUEST* pRequest = gRequestList_00708360.NewNode(2, 0, 0);
    pRequest->nUser = nUser;
    pRequest->pFile = pFile;
    pRequest->location = nPosition;
    if (pFile->nKind == -1)
        nPosition = (nPosition >> 1) + *pFile->pBlockWords;
    pRequest->nFileOffset = nPosition;
    pRequest->nDueTime = GetTickCount() + nDelay;
    pRequest->nArg9 = nArg9;
    pRequest->pDest = (unsigned char*)pDest;
    pRequest->nDestSize = nDestSize;
    pRequest->pBuffer = pBuffer;
    pRequest->soundbufferoffset = nBufferOffset;
    pRequest->stream = pStream;
    pRequest->nBytes = nBytes;
    pRequest->bDelete = nArg11;
    pRequest->pCallback = (D2StormRequestCallbackStrc*)pCallback;
    pFile->nRequests += 1;
    if (pStream)
        pStream->nRefs += 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    if (bSignal)
        SetEvent(ghStormEvent_00779054);
    return pRequest;
}

void __cdecl sub_00419C00_PumpStreams()
{
    if (gbStreamsPaused_00779044)
        return;
    for (AUDIOSTREAM* pStream = DdaHead(); (int)pStream > 0; pStream = (AUDIOSTREAM*)pStream->tLink.m_next)
    {
        if (pStream->fillstatus == 3 || (pStream->fillstatus == 2 && pStream->pFile->nPosition >= pStream->waveheadersize + pStream->nSize))
        {
            if (pStream->bRestart)
            {
                pStream->pFile->nPosition = pStream->waveheadersize;
                pStream->writecursor = 0;
                pStream->nCounter = 0;
            }
            else
            {
                unsigned int nPlay = sub_00415760_UpdatePlayed(pStream);
                if (nPlay == -1)
                    continue;
                if (pStream->nPlayed >= pStream->nSize)
                {
                    pStream->pBuffer->Stop();
                    pStream->fillstatus = 4;
                    continue;
                }
                if ((nPlay - pStream->nextwrite) % pStream->soundbuffersize >= gnStreamChunk_00779038)
                {
                    unsigned int nCount = gnStreamChunk_00779038;
                    if (nCount >= pStream->soundbuffersize - pStream->nextwrite)
                        nCount = pStream->soundbuffersize - pStream->nextwrite;
                    void* pLocked = 0;
                    unsigned long nLocked = nCount;
                    if (pStream->pBuffer->Lock(pStream->nextwrite, nCount, &pLocked, &nLocked, 0, 0, 0) >= 0)
                    {
                        SMemFill(pLocked, nLocked, pStream->nFill);
                        pStream->pBuffer->Unlock(pLocked, nLocked, 0, 0);
                        pStream->writecursor += nLocked;
                        pStream->nCounter += nLocked;
                        pStream->nextwrite += nLocked;
                        if (pStream->nextwrite >= pStream->soundbuffersize)
                            pStream->nextwrite -= pStream->soundbuffersize;
                    }
                }
                pStream->fillstatus = 3;
            }
        }
        if (pStream->fillstatus == 2)
        {
            unsigned int nPlay = sub_00415760_UpdatePlayed(pStream);
            if (nPlay == -1)
                continue;
            if ((nPlay - pStream->nextwrite) % pStream->soundbuffersize < gnStreamChunk_00779038)
                continue;
            unsigned int nCount = pStream->soundbuffersize - pStream->nextwrite;
            if (gnStreamChunk_00779038 < nCount)
                nCount = gnStreamChunk_00779038;
            unsigned int nLeft = pStream->nSize + pStream->waveheadersize - pStream->pFile->nPosition;
            if (nCount >= nLeft)
                nCount = nLeft;
            if (gbAlignReads_007790A4)
            {
                unsigned int nOver = (pStream->pFile->archive->sectorsize - 1) & (pStream->pFile->nPosition + nCount);
                if (nOver && nOver < nCount)
                    nCount -= nOver;
            }
            IssueRequest(pStream->pFile->nPosition, 0, 0, pStream->pBuffer, pStream->nextwrite, pStream, nCount, 0, 0, 0, 1, 0, 0, pStream->pFile);
            pStream->pFile->nPosition += nCount;
            pStream->nextwrite += gnStreamChunk_00779038;
            if (pStream->nextwrite >= pStream->soundbuffersize)
                pStream->nextwrite -= pStream->soundbuffersize;
        }
        else if (pStream->fillstatus == 0)
        {
            unsigned int nTotal = pStream->nSize - pStream->nOffset;
            if (pStream->soundbuffersize < nTotal)
                nTotal = pStream->soundbuffersize;
            unsigned int nDone = 0;
            pStream->pFile->nPosition = pStream->waveheadersize + pStream->nOffset;
            unsigned int nIndex = 0;
            if (gbAlignReads_007790A4)
            {
                nDone = gnStreamChunk_00779038 < nTotal ? gnStreamChunk_00779038 : nTotal;
                unsigned int nOver = (pStream->pFile->archive->sectorsize - 1) & (pStream->pFile->nPosition + nDone);
                if (nOver && nOver < nDone)
                    nDone -= nOver;
                IssueRequest(pStream->pFile->nPosition, 0, 0, pStream->pBuffer, 0, pStream, nDone, 0, 0, 0, 1, 0, 0, pStream->pFile);
                pStream->pFile->nPosition += nDone;
                nIndex = 1;
            }
            for (; nDone < nTotal; nDone += gnStreamChunk_00779038)
            {
                unsigned int nCount = gnStreamChunk_00779038;
                if (nCount >= nTotal - nDone)
                    nCount = nTotal - nDone;
                IssueRequest(pStream->pFile->nPosition, 0, 0, pStream->pBuffer, nDone, pStream, nCount, nIndex, 0, 0, 1, 0, 0, pStream->pFile);
                ++nIndex;
                pStream->pFile->nPosition += nCount;
            }
            pStream->fillstatus = 1;
            pStream->nextwrite = nDone % pStream->soundbuffersize;
        }
    }
}

// 0x00419760
static void RemoveFileRef(FILEREC* pFile)
{
    if (pFile && !--pFile->nRefCount)
        delete pFile;
}

void __fastcall sub_M126_Emit_00419760(int a, FILEREC* pFile, int nUnused)
{
    RemoveFileRef(pFile);
}

// 0x00419A80
int __stdcall SFileCloseArchive(void* hArchive)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    ARCHIVEREC* pRec;
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    ARCHIVEREC* pHandle = (ARCHIVEREC*)hArchive;
    if (pHandle)
    {
        if (pHandle->hParentFile)
        {
            FILEREC* pFile;
            if (sub_00415950_GetFileRec(pRec->hParentFile, &pFile))
                SFileCloseFile(pRec->hParentFile);
        }
        else if (pHandle->pParent)
        {
            ARCHIVEREC* pParent = pRec->pParent;
            if (pParent && !--pParent->nRefCount)
                delete pParent;
        }
    }
    (pRec ? &pRec->tLink : &gStormList_00708354.m_terminator)->Unlink();
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004198D0
int __stdcall SFileCloseFile(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    FILEREC* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    (pRec ? &pRec->tLink : &gFileList_0070836C.m_terminator)->Unlink();
    if (pRec && !--pRec->nRefCount)
        delete pRec;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

inline void AUDIOSTREAM::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00419BD0
static inline void RemoveStreamRef(AUDIOSTREAM* stream)
{
    if (stream && --stream->nRefCount == 0)
        delete stream;
}

void __stdcall emit_release_00419BD0(AUDIOSTREAM* stream) { RemoveStreamRef(stream); }

// 0x0041BA60
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq)
{
    void* hFile;
    VALIDATEBEGIN;
    if (!phMpq)
        nValid = 0;
    else
        *phMpq = 0;
    VALIDATE(szMpqName);
    VALIDATE(*szMpqName);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();

    char szPath[0x104];
    SStrCopy(szPath, szMpqName, 0x104);
    szPath[0x103] = 0;
    if (!sub_00415940_PathPresent(szPath))
    {
        if (*szMpqName != 0x5C && !strstr(szMpqName, ":\\") && !strstr(szMpqName, "\\\\"))
            sub_00415A80_BuildPath(0, szMpqName, szPath);
        else
            SStrCopy(szPath, szMpqName, 0x104);
    }

    const int nVolume = sub_00415960_CheckVolume(szPath);
    if ((dwFlags & 1) && !nVolume)
    {
        sub_0041C340_SetLastError(0xF);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    hFile = CreateFileA(szPath, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }

    void* pMemory = SMemAlloc(sizeof(ARCHIVEREC), gszTypeNameArchiveRec_00708398, -2, 8);
    ARCHIVEREC* pArchive = pMemory ? new (pMemory) ARCHIVEREC : 0;
    SStrCopy(pArchive->szName, szPath, 0x104);
    pArchive->hFile = hFile;
    pArchive->nMode = nVolume ? 3 : 0;
    pArchive->nPriority = nPriority;
    pArchive->bNested = 1;
    if (nVolume)
        pArchive->nMode = 3;
    else
        pArchive->nMode = ((unsigned char)dwFlags >> 1) & 1;
    pArchive->bNoDiskSearch = (dwFlags >> 2) & 1;
    pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), ".\\SOURCE\\SFILE.CPP", 0x1052, 0);
    pArchive->nArchiveOffset = 0;
    pArchive->nArchiveLimit = GetFileSize(hFile, 0);
    pArchive->nRefs = 0;
    const int nResult = s_OpenArchive(pArchive, dwFlags, nVolume, phMpq);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

// build: context sub_004192F0_OpenDiskFile
static __forceinline int sub_004192F0_OpenDiskFile(const char* szFileName, unsigned int dwFlags, void** phFile, const char* szPath)
{
    void* hFile = CreateFileA(szPath, 0x80000000, 1, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        if (dwFlags & 4)
        {
            *phFile = hFile;
        }
        else
        {
            FILEREC* pFile = (FILEREC*)gFileList_0070836C.sub_00418F20_NewNode(1, 0, 0);
            SStrCopy(pFile->name, szFileName, 0x104);
            pFile->szLocalPath = SStrDup(szPath);
            pFile->hFile = hFile;
            pFile->nRefCount = 1;
            pFile->nCrcValue = 0;
            *phFile = pFile;
        }

        return 2;
    }

    return 0;
}

// 0x004192F0
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile)
{
    VALIDATEBEGIN;
    if (!phFile)
        nValid = 0;
    else
        *phFile = 0;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;

    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();

    D2StormBlockStrc* pBlock;
    ARCHIVEREC* pArchive;
    char szPath[0x104];
    int nResult = 0;
    const int nFound = GetFileBlockEntry((void*)hMpq, szFileName, dwFlags, &pArchive, &pBlock, szPath);
    if (nFound)
    {
        if (nFound == 2)
        {
            nResult = sub_004192F0_OpenDiskFile(szFileName, dwFlags, phFile, szPath);
        }
        else if (dwFlags & 4)
        {
            void* hFile = CreateFileA(pArchive->szName, 0x80000000, 1, 0, 3, 0x8000000, 0);
            nResult = hFile != (void*)-1;
            *phFile = hFile;
            if (nResult)
                SetFilePointer(hFile, pBlock->nOffset, 0, 0);
            else
                sub_0041C340_SetLastError(2);
        }
        else
        {
            const char* szBaseName = szFileName;
            const char* szSeparator = SStrChrR(szBaseName, ':');
            if (szSeparator)
                szBaseName = szSeparator + 1;
            szSeparator = SStrChrR(szBaseName, '\\');
            if (szSeparator)
                szBaseName = szSeparator + 1;

            unsigned int nKey = sub_00415330_HashString(3, szBaseName);
            D2StormBlockStrc* pFileBlock = pBlock;
            const unsigned int dwBlockFlags = pFileBlock->dwFlags;
            ARCHIVEREC* pFileArchive = pArchive;
            if (dwBlockFlags & 0x20000)
                nKey = (pFileBlock->nOffset - pFileArchive->nArchiveOffset + nKey) ^ pFileBlock->nFileSize;

            const unsigned int nBlocks = (pFileBlock->nFileSize + pFileArchive->sectorsize - 1) / pFileArchive->sectorsize;
            unsigned int* pBlockOffsets = 0;
            if (dwBlockFlags & 0xFF00)
                pBlockOffsets = (unsigned int*)SMemAlloc((nBlocks + 1) * sizeof(unsigned int), gszSFileSourceFile_006CF084, 0x1231, 0);

            FILEREC* pFile = (FILEREC*)gFileList_0070836C.sub_00418F20_NewNode(1, 0, 0);
            SStrCopy(pFile->name, szFileName, 0x104);
            pFile->hFile = (void*)-1;
            pFile->archive = pFileArchive;
            pFile->pBlock = pFileBlock;
            pFile->nKey = nKey;
            pFile->nBlocks = nBlocks;
            pFile->pBlockOffsets = pBlockOffsets;
            pFile->pBuffer = (unsigned char*)SMemAlloc(0x1000, gszSFileSourceFile_006CF084, 0x123C, 0);
            pFile->nRefCount = 1;
            pFile->nCrcValue = pFileBlock->nCrc ? gnFileCrc_007790B0 : 0;
            pFile->nCrcState = 1;
            ++pFileArchive->nOpenFiles;
            *phFile = pFile;
            nResult = 1;
        }
    }

    LeaveCriticalSection(&gBasePathLock_00779068);
    if (nResult && gpfnOpenFileCallback_00779060)
        gpfnOpenFileCallback_00779060(szFileName, gpOpenFileCallbackParam_00779064);

    return nResult;
}

// 0x0041BCA0
int __stdcall SFileOpenFileAsArchive(unsigned int hMpq, const char* szName, int nPriority, unsigned int nFlags, void** phArchive)
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
    if (!(pFile->pBlock->dwFlags & 0x1FF00))
    {
        void* pMemory = SMemAlloc(sizeof(ARCHIVEREC), gszTypeNameArchiveRec_00708398, -2, 8);
        ARCHIVEREC* pArchive = pMemory ? new (pMemory) ARCHIVEREC : 0;
        SStrCopy(pArchive->szName, szName, 0x104);
        pArchive->hFile = pFile->archive->hFile;
        pArchive->nMode = pFile->archive->nMode;
        pArchive->bNoDiskSearch = (nFlags >> 2) & 1;
        pArchive->nPriority = nPriority;
        pArchive->nRefs = 0;
        pArchive->nOpenFiles = 1;
        pArchive->hNestedFile = hFile;
        pArchive->pHeader = (D2StormMpqHeaderStrc*)SMemAlloc(sizeof(D2StormMpqHeaderStrc), gszSFileSourceFile_006CF084, 0x11AD, 0);
        pArchive->nArchiveOffset = pFile->pBlock->nOffset;
        pArchive->nArchiveLimit = pFile->pBlock->nFileSize + pFile->pBlock->nOffset;
        s_OpenArchive(pArchive, nFlags, pArchive->nMode, phArchive);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 1;
    }
    SFileCloseFile(hFile);
    sub_0041C340_SetLastError(0x3EE);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 0;
}

#include "gen/data/Source/Storm/SOURCE/SFILE_00411A80.inc"
