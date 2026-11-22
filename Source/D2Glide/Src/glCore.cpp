#include "D2Glide.h"
#include "D2GameTypes.h"

struct D2GlideHwQueryStrc;

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

int gdwGlobal_0087EFE8; // 0x0087EFE8

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

int __cdecl GLIDE_Close(); // 0x00509E10

D2GfxSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148

void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88

void (__stdcall* gpfGlideBufferSwap_0087EB90)(int nSwapInterval); // 0x0087EB90

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C

int __fastcall GLIDE_ChangeRes(void* hWnd, int nResolution); // 0x00509F70

void __fastcall GLIDE_SetGamma(int nGamma); // 0x005090B0

void __cdecl GLIDE_SmackFree(); // 0x0050DF70

void __cdecl GLIDE_FreeBlockBuffers(); // 0x0050F8C0

void __cdecl GLIDE_FreePerspectiveTable(); // 0x0050DCA0

void __cdecl GLIDE_FreeBlendTable(); // 0x0050DB40

int gnScreenWidth_007C9138;                                                                                 // 0x007C9138

extern void* ghDDrawWindow_007C9140; // 0x007C9140

int gbRenderPaused_007C9144;                                                                                // 0x007C9144

extern void* ghGlideLibrary_0087EFA8; // 0x0087EFA8

int gnGlideGammaTableSize_0087EFD4;                                                                         // 0x0087EFD4

extern int gnGlideTmuState_0072F254; // 0x0072F254

void (__stdcall* gpfGlideFn7_0087EAD0)(int a1, int a2, int a3, int a4, int a5, int a6, int a7); // 0x0087EAD0

unsigned int gaGlidePalette_0087EBA0[256];                                                                  // 0x0087EBA0

int gnGlideTmuCount_0087EFB4; // 0x0087EFB4

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

void (__stdcall* gpfGlideFn3_0087EAFC)(int a1, int a2, int a3); // 0x0087EAFC

extern void (__stdcall* gpfGlideFn_0087EB34)(int a1); // 0x0087EB34

void (__stdcall* gpfGlideFn_0087EAB0)(); // 0x0087EAB0

void (__stdcall* gpfGlideFn_0087EB04)(); // 0x0087EB04

void (__stdcall* gpfGlideFn_0087EB3C)(int a1); // 0x0087EB3C

void __cdecl sub_0050B9E0_GlideCreateDebugFont();

int __cdecl sub_00509670_GlideInitTextures();

int gdwGlobal_0087EFAC; // 0x0087EFAC

int gdwGlobal_0087EFB0; // 0x0087EFB0

int gdwGlobal_0087EFC0; // 0x0087EFC0

int gdwGlobal_0087EFBC; // 0x0087EFBC

int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams); // 0x0087EB1C

void (__stdcall* gpfGlideFn_0087EB9C)(int a1, int a2, int a3); // 0x0087EB9C

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

int gbGlideInit_0087EFCC; // 0x0087EFCC

void __cdecl GLIDE_CloseAtExit(); // 0x00509FD0

void __cdecl sub_0050C760_GlideInitVertices(); // 0x0050C760

void __cdecl sub_0050D540_GlideInitD(); // 0x0050D540

void __cdecl GLIDE_AllocBlendTable(); // 0x0050DB20

void __cdecl GLIDE_BuildBlendTable(); // 0x0050DB70

void __cdecl GLIDE_AllocPerspectiveTable(); // 0x0050DC80

void __cdecl GLIDE_FillPerspectiveTable(); // 0x0050DCD0

void __cdecl GLIDE_SmackInit(); // 0x0050DF10

void __cdecl GLIDE_InitBlockBuffers(); // 0x0050F870

char gData_007C90C8[12]; // 0x007C90C8

int gdwGlobal_00881790; // 0x00881790

struct D2TileLibraryEntryStrc;

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

void __fastcall GLIDE_SetColorCombineMode(int nState);                                                      // 0x005094B0

void __fastcall GLIDE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500

void __fastcall GLIDE_SetTextureFilterMode(int nMode);                                                       // 0x005095D0

int __fastcall GLIDE_CreateSurface(void* hWnd, int nResolution); // 0x00509E90

int __cdecl sub_0050BF40_GlideGetBlendedShadows();                                                                    // 0x0050BF40

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x0050C270

int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels); // 0x0050C890

int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00

int __cdecl GLIDE_IsPerspective();                                                               // 0x0050DD30

void __fastcall sub_0050FDF0_GlidePlaySmacker(const char* szFile, int nResolutionMode, void* pfFrame);      // 0x0050FDF0

void __fastcall sub_005103B0_DDrawLogError(const char* szWhere, int hResult); // 0x005103B0

void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor);                     // 0x00512D90

void __fastcall sub_005137E0_DDrawPlaySmacker(const char* szFile, int nResolutionMode, void* pfFrame);      // 0x005137E0

void __fastcall sub_006BE190_BuildGammaTable(int gamma,void* table,double scale,int entrySize,int entries,int mask); // 0x006BE190

extern const double gdGlideGammaScale_006CD038;                                                             // 0x006CD038

