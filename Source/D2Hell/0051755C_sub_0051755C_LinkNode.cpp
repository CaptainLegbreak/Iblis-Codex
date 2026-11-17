struct D2Node0051755CStrc;

struct D2Link0051755CStrc
{
    D2Link0051755CStrc* m_prevlink;
    D2Node0051755CStrc* m_next;

    D2Link0051755CStrc* sub_005174C0_NextLink(int nLinkOffset); // 0x005174C0
    void sub_005174E2_Unlink(); // 0x005174E2
};

struct D2List0051755CStrc
{
    int m_linkoffset;
    D2Link0051755CStrc m_terminator;

    D2Link0051755CStrc* sub_0051752F_Link(D2Node0051755CStrc* pNode); // 0x0051752F
    void sub_0051755C_LinkNode(D2Node0051755CStrc* pNode, int nLinkType, D2Node0051755CStrc* pExisting);
};

// 0x0051755C
void D2List0051755CStrc::sub_0051755C_LinkNode(D2Node0051755CStrc* pNode, int nLinkType, D2Node0051755CStrc* pExisting)
{
    D2Link0051755CStrc* pLink = sub_0051752F_Link(pNode);
    if (pLink->m_prevlink)
    {
        pLink->sub_005174E2_Unlink();
    }

    D2Link0051755CStrc* pExistingLink = pExisting ? sub_0051752F_Link(pExisting) : &m_terminator;

    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->sub_005174C0_NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
    {
        D2Link0051755CStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
    }
        break;
    }
}
