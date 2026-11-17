typedef int (__stdcall* FARPROC)();
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
    int unk0x08;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);
typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

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
    D2QuestGUIDStrc tPlayerGUIDs;
    void* pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    void* pfStatusFilter;
    void* pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    union
    {
        int nOldLevel;
        unsigned short nNPCNo;
    };
    union
    {
        int nNewLevel;
        unsigned short nMessageIndex;
    };
};

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped;
    unsigned char bHratliActivated;
    unsigned char bBossHasSpawned;
    unsigned char bGidbinnObjectActivated;
    unsigned char bBossIsSpawning;
    unsigned char bSpawnTimerStarted;
    unsigned char unk0x06;
    unsigned char bGidbinnBroughtToOrmus;
    int nGidbinnX;
    int nGidbinnY;
    int nAltarX;
    int nAltarY;
    unsigned char bGidbinnObjectInitialized;
    char unk0x19[0x03];
    int nGidbinnsInGame;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);                      // 0x00544160
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                              // 0x00545200
int __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
void __fastcall D2GAME_NPC_AssignMercenary_6FCCB520(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId);    // 0x00579180
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

int __fastcall ACT3Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005B8BF0
int __fastcall ACT3Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x005B9130
void __fastcall ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B91B0

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

#define MONSTER_HRATLI 253
#define MONSTER_ASHEARA 252
#define MONSTER_ORMUS 255
#define QUESTSTATEFLAG_A3Q3 19

// 0x005B9240
void __fastcall ACT3Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0) == 1)
    {
        return;
    }

    if (nNpcNo == MONSTER_ORMUS)
    {
        if (nMessageIndex == 587)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g') && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 5) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
            {
                ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bGidbinnBroughtToOrmus = 1;
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
                --((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->nGidbinnsInGame;
                QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 6);

                const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pQuestData->pGame, nPartyId, ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState, 0);
                }

                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_SetCompletionFlag);
            }

            if (pQuestData->bNotIntro)
            {
                QUESTS_SetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A3Q3, 13);
            }

            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 0);

            if (!pQuestData->bNotIntro || pQuestData->fState == 5)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 621);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 622);
            pQuestData->pfSeqFilter(pQuestData);
        }
        else if (nMessageIndex == 593 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 6) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8);

            int nItemLevel = 21;
            switch (pQuestArg->pGame->nDifficulty)
            {
            case 1:
                nItemLevel = 35;
                break;
            case 2:
                nItemLevel = 75;
                break;
            }

            QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' nir', nItemLevel, 6, 1);

            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7))
            {
                return;
            }

            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 13);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
    }
    else if (nNpcNo == MONSTER_HRATLI)
    {
        if (nMessageIndex == 571)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 659);
            ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bHratliActivated = 1;
        }
    }
    else if (nNpcNo == MONSTER_ASHEARA)
    {
        if (nMessageIndex != 589 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7);
        D2GAME_NPC_AssignMercenary_6FCCB520(pQuestData->pGame, pQuestArg->pPlayer, MONSTER_ASHEARA);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0);
        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}
