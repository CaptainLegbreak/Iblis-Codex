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

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_00417A10_Link(char* pNode);
    D2StormLinkStrc* sub_00417A50_Link(char* pNode);
    D2StormLinkStrc* sub_00417B60_Link(char* pNode);
    D2StormLinkStrc* sub_00417C50_Link(char* pNode);
    D2StormLinkStrc* sub_00417D60_Link(char* pNode);
    D2StormLinkStrc* sub_0041C560_Link(char* pNode);
    void sub_00417A70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    void sub_00417B80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    void sub_00417C70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    void sub_00417D80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    void sub_004184B0_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    void sub_0041C580_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    char* sub_00417B20_Next(char* pNode);
    char* sub_00417D20_Next(char* pNode);
    char* sub_00417E30_Next(char* pNode);
    char* sub_0041C630_Next(char* pNode);
    void sub_00417E90_UnlinkNode(char* pNode);
    void sub_00418560_UnlinkNode(char* pNode);
    void sub_004185F0_UnlinkNode(char* pNode);
    void sub_00418660_UnlinkNode(char* pNode);
    void sub_00418710_UnlinkNode(char* pNode);
    void sub_0041C690_UnlinkNode(char* pNode);
    char* sub_004185D0_RawNext(char* pNode);
    char* sub_004186D0_RawNext(char* pNode);
    char* sub_004186F0_RawNext(char* pNode);
    char* sub_0041C700_RawNext(char* pNode);
};

// 0x00416770
D2StormLinkStrc* D2StormLinkStrc::sub_00416770_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004168C0
D2StormLinkStrc* D2StormLinkStrc::sub_004168C0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00416930
D2StormLinkStrc* D2StormLinkStrc::sub_00416930_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00416970
D2StormLinkStrc* D2StormLinkStrc::sub_00416970_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x004169B0
D2StormLinkStrc* D2StormLinkStrc::sub_004169B0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00417A10
D2StormLinkStrc* D2StormFixedListStrc::sub_00417A10_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417A50
D2StormLinkStrc* D2StormFixedListStrc::sub_00417A50_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417A70
void D2StormFixedListStrc::sub_00417A70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417B20
char* D2StormFixedListStrc::sub_00417B20_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417B60
D2StormLinkStrc* D2StormFixedListStrc::sub_00417B60_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417B80
void D2StormFixedListStrc::sub_00417B80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417C50
D2StormLinkStrc* D2StormFixedListStrc::sub_00417C50_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417C70
void D2StormFixedListStrc::sub_00417C70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417D20
char* D2StormFixedListStrc::sub_00417D20_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417D60
D2StormLinkStrc* D2StormFixedListStrc::sub_00417D60_Link(char* pNode)
{
    return Link(pNode);
}

// 0x00417D80
void D2StormFixedListStrc::sub_00417D80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00417E30
char* D2StormFixedListStrc::sub_00417E30_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00417E90
void D2StormFixedListStrc::sub_00417E90_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004184B0
void D2StormFixedListStrc::sub_004184B0_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x00418560
void D2StormFixedListStrc::sub_00418560_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004185D0
char* D2StormFixedListStrc::sub_004185D0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x004185F0
void D2StormFixedListStrc::sub_004185F0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00418660
void D2StormFixedListStrc::sub_00418660_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004186D0
char* D2StormFixedListStrc::sub_004186D0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x004186F0
char* D2StormFixedListStrc::sub_004186F0_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x00418710
void D2StormFixedListStrc::sub_00418710_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0041C3A0
D2StormLinkStrc* D2StormLinkStrc::sub_0041C3A0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0041C560
D2StormLinkStrc* D2StormFixedListStrc::sub_0041C560_Link(char* pNode)
{
    return Link(pNode);
}

// 0x0041C580
void D2StormFixedListStrc::sub_0041C580_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
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

// 0x0041C630
char* D2StormFixedListStrc::sub_0041C630_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x0041C690
void D2StormFixedListStrc::sub_0041C690_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0041C700
char* D2StormFixedListStrc::sub_0041C700_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}
