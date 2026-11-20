#include "D2Common.h"
#include "D2Drlg.h"

struct D2CommonStormNodeStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonStormSlotListAStrc;
struct D2DrlgActStrc;
struct D2DrlgDeleteStrc;
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
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct D2StormSlotLink0060EDB0Strc;
struct D2StormSlotList0060EDB0Strc;
struct D2StormLinkStrc;
struct D2StormListAStrc;
struct D2StormListArrayStrc;
struct D2StormNamedNodeStrc;
struct D2StormNameKeyStrc;
struct D2StormHashTable0060F1D0Strc;
struct D2CommonStormHashTableBStrc;
struct D2CommonIgnoreListStrc;
struct D2CommonStormSlotArrayAStrc;
struct D2CommonStormSlotArrayAViewStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct D2CommonStormSlotArrayBStrc;
struct D2CommonStormSlotGrowArrayBStrc;
struct D2CommonStormZero6105F0Strc;
struct D2CommonRecord610610Strc;
struct D2ProfileCounterStrc;
struct D2CompCodeTxt;
struct D2ExperienceTxt;
struct D2ExperienceDataTbl;
struct D2RectStrc;
struct Link;
struct Key;
struct Node;
struct List;
struct D2Object00610D30Strc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
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
    bool sub_0060E0C0_IsLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    char* sub_0060E0B0_GetKey();
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayAStrc();
    unsigned int sub_0060E230_Count();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayBStrc();
    unsigned int sub_0060E250_Count();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E260_InitializeTerminator();
    char* sub_0060E440_Head();
    void sub_0060E5F0_Reset();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E270_InitializeTerminator();
    char* sub_0060E5D0_Head();
    void sub_0060E610_Reset();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* sub_0060E6D0_Head();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
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

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListAStrc();
// build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
    void UnlinkAll();
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonMappingEntryNodeBaseStrc();                                                                    // 0x0060EA10
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonStringEntryNodeStrc();                                                                         // 0x0060EAE0
    void sub_0060EE30_Destroy();
};

struct D2CommonStormHashTableAStrc
{
    void sub_0060EB70_InternalClear(int bWarn);                                                             // 0x0060EB70
    void sub_0060ED60_Clear();
};

struct D2StormSlotLink0060EDB0Strc
{
    D2StormSlotLink0060EDB0Strc* m_prevlink;
    char* m_next;

    ~D2StormSlotLink0060EDB0Strc()
    {
        Unlink();
    }
    D2StormSlotLink0060EDB0Strc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLink0060EDB0Strc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLink0060EDB0Strc*)(m_next + nLinkOffset);
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

struct D2StormSlotList0060EDB0Strc
{
    int m_linkoffset;
    D2StormSlotLink0060EDB0Strc m_terminator;

    ~D2StormSlotList0060EDB0Strc();
    void UnlinkAll();                                                                                       // 0x0060E820
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* Next()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
};

struct Link { Link* previous; char* next; Link() { previous=0; next=0; } };

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
};

struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;
};

struct D2StormNamedNodeStrc
{
    unsigned int m_hashval;
    unsigned char unk_04[0x10];
    const char* m_key;
};

struct D2StormNameKeyStrc
{
    const char* m_str;
};

struct D2StormHashTable0060F1D0Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_0060F1D0_Ptr(unsigned int nHashVal, const D2StormNameKeyStrc& tKey);
};

struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x00610690
    virtual D2CommonStormNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~D2CommonStormHashTableBStrc();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0

    char unk0x04[0x24];

    void sub_0060EE60_InternalClear(int bWarn);                                                             // 0x0060EE60
};

struct D2CommonIgnoreListStrc
{
    virtual int sub_00610EB0_Add(const char* szName);                                                       // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName);                                                    // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName);                                                  // 0x00610380
    virtual void sub_00610F90_VirtSlot3();                                                                  // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName);                                               // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5();                                                                  // 0x0060FC40
    virtual void sub_00611320_VirtSlot6();                                                                  // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize);                        // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled();                                                                   // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled);                                                     // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10();
    virtual ~D2CommonIgnoreListStrc();

