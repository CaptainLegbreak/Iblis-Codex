// build: context ??_GD2CelEntryStrc@@QAEPAXI@Z

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern "C" const char gszTypeNameCelEntry[];                                                                // 0x00741F14

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;
};

struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormNodeStrc* Head()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormNodeStrc*)m_terminator.m_next : 0;
    }
    void UnlinkAll();
    void sub_00602BF0_DeleteAll();
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();
};

struct D2StormEntry38Strc;

struct D2GameHashTableStrc
{
    char unk0x04[0x24];

    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    D2StormEntry38Strc* sub_006030E0_InternalFind(unsigned int nHashVal, const int& tKey);                 // 0x006030E0
};

struct D2GameDataTableStrc : D2GameHashTableStrc
{
    char unk0x28[0x1C];
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    unsigned int sub_00603280_GenerateHandle();
};

// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
void D2StormNodeListStrc::UnlinkAll()
{
    D2StormNodeStrc* pNode;
    while ((pNode = Head()) != 0)
        pNode->f_0.Unlink();
}

// build: symbol ?UnlinkAll@D2StormSlotListStrc@@QAEXXZ 0x00602640
void D2StormSlotListStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// build: symbol ?UnlinkAll@D2StormListEStrc@@QAEXXZ 0x00602690
void D2StormListEStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// 0x00602BF0
void D2StormNodeListStrc::sub_00602BF0_DeleteAll()
{
    char* pNode;
    while ((pNode = m_terminator.Next()) != 0)
    {
        ((D2CelEntryStrc*)pNode)->~D2CelEntryStrc();
        SMemFree(pNode, gszTypeNameCelEntry, -2, 0);
    }
}

// 0x00603280
unsigned int D2GameDataTableStrc::sub_00603280_GenerateHandle()
{
    for (;;)
    {
        ++m_sequence;
        if (!m_sequence)
        {
            m_wrapped = 1;
            continue;
        }

        if (!m_wrapped || !sub_006030E0_InternalFind(m_sequence, f_44))
        {
            break;
        }
    }

    return m_sequence;
}
