struct D2UnitStrc;

struct D2DamageStrc
{
    char unk0x00[0x48];
    int dwAbsLife;
};

struct D2DamageContextStrc
{
    void* pGame;
    void* pDifficultyLevelsTxt;
    D2UnitStrc* pAttacker;
    D2UnitStrc* pDefender;
    int bAttackerIsMonster;
    int bDefenderIsMonster;
    D2DamageStrc* pDamage;
};

struct D2ResistTableEntryStrc
{
    int nOffsetInDamageStrc;
    int nResStatId;
    int nMaxResStatId;
    int nPierceStatId;
    int nAbsorbPctStatId;
    int nAbsorbStatId;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

static __declspec(noinline) int __cdecl sub_0057BF10_AbsorbDamage(D2DamageContextStrc* pContext, D2ResistTableEntryStrc* pEntry, int nValue);

// 0x0057BF10
static int __cdecl sub_0057BF10_AbsorbDamage(D2DamageContextStrc* pContext, D2ResistTableEntryStrc* pEntry, int nValue)
{
    if (pEntry->nAbsorbPctStatId == -1)
    {
        return nValue;
    }

    int nAbsorbPct = STATLIST_UnitGetStatValue(pContext->pDefender, pEntry->nAbsorbPctStatId, 0);
    if (nAbsorbPct >= 40)
    {
        nAbsorbPct = 40;
    }

    if (nAbsorbPct > 0)
    {
        const int nAbsorbed = DATATBLS_ApplyRatio(nValue, nAbsorbPct, 100);
        pContext->pDamage->dwAbsLife += nAbsorbed;
        nValue -= nAbsorbed;
    }

    int nAbsorb = STATLIST_UnitGetStatValue(pContext->pDefender, pEntry->nAbsorbStatId, 0) << 8;
    if (nAbsorb > 0)
    {
        if (nAbsorb >= nValue)
        {
            nAbsorb = nValue;
        }

        pContext->pDamage->dwAbsLife += nAbsorb;
        nValue -= nAbsorb;
    }

    return nValue;
}

// build: context sub_0057BF10_Shim
// calling-convention shim (not game code)
int __fastcall sub_0057BF10_Shim(D2DamageContextStrc* pContext, D2ResistTableEntryStrc* pEntry, int nValue)
{
    return sub_0057BF10_AbsorbDamage(pContext, pEntry, nValue);
}
