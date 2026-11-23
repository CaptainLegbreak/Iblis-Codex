struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* sub_0045B9D0_Next();
    char* sub_0045B9E0_RawNext();
    void sub_0045B9F0_Unlink();
    void sub_0045BA30_Unlink();
    char* sub_0045BAA0_Next();
    void sub_0045BAD0_Unlink();
    void sub_0045BCC0_Unlink();
    void sub_0045BD90_Unlink();
};

struct D2StormTermLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormTermLinkStrc() : m_prevlink(0), m_next(0) {}
};

struct D2StormLink0045BAC0Strc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLink0045BAC0Strc();
};

struct D2StormLink0045BCB0Strc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLink0045BCB0Strc();
};

struct D2StormLink0045BD80Strc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLink0045BD80Strc();
};

struct D2StormListBaseStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0045BA80_InitializeTerminator();
    char* sub_0045BAB0_Head();
    void sub_0045BB10_Initialize();
};

struct D2StormList0045BBC0Strc
{
    int m_linkoffset;
    D2StormTermLinkStrc m_terminator;

    D2StormList0045BBC0Strc();
};

struct D2StormExplicitListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void UnlinkAll();                                                                                       // 0x0045BD00
    ~D2StormExplicitListStrc();
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



// 0x0045B9D0
char* D2StormLinkStrc::sub_0045B9D0_Next()
{
    return (int)m_next <= 0 ? 0 : m_next;
}

// 0x0045B9E0
char* D2StormLinkStrc::sub_0045B9E0_RawNext()
{
    return m_next;
}

// 0x0045B9F0
void D2StormLinkStrc::sub_0045B9F0_Unlink()
{
    STORM_LinkUnlink(this);
}

// 0x0045BA30
void D2StormLinkStrc::sub_0045BA30_Unlink()
{
    STORM_LinkUnlink(this);
}

// 0x0045BA80
void D2StormListBaseStrc::sub_0045BA80_InitializeTerminator()
{
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0045BAA0
char* D2StormLinkStrc::sub_0045BAA0_Next()
{
    return (int)m_next <= 0 ? 0 : m_next;
}

// 0x0045BAB0
char* D2StormListBaseStrc::sub_0045BAB0_Head()
{
    return (int)m_terminator.m_next <= 0 ? 0 : m_terminator.m_next;
}

// 0x0045BAC0
D2StormLink0045BAC0Strc::D2StormLink0045BAC0Strc() : m_prevlink(0), m_next(0)
{
}

// 0x0045BAD0
void D2StormLinkStrc::sub_0045BAD0_Unlink()
{
    STORM_LinkUnlink(this);
}

// 0x0045BB10
void D2StormListBaseStrc::sub_0045BB10_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0045BBC0
D2StormList0045BBC0Strc::D2StormList0045BBC0Strc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = (D2StormLinkStrc*)&m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0045BCB0
D2StormLink0045BCB0Strc::D2StormLink0045BCB0Strc() : m_prevlink(0), m_next(0)
{
}

// 0x0045BCC0
void D2StormLinkStrc::sub_0045BCC0_Unlink()
{
    STORM_LinkUnlink(this);
}

// 0x0045BD40
D2StormExplicitListStrc::~D2StormExplicitListStrc()
{
    UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x0045BD80
D2StormLink0045BD80Strc::D2StormLink0045BD80Strc() : m_prevlink(0), m_next(0)
{
}

// 0x0045BD90
void D2StormLinkStrc::sub_0045BD90_Unlink()
{
    STORM_LinkUnlink(this);
}
