struct D2UnitStrc;
struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

#define UNIT_PLAYER 0
#define IFLAG_BROKEN 0x00000100
#define EVENTTYPE_STATREGEN 3
#define STAT_ITEM_REPLENISH_DURABILITY 252
#define STAT_ITEM_REPLENISH_QUANTITY 253
#define STAT_DURABILITY 72
#define STAT_QUANTITY 70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem);                                                          // 0x00629F20
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
void __fastcall D2GAME_RepairBrokenItem_6FC4B630(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x0055F900
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x00562C40
static int __stdcall sub_6FC4A350(D2GameStrc* pGame, D2UnitStrc* pItem, int nLengthStatId, int nValueStatId, int nMaxValue)
{
    const int nLength = STATLIST_UnitGetStatValue(pItem, nLengthStatId, 0);
    if (!nLength)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetStatValue(pItem, nValueStatId, 0) + 1;
    if (nValue > nMaxValue)
    {
        return 1;
    }

    STATLIST_SetUnitStat(pItem, nValueStatId, nValue, 0);

    const int nOwnerGUID = ITEMS_GetOwnerId(pItem);
    if (nOwnerGUID != -1)
    {
        D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
        if (pOwner)
        {
            D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pOwner, ".\\ITEMS\\ItemMode.cpp", 5504);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, nValueStatId, nValue, 0);
                if (nValue >= 1)
                {
                    if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 5510, ".\\ITEMS\\ItemMode.cpp"))
                    {
                        D2GAME_RepairBrokenItem_6FC4B630(pGame, pOwner, pItem);
                    }
                }
            }
        }
    }

    int nDuration = 2500 / nLength + 1;
    if (nDuration < 125)
    {
        nDuration = 125;
    }

    EVENT_SetEvent(pGame, pItem, EVENTTYPE_STATREGEN, pGame->dwGameFrame + nDuration, 0, 0);

    return 1;
}

// 0x00562D30
void __fastcall sub_6FC4A2E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!ITEMS_CheckItemFlag(pUnit, IFLAG_BROKEN, 5542, ".\\ITEMS\\ItemMode.cpp") && ITEMS_HasDurability(pUnit) && sub_6FC4A350(pGame, pUnit, STAT_ITEM_REPLENISH_DURABILITY, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pUnit)))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pUnit))
    {
        sub_6FC4A350(pGame, pUnit, STAT_ITEM_REPLENISH_QUANTITY, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pUnit));
    }
}
