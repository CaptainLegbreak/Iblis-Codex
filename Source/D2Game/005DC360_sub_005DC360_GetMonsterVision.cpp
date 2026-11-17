struct D2MonsterDataStrc
{
    char unk0x00[0x50];
    int pVision;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

// 0x005DC360
int __fastcall sub_005DC360_GetMonsterVision(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pVision;
    }
    return 0;
}

// 0x005DC840
int __fastcall sub_005DC840_IsActiveUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    switch (pUnit->dwUnitType)
    {
    case 0:
    case 1:
        return !SUNIT_IsDead(pUnit);
    case 3:
        return 1;
    }
    return 0;
}
