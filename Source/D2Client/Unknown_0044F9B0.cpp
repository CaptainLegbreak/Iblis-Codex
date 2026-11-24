#include "D2Client.h"
#include "D2StormAutoLink.h"
#include "D2GameTypes.h"
class type_info;
struct SGAMEDATA;
class HASHKEY_NONE;
template <class T, int FILL> class TSExplicitList;
template <class T, class KEY> class TSHashObjectChunk;

// The decorated name of T's type descriptor, which the Storm templates pass to the allocator as the file name.
#define STORM_TYPENAME(T) ((const char*)&typeid(T) + 8)

// build: symbol ??_R0?AUSGAMEDATA@@@8 0x0070F564
// build: symbol ??_R0?AV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@8 0x0070F57C
// build: symbol ??_R0?AV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@8 0x0070F5EC
typedef TSExplicitList<SGAMEDATA, 0xDDDDDDDD> D2SGameDataExplicitList;
typedef TSHashObjectChunk<SGAMEDATA, HASHKEY_NONE> D2SGameDataHashObjectChunk;


struct D2StormSlotListStrc;
struct D2StormEntry38Strc;
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
struct D2StormLinkStrc;
struct D2SGameDataStrc;
struct D2StormListAStrc;
struct D2StormListArrayStrc;
struct D2StormHashTableStrc;
struct D2StormHashTableReuseStrc;
struct D2StormGameDataArrayStrc;
struct D2StormHashObjectChunkStrc;
struct D2StormChunkListStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct D2StormSlotLinkStrc;
struct D2StormListStrc;
struct D2StormListEStrc;
struct D2StormSlotArrayStrc;
struct D2StormEntryArrayStrc;
struct D2StormSlotGrowArrayStrc;
struct D2StormEntryGrowArrayStrc;
struct D2StormHashChunkStrc;
struct D2Storm603530ArrayStrc;
struct D2Storm603530Strc;
struct D2Storm603570ArrayStrc;
struct D2Storm603570LinkStrc;
struct D2Storm603570ListStrc;
struct D2Storm603570Strc;
struct D2GameHashTableReuseStrc;
struct D2Storm603ED0Strc;
struct D2Storm603F70Strc;
struct D2CriticalSectionStrc;
struct D2StormEntryArray604080Strc;
struct D2StormEntryLink604080Strc;
struct D2StormEntryList604080Strc;
struct D2StormEntry604080Strc;
struct D2GameHashTableStrc;
struct D2StormEntryGrowArray604460Strc;
struct D2Storm604460Strc;
struct D2Storm604470Strc;
struct D2StormCritSectStrc;
struct D2GameHashTableReuseViewStrc;
struct D2GameExportTableSimpleViewStrc;
struct D2GameDataTableViewStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020

struct D2SGameDataStrc
{
    unsigned int m_hashval;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc m_linktofull;
    char unk0x14[0x1DE0];

    D2SGameDataStrc()
    {
    }
    ~D2SGameDataStrc();                                                                                     // 0x0044F820
    static void operator delete(void* pMemory);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc(const D2StormListAStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    D2SGameDataStrc* HeadNode()
    {
        return (int)m_terminator.m_next > 0 ? (D2SGameDataStrc*)m_terminator.m_next : 0;
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        if (pLink->m_prevlink)
            pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExisting);
        if (nLinkType == 1)
        {
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
        }
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044FC60_DeleteAll();
    static void operator delete(void* pMemory);
    void sub_004502A0_LinkNode(D2SGameDataStrc* pNode, unsigned int nLinkType, D2SGameDataStrc* pExisting); // 0x004502A0
    D2SGameDataStrc* sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;

    ~D2StormListArrayStrc();                                                                                // 0x0044FF60
    void sub_0044FE10_ReallocData(unsigned int nAlloc);
    static void operator delete(void* pMemory);
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;
};

struct D2StormHashTableReuseStrc : D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormGameDataArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2SGameDataStrc* m_data;
    unsigned int m_chunk;

    D2StormGameDataArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
    ~D2StormGameDataArrayStrc();                                                                            // 0x0044FD80
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameDataArrayStrc m_array;
    D2StormLinkStrc f_10;

