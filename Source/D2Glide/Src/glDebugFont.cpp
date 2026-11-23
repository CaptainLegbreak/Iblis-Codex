#include "D2Glide.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hdc); // 0x006CC0A0

extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleBitmap(void* hdc, int cx, int cy); // 0x006CC0E4

extern int ganSubtileRowXOffset[]; // 0x0072DB48

extern int ganSubtileRowWidth[]; // 0x0072DB84

extern int ganSubtileRowSrcOffset[]; // 0x0072DBC0

extern unsigned long gdwGlideDebugFontTextColor; // 0x0072F2B0

extern int gnScreenPitch; // 0x007D544C

extern int gaGlideDebugFontCharWidths[96]; // 0x008802C8

extern unsigned char* gpGlideDebugFontGlyphs; // 0x0088044C

unsigned long gdwGlideDebugFontBkColor; // 0x00880448

unsigned char* gpGlideDebugFontGlyphs; // 0x0088044C

// 0x004F69B0
void __fastcall CMNSUBTILE_DrawIsoBlockFlat(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette)
{
    unsigned char* pRow = pDst;
    for (int i = 0; i < 15; ++i)
    {
        unsigned char* d = &pRow[ganSubtileRowXOffset[i]];
        unsigned char* s = &pSrc[ganSubtileRowSrcOffset[i]];
        switch (ganSubtileRowWidth[i])
        {
        case 32:
            d[31] = pPalette[s[31]];
            d[30] = pPalette[s[30]];
            d[29] = pPalette[s[29]];
            d[28] = pPalette[s[28]];
        case 28:
            d[27] = pPalette[s[27]];
            d[26] = pPalette[s[26]];
            d[25] = pPalette[s[25]];
            d[24] = pPalette[s[24]];
        case 24:
            d[23] = pPalette[s[23]];
            d[22] = pPalette[s[22]];
            d[21] = pPalette[s[21]];
            d[20] = pPalette[s[20]];
        case 20:
            d[19] = pPalette[s[19]];
            d[18] = pPalette[s[18]];
            d[17] = pPalette[s[17]];
            d[16] = pPalette[s[16]];
        case 16:
            d[15] = pPalette[s[15]];
            d[14] = pPalette[s[14]];
            d[13] = pPalette[s[13]];
            d[12] = pPalette[s[12]];
        case 12:
            d[11] = pPalette[s[11]];
            d[10] = pPalette[s[10]];
            d[9] = pPalette[s[9]];
            d[8] = pPalette[s[8]];
        case 8:
            d[7] = pPalette[s[7]];
            d[6] = pPalette[s[6]];
            d[5] = pPalette[s[5]];
            d[4] = pPalette[s[4]];
        case 4:
            d[3] = pPalette[s[3]];
            d[2] = pPalette[s[2]];
            d[1] = pPalette[s[1]];
            d[0] = pPalette[s[0]];
        }
        pRow += gnScreenPitch;
    }
}

// 0x0050B9E0
void __cdecl GLIDE_CreateDebugFont()
{
    void* hDC = CreateCompatibleDC(0);
// build: symbol ?gszCourier@* 0x006DD52C
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier);
    void* hBitmap = CreateCompatibleBitmap(hDC, 8, 16);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwGlideDebugFontTextColor);
    SetBkColor(hDC, gdwGlideDebugFontBkColor);
    SetBkMode(hDC, 2);
    tagRECT rect;
    SetRect(&rect, 0, 0, 8, 16);
    D2_ASSERT(!gpGlideDebugFontGlyphs, 0x98);
    gpGlideDebugFontGlyphs = (unsigned char*)FOG_Alloc(0x3000, ".\\Src\\glDebugFont.cpp", 0x99, 0);
    for (int nGlyph = 0; nGlyph < 96; ++nGlyph)
    {
        unsigned char* pMask = &gpGlideDebugFontGlyphs[nGlyph * 0x80];
        char cChar = nGlyph + 0x20;
        DrawTextA(hDC, &cChar, 1, &rect, 0);
        for (int y = 0; y < 16; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (GetPixel(hDC, x, y) == gdwGlideDebugFontTextColor)
                    *pMask++ = 0xFF;
                else
                    *pMask++ = 0;
            }
        }
    }
    GetCharWidthA(hDC, 0x20, 0x7F, gaGlideDebugFontCharWidths);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

