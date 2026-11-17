// build: context D2StormSlotListStrc::~D2StormSlotListStrc

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    D2StormLinkStrc* sub_0060E170_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0060E1C0_NextLink(int nLinkOffset);
};

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(D2StormNodeStrc* pNode)
    {
        return pNode ? &pNode->f_0 : &m_terminator;
    }
    D2StormLinkStrc* sub_00601FA0_Link(D2StormNodeStrc* pNode);
    void sub_00601FC0_LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode);
    char* sub_00602070_Next(D2StormNodeStrc* pNode);
    void sub_00602190_UnlinkNode(D2StormNodeStrc* pNode);
};

struct D2StormListEStrc
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
    D2StormLinkStrc* sub_00602110_Link(char* pNode);
    D2StormLinkStrc* sub_00602280_Link(char* pNode);
    void sub_006022F0_InitLinkField(int nLinkOffset);
    char* sub_00602310_Next(char* pNode);
    void sub_00602350_InitLinkField(int nLinkOffset);
    void sub_006024E0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    void sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_00603FC0_LinkNode(char* pNode, int nLinkType, char* pExistingNode);
    void sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource);
};

struct D2StormListEArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListEStrc* f_8;
    unsigned int f_C;

    D2StormListEStrc* sub_0060E0E0_At(unsigned int nIndex);
    D2StormListEStrc* sub_0060E110_At(unsigned int nIndex);
    unsigned int sub_0060E2A0_CalcChunkSize(unsigned int nCount);
    unsigned int sub_0060E300_CalcChunkSize(unsigned int nCount);
};

struct D2StormHashTableEStrc
{
    char unk0x00[0x24];
    unsigned int m_slotmask;

    unsigned int sub_0060E1F0_SlotIndex(unsigned int nHashVal);
    unsigned int sub_0060E210_SlotIndex(unsigned int nHashVal);
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc()
    {
        Unlink();
    }
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormSlotLinkStrc m_terminator;

    D2StormSlotListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc()
    {
        UnlinkAll();
    }
    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
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
    void LinkToTail(char* pNode)
    {

        D2StormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormSlotLinkStrc* pExistingLink = Link(0);
        D2StormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
    }
    void UnlinkAll();                                                                                       // 0x00602640
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    void sub_00603300_SetCount(unsigned int nCount);                                                        // 0x00603300
};

struct D2StormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2GameHashTableStrc
{
    virtual void sub_006036D0_InternalDelete(D2StormHashNodeStrc* pNode);                                   // 0x006036D0
    virtual void sub_00603610_VirtSlot1();                                                                  // 0x00603610
    virtual void sub_006037B0_VirtSlot2();                                                                  // 0x006037B0
    virtual void sub_00603780_VirtSlot3();                                                                  // 0x00603780
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00603C80_GrowListArray();
};

// 0x00601FA0
D2StormLinkStrc* D2StormNodeListStrc::sub_00601FA0_Link(D2StormNodeStrc* pNode)
{
    return pNode ? &pNode->f_0 : &m_terminator;
}

// 0x00601FC0
void D2StormNodeListStrc::sub_00601FC0_LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormLinkStrc* pPrevLink;
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = (char*)pNode;
        break;
    default:
        pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = (char*)pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x00602070
char* D2StormNodeListStrc::sub_00602070_Next(D2StormNodeStrc* pNode)
{
    return Link(pNode)->Next();
}

// 0x00602110
D2StormLinkStrc* D2StormListEStrc::sub_00602110_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x00602190
void D2StormNodeListStrc::sub_00602190_UnlinkNode(D2StormNodeStrc* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00602280
D2StormLinkStrc* D2StormListEStrc::sub_00602280_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x006022F0
void D2StormListEStrc::sub_006022F0_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x00602310
char* D2StormListEStrc::sub_00602310_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00602350
void D2StormListEStrc::sub_00602350_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x006024E0
void D2StormListEStrc::sub_006024E0_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormLinkStrc* pPrevLink;
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x00603C80
void D2GameHashTableStrc::sub_00603C80_GrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = 2 * nOldCount;
    D2StormSlotListStrc tTempList;
    tTempList.ChangeLinkOffset(4);

    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.f_8[i].Head()) != 0)
            tTempList.LinkToTail(pNode);
    }

    m_slotlistarray.sub_00603300_SetCount(nNewCount);
    for (unsigned int i = 0; i < nNewCount; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;

    char* pNode;
    while ((pNode = tTempList.Head()) != 0)
        m_slotlistarray.f_8[((D2StormHashNodeStrc*)pNode)->f_0 & m_slotmask].LinkToTail(pNode);
}

// 0x00603F50
void D2StormListEStrc::sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x00603FC0
void D2StormListEStrc::sub_00603FC0_LinkNode(char* pNode, int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    D2StormLinkStrc* pPrevLink;
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x0060E0E0
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E0E0_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0060E110
D2StormListEStrc* D2StormListEArrayStrc::sub_0060E110_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0060E170
D2StormLinkStrc* D2StormLinkStrc::sub_0060E170_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0060E1C0
D2StormLinkStrc* D2StormLinkStrc::sub_0060E1C0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0060E1F0
unsigned int D2StormHashTableEStrc::sub_0060E1F0_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x0060E210
unsigned int D2StormHashTableEStrc::sub_0060E210_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x0060E2A0
unsigned int D2StormListEArrayStrc::sub_0060E2A0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x0060E2E0
unsigned int __stdcall sub_0060E2E0_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0060E300
unsigned int D2StormListEArrayStrc::sub_0060E300_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x0060E340
unsigned int __stdcall sub_0060E340_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0060E370
void D2StormListEStrc::sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x0060E390
void D2StormListEStrc::sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}
