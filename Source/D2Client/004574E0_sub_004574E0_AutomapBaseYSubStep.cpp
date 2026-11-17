int gnAutomapBaseX_007A5188;                                                                                // 0x007A5188
int gnAutomapBaseY_007A518C;                                                                                // 0x007A518C
extern int gdwGlobal_007113E0;                                                                              // 0x007113E0
extern int gdwGlobal_007A5150;                                                                              // 0x007A5150
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnMiniMapX_007A51DC;                                                                             // 0x007A51DC
extern int gnMiniMapY_007A51D8;                                                                             // 0x007A51D8
void __cdecl sub_00457520_UpdateAutomapLayout();                                                            // 0x00457520

// 0x004574E0
void __stdcall sub_004574E0_AutomapBaseYSubStep(int nUnused)
{
    gnAutomapBaseY_007A518C -= 0x10;
}

// 0x004574F0
void __stdcall sub_004574F0_AutomapBaseXSubStep(int nUnused)
{
    gnAutomapBaseX_007A5188 -= 0x10;
}

// 0x00457500
void __stdcall sub_00457500_AutomapBaseXAddStep(int nUnused)
{
    gnAutomapBaseX_007A5188 += 0x10;
}

// 0x00457640
void __fastcall sub_00457640(int bForce)
{
    if (!gdwGlobal_007113E0 && !bForce)
    {
        return;
    }

    sub_00457520_UpdateAutomapLayout();
    switch (gdwGlobal_007A5150)
    {
    case 1:
        gnAutomapBaseX_007A5188 = gnGlobal_0071146C / 3 - gnMiniMapX_007A51DC - 0x10;
        gnAutomapBaseY_007A518C = gnGlobal_00711470 / 3 - gnMiniMapY_007A51D8 - 0x10;
        break;
    default:
        gnAutomapBaseX_007A5188 = 0;
        gnAutomapBaseY_007A518C = 0;
        break;
    }
}
