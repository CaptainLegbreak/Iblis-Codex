struct D2ItemDataStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
};

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    void* pGrids;
    int nGridCount;
    int dwLeftItemGUID;
};

#define INVENTORY_SIGNATURE 0x1020304
#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define D2UnitInvalidGUID -1
#define ITEMTYPE_WEAPON 0x2D
#define BODYLOC_RARM 4
#define BODYLOC_LARM 5

int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0

inline void INVENTORY_SetLeftItemGUIDInline(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int bSet)
{
    if (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE && pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        const int nItemGUID = pItem ? pItem->dwUnitId : D2UnitInvalidGUID;
        if (bSet)
        {
            pInventory->dwLeftItemGUID = nItemGUID;
        }
        else if (pInventory->dwLeftItemGUID == nItemGUID)
        {
            pInventory->dwLeftItemGUID = D2UnitInvalidGUID;
        }
    }
}

// 0x0063D2B0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return;
    }
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM)
    {
        return;
    }
    if (!ITEMS_CheckItemTypeId(pItem, ITEMTYPE_WEAPON))
    {
        return;
    }
    INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    D2UnitStrc* pWeapon = 0;
    if (nBodyLoc == BODYLOC_RARM)
    {
        pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
    }
    else if (nBodyLoc == BODYLOC_LARM)
    {
        pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    else
    {
        return;
    }
    if (pWeapon && ITEMS_CanBeEquipped(pWeapon))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pWeapon, 1);
    }
}
