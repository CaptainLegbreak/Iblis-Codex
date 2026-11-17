struct D2UnitStrc;
struct D2InventoryStrc;
struct D2ClientStrc;
struct D2SaveHeaderStrc;
struct D2SkillStrc;

struct _RTL_CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

struct HASHKEY_NONE
{
    int nUnused;
};

struct D2GameStrc;

struct D2GameDataTableStrc
{
    unsigned int sub_0052E6D0_GenerateHandle();                                                             // 0x0052E6D0
    D2GameStrc* sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags);   // 0x00530820
    D2GameStrc* sub_005308C0_NewHandle(unsigned int* pHandle);
    D2GameStrc* sub_005308F0_NewLock(unsigned int* pHandle, int* pLockedHandle);

    char tHashTable[0x44];
    HASHKEY_NONE f_44;
    unsigned int nSequence;
    int bWrapped;
    _RTL_CRITICAL_SECTION f_50;
};

struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x1C];
    D2UnitStrc* pChangeFirstUnit;
    char unk0x20[0x5C];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xCC];
    D2UnitStrc* pChangeNextUnit;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x4C];
    int bBusy;
};

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int field_4;
    int field_8;
    int field_C;
    D2NpcEventStrc* pNext;
};

struct D2NpcGambleStrc
{
    D2InventoryStrc* pInventory;
    int dwGUID;
    D2NpcGambleStrc* pNext;
};

struct D2NpcRecordStrc
{
    int nNPC;
    D2InventoryStrc* pInventory;
    D2NpcGambleStrc* pGamble;
    int bGambleInit;
    int unk0x10;
    D2NpcEventStrc* pEvent;
    int unk0x18;
    int bTrading;
    unsigned char bVendorInit;
    unsigned char unk0x21;
    unsigned char unk0x22;
    unsigned char bTrader;
    char unk0x24[0x20];
};

struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
};

struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    unsigned int fFlags;
    unsigned char nTemplate;
    unsigned char pad0x0D[3];
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[5];
    int bExpansion;
    char f_74[8];
    unsigned int dwInitSeed;
    unsigned int dwObjSeed;
    char unk0x84[0x24];
    unsigned int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1050];
    D2UnitStrc* pUnitList[5][128];
    char unk0x1B20[0x204];
    D2NpcControlStrc* pNpcControl;
    D2ArenaStrc* pArenaCtrl;
};

struct D2ClientStrc
{
    char unk0x00[0x17C];
    D2SaveHeaderStrc* pSaveHeader;
    unsigned int nSaveHeaderSize;
    char unk0x184[0x24];
    D2GameStrc* pGame;
    char unk0x1AC[8];
    D2ActiveRoomStrc* pRoom;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

struct D2RosterIterateStrc
{
    int bFlag;
    D2UnitStrc* pUnit;
};

struct D2UnitProxyArgStrc
{
    int nLevelId;
    int nCounter;
};

struct D2GSPacketSrv53
{
    unsigned char nHeader;
    unsigned char nCycleIndex;
    unsigned char nCycleIndex1;
    unsigned char nCycleIndex2;
    unsigned char nCycleIndex3;
    unsigned char nTicks;
    unsigned char nTicks1;
    unsigned char nTicks2;
    unsigned char nTicks3;
    unsigned char nEclipse;
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    unsigned char dwPlayerGUID1;
    unsigned char dwPlayerGUID1_1;
    unsigned char dwPlayerGUID1_2;
    unsigned char dwPlayerGUID1_3;
    unsigned char dwPlayerGUID2;
    unsigned char dwPlayerGUID2_1;
    unsigned char dwPlayerGUID2_2;
    unsigned char dwPlayerGUID2_3;
    unsigned char nFlags;
    unsigned char nFlags1;
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char dwPlayerGUID;
    unsigned char dwPlayerGUID1;
    unsigned char dwPlayerGUID2;
    unsigned char dwPlayerGUID3;
    unsigned char dwCorpseGUID;
    unsigned char dwCorpseGUID1;
    unsigned char dwCorpseGUID2;
    unsigned char dwCorpseGUID3;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnVirtualPlayerCount_6FD4DC1C;                                                                   // 0x00883D70

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall sub_0056DEB0(int a1, int a2, int a3, int a4);                                               // 0x0056DEB0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);                                        // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);      // 0x005538D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags);       // 0x0055B300
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x00571600
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct);                                           // 0x0061AE80
void __fastcall D2GAME_PACKETS_SendPacket0x03_6FC3C810(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId); // 0x0053B390
void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse); // 0x0061C330
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket);            // 0x0053C900
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                    // 0x0061A180
void __fastcall sub_00553220(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00553220
void __stdcall sub_0064C160(D2ActiveRoomStrc* pRoom);                                                       // 0x0064C160
void __fastcall sub_0053FAE0(D2GameStrc* pGame);                                                            // 0x0053FAE0
void __fastcall sub_0053DDF0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket);                        // 0x0053DDF0
void __fastcall sub_0053DF50(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket);                        // 0x0053DF50
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame);  // 0x00548B00
void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID); // 0x00578460
void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId);  // 0x00579C00
void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit);                                                   // 0x005350B0
void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId);              // 0x005724C0

