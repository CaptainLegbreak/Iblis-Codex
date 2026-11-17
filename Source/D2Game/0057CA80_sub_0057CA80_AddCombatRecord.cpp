struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2CombatStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x9C];
    D2CombatStrc* pCombat;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int unk0x48[10];
};

struct D2CombatStrc
{
    D2GameStrc* pGame;
    unsigned int dwAttackerType;
    int dwAttackerId;
    unsigned int dwDefenderType;
    int dwDefenderId;
    D2DamageStrc tDamage;
    D2CombatStrc* pNext;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define STAT_HITPOINTS 6
#define DAMAGEHITFLAG_2 2
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
#define DAMAGERESULTFLAG_WILLDIE 0x02

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0
void __fastcall SUNITDMG_CalculateTotalDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057C1E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

// 0x0057CA80
static void __stdcall sub_0057CA80_AddCombatRecord(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (pDefender && pDefender->dwUnitType == UNIT_OBJECT && (pDefender->dwClassId == 7 || pDefender->dwClassId == 11))
    {
        return;
    }

    if (pDefender->dwUnitType != UNIT_MONSTER && pDefender->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2CombatStrc* pCombat = (D2CombatStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2CombatStrc), ".\\UNIT\\SUnitDmg.cpp", 1995, 0);
    pCombat->pGame = pGame;
    pCombat->dwAttackerType = pAttacker->dwUnitType;
    pCombat->dwAttackerId = pAttacker->dwUnitId;
    pCombat->dwDefenderType = pDefender->dwUnitType;
    pCombat->dwDefenderId = pDefender->dwUnitId;
    memcpy(&pCombat->tDamage, pDamage, sizeof(pCombat->tDamage));
    pCombat->pNext = pAttacker->pCombat;
    pAttacker->pCombat = pCombat;
}

// 0x0057DBF0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    const unsigned int nAttackerType = pAttacker->dwUnitType;
    if (!(pDamage->wResultFlags & 0x8380) && pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (!(pDamage->dwHitFlags & DAMAGEHITFLAG_2))
        {
            SUNITDMG_FillDamageValues(pGame, pAttacker, pDefender, pDamage, 0, nSrcDam);
        }

        SUNITDMG_CalculateTotalDamage(pGame, pAttacker, pDefender, pDamage);

        int nTotalDamage = pDamage->dwPhysDamage + pDamage->dwFireDamage + pDamage->dwLtngDamage + pDamage->dwMagDamage + pDamage->dwColdDamage + pDamage->dwPoisDamage;
        if (nAttackerType == UNIT_MONSTER)
        {
            nTotalDamage += pDamage->dwLifeLeech;
        }

        const int nHitpoints = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);
        if ((nTotalDamage & ~0xFF) > (nHitpoints & ~0xFF))
        {
            pDamage->wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
        }
    }

    sub_0057CA80_AddCombatRecord(pGame, pAttacker, pDefender, pDamage);
}
