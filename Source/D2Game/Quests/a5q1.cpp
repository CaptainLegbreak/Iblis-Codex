#include "D2Game.h"
#include "D2Structs.h"

#define MONSTER_AKARA 148
#define MONSTER_KASHYA 150
#define MONSTER_WARRIV1 155
#define MONSTER_LARZUK 511
#define MONSTER_MALAH 513
#define QUEST_A1Q4_CAIN 4
#define QUEST_A5Q3_PRISONOFICE 33
#define QUEST_A5Q6_BAAL 36
#define QUESTSTATEFLAG_A5Q6 40
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_CUSTOM1 5
#define QFLAG_PRIMARYGOALDONE 13
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define MONMODE_DEAD 12
#define MONSTER_DREHYA 512
#define MONSTER_DREHYAICED 527
#define MONSTER_ACT5POW 534
#define QUESTSTATEFLAG_A5Q4 38
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM4 8
#define ITEMCODE_DEFROST_POTION 0x20656369

struct D2ObjectControlStrc;
struct D2PlayerDataStrc;
struct D2Act5Quest1Strc;
struct D2Act5Quest3Strc;
struct D2Act1Quest4Strc;
struct D2GSPacketSrv5D;
struct D2MonsterDataStrc;
struct D2ModeChangeStrc;
struct D2Act5Quest2Strc;
struct D2ObjInitFnStrc;
struct D2ObjOperateFnStrc;
struct D2CoordStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2MapAIStrc;
struct D2QuestArgStrc;
struct D2QuestGUIDStrc;
struct D2Act4Quest2Strc;
struct D2Act4Quest3Strc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x2];
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};


struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

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
    unsigned char nFlagsLowByte;
    char unk0x15[0x03];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    void* pfStatusFilter;
    void* pfActiveFilter;
    void* pfSeqFilter;
};

struct D2Act5Quest1Strc
{
    D2MapAIStrc* pLarzukMapAI;
    D2ActiveRoomStrc* pRoom;
    unsigned char bLarzukStartActivated;
    unsigned char unused0x09[7];
    int nLarzukGUID;
    unsigned char unused0x14;
    unsigned char bLarzukSpawned;
    unsigned char bLarzukEndActivated;
    unsigned char bLarzukMapAIChanged;
};

struct D2Act5Quest3Strc
{
    char tPlayerGUIDs[0x84];
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
    unsigned char unk_AC[0x2];
    unsigned char bChangeToSpecialObjectModeInTown;
    unsigned char unk_AF[0x2];
    unsigned char bDrehyaPortalOutsideTownSpawned;
    unsigned char bDrehyaPortalInTownSpawned;
    char unk0xB3[0x05];
    D2CoordStrc tDrehyaPortalInTownCoords;
    unsigned char unk_C0[0x4];
    D2CoordStrc pDrehyaPortalCoords;
    unsigned char unused0xCC[12];
    int nDefrostPotionsInGame;
    int nObjectUpdateInvocations;
    unsigned char bDrehyaPortalCoordsInitialized;
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
    unsigned char bRewarded;
    unsigned char pad0x103;
    D2MapAIStrc* pDrehyaMapAI;
    D2MapAIStrc* pNilathakMapAI;
    unsigned char bDrehyaMapAIChanged;
    unsigned char bNilathakMapAIChanged;
    unsigned char unk_10E[0x2];
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x28];
    int nInvisibleObjectGUID;
    char unk0x2C[0x1D];
    unsigned char bInvisbleObjectInitialized;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

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
    int nData[8];
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
        D2TextHeaderStrc* pTextControl;
        int nOldLevel;
        unsigned short nNPCNo;
    };
    unsigned short nMessageIndex;
    unsigned char unk_1A[0x2];
};

struct D2Act5Quest2Strc
{
    char tPlayerGUIDs[0x84];
    unsigned char bQualKehkActivated;
    unsigned char unused0x85;
    unsigned char bWussiesSpawned[3];
    unsigned char pad0x89[3];
    D2CoordStrc pWussieCoords[3];
    int nSpawnedWussies;
    int nKilledWussies;
    char unk0xAC[0x62];
    unsigned char unk0x10E[3];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    D2ObjectControlStrc* pObjectregion;
    void* pObjectTxt;
    int nX;
    int nY;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

extern unsigned int gnA5Q1NpcIndices_00733928[]; // 0x00733928
extern unsigned int gnA5Q4NpcIndices_007350E8[]; // 0x007350E8
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, int bCheckActive); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwCode); // 0x00558110
int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0
void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pUnit, void(__fastcall* pfCallback)(D2UnitStrc*), int a4); // 0x00573180
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005879D0
int __fastcall ACT5Q2_SpawnCagedWussies(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp, int nCount); // 0x00588600
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588EB0
void __fastcall ACT5Q3_SendPacket0x5DToClient(D2UnitStrc* pUnit); // 0x00589070
int __fastcall ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00589A50
int __fastcall ACT5Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00589AA0
bool __fastcall ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0058AAB0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset); // 0x0061AED0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2MapAIStrc* __fastcall DRLGPRESET_CreateCopyOfMapAI(void* pMemPool, D2MapAIStrc* pMapAI); // 0x006660B0
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);