extern tagPALETTEENTRY gaDDrawPalette_007C8CC8[256];                                                     // 0x007C8CC8

extern void (__stdcall* gpfGlideGammaCorrectionRGB_0087EABC)(float fRed, float fGreen, float fBlue);       // 0x0087EABC

extern void (__stdcall* gpfGlideLoadGammaTable_0087EAE0)(int nEntries, unsigned int* pRed, unsigned int* pGreen, unsigned int* pBlue); // 0x0087EAE0

extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0

int gbGlidePlayingVideo_0087EFD0;                                                                           // 0x0087EFD0

int gbDDrawPlayingVideo_0088126C;                                                                           // 0x0088126C

D2DDrawSurfaceStrc* gpDDrawBackSurface_0088127C;                                                            // 0x0088127C

struct D2GfxLightExStrc;

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090

extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4

extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink);                            // 0x006CC5BC

extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0

extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink);                               // 0x006CC5C4

unsigned int __fastcall GLIDE_GetPaletteColor(int nPaletteIndex);                                   // 0x005093F0

void __cdecl sub_0050BE20_GlideDebugRefresh();                                                               // 0x0050BE20

void __fastcall sub_0050DBC0_GlideSetAmbientColor(int nRed, int nGreen, int nBlue);                         // 0x0050DBC0

void __cdecl DDRAW_ReleaseSurfaces();                                                           // 0x00511A80

int __fastcall DDRAW_CreateSurface(void* hWnd, int nResolutionMode);                           // 0x005115E0

void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710

extern "C" const char gszDisplay_006DE1E8[];                                                                // 0x006DE1E8

extern "C" const char gszDdDebugFontSourceFile_006DE1D0[];                                                  // 0x006DE1D0

extern unsigned long gdwDDrawDebugFontTextColor_0072F7F0;                                                    // 0x0072F7F0

extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154

void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride);        // 0x0087EAC4

extern void (__stdcall* gpfGlideTexDownloadTable_0087EB40)(int nType, void* pData);                         // 0x0087EB40

void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable);                                                       // 0x0087EB8C

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

int __fastcall GLIDE_DownloadDebugFont(int nStartAddress, int nAlignment); // 0x0050B860

int __fastcall GLIDE_SetSmackTexAddresses(int nBase, int nAlign); // 0x0050DFE0

D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4]; // 0x0087F048

