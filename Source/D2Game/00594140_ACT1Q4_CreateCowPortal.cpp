struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

enum D2C_Q05QuestConstants
{
    LEVEL_ROGUEENCAMPMENT = 1,
    LEVEL_MOOMOOFARM = 39,
    OBJECT_PERMANENT_TOWN_PORTAL = 60,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
    UNIT_PLAYER = 0,
    UNIT_OBJECT = 2,
    OBJECT_PORTAL_TO_DURIELS_LAIR = 100,
    OBJMODE_OPERATING = 1,
    OBJMODE_OPENED = 2,
    EVENTTYPE_ENDANIM = 1,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_PRIMARYGOALDONE = 13,
    QFLAG_CUSTOM6 = 10,
    QFLAG_CUSTOM7 = 11,
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
};

struct D2GameStrc
{
    char pad0x00[0x6D];
    unsigned char nDifficulty;
    char pad0x6E[0x02];
    int bExpansion;
    char pad0x74[0x34];
    int dwGameFrame;
};

struct D2ObjectsTxt
{
    char pad0x00[0xD8];
    unsigned int dwFrameCnt[8];
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
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    unsigned char bDurielKilled;
    unsigned char unk0x02;
    unsigned char bTimerActive;
    unsigned char bHoradricOrificeInitialized;
    unsigned char bTyraelsDoorInitialized;
    unsigned char bUnusedObjectInitialized;
    unsigned char unused0x07;
    unsigned char bInitJerhynActivated;
    unsigned char bTyraelActivated;
    unsigned char bEndJerhynActivated;
    unsigned char bDurielLairTombOpen;
    unsigned char bDurielLairPortalNeedsToOpen;
    unsigned char bObjectsNeedUpdate;
    unsigned char unk0x0E[0x12];
    int nHoradricOrificeGUID;
    unsigned char unused0x24[4];
    int nUnusedObjectGUID;
};

struct D2PlayerDataStrc
{
    char pad0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C360
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                          // 0x00544760
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned int fCollision, D2ActiveRoomStrc** ppRoom, int nRadius, int a7); // 0x00545340
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                              // 0x0061AED0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin);                    // 0x00553380

__forceinline D2BitBufferStrc* QUESTS_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00594140
int __fastcall ACT1Q4_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom;
    if (QUESTS_GetGlobalState(pGame, QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM7)
        || QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6))
    {
        goto fail;
    }

    if (!((!pGame->bExpansion && QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A4Q2, QFLAG_REWARDGRANTED))
        || (pGame->bExpansion && QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))))
    {
        goto fail;
    }

    pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROGUEENCAMPMENT)
    {
fail:
        SUNIT_AttachSound(pUnit, 20, pUnit);
        return 0;
    }

    D2CoordStrc pCoord;
    D2ActiveRoomStrc* pFreeRoom = 0;
    UNITS_GetCoords(pUnit, &pCoord);
    QUESTS_GetFreePosition(pRoom, &pCoord, 3, 0x400, &pFreeRoom, 4, 100);
    if (pFreeRoom && D2GAME_CreatePortalObject_6FD13DF0(pGame, pUnit, pFreeRoom, pCoord.nX, pCoord.nY, LEVEL_MOOMOOFARM, 0, OBJECT_PERMANENT_TOWN_PORTAL, 0))
    {
        QUESTS_SetGlobalState(pGame, QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM7);
        return 1;
    }

    SUNIT_AttachSound(pUnit, 20, pUnit);
    return 0;
}

// 0x00595420
void __fastcall sub_00595420_UpdatePlayerListQuestState(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuestId, int nSoundId)
{
    for (int i = 0; i < pQuestGUID->nPlayerCount; ++i)
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pQuestGUID->nPlayerGUIDs[i]);
        if (pPlayer)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, nQuestId, QFLAG_REWARDGRANTED) != 1)
            {
                QUESTRECORD_SetQuestState(pQuestFlags, nQuestId, QFLAG_PRIMARYGOALDONE);
                QUESTRECORD_SetQuestState(pQuestFlags, nQuestId, QFLAG_REWARDGRANTED);
                if (nSoundId)
                {
                    SUNIT_AttachSound(pPlayer, nSoundId, pPlayer);
                }
            }
        }
    }
}

// 0x0059D870
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    int nObjects = 0;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bObjectsNeedUpdate == 1)
    {
        if (pQuestDataEx->bUnusedObjectInitialized)
        {
            D2UnitStrc* pUnusedObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nUnusedObjectGUID);
            if (pUnusedObject)
            {
                nObjects = 1;
                if (!pUnusedObject->dwAnimMode)
                {
                    if (pQuestDataEx->bDurielLairPortalNeedsToOpen)
                    {
                        UNITS_ChangeAnimMode(pUnusedObject, OBJMODE_OPENED);
                    }
                    else
                    {
                        UNITS_ChangeAnimMode(pUnusedObject, OBJMODE_OPERATING);
                        const int nClassId = pUnusedObject->dwClassId;
                        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
                        EVENT_SetEvent(pQuestData->pGame, pUnusedObject, EVENTTYPE_ENDANIM, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
                    }
                }
            }
        }

        if (pQuestDataEx->bHoradricOrificeInitialized)
        {
            D2UnitStrc* pHoradricOrifice = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nHoradricOrificeGUID);
            if (pHoradricOrifice)
            {
                const int nX = UNITS_GetXPosition(pHoradricOrifice) - 13;
                const int nY = CLIENTS_GetUnitY(pHoradricOrifice) + 3;

                D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pHoradricOrifice), nX, nY);
                if (pRoom)
                {
                    D2UnitStrc* pDurielLairPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_PORTAL_TO_DURIELS_LAIR, nX, nY, pGame, pRoom, 1, 1, 0);
                    if (pDurielLairPortal)
                    {
                        ++nObjects;
                        if (pQuestDataEx->bDurielLairPortalNeedsToOpen)
                        {
                            UNITS_ChangeAnimMode(pDurielLairPortal, OBJMODE_OPENED);
                        }
                        else
                        {
                            UNITS_ChangeAnimMode(pDurielLairPortal, OBJMODE_OPERATING);
                            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pHoradricOrifice), 1);
                            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
                        }
                    }
                }
            }
        }

        if (!nObjects)
        {
            return false;
        }

        pQuestDataEx->bDurielLairTombOpen = 1;
        pQuestDataEx->bObjectsNeedUpdate = 0;
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}
