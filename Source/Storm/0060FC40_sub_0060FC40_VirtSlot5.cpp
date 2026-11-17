extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
char* __stdcall sub_00414200_StrLower(char* szString);                                                      // 0x00414200

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
