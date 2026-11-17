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
