#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define NUM_UNIT_TYPES 6
#define UNITFLAGEX_STORELASTATTACKER 0x20000
#define UNITFLAG_HASEVENTSOUND 0x400
#define STATE_PLAYERBODY 7
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_ENDANIM 1
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define COLLISION_PATTERN_SMALL_NO_PRESENCE 5
#define COLLIDE_CORPSE 0x8000
#define UNITFLAGEX_HASBEENDELETED 0x100
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12
#define SKILLSFLAGINDEX_TARGETPET 25
#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_GOOD 2
#define UNIT_NUM_ALIGNMENT 3
#define MONSTER_HYDRA1 351
#define MONSTER_HYDRA2 352
#define MONSTER_HYDRA3 353
#define STATE_ALIGNMENT 105
#define STAT_ALIGNMENT 172
#define EVENTTYPE_REMOVESKILLCOOLDOWN 14
struct D2MonsterRegionStrc;
struct D2QuestChainStrc;
struct D2ItemsTxt;
struct D2SeedStrc;
struct D2PlayerDataStrc;
struct T00552FD0;
struct D2ItemDataStrc;
struct D2StaticPathStrc;
struct D2ObjectDataStrc;
struct D2DrlgCoordsStrc;
struct Pad40_00553970;
struct Obj00553970;
struct Obj00554100;
struct Obj00554190;
struct D2SkillsTxt;
struct Obj00554650;
struct D2MonsterDataStrc;
struct D2MonStatsTxt;
struct D2AiTableStrc;
struct D2PresetUnitStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2PlayerDataStrc* pPlayerData;
        D2ItemDataStrc* pItemData;
        D2ObjectDataStrc* pObjectData;
        D2MonsterDataStrc* pMonsterData;
        void* f_14;
    };
    unsigned char nAct;
    char unk0x19[0x3];
    D2DrlgActStrc* pDrlgAct;
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    D2AnimSeqTxt* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    char unk0x4E[0x02];
    T00552FD0* pAnimData;
    unsigned char unk_54[0xC];
    D2InventoryStrc* pInventory;
    int dwInteractGUID;
    int dwInteractType;
    unsigned char nInteract;
    unsigned char unk_6D[0x1];
    short nUpdateType;
    D2UnitStrc* pUpdateUnit;
    D2QuestChainStrc* pQuestEventList;
    unsigned char bSparkChest;
    char unk0x79[7];
    D2GameStrc* pGame;
    unsigned char unk_84[0x10];
    int dwOwnerType;
    int dwOwnerGUID;
    int dwKillerType;
    int dwKillerGUID;
    char unk0xA4[0x20];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
    char unk0xCC[0x18];
    D2UnitStrc* pListNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x50];
    int bExpansion;
    unsigned char unk_74[0x1C];
    int dwLastUsedUnitGUID[6];
    int dwGameFrame;
    unsigned char unk_AC[0x10];
    D2DrlgActStrc* pAct[5];
    unsigned char unk_D0[0x20];
    D2MonsterRegionStrc* pMonReg[1024];
    unsigned char unk_10F0[0x30];
    D2UnitStrc* pUnitList[5][128];
    D2UnitStrc* pTileList;
};

void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057C980
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem); // 0x00627DC0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

struct D2PlayerDataStrc
{
    char unk0x00[64];
    int nNecropetFlag;
    char unk0x44[88];
    D2ClientStrc* pClient;
    unsigned char unk_A0[0xA8];
    int nSkillCooldown148;
    int nSkillCooldown14C;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
D2UnitStrc* __stdcall sub_K11_EmitUse(D2UnitStrc** ppList);

typedef int (__stdcall* FARPROC)();

struct T00552FD0
{
    char unk0x00[0x10];
    unsigned char pFrameFlags[0x90];
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID); // 0x00648BB0

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

struct D2ActiveRoomStrc
{
    char unk0x00[0x48];
    D2ClientStrc** ppClients;
    char unk0x4C[0x2C];
    int nNumClients;
};

struct D2ItemDataStrc
{
    char unk0x00[0x24];
    int dwActionStamp;
};



D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00
void __fastcall sub_00534AD0_ResetModeAndEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x00534AD0
int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int a5); // 0x005735A0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused); // 0x0064C2C0
void __fastcall sub_00553060_AddToUnitList(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x00553060
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2); // 0x00620FA0
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    union
    {
        struct
        {
            D2CoordStrc tGameCoords;
        };
        struct
        {
            int nX;
            int nY;
        };
    };
};

