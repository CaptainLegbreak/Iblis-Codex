struct D2StormEntry38Strc;

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormSlotLinkStrc m_terminator;

    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
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
    void sub_00603850_SetCount(unsigned int nCount);
};

struct D2GameHashTableStrc
{
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();                                                                                 // 0x00603780
    void sub_00602800_InternalClear(int bWarn);
};

// 0x00602800
void D2GameHashTableStrc::sub_00602800_InternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.f_4; ++i)
    {
        for (;;)
        {
            char* pNode = m_slotlistarray.f_8[i].Head();
            if (!pNode)
                break;
            if (bWarn)
                m_slotlistarray.f_8[i].sub_006C4290(pNode);
            else
                InternalDelete((D2StormEntry38Strc*)pNode);
        }
    }
}

// 0x00603850
void D2StormSlotArrayStrc::sub_00603850_SetCount(unsigned int nCount)
{
    sub_00603300_SetCount(nCount);
}
