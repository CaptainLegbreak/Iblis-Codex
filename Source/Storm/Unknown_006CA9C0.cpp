#include "D2GameTypes.h"
struct D2SGameDataStrc;
struct D2StormListAStrc;


extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210

struct SGAMEDATA;
struct HSGAMEDATA__;
struct HSGAMEDATALOCK__;
class HASHKEY_NONE;
class CCritSect;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <class T, class THANDLE, int CHUNKSIZE> class TSExportTableSimple;
template <class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE> class TSExportTableSync;
template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> D2StormHashTableReuseStrc;
template <> class TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0>;
typedef TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> D2StormExportTableSimpleStrc;
template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0>;
typedef TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> D2StormExportTableSyncStrc;
// build: symbol ??0?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00451100

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
};

template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> : public TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2SGameDataStrc* pNode);                                                    // 0x00450D60
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00451000
    char unk0x04[0x40];

    TSHashTableReuse();                                                                            // 0x00451100
};

template <> class TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> : public D2StormHashTableReuseStrc
{
public:
    unsigned int unk0x44;
    unsigned int m_sequence;
    void* m_wrapper;

    TSExportTableSimple()
    {
        m_sequence = ~(unsigned int)this & 0x0FFFFFFF;
        m_wrapper = 0;
    }
};

template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> : public D2StormExportTableSimpleStrc
{
public:
    D2CriticalSectionStrc m_cs;

    TSExportTableSync()
    {
        InitializeCriticalSection(&m_cs);
    }
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere)
{
    return pWhere;
}

extern D2StormExportTableSyncStrc gGameDataTable_007A0690;                                                  // 0x007A0690
void __cdecl sub_006CB3E0_DestroyHashTable();                                                           // 0x006CB3E0
extern "C" int __cdecl atexit(void (__cdecl* callback)());                                                  // 0x00683824

// build: symbol ??_7?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@6B@ 0x006D5E98
// 0x006CA9C0
void __cdecl sub_006CA9C0_InitGameDataTable()
{
    new (&gGameDataTable_007A0690) D2StormExportTableSyncStrc;
    atexit(sub_006CB3E0_DestroyHashTable);
}