struct D2ObjectDataStrc
{
    char unk0x00[0x18];
    D2CoordStrc DestRoomCooords;
    D2CoordStrc DestPortalCoords;
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

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

struct Pad40_00553970 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00553970 {
    Pad40_00553970 tPad000;
    Pad40_00553970 tPad040;
    Pad40_00553970 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwUnknownC4;
    unsigned int dwUnknownC8;
    unsigned int dwUnknownCC;
    unsigned int dwUnknownD0;
    unsigned int dwUnknownD4;
    unsigned int dwUnknownD8;
    unsigned int dwValueDC;
};

short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710

struct Obj00554100 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    int nValue64;
    int nValue68;
    unsigned char nValue6C;
};

struct Obj00554190 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    int nValue64;
    int nValue68;
    unsigned char nValue6C;
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090
void __fastcall sub_00547DD0(D2MonsterRegionStrc** pMonReg, D2UnitStrc* pUnit, int nAlignment, int nAlignNew); // 0x00547DD0
void __stdcall sub_00619EE0(D2ActiveRoomStrc* pRoom); // 0x00619EE0
void __stdcall sub_00619F20(D2ActiveRoomStrc* pRoom); // 0x00619F20
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

typedef int (__fastcall* EventTimerCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5);

void __fastcall sub_6FC349B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback); // 0x00540EA0

struct Obj00554650 { unsigned char bUnknown00[0x60]; unsigned int dwFlags60; };

struct D2MonsterDataStrc
{
    char unk0x00[0x50];
    int unk0x50;
};
D2ActiveRoomStrc* __fastcall sub_005545C0_GetValidNextRoom(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005545C0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600
void __stdcall sub_00648B40_roomInvalid(D2DynamicPathStrc* pPath, int bValue); // 0x00648B40


struct D2AiTableStrc
{
    int unk0x00;
    void* unk0x04;
    void* pAiParamFn;
    void* unk0x0C;
};
void __fastcall sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x00554670
int __stdcall D2Common_10226(D2UnitStrc* pUnit, int nFlag); // 0x00650840
void __fastcall sub_00555580_DetachUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int bKeepInRoom); // 0x00555580
void __fastcall QUESTS_FreeChainRecord(D2GameStrc* pGame, D2QuestChainStrc* pChain); // 0x00543590
void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B1A20
void __fastcall sub_00535430(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00535430
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0
void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005349D0
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster); // 0x005736A0
void __fastcall OBJECTS_FreeHoverMessage(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00552A00
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit); // 0x00623570
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall MISSILES_Free(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x0059F8E0
void __fastcall ITEMS_FreeSocketInventoryAndTimers(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x00557EE0
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem); // 0x00627D00
void __fastcall SUNITEVENT_FreeEventList(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C0A90
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit); // 0x00571F40
void __stdcall UNITS_FreeUnit(D2UnitStrc* pUnit); // 0x00620300

struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall QUESTS_MapPresetSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI); // 0x00545C90
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags); // 0x005557D0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

// 0x00552DB0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 222);

    return pUnit->pListNext;
}

// 0x00553540
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_6FCBC7E0(pGame, pUnit);
    D2UnitStrc* pTargetUnit = PATH_GetTargetUnit(pUnit->pDynamicPath);
    if (pTargetUnit != pUnit)
    {
        return pTargetUnit;
    }

    return 0;
}

// 0x00553570
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode)
{
    SUNITDMG_FreeAttackerCombatList(pGame, pUnit);
    UNITS_ChangeAnimMode(pUnit, nMode);
}

