struct D2MonsterDataStrc
{
    char unk0x00[4];
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

// 0x004DA770
unsigned char __fastcall sub_004DA770_GetMonComponentIndex(D2UnitStrc* pUnit, unsigned char nComponent)
{
    if (pUnit && pUnit->dwUnitType == 1 && nComponent < 16 && pUnit->pMonsterData)
        return pUnit->pMonsterData->nComponent[nComponent];
    return 0;
}