struct D2Act4Quest2Strc
{
    char pad0x00[0x14];
    unsigned char bDiabloKilled;
};

struct D2Act4Quest3Strc
{
    char pad0x00[0x02];
    unsigned char bCainActivated;
    char pad0x03[0x0D];
    int nHellforgeHammersInGame;
    char pad0x14[0x08];
    unsigned char bSoulstoneAcquired;
};

extern "C" const char gszAct4Q3SourceFile[];
extern char gpAct4Q3NpcMessages[];
extern char gpAct4Q4NpcMessages[];
extern char gpAct3IntroNpcMessages[];
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);
int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData);
void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT4Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

// 0x00586C50
bool __fastcall ACT5Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_MALAH))
    {
        return true;
    }

    return false;
}

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00586FF0
void __fastcall ACT5Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_PRIMARYGOALDONE);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDPENDING))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_CUSTOM1))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
    }
    else if (bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone))
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        const unsigned int nIndex = gnA5Q1NpcIndices_00733928[pQuestData->fState];
        if (nIndex != -1 && nIndex < 8)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005870D0
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x00587100
int __fastcall ACT5Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED))
    {
        D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK)->pQuestDataEx;
        bool bFound = false;
        if (pRoom == pQuestDataEx->pRoom)
        {
            bFound = true;
        }
        else
        {
            D2ActiveRoomStrc** ppRoomList;
            unsigned int nNumRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
            for (unsigned int i = 0; i < nNumRooms; ++i)
            {
                if (ppRoomList[i] == pQuestDataEx->pRoom)
                {
                    bFound = true;
                    break;
                }
            }
        }

        pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (bFound)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE);
        }
    }

    return 0;
}

#include "gen/data/Source/D2Game/Quests/a5q1.inc"

static __forceinline D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
}

// 0x005872F0
int __fastcall ACT5Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (QUESTRECORD_GetQuestState(GetQuestFlags(pGame, pUnit), 35, 13))
        SUNIT_AttachSound(pUnit, 80, pUnit);
    return 0;
}

// 0x005874E0
bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_LARZUK)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_CUSTOM1))
        {
            return true;
        }

        if (pQuest->bNotIntro && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }

    return false;
}

// 0x00587950
void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);
    if (!pQuestData || !pMapAi)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pLarzukMapAI = DRLGPRESET_CreateCopyOfMapAI(pQuestData->pGame->pMemoryPool, pMapAi);
    if (!pQuestDataEx->bLarzukSpawned)
    {
        return;
    }

    D2UnitStrc* pLarzuk = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_MONSTER, pQuestDataEx->nLarzukGUID);
    if (pLarzuk && pQuestDataEx->pLarzukMapAI && pQuestDataEx->pLarzukMapAI->pPosition && !pQuestDataEx->bLarzukMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pLarzukMapAI, AIGENERAL_GetMapAiFromUnit(pLarzuk));
        pQuestDataEx->bLarzukMapAIChanged = 1;
    }
}

// 0x00588340
bool __fastcall ACT5Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_QUAL_KEHK)
    {
        if (pQuest->fState == 1)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
            {
                return true;
            }

            return false;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_ACT5POW)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q2, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }

    return false;
}

// 0x005886A0
void __fastcall OBJECTS_InitFunction62_CagedWussie(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q2_RESCUESOLDIERS);
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    if (pQuestData->fState < 2)
    {
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 860);
    }

    if (!pQuestData->fLastState && pQuestDataEx->nKilledWussies < 5)
    {
        pQuestData->nFlagsLowByte = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
    }

    for (int nCounter = 0; nCounter < 3; ++nCounter)
    {
        if (!pQuestDataEx->bWussiesSpawned[nCounter])
        {
            for (int i = 0; i < nCounter; ++i)
            {
                if (pQuestDataEx->pWussieCoords[i].nX == pOp->nX && pQuestDataEx->pWussieCoords[i].nY == pOp->nY)
                {
                    return;
                }
            }

            pQuestDataEx->pWussieCoords[nCounter].nX = pOp->nX;
            pQuestDataEx->pWussieCoords[nCounter].nY = pOp->nY;
            pQuestDataEx->nSpawnedWussies += ACT5Q2_SpawnCagedWussies(pQuestData, pOp, nCounter);
            pQuestDataEx->bWussiesSpawned[nCounter] = 1;
            pQuestDataEx->unk0x10E[nCounter] = 0;
            return;
        }
    }
}

