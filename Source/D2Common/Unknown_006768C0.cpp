#include "D2DrlgPresets.h"

// 0x006768C0
int __fastcall sub_006768C0_PlaceLevel(D2DrlgLevelLinkDataStrc* pData)
{
    pData->nRand[1][pData->nIteration] = 0;
    pData->nRand[0][pData->nIteration] = pData->nRand[1][pData->nIteration];
    const int nIndex = pData->nIteration;
    const int nDirection = pData->nRand[0][nIndex];
    D2DrlgCoordStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    switch (nDirection)
    {
    case 0:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        break;
    case 1:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX - pData->pLevelCoord[nIndex].nWidth;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY;
        break;
    case 2:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nPosX;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY - pData->pLevelCoord[nIndex].nHeight;
        break;
    case 3:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nPosY;
        break;
    }
    return 1;
}
