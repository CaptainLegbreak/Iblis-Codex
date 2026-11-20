#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act5Quest3Strc;
struct D2MonsterDataStrc;
struct D2StaticPathStrc;
struct D2ModeChangeStrc;
struct D2MapAIHolderStrc;
struct D2ObjInitFnStrc;
union D2SeedStrc;
struct D2GSPacketSrv5D;
struct D2ItemsTxt;
struct D2QuestRewardItemsStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2CoordStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;
struct D2MapAIStrc;



struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    unsigned short nGUIDCount;
    unsigned short unk0x82;
};


struct D2Act5Quest3Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    int unk0x84;
    int unk0x88;
    int nTimerInvocations;
    unsigned char bDrehyaIcedMonsterSpawned;
    unsigned char bDrehyaMonsterInTownSpawned;
    unsigned char bNilathakOutsideTownSpawned;
    unsigned char bNihlathakMonsterInTownSpawned;
    int nDrehyaMonsterInTownGUID;
    int nDrehyaIcedMonsterGUID;
    int NihlathakMonsterInTownGUID;
    int nNihlathakOutsideTownGUID;
    unsigned char bFrozenAnyaObjectSpawned;
    unsigned char pad0xA5[3];
    int nFrozenDrehyaObjectGUID;
    unsigned char bMalahIntroActivated;
    unsigned char bChangeToSpecialObjectModeOutsideTown;
    unsigned char bChangeToSpecialObjectModeInTown;
    unsigned char pad0xAF;
    unsigned char unused0xB0;
    unsigned char bDrehyaPortalOutsideTownSpawned;
    unsigned char bDrehyaPortalInTownSpawned;
    unsigned char unused0xB3;
    int nDrehyaPortalInTownGUID;
    unsigned char unk_B8[0x20];
    int nDefrostPotionsInGame;
    unsigned char unk_DC[0x5];
    unsigned char bDrehyaInTownInitialized;
    unsigned char bDefrostPotionAcquired;
    unsigned char bDrehyaIcedRemoved;
    int nDrehyaObjectInTownGUID;
    D2CoordStrc pDrehyaObjectInTownCoords;
    D2CoordStrc pDrehyaObjectOutsideTownCoords;
    int nDrehyaObjectOutsideTownGUID;
    int nFrozenAnyaObjectGUID;
    unsigned char bTimerActive;
    unsigned char bMalahActivated;
    unsigned char unk_102;
    unsigned char pad0x103;
    D2MapAIStrc* pDrehyaMapAI;
    D2MapAIStrc* pNilathakMapAI;
    unsigned char bDrehyaMapAIChanged;
    unsigned char bNilathakMapAIChanged;
    unsigned char pad0x10E[2];
    int nNihlathakObjectInTownGUID;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    D2Act5Quest3Strc* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    unsigned char unk_A0[0x40];
    int eFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        int nOldLevel;
        D2TextHeaderStrc* pTextControl;
    };
    int nNewLevel;
};

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

struct D2MapAIStrc
{
    void* unk0x00;
    void* pPosition;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};


struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
D2UnitStrc* __fastcall sub_005459A0_SpawnMonsterNear(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int a5, int nMonsterId); // 0x005459A0
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0
void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pUnit, void(__fastcall* pfCallback)(D2UnitStrc*), int a4); // 0x00573180
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath); // 0x00648730
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00589160
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588EB0
int __fastcall ACT5Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588F10
int __fastcall ACT5Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00589AA0
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc*, D2TextHeaderStrc*, int, int); // 0x00543790
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc*, int); // 0x005452C0
extern const unsigned int gnAct5Q3MessageIndices_00734304[]; // 0x00734304
static void sub_005893E0_RemoveTownNpcs(D2QuestDataStrc* pQuestData);

struct D2MapAIHolderStrc
{
    int unk0x00;
    void* pPosition;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    void* pObjectregion;
    void* pObjectTxt;
    int nX;
    int nY;
};

