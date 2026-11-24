#include "D2Gdi.h"
#include "D2Win32Base.h"
#include "D2CelContext.h"
#include "D2GfxTypes.h"

struct D2CelStrc;
struct D2ClipRectStrc;
struct D2ClipResultStrc;
extern int gnWideWidth_0098A16C; // 0x0098A16C
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
extern int gnRenderHeight; // 0x007C913C
static int __stdcall sub_006C8310_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter);

struct D2ClipRectStrc { int left, right, top, bottom; };

struct D2ClipResultStrc { int left, right, skipRows, rowCount; };
extern const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250
extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150
int __stdcall CmpDoLensEffect(unsigned char* pPixel, int nStride); // 0x00608C00
int __fastcall GDI_DrawImage(void* context, int second, int third, int fourth, int fifth, int last); // 0x006C84B0
extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int height, int width, int escapement, int orientation, int weight, unsigned long italic, unsigned long underline, unsigned long strikeout, unsigned long charset, unsigned long outPrecision, unsigned long clipPrecision, unsigned long quality, unsigned long pitchAndFamily, const char* face); // 0x006CC0E0
extern const char gszCourier[]; // 0x006DD52C
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object); // 0x006CC0D4
extern void* ghGdiDebugFont; // 0x0098A170

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd); // 0x006CC44C
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC); // 0x006CC448
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hdc); // 0x006CC0A0
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8
void* __cdecl sub_006C8020(); // 0x006C8020
extern unsigned long gdwGdiDebugTextColor; // 0x0074C5C0
extern void* ghGdiDebugFont_0098A170; // 0x0098A170

extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148
void __fastcall sub_006C8A60_Draw(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nLevel); // 0x006C8A60

// 0x006C8250
int __fastcall sub_006C8250_GetSetting(unsigned int nSelector, int* pValue)
{
// build: symbol ?gaSelectorValues@* 0x0074C5A0
    *pValue = gaSelectorValues[nSelector];
    switch (nSelector)
    {
    case 0:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[2];
    case 1:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[1];
    case 2:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[0];
    case 3:
        return (int)gpGfxPaletteView_007C9150->pScreenPalette;
    case 4:
        return (int)gpGfxPaletteView_007C9150->pLuminancePalette;
    case 6:
        return (int)gpGfxPaletteView_007C9150->pDarkBlendPalette;
    }
    return 0;
}

#include "gen/data/Source/D2Gdi/Unknown_006C8250.inc"

int gnGdiOriginX; // 0x0098A168

int gnModeWidth; // 0x0098A16C

// 0x006C82D0
void __fastcall sub_006C82D0_SetResolution(int nMode)
{
    if (nMode != 0)
    {
        gnGdiOriginX = 0;
        if (nMode != 3)
            gnModeWidth = 800;
        else
            gnWideWidth_0098A16C = 1344;
    }
    else
    {
        gnGdiOriginX = 0;
        gnModeWidth = 640;
    }
}

// 0x006C8310
static int __stdcall sub_006C8310_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

extern "C" int __stdcall sub_006C8310_EmitCelClip(D2CelStrc* pCel, int nX, int nY)
{
    return sub_006C8310_IsCelOffScreen(pCel, nX, nY, 0) + 9;
}

static
// 0x006C8380
int __stdcall sub_006C8380_ClipCel(D2CelStrc* cel, int x, int y, const D2ClipRectStrc* clip, D2ClipResultStrc* result)
{
    int width = CelGetWidth(cel);
    int height = CelGetHeight(cel);
    int left = clip->left > 0 ? clip->left : 0;
    int right = clip->right < gnSurfaceWidth_007C9138 ? clip->right : gnSurfaceWidth_007C9138;
    if (left > right)
        return 1;
    x += CelGetOffsetX(cel);
    if (x >= right || x + width < left)
        return 1;
    int top = clip->top > 0 ? clip->top : 0;
    int bottom = clip->bottom < gnSurfaceHeight_007C913C ? clip->bottom : gnSurfaceHeight_007C913C;
    if (top > bottom)
        return 1;
    y += CelGetOffsetY(cel);
    if (y < top || y - height > bottom)
        return 1;
    result->left = left;
    result->right = right;
    if (y <= bottom)
        result->skipRows = 0;
    else
        result->skipRows = y - bottom - 1;
    if (y - height >= top)
        result->rowCount = height - result->skipRows;
    else
        result->rowCount = y - result->skipRows - top + 1;
    if (result->rowCount <= 0)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 209);
        exit(-1);
    }
    return 0;
}

