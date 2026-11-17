struct D2SGameDataStrc;

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

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
// build: symbol ?UnlinkAll@D2StormListAStrc@@QAEXXZ 0x0044F8E0
    void UnlinkAll();
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormChunkListStrc()
    {
        UnlinkAll();
    }
// build: symbol ?UnlinkAll@D2StormChunkListStrc@@QAEXXZ 0x0044F930
    void UnlinkAll();
    void sub_00450580_DeleteAll();                                                                          // 0x00450580
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    ~D2StormListFixedArrayStrc();                                                                           // 0x0044FF60
    void Clear()
    {
        this->~D2StormListFixedArrayStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};

struct SGAMEDATA;
class HASHKEY_NONE;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>;
typedef TSHashTable<SGAMEDATA, HASHKEY_NONE> D2StormHashTableStrc;
template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> D2StormHashTableReuseStrc;
// build: symbol ??1?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00450760
// build: symbol ??1?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAE@XZ 0x00450210

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);                                                    // 0x004503F0
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00450420
    virtual ~TSHashTable();                                                                        // 0x00450210
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListFixedArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0044FA00_InternalClear(int bWarn);                                                             // 0x0044FA00
};

template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> : public D2StormHashTableStrc
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);                                                    // 0x00450D60
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00451000
    virtual ~TSHashTableReuse();
// build: symbol ?Destroy@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEXXZ 0x004510B0
    virtual void Destroy();
    D2StormListAStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormChunkListStrc m_chunkList;
};

// build: symbol ??_7?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@6B@ 0x006D5E70
// build: symbol ?Destroy@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEXXZ 0x00450520
void D2StormHashTableStrc::Destroy()
{
    sub_0044FA00_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}

// 0x00450760
D2StormHashTableReuseStrc::~TSHashTableReuse()
{
    m_chunkList.sub_00450580_DeleteAll();
    m_reuseList.sub_0044FC60_DeleteAll();
}
