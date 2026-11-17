struct D2WinControlStrc;

void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                         // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __fastcall sub_004FD830(D2WinControlStrc* pControl);                                                   // 0x004FD830
void __fastcall sub_004FDA50(D2WinControlStrc* pControl);                                                   // 0x004FDA50
int __fastcall sub_00431050_ShowCredits(int nUnused);                                                       // 0x00431050
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30

extern D2WinControlStrc* gpList_0077995C;                                                                   // 0x0077995C
extern D2WinControlStrc* gpList_00779960;                                                                   // 0x00779960
extern D2WinControlStrc* gpList_00779964;                                                                   // 0x00779964
D2WinControlStrc* gpControl_00779968;                                                                       // 0x00779968

// 0x004312C0
int __stdcall sub_004312C0_CreateCreditsScreen(int nUnused)
{
    sub_0042F480_Reset();
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_0042F430_CreateControl(0x29);
    sub_0042F430_CreateControl(0x2A);
    if (!sub_00408F20_HasExpansionMpq())
    {
        gpList_0077995C = sub_0042F430_CreateControl(0x2B);
        gpList_00779960 = sub_0042F430_CreateControl(0x2C);
        gpList_00779964 = sub_0042F430_CreateControl(0x2D);
    }
    else
    {
        gpList_0077995C = sub_0042F430_CreateControl(0x2F);
        gpList_00779960 = sub_0042F430_CreateControl(0x30);
        gpList_00779964 = sub_0042F430_CreateControl(0x31);
    }
    gpControl_00779968 = sub_0042F430_CreateControl(0x2E);
    sub_004FD830(gpControl_00779968);
    sub_004FDA50(gpControl_00779968);
    sub_00431050_ShowCredits(0);
    D2Win_10053(gpList_00779964, 20);
    D2Win_10053(gpList_0077995C, 20);
    D2Win_10053(gpList_00779960, 20);
    return 1;
}
