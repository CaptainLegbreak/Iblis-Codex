struct D2SubTileBlockStrc
{
    short nX;
    short nY;
    int unk0x04;
    unsigned short nFormat;
    unsigned short unk0x0A;
    int unk0x0C;
    unsigned char* pData;
};

struct D2TileStrc
{
    char unk0x00[0x50];
    int nBlocks;
    D2SubTileBlockStrc* pBlocks;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette); // 0x00511FB0

extern int gnRenderWidth_007C9138;                                                                          // 0x007C9138
extern int gnRenderHeight_007C913C;                                                                         // 0x007C913C
extern int gnProjectOriginX_00880B60;                                                                       // 0x00880B60
extern int gnProjectOriginY_00880B68;                                                                       // 0x00880B68
extern int* gpnPerspectiveTable_00880B6C;                                                                   // 0x00880B6C

// 0x0050DD60
void __fastcall sub_0050DD60_ProjectToScreen(int nX, int nY, int nZ, int* pScreenX, int* pScreenY)
{
    const int nA = ((nX - gnProjectOriginX_00880B60) * 24) >> 16;
    const int nB = ((nY - gnProjectOriginY_00880B68) * 24) >> 16;
    const int nZScaled = nZ * 0x4CC;
    const int nSum = (nB + nA) * 0x2D4;
    const int nPerspective = gpnPerspectiveTable_00880B6C[(((nSum * 0x376 + (nZScaled << 9)) >> 20) - 0x1000) & 0x1FFF];
    *pScreenX = (((nB - nA) * nPerspective * 0x2D4) >> 20) + gnRenderWidth_007C9138 / 2;
    *pScreenY = ((((nZScaled * 0x376 - (nSum << 9)) >> 10) * nPerspective) >> 20) + gnRenderHeight_007C913C / 2 - 0x20;
}

// 0x0050F980
void __stdcall sub_0050F980_DecodeTileBlocks(D2TileStrc* pTile, unsigned char* pDst)
{
    memset(pDst, 0, 0x8000);

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const D2SubTileBlockStrc* pBlock = &pTile->pBlocks[i];
        unsigned char* p = pBlock->nX + ((pBlock->nY << 8) + pDst);
        const unsigned short nFormat = pBlock->nFormat;
        if (!(nFormat & 1))
        {
            continue;
        }

        if (nFormat & 4)
        {
            const unsigned char* pSrc = pBlock->pData;
            int nRows = 15;
            unsigned char* pRow = p;
            do
            {
                const unsigned char nGap = *pSrc++;
                unsigned char nCount = *pSrc++;
                if (!nGap && !nCount)
                {
                    --nRows;
                    pRow += 0x100;
                    p = pRow;
                }
                else
                {
                    p += nGap;
                    while (nCount--)
                    {
                        *p++ = *pSrc++;
                    }
                }
            }
            while (nRows);
        }
        else
        {
            const unsigned char* pSrc = pBlock->pData;
            p += 0x0E;
            int nLength = 4;
            D2_ASSERT(pSrc, 0xA8);
            D2_ASSERT(pDst, 0xA9);
            for (int nRow = 0; nRow < 15; ++nRow)
            {
                memcpy(p, pSrc, nLength);
                pSrc += nLength;
                if (nRow < 7)
                {
                    p += 0xFE;
                    nLength += 4;
                }
                else
                {
                    p += 0x102;
                    nLength -= 4;
                }
            }
        }
    }
}

// 0x00512410
int __fastcall sub_00512410_ForwardToDrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nScreenMode, void* pPalette)
{
    return sub_00511FB0_DrawImage(pData, nX, nY, dwGamma, nDrawMode, pPalette);
}
