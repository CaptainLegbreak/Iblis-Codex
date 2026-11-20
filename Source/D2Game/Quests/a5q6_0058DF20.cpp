#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
struct D2GameStrc;
struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;





struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);




struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" const char gszA5Q6SourceFile[];                                                                  // 0x006E1AF0
extern char gpAct5Q6NpcMessages[];                                                                          // 0x00735800

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty);      // 0x00538680
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058D770
int __fastcall ACT5Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D8B0
void __fastcall ACT5Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058D870
void __fastcall sub_0058D940_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058D940
void __fastcall ACT5Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058D9F0
void __fastcall ACT5Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058DCF0
void __fastcall sub_0058DF20_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058DF20
void __fastcall ACT5Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058E190
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058E2B0
void __fastcall ACT5Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT5Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
bool __fastcall ACT5Q6_SeqCallback(D2QuestDataStrc* pQuestData);

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
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
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
void __fastcall GAME_SaveAndSendClientSaves(D2GameStrc* pGame);                                                            // 0x0052E2A0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B030
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                              // 0x0061AED0
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame); // 0x005438B0
int __fastcall sub_0058DEA0_UnitIterate_CompleteInChamber(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DEA0
int __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DD90
int __fastcall ACT5Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DDE0
int __fastcall ACT5Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DE30

#ifdef MOVED_TEST
#define FX_ID 21
#define GOLD_STEP 6010
#define GOLD_MIN 1510
#define GOLD_MAX 3010
#define DEATH_MISSILE 627
#else
#define FX_ID 19
#define GOLD_STEP 6000
#define GOLD_MIN 1500
#define GOLD_MAX 3000
#define DEATH_MISSILE 625
#endif

// 0x0058DF20
void __fastcall sub_0058DF20_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest6Strc* pEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    QUESTS_TriggerFX(pQuestData->pGame,FX_ID);
    if (pQuestData->bNotIntro) {
        bool bDropGold = false;
        pEx->pRoom = UNITS_GetRoom(pQuestArg->pTarget);
        if (!pEx->pRoom) return;
        QUESTS_UnitIterate(pQuestData,4,0,ACT5Q6_UnitIterate_StatusCyclerEx,true);
        if (pQuestArg->pPlayer) {
            if (pQuestData->bNotIntro) {
                D2GameStrc* pGame = pQuestArg->pGame;
                D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
                if (!QUESTRECORD_GetQuestState(pFlags,40,0)) bDropGold = true;
            }
            pEx->nCompletions = 0;
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,sub_0058DEA0_UnitIterate_CompleteInChamber);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_SetCompletionFlag);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_AttachCompletionSound);
            if (bDropGold) {
                int nGoldMin = GOLD_MIN + GOLD_STEP * pQuestData->pGame->nDifficulty;
                unsigned int nGoldMax = GOLD_MAX + GOLD_STEP * pQuestData->pGame->nDifficulty;
                if (nGoldMax >= 65535) nGoldMax = 65535;
                for (int i=0; i<pEx->nCompletions; ++i) {
                    sub_00545990(pQuestData,pQuestArg,95);
                    int nGold = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame),nGoldMin,nGoldMax);
                    ITEMS_DropGoldPile(pQuestData->pGame,pQuestArg->pTarget,nGold);
                }
            }
            GAME_SaveAndSendClientSaves(pQuestData->pGame);
        }
        if (pQuestData->fState != 5) pQuestData->fState = 5;
    }
    D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pQuestArg->pGame,pQuestArg->pTarget,0,1,DEATH_MISSILE,CLIENTS_GetUnitX(pQuestArg->pTarget),CLIENTS_GetUnitY(pQuestArg->pTarget));
    if (pMissile) {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        DUNGEON_ToggleHasPortalFlag(pRoom,0);
    }
}
