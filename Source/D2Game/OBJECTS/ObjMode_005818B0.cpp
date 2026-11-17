#include "D2Game.h"

#define UNIT_OBJECT 2
#define UNITFLAGEX_TELEPORTED 0x10000
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_TILE 5
#define PLRMODE_DEAD 17
#define MONMODE_DEAD 12
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJECT_EXPLODINGBARREL 11
#define UNITFLAG_TARGETABLE 0x00000002
#define EVENTTYPE_ENDANIM 1
struct D2ObjectControlStrc;
struct D2ObjectDataStrc;
struct D2ObjOperateFnStrc;
struct D2DrlgCoordsStrc;
struct D2ObjOperateStrc;
struct D2SeedStrc;
struct D2ItemsTxt;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ShrineTableStrc;
struct D2GSPacketSrv58;
struct D2ObeliskPowerUpStrc;

struct D2ObjectDataStrc
{
    int unk00;
    unsigned char InteractType;
    unsigned char nPortalFlags;
    unsigned short unk0x06;
    D2ShrinesTxt* pShrineTxt;
    int dwOperateGUID;
};

struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    union
    {
        struct
        {
            char unk0x08[0x58];
        };
        struct
        {
            unsigned char unk_08[0x4];
            int dwUnitId;
            int dwAnimMode;
            D2ObjectDataStrc* pObjectData;
            unsigned char unk_18[0x8];
            D2SeedStrc pSeed;
        };
        struct
        {
            unsigned char unk_08_2[0x8];
            unsigned int mode;
        };
    };
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
    unsigned char unk_CC[0x8];
    unsigned int lastOperateTick;
    unsigned char unk_D8[0x10];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char pad00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char pad00[0xA8];
    int dwGameFrame;
};

struct D2CoordStrc
{
    union
    {
        int nX;
        int x;
    };
    union
    {
        int nY;
        int y;
    };
};

struct D2ObjectsTxt
{
    char pad00[0xD8];
    union
    {
        struct
        {
            unsigned int dwFrameCnt[8];
        };
        struct
        {
            unsigned char unk_D8[0x4];
            unsigned int dwFrameCnt1;
        };
    };
    unsigned char unk_F8[0x6F];
    unsigned char nSubClass;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall UNITS_GetDistanceToOtherUnit(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

struct D2ShrinesTxt
{
    unsigned char nCode;
    char unk0x01[0x03];
    int dwArg0;
    int dwArg1;
    int dwDurationInFrames;
};

void __fastcall D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char a6, int nAnimMode); // 0x0053B470
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall sub_6FC3F550(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D900

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

extern "C" const char gszObjModeSourceFile_006E1970[]; // 0x006E1970
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
static __declspec(noinline) void sub_00581B50_TeleportToUnit(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ActiveRoomStrc* pRoom);

struct D2ObjOperateStrc { D2GameStrc* game; D2UnitStrc* object; D2UnitStrc* player; };

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc*,D2CoordStrc*); // 0x00620870
unsigned int __stdcall sub_00620510(D2UnitStrc*); // 0x00620510
unsigned int __stdcall sub_006205A0(D2UnitStrc*); // 0x006205A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall sub_0055F140(D2GameStrc*,D2UnitStrc*); // 0x0055F140
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
void __stdcall UNITS_RefreshInventory(D2UnitStrc*); // 0x00623830
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc*,D2ActiveRoomStrc*,int,int); // 0x00620A70
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc*,int,int,unsigned int,unsigned int,unsigned short); // 0x0064D800
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    unsigned char unk_84[0x38];
    unsigned int dwUpgradeCode;
    unsigned char unk_C0[0x62];
    unsigned char nSubType;
    unsigned char unk_123[0x1];
};

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pLastItem); // 0x0063CD80
int __stdcall SUNIT_Dummy_00582AC0(D2UnitStrc* pUnit, int nValue);
__declspec(noinline) static int __stdcall sub_00582AC0_UpgradeGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer);

