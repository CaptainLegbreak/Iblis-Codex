struct D2DrlgActStrc;
struct D2SkillStrc;
struct D2BitBufferStrc;
struct D2DynamicPathStrc;

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

enum D2C_MonsterIds
{
    MONSTER_GHEED = 147,
    MONSTER_AKARA = 148,
    MONSTER_CHARSI = 154,
    MONSTER_DROGNAN = 177,
    MONSTER_FARA = 178,
    MONSTER_ELZIX = 199,
    MONSTER_LYSANDER = 202,
    MONSTER_ASHEARA = 252,
    MONSTER_HRATLI = 253,
    MONSTER_ALKOR = 254,
    MONSTER_ORMUS = 255,
    MONSTER_HALBU = 257,
    MONSTER_JAMELLA = 405,
    MONSTER_LARZUK = 511,
    MONSTER_DREHYA = 512,
    MONSTER_MALAH = 513,
    MONSTER_NIHLATHAK = 514,
};

enum D2C_MonStatsTxtFlagIndices
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
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
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    char unk0x008[0x1A4];
    unsigned char nAct;
    char f_1AD[0x2FB];
    D2ClientStrc* pNext;
};

struct D2PartyNodeStrc
{
    int nUnitGUID;
    D2PartyNodeStrc* pNext;
};

struct D2PartyStrc
{
    short nPartyId;
    short field_2;
    D2PartyNodeStrc* pPartyNodes;
    D2PartyStrc* pNext;
};

struct D2PartyControlStrc
{
    short field_0;
    short field_2;
    D2PartyStrc* pParties;
};

struct D2InactiveItemNodeStrc
{
    D2InactiveItemNodeStrc* pNext;
    int nFrame;
    int nOwnerId;
};

struct D2InactiveUnitListStrc
{
    int nX;
    int nY;
    D2InactiveItemNodeStrc* pInactiveItems;
    void* pInactiveMonsters;
    void* pInactiveUnits;
    D2InactiveUnitListStrc* pNext;
};

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
    char unk0x1C[0xD8];
    D2QuestDataStrc* pPrev;
};

struct D2GameStrc;
typedef unsigned char (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuest);

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

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    D2DrlgCoordsStrc tCoords;
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom;
    int nX;
    int nY;
    D2ObjectRoomCoordStrc* pNext;
};

struct D2ObjectRegionStrc;

struct D2ObjectControlStrc
{
    char unk0x0000[0x28];
    int* pShrineSubTypeIds[8];
    D2ObjectRegionStrc* pObjectRegion[1024];
    char unk0x1048[0xC8];
    D2ObjectRoomCoordStrc* pObjectRoomCoord;
};

struct D2GameStrc
{
    char unk0x0000[0x1C];
    void* pMemoryPool;
    char unk0x0020[0x68];
    D2ClientStrc* pClientList;
    char unk0x008C[0x1C];
    int dwGameFrame;
    char unk0x00AC[0x10];
    D2DrlgActStrc* pAct[5];
    char unk0x00D0[0x08];
    D2InactiveUnitListStrc* pInactiveUnitList[5];
    char unk0x00EC[0x1004];
    D2ObjectControlStrc* pObjectControl;
    D2QuestInfoStrc* pQuestControl;
    char unk0x10F8[0xC34];
    D2PartyControlStrc* pPartyControl;
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

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1D8];
    int nLevelsTxtRecordCount;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc*, D2UnitStrc*, D2ClientStrc*, int);
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
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2UnkPlrMsgStrc stru_6FD30708[20];                                                                   // 0x007319E8

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId);                                     // 0x00536D50
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient);                             // 0x005387F0
void __fastcall D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(D2ClientStrc* pClient, char nHeader, char a3, int a4, char a5, int a6, int a7, short a8, short a9); // 0x0053B520
void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10); // 0x0053B570
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket);            // 0x0053C900
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);            // 0x0055FDE0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall ENVIRONMENT_UpdateCycleIndex(D2DrlgActStrc* pAct, int nActNo);                               // 0x0061C040
void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse); // 0x0061C330
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord);                       // 0x0065C490

// 0x0052D7B0
void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i] && ENVIRONMENT_UpdateCycleIndex(pGame->pAct[i], i))
        {
            int nCycleIndex;
            int nTicks;
            int nEclipse;
            ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(pGame->pAct[i], &nCycleIndex, &nTicks, &nEclipse);
            D2GSPacketSrv53 packet53;
            packet53.nHeader = 0x53;
            *(int*)&packet53.nCycleIndex = nCycleIndex;
            *(int*)&packet53.nTicks = nTicks;
            packet53.nEclipse = nEclipse;
            for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
            {
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_UpdatePlayerItems_6FC4BB90(pGame, pPlayer, 1);
                    if (pClient->dwClientState == 4 && pClient->nAct == i)
                        D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);
                }
            }
        }
    }
}

