#include "D2Game.h"

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
    int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    char unk0x08[0x68];
};

struct D2SkillsTxt
{
    char unk0x000[0x138];
    unsigned int dwCalc[4];
    char unk0x148[0x23C - 0x148];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage); // 0x0057CEE0
void __fastcall SUNITDMG_RollDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E240
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short wFlag);                     // 0x005A0180
int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D30F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall MONSTERS_IsBoss(int* pMonStatsTxt, D2UnitStrc* pUnit);                                        // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline unsigned __int64 ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x005D3140
int __fastcall SKILLS_SrvDo033_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!SKILLS_SrvSt22_PsychicHammer(pGame, pUnit, nSkillId, nSkillLevel))
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SUNITDMG_RollDamage(pUnit, nSkillId, nSkillLevel, &damage);
    SUNITDMG_ExecuteEvents(pGame, pUnit, pTargetUnit, 1, &damage);
    damage.wResultFlags |= 1;

    const int nTargetLevel = STATLIST_UnitGetStatValue(pTargetUnit, 12, 0);
    int nLevel = nTargetLevel + nSkillLevel - STATLIST_UnitGetStatValue(pTargetUnit, 12, 0);
    nLevel = D2_MIN(D2_MAX(nLevel, 1), nSkillLevel);

    int nChance;
    if (!(pTargetUnit && pTargetUnit->dwUnitType == 0) && !MONSTERS_GetHirelingTypeId(pTargetUnit))
    {
        if (MONSTERS_IsBoss(0, pTargetUnit))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pTargetUnit, 8))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }
        else
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        }
    }
    else
    {
        nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
    }

    if (nChance > 0)
    {
        unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nHighSeed + (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((int)((unsigned int)lSeed % 100) < nChance)
        {
            damage.wResultFlags |= 8;
        }
    }

    if (!(STATLIST_UnitGetStatValue(pTargetUnit, 6, 0) & 0xFFFFFF00))
    {
        damage.wResultFlags |= 2;
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTargetUnit, &damage);
    return 1;
}
