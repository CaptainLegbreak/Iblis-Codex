#include "D2Win.h"
#include "D2GlideTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define GLIDE_GETPROC(pfn, szName, nLine) *(void**)&pfn = GetProcAddress(ghGlideLibrary_0087EFA8, szName); D2_ASSERT(pfn, nLine)

struct D2GrLfbInfoStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);
extern void (__stdcall* gpfGlideFn_0087EB9C)(int a1, int a2, int a3); // 0x0087EB9C
extern void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval); // 0x0087EB90
extern void* gpfGlideFinish_0087EB14; // 0x0087EB14
extern void* gpfGlideSstWinClose_0087EFA4; // 0x0087EFA4
extern void (__stdcall* gpfGlideFn_0087EB3C)(int a1); // 0x0087EB3C
extern void (__stdcall* gpfGlideFn4_0087EACC)(int a1, int a2, int a3, int a4); // 0x0087EACC
extern void (__stdcall* gpfGlideFn5_0087EAF0)(int a1, int a2, int a3, int a4, int a5); // 0x0087EAF0
extern void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable); // 0x0087EB8C
extern void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor); // 0x0087EFA0
extern void (__stdcall* gpfGlideAlphaFunction_0087EAB4)(int nFunction); // 0x0087EAB4
extern int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams); // 0x0087EB1C
extern void (__stdcall* gpfGlideFn7_0087EAD0)(int a1, int a2, int a3, int a4, int a5, int a6, int a7); // 0x0087EAD0
extern void (__stdcall* gpfGlideFn3_0087EAFC)(int a1, int a2, int a3); // 0x0087EAFC
extern void (__stdcall* gpfGlideFn_0087EB04)(); // 0x0087EB04
extern void (__stdcall* gpfGlideFn_0087EAB0)(); // 0x0087EAB0

int __cdecl sub_00508970_GlideLoadLibrary(); // 0x00508970
void __fastcall sub_0050ECB0_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush); // 0x0050ECB0
void __fastcall sub_0050F210_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush); // 0x0050F210
void __fastcall sub_0050F7C0_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush); // 0x0050F7C0
extern D2GlideTileCacheStrc gGlideTileCache_0087EB48; // 0x0087EB48
extern D2GlideFloorCacheStrc gGlideFloorCache_0087EB68; // 0x0087EB68
extern D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4]; // 0x0087F048

void* ghGlideLibrary_0087EFA8; // 0x0087EFA8

void (__stdcall* gpfGlideGammaCorrectionRGB_0087EABC)(float fRed, float fGreen, float fBlue); // 0x0087EABC

void (__stdcall* gpfGlideDrawPoint_0087EAA0)(const D2GlideSpriteVertexStrc* pVertex); // 0x0087EAA0

void (__stdcall* gpfGlideDrawLine_0087E978)(const D2GlideSpriteVertexStrc* pStart, const D2GlideSpriteVertexStrc* pEnd); // 0x0087E978

void* gpfGlideDrawTriangle_0087EB0C; // 0x0087EB0C

void (__stdcall* gpfGlideDrawVertexArray_0087EB18)(int nMode, int nCount, void** ppVertices); // 0x0087EB18

void* (__stdcall* gpfGlideFn_0087EAF4)(void* hWnd, int nRes, int nRefresh, int nFormat, int nOrigin, int nBuffers, int nAux); // 0x0087EAF4

void (__stdcall* gpfGlideFn_0087EB34)(int a1); // 0x0087EB34

void* gpfGlideClipWindow_0087EB10; // 0x0087EB10

void (__stdcall* gpfGlideFn_0087EB30)(int a1, int a2); // 0x0087EB30

void* gpfGlideDepthBufferFunction_0087EB28; // 0x0087EB28

void* gpfGlideDepthBufferMode_0087EB20; // 0x0087EB20

void (__stdcall* gpfGlideFn_0087E97C)(int a1); // 0x0087E97C

void (__stdcall* gpfGlideLoadGammaTable_0087EAE0)(int nEntries, unsigned int* pRed, unsigned int* pGreen, unsigned int* pBlue); // 0x0087EAE0

