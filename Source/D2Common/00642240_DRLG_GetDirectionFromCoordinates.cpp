struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

// 0x00642240
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2)
{
    if (pDrlgCoord1->nPosX > pDrlgCoord2->nPosX)
    {
        if (pDrlgCoord1->nPosX == pDrlgCoord2->nPosX + pDrlgCoord2->nWidth)
            return 0;
    }
    else
    {
        if (pDrlgCoord2->nPosX == pDrlgCoord1->nPosX + pDrlgCoord1->nWidth)
            return 2;
    }

    if (pDrlgCoord1->nPosY > pDrlgCoord2->nPosY)
    {
        if (pDrlgCoord1->nPosY == pDrlgCoord2->nPosY + pDrlgCoord2->nHeight)
            return 1;
    }
    else
    {
        if (pDrlgCoord2->nPosY == pDrlgCoord1->nPosY + pDrlgCoord1->nHeight)
            return 3;
    }

    return -1;
}