int __fastcall GLIDE_TexCacheInit(D2GlideTexCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050E890

int __fastcall sub_0050ED90_TileCacheInit(D2GlideTileCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050ED90

int __fastcall GLIDE_FloorCacheInit(D2GlideFloorCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050F320

void __cdecl GLIDE_InitSprites(); // 0x0050B7B0

void __stdcall GLIDE_ReleaseTileCache(); // 0x0050FCB0

void __stdcall TileSetHardwareFreeCallback(void* pfnCallback); // 0x00604A30

extern unsigned int (__stdcall* gpfnGrTexMinAddress_0087EB24)(int nTmu); // 0x0087EB24

extern unsigned int (__stdcall* gpfnGrTexMaxAddress_0087EB44)(int nTmu); // 0x0087EB44

extern unsigned int gdwTmuMinAddress_0087EAA4[]; // 0x0087EAA4

extern unsigned int gdwTmuMaxAddress_0087EAE4[]; // 0x0087EAE4

extern int gnTmuCount_0087EFB4; // 0x0087EFB4

extern unsigned int gnTexAlign_0087EFBC; // 0x0087EFBC

extern int gbFloorTiles_0087EFE8; // 0x0087EFE8

extern D2GlideTileCacheStrc gTileCache_0087EB48; // 0x0087EB48

extern D2GlideFloorCacheStrc gFloorCache_0087EB68; // 0x0087EB68

extern unsigned int gnFloorCacheSize_007C90C8; // 0x007C90C8

extern unsigned int gnTileCacheSize_007C90D4; // 0x007C90D4

extern unsigned int gnTexCacheSize_007C90E0; // 0x007C90E0

extern unsigned int gnTexCacheSize_007C90E4; // 0x007C90E4

extern unsigned int gnTexCacheSize_007C90E8; // 0x007C90E8

extern const char gszInsufficientTextureMemory_006DD480[]; // 0x006DD480

void __fastcall sub_0050F7C0(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050F7C0

void __fastcall sub_0050F210(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050F210

void __cdecl GLIDE_SmackFlush(); // 0x0050E030

void __fastcall sub_0050ECB0(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050ECB0

void __cdecl GLIDE_FreeSpriteBuffers(); // 0x0050A0C0

void __cdecl GLIDE_FreeDebugFont(); // 0x0050BB70

typedef void (__stdcall* D2GlideFinishFn)();

typedef int (__stdcall* D2GlideIdleFn)(int nHandle);

extern D2GlideTexCacheStrc gTexCacheA_0087EB68; // 0x0087EB68

extern D2GlideTexCacheStrc gTexCacheB_0087EB48; // 0x0087EB48

extern int gnGlideState_007C9140; // 0x007C9140

// 0x004F5140
int __cdecl sub_004F5140()
{
    return gdwGlobal_007C8CB0;
}

// 0x004F5150
int __cdecl D2GFX_CheckWindowed()
{
    return gdwGlobal_007C8CB4;
}

// 0x004F5170
int __cdecl D2GFX_CheckUnitPerspective()
{
    return gdwGlobal_0072DA4C;
}

// 0x004F5180
int __cdecl D2GFX_IsFixedAspectRatio()
{
    return gdwGlobal_0072DA7C;
}

// 0x004F51F0
int __cdecl D2GFX_CheckBlendedShadows()
{
    return gdwGlobal_0072DA5C;
}

// 0x004F5210
int __cdecl D2GFX_CheckLowQuality()
{
    return gdwGlobal_0072DA50;
}

// 0x004F59A0
int __cdecl WINDOW_GetWindow()
{
    return gdwGlobal_007C8CBC;
}

// 0x004F65E0
int __cdecl SCALE_GetFactor()
{
    return gdwGlobal_0072DB44;
}

// 0x004F9200
int __cdecl CONTROL_GetFocusedEditBox()
{
    return gdwGlobal_007D55CC;
}

// 0x004F97D0
int __cdecl D2Win_IsCtrlKeyDown()
{
    return gdwGlobal_007D55E4;
}

// 0x004FA460
int __cdecl D2Win_IsMouseButtonPressed()
{
    return gdwGlobal_007D55E0;
}

// 0x004FA4B0
int __cdecl CONTROL_GetActiveControlList()
{
    return gdwGlobal_007D55D4;
}

// 0x004FD0F0
void __fastcall IMAGE_Destroy(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x004FD100
void __fastcall IMAGE2_Destroy(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x004FD820
void __fastcall TIMER_Destroy(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00500300
void __fastcall ANIMIMAGE_Destroy(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00505150
int __cdecl D2COMP_GetFirstCompositeUnit()
{
    return gdwGlobal_0087E838;
}

// 0x00507DB0
void __fastcall PROGRESSBAR_Destroy(void* pArg)
{
    sub_004F9310(pArg);
}

// 0x00507EE0
void __fastcall SCROLLBAR_Destroy(void* pArg)
{
    sub_004F9310(pArg);
}

void __fastcall GLIDE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush);                     // 0x0050ECB0
void __fastcall sub_0050F210_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush);                    // 0x0050F210
void __fastcall GLIDE_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush);                  // 0x0050F7C0
extern D2GlideTileCacheStrc gGlideTileCache_0087EB48;                                                       // 0x0087EB48
extern D2GlideFloorCacheStrc gGlideFloorCache_0087EB68;                                                     // 0x0087EB68

// 0x00508F90
void __cdecl GLIDE_ClearCaches()
{
    GLIDE_FloorCacheDestroy(&gGlideFloorCache_0087EB68, 0);
    sub_0050F210_TileCacheDestroy(&gGlideTileCache_0087EB48, 0);
    GLIDE_TexCacheDestroy(&gaGlideTexCaches_0087F048[1], 0);
    GLIDE_TexCacheDestroy(&gaGlideTexCaches_0087F048[2], 0);
    GLIDE_TexCacheDestroy(&gaGlideTexCaches_0087F048[3], 0);
}

// 0x00508FD0
int __cdecl GLIDE_CheckCutScene()
{
    return gdwGlobal_0087EFD0;
}

int gdwGlobal_007B57E4; // 0x007B57E4

// 0x005090A0
void __fastcall GLIDE_SetGlobalScale(int nValue)
{
    gdwGlobal_007B57E4 = nValue;
}

// 0x005090B0
void __fastcall GLIDE_SetGamma(int nGamma)
{
    if (gnGlideGammaTableSize_0087EFD4 > 0)
    {
        int nEntries;
        int nBits;
        if (!gpfGlideGet_0087EB1C(5, 4, &nEntries))
        {
            return;
        }

        if (!gpfGlideGet_0087EB1C(0x2A, 4, &nBits))
        {
            return;
        }

        unsigned int* pTable = (unsigned int*)SMemAlloc(nEntries * 4, ".\\Src\\glCore.cpp", 0x42F, 0);
        sub_006BE190_BuildGammaTable(nGamma, pTable, gnGlideGammaTableSize_0087EFD4, 4, nEntries, (1 << nBits) - 1);
        gpfGlideLoadGammaTable_0087EAE0(nEntries, pTable, pTable, pTable);
        SMemFree(pTable, ".\\Src\\glCore.cpp", 0x43A, 0);
    }
    else
    {
        const float fGamma = nGamma / gdGlideGammaScale_006CD038;
        gpfGlideGammaCorrectionRGB_0087EABC(fGamma, fGamma, fGamma);
    }
}

// 0x00509190
int __cdecl GLIDE_GammaCanBeControlled()
{
    return 1;
}

D2PaletteTableStrc gtGfxPaletteView_0087E980; // 0x0087E980

int gbGlideDrawing_0087EFE4; // 0x0087EFE4

// 0x005091A0
int __cdecl GLIDE_EndDraw()
{
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x47A);
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
    gbGlideDrawing_0087EFE4 = 0;
    return 1;
}

// 0x005091E0
int __cdecl GLIDE_Blit()
{
    if (gpGfxSettings_007C9148->bVSync)
    {
        gpfGlideBufferSwap_0087EB90(1);
        return 1;
    }

    gpfGlideBufferSwap_0087EB90(0);
    return 1;
}

// 0x00509210
int __fastcall GLIDE_GetBackBuffer(unsigned char* pBuffer)
{
    D2GrLfbInfoStrc tInfo;
    tInfo.size = sizeof(tInfo);
    if (!gpfGlideLfbLock_0087EADC(0, 1, 0xFF, 0, 0, &tInfo))
    {
        return 0;
    }

    unsigned char* pDstRow = pBuffer;
    unsigned short* pSrcRow = (unsigned short*)tInfo.lfbPtr;
    for (int y = 0; y < gnScreenHeight_007C913C; ++y)
    {
        unsigned short* pSrc = pSrcRow;
        unsigned char* pDst = pDstRow;
        for (int x = 0; x < gnScreenWidth_007C9138; ++x)
        {
            const unsigned short nPixel = *pSrc;
            const unsigned char nRed = nPixel >> 11;
            const unsigned char nGreen = nPixel >> 5;
            const unsigned char nBlue = (unsigned char)nPixel;
            *pDst = nRed << 3;
            ++pDst;
            *pDst = nGreen << 2;
            ++pDst;
            *pDst = nBlue << 3;
            ++pSrc;
            ++pDst;
        }

        pDstRow += 3 * gnScreenWidth_007C9138;
        pSrcRow = (unsigned short*)((unsigned char*)pSrcRow + tInfo.strideInBytes);
    }

    gpfGlideLfbUnlock_0087EAD8(0, 1);
    return 1;
}

// 0x005092F0
void __fastcall GLIDE_GetDimensions(int* pWidth, int* pHeight)
{
    *pWidth = gnScreenWidth_007C9138;
    *pHeight = gnScreenHeight_007C913C;
}

// 0x00509300
void __fastcall GLIDE_SetPalette(const tagPALETTEENTRY* pPalette)
{
    if (gbGlidePaletteTable_0087EFC8)
    {
        for (int i = 0; i < 256; ++i)
        {
            unsigned int dwColor = 0xFF;
            dwColor = (dwColor << 8) + pPalette[i].peRed;
            dwColor = (dwColor << 8) + pPalette[i].peGreen;
            dwColor = (dwColor << 8) + pPalette[i].peBlue;
            gaGlidePalette_0087EBA0[i] = dwColor;
        }
        gpfGlideTexDownloadTable_0087EB40(2, gaGlidePalette_0087EBA0);
    }
}

void (__stdcall* gpfGlideFn4_0087EACC)(int a1, int a2, int a3, int a4); // 0x0087EACC

void (__stdcall* gpfGlideFn5_0087EAF0)(int a1, int a2, int a3, int a4, int a5); // 0x0087EAF0

void (__stdcall* gpfGlideColorCombine_0087EB2C)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C

int gnGlideState_0087EFD8; // 0x0087EFD8

int gnGlideState_0087EFDC; // 0x0087EFDC

int gnGlideState_0087EFE0; // 0x0087EFE0

// 0x005093F0
unsigned int __fastcall GLIDE_GetPaletteColor(int nPaletteIndex)
{
    return gaGlidePalette_0087EBA0[nPaletteIndex] << 8;
}

// 0x00509400
void __fastcall GLIDE_SetPaletteTables(D2PaletteTableStrc* pSource)
{
    gtGfxPaletteView_0087E980 = *pSource;
    gpGfxPaletteView_007C9150 = &gtGfxPaletteView_0087E980;
}

// 0x00509420
int __cdecl GLIDE_ActivateWindow()
{
    return 0;
}

// 0x00509430
int __fastcall GLIDE_SetOption(int nOption, int nValue)
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

// 0x00509460
void __fastcall GLIDE_SetTextureCombineMode(int nTmu)
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
void __fastcall GLIDE_SetColorCombineMode(int nState)
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
void __fastcall GLIDE_SetAlphaBlendMode(int nMode)
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
void __fastcall GLIDE_SetTextureFilterMode(int nMode)
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

// 0x00509640
void* __cdecl GLIDE_GetCacheResults()
{
    return gData_007C90C8;
}

// 0x00509650
int __cdecl GLIDE_GetFloorTilesFlag()
{
    return gdwGlobal_0087EFE8;
}

// 0x00509660
void __fastcall GLIDE_SetFloorTilesFlag(int nValue)
{
    gdwGlobal_0087EFE8 = nValue;
}

// 0x00509670
int __cdecl GLIDE_InitTextureMemory()
{
	const unsigned int nMask = gnTexAlign_0087EFBC - 1;
	unsigned int nTotal = 0;
	unsigned int nAlign64K = 0x10000;
	unsigned int nAlign16K = 0x4000;
	unsigned int nAlign4K = 0x1000;
	if (nMask & 0x10000)
	{
		nAlign64K = (nMask | 0x10000) + 1;
	}
	if (nMask & 0x4000)
	{
		nAlign16K = (nMask | 0x4000) + 1;
	}
	if (nMask & 0x1000)
	{
		nAlign4K = (nMask | 0x1000) + 1;
	}

	for (int i = 0; i < gnTmuCount_0087EFB4; ++i)
	{
		gdwTmuMinAddress_0087EAA4[i] = gpfnGrTexMinAddress_0087EB24(i);
		gdwTmuMaxAddress_0087EAE4[i] = gpfnGrTexMaxAddress_0087EB44(i);
		nTotal += gdwTmuMaxAddress_0087EAE4[i] - gdwTmuMinAddress_0087EAA4[i];
	}

	if ((float)nTotal < 3.5 * 1024 * 1024)
	{
		sub_00410610_WriteLogLine(gszInsufficientTextureMemory_006DD480);
		return 0;
	}

	unsigned int nAddress = gdwTmuMinAddress_0087EAA4[0];
	int nTmu = 0;
	if (gbFloorTiles_0087EFE8)
	{
		const unsigned int nMask2 = gnTexAlign_0087EFBC - 1;
		unsigned int nAlign1K = 0x400;
		if (nMask2 & 0x400)
		{
			nAlign1K = (nMask2 | 0x400) + 1;
		}
		unsigned int nAlign32K = 0x8000;
		if (nMask2 & 0x8000)
		{
			nAlign32K = (nMask2 | 0x8000) + 1;
		}

		nAddress += GLIDE_DownloadDebugFont(nAddress, gnTexAlign_0087EFBC);
		unsigned int nFree = gdwTmuMaxAddress_0087EAE4[0] - nAddress;
		unsigned int nEnd;
		if (gnTmuCount_0087EFB4 > 1)
		{
			unsigned int nFloorSize = 3 * nFree / 4;
			if (nFloorSize < 0x1CCCCC)
			{
				nFloorSize = 0x1CCCCC;
			}
			gnFloorCacheSize_007C90C8 = nFloorSize;
			nEnd = GLIDE_FloorCacheInit(&gFloorCache_0087EB68, nAddress, nFloorSize + nAddress, nAlign32K);
			gnTileCacheSize_007C90D4 = gdwTmuMaxAddress_0087EAE4[0] - nEnd;
			nEnd = sub_0050ED90_TileCacheInit(&gTileCache_0087EB48, nEnd, gdwTmuMaxAddress_0087EAE4[0], nAlign1K);
		}
		else
		{
			unsigned int nFloorSize = nFree / 2;
			if (nFree / 2 >= 0x300000)
			{
				nFloorSize = 0x300000;
			}
			unsigned int nTileSize = nFree / 4;
			if (nFree / 4 >= 0x100000)
			{
				nTileSize = 0x100000;
			}
			gnFloorCacheSize_007C90C8 = nFloorSize;
			nEnd = GLIDE_FloorCacheInit(&gFloorCache_0087EB68, nAddress, nFloorSize + nAddress, nAlign32K);
			gnTileCacheSize_007C90D4 = nTileSize;
			nEnd = sub_0050ED90_TileCacheInit(&gTileCache_0087EB48, nEnd, nTileSize + nEnd, nAlign1K);
		}

		if (gnTmuCount_0087EFB4 > 1)
		{
			nEnd = gdwTmuMinAddress_0087EAA4[1];
			nTmu = 1;
		}

		const unsigned int nStart = nEnd;
		const unsigned int nSize = gdwTmuMaxAddress_0087EAE4[nTmu] - nStart;
		nEnd = GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[1], nStart, nStart + 25 * nSize / 100, nAlign64K);
		gnTexCacheSize_007C90E0 = gaGlideTexCaches_0087F048[1].nCount * nAlign64K;
		nEnd = GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[2], nEnd, nStart + 65 * nSize / 100, nAlign16K);
		gnTexCacheSize_007C90E4 = gaGlideTexCaches_0087F048[2].nCount * nAlign16K;
		GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[3], nEnd, gdwTmuMaxAddress_0087EAE4[nTmu], nAlign4K);
		gnTexCacheSize_007C90E8 = gaGlideTexCaches_0087F048[3].nCount * nAlign4K;
	}
	else if (gnScreenWidth_007C9138 == 800 && gnScreenHeight_007C913C == 600)
	{
		nAddress += GLIDE_SetSmackTexAddresses(nAddress, gnTexAlign_0087EFBC);
		const unsigned int nFree = gdwTmuMaxAddress_0087EAE4[0] - nAddress;
		if (gnTmuCount_0087EFB4 > 1)
		{
			int nEnd = GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[2], nAddress, nAddress + 50 * nFree / 100, nAlign16K);
			gnTexCacheSize_007C90E4 = gaGlideTexCaches_0087F048[2].nCount * nAlign16K;
			GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[3], nEnd, gdwTmuMaxAddress_0087EAE4[0], nAlign4K);
			gnTexCacheSize_007C90E8 = gaGlideTexCaches_0087F048[3].nCount * nAlign4K;
			GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[1], gdwTmuMinAddress_0087EAA4[1], gdwTmuMaxAddress_0087EAE4[1], nAlign64K);
			gnTexCacheSize_007C90E0 = gaGlideTexCaches_0087F048[1].nCount * nAlign64K;
		}
		else
		{
			int nEnd = GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[1], nAddress, nAddress + 50 * nFree / 100, nAlign64K);
			gnTexCacheSize_007C90E0 = gaGlideTexCaches_0087F048[1].nCount * nAlign64K;
			nEnd = GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[2], nEnd, nAddress + 75 * nFree / 100, nAlign16K);
			gnTexCacheSize_007C90E4 = gaGlideTexCaches_0087F048[2].nCount * nAlign16K;
			GLIDE_TexCacheInit(&gaGlideTexCaches_0087F048[3], nEnd, gdwTmuMaxAddress_0087EAE4[0], nAlign4K);
			gnTexCacheSize_007C90E8 = gaGlideTexCaches_0087F048[3].nCount * nAlign4K;
		}
	}

	GLIDE_InitSprites();
	TileSetHardwareFreeCallback(GLIDE_ReleaseTileCache);
	return 1;
}

