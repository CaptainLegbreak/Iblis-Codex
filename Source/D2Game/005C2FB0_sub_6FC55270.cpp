struct D2UnitStrc;
struct D2ItemDropStrc;

int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                  // 0x005C2AF0
int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);                        // 0x005C2D40
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670

// 0x005C2FB0
int __fastcall sub_6FC55270(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_ApplyLowQuality(pItem, pItemDrop);
    }

    return ITEMS_ApplyLegacyLowQuality(pItem, pItemDrop);
}
