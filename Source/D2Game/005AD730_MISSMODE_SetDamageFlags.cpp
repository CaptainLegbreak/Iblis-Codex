struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    char unk0x0C[0x48];
    int dwPiercePct;
    char unk0x58[0x08];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    char unk0x65[0x0B];
};

struct D2MissilesTxt
{
    char unk0x000[0x04];
    unsigned char nMissileFlags;
    char unk0x005[0xA9];
    unsigned char nKnockBack;
    char unk0x0AF[0x1A4 - 0xAF];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE280

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage); // 0x0057CEE0
unsigned int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4, int a5); // 0x0057DFB0
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
unsigned int __stdcall MISSILE_GetFlags(D2UnitStrc* pMissile);                                              // 0x0064A190
unsigned int __stdcall MISSILE_GetHitClass(D2UnitStrc* pMissile);                                           // 0x0064A5A0

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline void MISSMODE_SetMissileHitFlags(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (MISSILE_GetFlags(pUnit) & 1)
    {
        pDamage->dwHitFlags |= 0x20;
    }

    if (MISSILE_GetFlags(pUnit) & 2)
    {
        pDamage->dwHitFlags |= 0x80;
    }

    pDamage->dwPiercePct = STATLIST_UnitGetStatValue(pUnit, 0x147, 0);
}

// 0x005AD730
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (!pMissile || pMissile->dwUnitType != 3)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    pDamage->wResultFlags |= 1;

    if (!STATES_CheckState(pDefender, 0x36))
    {
        if (pMissilesTxtRecord->nMissileFlags & gdwBitMasks[0])
        {
            pDamage->wResultFlags |= 4;
        }
        else if (pMissilesTxtRecord->nMissileFlags & gdwBitMasks[1])
        {
            pDamage->wResultFlags |= 0x4000;
        }

        if (pMissilesTxtRecord->nKnockBack > 0 && (int)SEED_RollLimitedRandomNumber(&pMissile->pSeed, 100) < pMissilesTxtRecord->nKnockBack)
        {
            pDamage->wResultFlags |= 8;
        }
    }

    unsigned int nBlockFlags = SUNITDMG_ApplyBlockOrDodge(pGame, pOwner, pDefender, 1, pDamage->dwPhysDamage != 0);
    if (nBlockFlags & 0x1F && !(pMissilesTxtRecord->nMissileFlags & gdwBitMasks[0]) && !pMissilesTxtRecord->nKnockBack)
    {
        pDamage->wResultFlags = pDamage->wResultFlags & (unsigned short)~1 | 0x4000;
        nBlockFlags &= 0xFFFFFFE0;
    }

    if (nBlockFlags & 8)
    {
        pDamage->wResultFlags |= 0x200;
    }

    if (nBlockFlags & 2)
    {
        pDamage->wResultFlags |= 0x100;
    }

    if (nBlockFlags & 0x11)
    {
        pDamage->wResultFlags |= 0x10;
    }

    if (nBlockFlags)
    {
        pDamage->wResultFlags &= (unsigned short)~1;
    }

    const unsigned int* pdwHitClass = &pDamage->dwHitClass;
    pDamage->dwHitClass = *pdwHitClass & 0xF0 | MISSILE_GetHitClass(pMissile);

    if (*pdwHitClass & 0xF0)
    {
        pDamage->nHitClassActiveSet = 1;
    }

    D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pOwner, pDefender, pDamage);

    MISSMODE_SetMissileHitFlags(pMissile, pDamage);

    if (pDamage->wResultFlags & 1)
    {
        SUNITDMG_ExecuteEvents(pGame, pOwner, pDefender, 1, pDamage);
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pOwner, pDefender, pDamage);
}
