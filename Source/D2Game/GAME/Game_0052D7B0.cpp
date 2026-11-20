#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define PLRMODE_DEATH 0
#define PLRMODE_NEUTRAL 1
#define PLRMODE_DEAD 17
#define EVENTTYPE_STATREGEN 3
#define EVENTTYPE_DELAYEDPORTAL 11
struct D2SaveHeaderStrc;
struct D2StaticPathStrc;
struct D2PartyNodeStrc;
struct D2PartyStrc;
struct D2PartyControlStrc;
struct D2InactiveItemNodeStrc;
struct D2InactiveUnitListStrc;
struct D2QuestTimerStrc;
struct D2QuestInfoStrc;
struct D2DrlgCoordsStrc;
struct D2ObjectRoomCoordStrc;
struct D2ObjectControlStrc;
struct D2GSPacketSrv53;
struct D2MonStatsTxt;
struct D2ObjInitFnStrc;
struct D2UnkPlrMsgStrc;
struct _RTL_CRITICAL_SECTION;
struct HASHKEY_NONE;
struct D2GameDataTableStrc;
struct D2PlayerDataStrc;
struct D2NpcEventStrc;
struct D2NpcGambleStrc;
struct D2NpcRecordStrc;
struct D2NpcControlStrc;
struct D2ArenaStrc;
struct D2RosterIterateStrc;
struct D2UnitProxyArgStrc;
struct D2GSPacketSrv8C;
struct D2GSPacketSrv8E;

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




struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    unsigned char unk_08[0x174];
    D2SaveHeaderStrc* pSaveHeader;
    unsigned int nSaveHeaderSize;
    char unk0x184[0x24];
    D2GameStrc* pGame;
    unsigned char nAct;
    unsigned char unk_1AD[0x7];
    D2ActiveRoomStrc* pRoom;
    unsigned char unk_1B8[0x2F0];
    D2ClientStrc* pNext;
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
    char unk0x00[0x1C];
    D2UnitStrc* pChangeFirstUnit;
    unsigned char unk_20[0x2C];
    D2DrlgCoordsStrc tCoords;
    unsigned char unk_5C[0x20];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom;
    int nX;
    int nY;
    D2ObjectRoomCoordStrc* pNext;
};

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
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[5];
    int bExpansion;
    char f_74[8];
    unsigned int dwInitSeed;
    unsigned int dwObjSeed;
    unsigned char unk_84[0x4];
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
    unsigned char unk_10F8[0x28];
    D2UnitStrc* pUnitList[5][128];
    char unk0x1B20[0x204];
    D2NpcControlStrc* pNpcControl;
    D2ArenaStrc* pArenaCtrl;
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2UnkPlrMsgStrc stru_6FD30708[20]; // 0x007319E8
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId); // 0x00536D50
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0
void __fastcall D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(D2ClientStrc* pClient, char nHeader, char a3, int a4, char a5, int a6, int a7, short a8, short a9); // 0x0053B520
void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10); // 0x0053B570
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket); // 0x0053C900
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055FDE0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates;
};

int __stdcall ENVIRONMENT_UpdateCycleIndex(D2DrlgActStrc* pAct, int nActNo); // 0x0061C040
void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse); // 0x0061C330
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490

struct _RTL_CRITICAL_SECTION
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

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

struct D2RosterIterateStrc
{
    int bFlag;
    D2UnitStrc* pUnit;
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

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern int gnVirtualPlayerCount_6FD4DC1C; // 0x00883D70
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0056DEB0(int a1, int a2, int a3, int a4); // 0x0056DEB0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
void __fastcall D2GAME_PACKETS_SendPacket0x03_6FC3C810(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId); // 0x0053B390
void __stdcall sub_0064C160(D2ActiveRoomStrc* pRoom); // 0x0064C160
void __fastcall sub_0053FAE0(D2GameStrc* pGame); // 0x0053FAE0
void __fastcall sub_0053DDF0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DDF0
void __fastcall sub_0053DF50(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DF50
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00
void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID); // 0x00578460
void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId); // 0x00579C00
void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit); // 0x005350B0
void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId); // 0x005724C0

void __fastcall sub_6FC81E10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

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

#include "gen/data/Source/D2Game/GAME/Game_0052D7B0.inc"

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
