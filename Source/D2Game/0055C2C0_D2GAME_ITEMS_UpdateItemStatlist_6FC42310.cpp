struct D2GameStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x000[0xF0];
    int dwGemOffset;
};

struct D2GemsTxt;

extern "C" const char szItemModeCpp[];                                                                      // 0x006E1164

void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);                            // 0x0055C270
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem);                                                     // 0x00629A40
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2GemsTxt* pGemsTxt, int nArg2, int nArg5); // 0x0065FEC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4);                       // 0x00663CC0

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static __forceinline D2InventoryStrc* GetUnitInventory(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }
    return pInventory;
}

// 0x0055C2C0
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4)
{
    if (!pUnit || sub_0044BE50(pItem) != 4)
    {
        return;
    }

    const int v_dwUnitType_74 = *(int *)&pUnit->dwUnitType;
    if (v_dwUnitType_74 == 0 && STATES_CheckState(pUnit, 7))
    {
        return;
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x14))
    {
        if (pUnit->dwUnitType != 4)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (!pItemsTxtRecord)
        {
            return;
        }

        const int v_dwGemOffset_93 = *(int *)&pItemsTxtRecord->dwGemOffset;
        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(v_dwGemOffset_93);
        if (!pGemsTxtRecord)
        {
            return;
        }

        sub_0065FEC0_ItemApplyProps(2, 0, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x4A))
    {
        if (pUnit->dwUnitType != 4)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (!pItemsTxtRecord)
        {
            return;
        }

        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord((*(int *)&pItemsTxtRecord->dwGemOffset));
        if (!pGemsTxtRecord)
        {
            return;
        }

        sub_0065FEC0_ItemApplyProps(5, pUnit, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMS_GetItemQuality(pItem) == 5)
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    sub_0055C270_OnItemToBelt(pUnit, pItem);

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    D2UnitStrc* pLeftHandWeapon = 0;
    if (nUnitType == 0)
    {
        pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(GetUnitInventory(pUnit));
    }

    int bType = 1;
    if (UNITS_CanDualWield(pUnit))
    {
        if (pItem != pLeftHandWeapon && ITEMS_CheckItemTypeId(pItem, 0x2D))
        {
            bType = 0;
        }

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x2B8, szItemModeCpp) && !a4)
        {
            {
                if (pUnit->pDynamicPath)
                {
                    UNITS_UpdateAnimRateAndVelocity(pUnit, szItemModeCpp, 0x2CF);
                }
                return;
            }
        }
    }
    else
    {
        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x2C1, szItemModeCpp) && !a4)
        {
            goto skip_merge;
        }
    }

    STATLIST_MergeStatLists(pUnit, pItem, bType);
skip_merge:

    if (pUnit->pDynamicPath)
    {
        UNITS_UpdateAnimRateAndVelocity(pUnit, szItemModeCpp, 0x2CF);
    }
}
