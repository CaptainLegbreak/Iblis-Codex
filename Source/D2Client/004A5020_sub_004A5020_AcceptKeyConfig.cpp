void __cdecl sub_00469D40_SaveAndBindHotkeys();                                                             // 0x00469D40
void __cdecl sub_00469D50();                                                                                // 0x00469D50
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __fastcall sub_0047E200_CloseMenus(int bRestore);                                                      // 0x0047E200
void __fastcall sub_0047E090(int bSaveState, int nMenu);                                                // 0x0047E090

// 0x004A5020
void __cdecl sub_004A5020_AcceptKeyConfig()
{
    sub_00469D40_SaveAndBindHotkeys();
    sub_00455F20(11, 1, 0);
    sub_0047E200_CloseMenus(1);
}

// 0x004A5040
void __cdecl sub_004A5040_CancelKeyConfig()
{
    sub_00469D50();
    sub_00455F20(11, 1, 0);
    sub_0047E090(0, 1);
}
