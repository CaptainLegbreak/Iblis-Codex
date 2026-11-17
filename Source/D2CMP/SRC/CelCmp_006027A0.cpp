struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

static D2StormLinkStrc* STORM_LinkNextLink(D2StormLinkStrc* pLink, int nLinkOffset)
{
    if ((int)pLink->m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)pLink->m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)pLink - pLink->m_prevlink->m_next;
    return (D2StormLinkStrc*)(pLink->m_next + nLinkOffset);
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

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
    void UnlinkAll();
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

// build: symbol ?UnlinkAll@D2StormSlotListStrc@@QAEXXZ 0x00602640
    void UnlinkAll();
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

// build: symbol ?UnlinkAll@D2StormListEStrc@@QAEXXZ 0x00602690
    void UnlinkAll();
};

struct D2StormNodeList006027A0Strc : D2StormNodeListStrc { ~D2StormNodeList006027A0Strc(); };
struct D2StormSlotList00602890Strc : D2StormSlotListStrc { ~D2StormSlotList00602890Strc(); };
struct D2StormListE006028D0Strc : D2StormListEStrc { ~D2StormListE006028D0Strc(); };
struct D2StormSlotList00602AA0Strc : D2StormSlotListStrc { ~D2StormSlotList00602AA0Strc(); };
struct D2StormListE00602AE0Strc : D2StormListEStrc { ~D2StormListE00602AE0Strc(); };
struct D2StormSlotList00602DF0Strc : D2StormSlotListStrc { ~D2StormSlotList00602DF0Strc(); };

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    int f_14;

    ~D2StormHashObjectStrc();                                                                               // 0x00602430
};

struct D2StormEntry00602B20Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeList006027A0Strc tList;

    ~D2StormEntry00602B20Strc();
};

struct D2StormEntry00602EC0Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeList006027A0Strc tList;

    ~D2StormEntry00602EC0Strc();
};

// 0x006027A0
D2StormNodeList006027A0Strc::~D2StormNodeList006027A0Strc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00602890
D2StormSlotList00602890Strc::~D2StormSlotList00602890Strc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x006028D0
D2StormListE006028D0Strc::~D2StormListE006028D0Strc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00602AA0
D2StormSlotList00602AA0Strc::~D2StormSlotList00602AA0Strc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00602AE0
D2StormListE00602AE0Strc::~D2StormListE00602AE0Strc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00602B20
D2StormEntry00602B20Strc::~D2StormEntry00602B20Strc()
{
}

// 0x00602DF0
D2StormSlotList00602DF0Strc::~D2StormSlotList00602DF0Strc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00602EC0
D2StormEntry00602EC0Strc::~D2StormEntry00602EC0Strc()
{
}
