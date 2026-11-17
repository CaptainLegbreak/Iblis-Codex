struct Game; struct Skill;
struct Unit { char pad[0xC4]; unsigned int flags; };
Skill* __stdcall sub_00620250(Unit*);  // 0x00620250
Unit* __stdcall sub_00553540(Game*, Unit*);  // 0x00553540
void __fastcall sub_0057C9F0(Game*, Unit*, Unit*);  // 0x0057C9F0
int __fastcall sub_005CDD30(Unit*);  // 0x005CDD30
int __fastcall sub_0056F640(Game*, Unit*, int, int, int);  // 0x0056F640
int __fastcall sub_005CDDD0(Game*, Unit*, Unit*, int, int);  // 0x005CDDD0
int __stdcall sub_006444A0(Skill*);  // 0x006444A0
int __fastcall sub_005D8C70(Game*, Unit*, int, int);  // 0x005D8C70
enum { UNIT_FLAG = 0x40 };
// 0x005CDF10
int __fastcall sub_005CDF10(Game* game, Unit* unit, int skillId, int skillLevel)
{
    Skill* skill = sub_00620250(unit);
    if (!skill) return 0;
    Unit* target = sub_00553540(game, unit);
    if (!target) return 0;
    sub_0057C9F0(game, unit, target);
    if (unit) unit->flags |= UNIT_FLAG;
    if (sub_005CDD30(unit)) sub_0056F640(game, unit, skillId, skillLevel, 0);
    sub_005CDDD0(game, unit, target, skillId, skillLevel);
    if (sub_006444A0(skill)) sub_005D8C70(game, unit, skillId, skillLevel);
    return 1;
}
