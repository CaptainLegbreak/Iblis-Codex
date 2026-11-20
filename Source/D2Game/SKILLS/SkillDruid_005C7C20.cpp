#include "D2Game.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[20];
    unsigned int dwHitClass;
    int unk0x64[3];
};



extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned short __fastcall sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall sub_6FD11D90(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId);         // 0x0056C840
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20
void __fastcall sub_6FCFEDD0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nFrame, int nSkillId, int nSkillLevel); // 0x005C7DB0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C7C20
static void __stdcall sub_005C7C20_RabiesDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nLength, int nSkillLevel)
{
    if (nLength < 10)
    {
        nLength = 10;
    }

    D2DamageStrc damage = {};
    sub_6FD155E0(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    sub_6FD11D90(pUnit, &damage, nLength, nSkillId);
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
}

// 0x005C8AD0
int __fastcall SKILLS_SrvDo121_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 967) != nSkillId || !SKILLS_GetParam1(pSkill))
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    sub_6FD00370(pGame, pUnit, nSkillLevel);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    sub_6FCFEDD0(pGame, pUnit, pTarget, nLength, nSkillId, nSkillLevel);
    sub_005C7C20_RabiesDamage(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nLength, nSkillLevel);
    return 1;
}
