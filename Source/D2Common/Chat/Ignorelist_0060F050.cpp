#define D2_STORM_UNLINK_TERMINATOR(pThis)                                                                   \
    if ((pThis)->m_prevlink)                                                                                \
    {                                                                                                       \
        D2CommonStormPlainLinkStrc* pNext;                                                                  \
        if ((int)(pThis)->m_next < 0)                                                                       \
        {                                                                                                   \
            pNext = (D2CommonStormPlainLinkStrc*)~(unsigned int)(pThis)->m_next;                           \
        }                                                                                                   \
        else                                                                                                \
        {                                                                                                   \
            int nLinkOffset = -1;                                                                           \
            if (nLinkOffset < 0)                                                                            \
            {                                                                                               \
                nLinkOffset = (char*)(pThis) - (pThis)->m_prevlink->m_next;                                 \
            }                                                                                               \
            pNext = (D2CommonStormPlainLinkStrc*)((pThis)->m_next + nLinkOffset);                          \
        }                                                                                                   \
        pNext->m_prevlink = (pThis)->m_prevlink;                                                            \
        (pThis)->m_prevlink->m_next = (pThis)->m_next;                                                      \
        (pThis)->m_prevlink = 0;                                                                            \
        (pThis)->m_next = 0;                                                                                \
    }

struct D2CommonStormPlainLinkStrc;
struct D2CommonStormListGStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonStormHashTableBStrc;
struct D2CommonStormSlotListCStrc;
struct D2CommonStormSlotListDStrc;
struct D2CommonStormSlotListEStrc;
struct D2CommonStormZeroAStrc;
struct D2CommonStormZeroBStrc;
struct D2StormLinkStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormHashNodeStrc;
struct D2CommonStormSlotArrayAStrc;
struct D2CommonStormHashTableAStrc;
struct D2CommonChatIgnoreListStrc;
struct D2CommonIgnoreListStrc;

struct D2CommonStormPlainLinkStrc
{
    D2CommonStormPlainLinkStrc* m_prevlink;
    char* m_next;
};

struct D2CommonStormListGStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;
    // build: symbol ?UnlinkAll@D2CommonStormSlotListAStrc@@QAEXXZ 0x0060E820
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

// build: symbol ?UnlinkAll@D2CommonStormSlotListBStrc@@QAEXXZ 0x0060ECB0
    void UnlinkAll();
};

struct D2CommonStormHashTableBStrc
{
    void sub_0060EE60_InternalClear(int bWarn);                                                             // 0x0060EE60
    void sub_0060F150_Clear();
};

struct D2CommonStormSlotListCStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

    ~D2CommonStormSlotListCStrc();
};

struct D2CommonStormSlotListDStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

    ~D2CommonStormSlotListDStrc();
};

struct D2CommonStormSlotListEStrc
{
    int m_linkoffset;
    D2CommonStormPlainLinkStrc m_terminator;

    ~D2CommonStormSlotListEStrc();
};

struct D2CommonStormZeroAStrc
{
    int m_value;

    D2CommonStormZeroAStrc();
};

struct D2CommonStormZeroBStrc
{
    int m_value;

    D2CommonStormZeroBStrc();
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
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;
};

struct D2CommonStormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
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
    D2CommonStormHashNodeStrc* sub_0060F8B0_Ptr(const char* szKey);                                         // 0x0060F8B0
};

struct D2CommonChatIgnoreListStrc
{
    D2CommonChatIgnoreListStrc(int nEmitTag);
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
    virtual ~D2CommonChatIgnoreListStrc()
    {
    }
    static void operator delete(void* pMemory);
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2;
    char unk0x54[0x2C];
    char szFileName[0x104];
    int m_bEnabled;

    int sub_0060FB20_Remove(const char* szName);
    int sub_0060FBE0_RemoveAlias(const char* szName);
    void sub_0060DE00_SetEnabled(int bEnabled);
    void sub_0060DFF0_NormalizeKey(const char* szName, char* szOut, int nSize);                             // 0x0060DFF0
    int sub_0060F0A0_Save();                                                                                // 0x0060F0A0
    int sub_0060FD50_Contains(const char* szKey);
};


// 0x0060F050
void __fastcall sub_0060F050_ConstructList(D2CommonStormListGStrc* pList, const D2CommonStormListGStrc* pSource)
{
    if (pList)
    {
        D2CommonStormPlainLinkStrc* pLink = &pList->m_terminator;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
        pList->m_linkoffset = pSource->m_linkoffset;
        pList->m_terminator.m_prevlink = &pList->m_terminator;
        pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
    }
}

// 0x0060F150
void D2CommonStormHashTableBStrc::sub_0060F150_Clear()
{
    sub_0060EE60_InternalClear(0);
}

// 0x0060F190
D2CommonStormSlotListCStrc::~D2CommonStormSlotListCStrc()
{
    ((D2CommonStormSlotListBStrc*)this)->UnlinkAll();
    D2CommonStormPlainLinkStrc* pThis = &m_terminator;
    D2_STORM_UNLINK_TERMINATOR(pThis)
}

// 0x0060F2C0
D2CommonStormSlotListDStrc::~D2CommonStormSlotListDStrc()
{
    ((D2CommonStormSlotListAStrc*)this)->UnlinkAll();
    D2CommonStormPlainLinkStrc* pThis = &m_terminator;
    D2_STORM_UNLINK_TERMINATOR(pThis)
}

// 0x0060F4E0
void __fastcall sub_0060F4E0_ConstructList(D2CommonStormListGStrc* pList, const D2CommonStormListGStrc* pSource)
{
    if (pList)
    {
        D2CommonStormPlainLinkStrc* pLink = &pList->m_terminator;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
        pList->m_linkoffset = pSource->m_linkoffset;
        pList->m_terminator.m_prevlink = &pList->m_terminator;
        pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
    }
}

// 0x0060F690
D2CommonStormSlotListEStrc::~D2CommonStormSlotListEStrc()
{
    ((D2CommonStormSlotListBStrc*)this)->UnlinkAll();
    D2CommonStormPlainLinkStrc* pThis = &m_terminator;
    D2_STORM_UNLINK_TERMINATOR(pThis)
}

// 0x0060FE30
D2CommonStormZeroAStrc::D2CommonStormZeroAStrc()
{
    m_value = 0;
}

// 0x0060FE40
D2CommonStormZeroBStrc::D2CommonStormZeroBStrc()
{
    m_value = 0;
}

// 0x0060FBE0
int D2CommonIgnoreListStrc::sub_0060FBE0_RemoveAlias(const char* szName)
{
    if (szName && *szName && sub_0060DDF0_IsEnabled())
    {
        D2CommonStormHashNodeStrc* pNode = m_table2.sub_0060F8B0_Ptr(szName);
        if (pNode)
        {
            m_table2.sub_0060E6E0_UnlinkNode(pNode);
            sub_0060F0A0_Save();
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
