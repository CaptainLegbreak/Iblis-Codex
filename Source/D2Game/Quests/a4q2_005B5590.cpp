#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2QuestData.h"









typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                        // 0x005B4BE0

// build: symbol ?ACT4Q2_KillAllMonstersInCS@@YGXPAUD2GameStrc@@PAUD2Act4Quest2Strc@@@Z 0x005B5230
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

// 0x005B5590
void __fastcall OBJECTS_InitFunction55_DiabloStartPoint(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDiabloSpawned)
    {
        return;
    }

    pQuestDataEx->bDiabloStartPointInitialized = 1;
    pQuestDataEx->nDiabloStartPointObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    for (int nCounter = 0; nCounter < 5; ++nCounter)
    {
        if (!pQuestDataEx->bSealActivated[nCounter])
        {
            return;
        }
    }

    if (pQuestDataEx->nBossesKilled != 3)
    {
        return;
    }

    ACT4Q2_KillAllMonstersInCS(pOp->pGame, pQuestDataEx);
    if (pQuestDataEx->bTimerCreated)
    {
        return;
    }

    pQuestDataEx->dwTickCount = 0;
    pQuestDataEx->bNeedToSpawnDiablo = 1;
    pQuestDataEx->unk0x03 = 0;
    pQuestDataEx->bTimerCreated = 1;
    QUESTS_CreateTimer(pQuestData, (QUESTUPDATE)ACT4Q2_SpawnDiablo, 1);
}
