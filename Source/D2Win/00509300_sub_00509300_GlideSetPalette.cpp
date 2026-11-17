struct D2CriticalSectionStrc;
struct D2TileLibraryEntryStrc;
struct D2GfxLightExStrc;

struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct T00508FE0
{
    float x;
    float y;
    float unk0x08;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GrLfbInfoStrc
{
    int size;
    void* f_4;
    unsigned int strideInBytes;
    int f_C;
    int origin;
};

struct D2BinkStrc
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Frames;
    unsigned int f_C;
};

struct D2DDSurfaceDescStrc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    int lPitch;
    unsigned int dwBackBufferCount;
    unsigned int dwRefreshRate;
    unsigned int dwAlphaBitDepth;
    unsigned int dwReserved;
    void* lpSurface;
    unsigned int unk0x28[17];
};

struct D2DDrawSurfaceStrc;

struct D2DDrawSurfaceVtblStrc
{
    void* unk0x00[25];
    long (__stdcall* Lock)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDSurfaceDescStrc* pSurfaceDesc, unsigned long dwFlags, void* hEvent);
    void* unk0x68[6];
    long (__stdcall* Unlock)(D2DDrawSurfaceStrc* pThis, void* pRect);
};

struct D2DDrawSurfaceStrc
{
    D2DDrawSurfaceVtblStrc* lpVtbl;
};

struct D2DDrawObjectStrc;

struct D2DDrawObjectVtblStrc
{
    void* QueryInterface;
    void* AddRef;
    unsigned long (__stdcall* Release)(D2DDrawObjectStrc* pThis);
};

struct D2DDrawObjectStrc
{
    D2DDrawObjectVtblStrc* lpVtbl;
};

struct D2TileDrawFunctionsStrc
{
    void* unk0x00[3];
    int (__fastcall* pfDrawFloorTile)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightExStrc* pLight);
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0
extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h);                          // 0x006CC09C
extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color);      // 0x006CC0AC
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color);        // 0x006CC0B0
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);                              // 0x006CC0B4
extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y);                 // 0x006CC0B8
extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho);                                      // 0x006CC0D4
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc);                                         // 0x006CC0D8
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink);                            // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink);                               // 0x006CC5C4
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                                // 0x0040B380
unsigned int __fastcall sub_005093F0_GlidePaletteColor(int nPaletteIndex);                                   // 0x005093F0
void __fastcall sub_005094B0_GlideSetState(int nState);                                                      // 0x005094B0
void __fastcall sub_00509500_GlideSetCombine(int nMode);                                                     // 0x00509500
void __cdecl sub_0050BE20_GlideDebugRefresh();                                                               // 0x0050BE20
void __fastcall sub_0050DBC0_GlideSetAmbientColor(int nRed, int nGreen, int nBlue);                         // 0x0050DBC0
void __cdecl sub_00511A80_DDrawReleaseSurfaces();                                                           // 0x00511A80
int __fastcall sub_005115E0_DDrawRestoreSurface(void* hWnd, int nResolutionMode);                           // 0x005115E0
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3);                                   // 0x005FDEA0

extern "C" const char gszCourier_006DD52C[];                                                                // 0x006DD52C
extern "C" const char gszDisplay_006DE1E8[];                                                                // 0x006DE1E8
extern "C" const char gszDdDebugFontSourceFile_006DE1D0[];                                                  // 0x006DE1D0
extern unsigned long gdwDDrawDebugFontTextColor_0072F7F0;                                                    // 0x0072F7F0
extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern int gbSurfaceActive_007C9140;                                                                        // 0x007C9140
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C;                                               // 0x007C914C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern int (__stdcall* gpfGlideLfbLock_0087EADC)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC
extern int (__stdcall* gpfGlideLfbUnlock_0087EAD8)(int nType, int nBuffer);                                  // 0x0087EAD8
void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride);        // 0x0087EAC4
extern void (__stdcall* gpfGlideTexDownloadTable_0087EB40)(int nType, void* pData);                         // 0x0087EB40
extern void (__stdcall* gpfGlideBufferClear_0087EB88)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
void (__stdcall* gpfGlideMask_0087EB8C)(int bEnable);                                                       // 0x0087EB8C
unsigned int gaGlidePalette_0087EBA0[256];                                                                  // 0x0087EBA0
extern void (__stdcall* gpfGlideConstantColor_0087EFA0)(unsigned int dwColor);                              // 0x0087EFA0
extern int gbGlidePaletteTable_0087EFC8;                                                                    // 0x0087EFC8
extern int gnGlideState_0087EFD8;                                                                           // 0x0087EFD8
extern int gnGlideState_0087EFDC;                                                                           // 0x0087EFDC
extern int gnGlideState_0087EFE0;                                                                           // 0x0087EFE0
extern int gbGlideDrawing_0087EFE4;                                                                         // 0x0087EFE4
extern unsigned int gaGlideDebugLight_0087F0D0[0x400];                                                      // 0x0087F0D0
extern int gnGlideDebugX_008800D0;                                                                          // 0x008800D0
extern int gnGlideDebugY_008800D4;                                                                          // 0x008800D4
extern void** gppGlideDebugBuffer_00880454;                                                                 // 0x00880454
extern unsigned int gnGlideBinkY_00880C04;                                                                  // 0x00880C04
extern unsigned int gnGlideBinkX_00880C08;                                                                  // 0x00880C08
extern D2BinkStrc* gpGlideBink_00880C0C;                                                                    // 0x00880C0C
extern unsigned int gnGlideBinkFlags_00880C14;                                                              // 0x00880C14
extern int gbGlideBinkDone_00880C18;                                                                        // 0x00880C18
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881278;                                                         // 0x00881278
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

// 0x00509300
void __fastcall sub_00509300_GlideSetPalette(const T004F51E0* pPalette)
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

// 0x0050BF50
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    T00508FE0 vertices[4];
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
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, vertices, sizeof(T00508FE0));
    gpfGlideMask_0087EB8C(1);
}

// 0x0050C0F0
void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    T00508FE0 vertices[4];
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
    gpfGlideDrawVertexArrayContiguous_0087EAC4(5, 4, vertices, sizeof(T00508FE0));
    gpfGlideMask_0087EB8C(1);
}
