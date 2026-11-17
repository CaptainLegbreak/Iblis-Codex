struct D2CommonChatIgnoreListStrc
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
};
struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
};

D2CommonIgnoreListStrc* sub_00611560_GetOrCreateIgnoreList();                                               // 0x00611560
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_00520BF0_IsReplyReceived(unsigned char nReply);                                          // 0x00520BF0
extern "C" int __fastcall sub_00520C20_GetSlotB(unsigned char nSlot);                                       // 0x00520C20

// 0x0051B1B0
int __cdecl sub_0051B1B0_SendStopAdv()
{
    sub_0051C5C0_SendPacket(2, 0, 0);
    return 1;
}

// 0x0051B1D0
int __cdecl sub_0051B1D0_LeaveGame()
{
    sub_00611560_GetOrCreateIgnoreList()->sub_0060F500_VirtSlot10();
    sub_0051C5C0_SendPacket(0x1F, 0, 0);
    return 1;
}

// 0x0051B1F0
int __fastcall sub_0051B1F0_GetStartAdvResult(int* pValue)
{
    *pValue = sub_00520C20_GetSlotB(0x1C);
    return sub_00520BF0_IsReplyReceived(0x1C);
}
