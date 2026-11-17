struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2QtyWarnStrc
{
    int nWarnType;
    int nFrame;
    unsigned int nLevel0;
    unsigned int nLevel1;
    unsigned int nLevel2;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern unsigned char gabSlots_007BEFB4[];                                                                   // 0x007BEFB4
extern int gaBodyLocs_00722374[];                                                                           // 0x00722374
extern unsigned int gnBodyLocCount_0072237C;                                                                // 0x0072237C
extern D2QtyWarnStrc gaQtyWarn_00722380[];                                                                  // 0x00722380
extern unsigned int gnQtyWarnCount_007223E4;                                                                // 0x007223E4

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60
D2UnitStrc* __fastcall sub_00463DD0();                                                               // 0x00463DD0
void __stdcall sub_00497C50_DrawSlotIcon(int nFrame);                                                       // 0x00497C50
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* pItem);                                           // 0x00629800
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem);                                              // 0x0062A0F0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x00497E00
void __cdecl sub_00497E00()
{
    memset(gabSlots_007BEFB4, 0, 6);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pRightArm = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArm = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if ((pRightArm && ITEMS_GetAmmoType(pRightArm) && (!pLeftArm || !ITEMS_CheckItemTypeId(pLeftArm, ITEMS_GetAmmoType(pRightArm))))
        || (pLeftArm && ITEMS_GetAmmoType(pLeftArm) && (!pRightArm || !ITEMS_CheckItemTypeId(pRightArm, ITEMS_GetAmmoType(pLeftArm)))))
    {
        sub_00497C50_DrawSlotIcon(2);
    }

    for (unsigned int i = 0; i < gnBodyLocCount_0072237C; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, gaBodyLocs_00722374[i]);
        if (!pItem)
        {
            continue;
        }

        const unsigned char nWarnType = ITEMS_GetQtyWarnCount(pItem);
        if (!nWarnType)
        {
            continue;
        }

        for (unsigned int j = 0; j < gnQtyWarnCount_007223E4; ++j)
        {
            if (nWarnType != gaQtyWarn_00722380[j].nWarnType)
            {
                continue;
            }

            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_00451F60_UnitClassId(pItem));
            unsigned int nQuantity = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            if (!ITEMS_IsMagSetRarUniCrfOrTmp(pItem))
            {
                for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
                {
                    D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pNode);
                    if (pInvItem != pItem && !ITEMS_GetInvPage(pInvItem)
                        && DATATBLS_GetItemsTxtRecord(!pInvItem ? -1 : pInvItem->dwClassId)->dwCode == pItemsTxtRecord->dwCode)
                    {
                        nQuantity += STATLIST_UnitGetStatValue(pInvItem, 0x46, 0);
                    }
                }
            }

            if (nQuantity <= gaQtyWarn_00722380[j].nLevel2)
            {
                sub_00497C50_DrawSlotIcon(gaQtyWarn_00722380[j].nFrame + 2);
            }
            else if (nQuantity <= gaQtyWarn_00722380[j].nLevel1)
            {
                sub_00497C50_DrawSlotIcon(gaQtyWarn_00722380[j].nFrame + 1);
            }
            else if (nQuantity <= gaQtyWarn_00722380[j].nLevel0)
            {
                sub_00497C50_DrawSlotIcon(gaQtyWarn_00722380[j].nFrame);
            }
        }
    }
}

#include "gen/data/Source/D2Client/00497E00_sub_00497E00.inc"
