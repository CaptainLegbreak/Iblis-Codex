struct D2UnitStrc;

struct D2SkillIconStateStrc
{
    char unk0x000[0x2D0];
    int anValues[60];
    unsigned char bFlag;
    char unk0x3C1[0x4];
};

extern D2SkillIconStateStrc gtSkillIconState_007C0300;                                                      // 0x007C0300
extern int gbGlobal_007C07FC;                                                                               // 0x007C07FC
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern "C" { int gnValue_007C0C3C; }                                                                        // 0x007C0C3C

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
void __fastcall sub_004AA3A0_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0

// 0x004AA6B0
void __fastcall sub_004AA6B0_BuildLeftRows(int bNoDraw)
{
    if (!gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnGlobal_0071146C - 0x80, 0, 0, bNoDraw);
    }
}

// 0x004AA6E0
void __cdecl sub_004AA6E0_BuildRightRows2()
{
    if (gbGlobal_007C07FC)
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
}

// 0x004AA710
void __cdecl sub_004AA710_BuildLeftRows2()
{
    if (!gbGlobal_007C07FC)
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnGlobal_0071146C - 0x80, 0, 1, 0);
}

// 0x004AA8E0
void __cdecl sub_004AA8E0_ClearValue7C0C3C()
{
    gnValue_007C0C3C = 0;
}
