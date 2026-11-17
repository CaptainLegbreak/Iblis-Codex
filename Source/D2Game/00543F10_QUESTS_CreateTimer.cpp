struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2MapAIStrc;
struct D2TextHeaderStrc;
struct D2QuestInfoStrc;
struct D2ObjectControlStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x4C];
    unsigned int dwLastHitClass;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x10D0];
    D2ObjectControlStrc* pObjectControl;
    D2QuestInfoStrc* pQuestControl;
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
};

typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);

struct D2QuestTimerStrc
{
    QUESTUPDATE pfUpdate;
    D2QuestDataStrc* pQuest;
    unsigned int dwTicks;
    unsigned int dwTimeout;
    D2QuestTimerStrc* pNext;
};

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2LevelsTxt
{
    char unk0x00[0x30];
    unsigned char nQuest;
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom;
    int nX;
    int nY;
    D2ObjectRoomCoordStrc* pNext;
};

struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
    int nShrines;
    int nWells;
    int nTrapMonsterId;
    D2CoordStrc wellCoordinates[4];
    D2CoordStrc shrineCoordinates[10];
};

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
    char unk0x1048[0xC8];
    D2ObjectRoomCoordStrc* pObjectRoomCoord;
};

struct D2MonsterRegionStrc
{
    char unk0x000[0x2C8];
    unsigned int dwUniqueCount;
    unsigned int dwMonSpawnCount;
    char unk0x2D0[0x08];
    unsigned char nQuest;
};

struct D2GSPacketSrv29
{
    unsigned char nHeader;
    unsigned char pData[96];
};

struct D2PackedGuidStrc
{
    unsigned short f_0;
    unsigned short f_2;
};

struct D2MessageStrc
{
    unsigned char nMenu;
    unsigned char pad0x01;
    unsigned short nStringId;
};

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x00681CE0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern int dword_6FD4DC34;                                                                                  // 0x008846DC
extern const D2UnkPlrMsgStrc stru_6FD30708[];                                                               // 0x007319E8
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall sub_6FC84C70(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A930
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestFlags, unsigned char* pBuffer, int nBufferSize, int nUnused); // 0x0065C560
void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket);   // 0x0053D700
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00593CB0
void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x0059D6A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket);   // 0x0053C8D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x0059DB20
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x005BBFA0
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel);        // 0x0058D090
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0058E640
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique);                                       // 0x00659B80
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi);        // 0x0058AD80
void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi);     // 0x0058AE10
void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi);        // 0x00587950
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall MONSTER_CheckSummonerFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00573540
int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit);                                                       // 0x00573520
void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId);                                        // 0x00573500
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue); // 0x0053BE40
void __fastcall sub_6FC3D830(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue); // 0x0053C1D0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD50

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define STRCOLOR_DARK_GOLD 4
#define LEVEL_DURIELSLAIR 73
#define LEVEL_DURANCEOFHATELEV1 100
#define LEVEL_GLACIALCAVESLEV1 118
#define LEVEL_ROCKYSUMMIT 120
#define LEVEL_THEWORLDSTONEKEEPLEV1 128
#define LEVEL_THEWORLDSTONECHAMBER 132
#define OBJECT_DREHYA_START_IN_TOWN 459
#define OBJECT_NIHLATHAK_START_IN_TOWN 461
#define OBJECT_LARZUK_STANDARD 543
#define OBJRGN_WELL_DISTANCE 100
#define OBJRGN_SHRINE_DISTANCE 50
#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_NEUTRAL 1
#define UNIT_ALIGNMENT_GOOD 2
#define UNIT_ALIGNMENT_UNASSIGNED 4
#define MONTYPEFLAG_OTHER 1
#define IMODE_STORED 0
#define IMODE_EQUIP 1
#define IMODE_INBELT 2
#define IMODE_ONCURSOR 4

// 0x00543F10
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks)
{
    D2QuestInfoStrc* pQuestControl = pQuest->pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }

    D2_ASSERT(!pQuestControl->bExecuting, 1047);

    D2QuestTimerStrc* pPrevious = pQuestControl->pTimer;
    D2QuestTimerStrc* pQuestTimer = (D2QuestTimerStrc*)sub_0040B430(pQuest->pGame->pMemoryPool, sizeof(D2QuestTimerStrc), gszQuestsSourceFile, 1050, 0);
    pQuestTimer->pNext = pPrevious;
    pQuestTimer->pfUpdate = pfnCallback;
    pQuestTimer->pQuest = pQuest;
    pQuestTimer->dwTicks = nTicks + pQuestControl->dwTick;
    pQuestTimer->dwTimeout = nTicks;
    pQuestControl->pTimer = pQuestTimer;
}

