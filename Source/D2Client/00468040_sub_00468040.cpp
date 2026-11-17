int gdwGlobal_007A6ABC;                                                                                     // 0x007A6ABC
int gdwGlobal_007A6ADC;                                                                                     // 0x007A6ADC
extern int gdwGlobal_007A6AE0;                                                                              // 0x007A6AE0
extern int gdwGlobal_007A6AF0;                                                                              // 0x007A6AF0

// 0x00468040
void __fastcall sub_00468040(int nArg, int nArg2)
{
    gdwGlobal_007A6ABC = 0;
    gdwGlobal_007A6ADC = 6;
    gdwGlobal_007A6AE0 = nArg;
    gdwGlobal_007A6AF0 = nArg2 ? 8 : 7;
}
