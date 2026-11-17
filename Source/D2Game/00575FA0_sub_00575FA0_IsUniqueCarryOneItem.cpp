struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x64];
    unsigned int dwFlagEx;
};

struct D2UniqueItemsTxt
{
    short wId;
    char unk0x002[0x2A];
    unsigned char nUniqueItemFlags[4];
    char unk0x030[0x11C];
};

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define ITEMQUAL_UNIQUE 7
#define UNIQUEITEMSFLAGINDEX_CARRY1 2
#define PETTYPE_HIREABLE 7
#define STAT_DURABILITY 72
#define STAT_QUANTITY 70
#define IFLAG_NEWITEM 0x00000001
#define IFLAG_BROKEN 0x00000100

extern "C" const char gszNpcSourceFile[];                                                                   // 0x006E15F0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __fastcall sub_0055F590_CheckItem(D2UnitStrc* pItem, const char* szFile, int nLine);                    // 0x0055F590
void __fastcall D2GAME_RepairBrokenItem_6FC4B630(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x0055F900
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);      // 0x0055FE80
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);           // 0x00574EC0
void __fastcall sub_6FC7E310(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3, int a4);                       // 0x005754B0
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall sub_0062E660(D2UnitStrc* pItem);                                                              // 0x0062E660
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00575FA0
int __fastcall sub_00575FA0_IsUniqueCarryOneItem(D2UnitStrc* pItem)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_UNIQUE)
    {
        return 0;
    }

    if (ITEMS_GetFileIndex(pItem) < 0)
    {
        return 0;
    }

    D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    return (pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7]) != 0;
}

// 0x005761C0
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    if (sub_0062E660(pItem))
    {
        if (ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nMaxStack, 0);

            if (pPlayer)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 185), pItem, 1, STAT_QUANTITY, nMaxStack, 0);
            }
        }

        D2GAME_RechargeItem_6FC4BD50(pGame, pPlayer, pItem);

        if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 191, gszNpcSourceFile))
        {
            D2GAME_RepairBrokenItem_6FC4B630(pGame, pPlayer, pItem);
        }
        else
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            if (nMaxDurability > 0)
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);

                if (pPlayer)
                {
                    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pPlayer, gszNpcSourceFile, 203), pItem, 1, STAT_DURABILITY, nMaxDurability, 0);
                }
            }
        }
    }
}

// 0x00576C30
void __fastcall sub_00576C30_AddItemsToTrade(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pCurrent = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pCurrent)
        {
            pCurrent->dwFlagEx |= 4;
        }

        if (sub_0055F590_CheckItem(pCurrent, gszNpcSourceFile, 730))
        {
            ITEMS_SetItemFlag(pCurrent, IFLAG_NEWITEM, 1);
        }

        INVENTORY_AddItemToTradeInventory(pPlayer->pInventory, pCurrent);
    }
}

// 0x005773D0
void __fastcall sub_005773D0_UpdateMercForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0))
    {
        sub_6FC7E310(pGame, pPlayer, UNITS_GetUnitXPosition(pPlayer), UNITS_GetUnitYPosition(pPlayer));
    }
}