int gnUnitInitSeed_008846E8; // 0x008846E8

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00552DF0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed)
{
    D2_ASSERT(pUnit, 415);

    SEED_InitSeed(&pUnit->pSeed);

    if (pSeed)
    {
        pUnit->dwInitSeed = (unsigned int)ITEMS_RollRandomNumberInline(pSeed);
    }
    else
    {
        pUnit->dwInitSeed = SEED_GetRandomValue(2 * gnUnitInitSeed_008846E8++);
    }

    SEED_InitLowSeed(&pUnit->pSeed, pUnit->dwInitSeed);
}

// 0x00552E90
void __fastcall sub_00552E90_InitItemSeeds(D2UnitStrc* pItem, D2SeedStrc* pGameSeed)
{
    ITEMS_InitItemSeed(pItem);
    ITEMS_SetItemStartSeed(pItem, (unsigned int)ITEMS_RollRandomNumberInline(pGameSeed));
    SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), ITEMS_GetItemStartSeed(pItem));
}

// 0x00552EE0
int __fastcall sub_00552EE0(D2GameStrc* pGame, int nUnitType)
{
    D2_ASSERT(nUnitType < NUM_UNIT_TYPES, 452);

    int nUnitGUID = pGame->dwLastUsedUnitGUID[nUnitType] + 1;
    if (nUnitGUID == -1)
    {
        nUnitGUID = 1;
    }

    pGame->dwLastUsedUnitGUID[nUnitType] = nUnitGUID;
    return nUnitGUID;
}

// 0x00552F20
int __fastcall sub_00552F20(int nUnitGUID)
{
    return nUnitGUID & UNIT_LIST_MASK;
}

// 0x00553010
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 800);

    if (pUnit->dwFlagEx & UNITFLAGEX_STORELASTATTACKER)
    {
        return SUNIT_GetServerUnit(pGame, pUnit->dwKillerType, pUnit->dwKillerGUID);
    }

    return 0;
}

// 0x00553180
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit, 1210);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 1211);

    UNITS_GetPlayerData(pUnit)->pClient = pClient;
}

// 0x005531C0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    return UNITS_GetPlayerData(pPlayer)->pClient;
}

// 0x00553380
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit)
{
    D2_ASSERT(pUnit, 1367);

    pUnit->nUpdateType = nUpdateType;
    pUnit->pUpdateUnit = pUpdateUnit;
    UNITROOM_RefreshUnit(pUnit);
    pUnit->dwFlags |= UNITFLAG_HASEVENTSOUND;
}

// 0x00554010
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2601);

    return pUnit->pGame;
}

// 0x00554040
void __fastcall sub_00554040(D2UnitStrc* pUnit, int nFlag)
{
    D2_ASSERT(pUnit, 2610);

    pUnit->pPlayerData->nNecropetFlag = nFlag;
}

// 0x00554070
unsigned int __fastcall sub_00554070(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2620);

    return pUnit->pPlayerData->nNecropetFlag;
}

// 0x005540A0
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest)
{
    D2_ASSERT(pUnit, 2631);

    pUnit->bSparkChest = nSparkChest;
}

// 0x005540D0
unsigned char __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2640);

    return pUnit->bSparkChest;
}

// 0x00552F30
static D2UnitStrc** __stdcall SUNIT_GetUnitList(D2GameStrc* pGame, int nUnitType, int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
    {
        return (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }
    return 0;
}

D2UnitStrc* __fastcall sub_K11_Emit00552F30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return sub_K11_EmitUse(SUNIT_GetUnitList(pGame, pUnit->dwUnitType, pUnit->dwUnitId));
}

// 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID)
{
    D2_ASSERT(pGame, 722);

    D2UnitStrc** ppUnitList;
    if (nUnitType == UNIT_TILE)
    {
        ppUnitList = &pGame->pTileList;
    }
    else if (nUnitType >= 0 && nUnitType <= 4)
    {
        ppUnitList = (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }
    else
    {
        ppUnitList = 0;
    }

    for (D2UnitStrc* pUnit = *ppUnitList; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitGUID)
        {
            return pUnit;
        }
    }

    return 0;
}

