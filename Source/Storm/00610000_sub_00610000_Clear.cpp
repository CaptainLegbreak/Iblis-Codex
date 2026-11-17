struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonStormNodeStrc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};
struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};
struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};
struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;
    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
    void sub_00610000_Clear();
};
struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;
    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
    void Clear()
    {
        this->~D2CommonStormSlotArrayBStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};
struct D2CommonStormHashTableAStrc
{
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x0060FFA0
    virtual D2CommonStormNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~D2CommonStormHashTableAStrc();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();
    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;
    void sub_0060EB70_InternalClear(int bWarn);                                                             // 0x0060EB70
};
struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x00610690
    virtual D2CommonStormNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~D2CommonStormHashTableBStrc();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();
    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;
    void sub_0060EE60_InternalClear(int bWarn);                                                             // 0x0060EE60
};

// 0x00610000
void D2CommonStormSlotArrayAStrc::sub_00610000_Clear()
{
    this->~D2CommonStormSlotArrayAStrc();
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

// 0x00610020
void D2CommonStormHashTableAStrc::sub_00610020_VirtSlot3()
{
    sub_0060EB70_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.sub_00610000_Clear();
}

// 0x006107D0
void D2CommonStormHashTableBStrc::sub_006107D0_VirtSlot3()
{
    sub_0060EE60_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}