static D2MonStatsTxt* SUNITPROXY_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x00536F80
void __fastcall SUNITPROXY_FillGlobalItemCache()
{
    const int nRecordCount = sgptDataTables->nMonStatsTxtRecordCount;
    for (int i = 0; i < nRecordCount; ++i)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SUNITPROXY_GetMonStatsTxtRecordInline(i);
        int bInteract = 0;
        if (pMonStatsTxtRecord)
            bInteract = pMonStatsTxtRecord->nFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7];
        if (bInteract)
        {
            switch (i)
            {
            case MONSTER_HALBU:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(12);
                break;
            case MONSTER_ALKOR:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(7);
                break;
            case MONSTER_CHARSI:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(2);
                break;
            case MONSTER_FARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(3);
                break;
            case MONSTER_ASHEARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(10);
                break;
            case MONSTER_HRATLI:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(6);
                break;
            case MONSTER_AKARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(0);
                break;
            case MONSTER_DROGNAN:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(5);
                break;
            case MONSTER_LYSANDER:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(4);
                break;
            case MONSTER_ORMUS:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(8);
                break;
            case MONSTER_GHEED:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(1);
                break;
            case MONSTER_ELZIX:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(9);
                break;
            case MONSTER_JAMELLA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(13);
                break;
            case MONSTER_DREHYA:
            case MONSTER_NIHLATHAK:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(16);
                break;
            case MONSTER_MALAH:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(14);
                break;
            case MONSTER_LARZUK:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(15);
                break;
            default:
                break;
            }
        }
    }
}

// 0x00540000
void __fastcall PARTY_FreePartyControl(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x2E);
    D2PartyControlStrc* pPartyControl = pGame->pPartyControl;
    if (!pPartyControl)
        return;
    D2PartyStrc* pParty = pPartyControl->pParties;
    while (pParty)
    {
        D2PartyStrc* pNextParty = pParty->pNext;
        D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes;
        while (pPartyNode)
        {
            D2PartyNodeStrc* pNextPartyNode = pPartyNode->pNext;
            FOG_FreeServerMemory(pGame->pMemoryPool, pPartyNode, ".\\UNIT\\Party.cpp", 0x3F, 0);
            pPartyNode = pNextPartyNode;
        }
        FOG_FreeServerMemory(pGame->pMemoryPool, pParty, ".\\UNIT\\Party.cpp", 0x43, 0);
        pParty = pNextParty;
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pPartyControl, ".\\UNIT\\Party.cpp", 0x47, 0);
    pGame->pPartyControl = 0;
}

// 0x005404C0
void __fastcall sub_005404C0_AddLivingMemberLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    if (!SUNIT_IsDead(pUnit))
        *(int*)pArgs += STATLIST_UnitGetStatValue(pUnit, 12, 0);
}

// 0x00542AC0
void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct)
{
    for (D2InactiveUnitListStrc* i = pGame->pInactiveUnitList[nAct]; i; i = i->pNext)
    {
        D2InactiveItemNodeStrc* pPrevious = 0;
        D2InactiveItemNodeStrc* pCurrent = i->pInactiveItems;
        while (pCurrent)
        {
            D2InactiveItemNodeStrc* pNext = pCurrent->pNext;
            if (pCurrent->nFrame && pGame->dwGameFrame > pCurrent->nFrame)
            {
                if (pPrevious)
                    pPrevious->pNext = pNext;
                else
                    i->pInactiveItems = pNext;
                FOG_FreeServerMemory(pGame->pMemoryPool, pCurrent, ".\\UNIT\\SUnitInactive.cpp", 0x723, 0);
            }
            else
            {
                pPrevious = pCurrent;
            }
            pCurrent = pNext;
        }
    }
}

// 0x00543800
void __fastcall QUESTS_QuestFree(D2GameStrc* pGame)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;
    D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest;
    while (pQuestData)
    {
        D2QuestDataStrc* pPrevQuestData = pQuestData->pPrev;
        if (pQuestData->pQuestDataEx)
            FOG_FreeServerMemory(pGame->pMemoryPool, pQuestData->pQuestDataEx, gszQuestsSourceFile, 0x1DF, 0);
        FOG_FreeServerMemory(pGame->pMemoryPool, pQuestData, gszQuestsSourceFile, 0x1E1, 0);
        pQuestData = pPrevQuestData;
    }
    D2QuestTimerStrc* pTimer = pQuestControl->pTimer;
    while (pTimer)
    {
        D2QuestTimerStrc* pNextTimer = pTimer->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x1E8, 0);
        pTimer = pNextTimer;
    }
    QUESTRECORD_FreeRecord(pGame->pMemoryPool, pQuestControl->pQuestFlags);
    FOG_FreeServerMemory(pGame->pMemoryPool, pQuestControl, gszQuestsSourceFile, 0x1EC, 0);
}

