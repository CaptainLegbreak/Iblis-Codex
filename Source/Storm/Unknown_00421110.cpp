#include "Storm.h"
#include "stpl.h"

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

// build: symbol ?ReallocData@?$TSFixedArray@IU?$TSCD@I@@@@QAEXI@Z 0x00421110
// build: symbol ?ReallocData@?$TSFixedArray@EU?$TSCD@E@@@@QAEXI@Z 0x00421680
// build: symbol ?ReallocData@?$TSFixedArray@DU?$TSCD@D@@@@QAEXI@Z 0x004216B0
// build: symbol ??4?$TSFixedArray@IU?$TSCD@I@@@@QAEAAU0@ABU0@@Z 0x00421870
// build: symbol ?SetCount@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x00421980
// build: symbol ??4?$TSGrowableArray@IU?$TSCD@I@@@@QAEAAU0@ABU0@@Z 0x00421BA0
// build: symbol ?Set@?$TSFixedArray@IU?$TSCD@I@@@@QAEXIPBI@Z 0x004215C0
// build: symbol ?CalcChunkSize@?$TSGrowableArray@EU?$TSCD@E@@@@QAEII@Z 0x00421160
// build: symbol ?ReallocData@?$TSGrowableArray@EU?$TSCD@E@@@@QAEXI@Z 0x004211C0
// build: symbol ??0?$TSBaseArray@I@@QAE@XZ 0x00421020
// build: symbol ??0?$TSBaseArray@E@@QAE@XZ 0x00421030
// build: symbol ??0?$TSGrowableArray@IU?$TSCD@I@@@@QAE@XZ 0x00421860
// build: symbol ??_R0I@8 0x0070886C
// build: symbol ??_R0E@8 0x00708878
// build: symbol ??_R0D@8 0x00708884
template TSBaseArray<unsigned int>::TSBaseArray();
template TSBaseArray<unsigned char>::TSBaseArray();
template TSGrowableArray<unsigned int>::TSGrowableArray();
template void TSFixedArray<unsigned int>::ReallocData(unsigned int);
template void TSFixedArray<unsigned char>::ReallocData(unsigned int);
template void TSFixedArray<char>::ReallocData(unsigned int);
template TSFixedArray<unsigned int>& TSFixedArray<unsigned int>::operator=(const TSFixedArray<unsigned int>&);
template void TSGrowableArray<unsigned char>::SetCount(unsigned int);
template TSGrowableArray<unsigned int>& TSGrowableArray<unsigned int>::operator=(const TSGrowableArray<unsigned int>&);