#include "gen/data/Source/D2Game/UNIT/SUnit.inc"

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!UNIT_HasFlagEx(pUnit, UNITFLAGEX_STOREOWNERINFO))
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x00553490
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1792);
    D2_ASSERT(pGame, 1793);

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 1796);

    if (!PATH_GetTargetUnit(pPath))
    {
        return;
    }

    int nTargetType;
    int nTargetGUID;
    PATH_GetTargetTypeAndGUID(pPath, &nTargetType, &nTargetGUID);

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nTargetType, nTargetGUID);
    if (pTarget != PATH_GetTargetUnit(pPath))
    {
        PATH_SetTargetUnit(pPath, 0);
    }

    if (!pTarget || pTarget->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    const int nAnimMode = pTarget->dwAnimMode;
    if (nAnimMode == IMODE_INBELT || nAnimMode == IMODE_EQUIP)
    {
        PATH_SetTargetUnit(pPath, 0);
    }
}

// 0x005537D0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate)
{
    D2_ASSERT(pGame, 1970);
    D2_ASSERT(pfIterate, 1971);

    D2UnitStrc** ppUnitList;
    if (nType == UNIT_PLAYER)
    {
        ppUnitList = pGame->pUnitList[0];
    }
    else if (nType == UNIT_MONSTER)
    {
        ppUnitList = pGame->pUnitList[1];
    }
    else
    {
        return 0;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)pfIterate), 1991);

    for (int i = 0; i < 128; ++i, ++ppUnitList)
    {
        for (D2UnitStrc* pUnit = *ppUnitList; pUnit; pUnit = pUnit->pListNext)
        {
            if (!STATES_CheckState(pUnit, STATE_PLAYERBODY) && pfIterate(pGame, pUnit, pArg) == 1)
            {
                return pUnit;
            }

            D2_ASSERT(pUnit, 222);
        }
    }

    return 0;
}

// 0x00553C70
void __fastcall sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    if (a3 <= 0)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    const int nCalc = nFrame - (pUnit->nSeqCurrentFramePrecise >> 8) - a3;
    pUnit->nSeqCurrentFramePrecise = (nFrame - nCalc) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        T00552FD0* pAnimData = pUnit->pAnimData;
        int nIndex = nCalc - 1;
        int nAnimFrame = nCalc << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553DC0
void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    pUnit->nSeqCurrentFramePrecise = (nFrame - a3) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        T00552FD0* pAnimData = pUnit->pAnimData;
        int nIndex = a3 - 1;
        int nAnimFrame = a3 << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553160
static int sub_00553160_RoomHasClients(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    return pRoom->nNumClients != 0;
}

// 0x00554850
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate)
{
    D2_ASSERT(pGame, 0x3FF);
    D2_ASSERT(pUnit, 0x403);

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    pUnit->pDrlgAct = pGame->pAct[pUnit->nAct];

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        sub_00534AD0_ResetModeAndEvents(pGame, pUnit, nX, nY);
        break;

    case UNIT_MONSTER:
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        MONSTER_SetVelocityAndPosition(pGame, pUnit, nX, nY, bSkipRoomUpdate);
        if (sub_00553160_RoomHasClients(pUnit))
        {
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
        }
        else
        {
            sub_00553220(pGame, pUnit);
        }
        break;

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        if (pObjectsTxtRecord->nHasCollision[pUnit->dwAnimMode])
        {
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        }

        D2_ASSERT(pRoom, 0x420);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }
    case UNIT_ITEM:
        if (pUnit->dwAnimMode == IMODE_ONGROUND)
        {
            UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
            if (pRoom)
            {
                UNITROOM_AddUnitToRoomEx(pUnit, pRoom, 0);
            }
        }
        break;

    case UNIT_MISSILE:
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        break;

    case UNIT_TILE:
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        D2_ASSERT(pRoom, 0x442);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;

    default:
        D2_ASSERT(0, 0x447);
        break;
    }

    sub_00553060_AddToUnitList(pUnit, pGame);

    if (UNITS_GetRoom(pUnit))
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    if (!bSkipRoomUpdate)
    {
        UNITS_SetCurrentRoomInvalid(pUnit, 1);
    }
}

