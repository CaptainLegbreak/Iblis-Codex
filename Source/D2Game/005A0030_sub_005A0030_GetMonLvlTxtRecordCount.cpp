struct D2MonUModTxt
{
    char unk0x00[0x20];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB74];
    int nMonLvlTxtRecordCount;
    char unk0xB78[0xC50 - 0xB78];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x18];
    int dwDurielFlag;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

#define UNIT_MONSTER 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// 0x005A0030
int __fastcall sub_005A0030_GetMonLvlTxtRecordCount()
{
    return sgptDataTables->nMonLvlTxtRecordCount;
}

// 0x005A0040
D2MonUModTxt* __fastcall MONSTERUNIQUE_GetMonUModTxtRecord(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMonUModTxt[nUMod];
}

// 0x005A0060
int __fastcall sub_005A0060_GetMonUModTxtRecordCount()
{
    return sgptDataTables->nMonUModTxtRecordCount;
}

static __forceinline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005A0220
static __forceinline int sub_005A0220_GetMonsterField18(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }

    return pMonsterData->dwDurielFlag;
}

// 0x005A0240
static __forceinline void sub_005A0240_SetMonsterField18(D2UnitStrc* pUnit, int nValue)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->dwDurielFlag = nValue;
    }
}

int __fastcall sub_M117_Emit_005A0220(D2UnitStrc* pUnit, int nValue)
{
    sub_005A0240_SetMonsterField18(pUnit, nValue);
    return sub_005A0220_GetMonsterField18(pUnit);
}
