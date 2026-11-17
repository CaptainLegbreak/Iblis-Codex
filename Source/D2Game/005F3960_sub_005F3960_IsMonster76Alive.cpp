struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit);                                                           // 0x0063EA40
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

// 0x005F3960
int __fastcall sub_005F3960_IsMonster76Alive(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwUnitType : 6) != 1)
    {
        return 0;
    }

    if (MONSTERS_IsDead(pUnit))
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(sub_00463860(pUnit)) != 0x76)
    {
        return 0;
    }

    return 1;
}