// 0x00554A30
void __fastcall SUNIT_Restore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pGame, 0x45C);
    D2_ASSERT(pUnit, 0x45D);

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    pUnit->pDrlgAct = pGame->pAct[pUnit->nAct];
    pUnit->dwFlagEx &= ~UNITFLAGEX_HASBEENDELETED;

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
        pUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        sub_00534AD0_ResetModeAndEvents(pGame, pUnit, nX, nY);
        if (pUnit->dwAnimMode == PLRMODE_DEAD || pUnit->dwAnimMode == PLRMODE_DEATH)
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            sub_00649190_SetPathMode(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
            PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
        }
        break;

    case UNIT_MONSTER:
        PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
        pUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        MONSTER_SetVelocityAndPosition(pGame, pUnit, nX, nY, 0);
        if (sub_00553160_RoomHasClients(pUnit))
        {
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
        }
        else
        {
            sub_00553220(pGame, pUnit);
        }

        if (MONSTERS_IsDead(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            sub_00649190_SetPathMode(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
            PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
        }
        break;

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        if (pObjectsTxtRecord->nHasCollision[pUnit->dwAnimMode])
        {
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        }

        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }
    case UNIT_ITEM:
        if (pUnit->dwAnimMode == IMODE_ONGROUND)
        {
            UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
            UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
            UNITROOM_AddUnitToRoom(pUnit, pRoom);
            pUnit->pItemData->dwActionStamp = ITEMS_GetGroundRemovalTime(pGame, pUnit);
        }
        break;

    case UNIT_MISSILE:
        PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
        pUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(pGame->pMemoryPool, pRoom, nX, nY, pUnit, 0);
        break;

    case UNIT_TILE:
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;

    default:
        D2_ASSERT(0, 0x4AA);
        break;
    }

    if (UNITS_GetRoom(pUnit))
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    UNITS_SetCurrentRoomInvalid(pUnit, 1);
}

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00553590
void __fastcall sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond)
{
    D2_ASSERT(pFirst, 1875);
    D2_ASSERT(pSecond, 1877);

    pFirst->pObjectData->DestPortalCoords.nX = CLIENTS_GetUnitX(pSecond);
    pFirst->pObjectData->DestPortalCoords.nY = CLIENTS_GetUnitY(pSecond);

    pSecond->pObjectData->DestPortalCoords.nX = CLIENTS_GetUnitX(pFirst);
    pSecond->pObjectData->DestPortalCoords.nY = CLIENTS_GetUnitY(pFirst);

    D2ActiveRoomStrc* pSecondRoom = UNITS_GetRoom(pSecond);
    if (pSecondRoom)
    {
        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pSecondRoom, &drlgCoords);
        pFirst->pObjectData->DestRoomCooords.nX = drlgCoords.nTileXPos;
        pFirst->pObjectData->DestRoomCooords.nY = drlgCoords.nTileYPos;
    }

    D2ActiveRoomStrc* pFirstRoom = UNITS_GetRoom(pFirst);
    if (pFirstRoom)
    {
        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pFirstRoom, &drlgCoords);
        pSecond->pObjectData->DestRoomCooords.nX = drlgCoords.nTileXPos;
        pSecond->pObjectData->DestRoomCooords.nY = drlgCoords.nTileYPos;
    }
}

// 0x00553970
extern "C" __declspec(dllexport) void __fastcall sub_00553970(Obj00553970* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValueDC = dwValue;
    }
}

// 0x00553990
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
}

// 0x00554630
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->pGame && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        return PARTY_GetPartyIdForUnitOwner(pPlayer->pGame, pPlayer);
    }

    return -1;
}

// 0x00554D00
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType = pUnit->dwInteractType;
    int nUnitGUID = pUnit->dwInteractGUID;
    if (pUnit->nInteract)
    {
        return SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    }

    return 0;
}

