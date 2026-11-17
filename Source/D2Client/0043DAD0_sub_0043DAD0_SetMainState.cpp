struct D2WinControlStrc;

void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                         // 0x004F9740
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C

// 0x0043DAD0
int __fastcall sub_0043DAD0_SetMainState(int bSet)
{
    sub_004F9740_SetControlState(gpControlMain_0077BC4C, bSet);
    return 1;
}
