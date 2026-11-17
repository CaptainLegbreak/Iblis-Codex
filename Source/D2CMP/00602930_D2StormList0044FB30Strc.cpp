inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormLinkStrc()
    {
        Unlink();
    }
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

struct D2StormChunkLinkStrc
{
    D2StormChunkLinkStrc* m_prevlink;
    char* m_next;

    D2StormChunkLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormChunkLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormChunkLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormCtorLinkStrc
{
    D2StormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2StormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    ~D2SGameDataStrc();
};

struct D2StormGameArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;

    ~D2StormGameArrayStrc();
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc();
    void UnlinkAll();
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormChunkListStrc();
    void UnlinkAll();
};

struct sub_0044F9F0
{
    D2SGameDataStrc tData;

    ~sub_0044F9F0();
};

struct D2StormList0044FB30Strc
{
    int m_linkoffset;
    D2StormCtorLinkStrc m_terminator;

    D2StormList0044FB30Strc();
};

struct D2StormDeadListStrc
{
    int m_linkoffset;
    D2StormCtorLinkStrc m_terminator;

    D2StormDeadListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormDeadListStrc(const D2StormDeadListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct sub_0044FBE0 : D2StormListAStrc
{
    ~sub_0044FBE0();
};

struct sub_0044FC20 : D2StormChunkListStrc
{
    ~sub_0044FC20();
};

struct sub_0044FDD0 : D2StormListAStrc
{
    ~sub_0044FDD0();
};

struct D2StormGameGrowArrayStrc
{
    D2StormGameArrayStrc tArray;

    ~D2StormGameGrowArrayStrc();
};

struct D2StormGameHashChunkStrc
{
    D2StormGameArrayStrc tArray;
    D2StormChunkLinkStrc f_10;

    ~D2StormGameHashChunkStrc();
};

sub_0044F9F0::~sub_0044F9F0()
{
}

D2StormListAStrc::~D2StormListAStrc()
{
    UnlinkAll();
}

D2StormChunkListStrc::~D2StormChunkListStrc()
{
    UnlinkAll();
}

// 0x00602930
D2StormList0044FB30Strc::D2StormList0044FB30Strc()
{
    m_linkoffset = 0x10;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

void __fastcall sub_0044FB50_ConstructDeadList(D2StormDeadListStrc* pList)
{
    new (pList) D2StormDeadListStrc;
}

sub_0044FBE0::~sub_0044FBE0()
{
}

sub_0044FC20::~sub_0044FC20()
{
}

void __fastcall sub_0044FD60_CopyConstructDeadList(D2StormDeadListStrc* pList, const D2StormDeadListStrc* pSource)
{
    new (pList) D2StormDeadListStrc(*pSource);
}

sub_0044FDD0::~sub_0044FDD0()
{
}

D2StormGameGrowArrayStrc::~D2StormGameGrowArrayStrc()
{
}

D2StormGameHashChunkStrc::~D2StormGameHashChunkStrc()
{
    f_10.Unlink();
}
