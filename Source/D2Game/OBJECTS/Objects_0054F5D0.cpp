#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ROOM_MIN_SUBTILES 2
#define CREATE_TRIES 5
#define CREATE_SIZE_GROW 6
#define COLLIDE_MASK_PLACEMENT 0x3F11
#define LINE_CREATE_ROOM 1358
#define IFLAG_IDENTIFIED 0x00000010
#define INVPAGE_TRADE 2
#define PACKETSIZE06_HEADER 0x92
#define UPDATEUI_TRADEACCEPTED 6
#define TRADESTATE_ACCEPTED 3
#define D2_PAIR_CAPACITY 0x3FF
#define D2S_ERROR_WRITE 3
#define D2S_ERROR_READ_SIZE 0x14
struct D2SeedStrc;
struct D2ObjectControlStrc;
struct D2ObjectDataStrc;
struct D2ObjInitFnStrc;
struct D2DrlgCoordsStrc;
struct D2StaticPathStrc;
struct D2PlayerListStrc;
struct D2ItemTradeStrc;
struct D2PlayerTradeStrc;
struct D2PlayerDataStrc;
struct D2ItemsTxt;
struct D2SkillsTxt;
struct D2UnkPairStrc;
struct D2UnkFieldPairStrc;
struct _SYSTEMTIME;
struct D2LocalDateStrc;
struct D2PackedWordStrc;
struct D2UnkCallRecordStrc;
struct D2Unk0056DCC0Strc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectDataStrc
{
    char unk0x00[0x04];
    unsigned char InteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    unsigned char unk_18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x40];
    int unk0xA4;
    char unk0xA8[0x1C];
    unsigned int dwFlags;
};

struct D2ObjectsTxt
{
    char unk0x000[0xC4];
    unsigned char nSelectable[8];
    char unk0x0CC[0x5C];
    unsigned char nIsAttackable;
    char unk0x129[0x14];
    unsigned char nAutomap13D;
    char unk0x13E[0x73];
    unsigned char nInitFn;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    D2ObjectsTxt* pObjectTxt;
    int nX;
    int nY;
};

typedef void (__fastcall* D2ObjInitFn)(D2ObjInitFnStrc* pOp);

typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2ObjInitFn gpObjInitFnTable_00731BC0[80]; // 0x00731BC0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

struct D2ActiveRoomStrc
{
    char unk0x00[0x7C];
    D2ActiveRoomStrc* pRoomNext;
};

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
int __fastcall sub_0054F520_AllocTimerArg(D2GameStrc* pGame); // 0x0054F520
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, char bSparkChest); // 0x005540A0
void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, int pTimerArg); // 0x006234C0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

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

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2PlayerListStrc
{
    int nUnitGUID;
    unsigned int dwFlags;
    int field_8;
    int field_C;
    D2PlayerListStrc* pNext;
};

struct D2ItemTradeStrc
{
    int nItemGUID1;
    int nItemGUID2;
    D2ItemTradeStrc* pNext;
};

struct D2PlayerTradeStrc
{
    int nSaveLength;
    unsigned char* pSaveData;
    D2ItemTradeStrc* pItemTrade;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x38];
    D2PlayerListStrc* pPlayerList;
    char unk0x3C[0x14];
    unsigned int dwTradeState;
    char unk0x54[0x08];
    D2PlayerTradeStrc* pTrade;
    char unk0x60[0x100];
    unsigned int dwHostileDelay;
};

struct D2ItemsTxt
{
    char unk0x000[0x12A];
    unsigned char nQuest;
};

struct D2SkillsTxt
{
    char unk0x000[0x128];
    unsigned int dwPerDelay;
    char unk0x12C[0xB0];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2DamageStrc
{
    char unk0x00[0x18];
    int dwBurnLen;
    char unk0x1C[0x10];
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    char unk0x38[0x0C];
    int dwStunLen;
};

struct D2UnkPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2UnkFieldPairStrc
{
    char unk0x00[0x80];
    int nValue;
};

struct _SYSTEMTIME
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2LocalDateStrc
{
    int nDayOfWeek;
    int f_4;
    int nDay;
    int f_C;
};

struct D2PackedWordStrc
{
    union
    {
        unsigned short wRaw;
        struct
        {
            unsigned short nId : 12;
            unsigned short nUnused : 3;
            unsigned short bFlag : 1;
        };
    };
    unsigned short nCount;
};

struct D2UnkCallRecordStrc
{
    void* pArg1;
    void* pArg2;
    int nZero;
    int nArg4;
};

struct D2Unk0056DCC0Strc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    void* pUnk0x20;
};

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