    static void operator delete(void* pMemory);
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormHashObjectChunkStrc* HeadChunk()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormHashObjectChunkStrc*)m_terminator.m_next : 0;
    }
    void sub_00450580_DeleteAll();
    void sub_004508A0_LinkNode(D2StormHashObjectChunkStrc* pNode, unsigned int nLinkType, D2StormHashObjectChunkStrc* pExisting); // 0x004508A0
    D2StormHashObjectChunkStrc* sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2Storm408ElemStrc* m_data;
    unsigned int m_chunk;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void CelReuseListDeleteAll();
    void CelChunkListDeleteAll();
};

struct D2StormSlotArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormSlotListStrc* m_data;
    unsigned int m_chunk;

    ~D2StormSlotArrayStrc();
    void CelSlotArrayClear();
};

struct D2StormEntryArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormEntry38Strc* m_data;
    unsigned int m_chunk;

    ~D2StormEntryArrayStrc();
};

struct D2StormSlotGrowArrayStrc
{
    D2StormSlotArrayStrc tArray;

    ~D2StormSlotGrowArrayStrc();
};

struct D2StormEntryGrowArrayStrc
{
    D2StormEntryArrayStrc tArray;

    ~D2StormEntryGrowArrayStrc();
};

struct D2StormHashChunkStrc
{
    D2StormEntryArrayStrc tArray;
    D2StormSlotLinkStrc f_10;

    ~D2StormHashChunkStrc();
};

struct D2Storm603530ArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;
};

struct D2Storm603530Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603530Strc();
};

struct D2Storm603570ArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;

    D2Storm603570ArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
};

struct D2Storm603570LinkStrc
{
    D2Storm603570LinkStrc* m_prevlink;
    char* m_next;

    D2Storm603570LinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2Storm603570ListStrc
{
    int m_linkoffset;
    D2Storm603570LinkStrc m_terminator;

    D2Storm603570ListStrc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2Storm603570Strc
{
    unsigned int unk0x00;
    D2Storm603570ArrayStrc tArray;
    char unk0x14[0x18];
    D2Storm603570ListStrc tList;

    D2Storm603570Strc();
};

struct D2GameHashTableReuseStrc
{
    char unk0x00[0x28];
    D2StormListEStrc m_reuseList;
    int unk0x34;
    D2StormListEStrc m_chunkList;

    void CelListTableDeleteReuseLists();
};

struct D2Storm603ED0Strc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00603ED0_GetDifference();
};

struct D2Storm603F70Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603F70Strc(int nUnused);
};


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection);

struct D2StormEntryArray604080Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;

    D2StormEntryArray604080Strc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
};

struct D2StormEntryLink604080Strc
{
    D2StormEntryLink604080Strc* m_prevlink;
    char* m_next;

