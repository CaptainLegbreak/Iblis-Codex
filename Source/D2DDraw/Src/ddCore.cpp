#include "D2DDraw.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"

struct D2CriticalSectionStrc;
struct D2TileLibraryEntryStrc;
struct D2GfxLightExStrc;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0
extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C
extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y); // 0x006CC0B8
extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho); // 0x006CC0D4
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink); // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink); // 0x006CC5C4
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex); // 0x005093F0
void __fastcall sub_005094B0_GlideSetState(int nState); // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode); // 0x00509500
void __cdecl sub_0050BE20_GlideDebugRefresh(); // 0x0050BE20
void __fastcall sub_0050DBC0_GlideSetAmbientColor(int nRed, int nGreen, int nBlue); // 0x0050DBC0
void __cdecl sub_00511A80_DDrawReleaseSurfaces(); // 0x00511A80
int __fastcall sub_005115E0_DDrawRestoreSurface(void* hWnd, int nResolutionMode); // 0x005115E0
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0
extern "C" const char gszCourier_006DD52C[]; // 0x006DD52C
extern unsigned long gdwDDrawDebugFontTextColor_0072F7F0; // 0x0072F7F0
extern int (__stdcall* gpfGlideLfbLock_0087EADC)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC
extern int (__stdcall* gpfGlideLfbUnlock_0087EAD8)(int nType, int nBuffer); // 0x0087EAD8
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfGlideTexDownloadTable_0087EB40)(int nType, void* pData); // 0x0087EB40
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable); // 0x0087EB8C
extern unsigned int gaGlidePalette_0087EBA0[256]; // 0x0087EBA0
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor); // 0x0087EFA0
extern int gbGlidePaletteTable_0087EFC8; // 0x0087EFC8
extern int gnGlideState_0087EFD8; // 0x0087EFD8
extern int gnGlideState_0087EFDC; // 0x0087EFDC
extern int gnGlideState_0087EFE0; // 0x0087EFE0
extern int gbGlideDrawing_0087EFE4; // 0x0087EFE4
extern unsigned int gnGlideBinkX_00880C08; // 0x00880C08
extern D2BinkStrc* gpGlideBink_00880C0C; // 0x00880C0C
extern int gbGlideBinkDone_00880C18; // 0x00880C18
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881278; // 0x00881278
extern D2DDrawObjectStrc* gpDDrawObject_00881290; // 0x00881290
extern int gaDDrawDebugFontCharWidths_00881428[96]; // 0x00881428
extern unsigned char* gpDDrawDebugFontGlyphs_008815AC; // 0x008815AC
extern unsigned int gnDDrawBinkX_008816BC; // 0x008816BC
extern D2BinkStrc* gpDDrawBink_008816C0; // 0x008816C0
extern int gbDDrawBinkDone_008816CC; // 0x008816CC
int __fastcall sub_00511B80_DDrawClose(); // 0x00511B80

D2CriticalSectionStrc* gpRenderCriticalSection_007C9134; // 0x007C9134

unsigned int gaGlideDebugLight_0087F0D0[0x400]; // 0x0087F0D0

int gnGlideDebugX_008800D0; // 0x008800D0

int gnGlideDebugY_008800D4; // 0x008800D4

void** gppGlideDebugBuffer_00880454; // 0x00880454

unsigned int gnGlideBinkY_00880C04; // 0x00880C04

unsigned int gnGlideBinkFlags_00880C14; // 0x00880C14

int gaDDrawDebugFontGlyphOffsets_008812A8[96]; // 0x008812A8

unsigned long gdwDDrawDebugFontBkColor_008815A8; // 0x008815A8

unsigned int gnDDrawBinkY_008816B8; // 0x008816B8

unsigned int gnDDrawBinkFlags_008816C8; // 0x008816C8

// 0x00508FE0
int __fastcall sub_00508FE0_GlideStartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (gbRenderPaused_007C9144)
        return 0;
    gbGlideDrawing_0087EFE4 = 1;
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x401);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (bClear)
        gpfGlideBufferClear_0087EB88((((nRed << 4) | nGreen) << 4 | nBlue) << 4, 0, 0);
    gnGlideState_0087EFD8 = 0;
    gnGlideState_0087EFDC = 0;
    gnGlideState_0087EFE0 = 0;
    gpfGlideMask_0087EB8C(1);
    sub_0050DBC0_GlideSetAmbientColor(0xFF, 0xFF, 0xFF);
    return 1;
}

// build: context sub_00509300_GlideSetPalette
void __fastcall sub_00509300_GlideSetPalette(const tagPALETTEENTRY* pPalette)
{
    if (gbGlidePaletteTable_0087EFC8)
    {
        for (int i = 0; i < 256; ++i)
            gaGlidePalette_0087EBA0[i] = ((((0xFF << 8) + pPalette[i].peRed) << 8) + pPalette[i].peGreen << 8) + pPalette[i].peBlue;
        gpfGlideTexDownloadTable_0087EB40(2, gaGlidePalette_0087EBA0);
    }
}

