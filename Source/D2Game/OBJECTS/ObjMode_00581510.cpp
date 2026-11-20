#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"

struct D2ObjectControlStrc;
union D2SeedStrc;


struct D2ShrinesTxt
{
    unsigned char bCode;
    char unk0x01[0x0F];
    unsigned char nResetTimeInMins;
};


struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
    unsigned char InteractType;
    unsigned char nPortalFlags;
    unsigned short unk0x06;
    D2ShrinesTxt* pShrineTxt;
    int dwOperateGUID;
};



struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};


struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

typedef void(__fastcall* ObjShrineFunction)(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

struct D2ShrineTableStrc
{
    ObjShrineFunction pfShrineCallback;
    int unk0x04;
    int unk0x08;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

struct D2GSPacketSrv63
{
    unsigned char nHeader;
    unsigned char dwUnitId[4];
    unsigned char pData[16];
};

typedef int(__stdcall* FARPROC)();
typedef int(__fastcall* ObjOperateFunction)(D2ObjOperateFnStrc* pOp);
typedef void(__fastcall* PlayerPetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);         // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern const D2ShrineTableStrc sgcptShrineChart[];                                                    // 0x006E1850
extern ObjOperateFunction gpObjOperateFnTable_00732D18[];                                                   // 0x00732D18

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall sub_0053D960_SendPacket0x63(D2ClientStrc* pClient, D2GSPacketSrv63* pPacket);               // 0x0053D960
void __fastcall QUESTS_HellPortalActChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nLevelId, D2UnitStrc* pObject); // 0x00546AC0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
unsigned char __fastcall sub_00552AA0_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord);                    // 0x00552AA0
unsigned char __fastcall sub_00552AB0();                                                    // 0x00552AB0
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit);                                            // 0x00552B10
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID);      // 0x00554120
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, int a5); // 0x00555DA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2);                                     // 0x00558200
unsigned int __fastcall ITEMS_GetHealthPotionDropCode(D2UnitStrc* pUnit);                                   // 0x00558450
unsigned int __fastcall ITEMS_GetManaPotionDropCode(D2UnitStrc* pUnit);                                     // 0x005584C0
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);  // 0x00558D90
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __fastcall sub_005550B0_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile);                // 0x005550B0
int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* pGame, D2UnitStrc* pPlayer);                          // 0x0055F140
void __fastcall D2GAME_SHRINES_Refill_6FC76730(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);   // 0x005828E0
void __fastcall sub_00584820_ClearSteegStoneGUID(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00584820
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, short nState); // 0x005852E0
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality);       // 0x00585B90
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit);                                         // 0x00578C20
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit);                                                        // 0x006205A0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag);                    // 0x00622300
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                // 0x0063C1E0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboursRooms); // 0x0064E7B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);             // 0x0065C310
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo);                // 0x00660E00
void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, unsigned short wField);                // 0x00660EC0

#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1
#define EVENTTYPE_ACTIVESTATE 5
#define EVENTTYPE_FREEHOVER 6
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAG_TARGETABLE 0x00000002
#define UNITFLAG_HASTXTMSG 0x00000100
#define STAT_HITPOINTS 6
#define STAT_MAXHP 7
#define STAT_MANA 8
#define STATE_FREEZE 1
#define STATE_POISON 2
#define ITEMQUAL_MAGIC 4
#define QFLAG_REWARDGRANTED 0
#define QFLAG_PRIMARYGOALDONE 13
#define OBJECT_STONETHETA 22
#define OBJECT_OBELISK 80
#define OBJECT_DESERT_OBELISK 90
#define OBJECT_PORTAL_TO_DURIELS_LAIR 100
#define OBJECT_JERHYN_PLACEHOLDER1 121
#define OBJECT_JERHYN_PLACEHOLDER2 122
#define OBJECT_ORIFICE 152
#define OBJECT_STASH 267
#define OBJECT_GUILD_PORTAL 377
#define LEVEL_DURIELSLAIR 73

