#include "D2Glide.h"
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hdc); // 0x006CC0A0
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleBitmap(void* hdc, int cx, int cy); // 0x006CC0E4
extern int gnSubtileRowXOffset_0072DB48[]; // 0x0072DB48
extern int gnSubtileRowWidth_0072DB84[]; // 0x0072DB84
extern int gnSubtileRowSrcOffset_0072DBC0[]; // 0x0072DBC0
extern unsigned long gdwGlideDebugFontTextColor_0072F2B0; // 0x0072F2B0
extern int gnScreenPitch_007D544C; // 0x007D544C
extern int gaGlideDebugFontCharWidths_008802C8[96]; // 0x008802C8
extern unsigned char* gpGlideDebugFontGlyphs_0088044C; // 0x0088044C

unsigned long gdwGlideDebugFontBkColor_00880448; // 0x00880448

unsigned char* gpGlideDebugFontGlyphs_0088044C; // 0x0088044C

// 0x004F69B0
void __fastcall sub_004F69B0_DrawSubtileRows(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette)
{
    unsigned char* pRow = pDst;
    for (int i = 0; i < 15; ++i)
    {
        unsigned char* d = &pRow[gnSubtileRowXOffset_0072DB48[i]];
        unsigned char* s = &pSrc[gnSubtileRowSrcOffset_0072DBC0[i]];
        switch (gnSubtileRowWidth_0072DB84[i])
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
        pRow += gnScreenPitch_007D544C;
    }
}

// 0x0050B9E0
void __cdecl sub_0050B9E0_GlideCreateDebugFont()
{
    void* hDC = CreateCompatibleDC(0);
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier_006DD52C);
    void* hBitmap = CreateCompatibleBitmap(hDC, 8, 16);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwGlideDebugFontTextColor_0072F2B0);
    SetBkColor(hDC, gdwGlideDebugFontBkColor_00880448);
    SetBkMode(hDC, 2);
    tagRECT rect;
    SetRect(&rect, 0, 0, 8, 16);
    D2_ASSERT(!gpGlideDebugFontGlyphs_0088044C, 0x98);
    gpGlideDebugFontGlyphs_0088044C = (unsigned char*)FOG_Alloc(0x3000, ".\\Src\\glDebugFont.cpp", 0x99, 0);
    for (int nGlyph = 0; nGlyph < 96; ++nGlyph)
    {
        unsigned char* pMask = &gpGlideDebugFontGlyphs_0088044C[nGlyph * 0x80];
        char cChar = nGlyph + 0x20;
        DrawTextA(hDC, &cChar, 1, &rect, 0);
        for (int y = 0; y < 16; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (GetPixel(hDC, x, y) == gdwGlideDebugFontTextColor_0072F2B0)
                    *pMask++ = 0xFF;
                else
                    *pMask++ = 0;
            }
        }
    }
    GetCharWidthA(hDC, 0x20, 0x7F, gaGlideDebugFontCharWidths_008802C8);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

#include "gen/data/Source/D2Glide/Src/glDebugFont.inc"

// 0x0050BB70
void __cdecl sub_0050BB70_GlideFreeDebugFont()
{
    if (gpGlideDebugFontGlyphs_0088044C)
    {
        FOG_Free(gpGlideDebugFontGlyphs_0088044C, ".\\Src\\glDebugFont.cpp", 0xFB, 0);
        gpGlideDebugFontGlyphs_0088044C = 0;
    }
}
