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
unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex);                                   // 0x005093F0
void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __cdecl sub_0050BE20_GlideDebugRefresh();                                                               // 0x0050BE20
void __fastcall sub_0050DBC0_GlideSetAmbientColor(int nRed, int nGreen, int nBlue);                         // 0x0050DBC0
void __cdecl sub_00511A80_DDrawReleaseSurfaces();                                                           // 0x00511A80
int __fastcall sub_005115E0_DDrawRestoreSurface(void* hWnd, int nResolutionMode);                           // 0x005115E0
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
extern "C" const char gszDisplay_006DE1E8[];                                                                // 0x006DE1E8
extern "C" const char gszDdDebugFontSourceFile_006DE1D0[];                                                  // 0x006DE1D0
extern unsigned long gdwDDrawDebugFontTextColor_0072F7F0;                                                    // 0x0072F7F0
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride);        // 0x0087EAC4
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable);                                                       // 0x0087EB8C
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0
extern int gnGlideState_0087EFD8;                                                                           // 0x0087EFD8
extern int gnGlideState_0087EFDC;                                                                           // 0x0087EFDC
extern int gnGlideState_0087EFE0;                                                                           // 0x0087EFE0
extern int gbGlideDrawing_0087EFE4;                                                                         // 0x0087EFE4
extern int gnGlideDebugX_008800D0;                                                                          // 0x008800D0
extern int gnGlideDebugY_008800D4;                                                                          // 0x008800D4
extern void** gppGlideDebugBuffer_00880454;                                                                 // 0x00880454
extern unsigned int gnGlideBinkY_00880C04;                                                                  // 0x00880C04
extern unsigned int gnGlideBinkX_00880C08;                                                                  // 0x00880C08
extern D2BinkStrc* gpGlideBink_00880C0C;                                                                    // 0x00880C0C
extern unsigned int gnGlideBinkFlags_00880C14;                                                              // 0x00880C14
extern int gbGlideBinkDone_00880C18;                                                                        // 0x00880C18
extern D2DDrawObjectStrc* gpDDrawObject_00881290;                                                           // 0x00881290
extern int gaDDrawDebugFontGlyphOffsets_008812A8[96];                                                       // 0x008812A8
extern int gaDDrawDebugFontCharWidths_00881428[96];                                                         // 0x00881428
extern unsigned long gdwDDrawDebugFontBkColor_008815A8;                                                     // 0x008815A8
extern unsigned char* gpDDrawDebugFontGlyphs_008815AC;                                                      // 0x008815AC
extern unsigned int gnDDrawBinkY_008816B8;                                                                  // 0x008816B8
extern unsigned int gnDDrawBinkX_008816BC;                                                                  // 0x008816BC
extern D2BinkStrc* gpDDrawBink_008816C0;                                                                    // 0x008816C0
extern unsigned int gnDDrawBinkFlags_008816C8;                                                              // 0x008816C8
extern int gbDDrawBinkDone_008816CC;                                                                        // 0x008816CC

// 0x0050BF50
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnScreenWidth_007C9138);
    nXEnd = D2_MIN(D2_MAX(nXEnd, 0), gnScreenWidth_007C9138);
    if (nX1 == nXEnd)
        return;
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnScreenHeight_007C913C);
    nYEnd = D2_MIN(D2_MAX(nYEnd, 0), gnScreenHeight_007C913C);
    if (nYEnd == nY1)
        return;
    D2_ASSERT(nYEnd > nY1, 0x29);
    sub_005094B0_GlideSetState(2);
    sub_00509500_GlideSetCombine(4);
    gpfGlideMask_0087EB8C(0);
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

// 0x0050C0F0
void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnScreenWidth_007C9138);
    nXEnd = D2_MIN(D2_MAX(nXEnd, 0), gnScreenWidth_007C9138);
    if (nX1 == nXEnd)
        return;
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnScreenHeight_007C913C);
    nYEnd = D2_MIN(D2_MAX(nYEnd, 0), gnScreenHeight_007C913C);
    if (nYEnd == nY1)
        return;
    D2_ASSERT(nYEnd > nY1, 0x61);
    sub_005094B0_GlideSetState(2);
    sub_00509500_GlideSetCombine(4);
    gpfGlideMask_0087EB8C(0);
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
    gpfGlideConstantColor_0087EFA0(sub_005093F0_GlidePaletteColor((unsigned char)dwColor) & 0xFFFFFF00 | nAlpha);
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfGlideMask_0087EB8C(1);
}
