#include "D2Game.h"

#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
#define ACT_I 0
#define ACT_III 2
#define QUESTSTATEFLAG_A1Q2 2
#define MONSTER_KASHYA 150
struct Obj00590810;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act1Quest2Strc;

struct Obj00590810 {
    unsigned char bUnknown00[9];
    unsigned char bFlag09;
    unsigned char bUnknown0A[2];
    unsigned char bValue0C;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned short dwClassId;
    unsigned short unk0x06;
    int unk0x08;
    int dwUnitId;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char nFlag0B;
    unsigned char nState0C;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    void* pfCallback[16];
    int nQuestFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

struct D2Act1Quest2Strc
{
    char unk0x00[0x03];
    unsigned char bKashyaActivated;
};
void __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuestId, int nState); // 0x0065C360

// 0x00590810
extern "C" __declspec(dllexport) bool __fastcall sub_00590810(Obj00590810* pObj) {
    if (pObj->bFlag09 && pObj->bValue0C >= 4) {
        return true;
    }
    return false;
}

// 0x00590830
int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 2);
    }

    return 0;
}

// 0x00590920
void __fastcall ACT1Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || pQuestArg->pTarget->dwClassId != MONSTER_KASHYA)
    {
        return;
    }

    D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bKashyaActivated != 1)
    {
        return;
    }

    pQuestData->bStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bKashyaActivated = 0;
    pQuestData->pfCallback[2] = 0;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
}

// 0x00590BF0
bool __fastcall ACT1Q2_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    pQuestData->bStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 3, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
    return true;
}

// 0x00590C10
void __fastcall ACT1Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

// 0x00590D60
void __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == ACT_I)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING);
    }
}

// 0x00590DD0
int __fastcall ACT1Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, 2, 0);
    }

    return 0;
}

// 0x00590E30
int __fastcall ACT1Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE) == 1)
    {
        SUNIT_AttachSound(pUnit, 34, pUnit);
    }

    return 0;
}

// 0x00590E70
int __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q2_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00590890
int __fastcall sub_00590890_SyncQuest2(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestRecord, 2, 0) == 1 || QUESTRECORD_GetQuestState(pQuestRecord, 2, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 2);
    if (!pQuestData)
    {
        return 0;
    }
    const unsigned char nState = pQuestData->nState0C;
    if (nState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 2, 2);
        return 0;
    }
    if (nState == 3)
    {
        if (pQuestData->nFlag0B == 1)
        {
            QUESTRECORD_SetQuestState(pQuestRecord, 2, 3);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestRecord, 2, 4);
    }
    return 0;
}
