struct Unicode;
struct D2UnitStrc;
struct D2SkillStrc;

char gbTextOffsetInit_007C8C9C;                                                                             // 0x007C8C9C
extern int gnTextOffset1_0072D8D4;                                                                          // 0x0072D8D4
extern int gnTextOffset2_0072D8D0;                                                                          // 0x0072D8D0
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
char gbSkillRefreshInit_007C8CA4;                                                                           // 0x007C8CA4
extern int gnGlobal_0072D844;                                                                               // 0x0072D844
extern int gnGlobal_0072D88C;                                                                               // 0x0072D88C

void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
void __fastcall sub_004ED570(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot);                            // 0x004ED570
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __cdecl sub_00525150();                                                                         // 0x00525150
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

// 0x004E9870
void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2)
{
    sub_00502EF0(6);
    if (!gbTextOffsetInit_007C8C9C)
    {
        if (sub_00525150() >= 6 && sub_00525150() <= 9)
        {
            gnTextOffset1_0072D8D4 = -7;
        }
        else
        {
            gnTextOffset1_0072D8D4 = -6;
        }

        gbTextOffsetInit_007C8C9C = 1;
    }

    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_00711470 + gnGlobal_007A285C + gnTextOffset1_0072D8D4 + nY - 480, gnGlobal_007A2858 + nRight, wszText1, nColor1);
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnTextOffset2_0072D8D0 + gnGlobal_00711470 + gnGlobal_007A285C + nY - 480, gnGlobal_007A2858 + nRight, wszText2, nColor2);
}

// 0x004EDA20
void __fastcall sub_004EDA20_RefreshSkills(D2UnitStrc* pUnit)
{
    if (!gbSkillRefreshInit_007C8CA4)
    {
        if (sub_00525150() >= 6 && sub_00525150() <= 9)
        {
            gnGlobal_0072D844 -= 1;
            gnGlobal_0072D88C -= 1;
        }

        gbSkillRefreshInit_007C8CA4 = 1;
    }

    if (pUnit)
    {
        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        sub_004ED570(pUnit, pSkill, 0);
        pSkill = UNITS_GetRightSkill(pUnit);
        sub_004ED570(pUnit, pSkill, 6);
    }
}

#include "gen/data/Source/D2Client/004E9870_sub_004E9870_DrawTwoTexts.inc"