enum D2C_UnitFlags
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISVALIDTARGET = 0x00000008,
};

enum D2C_ElemTypes
{
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(_SYSTEMTIME* lpSystemTime); // 0x006CC1D4
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
D2UnitStrc* __fastcall OBJECTS_PopulateFn3_CommonObjects(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nDensity, int nObjectId, int nChance); // 0x00551470
void __stdcall sub_00551150_SpawnFlies(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00551150
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
int __fastcall sub_00531BB0_WriteItemList(void* pArg1, void* pArg2, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0
void __fastcall sub_0053DA90(D2UnitStrc* pUnit, int nArg); // 0x0053DA90
void __fastcall sub_0053DE20_SendPacket0x8CToAllPlayers(D2GameStrc* pGame, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState); // 0x0053DE20
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0
void __fastcall sub_0056DCC0(D2GameStrc* pGame, D2Unk0056DCC0Strc* pRecord); // 0x0056DCC0
int __fastcall sub_0058F710(D2UnitStrc* pUnit); // 0x0058F710
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame); // 0x00626D40
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall sub_0063C550_Return(D2InventoryStrc* pInventory, int nX); // 0x0063C550
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall sub_0063EA70_GetMonsterId(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0063EA70
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AA0
void __stdcall PATH_ClearNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AB0

// 0x0054F5D0
void __fastcall OBJECTS_InitHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pUnit);

    if (pUnit)
    {
        pUnit->dwUnitId = nUnitGUID;
    }

    D2GAME_SetSparkChest_6FCBD7C0(pUnit, 0);

    int nAnimMode;
    if (pUnit)
    {
        pUnit->dwFlags &= ~8u;
        pUnit->unk0xA4 = 0;
        nAnimMode = pUnit->dwAnimMode;
    }
    else
    {
        nAnimMode = 0;
    }

    D2_ASSERT(nAnimMode < 8, 0x240);

    if (pObjectsTxtRecord->nIsAttackable)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 4u;
        }
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~4u;
        }
    }

    pUnit->pObjectData->InteractType = 0;

    const int nClassId = pUnit->dwClassId;
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pUnit);
    D2_ASSERT((unsigned short)nClassId < 0x23D, 0x260);
    D2_ASSERT(pObjectsTxtRecord->nInitFn < 80, 0x262);

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);

    if (pObjectsTxtRecord->nInitFn < 80 && gpObjInitFnTable_00731BC0[pObjectsTxtRecord->nInitFn])
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpObjInitFnTable_00731BC0[pObjectsTxtRecord->nInitFn]), 0x26A);

        D2ObjInitFnStrc pOp;
        pOp.pGame = pGame;
        pOp.pObject = pUnit;
        pOp.pRoom = pRoom;
        pOp.pObjectregion = pObjectControl;
        pOp.pObjectTxt = pObjectsTxtRecord;
        pOp.nX = nX;
        pOp.nY = nY;
        gpObjInitFnTable_00731BC0[pObjectsTxtRecord->nInitFn](&pOp);
    }

    if (pObjectsTxtRecord->nSelectable[nAnimMode])
    {
        pUnit->dwFlags |= 2u;
    }
    else
    {
        pUnit->dwFlags &= ~2u;
    }

    int bFlag80 = 1;
    if (pObjectsTxtRecord->nAutomap13D)
    {
        bFlag80 = (pUnit->dwFlags & 0x80) != 0;
    }

    if (!bFlag80 && !SEED_RollLimitedRandomNumber(&pObjectControl->pSeed, 14))
    {
        UNITS_ChangeAnimMode(pUnit, 2);
    }

    UNITS_SetTimerArg(pUnit, sub_0054F520_AllocTimerArg(pGame));
}

