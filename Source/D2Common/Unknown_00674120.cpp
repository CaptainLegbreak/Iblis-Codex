#include "D2Drlg.h"



int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570

// 0x00674120
int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (!(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x200))
    {
        return 0;
    }
    return DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
}