inline D2HoverTextStrc* UNIT_GetHoverText(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->pHoverText;
    }

    return 0;
}

inline void UNIT_SetHoverText(D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText)
{
    if (pUnit)
    {
        pUnit->pHoverText = pHoverText;
    }
}

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline D2WaypointDataStrc* PLAYER_GetWaypointFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
}

// 0x00581510
void __fastcall sub_6FC74B40(D2GameStrc* pGame, D2UnitStrc* pObject)
{

    unsigned char nLeft = pObject->pObjectData->InteractType;
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pObject);
    if (nLeft / pObjectsTxtRecord->dwParm[2] >= sub_00552AB0())
    {
        D2_ASSERT(nLeft / pObjectsTxtRecord->dwParm[2] < sub_00552AB0(), 220);
    }
    else
    {
        const unsigned char nNewLeft = nLeft + 1;
        pObject->pObjectData->InteractType = nNewLeft;

        if (sub_00552AA0_GetRegenerateMax(pObjectsTxtRecord) - nLeft < 0)
        {
            pObject->pObjectData->InteractType = sub_00552AA0_GetRegenerateMax(pObjectsTxtRecord);
            D2_ASSERT(sub_00552AA0_GetRegenerateMax(pObjectsTxtRecord) - nLeft >= 0, 227);
        }
        else
        {
            const unsigned char nMax = sub_00552AA0_GetRegenerateMax(pObjectsTxtRecord);
            if (nNewLeft <= nMax && !(nNewLeft % (unsigned char)(nMax / sub_00552AB0())))
            {
                UNITS_ChangeAnimMode(pObject, sub_00552AB0() - nNewLeft / pObjectsTxtRecord->dwParm[2]);
            }

            UNITROOM_RefreshUnit(pObject);
            pObject->dwFlags |= UNITFLAG_DOUPDATE;
        }
    }
}

// 0x00581EB0
int __fastcall OBJECTS_OperateFunction16_TrapDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->hObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(pOp->hObject);
    const int nSizeY = UNITS_GetUnitSizeY(pOp->hObject);

    switch (!pOp->hObject ? 0 : pOp->hObject->dwAnimMode)
    {
    case OBJMODE_NEUTRAL:
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2UnitStrc* hUnit = UNITS_GetRoom(pOp->hObject)->pUnitFirst;
        while (hUnit && hUnit->dwUnitType != UNIT_TILE)
        {
            hUnit = hUnit->ptRoomNext;
        }

        D2_ASSERT(hUnit, 1038);

        sub_005550B0_WarpPlayer(pOp->pGame, pOp->hPlayer, hUnit);
        return 1;
    }
    }

    return 1;
}

