#define D2_ABS_004F8B80(x) ((x) < 0 ? -(x) : (x))
extern int gdwGlobal_0072DA50; // 0x0072DA50

struct D2LightCellStrc
{
    unsigned char nLevel;
    unsigned char unk0x01[0x0B];
};

struct D2TileBlockList004F8B80Strc
{
    char unk0x00[0x50];
    int nBlocks;
    D2TileLibraryBlockStrc* pBlocks;
};

// 0x004F8B80
void __fastcall sub_004F8B80_DrawTileBlocks(D2TileBlockList004F8B80Strc* pTile, int nX, int nY, D2LightCellStrc (*pLight)[8])
{
    unsigned char* pScreen = gnScreenPitch * nY + gpScreenBuffer + nX;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        D2TileLibraryBlockStrc* pBlock = &pTile->pBlocks[i];
        const int nPosX = pBlock->nPosX;
        unsigned char* pDst = pBlock->nPosY * gnScreenPitch + nPosX + pScreen;
        if (!(pBlock->nFormat & 1))
            continue;
        const int nBlockX = nPosX + nX;
        const int nBlockY = nY + pBlock->nPosY;
        if (nBlockY < gnScreen_7D2330 || nBlockY >= gnScreen_7D2338 || nBlockX < gnScreen_7C9788 || nBlockX >= gnScreen_7C9798)
            continue;

        int aLight[4];
        int bFlat = 0;
        unsigned char nLight = 0;
        if (gnLightingOff)
        {
            nLight = pLight[pBlock->nGridY + 1][pBlock->nGridX + 1].nLevel;
            bFlat = 1;
        }
        else
        {
            D2LightCellStrc* pCell = pLight[pBlock->nGridY] + pBlock->nGridX;
            const int nL21 = pCell[10].nLevel;
            const int nL12 = pCell[17].nLevel;
            const int nL11 = pCell[9].nLevel;
            const int nL22 = pCell[18].nLevel;
            int nDelta = nL21 - nL11;
            const int nDiff1 = D2_ABS_004F8B80(nDelta);
            nDelta = nL12 - nL11;
            const int nDiff2 = D2_ABS_004F8B80(nDelta);
            nDelta = nL22 - nL21;
            const int nDiff3 = D2_ABS_004F8B80(nDelta);
            if (!gdwGlobal_0072DA50 && nDiff3 + nDiff2 + nDiff1 >= 10)
            {
                aLight[0] = (nL12 + pCell[16].nLevel + nL11 + pCell[8].nLevel) >> 2;
                aLight[1] = (pCell[1].nLevel + pCell[2].nLevel + nL21 + nL11) >> 2;
                aLight[2] = (pCell[19].nLevel + nL12 + pCell[11].nLevel + nL21) >> 2;
                aLight[3] = (pCell[25].nLevel + pCell[26].nLevel + nL22 + nL12) >> 2;
            }
            else
            {
                nLight = nL11;
                bFlat = 1;
            }
        }

        if (nBlockY >= gnInnerBlockTop && nBlockY < gnInnerBlockBottom && nBlockX >= gnInnerBlockLeft && nBlockX < gnInnerBlockRight)
        {
            if (bFlat)
                CMNSUBTILE_DrawBlock(pBlock, pDst, nLight);
            else
                CMNSUBTILE_DrawLitBlock(pBlock, pDst, aLight);
        }
        else
        {
            if (bFlat)
                CMNSUBTILE_DrawBlockClipped(pBlock, nBlockX, nBlockY, pDst, nLight);
            else
                CMNSUBTILE_DrawLitBlockClipped(pBlock, nBlockX, nBlockY, pDst, aLight);
        }
    }
}
