int __stdcall sub_004164B0_SetBasePath(const char* szPath);                                                // 0x004164B0
extern int gdwGlobal_008F03C8;                                                                              // 0x008F03C8

// 0x004067C0
int __cdecl sub_004067C0_SetBasePathToCurrent()
{
    return sub_004164B0_SetBasePath(".\\");
}

// 0x00413740
void __cdecl sub_00413740_Nop()
{
}

// 0x00608520
int __cdecl sub_00608520_ToggleGlobal()
{
    return gdwGlobal_008F03C8 = (gdwGlobal_008F03C8 == 0);
}
