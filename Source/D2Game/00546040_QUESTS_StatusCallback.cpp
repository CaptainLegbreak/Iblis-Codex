extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
typedef int(__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2DrlgActStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;

struct T005438E0
{
    D2QuestDataStrc* pLastQuest;
    char unk0x04[0x8];
    D2BitBufferStrc* pQuestFlags;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x4E];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1024];
    T005438E0* pQuestControl;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

struct D2QuestDataStrc
{
    int nQuestNo;
    char pad0x04[0x7];
    unsigned char fLastState;
    char pad0x0C[0xD4];
    int nQuestFilter;
    char pad0xE4[0x4];
    QUESTSTATUSFILTER pfStatusFilter;
    char pad0xEC[0x8];
    D2QuestDataStrc* pPrev;
};

#define MAX_QUEST_STATUS 41

#pragma pack(push, 1)
struct D2GSPacketSrv52
{
    unsigned char nHeader;
    unsigned char pQuestList[MAX_QUEST_STATUS];
};

struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nMonstersToBeKilled;
    unsigned short nStaffTombLevelOffset;
    unsigned short nBarbsToBeRescued;
    unsigned char unk0x09[6];
};
#pragma pack(pop)

extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket);            // 0x0053D7E0
void __fastcall sub_0053D840(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket);                     // 0x0053D840
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pQuestList, D2BitBufferStrc* pQuestFlags); // 0x00543F90
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
unsigned short __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData);                         // 0x00588C50
unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc* pQuestData);                       // 0x005901E0
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct);                                     // 0x0061AEB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

#define QFLAG_REWARDGRANTED 0
#define QFLAG_PRIMARYGOALDONE 13
#define QUESTSTATEFLAG_A1Q1 1
#define QUESTSTATEFLAG_A2Q4 12
#define QUESTSTATEFLAG_A5Q2 36
#define QUEST_A1Q1_DENOFEVIL 1
#define QUEST_A5Q2_RESCUESOLDIERS 32
#define LEVEL_TALRASHASTOMB1 66
#define ACT_II 1
#define QUEST_FLAGS_PACKET 0x28
#define QUEST_FLAGS_KIND 6
#define PACKET_QUESTSTATUS 0x52
#define PACKET_QUESTPROGRESS 0x50
#define LINE_UPDATEFLAGS_CLIENT 0xCA7
#define LINE_STATUS_CLIENT 0x49A
#define LINE_STATUS_QUESTNO 0x4B3
#define LINE_STATUS_FILTER 0x4CB

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, LINE_UPDATEFLAGS_CLIENT), QUEST_FLAGS_PACKET, QUEST_FLAGS_KIND, 0, pQuestFlags, 0);
}

// 0x00546040
void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszQuestsSourceFile, LINE_STATUS_CLIENT);
    D2GSPacketSrv52 packet52 = { PACKET_QUESTSTATUS };

    T005438E0* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }

    D2QuestDataStrc* pQuest = pQuestControl->pLastQuest;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    for (; pQuest; pQuest = pQuest->pPrev)
    {
        D2_ASSERT(pQuest->nQuestNo < MAX_QUEST_STATUS, LINE_STATUS_QUESTNO);

        if (pQuest->fLastState)
        {
            if (!pQuest->pfStatusFilter)
            {
                QUESTS_RefreshStatus(pQuest, &packet52.pQuestList[pQuest->nQuestFilter], pQuestFlags);
            }
            else
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfStatusFilter), LINE_STATUS_FILTER);

                unsigned char nStatus;
                if (pQuest->pfStatusFilter(pQuest, pUnit, pQuestControl->pQuestFlags, pQuestFlags, &nStatus) == 1)
                {
                    packet52.pQuestList[pQuest->nQuestFilter] = nStatus;
                }
            }
        }
    }

    bool bSendPacket0x50 = false;
    D2GSPacketSrv50 packet50 = {};
    if (packet52.pQuestList[QUESTSTATEFLAG_A1Q1] && pGame->pQuestControl)
    {
        D2QuestDataStrc* pQuestData1 = pGame->pQuestControl->pLastQuest;
        while (pQuestData1 && pQuestData1->nQuestNo != QUEST_A1Q1_DENOFEVIL)
        {
            pQuestData1 = pQuestData1->pPrev;
        }

        if (pQuestData1)
        {
            bSendPacket0x50 = true;
            packet50.nMonstersToBeKilled = ACT1Q1_GetMonstersToBeKilled(pQuestData1);
        }
    }

    if (packet52.pQuestList[QUESTSTATEFLAG_A5Q2] && pGame->pQuestControl)
    {
        D2QuestDataStrc* pQuestData32 = pGame->pQuestControl->pLastQuest;
        while (pQuestData32 && pQuestData32->nQuestNo != QUEST_A5Q2_RESCUESOLDIERS)
        {
            pQuestData32 = pQuestData32->pPrev;
        }

        if (pQuestData32)
        {
            bSendPacket0x50 = true;
            packet50.nBarbsToBeRescued = ACT5Q2_GetBarbsToBeRescued(pQuestData32);
        }
    }

    if ((QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE)) && pGame->pAct[ACT_II])
    {
        bSendPacket0x50 = true;
        packet50.nStaffTombLevelOffset = DUNGEON_GetHoradricStaffTombLevelId(pGame->pAct[ACT_II]) - LEVEL_TALRASHASTOMB1;
    }

    if (bSendPacket0x50)
    {
        packet50.nHeader = PACKET_QUESTPROGRESS;
        packet50.nQuestId = QUEST_A1Q1_DENOFEVIL;
        D2GAME_SendPacket0x50_6FC3F440(pClient, &packet50);
    }

    sub_0053D840(pClient, &packet52);
}
