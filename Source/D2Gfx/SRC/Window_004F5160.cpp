#include "D2Gfx.h"
#include "D2GfxTypes.h"

struct D2CacheStatsStrc;

extern int gnResolutionMode; // 0x007C8CB8

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48
extern int gdwGlobal_0072DA7C; // 0x0072DA7C
extern int gnDisplayType; // 0x007C8CB0
extern int gnViewMatrixAdjust_007C8CC4; // 0x007C8CC4

// 0x004F5160
int __stdcall D2GFX_GetResolutionMode()
{
    return gnResolutionMode;
}

// 0x004F6250
int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer)
{
    return gpGraphicsInterface->pfGetBackBuffer(pBuffer);
}

// 0x004F6380
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    gpGraphicsInterface->pfDrawLine(nXStart, nYStart, nXEnd, nYEnd, dwColor, nAlpha);
}

// 0x004F51C0
int __cdecl sub_004F51C0_IsHighVideoMode()
{
    return gnDisplayType >= 4;
}

// 0x004F5260
int __stdcall D2GFX_GammaCanBeControlled()
{
    return gpGraphicsInterface->pfGammaCanBeControlled();
}

// 0x004F5270
void __cdecl D2GFX_EnableVSync()
{
    gGfxSettings.bVSync = 1;
}

// 0x004F5280
void __cdecl sub_004F5280()
{
    gdwGlobal_0072DA7C = 0;
}

// 0x004F5290
D2CacheStatsStrc* __cdecl sub_004F5290_GetCacheStats()
{
    return gpGraphicsInterface->pfGetCacheResults();
}

// 0x004F52A0
void __fastcall sub_004F52A0_SetOffset(int nOffset)
{
    gnViewMatrixAdjust_007C8CC4 = nOffset;
}

// 0x004F52B0
int __fastcall D2GFX_SetOption(int nOption, int nValue)
{
    return gpGraphicsInterface->pfSetOption(nOption, nValue);
}

#include "gen/data/Source/D2Gfx/SRC/Window_004F5160.inc"