// 0x00553B10
void __fastcall sub_00553B10(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    const int nCalc = (100 - a3) * (nFrame - (pUnit->nSeqCurrentFramePrecise >> 8)) / 100;
    pUnit->nSeqCurrentFramePrecise = (nFrame - nCalc) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        T00552FD0* pAnimData = pUnit->pAnimData;
        int nIndex = nCalc - 1;
        int nAnimFrame = nCalc << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553F00
void __fastcall sub_6FCBD3A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    sub_6FC35570(pGame, pUnit, EVENTTYPE_MODECHANGE, 0, 0);
}

// 0x00554100
extern "C" __declspec(dllexport) int __stdcall sub_00554100(Obj00554100* pObj, int* pOut68, int* pOut64) {
    *pOut64 = pObj->nValue64;
    *pOut68 = pObj->nValue68;
    return pObj->nValue6C;
}

// 0x00554190
extern "C" __declspec(dllexport) void __stdcall sub_00554190(Obj00554190* pObj) {
    pObj->nValue64 = -1;
    pObj->nValue68 = 6;
    pObj->nValue6C = 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pSkillsTxt[nSkillId];
}

static __forceinline int SUNIT_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }

    return -1;
}

// 0x005541B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    int bFlag = 0;
    if (pUnit)
    {
        bFlag = (pUnit->dwFlags >> 16) & 1;
    }

    if (bFlag)
    {
        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->dwAnimMode == PLRMODE_DEATH || pUnit->dwAnimMode == PLRMODE_DEAD)
        {
            return 1;
        }
        return 0;

    case UNIT_MONSTER:
        if (pUnit->dwAnimMode == MONMODE_DEATH || pUnit->dwAnimMode == MONMODE_DEAD)
        {
            return 1;
        }
        return 0;
    }

    return 1;
}

// 0x005542C0
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId)
{
    if (!pOwner || !pPet)
    {
        return 0;
    }

    const int nOwnerUnitType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerUnitType != UNIT_PLAYER && pPet->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETPET >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETPET & 7]))
    {
        return 0;
    }

    int nOwnerGUID;
    int nOwnerType;
    AIGENERAL_GetOwnerData(pPet, &nOwnerGUID, &nOwnerType);
    if (nOwnerType != UNIT_PLAYER || nOwnerGUID != SUNIT_GetUnitGUIDInline(pOwner))
    {
        return 0;
    }

    return 1;
}

// 0x00554340
static void __stdcall sub_00554340_UpdateAlignmentRegion(D2UnitStrc* pUnit, int nAlignment, int nAlignNew, int bUpdate)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pGame)
    {
        return;
    }
    if (bUpdate)
    {
        sub_00547DD0(pUnit->pGame->pMonReg, pUnit, nAlignment, nAlignNew);
    }
    if (nAlignment == nAlignNew)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    if (nAlignNew == UNIT_ALIGNMENT_GOOD)
    {
        sub_00619EE0(pRoom);
    }
    else if (nAlignment == UNIT_ALIGNMENT_GOOD)
    {
        sub_00619F20(pRoom);
    }
    if (!MONSTERS_IsDead(pUnit))
    {
        D2Common_10214(pUnit);
    }
}

// 0x005543B0
void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int bUpdate)
{
    const int nNew = nAlignNew;
    int nAlignment = UNIT_ALIGNMENT_UNASSIGNED;
    if (!pUnit)
    {
        return;
    }
    D2_ASSERT(nNew < UNIT_NUM_ALIGNMENT, 2994);
    const int nClassId = pUnit->dwClassId;
    if (nClassId != MONSTER_HYDRA1 && nClassId != MONSTER_HYDRA2 && nClassId != MONSTER_HYDRA3 && nNew == UNIT_ALIGNMENT_EVIL && sub_00451F30_TestUnitFlag(pUnit, 0x80000000))
    {
        return;
    }
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_ALIGNMENT);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(pUnit->pMemoryPool, 0, 0, pUnit->dwUnitType, pUnit->dwUnitId);
        D2_ASSERT(pStatList, 3012);
        STATLIST_SetState(pStatList, STATE_ALIGNMENT);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, STATE_ALIGNMENT, 1);
    }
    else
    {
        nAlignment = STATLIST_GetStatValue(pStatList, STAT_ALIGNMENT, 0);
    }
    STATLIST_SetStat(pStatList, STAT_ALIGNMENT, nNew, 0);
    STATES_ToggleGfxStateFlag(pUnit, STATE_ALIGNMENT, 1);
    sub_00554340_UpdateAlignmentRegion(pUnit, nAlignment, nNew, bUpdate);
}

