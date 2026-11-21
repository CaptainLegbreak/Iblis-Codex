#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"

struct D2DrlgOutdoorInfoStrc;
struct D2CoordStrc;




void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
static __declspec(noinline) void sub_0067DCA0(D2DrlgLevelStrc* pLevel);


int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0
extern const D2CoordStrc gAct5WallSteps_006F1FD8[12]; // 0x006F1FD8

// 0x0067DCA0
static void sub_0067DCA0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;

    const int nX = pInfo->nGridWidth - 2;
    const int nY = pInfo->nGridHeight - 3;
    D2DrlgGridStrc* const pGrid = &pInfo->pGrid[2];
    DRLGGRID_AlterGridFlag(pGrid, pInfo->nGridWidth - 2, pInfo->nGridHeight - 4, 0x400, 0);
    DRLGGRID_AlterGridFlag(pGrid, nX, nY, 0x400, 0);
}

// build: context EmitMarkLevel111Exit
// calling-convention shim (not game code)
void __stdcall EmitMarkLevel111Exit(D2DrlgLevelStrc* pLevel)
{
    sub_0067DCA0(pLevel);
}

// 0x0067DEF0
void __stdcall sub_0067DEF0(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    int nRight = pInfo->nGridWidth - 2;
    int nX = nRight;
    int nY = 0;
    int nBottom = pInfo->nGridHeight - 2;
    int bTundra = pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS;
    int nKindBase = bTundra ? 0x3BD : 0x371;
    int nPresetBase = bTundra ? 0x3C9 : 0x37D;

    while (nX != 0 || nY != nBottom)
    {
        const int nEntry = DRLGGRID_GetGridEntry(&pInfo->pGrid[0], nX, nY);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nEntry - nKindBase + nPresetBase, -1, 0);
        nX += 2 * gAct5WallSteps_006F1FD8[nEntry - nKindBase].nX;
        nY += 2 * gAct5WallSteps_006F1FD8[nEntry - nKindBase].nY;
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, 0, bTundra ? 0x3D6 : 0x38A, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nBottom, bTundra ? 0x3D5 : 0x389, -1, 0);
}
