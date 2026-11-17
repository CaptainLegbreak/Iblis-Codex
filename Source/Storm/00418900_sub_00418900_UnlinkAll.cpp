struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormListBaseStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

static D2StormLinkStrc* STORM_LinkNextLink(D2StormLinkStrc* pLink, int nLinkOffset)
{
    if ((int)pLink->m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)pLink->m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)pLink - pLink->m_prevlink->m_next;
    return (D2StormLinkStrc*)(pLink->m_next + nLinkOffset);
}

static char* STORM_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

static void STORM_LinkUnlink(D2StormLinkStrc* pLink)
{
    if (pLink->m_prevlink)
    {
        STORM_LinkNextLink(pLink, -1)->m_prevlink = pLink->m_prevlink;
        pLink->m_prevlink->m_next = pLink->m_next;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
    }
}

struct D2StormList00708354Strc : D2StormListBaseStrc { void sub_00418900_UnlinkAll(); };
struct D2StormList00708360Strc : D2StormListBaseStrc { void sub_00418940_UnlinkAll(); };
struct D2StormList0070836CStrc : D2StormListBaseStrc { void sub_00418980_UnlinkAll(); };
struct D2StormList00708378Strc : D2StormListBaseStrc { void sub_004189C0_UnlinkAll(); };
struct D2StormList00708384Strc : D2StormListBaseStrc { void sub_00418A00_UnlinkAll(); };

// 0x00418900
void D2StormList00708354Strc::sub_00418900_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x00418940
void D2StormList00708360Strc::sub_00418940_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x00418980
void D2StormList0070836CStrc::sub_00418980_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x004189C0
void D2StormList00708378Strc::sub_004189C0_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x00418A00
void D2StormList00708384Strc::sub_00418A00_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}
