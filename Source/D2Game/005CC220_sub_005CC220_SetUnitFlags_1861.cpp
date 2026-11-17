struct D2GameStrc;

struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlags;
};

// 0x005CC220
int __fastcall sub_005CC220_SetUnitFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x0E;
    }
    return 1;
}