// 0x00509A70
void __cdecl GLIDE_ClearAndSwap()
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

int gbGlideInit_0087EFC8; // 0x0087EFC8

D2GlideFinishFn gpfnGlideFinish_0087EB14; // 0x0087EB14

D2GlideIdleFn gpfnGlideIdle_0087EFA4; // 0x0087EFA4

int gnGlideHandle_0087EB94; // 0x0087EB94

// 0x00509AA0
int __cdecl GLIDE_CloseSurface()
{
    if (gbGlideInit_0087EFC8)
    {
        gbGlideInit_0087EFC8 = 0;
        gpfnGlideFinish_0087EB14();
        if (gbFloorTiles_0087EFE8)
        {
            sub_0050F7C0(&gTexCacheA_0087EB68, 1);
            sub_0050F210(&gTexCacheB_0087EB48, 1);
        }
        else
        {
            GLIDE_SmackFlush();
        }
        sub_0050ECB0(&gaGlideTexCaches_0087F048[1], 1);
        sub_0050ECB0(&gaGlideTexCaches_0087F048[2], 1);
        sub_0050ECB0(&gaGlideTexCaches_0087F048[3], 1);
        GLIDE_FreeSpriteBuffers();
        for (int i = 0; ; ++i)
        {
            int nIdle = i < 100 ? gpfnGlideIdle_0087EFA4(gnGlideHandle_0087EB94) : 1;
            if (nIdle == 1)
            {
                break;
            }
        }
        GLIDE_FreeDebugFont();
        gnGlideState_007C9140 = 0;
    }
    return 1;
}

