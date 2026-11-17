struct D2GameStrc;
struct D2InventoryStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; char unk10[0x50]; D2InventoryStrc* pInventory; };
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc*, int*); // 0x00625820
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
int __stdcall ITEMS_UpdateSets(D2UnitStrc*, D2UnitStrc*, int, int); // 0x00663CC0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*, unsigned int, int, const char*); // 0x006280A0
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc*, D2UnitStrc*); // 0x006277F0
int __stdcall UNITS_CanDualWield(D2UnitStrc*); // 0x006235A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*, int); // 0x00629BB0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc*, D2UnitStrc*, int); // 0x00627910
void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc*, D2UnitStrc*); // 0x0055C6E0
void __stdcall sub_006275B0_UpdateVitals(D2UnitStrc*); // 0x006275B0
static __forceinline D2InventoryStrc* GetUnitInventory(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }
    return pInventory;
}

// 0x0055C730
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals)
{
    if (!pTarget || !pItem || pItem->dwUnitType != 4)
        return;
    if (pTarget->dwUnitType == 0 && STATES_CheckState(pTarget, 7))
        return;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 9, pItem->dwUnitId);
    if (pTarget != STATLIST_GetOwner(pItem, 0))
        return;
    if (ITEMS_GetItemQuality(pItem) == 5)
        ITEMS_UpdateSets(pTarget, pItem, 1, 0);
    const int nTargetType = pTarget ? pTarget->dwUnitType : 6;
    D2UnitStrc* pLeftWeapon = 0;
    if (nTargetType == 0)
        pLeftWeapon = INVENTORY_GetLeftHandWeapon(GetUnitInventory(pTarget));
    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x3D8, ".\\ITEMS\\ItemMode.cpp") || bUpdateStatList)
        STATLIST_ExpireUnitStatlist(pTarget, pItem);
    if (UNITS_CanDualWield(pTarget) && pLeftWeapon && ITEMS_CheckItemTypeId(pItem, 0x2D) && pLeftWeapon != pItem)
    {
        if (!ITEMS_CheckItemFlag(pLeftWeapon, 0x100, 0x3E6, ".\\ITEMS\\ItemMode.cpp") || bUpdateStatList)
        {
            if (STATLIST_GetOwner(pLeftWeapon, 0))
                STATLIST_MergeStatLists(pTarget, pLeftWeapon, 1);
        }
    }
    sub_0055C6E0_OnItemToCursor(pTarget, pItem);
    if (bUpdateVitals)
        sub_006275B0_UpdateVitals(pTarget);
}