    char unk0x04[0x50];
    D2CommonStormHashTableBStrc m_table3;
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
};

struct D2CommonStormSlotArrayAViewStrc : D2CommonStormSlotArrayAStrc
{
    ~D2CommonStormSlotArrayAViewStrc();
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

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayBStrc();
};

struct D2CommonStormSlotGrowArrayBStrc : D2CommonStormSlotArrayBStrc
{
    ~D2CommonStormSlotGrowArrayBStrc();
};

struct D2CommonStormZero6105F0Strc
{
    int unk0x00;
    int n0x04;
    int n0x08;
    int n0x0C;
    int n0x10;
    int n0x14;
    D2CommonStormZero6105F0Strc();
};

extern const int gnTileTypeTable_006EEF88[];
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pnCount); // 0x006CC25C

struct D2CommonRecord610610Strc
{
    int unk0x00;
    int f_4;
    int f_8;
    int nFieldC;
    int nField10;
    int nField14;
    int nField18;

    D2CommonRecord610610Strc(int nValue);
};

struct D2ProfileCounterStrc
{
    char szName[0x68];
    __int64 nTotal;
    int nCount;
    int f_74;
};

struct D2CompCodeTxt
{
    unsigned int dwCode;
};

struct D2ExperienceTxt
{
    unsigned int dwClass[7];
    unsigned int dwExpRatio;
};

struct D2ExperienceDataTbl
{
    D2ExperienceTxt tMax;
    D2ExperienceTxt aLevels[1];
};


struct D2DrlgActStrc
{
    char unk0x00[0x10];
    D2ActiveRoomStrc* pRoom;
    char unk0x14[0x44];
    int bHasPendingRoomDeletions;
    void* pMemPool;
};

struct D2DrlgDeleteStrc
{
    int nUnitType;
    int nUnitGUID;
    D2DrlgDeleteStrc* pNext;
};

struct D2RectStrc
{
    int left;
    int top;
    int right;
    int bottom;
};

typedef void(__stdcall* PROFHOOKFN)(int nA, char* pBuffer, int nC);

extern D2ProfileCounterStrc gaProfEntries[23]; // 0x00743800
extern D2CompCodeTxt* gpCompCodeTxt; // 0x0096BCAC
extern int gbCompileTxt; // 0x0096C8B4
void __cdecl LOG_11100(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel); // 0x0066BAC0
void* __stdcall sub_00413020(unsigned,const char*,int,unsigned); // 0x00413020
extern "C" const char mappingName[]; // 0x0074362C

struct Key { char* text; Key() { text=0; } };

struct Node { unsigned hash; Link slot,full; Key key; void* mapped; Node() { mapped=0; } };

struct List {
    void sub_0060E890(char*,int,char*);
    Node* sub_00610630(int,unsigned,unsigned);
};

enum { ALLOC_FLAG = 8 };

struct D2Object00610D30Strc
{
    ~D2Object00610D30Strc(); // 0x00610AA0
    void* sub_00610D30(unsigned int nFlags);
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

inline void* __cdecl operator new(unsigned int size,void* where) throw();

// 0x0060E0C0
bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

// 0x0060E1A0
char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

// 0x0060E240
char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

// 0x0060E3B0
void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

// 0x0060E400
void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

// 0x0060E690
void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

// 0x0060E760
void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

// 0x0060E3F0
D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x0060E5E0
D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x0060E0B0
char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

// 0x0060E200
D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

// 0x0060E230
unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

// 0x0060E220
D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

// 0x0060E250
unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

// 0x0060E260
void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

// 0x0060E440
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

// 0x0060E5F0
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0060E270
void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

// 0x0060E5D0
char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

// 0x0060E610
void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0060E280
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

// 0x0060E360
char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

// 0x0060E6D0
char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

// 0x0060E800
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060E870
D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060EE40
D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0060EC40
D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

// 0x0060EEF0
D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

// 0x0060ED30
D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, ".\\Chat\\Ignorelist.cpp", 0x11, 0);
}

