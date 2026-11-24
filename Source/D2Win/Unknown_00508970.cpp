#include "D2Win.h"
#include "D2GlideTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define GLIDE_GETPROC(pfn, szName, nLine) *(void**)&pfn = GetProcAddress(ghGlideLibrary, szName); D2_ASSERT(pfn, nLine)

struct D2GrLfbInfoStrc;
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);
extern void (__stdcall* gpfnGrVertexLayout)(int a1, int a2, int a3); // 0x0087EB9C
extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfnGrBufferSwap)(int nSwapInterval); // 0x0087EB90
extern void* gpfGlideFinish_0087EB14; // 0x0087EB14
extern void* gpfGlideSstWinClose_0087EFA4; // 0x0087EFA4
extern void (__stdcall* gpfnGrSstSelect)(int a1); // 0x0087EB3C
extern void (__stdcall* gpfnGrAlphaBlendFunction)(int a1, int a2, int a3, int a4); // 0x0087EACC
extern void (__stdcall* gpfnGrAlphaCombine)(int a1, int a2, int a3, int a4, int a5); // 0x0087EAF0
extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C
extern void (__stdcall* gpfnGrColorCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0
extern void (__stdcall* gpfnGrDitherMode)(int nFunction); // 0x0087EAB4
extern int (__stdcall* gpfnGrGet)(int nName, int nSize, int* pParams); // 0x0087EB1C
extern void (__stdcall* gpfnGrTexCombine)(int a1, int a2, int a3, int a4, int a5, int a6, int a7); // 0x0087EAD0
extern void (__stdcall* gpfnGrTexFilterMode)(int a1, int a2, int a3); // 0x0087EAFC
extern void (__stdcall* gpfnGrGlideInit)(); // 0x0087EB04
extern void (__stdcall* gpfnGrGlideShutdown)(); // 0x0087EAB0

int __cdecl sub_00508970_GlideLoadLibrary(); // 0x00508970
void __fastcall GLTEXTURECACHE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush); // 0x0050ECB0
void __fastcall GLSUBTILECACHE_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush); // 0x0050F210
void __fastcall GLFLOORCACHE_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush); // 0x0050F7C0
extern D2GlideTileCacheStrc gtGlideTileCache; // 0x0087EB48
extern D2GlideFloorCacheStrc gtGlideFloorCache; // 0x0087EB68
extern D2GlideTexCacheStrc gaGlideTexCaches[4]; // 0x0087F048

void* ghGlideLibrary; // 0x0087EFA8

void (__stdcall* gpfnGuGammaCorrectionRGB)(float fRed, float fGreen, float fBlue); // 0x0087EABC

void (__stdcall* gpfnGrDrawPoint)(const D2GlideSpriteVertexStrc* pVertex); // 0x0087EAA0

void (__stdcall* gpfnGrDrawLine)(const D2GlideSpriteVertexStrc* pStart, const D2GlideSpriteVertexStrc* pEnd); // 0x0087E978

void* gpfnGrDrawTriangle; // 0x0087EB0C

void (__stdcall* gpfnGrDrawVertexArray)(int nMode, int nCount, void** ppVertices); // 0x0087EB18

void* (__stdcall* gpfnGrSstWinOpen)(void* hWnd, int nRes, int nRefresh, int nFormat, int nOrigin, int nBuffers, int nAux); // 0x0087EAF4

void (__stdcall* gpfnGrChromakeyValue)(int a1); // 0x0087EB34

void* gpfnGrClipWindow; // 0x0087EB10

void (__stdcall* gpfnGrColorMask)(int a1, int a2); // 0x0087EB30

void* gpfnGrDepthBufferFunction; // 0x0087EB28

void* gpfnGrDepthBufferMode; // 0x0087EB20

void (__stdcall* gpfnGrDepthMask)(int a1); // 0x0087E97C

void (__stdcall* gpfnGrLoadGammaTable)(int nEntries, unsigned int* pRed, unsigned int* pGreen, unsigned int* pBlue); // 0x0087EAE0

void* gpfnGrGetString; // 0x0087EAC8

void* gpfnGrGetProcAddress; // 0x0087EB08

void* gpfnGrEnable; // 0x0087EAC0

void* gpfnGrDisable; // 0x0087EAF8

void (__stdcall* gpfnGrCoordinateSpace)(int a1); // 0x0087EB38

void* gpfnGrTexTextureMemRequired; // 0x0087EB00

void* gpfnGrTexMinAddress; // 0x0087EB24

void* gpfnGrTexMaxAddress; // 0x0087EB44

void (__stdcall* gpfnGrTexDownloadTable)(int nType, void* pData); // 0x0087EB40

void* gpfnGrTexMipMapMode; // 0x0087EAD4

int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC

int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8