struct D2SkillsTxt
{
    char unk0x000[0x198];
    int dwToHit;
    int dwLevToHit;
};

struct D2CharStatsTxt
{
    char unk0x00[0x3C];
    int dwToHitFactor;
    char unk0x40[0x84];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

typedef void(__fastcall* ObjShrineFunction)(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2ShrineTableStrc
{
    ObjShrineFunction pfShrineCallback;
    int unk0x04;
    int unk0x08;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const D2ShrineTableStrc gpShrineTable_006E1850[]; // 0x006E1850
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2StatListStrc* __fastcall sub_00582800_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback); // 0x00582800
void __fastcall sub_6FC77AB0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x00583A40
static __declspec(noinline) void __stdcall OBJMODE_GetToHitPercentage(int* pToHit, int nSkillLevel, D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2UnitStrc* pWeapon);
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp); // 0x00584330

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

#pragma pack(push, 1)
struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nAction;
    unsigned char nResult;
};

#pragma pack(pop)
typedef int(__fastcall* ObeliskPowerUpFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue);

struct D2ObeliskPowerUpStrc
{
    ObeliskPowerUpFunction pPowerUpCallback;
    unsigned int nChance;
    int nValue;
};

extern D2ObeliskPowerUpStrc gaObeliskPowerUps_00732EB0[21]; // 0x00732EB0
extern "C" const char gszObjModeSourceFile[]; // 0x006E1970
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __fastcall ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pObject); // 0x0059DD80
static int __stdcall sub_00585240_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer); // 0x00585240

// 0x005818B0
void __fastcall D2GAME_SpikeTraps_6FC74F60(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    int nAnimMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);

    int bArmed = 0;
    switch (pObject->pObjectData->InteractType)
    {
    case 1:
        bArmed = 1;
    case 0:
    {
        D2CoordStrc tCoord;
        UNITS_GetCoords(pObject, &tCoord);

        int bWarningTriggered = 0;
        int bDamageTriggered = 0;
        D2UnitStrc* pUnit = pRoom->pUnitFirst;
        if (pUnit)
        {
            do
            {
                const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
                const int nUnitMode = pUnit ? pUnit->dwAnimMode : 0;
                if (nUnitType == 0 && nUnitMode != 17 && UNITS_GetDistanceToOtherUnit(pObject, pUnit) <= 0)
                {
                    if (bArmed)
                    {
                        OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, pUnit, 0);
                        bDamageTriggered = 1;
                    }
                    else
                    {
                        SUNIT_AttachSound(pObject, 13, 0);
                        bWarningTriggered = 1;
                    }
                }

                pUnit = pUnit->pRoomNext;
            }
            while (pUnit);

            if (bWarningTriggered)
            {
                pObject->pObjectData->InteractType = 1;
                EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 25, 0, 0);
                return;
            }
        }

        if (bArmed)
        {
            if (bDamageTriggered == 1)
            {
                pObject->pObjectData->InteractType = 2;
                UNITS_ChangeAnimMode(pObject, 1);
            }
            else
            {
                pObject->pObjectData->InteractType = 0;
            }

            EVENT_SetEvent(pGame, pObject, 3, (DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId)->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            return;
        }
        break;
    }
    case 2:
        if (nAnimMode)
        {
            UNITS_ChangeAnimMode(pObject, 0);
            pObject->pObjectData->InteractType = 0;
        }
        EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 15, 0, 0);
        return;
    }

    EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 15, 0, 0);
}

