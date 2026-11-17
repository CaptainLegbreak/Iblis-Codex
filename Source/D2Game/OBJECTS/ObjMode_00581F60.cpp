#include "D2Game.h"

#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ObjOperateFnStrc;
struct D2ObjectDataStrc;
struct D2PlayerDataStrc;
struct D2PortalQuestStrc;

struct D2GameStrc
{
    char unk00[0x1C];
    void* pMemoryPool;
    char unk20[0x4D];
    unsigned char nDifficulty;
    char unk6E[2];
    int bExpansion;
    char unk74[0x34];
    int dwGameFrame;
    char unkAC[0x10];
    D2DrlgActStrc* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    unsigned char unk_18[0xD0];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };

struct D2CoordStrc { int nX; int nY; };

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    int unk0C;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char unk00[0xD8];
    union
    {
        struct
        {
            unsigned int dwFrameCnt[8];
        };
        struct
        {
            unsigned char unk_D8[0x4];
            unsigned int dwFrameCnt3;
        };
    };
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc*, D2CoordStrc*); // 0x00620870
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc*); // 0x006205A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*, D2ActiveRoomStrc***, unsigned int*); // 0x00619790
void __fastcall SUNIT_WarpPlayer(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x005550B0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0

struct D2ObjectDataStrc { D2ObjectsTxt* pObjectTxt; unsigned char InteractType; unsigned char nPortalFlags; unsigned short unk06; };

struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };

struct D2PortalQuestStrc { int nQuest; int nExpansionQuest; };

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);
extern const char gszObjModeSourceFile_006E1970[]; // 0x006E1970
int __fastcall PLAYER_HasHostilePlayer(D2GameStrc*, D2UnitStrc*); // 0x00535B10
D2UnitStrc* __fastcall sub_00553720_GetOtherPortal(D2GameStrc*, D2UnitStrc*); // 0x00553720
void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc*, D2UnitStrc*); // 0x0058CF50
D2PortalQuestStrc* __fastcall DATATBLS_GetLevelDefRecord(int); // 0x0061E470
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer); // 0x005353F0
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nSourceLevelId, int nDestinationLevelId, D2UnitStrc* pPlayer); // 0x00543B90
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit); // 0x00552B10
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B6C0
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

// 0x00581F60
int __fastcall sub_00581F60_OperateWarpObject(D2ObjOperateFnStrc* pOp)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    D2CoordStrc coords;
    UNITS_GetCoords(pOp->pObject, &coords);
    UNITS_GetUnitSizeX(pOp->pObject);
    UNITS_GetUnitSizeY(pOp->pObject);
    switch (!pOp->pObject ? 0 : pOp->pObject->dwAnimMode)
    {
    case 0:
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        {
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxt->dwFrameCnt3 >> 8) + 1, 0, 0);
        }
        break;
    case 2:
        {
            D2UnitStrc* pTile = pRoom->pUnitFirst;
            while (pTile)
            {
                if ((!pTile ? 6 : pTile->dwUnitType) == 5) goto found;
                pTile = pTile->pRoomNext;
            }
            D2ActiveRoomStrc** ppRooms;
            unsigned int nRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            unsigned int i = 0;
            if (i >= nRooms) goto done;
            do
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = ppRooms[i]->pUnitFirst;
                    while (pTile)
                    {
                        if ((!pTile ? 6 : pTile->dwUnitType) == 5) goto found;
                        pTile = pTile->pRoomNext;
                    }
                }
            } while (++i < nRooms);
            return 1;
        found:
            SUNIT_WarpPlayer(pOp->pGame, pOp->pPlayer, pTile);
            return 1;
        }
        break;
    }
done:
    return 1;
}

// build: context UNIT_GetId
static __forceinline int UNIT_GetId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }

// build: context UNIT_GetType
static __forceinline int UNIT_GetType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

// build: context UNIT_GetClass
static __forceinline int UNIT_GetClass(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwClassId; }

