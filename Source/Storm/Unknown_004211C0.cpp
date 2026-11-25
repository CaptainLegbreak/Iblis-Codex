#include "Storm.h"
#include "stpl.h"

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// The big-number code's byte, limb and char arrays: TSGrowableArray members.
// build: symbol ?ReallocData@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x004211C0
// build: symbol ?Reserve@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXIH@Z 0x00421630
// build: symbol ?ReallocData@?$TSGrowableArray@IU?$TSCD@I@@@@QAEXI@Z 0x004216E0
// build: symbol ??0?$TSGrowableArray@EU?$TSCD@E@@@@QAE@XZ 0x004218A0
// build: symbol ?Reserve@?$TSGrowableArray@IU?$TSCD@I@@@@QAEXIH@Z 0x00421AB0
// build: symbol ?Reserve@?$TSGrowableArray@DU?$TSCD@D@@@@QAEXIH@Z 0x00421B00
// build: symbol ?CalcChunkSize@?$TSGrowableArray@IU?$TSCD@I@@@@QAEII@Z 0x004210A0
// build: symbol ?CalcChunkSize@?$TSGrowableArray@EU?$TSCD@E@@@@QAEII@Z 0x00421160
// build: symbol ?CalcChunkSize@?$TSGrowableArray@DU?$TSCD@D@@@@QAEII@Z 0x00421240
// build: symbol ?ReallocData@?$TSGrowableArray@DU?$TSCD@D@@@@QAEXI@Z 0x00421770
// build: symbol ??_R0I@8 0x0070886C
// build: symbol ??_R0E@8 0x00708878
// build: symbol ??_R0D@8 0x00708884
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol _SMemReAlloc@20 0x004133D0
template void TSGrowableArray<unsigned char>::ReallocData(unsigned int);
template void TSGrowableArray<unsigned char>::Reserve(unsigned int, int);
template void TSGrowableArray<unsigned int>::ReallocData(unsigned int);
template TSGrowableArray<unsigned char>::TSGrowableArray();
template void TSGrowableArray<unsigned int>::Reserve(unsigned int, int);
template void TSGrowableArray<char>::Reserve(unsigned int, int);

// The byte array's one-element Add keeps its own name: Storm's name for it isn't known.
struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}

#include "gen/data/Source/Storm/Unknown_004211C0.inc"
