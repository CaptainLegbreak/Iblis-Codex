#include "D2GameTypes.h"
#include "D2StormLink.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650


struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormSlotListStrc()
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
    void UnlinkAll();                                                                                       // 0x00602640
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListEStrc()
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

struct D2StormEntry38Strc;

struct D2StormSlotArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormSlotListStrc* m_data;
    unsigned int m_chunk;
};

struct CELLIST;
struct HCELLIST__;
struct HLOCKEDCELLIST__;
class HASHKEY_NONE;
class CCritSect;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <class T, class THANDLE, int CHUNKSIZE> class TSExportTableSimple;
template <class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE> class TSExportTableSync;
template <> class TSHashTable<CELLIST, HASHKEY_NONE>;
typedef TSHashTable<CELLIST, HASHKEY_NONE> D2GameHashTableStrc;
template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> D2GameHashTableReuseStrc;
template <> class TSExportTableSimple<CELLIST, HCELLIST__*, 0>;
typedef TSExportTableSimple<CELLIST, HCELLIST__*, 0> D2GameExportTableSimpleStrc;
template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0>;
typedef TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> D2GameDataTableStrc;
// build: symbol ??0?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@QAE@XZ 0x00604810
// build: symbol ??0?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@QAE@XZ 0x00604730
// build: symbol ??1?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00604640

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();                                                                                  // 0x00603BD0
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~TSHashTable();                                                                         // 0x00603460
    virtual void Destroy();                                                                                 // 0x00603780
};

template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> : public D2GameHashTableStrc
{
public:
    D2StormSlotListStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormListEStrc m_chunkList;

    TSHashTableReuse();
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x00604150
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006044F0
    virtual ~TSHashTableReuse();                                                                    // 0x00604640
    virtual void Destroy();                                                                                 // 0x006046E0
};

template <> class TSExportTableSimple<CELLIST, HCELLIST__*, 0> : public D2GameHashTableReuseStrc
{
public:
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    TSExportTableSimple();
    static void operator delete(void* pMemory);
};

struct D2StormCritSectStrc
{
    D2CriticalSectionStrc f_0;

    ~D2StormCritSectStrc()
    {
        DeleteCriticalSection(&f_0);
    }
};

template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> : public D2GameExportTableSimpleStrc
{
public:
    D2StormCritSectStrc m_sync;

    TSExportTableSync();
    static void operator delete(void* pMemory);
};

inline void D2GameExportTableSimpleStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

inline void D2GameDataTableStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??0?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00603E70
// build: symbol ??_7?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@6B@ 0x006E5E24
// build: symbol ??_7?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@6B@ 0x006E5E10
// 0x00604730
D2GameExportTableSimpleStrc::TSExportTableSimple()
{
    m_sequence = ~(unsigned int)this & 0x0FFFFFFF;
    m_wrapped = 0;
}

// 0x00604810
D2GameDataTableStrc::TSExportTableSync()
{
    InitializeCriticalSection(&m_sync.f_0);
}
