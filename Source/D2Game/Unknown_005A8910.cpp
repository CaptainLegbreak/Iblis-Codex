#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2MissilesTxt;
struct D2SkillsTxt;

enum D2C_ItemStats
{
    STAT_HITPOINTS = 6,
    STAT_MINDAMAGE = 21,
    STAT_MAXDAMAGE = 22,
    STAT_DAMAGEPERCENT = 25,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_MAGICMINDAM = 52,
    STAT_MAGICMAXDAM = 53,
    STAT_COLDMINDAM = 54,
    STAT_COLDMAXDAM = 55,
    STAT_COLDLENGTH = 56,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
    STAT_LIFEDRAINMINDAM = 60,
    STAT_MANADRAINMINDAM = 62,
    STAT_STAMDRAINMINDAM = 64,
    STAT_STUNLENGTH = 66,
    STAT_SKILL_BYPASS_UNDEAD = 103,
    STAT_SKILL_BYPASS_DEMONS = 104,
    STAT_SKILL_BYPASS_BEASTS = 106,
    STAT_ITEM_DEMONDAMAGE_PERCENT = 121,
    STAT_ITEM_UNDEADDAMAGE_PERCENT = 122,
    STAT_ITEM_DEADLYSTRIKE = 141,
    STAT_DAMAGE_VS_MONTYPE = 180,
    STAT_POISON_COUNT = 326,
    STAT_PASSIVE_FIRE_MASTERY = 329,
    STAT_PASSIVE_LTNG_MASTERY = 330,
    STAT_PASSIVE_COLD_MASTERY = 331,
    STAT_PASSIVE_POIS_MASTERY = 332,
    STAT_FIRELENGTH = 315,
    STAT_BURNINGMIN = 316,
    STAT_BURNINGMAX = 317,
    STAT_PASSIVE_MAG_MASTERY = 357,
};

enum D2C_DamageFlags
{
    DAMAGEHITFLAG_BYPASSUNDEAD = 0x100,
    DAMAGEHITFLAG_BYPASSDEMON = 0x200,
    DAMAGEHITFLAG_BYPASSBEASTS = 0x400,
    DAMAGERESULTFLAG_CRITICALSTRIKE = 0x2000,
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

struct D2MonStatsTxt
{
    char unk0x00[0x1C];
    short nMonType;
    char unk0x1E[0x18A];
};

struct D2MissilesTxt
{
    char unk0x00[0x36];
    short wProgOverlay;
    char unk0x38[0x14];
    int dwHitPar[2];
    char unk0x54[0x150];
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[2];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2); // 0x0057A830
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

struct Unit { char type[4]; int classId; };

struct Damage {
    unsigned int hitFlags; unsigned short resultFlags,extra;
    int physical,enhancedPercent,fire,burn,burnLength,lightning,magic,cold,poison,
        poisonLength,coldLength,freezeLength,lifeLeech,manaLeech,staminaLeech,stunLength;
};

enum { ZERO_DAMAGE=0 };


static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static __forceinline D2MissilesTxt* GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        return GetMissilesTxtRecord(pMissile->dwClassId);
    }
    return 0;
}

// 0x005A8910
static int __stdcall MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int nMinDamStat, int nMasteryStat, int nMaxDamStat)
{
    int nMaxDam = STATLIST_UnitGetStatValue(pUnit, nMaxDamStat, 0);
    if (nMaxDam <= 0)
    {
        return 0;
    }

    int nMinDam = STATLIST_UnitGetStatValue(pUnit, nMinDamStat, 0);
    if (nMinDam <= 0)
    {
        return 0;
    }

    if (nMinDam > nMaxDam)
    {
        const int nTemp = nMinDam;
        nMinDam = nMaxDam;
        nMaxDam = nTemp;
    }

    if (nMasteryStat != -1)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, nMasteryStat, 0);
        if (nMastery)
        {
            nMinDam += DATATBLS_ApplyRatio(nMinDam, nMastery, 100);
            nMaxDam += DATATBLS_ApplyRatio(nMaxDam, nMastery, 100);
        }
    }

    return nMinDam + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDam - nMinDam);
}

