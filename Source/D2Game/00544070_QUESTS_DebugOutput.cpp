extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define ACT_III 2
#define QUEST_A3Q4_GOLDENBIRD 0x12
#define MONSTER_JERHYN 0xC9
#define MONSTER_ACT2GUARD2 0x14B
#define MONSTER_FETISH11 0x197
#define MONSTATSFLAGINDEX_FLYING 14
#define STRCOLOR_DARK_GOLD 4
#define NUM_QUEST_PLAYER_GUIDS 32

struct D2ActiveRoomStrc;

struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[5];
    unsigned char bNotIntro;
    unsigned char bActive;
    char unk0x0B[0xD5];
    int nQuestFilter;
    char unk0xE4[0x10];
    D2QuestDataStrc* pPrev;
};

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
};

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x6C];
    D2QuestChainStrc* pQuestEventList;
};

struct D2GameStrc
{
    char unk0x0000[0x10F4];
    D2QuestInfoStrc* pQuestControl;
};

struct D2MonStatsTxt
{
    char unk0x000[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x010[0x198];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int dword_6FD4DC34;                                                                                  // 0x008846DC
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __fastcall sub_6FC84C70(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);              // 0x0054A930
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall sub_0059B6C0_JerhynSpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);        // 0x0059B6C0
void __fastcall sub_0059B6D0_Act2Guard2SpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);    // 0x0059B6D0
void __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);     // 0x005BAC70
void __fastcall sub_005BACF0_GoldenBirdSpawnCheck(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);        // 0x005BACF0

// build: context QUESTS_GetQuestData_Inlined
static D2QuestDataStrc* QUESTS_GetQuestData_Inlined(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int QUESTS_QuickCheckPlayerGUID_Inlined(D2QuestGUIDStrc* pGUIDs, int dwGUID)
{
    for (int i = 0; i < pGUIDs->nPlayerCount; ++i)
    {
        if (pGUIDs->nPlayerGUIDs[i] == dwGUID)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00544070
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine)
{
    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pGame, szMessage, STRCOLOR_DARK_GOLD);
    }
}

// 0x005447A0
void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, D2UnitStrc* pWarriv, int nXpos, int nYpos, int nWarrivID)
{
    if (nWarrivID >= 0 && nWarrivID < sgptDataTables->nMonStatsTxtRecordCount)
    {
        switch (nWarrivID)
        {
        case MONSTER_JERHYN:
            sub_0059B6C0_JerhynSpawnHook(pGame, pWarriv, nXpos, nYpos);
            break;
        case MONSTER_ACT2GUARD2:
            sub_0059B6D0_Act2Guard2SpawnHook(pGame, pWarriv, nXpos, nYpos);
            break;
        }
    }
}

// 0x00544E80
void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_III)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData_Inlined(pGame, QUEST_A3Q4_GOLDENBIRD);

    if (!pUnit)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord && pQuestData && pQuestData->bNotIntro == 1 && pUnit->dwClassId != MONSTER_FETISH11
        && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_FLYING >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_FLYING & 7]))
    {
        ACT3Q4_UnitIterate_SetGoldenBirdBoss(pQuestData, pUnit);
    }
}

// 0x00544F20
void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestChainStrc* pQuestChain = pUnit->pQuestEventList;
    if (!pQuestChain)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_III)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = pQuestChain->pQuestData;
    if (pQuestData->nQuestFilter != 20 || pQuestData->bActive != 1)
    {
        return;
    }

    sub_005BACF0_GoldenBirdSpawnCheck(pQuestData, pUnit);
}

// 0x00545200
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID)
{
    if (pQuestGUID->nPlayerCount >= NUM_QUEST_PLAYER_GUIDS)
    {
        return;
    }

    if (QUESTS_QuickCheckPlayerGUID_Inlined(pQuestGUID, dwGUID))
    {
        return;
    }

    pQuestGUID->nPlayerGUIDs[pQuestGUID->nPlayerCount] = dwGUID;
    ++pQuestGUID->nPlayerCount;
}

// 0x00545240
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID)
{
    for (int i = 0; i < pGUIDs->nPlayerCount; ++i)
    {
        if (pGUIDs->nPlayerGUIDs[i] == dwGUID)
        {
            if (i != pGUIDs->nPlayerCount - 1)
            {
                pGUIDs->nPlayerGUIDs[i] = pGUIDs->nPlayerGUIDs[pGUIDs->nPlayerCount - 1];
            }

            --pGUIDs->nPlayerCount;
            return 1;
        }
    }

    return 0;
}
