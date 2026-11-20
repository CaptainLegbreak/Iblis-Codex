#include "D2Glide.h"
struct D2GfxSettingsStrc;
struct D2GlideHwQueryStrc;
struct D2GlideTexSlotStrc;
struct D2GlideTexCacheEntryStrc;
struct D2GlideTexCacheStrc;

extern int gdwGlobal_007C8CB0; // 0x007C8CB0
extern int gdwGlobal_007C8CB4; // 0x007C8CB4
extern int gdwGlobal_0072DA4C; // 0x0072DA4C
extern int gdwGlobal_0072DA7C; // 0x0072DA7C
extern int gdwGlobal_0072DA5C; // 0x0072DA5C
extern int gdwGlobal_0072DA50; // 0x0072DA50
extern int gdwGlobal_007C8CBC; // 0x007C8CBC
extern int gdwGlobal_0072DB44; // 0x0072DB44
extern int gdwGlobal_007D55CC; // 0x007D55CC
extern int gdwGlobal_007D55E4; // 0x007D55E4
extern int gdwGlobal_007D55E0; // 0x007D55E0
extern int gdwGlobal_007D55D4; // 0x007D55D4
void __stdcall sub_004F9310(void* pArg); // 0x004F9310
extern int gdwGlobal_0087E838; // 0x0087E838
extern int gdwGlobal_0087EFD0; // 0x0087EFD0
extern int gdwGlobal_0087EFE8; // 0x0087EFE8
extern int gdwGlobal_0088126C; // 0x0088126C
extern int gdwGlobal_00881768; // 0x00881768
extern int gdwGlobal_0088176C; // 0x0088176C
extern int gdwGlobal_00881770; // 0x00881770
extern int gdwGlobal_00881774; // 0x00881774
extern int gdwGlobal_00881778; // 0x00881778
extern int gdwGlobal_0072F830; // 0x0072F830
extern int gdwGlobal_00881798; // 0x00881798
extern int gdwGlobal_008817AC; // 0x008817AC
extern int gdwGlobal_008817B0; // 0x008817B0
extern int gdwGlobal_008817B4; // 0x008817B4
extern int gdwGlobal_008817B8; // 0x008817B8
extern int gdwGlobal_008817BC; // 0x008817BC
extern int gdwGlobal_008817C0; // 0x008817C0
extern int gdwGlobal_008817FC; // 0x008817FC
extern char gData_0072FAA0[]; // 0x0072FAA0
extern int gdwGlobal_008818BC; // 0x008818BC
extern int gdwGlobal_008818C0; // 0x008818C0
extern int gdwGlobal_00881C04; // 0x00881C04
extern int gdwGlobal_00881C50; // 0x00881C50

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
    int bLowQuality;
    int nGamma;
    int bVSync;
    int bBlendedShadows;
};

int __cdecl sub_00509E10_GlideClose(); // 0x00509E10
extern D2GfxSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval); // 0x0087EB90

struct D2GfxPaletteViewStrc
{
    int dwData[0x48];
};
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
int __fastcall sub_00509F70_GlideReopenWindow(void* hWnd, int nResolution); // 0x00509F70
void __fastcall sub_005090B0_GlideSetGamma(int nGamma); // 0x005090B0
void __cdecl sub_0050DF70_GlideSmackFree(); // 0x0050DF70
void __cdecl sub_0050F8C0_GlideShutdownStep(); // 0x0050F8C0
void __cdecl sub_0050DCA0_FreePerspectiveTable(); // 0x0050DCA0
void __cdecl sub_0050DB40_FreeBlendTable(); // 0x0050DB40
extern int gnScreenWidth_007C9138; // 0x007C9138
extern void* ghDDrawWindow_007C9140; // 0x007C9140
extern int gbRenderPaused_007C9144; // 0x007C9144
extern void* ghGlideLibrary_0087EFA8; // 0x0087EFA8
extern int gnGlideGammaTableSize_0087EFD4; // 0x0087EFD4
extern int gnGlideTmuState_0072F254; // 0x0072F254
extern void (__stdcall* gpfGlideFn7_0087EAD0)(int a1, int a2, int a3, int a4, int a5, int a6, int a7); // 0x0087EAD0
extern unsigned int gaGlidePalette_0087EBA0[256]; // 0x0087EBA0
extern int gnGlideTmuCount_0087EFB4; // 0x0087EFB4