// 0x005A89A0
void __stdcall MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage)
{
    memset(pDamage, 0x00, sizeof(*pDamage));

    pDamage->dwPhysDamage = MISSMODE_RollDamageValue(pMissile, STAT_MINDAMAGE, -1, STAT_MAXDAMAGE);
    pDamage->dwFireDamage = MISSMODE_RollDamageValue(pMissile, STAT_FIREMINDAM, STAT_PASSIVE_FIRE_MASTERY, STAT_FIREMAXDAM);
    pDamage->dwMagDamage = MISSMODE_RollDamageValue(pMissile, STAT_MAGICMINDAM, STAT_PASSIVE_MAG_MASTERY, STAT_MAGICMAXDAM);
    pDamage->dwLtngDamage = MISSMODE_RollDamageValue(pMissile, STAT_LIGHTMINDAM, STAT_PASSIVE_LTNG_MASTERY, STAT_LIGHTMAXDAM);
    pDamage->dwColdDamage = MISSMODE_RollDamageValue(pMissile, STAT_COLDMINDAM, STAT_PASSIVE_COLD_MASTERY, STAT_COLDMAXDAM);
    pDamage->dwColdLen = STATLIST_UnitGetStatValue(pMissile, STAT_COLDLENGTH, 0);
    pDamage->dwPoisDamage = MISSMODE_RollDamageValue(pMissile, STAT_POISONMINDAM, STAT_PASSIVE_POIS_MASTERY, STAT_POISONMAXDAM);
    pDamage->dwPoisLen = STATLIST_UnitGetStatValue(pMissile, STAT_POISONLENGTH, 0);

    const int nPoisonCount = STATLIST_UnitGetStatValue(pMissile, STAT_POISON_COUNT, 0);
    if (nPoisonCount > 1)
    {
        pDamage->dwPoisLen /= nPoisonCount;
    }

    pDamage->dwManaLeech = STATLIST_UnitGetStatValue(pMissile, STAT_MANADRAINMINDAM, 0);
    pDamage->dwLifeLeech = STATLIST_UnitGetStatValue(pMissile, STAT_LIFEDRAINMINDAM, 0);
    pDamage->dwStamLeech = STATLIST_UnitGetStatValue(pMissile, STAT_STAMDRAINMINDAM, 0);
    pDamage->dwBurnDamage = MISSMODE_RollDamageValue(pMissile, STAT_BURNINGMIN, STAT_PASSIVE_FIRE_MASTERY, STAT_BURNINGMAX);
    pDamage->dwBurnLen = STATLIST_UnitGetStatValue(pMissile, STAT_FIRELENGTH, 0);
    pDamage->dwStunLen = STATLIST_UnitGetStatValue(pMissile, STAT_STUNLENGTH, 0);

    if (pTarget)
    {
        int nDamagePercent = STATLIST_UnitGetStatValue(pMissile, STAT_DAMAGEPERCENT, 0);
        if (MONSTERS_IsDemon(pTarget))
        {
            nDamagePercent += STATLIST_UnitGetStatValue(pMissile, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
        }

        if (MONSTERS_IsUndead(pTarget))
        {
            nDamagePercent += STATLIST_UnitGetStatValue(pMissile, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
        }

        if (pTarget->dwUnitType == 1)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pTarget->dwClassId);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->nMonType > 0)
            {
                const int nMonType = pMonStatsTxtRecord->nMonType;
                D2StatStrc statBuffer[128];
                const int nStats = STATLIST_CopyStats(pMissile, STAT_DAMAGE_VS_MONTYPE, statBuffer, 128);
                for (int i = 0; i < nStats; ++i)
                {
                    if (SUNITDMG_CheckMonType(statBuffer[i].nLayer, nMonType))
                    {
                        nDamagePercent += statBuffer[i].nValue;
                    }
                }
            }
        }

        if (nDamagePercent <= -90)
        {
            nDamagePercent = -90;
        }

        pDamage->dwPhysDamage += nDamagePercent * pDamage->dwPhysDamage / 100;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_ITEM_DEADLYSTRIKE, 0))
    {
        pDamage->dwPhysDamage *= 2;
        pDamage->wResultFlags |= DAMAGERESULTFLAG_CRITICALSTRIKE;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_BYPASS_UNDEAD, 0))
    {
        pDamage->dwHitFlags |= DAMAGEHITFLAG_BYPASSUNDEAD;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_BYPASS_DEMONS, 0))
    {
        pDamage->dwHitFlags |= DAMAGEHITFLAG_BYPASSDEMON;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_BYPASS_BEASTS, 0))
    {
        pDamage->dwHitFlags |= DAMAGEHITFLAG_BYPASSBEASTS;
    }
}