// 0x0050BB70
void __cdecl GLIDE_FreeDebugFont()
{
    if (gpGlideDebugFontGlyphs)
    {
        FOG_Free(gpGlideDebugFontGlyphs, ".\\Src\\glDebugFont.cpp", 0xFB, 0);
        gpGlideDebugFontGlyphs = 0;
    }
}

struct D2GlideFontVertexStrc
{
    float x;
    float y;
    int nColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GlideDebugGlyphStrc
{
    unsigned char pixels[16][8];
};

typedef void (__stdcall* GlideTexDownloadMipMapFn)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);

extern GlideTexDownloadMipMapFn gpfnGrTexDownloadMipMap;                 // 0x0087EAB8

extern D2GrTexInfoStrc gtGlideDebugFontTexInfo;                             // 0x0072F2B4

int gaGlideDebugFontTexAddr[96];                                           // 0x008800D8

D2GlideFontVertexStrc gaGlideDebugFontVertices[4];                         // 0x00880258

static int gnGlideDebugFontTmu;                                            // 0x00880450

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);       // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

#pragma intrinsic(memcpy)

static int __fastcall GlideAlignAddress(int nAddress, int nAlignment)
{
    if (nAddress & (nAlignment - 1))
        nAddress = (nAddress | (nAlignment - 1)) + 1;
    return nAddress;
}

// 0x0050B860
int __fastcall GLIDE_DownloadDebugFont(int nStartAddress, int nAlignment)
{
    int nStride = GlideAlignAddress(0x80, nAlignment);
    int nTotal = nStride * 96;
    nStartAddress = GlideAlignAddress(nStartAddress, nAlignment);

    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(0x80, ".\\Src\\glDebugFont.cpp", 0x62, 0);
    gtGlideDebugFontTexInfo.pData = pBuffer;

    for (int nGlyph = 0; nGlyph < 96; ++nGlyph)
    {
        gaGlideDebugFontTexAddr[nGlyph] = nStartAddress;
        memcpy(pBuffer, &gpGlideDebugFontGlyphs[nGlyph * 0x80], 0x80);
        gpfnGrTexDownloadMipMap(gnGlideDebugFontTmu, gaGlideDebugFontTexAddr[nGlyph], 3, &gtGlideDebugFontTexInfo);
        nStartAddress += nStride;
    }

    FOG_Free(pBuffer, ".\\Src\\glDebugFont.cpp", 0x70, 0);

    gaGlideDebugFontVertices[0].x = 0.0f;
    gaGlideDebugFontVertices[0].y = 0.0f;
    gaGlideDebugFontVertices[0].nColor = -1;
    gaGlideDebugFontVertices[0].oow = 1.0f;
    gaGlideDebugFontVertices[1].oow = 1.0f;
    gaGlideDebugFontVertices[1].nColor = -1;
    gaGlideDebugFontVertices[0].sow = 0.0f;
    gaGlideDebugFontVertices[0].tow = 0.0f;
    gaGlideDebugFontVertices[1].x = 0.0f;
    gaGlideDebugFontVertices[1].y = 0.0f;
    gaGlideDebugFontVertices[1].sow = 0.0f;
    gaGlideDebugFontVertices[1].tow = 256.0f;
    gaGlideDebugFontVertices[2].x = 0.0f;
    gaGlideDebugFontVertices[2].y = 0.0f;
    gaGlideDebugFontVertices[2].nColor = -1;
    gaGlideDebugFontVertices[2].oow = 1.0f;
    gaGlideDebugFontVertices[2].sow = 128.0f;
    gaGlideDebugFontVertices[3].sow = 128.0f;
    gaGlideDebugFontVertices[2].tow = 256.0f;
    gaGlideDebugFontVertices[3].x = 0.0f;
    gaGlideDebugFontVertices[3].y = 0.0f;
    gaGlideDebugFontVertices[3].nColor = -1;
    gaGlideDebugFontVertices[3].tow = 0.0f;
    gaGlideDebugFontVertices[3].oow = 1.0f;

    return nTotal;
}

#include "gen/data/Source/D2Glide/Src/glDebugFont.inc"