// 0x00581A20
void __fastcall OBJMODE_SendObjectModeAndShrineUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(pClient, 0x0E, UNIT_OBJECT, !pUnit ? -1 : pUnit->dwUnitId, 3, !pUnit ? 0 : (pUnit->dwFlags >> 1) & 1, (unsigned short)pUnit->dwAnimMode);

    const unsigned char nSubClass = DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nSubClass;
    if (nSubClass)
    {
        if (nSubClass & 4)
        {
            sub_6FC3F550(pClient, pUnit);
        }
        else if (pUnit->dwAnimMode == 1 && nSubClass & 1)
        {
            const D2ShrinesTxt* const pShrineTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
            unsigned char nCode = 0;
            if (pShrineTxt)
            {
                nCode = pShrineTxt->nCode;
            }

            const int nOperateGUID = pUnit->pObjectData->dwOperateGUID;
            if (nOperateGUID)
            {
                sub_6FC3F060(pClient, 2, !pUnit ? -1 : pUnit->dwUnitId, 0, 0, nOperateGUID - 1, 0, nCode, 0);
            }
        }
    }
}

// 0x00581B50
static void sub_00581B50_TeleportToUnit(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ActiveRoomStrc* pRoom)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    if (COLLISION_GetFreeCoordinates(pRoom, &tCoord, 3, 0x1C09, 0) && sub_6FCBDFE0(SUNIT_GetGameFromUnit(pPlayer), pPlayer, pRoom, tCoord.nX, tCoord.nY, 0, 0))
    {
        D2DrlgCoordsStrc tRoomCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(SUNIT_GetClientFromPlayer(pPlayer, gszObjModeSourceFile_006E1970, 865), DUNGEON_GetLevelIdFromRoom(pRoom), tRoomCoords.nTileXPos, tRoomCoords.nTileYPos);
        UNITROOM_RefreshUnit(pPlayer);
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= UNITFLAGEX_TELEPORTED;
        }
    }
}

// 0x00581BF0
int __fastcall OBJECTS_OperateFunction27_TeleportPad(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    if (pRoom)
    {
        const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwClassId;

        D2UnitStrc* pUnit = pRoom->pUnitFirst;
        while (pUnit && ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_OBJECT || pUnit == pOp->pObject || (!pUnit ? -1 : pUnit->dwClassId) != nUnitId))
        {
            pUnit = pUnit->pRoomNext;
        }

        if (pUnit)
        {
            sub_00581B50_TeleportToUnit(pUnit, pOp->pPlayer, pRoom);
            return 0;
        }

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] != pRoom)
            {
                pUnit = ppRoomList[i]->pUnitFirst;
                while (pUnit && ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_OBJECT || pUnit == pOp->pObject || (!pUnit ? -1 : pUnit->dwClassId) != nUnitId))
                {
                    pUnit = pUnit->pRoomNext;
                }

                if (pUnit)
                {
                    sub_00581B50_TeleportToUnit(pUnit, pOp->pPlayer, ppRoomList[i]);
                    return 0;
                }
            }
        }
    }

    return 0;
}

static inline unsigned int GetAnimMode(D2UnitStrc* unit) { if(!unit) return 0; return unit->mode; }

// 0x00581D40
int __fastcall sub_00581D40_OperateDoor(D2ObjOperateStrc* context,int unused)
{
 D2ActiveRoomStrc* room=UNITS_GetRoom(context->object);
 D2CoordStrc coords;
 UNITS_GetCoords(context->object,&coords);
 unsigned int sizeX=sub_00620510(context->object);
 unsigned int sizeY=sub_006205A0(context->object);
 unsigned int tick=GetTickCount();
 unsigned int mode=GetAnimMode(context->object);
 if(tick<context->object->lastOperateTick+500) return 1;
 switch(mode) {
 case 6:
  if(!sub_0055F140(context->game,context->player)) {
   SUNIT_AttachSound(context->player,22,context->player);
   return 1;
  }
 case 0:
  UNITS_RefreshInventory(context->object);
  UNITS_ChangeAnimMode(context->object,2);
  context->object->lastOperateTick=tick;
  return 1;
 case 2:
 case 5:
  if(!COLLISION_CheckMaskWithSizeXY(room,coords.x,coords.y,sizeX,sizeY,0x8180)) {
   UNITS_BlockCollisionPath(context->object,room,coords.x,coords.y);
   UNITS_ChangeAnimMode(context->object,0);
   context->object->lastOperateTick=tick;
   return 1;
  }
  if(!COLLISION_CheckMaskWithSizeXY(room,coords.x,coords.y,sizeX,sizeY,0x8000)) {
   if(mode!=5) {
    UNITS_ChangeAnimMode(context->object,5);
    context->object->lastOperateTick=tick;
    break;
   }
  } else {
   UNITS_ChangeAnimMode(context->object,4);
   context->object->lastOperateTick=tick;
   return 1;
  }
 }
 return 1;
}