// 0x00509B60
void __fastcall GLIDE_OpenSmackCutscene(const char* szFile, int nResolutionMode, void* pfFrame)
{
    if (!gbRenderPaused_007C9144)
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

        gbGlidePlayingVideo_0087EFD0 = 1;
        sub_0050FDF0_GlidePlaySmacker(szFile, nResolutionMode, pfFrame);
        gbGlidePlayingVideo_0087EFD0 = 0;
    }
}

// 0x00509BC0
static int GLIDE_OpenDevice(int nResolution, void* hWnd)
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

// 0x00509E10
int __cdecl GLIDE_Close()
{
    if (gbGlideInit_0087EFCC)
    {
        GLIDE_SmackFree();
        sub_00509AA0_GlideSuspend();
        gpfGlideFn_0087EAB0();
        GLIDE_FreeBlockBuffers();
        GLIDE_FreePerspectiveTable();
        GLIDE_FreeBlendTable();
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

// 0x00509E90
int __fastcall GLIDE_CreateSurface(void* hWnd, int nResolution)
{
    if (gbGlidePaletteTable_0087EFC8)
    {
        return 1;
    }

    if (!GLIDE_OpenDevice(nResolution, hWnd))
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

// 0x00509EE0
void __fastcall GLIDE_PauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection_007C9134, 0x3A3);

    EnterCriticalSection(gpRenderCriticalSection_007C9134);
    if (nWindowState)
    {
        sub_00509AA0_GlideSuspend();
        gbRenderPaused_007C9144 = 1;
    }
    else
    {
        GLIDE_CreateSurface(hWnd, nResolutionMode);
        gbRenderPaused_007C9144 = 0;
    }
    LeaveCriticalSection(gpRenderCriticalSection_007C9134);
}

// 0x00509F70
int __fastcall GLIDE_ChangeRes(void* hWnd, int nResolution)
{
    sub_00509AA0_GlideSuspend();
    gpfGlideFn_0087EAB0();
    gpfGlideFn_0087EB04();
    gpfGlideFn_0087EB3C(0);
    if (!GLIDE_OpenDevice(nResolution, hWnd))
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

// 0x00509FD0
void __cdecl GLIDE_CloseAtExit()
{
    GLIDE_Close();
}

// 0x00509FE0
int __cdecl GLIDE_PlayCutscene()
{
    if (!gbRenderPaused_007C9144 && GLIDE_ChangeRes(ghDDrawWindow_007C9140, 0))
    {
        GLIDE_SetGamma(0x64);
        return 1;
    }

    return 0;
}

// 0x0050A010
int __fastcall GLIDE_Init(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pTileDrawFunctions)
{
    D2_ASSERT(!gbGlideInit_0087EFCC, 0x2A6);

    gpGfxSettings_007C9148 = pSettings;
    gpTileDrawFunctions_007C914C = pTileDrawFunctions;
    GLIDE_InitBlockBuffers();
    GLIDE_AllocPerspectiveTable();
    GLIDE_AllocBlendTable();
    gpfGlideFn_0087EB04();
    gbGlideInit_0087EFCC = 1;
    gpfGlideFn_0087EB3C(0);
    atexit(GLIDE_CloseAtExit);
    GLIDE_BuildBlendTable();
    GLIDE_FillPerspectiveTable();
    sub_0050C760_GlideInitVertices();
    sub_0050D540_GlideInitD();
    GLIDE_SmackInit();
    gpRenderCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\glCore.cpp", 0x2D5, 0);
    InitializeCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}

// 0x0050A110
void __fastcall GLIDE_ReleaseTexSlots(D2GlideTexSlotStrc* pSlots)
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



// 0x0050C3A0
void __fastcall GLIDE_UtilDiamond(tagRECT* pRect, int nPaletteIndex)
{
    const int nX = pRect->left;
    const int nRight = pRect->right;
    D2_ASSERT(nX <= nRight, 0xB9);

    const int nY = pRect->top;
    const int nBottom = pRect->bottom;
    D2_ASSERT(nY <= nBottom, 0xBA);

    const unsigned int nWidth = nRight - nX;
    const unsigned int nHeight = nBottom - nY;
    if (!nWidth || !nHeight)
    {
        return;
    }

    const int nCenterX = nX + (nWidth >> 1);
    const int nCenterY = nY + (nHeight >> 1);
    const int nX2 = nX + nWidth;
    const int nY2 = nY + nHeight;
    if (nX2 < 0 || nX > gnScreenWidth_007C9138 || nY2 < 0 || nY > gnScreenHeight_007C913C)
    {
        return;
    }

    sub_0050C270_GlideDrawLine(nCenterX, nY, nX2, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nCenterY, nCenterX, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nCenterX, nY2, nX, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX, nCenterY, nCenterX, nY, nPaletteIndex, 0xFF);
}

// 0x0050C490
void __fastcall GLIDE_UtilRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0xDF);
    D2_ASSERT(pRect->top <= pRect->bottom, 0xE0);

    const int nX1 = D2_MIN(D2_MAX(pRect->left, 0), gnScreenWidth_007C9138 - 1);
    const int nX2 = D2_MIN(D2_MAX(pRect->right, 0), gnScreenWidth_007C9138 - 1);
    if (nX1 == nX2)
    {
        return;
    }

    const int nY1 = D2_MIN(D2_MAX(pRect->top, 0), gnScreenHeight_007C913C - 1);
    const int nY2 = D2_MIN(D2_MAX(pRect->bottom, 0), gnScreenHeight_007C913C - 1);
    if (nY1 == nY2)
    {
        return;
    }

    D2_ASSERT(nY2 > nY1, 0xF0);

    sub_0050C270_GlideDrawLine(nX1, nY1, nX2, nY1, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY1, nX2, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY2, nX1, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX1, nY2, nX1, nY1, nPaletteIndex, 0xFF);
}

