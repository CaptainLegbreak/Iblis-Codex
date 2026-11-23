#include "D2Client.h"
struct D2UnitStrc;

extern D2SkillIconStateStrc gtHotkeySlots;                                                      // 0x007C0300
extern int gbSkillSelectRight;                                                                               // 0x007C07FC
extern int gnScreenWidth;                                                                               // 0x0071146C
extern "C" { int gbSkillPointsHighlight; }                                                                        // 0x007C0C3C

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0

// 0x004AA6B0
void __fastcall sub_004AA6B0_BuildLeftRows(int bNoDraw)
{
    if (!gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 0, bNoDraw);
    }
}

// 0x004AA6E0
void __cdecl sub_004AA6E0_BuildRightRows2()
{
    if (gbSkillSelectRight)
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
}

// 0x004AA710
void __cdecl sub_004AA710_BuildLeftRows2()
{
    if (!gbSkillSelectRight)
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 1, 0);
}

// 0x004AA8E0
void __cdecl sub_004AA8E0_ClearValue7C0C3C()
{
    gbSkillPointsHighlight = 0;
}
