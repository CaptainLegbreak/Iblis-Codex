#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"







struct D2DataTablesStrc
{
    char unk0x000[0xB36];
    unsigned short wAncientSuperUniqueIds[3];
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2);                                                    // 0x005544B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex); // 0x00545C30
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT5Q5_UnitIterate_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);            // 0x0058D510

static bool sub_0058BEC0_RemoveAncientMonster(D2GameStrc* pGame, int nAncientMonsterGUID)
{
    D2UnitStrc* pAncientMonster = SUNIT_GetServerUnit(pGame, 1, nAncientMonsterGUID);
    if (!pAncientMonster)
    {
        return false;
    }

    if (STATES_CheckState(pAncientMonster, 0x36))
    {
        sub_6FCBDE90(pAncientMonster, 0);
    }

    if (UNITS_GetRoom(pAncientMonster))
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pAncientMonster, 0x0C, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pAncientMonster), 1, nAncientMonsterGUID);
        UNITS_FreeCollisionPath(pAncientMonster);
        UNITROOM_RemoveUnitFromRoom(pAncientMonster);
    }

    return true;
}

// 0x0058C000
static void __stdcall ACT5Q5_DeactivateAncientMonsters(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2Act5Quest5Strc* pQuestDataEx)
{
    for (int i = 0; i < 0x03; ++i)
    {
        if (pQuestDataEx->bAncientMonsterSpawned[i])
        {
            if (sub_0058BEC0_RemoveAncientMonster(pGame, pQuestDataEx->nAncientMonsterGUID[i]))
            {
                --pQuestDataEx->nAncientsSpawned;
                --pQuestDataEx->nAncientsAlive;
            }
            else
            {
                SUNITINACTIVE_DeleteSingleListNode(pGame, 1, i + 0x21C, 0x04);
            }

            pQuestDataEx->bAncientMonsterSpawned[i] = 0;
        }
    }

    pQuestDataEx->bAncientsActivated = 0;

    for (int i = 0; i < 0x03; ++i)
    {
        pQuestDataEx->bAncienStatueRespawned[i] = 0;
        D2UnitStrc* pAncientStatue = SUNIT_GetServerUnit(pQuestData->pGame, 0x02, pQuestDataEx->nAncientStatueGUID[i]);
        if (pAncientStatue)
        {
            UNITS_ChangeAnimMode(pAncientStatue, 0);
        }
        pQuestDataEx->nAncientStatueObjectMode[i] = 0;
    }

    pQuestDataEx->nAltarObjectMode = 0;
    D2UnitStrc* pAltar = SUNIT_GetServerUnit(pGame, 0x02, pQuestDataEx->nAltarGUID);
    if (pAltar)
    {
        UNITS_ChangeAnimMode(pAltar, 0);
    }
}

// 0x0058C0E0
void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if ((pUnit && pUnit->dwAnimMode == 0x04) || pQuestDataEx->nAncientsSpawned >= 0x03)
    {
        return;
    }

    const int nObjectId = !pUnit ? -1 : pUnit->dwClassId;

    D2UnitStrc* pAncient;
    D2CoordStrc tCoord;
    int nIndex = 0;
    int nMonsterId = 0;
    switch (nObjectId)
    {
    case 0x1DA:
        nIndex = 1;
        nMonsterId = sgptDataTables->wAncientSuperUniqueIds[2];
        break;

    case 0x1DB:
        nIndex = 0;
        nMonsterId = sgptDataTables->wAncientSuperUniqueIds[0];
        break;

    case 0x1DC:
        nIndex = 0x02;
        nMonsterId = sgptDataTables->wAncientSuperUniqueIds[1];
        break;

    default:
        return;
    }

    if (pQuestDataEx->nActivePortalCount > 0)
    {
        ACT5Q5_DeactivateAncientMonsters(pQuestData->pGame, pQuestData, pQuestDataEx);
        return;
    }

    UNITS_GetCoords(pUnit, &tCoord);
    pAncient = QUESTS_SpawnMonster(pQuestData->pGame, pUnit, &tCoord, 0x02, nMonsterId);
    if (!pAncient)
    {
        EVENT_SetEvent(pQuestData->pGame, pUnit, 0x07, pQuestData->pGame->dwGameFrame + 0x0A, 0, 0);
        return;
    }

    if (!pUnit || pUnit->dwAnimMode != 0x04)
    {
        UNITS_ChangeAnimMode(pUnit, 0x04);
        pQuestDataEx->nAncientStatueObjectMode[nIndex] = 0x04;
    }

    pQuestDataEx->bAncientMonsterSpawned[pQuestDataEx->nAncientsSpawned] = 1;
    pQuestDataEx->nAncientMonsterGUID[pQuestDataEx->nAncientsSpawned] = !pAncient ? -1 : pAncient->dwUnitId;

    ++pQuestDataEx->nAncientsSpawned;
    ++pQuestDataEx->nAncientsAlive;

    pQuestDataEx->bAncientsActivated = 1;
}

void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bAncientsDefeated)
    {
        return;
    }

    ++((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount;
    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 0;
    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->active = 0;
    ACT5Q5_DeactivateAncientMonsters(pGame, pQuestData, (D2Act5Quest5Strc*)pQuestData->pQuestDataEx);
}

void __fastcall ACT5Q5_OnPlayerDied(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nActivePortalCount || pQuestDataEx->bAncientsDefeated || !pQuestDataEx->bActivatable)
    {
        return;
    }

    pQuestDataEx->nLivingPlayersOnSummit = 0;
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT5Q5_UnitIterate_CountLivingPlayers);

    if (!pQuestDataEx->nLivingPlayersOnSummit)
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 0;
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->active = 0;
        ACT5Q5_DeactivateAncientMonsters(pGame, pQuestData, (D2Act5Quest5Strc*)pQuestData->pQuestDataEx);
    }
}
