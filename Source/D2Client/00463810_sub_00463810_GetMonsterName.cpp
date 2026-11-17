struct Unicode;
struct D2GfxDataStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    const Unicode* wszName;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x3C];
    D2GfxDataStrc* pGfxData;
};

extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80];                                                    // 0x007A5E70
extern D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80];                                                    // 0x007A5270

// 0x00463810
const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        return pUnit->pMonsterData->wszName;
    return 0;
}

// 0x00463C70
void __cdecl sub_00463C70()
{
    for (int i = 0; i < 6 * 0x80; ++i) gpUnitHashTable_007A5E70[i] = 0;
    for (int i = 0; i < 6 * 0x80; ++i) gpUnitHashTable_007A5270[i] = 0;
}

// 0x00463E10
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->pGfxData;
}
