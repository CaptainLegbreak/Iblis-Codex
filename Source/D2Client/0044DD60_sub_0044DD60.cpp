void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __cdecl sub_00477EE0();                                                                                // 0x00477EE0

extern int gdwGlobal_007A0620;                                                                              // 0x007A0620
int gdwGlobal_007A0674;                                                                                     // 0x007A0674

// 0x0044DD60
void __cdecl sub_0044DD60()
{
    sub_0044B880_SetValue(0);
    gdwGlobal_007A0674 = 1;
    sub_00477EE0();
    gdwGlobal_007A0620 = 1;
}
