struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2SurfaceDescStrc
{
    unsigned int dwSize;
    unsigned int unk0x04[8];
    void* lpSurface;
    unsigned int unk0x28[21];
};

struct D2DDSurfaceStrc;
struct D2D3DTextureStrc;

struct D2DDSurfaceVtbl
{
    void* pfnQueryInterface;
    void* pfnAddRef;
    unsigned long (__stdcall* Release)(D2DDSurfaceStrc* pThis);
    void* pfn0x0C[22];
    long (__stdcall* Lock)(D2DDSurfaceStrc* pThis, D2RectStrc* pRect, D2SurfaceDescStrc* pDesc, unsigned int dwFlags, void* hEvent);
    void* pfn0x68[6];
    long (__stdcall* Unlock)(D2DDSurfaceStrc* pThis, D2RectStrc* pRect);
};

struct D2DDSurfaceStrc
{
    D2DDSurfaceVtbl* lpVtbl;
};

struct D2D3DTextureVtbl
{
    void* pfnQueryInterface;
    void* pfnAddRef;
    unsigned long (__stdcall* Release)(D2D3DTextureStrc* pThis);
    void* pfnGetHandle;
    void* pfnPaletteChanged;
    long (__stdcall* Load)(D2D3DTextureStrc* pThis, D2D3DTextureStrc* pSource);
};

struct D2D3DTextureStrc
{
    D2D3DTextureVtbl* lpVtbl;
};

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);
extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName);
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleBitmap(void* hDC, int cx, int cy);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hDC, unsigned long dwColor);
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hDC, unsigned long dwColor);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hDC, int nMode);
extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hDC, const char* szText, int nCount, D2RectStrc* pRect, unsigned int nFormat);
extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hDC, int nX, int nY);
extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hDC, unsigned int nFirst, unsigned int nLast, int* pWidths);
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* hObject);
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned long gdwFontTextColor_0074C0CC; // 0x0074C0CC
unsigned long gdwFontBkColor_00971148;        // 0x00971148
extern unsigned int gdwRenderFlags_0096F3A8; // 0x0096F3A8
int gaFontCharWidths_00970FC8[96];      // 0x00970FC8
extern void* gapFontGlyphA_00971150[]; // 0x00971150
extern D2D3DTextureStrc* gapFontGlyphB_009712D0[]; // 0x009712D0

void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult); // 0x006B20E0
int __fastcall sub_006B3730_CreateWorkSurface(D2DDSurfaceStrc** ppSurface, D2D3DTextureStrc** ppTexture, int nWidth, int nHeight); // 0x006B3730
int __fastcall sub_006B58A0_CreateGlyphTexture(void** ppGlyphA, D2D3DTextureStrc** ppGlyphB, int nWidth, int nHeight); // 0x006B58A0
void __fastcall sub_006B38A0_UploadGlyph(void* pGlyphA, D2DDSurfaceStrc* pSurface, int nHeight); // 0x006B38A0

// 0x006B72A0
void __cdecl sub_006B72A0_CreateFontTextures()
{
    void* hDC = CreateCompatibleDC(0);
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, "Courier");
    void* hBitmap = CreateCompatibleBitmap(hDC, 8, 16);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwFontTextColor_0074C0CC);
    SetBkColor(hDC, gdwFontBkColor_00971148);
    SetBkMode(hDC, 2);

    D2RectStrc tRect;
    SetRect(&tRect, 0, 0, 8, 16);

    D2DDSurfaceStrc* pSurface = 0;
    D2D3DTextureStrc* pTexture = 0;
    sub_006B3730_CreateWorkSurface(&pSurface, &pTexture, 8, 16);

    for (int nChar = ' '; nChar <= 0x7F; ++nChar)
    {
        char szChar = (char)nChar;
        DrawTextA(hDC, &szChar, 1, &tRect, 0);

        D2SurfaceDescStrc tDesc = { sizeof(D2SurfaceDescStrc) };
        long hResult = pSurface->lpVtbl->Lock(pSurface, 0, &tDesc, 0x21, 0);
        if (hResult)
        {
            sub_006B20E0_ReportError("Failed to lock memory surface", hResult);
        }

        unsigned short* pPixel = (unsigned short*)tDesc.lpSurface;
        for (int nY = 0; nY < 16; ++nY)
        {
            for (int nX = 0; nX < 8; ++nX)
            {
                if (GetPixel(hDC, nX, nY) == gdwFontTextColor_0074C0CC)
                {
                    *pPixel++ = 0xFFFF;
                }
                else
                {
                    *pPixel++ = 0;
                }
            }
        }

        hResult = pSurface->lpVtbl->Unlock(pSurface, 0);
        if (hResult)
        {
            sub_006B20E0_ReportError("Failed to unlock memory surface", hResult);
        }

        D2_ASSERT(sub_006B58A0_CreateGlyphTexture(&gapFontGlyphA_00971150[nChar - ' '], &gapFontGlyphB_009712D0[nChar - ' '], 8, 16), 0xBF);
        if (gdwRenderFlags_0096F3A8 & gdwBitMasks[10])
        {
            sub_006B38A0_UploadGlyph(gapFontGlyphA_00971150[nChar - ' '], pSurface, 16);
        }
        else
        {
            gapFontGlyphB_009712D0[nChar - ' ']->lpVtbl->Load(gapFontGlyphB_009712D0[nChar - ' '], pTexture);
        }
    }

    pTexture->lpVtbl->Release(pTexture);
    pSurface->lpVtbl->Release(pSurface);
    GetCharWidthA(hDC, 0x20, 0x7F, gaFontCharWidths_00970FC8);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

#include "gen/data/Source/Storm/006B72A0_sub_006B72A0_CreateFontTextures.inc"
