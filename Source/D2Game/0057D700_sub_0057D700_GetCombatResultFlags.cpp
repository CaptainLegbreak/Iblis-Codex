struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    char unk0x08[0x68];
};

struct D2CombatStrc
{
    char unk0x00[0x04];
    int dwAttackerType;
    int dwAttackerId;
    int dwDefenderType;
    int dwDefenderId;
    D2DamageStrc tDamage;
    D2CombatStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    char unk0x10[0x9C];
    D2CombatStrc* pCombat;
};

typedef char chkCombatNext_M125[(int)&((D2CombatStrc*)0)->pNext == 0x84 ? 1 : -1];
typedef char chkUnitCombat_M125[(int)&((D2UnitStrc*)0)->pCombat == 0xAC ? 1 : -1];

// 0x0057D700
unsigned short __fastcall sub_0057D700_GetCombatResultFlags(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pDefender || !pAttacker)
    {
        return 0;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (!pCombat)
    {
        return 0;
    }

    for (; pCombat; pCombat = pCombat->pNext)
    {
        if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId
            && pCombat->dwDefenderType == pDefender->dwUnitType && pCombat->dwDefenderId == pDefender->dwUnitId)
        {
            return (unsigned char)pCombat->tDamage.wResultFlags;
        }
    }

    return 0;
}