struct D2GlideHwQueryStrc
{
    int nParamB;
    int nParamA;
    int nParamE;
    int bResult;
    int nUnits;
};
extern void* gdwGlobal_0087EB94; // 0x0087EB94
extern int gdwGlobal_0072F250; // 0x0072F250
extern int gdwGlobal_0087EFB8; // 0x0087EFB8
extern void* (__stdcall* gpfGlideFn_0087EAF4)(void* hWnd, int nRes, int nRefresh, int nFormat, int nOrigin, int nBuffers, int nAux); // 0x0087EAF4
extern void (__stdcall* gpfGlideFn_0087EB38)(int a1); // 0x0087EB38
extern void (__stdcall* gpfGlideFn_0087E97C)(int a1); // 0x0087E97C
extern void (__stdcall* gpfGlideFn_0087EB30)(int a1, int a2); // 0x0087EB30
extern void (__stdcall* gpfGlideFn3_0087EAFC)(int a1, int a2, int a3); // 0x0087EAFC
extern void (__stdcall* gpfGlideFn_0087EB34)(int a1); // 0x0087EB34
extern void (__stdcall* gpfGlideFn_0087EAB0)();
extern void (__stdcall* gpfGlideFn_0087EB04)();
extern void (__stdcall* gpfGlideFn_0087EB3C)(int a1);
void __cdecl sub_0050B9E0_GlideCreateDebugFont();
int __cdecl sub_00509670_GlideInitTextures();
extern int gdwGlobal_0087EFAC; // 0x0087EFAC
extern int gdwGlobal_0087EFB0; // 0x0087EFB0
extern int gdwGlobal_0087EFC0; // 0x0087EFC0
extern int gdwGlobal_0087EFBC; // 0x0087EFBC
extern int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams); // 0x0087EB1C
extern void (__stdcall* gpfGlideFn_0087EB9C)(int a1, int a2, int a3); // 0x0087EB9C

struct D2GlideTexCacheEntryStrc
{
    int nId;
    int f_4;
    D2GlideTexSlotStrc* pOwner;
    int nOwnerIndex;
    int f_10;
    D2GlideTexCacheEntryStrc* pNext;
    D2GlideTexCacheEntryStrc* pPrev;
};

struct D2GlideTexCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824
extern int gbGlideInit_0087EFCC; // 0x0087EFCC
void __cdecl sub_00509FD0_GlideCloseAtExit(); // 0x00509FD0
void __cdecl sub_0050C760_GlideInitVertices(); // 0x0050C760
void __cdecl sub_0050D540_GlideInitD(); // 0x0050D540
void __cdecl sub_0050DB20_AllocBlendTable(); // 0x0050DB20
void __cdecl sub_0050DB70_BuildMulTable(); // 0x0050DB70
void __cdecl sub_0050DC80_AllocPerspectiveTable(); // 0x0050DC80
void __cdecl sub_0050DCD0_FillPerspectiveTable(); // 0x0050DCD0
void __cdecl sub_0050DF10_GlideSmackInit(); // 0x0050DF10
void __cdecl sub_0050F870_GlideBlocksInit(); // 0x0050F870

char gData_007C90C8[12]; // 0x007C90C8

int gdwGlobal_00881790; // 0x00881790

// 0x004F5140
int __cdecl sub_004F5140()
{
    return gdwGlobal_007C8CB0;
}

// 0x004F5150
int __cdecl sub_004F5150()
{
    return gdwGlobal_007C8CB4;
}

// 0x004F5170
int __cdecl sub_004F5170()
{
    return gdwGlobal_0072DA4C;
}

// 0x004F5180
int __cdecl sub_004F5180()
{
    return gdwGlobal_0072DA7C;
}

// 0x004F51F0
int __cdecl sub_004F51F0()
{
    return gdwGlobal_0072DA5C;
}

// 0x004F5210
int __cdecl sub_004F5210()
{
    return gdwGlobal_0072DA50;
}

// 0x004F59A0
int __cdecl sub_004F59A0()
{
    return gdwGlobal_007C8CBC;
}

// 0x004F65E0
int __cdecl sub_004F65E0()
{
    return gdwGlobal_0072DB44;
}

// 0x004F9200
int __cdecl sub_004F9200()
{
    return gdwGlobal_007D55CC;
}

// 0x004F97D0
int __cdecl sub_004F97D0()
{
    return gdwGlobal_007D55E4;
}

// 0x004FA460
int __cdecl sub_004FA460()
{
    return gdwGlobal_007D55E0;
}

