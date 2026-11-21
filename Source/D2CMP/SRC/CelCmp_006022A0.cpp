#include "D2GameTypes.h"
#include "D2CmpStormList.h"
// build: context D2StormEntry38Strc::~D2StormEntry38Strc
// build: context D2StormNodeListStrc::LinkNode
// build: context D2StormSlotListStrc::LinkNode

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

extern "C" const char gszTypeNameCelEntry[];                                                                // 0x00741F14
extern "C" const char gszTypeNameCelList[];                                                                 // 0x00741F2C
extern "C" const char gszTypeNameCelHashChunk[];                                                            // 0x00741FB4

struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormSlotLinkStrc m_linktoslot;
    D2StormSlotLinkStrc f_C;
    int f_14;
};

struct D2StormEntry38Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;

    static void operator delete(void* pMemory);
};

struct D2StormHashChunkStrc
{
    D2StormEntryArrayStrc tArray;
    D2StormSlotLinkStrc f_10;

    static void operator delete(void* pMemory);
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
// build: symbol ??1?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00604640
// build: symbol ??1?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAE@XZ 0x00603460

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~TSHashTable();                                                                         // 0x00603460
    virtual void Destroy();                                                                                 // 0x00603780
    static void operator delete(void* pMemory);
    explicit TSHashTable(int nEmit)
    {
        m_slotmask = nEmit;
    }
    D2StormEntry38Strc* sub_006030E0_InternalFind(unsigned int nHashVal, const int& tKey);                 // 0x006030E0
    int sub_006045B0(unsigned int nSlot);                                                   // 0x006045B0
};

template <> class TSHashTableReuse<CELLIST, HASHKEY_NONE, 0> : public D2GameHashTableStrc
{
public:
    D2StormListEStrc m_reuseList;
    int unk0x34;
    D2StormListEStrc m_chunkList;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~TSHashTableReuse();                                                                    // 0x00604640
    virtual void Destroy();                                                                                 // 0x006046E0
    static void operator delete(void* pMemory);
    // build: context ??0?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@*
    explicit TSHashTableReuse(int nEmit) : D2GameHashTableStrc(nEmit)
    {
    }
};

template <> class TSExportTableSimple<CELLIST, HCELLIST__*, 0> : public D2GameHashTableReuseStrc
{
public:
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    static void operator delete(void* pMemory);
    // build: context ??0?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@*
    explicit TSExportTableSimple(int nEmit) : D2GameHashTableReuseStrc(nEmit)
    {
    }
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

    static void operator delete(void* pMemory);
    // build: context ??0?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@*
    explicit TSExportTableSync(int nEmit) : D2GameExportTableSimpleStrc(nEmit)
    {
    }
    void SyncEnterLock(int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&m_sync.f_0);
        *pLockHandle = bForWriting ? 1 : -1;
    }
    void SyncLeaveLock(int nLockHandle)
    {
        if (nLockHandle)
            LeaveCriticalSection(&m_sync.f_0);
    }
    D2StormEntry38Strc* sub_00603250_Ptr(unsigned int hHandle);
    D2StormEntry38Strc* sub_00603400_Lock(unsigned int hHandle, int* pLockHandle, int bForWriting);
    char* sub_00604760_New(unsigned int nHashVal, const int& tKey, int nExtraBytes, int nFlags);
    char* sub_006048C0_NewLock(unsigned int* pHandle, int* pLockHandle);                                    // 0x006048C0
};

extern D2GameDataTableStrc gCelListTable;                                                                   // 0x008E8CC0

