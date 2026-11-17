struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

struct D2GraphicsInterfaceStrc
{
    void* pfSlots00[0x34 / 4];
    int (__fastcall* pfPlayCutscene)();
    void* pfSlots38[(0xD4 - 0x38) / 4];
    void (__fastcall* pfClearCaches)();
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2GfxSettingsStrc gGfxSettings;                                                                      // 0x0072DA48
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
void __stdcall WINDOW_ShowAll();                                                                            // 0x004F5F60

// 0x004F5020
int __stdcall sub_004F5020_ClearInterface()
{
    gpGraphicsInterface = 0;
    return 1;
}

// 0x004F5030
void __cdecl j_D2GFX_10040_ShowAllWindows()
{
    WINDOW_ShowAll();
}

// 0x004F5040
int __stdcall D2GFX_ReturnFalse(int nArg1, int nArg2, int nArg3)
{
    return 0;
}

// 0x004F52C0
void __cdecl sub_004F52C0_Empty()
{
}

// 0x004F52D0
void __cdecl sub_004F52D0_Empty()
{
}

// 0x004F54B0
int __stdcall D2GFX_TogglePerspective()
{
    gGfxSettings.bPerspectiveEnabled = gGfxSettings.bPerspectiveEnabled == 0;
    return gGfxSettings.bPerspectiveEnabled;
}

// 0x004F54D0
int __stdcall D2GFX_ToggleBlendedShadows()
{
    gGfxSettings.bBlendedShadows = gGfxSettings.bBlendedShadows == 0;
    return gGfxSettings.bBlendedShadows;
}

// 0x004F5D50
void __stdcall WINDOW_ClearCaches()
{
    gpGraphicsInterface->pfClearCaches();
}

// 0x004F5D60
void __stdcall WINDOW_PlayCutscene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2AD);
    gpGraphicsInterface->pfPlayCutscene();
}