// calling-convention shim (not game code)
static int __stdcall sub_00582AC0_UpgradeGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    SUNIT_Dummy_00582AC0(pPlayer, (int)pPlayer);
    SUNIT_Dummy_00582AC0(pPlayer, (int)pGame);
    SUNIT_Dummy_00582AC0(pPlayer, (int)pGame);
    SUNIT_Dummy_00582AC0((D2UnitStrc*)pGame, (int)pItem);
    SUNIT_Dummy_00582AC0(pPlayer, (int)pGame);
    return SUNIT_Dummy_00582AC0(pItem, nItemId);
}

// 0x00582C40
void __fastcall sub_00582C40_OperateGemShrine(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2InventoryStrc* pInventory = pOp->pPlayer->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetBackPackItemByType(pInventory, 0x14, 0);
    int bUpgraded = 0;
    while (pItem)
    {
        if (bUpgraded)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (pItemsTxtRecord->dwUpgradeCode != ' non')
        {
            const int nItemId = DATATBLS_GetItemIdFromItemCode(pItemsTxtRecord->dwUpgradeCode);
            D2_ASSERT(nItemId != -1, 0x823);
            if (sub_00582AC0_UpgradeGem(pItem, nItemId, pOp->pGame, pOp->pPlayer))
            {
                bUpgraded = 1;
                pItem = 0;
            }
        }

        pItem = INVENTORY_GetBackPackItemByType(pInventory, 0x14, pItem);
    }

    if (bUpgraded)
    {
        return;
    }

    D2SeedStrc* pSeed = &pOp->pPlayer->pSeed;
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;

    unsigned int dwCode;
    switch ((unsigned int)lSeed % 6)
    {
    case 0: dwCode = ' wcg'; break;
    case 1: dwCode = ' rcg'; break;
    case 2: dwCode = ' gcg'; break;
    case 3: dwCode = ' bcg'; break;
    case 4: dwCode = ' ycg'; break;
    default: dwCode = ' vcg'; break;
    }

    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    D2_ASSERT(nItemId != -1, 0x84C);
    sub_00582AC0_UpgradeGem(0, nItemId, pOp->pGame, pOp->pPlayer);
}

static __forceinline D2CharStatsTxt* sub_00583740_GetCharStatsRecord(int nClassId)
{
    return (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
}

// 0x00583740
static void __stdcall OBJMODE_GetToHitPercentage(int* pToHit, int nSkillLevel, D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2UnitStrc* pWeapon)
{
    *pToHit = UNITS_GetAttackRate(pUnit);
    D2_ASSERT(pSkill, 0x963);

    if (!pWeapon)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    }

    if (pWeapon && ITEMS_GetItemType(pWeapon) == 0x26)
    {
        *pToHit = 0;
    }

    const int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, pSkill, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x77, 0);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    const int nToHit = *pToHit;
    *pToHit = nToHit + nToHit * (pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit + nBonus) / 100;

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == 0)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_00583740_GetCharStatsRecord(pUnit->dwClassId);

        if (pCharStatsTxtRecord)
        {
            *pToHit += pCharStatsTxtRecord->dwToHitFactor;
        }
    }
}