// 0x0060EE30
void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

// 0x0060ED60
void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x0060EDB0
D2StormSlotList0060EDB0Strc::~D2StormSlotList0060EDB0Strc()
{
    UnlinkAll();
}

// 0x0060F1D0
char* D2StormHashTable0060F1D0Strc::sub_0060F1D0_Ptr(unsigned int nHashVal, const D2StormNameKeyStrc& tKey)
{
    for (char* pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].Head(); (int)pNode > 0; pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormNamedNodeStrc*)pNode)->m_hashval == nHashVal && !SStrCmpI(((D2StormNamedNodeStrc*)pNode)->m_key, tKey.m_str, 0x7FFFFFFF))
        {
            return pNode;
        }
    }
    return 0;
}

// 0x0060F500
void D2CommonIgnoreListStrc::sub_0060F500_VirtSlot10()
{
    m_table3.sub_0060EE60_InternalClear(0);
}

// 0x0060F930
D2CommonStormSlotArrayAViewStrc::~D2CommonStormSlotArrayAViewStrc()
{
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

// 0x0060F940
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

D2CommonStormSlotGrowArrayBStrc::~D2CommonStormSlotGrowArrayBStrc()
{
}

// 0x0060FE50
D2CommonStormZero6105F0Strc::D2CommonStormZero6105F0Strc() : n0x04(0), n0x08(0), n0x0C(0), n0x10(0), n0x14(0)
{
}

int __fastcall sub_0066D7E0_MapTileType(int nId)
{
    return gnTileTypeTable_006EEF88[nId];
}

void __fastcall sub_0066D800_TileToClientCoords(int* pX, int* pY)
{
    *pY += 1;
    DUNGEON_GameTileToClientCoords(pX, pY);
    *pY += 0x28;
}

PROFHOOKFN gpfnProfHook; // 0x0096BC28

int gnCompCodeTxtRecordCount; // 0x0096BCB4

D2ExperienceDataTbl* gpExperienceTxt; // 0x0096C8A8

// 0x00610610
D2CommonRecord610610Strc::D2CommonRecord610610Strc(int nValue)
    : f_4(0), f_8(0), nFieldC(0), nField10(0), nField14(0), nField18(nValue)
{
}

// 0x00611620
void __fastcall sub_00611620_ClearAndCallHook(int nA, char* pBuffer, int nC)
{
    PROFHOOKFN pfnHook = gpfnProfHook;
    *pBuffer = 0;
    if (pfnHook)
        pfnHook(nA, pBuffer, nC);
}

// 0x00611660
void __fastcall sub_00611660_AddSample(int nIndex, __int64 nStart)
{
    __int64 nNow;
    QueryPerformanceCounter(&nNow);
    gaProfEntries[nIndex].nTotal += nNow - nStart;
    gaProfEntries[nIndex].nCount++;
}

// 0x006116B0
void __cdecl sub_006116B0_WriteProfileCounters()
{
    __int64 nFrequency;
    QueryPerformanceFrequency(&nFrequency);
    LOG_11100(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x4E, "PROFILING DUMP FREQUENCY %d:\n", nFrequency);
    for (int i = 0; i < 23; i++)
        LOG_11100(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x54, "FUNCTION: %30s, TIME %12d, COUNT %5d", gaProfEntries[i].szName,
            (int)gaProfEntries[i].nTotal, gaProfEntries[i].nCount);
}

// 0x006117D0
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode)
{
    if (nCompCode >= gnCompCodeTxtRecordCount)
        return 0;
    return gpCompCodeTxt[nCompCode].dwCode;
}

// 0x00611800
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel)
{
    if (nClass < 0 || nClass >= 7)
        nClass = 0;
    return gpExperienceTxt->aLevels[dwLevel].dwClass[nClass];
}

// 0x00611830
int __stdcall DATATBLS_GetMaxLevel(int nClass)
{
    if (nClass < 0 || nClass >= 7)
        nClass = 0;
    return gpExperienceTxt->tMax.dwClass[nClass];
}

