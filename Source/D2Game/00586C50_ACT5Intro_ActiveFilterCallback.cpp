struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2ClientStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
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
    char unk0x0D[0x0B];
    void* pQuestDataEx;
    char unk0x1C[0xC4];
    int nQuestFilter;
};

struct D2Act5Quest1Strc
{
    char unk0x00[0x04];
    D2ActiveRoomStrc* pRoom;
};

struct D2Act5Quest3Strc
{
    char unk0x00[0xAE];
    unsigned char bChangeToSpecialObjectModeInTown;
    char unk0xAF[0x03];
    unsigned char bDrehyaPortalInTownSpawned;
    char unk0xB3[0x05];
    D2CoordStrc tDrehyaPortalInTownCoords;
};

struct D2Act1Quest4Strc
{
    char unk0x00[0x28];
    int nInvisibleObjectGUID;
    char unk0x2C[0x1D];
    unsigned char bInvisbleObjectInitialized;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId);                // 0x005723C0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

#define MONSTER_AKARA 148
#define MONSTER_KASHYA 150
#define MONSTER_WARRIV1 155
#define MONSTER_LARZUK 511
#define MONSTER_MALAH 513
#define MONSTER_QUAL_KEHK 515
#define QUEST_A1Q4_CAIN 4
#define QUEST_A5Q1_SHENK 31
#define QUEST_A5Q3_PRISONOFICE 33
#define QUEST_A5Q6_BAAL 36
#define QUESTSTATEFLAG_A1Q0 0
#define QUESTSTATEFLAG_A5Q1 35
#define QUESTSTATEFLAG_A5Q6 40
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_CUSTOM1 5
#define QFLAG_PRIMARYGOALDONE 13
#define QUEST_LOG_PACKET 0x5D

// 0x00586C50
bool __fastcall ACT5Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_MALAH))
    {
        return true;
    }

    return false;
}

// 0x00587100
int __fastcall ACT5Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED))
    {
        D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK)->pQuestDataEx;
        bool bFound = false;
        if (pRoom == pQuestDataEx->pRoom)
        {
            bFound = true;
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
                    bFound = true;
                    break;
                }
            }
        }

        pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (bFound)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE);
        }
    }

    return 0;
}

// 0x005874E0
bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_LARZUK)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_CUSTOM1))
        {
            return true;
        }

        if (pQuest->bNotIntro && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }

    return false;
}

// 0x00589070
void __fastcall ACT5Q3_SendPacket0x5DToClient(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nFlags = 32;
    packet5D.nQuestId = QUEST_A5Q3_PRISONOFICE;
    sub_6FC3F380(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 286), &packet5D);
}

// 0x0058A7D0
int __fastcall sub_0058A7D0_GetDrehyaPortalInTownCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDrehyaPortalInTownSpawned || pQuestDataEx->bChangeToSpecialObjectModeInTown)
    {
        return 0;
    }

    pCoord->nX = pQuestDataEx->tDrehyaPortalInTownCoords.nX;
    pCoord->nY = pQuestDataEx->tDrehyaPortalInTownCoords.nY;
    return 1;
}

// 0x0058CCF0
bool __fastcall ACT5Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId != MONSTER_QUAL_KEHK || pQuest->fState != 1)
    {
        return false;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    return true;
}

// 0x0058DE30
int __fastcall ACT5Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 472);
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nQuestId = QUEST_A5Q6_BAAL;
    packet5D.nFlags = 2;
    sub_6FC3F380(pClient, &packet5D);

    SUNIT_AttachSound(pUnit, 83, pUnit);
    return 0;
}

// 0x0058F9B0
bool __fastcall ACT1Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x0058FB50
bool __fastcall ACT1Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_WARRIV1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    return false;
}

// 0x005905B0
bool __fastcall ACT1Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_AKARA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->bNotIntro == 1 && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
}

// 0x00591080
bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_KASHYA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
}

// 0x00592880
void __fastcall ACT1Q4_SendPacket0x5DToClient(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nFlags = 1;
    packet5D.nQuestId = QUEST_A1Q4_CAIN;
    sub_6FC3F380(SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 613), &packet5D);
}

// 0x00592F80
void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bInvisbleObjectInitialized = 1;
    pQuestDataEx->nInvisibleObjectGUID = !pUnit ? -1 : pUnit->dwUnitId;
}