static __forceinline int OBJMODE_GetToHitPercentageValue(D2UnitStrc* pUnit, D2UnitStrc* pWeapon, D2SkillStrc* pSkill)
{
    int nPercentage;
    OBJMODE_GetToHitPercentage(&nPercentage, 1, pUnit, pSkill, pWeapon);
    return nPercentage;
}

static __forceinline int OBJMODE_GetMinDamagePercentage(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    int bTwoHanded = 0;
    if (D2Common_10434(pUnit, 1) || pWeapon)
    {
        bTwoHanded = INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2;
    }

    if (bTwoHanded)
    {
        return STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
    }
    return STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
}

static __declspec(noinline) int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit && pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    switch (nStatId)
    {
    case 0x0B:
    case 0x1B:
    case 0x27:
    case 0x29:
    case 0x2B:
    case 0x2D:
    case 0x55:
    case 0xAB:
        return nValue;

    case 0x13:
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        return nValue * OBJMODE_GetToHitPercentageValue(pUnit, pWeapon, pSkill) / 100;
    }

    case 0x15:
        return nValue * OBJMODE_GetMinDamagePercentage(pUnit, pWeapon) / 100;

    default:
        return nValue * STATLIST_UnitGetStatValue(pUnit, nStatId, 0) / 100;
    }
}

void __fastcall D2GAME_SHRINES_CombatBoost_6FC77690(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pShrinesTxtRecord->nCode < gnShrineTableCount_00732EAC, 0x9C1);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[pShrinesTxtRecord->nCode];
    const int nValue = OBJMODE_CalculateShrineStatBonus(0x13, pShrinesTxtRecord->dwArg0, pOp->pPlayer);
    D2StatListStrc* pStatList = sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, pShrinesTxtRecord->dwDurationInFrames, pShrinesTxtRecord->dwArg1, 0x19, pShrineRecord->unk0x08, 0);
    sub_006270B0(pStatList, 0x13, nValue, 0);
}

void __fastcall D2GAME_SHRINES_Stamina_6FC779C0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pShrinesTxtRecord->nCode < gnShrineTableCount_00732EAC, 0x9E7);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[pShrinesTxtRecord->nCode];
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pOp->pPlayer);
    STATLIST_SetUnitStat(pOp->pPlayer, 0x0A, nMaxStamina, 0);
    const int nStatValue = OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, pShrinesTxtRecord->dwArg0, pOp->pPlayer);
    D2StatListStrc* pStatList = sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, pShrinesTxtRecord->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, sub_6FC77AB0);
    sub_006270B0(pStatList, 0x0A, 2 * nStatValue, 0);
    sub_006270B0(pStatList, 0x1C, 1000, 0);
}

// build: context D2GAME_SHRINES_DefensiveBoost_6FC77AE0
void __fastcall D2GAME_SHRINES_DefensiveBoost_6FC77AE0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pShrinesTxtRecord->nCode < gnShrineTableCount_00732EAC, 0x9F9);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[pShrinesTxtRecord->nCode];
    const int nStatValue = pShrineRecord->unk0x04 != -1 ? OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, pShrinesTxtRecord->dwArg0, pOp->pPlayer) : 0;

    sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, pShrinesTxtRecord->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, 0);
}

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

// build: context OBJECTS_IsNeutralExplodingBarrel
static __forceinline int OBJECTS_IsNeutralExplodingBarrel(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwClassId == OBJECT_EXPLODINGBARREL && pUnit->dwAnimMode == OBJMODE_NEUTRAL;
}

