struct D2CommonStormPlainLinkStrc
{
    D2CommonStormPlainLinkStrc* m_prevlink;
    char* m_next;
};

struct D2CommonStormListGStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

// build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
    void UnlinkAll();
};

struct D2CommonStormHashTableBStrc
{
    void sub_0060EE60_InternalClear(int bWarn);                                                             // 0x0060EE60
    void sub_0060F150_Clear();
};

struct D2CommonStormSlotListCStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

    ~D2CommonStormSlotListCStrc();
};

struct D2CommonStormSlotListDStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

    ~D2CommonStormSlotListDStrc();
};

struct D2CommonStormSlotListEStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

    ~D2CommonStormSlotListEStrc();
};

struct D2CommonStormZeroAStrc
{
    int m_value;

    D2CommonStormZeroAStrc();
};

struct D2CommonStormZeroBStrc
{
    int m_value;

    D2CommonStormZeroBStrc();
};

#define D2_STORM_UNLINK_TERMINATOR(pThis)                                                                   \
    if ((pThis)->m_prevlink)                                                                                \
    {                                                                                                       \
        D2CommonStormPlainLinkStrc* pNext;                                                                  \
        if ((int)(pThis)->m_next < 0)                                                                       \
        {                                                                                                   \
            pNext = (D2CommonStormPlainLinkStrc*)~(unsigned int)(pThis)->m_next;                           \
        }                                                                                                   \
        else                                                                                                \
        {                                                                                                   \
            int nLinkOffset = -1;                                                                           \
            if (nLinkOffset < 0)                                                                            \
            {                                                                                               \
                nLinkOffset = (char*)(pThis) - (pThis)->m_prevlink->m_next;                                 \
            }                                                                                               \
            pNext = (D2CommonStormPlainLinkStrc*)((pThis)->m_next + nLinkOffset);                          \
        }                                                                                                   \
        pNext->m_prevlink = (pThis)->m_prevlink;                                                            \
        (pThis)->m_prevlink->m_next = (pThis)->m_next;                                                      \
        (pThis)->m_prevlink = 0;                                                                            \
        (pThis)->m_next = 0;                                                                                \
    }

// 0x0060F050
void __fastcall sub_0060F050_ConstructList(D2CommonStormListGStrc* pList, const D2CommonStormListGStrc* pSource)
{
    if (pList)
    {
        D2CommonStormPlainLinkStrc* pLink = &pList->m_terminator;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
        pList->m_linkoffset = pSource->m_linkoffset;
        pList->m_terminator.m_prevlink = &pList->m_terminator;
        pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
    }
}

// 0x0060F150
void D2CommonStormHashTableBStrc::sub_0060F150_Clear()
{
    sub_0060EE60_InternalClear(0);
}

// 0x0060F190
D2CommonStormSlotListCStrc::~D2CommonStormSlotListCStrc()
{
    ((D2CommonStormSlotListBStrc*)this)->UnlinkAll();
    D2CommonStormPlainLinkStrc* pThis = &m_terminator;
    D2_STORM_UNLINK_TERMINATOR(pThis)
}

// 0x0060F2C0
D2CommonStormSlotListDStrc::~D2CommonStormSlotListDStrc()
{
    ((D2CommonStormSlotListAStrc*)this)->UnlinkAll();
    D2CommonStormPlainLinkStrc* pThis = &m_terminator;
    D2_STORM_UNLINK_TERMINATOR(pThis)
}

// 0x0060F4E0
void __fastcall sub_0060F4E0_ConstructList(D2CommonStormListGStrc* pList, const D2CommonStormListGStrc* pSource)
{
    if (pList)
    {
        D2CommonStormPlainLinkStrc* pLink = &pList->m_terminator;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
        pList->m_linkoffset = pSource->m_linkoffset;
        pList->m_terminator.m_prevlink = &pList->m_terminator;
        pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
    }
}

// 0x0060F690
D2CommonStormSlotListEStrc::~D2CommonStormSlotListEStrc()
{
    ((D2CommonStormSlotListBStrc*)this)->UnlinkAll();
    D2CommonStormPlainLinkStrc* pThis = &m_terminator;
    D2_STORM_UNLINK_TERMINATOR(pThis)
}

// 0x0060FE30
D2CommonStormZeroAStrc::D2CommonStormZeroAStrc()
{
    m_value = 0;
}

// 0x0060FE40
D2CommonStormZeroBStrc::D2CommonStormZeroBStrc()
{
    m_value = 0;
}
