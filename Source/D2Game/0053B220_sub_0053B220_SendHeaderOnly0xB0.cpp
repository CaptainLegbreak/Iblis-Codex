struct D2UnitStrc;
struct D2ClientStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize);                  // 0x0052B330
void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053CEF0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                               // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                   // 0x00628280
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem);                                              // 0x006282F0

struct D2GSPacketSrvB0
{
    unsigned char nHeader;
};

struct D2GSPacketSrv06
{
    unsigned char nHeader;
};

#define ITEMACTION_REMOVEFROMCONTAINER 5
#define ITEMACTION_EQUIP 6
#define ITEMACTION_INDIRECTLYSWAPBODYITEM 7
#define ITEMACTION_UNEQUIP 8
#define ITEMACTION_SWAPBODYITEM 9
#define ITEMACTION_AUTOUNEQUIP 0x11
#define ITEMACTION_UNKNOWN0x14 0x14
#define ITEMACTION_WEAPONSWITCH 0x17

// 0x0053B220
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId)
{
    D2GSPacketSrvB0 packetB0;
    packetB0.nHeader = 0xB0;
    sub_0052B330(0, nClientId, &packetB0, sizeof(packetB0));
}

// 0x0053B240
void __fastcall sub_6FC3C6B0(int nClientId)
{
    D2GSPacketSrv06 packet06;
    packet06.nHeader = 0x06;
    sub_0052B330(1, nClientId, &packet06, sizeof(packet06));
}

// 0x0053B260
void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nErrorCode)
{
    unsigned int packetB4[2];
    *(unsigned char*)packetB4 = 0xB4;
    *(unsigned int*)((unsigned char*)packetB4 + 1) = nErrorCode;
    sub_0052B330(0, nClientId, packetB4, 5);
}

// 0x0053D010
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2050) == pClient, 2050);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pPlayer, pItem, ITEMACTION_REMOVEFROMCONTAINER, dwCmdFlag, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

// 0x0053D090
void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_EQUIP, dwFlags, 0);
}

// 0x0053D0B0
void __fastcall D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem_6FC3EA70(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_INDIRECTLYSWAPBODYITEM, dwFlags, 0);
}

// 0x0053D0D0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unequip_6FC3EA90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNEQUIP, dwFlags, 0);
}

// 0x0053D0F0
void __fastcall D2GAME_SendP0x9D_ItemAction_SwapBodyItem_6FC3EAB0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_SWAPBODYITEM, dwFlags, 0);
}

// 0x0053D110
void __fastcall D2GAME_SendP0x9D_ItemAction_WeaponSwitch_6FC3EAD0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_WEAPONSWITCH, dwFlags, 0);
}

// 0x0053D2C0
void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_AUTOUNEQUIP, dwFlags, 0);
}

// 0x0053D350
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x14, dwFlags, 0);
}
