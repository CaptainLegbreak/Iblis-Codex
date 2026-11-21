#include "D2GameTypes.h"
#include "D2CmpStormList.h"
// build: context ??_GD2StormSlotListStrc@@QAEPAXI@Z

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

struct D2StormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_006023E0_RawNext(D2StormLinkStrc* pLink);
};

struct D2StormListCStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListCStrc(const D2StormListCStrc& source);
};

struct D2StormListDStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListDStrc(const D2StormListDStrc& source);
};

struct D2StormEntryListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormEntryListStrc(const D2StormEntryListStrc& source);
};

struct D2StormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2StormEntry38Strc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    int unk0x14;
    int dwUnk0x18;
    int dwUnk0x1C;
    int dwUnk0x20;
    int dwUnk0x24;
    int dwUnk0x28;
    D2StormEntryListStrc tList;

    D2StormEntry38Strc(const D2StormEntry38Strc& source);
};

static unsigned int __stdcall STORM_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

struct CELLIST;
struct HCELLIST__;
struct HLOCKEDCELLIST__;
class HASHKEY_NONE;
class CCritSect;
template <class T, class KEY> class TSHashTable;
template <class T, class THANDLE, class TLOCKEDHANDLE, class TSYNC, int CHUNKSIZE> class TSExportTableSync;
template <> class TSHashTable<CELLIST, HASHKEY_NONE>;
typedef TSHashTable<CELLIST, HASHKEY_NONE> D2GameHashTableStrc;
template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0>;
typedef TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> D2GameDataTableStrc;
// build: symbol ??0?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@QAE@XZ 0x00603BD0

template <> class TSHashTable<CELLIST, HASHKEY_NONE>
{
public:
    virtual void sub_006036D0_InternalDelete(D2StormHashNodeStrc* pNode);                                   // 0x006036D0
    virtual void sub_00603610_VirtSlot1();                                                                  // 0x00603610
    virtual void sub_006037B0_VirtSlot2();                                                                  // 0x006037B0
    virtual void sub_00603780_VirtSlot3();                                                                  // 0x00603780
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable();
};

template <> class TSExportTableSync<CELLIST, HCELLIST__*, HLOCKEDCELLIST__*, CCritSect, 0> : public D2GameHashTableStrc
{
public:
    char unk0x28[0x1C];
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;
    D2CriticalSectionStrc f_50;

    void SyncEnterLock(int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&f_50);
        *pLockHandle = 2 * (bForWriting != 0) - 1;
    }
    void SyncLeaveLock(int nLockHandle)
    {
        if (nLockHandle)
            LeaveCriticalSection(&f_50);
    }
    unsigned int sub_00603280_GenerateHandle();                                                             // 0x00603280
    char* sub_00604760_New(unsigned int nHashVal, const int& tKey, int nExtraBytes, int nFlags);            // 0x00604760
    void sub_00601B80_SyncEnterLock(int* pLockHandle, int bForWriting);
    int sub_00601CB0_IsWriteLock(int nLockHandle);
    unsigned int sub_00601D00_SlotIndex(unsigned int nHashVal);
    void sub_006021E0_UnlinkNode(D2StormHashNodeStrc* pNode);
    void sub_00602400_SyncLeaveLock(int nLockHandle);
    void sub_00602620_Delete(D2StormHashNodeStrc* pNode);
    void sub_006027E0_Delete(D2StormHashNodeStrc* pNode);
    void sub_00602A10_DeleteUnlock(D2StormHashNodeStrc* pNode, int nLockHandle);
    char* sub_00604840_NewHandle(unsigned int* pHandle);
    char* sub_006048C0_NewLock(unsigned int* pHandle, int* pLockHandle);
};

// build: symbol ??_7?$TSHashTable@UCELLIST@@VHASHKEY_NONE@@@@6B@ 0x006E5DE8
// 0x00601B80
void D2GameDataTableStrc::sub_00601B80_SyncEnterLock(int* pLockHandle, int bForWriting)
{
    EnterCriticalSection(&f_50);
    *pLockHandle = bForWriting ? 1 : -1;
}

// 0x00601BC0
D2StormLinkStrc* D2StormLinkStrc::sub_00601BC0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00601C30
D2StormLinkStrc* D2StormLinkStrc::sub_00601C30_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00601CB0
int D2GameDataTableStrc::sub_00601CB0_IsWriteLock(int nLockHandle)
{
    return nLockHandle == 1;
}

// 0x00601D00
unsigned int D2GameDataTableStrc::sub_00601D00_SlotIndex(unsigned int nHashVal)
{
    return m_slotmask & nHashVal;
}

