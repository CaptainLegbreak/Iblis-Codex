#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

union D2SeedStrc;

struct D2SkillsTxt;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2DataTablesStrc;

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0

void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F850

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

static void __stdcall sub_005DAA40_ImpaleWearItem(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x005DAA40

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

static inline unsigned int sub_M401_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005DAA40
static void __stdcall sub_005DAA40_ImpaleWearItem(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (!ITEMSIsA(pItem, 0x2D))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
        {
            sub_6FD118C0(pGame, pUnit);
        }
    }
    else if (ITEMS_HasDurability(pItem) && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
    {
        int nNewDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) - nAmount;
        if (nNewDurability < 0)
        {
            nNewDurability = 0;
        }

        if (nNewDurability)
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nNewDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\SKILLS\\SkillAma.cpp", 0x9B), pItem, 1, 0x48, nNewDurability, 0);
        }
        else
        {
            sub_6FC4B580(pGame, pUnit, pItem);
        }
    }
}

int __fastcall sub_M401_Emit_005DAB40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nChance, int nAmount)
{
    D2UnitStrc* pItem = sub_6FC7C7B0(pUnit);
    if (!pItem)
    {
        return 0;
    }

    sub_005DAA40_ImpaleWearItem(pGame, nChance, nAmount + 7, pItem, pUnit);
    return 9;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005DAB40
int __fastcall sub_005DAB40(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DamageStrc damage;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget && SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
        {
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
            if (damage.wResultFlags & 1)
            {
                const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                damage.dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pUnit, 1, 0, 0, 0, nDamagePercent, 0, pSkillsTxtRecord->nSrcDam);
                if (pSkillsTxtRecord->nEType > 0)
                {
                    damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
                    if (damage.dwConvPct > 0)
                    {
                        damage.nConvType = pSkillsTxtRecord->nEType;
                    }
                }

                D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
                damage.dwHitFlags = 1;

                D2UnitStrc* pItem = sub_6FC7C7B0(pUnit);
                if (pItem && ITEMS_HasDurability(pItem))
                {
                    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
                    const int nAmount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
                    sub_005DAA40_ImpaleWearItem(pGame, nChance, nAmount, pItem, pUnit);
                }
            }

            SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
            return 1;
        }
    }

    return 0;
}

// 0x005DB020
int __fastcall SKILLS_SrvSt10_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
    if (damage.wResultFlags & 1)
    {
        const int nMinDamage = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        const int nMaxDamage = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        damage.dwLtngDamage = nMinDamage + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage);
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

int __fastcall sub_6FD119C0(D2UnitStrc* pUnit); // 0x0056C4E0

void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310

void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380

int __fastcall sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter); // 0x0056BC80

D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int nPrevious, int* pCount); // 0x0056BD10

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x005DACD0
int __fastcall SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!sub_6FD119C0(pUnit))
    {
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        return 0;
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);

    int nTargetCount = 0;
    if (!pTarget)
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nAuraRange, 3, -1, &nTargetCount);
    }
    else
    {
        nTargetCount = sub_6FD10790(pGame, pUnit, 0, 0, nAuraRange, 3);
    }

    int nDesiredShots = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
    int nShotsRemaining = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nDesiredShots > nShotsRemaining)
    {
        nDesiredShots = nShotsRemaining;
    }

    nTargetCount = D2_MIN(D2_MAX(nTargetCount, nDesiredShots), nShotsRemaining);
    SKILLS_SetParam1(pSkill, nTargetCount);

    if (pTarget)
    {
        SKILLS_SetParam2(pSkill, sub_0044BE50(pTarget));
        SKILLS_SetParam3(pSkill, UNITS_GetUnitId(pTarget));
    }
    else
    {
        SKILLS_SetParam2(pSkill, 1);
        SKILLS_SetParam3(pSkill, -1);
    }

    sub_6FD118C0(pGame, pUnit);
    return 1;
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

// 0x005DAE30
int __fastcall sub_005DAE30_InitializeMeleeTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    int nRange = sub_6FD15460(pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nTargets = 0;
    if (!pTarget)
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nRange, 0x20003, -1, &nTargets);
        if (!pTarget)
        {
            SKILLS_SetParam1(pSkill, 0);
            return 1;
        }
    }
    else
        nTargets = sub_6FD10790(pGame, pUnit, 0, 0, nRange, 0x20003);
    int nMaxTargets = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nTargets >= nMaxTargets)
        nTargets = nMaxTargets;
    SKILLS_SetParam1(pSkill, nTargets);
    int nTargetType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    SKILLS_SetParam2(pSkill, nTargetType);
    nRange = pTarget ? pTarget->dwUnitId : -1;
    SKILLS_SetParam3(pSkill, nRange);
    return 1;
}
struct D2StaticPathStrc;

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc*, D2UnitStrc*, int*, int*); // 0x0056D2C0

void __fastcall SKILLS_EnlargeVector(int*, int*); // 0x0056D370

void __fastcall SKILLS_MakeShortPerpendicularVector(int*, int*); // 0x0056D3B0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30

int __fastcall UNITS_GetWeaponClass(D2UnitStrc*); // 0x00623C60

int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

int __stdcall SKILLS_GetParam1(D2SkillStrc*); // 0x006444A0

int __stdcall SKILLS_GetParam2(D2SkillStrc*); // 0x006444D0

int __stdcall SKILLS_GetParam3(D2SkillStrc*); // 0x00644500

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*, D2UnitStrc*); // 0x00620C10

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc*, int); // 0x005DB6A0

int __fastcall sub_004F4110_GetSkillParam5(int); // 0x004F4110

void __fastcall sub_0056E210(D2UnitStrc*, int); // 0x0056E210

int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId); // 0x004EFC20

int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit); // 0x0056E510

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

// 0x005DBC60
int __fastcall SKILLS_SrvDo013_Fend_Zeal_Fury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nAuraRange = SKILLS_GetMeleeSearchRange(pUnit);
    const int nTargetGUID = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), nTargetGUID);
    if (!pTarget || !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nAuraRange, 0x20003, nTargetGUID, 0);
        if (!pTarget)
        {
            return 0;
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }
    }

    unsigned char& nSrcDam = *(unsigned char*)&nSkillLevel;
    nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 4);

    const int nAttacksRemaining = SKILLS_GetParam1(pSkill) - 1;
    SKILLS_SetParam1(pSkill, nAttacksRemaining);
    if (nAttacksRemaining <= 0)
    {
        return 0;
    }

    D2UnitStrc* pNextTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nAuraRange, 0x20003, !pTarget ? -1 : pTarget->dwUnitId, 0);
    if (!pNextTarget)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, !pNextTarget ? 6 : pNextTarget->dwUnitType);
    SKILLS_SetParam3(pSkill, !pNextTarget ? -1 : pNextTarget->dwUnitId);
    sub_0056E210(pUnit, sub_004EFC20_GetSkillParam2(nSkillId));
    return 0;
}

