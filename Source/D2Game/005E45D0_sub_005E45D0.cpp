struct D2GameStrc;
struct D2AiTickParamStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc { char unk_00[0xC]; int nXPos; int nYPos; };
struct D2UnitStrc { int dwUnitType; char dwClassId[0xC]; int dwAnimMode; char unk_14[0x18]; union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; }; };
struct D2PlayerDataStrc { char unk_00[0x148]; int nX; int nY; };
int __fastcall PLAYERPETS_GetTotalPetCount(D2UnitStrc*); // 0x00574F40
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*, int, int); // 0x005DC5C0
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3EA0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
int __stdcall sub_0061B130_GetCollision(D2ActiveRoomStrc*, int, int); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10
unsigned int __stdcall sub_00648A20_GetLastPointX(D2DynamicPathStrc*); // 0x00648A20
unsigned int __stdcall sub_00648A30_GetLastPointY(D2DynamicPathStrc*); // 0x00648A30
static __forceinline int GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}
static __forceinline int GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}
// 0x005E45D0
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int bCombat, D2AiTickParamStrc* pAiTickParam, int bSkipIdle, int nRange)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nMode = pOwner->dwAnimMode;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOwner);
    int nOwnerCollision;
    int nUnitCollision;
    int nFirstX;
    int nFirstY;
    unsigned int nLastX;
    unsigned int nLastY;
    int nMove;
    nRange += PLAYERPETS_GetTotalPetCount(pOwner) >> 1;
    if (nRange > 36) nRange = 36;
    if (nDistance <= 1 && nMode == 1 && !bCombat)
        return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 5, 0, 0, nRange);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (nDistance > 80)
            return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, nRange);
        goto ReturnZero;
    }
    nOwnerCollision = sub_0061B130_GetCollision(UNITS_GetRoom(pOwner), GetUnitX(pOwner), GetUnitY(pOwner));
    nUnitCollision = sub_0061B130_GetCollision(UNITS_GetRoom(pUnit), GetUnitX(pUnit), GetUnitY(pUnit));
    nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);
    nLastX = sub_00648A20_GetLastPointX(pPath);
    nLastY = sub_00648A30_GetLastPointY(pPath);
    nMove = 2;
    if (nMode == 2 || nMode == 6 || nMode == 3) nMove = 0;
    if (nFirstX != nLastX && nFirstY != nLastY) nMove = 0;
    if (nOwnerCollision != nUnitCollision) nMove = 1;
    if (nDistance > nRange) nMove = 1;
    if (nDistance > 50) nMove = 3;
    if (AIUTIL_GetDistanceToCoordinates(pUnit, pPlayerData->nX, pPlayerData->nY) < 28)
    {
        if ((nMove == 1 && nDistance < 30) || nMove == 2) nMove = 4;
    }
    if (bSkipIdle && nMove == 2)
    {
ReturnZero:
        return 0;
    }
    return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, nMove, 0, 0, nRange);
}
