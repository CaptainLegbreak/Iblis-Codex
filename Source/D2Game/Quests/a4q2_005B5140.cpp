#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2QuestData.h"
struct D2GameStrc;
struct D2QuestDataStrc;
struct D2UnitStrc;
struct D2PlayerDataStrc;
struct D2Act4Quest2Strc;
struct D2ModeChangeStrc;
struct D2ObjOperateFnStrc;
struct D2QuestSpawnStrc;





void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0


D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0


D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790




struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
    void* pObjectregion;
    int nObjectIdx;
};


typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005B4BE0

typedef int(__fastcall* UNITITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, D2UnitStrc* pUnit, UNITITERATEFN pfnCallback); // 0x005537D0
int __fastcall ACT4Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B4970
int __fastcall ACT4Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B49C0
int __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B4DF0
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B4E40
int __fastcall ACT4Q2_UnitIterate_UpdatePlayerState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B5140

struct D2QuestSpawnStrc { char unk0x00[0x24]; D2CoordStrc tSpawnCoords[3]; };

struct D2DataTablesStrc { char unk0x00[0xB28]; unsigned short wSpawnIds[3]; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex); // 0x00545C30

// 0x005B4D20
static void __stdcall sub_005B4D20(D2GameStrc* pGame, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pUnit)
{
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 0);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 26);
    if (!pGame->bExpansion)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 6);
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 7);
        CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 592), 4, pGame->nDifficulty);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData)
    {
        ++((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->nPlayerCount;
    }
}

// 0x005B4DA0
void __fastcall sub_005B4DA0_ACT4Q2_UnitIterate_SetCompleted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 3)
    {
        return;
    }

    sub_005B4D20(pGame, pQuestFlags, pUnit);
}

// 0x005B5140
int __fastcall ACT4Q2_UnitIterate_UpdatePlayerState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
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
                bInRange = 1;
                break;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 1) && bInRange)
    {
        sub_005B4D20(pGame, pQuestFlags, pUnit);
    }

    return 0;
}

// 0x005B5230
static void __stdcall ACT4Q2_KillAllMonstersInCS(D2GameStrc* pGame, D2Act4Quest2Strc* pQuestDataEx)
{
    if (pQuestDataEx->bSanctumCleared)
    {
        return;
    }

    pQuestDataEx->bSanctumCleared = 1;
    QUESTS_TriggerFX(pGame, 12);

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[3]); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == 108)
        {
            D2UnitStrc* pNext = 0;
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
            {
                pNext = pUnit->ptRoomNext;
                if (pUnit->dwUnitType == 1 && pUnit->dwClassId != 243 && !SUNIT_IsDead(pUnit) && STATLIST_GetUnitAlignment(pUnit) == 0)
                {
                    D2ModeChangeStrc modeChange;
                    MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                }
            }
        }
    }
}

// 0x005B52E0
void __fastcall ACT4Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (UNIT_CLASSID_OR_INVALID(pQuestArg->pTarget) != 243)
    {
        ++pQuestDataEx->nBossesKilled;
        if (pQuestDataEx->nBossesKilled != 3)
        {
            return;
        }

        for (int i = 0; i < 5; ++i)
        {
            if (!pQuestDataEx->bSealActivated[i])
            {
                return;
            }
        }

        ACT4Q2_KillAllMonstersInCS(pQuestData->pGame, pQuestDataEx);
        if (pQuestDataEx->bTimerCreated)
        {
            return;
        }

        pQuestDataEx->dwTickCount = 0;
        pQuestDataEx->bNeedToSpawnDiablo = 1;
        pQuestDataEx->unk0x03 = 0;
        pQuestDataEx->bTimerCreated = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
        return;
    }
    if (!pQuestData->pGame->bExpansion)
    {
        QUESTS_TriggerFX(pQuestData->pGame, 13);
    }

    pQuestDataEx->bDiabloKilled = 1;
    bool bQuestNotDone = false;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    pQuestDataEx->pRoom = pRoom;
    if (pQuestArg->pPlayer)
    {
        if (!((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bTimerCreated)
        {
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToSpawnDiablo = 0;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->unk0x03 = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToEndGame = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToWarpPlayers = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bClientsSaved = 0;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bTimerCreated = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->dwTickCount = GetTickCount();
            QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
        }

        if (!pQuestData->bNotIntro)
        {
            return;
        }

        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0))
        {
            bQuestNotDone = true;
        }
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    pQuestDataEx->nPlayerCount = 0;
    QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q2_UnitIterate_StatusCyclerEx, 1);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_UpdatePlayerState);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_AttachCompletionSound);
    if (!bQuestNotDone)
    {
        return;
    }

    for (int i = 0; i < pQuestDataEx->nPlayerCount; ++i)
    {
        sub_00545990(pQuestData, pQuestArg, 0x40);
    }
}