#include "gen/data/Source/D2Game/OBJECTS/Objects_0054F5D0.inc"

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00550380
D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    if (drlgCoords.nSubtileWidth < ROOM_MIN_SUBTILES || drlgCoords.nSubtileHeight < ROOM_MIN_SUBTILES)
    {
        return 0;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    int nX;
    int nY;
    int i;
    for (i = 0; i < CREATE_TRIES; ++i)
    {
        nX = OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileWidth - nSizeX - 1) + drlgCoords.nSubtileX;
        nY = OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileHeight - nSizeY - 1) + drlgCoords.nSubtileY;
        if (nX && nY && (unsigned short)nX >= drlgCoords.nSubtileX + 1 && (unsigned short)nY >= drlgCoords.nSubtileY + 1
            && (unsigned short)nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth - 1 && (unsigned short)nY < drlgCoords.nSubtileY + drlgCoords.nSubtileHeight - 1
            && !COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + CREATE_SIZE_GROW, nSizeY + CREATE_SIZE_GROW, COLLIDE_MASK_PLACEMENT))
        {
            break;
        }
    }

    if (i >= CREATE_TRIES)
    {
        return 0;
    }

    D2_ASSERT(pRoom, LINE_CREATE_ROOM);
    return SUNIT_AllocUnitData(UNIT_OBJECT, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline D2PlayerListStrc* sub_0055B110(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    const int nUnitGUID = !pPlayer2 ? -1 : pPlayer2->dwUnitId;
    if (pPlayer1 != pPlayer2)
    {
        for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
        {
            if (pPlayerList->nUnitGUID == nUnitGUID)
            {
                return pPlayerList;
            }
        }
    }

    return 0;
}

// 0x00551690
D2UnitStrc* __fastcall OBJECTS_PopulateFn6_RogueGuardCorpse(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nDensity, int nObjectId, int nProbability)
{
    D2UnitStrc* pObject = OBJECTS_PopulateFn3_CommonObjects(pGame, pRoom, nDensity, nObjectId, nProbability);
    if (pObject)
    {
        sub_00551150_SpawnFlies(pGame, pObject);
    }

    return pObject;
}

// 0x005545C0
D2ActiveRoomStrc* __fastcall sub_005545C0_GetValidNextRoom(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pNextRoom = PATH_GetNextRoom(pDynamicPath);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (nLevelId)
    {
        for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)]); pRoom; pRoom = pRoom->pRoomNext)
        {
            if (pRoom == pNextRoom)
            {
                return pNextRoom;
            }
        }
    }

    PATH_ClearNextRoom(pDynamicPath);
    return 0;
}

// 0x00555CD0
void __fastcall sub_00555CD0_AppendPair(int* pCount, D2UnkPairStrc* pPairs, int nSecond, int nFirst)
{
    const int nCount = *pCount;
    if (nCount < D2_PAIR_CAPACITY)
    {
        pPairs[nCount].nSecond = nSecond;
        pPairs[nCount].nFirst = nFirst;
        ++*pCount;
    }
}

// 0x00555D20
void __fastcall sub_6FC4BE80(D2UnitStrc* pUnit, D2GameStrc* pGame, int nUnitGUID, D2ActiveRoomStrc* pRoom)
{
    if (pUnit)
    {
        pUnit->dwUnitId = nUnitGUID;
        pUnit->dwFlags = pUnit->dwFlags & ~UNITFLAG_ISVALIDTARGET | UNITFLAG_TARGETABLE;
    }

    ITEMS_SetItemFlag(pUnit, IFLAG_IDENTIFIED, 1);
    STATLIST_AllocStatListEx(pUnit, 0, 0, 0);

    const unsigned char nQuest = DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nQuest;
    if (nQuest)
    {
        QUESTS_CreateChainRecord(pGame, pUnit, nQuest - 1);
    }

    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pUnit);
}

// 0x00557FF0
int __fastcall sub_00557FF0_InventoryContainsItem(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2InventoryStrc* pOtherInventory)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 2740);

    if (pOtherInventory)
    {
        pInventory = pOtherInventory;
    }

    if (pItem == INVENTORY_GetCursorItem(pInventory))
    {
        return 1;
    }

    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        if (pItem == INVENTORY_UnitIsItem(pNode))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0055B260
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags, int bSet)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2 || !pPlayerList)
    {
        return;
    }

    if (bSet)
    {
        pPlayerList->dwFlags |= nFlags;
    }
    else
    {
        pPlayerList->dwFlags &= ~nFlags;
    }

    sub_0053DE20_SendPacket0x8CToAllPlayers(pGame, !pPlayer1 ? -1 : pPlayer1->dwUnitId, !pPlayer2 ? -1 : pPlayer2->dwUnitId, pPlayerList->dwFlags);
}

