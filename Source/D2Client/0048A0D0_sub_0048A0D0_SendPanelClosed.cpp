void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                         // 0x00455F20
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600

extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern int gnGlobal_007BCC54;                                                                               // 0x007BCC54
extern int gnGlobal_007BCE30;                                                                               // 0x007BCE30
int gnGlobal_007BCE40;                                                                                      // 0x007BCE40
int gnGlobal_007BCE44;                                                                                      // 0x007BCE44
int gnGlobal_007BCE48;                                                                                      // 0x007BCE48
int gnGlobal_007BCE4C;                                                                                      // 0x007BCE4C

// 0x0048A0D0
void __cdecl sub_0048A0D0_SendPanelClosed()
{
    sub_00478600_SendShorts(0x4F, 0x18, 0, 0);
}

// 0x0048A460
void __cdecl sub_0048A460_CloseCubePanel()
{
    if (sub_00455F20(0x1A, 0, 0))
    {
        gnGlobal_007BCC54 = 0;
        gdwGlobal_007BCBF0 = 0xE;
        sub_0044DA40();
        gnGlobal_007BCE30 = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE4C = 0;
    }
}
