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

struct D2TileLightStrc
{
    int nCorner[4];
};

struct D2TileDrawFunctionsStrc
{
    void* unk0x00[6];
    void (__fastcall* pfDrawLitBlock)(unsigned char* pData, int nX, int nY, D2TileLightStrc* pLight, int nArg);
};

int __stdcall sub_005FDEA0(D2TileStrc* pTile, int a2, int a3);                                              // 0x005FDEA0

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C;                                               // 0x007C914C

// 0x006C93A0
int __fastcall sub_006C93A0_DrawLitTile(D2TileStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf, int nArg)
{
    int bResult = 0;
    if (sub_005FDEA0(pTile, 1, 0))
    {
        int nLeft = -32;
        int nRight = gnScreenWidth_007C9138;
        const int nBottom = gnScreenHeight_007C913C + 32;
        switch (nHalf)
        {
        case 1:
            nRight -= gnScreenWidth_007C9138 / 2;
            break;
        case 2:
            nLeft = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            const int nPosX = pTile->pBlocks[i].nX + nX;
            const int nPosY = pTile->pBlocks[i].nY + nY;
            if (nPosX >= nLeft && nPosX < nRight && nPosY >= -32 && nPosY < nBottom)
            {
                const int nIndex = pTile->pBlocks[i].nX >> 5;
                D2SubTileBlockStrc* pBlock = i + pTile->pBlocks;
                D2TileLightStrc tLight;
                bResult = 1;
                tLight.nCorner[0] = pLight[4 * nIndex];
                tLight.nCorner[3] = pLight[4 * nIndex];
                tLight.nCorner[1] = pLight[4 * nIndex + 4];
                tLight.nCorner[2] = pLight[4 * nIndex + 4];
                gpTileDrawFunctions_007C914C->pfDrawLitBlock(pBlock->pData, nPosX, nPosY, &tLight, nArg);
            }
        }
    }

    return bResult;
}