int __fastcall EmitClipCel(const D2ClipRectStrc* clip, D2CelStrc* cel, int x, int y, D2ClipResultStrc* result)
{
    return sub_006C8380_ClipCel(cel, x, y, clip + 1, result);
}

static int __stdcall sub_006C85A0_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

// 0x006C85A0
int __fastcall sub_006C85A0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_006C85A0_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    {
        unsigned char* pGammaTable = 0;
        unsigned char* pPaletteTable = 0;
        int nType;
        const int nCaps = sub_006C8250_GetSetting(nDrawMode, &nType);
        const int nGamma = (unsigned char)dwGamma;
        if (nGamma != 0xFF)
            pGammaTable = gpGfxPaletteView_007C9150->pShadowLightGammaPalettes[nGamma >> 3];
        if (nDrawMode == 7)
            pGammaTable = gpGfxPaletteView_007C9150->pRemap;
        if (nPalette)
            pPaletteTable = gpGfxPaletteView_007C9150->pStandardShiftPalettes[nPalette];

        CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
            gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPaletteTable);
    }
    return 1;
}

// 0x006C88B0
int __fastcall sub_006C88B0_DrawAt(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnStride_007C9138 - 80, 0x1AB);
    D2_ASSERT(nY > 0 && nY < gnHeight_007C913C - 80, 0x1AC);
    return CmpDoLensEffect(gpBuffer_007C9154 + nY * gnStride_007C9138 + nX, gnStride_007C9138);
}

// 0x006C8910
int __fastcall sub_006C8910_ForwardDraw(void* context, int second, int third, int fourth, int fifth, int unused, int last)
{
    return GDI_DrawImage(context, second, third, fourth, fifth, last);
}

void* ghGdiDebugFont; // 0x0098A170

// 0x006C8930
void __cdecl sub_006C8930_CreateGraphicFont()
{
    ghGdiDebugFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier);
}

// 0x006C8960
void __cdecl sub_006C8960_DeleteGraphicObject()
{
    DeleteObject(ghGdiDebugFont);
}

unsigned long gdwGdiDebugBkColor; // 0x0098A174

// 0x006C8970
void __fastcall sub_006C8970_GdiDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    int anText[0x200 / sizeof(int)];
    wvsprintfA((char*)anText, szFormat, args);
    void* hScreenDC = GetDC(0);
    void* hDC = CreateCompatibleDC(hScreenDC);
    SelectObject(hDC, sub_006C8020());
    SelectObject(hDC, ghGdiDebugFont_0098A170);
    SetTextColor(hDC, gdwGdiDebugTextColor);
    SetBkColor(hDC, gdwGdiDebugBkColor);
    SetBkMode(hDC, 1);
    tagRECT tRect;
    SetRect(&tRect, nX, nY, gnRenderWidth - nX, gnRenderHeight - nY);
    DrawTextA(hDC, (char*)anText, -1, &tRect, 0);
    DeleteDC(hDC);
    ReleaseDC(0, hScreenDC);
}

// 0x006C8A50
int __cdecl sub_006C8A50_GetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}

// 0x006C8C00
void __fastcall sub_006C8C00_DrawAlpha(int nArg1, int nArg2, int a, int b, int c, unsigned char nAlpha)
{
    int nLevel;
    if (nAlpha >= 0xC0)
        nLevel = 5;
    else if (nAlpha >= 0x80)
        nLevel = 2;
    else if (nAlpha >= 0x40)
        nLevel = 1;
    else if (nAlpha > 0)
        nLevel = 0;
    else
        return;
    sub_006C8A60_Draw(nArg1, nArg2, a, b, c, nLevel);
}