// 0x00584240
static int sub_00584240_ExplodeBarrel(D2ObjOperateFnStrc* pOp)
{
    D2ObjOperateFnStrc tNewOp = *pOp;
    D2CoordStrc tCoord;
    UNITS_GetCoords(pOp->pObject, &tCoord);
    for (D2UnitStrc* pUnit = UNITS_GetRoom(pOp->pObject)->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (pUnit != pOp->pObject && nUnitType != UNIT_TILE)
        {
            if (nUnitType == UNIT_PLAYER)
            {
                if (nAnimMode != PLRMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_MONSTER)
            {
                if (nAnimMode != MONMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_OBJECT)
            {
                if (OBJECTS_IsNeutralExplodingBarrel(pUnit) && sub_006416D0_UnitEdgeDistance(pOp->pObject, pUnit) <= 2)
                {
                    tNewOp.pObject = pUnit;
                    OBJECTS_OperateFunction07_ExplodingBarrel(&tNewOp);
                }
            }
        }
    }
    return 0;
}

// 0x00584330
int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp)
{
    if ((!pOp->pObject ? 0 : pOp->pObject->dwAnimMode) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);
        sub_00584240_ExplodeBarrel(pOp);
        UNITS_FreeCollisionPath(pOp->pObject);
        D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}

// 0x00585240
static __declspec(noinline) int __stdcall sub_00585240_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer)
{
    if (nSubType < gnObeliskPowerUps_00732FAC)
    {
        const unsigned __int64 lSeed = pPlayer->pSeed.nHighSeed + 0x6AC690C5i64 * pPlayer->pSeed.nLowSeed;
        pPlayer->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pPlayer->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((unsigned int)lSeed % 100 < gaObeliskPowerUps_00732EB0[nSubType].nChance)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback), 4341);
            return gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback(pGame, pPlayer, gaObeliskPowerUps_00732EB0[nSubType].nValue);
        }
    }

    return 0;
}

// 0x005852E0
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, unsigned short nState)
{
    D2GSPacketSrv58 packet58;
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, nPlayerGUID);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (pPlayer)
    {
        if (!pObject)
        {
            return 1;
        }

        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszObjModeSourceFile, 0x1135);
        packet58.nHeader = 0x58;
        packet58.nUnitId = nObjectGUID;
        const int nAnimMode = pObject->dwAnimMode;
        switch (nState)
        {
        case 2:

            if (nAnimMode == 3)
            {
                packet58.nAction = 1;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                UNITS_ChangeAnimMode(pObject, 0);
                SUNIT_ResetInteractInfo(pPlayer);
            }
            else
            {
                packet58.nAction = 1;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                UNITS_ChangeAnimMode(pObject, 0);
                SUNIT_ResetInteractInfo(pPlayer);
            }
            break;

        case 3:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            if ((!pObject ? -1 : pObject->dwClassId) == 0x98)
            {
                if (pItemsTxtRecord->dwCode != 0x20747368)
                {
                    packet58.nAction = 4;
                    sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                    return 1;
                }
            }
            else if (!D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem))
            {
                packet58.nAction = 4;
                sub_0053D8D0_SendPacket0x58(pClient, &packet58);
                return 1;
            }

            packet58.nAction = 5;
            SUNIT_ResetInteractInfo(pPlayer);
            if (pObject->dwClassId == 0x98)
            {
                packet58.nResult = 1;
            }
            else
            {
                packet58.nResult = sub_00585240_ApplyObeliskPowerUp(pGame, pItemsTxtRecord->nSubType, pPlayer);
            }

            sub_0053D8D0_SendPacket0x58(pClient, &packet58);
            if (packet58.nResult == 1)
            {
                UNITS_ChangeAnimMode(pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
                if (pObject->dwClassId == 0x98)
                {
                    UNITS_ChangeAnimMode(pObject, 2);
                    ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(pGame, pPlayer, pObject);
                    break;
                }

                EVENT_SetEvent(pGame, pObject, 1, pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt1 >> 8) + 1, 0, 0);
                break;
            }

            UNITS_ChangeAnimMode(pObject, 0);
            break;
        }
        }

        return 1;
    }

    D2_ASSERT(pObject, 0x1109);
    return 1;
}
