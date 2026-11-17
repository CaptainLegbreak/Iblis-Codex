extern int gnGlobal_007BCA4C;                                                                               // 0x007BCA4C
extern int gnGlobal_007BCBD8;                                                                               // 0x007BCBD8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0

// 0x004880F0
void __cdecl sub_004880F0_ClearClickPos()
{
    gnGlobal_007BCA4C = 0;
    gnGlobal_007BCBD8 = 0;
}

// 0x00488890
int __cdecl sub_00488890_IsNpcStateMenu()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 4
        || gdwGlobal_007BCBF0 == 9)
    {
        return 1;
    }

    return 0;
}
