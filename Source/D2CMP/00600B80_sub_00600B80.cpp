extern "C" const char szPalShiftGrey_006DCDA0[];                                                            // 0x006DCDA0
extern "C" const char szPalShiftGrey2_006DCD98[];                                                           // 0x006DCD98
extern "C" const char szPalShiftGold_006DCD90[];                                                            // 0x006DCD90
extern "C" const char szPalShiftBrown_006DCD88[];                                                           // 0x006DCD88
extern "C" const char szPalShiftGreyBrown_006DCD7C[];                                                       // 0x006DCD7C
extern "C" const char szPalShiftInvGrey_006DCD74[];                                                         // 0x006DCD74
extern "C" const char szPalShiftInvGrey2_006DCD68[];                                                        // 0x006DCD68
extern "C" const char szPalShiftInvGreyBrown_006DCD58[];                                                    // 0x006DCD58
void __fastcall sub_006009C0(const char* szName, int nIndex);                                              // 0x006009C0

// 0x00600B80
void __cdecl sub_00600B80()
{
    sub_006009C0(szPalShiftGrey_006DCDA0, 1);
    sub_006009C0(szPalShiftGrey2_006DCD98, 2);
    sub_006009C0(szPalShiftGold_006DCD90, 3);
    sub_006009C0(szPalShiftBrown_006DCD88, 4);
    sub_006009C0(szPalShiftGreyBrown_006DCD7C, 5);
    sub_006009C0(szPalShiftInvGrey_006DCD74, 6);
    sub_006009C0(szPalShiftInvGrey2_006DCD68, 7);
    sub_006009C0(szPalShiftInvGreyBrown_006DCD58, 8);
}
