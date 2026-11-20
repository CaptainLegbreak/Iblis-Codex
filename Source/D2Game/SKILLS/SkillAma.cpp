#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2SeedStrc;
struct D2SkillsTxt;
struct D2UnitStrc;
struct D2DamageStrc;
struct D2DataTablesStrc;



int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F850
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0

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
    int unk0x40[3];
    int dwDmgTotal;
    int unk0x50[4];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
static void __stdcall sub_005DAA40_ImpaleWearItem(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x005DAA40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

static __forceinline unsigned int sub_M401_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005DAA40
static void __stdcall sub_005DAA40_ImpaleWearItem(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (!ITEMS_CheckItemTypeId(pItem, 0x2D))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0 && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
        {
            sub_6FD118C0(pGame, pUnit);
        }
    }
    else if (ITEMS_HasDurability(pItem) && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
    {
        int nNewDurability = STATLIST_UnitGetStatValue(pItem, 0x48, 0) - nAmount;
        if (nNewDurability < 0)
        {
            nNewDurability = 0;
        }

        if (nNewDurability)
        {
            STATLIST_SetUnitStat(pItem, 0x48, nNewDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillAma.cpp", 0x9B), pItem, 1, 0x48, nNewDurability, 0);
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
        if (pTarget && sub_00554200(pGame, pUnit, pTarget))
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
