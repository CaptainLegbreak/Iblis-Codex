struct D2StormEntry38Strc;

struct D2StormSlotListStrc
{
    int m_linkoffset;
    void* m_terminator[2];
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2StormSlotArrayStrc();                                                                                // 0x00603060
    void Clear()
    {
        this->~D2StormSlotArrayStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};

struct D2GameHashTableStrc
{
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00602800_InternalClear(int bWarn);                                                             // 0x00602800
};

// 0x00603780
void D2GameHashTableStrc::Destroy()
{
    sub_00602800_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}
