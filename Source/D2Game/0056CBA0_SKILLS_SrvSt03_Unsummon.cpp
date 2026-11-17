struct D2GameStrc;
struct D2SkillStrc;
struct D2UnitStrc { unsigned int type; int classId; void* pool; int id; };
struct D2PetTypeTxt { unsigned int type; unsigned char flags; };
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* game, D2UnitStrc* unit); // 0x00553540
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* unit); // 0x0058F0D0
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* player, int petId); // 0x00574A20
extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int petType); // 0x00478A20
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* unit); // 0x00620250
void __stdcall SKILLS_SetParam1(D2SkillStrc* skill, int value); // 0x00644560
extern const unsigned char gnPetFlag_006CE274; // 0x006CE274
static inline unsigned int sub_0056CBA0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->type;
}

static inline int sub_0056CBA0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->id;
}

// 0x0056CBA0
int __fastcall SKILLS_SrvSt03_Unsummon(D2GameStrc* game, D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2UnitStrc* target = SUNIT_GetTargetUnit(game, unit);
    if (!target)
        return 0;
    if (sub_0056CBA0_GetUnitType(target) != 1)
        return 0;
    if (!unit)
        return 0;
    if (unit->type != 0)
        return 0;
    if (AIGENERAL_GetMinionOwner(target) != unit)
        return 0;
    D2PetTypeTxt* petType = sub_00478A20_GetPetTypeTxtRecord(PLAYERPETS_GetPetTypeFromPetGUID(unit, target->id));
    if (!petType)
        return 0;
    if (!(petType->flags & gnPetFlag_006CE274))
        return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill)
        return 0;
    SKILLS_SetParam1(skill, sub_0056CBA0_GetUnitId(target));
    return 1;
}
