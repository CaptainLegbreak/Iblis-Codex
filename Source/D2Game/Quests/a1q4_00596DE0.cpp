#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"





struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
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
struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char unk0x10[0x04];
    int nOldLevel;
    int nNewLevel;
};


struct D2Act1Quest4Strc
{
    char unk0x00[0x30];
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
    unsigned char bCainInTownSpawnPending;
    unsigned char bAkaraIntroActivated;
    int nCainGibbetObjectMode;
    int unk0x58;
    unsigned char bCairnStonesActive[5];
    unsigned char bCainRemovedFromTristram;
    unsigned char bCainNotCreated;
    unsigned char bQuestCompleteBefore;
    unsigned char bAkaraActivatedForScroll;
    unsigned char unk0x65;
    unsigned char bPortalFromTristramToTownSpawned;
    unsigned char bCainPortalCoordsInitialized;
    int nCainMonsterInTownGUID;
    int nCainObjectGUID;
    unsigned char bCainObjectInitialized;
    unsigned char pad0x71[3];
    D2UnitStrc* pPlayerInTristram;
    unsigned char bScrollAcquired;
    unsigned char pad0x79[3];
    int nScrollsInGame;
    char unk0x80[0x04];
    D2CoordStrc pCainStartPositionCoords;
    char unk0x8C[0x28];
    char pQuestGUID[0x10];
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
int __fastcall QUESTS_FastRemovePlayerGUID(void* pGUIDs, int dwGUID);                                       // 0x00545240
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);           // 0x00545310
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005920D0
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005928C0
int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);       // 0x00592B10
bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);       // 0x00593260

// 0x00592860
static void sub_00592860_DebugStartedQuest(D2QuestDataStrc* pQuestData)
{
    QUESTS_DebugOutput(pQuestData->pGame, "Started quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 599);
}

// 0x00592960
static void __stdcall ACT1Q4_SpawnCainInTown(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2ActiveRoomStrc* pFreeRoom = pRoom;

    D2DrlgCoordsStrc pRoomCoord;
    DUNGEON_GetRoomCoordinates(pRoom, &pRoomCoord);

    D2CoordStrc pCoord;
    pCoord.nX = nX;
    pCoord.nY = nY;

    int nCounter = 0;
    while (pCoord.nX < pRoomCoord.nSubtileX || pCoord.nY < pRoomCoord.nSubtileY
        || pCoord.nX >= pRoomCoord.nSubtileWidth + pRoomCoord.nSubtileX - 1 || pCoord.nY >= pRoomCoord.nSubtileHeight + pRoomCoord.nSubtileY - 1)
    {
        ++nCounter;
        ++pCoord.nX;
        ++pCoord.nY;
        if (nCounter > 20)
        {
            pCoord.nX = nY;
            break;
        }
    }

    QUESTS_GetFreePosition(pRoom, &pCoord, 2, 0x100, &pFreeRoom, 1, 100);
    if (!pFreeRoom)
    {
        pFreeRoom = pRoom;
        pCoord.nX = nX;
        pCoord.nY = nY;
    }

    D2UnitStrc* pCain = D2GAME_SpawnMonster_6FC69F10(pGame, pFreeRoom, pCoord.nX, pCoord.nY, 0x109, 1, 5, 0);
    if (pCain)
    {
        pCain->dwFlags |= 0x3000000;
        pQuestDataEx->bCainInTownSpawned = 1;
        pQuestDataEx->bCainInTownSpawnPending = 0;
        pQuestDataEx->nCainMonsterInTownGUID = !pCain ? -1 : pCain->dwUnitId;
        return;
    }

    {
        nCounter = 0;
        do
        {
            ++pCoord.nX;
            ++pCoord.nY;
            pFreeRoom = D2GAME_GetRoom_6FC52070(pFreeRoom, pCoord.nX, pCoord.nY);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                pCoord.nX = nX;
                pCoord.nY = nY;
            }

            QUESTS_GetFreePosition(pFreeRoom, &pCoord, 2, 0x100, &pFreeRoom, 2, 100);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                pCoord.nX = nX;
                pCoord.nY = nY;
            }

            ++nCounter;
            pCain = D2GAME_SpawnMonster_6FC69F10(pGame, pFreeRoom, pCoord.nX, pCoord.nY, 0x109, 1, 10, 0);
            if (pCain)
            {
                pCain->dwFlags |= 0x3000000;
                pQuestDataEx->bCainInTownSpawned = 1;
                pQuestDataEx->bCainInTownSpawnPending = 0;
                pQuestDataEx->nCainMonsterInTownGUID = !pCain ? -1 : pCain->dwUnitId;
                return;
            }
        }
        while (nCounter < 20);
    }

    pCain = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, 0x109, 1, 15, 0);
    if (!pCain)
    {
        return;
    }

    pCain->dwFlags |= 0x3000000;
    pQuestDataEx->bCainInTownSpawned = 1;
    pQuestDataEx->bCainInTownSpawnPending = 0;
    pQuestDataEx->nCainMonsterInTownGUID = !pCain ? -1 : pCain->dwUnitId;
}

