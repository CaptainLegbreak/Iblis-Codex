struct D2UnitStrc;
struct D2StatListStrc;

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2RunesTxt
{
    char unk0x00[0xB0];
    D2PropertyStrc pProperties[7];
};

D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem);                             // 0x0062BED0
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70

// 0x006600A0
int __stdcall ITEMMODS_UpdateRuneword(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused)
{
    const D2RunesTxt* pRunesTxtRecord = ITEMS_GetRunesTxtRecordFromItem(pUnit);
    if (!pRunesTxtRecord)
    {
        return 0;
    }

    if (sub_00625790_UnitFindStatList(pUnit, 171, 0x40))
    {
        return 0;
    }

    ITEMS_SetItemFlag(pUnit, 0x4000000, 1);

    for (int i = 0; i < 7; ++i)
    {
        const D2PropertyStrc* pProperty = &pRunesTxtRecord->pProperties[i];
        if (pProperty->nProperty < 0)
        {
            break;
        }

        D2COMMON_11292_ItemAssignProperty(6, pUnit, pItem, 0, i, 0, pProperty, 171, 0x40, 0);
    }

    return 1;
}