// build: context MISSMODE_GetDamageValue
int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (!pAttacker)
    {
        return 0;
    }

    switch (MISSILE_GetElemTypeFromMissileId(pAttacker->dwClassId))
    {
    case 0:
    {
        pDamage->dwPhysDamage = MISSMODE_RollDamageValue(pAttacker, STAT_MINDAMAGE, -1, STAT_MAXDAMAGE);

        if (pDefender)
        {
            int nDamagePercent = STATLIST_UnitGetStatValue(pAttacker, STAT_DAMAGEPERCENT, 0);
            if (MONSTERS_IsDemon(pDefender))
            {
                nDamagePercent += STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
            }

            if (MONSTERS_IsUndead(pDefender))
            {
                nDamagePercent += STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
            }

            if (nDamagePercent <= -90)
            {
                nDamagePercent = -90;
            }

            pDamage->dwPhysDamage += pDamage->dwPhysDamage * nDamagePercent / 100;
        }

        if (STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_DEADLYSTRIKE, 0))
        {
            pDamage->dwPhysDamage *= 2;
            pDamage->wResultFlags |= DAMAGERESULTFLAG_CRITICALSTRIKE;
        }

        return pDamage->dwPhysDamage;
    }
    case 1:
    {
        pDamage->dwFireDamage = MISSMODE_RollDamageValue(pAttacker, STAT_FIREMINDAM, STAT_PASSIVE_FIRE_MASTERY, STAT_FIREMAXDAM);
        return pDamage->dwFireDamage;
    }
    case 2:
    {
        pDamage->dwLtngDamage = MISSMODE_RollDamageValue(pAttacker, STAT_LIGHTMINDAM, STAT_PASSIVE_LTNG_MASTERY, STAT_LIGHTMAXDAM);
        return pDamage->dwLtngDamage;
    }
    case 3:
    {
        pDamage->dwMagDamage = MISSMODE_RollDamageValue(pAttacker, STAT_MAGICMINDAM, STAT_PASSIVE_MAG_MASTERY, STAT_MAGICMAXDAM);
        return pDamage->dwMagDamage;
    }
    case 4:
    {
        pDamage->dwColdDamage = MISSMODE_RollDamageValue(pAttacker, STAT_COLDMINDAM, STAT_PASSIVE_COLD_MASTERY, STAT_COLDMAXDAM);
        pDamage->dwColdLen = STATLIST_UnitGetStatValue(pAttacker, STAT_COLDLENGTH, 0);
        return pDamage->dwColdDamage;
    }
    case 5:
    {
        pDamage->dwPoisDamage = MISSMODE_RollDamageValue(pAttacker, STAT_POISONMINDAM, STAT_PASSIVE_POIS_MASTERY, STAT_POISONMAXDAM);
        pDamage->dwPoisLen = STATLIST_UnitGetStatValue(pAttacker, STAT_POISONLENGTH, 0);

        const int nPoisonCount = STATLIST_UnitGetStatValue(pAttacker, STAT_POISON_COUNT, 0);
        if (nPoisonCount > 1)
        {
            pDamage->dwPoisLen /= nPoisonCount;
        }
        return 25 * pDamage->dwPoisDamage;
    }
    case 6:
    {
        pDamage->dwLifeLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_LIFEDRAINMINDAM, 0);
        return 0;
    }
    case 7:
    {
        pDamage->dwManaLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_MANADRAINMINDAM, 0);
        return 0;
    }
    case 8:
    {
        pDamage->dwStamLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_STAMDRAINMINDAM, 0);
        return 0;
    }
    case 9:
    {
        pDamage->dwStunLen = STATLIST_UnitGetStatValue(pAttacker, STAT_STUNLENGTH, 0);
        return 0;
    }
    case 11:
    {
        pDamage->dwBurnDamage = MISSMODE_RollDamageValue(pAttacker, STAT_BURNINGMIN, STAT_PASSIVE_FIRE_MASTERY, STAT_BURNINGMAX);
        pDamage->dwBurnLen = STATLIST_UnitGetStatValue(pAttacker, STAT_FIRELENGTH, 0);
        return 25 * pDamage->dwBurnDamage;
    }
    case 12:
    {
        pDamage->dwColdDamage = MISSMODE_RollDamageValue(pAttacker, STAT_COLDMINDAM, STAT_PASSIVE_COLD_MASTERY, STAT_COLDMAXDAM);
        pDamage->dwFrzLen = STATLIST_UnitGetStatValue(pAttacker, STAT_COLDLENGTH, 0);
        return pDamage->dwColdDamage;
    }
    default:
        break;
    }

    return 0;
}

