typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define NUM_ACTS 5
#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_LUTGHOLEIN 40
#define LEVEL_KURASTDOCKTOWN 75
#define LEVEL_THEPANDEMONIUMFORTRESS 103
#define ACT_I 0
#define ACT_II 1
#define ACT_III 2
#define ACT_IV 3
#define PLRMODE_WALK 2
#define PLRMODE_RUN 3
#define EVENTTYPE_REMOVESTATE 12
#define STATE_POISON 2
#define QUESTSTATEFLAG_A2Q6 14
#define QUESTSTATEFLAG_A5Q3 37
#define QUESTSTATEFLAG_A5Q4 38
#define QUEST_A5Q4_NIHLATHAK 34
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_CUSTOM2 6
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_CUSTOM5 9
#define QFLAG_CUSTOM6 10
#define QFLAG_CUSTOM7 11
#define QFLAG_PRIMARYGOALDONE 13
#define QFLAG_COMPLETEDNOW 14
#define MONSTER_WARRIV2 175
#define MONSTER_ATMA 176
#define MONSTER_DROGNAN 177
#define MONSTER_FARA 178
#define MONSTER_JERHYN 201
#define MONSTER_LYSANDER 202
#define MONSTER_MESHIF1 210
#define MONSTER_CAIN2 244
#define MONSTER_TYRAEL1 251
#define CLIENTSAVEFLAG_HARDCORE 0x4
#define CLIENTSAVEFLAG_DEAD 0x8
#define CLIENTSAVEFLAG_EXPANSION 0x20
#define CLIENTSAVEFLAG_LADDER 0x40
#define GAMEFLAG_ARENA_HARDCORE 0x800

struct D2DrlgActStrc;
struct D2StatListStrc;
struct D2BitBufferStrc;
struct D2AnimSeqTxt;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2LargeIntegerStrc
{
    __int64 QuadPart;
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2SaveHeaderStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    unsigned int dwChecksum;
    char unk0x10[0x20];
    unsigned int dwLasTime;
    unsigned int dwPlayTime;
    char unk0x38[0x73];
    unsigned char dwMapSeed[4];
};

struct D2PlayerDataStrc
{
    char szName[16];
    D2BitBufferStrc* pQuestData[3];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0x50];
    int dwInteractGUID;
    int dwInteractType;
    unsigned char nInteract;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x7C];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2DrlgActStrc
{
    char unk0x00[0x58];
    int bHasPendingRoomDeletions;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    unsigned char nArenaTemplate;
    unsigned char nMaxLevelDifference;
    unsigned char nDifficulty;
    unsigned char nMaxPlayers;
    unsigned char unk0x6F;
    int bExpansion;
    unsigned int dwGameType;
    char unk0x78[0x30];
    int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1050];
    D2UnitStrc* pUnitList[5][128];
};

struct D2ClientStrc
{
    char unk0x000[0x0D];
    char szName[16];
    char unk0x01D[0x173];
    D2FileTimeStrc nSaveCreationTimestamp;
    char unk0x198[0x318];
    D2ClientStrc* pServerNextByName;
};

struct D2UnitProxyArgStrc
{
    int nLevelId;
    int nCounter;
};

struct D2UnitFindArgStrc
{
    int nFlags;
    int unk0x04;
    D2UnitStrc* pUnit;
    int nX;
    int nY;
    int nSize;
    int nMaxArrayEntries;
    int nIndex;
    void* pField;
    void* pfnUnitTest;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    int unk0x04[10];
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
};

struct D2Act2Quest6Strc
{
    unsigned char unk0x00;
    unsigned char bDurielKilled;
    unsigned char unk0x02[0x0D];
    unsigned char bPortalToLutGholeinOpened;
};

struct D2Act5Quest4Strc
{
    char unk0x00[0x8C];
    D2ActiveRoomStrc* pRoom;
};

struct D2StatesTxt
{
    char unk0x00[0x1E];
    short wGroup;
    char unk0x20[0x1C];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAC];
    short* pCurseStates;
    short nCurseStates;
};

