struct D2GraphicsInterfaceStrc;

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

extern D2GfxSettingsStrc gGfxSettings;                                                                      // 0x0072DA48
extern int gbIsWindowed;                                                                                    // 0x007C8CB4
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0

// 0x004F51D0
int __stdcall D2GFX_CheckPerspective()
{
    return gGfxSettings.bPerspectiveCapable != 0 ? gGfxSettings.bPerspectiveEnabled : 0;
}

// 0x004F54F0
int __stdcall D2GFX_ToggleLowQuality()
{
    gGfxSettings.bLowQuality = gGfxSettings.bLowQuality == 0;
    return gGfxSettings.bLowQuality;
}

// 0x004F5A30
int __stdcall WINDOW_IsFullScreen()
{
    if (gpGraphicsInterface)
    {
        return gbIsWindowed == 0;
    }

    return 0;
}
