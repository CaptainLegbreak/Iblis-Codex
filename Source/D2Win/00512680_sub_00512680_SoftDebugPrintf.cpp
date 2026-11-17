extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
extern int gaDDrawDebugFontGlyphOffsets_008812A8[96];                                                       // 0x008812A8
extern int gaDDrawDebugFontCharWidths_00881428[96];                                                         // 0x00881428
extern unsigned char* gpDDrawDebugFontGlyphs_008815AC;                                                      // 0x008815AC

static int __stdcall sub_005125E0_SoftDebugDrawChar(int nY, int nX, char ch)
{
    if (nX > 640)
        return 0;

    if (nX < 0)
        return gaDDrawDebugFontCharWidths_00881428[ch];

    const unsigned char n = ch - 0x20;
    if (n <= 0x5F)
    {
        const unsigned char* pBits = gpDDrawDebugFontGlyphs_008815AC + gaDDrawDebugFontGlyphOffsets_008812A8[(char)n];
        unsigned char* pDst = gpScreenBuffer_007C9154 + gnScreenWidth_007C9138 * nY + nX;
        for (int nRow = 16; nRow; --nRow)
        {
            for (int nCol = 8; nCol; --nCol)
            {
                if (*pBits++)
                    *pDst = 0xFF;
                ++pDst;
            }
            pDst += gnScreenWidth_007C9138 - 8;
        }
        return gaDDrawDebugFontCharWidths_00881428[(char)n];
    }

    return gaDDrawDebugFontCharWidths_00881428[0];
}

// 0x00512680
void __fastcall sub_00512680_SoftDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    char szText[0x200];
    const int nLength = wvsprintfA(szText, szFormat, args);
    const int nStartX = nX;

    for (int i = 0; i < nLength; ++i)
    {
        nX += sub_005125E0_SoftDebugDrawChar(nY, nX, szText[i]);
        if (szText[i] == '\n')
        {
            nX = nStartX;
            nY += 0x0C;
        }
    }
}
