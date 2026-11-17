extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260

struct D2TileGfxStrc
{
    unsigned int nOrientation;
};

struct D2CellTileStrc
{
    int nX;
    int nY;
    char unk0x08[0x0C];
    unsigned int dwFlags;
    D2TileGfxStrc* pTile;
    int nType;
    int unk0x20;
    unsigned int dwFadeFlags;
    unsigned char nAlpha;
    unsigned char nAlphaFrom;
    unsigned char nAlphaTo;
    unsigned char unk0x2B;
    unsigned int dwEndTick;
};

struct D2LightPointStrc
{
    int nX;
    int nY;
};

struct D2CellTileNodeStrc
{
    unsigned int dwFlags;
    D2LightPointStrc* pLightA;
    D2LightPointStrc* pLightB;
    D2CellTileStrc* pTile;
    D2CellTileNodeStrc* pNext;
};

struct D2GridCellStrc
{
    int unk0x00[4];
    D2CellTileNodeStrc* pNodes;
    D2CellTileNodeStrc* pTiles;
};

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
};

struct D2LightPairStrc
{
    int nA;
    int nB;
};

int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __cdecl D2GFX_CheckPerspective();                                                                       // 0x004F51D0
int __cdecl sub_00477730();                                                                                 // 0x00477730
void __fastcall sub_00475AA0_ReadGridCell(D2LightPointStrc* pA, D2LightPointStrc* pB, unsigned char* pC0, unsigned char* pC1, unsigned char* pC2, unsigned char* pC3); // 0x00475AA0
int __stdcall TILE_TileDrawLit(D2TileGfxStrc* pTile, int nX, int nY, unsigned int* pLight, int nGamma);   // 0x004F6920
int __stdcall TILE_TileDrawTrans(D2TileGfxStrc* pTile, int nX, int nY, unsigned int* pLight, int nGamma, unsigned char nAlpha); // 0x004F6950

extern unsigned int gaLightPairCounts_006DB9D8[];                                                           // 0x006DB9D8
extern D2LightPairStrc gaLightPairsB_0072A9E8[][6];                                                         // 0x0072A9E8
extern D2LightPairStrc gaLightPairsA_0072ABC8[][6];                                                         // 0x0072ABC8

static D2LightPairStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileGfxStrc* pTile, unsigned int* pCount, int bAlternate)
{
    *pCount = gaLightPairCounts_006DB9D8[pTile->nOrientation];
    if (bAlternate)
        return gaLightPairsA_0072ABC8[pTile->nOrientation];
    return gaLightPairsB_0072A9E8[pTile->nOrientation];
}

// 0x004DEF80
void __stdcall sub_004DEF80_DrawCellTiles(D2GridCellStrc* pCell, int nPass, D2CellGridViewStrc* pView)
{
    const int nGamma = sub_0045AE90();
    const int bPerspective = D2GFX_CheckPerspective();
    const int nDetail = sub_00477730();
    const unsigned int dwTick = GetTickCount();
    const int bFade = nDetail >= 4;
    D2_ASSERT(nPass == 0 || nPass == 1, 0xF3);

    for (D2CellTileNodeStrc* pNode = pCell->pTiles; pNode; pNode = pNode->pNext)
    {
        D2CellTileStrc* pTile = pNode->pTile;
        D2_ASSERT(pTile->nType != 0xF, 0xF9);

        const unsigned int dwFade = pTile->dwFadeFlags;
        if (dwFade & 2)
        {
            if (bFade)
            {
                if (dwTick < pTile->dwEndTick)
                {
                    pTile->nAlpha = pTile->nAlphaFrom + (pTile->nAlphaTo - pTile->nAlphaFrom) * (int)(dwTick - pTile->dwEndTick + 500) / 500;
                }
                else
                {
                    unsigned char* pAlpha = &pTile->nAlpha;
                    *pAlpha = pTile->nAlphaTo;
                    pTile->dwFadeFlags = dwFade & ~2;
                }
            }
            else
            {
                unsigned char* pAlpha = &pTile->nAlpha;
                *pAlpha = pTile->nAlphaTo;
                pTile->dwFadeFlags = dwFade & ~2;
            }

            if (!pTile->nAlpha)
                pTile->dwFlags |= 0x400;
            else
                pTile->dwFlags &= ~0x400;
        }

        if ((pTile->dwFadeFlags & 4) && dwTick >= pTile->dwEndTick)
        {
            pTile->dwFadeFlags &= ~4;
            pTile->dwFlags |= 8;
        }

        if (!(pTile->dwFlags & 0x408) && nPass != ((pTile->dwFlags & 0x1C000) != 0))
        {
            unsigned int nCount;
            const D2LightPairStrc* pPairs = sub_004DEDB0_GetLightOffsets(pTile->pTile, &nCount, pTile->dwFadeFlags & 1);
            unsigned int aLight[8];
            for (unsigned int i = 0; i < nCount; ++i)
            {
                unsigned char nC0, nC1, nC2, nC3;
                sub_00475AA0_ReadGridCell(&pNode->pLightA[pPairs[i].nA], &pNode->pLightB[pPairs[i].nB], &nC0, &nC1, &nC2, &nC3);
                nC0 = nC0 > 0 ? nC0 : 0;
                aLight[i] = (((((nC3 << 8) | nC2) << 8) | nC1) << 8) | nC0;
            }

            const unsigned char nAlpha = pTile->nAlpha;
            int nX;
            int nY;
            if (bPerspective)
            {
                nX = (int)pNode->pLightA;
                nY = (int)pNode->pLightB;
            }
            else
            {
                nX = pView->nOffsetX - pView->nScrollX + pTile->nX;
                nY = pTile->nY - pView->nScrollY + pView->nOffsetY;
            }

            int bDrawn;
            if (nAlpha != 0xFF)
                bDrawn = TILE_TileDrawTrans(pTile->pTile, nX, nY, aLight, nGamma, nAlpha);
            else
                bDrawn = TILE_TileDrawLit(pTile->pTile, nX, nY, aLight, nGamma);

            if (bDrawn)
                pTile->dwFlags |= 0x20000;
        }
    }
}
