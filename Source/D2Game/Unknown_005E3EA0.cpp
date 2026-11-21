#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
// build: ob1

struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2RoomCoordListStrc;
struct D2AiParamStrc;
struct D2PlayerDataStrc { char unk00[0xa0]; unsigned char nPathIndex; char unkA1[7]; D2CoordStrc pPath[20]; };
struct D2PetMoveStrc { D2UnitStrc* pUnit; D2UnitStrc* pTarget; int nCounter; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gnPetDirections[8]; // 0x006E34F8
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*, int, int); // 0x00463740
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc*, D2ActiveRoomStrc*, D2RoomCoordListStrc*, int, int*, int*, int); // 0x0054DC40
int __fastcall sub_6FCBDFE0(D2GameStrc*, D2UnitStrc*, D2ActiveRoomStrc*, int, int, int, int); // 0x00554EA0
typedef void (__fastcall* PetIterateCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);
void __fastcall PLAYERPETS_IteratePets(D2GameStrc*, D2UnitStrc*, PetIterateCallback, void*); // 0x00574DE0
D2AiParamStrc* __fastcall sub_005A6190_GetAiParam(D2UnitStrc*); // 0x005A6190
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc*, int, int, unsigned char); // 0x005A6260
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*, int, int); // 0x005DC5C0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
void __fastcall sub_005DE190_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DED90
int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DEDE0
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DEE50
int __fastcall AITACTICS_RunToTargetCoordinatesDeleteAiEvent(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DEEB0
int __fastcall sub_005DEFE0_Escape(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
int __fastcall AITACTICS_WanderToTarget(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF400
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF530
void __fastcall sub_6FCE34B0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*); // 0x005E3900
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc*, int, int); // 0x0061AD30
int __stdcall D2Common_10095(D2ActiveRoomStrc*, int, int); // 0x0061B130
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char); // 0x0063E7A0
void __stdcall sub_0063E7E0_GetDirectionDelta(unsigned char, unsigned int*, unsigned int*); // 0x0063E7E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall sub_00648A20_GetLastPointX(D2DynamicPathStrc*); // 0x00648A20
int __stdcall sub_00648A30_GetLastPointY(D2DynamicPathStrc*); // 0x00648A30
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040
static inline int GetUnitX(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}
static inline int GetUnitY(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}
static inline int GetMonsterId(int nId) {
    if (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount) return -1;
    return nId;
}
// 0x005E3EA0
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nMove, int bRun, int nVelocity, int nRange)
{
    D2UnitStrc* pUnit = pPet;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    int nMode = pOwner->dwAnimMode;
    unsigned int nTargetX = 0;
    unsigned int nTargetY = 0;
    D2PlayerDataStrc* pData = UNITS_GetPlayerData(pOwner);
    int nLastX = sub_00648A20_GetLastPointX(pPath);
    int nLastY = sub_00648A30_GetLastPointY(pPath);
    int nX = GetUnitX(pUnit);
    int nY = GetUnitY(pUnit);
    int nOwnerX = GetUnitX(pOwner);
    int nOwnerY = GetUnitY(pOwner);
    switch (nMove) {
    case 0:
        {
            unsigned char nDirection = UNITS_GetDirectionToCoords(pOwner, nLastX, nLastY);
            nDirection = sub_0063E7A0_GetByteTableEntry(nDirection);
            int nCollision = D2Common_10095(UNITS_GetRoom(pOwner), CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
            for (int i = 0; i < 8; ++i) {
                unsigned int nOffsetX;
                unsigned int nOffsetY;
                sub_0063E7E0_GetDirectionDelta(gnPetDirections[nDirection], &nOffsetX, &nOffsetY);
                nTargetX = nLastX + 8 * nOffsetX;
                nTargetY = nLastY + 8 * nOffsetY;
                if (D2Common_10095(UNITS_GetRoom(pOwner), nTargetX, nTargetY) == nCollision) {
                    sub_005DE190_SetAiParam(pUnit, 0, nVelocity, 40);
                    if (bRun) {
                        if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                        if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nTargetX) / 2, (nY + nTargetY) / 2)) return 1;
                    } else {
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nTargetX) / 2, (nY + nTargetY) / 2)) return 1;
                    }
                }
                nDirection = (nDirection + 1) & 7;
            }
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, 4)) return 1;
            if (bRun && AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nOwnerX) / 2, (nY + nOwnerY) / 2)) return 1;
            if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nOwnerX) / 2, (nY + nOwnerY) / 2)) return 1;
            return AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nOwnerX, nOwnerY);
        }
    case 1:
        {
            if (nMode == 2) {
                sub_005DE190_SetAiParam(pUnit, 0, 0, 100);
                if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nLastX, nLastY)) return 1;
                if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nLastX) / 2, (nY + nLastY) / 2)) return 1;
            }
            int nSpeed;
            if (nVelocity) nSpeed = nVelocity;
            else nSpeed = SEED_RollLimitedRandomNumber(pSeed, 40) + 40;
            unsigned char nIndex = pData->nPathIndex;
            D2AiParamStrc* pAiParam = sub_005A6190_GetAiParam(pUnit);
            int bChanged = 0;
            for (int i = 0; i < 20; ++i) {
                if (!nIndex) nIndex = 19;
                else --nIndex;
                int nTargetY;
                int nTargetX = pData->pPath[nIndex].nX;
                nTargetY = pData->pPath[nIndex].nY;
                if (!nTargetX || !nTargetY || AIUTIL_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY) <= 5) continue;
                sub_005DE190_SetAiParam(pUnit, 0, nSpeed, 100);
                if (bRun) {
                    if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, nTargetX, nTargetY)) return 1;
                } else {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                sub_005DE190_SetAiParam(pUnit, 15, nSpeed, 100);
                if (bRun) {
                    if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                } else {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                }
                if (!bChanged) {
                    bChanged = 1;
                    sub_005A6260_SetAiParamFields(pAiParam, 1, nSpeed, 100);
                    if (bRun) {
                        if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                    } else {
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                    }
                }
            }
            int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner) / 4;
            if (nDistance < 4) nDistance = 4;
            sub_005DE190_SetAiParam(pUnit, 0, 15, 0);
            if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, nDistance)) return 1;
            break;
        }
    case 2:
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 10) {
            if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, SEED_RollLimitedRandomNumber(pSeed, 3) + 3)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            sub_005DE190_SetAiParam(pUnit, 0, 0, 40);
            if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nLastX, nLastY)) return 1;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return 1;
    case 3:
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
            D2RoomCoordListStrc* pCoords = D2Common_10096(pRoom, CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
            int nSpawnX;
            int nSpawnY;
            if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, pCoords, GetMonsterId(363), &nSpawnX, &nSpawnY, 0)) break;
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, nSpawnX, nSpawnY);
            if (!pRoom) break;
            if (!sub_6FCBDFE0(pGame, pUnit, pRoom, nSpawnX, nSpawnY, 0, 0)) break;
            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlagEx |= 0x10000;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return 1;
        }
    case 4:
        {
            D2PetMoveStrc args;
            args.pUnit = pUnit;
            args.nCounter = 0;
            PLAYERPETS_IteratePets(pGame, pOwner, sub_6FCE34B0, &args);
            if (args.nCounter >= 1) {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                if (sub_005DEFE0_Escape(pGame, pUnit, pOwner, nRange, 1)) return 1;
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, nRange)) return 1;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return 1;
        }
    case 5:
        sub_005DE190_SetAiParam(pUnit, 7, 0, 0);
        if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, nRange)) return 1;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        if (sub_005DEFE0_Escape(pGame, pUnit, pOwner, nRange, 1)) return 1;
        sub_005DE190_SetAiParam(pUnit, 0, 0, 40);
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nLastX, nLastY)) return 1;
        break;
    }
    return 0;
}

#include "gen/data/Source/D2Game/Unknown_005E3EA0.inc"
struct D2UnitStrc;
