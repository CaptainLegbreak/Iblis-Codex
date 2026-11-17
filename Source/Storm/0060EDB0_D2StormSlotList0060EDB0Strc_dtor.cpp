struct D2StormSlotLink0060EDB0Strc
{
    D2StormSlotLink0060EDB0Strc* m_prevlink;
    char* m_next;

    ~D2StormSlotLink0060EDB0Strc()
    {
        Unlink();
    }
    D2StormSlotLink0060EDB0Strc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLink0060EDB0Strc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLink0060EDB0Strc*)(m_next + nLinkOffset);
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

struct D2StormSlotList0060EDB0Strc
{
    int m_linkoffset;
    D2StormSlotLink0060EDB0Strc m_terminator;

    ~D2StormSlotList0060EDB0Strc();
    void UnlinkAll();                                                                                       // 0x0060E820
};

// 0x0060EDB0
D2StormSlotList0060EDB0Strc::~D2StormSlotList0060EDB0Strc()
{
    UnlinkAll();
}
