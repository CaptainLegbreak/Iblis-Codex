#include "D2Win.h"
#include "D2GfxTypes.h"

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2TileLibraryEntryStrc;
struct D2GfxLightStrc;
struct D2GfxLightExStrc;
union D2LargeIntegerStrc;
struct D2PerfStartStrc;
struct D2PaletteStrc;

union D2LargeIntegerStrc
{
    struct
    {
        unsigned long nLowPart;
        long nHighPart;
    };
    __int64 nQuadPart;
};

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(D2LargeIntegerStrc* pFrequency); // 0x006CC254
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount); // 0x006CC25C

struct D2PerfStartStrc
{
    D2LargeIntegerStrc tStart;

    D2PerfStartStrc()
    {
        QueryPerformanceCounter(&tStart);
    }
};

typedef char* va_list;

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
    union
    {
        struct
        {
            char unk0x00[0x60];
        };
        struct
        {
            unsigned char unk_00[0x54];
            void (__fastcall* pfSetGlobalScale)(int nScaleFactor);
        };
    };
    void (__fastcall* pfUpdatePerspective)(int nScaleX, int nScaleY);
    void (__fastcall* pfPerspectiveTransform)(int nPosX, int nPosY, int nBias, int* pXAdjust, int* pYAdjust);
    void (__fastcall* pfPerspectiveTransformScale)(int nPosX, int nPosY, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder);
    char unk0x6C[0x0C];
    void (__fastcall* pfSetAmbientColor)(int nRed, int nGreen, int nBlue);
    int (__fastcall* pfFloorTileDraw)(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData);
    void (__fastcall* pfCelFlatSpriteDraw)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette);
    void (__fastcall* pfCelDraw)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette);
    void (__fastcall* pfCelDrawColor)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift);
    void (__fastcall* pfCelDrawEx)(D2GfxDataStrc* pData, int nPosX, int nPosY, int nSkipLines, int nDrawLines, int eDrawMode);
    void (__fastcall* pfCelDrawShadow)(D2GfxDataStrc* pData, int nPosX, int nPosY);
    void (__fastcall* pfCelDrawHilight)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned char nPaletteIndex);
    void (__fastcall* pfCelDrawClipped)(D2GfxDataStrc* pData, int nPosX, int nPosY, void* pCropRect, int eDrawMode);
    int (__fastcall* pfTileDrawLit)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels);
    int (__fastcall* pfTileDrawTrans)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha);
    int (__fastcall* pfShadowTileDraw)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels);
    char unk0xA8[0x20];
    void (__fastcall* pfOutputString)(int nPosX, int nPosY, const char* szFormat, va_list va);
    void (__fastcall* pfDebugDraw)(unsigned int* pLight, unsigned int* pPlayerLight, int nPosX, int nPosY);
    void (__fastcall* pfDebugFillBackBuffer)(int nPosX, int nPosY);
};

struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48
extern int gnScreenPitch; // 0x007D544C
extern unsigned char gabLightCube[32][32][32]; // 0x007CA320
extern D2PaletteStrc gatLightPalettes[]; // 0x007D2348
extern int gnDisplayType; // 0x007C8CB0
extern int gnChangedScaleFactor; // 0x0072DB40

// build: symbol ?$S1@?1??sub_004F6130_GetElapsedMs@@YANXZ@4IA 0x007C9358
// 0x004F6110
double __cdecl sub_004F6110_GetPerfFrequency()
{
    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (double)tFrequency.nQuadPart;
}

// 0x004F6130
double __cdecl sub_004F6130_GetElapsedMs()
{
    static D2PerfStartStrc stStart; // 0x007C9350

    D2LargeIntegerStrc tNow;
    QueryPerformanceCounter(&tNow);
    tNow.nQuadPart -= stStart.tStart.nQuadPart;
    const double dTicks = (double)tNow.nQuadPart;

    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return dTicks / ((double)tFrequency.nQuadPart / 1000.0);
}

int gnDisplayType; // 0x007C8CB0

int gnPerspectiveScaleX; // 0x007C977C

int gnPerspectiveScaleY; // 0x007C9778

// 0x004F6430
void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue)
{
    return gpGraphicsInterface->pfSetAmbientColor(nRed, nGreen, nBlue);
}

// 0x004F6450
void __stdcall TEXTURE_CelFlatSpriteDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette)
{
    return gpGraphicsInterface->pfCelFlatSpriteDraw(pData, nXPos, nYPos, dwGamma, eDrawMode, nScreenMode, pPalette);
}

// 0x004F6480
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette)
{
    return gpGraphicsInterface->pfCelDraw(pData, nXPos, nYPos, dwGamma, eDrawMode, pPalette);
}