// build: symbol ?UnlinkAll@D2StormSlotListStrc@@QAEXXZ 0x00602640
// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
// build: symbol ??1D2StormHashObjectStrc@@QAE@XZ 0x00602430
// build: symbol ??_G?$TSExportTableSync@UCELLIST@@PAUHCELLIST__@@PAUHLOCKEDCELLIST__@@VCCritSect@@$0A@@@UAEPAXI@Z 0x00604900
// build: symbol ??_G?$TSExportTableSimple@UCELLIST@@PAUHCELLIST__@@$0A@@@UAEPAXI@Z 0x00604870
// build: symbol ??_G?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEPAXI@Z 0x00604700
// build: symbol ??_G?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEPAXI@Z 0x006037B0
// build: symbol ??_GD2StormEntry38Strc@@QAEPAXI@Z 0x00602CB0
// build: symbol ??_GD2StormHashChunkStrc@@QAEPAXI@Z 0x006037E0
// 0x006022A0
void D2StormListEStrc::sub_006022A0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00602590
void D2StormListEStrc::sub_00602590_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x006029B0
D2CelEntryStrc* D2StormNodeListStrc::sub_006029B0_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CelEntryStrc) + nExtraBytes, gszTypeNameCelEntry, -2, nFlags | 8);
    D2CelEntryStrc* pEntry = pMemory ? new (pMemory) D2CelEntryStrc : 0;
    if (nLinkType)
        sub_00601FC0_LinkNode(pEntry, nLinkType, 0);
    return pEntry;
}

// build: symbol ??_GD2StormSlotLinkStrc@@QAEPAXI@Z 0x00602A40
// build: symbol ??_GD2StormSlotListStrc@@QAEPAXI@Z 0x00602B70
// 0x00602C40
D2CelEntryStrc* D2StormNodeListStrc::sub_00602C40_DeleteNode(D2CelEntryStrc* pNode)
{
    D2CelEntryStrc* pNext = (D2CelEntryStrc*)Link(pNode)->Next();
    pNode->f_0.Unlink();
    SMemFree(pNode, gszTypeNameCelEntry, -2, 0);
    return pNext;
}

// 0x00602CB0
inline void D2StormEntry38Strc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00602D20
void D2StormListEStrc::sub_00602D20_DeleteAll()
{
    char* pNode;
    while ((pNode = m_terminator.Next()) != 0)
    {
        ((D2StormEntry38Strc*)pNode)->~D2StormEntry38Strc();
        SMemFree(pNode, gszTypeNameCelList, -2, 0);
    }
}

// 0x00602E30
char* D2StormListEStrc::sub_00602E30_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormEntry38Strc*)pNode)->~D2StormEntry38Strc();
    SMemFree(pNode, gszTypeNameCelList, -2, 0);
    return pNext;
}

// 0x00603250
inline D2StormEntry38Strc* D2GameDataTableStrc::sub_00603250_Ptr(unsigned int hHandle)
{
    return sub_006030E0_InternalFind(hHandle, f_44);
}

// 0x00603400
inline D2StormEntry38Strc* D2GameDataTableStrc::sub_00603400_Lock(unsigned int hHandle, int* pLockHandle, int bForWriting)
{
    SyncEnterLock(pLockHandle, bForWriting);
    D2StormEntry38Strc* pList = sub_00603250_Ptr(hHandle);
    if (!pList)
    {
        SyncLeaveLock(*pLockHandle);
        *pLockHandle = 0;
    }
    return pList;
}

// 0x006035A0
D2StormEntry38Strc* D2StormListEStrc::sub_006035A0_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormEntry38Strc) + nExtraBytes, gszTypeNameCelList, -2, nFlags | 8);
    D2StormEntry38Strc* pList = pMemory ? new (pMemory) D2StormEntry38Strc : 0;
    if (nLinkType)
        sub_006024E0_LinkNode((char*)pList, nLinkType, 0);
    return pList;
}

// build: symbol ?InternalNew@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEPAUD2StormEntry38Strc@@PAUD2StormSlotListStrc@@II@Z 0x00603610
D2StormEntry38Strc* D2GameHashTableStrc::InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormEntry38Strc) + nExtraBytes, gszTypeNameCelList, -2, nFlags | 8);
    D2StormEntry38Strc* pNode = pMemory ? new (pMemory) D2StormEntry38Strc : 0;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// build: symbol ?InternalDelete@?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@UAEXPAUD2StormEntry38Strc@@@Z 0x006036D0
