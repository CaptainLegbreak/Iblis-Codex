#include "D2StormAutoLink.h"
struct D2SGameDataStrc;

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
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;

    ~D2StormListFixedArrayStrc();                                                                           // 0x0044FF60
    void Clear()
    {
        this->~D2StormListFixedArrayStrc();
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
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
