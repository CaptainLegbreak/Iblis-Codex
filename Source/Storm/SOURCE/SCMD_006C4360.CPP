// build: ob1

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    int m_next;

    D2StormLinkStrc() { m_prevlink = 0; m_next = 0; }
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListStrc();
};

// 0x006C4360
D2StormListStrc::D2StormListStrc()
{
    D2StormLinkStrc* pLink = &m_terminator;
    pLink->m_prevlink = pLink;
    m_linkoffset = 0;
    m_terminator.m_next = ~(unsigned int)pLink;
}
