struct D2CelListStrc;

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

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    __forceinline ~D2StormSlotListStrc()
    {
        sub_00602640_UnlinkAll();
    }
    void sub_00602640_UnlinkAll();                                                                          // 0x00602640
    void sub_00602D20_DeleteAll();                                                                          // 0x00602D20
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    __forceinline ~D2StormListEStrc()
    {
        sub_00602690_UnlinkAll();
    }
    void sub_00602690_UnlinkAll();                                                                          // 0x00602690
    void sub_00603B60_DeleteAll();                                                                          // 0x00603B60
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2StormListFixedArrayStrc();
    void Clear()
    {
        this->~D2StormListFixedArrayStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};

extern "C" const int gTSHashTableReuseCelListVtable_006E5DFC[];                                           // 0x006E5DFC

struct D2GameHashTableStrc
{
    const int* f_0;
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListFixedArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    ~D2GameHashTableStrc();                                                                                // 0x00603460
};

struct D2GameHashTableReuseStrc : D2GameHashTableStrc
{
    D2StormSlotListStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormListEStrc m_chunkList;
};

// 0x00604640
void __fastcall sub_00604640_DestroyReuseTable(D2GameHashTableReuseStrc* pTable)
{
    pTable->f_0 = gTSHashTableReuseCelListVtable_006E5DFC;
    pTable->m_chunkList.sub_00603B60_DeleteAll();
    pTable->m_reuseList.sub_00602D20_DeleteAll();
    pTable->m_chunkList.~D2StormListEStrc();
    pTable->m_reuseList.~D2StormSlotListStrc();
    pTable->D2GameHashTableStrc::~D2GameHashTableStrc();
}
