struct D2GameStrc;
struct D2UnitStrc;

int __fastcall sub_005C4DF0_DetonateCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C4DF0

// 0x005C50B0
int __fastcall SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return sub_005C4DF0_DetonateCorpse(pGame, pUnit, nSkillId, nSkillLevel);
}
