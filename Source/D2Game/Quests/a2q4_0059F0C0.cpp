#include "D2Game.h"
#include "D2Structs.h"

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2MonsterDataStrc
{
    int unk0x00[12];
    void* pMonInteract;
};


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2Act2Quest4Strc
{
    char unk0x00[12];
    unsigned char bOldSpawned;
    unsigned char bSpawned;
    char unk0x0E[3];
    unsigned char bObjectReady;
    char unk0x12[3];
    unsigned char bCoordinatesSet;
    char unk0x16[18];
    int nX;
    int nY;
    int unk0x30[2];
    int nObjectGUID;
    int nUnitGUID;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char unk0x0D[7];
    unsigned char bTimer;
    char unk0x15[3];
    D2Act2Quest4Strc* pQuestDataEx;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    char unk0x10[4];
    int nOldLevel;
    int nNewLevel;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);           // 0x00545310
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall MONSTERAI_HasInteractUnit(void* pMonInteract);                                               // 0x00572DC0
void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pfCallback, int a4); // 0x00573180
void __fastcall GAME_RemoveUnit(D2UnitStrc* pUnit, D2GameStrc* pGame);                                      // 0x0052E050
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nQuest);                             // 0x00543640
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int a3, unsigned int a4, D2ActiveRoomStrc** ppRoom, int a6, int a7); // 0x00545340
D2UnitStrc* __fastcall sub_005B2F20(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonId, int nMode, int a7, int a8); // 0x005B2F20
int __fastcall ACT2Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0059AD50
int __fastcall ACT2Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x0059ADB0
static void __stdcall sub_0059EF70_SpawnQuestNpc(D2QuestDataStrc* pQuestData, D2CoordStrc* pCoords, D2ActiveRoomStrc* pRoom); // 0x0059EF70

static __forceinline void* QUESTS_GetMonsterInteract(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }
    return 0;
}

static __forceinline D2BitBufferStrc* QUESTS_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static __declspec(noinline) void __stdcall sub_0059EF70_SpawnQuestNpc(D2QuestDataStrc* quest, D2CoordStrc* coords, D2ActiveRoomStrc* room)
{
    D2Act2Quest4Strc* ex = quest->pQuestDataEx;
    if (ex->bOldSpawned == 1)
    {
        D2UnitStrc* unit = SUNIT_GetServerUnit(quest->pGame, 1, ex->nUnitGUID);
        if (unit)
        {
            void* interact = QUESTS_GetMonsterInteract(unit);
            if (MONSTERAI_HasInteractUnit(interact))
            {
                sub_00573180(quest->pGame, unit, 0, 1);
                return;
            }
            GAME_RemoveUnit(unit, quest->pGame);
            ex->bOldSpawned = 0;
        }
    }
    if (ex->bSpawned == 1) return;
    D2QuestDataStrc* other = QUESTS_GetQuestData(quest->pGame, 13);
    if (!other || !other->bNotIntro) goto Advance;
    if (other->fState < 2) goto Retreat;
Advance:
    coords->nX += 15;
    goto Position;
Retreat:
    coords->nX -= 10;
Position:
    coords->nY -= 3;
    D2ActiveRoomStrc* found = D2GAME_GetRoom_6FC52070(room, coords->nX, coords->nY);
    QUESTS_GetFreePosition(room, coords, 3, 0x100, &found, 9, 100);
    D2UnitStrc* npc = sub_005B2F20(quest->pGame, found, coords->nX, coords->nY, 201, 1, -1, 0);
    if (!npc) npc = sub_005B2F20(quest->pGame, found, coords->nX, coords->nY, 201, 1, 2, 0);
    if (npc)
    {
        npc->dwFlags |= 0x03000000;
        ex = quest->pQuestDataEx;
        ex->bSpawned = 1;
        if (!ex->bCoordinatesSet)
        {
            ex->bCoordinatesSet = 1;
            ex->nX = coords->nX;
            ex->nY = coords->nY;
        }
    }
}

// 0x0059F0C0
void __fastcall ACT2Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    const int nNewLevel = pQuestArg->nNewLevel;
    if (nNewLevel == 74)
    {
        bool bChanged = false;
        if (pQuestData->fState < 4)
        {
            bChanged = true;
            QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 663);
        }

        if (pQuestData->fLastState < 4)
        {
            pQuestData->bTimer = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
        }
        else if (!bChanged)
        {
            return;
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
        return;
    }

    if (nNewLevel == 50)
    {
        D2BitBufferStrc* pQuestFlags = QUESTS_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
        QUESTRECORD_SetQuestState(pQuestFlags, 12, 8);
        pQuestFlags = QUESTS_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
        QUESTRECORD_SetQuestState(pQuestFlags, 12, 7);
    }

    if (nOldLevel != 40)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = pQuestData->pQuestDataEx;
    if (pQuestDataEx->bOldSpawned == 1)
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nUnitGUID);
        if (!pUnit)
        {
            pQuestDataEx->bOldSpawned = 0;
        }
        else if (MONSTERAI_HasInteractUnit(QUESTS_GetMonsterInteract(pUnit)))
        {
            sub_00573180(pQuestData->pGame, pUnit, 0, 1);
        }
        else
        {
            GAME_RemoveUnit(pUnit, pQuestData->pGame);
            pQuestDataEx->bOldSpawned = 0;
        }
    }

    if (!pQuestDataEx->bSpawned && pQuestDataEx->bObjectReady)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nObjectGUID);
        if (pObject)
        {
            D2CoordStrc tCoords;
            UNITS_GetCoords(pObject, &tCoords);
            sub_0059EF70_SpawnQuestNpc(pQuestData, &tCoords, UNITS_GetRoom(pObject));
        }
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    D2BitBufferStrc* pQuestFlags = QUESTS_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 12, 0) == 1)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 12, 1) == 1)
    {
        return;
    }

    if (pQuestData->fState == 3)
    {
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 734);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
    }
}
