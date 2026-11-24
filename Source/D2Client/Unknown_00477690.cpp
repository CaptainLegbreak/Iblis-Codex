int __stdcall D2GFX_TogglePerspective();                                                                    // 0x004F54B0
int __stdcall D2GFX_ToggleBlendedShadows();                                                                 // 0x004F54D0
int __stdcall D2GFX_ToggleLowQuality();                                                                     // 0x004F54F0

extern "C" int gnLightmapRenderMode;                                                                        // 0x00712CCC
int gdwGlobal_007BB38C;                                                                                     // 0x007BB38C
extern "C" { int gnFlag_007BB3A8; }                                                                         // 0x007BB3A8




// 0x004776D0
void __fastcall sub_004776D0_SetModeValues(int nModeValue, int nValue)
{
    gnLightmapRenderMode = nModeValue;
    gdwGlobal_007BB38C = nValue;
}

// 0x004776E0
void __cdecl sub_004776E0_SetModeValuesOne()
{
    gnLightmapRenderMode = 1;
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