// 0x00583C70
int __fastcall OBJECTS_OperateFunction02_Shrine(D2ObjOperateFnStrc* pOp, int nOperate)
{

    D2UnitStrc* pPlayer = pOp->hPlayer;
    D2UnitStrc* pObject = pOp->hObject;
    D2ObjectDataStrc* pObjectData = pObject->pObjectData;

    if (pObjectData->dwOperateGUID)
    {
        return 0;
    }

    if (pObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        return 0;
    }

    pObjectData->dwOperateGUID = (!pPlayer ? -1 : pPlayer->dwUnitId) + 1;
    UNITROOM_RefreshUnit(pObject);

    pObject->dwFlags |= UNITFLAG_DOUPDATE;
    UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);

    D2HoverTextStrc* pOldHoverText = UNIT_GetHoverText(pOp->hObject);
    if (pOldHoverText)
    {
        CHAT_FreeHoverMsg(pOp->pGame->pMemoryPool, pOldHoverText);
    }

    char szText[20];
    wsprintfA(szText, gszFormatD_006D57BC, (unsigned short)(pOp->hObject->pObjectData->InteractType + 3683));

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(pOp->pGame->pMemoryPool, szText, pOp->pGame->dwGameFrame);
    if (pHoverText)
    {
        UNIT_SetHoverText(pOp->hObject, pHoverText);
        UNITROOM_RefreshUnit(pOp->hObject);
        SetUnitFlagMask(pOp->hObject, UNITFLAG_HASTXTMSG);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_FREEHOVER, pOp->pGame->dwGameFrame + 300, 0, 0);
    }

    D2ShrinesTxt* pShrinesTxtRecord = UNITS_GetShrineTxtRecordFromObject(pObject);

    const int nId = pShrinesTxtRecord->bCode;
    if (nId >= 0 && nId < gnShrineTableCount_00732EAC && sgcptShrineChart[nId].pfShrineCallback)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgcptShrineChart[nId].pfShrineCallback), 2653);
        sgcptShrineChart[nId].pfShrineCallback(pOp, pShrinesTxtRecord);
    }
    else
    {
        D2GAME_SHRINES_Refill_6FC76730(pOp, pShrinesTxtRecord);
    }

    if (pShrinesTxtRecord->nResetTimeInMins)
    {
        EVENT_SetEvent(pOp->pGame, pObject, EVENTTYPE_ACTIVESTATE, 1200 * pShrinesTxtRecord->nResetTimeInMins + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    if (pObject->dwAnimMode == OBJMODE_OPERATING)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        if (!pObjectsTxtRecord->nCycleAnim[1] && pObjectsTxtRecord->nMode[2])
        {
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }

    return 1;
}

// 0x00584420
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult)
{

    *pResult = 1;

    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, nObjectType, nObjectGUID);
    const int nClassId = !pObject ? -1 : pObject->dwClassId;
    D2ObjectsTxt* pObjectTxtRecord = UNITS_GetObjectTxtRecordFromObject(pObject);

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        int nInteractType;
        if (SUNIT_GetInteractInfo(pPlayer, &nInteractType, &nObjectGUID) || UNITS_GetPlayerData(pPlayer)->bBusy)
        {
            return 0;
        }

        D2InventoryStrc* pInventory = pPlayer->pInventory;
        if (INVENTORY_GetCursorItem(pInventory) && nClassId != OBJECT_STASH)
        {
            return 0;
        }
    }

    if (pObjectTxtRecord->nOperateFn < 101 && nClassId != OBJECT_JERHYN_PLACEHOLDER1 && nClassId != OBJECT_JERHYN_PLACEHOLDER2 && nClassId != OBJECT_STONETHETA
        && gpObjOperateFnTable_00732D18[pObjectTxtRecord->nOperateFn])
    {
        D2ObjOperateFnStrc pObjOperate;
        pObjOperate.pGame = pGame;
        pObjOperate.hObject = pObject;
        pObjOperate.hPlayer = pPlayer;
        pObjOperate.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
        pObjOperate.nObjectIdx = nClassId;
        return gpObjOperateFnTable_00732D18[pObjectTxtRecord->nOperateFn](&pObjOperate);
    }

    D2_ASSERT(pObjectTxtRecord->nOperateFn < 101, 3320);
    return 0;
}