    D2StormEntryLink604080Strc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2StormEntryList604080Strc
{
    int m_linkoffset;
    D2StormEntryLink604080Strc m_terminator;

    D2StormEntryList604080Strc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormEntryList604080Strc(const D2StormEntryList604080Strc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2StormEntry604080Strc
{
    unsigned int unk0x00;
    D2StormEntryArray604080Strc tArray;
    unsigned int unk0x14;
    unsigned int nField18;
    unsigned int nField1C;
    unsigned int nField20;
    unsigned int nField24;
    unsigned int nField28;
    D2StormEntryList604080Strc tList;

    D2StormEntry604080Strc()
    {
    }
    D2StormEntry604080Strc(const D2StormEntry604080Strc& source) : nField18(source.nField18), nField1C(source.nField1C),
        nField20(source.nField20), nField24(source.nField24), nField28(source.nField28), tList(source.tList)
    {
    }
};

struct D2GameHashTableStrc
{
    void CelListTableInternalClear(int bWarn);
    void sub_00604070_Clear();
};

struct D2StormEntryGrowArray604460Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormEntry604080Strc* m_data;
    unsigned int m_chunk;

    D2StormEntry604080Strc* sub_006043B0_New();
};

struct D2Storm604460Strc
{
    D2StormEntryGrowArray604460Strc tArray;

    D2StormEntry604080Strc* sub_00604460_New();
};

struct D2Storm604470Strc
{
    unsigned int nField00;
    unsigned int nField04;
    unsigned int f_8;
    unsigned int nField0C;
    unsigned int nField10;
    unsigned int nField14;

    D2Storm604470Strc();
};

struct D2StormCritSectStrc
{
    D2CriticalSectionStrc m_critsect;

    ~D2StormCritSectStrc()
    {
        DeleteCriticalSection(&m_critsect);
    }
};

struct D2GameHashTableReuseViewStrc
{
    char unk0x00[0x44];

    ~D2GameHashTableReuseViewStrc();
};

struct D2GameExportTableSimpleViewStrc : D2GameHashTableReuseViewStrc
{
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    ~D2GameExportTableSimpleViewStrc();
};

struct D2GameDataTableViewStrc : D2GameHashTableReuseViewStrc
{
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;
    D2StormCritSectStrc m_sync;

    ~D2GameDataTableViewStrc();
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

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
    return m_key;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
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

// 0x0044F9B0
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
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

// 0x0044FB10
D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x0044FC60
void D2StormListAStrc::sub_0044FC60_DeleteAll()
{
    D2SGameDataStrc* pNode;
    while ((pNode = HeadNode()) != 0)
    {
        pNode->m_linktofull.Unlink();
        pNode->m_linktoslot.Unlink();
        SMemFree(pNode, STORM_TYPENAME(SGAMEDATA), -2, 0);
    }
}

// 0x0044FE10
void D2StormListArrayStrc::sub_0044FE10_ReallocData(unsigned int nAlloc)
{
    D2StormListAStrc* pOld = m_data;
    for (unsigned int i = nAlloc; i < m_count; i++)
        pOld[i].~D2StormListAStrc();
    m_alloc = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2StormListAStrc), STORM_TYPENAME(D2SGameDataExplicitList), -2, 0x10);
    m_data = (D2StormListAStrc*)pNew;
    if (!pNew)
    {
        m_data = (D2StormListAStrc*)SMemAlloc(nAlloc * sizeof(D2StormListAStrc), STORM_TYPENAME(D2SGameDataExplicitList), -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= m_count ? m_count : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&m_data[i]) D2StormListAStrc(pOld[i]);
                pOld[i].~D2StormListAStrc();
            }
            SMemFree(pOld, STORM_TYPENAME(D2SGameDataExplicitList), -2, 0);
        }
    }
}

// 0x00450390
D2SGameDataStrc* D2StormListAStrc::sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, STORM_TYPENAME(SGAMEDATA), -2, nFlags | 8);
    D2SGameDataStrc* pNode = pMemory ? new (pMemory) D2SGameDataStrc : 0;
    if (nLocation)
        sub_004502A0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// build: symbol ?InternalDelete@D2StormHashTableStrc@@UAEXPAUD2SGameDataStrc@@@Z 0x004503F0
void D2StormHashTableStrc::InternalDelete(D2SGameDataStrc* pNode)
{
    pNode->~D2SGameDataStrc();
    SMemFree(pNode, STORM_TYPENAME(SGAMEDATA), -2, 0);
}

// build: symbol ?InternalNew@D2StormHashTableStrc@@UAEPAUD2SGameDataStrc@@PAUD2StormListAStrc@@II@Z 0x00450420
D2SGameDataStrc* D2StormHashTableStrc::InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, STORM_TYPENAME(SGAMEDATA), -2, nFlags | 8);
    D2SGameDataStrc* pNode = new (pMemory) D2SGameDataStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00450580
void D2StormChunkListStrc::sub_00450580_DeleteAll()
{
    D2StormHashObjectChunkStrc* pChunk;
    while ((pChunk = HeadChunk()) != 0)
    {
        pChunk->f_10.Unlink();
        for (unsigned int i = 0; i < pChunk->m_array.m_count; i++)
        {
            D2SGameDataStrc* pNode = &pChunk->m_array.m_data[i];
            pNode->m_linktofull.Unlink();
            pNode->m_linktoslot.Unlink();
        }
        if (pChunk->m_array.m_data)
            SMemFree(pChunk->m_array.m_data, STORM_TYPENAME(SGAMEDATA), -2, 0);
        SMemFree(pChunk, STORM_TYPENAME(D2SGameDataHashObjectChunk), -2, 0);
    }
}

// build: symbol ?InternalDelete@D2StormHashTableReuseStrc@@UAEXPAUD2SGameDataStrc@@@Z 0x00450D60
void D2StormHashTableReuseStrc::InternalDelete(D2SGameDataStrc* pNode)
{
    pNode->~D2SGameDataStrc();
    SMemFree(pNode, STORM_TYPENAME(SGAMEDATA), -2, 0);
}