#define UNIT_PLAYER 0
#define PLRMODE_DEATH 0
#define PLRMODE_NEUTRAL 1
#define PLRMODE_DEAD 17
#define EVENTTYPE_STATREGEN 3
#define EVENTTYPE_DELAYEDPORTAL 11
#define MAX_NPC_RECORDS 64

// 0x005308C0
D2GameStrc* D2GameDataTableStrc::sub_005308C0_NewHandle(unsigned int* pHandle)
{
    const unsigned int nHandle = sub_0052E6D0_GenerateHandle();
    *pHandle = nHandle;
    return sub_00530820_New(nHandle, &f_44, 0, 0);
}

// 0x005308F0
D2GameStrc* D2GameDataTableStrc::sub_005308F0_NewLock(unsigned int* pHandle, int* pLockedHandle)
{
    EnterCriticalSection(&f_50);
    *pLockedHandle = 1;
    const unsigned int nHandle = sub_0052E6D0_GenerateHandle();
    *pHandle = nHandle;
    return sub_00530820_New(nHandle, &f_44, 0, 0);
}

// 0x00531D60
void __fastcall sub_00531D60_ByteToHex(char* szOut, unsigned char nByte)
{
    char szHex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    szOut[0] = szHex[nByte >> 4];
    szOut[1] = szHex[nByte & 0xF];
}

// 0x00531DE0
char* __fastcall sub_00531DE0_BytesToHexString(char* szOut, const unsigned char* pData, int nLength)
{
    if (nLength <= 0)
    {
        return 0;
    }

    *szOut = '0';
    ++szOut;
    *szOut = 'x';
    ++szOut;
    do
    {
        sub_00531D60_ByteToHex(szOut, *pData);
        szOut += 2;
        ++pData;
        --nLength;
    }
    while (nLength);

    *szOut = 0;
    return szOut;
}

// 0x00532E70
void __stdcall sub_00532E70_ForwardIfSet(int a1, int a2, unsigned char a3)
{
    if (a3)
    {
        sub_0056DEB0(a1, a2, a3, 1);
    }
}

// 0x00534A50
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pPlayer = pGame->pUnitList[UNIT_PLAYER][i];
        while (pPlayer)
        {
            D2UnitStrc* pCurrent = pPlayer;
            pPlayer = SUNIT_GetNextUnitFromList(pPlayer);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x00534AB0
void __fastcall sub_00534AB0_ClearTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget == SUNIT_GetTargetUnit(pGame, pUnit))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
}

