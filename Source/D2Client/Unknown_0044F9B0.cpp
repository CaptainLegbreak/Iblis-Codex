#include "SGAMEDATA.h"

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

inline void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// The game list's Storm template members (D2Client keeps its games in a TSExportTableSync over
// TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>), in the order the object has them.
// build: symbol ??1?$TSHashObject@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x0044F820
// build: symbol ?UnlinkNode@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXPAUSGAMEDATA@@@Z 0x0044F890
// build: symbol ?UnlinkAll@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXXZ 0x0044F8E0
// build: symbol ?UnlinkAll@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x0044F930
// build: symbol ?ChangeLinkOffset@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXH@Z 0x0044F980
// build: symbol ??0?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAE@XZ 0x0044F9B0
// build: symbol ??0?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAE@XZ 0x0044F9D0
// build: symbol ??1D2SGameDataHolderStrc@@QAE@XZ 0x0044F9F0
// build: symbol ?InternalClear@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAEXH@Z 0x0044FA00
// build: symbol ??1?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAE@XZ 0x0044FA90
// build: symbol ??1?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAE@XZ 0x0044FAD0
// build: symbol ??0?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@QAE@XZ 0x0044FB10
// build: symbol ??0?$TSExplicitList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@$0BA@@@QAE@XZ 0x0044FB30
// build: symbol ??0?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAE@ABU0@@Z 0x0044FB80
// build: symbol ??_GSGAMEDATA@@QAEPAXI@Z 0x0044FBB0
// build: symbol ??1?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@QAE@XZ 0x0044FBE0
// build: symbol ??1?$TSExplicitList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@$0BA@@@QAE@XZ 0x0044FC20
// build: symbol ?Clear@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXXZ 0x0044FC60
// build: symbol ??_G?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@QAEPAXI@Z 0x0044FCF0
// build: symbol ??1SGAMEDATA@@QAE@XZ 0x0044FD50
// build: symbol ??1?$TSFixedArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAE@XZ 0x0044FD80
// build: symbol ??1D2SGameDataList0044FDD0Strc@@QAE@XZ 0x0044FDD0
// build: symbol ?ReallocData@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXI@Z 0x0044FE10
// build: symbol ??1?$TSFixedArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x0044FF60
// build: symbol ??1?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAE@XZ 0x0044FFE0
// build: symbol ??1?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x0044FFF0
// build: symbol ??0?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x00450030
// build: symbol ?Reserve@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXIH@Z 0x00450040
// build: symbol ??1?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x00450090
// build: symbol ??_G?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@QAEPAXI@Z 0x004500A0
// build: symbol ?SetCount@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXI@Z 0x00450110
// build: symbol ??1?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAE@XZ 0x00450210
// build: symbol ?LinkNode@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXPAUSGAMEDATA@@I0@Z 0x004502A0
// build: symbol ??0?$TSHashObject@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x00450350
// build: symbol ??0SGAMEDATA@@QAE@XZ 0x00450370
// build: symbol ?NewNode@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEPAUSGAMEDATA@@III@Z 0x00450390
// build: symbol ?InternalDelete@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEXPAUSGAMEDATA@@@Z 0x004503F0
// build: symbol ?InternalNew@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEPAUSGAMEDATA@@PAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@II@Z 0x00450420
// build: symbol ??_G?$TSFixedArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEPAXI@Z 0x004504D0
// build: symbol ?Clear@?$TSFixedArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXXZ 0x00450500
// build: symbol ?Destroy@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEXXZ 0x00450520
// build: symbol ??_G?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEPAXI@Z 0x00450550
// build: symbol ?Clear@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x00450580
// build: symbol ?DeleteChunksAndReuse@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAEXXZ 0x00450690
// build: symbol ??0?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x004506B0
// build: symbol ??1?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00450760
// build: symbol ?CalcChunkSize@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEII@Z 0x00450810
// build: symbol ?RoundUp@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@SGIII@Z 0x00450850
// build: symbol ??0?$TSBaseArray@USGAMEDATA@@@@QAE@XZ 0x00450870
// build: symbol ?LinkNode@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEXPAV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@I0@Z 0x004508A0
// build: symbol ??0SGAMEDATA@@QAE@ABU0@@Z 0x00450950
// build: symbol ?Clear@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAEXXZ 0x00450D20
// build: symbol ?InternalDelete@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEXPAUSGAMEDATA@@@Z 0x00450D60
// build: symbol ?ReallocData@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEXI@Z 0x00450D90
// build: symbol ?Reserve@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEXIH@Z 0x00450E70
// build: symbol ??0?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAE@XZ 0x00450EC0
// build: symbol ?New@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEPAUSGAMEDATA@@XZ 0x00450ED0
// build: symbol ??0?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x00450F80
// build: symbol ?NewNode@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEPAV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@III@Z 0x00450FA0
// build: symbol ?InternalNew@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEPAUSGAMEDATA@@PAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@II@Z 0x00451000
// build: symbol ?Destroy@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEXXZ 0x004510B0
// build: symbol ??_G?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEPAXI@Z 0x004510D0
// build: symbol ??0?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00451100
// build: symbol ??1?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@UAE@XZ 0x00451160
// build: symbol ??0?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@QAE@XZ 0x00451170
// build: symbol ??_G?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@UAEPAXI@Z 0x004511A0
// build: symbol ??1?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@UAE@XZ 0x004511D0
// build: symbol ??0?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@QAE@XZ 0x004511F0
// build: symbol ??_G?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@UAEPAXI@Z 0x00451220
// build: symbol ??_7?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@6B@ 0x006D5E98
// build: symbol __imp__InitializeCriticalSection@4 0x006CC210
// build: symbol __imp__DeleteCriticalSection@4 0x006CC1FC
// build: symbol ??_7?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@6B@ 0x006D5E84
// build: symbol ??_7?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@6B@ 0x006D5E5C
// build: symbol ??_7?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@6B@ 0x006D5E70
// build: symbol ??_R0?AUSGAMEDATA@@@8 0x0070F564
// build: symbol ??_R0?AV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@8 0x0070F57C
// build: symbol ??_R0?AV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@8 0x0070F5EC
// build: symbol ?CalcChunkSize@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEII@Z 0x0044DF30
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol _SMemReAlloc@20 0x004133D0
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::UnlinkNode(SGAMEDATA*);
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::UnlinkAll();
template void TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::UnlinkAll();
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::ChangeLinkOffset(int);
template TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::TSList();
template TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::TSList();
template void D2SGameDataTable::InternalClear(int);
template TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::~TSList();
template TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::~TSList();
template TSExplicitList<SGAMEDATA, STORM_EXPLICIT_LIST_UNSET>::TSExplicitList();
template TSExplicitList<D2SGameDataChunk, 0x10>::TSExplicitList();
template TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::TSList(const TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >&);
template TSExplicitList<SGAMEDATA, STORM_EXPLICIT_LIST_UNSET>::~TSExplicitList();
template TSExplicitList<D2SGameDataChunk, 0x10>::~TSExplicitList();
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::Clear();
template TSGrowableArray<D2SGameDataList>::TSGrowableArray();
template void TSGrowableArray<D2SGameDataList>::ReallocData(unsigned int);
template void TSGrowableArray<D2SGameDataList>::Reserve(unsigned int, int);
template TSGrowableArray<D2SGameDataList>::~TSGrowableArray();
template void TSGrowableArray<D2SGameDataList>::SetCount(unsigned int);
template TSGrowableArray<SGAMEDATA>::~TSGrowableArray();
template D2SGameDataChunk::~TSHashObjectChunk();
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::LinkNode(SGAMEDATA*, unsigned int, SGAMEDATA*);
template TSHashObject<SGAMEDATA, HASHKEY_NONE>::TSHashObject();
template SGAMEDATA* TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::NewNode(unsigned int, unsigned int, unsigned int);
template void TSFixedArray<D2SGameDataList>::Clear();
template void TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::Clear();
template void D2SGameDataReuseTable::DeleteChunksAndReuse();
template D2SGameDataTable::TSHashTable();
template D2SGameDataReuseTable::~TSHashTableReuse();
template unsigned int TSGrowableArray<SGAMEDATA>::CalcChunkSize(unsigned int);
template unsigned int __stdcall TSGrowableArray<SGAMEDATA>::RoundUp(unsigned int, unsigned int);
template TSBaseArray<SGAMEDATA>::TSBaseArray();
template void TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::LinkNode(D2SGameDataChunk*, unsigned int, D2SGameDataChunk*);
template void D2SGameDataTable::Clear();
template void TSGrowableArray<SGAMEDATA>::ReallocData(unsigned int);
template void TSGrowableArray<SGAMEDATA>::Reserve(unsigned int, int);
template TSGrowableArray<SGAMEDATA>::TSGrowableArray();
template SGAMEDATA* TSGrowableArray<SGAMEDATA>::New();
template D2SGameDataChunk* TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::NewNode(unsigned int, unsigned int, unsigned int);
template D2SGameDataReuseTable::TSHashTableReuse();
template D2SGameDataExportTable::TSExportTableSimple();
template D2SGameDataSyncTable::TSExportTableSync();

