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

// build: symbol ??1D2StormListAStrc@@QAE@XZ 0x0044FBE0
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll() throw(); // 0x0044F8E0
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    ~D2StormListFixedArrayStrc() throw(); // 0x0044FF60
};

struct D2StormSlotListArrayStrc
{
    D2StormListFixedArrayStrc m_array;

// build: symbol ??1D2StormSlotListArrayStrc@@QAE@XZ 0x00450090
    ~D2StormSlotListArrayStrc() throw()
    {
    }
};

struct SGAMEDATA;
class HASHKEY_NONE;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>;
typedef TSHashTable<SGAMEDATA, HASHKEY_NONE> D2StormHashTableStrc;
// build: symbol ??1?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x00450210

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode); // 0x004503F0
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00450420
    ~TSHashTable();
    virtual void Destroy(); // 0x00450520
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0044FA00_InternalClear(int bWarn); // 0x0044FA00
};

// build: symbol ??_7?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@6B@ 0x006D5E5C
// 0x00450210
D2StormHashTableStrc::~TSHashTable()
{
    sub_0044FA00_InternalClear(1);
}
