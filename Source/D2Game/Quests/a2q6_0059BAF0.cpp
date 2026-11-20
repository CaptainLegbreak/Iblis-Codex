#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define QUEST_A2Q4_HORAZONTOME 11
#define LEVEL_PALACECELLARLEV3 54
#define LEVEL_ARCANESANCTUARY 74
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define UNIT_TILE 5
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ObjectControlStrc;
struct D2ObjOperateFnStrc;
struct D2Act2Quest4Strc;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2Act2Quest6Strc;


struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);


struct D2Act2Quest4Strc
{
    char unk0x00[0x42];
    unsigned short nPortalModeInSanctuary;
    unsigned short nPortalModeInCellar;
};


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __fastcall sub_005550B0_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile); // 0x005550B0


typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

typedef int (__stdcall* FARPROC)();

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    int unk0x10;
    unsigned short nNPCNo;
    unsigned short unk0x16;
    unsigned short nMessageIndex;
    unsigned short unk0x1A;
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00[8];
    unsigned char bInitJerhynActivated;
    unsigned char bTyraelActivated;
    unsigned char bEndJerhynActivated;
    unsigned char unk0x0B[4];
    unsigned char bPortalToLutGholeinOpened;
    unsigned char unk0x10[0x2C];
    unsigned char bPortalIsOpening;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0
int __fastcall ACT2Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C650
void __fastcall ACT2Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059C760
int __fastcall ACT2Q6_UnitIterate_SetLeaveTownFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C860
int __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C9A0
int __fastcall ACT2Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C9F0

// 0x0059BAF0
void __fastcall ACT2Q4_SetPortalMode(D2GameStrc* pGame, int nLevelId)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        if (!pQuestDataEx->nPortalModeInCellar)
        {
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPERATING;
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPENED;
        }
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        if (!pQuestDataEx->nPortalModeInSanctuary)
        {
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPERATING;
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPENED;
        }
    }
}

// 0x0059D9D0
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp)
{
    for (D2UnitStrc* i = UNITS_GetRoom(pOp->hObject)->pUnitFirst; i; i = i->ptRoomNext)
    {
        if (i->dwUnitType == UNIT_TILE)
        {
            sub_005550B0_WarpPlayer(pOp->pGame, pOp->hPlayer, i);
        }
    }
}

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0059CB20
void __fastcall ACT2Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    const unsigned short nMessage = pQuestArg->nMessageIndex;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;

    if (pQuestArg->nNPCNo == 251)
    {
        if (pQuestData->bNotIntro && nMessage == 302 && !pQuestDataEx->bPortalToLutGholeinOpened)
        {
            pQuestDataEx->bPortalIsOpening = 1;

            if (D2GAME_CreatePortalObject_6FD13DF0(pQuestData->pGame, pQuestArg->pPlayer, UNITS_GetRoom(pQuestArg->pPlayer), CLIENTS_GetUnitX(pQuestArg->pPlayer), CLIENTS_GetUnitY(pQuestArg->pPlayer), 40, 0, 59, 0))
            {
                QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 577);
                SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q6_UnitIterate_SetLeaveTownFlag);
                SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
                SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q6_UnitIterate_SetCompletionFlag);

                pQuestDataEx->bPortalToLutGholeinOpened = 1;
                pQuestDataEx->bTyraelActivated = 1;
                pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
            }

            pQuestDataEx->bPortalIsOpening = 0;
        }
    }
    else if (pQuestArg->nNPCNo == 201)
    {
        if (nMessage == 430)
        {
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 596);
            D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 10);
            pQuestDataEx->bInitJerhynActivated = 1;
            pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
            if (pQuest)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 602);
                pQuest->pfSeqFilter(pQuest);
            }
        }
        else if (nMessage == 442 && QUESTRECORD_GetQuestState(pQuestFlags, 14, 3))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
            {
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 620);
            }
            pQuestDataEx->bEndJerhynActivated = 1;
            pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
            QUESTRECORD_SetQuestState(pQuestFlags, 14, 4);
            QUESTRECORD_ClearQuestState(pQuestFlags, 14, 3);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        return;
    }
    else if (pQuestArg->nNPCNo == 210)
    {
        if (nMessage == 450 && QUESTRECORD_GetQuestState(pQuestFlags, 14, 4))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 10, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' tsh');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' piv');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' fsm');
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
            {
                QUESTS_SetGlobalState(pQuestData->pGame, 14, 13);
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 644);
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 14, 0);
            QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
            QUESTRECORD_ClearQuestState(pQuestFlags, 14, 4);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
        return;
    }

    switch (nMessage)
    {
    case 445:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 6);
        break;
    case 446:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 7);
        break;
    case 449:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 8);
        break;
    case 444:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 9);
        break;
    case 452:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 10);
        break;
    case 447:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 11);
        break;
    default:
        return;
    }
}
