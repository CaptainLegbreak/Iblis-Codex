#include "D2Common.h"
#include "D2StormLink.h"

extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);      // 0x00412650


struct D2StormHashKeyStrIStrc
{
    char* m_str;

    D2StormHashKeyStrIStrc(const char* szString)
    {
        m_str = sub_00414310(szString);
    }
    // 0x0060DD90
    ~D2StormHashKeyStrIStrc()
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
    }
    D2StormHashKeyStrIStrc& operator=(const D2StormHashKeyStrIStrc& source)
    {
        if (m_str)
            SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
        m_str = sub_00414310(source.m_str);
        return *this;
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

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc()
    {
        if (pMapped)
            SMemFree(pMapped, ".\\Chat\\Ignorelist.cpp", 0x11, 0);
    }
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
    D2CommonStormSlotListBStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
};

struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonMappingEntryNodeStrc* pNode);
    virtual D2CommonMappingEntryNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2CommonStormHashTableBStrc();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0

    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    int sub_00610CA0(unsigned int nSlot);                                                   // 0x00610CA0
    D2CommonMappingEntryNodeStrc* sub_00610DF0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags);
    D2CommonMappingEntryNodeStrc* sub_00611170_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags);
};

// 0x00610DF0
inline __declspec(noinline) D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::sub_00610DF0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (sub_00610CA0(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2CommonMappingEntryNodeStrc* pNode = sub_006106D0_InternalNew(&m_slotlistarray[nSlot], nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->f_0 = nHashVal;
    pNode->f_14 = key;
    return pNode;
}

// 0x00611170
D2CommonMappingEntryNodeStrc* D2CommonStormHashTableBStrc::sub_00611170_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags)
{
    D2StormHashKeyStrIStrc key(szKey);
    return sub_00610DF0_InternalNewNode(SStrHash(szKey, 0, 0), key, nExtraBytes, nFlags);
}
