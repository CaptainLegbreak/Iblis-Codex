#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameObjs.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2MonModes.h"

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

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

extern unsigned int gnA5Q1NpcIndices_00733928[]; // 0x00733928

extern unsigned int gnA5Q4NpcIndices_007350E8[]; // 0x007350E8

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0

void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide); // 0x00573180

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

extern "C" const char gszAct4Q3SourceFile[];

extern char gpAct4Q3NpcMessages[];

extern char gpAct4Q4NpcMessages[];

extern char gpAct3IntroNpcMessages[];

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

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

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int(__fastcall* QUESTSEQFN)(D2QuestDataStrc* pQuestData);

typedef int(__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586DE0

int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586C80

#define QFLAG_COMPLETEDBEFORE 15

#define SUPERUNIQUE_SIEGE_BOSS 42

#define STAT_FIRERESIST 39

#define STAT_LIGHTRESIST 41

#define STAT_COLDRESIST 43

#define STAT_POISONRESIST 45

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern char gpAct5Q1NpcMessages[]; // 0x00733308

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

bool __fastcall ACT5Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00586CE0

void __fastcall ACT5Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586D80

void __fastcall ACT5Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586E70

void __fastcall ACT5Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586FF0

int __fastcall ACT5Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587100

int __fastcall ACT5Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005872F0

bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005874E0

bool __fastcall sub_00587560_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00587560

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005870D0

void __fastcall ACT5Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005873E0

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

#define PREFIX

#define TERMINAL_STATE 5

#define ASSERT_LINE 626

#define MONSTER_QUALKEHK 515

struct Unit0058F000;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

extern "C" unsigned int* __stdcall sub_0058F000(Unit0058F000* pUnit); // 0x0058F000

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_COMPLETEDNOW 14

// 0x00586C50
bool __fastcall ACT5Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_MALAH))
    {
        return true;
    }

    return false;
}

// 0x00586C80
int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q1_SHENK);
    }

    return 0;
}

// 0x00586CE0
bool __fastcall ACT5Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING) || QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE))
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, QFLAG_CUSTOM1))
        {
            *pStatus = 4;
            return true;
        }

        *pStatus = 3;
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
    }
    else if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
    }

    return true;
}

// 0x00586D80
void __fastcall ACT5Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_LARZUK)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukStartActivated == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bLarzukStartActivated = 0;
    }

    if (pQuestDataEx->bLarzukEndActivated == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bLarzukEndActivated = 0;
    }
}

// 0x00586DE0
int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_ENTERAREA);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_LEAVETOWN);
        }
    }

    return 0;
}

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00586E70
void __fastcall ACT5Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != 0x1FF)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 20077)
    {
        pQuestDataEx->bLarzukStartActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0xF8);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 20090)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) != 1)
        {
            return;
        }

        pQuestDataEx->bLarzukEndActivated = 1;
        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 5);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13) && pQuestData->fState != 5)
        {
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x108);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x109);
            pQuestData->pfSeqFilter(pQuestData);

            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        }

        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

// 0x00586FF0
void __fastcall ACT5Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_CUSTOM1))
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

// 0x005871C0
void __fastcall ACT5Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 1) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 0xD);
}

// 0x00587240
int __fastcall ACT5Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q1_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x00587290
int __fastcall ACT5Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x1F, 0);
    }

    return 0;
}

static inline D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
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

// 0x00587330
void __fastcall ACT5Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    ((D2Act5Quest1Strc*)pQuestData->pQuestDataEx)->pRoom = pRoom;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_SetRewardPending);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_AttachCompletionSound);

    QUESTS_SetGlobalState(pQuestData->pGame, 0x23, 0xD);
    QUESTS_TriggerFX(pQuestData->pGame, 0xF);

    if (pQuestData->fLastState < 3)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005873E0
void __fastcall ACT5Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;

    switch (nNewLevel)
    {
    case 110:
    case 111:
    case 112:
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x229);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
        }
        return;

    default:
        break;
    }

    if (nOldLevel != 109)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x23F);
    if (!pQuestData->fLastState)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x005874E0
bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_LARZUK)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_CUSTOM1))
        {
            return true;
        }

        if (pQuest->bNotIntro && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }

    return false;
}

// 0x00587560
bool __fastcall sub_00587560_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != TERMINAL_STATE && pQuestData->bNotIntro)
        return true;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), ASSERT_LINE);
            exit(-1);
        }
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x005875F0
void __fastcall ACT5Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0xF)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        pQuestData->fLastState = 5;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 4) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
    else if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, 0x201) && !pQuestData->fState && pQuestData->bNotIntro)
    {
        pQuestData->fState = 1;
    }
}

// 0x005876E0
void __fastcall ACT5Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT5Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT5Q1_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q1_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct5Q1NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x2D3, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 0x23;
    pQuestData->pfStatusFilter = ACT5Q1_StatusFilterCallback;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q1_ActiveFilterCallback;
    pQuestData->pfSeqFilter = sub_00587560_SeqCallback;
    pQuestData->nSeqId = 0x20;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest1Strc));
}

struct D2ActiveRoomStrc;

// 0x005877C0
void __fastcall ACT5Q1_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestInfo = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestInfo, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED);
    QUESTRECORD_ClearQuestState(pQuestInfo, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);

    if (!QUESTRECORD_GetQuestState(pQuestInfo, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE))
    {
        D2_ASSERT(QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK), 750);
    }
}

void __cdecl sub_00405A50_Nop()
{
}

void __cdecl sub_00405A60_Nop()
{
}

void __cdecl ITEMS_Nop()
{
}

