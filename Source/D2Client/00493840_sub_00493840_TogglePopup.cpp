int gnGlobal_007BEECC;                                                                                      // 0x007BEECC
extern int gnGlobal_007BEEE8;                                                                               // 0x007BEEE8
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30

// 0x00493840
void __cdecl sub_00493840_TogglePopup()
{
    switch (gnGlobal_007BEECC)
    {
    case 0:
        if (!sub_0044DB30())
        {
            gnGlobal_007BEECC = 2;
            gnGlobal_007BEEE8 = 0;
            sub_00455F20(0x23, 1, 0);
        }
        else
        {
            gnGlobal_007BEECC = 1;
            sub_00455F20(0x23, 0, 0);
        }
        break;

    case 1:
        if (!sub_0044DB30())
        {
            gnGlobal_007BEECC = 0;
            sub_00455F20(0x23, 0, 0);
        }
        else
        {
            gnGlobal_007BEECC = 2;
            gnGlobal_007BEEE8 = 0;
            sub_00455F20(0x23, 1, 0);
        }
        break;

    default:
        gnGlobal_007BEECC = 0;
        sub_00455F20(0x23, 0, 0);
        break;
    }
}
