#include "D2CMP.h"
#include "D2GameTypes.h"

struct D2CelListStrc;
struct D2CriticalSectionStrc;
struct D2StormEntryArray604080Strc;
struct D2StormEntryLink604080Strc;
struct D2StormEntryList604080Strc;
struct D2StormEntry604080Strc;
struct D2GameHashTableStrc;
struct D2StormEntryGrowArray604460Strc;
struct D2Storm604460Strc;
struct D2Storm604470Strc;
struct D2StormCritSectStrc;
struct D2GameHashTableReuseViewStrc;
struct D2GameExportTableSimpleViewStrc;
struct D2GameDataTableViewStrc;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2StormHashObjectStrc;
struct D2StormEntry38Strc;
struct D2StormEntryArrayStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct D2StormSlotListStrc;
struct D2StormListEStrc;
struct D2StormListFixedArrayStrc;
struct D2GameHashTableReuseStrc;


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC

struct D2StormEntryArray604080Strc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    D2StormEntryArray604080Strc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2StormEntryLink604080Strc
{
    D2StormEntryLink604080Strc* m_prevlink;
    char* m_next;

    D2StormEntryLink604080Strc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2StormEntryList604080Strc
{
    int m_linkoffset;
    D2StormEntryLink604080Strc m_terminator;

    D2StormEntryList604080Strc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormEntryList604080Strc(const D2StormEntryList604080Strc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2StormEntry604080Strc
{
    unsigned int unk0x00;
    D2StormEntryArray604080Strc tArray;
    unsigned int unk0x14;
    unsigned int nField18;
    unsigned int nField1C;
    unsigned int nField20;
    unsigned int nField24;
    unsigned int nField28;
    D2StormEntryList604080Strc tList;

    D2StormEntry604080Strc()
    {
    }

// build: context D2StormEntry604080Strc
    D2StormEntry604080Strc(const D2StormEntry604080Strc& source) : nField18(source.nField18), nField1C(source.nField1C),
        nField20(source.nField20), nField24(source.nField24), nField28(source.nField28), tList(source.tList)
    {
    }
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    __forceinline ~D2StormSlotListStrc()
    {
        sub_00602640_UnlinkAll();
    }
    void sub_00602640_UnlinkAll();                                                                          // 0x00602640
    void sub_00602D20_DeleteAll();                                                                          // 0x00602D20
};

struct D2StormListFixedArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2StormListFixedArrayStrc();
    void Clear()
    {
        this->~D2StormListFixedArrayStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};

struct D2GameHashTableStrc
{
    const int* f_0;
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListFixedArrayStrc m_slotlistarray;
    unsigned int m_slotmask;
    void sub_00602800_InternalClear(int bWarn);                                                             // 0x00602800
    void sub_00604070_Clear();
    ~D2GameHashTableStrc();                                                                                // 0x00603460
};

struct D2StormEntryGrowArray604460Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry604080Strc* f_8;
    unsigned int f_C;

    D2StormEntry604080Strc* sub_006043B0_New();                                                             // 0x006043B0
};

struct D2Storm604460Strc
{
    D2StormEntryGrowArray604460Strc tArray;

    D2StormEntry604080Strc* sub_00604460_New();
};

struct D2Storm604470Strc
{
    unsigned int nField00;
    unsigned int nField04;
    unsigned int f_8;
    unsigned int nField0C;
    unsigned int nField10;
    unsigned int nField14;

    D2Storm604470Strc();
};

struct D2StormCritSectStrc
{
    D2CriticalSectionStrc f_0;

    ~D2StormCritSectStrc()
    {
        DeleteCriticalSection(&f_0);
    }
};

struct D2GameHashTableReuseViewStrc
{
    char unk0x00[0x44];

    ~D2GameHashTableReuseViewStrc();                                                                        // 0x00604640
};

struct D2GameExportTableSimpleViewStrc : D2GameHashTableReuseViewStrc
{
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    ~D2GameExportTableSimpleViewStrc();
};

struct D2GameDataTableViewStrc : D2GameHashTableReuseViewStrc
{
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;
    D2StormCritSectStrc m_sync;

    ~D2GameDataTableViewStrc();
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormNodeListStrc(const D2StormNodeListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    ~D2StormNodeListStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll();                                                                                       // 0x006025E0
};

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    int f_14;

    D2StormHashObjectStrc()
    {
    }
    ~D2StormHashObjectStrc();                                                                               // 0x00602430
};

struct D2StormEntry38Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;

    D2StormEntry38Strc(const D2StormEntry38Strc& source)
        : dwFlags(source.dwFlags), nType(source.nType), nData(source.nData), nCount(source.nCount),
          nDirections(source.nDirections), tList(source.tList)
    {
    }
};

struct D2StormEntryArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry38Strc* f_8;
    unsigned int f_C;