// 0x0055B300
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2 || !pPlayerList)
    {
        return 0;
    }

    return pPlayerList->dwFlags & nFlags;
}

// 0x0055B3A0
void __fastcall sub_6FCBA980(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2 || !pPlayerList)
    {
        return;
    }

    pPlayerList->field_C = a3;
}

// 0x0055B4C0
void __fastcall sub_6FCBAAA0(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (!pPlayerList)
    {
        return;
    }

    sub_0053DE20_SendPacket0x8CToAllPlayers(pGame, !pPlayer1 ? -1 : pPlayer1->dwUnitId, !pPlayer2 ? -1 : pPlayer2->dwUnitId, pPlayerList->dwFlags);
}

// 0x0055B720
void __fastcall PLAYERLIST_SetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (pPlayerList)
    {
        pPlayerList->field_8 = a3;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    if (pPlayerData)
    {
        pPlayerData->dwHostileDelay = GetTickCount();
    }
}

// 0x0055CA00
int __fastcall sub_0055CA00_MatchFieldPair(D2UnkFieldPairStrc* pRecord1, D2UnkFieldPairStrc* pRecord2, int nValue1, int nValue2)
{
    if (pRecord1->nValue == nValue1 && pRecord2->nValue == nValue2)
    {
        return 1;
    }

    if (pRecord1->nValue == nValue2 && pRecord2->nValue == nValue1)
    {
        return 1;
    }

    return 0;
}

// 0x0055ED30
void __fastcall sub_6FC49090(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pItem)
    {
        pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemove, 4841);
    D2_ASSERT(pItem == pRemove, 4842);

    int nX;
    switch (pItem->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pItem->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pItem->pDynamicPath)
        {
            nX = PATH_GetXPosition(pItem->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }

    sub_0063C550_Return(pInventory, nX);
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
}

// 0x00564F00
int __cdecl sub_00564F00_CompareDescending(const unsigned int* pValue1, const unsigned int* pValue2)
{
    const unsigned int nValue1 = *pValue1;
    const unsigned int nValue2 = *pValue2;
    if (nValue1 > nValue2)
    {
        return -1;
    }

    return nValue1 != nValue2;
}

// 0x005665B0
void __stdcall sub_005665B0_GetLocalDate(D2LocalDateStrc* pDate)
{
    _SYSTEMTIME systemTime;
    GetLocalTime(&systemTime);
    pDate->nDayOfWeek = systemTime.wDayOfWeek + 1;
    pDate->f_4 = systemTime.wMonth;
    pDate->nDay = systemTime.wDay;
    pDate->f_C = systemTime.wYear;
}

// 0x00566BF0
void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2PlayerTradeStrc* pTrade = pPlayerData->pTrade;
    if (pTrade)
    {
        FOG_FreePool(pGame->pMemoryPool, pTrade->pSaveData, ".\\PLAYER\\PlrTrade.cpp", 2082, 0);

        D2ItemTradeStrc* pItemTrade = pTrade->pItemTrade;
        while (pItemTrade)
        {
            D2ItemTradeStrc* pNext = pItemTrade->pNext;
            FOG_FreePool(pGame->pMemoryPool, pItemTrade, ".\\PLAYER\\PlrTrade.cpp", 2087, 0);
            pItemTrade = pNext;
        }

        pTrade->pItemTrade = 0;
        FOG_FreePool(pGame->pMemoryPool, pTrade, ".\\PLAYER\\PlrTrade.cpp", 2091, 0);
        pPlayerData->pTrade = 0;
    }
}

// 0x00566C80
void __fastcall sub_6FC90BE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2UnitStrc* pOtherPlayer = (D2UnitStrc*)pArg;
    if (pPlayer != pOtherPlayer)
    {
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2107), PACKETSIZE06_HEADER, 0, !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId);
    }
}

// 0x00567020
void __fastcall sub_00567020_StartTrade(D2UnitStrc* pPlayer, int nUnused, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData)
{
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2422), UPDATEUI_TRADEACCEPTED);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 2423), UPDATEUI_TRADEACCEPTED);

    pPlayerData->dwTradeState = TRADESTATE_ACCEPTED;
    pInteractPlayerData->dwTradeState = TRADESTATE_ACCEPTED;
}

