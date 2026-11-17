struct D2StatListStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x60 - 0x04];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xC6C - 0xBA4];
    int nStuff;
    int nShiftedStuff;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag);               // 0x00625730
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

// 0x0065C820
int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pValue, D2StatListStrc** ppStatList)
{
    if (pValue)
    {
        *pValue = 0;
    }

    if (ppStatList)
    {
        *ppStatList = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType != 4)
    {
        return 0;
    }

    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || nSkillLevel <= 0 || nSkillLevel > 63)
    {
        return 0;
    }

    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        const int nValue = STATLIST_GetStatValue(pStatList, 204, nLayer);
        if (nValue)
        {
            if (pValue)
            {
                *pValue = nValue & 0xFF;
            }

            if (ppStatList)
            {
                *ppStatList = pStatList;
            }

            return 1;
        }
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (ITEMMODS_GetItemCharges(pSocketed, nSkillId, nSkillLevel, pValue, ppStatList))
            {
                return 1;
            }
        }
    }

    return 0;
}
