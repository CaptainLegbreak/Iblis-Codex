struct D2StormEntryNodeStrc;

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

struct D2StormSlotList0060EDB0Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

// build: symbol ??1D2StormSlotList0060EDB0Strc@@QAE@XZ 0x0060EDB0
    ~D2StormSlotList0060EDB0Strc()
    {
        UnlinkAll();
    }
    void UnlinkAll() throw(); // 0x0060E820
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    void* m_terminator[2];
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayAStrc() throw(); // 0x0060F610
};

struct D2CommonStormSlotArrayAViewStrc
{
    D2CommonStormSlotArrayAStrc m_array;

// build: symbol ??1D2CommonStormSlotArrayAViewStrc@@QAE@XZ 0x0060F930
    ~D2CommonStormSlotArrayAViewStrc() throw()
    {
    }
};

struct StringEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>;
typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;
// build: symbol ??1?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x0060FD90

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    virtual void InternalDelete(D2StormEntryNodeStrc* pNode); // 0x0060FFA0
    virtual D2StormEntryNodeStrc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~TSHashTable();
    virtual void Destroy(); // 0x00610020
    D2StormSlotList0060EDB0Strc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAViewStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0060EB70_InternalClear(int bWarn); // 0x0060EB70
};

// build: symbol ??_7?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62B4
// 0x0060FD90
D2CommonStormHashTableAStrc::~TSHashTable()
{
    sub_0060EB70_InternalClear(1);
}