// build: context PLAYER_GetQuestFlags
static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer) {
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00584870
int __fastcall sub_00584870_OperatePortal(D2ObjOperateFnStrc* pOp)
{
    if (PLAYER_IsBusy(pOp->pPlayer))
        return 0;
    if (PLAYER_HasHostilePlayer(pOp->pGame, pOp->pPlayer)
        && UNIT_GetId(pOp->pPlayer) != OBJECTS_GetUnitIdFromTimerArg(pOp->pObject))
        return 0;
    if (PLAYERLIST_GetHostileDelay(pOp->pPlayer, 0) + 5000 > GetTickCount()) {
        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        return 0;
    }
    const int nOwnerId = OBJECTS_GetUnitIdFromTimerArg(pOp->pObject);
    D2UnitStrc* pPlayer = pOp->pPlayer;
    if (nOwnerId != -1 && nOwnerId != UNIT_GetId(pPlayer)) {
        if (SUNIT_GetPartyId(pPlayer) == -1) {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }
        D2UnitStrc* pOwner = SUNIT_GetServerUnit(pOp->pGame, 0, nOwnerId);
        if (pOwner && SUNIT_GetPartyId(pPlayer) != SUNIT_GetPartyId(pOwner)) {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }
    }
    D2_ASSERT((pOp->pPlayer ? pOp->pPlayer->dwUnitType : 6) == 0, 0xED8);
    D2UnitStrc* pOtherPortal = sub_00553720_GetOtherPortal(pOp->pGame, pOp->pObject);
    if (pOtherPortal && pOtherPortal->dwUnitType != 2) pOtherPortal = 0;
    if (UNITS_GetRoom(pOp->pObject)) {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
        if (!pQuestFlags) {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }
        const int nLevelId = pOp->pObject->pObjectData->InteractType;
        D2PortalQuestStrc* pPortalQuest = DATATBLS_GetLevelDefRecord(nLevelId);
        if (!pPortalQuest) {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }
        if (pOp->nObjectIdx == 59) {
            const int nPortalId = PLAYER_GetUniqueIdFromPlayerData(pOp->pPlayer);
            if (nPortalId != UNIT_GetId(pOp->pObject) && pOtherPortal && nPortalId != sub_00451F50_GetUnitGUID(pOtherPortal)) {
                if (pOp->pGame->bExpansion) {
                    if (pPortalQuest->nExpansionQuest > 0 && !QUESTRECORD_GetQuestState(pQuestFlags, pPortalQuest->nExpansionQuest, 0)) {
                        SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
                        return 0;
                    }
                } else if (pPortalQuest->nQuest > 0 && !QUESTRECORD_GetQuestState(pQuestFlags, pPortalQuest->nQuest, 0)) {
                    SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
                    return 0;
                }
            }
        }
    }
    D2ActiveRoomStrc* pRoom;
    D2CoordStrc coords;
    if (!pOtherPortal) {
        const int nLevelId = pOp->pObject->pObjectData->InteractType;
        int nX, nY;
        pRoom = DUNGEON_FindActSpawnLocationEx(pOp->pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)], nLevelId, 0, &nX, &nY, 3);
        coords.nX = nX; coords.nY = nY;
    } else {
        coords.nX = CLIENTS_GetUnitX(pOtherPortal);
        coords.nY = CLIENTS_GetUnitY(pOtherPortal);
        pRoom = UNITS_GetRoom(pOtherPortal);
    }
    unsigned char nFlags = UNITS_GetObjectPortalFlags(pOp->pObject) | 5;
    UNITS_SetObjectPortalFlags(pOp->pObject, nFlags);
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pOp->pPlayer))) {
        QUESTS_ChangeLevel(pOp->pGame, DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->pPlayer)), DUNGEON_GetLevelIdFromRoom(pRoom), pOp->pPlayer);
    }
    pRoom = COLLISION_GetFreeCoordinates(pRoom, &coords, UNITS_GetUnitSizeX(pOp->pPlayer), 0x1C09, 0);
    if (!pRoom)
        return 0;
    int nX = coords.nX, nY = coords.nY;
    D2_ASSERT(sub_6FCBDFE0(pOp->pGame, pOp->pPlayer, pRoom, nX, nY, 0, 0), 0xF52);
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pOp->pPlayer, gszObjModeSourceFile_006E1970, 0xF54);
    SUNIT_AttachSound(pOp->pPlayer, 8, 0);
    sub_6FC817D0(pOp->pGame, pOp->pPlayer, 0, 2, nX + 5, nY + 5, 0);
    D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, UNIT_GetType(pOp->pPlayer), UNIT_GetId(pOp->pPlayer), 1, nX + 5, nY + 5, 0, 0);
    const int nClassId = UNIT_GetClass(pOp->pObject);
    if (pOtherPortal && (unsigned short)nClassId != 60) {
        if (PLAYER_GetUniqueIdFromPlayerData(pOp->pPlayer) == pOtherPortal->dwUnitId) {
            D2UnitStrc* pObject = pOp->pObject;
            pRoom = UNITS_GetRoom(pObject);
            DUNGEON_AllocDrlgDelete(pRoom, 2, UNIT_GetId(pOp->pObject));
            SUNIT_RemoveUnit(pOp->pGame, pOp->pObject);
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
            ACT5Q5_OnPortalClosed(pOp->pGame, pOtherPortal);
            pRoom = UNITS_GetRoom(pOtherPortal);
            DUNGEON_AllocDrlgDelete(pRoom, 2, pOtherPortal->dwUnitId);
            SUNIT_RemoveUnit(pOp->pGame, pOtherPortal);
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
        }
    } else if (pOp->pObject && pOp->pObject->dwAnimMode == 1) {
        D2ObjectsTxt* pRecord = DATATBLS_GetObjectsTxtRecord((unsigned short)nClassId);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    const int nFrame = pOp->pGame->dwGameFrame + 75;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pOp->pGame->pMemoryPool, 2, nFrame, 0, UNIT_GetType(pOp->pPlayer));
    if (pStatList) {
        EVENT_SetEvent(pOp->pGame, pOp->pPlayer, 12, nFrame, 0, 0);
        STATES_ToggleState(pOp->pPlayer, 102, 1);
        STATLIST_SetState(pStatList, 102);
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pOp->pPlayer, pStatList, 1);
    }
    return 0;
}
