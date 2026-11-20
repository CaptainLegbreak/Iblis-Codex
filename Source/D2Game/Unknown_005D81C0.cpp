#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
struct D2GameStrc;
struct D2UnitStrc;



struct D2SkillsTxt
{
    char unk_000[0x138];
    int dwCalc[4];
    char unk_148[0x23C - 0x148];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall sub_00645590_IsSelectableSoftCorpse(D2UnitStrc* pUnit); // 0x00645590
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x0056DAB0
int __stdcall shim_1(void* p1, void* p2);

// build: context sub_005D8100
static __declspec(noinline) int __stdcall sub_005D8100(D2UnitStrc* pUnit, D2GameStrc* pGame, int nSkillId)
{

    pUnit->dwUnitType = 0;
    return shim_1(&pGame, &nSkillId);
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int SKILLS_IsUnlootedCorpse(D2UnitStrc* pTarget)
{
    return pTarget && sub_00645590_IsSelectableSoftCorpse(pTarget) && !STATES_CheckState(pTarget, 118);
}

// 0x005D81C0
int __fastcall SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!SKILLS_IsUnlootedCorpse(pTarget))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 118, 1);
    UNITROOM_RefreshUnit(pTarget);

    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
    {
        const int dwCode = sub_005D8100(pUnit, pGame, nSkillId);
        OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, dwCode, 2);
    }

    return 1;
}