// Helpers of the table's types whose template form isn't settled keep their own names.
struct D2SGameDataHolderStrc
{
    SGAMEDATA tData;

    ~D2SGameDataHolderStrc();
};

struct D2SGameDataList0044FDD0Strc : TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >
{
    ~D2SGameDataList0044FDD0Strc();
};

struct D2SGameDataArrayHolderStrc
{
    TSGrowableArray<SGAMEDATA> m_array;

    SGAMEDATA* sub_00450F70_New();
    void sub_00450F50_ReserveExact(unsigned int nCount);
};

// 0x0044F9F0
D2SGameDataHolderStrc::~D2SGameDataHolderStrc()
{
}

// 0x0044FB50
void __fastcall sub_0044FB50_ConstructGameList(D2SGameDataList* pList)
{
    new (pList) D2SGameDataList;
}

// 0x0044FD60
void __fastcall sub_0044FD60_CopyConstructGameList(D2SGameDataList* pList, const D2SGameDataList* pSource)
{
    new (pList) D2SGameDataList(*pSource);
}

// 0x0044FDD0
D2SGameDataList0044FDD0Strc::~D2SGameDataList0044FDD0Strc()
{
}

// 0x00450D30
void __fastcall sub_00450D30_ConstructGameData(SGAMEDATA* pData)
{
    new (pData) SGAMEDATA;
}