// 0x0050BEF0
void __fastcall sub_0050BEF0_GlideDebugDraw(const unsigned int* pLight, const unsigned int* pPlayerLight, int nPosX, int nPosY)
{
    gnGlideDebugX_008800D0 = nPosX;
    gnGlideDebugY_008800D4 = nPosY;
    memcpy(gaGlideDebugLight_0087F0D0, pLight, 0x1000);
    memcpy(*gppGlideDebugBuffer_00880454, pPlayerLight, 0x4800);
    sub_0050BE20_GlideDebugRefresh();
}

// build: context sub_0050BF50_GlideDrawBox
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnScreenWidth_007C9138);
    const int nX2 = D2_MIN(D2_MAX(nXEnd, 0), gnScreenWidth_007C9138);
    if (nX1 == nX2)
        return;
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnScreenHeight_007C913C);
    const int nY2 = D2_MIN(D2_MAX(nYEnd, 0), gnScreenHeight_007C913C);
    if (nY2 == nY1)
        return;
    D2_ASSERT(nY2 > nY1, 0x29);
    sub_005094B0_GlideSetState(2);
    sub_00509500_GlideSetCombine(4);
    gpfGlideMask_0087EB8C(0);
    vertices[0].x = (float)nX1;
    vertices[0].y = (float)nY1;
    vertices[0].oow = 1.0f;
    vertices[0].sow = 0.0f;
    vertices[0].tow = 0.0f;
    vertices[1].x = (float)nX1;
    vertices[1].y = (float)nY2;
    vertices[1].oow = 1.0f;
    vertices[1].sow = 0.0f;
    vertices[1].tow = 0.0f;
    vertices[2].x = (float)nX2;
    vertices[2].y = (float)nY2;
    vertices[2].oow = 1.0f;
    vertices[2].sow = 0.0f;
    vertices[2].tow = 0.0f;
    vertices[3].x = (float)nX2;
    vertices[3].y = (float)nY1;
    vertices[3].oow = 1.0f;
    vertices[3].sow = 0.0f;
    vertices[3].tow = 0.0f;
    unsigned int dwRGBA = sub_005093F0_GlidePaletteColor((unsigned char)dwColor) & 0xFFFFFF00;
    switch (nDrawMode)
    {
    case 0:
        dwRGBA += 0x40;
        break;
    case 1:
        dwRGBA += 0x80;
        break;
    case 2:
        dwRGBA += 0xC0;
        break;
    default:
        dwRGBA += 0xFF;
        break;
    }
    gpfGlideConstantColor_0087EFA0(dwRGBA);
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfGlideMask_0087EB8C(1);
}

// build: context sub_0050C0F0_GlideDrawBoxAlpha
void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnScreenWidth_007C9138);
    const int nX2 = D2_MIN(D2_MAX(nXEnd, 0), gnScreenWidth_007C9138);
    if (nX1 == nX2)
        return;
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnScreenHeight_007C913C);
    const int nY2 = D2_MIN(D2_MAX(nYEnd, 0), gnScreenHeight_007C913C);
    if (nY2 == nY1)
        return;
    D2_ASSERT(nY2 > nY1, 0x61);
    sub_005094B0_GlideSetState(2);
    sub_00509500_GlideSetCombine(4);
    gpfGlideMask_0087EB8C(0);
    vertices[0].x = (float)nX1;
    vertices[0].y = (float)nY1;
    vertices[0].oow = 1.0f;
    vertices[0].sow = 0.0f;
    vertices[0].tow = 0.0f;
    vertices[1].x = (float)nX1;
    vertices[1].y = (float)nY2;
    vertices[1].oow = 1.0f;
    vertices[1].sow = 0.0f;
    vertices[1].tow = 0.0f;
    vertices[2].x = (float)nX2;
    vertices[2].y = (float)nY2;
    vertices[2].oow = 1.0f;
    vertices[2].sow = 0.0f;
    vertices[2].tow = 0.0f;
    vertices[3].x = (float)nX2;
    vertices[3].y = (float)nY1;
    vertices[3].oow = 1.0f;
    vertices[3].sow = 0.0f;
    vertices[3].tow = 0.0f;
    gpfGlideConstantColor_0087EFA0(sub_005093F0_GlidePaletteColor((unsigned char)dwColor) & 0xFFFFFF00 | nAlpha);
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfGlideMask_0087EB8C(1);
}

