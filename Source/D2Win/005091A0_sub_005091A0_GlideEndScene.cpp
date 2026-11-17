struct D2CriticalSectionStrc;

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

struct D2GfxPaletteViewStrc
{
    int dwData[0x48];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_00509F70_GlideReopenWindow(void* hWnd, int nResolution);                                 // 0x00509F70
void __fastcall sub_005090B0_GlideSetGamma(int nGamma);                                                     // 0x005090B0
void __cdecl sub_00509AA0_GlideSuspend();                                                                   // 0x00509AA0
void __cdecl sub_0050DF70_GlideShutdownStep();                                                              // 0x0050DF70
void __cdecl sub_0050F8C0_GlideShutdownStep();                                                              // 0x0050F8C0
void __cdecl sub_0050DCA0_GlideShutdownStep();                                                              // 0x0050DCA0
void __cdecl sub_0050DB40_GlideShutdownStep();                                                              // 0x0050DB40

extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern void* ghDDrawWindow_007C9140;                                                                        // 0x007C9140
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;                                                           // 0x007C9148
extern D2GfxPaletteViewStrc* gpGfxPaletteView_007C9150;                                                     // 0x007C9150
D2GfxPaletteViewStrc gtGfxPaletteView_0087E980;                                                             // 0x0087E980
void (__stdcall* gpfGlideFn_0087EAB0)();                                                                    // 0x0087EAB0
extern void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval);                                   // 0x0087EB90
extern void* ghGlideLibrary_0087EFA8;                                                                       // 0x0087EFA8
int gbGlideInit_0087EFCC;                                                                                   // 0x0087EFCC
extern int gnGlideGammaTableSize_0087EFD4;                                                                  // 0x0087EFD4
int gbGlideDrawing_0087EFE4;                                                                                // 0x0087EFE4

// 0x005091A0
int __cdecl sub_005091A0_GlideEndScene()
{
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x47A);
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    gbGlideDrawing_0087EFE4 = 0;
    return 1;
}

// 0x005091E0
int __cdecl sub_005091E0_GlideSwapBuffers()
{
    if (gpGfxSettings_007C9148->bVSync)
    {
        gpfGlideBufferSwap_0087EB90(1);
        return 1;
    }

    gpfGlideBufferSwap_0087EB90(0);
    return 1;
}

// 0x005092F0
void __fastcall sub_005092F0_GlideGetScreenSize(int* pWidth, int* pHeight)
{
    *pWidth = gnScreenWidth_007C9138;
    *pHeight = gnScreenHeight_007C913C;
}

// 0x00509400
void __fastcall sub_00509400_GlideSetPaletteView(D2GfxPaletteViewStrc* pSource)
{
    gtGfxPaletteView_0087E980 = *pSource;
    gpGfxPaletteView_007C9150 = &gtGfxPaletteView_0087E980;
}

// 0x00509430
int __fastcall sub_00509430_GlideSetOption(int nOption, int nValue)
{
    switch (nOption)
    {
    case 10:
        *(int*)nValue = gbGlideDrawing_0087EFE4;
        return 1;
    case 11:
        gnGlideGammaTableSize_0087EFD4 = nValue;
        return 1;
    }
    return 0;
}

// 0x00509E10
int __cdecl sub_00509E10_GlideClose()
{
    if (gbGlideInit_0087EFCC)
    {
        sub_0050DF70_GlideShutdownStep();
        sub_00509AA0_GlideSuspend();
        gpfGlideFn_0087EAB0();
        sub_0050F8C0_GlideShutdownStep();
        sub_0050DCA0_GlideShutdownStep();
        sub_0050DB40_GlideShutdownStep();
        gbGlideInit_0087EFCC = 0;
    }

    if (gpRenderCriticalSection_007C9134)
    {
        DeleteCriticalSection(gpRenderCriticalSection_007C9134);
        FOG_Free(gpRenderCriticalSection_007C9134, ".\\Src\\glCore.cpp", 0x30D, 0);
        gpRenderCriticalSection_007C9134 = 0;
    }

    if (ghGlideLibrary_0087EFA8)
    {
        FreeLibrary(ghGlideLibrary_0087EFA8);
    }

    return 1;
}

// 0x00509FE0
int __cdecl sub_00509FE0_GlideResume()
{
    if (!gbRenderPaused_007C9144 && sub_00509F70_GlideReopenWindow(ghDDrawWindow_007C9140, 0))
    {
        sub_005090B0_GlideSetGamma(0x64);
        return 1;
    }

    return 0;
}