// 0x00554570
int __fastcall sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventType, int a4, int a5)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }

    pPlayerData->nSkillCooldown148 = 0;
    pPlayerData->nSkillCooldown14C = 0;
    sub_6FC349B0(pGame, pPlayer, EVENTTYPE_REMOVESKILLCOOLDOWN, sub_6FCBDF90);
    return 1;
}

// 0x00554650
extern "C" __declspec(dllexport) int __fastcall sub_00554650(Obj00554650* pObj, unsigned int dwBits) {
    unsigned int dwFlags = pObj->dwFlags60;
    if (dwFlags & 0xF0) {
        return 0;
    }
    pObj->dwFlags60 = dwFlags | dwBits;
    return 1;
}

static __forceinline D2MonsterDataStrc* sub_00554670_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x00554670
void __fastcall sub_00554670_UpdateClientsOnRoomChange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    if (!UNITS_IsCurrentRoomInvalid(pUnit))
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        pRoom = sub_005545C0_GetValidNextRoom(pGame, pUnit);
    }
    if (pRoom && pCurrentRoom == pRoom)
    {
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = sub_00554670_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->unk0x50 = 0;
        }
    }

    D2ClientStrc** ppNewClients = 0;
    unsigned int nNewClients = 0;
    if (pCurrentRoom)
    {
        ppNewClients = pCurrentRoom->ppClients;
        nNewClients = pCurrentRoom->nNumClients;
    }

    D2ClientStrc** ppOldClients = 0;
    unsigned int nOldClients = 0;
    if (pRoom)
    {
        ppOldClients = pRoom->ppClients;
        nOldClients = pRoom->nNumClients;
    }

    unsigned int i = 0;
    unsigned int j = 0;
    while (i < nNewClients && j < nOldClients)
    {
        D2_ASSERT(ppNewClients, 262);
        D2_ASSERT(ppOldClients, 263);
        D2ClientStrc* pNewClient = ppNewClients[i];
        D2ClientStrc* pOldClient = ppOldClients[j];
        if (pNewClient < pOldClient)
        {
            if (pUnit != CLIENTS_GetPlayerFromClient(pNewClient, 0))
            {
                sub_00571F90(pGame, pUnit, ppNewClients[i]);
            }
            ++i;
        }
        else if (pNewClient > pOldClient)
        {
            if (pUnit != CLIENTS_GetPlayerFromClient(pOldClient, 0))
            {
                sub_00571600(pUnit, ppOldClients[j]);
            }
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }

    while (i < nNewClients)
    {
        D2_ASSERT(ppNewClients, 283);
        if (pUnit != CLIENTS_GetPlayerFromClient(ppNewClients[i], 0))
        {
            sub_00571F90(pGame, pUnit, ppNewClients[i]);
        }
        ++i;
    }

    while (j < nOldClients)
    {
        D2_ASSERT(ppOldClients, 289);
        if (pUnit != CLIENTS_GetPlayerFromClient(ppOldClients[j], 0))
        {
            sub_00571600(pUnit, ppOldClients[j]);
        }
        ++j;
    }

    sub_00648B40_roomInvalid(pUnit->pDynamicPath, 0);
}

// 0x00554CA0
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2_ASSERT(pGame, 1838);

    sub_6FCBC7E0(pGame, pMissile);
    const int v4 = D2Common_10226(pMissile, 1024) ? 1 : 2;
    if (UNITS_IsCurrentRoomInvalid(pMissile))
    {
        sub_6FCBB190(pGame, pMissile, 0);
    }

    return v4;
}