// 0x005845D0
void __fastcall sub_005845D0_UpdateDoorCollisionMode(D2GameStrc* pGame, D2UnitStrc* pUnused, int nObjectGUID)
{

    D2UnitStrc* hObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, nObjectGUID);
    D2_ASSERT(hObject, 3383);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(hObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(hObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(hObject);
    const int nSizeY = UNITS_GetUnitSizeY(hObject);

    const int nAnimMode = hObject->dwAnimMode;
    switch (nAnimMode)
    {
    case OBJMODE_NEUTRAL:
        COLLISION_CheckMaskWithSizeXY(pRoom, pCoord.nX, pCoord.nY, nSizeX, nSizeY, 0x8180);
        break;

    case OBJMODE_OPENED:
    case OBJMODE_SPECIAL3:
        if (!COLLISION_CheckMaskWithSizeXY(pRoom, pCoord.nX, pCoord.nY, nSizeX, nSizeY, 0x8180))
        {
            if (nAnimMode != OBJMODE_OPENED)
            {
                UNITS_ChangeAnimMode(hObject, OBJMODE_OPENED);
            }
        }
        else
        {
            if (nAnimMode != OBJMODE_SPECIAL3)
            {
                UNITS_ChangeAnimMode(hObject, OBJMODE_SPECIAL3);
            }
        }
        break;
    }
}

// 0x00584750
int __fastcall OBJECTS_OperateFunction46_HellGatePortal(D2ObjOperateFnStrc* pOp, int nOperate)
{

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED))
    {
        QUESTS_HellPortalActChange(pOp->pGame, pOp->hPlayer, nLevelId, pOp->hObject);
        if (nLevelId == LEVEL_DURANCEOFHATELEV3)
        {
            D2WaypointDataStrc* pWaypointFlags = PLAYER_GetWaypointFlags(pOp->pGame, pOp->hPlayer);
            unsigned short nWpNo;
            if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_THEPANDEMONIUMFORTRESS, &nWpNo))
            {
                WAYPOINTS_ActivateWaypoint(pWaypointFlags, nWpNo);
            }

            LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, LEVEL_THEPANDEMONIUMFORTRESS, 0);
        }
    }

    return 0;
}

// 0x00584D00
int __fastcall OBJECTS_OperateFunction43_DurielPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{

    D2_ASSERT((pOp->hPlayer ? pOp->hPlayer->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 4019);

    const unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pOp->hObject) | 5;
    UNITS_SetObjectPortalFlags(pOp->hObject, nPortalFlags);

    int nLevel = 0;
    D2UnitStrc* pObject = pOp->hObject;
    if (pObject)
    {
        switch (pObject->dwClassId)
        {
        case OBJECT_PORTAL_TO_DURIELS_LAIR:
            nLevel = LEVEL_DURIELSLAIR;
            break;

        case OBJECT_GUILD_PORTAL:
            nLevel = pObject->pObjectData->InteractType;
            break;
        }
    }

    int nX = 0;
    int nY = 0;
    const unsigned char bAct = DRLG_GetActNoFromLevelId(nLevel);
    D2_ASSERT(bAct < 5, 4043);

    D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pOp->pGame->pAct[bAct], nLevel, 0, &nX, &nY, UNITS_GetUnitSizeX(pOp->hPlayer));
    D2_ASSERT(pRoom, 4045);

    D2CoordStrc pCoord;
    pCoord.nX = nX;
    pCoord.nY = nY;

    pRoom = COLLISION_GetFreeCoordinates(pRoom, &pCoord, UNITS_GetUnitSizeX(pOp->hPlayer), 0x1C09, 0);
    if (pRoom)
    {
        D2_ASSERT(sub_6FCBDFE0(pOp->pGame, pOp->hPlayer, pRoom, pCoord.nX, pCoord.nY, 0, 0), 4057);
    }

    return 0;
}

// 0x00584E30
int __fastcall OBJECTS_OperateFunction23_Waypoint(D2ObjOperateFnStrc* pOp, int nOperate)
{

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
    D2WaypointDataStrc* pWaypointFlags = PLAYER_GetWaypointFlags(pOp->pGame, pOp->hPlayer);
    unsigned short nWpNo;
    if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &nWpNo))
    {
        WAYPOINTS_ActivateWaypoint(pWaypointFlags, nWpNo);
    }

    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    else if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_OPENED || UNIT_GetAnimMode(pOp->hObject) == OBJMODE_OPERATING)
    {
        if (!PLAYER_IsBusy(pOp->hPlayer))
        {
            D2GSPacketSrv63 packet63;
            packet63.nHeader = 0x63;
            const int nUnitId = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
            *(int*)packet63.dwUnitId = nUnitId;
            WAYPOINTS_ValidateAndCopyWaypointData(pWaypointFlags, (D2WaypointDataStrc*)packet63.pData);

            D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, ".\\OBJECTS\\ObjMode.cpp", 4126);
            sub_0053D960_SendPacket0x63(pClient, &packet63);

            SUNIT_SetInteractInfo(pOp->hPlayer, UNIT_OBJECT, !pOp->hObject ? -1 : pOp->hObject->dwUnitId);
        }
    }

    return 1;
}

