// build: context D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc
// build: context D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2CommonStormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2CommonStormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
// build: symbol ?UnlinkAll@D2CommonStormListAStrc@@QAEXXZ 0x0060E820
// build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
    void UnlinkAll();
    D2StormLinkStrc* sub_0060E450_Link(char* pNode);
    void sub_0060E470_InitLinkField(int nLinkOffset);
    void sub_0060E490_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    char* sub_0060E540_RawNext(char* pNode);
    char* sub_0060E650_Next(char* pNode);
    void sub_0060EC80_ChangeLinkOffset(int nLinkOffset);
};

struct D2CommonStormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
// build: symbol ?UnlinkAll@D2CommonStormListBStrc@@QAEXXZ 0x0060ECB0
// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
    void UnlinkAll();
    void sub_0060E5B0_InitLinkField(int nLinkOffset);
    D2StormLinkStrc* sub_0060E630_Link(char* pNode);
    char* sub_0060E7C0_Next(char* pNode);
    void sub_0060E890_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    char* sub_0060E940_RawNext(char* pNode);
    void sub_0060EF30_ChangeLinkOffset(int nLinkOffset);
};

struct D2CommonStormListCStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2CommonStormListCStrc(const D2CommonStormListCStrc& source);
};

struct D2CommonStormListDStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2CommonStormListDStrc(const D2CommonStormListDStrc& source);
};

struct D2CommonStormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2CommonStormListEStrc(const D2CommonStormListEStrc& source);
};

struct D2CommonStormListFStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2CommonStormListFStrc(const D2CommonStormListFStrc& source);
};

struct D2CommonStormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListAStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListBStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListBStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void UnlinkAll();
};

static unsigned int __stdcall STORM_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    D2CommonStormSlotArrayAStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    unsigned int sub_0060E2A0_CalcChunkSize(unsigned int nCount);                                           // 0x0060E2A0
    void sub_0060F390_ReallocData(unsigned int nAlloc);                                                     // 0x0060F390
    void sub_0060F6D0_Reserve(unsigned int nCount, int bRound);
    void sub_0060F9D0_SetCount(unsigned int nCount);
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    D2CommonStormSlotArrayBStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    unsigned int sub_0060E300_CalcChunkSize(unsigned int nCount);                                           // 0x0060E300
    void sub_0060F720_ReallocData(unsigned int nAlloc);                                                     // 0x0060F720
    void sub_0060FAD0_Reserve(unsigned int nCount, int bRound);
    void sub_006100B0_SetCount(unsigned int nCount);
};

struct StringEntryNode;
struct MappingEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>;
typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;
template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>;
typedef TSHashTable<MappingEntryNode, HASHKEY_STRI> D2CommonStormHashTableBStrc;
// build: symbol ??0?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@QAE@XZ 0x006104A0
// build: symbol ??0?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@QAE@XZ 0x00610B30

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormHashNodeStrc* pNode);                             // 0x0060FFA0
    virtual void sub_0060FEF0_VirtSlot1();                                                                  // 0x0060FEF0
    virtual void sub_00610050_VirtSlot2();                                                                  // 0x00610050
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020
    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();
    void sub_0060E6E0_UnlinkNode(D2CommonStormHashNodeStrc* pNode);
    void sub_0060E7A0_Delete(D2CommonStormHashNodeStrc* pNode);
    char* sub_0060EAA0_Next(char* pNode);
    char* sub_0060ED70_DeleteNext(D2CommonStormHashNodeStrc* pNode);
};

template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_00610690_InternalDelete(D2CommonStormHashNodeStrc* pNode);                             // 0x00610690
    virtual void sub_006106D0_VirtSlot1();                                                                  // 0x006106D0
    virtual void sub_00610800_VirtSlot2();                                                                  // 0x00610800
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0
    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();
    char* sub_0060EC00_Next(char* pNode);
};

// build: symbol ??_7?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62B4
// build: symbol ??_7?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62C8
// 0x0060E450
D2StormLinkStrc* D2CommonStormListAStrc::sub_0060E450_Link(char* pNode)
{
    return Link(pNode);
}

// 0x0060E470
void D2CommonStormListAStrc::sub_0060E470_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0060E490
void D2CommonStormListAStrc::sub_0060E490_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
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