// 0x004F64B0
void __stdcall TEXTURE_CelDrawColor(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift)
{
    return gpGraphicsInterface->pfCelDrawColor(pData, nXPos, nYPos, dwGamma, eDrawMode, nGlobalPaletteShift);
}

// 0x004F64E0
void __stdcall TEXTURE_CelDrawEx(D2GfxDataStrc* pData, int nXPos, int nYPos, int nSkipLines, int nDrawLines, int eDrawMode)
{
    if (nDrawLines)
    {
        return gpGraphicsInterface->pfCelDrawEx(pData, nXPos, nYPos, nSkipLines, nDrawLines, eDrawMode);
    }
}

// 0x004F6510
void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode)
{
    return gpGraphicsInterface->pfCelDrawClipped(pData, nXPos, nYPos, pCropRect, eDrawMode);
}

// 0x004F6540
void __stdcall TEXTURE_CelDrawShadow(D2GfxDataStrc* pData, int nXPos, int nYPos)
{
    return gpGraphicsInterface->pfCelDrawShadow(pData, nXPos + 2, nYPos);
}

// 0x004F6570
void __stdcall TEXTURE_CelDrawHilight(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfCelDrawHilight(pData, nXPos, nYPos, nPaletteIndex);
}

// 0x004F65A0
void __stdcall TEXTURE_DebugFillBackBuffer(int nXPos, int nYPos)
{
    return gpGraphicsInterface->pfDebugFillBackBuffer(nXPos, nYPos);
}

// 0x004F66E0
int __stdcall SCALE_CheckPerspectivePosition(int nXPos, int nYPos)
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0x74);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x75);

    int nX = nXPos - gnPerspectiveScaleX;
    if (nX < 0)
    {
        nX = -nX;
    }
    if (nX > 0x320000)
    {
        return 0;
    }

    int nY = nYPos - gnPerspectiveScaleY;
    if (nY < 0)
    {
        nY = -nY;
    }
    return nY <= 0x320000;
}

// 0x004F6760
void __stdcall SCALE_AdjustPerspectivePosition(int nXPos, int nYPos, int nBias, int* pXAdjust, int* pYAdjust)
{
    D2_ASSERT(gnDisplayType >= DISPLAYTYPE_GLIDE, 0x8B);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x8C);

    return gpGraphicsInterface->pfPerspectiveTransform(nXPos, nYPos, nBias, pXAdjust, pYAdjust);
}

// 0x004F67C0
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder)
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0x98);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x99);

    return gpGraphicsInterface->pfPerspectiveTransformScale(nXPos, nYPos, 0, pXAdjust, pYAdjust, bOrder);
}

// 0x004F6890
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...)
{
    va_list va;

    va_start(va, szFormat);
    return gpGraphicsInterface->pfOutputString(nXPos, nYPos, szFormat, va);
}

// 0x004F68B0
void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos)
{
    return gpGraphicsInterface->pfDebugDraw(pLight, pPlayerLight, nXPos, nYPos);
}

// 0x004F68E0
int __stdcall D2GFX_FloorTileDraw(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nXPos, int nYPos, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData)
{
    return gpGraphicsInterface->pfFloorTileDraw(pTile, pLight, nXPos, nYPos, nWorldXpos, nWorldYpos, nAlpha, nScreenPanels, pTileData);
}

// 0x004F6920
int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels)
{
    return gpGraphicsInterface->pfTileDrawLit(pTile, nXPos, nYPos, pLight, nScreenPanels);
}

// 0x004F6950
int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha)
{
    return gpGraphicsInterface->pfTileDrawTrans(pTile, nXPos, nYPos, pLight, nScreenPanels, nAlpha);
}

// 0x004F6980
int __stdcall TILE_ShadowTileDraw(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, int eDrawMode, int nScreenPanels)
{
    return gpGraphicsInterface->pfShadowTileDraw(pTile, nXPos, nYPos, eDrawMode, nScreenPanels);
}

