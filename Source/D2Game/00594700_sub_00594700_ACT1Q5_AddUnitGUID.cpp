struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    char unk0x00[0x0C];
    int dwUnitId;
};

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

// 0x00594700
static void __stdcall sub_00594700_ACT1Q5_AddUnitGUID(D2Act1Quest5Strc* pQuestDataEx, int nUnitId, int bSecondList)
{
    if (bSecondList)
    {
        if (pQuestDataEx->nUnitCount2 < 12)
        {
            pQuestDataEx->nUnitGUIDs2[pQuestDataEx->nUnitCount2] = nUnitId;
            pQuestDataEx->nUnitCount2 += 1;
        }
    }
    else
    {
        if (pQuestDataEx->nUnitCount1 < 12)
        {
            pQuestDataEx->nUnitGUIDs1[pQuestDataEx->nUnitCount1] = nUnitId;
            pQuestDataEx->nUnitCount1 += 1;
        }
    }
}

__forceinline D2BitBufferStrc* ACT1Q5_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00594F10
int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = ACT1Q5_GetPlayerQuestFlags_Inline(pGame, pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
        return 0;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == 0x19)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0);
        QUESTRECORD_ClearQuestState(pQuestFlags, 5, 1);
        SUNIT_AttachSound(pUnit, 0x25, pUnit);

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 5);
        if (!pQuestData)
            return 0;

        D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
        const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
        sub_00594700_ACT1Q5_AddUnitGUID(pQuestDataEx, nUnitId, 1);
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 5, 0xE);
    return 0;
}