// 0x00544300
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate)
{
    pQuest->fLastState = nIterateState;
    if (bIterate == 1)
    {
        if (pfIterate)
        {
            SUNIT_IterateUnitsOfType(pQuest->pGame, UNIT_PLAYER, pUnit, pfIterate);
            return;
        }

        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1464);
        exit(-1);
    }
}

// 0x00544350
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine)
{
    char szMsg[128];
    pQuestData->fState = nState;
    wsprintfA(szMsg, "changing state to %d\n", nState);
    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pQuestData->pGame, szMsg, STRCOLOR_DARK_GOLD);
    }
}

// 0x00544520
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2QuestInfoStrc* pQuestHead = pGame->pQuestControl;
    D2_ASSERT(pQuestHead->bPickedSet, 2013);

    D2GSPacketSrv29 packet29;
    packet29.nHeader = 0x29;
    QUESTRECORD_CopyRecordToBuffer(pQuestHead->pQuestFlags, packet29.pData, sizeof(packet29.pData), 0);
    D2GAME_PACKETS_SendPacket0x29_6FC3F370(pClient, &packet29);
}

// 0x00544840
void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitId)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nUnitId);
    if (!pItem || !ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        return;
    }

    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord)
    {
        return;
    }

    if (pItemsTxtRecord->dwCode == ' dkb')
    {
        ACT1Q4_SendStoneOrderToClient(pGame, pUnit);
    }
    else if (pItemsTxtRecord->dwCode == ' srt')
    {
        ACT2Q6_SendTombIdToClient(pGame, pUnit);
    }
}

// 0x005456A0
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 3274);

    D2GSPacketSrv27 packet27;
    packet27.nHeader = 0x27;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    memcpy(&packet27.dwUnitGUID, &nUnitGUID, sizeof(nUnitGUID));
    packet27.nUnitType = UNIT_OBJECT;
    packet27.pMessages[0].nMenu = 0;
    packet27.pMessages[0].nStringId = nMessage;
    packet27.nCount = 1;
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
}

// 0x00545920
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nLevelId == 0 || DRLG_GetActNoFromLevelId(nLevelId) < nAct)
        {
            return;
        }
    }

    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nFlags = 0;
    packet5D.nQuestId = nQuestId;
    packet5D.nState = 12;
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszQuestsSourceFile, 3458);
    sub_6FC3F380(pClient, &packet5D);
}

// 0x00545B80
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nTargetLevel)
{
    switch (nTargetLevel)
    {
    case LEVEL_DURIELSLAIR:
        return ACT2Q6_IsDurielsLairClosed(pGame, pPlayer);

    case LEVEL_DURANCEOFHATELEV1:
        return ACT3Q5_IsDuranceOfHateClosed(pGame, pPlayer);

    case LEVEL_GLACIALCAVESLEV1:
    case LEVEL_THEWORLDSTONEKEEPLEV1:
        if (nSourceLevel != LEVEL_ROCKYSUMMIT)
        {
            return 0;
        }
        return ACT5Q5_IsArreatSummitClosed(pGame, pPlayer, nTargetLevel);

    case LEVEL_THEWORLDSTONECHAMBER:
        return ACT5Q6_IsWorldStoneChamberClosed(pGame, pPlayer);

    default:
        return 0;
    }
}

// 0x00545C30
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex)
{
    int nClassId = DATATBLS_MapSuperUniqueId(nType, nIndex);
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), pPosition->nX, pPosition->nY);
    if (pRoom)
    {
        return D2GAME_SpawnPresetMonster_6FC66560(pGame, pRoom, nClassId, pPosition->nX, pPosition->nY, 1);
    }

    return 0;
}

// 0x00545C90
void __fastcall QUESTS_MapPresetSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_OBJECT)
    {
        return;
    }

    switch (pUnit->dwClassId)
    {
    case OBJECT_DREHYA_START_IN_TOWN:
        ACT5Q3_ChangeDrehyaMapAI(pGame, pUnit, pMapAI);
        break;

    case OBJECT_NIHLATHAK_START_IN_TOWN:
        ACT5Q3_ChangeNihlathakMapAI(pGame, pUnit, pMapAI);
        break;

    case OBJECT_LARZUK_STANDARD:
        ACT5Q1_ChangeLarzukMapAI(pGame, pUnit, pMapAI);
        break;

    default:
        break;
    }
}

// 0x00545CD0
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return;
    }

    const unsigned char nQuestId = DATATBLS_GetLevelsTxtRecord(nLevelId)->nQuest;
    if (!nQuestId)
    {
        return;
    }

    if (bDebug)
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 0)
        {
            return;
        }
    }
    else
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 1)
        {
            return;
        }
    }

    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pGame, "Error attaching to unit", STRCOLOR_DARK_GOLD);
    }
}