struct D2ServerCallbackFunctions
{
    void* pfCallbacks[21];
    void (__fastcall* pfGetTime)(D2FileTimeStrc* pTime);
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2CriticalSectionStrc gSrvClientListByNameLock_6FD443B8;                                             // 0x008846C0
extern D2ClientStrc* gpClientListByName_6FD443D0[256];                                                      // 0x00883EA8
extern int gbHasHighResolutionClock;                                                                        // 0x0088C7A0
extern D2LargeIntegerStrc gPerformanceFrequency;                                                            // 0x0088C790
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
extern int gbD2ServerCallbackFunctionsInitialized_6FD45834;                                                 // 0x00883D54

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount);        // 0x006CC25C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                              // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall CompareFileTime(const D2FileTimeStrc* pFileTime1, const D2FileTimeStrc* pFileTime2); // 0x006CC390
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0

int __fastcall CRC32_Compute(const void* pData, int nSize);                                                 // 0x006C99F6
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString);                                      // 0x004112C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
void __stdcall SStrCopy(char* szDest, const char* szSource, int nMax);                                      // 0x004135D0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                    // 0x0061A180
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom);                                             // 0x0061A2C0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __stdcall DUNGEON_RemoveClientFromRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient);                // 0x0061A700
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);      // 0x005538D0
void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);          // 0x00536820
void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bStale);        // 0x00537230
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData);          // 0x0065AC70
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame);                                                  // 0x0053FD40
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState);                                            // 0x0063A460
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList);                                                    // 0x00626090
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x00531E30
int __fastcall D2GAME_SAVE_CalculateChecksum_6FC8A140(D2SaveHeaderStrc* pSaveHeader, int nSize)
{
    int nCheckSum = 0;
    int nLastTime = 0;
    int nPlayTime = 0;
    int nMapSeed = 0;
    const unsigned int nVersion = pSaveHeader->dwVersion;
    if (nVersion > 91)
    {
        nCheckSum = pSaveHeader->dwChecksum;
        nLastTime = pSaveHeader->dwLasTime;
        nPlayTime = pSaveHeader->dwPlayTime;
        nMapSeed = *(int*)pSaveHeader->dwMapSeed;

        pSaveHeader->dwChecksum = 0;
        pSaveHeader->dwLasTime = 0;
        pSaveHeader->dwPlayTime = 0;
        *(int*)pSaveHeader->dwMapSeed = 0;
    }

    const int result = CRC32_Compute(pSaveHeader, nSize);

    if (nVersion > 91)
    {
        pSaveHeader->dwChecksum = nCheckSum;
        pSaveHeader->dwLasTime = nLastTime;
        pSaveHeader->dwPlayTime = nPlayTime;
        *(int*)pSaveHeader->dwMapSeed = nMapSeed;
    }

    return result;
}

// 0x00537580
void __fastcall SUNITPROXY_OnClientRemovedFromGame(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pGame->nGameType == 3)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    unsigned char nAct = 0;

    D2UnitProxyArgStrc unitProxyArg;
    unitProxyArg.nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    unitProxyArg.nCounter = 0;

    switch (unitProxyArg.nLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        nAct = ACT_I;
        break;

    case LEVEL_LUTGHOLEIN:
        nAct = ACT_II;
        break;

    case LEVEL_KURASTDOCKTOWN:
        nAct = ACT_III;
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        nAct = ACT_IV;
        break;

    default:
        return;
    }

    SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
    --unitProxyArg.nCounter;
    SUNITPROXY_UpdateVendorInventory(pGame, nAct, unitProxyArg.nCounter == 0);
}

// 0x00538C60
int __fastcall sub_6FC33F90(const char* szName, char* szGameName)
{
    int result = 1;
    const int nIndex = FOG_ComputeStringCRC16(szName) & 0xFF;
    EnterCriticalSection(&gSrvClientListByNameLock_6FD443B8);

    for (D2ClientStrc* pClient = gpClientListByName_6FD443D0[nIndex]; pClient; pClient = pClient->pServerNextByName)
    {
        if (!SStrCmpI(pClient->szName, szName, sizeof(pClient->szName)))
        {
            if (szGameName)
            {
                SStrCopy(szGameName, pClient->szName, sizeof(pClient->szName));
            }

            result = 0;
            break;
        }
    }

    LeaveCriticalSection(&gSrvClientListByNameLock_6FD443B8);
    return result;
}