// 0x00534AD0
void __fastcall sub_00534AD0_ResetModeAndEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    sub_6FC817D0(pGame, pUnit, 0, PLRMODE_NEUTRAL, nX, nY, 1);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_DELAYEDPORTAL, pGame->dwGameFrame + 250, 0, 0);
}

// 0x005356B0
int __fastcall sub_005356B0_SetSkillHotKey(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, unsigned char nHand, int nFlags)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\Player.cpp", 755);
    if (!pClient)
    {
        return 0;
    }

    CLIENTS_SetSkillHotKey(pClient, nHotkeyId, nSkillId, nHand, nFlags);
    return 1;
}

// 0x005356F0
void __fastcall sub_005356F0_CountPlayersInLevelCb(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2UnitProxyArgStrc* pCount = (D2UnitProxyArgStrc*)pArg;
    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == pCount->nLevelId && pUnit && pUnit->dwAnimMode != PLRMODE_DEATH && pUnit->dwAnimMode != PLRMODE_DEAD)
    {
        ++pCount->nCounter;
    }
}

// 0x00535730
int __fastcall sub_00535730_CountPlayersInLevel(D2GameStrc* pGame, int nLevelId)
{
    D2UnitProxyArgStrc arg = {};
    arg.nLevelId = nLevelId;
    SUNIT_IterateLivingPlayers(pGame, sub_005356F0_CountPlayersInLevelCb, &arg);
    return arg.nCounter;
}

// 0x00535760
void __fastcall PLAYER_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingPlayers)
{
    if (!SUNIT_IsDead(pUnit))
    {
        ++*((int*)pLivingPlayers);
    }
}

// 0x00535790
int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame)
{
    int nLivingPlayers = 0;
    SUNIT_IterateLivingPlayers(pGame, PLAYER_CountLivingPlayers, &nLivingPlayers);

    switch (pGame->nGameType)
    {
    case 1:
    case 2:
    case 3:
        if (gnVirtualPlayerCount_6FD4DC1C > nLivingPlayers)
        {
            return gnVirtualPlayerCount_6FD4DC1C;
        }
        break;
    }

    return nLivingPlayers;
}

// 0x00535AF0
void __fastcall sub_00535AF0_RosterFlagCb(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2RosterIterateStrc* pRosterIterate = (D2RosterIterateStrc*)pArgs;
    if (PLAYERLIST_CheckFlag(pRosterIterate->pUnit, pUnit, 8))
    {
        pRosterIterate->bFlag = 1;
    }
}

// 0x00535B50
void __fastcall sub_00535B50_RosterFlagCb2(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2RosterIterateStrc* pRosterIterate = (D2RosterIterateStrc*)pArgs;
    if (PLAYERLIST_CheckFlag(pUnit, pRosterIterate->pUnit, 8))
    {
        pRosterIterate->bFlag = 1;
    }
}

// 0x00535B80
int __fastcall sub_00535B80_IteratePlayersRoster(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2RosterIterateStrc rosterIterate = {};
    rosterIterate.bFlag = 0;
    rosterIterate.pUnit = pUnit;
    SUNIT_IterateLivingPlayers(pGame, sub_00535B50_RosterFlagCb2, &rosterIterate);
    return rosterIterate.bFlag;
}

// 0x00535EA0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex)
{
    D2NpcRecordStrc* pRecords = pGame->pNpcControl->pFirstRecord;
    for (*pIndex = 0; *pIndex < MAX_NPC_RECORDS; ++*pIndex)
    {
        if (pRecords[*pIndex].nNPC == nNpcClassId)
        {
            return &pRecords[*pIndex];
        }
    }

    D2_ASSERT(nNpcClassId, 114);
    return 0;
}

// 0x00535F10
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex)
{
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, pIndex);
}