// 0x00508970
int __cdecl sub_00508970_GlideLoadLibrary()
{
    ghGlideLibrary = LoadLibraryA("glide3x.dll");
    if (!ghGlideLibrary)
    {
        return 0;
    }

    GLIDE_GETPROC(gpfnGuGammaCorrectionRGB, "_guGammaCorrectionRGB@12", 0x9E);
    GLIDE_GETPROC(gpfnGrDrawPoint, "_grDrawPoint@4", 0xA1);
    GLIDE_GETPROC(gpfnGrDrawLine, "_grDrawLine@8", 0xA2);
    GLIDE_GETPROC(gpfnGrDrawTriangle, "_grDrawTriangle@12", 0xA3);
    GLIDE_GETPROC(gpfnGrVertexLayout, "_grVertexLayout@12", 0xA4);
    GLIDE_GETPROC(gpfnGrDrawVertexArray, "_grDrawVertexArray@12", 0xA5);
    GLIDE_GETPROC(gpfnGrDrawVertexArrayContiguous, "_grDrawVertexArrayContiguous@16", 0xA6);
    GLIDE_GETPROC(gpfnGrBufferClear, "_grBufferClear@12", 0xA8);
    GLIDE_GETPROC(gpfnGrBufferSwap, "_grBufferSwap@4", 0xA9);
    GLIDE_GETPROC(gpfGlideFinish_0087EB14, "_grFinish@0", 0xAA);
    GLIDE_GETPROC(gpfnGrSstWinOpen, "_grSstWinOpen@28", 0xAB);
    GLIDE_GETPROC(gpfGlideSstWinClose_0087EFA4, "_grSstWinClose@4", 0xAC);
    GLIDE_GETPROC(gpfnGrSstSelect, "_grSstSelect@4", 0xAD);
    GLIDE_GETPROC(gpfnGrAlphaBlendFunction, "_grAlphaBlendFunction@16", 0xAE);
    GLIDE_GETPROC(gpfnGrAlphaCombine, "_grAlphaCombine@20", 0xAF);
    GLIDE_GETPROC(gpfnGrChromakeyMode, "_grChromakeyMode@4", 0xB0);
    GLIDE_GETPROC(gpfnGrChromakeyValue, "_grChromakeyValue@4", 0xB1);
    GLIDE_GETPROC(gpfnGrClipWindow, "_grClipWindow@16", 0xB2);
    GLIDE_GETPROC(gpfnGrColorCombine, "_grColorCombine@20", 0xB3);
    GLIDE_GETPROC(gpfnGrColorMask, "_grColorMask@8", 0xB4);
    GLIDE_GETPROC(gpfnGrConstantColorValue, "_grConstantColorValue@4", 0xB5);
    GLIDE_GETPROC(gpfnGrDepthBufferFunction, "_grDepthBufferFunction@4", 0xB6);
    GLIDE_GETPROC(gpfnGrDepthBufferMode, "_grDepthBufferMode@4", 0xB7);
    GLIDE_GETPROC(gpfnGrDepthMask, "_grDepthMask@4", 0xB8);
    GLIDE_GETPROC(gpfnGrDitherMode, "_grDitherMode@4", 0xB9);
    GLIDE_GETPROC(gpfnGrLoadGammaTable, "_grLoadGammaTable@16", 0xBA);
    GLIDE_GETPROC(gpfnGrGet, "_grGet@12", 0xBB);
    GLIDE_GETPROC(gpfnGrGetString, "_grGetString@4", 0xBC);
    GLIDE_GETPROC(gpfnGrGetProcAddress, "_grGetProcAddress@4", 0xBD);
    GLIDE_GETPROC(gpfnGrEnable, "_grEnable@4", 0xBE);
    GLIDE_GETPROC(gpfnGrDisable, "_grDisable@4", 0xBF);
    GLIDE_GETPROC(gpfnGrCoordinateSpace, "_grCoordinateSpace@4", 0xC0);
    GLIDE_GETPROC(gpfnGrTexTextureMemRequired, "_grTexTextureMemRequired@8", 0xC1);
    GLIDE_GETPROC(gpfnGrTexMinAddress, "_grTexMinAddress@4", 0xC2);
    GLIDE_GETPROC(gpfnGrTexMaxAddress, "_grTexMaxAddress@4", 0xC3);
// build: symbol ?gpfnGrTexSource@* 0x0087EB98
    GLIDE_GETPROC(gpfnGrTexSource, "_grTexSource@16", 0xC4);
    GLIDE_GETPROC(gpfnGrTexCombine, "_grTexCombine@28", 0xC5);
    GLIDE_GETPROC(gpfnGrTexFilterMode, "_grTexFilterMode@12", 0xC6);
// build: symbol ?gpfnGrTexDownloadMipMap@* 0x0087EAB8
    GLIDE_GETPROC(gpfnGrTexDownloadMipMap, "_grTexDownloadMipMap@16", 0xC7);
    GLIDE_GETPROC(gpfnGrTexDownloadTable, "_grTexDownloadTable@8", 0xC8);
    GLIDE_GETPROC(gpfnGrTexMipMapMode, "_grTexMipMapMode@12", 0xC9);
    GLIDE_GETPROC(gpfnGrLfbLock, "_grLfbLock@24", 0xCA);
    GLIDE_GETPROC(gpfnGrLfbUnlock, "_grLfbUnlock@8", 0xCB);
    GLIDE_GETPROC(gpfnGrGlideInit, "_grGlideInit@0", 0xCC);
    GLIDE_GETPROC(gpfnGrGlideShutdown, "_grGlideShutdown@0", 0xCD);

    return 1;
}

int gnGlideNumBoards; // 0x0087EFC4

// 0x00508F60
int __cdecl sub_00508F60_GlideCheckBoards()
{
    if (!sub_00508970_GlideLoadLibrary())
    {
        return 0;
    }

    gpfnGrGet(0xF, 4, &gnGlideNumBoards);
    return gnGlideNumBoards > 0;
}


#include "gen/data/Source/D2Win/Unknown_00508970.inc"