void __cdecl sub_004DF920_Nop()
{
}

void __cdecl sub_004DF930_Nop()
{
}

// 0x00587830
void __cdecl sub_00587830_Nop()
{
}

// 0x00587840
void __fastcall OBJECTS_InitFunction71_LarzukStandard(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x1F);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukSpawned)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom;
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;
    QUESTS_GetFreePosition(pOp->pRoom, &pCoord, 2, 0x100, &pRoom, 16, 100);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pLarzuk = D2GAME_SpawnMonster_6FC69F10(pOp->pGame, pRoom, pCoord.nX, pCoord.nY, MONSTER_LARZUK, 1, 5, 0);
    if (!pLarzuk)
    {
        return;
    }

    pQuestDataEx->bLarzukSpawned = 1;
    pQuestDataEx->nLarzukGUID = !pLarzuk ? -1 : pLarzuk->dwUnitId;
    pLarzuk->dwFlags |= 0x3000000;

    if (pQuestDataEx->pLarzukMapAI && pQuestDataEx->pLarzukMapAI->pPosition && !pQuestDataEx->bLarzukMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pLarzukMapAI, (D2MapAIStrc*)sub_0058F000((Unit0058F000*)pLarzuk));
        pQuestDataEx->bLarzukMapAIChanged = 1;
    }
}

// 0x00587900
void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 2 || MONSTERUNIQUE_GetBossHcIdx(pUnit) != SUPERUNIQUE_SIEGE_BOSS)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
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

// 0x005879D0
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xF)
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xD)
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xE))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 0x20);
    }

    return 0;
}

// 0x00587A30
void __fastcall ACT5Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_QUALKEHK)
    {
        return;
    }

    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bQualKehkActivated == 1 && pQuestDataEx->nKilledWussies < 5)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bQualKehkActivated = 0;
        pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}

// 0x00587A90
int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x20);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 2);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 3);
    }

    return 0;
}

// 0x00587F60
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x20, 0);
    }

    return 0;
}

// 0x00587FC0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const int nGUID = !pUnit ? -1 : pUnit->dwUnitId;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (nGUID == pQuestDataEx->nWussieGUIDs[i][j])
            {
                return i;
            }
        }
    }

    return -1;
}

// 0x00588340
bool __fastcall ACT5Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_QUAL_KEHK)
    {
        if (pQuest->fState == 1)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
            {
                return true;
            }

            return false;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
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

// 0x00588C50
int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;

    int nBarbs = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (!pQuestDataEx->bWussiesSpawned[i])
        {
            nBarbs += 5;
        }
    }

    nBarbs += pQuestDataEx->nSpawnedWussies - pQuestDataEx->nFreedWussies - pQuestDataEx->nKilledWussies;
    if (nBarbs < 0)
    {
        nBarbs = 0;
    }

    return nBarbs;
}

// 0x00588DD0
void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q2_RESCUESOLDIERS);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState == 5)
    {
        return;
    }

    if (((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
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

// 0x00589160
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 331);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00589F10
bool __fastcall ACT5Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
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
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
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

// 0x00589FF0
void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);

    STATLIST_SetStat(pStatList, STAT_FIRERESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_LIGHTRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_COLDRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_POISONRESIST, nValue, 0);

    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_FIRERESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_LIGHTRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_COLDRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_POISONRESIST, nValue, pUnit);
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
    if (!pQuestDataEx->unk0x84[0])
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

    if (!ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ITEMCODE_DEFROST_POTION))
    {
        QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20131);

        if (pQuestData->fLastState == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        }

        return 0;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING)
        && ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ITEMCODE_DEFROST_POTION))
    {
        --pQuestDataEx->nDefrostPotionsInGame;
        QUESTS_DeleteItem(pOp->pGame, pOp->hPlayer, ITEMCODE_DEFROST_POTION);
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 2001);

        pQuestDataEx->unk0x84[0] = 1;
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING);

        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        QUESTS_TriggerFX(pQuestData->pGame, 16);

        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT5Q3_UnitIterate_SetCompletionFlag);

        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            pQuestDataEx->pDrehyaObjectOutsideTownCoords.nX = CLIENTS_GetUnitX(pOp->hObject);
            pQuestDataEx->pDrehyaObjectOutsideTownCoords.nY = CLIENTS_GetUnitY(pOp->hObject);

            QUESTS_CreateTimer(pQuestData, ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown, 1);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 0);
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
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return;
    }

    if (nNpcId == MONSTER_DREHYA && pQuestData->fState == 1)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_DREHYA, 0);
        }
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
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

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    return true;
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
    if (nNpcId == MONSTER_AKARA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->bNotIntro == 1 && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
}

// 0x00591080
bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_KASHYA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
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
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
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
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pfActiveFilter = ACT4Q3_ActiveFilterCallback;
    pQuestData->pQuestDataEx = 0;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;
    pQuestData->pNPCMessages = gpAct4Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfSeqFilter = ACT4Q3_SeqCallback;
    pQuestData->nSeqId = 23;
    pQuestData->eFilter = 27;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT4Q3_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT4Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT4Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[8] = ACT4Q3_Callback08_MonsterKilled;
    pQuestData->pCallback[4] = ACT4Q3_Callback04_ItemPickedUp;

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
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT4Q4_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct4Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 33;
    pQuestData->pfStatusFilter = ACT4Q4_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q4_ActiveFilterCallback;
}

void __fastcall ACT3Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT3Intro_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct3IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 42;
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

#include "gen/data/Source/D2Game/Quests/a5q1.inc"
