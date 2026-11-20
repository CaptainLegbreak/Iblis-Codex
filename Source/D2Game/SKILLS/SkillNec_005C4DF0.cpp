#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
struct D2AuraCallbackStrc;
struct D2MonStatsInitStrc { int nMinHP, nMaxHP; int unk_08[12]; };
struct D2UnkNecSkillStrc2 { D2DamageStrc* pDamage; int nX, nY, nSquaredRange; };
typedef int (__fastcall *AURACALLBACK)(D2AuraCallbackStrc*, D2UnitStrc*);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const char gszSkillNecSourceFile[]; // 0x006E3034
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0
int __fastcall DATATBLS_ApplyRatio(int, int, int); // 0x00483360
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
void __fastcall sub_6FD0FE80(D2GameStrc*, D2UnitStrc*, int, int, int, unsigned int, AURACALLBACK, void*, int, const char*, int); // 0x0056B7E0
void __fastcall sub_0056C8E0(D2UnitStrc*, D2DamageStrc*, int, int, int, int*, int*); // 0x0056C8E0
int __fastcall sub_6FD0D000(D2AuraCallbackStrc*, D2UnitStrc*); // 0x005C4D10
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc*, int, int, int); // 0x00644F20
int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc*); // 0x00645680
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int, int, int, int, short, D2MonStatsInitStrc*); // 0x006538A0

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005C4DF0
int __fastcall sub_005C4DF0_DetonateCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !sub_00645680_CanUnitCorpseBeSelected(pTarget))
        return 0;
    STATES_ToggleState(pTarget, 104, 1);
    UNITROOM_RefreshUnit(pTarget);
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
        return 0;
    int nLife = STATLIST_GetUnitBaseStat(pTarget, 7, 0);
    if ((!pTarget ? 6 : pTarget->dwUnitType) == 1)
    {
        int nGameType;
        if (pGame->nGameType || pGame->dwGameType)
            nGameType = 1;
        else
            nGameType = 0;
        D2MonStatsInitStrc monStats;
        memset(&monStats, 0, sizeof(monStats));
        const int nMonsterId = pTarget->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pTarget, 12, 0), 1, &monStats);
        nLife = (monStats.nMinHP + monStats.nMaxHP) << 7;
    }
    int nX = CLIENTS_GetUnitX(pTarget);
    int nY = CLIENTS_GetUnitY(pTarget);
    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nPhysicalRange = nRange / 2;
    int nElementalRange = (nRange + 1) / 2;
    int nMinDamage = DATATBLS_ApplyRatio(SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[0], nSkillId, nSkillLevel), nLife, 100);
    int nMaxDamage = DATATBLS_ApplyRatio(SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[1], nSkillId, nSkillLevel), nLife, 100);
    int nDamage = nMinDamage + ITEMS_RollLimitedRandomNumber(&pTarget->pSeed, nMaxDamage - nMinDamage);
    int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 12, 0);
    int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    if (nTargetLevel && nLevel < nTargetLevel)
        nDamage = DATATBLS_ApplyRatio(nDamage, nLevel, nTargetLevel);
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    int nPct = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[2], nSkillId, nSkillLevel);
    nPct = nPct > 0 ? nPct : 0;
    if (nPct >= 100)
        nPct = 100;
    if (nPct > 0 && pSkills->nEType)
    {
        const int nElementalLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        sub_0056C8E0(pUnit, &damage, pSkills->nEType, DATATBLS_ApplyRatio(nDamage, nPct, 100), nElementalLength, 0, 0);
        nDamage = DATATBLS_ApplyRatio(nDamage, 100 - nPct, 100);
    }
    damage.dwPhysDamage = nDamage;
    D2UnkNecSkillStrc2 args;
    args.pDamage = &damage;
    args.nSquaredRange = nPhysicalRange * nPhysicalRange;
    args.nX = nX;
    args.nY = nY;
    sub_6FD0FE80(pGame, pUnit, nX, nY, nElementalRange, pSkills->dwAuraFilter, sub_6FD0D000, &args, 0, gszSkillNecSourceFile, 0x69E);
    return 1;
}
