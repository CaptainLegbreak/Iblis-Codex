struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;
struct D2GameStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char pad0x08[0x01];
    unsigned char bNotIntro;
    char pad0x0A[0x02];
    unsigned char fState;
    char pad0x0D[0x0B];
    void* pQuestDataEx;
    char pad0x1C[0xC4];
    int nQuestFilter;
};

struct D2Act1Quest4Strc
{
    char pad0x00[0x92];
    unsigned char bChangePortalInTownToSpecialMode;
    char pad0x93[0x03];
    unsigned char bCainPortalInTownSpawned;
    char pad0x97[0x11];
    D2CoordStrc pCainPortalInTownCoords;
    int nUnk0xB0;
};

struct D2Act2Quest2Strc
{
    char pad0x00[0x20];
    int nHoradricCubes;
};

struct D2Act2Quest4Strc
{
    char pad0x00[0x40];
    unsigned short nHaremBlockerObjectMode;
    char pad0x42[0x04];
    unsigned char bIsHaremBlockerNeutral;
};

struct D2Act2Quest5Strc
{
    char pad0x00[0x04];
    D2ActiveRoomStrc* pRoom;
};

struct D2Act2Quest6Strc
{
    char pad0x00[0x40];
    D2UnitStrc* pTyrael;
    unsigned char bCloseToTyrael;
};

struct D2GSPacketSrv53
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short unk0x02;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned char unk0x08;
    unsigned char unk0x09;
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

enum D2QuestConstants
{
    QUEST_A1Q1_DENOFEVIL = 1,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q5_SUMMONER = 12,
    QUEST_A2Q6_DURIEL = 13,
    QUESTSTATEFLAG_A1Q1 = 1,
    QUESTSTATEFLAG_A2Q0 = 8,
    QUESTSTATEFLAG_A2Q1 = 9,
    QUESTSTATEFLAG_A2Q3 = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QUESTSTATEFLAG_A2Q5 = 13,
    QUESTSTATEFLAG_A2Q6 = 14,
    QUESTSTATEFLAG_A2Q7 = 30,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_CUSTOM3 = 7,
    QFLAG_CUSTOM4 = 8,
    QFLAG_PRIMARYGOALDONE = 13,
    OBJMODE_OPENED = 2,
    ACT_II = 1,
    MONSTER_WARRIV2 = 175,
    MONSTER_ATMA = 176,
    MONSTER_DROGNAN = 177,
    MONSTER_FARA = 178,
    MONSTER_GREIZ = 198,
    MONSTER_ELZIX = 199,
    MONSTER_GEGLASH = 200,
    MONSTER_JERHYN = 201,
    MONSTER_LYSANDER = 202,
    MONSTER_MESHIF1 = 210,
    MONSTER_CAIN2 = 244,
    MONSTER_NAVI = 266,
    MONSTER_ACT2GUARD2 = 331,
    MONSTER_ACT2GUARD4 = 377,
    MONSTER_ACT2GUARD5 = 378,
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket);            // 0x0053C900
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00594360
int __fastcall ACT1Q4_GetCainPortalInTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (pQuestData && pQuestData->bNotIntro)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainPortalInTownSpawned && !pQuestDataEx->bChangePortalInTownToSpecialMode)
        {
            pCoord->nX = pQuestDataEx->pCainPortalInTownCoords.nX;
            pCoord->nY = pQuestDataEx->pCainPortalInTownCoords.nY;
            return 1;
        }
    }

    return 0;
}

// 0x005946D0
void __fastcall sub_005946D0_SetA1Q4Unk0xB0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->nUnk0xB0 = nValue;
    }
}

// 0x00596BC0
bool __fastcall ACT1Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId != MONSTER_NAVI || !QUESTS_GetQuestData(pQuest->pGame, QUEST_A1Q1_DENOFEVIL)->bNotIntro || QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        return false;
    }

    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE)
        && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING))
    {
        return true;
    }

    return false;
}

// 0x005985B0
bool __fastcall sub_005985B0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x00598780
bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_JERHYN && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q0, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    return false;
}

// 0x0059A170
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 357);
    if (CLIENTS_GetActNo(pClient) == ACT_II)
    {
        D2GSPacketSrv53 packet53;
        packet53.nHeader = 0x53;
        *(int*)&packet53.unk0x01 = 2;
        *(int*)&packet53.unk0x05 = 0;
        packet53.unk0x09 = 0;
        D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);
    }

    return 0;
}

// 0x0059A1C0
bool __fastcall ACT2Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDGRANTED) == 1)
    {
        return false;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->nQuestFilter, QFLAG_REWARDPENDING) == 1)
    {
        if (nNpcId == MONSTER_ATMA || nNpcId == MONSTER_WARRIV2 || nNpcId == MONSTER_GREIZ || nNpcId == MONSTER_ELZIX
            || nNpcId == MONSTER_DROGNAN || nNpcId == MONSTER_LYSANDER || nNpcId == MONSTER_CAIN2 || nNpcId == MONSTER_MESHIF1
            || nNpcId == MONSTER_GEGLASH || nNpcId == MONSTER_JERHYN)
        {
            return true;
        }
    }

    if (nNpcId == MONSTER_DROGNAN && pQuest->fState == 1)
    {
        return true;
    }

    return false;
}

// 0x0059BB40
bool __fastcall ACT2Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if ((nNpcId == MONSTER_ATMA || nNpcId == MONSTER_WARRIV2 || nNpcId == MONSTER_ELZIX || nNpcId == MONSTER_DROGNAN
        || nNpcId == MONSTER_LYSANDER || nNpcId == MONSTER_CAIN2 || nNpcId == MONSTER_MESHIF1 || nNpcId == MONSTER_JERHYN
        || nNpcId == MONSTER_GEGLASH || nNpcId == MONSTER_FARA)
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING) == 1)
    {
        return true;
    }

    return false;
}

// 0x0059BE70
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q5_SUMMONER);
    D2_ASSERT(pQuestData, 269);

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 284);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING) && bInRange)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING);
    }

    return 0;
}

// 0x0059DF30
void __fastcall ACT2Q6_UnitIterate_CheckDistanceToTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pData;
    if (sub_006416D0_UnitEdgeDistance(pUnit, pQuestDataEx->pTyrael) < 12)
    {
        pQuestDataEx->bCloseToTyrael = 1;
    }
}

// 0x0059E4B0
bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_ACT2GUARD5)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A2Q6_DURIEL);
        if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 2
            && QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE)
            && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}
