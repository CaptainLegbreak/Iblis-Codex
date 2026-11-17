inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_00450580_DeleteAll();                                                                          // 0x00450580
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    ~D2StormListFixedArrayStrc();                                                                           // 0x0044FF60
    void sub_00450500_Clear();
};

struct D2StormSlotListArrayStrc
{
    D2StormListFixedArrayStrc m_array;
    ~D2StormSlotListArrayStrc();
};

struct D2SGameDataStrc;

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableStrc();
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;
};

struct D2StormHashTableReuseStrc : D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableReuseStrc();
    virtual void Destroy();
    D2StormListAStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormChunkListStrc m_chunkList;
    void sub_00450690_DeleteChunksAndReuse();
};

typedef char chkReuseChunk_M125[(int)&((D2StormHashTableReuseStrc*)0)->m_chunkList == 0x38 ? 1 : -1];

struct D2SGameDataStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    char unk0x14[0x1DF4 - 0x14];

    D2SGameDataStrc()
    {
        unk0x04 = 0;
        unk0x08 = 0;
        unk0x0C = 0;
        unk0x10 = 0;
    }
    D2SGameDataStrc(const D2SGameDataStrc& tSource);                                                        // 0x00450950
};

typedef char chkSGameData_M125[sizeof(D2SGameDataStrc) == 0x1DF4 ? 1 : -1];

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;
    D2SGameDataStrc* sub_00450ED0_New();                                                                    // 0x00450ED0
};

struct D2StormGameDataListStrc
{
    D2StormGameDataArrayStrc m_array;
    D2SGameDataStrc* sub_00450F70_New();
};

// 0x00450090
D2StormSlotListArrayStrc::~D2StormSlotListArrayStrc()
{
}

// 0x00450500
void D2StormListFixedArrayStrc::sub_00450500_Clear()
{
    this->D2StormListFixedArrayStrc::~D2StormListFixedArrayStrc();
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

// 0x00450690
void D2StormHashTableReuseStrc::sub_00450690_DeleteChunksAndReuse()
{
    m_chunkList.sub_00450580_DeleteAll();
    m_reuseList.sub_0044FC60_DeleteAll();
}

// 0x00450D30
void __fastcall sub_00450D30_ConstructGameData(D2SGameDataStrc* pData)
{
    new (pData) D2SGameDataStrc;
}

// 0x00450D50
void __fastcall sub_00450D50_CopyConstructGameData(D2SGameDataStrc* pData, const D2SGameDataStrc& tSource)
{
    new (pData) D2SGameDataStrc(tSource);
}

// 0x00450F70
D2SGameDataStrc* D2StormGameDataListStrc::sub_00450F70_New()
{
    return m_array.sub_00450ED0_New();
}
