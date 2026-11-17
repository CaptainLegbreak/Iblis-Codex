struct D2TileBlockStrc
{
    short nPosX;
    short nPosY;
    char unk0x04[0x0C];
    void* pData;
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x50];
    int nBlocks;
    D2TileBlockStrc* pBlocks;
};

struct D2TileDrawFunctionsStrc
{
    void* unk0x00;
    void (__fastcall* pfDrawWallBlock)(void* pData, int nX, int nY);
    void* unk0x08[3];
    void (__fastcall* pfDrawShadowBlock)(void* pData, int nX, int nY, int nAlpha);
};

int __stdcall sub_005FDEA0(D2TileLibraryEntryStrc* pTile, int a2, int a3); // 0x005FDEA0
int __cdecl sub_006C8A50_GetBlendedShadows(); // 0x006C8A50

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C

// 0x006C9290
int __fastcall sub_006C9290_DrawWallTile(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, void* pLight, int nScreenPanels)
{
    int bDrawn = 0;

    if (sub_005FDEA0(pTile, 1, 0))
    {
        int nMinX = -32;
        int nMaxX = gnScreenWidth_007C9138;
        int nMaxY = gnScreenHeight_007C913C + 32;

        switch (nScreenPanels)
        {
        case 1:
            nMaxX -= gnScreenWidth_007C9138 / 2;
            break;
        case 2:
            nMinX = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            D2TileBlockStrc* pBlock = &pTile->pBlocks[i];
            const int nX = pBlock->nPosX + nPosX;
            const int nY = pTile->pBlocks[i].nPosY + nPosY;
            if (nX >= nMinX && nX < nMaxX && nY >= -32 && nY < nMaxY)
            {
                bDrawn = 1;
                if (sub_006C8A50_GetBlendedShadows())
                    gpTileDrawFunctions_007C914C->pfDrawShadowBlock(pTile->pBlocks[i].pData, nX, nY, 0xC0);
                else
                    gpTileDrawFunctions_007C914C->pfDrawWallBlock(pTile->pBlocks[i].pData, nX, nY);
            }
        }
    }

    return bDrawn;
}
