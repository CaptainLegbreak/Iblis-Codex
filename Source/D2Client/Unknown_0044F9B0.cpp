#include "D2Client.h"

struct D2StormSlotListStrc;
struct D2StormEntry38Strc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct D2StormLinkStrc;
struct D2SGameDataStrc;
struct D2StormListAStrc;
struct D2StormListArrayStrc;
struct D2StormHashTableStrc;
struct D2StormHashTableReuseStrc;
struct D2StormGameDataArrayStrc;
struct D2StormHashObjectChunkStrc;
struct D2StormChunkListStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct D2StormSlotLinkStrc;
struct D2StormListStrc;
struct D2StormListEStrc;
struct D2StormSlotArrayStrc;
struct D2StormEntryArrayStrc;
struct D2StormSlotGrowArrayStrc;
struct D2StormEntryGrowArrayStrc;
struct D2StormHashChunkStrc;
struct D2Storm603530ArrayStrc;
struct D2Storm603530Strc;
struct D2Storm603570ArrayStrc;
struct D2Storm603570LinkStrc;
struct D2Storm603570ListStrc;
struct D2Storm603570Strc;
struct D2GameHashTableReuseStrc;
struct D2Storm603ED0Strc;
struct D2Storm603F70Strc;
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

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
extern const char gszTypeHashObjectChunk_0070F5F4[]; // 0x0070F5F4

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

struct D2SGameDataStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    char unk0x14[0x1DE0];

    D2SGameDataStrc()
    {
    }
    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc(const D2StormListAStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    D2SGameDataStrc* HeadNode()
    {
        return (int)m_terminator.m_next > 0 ? (D2SGameDataStrc*)m_terminator.m_next : 0;
    }
    // build: context D2StormListAStrc::LinkNode
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        if (pLink->m_prevlink)
            pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExisting);
        if (nLinkType == 1)
        {
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
        }
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044FC60_DeleteAll();
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    void sub_0044FE10_ReallocData(unsigned int nAlloc);
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;
};

struct D2StormHashTableReuseStrc : D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormGameDataArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2SGameDataStrc* f_8;
    unsigned int f_C;
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameDataArrayStrc m_array;
    D2StormLinkStrc f_10;
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormHashObjectChunkStrc* HeadChunk()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormHashObjectChunkStrc*)m_terminator.m_next : 0;
    }
    void sub_00450580_DeleteAll();
};

extern "C" const char gszTypeNewsTableItem_0072FF8C[];

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2StormListEStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00602D20_DeleteAll();
    void sub_00603B60_DeleteAll();
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;

    ~D2StormSlotArrayStrc();
    void sub_00603760_Clear();
};

struct D2StormEntryArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry38Strc* f_8;
    unsigned int f_C;

    ~D2StormEntryArrayStrc();
};

struct D2StormSlotGrowArrayStrc
{
    D2StormSlotArrayStrc tArray;

    ~D2StormSlotGrowArrayStrc();
};

struct D2StormEntryGrowArrayStrc
{
    D2StormEntryArrayStrc tArray;

    ~D2StormEntryGrowArrayStrc();
};

struct D2StormHashChunkStrc
{
    D2StormEntryArrayStrc tArray;
    D2StormSlotLinkStrc f_10;

    ~D2StormHashChunkStrc();
};

struct D2Storm603530ArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;
};

struct D2Storm603530Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603530Strc();
};

struct D2Storm603570ArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    D2Storm603570ArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2Storm603570LinkStrc
{
    D2Storm603570LinkStrc* m_prevlink;
    char* m_next;

    D2Storm603570LinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2Storm603570ListStrc
{
    int m_linkoffset;
    D2Storm603570LinkStrc m_terminator;

    D2Storm603570ListStrc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2Storm603570Strc
{
    unsigned int unk0x00;
    D2Storm603570ArrayStrc tArray;
    char unk0x14[0x18];
    D2Storm603570ListStrc tList;

    D2Storm603570Strc();
};

struct D2GameHashTableReuseStrc
{
    char unk0x00[0x28];
    D2StormListEStrc m_reuseList;
    int unk0x34;
    D2StormListEStrc m_chunkList;

    void sub_00603E50_DeleteLists();
};

struct D2Storm603ED0Strc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00603ED0_GetDifference();
};

struct D2Storm603F70Strc
{
    unsigned int unk0x00;
    D2Storm603530ArrayStrc tArray;

    D2Storm603F70Strc(int nUnused);
};

struct D2CriticalSectionStrc
{
    void* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned int SpinCount;
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection);

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
    D2StormEntry604080Strc(const D2StormEntry604080Strc& source) : nField18(source.nField18), nField1C(source.nField1C),
        nField20(source.nField20), nField24(source.nField24), nField28(source.nField28), tList(source.tList)
    {
    }
};

struct D2GameHashTableStrc
{
    void sub_00602800_InternalClear(int bWarn);
    void sub_00604070_Clear();
};

struct D2StormEntryGrowArray604460Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry604080Strc* f_8;
    unsigned int f_C;

    D2StormEntry604080Strc* sub_006043B0_New();
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

    ~D2GameHashTableReuseViewStrc();
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

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

// 0x0044F9B0
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x0044FB10
D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x0044FC60
void D2StormListAStrc::sub_0044FC60_DeleteAll()
{
    D2SGameDataStrc* pNode;
    while ((pNode = HeadNode()) != 0)
    {
        pNode->f_C.Unlink();
        pNode->m_linktoslot.Unlink();
        SMemFree(pNode, gszTypeSGameData_0070F56C, -2, 0);
    }
}