// 0x00601D30
D2StormLinkStrc* D2StormLinkStrc::sub_00601D30_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00601E20
unsigned int D2StormSlotArrayStrc::sub_00601E20_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x00601E60
unsigned int __stdcall sub_00601E60_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x006021E0
void D2GameDataTableStrc::sub_006021E0_UnlinkNode(D2StormHashNodeStrc* pNode)
{
    if (pNode->m_linktoslot.m_next)
    {
        pNode->m_linktoslot.Unlink();
        pNode->f_C.Unlink();
    }
}

// 0x00602260
char* D2StormSlotListStrc::sub_00602260_RawNext(char* pNode)
{
    return Link(pNode)->m_next;
}

// 0x006023B0
D2StormListCStrc::D2StormListCStrc(const D2StormListCStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x006023E0
char* D2StormListBStrc::sub_006023E0_RawNext(D2StormLinkStrc* pLink)
{
    return pLink ? pLink->m_next : m_terminator.m_next;
}

// 0x00602400
void D2GameDataTableStrc::sub_00602400_SyncLeaveLock(int nLockHandle)
{
    if (nLockHandle)
        LeaveCriticalSection(&f_50);
}

// 0x00602620
void D2GameDataTableStrc::sub_00602620_Delete(D2StormHashNodeStrc* pNode)
{
    sub_006021E0_UnlinkNode(pNode);
    sub_006036D0_InternalDelete(pNode);
}

// 0x006026E0
void D2StormSlotListStrc::sub_006026E0_ChangeLinkOffset(int nLinkOffset)
{
    if (nLinkOffset != m_linkoffset)
    {
        UnlinkAll();
        m_linkoffset = nLinkOffset;
        InitializeTerminator();
    }
}

// 0x006027E0
void D2GameDataTableStrc::sub_006027E0_Delete(D2StormHashNodeStrc* pNode)
{
    sub_006021E0_UnlinkNode(pNode);
    sub_006036D0_InternalDelete(pNode);
}

// 0x00602980
D2StormListDStrc::D2StormListDStrc(const D2StormListDStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00602A10
void D2GameDataTableStrc::sub_00602A10_DeleteUnlock(D2StormHashNodeStrc* pNode, int nLockHandle)
{
    sub_00602620_Delete(pNode);
    SyncLeaveLock(nLockHandle);
}

// 0x006031F0
void D2StormSlotArrayStrc::sub_006031F0_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00601E20_CalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        sub_00602F10_ReallocData(nCount);
    }
}

// 0x00603300
void D2StormSlotArrayStrc::sub_00603300_SetCount(unsigned int nCount)
{
    if (nCount > f_4)
    {
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_00601E20_CalcChunkSize(nCount);
            sub_00602F10_ReallocData(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = f_4; i < nCount; i++)
            new (&f_8[i]) D2StormSlotListStrc;
    }
    else if (nCount < f_4)
    {
        for (unsigned int i = nCount; i < f_4; i++)
            f_8[i].~D2StormSlotListStrc();
    }
    f_4 = nCount;
}

// 0x00603BD0
D2GameHashTableStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.sub_00603300_SetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
}

// 0x00603EE0
unsigned int D2StormEntryArrayStrc::sub_00603EE0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 8)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 8;
    return 8;
}

// 0x00603F20
unsigned int __stdcall sub_00603F20_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x00603F90
D2StormEntryListStrc::D2StormEntryListStrc(const D2StormEntryListStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x006040B0
D2StormEntry38Strc::D2StormEntry38Strc(const D2StormEntry38Strc& source)
    : dwUnk0x18(source.dwUnk0x18), dwUnk0x1C(source.dwUnk0x1C), dwUnk0x20(source.dwUnk0x20),
      dwUnk0x24(source.dwUnk0x24), dwUnk0x28(source.dwUnk0x28), tList(source.tList)
{
}

// 0x00604350
void D2StormEntryArrayStrc::sub_00604350_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00603EE0_CalcChunkSize(nCount);
            nCount = STORM_RoundUp(nCount, nChunk);
        }
        sub_006041B0_ReallocData(nCount);
    }
}

// 0x00604440
void D2StormEntryArrayStrc::sub_00604440_Grow(unsigned int nCount)
{
    unsigned int nNewCount = f_4 + nCount;
    if (nNewCount > f_0)
        sub_006041B0_ReallocData(nNewCount);
}

// 0x00604840
char* D2GameDataTableStrc::sub_00604840_NewHandle(unsigned int* pHandle)
{
    unsigned int nHandle = sub_00603280_GenerateHandle();
    *pHandle = nHandle;
    return sub_00604760_New(nHandle, f_44, 0, 0);
}

// 0x006048C0
char* D2GameDataTableStrc::sub_006048C0_NewLock(unsigned int* pHandle, int* pLockHandle)
{
    SyncEnterLock(pLockHandle, 1);
    return sub_00604840_NewHandle(pHandle);
}
