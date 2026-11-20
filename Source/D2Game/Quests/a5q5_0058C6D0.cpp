#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0




struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char bQualKehkActivated;
    unsigned char unused0x02[2];
    unsigned char bTimerActive;
    unsigned char unused0x05[7];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
    unsigned char pad0x12[2];
    int nAncientStatueGUID[3];
    int nAncientMonsterGUID[3];
    unsigned char bAncientMonsterSpawned[3];
    unsigned char pad0x2F;
    int nAncientStatueObjectMode[3];
    unsigned char bAncienStatueRespawned[3];
    unsigned char pad0x3F;
    int nAncientsSpawned;
    int nAncientsAlive;
};
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

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
    union
    {
        unsigned int dwFlags;
        unsigned char nFlagsByte;
    };
    D2Act5Quest5Strc* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    void* pCallback[15];
    void* pNPCMessages;
    int eFilter;
    char unk0xE4[0x0C];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define ACT_V 4
#define STAT_LEVEL 12
#define QUEST_A5Q5_ANCIENTS 35
#define QFLAG_REWARDGRANTED 0
#define QFLAG_PRIMARYGOALDONE 13
#define LEVEL_ROCKYSUMMIT 120

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);   // 0x00543520
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x005455B0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00570880
bool __fastcall ACT5Q5_Timer_RespawnAncientStatueObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);   // 0x0058BD50
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058BE20
int __fastcall ACT5Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x0058C780
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel);                                           // 0x00611800
int __stdcall DATATBLS_GetMaxLevel(int nClass);                                                             // 0x00611830
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static void __stdcall ACT5Q5_RewardPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058C5C0

// build: context ACT5Q5_RewardPlayer
static void __stdcall ACT5Q5_RewardPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    int nRewardExp = 1400000;
    switch (pGame->nDifficulty)
    {
    case 1:
        nRewardExp = 20000000;
        break;
    case 2:
        nRewardExp = 40000000;
        break;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    const int nMaxLevel = DATATBLS_GetMaxLevel(nClassId);
    int nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nCurrentLevel >= nMaxLevel)
    {
        return;
    }

    const unsigned int nNextThreshold = DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel + 1);
    const int nDeltaExpThreshold = nNextThreshold - DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel);
    if (nRewardExp > nDeltaExpThreshold)
    {
        nRewardExp = nDeltaExpThreshold;
    }

    do
    {
        if (!nRewardExp)
        {
            break;
        }

        const int nNextExp = STATLIST_GetUnitBaseStat(pUnit, STAT_NEXTEXP, 0);
        const unsigned int nDeltaExp = nNextExp - STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        if ((unsigned int)nRewardExp >= nDeltaExp)
        {
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNextExp, 0);
            STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nDeltaExp, 0);
            PLAYERSTATS_LevelUp(pGame, pUnit);
            nRewardExp -= nDeltaExp;
            nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }
        else
        {
            const int nExp = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
            nRewardExp += nExp;
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nRewardExp, 0);
            nRewardExp = 0;
        }
    }
    while (nCurrentLevel < nMaxLevel);
}

// 0x0058C6D0
void __fastcall ACT5Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) || STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < 20 * (pGame->nDifficulty + 1))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_V)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE);
    ACT5Q5_RewardPlayer(pGame, pUnit);
}

// 0x0058C7E0
int __fastcall ACT5Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);
    D2_ASSERT(pQuestData, 725);

    if (STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < 20 * (pGame->nDifficulty + 1) || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROCKYSUMMIT)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    ACT5Q5_RewardPlayer(pGame, pUnit);

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q5_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0058C8D0
static void __stdcall sub_0058C8D0_SpawnStatueMissile(D2QuestArgStrc* pQuestArg, int nObjectId, D2QuestDataStrc* pQuestData)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, nObjectId);
    if (!pObject)
    {
        return;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x420;
    missileParams.nMissile = 541;
    missileParams.pOwner = pQuestArg->pTarget;
    missileParams.pOrigin = pQuestArg->pTarget;
    missileParams.nTargetX = UNITS_GetXPositionInline(pObject);
    missileParams.nTargetY = UNITS_GetYPositionInline(pObject);
    missileParams.nSkillLevel = 1;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pQuestData->pGame, &missileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nObjectId);
    }
}

// 0x0058C9A0
void __fastcall ACT5Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest5Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bActivatable || !pQuestDataEx->unk0x10 || pQuestDataEx->nActivePortalCount)
    {
        return;
    }

    if (!pQuestDataEx->bTimerActive)
    {
        pQuestDataEx->bTimerActive = 1;
        QUESTS_CreateTimer(pQuestData, ACT5Q5_Timer_RespawnAncientStatueObjects, 2);
    }

    const int nMonsterId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nObjectId;
    switch (nMonsterId)
    {
    case MONSTER_ANCIENTBARB1:
        pQuestDataEx->bAncienStatueRespawned[2] = 1;
        nObjectId = pQuestDataEx->nAncientStatueGUID[2];
        break;

    case MONSTER_ANCIENTBARB2:
        pQuestDataEx->bAncienStatueRespawned[0] = 1;
        nObjectId = pQuestDataEx->nAncientStatueGUID[0];
        break;

    case MONSTER_ANCIENTBARB3:
        pQuestDataEx->bAncienStatueRespawned[1] = 1;
        nObjectId = pQuestDataEx->nAncientStatueGUID[1];
        break;

    default:
        return;
    }

    sub_0058C8D0_SpawnStatueMissile(pQuestArg, nObjectId, pQuestData);
    QUESTS_TriggerFX(pQuestData->pGame, 18);

    --pQuestDataEx->nAncientsAlive;
    if (pQuestDataEx->nAncientsAlive)
    {
        return;
    }

    pQuestDataEx->bAncientsDefeated = 1;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    if (pQuestArg->pPlayer)
    {
        D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestData->pGame, pQuestArg->pPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) && STATLIST_GetUnitBaseStat(pQuestArg->pPlayer, STAT_LEVEL, 0) >= 20 * (pQuestData->pGame->nDifficulty + 1))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE);
            ACT5Q5_RewardPlayer(pQuestArg->pGame, pQuestArg->pPlayer);
        }
    }

    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q5_UnitIterate_SetCompletionFlag);
    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 842);
    SUNIT_AllocUnitData(UNIT_OBJECT, 561, CLIENTS_GetUnitX(pQuestArg->pTarget), CLIENTS_GetUnitY(pQuestArg->pTarget), pQuestArg->pGame, UNITS_GetRoom(pQuestArg->pTarget), 1, 0, 0);

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 855);
        pQuest->pfSeqFilter(pQuest);
    }

    if (pQuestData->fLastState != 13)
    {
        pQuestData->nFlagsByte = 0;
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
    }
}
