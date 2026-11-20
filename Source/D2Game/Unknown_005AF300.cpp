#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2TxtItems.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"

struct D2ObjectControlStrc;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2ObjOperateFnStrc;
struct D2MissilesTxt;

struct D2MissilesTxt { char unk00[0x38]; int dwParam[3]; char unk44[0x52]; short nAnimLen; char unk98[0x10C]; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A380
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall sub_6FC75EB0(D2ObjOperateFnStrc* pOp); // 0x00585E00
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0

void __fastcall sub_0056DDE0_FillRecordAndCall(D2GameStrc* pGame, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, void* pArg8); // 0x0056DDE0
int __fastcall MISSMODE_RadamentDeathAreaEffectCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused); // 0x005AD8F0
int __fastcall MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused); // 0x005AD910
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

// 0x005AF300
int __fastcall MISSMODE_SrvDo18_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxt = 0;
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        pMissilesTxt = &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    if (!pMissilesTxt) return 2;
    const int nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    if (nCurrentFrame == 1)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, MISSILE_GetTargetX(pMissile));
        if (pObject) SUNIT_AttachSound(pObject, 92, 0);
    }
    if (nCurrentFrame == pMissilesTxt->nAnimLen - pMissilesTxt->dwParam[0])
    {
        const int nObjectGUID = MISSILE_GetTargetX(pMissile);
        D2ObjOperateFnStrc op;
        op.pGame = pGame;
        op.hPlayer = 0;
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
        if (pObject)
        {
            op.pObjectregion = (D2ObjectControlStrc*)&pObject->pSeed;
            op.hObject = pObject;
            op.nObjectIdx = pObject->dwClassId;
            sub_6FC75EB0(&op);
        }
        MISSILE_SetTargetY(pMissile, 1);
    }
    if (MISSILE_GetTargetY(pMissile))
    {
        int nFrequency = 2 * pMissilesTxt->dwParam[1];
        nFrequency *= 2;
        if (nFrequency < 1) nFrequency = 1;
        if (!(nCurrentFrame % nFrequency))
        {
            D2CoordStrc coords;
            UNITS_GetCoords(pMissile, &coords);
            const int nRange = pMissilesTxt->dwParam[2];
            D2SeedStrc* pSeed = &pMissile->pSeed;
            coords.nX += ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;
            coords.nY += ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;
            D2CoordStrc returnCoords;
            D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pMissile), &coords, &returnCoords, 1, 1);
            if (pRoom)
            {
                const int nItemLevel = DATATBLS_GetMonsterLevelInArea(DUNGEON_GetLevelIdFromRoom(pRoom), pGame->nDifficulty, pGame->bExpansion);
                D2ItemDropStrc drop;
                memset(&drop, 0, sizeof(drop));
                drop.pUnit = pMissile;
                drop.pSeed = 0;
                drop.pGame = pGame;
                drop.wItemFormat = pGame->wItemFormat;
                drop.nId = DATATBLS_GetItemIdFromItemCode(0x20646C67);
                drop.nSpawnType = 3;
                drop.nX = returnCoords.nX;
                drop.nY = returnCoords.nY;
                drop.pRoom = pRoom;
                drop.wUnitInitFlags = 1;
                drop.nQuality = 2;
                drop.nItemLvl = nItemLevel;
                D2GAME_CreateItemEx_6FC4ED80(pGame, &drop, 0);
            }
        }
    }
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005B0940
int __fastcall MISSMODE_SrvDo19_RadamentDeath(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    const int nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    if (nCurrentFrame > 1 && nCurrentFrame < 25)
    {
        sub_0056DDE0_FillRecordAndCall(pGame, 0x3002, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), (int)pMissile, 124, 1, (void*)MISSMODE_RadamentDeathAreaEffectCallback);
    }
    else if (nCurrentFrame == 1)
    {
        sub_0056DDE0_FillRecordAndCall(pGame, 0x3002, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), (int)pMissile, 124, 1, (void*)MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}