// 0x005B5630
int __fastcall OBJECTS_OperateFunction52_DiabloSeal(D2ObjOperateFnStrc* pOp)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == 0)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 7) + pOp->pGame->dwGameFrame, 0, 0);

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
        if (!pQuestData)
        {
            return 0;
        }

        D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;

        switch (!pOp->hObject ? -1 : pOp->hObject->dwClassId)
        {
        case 392:
            pQuestDataEx->bSealActivated[0] = 1;
            break;
        case 393:
            pQuestDataEx->bSealActivated[1] = 1;
            break;
        case 394:
            pQuestDataEx->bSealActivated[2] = 1;
            break;
        case 395:
            pQuestDataEx->bSealActivated[3] = 1;
            break;
        case 396:
            pQuestDataEx->bSealActivated[4] = 1;
            break;
        default:
            break;
        }

        for (int nCounter = 0; nCounter < 5; ++nCounter)
        {
            if (!pQuestDataEx->bSealActivated[nCounter])
            {
                return 0;
            }
        }

        if (pQuestDataEx->nBossesKilled != 3)
        {
            return 0;
        }

        ACT4Q2_KillAllMonstersInCS(pOp->pGame, pQuestDataEx);
        if (pQuestDataEx->bTimerCreated)
        {
            return 0;
        }

        pQuestDataEx->dwTickCount = 0;
        pQuestDataEx->bNeedToSpawnDiablo = 1;
        pQuestDataEx->unk0x03 = 0;
        pQuestDataEx->bTimerCreated = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
    }

    return 0;
}

// 0x005B5750
void __fastcall sub_005B5750_SpawnQuestMonster(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return;
    }
    D2QuestSpawnStrc* pQuestDataEx = (D2QuestSpawnStrc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pMonster;
    if (tCoords.nX == pQuestDataEx->tSpawnCoords[0].nX && tCoords.nY == pQuestDataEx->tSpawnCoords[0].nY)
    {
        pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[0], 2, sgptDataTables->wSpawnIds[0]);
    }
    else if (tCoords.nX == pQuestDataEx->tSpawnCoords[1].nX)
    {
        if (tCoords.nY == pQuestDataEx->tSpawnCoords[1].nY)
        {
            pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[1], 2, sgptDataTables->wSpawnIds[1]);
        }
        else if (tCoords.nX == pQuestDataEx->tSpawnCoords[2].nX && tCoords.nY == pQuestDataEx->tSpawnCoords[2].nY)
        {
            const int nMonId = sgptDataTables->wSpawnIds[2];
            pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[2], 2, nMonId);
        }
        else
        {
            return;
        }
        if (!pMonster)
        {
            EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 10, 0, 0);
        }
        return;
    }
    else if (tCoords.nX == pQuestDataEx->tSpawnCoords[2].nX && tCoords.nY == pQuestDataEx->tSpawnCoords[2].nY)
    {
        const int nMonId = sgptDataTables->wSpawnIds[2];
        pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->tSpawnCoords[2], 2, nMonId);
    }
    else
    {
        return;
    }
    if (!pMonster)
    {
        EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 10, 0, 0);
    }
}