static __declspec(noinline) void __stdcall ACT5Q3_SpawnDrehyaInTown(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx);
static void __stdcall sub_005891D0_SpawnDrehyaInTown(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx); // 0x005891D0
// 0x00589340
static void sub_00589340_RemoveNihlathakInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pNihlathak); // 0x00589340


struct D2GSPacketSrv5D { unsigned char nHeader, nQuestId, nFlags, nState; unsigned short field_4; };


struct D2QuestRewardItemsStrc { unsigned int* pCodes; int nCount; };

extern D2QuestRewardItemsStrc gNormalRewards[]; // 0x00735F6C
extern D2QuestRewardItemsStrc gNightmareRewards[]; // 0x00735EFC
extern D2QuestRewardItemsStrc gHellRewards[]; // 0x00735F34
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc*); // 0x005438B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00545780
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc*, D2UnitStrc*); // 0x005455B0
D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc*, D2UnitStrc*, unsigned int, int, int, int); // 0x005466B0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*, const char*, int); // 0x005531C0
void __fastcall sub_6FC3F380(D2ClientStrc*, D2GSPacketSrv5D*); // 0x0053D710
int __fastcall ACT5Q3_RemoveDrehyaIced(D2GameStrc*, D2UnitStrc*, void*); // 0x005890B0
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc*, int, int); // 0x0065C3A0
unsigned int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc*, int); // 0x00558200
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
extern "C" void* __cdecl memset(void*, int, unsigned int);

// 0x00589000
void __fastcall ACT5Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 4)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 1);
    }
}

static __forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nX;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 2 || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nY;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005891D0
static void __stdcall ACT5Q3_SpawnDrehyaInTown(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx)
{
    if (pQuestDataEx->bDrehyaInTownInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pDrehyaInTown = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nDrehyaObjectInTownGUID);
    if (!pDrehyaInTown)
    {
        return;
    }

    D2ObjInitFnStrc op;
    op.pRoom = UNITS_GetRoom(pDrehyaInTown);
    op.nX = CLIENTS_GetUnitX(pDrehyaInTown);
    op.nY = CLIENTS_GetUnitY(pDrehyaInTown);
    if (pQuestDataEx->bDrehyaMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pDrehya = sub_005459A0_SpawnMonsterNear(pQuestData->pGame, op.nX, op.nY, op.pRoom, 1, 0x200);
    if (!pDrehya)
    {
        return;
    }

    pQuestDataEx->nDrehyaMonsterInTownGUID = !pDrehya ? -1 : pDrehya->dwUnitId;
    pQuestDataEx->bDrehyaMonsterInTownSpawned = 1;

    D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pDrehya);
    if (pQuestDataEx->pDrehyaMapAI && ((D2MapAIHolderStrc*)pQuestDataEx->pDrehyaMapAI)->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
    {
        pQuestDataEx->bDrehyaMapAIChanged = 1;
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, pMapAI);
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pDrehya, &pCoord);

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pDrehya), pCoord.nX, pCoord.nY);
    if (pRoom)
    {
        D2UnitStrc* pDrehyaPortal = SUNIT_AllocUnitData(2, 0xBD, pCoord.nX, pCoord.nY, pQuestData->pGame, pRoom, 1, 1, 0);
        if (pDrehyaPortal)
        {
            pQuestDataEx->bDrehyaPortalInTownSpawned = 1;
            pQuestDataEx->nDrehyaPortalInTownGUID = !pDrehyaPortal ? -1 : pDrehyaPortal->dwUnitId;
        }
    }

    ACT5Q3_SeqCallback(pQuestData);
}