// 0x005675E0
int __fastcall PLRTRADE_CopyTradeSaveDataToBuffer(D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize)
{
    D2PlayerTradeStrc* pTrade = UNITS_GetPlayerData(pUnit)->pTrade;
    if (!pTrade)
    {
        return 0;
    }

    if (nBufferSize < pTrade->nSaveLength)
    {
        return 0;
    }

    memcpy(pBuffer, pTrade->pSaveData, pTrade->nSaveLength);
    return pTrade->nSaveLength;
}

// 0x00567840
int __fastcall sub_6FC93740(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (!SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) || nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        if (INVENTORY_GetItemNodePage(pItem) == INVPAGE_TRADE)
        {
            return 0;
        }
    }

    return 1;
}

// 0x005697B0
int __fastcall sub_005697B0(void* pArg1, void* pArg2, unsigned char** ppCursor, unsigned char* pEnd, int nArg5, int nArg6, int nArg7)
{
    unsigned char* pCursor = *ppCursor;
    const int nWritten = sub_00531BB0_WriteItemList(pArg1, pArg2, pCursor, pEnd - pCursor, nArg5, nArg6, nArg7);
    if (nWritten < 0)
    {
        return D2S_ERROR_WRITE;
    }

    *ppCursor = pCursor + nWritten;
    return 0;
}

// 0x00569EC0
void __fastcall sub_00569EC0_UnpackWord(D2PackedWordStrc* pPacked, int* pId, int* pFlag, int* pCount)
{
    if (pPacked->wRaw == 0xFFFF)
    {
        *pId = -1;
        *pFlag = 0;
        *pCount = -1;
        return;
    }

    *pId = pPacked->nId;
    *pFlag = pPacked->bFlag;
    *pCount = pPacked->nCount;
    if (!*pCount)
    {
        *pCount = -1;
    }
}

// 0x0056B740
int __fastcall sub_0056B740_CallWithRecord(void* pArg1, void* pArg2, int (__fastcall* pfnCallback)(D2UnkCallRecordStrc*), int nArg4)
{
    D2UnkCallRecordStrc record;
    record.pArg1 = pArg1;
    record.pArg2 = pArg2;
    record.nArg4 = nArg4;
    record.nZero = 0;
    return pfnCallback(&record);
}

// 0x0056C840
void __fastcall sub_6FD11D90(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    switch (pSkillsTxtRecord->nEType)
    {
    case ELEMTYPE_COLD:
        pDamage->dwColdLen = nLength;
        break;
    case ELEMTYPE_POIS:
        pDamage->dwPoisLen = nLength;
        break;
    case ELEMTYPE_STUN:
        pDamage->dwStunLen = nLength;
        break;
    case ELEMTYPE_BURN:
        pDamage->dwBurnLen = nLength;
        break;
    case ELEMTYPE_FREEZE:
        pDamage->dwFrzLen = nLength;
        break;
    }
}

// 0x0056CD50
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPerDelay, nSkillId, nSkillLevel);
    if (nDelay <= 5)
    {
        nDelay = 5;
    }

    return (pGame->dwGameFrame + nDelay - 1) / nDelay * nDelay + 1;
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056DDE0
void __fastcall sub_0056DDE0_FillRecordAndCall(D2GameStrc* pGame, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, void* pArg8)
{
    D2Unk0056DCC0Strc record = {};
    record.nUnk0x00 = nArg2;
    record.f_C = nArg3;
    record.f_10 = nArg4;
    record.nUnk0x04 = nArg5;
    record.nUnk0x08 = nArg6;
    record.nUnk0x18 = nArg7;
    record.pUnk0x20 = pArg8;
    sub_0056DCC0(pGame, &record);
}

// 0x0056E620
int __fastcall sub_0056E620_GetValidMonsterId(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    int nMonsterId = sub_0063EA70_GetMonsterId(pUnit, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    nMonsterId = sub_0058F710(pUnit);
    if (nMonsterId > 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x00570850
void __fastcall sub_00570850_Forward(void* pUnused, D2UnitStrc* pUnit, int nArg)
{
    sub_0053DA90(pUnit, nArg);
}