// 0x00589070
void __fastcall ACT5Q3_SendPacket0x5DToClient(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nFlags = 32;
    packet5D.nQuestId = QUEST_A5Q3_PRISONOFICE;
    sub_6FC3F380(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 286), &packet5D);
}

// 0x005890B0
int __fastcall ACT5Q3_RemoveDrehyaIced(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!pUnit || pUnit->dwClassId != MONSTER_DREHYAICED)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonsterInteractStrc* pMonInteract = nType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0;

    if (MONSTERAI_HasInteractUnit(pMonInteract))
    {
        sub_00573180(pGame, pUnit, ACT5Q3_SendPacket0x5DToClient, 0);
        return 1;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEAD, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bDrehyaIcedRemoved = 1;
    }

    return 1;
}

// 0x00589F10
bool __fastcall ACT5Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return false;
        }

        if (pQuest->fState == 1)
        {
            return true;
        }

        if (pQuest->fState == 4 && ((D2Act5Quest3Strc*)pQuest->pQuestDataEx)->nDefrostPotionsInGame == 0)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_DREHYAICED)
    {
        if (pQuest->bNotIntro && pQuest->fState < 5 && !ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ITEMCODE_DEFROST_POTION))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_DREHYA)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return false;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM5) == 0)
        {
            return true;
        }
    }

    return false;
}

// 0x0058A7D0
int __fastcall sub_0058A7D0_GetDrehyaPortalInTownCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDrehyaPortalInTownSpawned || pQuestDataEx->bChangeToSpecialObjectModeInTown)
    {
        return 0;
    }

    pCoord->nX = pQuestDataEx->tDrehyaPortalInTownCoords.nX;
    pCoord->nY = pQuestDataEx->tDrehyaPortalInTownCoords.nY;
    return 1;
}

// 0x0058A8D0
int __fastcall ACT5Q3_GetDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->unk0x84)
    {
        return 0;
    }

    if (!pQuestDataEx->bDrehyaPortalOutsideTownSpawned)
    {
        UNITS_GetCoords(pUnit, pCoord);
        return 1;
    }

    pCoord->nX = pQuestDataEx->pDrehyaPortalCoords.nX;
    pCoord->nY = pQuestDataEx->pDrehyaPortalCoords.nY;
    return 1;
}

// 0x0058ABC0
int __fastcall OBJECTS_OperateFunction67_FrozenAnya(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;

    if (!ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ITEMCODE_DEFROST_POTION))
    {
        QUESTS_SendScrollMessage(pOp->pPlayer, pOp->pObject, 20131);

        if (pQuestData->fLastState == 1)
        {
            pQuestData->nFlagsLowByte = 0;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        }

        return 0;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDPENDING)
        && ITEMS_FindQuestItem(pOp->pGame, pOp->pPlayer, ITEMCODE_DEFROST_POTION))
    {
        --pQuestDataEx->nDefrostPotionsInGame;
        QUESTS_DeleteItem(pOp->pGame, pOp->pPlayer, ITEMCODE_DEFROST_POTION);
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 2001);

        pQuestDataEx->unk0x84 = 1;
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING);

        pQuestData->nFlagsLowByte = 0;
        QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        QUESTS_TriggerFX(pQuestData->pGame, 16);

        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->pPlayer, ACT5Q3_UnitIterate_SetCompletionFlag);

        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            pQuestDataEx->pDrehyaObjectOutsideTownCoords.nX = UNITS_GetXPosition(pOp->pObject);
            pQuestDataEx->pDrehyaObjectOutsideTownCoords.nY = CLIENTS_GetUnitY(pOp->pObject);

            QUESTS_CreateTimer(pQuestData, ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown, 1);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->pObject), 0);
        }
    }

    return 0;
}

// 0x0058AD80
void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pMapAi)
    {
        return;
    }

    pQuestDataEx->pDrehyaMapAI = DRLGPRESET_CreateCopyOfMapAI(pQuestData->pGame->pMemoryPool, pMapAi);
    if (!pQuestDataEx->bDrehyaMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pDrehya = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_MONSTER, pQuestDataEx->nDrehyaMonsterInTownGUID);
    if (pDrehya && pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, AIGENERAL_GetMapAiFromUnit(pDrehya));
        pQuestDataEx->bDrehyaMapAIChanged = 1;
    }
}

