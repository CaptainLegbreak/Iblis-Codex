struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2TextHeaderStrc;

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

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
        D2TextHeaderStrc* pTextControl;
        unsigned short nNPCNo;
    };
    union
    {
        unsigned short nMessageIndex;
        int nNewLevel;
    };
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
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
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    char pad0xA0[0x40];
    int nQuestFilter;
};

struct D2Act2Quest4Strc
{
    unsigned char unused0x00[4];
    unsigned char bDrognanActivated;
    unsigned char pad0x05[3];
    D2ActiveRoomStrc* pRoom;
    unsigned char bJerhynStartInitialized;
    unsigned char bJerhynPalaceInitialized;
    unsigned char bPalaceOpen;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char bHaremBlockerInitialized;
    unsigned char unk0x12;
    unsigned char unk0x13;
    unsigned char unk0x14;
    unsigned char bJerhynCoordinatesStored;
    unsigned char bPortalToCanyonOpen;
    unsigned char unused0x17;
    char pad0x18[0x20];
    int nHaremBlockerGUID;
    int nJerhynGUID;
    unsigned short nHaremBlockerObjectMode;
    unsigned short nPortalModeInSanctuary;
    unsigned short nPortalModeInCellar;
    unsigned char bIsHaremBlockerNeutral;
    unsigned char pad0x47;
};

enum D2C_M11A2Q4Constants
{
    UNIT_OBJECT = 2,
    OBJMODE_NEUTRAL = 0,
    OBJMODE_OPENED = 2,
    QUEST_A2Q4_HORAZONTOME = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QFLAG_REWARDPENDING = 1,
    QFLAG_CUSTOM3 = 7,
    QFLAG_CUSTOM4 = 8,
    QFLAG_PRIMARYGOALDONE = 13,
    MONSTER_DROGNAN = 177,
    MONSTER_JERHYN = 201,
    MONSTER_ACT2GUARD2 = 331,
    LEVEL_CANYONOFTHEMAGI = 46,
    OBJECT_PERMANENT_TOWN_PORTAL = 60,
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                          // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);             // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C360
void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);          // 0x0065C3A0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                            // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                   // 0x00623830
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                 // 0x00543640
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);    // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);     // 0x00545780
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID);                               // 0x00545200
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                      // 0x00620870
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544720
int __fastcall ACT2Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);         // 0x0059AD50
int __fastcall ACT2Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x0059ADB0

// 0x0059AEF0
static void sub_0059AEF0_ACT2Q4_OpenPalace(D2QuestDataStrc* pQuestData, D2Act2Quest4Strc* pQuestDataEx)
{
    pQuestDataEx->bPalaceOpen = 1;
    if (pQuestDataEx->nHaremBlockerObjectMode == OBJMODE_NEUTRAL)
    {
        pQuestDataEx->bIsHaremBlockerNeutral = 1;
    }
    pQuestDataEx->nHaremBlockerObjectMode = OBJMODE_OPENED;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);

    if (pQuestDataEx->bHaremBlockerInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pHaremBlocker = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nHaremBlockerGUID);
    if (!pHaremBlocker)
    {
        return;
    }

    UNITS_ChangeAnimMode(pHaremBlocker, OBJMODE_OPENED);
    UNITS_FreeCollisionPath(pHaremBlocker);
}

// 0x0059AF50
void __fastcall ACT2Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == MONSTER_ACT2GUARD2)
    {
        switch (nMessageIndex)
        {
        case 186:
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3);
            break;

        case 187:
        case 188:
        case 189:
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4);
            break;
        }
    }
    else
    {
        if (nMessageIndex == 406 || nMessageIndex == 403 || nMessageIndex == 397 || nMessageIndex == 400 || nMessageIndex == 398 || nMessageIndex == 399
            || nMessageIndex == 405 || nMessageIndex == 407 || nMessageIndex == 402 || nMessageIndex == 401 || nMessageIndex == 404)
        {
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING))
            {
                QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING);
                QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            }
        }

        if (nMessageIndex == 396)
        {
            if (pQuestData->bNotIntro && pQuestData->fLastState < 5)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 5, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 0);
            }

            if (!pQuestDataEx->bPortalToCanyonOpen && UNITS_GetRoom(pQuestArg->pPlayer) == pQuestDataEx->pRoom)
            {
                D2ActiveRoomStrc* pRoom = 0;
                D2CoordStrc pCoord;
                UNITS_GetCoords(pQuestArg->pPlayer, &pCoord);
                QUESTS_GetFreePosition(pQuestDataEx->pRoom, &pCoord, 2, 0xBE11, &pRoom, 8, 100);
                if (pRoom && D2GAME_CreatePortalObject_6FD13DF0(pQuestData->pGame, pQuestArg->pPlayer, pRoom, pCoord.nX, pCoord.nY, LEVEL_CANYONOFTHEMAGI, 0, OBJECT_PERMANENT_TOWN_PORTAL, 0))
                {
                    pQuestDataEx->bPortalToCanyonOpen = 1;
                    QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->nQuestFilter, QFLAG_PRIMARYGOALDONE);
                }
            }
        }

        if (nNPCNo == MONSTER_DROGNAN)
        {
            if (nMessageIndex == 373)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 466);
                pQuestDataEx->bDrognanActivated = 1;
                sub_0059AEF0_ACT2Q4_OpenPalace(pQuestData, pQuestDataEx);
                QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            }
        }
        else if (nNPCNo == MONSTER_JERHYN)
        {
            if (nMessageIndex == 377)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 474);
                QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
            }
        }
    }
}

// 0x0059B660
void __fastcall sub_0059B660_ACT2Q4_OpenPalaceOrCycle(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 959);
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
        }
    }
    else
    {
        sub_0059AEF0_ACT2Q4_OpenPalace(pQuestData, pQuestDataEx);
    }
}
