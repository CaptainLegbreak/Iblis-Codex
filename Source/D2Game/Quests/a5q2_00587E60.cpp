#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2Act5Quest2Strc
{
    char tPlayerGUIDs[0x84];
    unsigned char bQualKehkActivated;
    char unk0x85[0xA8 - 0x85];
    int nKilledWussies;
    int nFreedWussies;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

// 0x00587E60
void __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2BitBufferStrc* pQuestFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 0xD);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x20);
    D2Act5Quest2Strc* const pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nFreedWussies == 15)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 5);
    }
    else if (pQuestDataEx->nFreedWussies == 14)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 6);
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 7);
    }
}
