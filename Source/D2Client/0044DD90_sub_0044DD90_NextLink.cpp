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
    D2StormLinkStrc* sub_0044DD90_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0044DE60_NextLink(int nLinkOffset);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc(const D2StormListAStrc& source);
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044DF90_CopyLinkOffset(const D2StormListAStrc* pSource);
    D2StormLinkStrc* sub_0044ED20_Link(char* pNode);
    void sub_0044EDC0_UnlinkNode(char* pNode);
    void sub_0044EE10_InitLinkField(int nLinkOffset);
    void sub_0044F980_ChangeLinkOffset(int nLinkOffset);
};

struct D2StormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListBStrc(const D2StormListBStrc& source);
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* sub_0044EDA0_Link(char* pNode);
    void sub_0044EE30_InitLinkField(int nLinkOffset);
    void sub_0044F890_UnlinkNode(char* pNode);
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    D2StormListAStrc* sub_0044DE10_At(unsigned int nIndex);
    unsigned int sub_0044DF30_CalcChunkSize(unsigned int nCount);
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(char* pNode);                                                               // 0x004503F0
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0044FA00_InternalClear(int bWarn);
};

// 0x0044DD90
D2StormLinkStrc* D2StormLinkStrc::sub_0044DD90_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0044DE10
D2StormListAStrc* D2StormListArrayStrc::sub_0044DE10_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x0044DE60
D2StormLinkStrc* D2StormLinkStrc::sub_0044DE60_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0044DF30
unsigned int D2StormListArrayStrc::sub_0044DF30_CalcChunkSize(unsigned int nCount)
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

// 0x0044DF70
unsigned int __stdcall sub_0044DF70_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0044DF90
void D2StormListAStrc::sub_0044DF90_CopyLinkOffset(const D2StormListAStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x0044ED20
D2StormLinkStrc* D2StormListAStrc::sub_0044ED20_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x0044EDA0
D2StormLinkStrc* D2StormListBStrc::sub_0044EDA0_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x0044EDC0
void D2StormListAStrc::sub_0044EDC0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0044EE10
void D2StormListAStrc::sub_0044EE10_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0044EE30
void D2StormListBStrc::sub_0044EE30_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0044EE90
D2StormListAStrc::D2StormListAStrc(const D2StormListAStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0044F890
void D2StormListBStrc::sub_0044F890_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0044F980
void D2StormListAStrc::sub_0044F980_ChangeLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x0044FA00
void D2StormHashTableStrc::sub_0044FA00_InternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.f_4; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.f_8[i].Head()) != 0)
        {
            if (bWarn)
                m_slotlistarray.f_8[i].Link(pNode)->Unlink();
            else
                InternalDelete(pNode);
        }
    }
}

// 0x0044FB80
D2StormListBStrc::D2StormListBStrc(const D2StormListBStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}