// 0x00543E10
void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;
    ++pQuestControl->dwTick;
    if (pQuestControl->dwTick == -1)
    {
        for (D2QuestTimerStrc* i = pQuestControl->pTimer; i; i = i->pNext)
            i->dwTicks = -1 - i->dwTicks;
    }
    pQuestControl->bExecuting = 1;
    D2QuestTimerStrc* pTimer = pQuestControl->pTimer;
    D2QuestTimerStrc* pPrev = 0;
    while (pTimer)
    {
        D2QuestTimerStrc* pNext = pTimer->pNext;
        if (pTimer->dwTicks < pQuestControl->dwTick)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)pTimer->pfUpdate), 0x3F0);
            if (pTimer->pfUpdate(pGame, pTimer->pQuest) == 1)
            {
                if (!pPrev)
                {
                    pQuestControl->pTimer = pTimer->pNext;
                    FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x3F7, 0);
                    pTimer = 0;
                }
                else
                {
                    pPrev->pNext = pTimer->pNext;
                    FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x3FE, 0);
                    pTimer = pPrev;
                }
            }
            else
            {
                pTimer->dwTicks = pQuestControl->dwTick + pTimer->dwTimeout;
            }
        }
        pPrev = pTimer;
        pTimer = pNext;
    }
    pQuestControl->bExecuting = 0;
}

// 0x00546E90
void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0xB6);
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    if (!pObjectControl)
        return;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = pObjectControl->pObjectRoomCoord;
    while (pObjectRoomCoord)
    {
        D2ObjectRoomCoordStrc* pNext = pObjectRoomCoord->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pObjectRoomCoord, ".\\OBJECTS\\objrgn.cpp", 0xC1, 0);
        pObjectRoomCoord = pNext;
    }
    pObjectControl->pObjectRoomCoord = 0;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
        FOG_FreeServerMemory(pGame->pMemoryPool, pObjectControl->pObjectRegion[i], ".\\OBJECTS\\objrgn.cpp", 0xE2, 0);
    for (int i = 0; i < 8; ++i)
    {
        if (pObjectControl->pShrineSubTypeIds[i])
            FOG_FreeServerMemory(pGame->pMemoryPool, pObjectControl->pShrineSubTypeIds[i], ".\\OBJECTS\\objrgn.cpp", 0xE8, 0);
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pGame->pObjectControl, ".\\OBJECTS\\objrgn.cpp", 0xEC, 0);
}

// 0x00547210
void __fastcall OBJECTS_InitFunction17_Waypoint(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = pOp->pGame->pObjectControl;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = pObjectControl->pObjectRoomCoord;
    while (pObjectRoomCoord)
    {
        if (pObjectRoomCoord->pRoom == pOp->pRoom
            || (pOp->pRoom && pObjectRoomCoord->nX >= pOp->pRoom->tCoords.nSubtileX && pObjectRoomCoord->nX < pOp->pRoom->tCoords.nSubtileX + pOp->pRoom->tCoords.nSubtileWidth
                && pObjectRoomCoord->nY >= pOp->pRoom->tCoords.nSubtileY && pObjectRoomCoord->nY < pOp->pRoom->tCoords.nSubtileY + pOp->pRoom->tCoords.nSubtileHeight))
        {
            if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
            {
                UNITS_ChangeAnimMode(pOp->pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
                EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
            }
            FOG_FreeServerMemory(pOp->pGame->pMemoryPool, pObjectRoomCoord, ".\\OBJECTS\\objrgn.cpp", 0x19B, 0);
            pObjectControl->pObjectRoomCoord = 0;
            return;
        }
        pObjectRoomCoord = pObjectRoomCoord->pNext;
    }
    if (DUNGEON_IsRoomInTown(pOp->pRoom))
        UNITS_ChangeAnimMode(pOp->pObject, 2);
}

// 0x00548180
void __fastcall sub_6FC81E10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    if (pUnit != CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
        {
            const int nTargetGUID = pTarget->dwUnitId;
            const int nTargetType = pTarget->dwUnitType;
            const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
            D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(pClient, 0x10, 0, nUnitGUID, (unsigned char)stru_6FD30708[nAnimMode].field_8, nTargetType, nTargetGUID, UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit));
        }
        else
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            int nY;
            if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
                nY = pUnit->pStaticPath->tGameCoords.nY;
            else
                nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
            int nX;
            if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
                nX = pUnit->pStaticPath->tGameCoords.nX;
            else
                nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
            const int nUnitId = pUnit->dwUnitId;
            D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(pClient, 0x0F, 0, nUnitId, (unsigned char)stru_6FD30708[nAnimMode].field_4, D2COMMON_10175_PathGetFirstPointX(pPath), D2COMMON_10176_PathGetFirstPointY(pPath), 0, nX, nY);
        }
    }
}

#include "gen/data/Source/D2Game/0052D7B0_GAME_UpdateEnvironment.inc"
