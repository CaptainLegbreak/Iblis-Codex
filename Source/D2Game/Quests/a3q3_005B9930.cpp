#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
struct D2RoomCoordListStrc;
struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0xC4];
    void* pAct;
};
struct D2QuestExStrc
{
    char unk0x00[0x02];
    unsigned char bMonsterSpawned;
    unsigned char f_3;
    unsigned char bSpawning;
    unsigned char unk0x05;
    char unk0x06[0x02];
    int nX;
    int nY;
    int unk0x10[2];
    unsigned char bInitDone;
    char unk0x19[0x0B];
    int nMonsterUnitId;
};
typedef int(__fastcall* QUESTCB)(D2QuestDataStrc*, void*);
struct D2QuestDataStrc
{
    char unk0x00[0x09];
    unsigned char bActive;
    char unk0x0A[0x0E];
    D2QuestExStrc* pQuestDataEx;
    char unk0x1C[0xA4];
    QUESTCB pCallback;
};
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(void* pAct, int a2, int a3);                              // 0x00619DA0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                 // 0x00543640
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                            // 0x00624690

// 0x005B9930
static __declspec(noinline) void sub_005B9930_QUESTS_SpawnQuestMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2QuestExStrc* pQuestDataEx)
{
    pQuestDataEx->bSpawning = 1;
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueGroup(pGame, pRoom, 0, 0x197, 1, 0, 0, 1);
    if (pMonster)
    {
        pQuestDataEx->f_3 = 0;
        pQuestDataEx->bMonsterSpawned = 1;
        pQuestDataEx->nMonsterUnitId = pMonster->dwUnitId;
    }
    pQuestDataEx->bSpawning = 0;
}

bool __fastcall sub_005B9A30_QuestSeqCallback(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2QuestExStrc* pQuestDataEx = pQuestData->pQuestDataEx;
    pQuestDataEx->unk0x05 = 0;
    if (pQuestDataEx->bInitDone == 1 && pQuestDataEx->f_3 && !pQuestDataEx->bMonsterSpawned && pGame->pAct)
    {
        D2ActiveRoomStrc* pRoom = sub_00619DA0_ActLookup(pGame->pAct, pQuestDataEx->nX, pQuestDataEx->nY);
        if (pRoom)
        {
            D2ActiveRoomStrc** ppRoomList;
            unsigned int nNumRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
            for (unsigned int i = 0; i < nNumRooms; ++i)
            {
                for (D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
                {
                    if (pUnit->dwUnitType == 0)
                    {
                        sub_005B9930_QUESTS_SpawnQuestMonster(pGame, pRoom, pQuestDataEx);
                        pQuestData->pCallback = sub_005B9980_QuestCallback;
                        return true;
                    }
                }
            }
        }
    }
    return true;
}

// 0x005B9AE0
void __fastcall sub_005B9AE0_OBJECTS_InitQuestSpawnPoint(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 17);
    if (pQuestData)
    {
        if (pQuestData->bActive)
        {
            D2QuestExStrc* pQuestDataEx = pQuestData->pQuestDataEx;
            pQuestDataEx->bInitDone = 1;
            pQuestDataEx->nX = pOp->nX;
            pQuestDataEx->nY = pOp->nY;
            if (pQuestDataEx->f_3 && !pQuestDataEx->bMonsterSpawned)
            {
                sub_005B9930_QUESTS_SpawnQuestMonster(pOp->pGame, pOp->pRoom, pQuestDataEx);
            }
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}