// 0x004FA4B0
int __cdecl sub_004FA4B0()
{
    return gdwGlobal_007D55D4;
}

// 0x004FD0F0
void __fastcall sub_004FD0F0(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x004FD100
void __fastcall sub_004FD100(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x004FD820
void __fastcall sub_004FD820(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00500300
void __fastcall sub_00500300(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00505150
int __cdecl sub_00505150()
{
    return gdwGlobal_0087E838;
}

// 0x00507DB0
void __fastcall sub_00507DB0(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00507EE0
void __fastcall sub_00507EE0(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00508FD0
int __cdecl sub_00508FD0()
{
    return gdwGlobal_0087EFD0;
}

// 0x00509190
int __cdecl sub_00509190()
{
    return 1;
}

// 0x00509420
int __cdecl sub_00509420()
{
    return 0;
}

// 0x00509640
void* __cdecl sub_00509640()
{
    return gData_007C90C8;
}

// 0x00509650
int __cdecl sub_00509650()
{
    return gdwGlobal_0087EFE8;
}

// 0x00510140
int __cdecl sub_00510140()
{
    return gdwGlobal_0088126C;
}

// 0x00510320
void __stdcall sub_00510320(int nUnused1)
{
}

// 0x00510370
int __cdecl sub_00510370()
{
    return 0;
}

// 0x00510380
int __cdecl sub_00510380()
{
    return 0;
}

// 0x005123A0
void __stdcall sub_005123A0(int nUnused1, int nUnused2)
{
}

// 0x005126F0
void __stdcall sub_005126F0(int nUnused1, int nUnused2)
{
}

// 0x00513AE0
int __cdecl sub_00513AE0()
{
    return gdwGlobal_00881790;
}

// 0x00513B50
int __cdecl sub_00513B50()
{
    return gdwGlobal_00881768;
}

// 0x00513B60
int __cdecl sub_00513B60()
{
    return gdwGlobal_0088176C;
}

// 0x00513B70
int __cdecl sub_00513B70()
{
    return gdwGlobal_00881770;
}

// 0x00513B80
int __cdecl sub_00513B80()
{
    return 0;
}

// 0x00513B90
int __cdecl sub_00513B90()
{
    return gdwGlobal_00881774;
}

// 0x00513BA0
int __cdecl sub_00513BA0()
{
    return gdwGlobal_00881778;
}

// 0x00513BB0
int __cdecl sub_00513BB0()
{
    return gdwGlobal_0072F830;
}

// 0x00514920
int __cdecl sub_00514920()
{
    return gdwGlobal_00881798;
}

// 0x00514C90
int __cdecl sub_00514C90()
{
    return gdwGlobal_008817AC;
}

// 0x00514CC0
int __cdecl sub_00514CC0()
{
    return gdwGlobal_008817B0;
}

// 0x00514CF0
int __cdecl sub_00514CF0()
{
    return gdwGlobal_008817B4;
}

// 0x00514D20
int __cdecl sub_00514D20()
{
    return gdwGlobal_008817B8;
}

// 0x00514D50
int __cdecl sub_00514D50()
{
    return gdwGlobal_008817BC;
}

// 0x00514D80
int __cdecl sub_00514D80()
{
    return gdwGlobal_008817C0;
}

// 0x00515060
int __cdecl sub_00515060()
{
    return gdwGlobal_008817FC;
}

// 0x00518C10
void* __cdecl sub_00518C10()
{
    return gData_0072FAA0;
}

// 0x0051A550
int __cdecl sub_0051A550()
{
    return gdwGlobal_008818BC;
}

// 0x0051A570
int __cdecl sub_0051A570()
{
    return gdwGlobal_008818C0;
}

// 0x0051CA10
int __cdecl sub_0051CA10()
{
    return 14;
}

// 0x0051CA70
int __cdecl sub_0051CA70()
{
    return gdwGlobal_00881C04;
}

// 0x0051EA70
int __cdecl sub_0051EA70()
{
    return gdwGlobal_00881C50;
}

#include "gen/data/Source/D2Glide/Src/glCore.inc"

int gdwGlobal_007B57E4; // 0x007B57E4

// 0x005090A0
void __fastcall sub_005090A0_SetGlobal(int nValue)
{
    gdwGlobal_007B57E4 = nValue;
}

// 0x00509660
void __fastcall sub_00509660_SetGlobal(int nValue)
{
    gdwGlobal_0087EFE8 = nValue;
}

// 0x00509A70
void __cdecl sub_00509A70_GlideClearAndSwap()
{
    gpfGlideBufferClear_0087EB88(0, 0, 0);
    if (gpGfxSettings_007C9148->bVSync)
    {
        gpfGlideBufferSwap_0087EB90(1);
    }
    else
    {
        gpfGlideBufferSwap_0087EB90(0);
    }
}

// 0x00509FD0
void __cdecl sub_00509FD0_GlideCloseAtExit()
{
    sub_00509E10_GlideClose();
}

D2GfxPaletteViewStrc gtGfxPaletteView_0087E980; // 0x0087E980

void (__stdcall* gpfGlideFn_0087EAB0)(); // 0x0087EAB0

int gbGlideInit_0087EFCC; // 0x0087EFCC

int gbGlideDrawing_0087EFE4; // 0x0087EFE4

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
        sub_0050DF70_GlideSmackFree();
        sub_00509AA0_GlideSuspend();
        gpfGlideFn_0087EAB0();
        sub_0050F8C0_GlideShutdownStep();
        sub_0050DCA0_FreePerspectiveTable();
        sub_0050DB40_FreeBlendTable();
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

void (__stdcall* gpfGlideFn4_0087EACC)(int a1, int a2, int a3, int a4); // 0x0087EACC

void (__stdcall* gpfGlideFn5_0087EAF0)(int a1, int a2, int a3, int a4, int a5); // 0x0087EAF0

void (__stdcall* gpfGlideFn3_0087EAFC)(int a1, int a2, int a3); // 0x0087EAFC

void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C

int gnGlideState_0087EFD8; // 0x0087EFD8

int gnGlideState_0087EFDC; // 0x0087EFDC

int gnGlideState_0087EFE0; // 0x0087EFE0

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

int gdwGlobal_0087EFAC; // 0x0087EFAC

int gdwGlobal_0087EFB0; // 0x0087EFB0

int gdwGlobal_0087EFE8; // 0x0087EFE8

int gdwGlobal_0087EFC0; // 0x0087EFC0

int gnGlideTmuCount_0087EFB4; // 0x0087EFB4

int gdwGlobal_0087EFBC; // 0x0087EFBC

int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams); // 0x0087EB1C

void (__stdcall* gpfGlideFn_0087EB9C)(int a1, int a2, int a3); // 0x0087EB9C

void (__stdcall* gpfGlideFn7_0087EAD0)(int a1, int a2, int a3, int a4, int a5, int a6, int a7); // 0x0087EAD0

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

D2GfxSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148

void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88

void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval); // 0x0087EB90

// 0x00509E90
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

// 0x00509F70
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

void (__stdcall* gpfGlideFn_0087EB04)(); // 0x0087EB04

void (__stdcall* gpfGlideFn_0087EB3C)(int a1); // 0x0087EB3C

D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4]; // 0x0087F048

// 0x0050A010
int __fastcall sub_0050A010_GlideInit(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pTileDrawFunctions)
{
    D2_ASSERT(!gbGlideInit_0087EFCC, 0x2A6);

    gpGfxSettings_007C9148 = pSettings;
    gpTileDrawFunctions_007C914C = pTileDrawFunctions;
    sub_0050F870_GlideBlocksInit();
    sub_0050DC80_AllocPerspectiveTable();
    sub_0050DB20_AllocBlendTable();
    gpfGlideFn_0087EB04();
    gbGlideInit_0087EFCC = 1;
    gpfGlideFn_0087EB3C(0);
    atexit(sub_00509FD0_GlideCloseAtExit);
    sub_0050DB70_BuildMulTable();
    sub_0050DCD0_FillPerspectiveTable();
    sub_0050C760_GlideInitVertices();
    sub_0050D540_GlideInitD();
    sub_0050DF10_GlideSmackInit();
    gpRenderCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\glCore.cpp", 0x2D5, 0);
    InitializeCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}

// 0x0050A110
void __fastcall sub_0050A110_ReleaseTexSlots(D2GlideTexSlotStrc* pSlots)
{
    for (int i = 0; i < 5; ++i)
    {
        const int nCache = pSlots[i].nCache - 1;
        if (nCache >= 0)
        {
            const int nId = pSlots[i].nId - 1;
            if (nId >= 0)
            {
                gaGlideTexCaches_0087F048[nCache + 1].pEntries[nId].pOwner = 0;
            }
        }
    }
}