static __forceinline int CLIENTS_GetUnitX_A5Q3(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitY_A5Q3(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context sub_005891D0_SpawnDrehyaInTown
static void __stdcall sub_005891D0_SpawnDrehyaInTown(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx)
{
    if (pQuestDataEx->bDrehyaInTownInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pDrehyaInTown = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nDrehyaObjectInTownGUID);
    if (!pDrehyaInTown)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pDrehyaInTown);
    const int nX = CLIENTS_GetUnitX_A5Q3(pDrehyaInTown);
    const int nY = CLIENTS_GetUnitY_A5Q3(pDrehyaInTown);
    if (pQuestDataEx->bDrehyaMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pDrehya = sub_005459A0_SpawnMonsterNear(pQuestData->pGame, nX, nY, pRoom, 1, 0x200);
    if (!pDrehya)
    {
        return;
    }

    pQuestDataEx->nDrehyaMonsterInTownGUID = pDrehya->dwUnitId;
    pQuestDataEx->bDrehyaMonsterInTownSpawned = 1;

    D2MapAIStrc* pMapAi = AIGENERAL_GetMapAiFromUnit(pDrehya);
    if (pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
    {
        pQuestDataEx->bDrehyaMapAIChanged = 1;
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, pMapAi);
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pDrehya, &pCoord);

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pDrehya), pCoord.nX, pCoord.nY);
    if (pTargetRoom)
    {
        D2UnitStrc* pDrehyaPortal = SUNIT_AllocUnitData(2, 0xBD, pCoord.nX, pCoord.nY, pQuestData->pGame, pTargetRoom, 1, 1, 0);
        if (pDrehyaPortal)
        {
            pQuestDataEx->bDrehyaPortalInTownSpawned = 1;
            pQuestDataEx->nDrehyaPortalInTownGUID = pDrehyaPortal->dwUnitId;
        }
    }

    ACT5Q3_SeqCallback(pQuestData);
}

// 0x00589340
static void sub_00589340_RemoveNihlathakInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pNihlathak)
{
    D2MonsterInteractStrc* pMonInteract = pNihlathak && pNihlathak->dwUnitType == 1 && pNihlathak->pMonsterData ? pNihlathak->pMonsterData->pMonInteract : 0;
    if (MONSTERAI_HasInteractUnit(pMonInteract))
    {
        sub_00573180(pQuestData->pGame, pNihlathak, 0, 0);
    }

    D2Common_10153(pNihlathak->pDynamicPath);
    D2GAME_EVENTS_Delete_6FC34840(pQuestData->pGame, pNihlathak, 2, 0);
    STATLIST_SetUnitStat(pNihlathak, 6, 0, 0);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pNihlathak, 12, &modeChange);
    modeChange.nX = 0;
    modeChange.nY = 0;
    D2GAME_ModeChange_6FC65220(pQuestData->pGame, &modeChange, 1);
    UNITROOM_RefreshUnit(pNihlathak);
    pNihlathak->dwFlags |= 1;
}

// 0x005893E0
static void sub_005893E0_RemoveTownNpcs(D2QuestDataStrc* pQuestData)
{
    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrehyaMonsterInTownSpawned && pQuestDataEx->unk0x84 != 2)
    {
        D2UnitStrc* pDrehya = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nDrehyaMonsterInTownGUID);
        if (pDrehya)
        {
            D2MonsterInteractStrc* pMonInteract = pDrehya->dwUnitType == 1 && pDrehya->pMonsterData ? pDrehya->pMonsterData->pMonInteract : 0;
            if (MONSTERAI_HasInteractUnit(pMonInteract))
            {
                sub_00573180(pQuestData->pGame, pDrehya, 0, 0);
            }

            D2ModeChangeStrc modeChange;
            MONSTERMODE_GetModeChangeInfo(pDrehya, 12, &modeChange);
            D2GAME_ModeChange_6FC65220(pQuestData->pGame, &modeChange, 1);

            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pDrehya), !pDrehya ? 6 : pDrehya->dwUnitType, pQuestDataEx->nDrehyaMonsterInTownGUID);
            UNITS_FreeCollisionPath(pDrehya);
            UNITROOM_RemoveUnitFromRoom(pDrehya);
        }
        else
        {
            SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x200, 4);
        }

        pQuestDataEx->bDrehyaMonsterInTownSpawned = 0;
    }

    if (pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        D2UnitStrc* pNihlathak = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->NihlathakMonsterInTownGUID);
        if (pNihlathak)
        {
            sub_00589340_RemoveNihlathakInTown(pQuestData, pNihlathak);

            const int nObjectGUID = pQuestDataEx->nNihlathakObjectInTownGUID;
            D2UnitStrc* pNihlathakInTown = SUNIT_GetServerUnit(pQuestData->pGame, 2, nObjectGUID);
            if (pNihlathakInTown)
            {
                D2GameStrc* pGame = pQuestData->pGame;
                const int nFrame = pGame->dwGameFrame;
                EVENT_SetEvent(pGame, pNihlathakInTown, 7, nFrame + 1, 0, 0);
            }
        }
        else
        {
            SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x202, 4);
        }

        pQuestDataEx->bNihlathakMonsterInTownSpawned = 0;
    }

    if (!pQuestDataEx->unk0x88)
    {
        pQuestDataEx->unk0x88 = 1;
    }
}