// 0x0050C630
void __fastcall GLIDE_UtilPoint(tagPOINT* pPoint, unsigned char nSize, int nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_0050BF50_GlideDrawBox(tRect.left, tRect.top, tRect.right, tRect.bottom, nPaletteIndex, 5);
    }
}


// 0x00510140
int __cdecl DDRAW_CheckCutScene()
{
    return gdwGlobal_0088126C;
}

// 0x00510320
void __stdcall DDRAW_SetAmbientColor(int nUnused1)
{
}

// 0x00510370
int __cdecl DDRAW_GetCacheResults()
{
    return 0;
}

// 0x00510380
int __cdecl DDRAW_ActivateWindow()
{
    return 0;
}

// 0x00511660
void __fastcall DDRAW_OpenSmackCutscene(const char* szFile, int nResolutionMode, void* pfFrame)
{
    if (!gbRenderPaused_007C9144)
    {
        gbDDrawPlayingVideo_0088126C = 1;
        D2DDBltFxStrc tBltFx = { sizeof(tBltFx) };
        tBltFx.dwFillColor = 0;
        D2_ASSERT(gpDDrawSurface_00881278, 0x387);

        const long hResult = gpDDrawSurface_00881278->lpVtbl->Blt(gpDDrawSurface_00881278, 0, 0, 0, 0x400, &tBltFx);
        if (hResult)
        {
            sub_005103B0_DDrawLogError("Cutscene clearing blit failed!", hResult);
            return;
        }

        sub_005137E0_DDrawPlaySmacker(szFile, nResolutionMode, pfFrame);
        gbDDrawPlayingVideo_0088126C = 0;
    }
}