// 0x005940E0
void __fastcall OBJECTS_InitFunction54_CainStartPosition(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nCainObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    pQuestDataEx->bCainObjectInitialized = 1;
    pQuestDataEx->pCainStartPositionCoords.nX = pOp->nX;
    pQuestDataEx->pCainStartPositionCoords.nY = pOp->nY;

    if (pQuestDataEx->bCainInTownSpawnPending == 1 && !pQuestDataEx->bCainInTownSpawned)
    {
        ACT1Q4_SpawnCainInTown(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY);
    }
}

// 0x00596CA0
static void __stdcall ACT1Q4_UpdateObjects(char bUseRemovalTimer, char bMoveCainToTown, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pCage = 0;
    if (pQuestDataEx->bCageModeChanged == 1)
    {
        pCage = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nCainGibbetGUID);
    }

    if (pCage && pCage->dwClassId == 0x1A)
    {
        int nAnimMode = 0;
        if (pCage)
        {
            nAnimMode = pCage->dwAnimMode;
        }

        if (nAnimMode != 3)
        {
            UNITS_ChangeAnimMode(pCage, 3);
            pQuestDataEx->nCainGibbetObjectMode = 3;
        }
    }
    else
    {
        pQuestDataEx->nCainGibbetObjectMode = 3;
    }

    if (pQuestDataEx->bInifussTreeInitialized == 1)
    {
        D2UnitStrc* pInifussTree = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nInifussTreeGUID);
        if (pInifussTree)
        {
            UNITS_ChangeAnimMode(pInifussTree, 1);
        }
    }

    if (bUseRemovalTimer)
    {
        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            QUESTS_CreateTimer(pQuestData, ACT1Q4_Timer_RemoveCainFromTristram, 1);
        }
    }
    else if (bMoveCainToTown)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 1, 0, ACT1Q4_UnitIterate_RemoveCainFromTristram);
    }
    else
    {
        pQuestDataEx->unk0x50 = 1;
        return;
    }

    if (!bMoveCainToTown)
    {
        pQuestDataEx->unk0x50 = 1;
        return;
    }

    if (!pQuestDataEx->bCainRemovedFromTristram)
    {
        SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x92, 0);
    }

    pQuestDataEx->unk0x50 = 1;
    if (!pQuestDataEx->bCainInTownSpawned)
    {
        pQuestDataEx->bCainInTownSpawnPending = 1;
    }
}

void __fastcall sub_00596D70_StartCainRemoval(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->unk0x65)
        {
            ACT1Q4_UpdateObjects(1, 0, pQuestData);
            QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x351);
            pQuestDataEx->unk0x65 = 1;
        }
    }
    else
    {
        D2_ASSERT(pQuestData, 0x357);
    }
}

inline D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer) { return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty]; }
// 0x00596DE0
void __fastcall ACT1Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    int nOldLevel = pQuestArg->nOldLevel;
    const int nNewLevel = pQuestArg->nNewLevel;

    if (nNewLevel == 0x26 && !pQuestDataEx->bCainInTownSpawned && !pQuestDataEx->unk0x50 && pQuestData->fState >= 6)
    {
        sub_00592860_DebugStartedQuest(pQuestData);
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x422);
        pQuestData->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuestData, 4, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 0);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }

    if (*(const int*)&nOldLevel == 1)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

        QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = GetQuestFlags(pGame, pQuestArg->pPlayer);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            return;
        }

        if (pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x436);
        }
    }

    if (nNewLevel == 1)
    {
        D2Act1Quest4Strc* pQuestDataEx2 = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx2->bCainObjectInitialized)
        {
            D2UnitStrc* pCain = SUNIT_GetServerUnit(pQuestArg->pGame, 2, pQuestDataEx2->nCainObjectGUID);
            if (pCain && pQuestDataEx2->bCainInTownSpawnPending == 1 && !pQuestDataEx2->bCainInTownSpawned)
            {
                ACT1Q4_SpawnCainInTown(pQuestArg->pGame, UNITS_GetRoom(pCain), UNITS_GetXPosition(pCain), CLIENTS_GetUnitY(pCain));
            }
        }
    }
    else if (nNewLevel == 0x28)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = GetQuestFlags(pGame, pQuestArg->pPlayer);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            return;
        }

        if (!pQuestDataEx->unk0x50 && pQuestData->fState < 6)
        {
            sub_00592860_DebugStartedQuest(pQuestData);
            ACT1Q4_UpdateObjects(0, 1, pQuestData);
            QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x458);
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 5, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
            QUESTS_SetGlobalState(pQuestData->pGame, 4, 13);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_AddPlayerGUIDs);
            pQuestDataEx->unk0x58 = 1;
        }
    }
}

void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1 || ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->unk0x50)
    {
        return;
    }

    if (pQuestData->fState >= 6)
    {
        return;
    }

    sub_00592860_DebugStartedQuest(pQuestData);
    ACT1Q4_UpdateObjects(0, 1, pQuestData);
    QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x9FD);
    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 5, pUnit, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
    QUESTS_SetGlobalState(pGame, 4, 13);
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT1Q4_UnitIterate_AddPlayerGUIDs);
}