// build: symbol ?InternalNew@D2StormHashTableReuseStrc@@UAEPAUD2SGameDataStrc@@PAUD2StormListAStrc@@II@Z 0x00451000
D2SGameDataStrc* D2StormHashTableReuseStrc::InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, STORM_TYPENAME(SGAMEDATA), -2, nFlags | 8);
    D2SGameDataStrc* pNode = new (pMemory) D2SGameDataStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// build: symbol ??_GD2SGameDataStrc@@QAEPAXI@Z 0x0044FBB0
// build: symbol ??_GD2StormListAStrc@@QAEPAXI@Z 0x0044FCF0
// build: symbol ??_GD2StormHashObjectChunkStrc@@QAEPAXI@Z 0x004500A0
// build: symbol ??_GD2StormListArrayStrc@@QAEPAXI@Z 0x004504D0
// 0x0044FBB0
inline void D2SGameDataStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0044FCF0
inline void D2StormListAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004500A0
inline void D2StormHashObjectChunkStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004504D0
inline void D2StormListArrayStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void sub_Emit_D2SGameDataStrc(D2SGameDataStrc* p)
{
    delete p;
}

void sub_Emit_D2StormListAStrc(D2StormListAStrc* p)
{
    delete p;
}

void sub_Emit_D2StormHashObjectChunkStrc(D2StormHashObjectChunkStrc* p)
{
    delete p;
}

void sub_Emit_D2StormListArrayStrc(D2StormListArrayStrc* p)
{
    delete p;
}

#include "gen/data/Source/D2Client/Unknown_0044F9B0.inc"

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00450030
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

D2StormSlotGrowArrayStrc::~D2StormSlotGrowArrayStrc()
{
}

D2StormEntryGrowArrayStrc::~D2StormEntryGrowArrayStrc()
{
}

D2StormHashChunkStrc::~D2StormHashChunkStrc()
{
    f_10.Unlink();
}

void __fastcall sub_00603500_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00450350
D2Storm603530Strc::D2Storm603530Strc()
{
    tArray.m_alloc = 0;
    tArray.m_count = 0;
    tArray.m_data = 0;
    tArray.m_chunk = 0;
}

D2Storm603570Strc::D2Storm603570Strc()
{
}

void D2StormSlotArrayStrc::CelSlotArrayClear()
{
    this->D2StormSlotArrayStrc::~D2StormSlotArrayStrc();
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

void D2GameHashTableReuseStrc::CelListTableDeleteReuseLists()
{
    m_chunkList.CelChunkListDeleteAll();
    m_reuseList.CelReuseListDeleteAll();
}

// 0x00450800
unsigned int D2Storm603ED0Strc::sub_00603ED0_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00450880
D2Storm603F70Strc::D2Storm603F70Strc(int nUnused)
{
    tArray.m_alloc = 0;
    tArray.m_count = 0;
    tArray.m_data = 0;
    tArray.m_chunk = 0;
}

void D2GameHashTableStrc::sub_00604070_Clear()
{
    CelListTableInternalClear(0);
}

void __fastcall sub_00604080_ConstructEntry(D2StormEntry604080Strc* pEntry)
{
    new (pEntry) D2StormEntry604080Strc;
}

void __fastcall sub_00604100_CopyConstructEntry(D2StormEntry604080Strc* pEntry, const D2StormEntry604080Strc* pSource)
{
    new (pEntry) D2StormEntry604080Strc(*pSource);
}

D2StormEntry604080Strc* D2Storm604460Strc::sub_00604460_New()
{
    return tArray.sub_006043B0_New();
}

// 0x00450F80
D2Storm604470Strc::D2Storm604470Strc()
{
    nField00 = 0;
    nField04 = 0;
    f_8 = 0;
    nField0C = 0;
    nField10 = 0;
    nField14 = 0;
}

// 0x00450FA0
D2StormHashObjectChunkStrc* D2StormChunkListStrc::sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHashObjectChunkStrc) + nExtraBytes, STORM_TYPENAME(D2SGameDataHashObjectChunk), -2, nFlags | 8);
    D2StormHashObjectChunkStrc* pNode = pMemory ? new (pMemory) D2StormHashObjectChunkStrc : 0;
    if (nLocation)
        sub_004508A0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

D2GameExportTableSimpleViewStrc::~D2GameExportTableSimpleViewStrc()
{
}

D2GameDataTableViewStrc::~D2GameDataTableViewStrc()
{
}
