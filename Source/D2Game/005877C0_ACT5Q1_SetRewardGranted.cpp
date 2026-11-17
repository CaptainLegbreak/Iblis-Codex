struct D2StatListStrc;
struct D2BitBufferStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc;
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef int(__stdcall* FARPROC)();

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    char unk0x1C[0xD4];
    QUESTSEQFILTER pfSeqFilter;
};

struct D2Act5Quest2Strc
{
    char unk0x00[0x86];
    unsigned char bWussiesSpawned[3];
    char unk0x89[0x1B];
    int nSpawnedWussies;
    int nKilledWussies;
    int nFreedWussies;
    int nWussieGUIDs[3][5];
};

#define QUEST_A5Q1_SHENK 31
#define QUEST_A5Q2_RESCUESOLDIERS 32
#define QUESTSTATEFLAG_A5Q1 35
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_COMPLETEDBEFORE 15
#define SUPERUNIQUE_SIEGE_BOSS 42
#define UNIT_INVALID 6
#define STAT_FIRERESIST 39
#define STAT_LIGHTRESIST 41
#define STAT_COLDRESIST 43
#define STAT_POISONRESIST 45

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x00586C80
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005879D0
short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit);                                             // 0x005A01E0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);         // 0x0065C3A0

// 0x005877C0
void __fastcall ACT5Q1_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED);
    QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE))
    {
        D2_ASSERT(QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK), 750);
    }
}

// 0x00587900
void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 2 || MONSTERUNIQUE_GetBossHcIdx(pUnit) != SUPERUNIQUE_SIEGE_BOSS)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
}

// 0x00587FC0
int __fastcall sub_00587FC0_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const int nGUID = !pUnit ? -1 : pUnit->dwUnitId;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (nGUID == pQuestDataEx->nWussieGUIDs[i][j])
            {
                return i;
            }
        }
    }

    return -1;
}

// 0x00588C50
int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;

    int nBarbs = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (!pQuestDataEx->bWussiesSpawned[i])
        {
            nBarbs += 5;
        }
    }

    nBarbs += pQuestDataEx->nSpawnedWussies - pQuestDataEx->nFreedWussies - pQuestDataEx->nKilledWussies;
    if (nBarbs < 0)
    {
        nBarbs = 0;
    }

    return nBarbs;
}

// 0x00588DD0
void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q2_RESCUESOLDIERS);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState == 5)
    {
        return;
    }

    if (((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
}

// 0x00589160
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 331);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00589FF0
void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);

    STATLIST_SetStat(pStatList, STAT_FIRERESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_LIGHTRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_COLDRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_POISONRESIST, nValue, 0);

    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_FIRERESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_LIGHTRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_COLDRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_POISONRESIST, nValue, pUnit);
}
