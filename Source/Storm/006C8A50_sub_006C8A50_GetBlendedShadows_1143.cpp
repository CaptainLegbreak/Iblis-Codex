struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

extern D2GfxSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148

// 0x006C8A50
int __cdecl sub_006C8A50_GetBlendedShadows()
{
    return gpGfxSettings_007C9148->bBlendedShadows;
}
