struct D2UnitStrc;

extern int gdwGlobal_007A6ABC;                                                                              // 0x007A6ABC
extern int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
extern int gdwGlobal_007A6AE0;                                                                              // 0x007A6AE0
int gdwGlobal_007A6AF0;                                                                                     // 0x007A6AF0

// 0x00468070
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem)
{
    gdwGlobal_007A6ABC = (int)pItem;
    gnGlobal_007A6ADC = 5;
    if (!pItem)
    {
        gdwGlobal_007A6AE0 = 0;
        gdwGlobal_007A6AF0 = 1;
    }
    else
    {
        gdwGlobal_007A6AE0 = 0;
        gdwGlobal_007A6AF0 = 1;
        gdwGlobal_007A6AF0 = 4;
    }
}
