#include "D2Game.h"
#include "D2Structs.h"

struct D2SeedStrc;
struct D2PlayerDataStrc;
struct D2Act2Quest3Strc;
struct D2GSPacketSrv5D;
struct D2ObjInitFnStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x4E];
    D2DrlgActStrc* pAct[5];
};


struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
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
    char unk0x0D[0x07];
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act2Quest3Strc
{
    unsigned char unused0x00;
    unsigned char bDarkenTimerCreated;
    unsigned char bDarknessApplied;
    unsigned char bDarknessPending;
    unsigned char bAltarDestroyed;
    unsigned char bAltarInitialized;
    unsigned char unk0x06;
    char unk0x07[0x91];
    int nAltarLevelId;
    int nViperAmuletDropCount;
};

enum
{
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_ENTERAREA = 4,
    QFLAG_PRIMARYGOALDONE = 13,
    QFLAG_COMPLETEDBEFORE = 15,
    ACT_II = 1,
    A2Q3_SOUND_COMPLETE = 52,
    A2Q3_STATE_TIMER = 4,
    A2Q3_ITERATE_TIMER = 3,
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599F50

#pragma pack(push, 1)
struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

#pragma pack(pop)
struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710
int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A100
int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A4F0

// 0x0059A040
void __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_II)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING);
}

// 0x0059A0B0
int __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q3_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0059A4F0
int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q3_TAINTEDSUN);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState >= 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_STARTED);
    }

    if (pQuestData->fState == QFLAG_STARTED)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_LEAVETOWN);
    }
    else if (pQuestData->fState == QFLAG_LEAVETOWN)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_ENTERAREA);
    }

    return 0;
}

// 0x0059A680
int __fastcall ACT2Q3_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q3_TAINTEDSUN);

    if (pRoom && pQuestData)
    {
        D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->nAltarLevelId == DUNGEON_GetLevelIdFromRoom(pRoom)
            && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED) != 1
            && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_COMPLETEDBEFORE) != 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING);
        }
    }

    return 0;
}

// 0x0059A700
bool __fastcall ACT2Q3_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;

    if (pQuestData->fState == A2Q3_STATE_TIMER)
    {
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, A2Q3_ITERATE_TIMER, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
    }
    pQuestDataEx->unk0x06 = 0;

    return 1;
}

// 0x0059A730
int __fastcall ACT2Q3_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, A2Q3_SOUND_COMPLETE, pUnit);
    }

    return 0;
}

// 0x0059A770
int __fastcall ACT2Q3_UnitIterate_DetermineViperAmuletDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' piv') || ITEMS_FindQuestItem(pGame, pUnit, ' tsh'))
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData)
    {
        ++((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->nViperAmuletDropCount;
    }

    return 0;
}

// build: symbol ?sub_0059A350_ApplyDarkness@@YA_NPAUD2QuestDataStrc@@@Z 0x0059A350
static bool sub_0059A350_ApplyDarkness(D2QuestDataStrc* pQuestData)
{
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x211);
    }

    D2GameStrc* pGame = pQuestData->pGame;
    if (pGame->pAct[1])
    {
        ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_UpdateClient);
        return true;
    }

    ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bDarknessPending = 1;
    return false;
}

// 0x0059A570
static void __stdcall sub_0059A570_StartDarknessForPlayer(D2UnitStrc* pPlayer, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!sub_0059A350_ApplyDarkness(pQuestData))
    {
        pQuestDataEx->bDarknessPending = 1;
        D2GSPacketSrv5D packet5D = {};
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = 10;
        packet5D.nFlags = 1;
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x2E0);
        sub_6FC3F380(pClient, &packet5D);
    }
    else
    {
        pQuestDataEx->bDarknessApplied = 1;
    }
}

void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 11, 13);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 2) == 1)
    {
        sub_0059A570_StartDarknessForPlayer(pQuestArg->pPlayer, pQuestData);

        if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 4))
        {
            pQuestData->fLastState = 2;
            pQuestData->fState = 3;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 3))
        {
            pQuestData->fLastState = 2;
            pQuestData->fState = 2;
        }
        else
        {
            pQuestData->fLastState = 1;
            pQuestData->fState = 1;
        }
    }
}