void D2GameHashTableStrc::InternalDelete(D2StormEntry38Strc* pNode)
{
    pNode->~D2StormEntry38Strc();
    SMemFree(pNode, gszTypeNameCelList, -2, 0);
}

// 0x006037B0
inline void D2GameHashTableStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x006037E0
inline void D2StormHashChunkStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void __fastcall sub_005179B3_ConvertCelPixels(void* pDst, void* pSrc, int nRows, unsigned int nSrcSize, unsigned int nWidth, int nRows2); // 0x005179B3

// build: context sub_F43_NewCelEntry
static inline D2CelEntryStrc* __cdecl sub_F43_NewCelEntry(D2StormNodeListStrc* pList, int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2CelEntryStrc) + nExtraBytes, gszTypeNameCelEntry, -2, nFlags | 8);
    D2CelEntryStrc* pEntry = pMemory ? new (pMemory) D2CelEntryStrc : 0;
    if (nLinkType)
        pList->LinkNode(pEntry, nLinkType, 0);
    return pEntry;
}

// 0x00603860
void __stdcall sub_00603860_AddCelListEntry(unsigned int hCelList, void* pSrc, unsigned int nSrcSize, unsigned int dwPixelWidth, unsigned int dwPixelHeight, int nArg6, int nArg7, int nArg8)
{
    D2_ASSERT(dwPixelWidth && dwPixelHeight, 0x229);
    D2_ASSERT(nSrcSize >= dwPixelHeight, 0x22A);
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.sub_00603400_Lock(hCelList, &hLock, 0);
    D2CelEntryStrc* pEntry = sub_F43_NewCelEntry(&pList->tList, 2, 0, 0);
    ++pList->nCount;
    pEntry->nSize = dwPixelWidth * dwPixelHeight;
    pEntry->nArg6 = nArg6;
    pEntry->nWidth = dwPixelWidth;
    pEntry->nHeight = dwPixelHeight;
    pEntry->nArg7 = nArg7;
    pEntry->nArg8 = nArg8;
    const int nRows = pList->dwFlags & 4 ? 3 * dwPixelHeight : dwPixelHeight;
    pEntry->pData = FOG_Alloc(nRows * dwPixelWidth, ".\\SRC\\CelCmp.cpp", 0x239, 0);
    sub_005179B3_ConvertCelPixels(pEntry->pData, pSrc, nRows, nSrcSize, dwPixelWidth, nRows);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x00603B60
void D2StormListEStrc::sub_00603B60_DeleteAll()
{
    char* pNode;
    while ((pNode = m_terminator.Next()) != 0)
    {
        ((D2StormHashChunkStrc*)pNode)->~D2StormHashChunkStrc();
        SMemFree(pNode, gszTypeNameCelHashChunk, -2, 0);
    }
}

// build: symbol ?InternalDelete@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEXPAUD2StormEntry38Strc@@@Z 0x00604150
void D2GameHashTableReuseStrc::InternalDelete(D2StormEntry38Strc* pNode)
{
    pNode->~D2StormEntry38Strc();
    SMemFree(pNode, gszTypeNameCelList, -2, 0);
}

// 0x00604490
D2StormHashChunkStrc* D2StormListEStrc::sub_00604490_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHashChunkStrc) + nExtraBytes, gszTypeNameCelHashChunk, -2, nFlags | 8);
    D2StormHashChunkStrc* pChunk = pMemory ? new (pMemory) D2StormHashChunkStrc : 0;
    if (nLinkType)
        sub_00603FC0_LinkNode((char*)pChunk, nLinkType, 0);
    return pChunk;
}

