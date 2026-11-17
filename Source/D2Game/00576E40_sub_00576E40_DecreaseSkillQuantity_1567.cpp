struct D2SkillStrc;
struct D2ClientStrc;
struct D2UnitStrc { int type, classId; void* pool; int id; };
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetQuantity(D2SkillStrc*); // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc*, int); // 0x00645120
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0
void __fastcall sub_005701B0_AssignSkill(D2UnitStrc*, int, int, int); // 0x005701B0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*, const char*, int); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc*, unsigned char, int, int, int); // 0x0053C520
extern const char gszUnitNpcSource_006E15F0[]; // 0x006E15F0
// 0x00576E40
void __fastcall sub_00576E40_DecreaseSkillQuantity(D2UnitStrc* unit, int skillId, int decrement)
{
    if (skillId < 0) return;
    D2SkillStrc* skill = SKILLS_GetHighestLevelSkillFromUnitAndId(unit, skillId);
    if (!skill) return;
    int quantity = SKILLS_GetQuantity(skill) - decrement;
    if (quantity <= 0) {
        if (UNITS_GetRightSkill(unit) == skill) sub_005701B0_AssignSkill(unit, 0, 0, -1);
        quantity = 0;
    }
    SKILLS_SetQuantity(skill, quantity);
    int id, type;
    if (!unit) { id = -1; type = 6; }
    else { id = unit->id; type = unit->type; }
    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(unit, gszUnitNpcSource_006E15F0, 0x40b), (unsigned char)type, id, skillId, quantity);
}
