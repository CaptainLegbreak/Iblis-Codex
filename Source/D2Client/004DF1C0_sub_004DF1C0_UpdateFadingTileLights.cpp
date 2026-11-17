extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TileLibraryEntryStrc
{
    unsigned int nLightDirection;
};

struct D2GfxLightStrc
{
    unsigned int aColor[8];
};

struct D2LightOffsetStrc
{
    int nX;
    int nY;
};

struct D2LightOffsetsStrc
{
    D2LightOffsetStrc aOffset[6];
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int unk0x08[3];
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    int unk0x20;
    unsigned int dwLightFlags;
    unsigned char nAlpha;
    unsigned char nFadeFrom;
    unsigned char nFadeTo;
    char unk0x2B;
    unsigned int dwLightTime;
};

struct D2TileLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2DrlgTileDataStrc* pTileData;
    D2TileLightNodeStrc* pNext;
};

struct D2CellPosStrc;

struct D2UnitLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2CellPosStrc* pPos;
    D2UnitLightNodeStrc* pNext;
};

struct D2TileLightEntryStrc
{
    int unk0x00[5];
    D2TileLightNodeStrc* pFadeList;
    D2UnitLightNodeStrc* pUnitList;
    int unk0x1C;
    D2TileLightNodeStrc* pList;
};

struct D2TileLightCtxStrc
{
    int unk0x00;
    int nX;
    int nY;
    int unk0x0C[6];
    int f_24;
    int f_28;
    char unk0x2C[0xEAA8 - 0x2C];
    D2TileLightEntryStrc* pEntries;
    int unk0xEAAC;
    unsigned int nSize;
};

extern unsigned int gaLightSampleCounts_006DB9D8[]; // 0x006DB9D8
extern D2LightOffsetsStrc gaLightOffsetsA_0072ABC8[]; // 0x0072ABC8
extern D2LightOffsetsStrc gaLightOffsetsB_0072A9E8[]; // 0x0072A9E8
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl sub_004F51D0_IsPerspective(); // 0x004F51D0
int __stdcall sub_00477730(); // 0x00477730
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall sub_00475AA0_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3); // 0x00475AA0
int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha); // 0x004F6950
int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels); // 0x004F6920
void __fastcall sub_004DC7B0(D2CellPosStrc* pPos, unsigned int nColor, int nArg); // 0x004DC7B0

static D2LightOffsetsStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileLibraryEntryStrc* pTile, unsigned int* pCount, int bAlternate)
{
    *pCount = gaLightSampleCounts_006DB9D8[pTile->nLightDirection];
    if (bAlternate)
        return &gaLightOffsetsA_0072ABC8[pTile->nLightDirection];
    return &gaLightOffsetsB_0072A9E8[pTile->nLightDirection];
}

// 0x004DF1C0
void __fastcall sub_004DF1C0_UpdateFadingTileLights(D2TileLightCtxStrc* pCtx)
{
    int nCount = pCtx->nSize * pCtx->nSize;
    D2TileLightEntryStrc* pEntry = pCtx->pEntries;
    while (nCount--)
    {
        if (pEntry->pFadeList)
        {
            const int nScreenPanels = sub_0045AE90();
            const int bPerspective = sub_004F51D0_IsPerspective();
            const int nLightDetail = sub_00477730();
            const unsigned int nTick = GetTickCount();
            const int bFade = nLightDetail >= 4;
            for (D2TileLightNodeStrc* pNode = pEntry->pFadeList; pNode; pNode = pNode->pNext)
            {
                D2DrlgTileDataStrc* pTileData = pNode->pTileData;
                D2_ASSERT(pTileData->nTileType != 15, 0xF9);

                const unsigned int dwLightFlags = pTileData->dwLightFlags;
                if (dwLightFlags & 2)
                {
                    if (bFade)
                    {
                        if (nTick < pTileData->dwLightTime)
                        {
                            pTileData->nAlpha = pTileData->nFadeFrom + (pTileData->nFadeTo - pTileData->nFadeFrom) * (int)(nTick - pTileData->dwLightTime + 500) / 500;
                        }
                        else
                        {
                            unsigned char* pAlpha = &pTileData->nAlpha;
                            *pAlpha = pTileData->nFadeTo;
                            pTileData->dwLightFlags = dwLightFlags & ~2;
                        }
                    }
                    else
                    {
                        unsigned char* pAlpha = &pTileData->nAlpha;
                        *pAlpha = pTileData->nFadeTo;
                        pTileData->dwLightFlags = dwLightFlags & ~2;
                    }

                    if (!pTileData->nAlpha)
                        pTileData->dwFlags |= 0x400;
                    else
                        pTileData->dwFlags &= ~0x400;
                }

                if ((pTileData->dwLightFlags & 4) && nTick >= pTileData->dwLightTime)
                {
                    pTileData->dwLightFlags &= ~4;
                    pTileData->dwFlags |= 8;
                }

                if (pTileData->dwFlags & 0x408)
                    continue;

                if (!(pTileData->dwFlags & 0x1C000))
                    continue;

                unsigned int nLights;
                D2LightOffsetsStrc* pOffsets = sub_004DEDB0_GetLightOffsets(pTileData->pTile, &nLights, pTileData->dwLightFlags & 1);
                D2GfxLightStrc tLight;
                for (unsigned int i = 0; i < nLights; ++i)
                {
                    unsigned char nValue0;
                    unsigned char nValue1;
                    unsigned char nValue2;
                    unsigned char nValue3;
                    sub_00475AA0_ReadGridCell(pNode->nX + 8 * pOffsets->aOffset[i].nX, pNode->nY + 8 * pOffsets->aOffset[i].nY, &nValue0, &nValue1, &nValue2, &nValue3);
                    nValue0 = nValue0 > 0 ? nValue0 : 0;
                    tLight.aColor[i] = (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0;
                }

                const unsigned char nAlpha = pTileData->nAlpha;
                int nX;
                int nY;
                if (bPerspective)
                {
                    nX = pNode->nX;
                    nY = pNode->nY;
                }
                else
                {
                    nX = pCtx->nX - pCtx->f_24 + pTileData->nWidth;
                    nY = pTileData->nHeight - pCtx->f_28 + pCtx->nY;
                }

                int bDrawn;
                if (nAlpha != 0xFF)
                    bDrawn = TILE_TileDrawTrans(pTileData->pTile, nX, nY, &tLight, nScreenPanels, nAlpha);
                else
                    bDrawn = TILE_TileDrawLit(pTileData->pTile, nX, nY, &tLight, nScreenPanels);

                if (bDrawn)
                    pTileData->dwFlags |= 0x20000;
            }
        }

        for (D2UnitLightNodeStrc* pUnitNode = pEntry->pUnitList; pUnitNode; pUnitNode = pUnitNode->pNext)
        {
            unsigned char nValue0;
            unsigned char nValue1;
            unsigned char nValue2;
            unsigned char nValue3;
            sub_00475AA0_ReadGridCell(pUnitNode->nX, pUnitNode->nY, &nValue0, &nValue1, &nValue2, &nValue3);
            sub_004DC7B0(pUnitNode->pPos, (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0, 0);
        }

        ++pEntry;
    }
}
