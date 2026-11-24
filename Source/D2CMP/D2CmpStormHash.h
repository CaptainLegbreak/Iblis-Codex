#pragma once
// Storm's hash table as the cel loader (CelCmp*.cpp) uses it: the hashed object and the cel list entry built on it,
// the reuse chunk, and the TSHashTable / TSHashTableReuse / TSExportTableSimple / TSExportTableSync classes over
// CELLIST that hold the cel lists.

#include "D2SysTypes.h"
#include "D2CmpStormList.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

struct D2StormHashObjectStrc
{
    unsigned int m_hashval;                                       // 0x00 hash value
    D2StormSlotLinkStrc m_linktoslot;                       // 0x04
    D2StormSlotLinkStrc m_linktofull;                                // 0x0C link in the full list
    int m_key;                                               // 0x14

    ~D2StormHashObjectStrc();                                                                               // 0x00602430
};

struct D2StormEntry38Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;                                   // 0x18
    int nType;                                              // 0x1C
    int nData;                                              // 0x20
    unsigned int nCount;                                    // 0x24
    unsigned int nDirections;                               // 0x28
    D2StormNodeListStrc tList;                              // 0x2C

    D2StormEntry38Strc()
    {
    }
    D2StormEntry38Strc(const D2StormEntry38Strc& source);                                                   // 0x006040B0
    static void operator delete(void* pMemory);
};

struct D2StormHashChunkStrc
{
    D2StormEntryArrayStrc tArray;                           // 0x00
    D2StormSlotLinkStrc f_10;                               // 0x10

    ~D2StormHashChunkStrc();                                                                                // 0x006032C0
    static void operator delete(void* pMemory);
};

struct D2StormCritSectStrc
{
    D2CriticalSectionStrc m_critsect;                              // 0x00

    ~D2StormCritSectStrc()
    {
        DeleteCriticalSection(&m_critsect);
    }
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

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~TSHashTable();                                                                                 // 0x00603460
    virtual void Destroy();                                                                                 // 0x00603780

    D2StormSlotListStrc m_fulllist;                         // 0x04
    unsigned int m_fullnessIndicator;                       // 0x10
    D2StormSlotGrowArrayStrc m_slotlistarray;               // 0x14
    unsigned int m_slotmask;                                // 0x24

    TSHashTable();                                                                                          // 0x00603BD0
    explicit TSHashTable(int nEmit)
    {
        m_slotmask = nEmit;
    }
    static void operator delete(void* pMemory);
    D2StormEntry38Strc* sub_006030E0_InternalFind(unsigned int nHashVal, const int& tKey);                 // 0x006030E0
    int sub_006045B0(unsigned int nSlot);                                                                   // 0x006045B0
    void CelListTableInternalClear(int bWarn);                                                             // 0x00602800
    void CelListTableGrowListArray();                                                                      // 0x00603C80
    void sub_00604070_Clear();                                                                              // 0x00604070
};

template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> : public D2GameHashTableStrc
{
public:
    D2StormSlotListStrc m_reuseList;                        // 0x28
    int unk0x34;                                            // 0x34
    D2StormHashChunkListStrc m_chunkList;                   // 0x38

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~TSHashTableReuse();                                                                            // 0x00604640
    virtual void Destroy();
    static void operator delete(void* pMemory);
    explicit TSHashTableReuse(int nEmit) : D2GameHashTableStrc(nEmit)
    {
    }
    void CelListTableDeleteReuseLists();                                                                        // 0x00603E50
};

template <> class TSExportTableSimple<CELLIST, HCELLIST__*, 0> : public D2GameHashTableReuseStrc
{
public:
    int f_44;                                               // 0x44
    unsigned int m_sequence;                                // 0x48
    int m_wrapped;                                          // 0x4C

    static void operator delete(void* pMemory);
    explicit TSExportTableSimple(int nEmit) : D2GameHashTableReuseStrc(nEmit)
    {
    }
};

template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> : public D2GameExportTableSimpleStrc
{
public:
    D2StormCritSectStrc m_sync;                             // 0x50

    static void operator delete(void* pMemory);
    explicit TSExportTableSync(int nEmit) : D2GameExportTableSimpleStrc(nEmit)
    {
    }
    void SyncEnterLock(int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&m_sync.m_critsect);
        *pLockHandle = bForWriting ? 1 : -1;
    }
    void SyncLeaveLock(int nLockHandle)
    {
        if (nLockHandle)
            LeaveCriticalSection(&m_sync.m_critsect);
    }
    D2StormEntry38Strc* Ptr(unsigned int hHandle)
    {
        return sub_006030E0_InternalFind(hHandle, f_44);
    }
    D2StormEntry38Strc* Lock(unsigned int hHandle, int* pLockHandle, int bForWriting)
    {
        SyncEnterLock(pLockHandle, bForWriting);
        D2StormEntry38Strc* pList = Ptr(hHandle);
        if (!pList)
        {
            SyncLeaveLock(*pLockHandle);
            *pLockHandle = 0;
        }
        return pList;
    }
    D2StormEntry38Strc* CelListTablePtr(unsigned int hHandle);                                             // 0x00603250
    D2StormEntry38Strc* CelListTableLock(unsigned int hHandle, int* pLockHandle, int bForWriting);         // 0x00603400
// build: symbol ?Delete@* 0x0052E590
    void Delete(D2StormEntry38Strc* pNode)
    {
        CelListTableUnlinkNode(pNode);
        InternalDelete(pNode);
    }
    unsigned int CelListTableGenerateHandle();                                                             // 0x00603280
    char* CelListTableNew(unsigned int nHashVal, const int& tKey, int nExtraBytes, int nFlags);            // 0x00604760
    void CelListTableSyncEnterLock(int* pLockHandle, int bForWriting);                                     // 0x00601B80
    int CelListTableIsWriteLock(int nLockHandle);                                                          // 0x00601CB0
    unsigned int CelListTableSlotIndex(unsigned int nHashVal);                                             // 0x00601D00
    void CelListTableUnlinkNode(D2StormEntry38Strc* pNode);                                                // 0x006021E0
    void CelListTableSyncLeaveLock(int nLockHandle);                                                       // 0x00602400
    void CelListTableDelete(D2StormEntry38Strc* pNode);                                                    // 0x00602620
    void sub_006027E0_Delete(D2StormEntry38Strc* pNode);                                                    // 0x006027E0
    void CelListTableDeleteUnlock(D2StormEntry38Strc* pNode, int nLockHandle);                             // 0x00602A10
    char* CelListTableNewHandle(unsigned int* pHandle);                                                    // 0x00604840
    char* CelListTableNewLock(unsigned int* pHandle, int* pLockHandle);                                    // 0x006048C0
};
