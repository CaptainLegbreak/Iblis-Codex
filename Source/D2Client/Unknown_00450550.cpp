int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);             // 0x006CC1FC

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct SGAMEDATA;
struct HSGAMEDATA__;
struct HSGAMEDATALOCK__;
class HASHKEY_NONE;
class CCritSect;
template <class T, class KEY> class TSHashTable;
template <class T, class KEY, int CHUNKSIZE> class TSHashTableReuse;
template <class T, class THANDLE, int CHUNKSIZE> class TSExportTableSimple;
template <class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE> class TSExportTableSync;
template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>;
typedef TSHashTable<SGAMEDATA, HASHKEY_NONE> D2StormHashTableStrc;
template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>;
typedef TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> D2StormHashTableReuseStrc;
template <> class TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0>;
typedef TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> D2StormExportTableSimpleStrc;
template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0>;
typedef TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> D2StormExportTableSyncStrc;
// build: symbol ??1?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00450760
// build: symbol ??1?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAE@XZ 0x00450210

template <> class TSHashTable<SGAMEDATA, HASHKEY_NONE>
{
public:
    explicit TSHashTable(int nEmitTag)
    {
    }
    virtual void InternalDelete(char* pNode);                                                               // 0x004503F0
    virtual void InternalNew();                                                                             // 0x00450420
    virtual ~TSHashTable();                                                                        // 0x00450210
    virtual void Destroy();                                                                                 // 0x00450520
    static void operator delete(void* pMemory);

    char unk0x04[0x24];
};

template <> class TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> : public D2StormHashTableStrc
{
public:
    explicit TSHashTableReuse(int nEmitTag) : D2StormHashTableStrc(nEmitTag)
    {
    }
    virtual void InternalDelete(char* pNode);                                                               // 0x00450D60
    virtual void InternalNew();                                                                             // 0x00451000
    virtual ~TSHashTableReuse();                                                                   // 0x00450760
    virtual void Destroy();                                                                                 // 0x004510B0
    static void operator delete(void* pMemory);

    char unk0x28[0x28];
};

template <> class TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> : public D2StormHashTableReuseStrc
{
public:
    explicit TSExportTableSimple(int nEmitTag) : D2StormHashTableReuseStrc(nEmitTag)
    {
    }
    static void operator delete(void* pMemory);
};

struct D2StormCritSectStrc
{
    char tCriticalSection[0x18];

    ~D2StormCritSectStrc();
};

template <> class TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> : public D2StormExportTableSimpleStrc
{
public:
    explicit TSExportTableSync(int nEmitTag) : D2StormExportTableSimpleStrc(nEmitTag)
    {
    }
    static void operator delete(void* pMemory);

    D2StormCritSectStrc m_cs;
};

inline D2StormCritSectStrc::~D2StormCritSectStrc()
{
    DeleteCriticalSection(tCriticalSection);
}

// build: symbol ??_G?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@UAEPAXI@Z 0x004511A0
// build: symbol ??_G?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@UAEPAXI@Z 0x00451220
// build: symbol ??_G?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEPAXI@Z 0x004510D0
// build: symbol ??_G?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEPAXI@Z 0x00450550
// 0x00450550
inline void D2StormHashTableStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004510D0
inline void D2StormHashTableReuseStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004511A0
inline void D2StormExportTableSimpleStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00451220
inline void D2StormExportTableSyncStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void sub_Emit_D2StormHashTables(void* pHash, void* pReuse, void* pSimple, void* pSync)
{
    new (pHash) D2StormHashTableStrc(0);
    new (pReuse) D2StormHashTableReuseStrc(0);
    new (pSimple) D2StormExportTableSimpleStrc(0);
    new (pSync) D2StormExportTableSyncStrc(0);
}