// 0x00511970
int __fastcall DDRAW_GetBackBuffer(unsigned char* pBuffer)
{
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    if (!gpDDrawBackSurface_0088127C)
    {
        return 0;
    }

    long hResult = gpDDrawBackSurface_0088127C->lpVtbl->Lock(gpDDrawBackSurface_0088127C, 0, &tDesc, 0x11, 0);
    if (hResult)
    {
        sub_005103B0_DDrawLogError("Lock failed!", hResult);
        return 0;
    }

    unsigned char* pDstRow = pBuffer;
    unsigned char* pSrcRow = (unsigned char*)tDesc.lpSurface;
    for (int y = 0; y < gnScreenHeight_007C913C; ++y)
    {
        unsigned char* pSrc = pSrcRow;
        unsigned char* pDst = pDstRow;
        for (int x = 0; x < gnScreenWidth_007C9138; ++x)
        {
            const tagPALETTEENTRY* pEntry = &gaDDrawPalette_007C8CC8[*pSrc];
            *pDst = pEntry->peRed;
            ++pDst;
            *pDst = pEntry->peGreen;
            ++pDst;
            *pDst = pEntry->peBlue;
            ++pSrc;
            ++pDst;
        }

        pDstRow += 3 * gnScreenWidth_007C9138;
        pSrcRow += tDesc.lPitch;
    }

    hResult = gpDDrawBackSurface_0088127C->lpVtbl->Unlock(gpDDrawBackSurface_0088127C, 0);
    if (hResult)
    {
        sub_005103B0_DDrawLogError("Unlock failed!", hResult);
        return 0;
    }

    return 1;
}

