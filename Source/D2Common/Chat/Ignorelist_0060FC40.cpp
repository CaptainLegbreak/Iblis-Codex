struct D2StormLinkStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormHashNodeStrc;
struct D2CommonIgnoreAliasNodeStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotArrayAStrc;
struct D2CommonStormHashTableAStrc;
struct D2CommonChatIgnoreListStrc;
struct D2CommonIgnoreListStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonStormSlotArrayBStrc;
struct D2CommonStormHashTableBStrc;

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
char* __stdcall sub_00414200_StrLower(char* szString); // 0x00414200

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;
    D2CommonStormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2CommonStormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2CommonIgnoreAliasNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    const char* f_14;
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;
};

struct D2CommonStormHashTableAStrc
{
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormHashNodeStrc* pNode);                             // 0x0060FFA0
    virtual void sub_0060FEF0_VirtSlot1();                                                                  // 0x0060FEF0
    virtual void sub_00610050_VirtSlot2();                                                                  // 0x00610050
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020
    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0060E6E0_UnlinkNode(D2CommonStormHashNodeStrc* pNode);                                         // 0x0060E6E0
    char* sub_0060EAA0_Next(char* pNode);                                                                   // 0x0060EAA0
    D2CommonStormHashNodeStrc* sub_0060F8B0_Ptr(const char* szKey);
};

struct D2CommonChatIgnoreListStrc
{
    virtual int sub_00610EB0_Add(const char* szName) = 0;                                                   // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName) = 0;                                                // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName) = 0;                                              // 0x00610380
    virtual void sub_00610F90_VirtSlot3() = 0;                                                              // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;                                           // 0x0060FBE0
    virtual int sub_0060FC40_VirtSlot5(const char* szName) = 0;
    virtual void sub_00611320_VirtSlot6() = 0;                                                              // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;                    // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled() = 0;                                                               // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;                                                 // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10() = 0;                                                             // 0x0060F500
    virtual ~D2CommonChatIgnoreListStrc()
    {
    }
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2;
    char unk0x54[0x2C];
    char szFileName[0x104];
    int m_bEnabled;

    int sub_0060FC40_VirtSlot5(const char* szName);
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListBStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListBStrc()
    {
        UnlinkAll();
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    char* Next(char* pNode)
    {
        return Link(pNode)->Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2CommonStormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2CommonStormSlotLinkStrc* pExistingLink = Link(pExistingNode);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            D2CommonStormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void UnlinkAll();                                                                                       // 0x0060ECB0
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    D2CommonStormSlotArrayBStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    void sub_006100B0_SetCount(unsigned int nCount);                                                        // 0x006100B0
};

struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonStormHashNodeStrc* pNode);                             // 0x00610690
    virtual void sub_006106D0_VirtSlot1();                                                                  // 0x006106D0
    virtual void sub_00610800_VirtSlot2();                                                                  // 0x00610800
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0
    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    void InternalLinkNode(D2CommonStormHashNodeStrc* pNode, unsigned int nHashVal)
    {
        m_slotlistarray.f_8[nHashVal & m_slotmask].LinkNode((char*)pNode, 2, 0);
    }
    void sub_006108D0_GrowListArray();
};


// 0x0060FC40
int D2CommonIgnoreListStrc::sub_0060FC40_VirtSlot5(const char* szName)
{
    if (szName && *szName && sub_0060DDF0_IsEnabled())
    {
        if (m_table2.sub_0060F8B0_Ptr(szName))
            return 1;
        char szLower[0x100];
        char szKey[0x100];
        SStrCopy(szLower, szName, 0x7FFFFFFF);
        sub_00414200_StrLower(szLower);
        for (char* pNode = (char*)((((int)m_table2.m_fulllist.m_terminator.m_next <= 0) - 1) & (int)m_table2.m_fulllist.m_terminator.m_next);
             (int)pNode > 0; pNode = m_table2.sub_0060EAA0_Next(pNode))
        {
            SStrCopy(szKey, ((D2CommonIgnoreAliasNodeStrc*)pNode)->f_14, 0x7FFFFFFF);
            sub_00414200_StrLower(szKey);
            if (strstr(szLower, szKey))
                return 1;
        }
        return 0;
    }
    return 0;
}

// 0x006108D0
void D2CommonStormHashTableBStrc::sub_006108D0_GrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = nOldCount * 2;
    D2CommonStormSlotListBStrc tTemp;
    tTemp.ChangeLinkOffset(4);
    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.f_8[i].Head()) != 0)
            tTemp.LinkNode(pNode, 2, 0);
    }
    m_slotlistarray.sub_006100B0_SetCount(nNewCount);
    for (unsigned int j = 0; j < nNewCount; j++)
        m_slotlistarray.f_8[j].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;
    D2CommonStormHashNodeStrc* pNode;
    while ((pNode = (D2CommonStormHashNodeStrc*)tTemp.Head()) != 0)
        InternalLinkNode(pNode, pNode->f_0);
}