// 0x00535F30
void __fastcall SUNITPROXY_AllocNpcEvent(D2UnitStrc* pNpc, D2GameStrc* pGame, D2UnitStrc* pPlayer, int a4)
{
    int nUnused;
    D2NpcEventStrc* pNpcEvent = (D2NpcEventStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcEventStrc), ".\\UNIT\\sunitproxy.cpp", 133, 0);
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nUnused);
    if (pNpcRecord)
    {
        pNpcEvent->pNext = pNpcRecord->pEvent;
        pNpcRecord->pEvent = pNpcEvent;
        pNpcEvent->field_C = 1;
        pNpcEvent->pUnit = pPlayer;
        pNpcEvent->field_8 = a4;
    }
    else
    {
        ITEMS_RemoveFromAllPlayers(pGame, pPlayer);
    }
}

// 0x00536820
void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2UnitProxyArgStrc* pUnitProxyArg = (D2UnitProxyArgStrc*)pArg;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && pUnitProxyArg->nLevelId == DUNGEON_GetLevelIdFromRoom(pRoom))
    {
        ++pUnitProxyArg->nCounter;
    }
}

// 0x00536850
void __fastcall SUNITPROXY_InitializeNpcEventChain(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit)
{
    int i = 0;
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecord = pNpcControl->pFirstRecord;
    GetTickCount();
    for (; i < pNpcControl->nArraySize; ++i)
    {
        if (pRecord->bTrader == 1 && pRecord->bVendorInit == 1 && pRecord->bTrading == 1)
        {
            D2NpcEventStrc* pEvent = (D2NpcEventStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcEventStrc), ".\\UNIT\\sunitproxy.cpp", 611, 0);
            pEvent->pNext = pRecord->pEvent;
            pEvent->field_C = 0;
            pEvent->pUnit = pUnit;
            pEvent->field_8 = 1;
            pEvent->field_4 = 4;
            pRecord->pEvent = pEvent;
        }
        ++pRecord;
    }
}

// 0x00536B20
D2InventoryStrc* __fastcall SUNITPROXY_GetNpcInventory(D2GameStrc* pGame, int nNpc)
{
    int nUnused;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, nNpc, &nUnused)->pInventory;
}

// 0x00536C50
D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nUnused);
    if (!pNpcRecord || !pNpcRecord->bGambleInit)
    {
        return 0;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
    {
        if (pGamble->dwGUID == nPlayerGUID)
        {
            return pGamble->pInventory;
        }
    }

    return 0;
}

// 0x005384E0
void __fastcall sub_005384E0_RemoveUnitIfNotAdjacent(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pClient, 2131);

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pClientRoom = pClient->pRoom;
    D2_ASSERT(pClientRoom, 2137);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

    unsigned int i = 0;
    for (; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 2142);
        if (pUnitRoom == pRoom)
        {
            break;
        }
    }

    if (i >= nNumRooms)
    {
        sub_00571600(pUnit, pClient);
    }
}

// 0x00538E60
void __fastcall CLIENTS_CopySaveDataToClient(D2ClientStrc* pClient, const void* pData, unsigned int nSize)
{
    D2_ASSERT(pClient, 2921);

    if (pClient->nSaveHeaderSize != nSize || pClient->pSaveHeader)
    {
        if (pClient->pSaveHeader)
        {
            FOG_FreeServerMemory(pClient->pGame->pMemoryPool, pClient->pSaveHeader, ".\\GAME\\Clients.cpp", 2926, 0);
        }

        pClient->pSaveHeader = (D2SaveHeaderStrc*)sub_0040B430(pClient->pGame->pMemoryPool, nSize, ".\\GAME\\Clients.cpp", 2928, 0);
        pClient->nSaveHeaderSize = nSize;
    }

    memcpy(pClient->pSaveHeader, pData, nSize);
}

