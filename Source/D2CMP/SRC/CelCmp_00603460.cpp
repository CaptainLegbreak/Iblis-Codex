#include "D2CmpStormList.h"
struct D2StormEntry38Strc;

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

inline D2StormSlotGrowArrayStrc::~D2StormSlotGrowArrayStrc() throw()
{
}

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
