#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"






extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

inline int UNITS_GetXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}


// 0x004C80D0
static int __stdcall sub_004C80D0_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;

    const int nUnitX = UNITS_GetXInline(pUnit);
    const int nUnitY = UNITS_GetYInline(pUnit);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nDistance = sub_006417F0_GetDistanceToXY(pUnit, *pX, *pY);
    if (nDistance <= 1)
        nDistance = 1;
    if (nDistance > nRange)
    {
        const int nDeltaX = *pX - nUnitX;
        const int nDeltaY = *pY - nUnitY;
        *pX = nUnitX + nDeltaX * nRange / nDistance;
        *pY = nUnitY + nDeltaY * nRange / nDistance;
    }

    nSkillLevel = *pY - nUnitY;
    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, -2), 2);
    int nOffsetY = nUnitX - *pX;
    nOffsetY = D2_MIN(D2_MAX(nOffsetY, -2), 2);

    D2CoordStrc tCoord;
    tCoord.nX = *pX;
    tCoord.nY = *pY;
    int nTries = 3;
    while (nTries)
    {
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), tCoord.nX, tCoord.nY);
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &tCoord, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
        const int nAdjustedX = tCoord.nX;
        const int nAdjustedY = tCoord.nY;
        if (pRoom
            && !COLLISION_CheckAnyCollisionWithPattern(pRoom, nAdjustedX, nAdjustedY, PATH_GetUnitCollisionPattern(pUnit), 0x1C09)
            && D2Common_11025(nUnitX, nUnitY, nAdjustedX, nAdjustedY, pRoom, 0x804)
            && sub_006417F0_GetDistanceToXY(pUnit, nAdjustedX, nAdjustedY) <= nRange)
        {
            *pX = nAdjustedX;
            *pY = nAdjustedY;
            return 1;
        }

        --nTries;
        if (nTries == 2)
        {
            tCoord.nX = *pX + nSkillLevel;
            tCoord.nY = *pY + nOffsetY;
        }
        else if (nTries == 1)
        {
            tCoord.nX = *pX - nSkillLevel;
            tCoord.nY = *pY - nOffsetY;
        }
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
        UNITSND_PlayPlayerSpeech(pUnit, 19);
    return 0;
}

int __fastcall sub_004C80D0_EmitTargetPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pX, int* pY)
{
    return sub_004C80D0_AdjustTargetPosition(nSkillId, pUnit, nSkillLevel, pX, pY);
}