// 0x00585120
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseMana(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    const int nNewValue = (nValue << 8) + STATLIST_GetMaxManaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewValue, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXMANA, nNewValue, 0);
    return 1;
}

// 0x005851E0
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseHitpoints(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    const int nNewValue = (nValue << 8) + STATLIST_GetMaxLifeFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewValue, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nNewValue, 0);
    return 1;
}

// 0x005854D0
void __fastcall sub_6FC79B50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{

    if (pObject)
    {
        const int nClassId = pObject->dwClassId;
        if ((unsigned short)nClassId == OBJECT_OBELISK || (unsigned short)nClassId == OBJECT_DESERT_OBELISK)
        {
            const int nObjectGUID = pObject->dwUnitId;
            OBJMODE_MainObeliskHandler(pGame, !pUnit ? -1 : pUnit->dwUnitId, nObjectGUID, 0, 2);
        }
        else if ((unsigned short)nClassId == OBJECT_STEEG_STONE)
        {
            sub_00584820_ClearSteegStoneGUID(pGame, pUnit, pObject);
        }
        else if ((unsigned short)nClassId == OBJECT_ORIFICE)
        {
            UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
        }
    }

    SUNIT_ResetInteractInfo(pUnit);
}

// 0x005856A0
void __fastcall OBJMODE_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pUnit2, void* pUnitHealed)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit2, STAT_HITPOINTS, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit2);
    if (nHitpoints < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit2, STAT_HITPOINTS, nMaxHp, 0);
        *(unsigned char*)pUnitHealed = 1;
    }

    D2StatListStrc* pPoisonStatList = STATLIST_GetStatListFromUnitAndState(pUnit2, STATE_POISON);
    if (pPoisonStatList)
    {
        D2Common_10474(pUnit2, pPoisonStatList);
        STATLIST_FreeStatList(pPoisonStatList);
    }

    D2StatListStrc* pFreezeStatList = STATLIST_GetStatListFromUnitAndState(pUnit2, STATE_FREEZE);
    if (pFreezeStatList)
    {
        D2Common_10474(pUnit2, pFreezeStatList);
        STATLIST_FreeStatList(pFreezeStatList);
    }

    D2GAME_NPC_RemoveStates_6FCCAF30(pUnit2);
}

// 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality)
{

    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nItemId != -1)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pUnit, &pCoord);

        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = nItemId;
            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pGame;
            itemDrop.nSpawnType = 3;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = nItemQuality;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

// 0x00585E00
void __fastcall sub_6FC75EB0(D2ObjOperateFnStrc* pOp)
{

    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        unsigned int dwCode = ITEMS_GetHealthPotionDropCode(pOp->hObject);
        D2_ASSERT(dwCode, 1428);

        pOp->hObject->dwDropItemCode = dwCode;

        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);

        dwCode = ITEMS_GetManaPotionDropCode(pOp->hObject);
        D2_ASSERT(dwCode, 1433);

        pOp->hObject->dwDropItemCode = dwCode;

        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);

        if (pObjectsTxtRecord->nMode[1])
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
        }

        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);
    }
}

// 0x00586850
void __fastcall sub_6FC78340(D2GameStrc* pGame, D2UnitStrc* pUnit)
{

    D2ObjOperateFnStrc op;
    op.pGame = pGame;
    op.hObject = pUnit;
    op.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pUnit));
    op.hPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, OBJECTS_GetUnitIdFromTimerArg(pUnit));
    OBJMODE_DropFromChestTCWithQuality(&op, 0);
}

#include "gen/data/Source/D2Game/OBJECTS/ObjMode_00581510.inc"
