int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern "C" const char gszTypeNameStringEntryList_0074366C[];                                                // 0x0074366C
extern "C" const char gszTypeNameMappingEntryList_007436AC[];                                               // 0x007436AC

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
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
};

struct D2CommonStormNodeStrc;

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListAStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
// build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
    void UnlinkAll();
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayAStrc();
    D2CommonStormSlotListAStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
    void sub_0060F9D0_SetCount(unsigned int nCount);                                                        // 0x0060F9D0
    void sub_00610090_SetCountForward(unsigned int nCount);
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayBStrc();
    D2CommonStormSlotListBStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
    void sub_006100B0_SetCount(unsigned int nCount);                                                        // 0x006100B0
    void sub_00610830_SetCountForward(unsigned int nCount);
};

struct D2CommonStormHashTableAStrc
{
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x0060FFA0
    virtual D2CommonStormNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~D2CommonStormHashTableAStrc();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020

    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0060EB70_InternalClear(int bWarn);
};

struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x00610690
    virtual D2CommonStormNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~D2CommonStormHashTableBStrc();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0

    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0060EE60_InternalClear(int bWarn);
};

// 0x0060EB70
void D2CommonStormHashTableAStrc::sub_0060EB70_InternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.f_4; i++)
    {
        while (char* pNode = m_slotlistarray[i].Head())
        {
            if (bWarn)
                m_slotlistarray[i].sub_006C4290(pNode);
            else
                sub_0060FFA0_InternalDelete((D2CommonStormNodeStrc*)pNode);
        }
    }
}

// 0x0060EE60
void D2CommonStormHashTableBStrc::sub_0060EE60_InternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.f_4; i++)
    {
        while (char* pNode = m_slotlistarray[i].Head())
        {
            if (bWarn)
                m_slotlistarray[i].sub_006C4290(pNode);
            else
                sub_00610690_InternalDelete((D2CommonStormNodeStrc*)pNode);
        }
    }
}

// 0x0060F610
D2CommonStormSlotArrayAStrc::~D2CommonStormSlotArrayAStrc()
{
    for (unsigned int i = 0; i < f_4; i++)
        f_8[i].~D2CommonStormSlotListAStrc();
    if (f_8)
        SMemFree(f_8, gszTypeNameStringEntryList_0074366C, -2, 0);
}

// 0x0060F950
D2CommonStormSlotArrayBStrc::~D2CommonStormSlotArrayBStrc()
{
    for (unsigned int i = 0; i < f_4; i++)
        f_8[i].~D2CommonStormSlotListBStrc();
    if (f_8)
        SMemFree(f_8, gszTypeNameMappingEntryList_007436AC, -2, 0);
}

// 0x00610090
void D2CommonStormSlotArrayAStrc::sub_00610090_SetCountForward(unsigned int nCount)
{
    sub_0060F9D0_SetCount(nCount);
}

// 0x00610830
void D2CommonStormSlotArrayBStrc::sub_00610830_SetCountForward(unsigned int nCount)
{
    sub_006100B0_SetCount(nCount);
}
