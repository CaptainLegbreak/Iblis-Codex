struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

void __stdcall sub_00649F70(D2UnitStrc* pUnit, int nArg);                                                   // 0x00649F70

// 0x005CAF80
int __fastcall SKILLS_SrvSt43_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    sub_00649F70(pUnit, 1);
    return 1;
}
