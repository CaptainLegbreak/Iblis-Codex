#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nZooMonsterId;
    unsigned char unk0x05[0x0A];
};
#pragma pack(pop)

struct D2ClientStrc;
struct D2BitBufferStrc;
struct D2UnitStrc;

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

struct D2Act5Quest6Strc
{
    char unk0x00[0x9C];
    int nLastPortalObjectMode;
    unsigned char bZooInitialized;
    unsigned char pad0xA1[3];
    unsigned short nZooMonsterId;
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
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    D2Act5Quest6Strc* pQuestDataEx;
    char tPlayerGUIDs[0x84];
    void* pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#define UNIT_PLAYER 0
#define QUEST_A5Q6_BAAL 36
#define LEVEL_HARROGATH 109
#define LEVEL_THRONEOFDESTRUCTION 131
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1

void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket);            // 0x0053D7E0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x0058D770
int __fastcall ACT5Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D8B0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x0058E120
static void sub_0058E120_SendZooMonsterId(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 579);
    D2GSPacketSrv50 packet50;
    packet50.nHeader = 0x50;
    packet50.nQuestId = QUEST_A5Q6_BAAL;
    packet50.nZooMonsterId = QUESTS_GetQuestData(pGame, QUEST_A5Q6_BAAL)->pQuestDataEx->nZooMonsterId;
    D2GAME_SendPacket0x50_6FC3F440(pClient, &packet50);
}

// 0x0058E180
int __fastcall ACT5Q6_UnitIterate_SendZooMonsterIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    sub_0058E120_SendZooMonsterId(pGame, pUnit);
    return 0;
}

// 0x0058E190
void __fastcall ACT5Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    const int nNewLevel = pQuestArg->nNewLevel;
    if (nNewLevel == LEVEL_HARROGATH)
    {
        sub_0058E120_SendZooMonsterId(pQuestArg->pGame, pQuestArg->pPlayer);
    }

    if (nOldLevel == LEVEL_HARROGATH)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            D2UnitStrc* pPlayer = pQuestArg->pPlayer;
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, QFLAG_REWARDPENDING) == 1)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 626);
            if (pQuestData->fLastState != 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q6_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel >= LEVEL_THRONEOFDESTRUCTION)
    {
        if (pQuestData->bNotIntro && pQuestData->fLastState < 2)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q6_UnitIterate_UpdateQuestStateFlags);
    }
}
