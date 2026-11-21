#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

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
struct D2CriticalSectionStrc;
struct D2StormLinkStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
void __cdecl sub_00415B90_InitCryptTable(); // 0x00415B90
extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern D2StormArchiveListStrc gArchiveList_00708354; // 0x00708354

inline void* operator new(unsigned int, void* pWhere) throw();

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

// 0x00417800
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
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

// 0x00418D80
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

// 0x00419180
int __stdcall sub_00419180_OpenPathAsArchive(void* hArchive, const char* szPrefix, int nPriority, unsigned int nFlags, void** phArchive)
{
    VALIDATEBEGIN;
    if (!phArchive)
        nValid = 0;
    else
        *phArchive = 0;
    VALIDATE(szPrefix);
    // stands for the original testing szPrefix and *szPrefix independently: with a plain read the null test of szPrefix is dropped
    VALIDATE(*(const volatile char*)szPrefix);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();
    D2StormArchiveRecStrc* pParent = (D2StormArchiveRecStrc*)hArchive;
    if (!pParent)
    {
        sub_0041C340_SetLastError(0x57);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    void* pMemory = SMemAlloc(sizeof(D2StormArchiveRecStrc), gszTypeNameArchiveRec_00708398, -2, 8);
    D2StormArchiveRecStrc* pArchive = pMemory ? new (pMemory) D2StormArchiveRecStrc : 0;
    SStrCopy(pArchive->szName, pParent->szName, 0x104);
    pArchive->hFile = pParent->hFile;
    pArchive->pParent = pParent;
    pArchive->nPriority = nPriority;
    pArchive->nRefs = 0;
    SStrCopy(pArchive->szPrefix, szPrefix, 0x7FFFFFFF);
    pArchive->nRefCount = 1;
    ++pParent->nRefCount;
    D2StormArchiveRecStrc* pExisting;
    for (pExisting = gArchiveList_00708354.Head(); pExisting; pExisting = (D2StormArchiveRecStrc*)pExisting->tLink.Next())
    {
        if (pExisting->nPriority <= pArchive->nPriority)
            break;
    }
    pArchive->tLink.Unlink();
    D2StormLinkStrc* pExistingLink = &pExisting->tLink;
    if (!pExisting)
        pExistingLink = &gArchiveList_00708354.m_terminator;
    D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
    pArchive->tLink.m_prevlink = pPrevLink;
    pArchive->tLink.m_next = pPrevLink->m_next;
    pPrevLink->m_next = (char*)pArchive;
    pExistingLink->m_prevlink = &pArchive->tLink;
    *phArchive = pArchive;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}
