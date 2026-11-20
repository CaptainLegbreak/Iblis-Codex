#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0




struct D2MapAIStrc
{
    int unk0x00;
    void* pPosition;
};


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[5];
    unsigned short unused0x0A;
    unsigned short nCurrentMonolithNo;
    unsigned char pad0x0E[2];
    int nMonolithGUIDs[5];
    int unused0x24;
    int nInvisibleObjectGUID;
    short nCairnStoneInteractions;
    unsigned char pad0x2E[2];
    int nInifussTreeGUID;
    int nCainGibbetGUID;
    int nDecipheredScrollGUID;
    int nPlayerGUID;
    int nCairnStoneAlphaGUID;
    unsigned char bOpenPortalTimerActive;
    unsigned char bPortalToTristramOpened;
    unsigned char bTimerActive;
    unsigned char bInifussTreeInitialized;
    unsigned char bCageModeChanged;
    unsigned char bInvisbleObjectInitialized;
    unsigned char bMonolithStonesOrdered;
    unsigned char unk0x4B;
    unsigned char unk0x4C;
    unsigned char bActivateCairnStones;
    unsigned char bDecipheredScrollAcquired;
    unsigned char bOperatedWithLastCairnStone;
    unsigned char unk0x50;
    unsigned char bCainInTownSpawned;
    unsigned char unk0x52;
    unsigned char bAkaraIntroActivated;
    int nCainGibbetObjectMode;
    int unk0x58;
    unsigned char bCairnStonesActive[5];
    unsigned char bCainRemovedFromTristram;
    unsigned char bCainNotCreated;
    unsigned char bQuestCompleteBefore;
    unsigned char bAkaraActivatedForScroll;
    unsigned char unk0x65[0x13];
    unsigned char bScrollAcquired;
    unsigned char pad0x79[3];
    int nScrollsInGame;
    unsigned char unk0x80[0x34];
    D2QuestGUIDStrc pQuestGUID;
    D2QuestGUIDStrc tPlayerGUIDs;
};
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall ACT1Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005921B0
void __fastcall ACT1Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00592250
void __fastcall ACT1Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00592580
void __fastcall ACT1Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592B90
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592C80
void __fastcall ACT1Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592CF0
void __fastcall ACT1Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00592E20
void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592E60
bool __fastcall ACT1Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00592FB0
bool __fastcall ACT1Q4_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x00593D70
void __fastcall ACT1Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00593E70
void __fastcall ACT1Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00596DE0
void __fastcall ACT1Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00597030

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity); // 0x00559A30
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005920D0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                          // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

__declspec(noinline) static void sub_00592860_DebugStartedQuest(D2QuestDataStrc* pQuestData);
static void sub_00592860_DebugStartedQuest(D2QuestDataStrc* pQuestData)
{
    QUESTS_DebugOutput(pQuestData->pGame, "Started quest", "..\D2Game/Quests/a1q4.cpp", 599);
}

// build: context sub_00593AF0_GetPlayerQuestFlags
static __forceinline D2BitBufferStrc* sub_00593AF0_GetPlayerQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00593AF0
int __fastcall OBJECTS_OperateFunction12_InifussTree(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestInfo = QUESTS_GetQuestData(pOp->pGame, 4);
    D2_ASSERT(pQuestInfo, 0x828);

    if (!pQuestInfo->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        return 0;
    }

    if (pQuestInfo->fState >= 6)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags;
    if (pOp->hObject && pOp->hObject->dwAnimMode != 0
        || QUESTRECORD_GetQuestState(pQuestFlags = sub_00593AF0_GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 4, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ' dkb') || ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ' skb'))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestInfo->pQuestDataEx;
    SUNIT_AttachSound(pOp->hPlayer, 45, 0);

    pOp->hObject->dwDropItemCode = ' skb';
    sub_00592860_DebugStartedQuest(pQuestInfo);
    QUESTS_StateDebug(pQuestInfo, 4, gszA1Q4SourceFile, 0x84B);

    int nItemLevel;
    D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 0);
    if (pItem)
    {
        pQuestInfo->pCallback[9] = ACT1Q4_Callback09_PlayerDroppedWithQuestItem;
        pQuestInfo->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestInfo, 2, pOp->hPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->unk0x4B = 1;
        const int nScrollGUID = (pItem ? pItem->dwUnitId : -1);
        pQuestDataEx->nDecipheredScrollGUID = nScrollGUID;
        pQuestDataEx->unk0x58 = 1;
        pQuestDataEx->bScrollAcquired = 1;
        ++pQuestDataEx->nScrollsInGame;
        UNITS_ChangeAnimMode(pOp->hObject, 1);
    }

    pQuestDataEx->bInifussTreeInitialized = 1;
    pQuestDataEx->nInifussTreeGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
    return 0;
}
