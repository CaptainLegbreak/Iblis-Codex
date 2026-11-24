#include "D2StormLink.h"
#include "D2StormListArray.h"
struct D2StormSlotListStrc;
struct D2StormEntry38Strc;
struct D2SGameDataStrc;
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
struct D2StormListAStrc;
struct D2StormChunkListStrc;
struct D2StormListFixedArrayStrc;
struct D2StormSlotListArrayStrc;
struct D2StormListArrayStrc;
struct D2StormHashTableStrc;
struct D2StormHashTableReuseStrc;
struct D2StormGameDataArrayStrc;
struct D2StormGameDataListStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
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
    bool IGNORELIST_IsLinkLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    char* IGNORELIST_GetStringEntryKey();
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;

    D2ChatStormBaseArrayAStrc();
    unsigned int IGNORELIST_GetStringSlotArrayCount();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;

    D2ChatStormBaseArrayBStrc();
    unsigned int IGNORELIST_GetMappingSlotArrayCount();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitStringListTerminator();
    char* IGNORELIST_GetStringListHead();
    void IGNORELIST_ResetStringList();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitMappingListTerminator();
    char* IGNORELIST_GetMappingListHead();
    void IGNORELIST_ResetMappingList();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* IGNORELIST_GetStringTableHead();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListAStrc();
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
    void UnlinkAll();
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    ~D2CommonMappingEntryNodeBaseStrc();
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int m_hashval;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc m_linktofull;
    char* m_key;

    ~D2CommonStringEntryNodeStrc();
    void IGNORELIST_DestroyStringEntryNode();
};

struct D2CommonStormHashTableAStrc
{
    void IGNORELIST_InternalClearStringTable(int bWarn);
    void IGNORELIST_ClearStringTable();
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

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_00450580_DeleteAll();                                                                          // 0x00450580
};

struct D2StormListFixedArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    ~D2StormListFixedArrayStrc();                                                                           // 0x0044FF60
    void sub_00450500_Clear();
};

struct D2StormSlotListArrayStrc
{
    D2StormListFixedArrayStrc m_array;
    ~D2StormSlotListArrayStrc();
};


struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableStrc();
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;
};

struct D2StormHashTableReuseStrc : D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableReuseStrc();
    virtual void Destroy();
    D2StormListAStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormChunkListStrc m_chunkList;
    void sub_00450690_DeleteChunksAndReuse();
};

typedef char chkReuseChunk_M125[(int)&((D2StormHashTableReuseStrc*)0)->m_chunkList == 0x38 ? 1 : -1];

struct D2SGameDataStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    char unk0x14[0x1DF4 - 0x14];

    D2SGameDataStrc()
    {
        unk0x04 = 0;
        unk0x08 = 0;
        unk0x0C = 0;
        unk0x10 = 0;
    }
    D2SGameDataStrc(const D2SGameDataStrc& tSource);                                                        // 0x00450950
};

typedef char chkSGameData_M125[sizeof(D2SGameDataStrc) == 0x1DF4 ? 1 : -1];

struct D2StormGameDataArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2SGameDataStrc* m_data;
    unsigned int m_chunk;
    D2SGameDataStrc* sub_00450ED0_New();                                                                    // 0x00450ED0
};

struct D2StormGameDataListStrc
{
    D2StormGameDataArrayStrc m_array;
    D2SGameDataStrc* sub_00450F70_New();
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

// 0x0044F9D0
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

// 0x00450370
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

unsigned int D2Storm603ED0Strc::sub_00603ED0_GetDifference()
{
    return nFirst - nSecond;
}

D2Storm603F70Strc::D2Storm603F70Strc(int nUnused)
{
    tArray.m_alloc = 0;
    tArray.m_count = 0;
    tArray.m_data = 0;
    tArray.m_chunk = 0;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00450090
D2StormSlotListArrayStrc::~D2StormSlotListArrayStrc()
{
}

// 0x00450500
void D2StormListFixedArrayStrc::sub_00450500_Clear()
{
    this->D2StormListFixedArrayStrc::~D2StormListFixedArrayStrc();
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

// 0x00450690
void D2StormHashTableReuseStrc::sub_00450690_DeleteChunksAndReuse()
{
    m_chunkList.sub_00450580_DeleteAll();
    m_reuseList.sub_0044FC60_DeleteAll();
}

// 0x00450D30
void __fastcall sub_00450D30_ConstructGameData(D2SGameDataStrc* pData)
{
    new (pData) D2SGameDataStrc;
}

// 0x00450D50
void __fastcall sub_00450D50_CopyConstructGameData(D2SGameDataStrc* pData, const D2SGameDataStrc& tSource)
{
    new (pData) D2SGameDataStrc(tSource);
}

// 0x00450F70
D2SGameDataStrc* D2StormGameDataListStrc::sub_00450F70_New()
{
    return m_array.sub_00450ED0_New();
}

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

// 0x00450EC0
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
