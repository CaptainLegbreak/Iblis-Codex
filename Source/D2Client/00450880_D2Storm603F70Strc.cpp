struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00602D20_DeleteAll();
    void sub_00603B60_DeleteAll();
};

struct D2StormSlotListStrc;
struct D2StormEntry38Strc;

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2StormSlotArrayStrc();
    void sub_00603760_Clear();
};

struct D2StormEntryArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry38Strc* f_8;
    unsigned int f_C;

    ~D2StormEntryArrayStrc();
};

struct D2StormSlotGrowArrayStrc
{
    D2StormSlotArrayStrc tArray;

    ~D2StormSlotGrowArrayStrc();
};

struct D2StormEntryGrowArrayStrc
{
    D2StormEntryArrayStrc tArray;

    ~D2StormEntryGrowArrayStrc();
};

struct D2StormHashChunkStrc
{
    D2StormEntryArrayStrc tArray;
    D2StormSlotLinkStrc f_10;

    ~D2StormHashChunkStrc();
};

struct D2Storm603530ArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;
};

struct D2Storm603530Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603530Strc();
};

struct D2Storm603570ArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    D2Storm603570ArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2Storm603570LinkStrc
{
    D2Storm603570LinkStrc* m_prevlink;
    char* m_next;

    D2Storm603570LinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2Storm603570ListStrc
{
    int m_linkoffset;
    D2Storm603570LinkStrc m_terminator;

    D2Storm603570ListStrc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2Storm603570Strc
{
    unsigned int unk0x00;
    D2Storm603570ArrayStrc tArray;
    char unk0x14[0x18];
    D2Storm603570ListStrc tList;

    D2Storm603570Strc();
};

struct D2GameHashTableReuseStrc
{
    char unk0x00[0x28];
    D2StormListEStrc m_reuseList;
    int unk0x34;
    D2StormListEStrc m_chunkList;

    void sub_00603E50_DeleteLists();
};

struct D2Storm603ED0Strc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00603ED0_GetDifference();
};

struct D2Storm603F70Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603F70Strc(int nUnused);
};

D2StormSlotGrowArrayStrc::~D2StormSlotGrowArrayStrc()
{
}

D2StormEntryGrowArrayStrc::~D2StormEntryGrowArrayStrc()
{
}

D2StormHashChunkStrc::~D2StormHashChunkStrc()
{
    f_10.Unlink();
}

void __fastcall sub_00603500_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

D2Storm603530Strc::D2Storm603530Strc()
{
    tArray.f_0 = 0;
    tArray.f_4 = 0;
    tArray.f_8 = 0;
    tArray.f_C = 0;
}

D2Storm603570Strc::D2Storm603570Strc()
{
}

void D2StormSlotArrayStrc::sub_00603760_Clear()
{
    this->D2StormSlotArrayStrc::~D2StormSlotArrayStrc();
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

void D2GameHashTableReuseStrc::sub_00603E50_DeleteLists()
{
    m_chunkList.sub_00603B60_DeleteAll();
    m_reuseList.sub_00602D20_DeleteAll();
}

unsigned int D2Storm603ED0Strc::sub_00603ED0_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00450880
D2Storm603F70Strc::D2Storm603F70Strc(int nUnused)
{
    tArray.f_0 = 0;
    tArray.f_4 = 0;
    tArray.f_8 = 0;
    tArray.f_C = 0;
}
