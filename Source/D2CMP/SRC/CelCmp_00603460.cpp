#include "D2CmpStormList.h"
#include "D2CmpStormHash.h"
struct D2StormEntry38Strc;

inline D2StormSlotGrowArrayStrc::~D2StormSlotGrowArrayStrc() throw()
{
}

// build: symbol ??1?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAE@XZ 0x00603460
// build: symbol ??1D2StormSlotListStrc@@QAE@XZ 0x00602AA0

// build: symbol ??_7?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@6B@ 0x006E5DE8
// 0x00603460
D2GameHashTableStrc::~TSHashTable()
{
    CelListTableInternalClear(1);
}
