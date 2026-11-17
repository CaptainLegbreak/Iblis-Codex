struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);

inline int sub_M449_IsUnitTypeInl(D2UnitStrc* pUnit, int nType)
{
    if (!pUnit)
    {
        return 0;
    }
    if (pUnit->dwUnitType != nType)
    {
        return 0;
    }
    return 1;
}

// 0x0046F090
static __declspec(noinline) int sub_0046F090_IsNotMonsterOrNoFlag2(D2UnitStrc* pUnit)
{
    if (!sub_M449_IsUnitTypeInl(pUnit, 1))
    {
        return 1;
    }

    const int nClassId = pUnit->dwClassId;
    return !sub_004638A0_CheckMonStats2Flag(nClassId, 2);
}

int __cdecl sub_M449_Emit_0046F090(D2UnitStrc* pUnit)
{
    return sub_0046F090_IsNotMonsterOrNoFlag2(pUnit) + 0x55;
}
