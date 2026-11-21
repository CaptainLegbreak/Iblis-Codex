#include "D2Common.h"
#include "D2StormLink.h"

struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonStormNodeStrc;
struct D2StormLinkStrc;
struct D2StormListAStrc;
struct D2StormListArrayStrc;
struct D2StormNamedNodeStrc;
struct D2StormNameKeyStrc;
struct D2StormHashTable0060F1D0Strc;
struct D2StormHashTable0060F590Strc;
struct D2CommonStormSlotArrayAStrc;
struct D2CommonStormSlotArrayBStrc;
struct D2CommonStormHashTableAStrc;
struct D2CommonStormHashTableBStrc;
struct D2CommonIgnoreListStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags) throw(); // 0x00412650


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
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;
};

struct D2StormNamedNodeStrc
{
    unsigned int f_0;
    unsigned char f_4[0x10];
    const char* f_14;
};

struct D2StormNameKeyStrc
{
    char* m_str;

    D2StormNameKeyStrc(const char* szString)
    {
        m_str = sub_00414310(szString);
    }
    // 0x0060DD90
    ~D2StormNameKeyStrc()
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
    }
};

struct D2StormHashTable0060F1D0Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_0060F1D0_Ptr(unsigned int nHashVal, const D2StormNameKeyStrc& tKey);
    char* sub_0060F510_Ptr(const char* szKey);
};

struct D2StormHashTable0060F590Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_0060F590_InternalFind(unsigned int nHashVal, const D2StormNameKeyStrc& tKey);
    char* sub_0060F8B0_Ptr(const char* szKey);
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;
    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
    void sub_00610000_Clear();
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;
    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
    void Clear()
    {
        this->~D2CommonStormSlotArrayBStrc();
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
    }
};

struct D2CommonStormHashTableAStrc
{
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x0060FFA0
    virtual D2CommonStormNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~D2CommonStormHashTableAStrc();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();
    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;
    void sub_0060EB70_InternalClear(int bWarn);                                                             // 0x0060EB70
};

struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x00610690
    virtual D2CommonStormNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~D2CommonStormHashTableBStrc();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();
    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;
    void sub_0060EE60_InternalClear(int bWarn);                                                             // 0x0060EE60
};

typedef unsigned int size_t;

struct D2CommonIgnoreListStrc
{
    D2CommonIgnoreListStrc();                                                                               // 0x00611200

    char unk0x00[0x188];
};

inline void* __cdecl operator new(size_t nSize, void* pWhere) throw();
inline void __cdecl operator delete(void* pMemory, void* pWhere) throw();

// 0x0060F1D0
char* D2StormHashTable0060F1D0Strc::sub_0060F1D0_Ptr(unsigned int nHashVal, const D2StormNameKeyStrc& tKey)
{
    for (char* pNode = m_slotlistarray.f_8[nHashVal & m_slotmask].Head(); (int)pNode > 0; pNode = m_slotlistarray.f_8[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormNamedNodeStrc*)pNode)->f_0 == nHashVal && !SStrCmpI(((D2StormNamedNodeStrc*)pNode)->f_14, tKey.m_str, 0x7FFFFFFF))
        {
            return pNode;
        }
    }
    return 0;
}

// 0x0060F510
char* D2StormHashTable0060F1D0Strc::sub_0060F510_Ptr(const char* szKey)
{
    return sub_0060F1D0_Ptr(SStrHash(szKey, 0, 0), D2StormNameKeyStrc(szKey));
}

// 0x0060F590
char* D2StormHashTable0060F590Strc::sub_0060F590_InternalFind(unsigned int nHashVal, const D2StormNameKeyStrc& tKey)
{
    for (char* pNode = m_slotlistarray.f_8[nHashVal & m_slotmask].Head(); (int)pNode > 0; pNode = m_slotlistarray.f_8[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormNamedNodeStrc*)pNode)->f_0 == nHashVal && !SStrCmpI(((D2StormNamedNodeStrc*)pNode)->f_14, tKey.m_str, 0x7FFFFFFF))
        {
            return pNode;
        }
    }
    return 0;
}

// 0x0060F8B0
char* D2StormHashTable0060F590Strc::sub_0060F8B0_Ptr(const char* szKey)
{
    return sub_0060F590_InternalFind(SStrHash(szKey, 0, 0), D2StormNameKeyStrc(szKey));
}

// 0x00610000
void D2CommonStormSlotArrayAStrc::sub_00610000_Clear()
{
    this->~D2CommonStormSlotArrayAStrc();
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

// 0x00610020
void D2CommonStormHashTableAStrc::sub_00610020_VirtSlot3()
{
    sub_0060EB70_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.sub_00610000_Clear();
}

// 0x006107D0
void D2CommonStormHashTableBStrc::sub_006107D0_VirtSlot3()
{
    sub_0060EE60_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}

inline void* __cdecl operator new(size_t nSize, void* pWhere) throw()
{
    return pWhere;
}

inline void __cdecl operator delete(void* pMemory, void* pWhere) throw()
{
}

D2CommonIgnoreListStrc* gpIgnoreList_0096BC20; // 0x0096BC20

// build: symbol ??3@YAXPAX0@Z 0x0040EB30
// 0x006114E0
void sub_006114E0_CreateIgnoreList()
{
    gpIgnoreList_0096BC20 = new (SMemAlloc(sizeof(D2CommonIgnoreListStrc), ".\\Chat\\Ignorelist.cpp", 0x41, 0))
        D2CommonIgnoreListStrc;
}

// 0x00611560
D2CommonIgnoreListStrc* sub_00611560_GetOrCreateIgnoreList()
{
    if (!gpIgnoreList_0096BC20)
    {
        gpIgnoreList_0096BC20 = new (SMemAlloc(sizeof(D2CommonIgnoreListStrc), ".\\Chat\\Ignorelist.cpp", 0x48, 0))
            D2CommonIgnoreListStrc;
    }
    return gpIgnoreList_0096BC20;
}