// 0x0053A820
void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame)
{
    for (int i = 0; i < NUM_ACTS; ++i)
    {
        D2DrlgActStrc* pAct = pGame->pAct[i];
        if (pAct && pAct->bHasPendingRoomDeletions)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
            {
                DUNGEON_FreeDrlgDelete(pRoom);
            }

            pAct->bHasPendingRoomDeletions = 0;
        }
    }
}

// 0x0053AB80
void __fastcall LEVEL_RemoveClientFromAdjacentRooms(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 334);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        DUNGEON_RemoveClientFromRoom(ppRoomList[i], pClient);
    }
}

// 0x0054C990
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x54_TurnStaminaOff_6FC88380(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_RUN)
    {
        UNITS_ChangeAnimMode(pUnit, PLRMODE_WALK);
    }

    return 0;
}

// 0x00554120
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID)
{
    if (pUnit->nInteract)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
            if (pPlayerData)
            {
                char szMessage[80];
                sprintf(szMessage, "Player %s attempted to operate while busy\n", pPlayerData->szName);
            }
        }
    }
    else
    {
        pUnit->dwInteractGUID = nInteractUnitGUID;
        pUnit->dwInteractType = nInteractUnitType;
        pUnit->nInteract = 1;
    }
}

// 0x00564340
int __fastcall TASK_GetClockTime()
{
    if (gbHasHighResolutionClock)
    {
        D2LargeIntegerStrc nQPC;
        QueryPerformanceCounter(&nQPC);
        return 1000 * nQPC.QuadPart / gPerformanceFrequency.QuadPart;
    }

    return GetTickCount();
}

// 0x0056C210
D2UnitFindDataStrc* __fastcall sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY)
{
    D2UnitFindDataStrc* pUnitFindData = (D2UnitFindDataStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2UnitFindDataStrc), ".\\SKILLS\\Skills.cpp", 1099, 0);

    D2UnitFindArgStrc unitFindArg = {};
    unitFindArg.nFlags = 0x583;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nX = nX;
    unitFindArg.nY = nY;
    unitFindArg.nSize = nSize;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, pUnitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(pUnitFindData);

    return pUnitFindData;
}

// 0x00569D80
int __fastcall sub_00569D80(D2GameStrc* pGame, unsigned short nFlags, D2ClientStrc* pClient)
{
    if (nFlags & CLIENTSAVEFLAG_EXPANSION)
    {
        if (!pGame->bExpansion)
        {
            return 8;
        }
    }
    else
    {
        if (pGame->bExpansion)
        {
            return 9;
        }
    }

    if (gbD2ServerCallbackFunctionsInitialized_6FD45834)
    {
        D2FileTimeStrc tNow;
        gpD2EventCallbackTable_6FD45830->pfGetTime(&tNow);
        if ((nFlags & CLIENTSAVEFLAG_LADDER) && CompareFileTime(&pClient->nSaveCreationTimestamp, &tNow) > 0)
        {
            if (!pGame->dwGameType)
            {
                return 25;
            }
        }
        else
        {
            if (pGame->dwGameType)
            {
                return 26;
            }
        }
    }

    if (nFlags & CLIENTSAVEFLAG_HARDCORE)
    {
        if (nFlags & CLIENTSAVEFLAG_DEAD)
        {
            return 10;
        }

        if (!(ARENA_GetFlags(pGame) & GAMEFLAG_ARENA_HARDCORE))
        {
            return 11;
        }
    }
    else
    {
        if (ARENA_GetFlags(pGame) & GAMEFLAG_ARENA_HARDCORE)
        {
            return 12;
        }
    }

    const int nProgression = (nFlags >> 8) & 0x1F;
    if (pGame->nDifficulty > 1)
    {
        if (((nFlags & CLIENTSAVEFLAG_EXPANSION) && nProgression < 10) || nProgression < 8)
        {
            return 14;
        }
    }
    else if (pGame->nDifficulty > 0)
    {
        if (((nFlags & CLIENTSAVEFLAG_EXPANSION) && nProgression < 5) || nProgression < 4)
        {
            return 13;
        }
    }

    return 0;
}