// 0x00450D50
void __fastcall sub_00450D50_CopyConstructGameData(SGAMEDATA* pData, const SGAMEDATA& tSource)
{
    new (pData) SGAMEDATA(tSource);
}

// 0x00450F50
void D2SGameDataArrayHolderStrc::sub_00450F50_ReserveExact(unsigned int nCount)
{
    unsigned int nTotal = m_array.m_count + nCount;
    if (nTotal > m_array.m_alloc)
        m_array.ReallocData(nTotal);
}

// 0x00450F70
SGAMEDATA* D2SGameDataArrayHolderStrc::sub_00450F70_New()
{
    return m_array.New();
}

struct D2SGameDataListArrayHolderStrc
{
    TSGrowableArray<D2SGameDataList> m_array;

    void sub_00450680_SetCount(unsigned int nCount);
};

struct D2SGameDataPairStrc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00450800_GetDifference();
};

struct D2SGameDataArrayOwnerStrc
{
    unsigned int unk0x00;
    TSGrowableArray<SGAMEDATA> m_array;

    D2SGameDataArrayOwnerStrc(int nUnused);
};

// 0x00450680
void D2SGameDataListArrayHolderStrc::sub_00450680_SetCount(unsigned int nCount)
{
    m_array.SetCount(nCount);
}

// 0x00450800
unsigned int D2SGameDataPairStrc::sub_00450800_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00450880
D2SGameDataArrayOwnerStrc::D2SGameDataArrayOwnerStrc(int nUnused)
{
}

#include "gen/data/Source/D2Client/Unknown_0044F9B0.inc"
