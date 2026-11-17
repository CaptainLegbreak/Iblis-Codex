struct D2GameStrc;

struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlags;
};

// 0x005CC1D0
int __fastcall SKILLS_SrvSt51_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    return 1;
}