// 0x00555600
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 0x59);
    D2_ASSERT(pUnit, 0x5C);
    D2_ASSERT(pUnit->dwUnitType < NUM_UNIT_TYPES, 0x61);

    sub_00555580_DetachUnit(pUnit, pGame, 0);

    if (pUnit->pQuestEventList)
    {
        QUESTS_FreeChainRecord(pGame, pUnit->pQuestEventList);
        pUnit->pQuestEventList = 0;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        D2GAME_FreeUnitNode_6FC40310(pGame, pUnit);
        sub_00535430(pGame, pUnit);
        PARTY_LeaveParty(pGame, pUnit);
        PLAYER_Destroy(pGame, pUnit);

        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }
        break;

    case UNIT_MONSTER:
        sub_005B1A90(pGame, pUnit);

        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }

        MONSTER_Free(pGame, pUnit);
        break;

    case UNIT_OBJECT:
        OBJECTS_FreeHoverMessage(pGame, pUnit);
        UNITS_FreeStaticPath(pUnit);
        FOG_FreePool(pGame->pMemoryPool, pUnit->f_14, ".\\UNIT\\SUnit.cpp", 0xA4, 0);
        break;

    case UNIT_MISSILE:
        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }

        MISSILES_Free(pGame, pUnit);
        break;

    case UNIT_ITEM:
        ITEMS_FreeSocketInventoryAndTimers(pGame, pUnit);
        ITEMS_FreeItemData(pGame->pMemoryPool, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_TILE:
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    SUNITEVENT_FreeEventList(pGame, pUnit);
    D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(pUnit);
    UNITS_FreeUnit(pUnit);
}

// 0x00555770
void __fastcall sub_00555770_RemoveAllTiles(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x12D);
    D2UnitStrc* pTile = pGame->pTileList;
    while (pTile)
    {
        D2UnitStrc* pCurrent = pTile;
        pTile = pTile->pListNext;
        SUNIT_RemoveUnit(pGame, pCurrent);
    }
    pGame->pTileList = 0;
}

// 0x00555CC0
int __cdecl sub_00555CC0_GetItemsTxtCount()
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (!pItemDataTbl)
        return 0;
    return pItemDataTbl->nItemsTxtRecordCount;
}

// 0x00555910
void __fastcall SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    D2DrlgCoordsStrc pCoord;

    DUNGEON_GetRoomCoordinates(pRoom, &pCoord);

    const int nX = pPresetUnit->nXpos + pCoord.nSubtileX;
    const int nY = pPresetUnit->nYpos + pCoord.nSubtileY;
    D2UnitStrc* pUnit = SUNIT_CreatePresetUnit(pGame, pRoom, pPresetUnit->nUnitType, pPresetUnit->nIndex, nX, nY, pPresetUnit->nMode, 0);
    if (!pUnit)
    {
        return;
    }

    if (pPresetUnit->nUnitType == UNIT_MONSTER)
    {
        D2MapAIStrc** ppPresetMapAI = &pPresetUnit->pMapAI;
        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (*ppPresetMapAI)
        {
            DRLGPRESET_ChangeMapAI(ppPresetMapAI, pMapAI);
        }
    }
    else if (pPresetUnit->nUnitType == UNIT_OBJECT)
    {
        QUESTS_MapPresetSpawn(pGame, pUnit, pPresetUnit->pMapAI);
    }
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

// 0x00555AE0
void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x9D6);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory);
    while (i)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(i);

        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        D2_ASSERT(pItem, 0x9E9);

        if (pItem->dwUnitType == UNIT_ITEM)
        {
            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);

            if (INVENTORY_GetItemNodePage(i) == 3)
            {
                sub_0063BE30(pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, pItem));
            }
            else if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                const unsigned char nPage = ITEMS_GetInvPage(pItem);
                const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion);
                INVENTORY_Return(".\\UNIT\\SUnit.cpp", 0xA03, pInventory, UNITS_GetUnitXPosition(pItem), UNITS_GetUnitYPosition(pItem), nInventoryRecordId, 0, nPage);
            }
        }

        D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA07);

        if (pItem->dwUnitType < UNIT_TYPES_COUNT)
        {
            SUNIT_RemoveUnit(pGame, pItem);
        }

        i = pNext;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem && pCursorItem->dwUnitType < UNIT_TYPES_COUNT)
    {
        SUNIT_RemoveUnit(pGame, pCursorItem);
    }
}
