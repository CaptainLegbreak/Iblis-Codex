struct D2DrlgStrc
{
    char unk0x000[0x450];
    unsigned char nDifficulty;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1C];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
    char unk0x02C[0x1B4 - 0x2C];
    D2DrlgStrc* pDrlg;
};

struct D2LevelDefBin
{
    char unk0x00[0x0C];
    int dwSizeX[3];
    int dwSizeY[3];
};

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0

// 0x00678910
D2DrlgLevelStrc* __stdcall sub_00678910(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef;
    D2DrlgLevelStrc* pAdjacentLevel;
    int nSizeX;
    int nSizeY;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    int nHalfWidth = pLevel->nWidth / 2;
    int nPosY = 0;

    for (int i = 0; i < 5; ++i)
    {
        pLevelDef = DATATBLS_GetLevelDefRecord(79 + i);
        nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
        nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
        nPosY -= nSizeY;
        pAdjacentLevel = DRLG_GetLevel(pDrlg, 79 + i);
        const int nOffsetX = nHalfWidth - nSizeX / 2;
        pAdjacentLevel->nPosX = nOffsetX + pLevel->nPosX;
        pAdjacentLevel->nPosY = pLevel->nPosY + nPosY;
        pAdjacentLevel->nWidth = nSizeX;
        pAdjacentLevel->nHeight = nSizeY;
    }

    return pAdjacentLevel;
}
