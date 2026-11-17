struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

struct D2GlideHwQueryStrc
{
    int nParamB;
    int nParamA;
    int nParamE;
    int bResult;
    int nUnits;
};

extern int gbGlidePaletteTable_0087EFC8;                                                                    // 0x0087EFC8
int gdwGlobal_0087EFAC;                                                                                     // 0x0087EFAC
int gdwGlobal_0087EFB0;                                                                                     // 0x0087EFB0
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
int gdwGlobal_0087EFE8;                                                                                     // 0x0087EFE8
extern void* ghDDrawWindow_007C9140;                                                                        // 0x007C9140
extern void* gdwGlobal_0087EB94;                                                                            // 0x0087EB94
extern int gdwGlobal_0072F250;                                                                              // 0x0072F250
int gdwGlobal_0087EFC0;                                                                                     // 0x0087EFC0
int gnGlideTmuCount_0087EFB4;                                                                               // 0x0087EFB4
int gdwGlobal_0087EFBC;                                                                                     // 0x0087EFBC
extern int gdwGlobal_0087EFB8;                                                                              // 0x0087EFB8
extern int gnGlideTmuState_0072F254;                                                                        // 0x0072F254
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;
extern void* (__stdcall* gpfGlideFn_0087EAF4)(void* hWnd, int nRes, int nRefresh, int nFormat, int nOrigin, int nBuffers, int nAux); // 0x0087EAF4
int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams);                                 // 0x0087EB1C
extern void (__stdcall* gpfGlideFn_0087EB38)(int a1);                                                       // 0x0087EB38
void (__stdcall* gpfGlideFn_0087EB9C)(int a1, int a2, int a3);                                              // 0x0087EB9C
extern void (__stdcall* gpfGlideFn_0087E97C)(int a1);                                                       // 0x0087E97C
extern void (__stdcall* gpfGlideFn_0087EB30)(int a1, int a2);                                               // 0x0087EB30
void (__stdcall* gpfGlideFn7_0087EAD0)(int a1, int a2, int a3, int a4, int a5, int a6, int a7);             // 0x0087EAD0
extern void (__stdcall* gpfGlideFn3_0087EAFC)(int a1, int a2, int a3);                                      // 0x0087EAFC
extern void (__stdcall* gpfGlideFn_0087EB34)(int a1);                                                       // 0x0087EB34
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth);
extern void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval);
extern void (__stdcall* gpfGlideFn_0087EAB0)();
extern void (__stdcall* gpfGlideFn_0087EB04)();
extern void (__stdcall* gpfGlideFn_0087EB3C)(int a1);
void __cdecl sub_0050B9E0_GlideCreateDebugFont();
int __cdecl sub_00509670_GlideInitTextures();
void __cdecl sub_00509AA0_GlideSuspend();
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00509BC0
static int sub_00509BC0_GlideOpen(int nResolution, void* hWnd)
{
    D2GlideHwQueryStrc tQuery;
    D2_ASSERT(!gbGlidePaletteTable_0087EFC8, 0x143);
    sub_0050B9E0_GlideCreateDebugFont();
    tQuery.bResult = 0;
    int nRefresh;
    int nGrRes;
    if (!nResolution)
    {
        nGrRes = 7;
        nRefresh = gdwGlobal_0087EFAC;
        gnScreenWidth_007C9138 = 640;
        gnScreenHeight_007C913C = 480;
    }
    else
    {
        nGrRes = 8;
        nRefresh = gdwGlobal_0087EFB0;
        gnScreenWidth_007C9138 = 800;
        gnScreenHeight_007C913C = 600;
    }

    switch (nResolution)
    {
    case 0:
    case 2:
        gdwGlobal_0087EFE8 = 1;
        break;

    default:
        gdwGlobal_0087EFE8 = 0;
        break;
    }

    ghDDrawWindow_007C9140 = hWnd;
    gdwGlobal_0087EB94 = gpfGlideFn_0087EAF4(hWnd, nGrRes, nRefresh, 2, 0, 2, 0);
    if (gdwGlobal_0087EB94)
    {
        gbGlidePaletteTable_0087EFC8 = 1;
        if (gdwGlobal_0072F250)
        {
            tQuery.nUnits = 0;
            gdwGlobal_0072F250 = 0;
            gpfGlideGet_0087EB1C(0xA, 4, &tQuery.nParamA);
            gpfGlideGet_0087EB1C(0xB, 4, &tQuery.nParamB);
            gpfGlideGet_0087EB1C(0x11, 4, &tQuery.nUnits);
            gdwGlobal_0087EFC0 = tQuery.nUnits > 1;
            gpfGlideGet_0087EB1C(0x13, 4, &gnGlideTmuCount_0087EFB4);
            if (gnGlideTmuCount_0087EFB4 >= 3)
            {
                gnGlideTmuCount_0087EFB4 = 3;
            }
            gpfGlideGet_0087EB1C(0x24, 4, &gdwGlobal_0087EFBC);
            gpfGlideGet_0087EB1C(0xE, 4, &tQuery.nParamE);
            gdwGlobal_0087EFB8 = tQuery.nParamE != 0;
            if (!gnGlideTmuCount_0087EFB4)
            {
                return 0;
            }
        }

        gpfGlideFn_0087EB38(0);
        gpfGlideFn_0087EB9C(1, 0, 1);
        gpfGlideFn_0087EB9C(0x50, 0xC, 1);
        gpfGlideFn_0087EB9C(0x40, 0x10, 1);
        if (gnGlideTmuCount_0087EFB4 > 1)
        {
            gpfGlideFn_0087EB9C(0x51, 0xC, 1);
            gpfGlideFn_0087EB9C(0x41, 0x10, 1);
        }
        gpfGlideFn_0087EB9C(0x30, 8, 1);
        gpfGlideFn_0087E97C(0);
        gpfGlideFn_0087EB30(1, 0);
        if (gnGlideTmuState_0072F254)
        {
            gpfGlideFn7_0087EAD0(0, 1, 0, 1, 0, 0, 0);
            gnGlideTmuState_0072F254 = 0;
        }
        gpfGlideFn3_0087EAFC(0, 0, 0);
        gpfGlideFn7_0087EAD0(0, 1, 0, 1, 0, 0, 0);
        if (gnGlideTmuCount_0087EFB4 > 1)
        {
            gpfGlideFn3_0087EAFC(1, 0, 0);
            gpfGlideFn7_0087EAD0(1, 1, 0, 1, 0, 0, 0);
        }
        gpfGlideFn_0087EB34(0xFF);
        if (sub_00509670_GlideInitTextures())
        {
            tQuery.bResult = 1;
        }
    }
    else
    {
        sub_00410610_WriteLogLine("Opening Glide window failed!");
    }

    return tQuery.bResult;
}