// 0x0053ABE0
void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    D2GAME_PACKETS_SendPacket0x03_6FC3C810(pClient, 3, nAct, pGame->dwInitSeed, pGame->dwObjSeed, DUNGEON_GetTownLevelIdFromAct(pGame->pAct[nAct]));

    int nCycleIndex;
    int nTicks;
    int nEclipse;
    ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(pGame->pAct[nAct], &nCycleIndex, &nTicks, &nEclipse);

    D2GSPacketSrv53 packet53;
    packet53.nHeader = 0x53;
    *(int*)&packet53.nCycleIndex = nCycleIndex;
    *(int*)&packet53.nTicks = nTicks;
    packet53.nEclipse = nEclipse;
    D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);
}

// 0x0053B000
void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        D2DrlgActStrc* pAct = pGame->pAct[i];
        if (pAct && pAct->bHasPendingUnitListUpdates)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
            {
                for (D2UnitStrc* pUnit = pRoom->pChangeFirstUnit; pUnit; pUnit = pUnit->pChangeNextUnit)
                {
                    sub_00553220(pGame, pUnit);
                }

                sub_0064C160(pRoom);
            }

            pGame->pAct[i]->bHasPendingUnitListUpdates = 0;
        }
    }

    sub_0053FAE0(pGame);
}

// 0x0053DE20
void __fastcall sub_0053DE20_SendPacket0x8CToAllPlayers(D2GameStrc* pGame, int dwPlayerId1, int dwPlayerId2, short wRelationState)
{
    D2GSPacketSrv8C packet8C;
    packet8C.nHeader = 0x8C;
    *(int*)&packet8C.dwPlayerGUID1 = dwPlayerId1;
    *(int*)&packet8C.dwPlayerGUID2 = dwPlayerId2;
    *(short*)&packet8C.nFlags = wRelationState;
    SUNIT_IterateLivingPlayers(pGame, sub_0053DDF0, &packet8C);
}

// 0x0053DF80
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;
    packet8E.nHeader = 0x8E;
    *(int*)&packet8E.dwPlayerGUID = nUnitId;
    *(int*)&packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;
    SUNIT_IterateLivingPlayers(pGame, sub_0053DF50, &packet8E);
}

// 0x0053F4B0
void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int nUnused, unsigned int nFlags, unsigned char nTemplate)
{
    D2ArenaStrc* pArena = (D2ArenaStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ArenaStrc), ".\\GAME\\Arena.cpp", 50, 0);
    memset(pArena, 0, sizeof(D2ArenaStrc));
    pGame->pArenaCtrl = pArena;
    pArena->fFlags = nFlags & 0x3179C7;
    pArena->nTemplate = nTemplate;
}

// 0x005404F0
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits)
{
    if (pUnit && !SUNIT_IsDead(pUnit))
    {
        ++*((int*)pLivingUnits);
    }
}

// 0x00549FA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0B_6FC83EE0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return nSize != 1 ? 3 : 0;
}

// 0x0054AA90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x13_InteractWithEntity_6FC84D70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    return sub_6FC828D0(pUnit, nUnitType, nUnitGUID, 0, pGame);
}

// 0x0054BBA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x34_IdentifyItemsWithNpc_6FC86BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    D2GAME_NPC_IdentifyAllItems_6FCC9C90(pGame, pUnit, *(int*)((char*)pPacket + 1));
    return 0;
}

// 0x0054BC00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x62_ResurrectMerc_6FC86C00(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (nSize != 5)
    {
        return 3;
    }

    D2GAME_NPC_ResurrectMerc_6FCC9350(pGame, pUnit, *(int*)((char*)pPacket + 1));
    return 0;
}

// 0x0054C590
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x48_TurnOffBusyState_6FC87E20(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!UNITS_GetPlayerData(pUnit)->bBusy)
    {
        return 2;
    }

    PLAYER_ResetBusyState(pUnit);
    return 0;
}

// 0x0054C690
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4D_PlayNpcMessage_6FC880A0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const int nMonsterId = *(unsigned short*)((char*)pPacket + 1);
    if (nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 2;
    }

    PLRINTRO_MaskNpcIntroFlag(pGame, pUnit, nMonsterId);
    return 0;
}
