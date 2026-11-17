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

int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650
extern char gszTypeNameHandler_00708434[];                                                                  // 0x00708434

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

struct D2StormList00708420Strc : D2StormListBaseStrc
{
    void sub_0041C770_UnlinkAll();
    void sub_0041C9C0_DeleteAll();
};

// 0x0041C770
void D2StormList00708420Strc::sub_0041C770_UnlinkAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
}

// 0x0041C9C0
void D2StormList00708420Strc::sub_0041C9C0_DeleteAll()
{
    while (char* pNode = STORM_LinkNext(&m_terminator))
    {
        STORM_LinkUnlink((D2StormLinkStrc*)pNode);
        SMemFree(pNode, gszTypeNameHandler_00708434, -2, 0);
    }
}
