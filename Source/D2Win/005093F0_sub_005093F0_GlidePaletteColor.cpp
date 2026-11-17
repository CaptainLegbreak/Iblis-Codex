extern int gnGlideTmuState_0072F254;                                                                        // 0x0072F254
extern void (__stdcall* gpfGlideFn7_0087EAD0)(int a1, int a2, int a3, int a4, int a5, int a6, int a7);     // 0x0087EAD0
void (__stdcall* gpfGlideFn4_0087EACC)(int a1, int a2, int a3, int a4);                                    // 0x0087EACC
void (__stdcall* gpfGlideFn5_0087EAF0)(int a1, int a2, int a3, int a4, int a5);                            // 0x0087EAF0
void (__stdcall* gpfGlideFn3_0087EAFC)(int a1, int a2, int a3);                                            // 0x0087EAFC
void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert);        // 0x0087EB2C
extern unsigned int gaGlidePalette_0087EBA0[256];                                                           // 0x0087EBA0
extern int gnGlideTmuCount_0087EFB4;                                                                        // 0x0087EFB4
int gnGlideState_0087EFD8;                                                                                  // 0x0087EFD8
int gnGlideState_0087EFDC;                                                                                  // 0x0087EFDC
int gnGlideState_0087EFE0;                                                                                  // 0x0087EFE0

// 0x005093F0
unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex)
{
    return gaGlidePalette_0087EBA0[nPaletteIndex] << 8;
}

// 0x00509460
void __fastcall sub_00509460_GlideSelectTmuState(int nTmu)
{
    if (nTmu == gnGlideTmuState_0072F254)
        return;
    if (nTmu == 1)
        gpfGlideFn7_0087EAD0(0, 3, 8, 3, 8, 0, 0);
    else if (nTmu == 0)
        gpfGlideFn7_0087EAD0(0, 1, 0, 1, 0, 0, 0);
    gnGlideTmuState_0072F254 = nTmu;
}

// 0x005094B0
void __fastcall sub_005094B0_GlideSetState(int nState)
{
    if (gnGlideState_0087EFD8 && nState == gnGlideState_0087EFD8)
        return;
    switch (nState)
    {
    case 1:
        gpfGlideColorCombine_0087EB2C(3, 1, 0, 1, 0);
        break;
    case 2:
        gpfGlideColorCombine_0087EB2C(1, 0, 1, 2, 0);
        break;
    }
    gnGlideState_0087EFD8 = nState;
}

// 0x00509500
void __fastcall sub_00509500_GlideSetCombine(int nMode)
{
    if (gnGlideState_0087EFDC && nMode == gnGlideState_0087EFDC)
        return;
    switch (nMode)
    {
    case 1:
        gpfGlideFn5_0087EAF0(0, 0, 1, 2, 0);
        gpfGlideFn4_0087EACC(4, 0, 0, 0);
        break;
    case 2:
        gpfGlideFn5_0087EAF0(1, 0, 1, 2, 0);
        gpfGlideFn4_0087EACC(4, 4, 0, 0);
        break;
    case 3:
        gpfGlideFn5_0087EAF0(1, 0, 1, 2, 0);
        gpfGlideFn4_0087EACC(0, 2, 0, 0);
        break;
    case 4:
        gpfGlideFn5_0087EAF0(1, 0, 1, 2, 0);
        gpfGlideFn4_0087EACC(1, 5, 0, 0);
        break;
    }
    gnGlideState_0087EFDC = nMode;
}

// 0x005095D0
void __fastcall sub_005095D0_GlideSetDepth(int nMode)
{
    if (gnGlideState_0087EFE0 && nMode == gnGlideState_0087EFE0)
        return;
    switch (nMode)
    {
    case 1:
        gpfGlideFn3_0087EAFC(0, 0, 0);
        if (gnGlideTmuCount_0087EFB4 > 1)
            gpfGlideFn3_0087EAFC(1, 0, 0);
        break;
    case 2:
        gpfGlideFn3_0087EAFC(0, 1, 1);
        if (gnGlideTmuCount_0087EFB4 > 1)
            gpfGlideFn3_0087EAFC(1, 1, 1);
        break;
    }
    gnGlideState_0087EFE0 = nMode;
}

#include "gen/data/Source/D2Win/005093F0_sub_005093F0_GlidePaletteColor.inc"