// 0x00547170
void __fastcall OBJRGN_AllocObjectRoomCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = (D2ObjectRoomCoordStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ObjectRoomCoordStrc), ".\\OBJECTS\\objrgn.cpp", 375, 0);

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    pObjectRoomCoord->nX = nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    pObjectRoomCoord->nY = nY;

    pObjectRoomCoord->pRoom = pRoom;
    pObjectRoomCoord->pNext = pObjectControl->pObjectRoomCoord;
    pObjectControl->pObjectRoomCoord = pObjectRoomCoord;
}

// 0x005473A0
bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    for (int i = 0; i < pObjectRegion->nWells; ++i)
    {
        int nDistance = pObjectRegion->wellCoordinates[i].nX - nX;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_WELL_DISTANCE)
        {
            return false;
        }

        nDistance = pObjectRegion->wellCoordinates[i].nY - nY;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_WELL_DISTANCE)
        {
            return false;
        }
    }

    return true;
}

// 0x00547430
bool __fastcall OBJRGN_CanSpawnShrine(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    for (int i = 0; i < pObjectRegion->nShrines; ++i)
    {
        int nDistance = pObjectRegion->shrineCoordinates[i].nX - nX;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_SHRINE_DISTANCE)
        {
            return false;
        }

        nDistance = pObjectRegion->shrineCoordinates[i].nY - nY;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_SHRINE_DISTANCE)
        {
            return false;
        }
    }

    return true;
}

// 0x00547DD0
void __fastcall sub_6FC681C0(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit, int nPreviousAlignment, int nNewAlignment)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && !SUNIT_IsDead(pUnit) && !MONSTER_CheckSummonerFlag(pUnit, 2))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (pMonsterRegion && !pMonsterRegion->nQuest && nPreviousAlignment != nNewAlignment)
        {
            if (nPreviousAlignment == UNIT_ALIGNMENT_EVIL && (nNewAlignment == UNIT_ALIGNMENT_NEUTRAL || nNewAlignment == UNIT_ALIGNMENT_GOOD))
            {
                --pMonsterRegion->dwMonSpawnCount;
            }

            if (nNewAlignment == UNIT_ALIGNMENT_EVIL && nPreviousAlignment != UNIT_ALIGNMENT_UNASSIGNED)
            {
                ++pMonsterRegion->dwMonSpawnCount;
            }
        }
    }
}

// 0x00547ED0
void __fastcall sub_6FC682C0(D2MonsterRegionStrc** ppMonRegion, int nLevelId1, int nLevelId2, int nAlignment, int bDead, int a6, D2UnitStrc* pUnit)
{
    D2MonsterRegionStrc* pMonsterRegion1 = ppMonRegion[nLevelId1];
    D2MonsterRegionStrc* pMonsterRegion2 = ppMonRegion[nLevelId2];
    if (pUnit)
    {
        if (pMonsterRegion2 != pMonsterRegion1)
        {
            MONSTER_SetLevelId(pUnit, nLevelId1);
        }

        if (!a6 && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion2->dwMonSpawnCount;

            if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_OTHER))
            {
                --pMonsterRegion2->dwUniqueCount;
            }
        }
    }
    else
    {
        if (!a6 && !bDead && nAlignment == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion1->dwMonSpawnCount;
        }
    }
}

// 0x005484B0
void __fastcall sub_6FC82270(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;

    PlrMsgFunc pfSendMode = stru_6FD30708[nAnimMode].field_0;
    if (pfSendMode)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pfSendMode), 328);
        pfSendMode(pGame, pUnit, pClient, nAnimMode);
    }
}

// 0x00548520
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 339);
    D2_ASSERT(pClient, 340);

    if (pUnit == pPlayer)
    {
        D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(pClient, nStat, nNewValue);
    }
    else
    {
        sub_6FC3D830(pClient, 0x20, !pUnit ? -1 : pUnit->dwUnitId, nStat, nNewValue);
    }
}

// 0x005490E0
int __fastcall sub_005490E0_CheckCursorItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1123);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem && pItem->dwAnimMode == IMODE_ONCURSOR && INVENTORY_GetCursorItem(pUnit->pInventory) == pItem)
    {
        return 0;
    }

    return 1;
}

// 0x00549150
int __fastcall sub_00549150_CheckStoredItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1146);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem && pItem->dwAnimMode == IMODE_STORED && INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem))
    {
        return 0;
    }

    return 1;
}

// 0x005491B0
int __fastcall sub_005491B0_CheckStoredOrEquippedItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1169);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (pItem->dwAnimMode != IMODE_STORED && pItem->dwAnimMode != IMODE_EQUIP)
    {
        return 1;
    }

    return !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem);
}

// 0x005492F0
int __fastcall sub_005492F0_CheckBeltItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1256);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (pItem->dwAnimMode != IMODE_INBELT)
    {
        return 1;
    }

    return !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem);
}