// build: symbol ?InternalNew@?$TSHashTableReuse@UCELLIST@@VHASHKEY_NONE@@$0A@@@UAEPAUD2StormEntry38Strc@@PAUD2StormSlotListStrc@@II@Z 0x006044F0
D2StormEntry38Strc* D2GameHashTableReuseStrc::InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormEntry38Strc) + nExtraBytes, gszTypeNameCelList, -2, nFlags | 8);
    D2StormEntry38Strc* pNode = pMemory ? new (pMemory) D2StormEntry38Strc : 0;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00604700
inline void D2GameHashTableReuseStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00604760
char* D2GameDataTableStrc::sub_00604760_New(unsigned int nHashVal, const int& tKey, int nExtraBytes, int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (sub_006045B0(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2StormSlotListStrc* pSlotList = &m_slotlistarray.f_8[nSlot];
    D2StormEntry38Strc* pNode = InternalNew(pSlotList, nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->f_0 = nHashVal;
    return (char*)pNode;
}

// 0x00604870
inline void D2GameExportTableSimpleStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00604900
inline void D2GameDataTableStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

#define D2CMP_BITCOUNT_BX(x) ((x) - (((x) >> 1) & 0x77777777) - (((x) >> 2) & 0x33333333) - (((x) >> 3) & 0x11111111))
#define D2CMP_BITCOUNT(x) (((D2CMP_BITCOUNT_BX(x) + (D2CMP_BITCOUNT_BX(x) >> 4)) & 0x0F0F0F0F) % 255)

// 0x00604940
unsigned int __stdcall CelCompressCreate(int nType, unsigned int nDirections, int* pData, int bHasData)
{
    D2_ASSERT(D2CMP_BITCOUNT(nDirections) == 1, 0x1FF);
    D2_ASSERT(nDirections <= 32, 0x200);
    D2_ASSERT(nType < 2, 0x201);
    unsigned int hHandle;
    int hLock;
    D2StormEntry38Strc* pList = (D2StormEntry38Strc*)gCelListTable.sub_006048C0_NewLock(&hHandle, &hLock);
    pList->tList.sub_00602BF0_DeleteAll();
    pList->nType = nType;
    pList->nDirections = nDirections;
    pList->nCount = 0;
    pList->dwFlags = 0;
    if (bHasData)
    {
        pList->dwFlags = 4;
        if (pData)
        {
            pList->nData = *pData;
        }
    }
    gCelListTable.SyncLeaveLock(hLock);
    return hHandle;
}

void sub_F43_EmitDeletes(D2StormSlotLinkStrc* pLink, D2StormSlotListStrc* pSlotList, D2StormEntry38Strc* pList, D2StormHashChunkStrc* pChunk)
{
    delete pLink;
    delete pSlotList;
    delete pList;
    delete pChunk;
}

// build: context sub_F43_EmitTableVtables
void sub_F43_EmitTableVtables(void* pTable, void* pReuse, void* pSimple, void* pSync)
{
    new (pTable) D2GameHashTableStrc(1);
    new (pReuse) D2GameHashTableReuseStrc(1);
    new (pSimple) D2GameExportTableSimpleStrc(1);
    new (pSync) D2GameDataTableStrc(1);
}

typedef D2StormEntry38Strc* (D2GameDataTableStrc::*D2CELTABLEPTRFN)(unsigned int hHandle);
typedef D2StormEntry38Strc* (D2GameDataTableStrc::*D2CELTABLELOCKFN)(unsigned int hHandle, int* pLockHandle, int bForWriting);

void sub_F43_EmitTableMembers(D2CELTABLEPTRFN* ppfnPtr, D2CELTABLELOCKFN* ppfnLock)
{
    *ppfnPtr = &D2GameDataTableStrc::sub_00603250_Ptr;
    *ppfnLock = &D2GameDataTableStrc::sub_00603400_Lock;
}

#include "gen/data/Source/D2CMP/SRC/CelCmp_006022A0.inc"
