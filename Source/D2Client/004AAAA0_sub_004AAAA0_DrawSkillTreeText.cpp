struct Unicode;
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00711470;                                                                               // 0x00711470

// 0x004AAAA0
static __declspec(noinline) void __stdcall sub_004AAAA0_DrawSkillTreeText(int nY, const Unicode* wszText)
{
    const int nRight = gnAutomapWidth_007A5220 - gnGlobal_007A2858;
    sub_004A7080(nRight - 0x5A, gnGlobal_00711470 + gnGlobal_007A285C + nY - 0x1E0, nRight, wszText, 0);
}

void __fastcall sub_M26_Emit_004AB090(char nMode)
{
    if (nMode == 2)
    {
        sub_004AAAA0_DrawSkillTreeText(0x9C, D2LANG_GetStringFromTblIndex(0x1092));
        sub_004AAAA0_DrawSkillTreeText(0xA8, D2LANG_GetStringFromTblIndex(0x1087));
    }
}
