#include "D2Structs.h"
#define SKILL_FLAG 0x40
#define TARGET_FILTER 0x20003
struct D2GameStrc;
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit);                                                             // 0x0056E510
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380
int __fastcall sub_005D8C70_AdvanceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8C70
int __fastcall sub_005D8B10_ApplyToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D8B10
// 0x005D8E00
int __fastcall sub_005D8E00_SequenceAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget) return 0;
    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        sub_005D8C70_AdvanceSkill(pGame, pUnit, nSkillId, nSkillLevel);
        return sub_005D8B10_ApplyToTarget(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    }
    pUnit->dwFlags |= SKILL_FLAG;
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    sub_6FC80A30(pGame, pUnit);
    sub_6FC80E10(pGame, pUnit);
    sub_005D8C70_AdvanceSkill(pGame, pUnit, nSkillId, nSkillLevel);
    const int nAuraRange = SKILLS_GetMeleeSearchRange(pUnit);
    const int nTargetGUID = pTarget->dwUnitId;
    pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, nAuraRange, TARGET_FILTER, nTargetGUID, 0);
    return sub_005D8B10_ApplyToTarget(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
}
