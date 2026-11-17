extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern int gdwGlobal_007A0670;                                                                              // 0x007A0670
extern int gnGlobal_007A5254;                                                                               // 0x007A5254
extern int gdwGlobal_007BC974;                                                                              // 0x007BC974
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4

// 0x00402A80
int __cdecl sub_00402A80_IsDbgHelpLoaded()
{
    return ghDbgHelp_0098A680 != 0;
}

// 0x0044BFF0
int __cdecl sub_0044BFF0_IsSet()
{
    return gdwGlobal_007A0670 != 0;
}

// 0x0045FDD0
int __cdecl sub_0045FDD0_IsSet()
{
    return gnGlobal_007A5254 != 0;
}

// 0x0047EC40
int __cdecl sub_0047EC40_IsSet()
{
    return gdwGlobal_007BC974 != 0;
}

// 0x0048A690
int __cdecl sub_0048A690_HasHoverItem()
{
    return gdwGlobal_007BCBF4 != 0;
}
