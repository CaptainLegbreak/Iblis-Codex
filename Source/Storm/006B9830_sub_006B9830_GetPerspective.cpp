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

// 0x006B9830
int __cdecl sub_006B9830_GetPerspective()
{
    if (gpGfxSettings_007C9148->bPerspectiveCapable)
        return gpGfxSettings_007C9148->bPerspectiveEnabled;
    return 0;
}
