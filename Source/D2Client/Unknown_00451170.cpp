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
// build: symbol ??0?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@QAE@XZ 0x00451170
// build: symbol ??0?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@QAE@XZ 0x004511F0
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

    TSExportTableSimple();
};

template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> : public D2StormExportTableSimpleStrc
{
public:
    D2CriticalSectionStrc m_cs;

    TSExportTableSync();
};

// build: symbol ??_7?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@6B@ 0x006D5E84
// build: symbol ??_7?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@6B@ 0x006D5E98
// 0x00451170
D2StormExportTableSimpleStrc::TSExportTableSimple()
{
    m_sequence = ~(unsigned int)this & 0x0FFFFFFF;
    m_wrapper = 0;
}

// 0x004511F0
D2StormExportTableSyncStrc::TSExportTableSync()
{
    InitializeCriticalSection(&m_cs);
}