int __fastcall sub_00509E90_GlideOpenWindow(void* hWnd, int nResolution)
{
    if (gbGlidePaletteTable_0087EFC8)
    {
        return 1;
    }

    if (!sub_00509BC0_GlideOpen(nResolution, hWnd))
    {
        return 0;
    }

    gpfGlideBufferClear_0087EB88(0, 0, 0);
    if (gpGfxSettings_007C9148->bVSync)
    {
        gpfGlideBufferSwap_0087EB90(1);
        return 1;
    }

    gpfGlideBufferSwap_0087EB90(0);
    return 1;
}

int __fastcall sub_00509F70_GlideReopenWindow(void* hWnd, int nResolution)
{
    sub_00509AA0_GlideSuspend();
    gpfGlideFn_0087EAB0();
    gpfGlideFn_0087EB04();
    gpfGlideFn_0087EB3C(0);
    if (!sub_00509BC0_GlideOpen(nResolution, hWnd))
    {
        return 0;
    }

    gpfGlideBufferClear_0087EB88(0, 0, 0);
    if (gpGfxSettings_007C9148->bVSync)
    {
        gpfGlideBufferSwap_0087EB90(1);
        return 1;
    }

    gpfGlideBufferSwap_0087EB90(0);
    return 1;
}

#include "gen/data/Source/D2Win/00509BC0_sub_00509BC0_GlideOpen.inc"
