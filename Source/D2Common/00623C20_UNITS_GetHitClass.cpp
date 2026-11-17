struct D2MonStats2Txt
{
    char unk0x00[0x14];
    unsigned char nHitClass;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
unsigned char __stdcall ITEMS_GetHitClassFromItem(D2UnitStrc* pItem);                                       // 0x0062A180
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

// 0x00623C20
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == 0)
        {
            if (D2UnitStrc* pItem = D2Common_10434(pUnit, 0))
                return ITEMS_GetHitClassFromItem(pItem);
            else
                return 1;
        }
        else if (pUnit->dwUnitType == 1)
        {
            if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
                return pMonStats2TxtRecord->nHitClass;
        }
    }
    return 0;
}
