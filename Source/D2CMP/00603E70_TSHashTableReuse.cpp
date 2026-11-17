struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormSlotListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void UnlinkAll();                                                                                       // 0x00602640
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListEStrc()
    {
        m_linkoffset = 0x10;
        InitializeTerminator();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2StormEntry38Strc;

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;
};

struct CELLIST;
class HASHKEY_NONE;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <> class TSHashTable<CELLIST, HASHKEY_NONE>;
typedef TSHashTable<CELLIST, HASHKEY_NONE> D2GameHashTableStrc;
template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> D2GameHashTableReuseStrc;
// build: symbol ??0?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00603E70
// build: symbol ??0?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00603BD0
// build: symbol ??1?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00604640

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();                                                                                  // 0x00603BD0
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~TSHashTable();                                                                         // 0x00603460
    virtual void Destroy();                                                                                 // 0x00603780
};

template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> : public D2GameHashTableStrc
{
public:
    D2StormSlotListStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormListEStrc m_chunkList;

    TSHashTableReuse();
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x00604150
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006044F0
    virtual ~TSHashTableReuse();                                                                    // 0x00604640
    virtual void Destroy();                                                                                 // 0x006046E0
};

// build: symbol ??_7?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@6B@ 0x006E5DFC
// 0x00603E70
D2GameHashTableReuseStrc::TSHashTableReuse()
{
    m_chunkSize = 16;
    m_reuseList.ChangeLinkOffset(4);
}
