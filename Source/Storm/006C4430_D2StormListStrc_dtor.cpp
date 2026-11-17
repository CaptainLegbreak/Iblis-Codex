struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
        {
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (char*)this - m_prevlink->m_next;
        }
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

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void UnlinkAll();                   // 0x006C43F0
    ~D2StormListStrc();
};

// 0x006C4430
D2StormListStrc::~D2StormListStrc()
{
    UnlinkAll();
    m_terminator.Unlink();
}
