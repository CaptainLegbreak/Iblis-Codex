struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormLinkStrc()
    {
        Unlink();
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
};

struct D2StormTSListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormTSListStrc();
    void sub_00426CF0_UnlinkAll();                                                                          // 0x00426CF0
};

// 0x00426160
unsigned int __fastcall sub_00426160_GetTableSize(unsigned int nCount)
{
    unsigned int nSize = 1;
    const unsigned int nLimit = 2 * nCount + 2;
    while (nSize <= nLimit)
        nSize += nSize;
    return nSize;
}

// 0x00426D30
D2StormTSListStrc::~D2StormTSListStrc()
{
    sub_00426CF0_UnlinkAll();
}
