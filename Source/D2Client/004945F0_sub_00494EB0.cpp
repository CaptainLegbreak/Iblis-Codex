void __cdecl sub_00499E30();
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6);
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
unsigned char gnGlobal_007BEEF8;                                                                            // 0x007BEEF8
extern int gbHelpUiOpened_007BEF00;

// 0x004945F0
void __cdecl sub_00494EB0()
{
    sub_00499E30();
    sub_0046EFD0_DrawFramedBox(0, 0, gnGlobal_0071146C, gnGlobal_00711470 - 0x31, gnGlobal_007BEEF8, 1);
}

void __cdecl sub_00494FC0()
{
    if (gbHelpUiOpened_007BEF00)
    {
        sub_00455F20(0x15, 1, 0);
        gbHelpUiOpened_007BEF00 = 0;
    }
}
