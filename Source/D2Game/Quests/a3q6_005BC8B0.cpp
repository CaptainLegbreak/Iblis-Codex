#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
struct D2QuestDataStrc;




typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);
typedef int(__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act3Quest6Strc
{
    unsigned char bTimerStarted;
    unsigned char bHellGatePortalInitialized;
    unsigned char bMephistoBridgeInitialized;
    unsigned char bOrmusActivated;
    int nHellGatePortalGUID;
    int nMephistoBridgeGUID;
    int nHellGatePortalObjectMode;
    int nMephistoBridgeObjectMode;
    int nSoulStonesDropped;
    unsigned char bSoulStoneDropped;
    unsigned char pad0x19[3];
    int nSoulstonesToDrop;
};


#define QFLAG_REWARDGRANTED 0
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1
#define ITEMQUAL_NORMAL 2

void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity); // 0x00559A30
void __fastcall sub_005B6930_Return(D2GameStrc* pGame, int nSoulStonesDropped); // 0x005B6930
int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC190
void __fastcall ACT3Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC710
bool __fastcall ACT3Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005BC720
int __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC7C0
int __fastcall ACT3Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC810
int __fastcall ACT3Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC870
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

// 0x005BC140
static __declspec(noinline) void __stdcall sub_005BC140_ACT3Q6_SetCompletionStates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 204), 3, pGame->nDifficulty);
}

static __forceinline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005BC8B0
void __fastcall ACT3Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nItemLevel;

    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 619);
    QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 620);

    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT3Q6_Callback10_PlayerLeavesGame;
    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer && !QUESTRECORD_GetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED))
        {
            sub_00545990(pQuestData, pQuestArg, 62);

            if (!QUESTRECORD_GetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7))
            {
                ++((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nSoulstonesToDrop;
            }

            sub_005BC140_ACT3Q6_SetCompletionStates(pQuestArg->pGame, pQuestArg->pPlayer, sub_00543520(pQuestData->pGame, pQuestArg->pPlayer));
        }

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_UpdateQuestStateAfterMonsterKill);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_SetCompletionFlag);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_AttachCompletionSound);

        if (!pQuestDataEx->bTimerStarted)
        {
            QUESTS_CreateTimer(pQuestData, ACT3Q6_Timer_StatusCycler, 12);
            pQuestDataEx->bTimerStarted = 1;
        }
    }

    QUESTS_SetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);

    if (pQuestDataEx->bHellGatePortalInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nHellGatePortalGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);
            const int nClassId = pObject->dwClassId;
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
            sub_005417D0_DirectDated(pQuestData->pGame, pObject, EVENTTYPE_ENDANIM, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
        }
    }
    pQuestDataEx->nHellGatePortalObjectMode = OBJMODE_OPENED;

    pQuestArg->pTarget->dwDropItemCode = ' ssm';
    for (int i = 0; i < pQuestDataEx->nSoulstonesToDrop; ++i)
    {
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestArg->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            ++pQuestDataEx->nSoulStonesDropped;
            pQuestDataEx->bSoulStoneDropped = 1;
        }
    }

    sub_005B6930_Return(pQuestData->pGame, pQuestDataEx->nSoulStonesDropped);
    QUESTS_TriggerFX(pQuestData->pGame, 11);
}