// 0x0044FE10
void D2StormListArrayStrc::sub_0044FE10_ReallocData(unsigned int nAlloc)
{
    D2StormListAStrc* pOld = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOld[i].~D2StormListAStrc();
    f_0 = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2StormListAStrc), gszTypeExplicitList_0070F584, -2, 0x10);
    f_8 = (D2StormListAStrc*)pNew;
    if (!pNew)
    {
        f_8 = (D2StormListAStrc*)SMemAlloc(nAlloc * sizeof(D2StormListAStrc), gszTypeExplicitList_0070F584, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= f_4 ? f_4 : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&f_8[i]) D2StormListAStrc(pOld[i]);
                pOld[i].~D2StormListAStrc();
            }
            SMemFree(pOld, gszTypeExplicitList_0070F584, -2, 0);
        }
    }
}

// build: symbol ?InternalDelete@D2StormHashTableStrc@@UAEXPAUD2SGameDataStrc@@@Z 0x004503F0
void D2StormHashTableStrc::InternalDelete(D2SGameDataStrc* pNode)
{
    pNode->~D2SGameDataStrc();
    SMemFree(pNode, gszTypeSGameData_0070F56C, -2, 0);
}

// build: symbol ?InternalNew@D2StormHashTableStrc@@UAEPAUD2SGameDataStrc@@PAUD2StormListAStrc@@II@Z 0x00450420
D2SGameDataStrc* D2StormHashTableStrc::InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, gszTypeSGameData_0070F56C, -2, nFlags | 8);
    D2SGameDataStrc* pNode = new (pMemory) D2SGameDataStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

// 0x00450580
void D2StormChunkListStrc::sub_00450580_DeleteAll()
{
    D2StormHashObjectChunkStrc* pChunk;
    while ((pChunk = HeadChunk()) != 0)
    {
        pChunk->f_10.Unlink();
        for (unsigned int i = 0; i < pChunk->m_array.f_4; i++)
        {
            D2SGameDataStrc* pNode = &pChunk->m_array.f_8[i];
            pNode->f_C.Unlink();
            pNode->m_linktoslot.Unlink();
        }
        if (pChunk->m_array.f_8)
            SMemFree(pChunk->m_array.f_8, gszTypeSGameData_0070F56C, -2, 0);
        SMemFree(pChunk, gszTypeHashObjectChunk_0070F5F4, -2, 0);
    }
}

// build: symbol ?InternalDelete@D2StormHashTableReuseStrc@@UAEXPAUD2SGameDataStrc@@@Z 0x00450D60
void D2StormHashTableReuseStrc::InternalDelete(D2SGameDataStrc* pNode)
{
    pNode->~D2SGameDataStrc();
    SMemFree(pNode, gszTypeSGameData_0070F56C, -2, 0);
}

// build: symbol ?InternalNew@D2StormHashTableReuseStrc@@UAEPAUD2SGameDataStrc@@PAUD2StormListAStrc@@II@Z 0x00451000
D2SGameDataStrc* D2StormHashTableReuseStrc::InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2SGameDataStrc) + nExtraBytes, gszTypeSGameData_0070F56C, -2, nFlags | 8);
    D2SGameDataStrc* pNode = new (pMemory) D2SGameDataStrc;
    pList->LinkNode((char*)pNode, 1, 0);
    return pNode;
}

#include "gen/data/Source/D2Client/Unknown_0044F9B0.inc"

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

// 0x00450030
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

D2StormSlotGrowArrayStrc::~D2StormSlotGrowArrayStrc()
{
}

D2StormEntryGrowArrayStrc::~D2StormEntryGrowArrayStrc()
{
}

D2StormHashChunkStrc::~D2StormHashChunkStrc()
{
    f_10.Unlink();
}

void __fastcall sub_00603500_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00450350
D2Storm603530Strc::D2Storm603530Strc()
{
    tArray.f_0 = 0;
    tArray.f_4 = 0;
    tArray.f_8 = 0;
    tArray.f_C = 0;
}

D2Storm603570Strc::D2Storm603570Strc()
{
}

void D2StormSlotArrayStrc::sub_00603760_Clear()
{
    this->D2StormSlotArrayStrc::~D2StormSlotArrayStrc();
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

void D2GameHashTableReuseStrc::sub_00603E50_DeleteLists()
{
    m_chunkList.sub_00603B60_DeleteAll();
    m_reuseList.sub_00602D20_DeleteAll();
}

// 0x00450800
unsigned int D2Storm603ED0Strc::sub_00603ED0_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00450880
D2Storm603F70Strc::D2Storm603F70Strc(int nUnused)
{
    tArray.f_0 = 0;
    tArray.f_4 = 0;
    tArray.f_8 = 0;
    tArray.f_C = 0;
}

void D2GameHashTableStrc::sub_00604070_Clear()
{
    sub_00602800_InternalClear(0);
}

void __fastcall sub_00604080_ConstructEntry(D2StormEntry604080Strc* pEntry)
{
    new (pEntry) D2StormEntry604080Strc;
}

void __fastcall sub_00604100_CopyConstructEntry(D2StormEntry604080Strc* pEntry, const D2StormEntry604080Strc* pSource)
{
    new (pEntry) D2StormEntry604080Strc(*pSource);
}

D2StormEntry604080Strc* D2Storm604460Strc::sub_00604460_New()
{
    return tArray.sub_006043B0_New();
}

// 0x00450F80
D2Storm604470Strc::D2Storm604470Strc()
{
    nField00 = 0;
    nField04 = 0;
    f_8 = 0;
    nField0C = 0;
    nField10 = 0;
    nField14 = 0;
}

D2GameExportTableSimpleViewStrc::~D2GameExportTableSimpleViewStrc()
{
}

D2GameDataTableViewStrc::~D2GameDataTableViewStrc()
{
}
