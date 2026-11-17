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
    char unk0x00[0x54];
    void (__fastcall* pfSetGlobalScale)(int nScaleFactor);
    char unk0x58[0x08];
    void (__fastcall* pfUpdatePerspective)(int nScaleX, int nScaleY);
};

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0
extern int gnDisplayType;                                                                                   // 0x007C8CB0
extern D2GfxSettingsStrc gGfxSettings;                                                                      // 0x0072DA48
#include "gen/data/Source/D2Win/004F65C0_SCALE_UpdateFactor/gnChangedScaleFactor_0072DB40.inc"
#include "gen/data/Source/D2Win/004F65C0_SCALE_UpdateFactor/gnScaleFactor_0072DB44.inc"
static int gnPerspectiveScaleX_007C977C;                                                                    // 0x007C977C
static int gnPerspectiveScaleY_007C9778;                                                                    // 0x007C9778

// 0x004F65C0
void __stdcall SCALE_UpdateFactor()
{
    gnScaleFactor_0072DB44 = gnChangedScaleFactor_0072DB40;
    return gpGraphicsInterface->pfSetGlobalScale(gnScaleFactor_0072DB44);
}

// 0x004F65F0
void __stdcall SCALE_SetDefaultFactor()
{
    gnScaleFactor_0072DB44 = 0x100;
    return gpGraphicsInterface->pfSetGlobalScale(gnScaleFactor_0072DB44);
}

// 0x004F6670
void __stdcall SCALE_SetPerspectiveScale(int nXScale, int nYScale)
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0x61);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x62);
    gnPerspectiveScaleX_007C977C = nXScale;
    gnPerspectiveScaleY_007C9778 = nYScale;
    return gpGraphicsInterface->pfUpdatePerspective(nXScale, nYScale);
}

int __stdcall sub_J03_EmitScaleReaders()
{
    return gnChangedScaleFactor_0072DB40 + gnPerspectiveScaleX_007C977C + gnPerspectiveScaleY_007C9778;
}
