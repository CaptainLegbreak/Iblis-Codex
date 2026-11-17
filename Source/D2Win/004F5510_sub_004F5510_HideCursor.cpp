enum DisplayType
{
    DISPLAYTYPE_NONE = 0,
    DISPLAYTYPE_GDI = 1,
    DISPLAYTYPE_SOFTWARE = 2,
    DISPLAYTYPE_DDRAW = 3,
    DISPLAYTYPE_GLIDE = 4,
    DISPLAYTYPE_OPENGL = 5,
    DISPLAYTYPE_DIRECT3D = 6,
    DISPLAYTYPE_RAVE = 7,
};

struct D2GraphicsInterfaceStrc
{
    char unk0x00[0x10];
    int (__fastcall* pfCloseSurface)();
    char unk0x14[0x28];
    int (__fastcall* pfCheckCutScene)();
    char unk0x40[0x2C];
    void (__fastcall* pfPerspectiveClearScale)();
};

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
};

struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};

struct D2PaletteTableStrc
{
    D2PaletteStrc* pPalettes[72];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall ShowCursor(int bShow);                                     // 0x006CC4D8
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* hWnd);                                 // 0x006CC4E0
extern "C" __declspec(dllimport) long __stdcall ChangeDisplaySettingsA(void* lpDevMode, unsigned long dwFlags); // 0x006CC4F4

void __cdecl sub_004F5FA0_UpdatePauseState();                                                               // 0x004F5FA0

extern int gbCursorDisplayed;                                                                               // 0x0072DB38
extern D2GfxSettingsStrc gGfxSettings;                                                                      // 0x0072DA48
extern int gnDisplayType;                                                                                   // 0x007C8CB0
extern void* ghWnd;                                                                                         // 0x007C8CBC
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
extern int gbWindowState_6FA8D850;                                                                          // 0x007C9340
int gnRowOffsets_007C97A8[732];                                                                             // 0x007C97A8
extern unsigned char gLightCube_007CA320[32][32][32];                                                       // 0x007CA320
extern D2PaletteStrc gLightPalettes_007D2348[49];                                                           // 0x007D2348
extern int gnScreenPitch_007D544C;                                                                          // 0x007D544C
D2PaletteTableStrc gPaletteTables_007D5458;                                                                 // 0x007D5458
extern D2PaletteTableStrc* gpPaletteTables_007D5578;                                                        // 0x007D5578

// 0x004F5510
void __cdecl sub_004F5510_HideCursor()
{
    if (gbCursorDisplayed)
    {
        while (ShowCursor(0) >= 0);
        gbCursorDisplayed = 0;
    }
}

// 0x004F5540
void __cdecl sub_004F5540_ShowCursor()
{
    if (!gbCursorDisplayed)
    {
        while (ShowCursor(1) < 0);
        gbCursorDisplayed = 1;
    }
}

// 0x004F5900
int __stdcall WINDOW_Destroy()
{
    int bWindowDestroyed = 1;
    D2_ASSERT(gpGraphicsInterface, 0x12C);

    if (!gbCursorDisplayed)
    {
        while (ShowCursor(1) < 0);
        gbCursorDisplayed = 1;
    }

    if (!gpGraphicsInterface->pfCloseSurface())
    {
        bWindowDestroyed = 0;
    }

    if (ghWnd)
    {
        if (!DestroyWindow(ghWnd))
        {
            bWindowDestroyed = 0;
        }
        ghWnd = 0;
    }

    ChangeDisplaySettingsA(0, 0);
    return bWindowDestroyed;
}

// 0x004F5DD0
int __stdcall WINDOW_CheckCutScene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2F6);

    return gpGraphicsInterface->pfCheckCutScene();
}

// 0x004F6070
int __stdcall WINDOW_GetState()
{
    sub_004F5FA0_UpdatePauseState();
    return gbWindowState_6FA8D850;
}

// 0x004F6270
int __stdcall D2GFX_HardwareAcceleratedRenderMode()
{
    return gnDisplayType >= DISPLAYTYPE_GLIDE;
}

// 0x004F6830
void __stdcall SCALE_SetDefaultFactorPerspectiveFactor()
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0xA8);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0xA9);

    return gpGraphicsInterface->pfPerspectiveClearScale();
}

// 0x004F7CC0
extern "C" void __cdecl sub_004F7CC0()
{
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            int nValue = i << 24;
            const int nStep = ((j - i) << 24) >> 5;
            for (int k = 0; k < 32; ++k)
            {
                nValue = nValue > 0 ? nValue : 0;
                if (nValue >= 0x1F000000)
                {
                    nValue = 0x1F000000;
                }
                gLightCube_007CA320[i][j][k] = nValue >> 24;
                nValue += nStep;
            }

            D2_ASSERT((nValue >> 24) == j, 0x285);
        }
    }
}

// 0x004F7E70
void __cdecl sub_004F7E70_InitRowOffsets()
{
    int nValue = -32 * gnScreenPitch_007D544C;
    for (int i = 0; i < 732; ++i)
    {
        gnRowOffsets_007C97A8[i] = nValue;
        nValue += gnScreenPitch_007D544C;
    }
}

// 0x004F8E40
void __fastcall sub_004F8E40_CopyPaletteTables(D2PaletteTableStrc* pPaletteTables)
{
    gPaletteTables_007D5458 = *pPaletteTables;
    gpPaletteTables_007D5578 = &gPaletteTables_007D5458;
    for (int i = 0; i < 49; ++i)
    {
        gLightPalettes_007D2348[i] = *gPaletteTables_007D5458.pPalettes[i + 3];
    }
}

#include "gen/data/Source/D2Win/004F5510_sub_004F5510_HideCursor.inc"
