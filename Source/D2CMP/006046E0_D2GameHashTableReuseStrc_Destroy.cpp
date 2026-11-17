struct D2StormEntry38Strc;
struct D2StormSlotListStrc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00602D20_DeleteAll();                                                                          // 0x00602D20
    void sub_00603B60_DeleteAll();                                                                          // 0x00603B60
};

struct D2GameHashTableStrc
{
    int unk0x04[3];
    unsigned int m_fullnessIndicator;
    int unk0x14[4];
    unsigned int m_slotmask;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();
    void sub_00602800_InternalClear(int bWarn);                                                             // 0x00602800
};

struct D2GameHashTableReuseStrc : D2GameHashTableStrc
{
    D2StormListEStrc m_reuseList;
    int unk0x34;
    D2StormListEStrc m_chunkList;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2GameHashTableReuseStrc();                                                                    // 0x00604640
    virtual void Destroy();
};

// build: symbol ?Destroy@D2GameHashTableReuseStrc@@UAEXXZ 0x006046E0
void D2GameHashTableReuseStrc::Destroy()
{
    sub_00602800_InternalClear(0);
    m_chunkList.sub_00603B60_DeleteAll();
    m_reuseList.sub_00602D20_DeleteAll();
}
