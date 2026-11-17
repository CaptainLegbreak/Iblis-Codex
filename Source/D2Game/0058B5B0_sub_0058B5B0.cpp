struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

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

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

// 0x0058B5B0
void __fastcall sub_0058B5B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0xE) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 1) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0xD) == 1)
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

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 1))
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 0xD);
}
