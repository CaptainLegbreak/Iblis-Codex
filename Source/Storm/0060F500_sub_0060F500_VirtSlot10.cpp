struct D2CommonStormNodeStrc;
struct D2CommonStormSlotListBStrc;

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

// 0x0060F500
void D2CommonIgnoreListStrc::sub_0060F500_VirtSlot10()
{
    m_table3.sub_0060EE60_InternalClear(0);
}