// 0x00589540
void __fastcall sub_00589540_RemoveNihlathakFromTown(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    D2UnitStrc* pNihlathak = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->NihlathakMonsterInTownGUID);
    if (pNihlathak)
    {
        sub_00589340_RemoveNihlathakInTown(pQuestData, pNihlathak);
    }
}

void __fastcall sub_005891D0_EmitCaller(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx)
{
    ACT5Q3_SpawnDrehyaInTown(pQuestData, pQuestDataEx);
    ACT5Q3_SeqCallback(pQuestData);
}

static __forceinline D2BitBufferStrc* QUESTS_GetPlayerFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00589580
void __fastcall ACT5Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    const unsigned short nNpcId = (unsigned short)pQuestArg->nOldLevel;
    const unsigned short nMessage = (unsigned short)pQuestArg->nNewLevel;
    D2BitBufferStrc* pQuestFlags = QUESTS_GetPlayerFlags(pGame, pQuestArg->pPlayer);
    if (nNpcId == 513)
    {
        if (nMessage == 20116)
        {
            pQuestDataEx->bMalahIntroActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x208);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }
        if (nMessage == 20127)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' eci') || pQuestDataEx->nDefrostPotionsInGame)
                return;
            if (!QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' eci', 0, 2, 1))
                return;
            ++pQuestDataEx->nDefrostPotionsInGame;
            D2ClientStrc* pClient = UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x214);
            D2GSPacketSrv5D packet;
            memset(&packet, 0, sizeof(packet));
            packet.nHeader = 0x5D;
            packet.nQuestId = 33;
            packet.nFlags = 1;
            sub_6FC3F380(pClient, &packet);
            pQuestDataEx->bMalahActivated = 1;
            return;
        }
        if (nMessage == 20132)
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 1) && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 0))
            {
                if (!QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2rt', 0, 2, 1))
                    return;
                QUESTRECORD_SetQuestState(pQuestFlags, 37, 8);
                D2ClientStrc* pClient = UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x22B);
                D2GSPacketSrv5D packet;
            memset(&packet, 0, sizeof(packet));
                packet.nHeader = 0x5D;
                packet.nQuestId = 33;
                packet.nFlags = 2;
                sub_6FC3F380(pClient, &packet);
                if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 9))
                {
                    QUESTRECORD_ClearQuestState(pQuestFlags, 37, 1);
                    QUESTRECORD_SetQuestState(pQuestFlags, 37, 0);
                }
                else if (pQuestData->bNotIntro && pQuestData->fLastState < 6)
                {
                    pQuestData->dwFlags &= 0xFFFFFF00;
                    QUESTS_UnitIterate(pQuestData, 6, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
                }
                if (pQuestDataEx->unk0x84 == 1)
                {
                    pQuestDataEx->bDrehyaIcedRemoved = 0;
                    SUNIT_IterateUnitsOfType(pQuestData->pGame, 1, 0, ACT5Q3_RemoveDrehyaIced);
                    if (!pQuestDataEx->bDrehyaIcedRemoved)
                        SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 527, 4);
                    pQuestDataEx->bChangeToSpecialObjectModeOutsideTown = 1;
                    pQuestDataEx->unk0x84 = 2;
                    sub_005891D0_SpawnDrehyaInTown(pQuestData, pQuestDataEx);
                }
                QUESTS_UpdatePlayerFlags(pQuestArg->pGame, pQuestArg->pPlayer);
                return;
            }
            if ((QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
                && !pQuestDataEx->unk_102 && QUESTRECORD_GetQuestState(pQuestFlags, 37, 8)
                && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 7)
                && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2rt'))
            {
                if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2rt', 0, 2, 1))
                    pQuestDataEx->unk_102 = 1;
            }
            return;
        }
    }
    else if (nNpcId == 512 && nMessage == 20136)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 37, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 37, 0))
            return;
        D2QuestRewardItemsStrc* pRewardTable = gNormalRewards;
        const unsigned int nLevel = STATLIST_GetUnitBaseStat(pQuestArg->pPlayer, 12, 0);
        switch (pQuestArg->pGame->nDifficulty)
        {
        case 1:
            if (pQuestArg->pGame->nGameType == 3 || nLevel > 45)
                pRewardTable = gNightmareRewards;
            break;
        case 2:
            if (pQuestArg->pGame->nGameType == 3 || nLevel > 65)
                pRewardTable = gHellRewards;
            break;
        }
        if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 10))
            return;
        const int nClassId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;
        const unsigned int nIndex = SEED_RollLimitedRandomNumber(QUESTS_GetGlobalSeed(pQuestArg->pGame), pRewardTable[nClassId].nCount);
        const unsigned int nCode = pRewardTable[nClassId].pCodes[nIndex];
        D2UnitStrc* pItem = QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, nCode, ITEMS_GetItemLevelForNewItem(pQuestArg->pPlayer, 0), 6, 1);
        if (!pItem)
            return;
        const int nItemClassId = pItem->dwClassId;
        D2GSPacketSrv5D packet;
        memset(&packet, 0, sizeof(packet));
        packet.nHeader = 0x5D;
        packet.nFlags = 16;
        packet.nQuestId = 33;
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nItemClassId);
        if (pItemsTxt && pItemsTxt->wDropSound > 0)
            packet.field_4 = pItemsTxt->wDropSound;
        sub_6FC3F380(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x375), &packet);
        QUESTRECORD_SetQuestState(pQuestFlags, 37, 9);
        if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 8))
        {
            QUESTRECORD_ClearQuestState(pQuestFlags, 37, 1);
            QUESTRECORD_SetQuestState(pQuestFlags, 37, 0);
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 37, 10);
        return;
    }
    if (nMessage == 20131 && pQuestData->bNotIntro)
    {
        if (pQuestData->fState <= 3)
        {
            QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x387);
            sub_005893E0_RemoveTownNpcs(pQuestData);
        }
        if (pQuestData->fLastState < 3)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        }
    }
}

