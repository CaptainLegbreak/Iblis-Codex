#include "D2Glide.h"

struct D2GfxLightExStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090
extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink);                            // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink);                               // 0x006CC5C4
unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex);                                   // 0x005093F0
void __fastcall GLCORE_SetColorCombineMode(int nState);                                                      // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500
void __cdecl sub_0050BE20_GlideDebugRefresh();                                                               // 0x0050BE20
void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue);                         // 0x0050DBC0
void __cdecl DDRAW_ReleaseSurfaces();                                                           // 0x00511A80
int __fastcall DDRAW_CreateSurface(void* hWnd, int nResolutionMode);                           // 0x005115E0
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
extern "C" const char gszDisplay[];                                                                // 0x006DE1E8
extern "C" const char gszDdDebugFontSourceFile[];                                                  // 0x006DE1D0
extern unsigned long gdwDDrawDebugFontTextColor;                                                    // 0x0072F7F0
extern int gnRenderWidth;                                                                          // 0x007C9138
extern int gbRenderPaused;                                                                         // 0x007C9144
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride);        // 0x0087EAC4
extern void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
void (__stdcall* gpfnGrChromakeyMode)(int bEnable);                                                       // 0x0087EB8C
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor);                              // 0x0087EFA0
extern int gnGlideColorCombineState;                                                                           // 0x0087EFD8
extern int gnGlideAlphaCombineMode;                                                                           // 0x0087EFDC
extern int gnGlideTexFilterMode;                                                                           // 0x0087EFE0
extern int gbGlideDrawing;                                                                         // 0x0087EFE4
extern int gnGlideDebugX;                                                                          // 0x008800D0
extern int gnGlideDebugY;                                                                          // 0x008800D4
extern void** gppGlideDebugBuffer;                                                                 // 0x00880454
extern unsigned int gnGlideBinkY;                                                                  // 0x00880C04
extern unsigned int gnGlideBinkX;                                                                  // 0x00880C08
extern D2BinkStrc* gpGlideBink;                                                                    // 0x00880C0C
extern unsigned int gnGlideBinkFlags;                                                              // 0x00880C14
extern int gbGlideBinkDone;                                                                        // 0x00880C18
extern D2DDrawObjectStrc* gpDDrawObject_00881290;                                                           // 0x00881290
extern int gaDDrawDebugFontGlyphOffsets[96];                                                       // 0x008812A8
extern int gaDDrawDebugFontCharWidths[96];                                                         // 0x00881428
extern unsigned long gdwDDrawDebugFontBkColor;                                                     // 0x008815A8
extern unsigned char* gpDDrawDebugFontGlyphs;                                                      // 0x008815AC
extern unsigned int gnDDrawBinkY;                                                                  // 0x008816B8
extern unsigned int gnDDrawBinkX;                                                                  // 0x008816BC
extern D2BinkStrc* gpDDrawBink;                                                                    // 0x008816C0
extern unsigned int gnDDrawBinkFlags;                                                              // 0x008816C8
extern int gbDDrawBinkDone;                                                                        // 0x008816CC

// 0x0050BF50
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnRenderWidth);
    nXEnd = D2_MIN(D2_MAX(nXEnd, 0), gnRenderWidth);
    if (nX1 == nXEnd)
        return;
// build: symbol ?gnRenderHeight@* 0x007C913C
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnRenderHeight);
    nYEnd = D2_MIN(D2_MAX(nYEnd, 0), gnRenderHeight);
    if (nYEnd == nY1)
        return;
    D2_ASSERT(nYEnd > nY1, 0x29);
    GLCORE_SetColorCombineMode(2);
    GLCORE_SetAlphaBlendMode(4);
    gpfnGrChromakeyMode(0);
    vertices[0].x = (float)nX1;
    vertices[0].y = (float)nY1;
    vertices[0].oow = 1.0f;
    vertices[0].sow = 0.0f;
    vertices[0].tow = 0.0f;
    vertices[1].x = (float)nX1;
    vertices[1].y = (float)nYEnd;
    vertices[1].oow = 1.0f;
    vertices[1].sow = 0.0f;
    vertices[1].tow = 0.0f;
    vertices[2].x = (float)nXEnd;
    vertices[2].y = (float)nYEnd;
    vertices[2].oow = 1.0f;
    vertices[2].sow = 0.0f;
    vertices[2].tow = 0.0f;
    vertices[3].x = (float)nXEnd;
    vertices[3].y = (float)nY1;
    vertices[3].oow = 1.0f;
    vertices[3].sow = 0.0f;
    vertices[3].tow = 0.0f;
    unsigned int dwRGBA = GLCORE_GetPaletteColor((unsigned char)dwColor) & 0xFFFFFF00;
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
    gpfnGrConstantColorValue(dwRGBA);
    gpfnGrDrawVertexArrayContiguous(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfnGrChromakeyMode(1);
}

// 0x0050C0F0
void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnRenderWidth);
    nXEnd = D2_MIN(D2_MAX(nXEnd, 0), gnRenderWidth);
    if (nX1 == nXEnd)
        return;
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnRenderHeight);
    nYEnd = D2_MIN(D2_MAX(nYEnd, 0), gnRenderHeight);
    if (nYEnd == nY1)
        return;
    D2_ASSERT(nYEnd > nY1, 0x61);
    GLCORE_SetColorCombineMode(2);
    GLCORE_SetAlphaBlendMode(4);
    gpfnGrChromakeyMode(0);
    vertices[0].x = (float)nX1;
    vertices[0].y = (float)nY1;
    vertices[0].oow = 1.0f;
    vertices[0].sow = 0.0f;
    vertices[0].tow = 0.0f;
    vertices[1].x = (float)nX1;
    vertices[1].y = (float)nYEnd;
    vertices[1].oow = 1.0f;
    vertices[1].sow = 0.0f;
    vertices[1].tow = 0.0f;
    vertices[2].x = (float)nXEnd;
    vertices[2].y = (float)nYEnd;
    vertices[2].oow = 1.0f;
    vertices[2].sow = 0.0f;
    vertices[2].tow = 0.0f;
    vertices[3].x = (float)nXEnd;
    vertices[3].y = (float)nY1;
    vertices[3].oow = 1.0f;
    vertices[3].sow = 0.0f;
    vertices[3].tow = 0.0f;
    gpfnGrConstantColorValue(GLCORE_GetPaletteColor((unsigned char)dwColor) & 0xFFFFFF00 | nAlpha);
    gpfnGrDrawVertexArrayContiguous(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfnGrChromakeyMode(1);
}
