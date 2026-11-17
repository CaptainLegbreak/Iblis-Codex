struct D2DrlgLevelStrc;
struct D2DrlgCoordStrc;
struct D2OutdoorLinkStrc
{
    D2DrlgLevelStrc* pOtherLevel;
    int nSide;
    int unk_08;
    int nBlocked;
    D2DrlgCoordStrc* pCoords;
    D2OutdoorLinkStrc* pNext;
};
struct D2OutdoorInfoStrc
{
    char unk_00[0x5C];
    int nWidth;
    int nHeight;
    char unk_64[0x200];
    D2OutdoorLinkStrc* pLinks;
};
struct D2DrlgLevelStrc
{
    char unk_00[0x14];
    D2OutdoorInfoStrc* pOutdoor;
    int unk_18;
    int nX;
    int nY;
};
struct D2DrlgVertexStrc { int nX; int nY; };
struct D2OutdoorOffsetStrc { int nX; int nY; };
extern D2OutdoorOffsetStrc gaOffsets_006F05D8[]; // 0x006F05D8
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY); // 0x0066B980
int __fastcall sub_00673FF0_GetVisFlagToLevel(D2DrlgLevelStrc* pLevel, D2DrlgLevelStrc* pOtherLevel); // 0x00673FF0

// 0x00674040
int __fastcall DRLGOUTDOORS_GetOutLinkVisFlag(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pVertex)
{
    int y = pVertex->nY;
    D2OutdoorInfoStrc* pOutdoor = pLevel->pOutdoor;
    int x = pVertex->nX;
    int side;
    if (!x)
        side = y == 0;
    else
    {
        int const nMaxX = pOutdoor->nWidth - 1;
        if (!y)
            side = (x == nMaxX) + 1;
        else if (x == nMaxX)
            side = (y == pOutdoor->nHeight - 1) + 2;
        else if (y == pOutdoor->nHeight - 1)
            side = 3;
        else
            return 0;
    }
    int nSubtileX = gaOffsets_006F05D8[side].nX + 8 * pVertex->nX + pLevel->nX;
    int nSubtileY = gaOffsets_006F05D8[side].nY + 8 * pVertex->nY + pLevel->nY;
    for (D2OutdoorLinkStrc* pLink = pOutdoor->pLinks; pLink; pLink = pLink->pNext)
    {
        if (side == pLink->nSide && DRLGROOM_AreXYInsideCoordinates(pLink->pCoords, nSubtileX, nSubtileY))
        {
            if (pLink->nBlocked)
                return 0;
            return sub_00673FF0_GetVisFlagToLevel(pLevel, pLink->pOtherLevel);
        }
    }
    return 0;
}

#include "gen/data/Source/D2Common/00674040_DRLGOUTDOORS_GetOutLinkVisFlag.inc"