// 0x00589A50
int __fastcall ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0xD))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q3_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00589AA0
int __fastcall ACT5Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x21, 0);
    }

    return 0;
}

// 0x00589B00
void __fastcall ACT5Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (nNpcId == 527)
    {
        if (pQuestData->fState == 6)
        {
            D2ModeChangeStrc mode;
            MONSTERMODE_GetModeChangeInfo(pQuestArg->pTarget, 12, &mode);
            D2GAME_ModeChange_6FC65220(pQuestArg->pGame, &mode, 1);
        }
        return;
    }
    if (nNpcId == 513)
    {
        if (pQuestData->fState == 4)
        {
            if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20656369) && !pQuestDataEx->nDefrostPotionsInGame)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 513, 3);
            return;
        }
        if ((QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 15))
            && !pQuestDataEx->unk_102 && QUESTRECORD_GetQuestState(pFlags, 37, 8)
            && !QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 7)
            && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20327274)
            && !QUESTRECORD_GetQuestState(pFlags, 37, 8))
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 513, 5);
    }
    if (QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 1))
    {
        if (nNpcId == 512 && QUESTRECORD_GetQuestState(pFlags, 37, 9)) return;
        if (nNpcId == 513 && QUESTRECORD_GetQuestState(pFlags, 37, 8)) return;
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }
    if (bRewardGranted != 1 && (pQuestData->fState < 5 || bPrimaryGoalDone) && pQuestData->bNotIntro)
    {
        const unsigned int nIndex = gnAct5Q3MessageIndices_00734304[pQuestData->fState];
        if (nIndex != -1 && nIndex < 10)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00589D20
void __fastcall ACT5Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' eci'))
    {
        --pQuestDataEx->nDefrostPotionsInGame;
    }
}

