#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
struct D2MissilesTxt;
union D2SeedStrc;



struct D2MissilesTxt
{
    char unk0x000[0x04];
    unsigned char nMissileFlags;
    unsigned char unk_05[0x8B];
    unsigned int dwDmgCalc;
    unsigned char unk_94[0x1A];
    unsigned char nKnockBack;
    char unk0x0AF[0x1A4 - 0xAF];
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70
void __fastcall MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A91C0
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage); // 0x005A9270
extern const unsigned int gdwBitMasks[]; // 0x006CE280
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage); // 0x0057CEE0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid, int bBlock); // 0x0057DFB0
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall MISSILE_GetHitClass(D2UnitStrc* pMissile); // 0x0064A5A0

// 0x00483360
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    return 0;
}

// 0x005AD0F0
void __fastcall sub_005AD0F0_ConvertMissileDamage(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }
    int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwDmgCalc, -1, -1);
    if (nPercentage <= 0)
    {
        return;
    }
    nPercentage = D2_MIN(nPercentage, 100);
    int nDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercentage, 100);
    nDamage = D2_MIN(nDamage, pDamage->dwPhysDamage);
    nDamage += MISSMODE_GetDamageValue(pGame, pMissile, pUnit, pDamage);
    MISSMODE_ResetDamageParams(pGame, pMissile, pDamage);
    MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamage);
}

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
