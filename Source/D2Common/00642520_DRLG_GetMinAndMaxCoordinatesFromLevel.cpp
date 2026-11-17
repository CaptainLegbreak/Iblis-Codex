struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    D2DrlgRoomStrc* pDrlgRoomNext;
    char unk0x28[0x0C];
    D2DrlgCoordStrc pDrlgCoord;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x10];
    D2DrlgRoomStrc* pFirstRoomEx;
};

// 0x00642520
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx;
    const D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;

    *pTileMinX = pDrlgCoord->nPosX;
    *pTileMinY = pDrlgCoord->nPosY;
    *pTileMaxX = pDrlgCoord->nPosX + pDrlgCoord->nWidth;
    *pTileMaxY = pDrlgCoord->nPosY + pDrlgCoord->nHeight;

    while (pDrlgRoom)
    {
        if (pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth > *pTileMaxX)
        {
            *pTileMaxX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        }

        if (pDrlgRoom->pDrlgCoord.nPosX < *pTileMinX)
        {
            *pTileMinX = pDrlgRoom->pDrlgCoord.nPosX;
        }

        if (pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight > *pTileMaxY)
        {
            *pTileMaxY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        }

        if (pDrlgRoom->pDrlgCoord.nPosY < *pTileMinY)
        {
            *pTileMinY = pDrlgRoom->pDrlgCoord.nPosY;
        }

        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }
}
