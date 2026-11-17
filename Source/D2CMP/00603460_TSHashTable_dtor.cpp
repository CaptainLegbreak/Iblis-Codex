struct D2StormEntry38Strc;

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

struct D2StormFullListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

// build: symbol ??1D2StormFullListStrc@@QAE@XZ 0x00602AA0
    ~D2StormFullListStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll() throw(); // 0x00602640
};

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

    ~D2StormSlotArrayStrc() throw(); // 0x00603060
};

struct D2StormSlotGrowArrayStrc
{
    D2StormSlotArrayStrc m_array;

// build: symbol ??1D2StormSlotGrowArrayStrc@@QAE@XZ 0x00603240
    ~D2StormSlotGrowArrayStrc() throw()
    {
    }
};

struct CELLIST;
class HASHKEY_NONE;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<CELLIST, HASHKEY_NONE>;
typedef TSHashTable<CELLIST, HASHKEY_NONE> D2GameHashTableStrc;
// build: symbol ??1?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAE@XZ 0x00603460

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2StormEntry38Strc* pNode); // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~TSHashTable();
    virtual void Destroy(); // 0x00603780
    D2StormFullListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotGrowArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00602800_InternalClear(int bWarn); // 0x00602800
};

// build: symbol ??_7?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@6B@ 0x006E5DE8
// 0x00603460
D2GameHashTableStrc::~TSHashTable()
{
    sub_00602800_InternalClear(1);
}
