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
    D2StormLinkStrc* sub_00416770_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_004168C0_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00416930_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00416970_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_004169B0_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0041C3A0_NextLink(int nLinkOffset);
};

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    D2StormLinkStrc* Link(char* pNode) { return pNode ? (D2StormLinkStrc*)pNode : &m_terminator; }
    void sub_006C4180_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
};

// 0x006C4180
void D2StormFixedListStrc::sub_006C4180_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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
