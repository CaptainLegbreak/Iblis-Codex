struct D2MonsterDataStrc
{
    char unk0x00[0x1C];
    unsigned char nMonUmod[10];
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

int __stdcall sub_O05_EmitArg_AddUMod(D2UnitStrc* pUnit, int nValue);

// 0x005A02E0
static __declspec(noinline) void __stdcall sub_005A02E0_AddUMod(int nUMod, D2UnitStrc* pUnit)
{
    const unsigned int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    if (D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData)
    {
        int nIndex = 0;
        while (nIndex < 9 && pMonsterData->nMonUmod[nIndex])
        {
            ++nIndex;
        }

        if (nIndex < 9)
        {
            pMonsterData->nMonUmod[nIndex] = (unsigned char)nUMod;
        }
    }
}

void __stdcall sub_O05_Emit_005A02E0(D2UnitStrc* pUnit, int nValue)
{
    sub_005A02E0_AddUMod(sub_O05_EmitArg_AddUMod(pUnit, nValue), pUnit);
}
