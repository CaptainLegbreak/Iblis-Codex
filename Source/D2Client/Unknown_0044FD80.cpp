#include "D2StormAutoLink.h"
#include "D2StormListArray.h"
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags);       // 0x00412650

extern const char gszTypeSGameData[];                                                              // 0x0070F56C

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

struct D2StormGameArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2SGameDataStrc* m_data;
    unsigned int m_chunk;

    ~D2StormGameArrayStrc();
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc()
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
    void UnlinkAll();                                                                                       // 0x0044F8E0
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormChunkListStrc()
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


struct SGAMEDATA;
class HASHKEY_NONE;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>;
typedef TSHashTable<SGAMEDATA, HASHKEY_NONE> D2StormHashTableStrc;
template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> D2StormHashTableReuseStrc;
// build: symbol ??0?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00451100
// build: symbol ??0?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x004506B0

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);                                                    // 0x004503F0
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00450420
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();                                                                                 // 0x004506B0
};

template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> : public D2StormHashTableStrc
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);                                                    // 0x00450D60
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00451000
    D2StormListAStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormChunkListStrc m_chunkList;

    TSHashTableReuse();
};

// build: symbol ??_7?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@6B@ 0x006D5E70
// 0x0044FD80
D2StormGameArrayStrc::~D2StormGameArrayStrc()
{
    for (unsigned int i = 0; i < m_count; i++)
        m_data[i].~D2SGameDataStrc();
    if (m_data)
        SMemFree(m_data, gszTypeSGameData, -2, 0);
}

// 0x00451100
D2StormHashTableReuseStrc::TSHashTableReuse()
{
    m_chunkSize = 0x10;
    m_reuseList.ChangeLinkOffset(4);
}