// 0x005A9FB0
int __fastcall MISSMODE_SrvHit07_HolyBolt_FistOfTheHeavenBolt(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pMissilesTxtRecord->dwHitPar[0] && pOwner
        && (SUNIT_CanPetBeTargetedBySkill(pGame, pOwner, pUnit, nSkillId) || SUNIT_CanAllyBeTargetedBySkill(pGame, pOwner, pUnit, nSkillId)))
    {
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            const int nMin = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel) << 8;
            const int nMax = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel) << 8;
            int nRand = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin) + nMin;
            if (nRand <= 0)
            {
                nRand = MISSMODE_RollDamageValue(pMissile, STAT_MINDAMAGE, -1, STAT_MAXDAMAGE);
            }

            int nNewHp = nRand + STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
            const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (nNewHp >= nMaxHp)
            {
                nNewHp = nMaxHp;
            }
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

            const short nOverlay = pMissilesTxtRecord->wProgOverlay;
            if (nOverlay > 0)
            {
                UNITS_SetOverlay(pUnit, nOverlay, 0);
            }
        }
        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case 1:
        switch (pMissilesTxtRecord->dwHitPar[1])
        {
        case 0:
            return 3;

        case 2:
            if (MONSTERS_IsDemon(pUnit))
            {
                return 3;
            }
            break;

        default:
            if (MONSTERS_IsUndead(pUnit))
            {
                return 3;
            }
            break;
        }
        break;

    case 0:
        if (!pMissilesTxtRecord->dwHitPar[1])
        {
            return 3;
        }
        break;
    }

    return 4;
}

// 0x005A8F20
void __fastcall sub_005A8F20_SetElementalDamage(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, D2DamageStrc* pDamage, int nValue)
{
    if (pMissile)
    {
        switch (MISSILE_GetElemTypeFromMissileId(!pMissile ? -1 : pMissile->dwClassId))
        {
        case 4:
            pDamage->dwColdLen = nValue;
            break;
        case 5:
            pDamage->dwPoisLen = nValue;
            break;
        case 9:
            pDamage->dwStunLen = nValue;
            break;
        case 11:
            pDamage->dwBurnLen = nValue;
            break;
        case 12:
            pDamage->dwFrzLen = nValue;
            break;
        }
    }
}

static __forceinline int GetClassId(Unit* unit) { return unit->classId; }

// 0x005A8FB0
void __fastcall sub_005A8FB0(Game* game,Unit* missile,Unit* owner,Damage* damage,int value)
{
    if (!missile) return;
    switch (MISSILE_GetElemTypeFromMissileId(GetClassId(missile))) {
    case 0: damage->physical=value; break;
    case 1: damage->fire=value; break;
    case 2: damage->lightning=value; break;
    case 3: damage->magic=value; break;
    case 4: damage->cold=value; if (value<=ZERO_DAMAGE) damage->coldLength=0; break;
    case 5: damage->poison=value; if (value<=ZERO_DAMAGE) damage->poisonLength=0; break;
    case 6: damage->lifeLeech=value; break;
    case 7: damage->manaLeech=value; break;
    case 8: damage->staminaLeech=value; break;
    case 9: damage->stunLength=value; break;
    case 11: damage->burn=value; if (value<=ZERO_DAMAGE) damage->burnLength=0; break;
    case 12: damage->cold=value; if (value<=ZERO_DAMAGE) damage->freezeLength=0; break;
    }
}

// 0x005A90E0
int __fastcall sub_005A90E0_GetDamageValue(D2GameStrc* game, D2UnitStrc* missile, D2UnitStrc* unit, D2DamageStrc* damage, int unused)
{
 if (!missile) return 0;
 switch (MISSILE_GetElemTypeFromMissileId(!missile ? -1 : missile->dwClassId)) {
 case 0: return damage->dwPhysDamage;
 case 1: return damage->dwFireDamage;
 case 2: return damage->dwLtngDamage;
 case 3: return damage->dwMagDamage;
 case 4: return damage->dwColdDamage;
 case 5: return damage->dwPoisDamage;
 case 6: return damage->dwLifeLeech;
 case 7: return damage->dwManaLeech;
 case 8: return damage->dwStamLeech;
 case 9: return damage->dwStunLen;
 case 11: return damage->dwBurnDamage;
 case 12: return damage->dwColdDamage;
 default: return 0;
 }
}

// 0x005A94C0
static int __stdcall sub_005A94C0_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

int __stdcall sub_K13_Emit_005A94C0(D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY, int nMaxDistanceSq, int nX, int nY)
{
    return sub_005A94C0_CheckDistanceAndLineOfSight(nMaxDistanceSq, nX, nY, pRoom, nOffsetX, nOffsetY);
}