// 0x005123A0
void __stdcall DDRAW_CelDrawHilight(int nUnused1, int nUnused2)
{
}

// 0x005126F0
void __stdcall DDRAW_DebugDraw(int nUnused1, int nUnused2)
{
}

// 0x00512E80
void __fastcall DDRAW_UtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_00512D90_DDrawUtilFilledRect(&tRect, nPaletteIndex);
    }
}

// 0x00513AE0
int __cdecl D2SOUND_IsExpansion()
{
    return gdwGlobal_00881790;
}

// 0x00513B50
int __cdecl D2SOUND_GetDirectSound()
{
    return gdwGlobal_00881768;
}

// 0x00513B60
int __cdecl D2SOUND_IsPositionalSoundEnabled()
{
    return gdwGlobal_0088176C;
}

// 0x00513B70
int __cdecl D2SOUND_IsEaxEnabled()
{
    return gdwGlobal_00881770;
}

// 0x00513B80
int __cdecl sub_00513B80()
{
    return 0;
}

// 0x00513B90
int __cdecl D2SOUND_GetEaxVersion()
{
    return gdwGlobal_00881774;
}

// 0x00513BA0
int __cdecl D2SOUND_IsEaxRoomOff()
{
    return gdwGlobal_00881778;
}

// 0x00513BB0
int __cdecl sub_00513BB0()
{
    return gdwGlobal_0072F830;
}

// 0x00514920
int __cdecl D2SOUND_GetStreamChannelValue()
{
    return gdwGlobal_00881798;
}

// 0x00514C90
int __cdecl D2SOUND_GetSoundMixerOption()
{
    return gdwGlobal_008817AC;
}

// 0x00514CC0
int __cdecl D2SOUND_GetMasterVolumeOption()
{
    return gdwGlobal_008817B0;
}

// 0x00514CF0
int __cdecl D2SOUND_GetMusicVolumeOption()
{
    return gdwGlobal_008817B4;
}

// 0x00514D20
int __cdecl D2SOUND_GetPositionalBiasOption()
{
    return gdwGlobal_008817B8;
}

// 0x00514D50
int __cdecl D2SOUND_GetNpcSpeechOption()
{
    return gdwGlobal_008817BC;
}

// 0x00514D80
int __cdecl D2SOUND_GetOptionsMusicOption()
{
    return gdwGlobal_008817C0;
}

// 0x00515060
int __cdecl D2SOUND_AreWaveSlotsInitialized()
{
    return gdwGlobal_008817FC;
}

// 0x00518C10
void* __cdecl BNCLIENT_GetInterfaceTable()
{
    return gData_0072FAA0;
}

// 0x0051A550
int __cdecl BNCLIENT_GetServerToken()
{
    return gdwGlobal_008818BC;
}

// 0x0051A570
int __cdecl BNCLIENT_GetLogonType()
{
    return gdwGlobal_008818C0;
}

// 0x0051CA10
int __cdecl sub_0051CA10()
{
    return 14;
}

// 0x0051CA70
int __cdecl BNCLIENT_IsSetEmailRequested()
{
    return gdwGlobal_00881C04;
}

// 0x0051EA70
int __cdecl BNCLIENT_GetDownloadPercent()
{
    return gdwGlobal_00881C50;
}

#include "gen/data/Source/D2Glide/Src/glCore.inc"
