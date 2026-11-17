#include "D2Common.h"

extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);      // 0x00412650

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
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

struct D2StormHashKeyStrIStrc
{
    char* m_str;

// build: symbol ??1D2StormHashKeyStrIStrc@@QAE@XZ 0x0060DD90
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

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    D2StormHashKeyStrIStrc f_14;

    ~D2CommonStringEntryNodeStrc();                                                                         // 0x0060EAE0
};

struct D2CommonStormSlotListAStrc
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

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    ~D2CommonStormSlotArrayAStrc();                                                                         // 0x0060F610
    D2CommonStormSlotListAStrc& operator[](unsigned int nIndex)
    {
        return f_8[nIndex];
    }
    static void operator delete(void* pMemory);
};

struct D2CommonStormHashTableAStrc
{
    explicit D2CommonStormHashTableAStrc(int nEmitTag)
    {
    }
    virtual void sub_0060FFA0_InternalDelete(D2CommonStringEntryNodeStrc* pNode);
    virtual D2CommonStringEntryNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2CommonStormHashTableAStrc();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020
    static void operator delete(void* pMemory);

    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    int sub_00610840(unsigned int nSlot);                                                   // 0x00610840
    D2CommonStringEntryNodeStrc* sub_0060F8B0_Ptr(const char* szKey);                                       // 0x0060F8B0
    D2CommonStringEntryNodeStrc* sub_00610D60_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags);
    D2CommonStringEntryNodeStrc* sub_00610BE0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags);
};

// 0x00610BE0
inline __declspec(noinline) D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::sub_00610BE0_InternalNewNode(unsigned int nHashVal, const D2StormHashKeyStrIStrc& key, unsigned int nExtraBytes, unsigned int nFlags)
{
    unsigned int nSlot = nHashVal & m_slotmask;
    if (sub_00610840(nSlot))
        nSlot = nHashVal & m_slotmask;
    D2CommonStringEntryNodeStrc* pNode = sub_0060FEF0_InternalNew(&m_slotlistarray[nSlot], nExtraBytes, nFlags);
    m_fulllist.LinkNode((char*)pNode, 2, 0);
    pNode->f_0 = nHashVal;
    pNode->f_14 = key;
    return pNode;
}

// 0x00610D60
D2CommonStringEntryNodeStrc* D2CommonStormHashTableAStrc::sub_00610D60_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags)
{
    D2StormHashKeyStrIStrc key = { sub_00414310(szKey) };
    return sub_00610BE0_InternalNewNode(SStrHash(szKey, 0, 0), key, nExtraBytes, nFlags);
}
