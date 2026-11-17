struct D2UnitStrc
{
    int dwUnitType;
};

struct D2SetItemsTxt
{
    char unk0x00[0x87];
    unsigned char nAddFunc;
};

extern const int gnItemSetStates[];                                                                         // 0x006EE424
extern const int gnSetMaskToBonusMappingTable[];                                                            // 0x006EE440
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
const D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem);                      // 0x0062A490
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem);                                            // 0x0062B3A0
int __stdcall D2Common_10574(D2UnitStrc* pUnit, int nStateId, int bSet);                                    // 0x006279A0

// 0x00663A20
int __fastcall sub_00663A20_SetItemBonusStates(D2UnitStrc* pItem, unsigned int nSetItemMask)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && ITEMS_GetItemQuality(pItem) == 5)
    {
        const D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordFromItem(pItem);
        if (pSetItemsTxt)
        {
            switch (pSetItemsTxt->nAddFunc)
            {
            case 0:
                return 0;

            case 1:
            {
                const int nSetItems = ITEMS_GetNoOfSetItemsFromItem(pItem);
                for (int i = 0; i < 6; ++i)
                {
                    int nIndex = i;
                    if (i != nSetItems)
                    {
                        if (i > nSetItems)
                        {
                            nIndex -= 1;
                        }

                        if ((1 << i) & nSetItemMask)
                        {
                            D2Common_10574(pItem, gnItemSetStates[nIndex], 0);
                        }
                        else
                        {
                            D2Common_10574(pItem, gnItemSetStates[nIndex], 1);
                        }
                    }
                }
                break;
            }

            case 2:
            {
                const int nBonuses = (nSetItemMask >= 0x40 ? 0 : gnSetMaskToBonusMappingTable[nSetItemMask]) - 1;

                for (int i = 0; i < nBonuses; ++i)
                {
                    D2Common_10574(pItem, gnItemSetStates[i], 0);
                }

                if (nBonuses >= 5)
                {
                    return 1;
                }

                for (int i = nBonuses; i < 5; ++i)
                {
                    D2Common_10574(pItem, gnItemSetStates[i], 1);
                }
                break;
            }
            }

            return 1;
        }
    }

    return 0;
}

#include "gen/data/Source/D2Common/00663A20_sub_00663A20_SetItemBonusStates.inc"
