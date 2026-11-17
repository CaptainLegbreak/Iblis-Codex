struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

typedef void(__fastcall* STATLIST_UpdateFn)(D2UnitStrc* pUnit, int nValue, int nStatId, D2UnitStrc* pOther);

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall D2GAME_SendPacket0x47_6FC3EEE0(D2ClientStrc* pClient, D2UnitStrc* pPlayer);                 // 0x0053D370
void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, int a3);         // 0x0053D3C0
void __fastcall sub_6FC81C00(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00547F70
void __fastcall sub_6FC81CA0(D2UnitStrc* pPlayer, D2ClientStrc* pClient, int a3);                           // 0x00548010
void __fastcall sub_6FC82270(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient);                  // 0x005484B0
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, int nValue, int nStatId, D2UnitStrc* pOther); // 0x00548520
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                      // 0x0055F850
void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer);   // 0x00571580
void __fastcall sub_6FCC5F20(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x005715A0
void __fastcall sub_00571620(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571620
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient);                       // 0x00571740
void __fastcall sub_6FCC6540(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571CD0
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4); // 0x00597890
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, STATLIST_UpdateFn pfCallback); // 0x00625870
int __stdcall D2COMMON_10530_D2CheckStatlistFlagDMGRed(D2UnitStrc* pUnit);                                  // 0x00625A20
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall STATES_IsAnyGfxStateFlagSet(D2UnitStrc* pUnit);                                               // 0x00639F20
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020

#define UNIT_PLAYER 0
#define PLRMODE_NEUTRAL 1
#define ITEMTYPE_WEAPON 45
#define STAT_STRENGTH 0
#define STAT_DEXTERITY 2
#define STAT_LEVEL 12
#define STAT_VELOCITYPERCENT 67
#define STAT_ATTACKRATE 68
#define STAT_DURABILITY 72
#define IFLAG_BROKEN 0x100
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAGEX_HASINV 0x00000001
#define UNITFLAGEX_TELEPORTED 0x00010000

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00580380
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pPlayer->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
        int bChangedToNeutral = 0;
        while (pItem)
        {
            if (INVENTORY_GetItemNodePage(pItem) == 3)
            {
                D2UnitStrc* pWeapon = INVENTORY_UnitIsItem(pItem);
                if (ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_WEAPON) && ITEMS_HasDurability(pWeapon)
                    && STATLIST_UnitGetStatValue(pWeapon, STAT_DURABILITY, 0) <= 0
                    && !ITEMS_CheckItemFlag(pWeapon, IFLAG_BROKEN, 1513, ".\\PLAYER\\PlrModes.cpp"))
                {
                    if (!bChangedToNeutral)
                    {
                        UNITS_ChangeAnimMode(pPlayer, PLRMODE_NEUTRAL);
                        bChangedToNeutral = 1;
                    }

                    sub_6FC4B580(pGame, pPlayer, pWeapon);
                    pItem = INVENTORY_GetFirstItem(pInventory);
                    continue;
                }
            }

            pItem = INVENTORY_GetNextItem(pItem);
        }
    }
}

// 0x00580860
void __fastcall sub_6FC81650(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient, int a4)
{
    D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        if (UNIT_HasFlagEx(pPlayer, UNITFLAGEX_TELEPORTED))
        {
            sub_6FC81CA0(pPlayer, pClient, 1);
        }
        else if (UNIT_HasFlagEx(pPlayer, 0x800) && pPlayer != pOtherPlayer)
        {
            sub_6FC81CA0(pPlayer, pClient, 0);
        }
    }

    if (!a4 && pPlayer && UNIT_HasFlagEx(pPlayer, UNITFLAGEX_HASINV))
    {
        D2GAME_INVMODE_First_6FC40FB0(pGame, pPlayer, pClient, 0);
        D2GAME_SendPacket0x47_6FC3EEE0(pClient, pPlayer);
        D2GAME_SendPacket0x48_6FC3EF40(pClient, pPlayer, 0);
    }

    if (pPlayer && UNIT_HasFlag(pPlayer, UNITFLAG_DOUPDATE))
    {
        sub_6FC82270(pGame, pPlayer, pClient);
    }

    sub_6FCC6540(pPlayer, pClient);

    if (pPlayer)
    {
        if (UNIT_HasFlag(pPlayer, 0x400))
        {
            D2GAME_UpdateUnit_6FCC6080(pPlayer, pClient);
        }

        if (UNIT_HasFlag(pPlayer, 0x100))
        {
            sub_00571620(pPlayer, pClient);
        }

        if (UNIT_HasFlag(pPlayer, 0x8000))
        {
            sub_6FC81C00(pPlayer, pClient);
        }
    }

    if (STATES_IsAnyGfxStateFlagSet(pPlayer))
    {
        D2GAME_STATES_SendStates_6FCC5F00(pPlayer, pClient, 0);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pPlayer))
    {
        sub_6FCC5F20(pPlayer, pClient);
    }

    D2Common_10512(pPlayer, pOtherPlayer, STAT_VELOCITYPERCENT, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_ATTACKRATE, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_LEVEL, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_STRENGTH, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_DEXTERITY, D2GAME_UpdateAttribute_6FC822D0);
}
