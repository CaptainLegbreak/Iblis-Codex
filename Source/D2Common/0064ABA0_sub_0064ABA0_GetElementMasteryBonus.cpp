struct D2UnitStrc;

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

static __declspec(noinline) int sub_0064ABA0_GetElementMasteryBonus(int nAmount, int nElement, D2UnitStrc* pUnit);

// 0x0064ABA0
static int sub_0064ABA0_GetElementMasteryBonus(int nAmount, int nElement, D2UnitStrc* pUnit)
{
    int nMastery;
    switch (nElement)
    {
    case 1:
        nMastery = STATLIST_UnitGetStatValue(pUnit, 0x149, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    case 2:
        nMastery = STATLIST_UnitGetStatValue(pUnit, 0x14A, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    case 4:
    case 12:
        nMastery = STATLIST_UnitGetStatValue(pUnit, 0x14B, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    case 5:
        nMastery = STATLIST_UnitGetStatValue(pUnit, 0x14C, 0);
        if (nMastery)
            return DATATBLS_ApplyRatio(nAmount, nMastery, 100);
        break;
    }
    return 0;
}

void __fastcall sub_0064ABA0_EmitAddMasteryBonus(int* pMinMax, int nElement, D2UnitStrc* pUnit)
{
    pMinMax[0] += sub_0064ABA0_GetElementMasteryBonus(pMinMax[0], nElement, pUnit);
    pMinMax[1] += sub_0064ABA0_GetElementMasteryBonus(pMinMax[1], nElement, pUnit);
}
