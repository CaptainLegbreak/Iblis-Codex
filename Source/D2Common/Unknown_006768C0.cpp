struct D2DrlgCoordsStrc { int nX, nY, nWidth, nHeight; };
struct D2DrlgLinkStrc { void* pfLinker; int nLevel, nLevelLink, nLevelLinkEx; };
struct D2DrlgLevelLinkDataStrc
{
    unsigned int unk_00[2];
    D2DrlgCoordsStrc pLevelCoord[15];
    D2DrlgLinkStrc* pLink;
    int nRand[4][15];
    int nIteration;
    int nCurrentLevel;
};

// 0x006768C0
int __fastcall sub_006768C0_PlaceLevel(D2DrlgLevelLinkDataStrc* pData)
{
    pData->nRand[1][pData->nIteration] = 0;
    pData->nRand[0][pData->nIteration] = pData->nRand[1][pData->nIteration];
    const int nIndex = pData->nIteration;
    const int nDirection = pData->nRand[0][nIndex];
    D2DrlgCoordsStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    switch (nDirection)
    {
    case 0:
        pData->pLevelCoord[nIndex].nX = pLinkCoord->nX;
        pData->pLevelCoord[nIndex].nY = pLinkCoord->nHeight + pLinkCoord->nY;
        break;
    case 1:
        pData->pLevelCoord[nIndex].nX = pLinkCoord->nX - pData->pLevelCoord[nIndex].nWidth;
        pData->pLevelCoord[nIndex].nY = pLinkCoord->nY;
        break;
    case 2:
        pData->pLevelCoord[nIndex].nX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nX;
        pData->pLevelCoord[nIndex].nY = pLinkCoord->nY - pData->pLevelCoord[nIndex].nHeight;
        break;
    case 3:
        pData->pLevelCoord[nIndex].nX = pLinkCoord->nWidth + pLinkCoord->nX;
        pData->pLevelCoord[nIndex].nY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nY;
        break;
    }
    return 1;
}