// 0x00573640
void __fastcall MONSTER_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pMonster = pGame->pUnitList[1][i];
        while (pMonster)
        {
            D2UnitStrc* pNext = SUNIT_GetNextUnitFromList(pMonster);
            pGame->pUnitList[1][i] = pNext;
            SUNIT_RemoveUnit(pGame, pMonster);
            pMonster = pNext;
        }
    }
}

// 0x0058B4A0
int __fastcall ACT5Q4_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDNOW) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK)->pQuestDataEx;

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
    if (!bFound)
    {
        return 0;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE);
    return 0;
}

// 0x0059D300
bool __fastcall ACT2Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_JERHYN)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED) == 1)
        {
            return false;
        }

        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_LEAVETOWN) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_ENTERAREA))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_LEAVETOWN) == 1)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_MESHIF1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_ENTERAREA) == 1)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_TYRAEL1)
    {
        D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuest->pQuestDataEx;
        if (pQuest->bNotIntro != 1 || pQuestDataEx->bDurielKilled != 1)
        {
            return false;
        }

        if (pQuestDataEx->bPortalToLutGholeinOpened == 0)
        {
            return true;
        }
    }
    else
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_PRIMARYGOALDONE))
        {
            return false;
        }

        if (nNpcId == MONSTER_ATMA)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM2))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_WARRIV2)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM3))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_DROGNAN)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM4))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_LYSANDER)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM5))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_CAIN2)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM6))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_FARA)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM7))
            {
                return true;
            }
        }
    }

    return false;
}

// 0x005CEC90
int __stdcall sub_005CEC90_ShortenPoisonAndCurses(D2GameStrc* pGame, D2UnitStrc* pUnit, int nPercent)
{
    int bPoisonedOrCursed = 0;
    if (STATES_CheckState(pUnit, STATE_POISON))
    {
        D2StatListStrc* pPoisonStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_POISON);
        if (pPoisonStatList)
        {
            const int nFrame = pGame->dwGameFrame;
            const int nRemaining = D2COMMON_10473(pPoisonStatList) - nFrame;
            const int nExpireFrame = DATATBLS_ApplyRatio(nRemaining, nPercent, 100) + nFrame;
            D2COMMON_10476(pPoisonStatList, nExpireFrame);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
            bPoisonedOrCursed = 1;
        }
    }

    for (int i = 0; i < sgptDataTables->nCurseStates; ++i)
    {
        const int nCurseStateId = sgptDataTables->pCurseStates[i];
        if (STATES_CheckState(pUnit, nCurseStateId))
        {
            D2StatListStrc* pCurseStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nCurseStateId);
            if (pCurseStatList)
            {
                if (STATES_CheckStateMaskCurableByStateId(nCurseStateId))
                {
                    const int nFrame = pGame->dwGameFrame;
                    const int nRemaining = D2COMMON_10473(pCurseStatList) - nFrame;
                    const int nExpireFrame = DATATBLS_ApplyRatio(nRemaining, nPercent, 100) + nFrame;
                    D2COMMON_10476(pCurseStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
                }
                bPoisonedOrCursed = 1;
            }
        }
    }

    return bPoisonedOrCursed;
}

static inline D2StatesTxt* STATES_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x005EB7F0
int __fastcall sub_005EB7F0_IsStateGroupActive(D2UnitStrc* pUnit, int nStateId)
{
    D2StatesTxt* pStatesTxtRecord = STATES_GetStatesTxtRecordInline(nStateId);
    if (!pStatesTxtRecord || !pStatesTxtRecord->wGroup)
    {
        return 0;
    }

    int nResult = 0;
    const int nGroup = pStatesTxtRecord->wGroup;
    const int nCount = sgptDataTables->nStatesTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (i != nStateId)
        {
            if (STATES_GetStatesTxtRecordInline(i)->wGroup == nGroup && STATES_CheckState(pUnit, i))
            {
                nResult = 1;
            }
        }
    }

    return nResult;
}
