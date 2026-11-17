int __stdcall D2GFX_TogglePerspective();                                                                    // 0x004F54B0
int __stdcall D2GFX_ToggleBlendedShadows();                                                                 // 0x004F54D0
int __stdcall D2GFX_ToggleLowQuality();                                                                     // 0x004F54F0

extern "C" int gnModeValue_00712CCC;                                                                        // 0x00712CCC
int gdwGlobal_007BB38C;                                                                                     // 0x007BB38C
extern "C" { int gnFlag_007BB3A8; }                                                                         // 0x007BB3A8

// 0x00477690
int __cdecl sub_00477690_TogglePerspective()
{
    return D2GFX_TogglePerspective();
}

// 0x004776A0
int __cdecl sub_004776A0_ToggleBlendedShadows()
{
    return D2GFX_ToggleBlendedShadows();
}

// 0x004776B0
int __cdecl sub_004776B0_ToggleLowQuality()
{
    return D2GFX_ToggleLowQuality();
}

// 0x004776D0
void __fastcall sub_004776D0_SetModeValues(int nModeValue, int nValue)
{
    gnModeValue_00712CCC = nModeValue;
    gdwGlobal_007BB38C = nValue;
}

// 0x004776E0
void __cdecl sub_004776E0_SetModeValuesOne()
{
    gnModeValue_00712CCC = 1;
    gdwGlobal_007BB38C = 1;
}

// 0x00477970
void __cdecl sub_00477970_Empty()
{
}

// 0x00477BE0
void __cdecl sub_00477BE0_ToggleFlag7BB3A8()
{
    gnFlag_007BB3A8 = gnFlag_007BB3A8 == 0;
}
