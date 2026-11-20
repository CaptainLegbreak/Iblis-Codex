#pragma once

#include "D2GfxTypes.h"

struct tagRECT;

extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(tagRECT* lpRect, unsigned long dwStyle, int bMenu, unsigned long dwExStyle); // 0x006CC4FC
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* hWnd); // 0x006CC4E0
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect); // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall ShowCursor(int bShow); // 0x006CC4D8
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow); // 0x006CC4EC
extern "C" __declspec(dllimport) long __stdcall ChangeDisplaySettingsA(void* lpDevMode, unsigned long dwFlags); // 0x006CC4F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern int gnDisplayType; // 0x007C8CB0
extern void* ghInstance_007C8CA8; // 0x007C8CA8
void __cdecl sub_004F8EA0(); // 0x004F8EA0

struct tagPOINT;
struct tagPALETTEENTRY;
struct D2PaletteTableStrc;

struct D2GraphicsInterfaceStrc
{
    int (__fastcall* pfDetect)(void* hInstance);
    int (__fastcall* pfInit)(D2GfxSettingsStrc* pSettings, const void* pHelpers);
    int (__fastcall* pfClose)();
    int (__fastcall* pfCreateSurface)(void* hWnd, int nResolutionMode);
    int (__fastcall* pfCloseSurface)();
    void (__fastcall* pfPauseSurface)(void* hWnd, int nResolutionMode, int nWindowState);
    int (__fastcall* pfStartDraw)(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);
    int (__fastcall* pfEndDraw)();
    int (__fastcall* pfBlit)();
    int (__fastcall* pfChangeRes)(void* hWnd, int nResolutionMode);
    int (__fastcall* pfGetBackBuffer)(unsigned char* pBuffer);
    int (__fastcall* pfActivateWindow)(int bActive, int bWindowed);
    int (__fastcall* pfSetOption)(int nOption, int nValue);
    int (__fastcall* pfPlayCutscene)();
    void (__fastcall* pfOpenSmackCutscene)(const char* szFile, int nResolutionMode, void* pfFrame);
    int (__fastcall* pfCheckCutScene)();
    void (__fastcall* pfDecodeSmacker)(const char* szSmacker, unsigned char* pBuffer, int nVersion);
    void (__fastcall* pfPlaySmacker)(void* pContext);
    void (__fastcall* pfCloseSmacker)(void* pContext);
    void* (__fastcall* pfGetCacheResults)();
    int (__fastcall* pfGetDimensions)(int* pWidth, int* pHeight);
    void (__fastcall* pfSetGlobalScale)(int nScaleFactor);
    int (__fastcall* pfSetGamma)(int nGamma);
    int (__fastcall* pfGammaCanBeControlled)();
    void (__fastcall* pfUpdatePerspective)(int nScaleX, int nScaleY);
    void (__fastcall* pfPerspectiveTransform)(int nPosX, int nPosY, int nBias, int* pXAdjust, int* pYAdjust);
    void (__fastcall* pfPerspectiveTransformScale)(int nPosX, int nPosY, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder);
    void (__fastcall* pfPerspectiveClearScale)();
    void (__fastcall* pfSetPalette)(tagPALETTEENTRY* pPalette);
    void (__fastcall* pfSetPaletteTables)(D2PaletteTableStrc* pPaletteTables);
    void (__fastcall* pfSetAmbientColor)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);
    void* pfFloorTileDraw;
    void* pfCelFlatSpriteDraw;
    void* pfCelDraw;
    void* pfCelDrawColor;
    void* pfCelDrawEx;
    void* pfCelDrawShadow;
    void* pfCelDrawHilight;
    void* pfCelDrawClipped;
    void* pfTileDrawLit;
    void* pfTileDrawTrans;
    void* pfShadowTileDraw;
    void (__fastcall* pfUtilDiamond)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilRect)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilFilledRect)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilPoint)(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex);
    void (__fastcall* pfDrawBox)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode);
    void (__fastcall* pfDrawBoxAlpha)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha);
    void* pfDrawLine;
    void (__fastcall* pfClearScreen)(int bPartial);
    void* pfOutputString;
    void* pfDebugDraw;
    void* pfDebugFillBackBuffer;
    void (__fastcall* pfClearCaches)();
};

extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#include "D2Win32Types.h"

struct D2WindowPlacementStrc
{
    void* hWnd;
    tagWINDOWPLACEMENT windowPlacement;
};
