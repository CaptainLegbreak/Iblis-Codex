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

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004AA3A0_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0

// 0x004AA680
void __cdecl sub_004AA680_BuildRightRows()
{
    if (gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0_BuildSkillRows(sub_00463DD0(), 0x50, 1, 0, 0);
    }
}
