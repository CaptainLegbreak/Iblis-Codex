struct D2GameStrc;
struct D2UnitStrc;
struct D2SkillStrc;

int __fastcall sub_6FD119C0(D2UnitStrc* pUnit);                                                             // 0x0056C4E0
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00580310
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00580380
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
void __fastcall sub_6FC7D260(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4);                 // 0x005750E0

// 0x0056CAB0
int __fastcall SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_6FD119C0(pUnit))
    {
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        return 0;
    }

    return 1;
}

// 0x0056CC20
int __fastcall SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;

    sub_6FC7D260(pGame, pUnit, SKILLS_GetParam1(pSkill), 1);
    return 1;
}
