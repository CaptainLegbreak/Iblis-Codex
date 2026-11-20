#include "D2GameTypes.h"
struct D2CelListStrc;
struct D2StormListAStrc;


extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210

struct CELLIST;
struct HCELLIST__;
struct HLOCKEDCELLIST__;
class HASHKEY_NONE;
class CCritSect;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <class T, class THANDLE, int CHUNKSIZE> class TSExportTableSimple;
template <class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE> class TSExportTableSync;
template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> D2GameHashTableReuseStrc;
template <> class TSExportTableSimple<CELLIST, HCELLIST__*, 0>;
typedef TSExportTableSimple<CELLIST, HCELLIST__*, 0> D2GameExportTableSimpleStrc;
template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0>;
typedef TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> D2GameDataTableStrc;
// build: symbol ??0?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00603E70

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2CelListStrc* pNode);
    virtual D2CelListStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
};

template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> : public TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2CelListStrc* pNode);                                                    // 0x00604150
    virtual D2CelListStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006044F0
    char unk0x04[0x40];

    TSHashTableReuse();                                                                            // 0x00603E70
};

template <> class TSExportTableSimple<CELLIST, HCELLIST__*, 0> : public D2GameHashTableReuseStrc
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

template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> : public D2GameExportTableSimpleStrc
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

extern D2GameDataTableStrc gCelListTable_008E8CC0;                                                  // 0x008E8CC0
void __cdecl sub_006CB4C0_DestroyTable();                                                           // 0x006CB4C0
extern "C" int __cdecl atexit(void (__cdecl* callback)());                                                  // 0x00683824

// build: symbol ??_7?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@6B@ 0x006E5E24
// 0x006CAFC0
void __cdecl sub_006CAFC0_InitCelListTable()
{
    new (&gCelListTable_008E8CC0) D2GameDataTableStrc;
    atexit(sub_006CB4C0_DestroyTable);
}