// 0x00589D80
void __fastcall ACT5Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestArg->nNewLevel == 0x70)
    {
        if (pQuestData->bNotIntro && !pQuestData->fState)
        {
            pQuestData->fState = 1;
            sub_005893E0_RemoveTownNpcs(pQuestData);
        }
    }
    else if ((pQuestArg->nNewLevel == 0x71 || pQuestArg->nNewLevel == 0x72) && pQuestData->bNotIntro)
    {
        bool bStateChanged = false;
        if (pQuestData->fState <= 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x451);
            bStateChanged = true;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
        }
        else if (bStateChanged)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
        }

        sub_005893E0_RemoveTownNpcs(pQuestData);
    }

    if (nOldLevel == 0x6D)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x46E);
            if (!pQuestData->fLastState)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
            }
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel < 0x79 || nNewLevel > 0x7C || !pQuestData->bNotIntro || pQuestData->fState >= 5)
    {
        return;
    }

    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q3_UnitIterate_SetCompletionFlag);
    pQuestData->fState = 6;

    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    pQuestDataEx->unk0x84 = 2;
    if (!pQuestDataEx->unk0x88)
    {
        pQuestDataEx->unk0x88 = 1;
    }
}

// 0x0058A980
void __fastcall sub_6FCB53D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    pQuestDataEx->bChangeToSpecialObjectModeOutsideTown = 1;
    pQuestDataEx->unk0x84 = 2;
    sub_005891D0_SpawnDrehyaInTown(pQuestData, pQuestDataEx);
}

// 0x0058AAB0
bool __fastcall ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest3Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDrehyaIcedMonsterSpawned)
    {
        D2UnitStrc* pFrozenDrehya = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nFrozenAnyaObjectGUID);
        if (!pQuestDataEx->nTimerInvocations)
        {
            if (pFrozenDrehya)
            {
                UNITS_ChangeAnimMode(pFrozenDrehya, 2);
                UNITS_FreeCollisionPath(pFrozenDrehya);
            }

            pQuestDataEx->nTimerInvocations = 1;
        }
        else if (pQuestDataEx->nTimerInvocations == 1)
        {
            pQuestDataEx->nTimerInvocations = 2;
            if (pFrozenDrehya)
            {
                D2UnitStrc* pDrehya = sub_005459A0_SpawnMonsterNear(pGame, pQuestDataEx->pDrehyaObjectOutsideTownCoords.nX, pQuestDataEx->pDrehyaObjectOutsideTownCoords.nY, UNITS_GetRoom(pFrozenDrehya), 1, 0x20F);
                if (pDrehya)
                {
                    const int nUnitGUID = pFrozenDrehya->dwUnitId;
                    const int nUnitType = pFrozenDrehya->dwUnitType;
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pFrozenDrehya), nUnitType, nUnitGUID);
                    UNITROOM_RemoveUnitFromRoom(pFrozenDrehya);

                    D2MapAIStrc* pMapAi = AIGENERAL_GetMapAiFromUnit(pDrehya);
                    if (pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
                    {
                        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, pMapAi);
                        pQuestDataEx->bDrehyaMapAIChanged = 1;
                    }

                    const int nDrehyaGUID = (pDrehya ? pDrehya->dwUnitId : -1);
                    pQuestDataEx->nDrehyaIcedMonsterGUID = nDrehyaGUID;
                    pQuestDataEx->bDrehyaIcedMonsterSpawned = 1;
                    ACT5Q3_SeqCallback(pQuestData);
                    pQuestDataEx->bTimerActive = 0;
                    return true;
                }
            }
        }
    }

    return false;
}

#include "gen/data/Source/D2Game/Quests/a5q3.inc"
