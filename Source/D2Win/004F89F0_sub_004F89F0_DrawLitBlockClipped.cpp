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

void __fastcall sub_004F7850_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F7850
extern int gnSubtileRowXOffset_0072DB48[]; // 0x0072DB48
extern int gnSubtileRowWidth_0072DB84[]; // 0x0072DB84
extern int gnSubtileRowSrcOffset_0072DBC0[]; // 0x0072DBC0
extern int gnClipBottom_007C97A0; // 0x007C97A0
extern int gnClipLeft_007CA318; // 0x007CA318
extern unsigned char gLightCube_007CA320[32][32][32]; // 0x007CA320
extern int gnClipTop_007D2334; // 0x007D2334
extern int gnClipRight_007D233C; // 0x007D233C
extern D2PaletteStrc gLightPalettes_007D2348[]; // 0x007D2348
extern int gnScreenPitch_007D544C; // 0x007D544C

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

// build: context ClipRowSpan
static __forceinline int ClipRowSpan(int* pnSkip, int nWidth, int nRight, int nLeft)
{
    *pnSkip = nLeft;
    int nCount = D2_MAX(nRight, 0);
    return D2_MIN(nCount, nWidth) - *pnSkip;
}

// 0x004F89F0
void __fastcall sub_004F89F0_DrawLitBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, int* pLight)
{
    int nLightX = pLight[0] << 4;
    const int nLightXStep = pLight[3] - pLight[0];
    int nLightY = pLight[1] << 4;
    const int nLightYStep = pLight[2] - pLight[1];
    if (pBlock->nFormat & 4)
    {
        sub_004F7850_DrawLitRleRowsClipped(nX, nY, pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 15, 7);
        return;
    }

    const int nStartRow = D2_MAX(gnClipTop_007D2334 - nY, 0);
    const int nEndRow = D2_MIN(gnClipBottom_007C97A0 - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch_007D544C * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
        const int nNegX = -(nX + gnSubtileRowXOffset_0072DB48[i]);
        unsigned char* pLevels = (unsigned char*)gLightCube_007CA320 + 32 * ((nLightY >> 7) + 32 * (nLightX >> 7)) + gnSubtileRowXOffset_0072DB48[i];
        unsigned char* d = pRow + gnSubtileRowXOffset_0072DB48[i];
        unsigned char* s = pBlock->pData + gnSubtileRowSrcOffset_0072DBC0[i];
        int nSkip;
        int nCount = ClipRowSpan(&nSkip, gnSubtileRowWidth_0072DB84[i], gnClipRight_007D233C + nNegX, D2_MAX(gnClipLeft_007CA318 + nNegX, 0));
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            {
                unsigned char* pEnd = s + nCount;
                while (s < pEnd)
                {
                    *d = gLightPalettes_007D2348[*pLevels].unk0x00[*s];
                    ++s, ++d, ++pLevels;
                }
            }
        }

        pRow += gnScreenPitch_007D544C;
        nLightX += nLightXStep;
        nLightY += nLightYStep;
    }
}
