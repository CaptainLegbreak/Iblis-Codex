struct Unicode;
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int gnAutomapWidth_007A5220;                                                                                // 0x007A5220
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern unsigned char gbGlobal_007A0522;                                                                     // 0x007A0522

// 0x004AAAA0
static void __stdcall sub_004AAAA0_DrawSkillTreeText(const Unicode* wszText, int nY)
{
    const int nTextY = gnGlobal_00711470 + gnGlobal_007A285C + nY - 0x1E0;
    sub_004A7080(gnAutomapWidth_007A5220 - gnGlobal_007A2858 - 0x5A, nTextY, gnAutomapWidth_007A5220 - gnGlobal_007A2858, wszText, 0);
}

#define TEXT(y, id) sub_004AAAA0_DrawSkillTreeText(D2LANG_GetStringFromTblIndex(id), y)

// 0x004AACE0
void __cdecl sub_004AACE0_DrawSkillTreeTexts()
{
    TEXT(0x19, 0x1083);
    TEXT(0x25, 0x1084);
    TEXT(0x31, 0x1085);

    if (gbGlobal_007A0522 == 0)
    {
        TEXT(0x96, 0x1088);
        TEXT(0xA2, 0x1089);
        TEXT(0xAE, 0x1086);
        TEXT(0x102, 0x108A);
        TEXT(0x10E, 0x108B);
        TEXT(0x11A, 0x1086);
        TEXT(0x167, 0x108C);
        TEXT(0x173, 0x108D);
        TEXT(0x17F, 0x1086);
    }
    else if (gbGlobal_007A0522 == 3)
    {
        TEXT(0x9C, 0x108E);
        TEXT(0xA8, 0x108F);
        TEXT(0x108, 0x1090);
        TEXT(0x114, 0x108F);
        TEXT(0x172, 0x1091);
        TEXT(0x17E, 0x1086);
    }
    else if (gbGlobal_007A0522 == 2)
    {
        TEXT(0x9C, 0x1092);
        TEXT(0xA8, 0x1087);
        TEXT(0x102, 0x1093);
        TEXT(0x10E, 0x1094);
        TEXT(0x11A, 0x1087);
        TEXT(0x178, 0x1095);
    }
    else if (gbGlobal_007A0522 == 4)
    {
        TEXT(0xA2, 0x1096);
        TEXT(0x108, 0x1097);
        TEXT(0x114, 0x1098);
        TEXT(0x172, 0x1097);
        TEXT(0x17E, 0x1086);
    }
    else if (gbGlobal_007A0522 == 1)
    {
        TEXT(0x9C, 0x1099);
        TEXT(0xA8, 0x1087);
        TEXT(0x108, 0x109A);
        TEXT(0x114, 0x1087);
        TEXT(0x172, 0x109B);
        TEXT(0x17E, 0x1087);
    }
    else if (gbGlobal_007A0522 == 6)
    {
        TEXT(0x96, 0x57F4);
        TEXT(0xA2, 0x57F5);
        TEXT(0x108, 0x57F2);
        TEXT(0x114, 0x57F3);
        TEXT(0x172, 0x57F1);
    }
    else if (gbGlobal_007A0522 == 5)
    {
        TEXT(0xA2, 0x57F0);
        TEXT(0x108, 0x57EE);
        TEXT(0x114, 0x57EF);
        TEXT(0x172, 0x57ED);
    }
}
