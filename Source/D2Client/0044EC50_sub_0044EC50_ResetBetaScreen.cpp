void __cdecl sub_00477EE0();                                                                                // 0x00477EE0
int gdwGlobal_007A0600;                                                                                     // 0x007A0600
extern unsigned char gnBetaScreenIndex_007A060D;                                                            // 0x007A060D
extern int gdwGlobal_007A0620;                                                                              // 0x007A0620

// 0x0044EC50
void __cdecl sub_0044EC50_ResetBetaScreen()
{
    gdwGlobal_007A0600 = 1;
    gnBetaScreenIndex_007A060D = 0;
    sub_00477EE0();
    gdwGlobal_007A0620 = 1;
}
