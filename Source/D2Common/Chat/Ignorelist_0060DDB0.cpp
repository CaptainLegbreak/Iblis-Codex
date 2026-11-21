#include "D2Common.h"
#include "D2StormLink.h"

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

struct D2CommonIgnoreListStrc
{
    virtual int sub_00610EB0_Add(const char* szName) = 0;                                                   // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName) = 0;                                                // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName) = 0;                                              // 0x00610380
    virtual void sub_00610F90_VirtSlot3() = 0;                                                              // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;                                           // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5() = 0;                                                              // 0x0060FC40
    virtual void sub_00611320_VirtSlot6() = 0;                                                              // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;                    // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled() = 0;                                                               // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;                                                 // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10() = 0;                                                             // 0x0060F500
    virtual ~D2CommonIgnoreListStrc();
};

extern D2CommonIgnoreListStrc* gpIgnoreList_0096BC20;                                                       // 0x0096BC20

// 0x0060DDB0
void __cdecl sub_0060DDB0()
{
    delete gpIgnoreList_0096BC20;
    gpIgnoreList_0096BC20 = 0;
}


struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
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
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    char* MaskHead()
    {
        return m_terminator.MaskNext();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
    void UnlinkAll();                                                                                       // 0x0060E820
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void UnlinkAll();                                                                                       // 0x0060ECB0
};

// build: context D2CommonStormSlotListAStrc::UnlinkAll
void D2CommonStormSlotListAStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// build: context D2CommonStormSlotListBStrc::UnlinkAll
void D2CommonStormSlotListBStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

struct D2StormHashKeyStrIStrc
{
    char* m_str;

    ~D2StormHashKeyStrIStrc()
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
    }
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    D2StormHashKeyStrIStrc f_14;

    ~D2CommonMappingEntryNodeBaseStrc();                                                                    // 0x0060EA10
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    D2StormHashKeyStrIStrc f_14;

    ~D2CommonStringEntryNodeStrc();                                                                         // 0x0060EAE0
};

// 0x0060EA10
D2CommonMappingEntryNodeBaseStrc::~D2CommonMappingEntryNodeBaseStrc()
{
}

// 0x0060EAE0
D2CommonStringEntryNodeStrc::~D2CommonStringEntryNodeStrc()
{
}

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    D2CommonStormSlotListAStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
};

struct D2CommonStormHashTableAStrc
{
    virtual void sub_0060FFA0_InternalDelete(D2CommonStringEntryNodeStrc* pNode);                           // 0x0060FFA0
    virtual D2CommonStringEntryNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~D2CommonStormHashTableAStrc();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020

    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    D2CommonStringEntryNodeStrc* sub_0060F590_InternalFind(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key);
};

// 0x0060F590
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::sub_0060F590_InternalFind(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key)
{
    for (char* pNode = m_slotlistarray[nHashVal & m_slotmask].MaskHead(); (int)pNode > 0; pNode = m_slotlistarray[nHashVal & m_slotmask].RawNext(pNode))
    {
        D2CommonStringEntryNodeStrc* pEntry = (D2CommonStringEntryNodeStrc*)pNode;
        if (pEntry->f_0 == nHashVal && !SStrCmpI(pEntry->f_14.m_str, key.m_str, 0x7FFFFFFF))
            return pEntry;
    }
    return 0;
}
