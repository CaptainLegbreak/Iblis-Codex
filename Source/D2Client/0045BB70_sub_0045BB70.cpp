struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

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

struct D2StormListStrc {
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_0045BB70(D2StormLinkStrc* link);
};
// 0x0045BB70
void D2StormListStrc::sub_0045BB70(D2StormLinkStrc* link)
{
    if(!link) link=&m_terminator;
    link->Unlink();
}
