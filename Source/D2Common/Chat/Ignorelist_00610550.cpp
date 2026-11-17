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

struct D2CommonStormSlotListCStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

// build: symbol ??1D2CommonStormSlotListCStrc@@QAE@XZ 0x0060F190
    ~D2CommonStormSlotListCStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll() throw(); // 0x0060ECB0
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    void* m_terminator[2];
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayBStrc() throw(); // 0x0060F950
};

struct D2CommonStormSlotGrowArrayBStrc
{
    D2CommonStormSlotArrayBStrc m_array;

// build: symbol ??1D2CommonStormSlotGrowArrayBStrc@@QAE@XZ 0x00610080
    ~D2CommonStormSlotGrowArrayBStrc() throw()
    {
    }
};

struct MappingEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>;
typedef TSHashTable<MappingEntryNode, HASHKEY_STRI> D2CommonStormHashTableBStrc;
// build: symbol ??1?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x00610550

template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>
{
public:
    virtual void InternalDelete(D2StormEntryNodeStrc* pNode); // 0x00610690
    virtual D2StormEntryNodeStrc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~TSHashTable();
    virtual void Destroy(); // 0x006107D0
    D2CommonStormSlotListCStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotGrowArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0060EE60_InternalClear(int bWarn); // 0x0060EE60
};

// build: symbol ??_7?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@6B@ 0x006E62C8
// 0x00610550
D2CommonStormHashTableBStrc::~TSHashTable()
{
    sub_0060EE60_InternalClear(1);
}
