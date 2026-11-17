struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
};

struct D2Act4Quest2Strc
{
    char unk0x00[0x1C];
    int nPlayerCount;
    char unk0x20[0x1C];
    D2ActiveRoomStrc* pRoom;
};

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);          // 0x0065C360
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C310
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest);         // 0x0065C3E0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty);      // 0x00538680
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

// 0x005B4D20
static void __stdcall sub_005B4D20(D2BitBufferStrc* pQuestFlags, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 0);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 26);
    if (!pGame->bExpansion)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 6);
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 7);
        CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 592), 4, pGame->nDifficulty);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData)
    {
        ++((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->nPlayerCount;
    }
}

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
        sub_005B4D20(pQuestFlags, pGame, pUnit);
    }

    return 0;
}