void* gpfGlideGetString_0087EAC8; // 0x0087EAC8

void* gpfGlideGetProcAddress_0087EB08; // 0x0087EB08

void* gpfGlideEnable_0087EAC0; // 0x0087EAC0

void* gpfGlideDisable_0087EAF8; // 0x0087EAF8

void (__stdcall* gpfGlideFn_0087EB38)(int a1); // 0x0087EB38

void* gpfGlideTexTextureMemRequired_0087EB00; // 0x0087EB00

void* gpfGlideTexMinAddress_0087EB24; // 0x0087EB24

void* gpfGlideTexMaxAddress_0087EB44; // 0x0087EB44

void (__stdcall* gpfGlideTexDownloadTable_0087EB40)(int nType, void* pData); // 0x0087EB40

void* gpfGlideTexMipMapMode_0087EAD4; // 0x0087EAD4

int (__stdcall* gpfGlideLfbLock_0087EADC)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC

int (__stdcall* gpfGlideLfbUnlock_0087EAD8)(int nType, int nBuffer); // 0x0087EAD8

// 0x00508970
int __cdecl sub_00508970_GlideLoadLibrary()
{
    ghGlideLibrary_0087EFA8 = LoadLibraryA("glide3x.dll");
    if (!ghGlideLibrary_0087EFA8)
    {
        return 0;
    }

    GLIDE_GETPROC(gpfGlideGammaCorrectionRGB_0087EABC, "_guGammaCorrectionRGB@12", 0x9E);
    GLIDE_GETPROC(gpfGlideDrawPoint_0087EAA0, "_grDrawPoint@4", 0xA1);
    GLIDE_GETPROC(gpfGlideDrawLine_0087E978, "_grDrawLine@8", 0xA2);
    GLIDE_GETPROC(gpfGlideDrawTriangle_0087EB0C, "_grDrawTriangle@12", 0xA3);
    GLIDE_GETPROC(gpfGlideFn_0087EB9C, "_grVertexLayout@12", 0xA4);
    GLIDE_GETPROC(gpfGlideDrawVertexArray_0087EB18, "_grDrawVertexArray@12", 0xA5);
    GLIDE_GETPROC(gpfGlideDrawVertexArrayContiguous_0087EAC4, "_grDrawVertexArrayContiguous@16", 0xA6);
    GLIDE_GETPROC(gpfGlideBufferClear_0087EB88, "_grBufferClear@12", 0xA8);
    GLIDE_GETPROC(gpfGlideBufferSwap_0087EB90, "_grBufferSwap@4", 0xA9);
    GLIDE_GETPROC(gpfGlideFinish_0087EB14, "_grFinish@0", 0xAA);
    GLIDE_GETPROC(gpfGlideFn_0087EAF4, "_grSstWinOpen@28", 0xAB);
    GLIDE_GETPROC(gpfGlideSstWinClose_0087EFA4, "_grSstWinClose@4", 0xAC);
    GLIDE_GETPROC(gpfGlideFn_0087EB3C, "_grSstSelect@4", 0xAD);
    GLIDE_GETPROC(gpfGlideFn4_0087EACC, "_grAlphaBlendFunction@16", 0xAE);
    GLIDE_GETPROC(gpfGlideFn5_0087EAF0, "_grAlphaCombine@20", 0xAF);
    GLIDE_GETPROC(gpfGlideMask_0087EB8C, "_grChromakeyMode@4", 0xB0);
    GLIDE_GETPROC(gpfGlideFn_0087EB34, "_grChromakeyValue@4", 0xB1);
    GLIDE_GETPROC(gpfGlideClipWindow_0087EB10, "_grClipWindow@16", 0xB2);
    GLIDE_GETPROC(gpfGlideColorCombine_0087EB2C, "_grColorCombine@20", 0xB3);
    GLIDE_GETPROC(gpfGlideFn_0087EB30, "_grColorMask@8", 0xB4);
    GLIDE_GETPROC(gpfGlideConstantColor_0087EFA0, "_grConstantColorValue@4", 0xB5);
    GLIDE_GETPROC(gpfGlideDepthBufferFunction_0087EB28, "_grDepthBufferFunction@4", 0xB6);
    GLIDE_GETPROC(gpfGlideDepthBufferMode_0087EB20, "_grDepthBufferMode@4", 0xB7);
    GLIDE_GETPROC(gpfGlideFn_0087E97C, "_grDepthMask@4", 0xB8);
    GLIDE_GETPROC(gpfGlideAlphaFunction_0087EAB4, "_grDitherMode@4", 0xB9);
    GLIDE_GETPROC(gpfGlideLoadGammaTable_0087EAE0, "_grLoadGammaTable@16", 0xBA);
    GLIDE_GETPROC(gpfGlideGet_0087EB1C, "_grGet@12", 0xBB);
    GLIDE_GETPROC(gpfGlideGetString_0087EAC8, "_grGetString@4", 0xBC);
    GLIDE_GETPROC(gpfGlideGetProcAddress_0087EB08, "_grGetProcAddress@4", 0xBD);
    GLIDE_GETPROC(gpfGlideEnable_0087EAC0, "_grEnable@4", 0xBE);
    GLIDE_GETPROC(gpfGlideDisable_0087EAF8, "_grDisable@4", 0xBF);
    GLIDE_GETPROC(gpfGlideFn_0087EB38, "_grCoordinateSpace@4", 0xC0);
    GLIDE_GETPROC(gpfGlideTexTextureMemRequired_0087EB00, "_grTexTextureMemRequired@8", 0xC1);
    GLIDE_GETPROC(gpfGlideTexMinAddress_0087EB24, "_grTexMinAddress@4", 0xC2);
    GLIDE_GETPROC(gpfGlideTexMaxAddress_0087EB44, "_grTexMaxAddress@4", 0xC3);
    GLIDE_GETPROC(gpfGlideTexSource_0087EB98, "_grTexSource@16", 0xC4);
    GLIDE_GETPROC(gpfGlideFn7_0087EAD0, "_grTexCombine@28", 0xC5);
    GLIDE_GETPROC(gpfGlideFn3_0087EAFC, "_grTexFilterMode@12", 0xC6);
    GLIDE_GETPROC(gpfGlideTexDownloadMipMap_0087EAB8, "_grTexDownloadMipMap@16", 0xC7);
    GLIDE_GETPROC(gpfGlideTexDownloadTable_0087EB40, "_grTexDownloadTable@8", 0xC8);
    GLIDE_GETPROC(gpfGlideTexMipMapMode_0087EAD4, "_grTexMipMapMode@12", 0xC9);
    GLIDE_GETPROC(gpfGlideLfbLock_0087EADC, "_grLfbLock@24", 0xCA);
    GLIDE_GETPROC(gpfGlideLfbUnlock_0087EAD8, "_grLfbUnlock@8", 0xCB);
    GLIDE_GETPROC(gpfGlideFn_0087EB04, "_grGlideInit@0", 0xCC);
    GLIDE_GETPROC(gpfGlideFn_0087EAB0, "_grGlideShutdown@0", 0xCD);

    return 1;
}

int gnGlideNumBoards_0087EFC4; // 0x0087EFC4

// 0x00508F60
int __cdecl sub_00508F60_GlideCheckBoards()
{
    if (!sub_00508970_GlideLoadLibrary())
    {
        return 0;
    }

    gpfGlideGet_0087EB1C(0xF, 4, &gnGlideNumBoards_0087EFC4);
    return gnGlideNumBoards_0087EFC4 > 0;
}

// 0x00508F90
void __cdecl sub_00508F90_GlideDestroyTexCaches()
{
    sub_0050F7C0_FloorCacheDestroy(&gGlideFloorCache_0087EB68, 0);
    sub_0050F210_TileCacheDestroy(&gGlideTileCache_0087EB48, 0);
    sub_0050ECB0_TexCacheDestroy(&gaGlideTexCaches_0087F048[1], 0);
    sub_0050ECB0_TexCacheDestroy(&gaGlideTexCaches_0087F048[2], 0);
    sub_0050ECB0_TexCacheDestroy(&gaGlideTexCaches_0087F048[3], 0);
}
