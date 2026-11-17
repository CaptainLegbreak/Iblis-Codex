struct D2SeedStrc;
struct D2ClientStrc;

#pragma pack(push, 1)
struct D2GSPacketSrv53
{
    unsigned char nHeader;
    int nIndex;
    int nTicks;
    unsigned char bEclipse;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};
#pragma pack(pop)

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xA8];
    unsigned int dwDropItemCode;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2BitBufferStrc;

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
    char unk0x1C[0xC4];
    int nQuestFilter;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x8C];
    int nGoldPilesToDropFromWirtsBody;
    unsigned char bWirtsBodyInitialized;
    char unk0x91[0x23];
    D2QuestGUIDStrc tPlayerGUIDs;
};

struct D2Act3Quest7Strc
{
    char unk0x00[0x0C];
    unsigned char bVileDogsSpawned;
    unsigned char bVileDogSpawnTimerCreated;
    unsigned char unk0x0E[2];
    int nDarkWandererGUID;
};

struct D2Act4Quest3Strc
{
    char unk0x00[0x1C];
    unsigned char bSoulstoneAcquired;
};

struct D2Act5Quest5Strc
{
    char unk0x00[0x44];
    int nAncientsAlive;
    unsigned char bAncientsActivated;
};

struct D2Act5Quest6Strc
{
    char unk0x00[0x90];
    unsigned char bQuestStarted;
};

#define QUEST_A1Q4_CAIN 4
#define QUEST_A2Q3_TAINTEDSUN 10
#define ACT_II 1
#define QUEST_A3Q7_DARKWANDERER 28
#define QUEST_A5Q5_ANCIENTS 35
#define ITEMQUAL_NORMAL 2
#define EVENTTYPE_QUESTFN 7
#define QUESTSTATEFLAG_A5Q6 40
#define QUESTSTATEFLAG_A4Q1 25
#define QUESTSTATEFLAG_A4Q3 27
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM1 5
#define QFLAG_CUSTOM2 6
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_CUSTOM5 9
#define QFLAG_CUSTOM6 10
#define MONSTER_CAIN4 246
#define MONSTER_TYRAEL2 367
#define MONSTER_IZUALGHOST 406
#define MONSTER_LARZUK 511
#define MONSTER_DREHYA 512
#define MONSTER_MALAH 513
#define MONSTER_QUAL_KEHK 515
#define MONSTER_CAIN6 520
#define MONSTER_TYRAEL3 521
#define MONSTER_ANCIENTSTATUE1 539
#define MONSTER_ANCIENTSTATUE3 541

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket);            // 0x0053C900
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
typedef bool(__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
bool __fastcall ACT3Q7_SpawnVileDogs(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                       // 0x005BD390
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame);                                            // 0x005438B0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, void* pItemDrop, int a6, int a7); // 0x00559A30
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// build: context ACT5Q6_ActiveFilterCallback
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId >= MONSTER_ANCIENTSTATUE1 && nNpcId <= MONSTER_ANCIENTSTATUE3)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A5Q5_ANCIENTS);
        if (pQuestData)
        {
            D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
            if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive && pQuest->fState == 1 && !((D2Act5Quest6Strc*)pQuest->pQuestDataEx)->bQuestStarted)
            {
                return true;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    switch (nNpcId)
    {
    case MONSTER_LARZUK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_ENTERAREA))
        {
            return true;
        }
        break;

    case MONSTER_CAIN6:
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM6))
        {
            break;
        }
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM1))
        {
            return true;
        }
        break;

    case MONSTER_MALAH:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM2))
        {
            return true;
        }
        break;

    case MONSTER_TYRAEL3:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM3))
        {
            return true;
        }
        break;

    case MONSTER_QUAL_KEHK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM4))
        {
            return true;
        }
        break;

    case MONSTER_DREHYA:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM5))
        {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
}

// 0x005940A0
void __fastcall sub_005940A0_ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN)->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pPlayer ? -1 : pPlayer->dwUnitId);
}

// 0x00594630
void __fastcall sub_00594630_QuestGoldDrop(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bWirtsBodyInitialized)
    {
        pQuestDataEx->bWirtsBodyInitialized = 1;
        pQuestDataEx->nGoldPilesToDropFromWirtsBody = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 10, 20);
        pUnit->dwDropItemCode = ' dlg';
    }

    if (pQuestDataEx->nGoldPilesToDropFromWirtsBody)
    {
        int nItemLevel = 0;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pUnit, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            --pQuestDataEx->nGoldPilesToDropFromWirtsBody;
            if (pQuestDataEx->nGoldPilesToDropFromWirtsBody > 0)
            {
                EVENT_SetEvent(pQuestData->pGame, pUnit, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 10, 0, 0);
            }
        }
    }
}

// 0x0059A100
int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 322);
    if (CLIENTS_GetActNo(pClient) == ACT_II)
    {
        D2GSPacketSrv53 packet53;
        packet53.nHeader = 0x53;
        packet53.nIndex = 5;
        packet53.nTicks = 0;
        packet53.bEclipse = 1;
        D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);

        D2GSPacketSrv5D packet5D;
        memset(&packet5D, 0, sizeof(packet5D));
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = QUEST_A2Q3_TAINTEDSUN;
        packet5D.nFlags = 16;
        sub_6FC3F380(pClient, &packet5D);
    }

    return 0;
}

// 0x005B37F0
bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nId = nNpcId;
    if (pQuest->bNotIntro && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_REWARDGRANTED))
    {
        if (nId == MONSTER_TYRAEL2)
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_REWARDPENDING) == 1 || pQuest->fState == 1)
            {
                return true;
            }
        }
        else if (nId == MONSTER_IZUALGHOST)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_CUSTOM1))
            {
                return true;
            }
        }
    }

    return false;
}

// 0x005B5EE0
bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nId = nNpcId;
    if (nId == MONSTER_CAIN4 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING)
        && pQuest->bNotIntro && pQuest->fState == 1 && !((D2Act4Quest3Strc*)pQuest->pQuestDataEx)->bSoulstoneAcquired)
    {
        return true;
    }

    return false;
}

// 0x005BD4A0
void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q7_DARKWANDERER);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bVileDogsSpawned || pQuestDataEx->bVileDogSpawnTimerCreated)
    {
        return;
    }

    pQuestDataEx->bVileDogSpawnTimerCreated = 1;
    pQuestDataEx->nDarkWandererGUID = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_CreateTimer(pQuestData, ACT3Q7_SpawnVileDogs, 2);
}
