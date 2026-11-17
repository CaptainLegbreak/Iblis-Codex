struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};

struct D2TileLibraryBlockStrc
{
    short nPosX;
    short nPosY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned char nFormat;
    char unk0x09[0x07];
    unsigned char* pData;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_004F69B0_DrawSubtileRows(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette);  // 0x004F69B0
void __fastcall sub_004F6BB0_DrawLitSubtileRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep); // 0x004F6BB0
void __fastcall sub_004F71A0_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F71A0
void __fastcall sub_004F7580_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580

extern int gnClipBottom_007C978C;                                                                           // 0x007C978C
extern int gnClipLeft_007C9794;                                                                             // 0x007C9794
extern int gnInnerRight_007C9784;                                                                           // 0x007C9784
extern int gnInnerBottom_007C9790;                                                                          // 0x007C9790
extern int gnRowOffsets_007C97A8[732];                                                                      // 0x007C97A8
#define gnRowOffsets_007C9828 (gnRowOffsets_007C97A8 + 32)
extern int gnInnerTop_007CA31C;                                                                             // 0x007CA31C
extern int gnClipRight_007D2324;                                                                            // 0x007D2324
extern int gnInnerLeft_007D2328;                                                                            // 0x007D2328
extern int gnClipTop_007D232C;                                                                              // 0x007D232C
extern D2PaletteStrc gLightPalettes_007D2348[];                                                             // 0x007D2348
extern unsigned char* gpScreenBuffer_007D5448;                                                              // 0x007D5448
extern int gnScreenPitch_007D544C;                                                                          // 0x007D544C

// 0x004F6F60
void __fastcall sub_004F6F60_DrawRleRows(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows)
{
    unsigned char* p = pDst;
    while (nRows)
    {
        int nSkip = *pSrc++;
        int nCount = *pSrc++;
        if (!nSkip && !nCount)
        {
            --nRows;
            pDst += gnScreenPitch_007D544C;
            p = pDst;
        }
        else
        {
            p += nSkip;
            switch (nCount)
            {
            case 32: p[31] = pPalette[pSrc[31]];
            case 31: p[30] = pPalette[pSrc[30]];
            case 30: p[29] = pPalette[pSrc[29]];
            case 29: p[28] = pPalette[pSrc[28]];
            case 28: p[27] = pPalette[pSrc[27]];
            case 27: p[26] = pPalette[pSrc[26]];
            case 26: p[25] = pPalette[pSrc[25]];
            case 25: p[24] = pPalette[pSrc[24]];
            case 24: p[23] = pPalette[pSrc[23]];
            case 23: p[22] = pPalette[pSrc[22]];
            case 22: p[21] = pPalette[pSrc[21]];
            case 21: p[20] = pPalette[pSrc[20]];
            case 20: p[19] = pPalette[pSrc[19]];
            case 19: p[18] = pPalette[pSrc[18]];
            case 18: p[17] = pPalette[pSrc[17]];
            case 17: p[16] = pPalette[pSrc[16]];
            case 16: p[15] = pPalette[pSrc[15]];
            case 15: p[14] = pPalette[pSrc[14]];
            case 14: p[13] = pPalette[pSrc[13]];
            case 13: p[12] = pPalette[pSrc[12]];
            case 12: p[11] = pPalette[pSrc[11]];
            case 11: p[10] = pPalette[pSrc[10]];
            case 10: p[9] = pPalette[pSrc[9]];
            case 9: p[8] = pPalette[pSrc[8]];
            case 8: p[7] = pPalette[pSrc[7]];
            case 7: p[6] = pPalette[pSrc[6]];
            case 6: p[5] = pPalette[pSrc[5]];
            case 5: p[4] = pPalette[pSrc[4]];
            case 4: p[3] = pPalette[pSrc[3]];
            case 3: p[2] = pPalette[pSrc[2]];
            case 2: p[1] = pPalette[pSrc[1]];
            case 1: p[0] = pPalette[pSrc[0]];
            }
            p += nCount;
            pSrc += nCount;
        }
    }
}

// 0x004F8050
void __fastcall sub_004F8050_DrawRleVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nLight)
{
    if (nY < gnClipTop_007D232C || nY >= gnClipBottom_007C978C || nX < gnClipLeft_007C9794 || nX >= gnClipRight_007D2324)
        return;

    unsigned char* pPalette = gLightPalettes_007D2348[nLight >> 3].unk0x00;
    unsigned char* pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer_007D5448 + nX;
    D2_ASSERT(gpScreenBuffer_007D5448, 0x373);
    if (nY >= gnInnerTop_007CA31C && nY < gnInnerBottom_007C9790 && nX >= gnInnerLeft_007D2328 && nX < gnInnerRight_007C9784)
        sub_004F6F60_DrawRleRows(pSrc, pDst, pPalette, 0x20);
    else
        sub_004F7580_DrawRleRowsClipped(nX, nY, pSrc, pDst, pPalette, 0x20);
}

// 0x004F8810
void __fastcall sub_004F8810_DrawBlock(D2TileLibraryBlockStrc* pBlock, unsigned char* pDst, unsigned char nLight)
{
    unsigned char* pPalette = gLightPalettes_007D2348[nLight >> 3].unk0x00;
    if (pBlock->nFormat & 4)
        sub_004F6F60_DrawRleRows(pBlock->pData, pDst, pPalette, 0xF);
    else
        sub_004F69B0_DrawSubtileRows(pBlock->pData, pDst, pPalette);
}

// 0x004F8850
void __fastcall sub_004F8850_DrawLitBlock(D2TileLibraryBlockStrc* pBlock, unsigned char* pDst, int* pLight)
{
    const int nLightX = pLight[0] << 4;
    const int nLightXStep = pLight[3] - pLight[0];
    const int nLightY = pLight[1] << 4;
    const int nLightYStep = pLight[2] - pLight[1];
    if (pBlock->nFormat & 4)
        sub_004F71A0_DrawLitRleRows(pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 0xF, 7);
    else
        sub_004F6BB0_DrawLitSubtileRows(pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep);
}