// 0x006125A0
void __stdcall DATATBLS_ToggleCompileTxtFlag(int bSilent)
{
    gbCompileTxt = !bSilent;
}

// 0x006125C0
void __stdcall DATATBLS_UnloadBin(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00613E60
unsigned int __stdcall DATATBLS_GetExpRatio(int nLevel)
{
    if (!gpExperienceTxt)
        return 0;
    if (nLevel <= 0)
        return gpExperienceTxt->tMax.dwExpRatio;
    if (nLevel > (int)gpExperienceTxt->tMax.dwClass[0])
        return 0;
    return gpExperienceTxt->aLevels[nLevel].dwExpRatio;
}

// 0x00619B10
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomByTileCoordinates(D2DrlgActStrc* pAct, int nX, int nY)
{
    for (D2ActiveRoomStrc* pRoom = pAct->pRoom; pRoom; pRoom = pRoom->pRoomNext)
    {
        if (nX >= pRoom->tCoords.nTileXPos && nX < pRoom->tCoords.nTileXPos + pRoom->tCoords.nTileWidth && nY >= pRoom->tCoords.nTileYPos
            && nY < pRoom->tCoords.nTileYPos + pRoom->tCoords.nTileHeight)
            return pRoom;
    }
    return 0;
}

// 0x00619D00
void __stdcall DUNGEON_GetSubtileRect(D2ActiveRoomStrc* pRoom, D2RectStrc* pRect)
{
    D2_ASSERT(pRoom, 0x1E3);
    pRect->top = pRoom->tCoords.nSubtileY;
    pRect->bottom = pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight;
    pRect->left = pRoom->tCoords.nSubtileX;
    pRect->right = pRoom->tCoords.nSubtileWidth + pRoom->tCoords.nSubtileX;
    D2_ASSERT(pRect->top <= pRect->bottom, 0x1EB);
    D2_ASSERT(pRect->left <= pRect->right, 0x1EC);
}

// 0x00619F20
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        D2_ASSERT(pRoom->nAllies > 0, 0x27C);
        --pRoom->nAllies;
    }
}

// 0x0061A1D0
int __stdcall DUNGEON_GetWarpDestinationLevel(D2ActiveRoomStrc* pRoom, int nSourceLevel)
{
    if (!pRoom)
        return 0;
    return DRLGROOM_GetWarpDestinationLevel(pRoom->pDrlgRoom, nSourceLevel);
}

// 0x0061A270
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID)
{
    if (pRoom)
    {
        D2DrlgDeleteStrc* pDrlgDelete = (D2DrlgDeleteStrc*)FOG_AllocPool(pRoom->pAct->pMemPool, sizeof(D2DrlgDeleteStrc),
            ".\\DUNGEON\\Dungeon.cpp", 0x384, 0);
        pDrlgDelete->nUnitType = nUnitType;
        pDrlgDelete->nUnitGUID = nUnitGUID;
        pDrlgDelete->pNext = pRoom->pDrlgDelete;
        pRoom->pDrlgDelete = pDrlgDelete;
        pRoom->pAct->bHasPendingRoomDeletions = 1;
    }
}

#include "gen/data/Source/D2Common/Chat/Ignorelist.inc"

inline void* __cdecl operator new(unsigned int size,void* where) throw() { return where; }

// build: symbol ?sub_0060E890@List@@QAEXPADH0@Z 0x0060E890
// 0x00610630
Node* List::sub_00610630(int linkType,unsigned extra,unsigned flags)
{
    void* memory=sub_00413020(sizeof(Node)+extra,mappingName,-2,flags|ALLOC_FLAG);
    Node* node=new(memory) Node;
    if(linkType) sub_0060E890((char*)node,linkType,0);
    return node;
}

// 0x00610D30
void* D2Object00610D30Strc::sub_00610D30(unsigned int nFlags)
{
    this->~D2Object00610D30Strc();
    if (nFlags & 1)
        operator delete(this);
    return this;
}