// 0x0058AE10
void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData || !pMapAi)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pNilathakMapAI = DRLGPRESET_CreateCopyOfMapAI(pQuestData->pGame->pMemoryPool, pMapAi);
    if (!pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pNihlathak = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_MONSTER, pQuestDataEx->NihlathakMonsterInTownGUID);
    if (pNihlathak && pQuestDataEx->pNilathakMapAI && pQuestDataEx->pNilathakMapAI->pPosition && !pQuestDataEx->bNilathakMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNilathakMapAI, AIGENERAL_GetMapAiFromUnit(pNihlathak));
        pQuestDataEx->bNilathakMapAIChanged = 1;
    }
}

// 0x0058B2C0
void __fastcall ACT5Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_PRIMARYGOALDONE);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return;
    }

    if (nNpcId == MONSTER_DREHYA && pQuestData->fState == 1)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_DREHYA, 0);
        }
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDPENDING))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_ENTERAREA))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
        else
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (bRewardGranted == 1 || pQuestData->fState >= 4 && !bPrimaryGoalDone || !pQuestData->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnA5Q4NpcIndices_007350E8[pQuestData->fState];
    if (nIndex != -1 && nIndex < 8)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x0058CCF0
bool __fastcall ACT5Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId != MONSTER_QUAL_KEHK || pQuest->fState != 1)
    {
        return false;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    return true;
}

// 0x0058DE30
int __fastcall ACT5Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 472);
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nQuestId = QUEST_A5Q6_BAAL;
    packet5D.nFlags = 2;
    sub_6FC3F380(pClient, &packet5D);

    SUNIT_AttachSound(pUnit, 83, pUnit);
    return 0;
}

// 0x0058F9B0
bool __fastcall ACT1Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x0058FB50
bool __fastcall ACT1Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_WARRIV1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    return false;
}

// 0x005905B0
bool __fastcall ACT1Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_AKARA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->bNotIntro == 1 && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
}

// 0x00591080
bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_KASHYA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
}

// 0x00592880
void __fastcall ACT1Q4_SendPacket0x5DToClient(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nFlags = 1;
    packet5D.nQuestId = QUEST_A1Q4_CAIN;
    sub_6FC3F380(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 613), &packet5D);
}

// 0x00592F80
void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bInvisbleObjectInitialized = 1;
    pQuestDataEx->nInvisibleObjectGUID = !pUnit ? -1 : pUnit->dwUnitId;
}

void __fastcall ACT4Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, gszAct4Q3SourceFile, 433);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q3_UnitIterate_UpdateQuestStateFlags);
}

void __fastcall ACT4Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_GetBaseCode(pQuestArg->pTarget) == 0x20686668)
    {
        --pQuestDataEx->nHellforgeHammersInGame;
    }
}

void __fastcall ACT4Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20686668))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

void __fastcall ACT4Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfActiveFilter = ACT4Q3_ActiveFilterCallback;
    pQuestData->pQuestDataEx = 0;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;
    pQuestData->pNPCMessages = gpAct4Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfSeqFilter = ACT4Q3_SeqCallback;
    pQuestData->nSeqId = 23;
    pQuestData->nQuestFilter = 27;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pfCallback[3] = ACT4Q3_Callback03_ChangedLevel;
    pQuestData->pfCallback[0] = ACT4Q3_Callback00_NpcActivate;
    pQuestData->pfCallback[2] = ACT4Q3_Callback02_NpcDeactivate;
    pQuestData->pfCallback[11] = ACT4Q3_Callback11_ScrollMessage;
    pQuestData->pfCallback[13] = ACT4Q3_Callback13_PlayerStartedGame;
    pQuestData->pfCallback[14] = ACT4Q3_Callback14_PlayerJoinedGame;
    pQuestData->pfCallback[9] = ACT4Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pfCallback[8] = ACT4Q3_Callback08_MonsterKilled;
    pQuestData->pfCallback[4] = ACT4Q3_Callback04_ItemPickedUp;

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest3Strc), gszAct4Q3SourceFile, 856, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest3Strc));
}

void __fastcall ACT4Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 408)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 13))
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 23);
        if (!pQuest || !((D2Act4Quest2Strc*)pQuest->pQuestDataEx)->bDiabloKilled)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 1);
        }
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 0);
    }
}

void __fastcall ACT4Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[0] = ACT4Q4_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct4Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->nQuestFilter = 33;
    pQuestData->pfStatusFilter = ACT4Q4_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q4_ActiveFilterCallback;
}

void __fastcall ACT3Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pfCallback, 0x00, sizeof(pQuestData->pfCallback));
    pQuestData->pfCallback[0] = ACT3Intro_Callback00_NpcActivate;
    pQuestData->pfCallback[11] = ACT3Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct3IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->nQuestFilter = 42;
    pQuestData->pfStatusFilter = ACT3Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Intro_ActiveFilterCallback;
}

void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 465 || nMessageIndex == 466)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 16, 0);
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}

void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0))
    {
        return;
    }

    const int nClassId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;
    if (nClassId == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 0);
    }
}

void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}