// 0x004F6BB0
void __fastcall sub_004F6BB0_DrawLitSubtileRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep)
{
    unsigned char* pRow = pDst;
    for (int i = 0; i < 15; ++i)
    {
// build: symbol ?ganSubtileRowXOffset@* 0x0072DB48
        const int nOff = ganSubtileRowXOffset[i];
        unsigned char* v = (unsigned char*)gabLightCube + 32 * ((nLightY >> 7) + 32 * (nLightX >> 7)) + nOff;
// build: symbol ?ganSubtileRowSrcOffset@* 0x0072DBC0
        unsigned char* s = &pSrc[ganSubtileRowSrcOffset[i]];
// build: symbol ?ganSubtileRowWidth@* 0x0072DB84
        switch (ganSubtileRowWidth[i])
        {
        case 32:
            pRow[nOff + 31] = gatLightPalettes[v[31]].unk0x00[s[31]];
            pRow[nOff + 30] = gatLightPalettes[v[30]].unk0x00[s[30]];
            pRow[nOff + 29] = gatLightPalettes[v[29]].unk0x00[s[29]];
            pRow[nOff + 28] = gatLightPalettes[v[28]].unk0x00[s[28]];
        case 28:
            pRow[nOff + 27] = gatLightPalettes[v[27]].unk0x00[s[27]];
            pRow[nOff + 26] = gatLightPalettes[v[26]].unk0x00[s[26]];
            pRow[nOff + 25] = gatLightPalettes[v[25]].unk0x00[s[25]];
            pRow[nOff + 24] = gatLightPalettes[v[24]].unk0x00[s[24]];
        case 24:
            pRow[nOff + 23] = gatLightPalettes[v[23]].unk0x00[s[23]];
            pRow[nOff + 22] = gatLightPalettes[v[22]].unk0x00[s[22]];
            pRow[nOff + 21] = gatLightPalettes[v[21]].unk0x00[s[21]];
            pRow[nOff + 20] = gatLightPalettes[v[20]].unk0x00[s[20]];
        case 20:
            pRow[nOff + 19] = gatLightPalettes[v[19]].unk0x00[s[19]];
            pRow[nOff + 18] = gatLightPalettes[v[18]].unk0x00[s[18]];
            pRow[nOff + 17] = gatLightPalettes[v[17]].unk0x00[s[17]];
            pRow[nOff + 16] = gatLightPalettes[v[16]].unk0x00[s[16]];
        case 16:
            pRow[nOff + 15] = gatLightPalettes[v[15]].unk0x00[s[15]];
            pRow[nOff + 14] = gatLightPalettes[v[14]].unk0x00[s[14]];
            pRow[nOff + 13] = gatLightPalettes[v[13]].unk0x00[s[13]];
            pRow[nOff + 12] = gatLightPalettes[v[12]].unk0x00[s[12]];
        case 12:
            pRow[nOff + 11] = gatLightPalettes[v[11]].unk0x00[s[11]];
            pRow[nOff + 10] = gatLightPalettes[v[10]].unk0x00[s[10]];
            pRow[nOff + 9] = gatLightPalettes[v[9]].unk0x00[s[9]];
            pRow[nOff + 8] = gatLightPalettes[v[8]].unk0x00[s[8]];
        case 8:
            pRow[nOff + 7] = gatLightPalettes[v[7]].unk0x00[s[7]];
            pRow[nOff + 6] = gatLightPalettes[v[6]].unk0x00[s[6]];
            pRow[nOff + 5] = gatLightPalettes[v[5]].unk0x00[s[5]];
            pRow[nOff + 4] = gatLightPalettes[v[4]].unk0x00[s[4]];
        case 4:
            pRow[nOff + 3] = gatLightPalettes[v[3]].unk0x00[s[3]];
            pRow[nOff + 2] = gatLightPalettes[v[2]].unk0x00[s[2]];
            pRow[nOff + 1] = gatLightPalettes[v[1]].unk0x00[s[1]];
            pRow[nOff + 0] = gatLightPalettes[v[0]].unk0x00[s[0]];
        }
        pRow += gnScreenPitch;
        nLightX += nLightXStep;
        nLightY += nLightYStep;
    }
}

#include "gen/data/Source/D2Win/Unknown_004F6110/gnChangedScaleFactor.inc"

#include "gen/data/Source/D2Win/Unknown_004F6110/gnScaleFactor_0072DB44.inc"

static int gnPerspectiveScaleX_007C977C; // 0x007C977C

static int gnPerspectiveScaleY_007C9778; // 0x007C9778

// 0x004F65C0
void __stdcall SCALE_UpdateFactor()
{
    gnScaleFactor_0072DB44 = gnChangedScaleFactor;
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
    return gnChangedScaleFactor + gnPerspectiveScaleX_007C977C + gnPerspectiveScaleY_007C9778;
}

// 0x004F6610
void __cdecl sub_004F6610_IncreaseScaleFactor()
{
    if (gnChangedScaleFactor < 0x200)
    {
        gnChangedScaleFactor += 0x20;
        if (gnChangedScaleFactor > 0x200)
        {
            gnChangedScaleFactor = 0x200;
        }
    }
}

// 0x004F6640
void __cdecl sub_004F6640_DecreaseScaleFactor()
{
    if (gnChangedScaleFactor > 0x100)
    {
        gnChangedScaleFactor -= 0x20;
        if (gnChangedScaleFactor < 0x100)
        {
            gnChangedScaleFactor = 0x100;
        }
    }
}