// 0x0060E540
char* D2CommonStormListAStrc::sub_0060E540_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x0060E5B0
void D2CommonStormListBStrc::sub_0060E5B0_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0060E630
D2StormLinkStrc* D2CommonStormListBStrc::sub_0060E630_Link(char* pNode)
{
    return Link(pNode);
}

// 0x0060E650
char* D2CommonStormListAStrc::sub_0060E650_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x0060E6E0
void D2CommonStormHashTableAStrc::sub_0060E6E0_UnlinkNode(D2CommonStormHashNodeStrc* pNode)
{
    if (pNode->m_linktoslot.m_next)
    {
        pNode->m_linktoslot.Unlink();
        pNode->f_C.Unlink();
    }
}

// 0x0060E7A0
void D2CommonStormHashTableAStrc::sub_0060E7A0_Delete(D2CommonStormHashNodeStrc* pNode)
{
    sub_0060E6E0_UnlinkNode(pNode);
    sub_0060FFA0_InternalDelete(pNode);
}

// 0x0060E7C0
char* D2CommonStormListBStrc::sub_0060E7C0_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x0060E890
void D2CommonStormListBStrc::sub_0060E890_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
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

// 0x0060E940
char* D2CommonStormListBStrc::sub_0060E940_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x0060E9B0
D2CommonStormListCStrc::D2CommonStormListCStrc(const D2CommonStormListCStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060E9E0
D2CommonStormListDStrc::D2CommonStormListDStrc(const D2CommonStormListDStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060EAA0
char* D2CommonStormHashTableAStrc::sub_0060EAA0_Next(char* pNode)
{
    return m_fulllist.Next(pNode);
}

// 0x0060EC00
char* D2CommonStormHashTableBStrc::sub_0060EC00_Next(char* pNode)
{
    return m_fulllist.Next(pNode);
}

// 0x0060EC80
void D2CommonStormListAStrc::sub_0060EC80_ChangeLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x0060ED00
D2CommonStormListEStrc::D2CommonStormListEStrc(const D2CommonStormListEStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060ED70
char* D2CommonStormHashTableAStrc::sub_0060ED70_DeleteNext(D2CommonStormHashNodeStrc* pNode)
{
    char* pNext = m_fulllist.Next((char*)pNode);
    sub_0060E6E0_UnlinkNode(pNode);
    sub_0060FFA0_InternalDelete(pNode);
    return pNext;
}

// 0x0060EF30
void D2CommonStormListBStrc::sub_0060EF30_ChangeLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x0060F070
D2CommonStormListFStrc::D2CommonStormListFStrc(const D2CommonStormListFStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060F6D0
void D2CommonStormSlotArrayAStrc::sub_0060F6D0_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0060E2A0_CalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        sub_0060F390_ReallocData(nCount);
    }
}

// 0x0060F9D0
void D2CommonStormSlotArrayAStrc::sub_0060F9D0_SetCount(unsigned int nCount)
{
    if (nCount > f_4)
    {
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_0060E2A0_CalcChunkSize(nCount);
            sub_0060F390_ReallocData(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = f_4; i < nCount; i++)
            new (&f_8[i]) D2CommonStormSlotListAStrc;
    }
    else if (nCount < f_4)
    {
        for (unsigned int i = nCount; i < f_4; i++)
            f_8[i].~D2CommonStormSlotListAStrc();
    }
    f_4 = nCount;
}

// 0x0060FAD0
void D2CommonStormSlotArrayBStrc::sub_0060FAD0_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0060E300_CalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        sub_0060F720_ReallocData(nCount);
    }
}

// 0x006100B0
void D2CommonStormSlotArrayBStrc::sub_006100B0_SetCount(unsigned int nCount)
{
    if (nCount > f_4)
    {
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_0060E300_CalcChunkSize(nCount);
            sub_0060F720_ReallocData(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = f_4; i < nCount; i++)
            new (&f_8[i]) D2CommonStormSlotListBStrc;
    }
    else if (nCount < f_4)
    {
        for (unsigned int i = nCount; i < f_4; i++)
            f_8[i].~D2CommonStormSlotListBStrc();
    }
    f_4 = nCount;
}

// 0x006104A0
D2CommonStormHashTableAStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.sub_0060F9D0_SetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
}

// 0x00610B30
D2CommonStormHashTableBStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.sub_006100B0_SetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
}