    void sub_006041B0_ReallocData(unsigned int nAlloc);
};

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    __forceinline ~D2StormListEStrc()
    {
        sub_00602690_UnlinkAll();
    }
    void sub_00602690_UnlinkAll();                                                                          // 0x00602690
    void sub_00603B60_DeleteAll();                                                                          // 0x00603B60
};

extern "C" const int gTSHashTableReuseCelListVtable_006E5DFC[]; // 0x006E5DFC

struct D2GameHashTableReuseStrc : D2GameHashTableStrc
{
    D2StormSlotListStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormListEStrc m_chunkList;
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00604070
void D2GameHashTableStrc::sub_00604070_Clear()
{
    sub_00602800_InternalClear(0);
}

// 0x00604080
void __fastcall sub_00604080_ConstructEntry(D2StormEntry604080Strc* pEntry)
{
    new (pEntry) D2StormEntry604080Strc;
}

// 0x00604100
void __fastcall sub_00604100_CopyConstructEntry(D2StormEntry604080Strc* pEntry, const D2StormEntry604080Strc* pSource)
{
    new (pEntry) D2StormEntry604080Strc(*pSource);
}

// 0x00604460
D2StormEntry604080Strc* D2Storm604460Strc::sub_00604460_New()
{
    return tArray.sub_006043B0_New();
}

// 0x00604470
D2Storm604470Strc::D2Storm604470Strc()
{
    nField00 = 0;
    nField04 = 0;
    f_8 = 0;
    nField0C = 0;
    nField10 = 0;
    nField14 = 0;
}

// 0x00604800
D2GameExportTableSimpleViewStrc::~D2GameExportTableSimpleViewStrc()
{
}

// 0x006048A0
D2GameDataTableViewStrc::~D2GameDataTableViewStrc()
{
}

// 0x006041B0
void D2StormEntryArrayStrc::sub_006041B0_ReallocData(unsigned int nAlloc)
{
    D2StormEntry38Strc* pOldData = f_8;
    for (unsigned int i = nAlloc; i < f_4; ++i)
    {
        pOldData[i].~D2StormEntry38Strc();
    }

    f_0 = nAlloc;
    f_8 = (D2StormEntry38Strc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2StormEntry38Strc), gszTypeNameCelList, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2StormEntry38Strc*)SMemAlloc(nAlloc * sizeof(D2StormEntry38Strc), gszTypeNameCelList, -2, 0);
        if (pOldData)
        {
            const unsigned int nCopy = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCopy; ++i)
            {
                new (&f_8[i]) D2StormEntry38Strc(pOldData[i]);
                pOldData[i].~D2StormEntry38Strc();
            }
            SMemFree(pOldData, gszTypeNameCelList, -2, 0);
        }
    }
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

void __fastcall sub_0051D350_CopyElement(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x006043A0
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &f_8[f_4++];
}

// 0x00604640
void __fastcall sub_00604640_DestroyReuseTable(D2GameHashTableReuseStrc* pTable)
{
    pTable->f_0 = gTSHashTableReuseCelListVtable_006E5DFC;
    pTable->m_chunkList.sub_00603B60_DeleteAll();
    pTable->m_reuseList.sub_00602D20_DeleteAll();
    pTable->m_chunkList.~D2StormListEStrc();
    pTable->m_reuseList.~D2StormSlotListStrc();
    pTable->D2GameHashTableStrc::~D2GameHashTableStrc();
}