// 0x0050FD10
void __cdecl sub_0050FD10_GlideDrawVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpGlideBink_00880C0C);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x39);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    D2GrLfbInfoStrc info = { sizeof(D2GrLfbInfoStrc) };
    if (gpfGlideLfbLock_0087EADC(1, 0, 5, 0, 0, &info))
    {
        BinkCopyToBuffer(gpGlideBink_00880C0C, info.lfbPtr, info.strideInBytes, gpGlideBink_00880C0C->nHeight, gnGlideBinkX_00880C08, gnGlideBinkY_00880C04, gnGlideBinkFlags_00880C14);
        gpfGlideLfbUnlock_0087EAD8(1, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    if (gpGlideBink_00880C0C->nFrameNum == gpGlideBink_00880C0C->nFrames)
    {
        gbGlideBinkDone_00880C18 = 1;
        return;
    }
    BinkNextFrame(gpGlideBink_00880C0C);
}

// 0x00511C20
void __fastcall sub_00511C20_DDrawPauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x2F7);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (nWindowState)
    {
        gbRenderPaused_007C9144 = 1;
        sub_00511A80_DDrawReleaseSurfaces();
        if (gpDDrawObject_00881290)
        {
            gpDDrawObject_00881290->lpVtbl->Release(gpDDrawObject_00881290);
            gpDDrawObject_00881290 = 0;
        }
        gbSurfaceActive_007C9140 = 0;
    }
    else
    {
        gbRenderPaused_007C9144 = 0;
        sub_005115E0_DDrawRestoreSurface(hWnd, nResolutionMode);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
}

// 0x00512430
void __cdecl sub_00512430_DDrawCreateDebugFont()
{
    void* hDC = CreateDCA("DISPLAY", 0, 0, 0);
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier_006DD52C);
    void* hBitmap = CreateBitmap(8, 16, 1, 8, 0);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwDDrawDebugFontTextColor_0072F7F0);
    SetBkColor(hDC, gdwDDrawDebugFontBkColor_008815A8);
    SetBkMode(hDC, 2);
    tagRECT rect;
    SetRect(&rect, 0, 0, 8, 16);
    gpDDrawDebugFontGlyphs_008815AC = (unsigned char*)FOG_Alloc(0x3000, ".\\Src\\ddDebugFont.cpp", 0x3A, 0);
    unsigned char* pMask = gpDDrawDebugFontGlyphs_008815AC;
    int nOffset = 0;
    for (int nChar = 0x20; nChar <= 0x7F; ++nChar)
    {
        char cChar = nChar;
        DrawTextA(hDC, &cChar, 1, &rect, 0);
        for (int y = 0; y < 16; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (GetPixel(hDC, x, y) == gdwDDrawDebugFontTextColor_0072F7F0)
                    *pMask++ = 0xFF;
                else
                    *pMask++ = 0;
            }
        }
        gaDDrawDebugFontGlyphOffsets_008812A8[nChar - 0x20] = nOffset;
        nOffset += 0x80;
    }
    GetCharWidthA(hDC, 0x20, 0x7F, gaDDrawDebugFontCharWidths_00881428);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

// 0x005128B0
void __fastcall sub_005128B0_DDrawDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    int nDrawMode;
    if (nAlpha >= 0xC0)
        nDrawMode = 5;
    else if (nAlpha >= 0x80)
        nDrawMode = 2;
    else if (nAlpha >= 0x40)
        nDrawMode = 1;
    else if (nAlpha > 0)
        nDrawMode = 0;
    else
        return;
    sub_00512710_DDrawDrawBox(nXStart, nYStart, nXEnd, nYEnd, dwColor, nDrawMode);
}

// 0x00512900
void __fastcall sub_00512900_DDrawPutPixel(int nX, int nY, unsigned char nColor)
{
    if (nX >= 0 && nX < gnScreenWidth_007C9138 && nY >= 0 && nY < gnScreenHeight_007C913C)
        gpScreenBuffer_007C9154[gnScreenWidth_007C9138 * nY + nX] = nColor;
}

// 0x005132C0
int __fastcall sub_005132C0_DDrawFloorTileDraw(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData)
{
    int nResult = sub_005FDEA0(pTile, 1, 0);
    if (nResult)
    {
        nPosX -= 0x50;
        switch (nScreenPanels)
        {
        case 1:
            nPosX -= gnScreenWidth_007C9138 / 4;
            break;
        case 2:
            nPosX += gnScreenWidth_007C9138 / 4;
            break;
        }
        nResult = gpTileDrawFunctions_007C914C->pfDrawFloorTile(pTile, nPosX, nPosY, pLight);
    }
    return nResult;
}

// 0x005136F0
void __cdecl sub_005136F0_BlitBinkFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpDDrawBink_008816C0);
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x42);
    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    D2DDSurfaceDescStrc ddsd = { sizeof(D2DDSurfaceDescStrc) };
    if (gpDDrawSurface_00881278->lpVtbl->Lock(gpDDrawSurface_00881278, 0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpDDrawBink_008816C0, ddsd.lpSurface, ddsd.lPitch, gpDDrawBink_008816C0->nHeight, gnDDrawBinkX_008816BC, gnDDrawBinkY_008816B8, gnDDrawBinkFlags_008816C8);
        gpDDrawSurface_00881278->lpVtbl->Unlock(gpDDrawSurface_00881278, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    if (gpDDrawBink_008816C0->nFrameNum == gpDDrawBink_008816C0->nFrames)
    {
        gbDDrawBinkDone_008816CC = 1;
        return;
    }
    BinkNextFrame(gpDDrawBink_008816C0);
}

#include "gen/data/Source/D2DDraw/Src/ddCore.inc"

// 0x00511CD0
void __cdecl sub_00511CD0_DDrawCloseAtExit()
{
    sub_00511B80_DDrawClose();
}
