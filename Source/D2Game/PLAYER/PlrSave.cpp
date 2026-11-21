#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2QuestData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2Primitives.h"
#include "D2DrlgRooms.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2ItemModes.h"

#pragma function(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define STATE_PLAYERBODY 7

#define STAT_GOLD 14

#define ITEMTYPE_WEAPON 45

#define ITEMACTION_DROPTOGROUND 2

#define ITEMACTION_ONGROUND 3

#define LEVEL_ROGUEENCAMPMENT 1

#define LEVEL_LUTGHOLEIN 40

#define LEVEL_KURASTDOCKTOWN 75

#define ACT_II 1

#define ACT_III 2

#define EVENTTYPE_REMOVESTATE 12

#define STATE_POISON 2

#define QUESTSTATEFLAG_A2Q6 14

#define QUESTSTATEFLAG_A5Q4 38

#define QUEST_A5Q4_NIHLATHAK 34

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM2 6

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

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

#define NUM_DIFFICULTIES 3

#define PLRSAVE2ERROR_BAD_PLAYERINTRO 11

struct D2CorpseStrc;

struct D2SaveHeaderStrc;

struct D2ServerCallbackFunctions;

struct D2ClientInfoStrc;

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2PlayerDataStrc;

struct D2SkillsTxt;

struct D2PartyNodeStrc;

struct D2PartyStrc;

struct D2PartyControlStrc;

struct D2CorpseSaveStrc;

struct D2LargeIntegerStrc;

struct D2FileTimeStrc;

struct D2UnitProxyArgStrc;

struct D2UnitFindArgStrc;

struct D2Act2Quest6Strc;

struct D2Act5Quest4Strc;

struct D2StatesTxt;

struct D2PlrIntroSaveStrc;

struct D2RosterIterateStrc;

struct D2SavedItemStrc;

struct D2ItemKeyStrc;

struct D2GameStrc;

struct D2InventoryStrc;

struct D2ActiveRoomStrc;

struct D2UnitStrc;

struct D2CoordStrc;

struct D2ClientStrc;

struct D2DrlgActStrc;

struct D2CriticalSectionStrc;

struct D2UnitFindDataStrc;

struct D2QuestDataStrc;

struct D2DataTablesStrc;

struct D2ItemDropStrc;

struct D2ItemSaveStrc;

struct D2HirelingTxt;

struct D2CharStatsTxt;

struct D2BitBufferStrc;

struct D2ItemsTxt;

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc*); // 0x00627D40

void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc*,D2UnitStrc*); // 0x0063C180

int __fastcall D2GAME_PlaceItem_6FC44410(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus); // 0x005606B0

int __fastcall sub_6FC48940(D2GameStrc*,D2UnitStrc*,int,int,int,int*); // 0x0055E9B0

int __fastcall sub_6FC4B9D0(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055FB10

int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc*,D2UnitStrc*,int,int,int*,int,int,int,int); // 0x00562660

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall sub_00538410_RemoveUnitIfNotAdjacent2(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x00538410

void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005394A0

int __fastcall ClientAddPlayerToGame(D2ClientStrc* ptClient, D2GameStrc* ptGame, int bLoadFromSave, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00539760

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

int __fastcall D2GAME_Return1_6FC41900(D2UnitStrc* pItem); // 0x00564CA0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern const int dword_6FD307F8[]; // 0x00731AD8

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

void __fastcall sub_M93_UseCount_00531750(int nCount);

struct D2PartyStrc
{
    unsigned short nPartyId;
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

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

int __fastcall sub_005317B0_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x005317B0

void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId); // 0x00537340

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0

void __fastcall LEVEL_ChangeAct(D2GameStrc* pGame, D2ClientStrc* pClient, int nDestinationLevelId, int nTileCalc); // 0x0053ACC0

void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053EAE0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

int __fastcall PLRTRADE_CopyTradeSaveDataToBuffer(D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize); // 0x005675E0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

struct D2CorpseSaveStrc
{
    unsigned int unk0x00;
    int nX;
    int nY;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630

__declspec(noalias) int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7); // 0x00569AD0

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
    unsigned char unk_AF[0x1];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2CriticalSectionStrc gSrvClientListByNameLock_6FD443B8; // 0x008846C0

extern D2ClientStrc* gpClientListByName_6FD443D0[256]; // 0x00883EA8

extern int gbHasHighResolutionClock; // 0x0088C7A0

extern D2LargeIntegerStrc gPerformanceFrequency; // 0x0088C790

extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50

extern int gbD2ServerCallbackFunctionsInitialized_6FD45834; // 0x00883D54

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount); // 0x006CC25C

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) long __stdcall CompareFileTime(const D2FileTimeStrc* pFileTime1, const D2FileTimeStrc* pFileTime2); // 0x006CC390

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

unsigned int __fastcall CRC32_Compute(void* pData, unsigned int dwSize); // 0x006C99F6

unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString); // 0x004112C0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom); // 0x0061A2C0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x00536820

void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bStale); // 0x00537230

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame); // 0x0053FD40

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A

extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile);

extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC

int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050

int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient); // 0x00538590

int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int a5, int a6, int a7); // 0x00538CE0

D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient); // 0x00538E00

void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient); // 0x00538F10

void __fastcall D2GAME_SetSaveLoadComplete_6FC34300(D2ClientStrc* pClient); // 0x00538F80

extern "C" int __stdcall sub_00554100(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

extern "C" void __fastcall sub_00539300(D2ClientStrc* pClient, unsigned int* pOut); // 0x00539300

extern "C" void __fastcall sub_00539310(D2ClientStrc* pClient, unsigned int* pOut); // 0x00539310

void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer); // 0x005392F0

extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230

extern "C" const char gszFileModeWb_006D69E0[]; // 0x006D69E0

extern "C" const char gszSaveOpenError_006E09C4[]; // 0x006E09C4

extern "C" const char szPlrSaveCppFile_006E09AC[]; // 0x006E09AC

typedef int (__stdcall* FARPROC)();

extern int gnGlobal_00883D6C; // 0x00883D6C

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

unsigned int __fastcall D2GAME_GetSaveChecksumFromClient_6FC33940(D2ClientStrc* pClient); // 0x00538350

int __fastcall D2GAME_SAVE_CalculateChecksum_6FC8A140(D2SaveHeaderStrc* pSaveHeader, int nSize); // 0x00531E30

int __fastcall CLIENTS_GetSaveHeaderSize(D2ClientStrc* pClient); // 0x00538E30

void __fastcall sub_00539320(D2ClientStrc* pClient, unsigned int nClientInfo); // 0x00539320

void __fastcall D2GAME_SetSaveFileChecksum_6FC33970(D2ClientStrc* pClient, unsigned int nChecksum); // 0x00538380

void __fastcall CLIENTS_CopySaveDataToClient(D2ClientStrc* pClient, const void* pData, unsigned int nSize); // 0x00538E60

struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char unk0x04[NUM_DIFFICULTIES][8];
    unsigned char unk0x1C[NUM_DIFFICULTIES][8];
};

struct D2RosterIterateStrc
{
    int bFlag;
    D2UnitStrc* pUnit;
};

void __fastcall sub_00535AF0_RosterFlagCb(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs); // 0x00535AF0

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2UnitStrc* __stdcall sub_0063BF90_GetSecondaryWeapon(D2InventoryStrc* pInventory); // 0x0063BF90

extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

#pragma pack(push, 1)

struct D2SavedItemStrc
{
    unsigned char nBodyLoc;
    unsigned char nSocketedItems;
    int nItemLevel;
    int nItemId;
    unsigned char nSpawnType;
    unsigned char nItemQuality;
    int nQuantity;
    int nMinDurability;
    int nMaxDurability;
    int nX;
    int nY;
    int nItemIndex;
    unsigned int nItemFlags;
    unsigned int nSeed;
    unsigned int nItemSeed;
    unsigned char nInvPage;
    unsigned char nEarLevel;
    char szName[16];
    unsigned short nItemFormat;
    unsigned int nItemCode;
};

#pragma pack(pop)

struct D2ItemKeyStrc
{
    unsigned int nCode;
    int nIndex;
    int nLevel;
    unsigned int nSeed;
    unsigned int nItemSeed;
};

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90

void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc); // 0x0063BDB0

void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210

int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData); // 0x00532F30

int __fastcall PLRSAVE_CreateAndPlaceLegacyPlayerItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount); // 0x00531040

static int __stdcall sub_00531520_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent); // 0x00531520

int __fastcall sub_00531210_PlaceLoadedItem(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem,D2UnitStrc* pSocketItem); // 0x00531210

D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int* pSize, unsigned int dwVersion); // 0x00558CB0

void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00563470

void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit); // 0x00564CB0

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110

const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0

int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x00533350

int __fastcall sub_005335E0(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x005335E0

static int sub_00532D90_ClearValue(int* pValue);

static __declspec(noinline) D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem); // 0x00530F40

void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x005378E0

void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName); // 0x006220F0

void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed); // 0x00552DF0

int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient); // 0x005385F0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90

void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct); // 0x005706D0

void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3); // 0x00546270

int __fastcall sub_00534330(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00534330

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40

unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);

int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030

extern "C" int __stdcall sub_00410E90(D2BitBufferStrc* pBuffer); // 0x00410E90

extern "C" unsigned int __stdcall sub_006287A0(unsigned int dwA, unsigned int dwB); // 0x006287A0

int __stdcall DATATBLS_MapOldItemIndexToCurrent(int nItemId); // 0x006335A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

struct D2QuestSaveSectionStrc;

#pragma pack(push, 1)

struct D2QuestSaveSectionStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short nSize;
    unsigned char pQuestRecord[3][96];
};

#pragma pack(pop)

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0

unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc*); // 0x0053FCE0

extern "C" const char gszPlrSaveFile_006E09AC[]; // 0x006E09AC

void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerId); // 0x0063D430

static __declspec(noinline) int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize);

__declspec(noinline)
// 0x00531520
static int __stdcall sub_00531520_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent)
{
    switch (!pItem ? 0 : pItem->dwAnimMode)
    {
    case 6:
        if (pParent)
        {
            UNITS_ChangeAnimMode(pItem, 4);
            const int nParentGUID = pParent->dwUnitId;
            const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
            int bPlaced;
            if (D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, nItemGUID, nParentGUID, &bPlaced, 0, 1, 0, 0))
                break;
        }
    default:
        return 13;
    case 1:
        {
            D2InventoryStrc* pInventory = pPlayer->pInventory;
            const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
                return 13;
            int nPage = 3;
            if (nBodyLoc == 11 || nBodyLoc == 12)
                nPage = 4;
            if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
                return 13;
            ITEMS_SetBodyLocation(pItem, nBodyLoc);
            if (pItem)
                pItem->dwFlags &= ~2u;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 255);
            sub_00628170_SetItemCommandFlag(pItem, 8, 1);
            if (pItem)
                pItem->dwFlags &= ~0x02000000u;
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pPlayer, 1);
            QUESTS_ItemPickedUp(pGame, pPlayer, pItem);
            break;
        }
    case 0:
        {
            UNITS_ChangeAnimMode(pItem, 4);
            int nY;
            switch (pItem->dwUnitType)
            {
            case UNIT_OBJECT:
            case UNIT_ITEM:
            case UNIT_TILE:
                nY = pItem->pStaticPath->nYPos;
                break;
            default:
                nY = pItem->pDynamicPath ? PATH_GetYPosition(pItem->pDynamicPath) : 0;
                break;
            }
            int nX;
            switch (pItem->dwUnitType)
            {
            case UNIT_OBJECT:
            case UNIT_ITEM:
            case UNIT_TILE:
                nX = pItem->pStaticPath->nXPos;
                break;
            default:
                nX = pItem->pDynamicPath ? PATH_GetXPosition(pItem->pDynamicPath) : 0;
                break;
            }
            const int nItemGUID = pItem->dwUnitId;
            if (D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 536, pGame, pPlayer, nItemGUID, nX, nY, 0, 0, 0))
                break;
            return 13;
        }
    }
    return 0;
}

#define WRITE_ITEM(pItem) { const int nSize = D2GAME_SAVE_SerializeItem_6FC89AD0(pGame, pUnit, pItem, pData, nBufferSize - (pData - pBuffer), a4, a5, a6); if (nSize < 0) return -1; pData += nSize; if (!nSize && nItems > 0) --nItems; }

#define PREPARE_ITEM(pItem) (ITEMS_SerializeItemToBitstream(pItem, tempBuffer, sizeof(tempBuffer), 1, 1, 0))

#define UNIT_MONSTER 1

#define SYSERROR_BAD_WAYPOINT 3

#define WAYPOINT_MAGIC 0x5357

#define UNITFLAG_TARGETABLE 0x02

#define UNITFLAG_CANBEATTACKED 0x04

#define UNITFLAG_ISVALIDTARGET 0x08

#define UNITFLAG_INITSEEDSET 0x10

#define EVENTTYPE_FREEHOVER 3

#define EVENTTYPE_STATREGEN 4

#define EVENTTYPE_TRAP 6

#define COLLIDE_MASK_CORPSE 0x9C19

#define CLIENTFLAGEX_HAS_SAVE_CHECKSUM 0x08

#define LEVEL_HARROGATH 109

struct D2SkillListStrc;

struct D2WaypointSaveRecordStrc;

struct D2WaypointSaveSectionStrc;

struct D2CharItemStrc;

struct D2DrlgDeleteStrc;

static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory); // 0x00531750

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __fastcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int a4, int a5, int a6); // 0x005316D0

static __declspec(noinline) void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName);

struct D2WaypointSaveRecordStrc
{
    unsigned short nFlags;
    unsigned short unk0x02;
    int unk0x04[5];
};

struct D2WaypointSaveSectionStrc
{
    unsigned short nMagic;
    unsigned short unk0x02;
    int unk0x04;
    D2WaypointSaveRecordStrc pRecords[3];
};

struct D2DrlgDeleteStrc
{
    int nUnitType;
    int nUnitGUID;
    D2DrlgDeleteStrc* pNext;
};

typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

extern int gbClientListInitialized_008846D8; // 0x008846D8

extern D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8

extern D2ClientStrc* gpClientList_008842A8[256]; // 0x008842A8

int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400

void __fastcall sub_00534800_CreatePlayerIntros(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00534800

void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem); // 0x00534D60

D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536C50

void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0

void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0

void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D090

void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053ED50

void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70

void __fastcall ARENA_AllocArenaUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053F530

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

void __fastcall QUESTS_UpdateNPCIntros(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct); // 0x00545100

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue); // 0x0055B800

void __fastcall sub_6FC92EF0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567330

int __fastcall sub_00567620(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* a3); // 0x00567620

void __fastcall sub_00568760_ResetPlayerInteract(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00568760

int __fastcall sub_6FC61F20(D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00573140

void __fastcall PLAYERPETS_AllocPetList(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575AF0

void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00579130

void __fastcall sub_6FC79B50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x005854D0

void __fastcall ACT5Q5_OnPlayerDied(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058D560

void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597310

void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventory); // 0x00597890

D2DrlgDeleteStrc* __stdcall DUNGEON_GetDrlgDeleteFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A330

void* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int a2, int a3); // 0x00619DA0

void __stdcall UNITS_AllocPlayerData(D2UnitStrc* pUnit); // 0x00621F90

void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00623300

void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00623350

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, STATLIST_CallbackFn pfCallback, D2GameStrc* pGame); // 0x00626D40

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450

D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool); // 0x006438B0

void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit); // 0x00647EE0

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int nPosIncrementValue); // 0x0064E7E0

void __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20

void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDest, const D2WaypointSaveRecordStrc* pSource); // 0x00661030

static int __stdcall PLRSAVE_CreateNewPlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer); // 0x00532590

static int __stdcall D2GAME_SAVE_ReadFile_6FC8C9D0(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005343A0

static int __stdcall sub_005344B0_ReadSaveFromDisk(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005344B0

static int __stdcall sub_00534520_ReadSaveFromClient(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x00534520

int __fastcall D2GAME_SAVE_GetUnitDataFromFile_6FC8CB40(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, int bLoadSave, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005345A0

#pragma pack(push, 1)

struct D2LegacySaveHeaderStrc
{
 unsigned int dwMagic;
 unsigned int dwVersion;
 char szName[16];
 unsigned int dwFlags;
 unsigned short nSkills;
 unsigned short nStats;
 unsigned short nHeaderSize;
 unsigned short nClass;
 char unk24[0x22];
 unsigned char hotkeys[8][2];
 unsigned char nLeftSkill;
 unsigned char nRightSkill;
 unsigned char nLocation;
 unsigned char guildFlags[2];
 char guildTag[4];
 char guildName[28];
 unsigned char guildColors[3];
 unsigned int nMapSeed;
};

#pragma pack(pop)

typedef char LegacyHeaderSizeCheck[sizeof(D2LegacySaveHeaderStrc)==130?1:-1];

extern "C" int __cdecl _stricmp(const char*,const char*); // 0x006841E9

void __fastcall sub_00538630(D2ClientStrc*,unsigned short); // 0x00538630

void __fastcall CLIENTS_SetClassId(D2ClientStrc*,int); // 0x00538620

void __fastcall CLIENTS_SetActNo(D2ClientStrc*,unsigned char); // 0x005382E0

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc*); // 0x005387C0

void __fastcall sub_00539120_SetGuildFlags(D2ClientStrc*,int); // 0x00539120

void __fastcall sub_00539140_SetGuildTag(D2ClientStrc*,char*); // 0x00539140

void __fastcall sub_00539170_SetGuildName(D2ClientStrc*,char*); // 0x00539170

void __fastcall sub_005391C0_SetGuildColors(D2ClientStrc*,unsigned char,int,int); // 0x005391C0

void __fastcall sub_00539230_SetFlag(D2ClientStrc*,unsigned char); // 0x00539230

int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int bCorpseItems, int* pReadSize); // 0x005337F0

#define SYSERROR_CORPSES 6

struct _iobuf;

#define ACT_I 0

#define GAMETYPE_1 1

#define GAMETYPE_2 2

#define SYSERROR_UNK_14 14

extern "C" const char gszModeRb_006CDC90[];                                                                 // 0x006CDC90

extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782

extern "C" void __fastcall sub_00537970_SetClientFlag1(D2ClientStrc* pClient); // 0x00537970

void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit);                                                            // 0x0056DE40

#pragma pack(push, 1)

struct D2LegacyMercSaveStrc
{
    unsigned short wMagic;
    unsigned int dwFlags;
    unsigned int dwSeed;
    unsigned short wName;
    unsigned short wHirelingId;
    unsigned int dwExperience;
};

#pragma pack(pop)

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610

D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int, int, int); // 0x006562F0

D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc*, D2UnitStrc*, unsigned short, int, unsigned short, int, int); // 0x005774F0

unsigned int __fastcall PLRSAVE_ConvertLegacyHirelingExperience(D2GameStrc*, unsigned short, unsigned int); // 0x00533BF0

void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc*, int, int, D2PetInfoStrc*); // 0x005749B0

int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830

void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc*, unsigned short, int); // 0x005718C0

int __stdcall MONSTERS_GetHirelingExpForNextLevel(int, int); // 0x00663790

void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x00572840

void __fastcall sub_6FC7D470(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x005751A0

void __fastcall SUNIT_SetCombatMode(D2GameStrc*, D2UnitStrc*, int); // 0x00553570

void __fastcall sub_005738D0(D2GameStrc*, D2UnitStrc*); // 0x005738D0

void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc*, D2UnitStrc*, int, int); // 0x0055DF00

void __fastcall sub_0055F4F0(D2GameStrc*, D2UnitStrc*, int); // 0x0055F4F0

void __fastcall MONSTERAI_SendMercStats(D2GameStrc*, D2UnitStrc*, int); // 0x005726C0

int __fastcall sub_00532BE0_ReadQuestData(D2UnitStrc*, unsigned char*, int, int*); // 0x00532BE0

int __fastcall D2GAME_SAVE_ReadWaypointData_6FC8AD50(D2UnitStrc* pUnit, const unsigned char* pSection, int nUnused, int* pSize); // 0x00532C70

int __fastcall sub_00532D00_ReadPlayerIntro(D2UnitStrc*, unsigned char*, int, int*); // 0x00532D00

int __fastcall sub_00532DA0_ReadPlayerStats(D2GameStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x00532DA0

int __fastcall sub_6FC8AEC0(D2GameStrc*, D2ClientStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x00532E90

int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc*); // 0x00623460

void __fastcall sub_00568DB0(D2GameStrc*, D2UnitStrc*); // 0x00568DB0

int __fastcall PLRSAVE_ReadCorpseSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nRemainingSize, int* pSize); // 0x005339A0

int __stdcall sub_00533F70_ReadHotkeySection(D2UnitStrc* pPlayer, const unsigned char* pSection, unsigned int nSize, int* pSize); // 0x00533F70

unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800

unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc*); // 0x00539220

void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc*); // 0x0053E110

static int __stdcall sub_00533C70_ReadLegacyMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int nVersion, unsigned int nSize, int* pSize);

static void __stdcall sub_00532340_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient);

void __fastcall CLIENTS_SetFlags(D2ClientStrc* pClient, int nFlags); // 0x00538630

int __fastcall PLRSAVE_ReadLegacyHeader(D2GameStrc* pGame,D2ClientStrc* pClient,D2LegacySaveHeaderStrc* pSave,D2UnitStrc** ppPlayer,int* pNewPlayer,unsigned int* pVersion,int* pStats,int* pSkills,int* pLeft,int* pRight,int* pHeaderSize);

int __fastcall D2GAME_SAVE_ProcessSaveFile_6FC8C0C0(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg);

struct D2NpcVendorChainStrc
{
    int dwGUID;
    int unk0x04;
    D2NpcVendorChainStrc* pNext;
};

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int field_4;
    int field_8;
    int field_C;
    D2NpcEventStrc* pNext;
};

struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
};

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0

D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit);                           // 0x00535E80

struct D2NpcVendorStateStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01;
    unsigned char nAct;
    unsigned char bTrader;
    char unk0x04[3];
    unsigned char bRefreshInventory;
    unsigned int dwTicks;
};

static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

static __declspec(noinline) D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem)
{
    D2ItemDropStrc itemDrop;
    memset(&itemDrop, 0, sizeof(itemDrop));

    itemDrop.wItemFormat = pSavedItem->nItemFormat;
    itemDrop.nItemLvl = pSavedItem->nItemLevel;
    itemDrop.nId = pSavedItem->nItemId;
    itemDrop.nSpawnType = pSavedItem->nSpawnType;
    itemDrop.nX = pSavedItem->nX;
    itemDrop.nY = pSavedItem->nY;
    itemDrop.nQuality = pSavedItem->nItemQuality;
    itemDrop.nQuantity = pSavedItem->nQuantity;
    itemDrop.nMinDur = pSavedItem->nMinDurability;
    itemDrop.nMaxDur = pSavedItem->nMaxDurability;
    itemDrop.dwSeed = pSavedItem->nSeed;
    itemDrop.pGame = pGame;
    itemDrop.pRoom = 0;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.dwItemSeed = pSavedItem->nItemSeed;
    itemDrop.dwFlags1 = pSavedItem->nItemFlags;
    itemDrop.bForce = 1;
    itemDrop.nItemIndex = pSavedItem->nItemIndex;

    strcpy(itemDrop.szName, pSavedItem->szName);

    *(unsigned char*)&itemDrop.eEarLvl = pSavedItem->nEarLevel;

    D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
    if (!pItem)
        return 0;

    ITEMS_SetFileIndex(pItem, pSavedItem->nItemIndex);
    ITEMS_SetInvPage(pItem, pSavedItem->nInvPage);
    return pItem;
}

// 0x00531040
int __fastcall PLRSAVE_CreateAndPlaceLegacyPlayerItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount)
{
    if (pSocketedItemCount)
    {
        *pSocketedItemCount = 0;
    }

    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
    {
        return 12;
    }

    switch (pItem->dwAnimMode)
    {
    case IMODE_STORED:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, ".\\PLAYER\\PlrSave.cpp", 0xE1);
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 0xEA, pGame, pPlayer, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 1, 0))
        {
            return 12;
        }

        break;
    }
    case IMODE_EQUIP:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!ITEMMODE_EquipCursorItem(pGame, pPlayer, sub_00451F50(pItem), pSavedItem->nBodyLoc, 1, &nUnused))
        {
            return 12;
        }

        break;
    }
    case IMODE_INBELT:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        UNITS_SetXForStaticUnit(pItem, pSavedItem->nX);
        UNITS_SetYForStaticUnit(pItem, pSavedItem->nY);
        int nUnused;
        if (!sub_6FC48940(pGame, pPlayer, sub_00451F50(pItem), pSavedItem->nX, 0, &nUnused))
        {
            return 12;
        }

        break;
    }
    case IMODE_ONCURSOR:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        INVENTORY_SetCursorItem(pPlayer->pInventory, pItem);
        if (!sub_6FC4B9D0(pGame, pPlayer, pItem))
        {
            return 12;
        }

        break;
    }
    case 6:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!*ppItem || !D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, sub_00451F50(pItem), sub_00451F50(*ppItem), &nUnused, 0, 1, 0, 0))
        {
            return 12;
        }

        break;
    }
    default:
        return 12;
    }

    if (pSavedItem->nSocketedItems > 0)
    {
        *ppItem = pItem;
    }

    if (pSocketedItemCount)
    {
        *pSocketedItemCount = pSavedItem->nSocketedItems;
    }

    return 0;
}

static __forceinline unsigned int GetMode(D2UnitStrc* pUnit) { if (!pUnit) return 0; return pUnit->dwAnimMode; }

static __forceinline int GetId(D2UnitStrc* pUnit) { if (!pUnit) return -1; return pUnit->dwUnitId; }

// 0x00531210
int __fastcall sub_00531210_PlaceLoadedItem(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem,D2UnitStrc* pSocketItem)
{
    switch (GetMode(pItem))
    {
    case 0:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp",319,pGame,pPlayer,nId,CLIENTS_GetUnitX(pItem),CLIENTS_GetUnitY(pItem),0,1,0))
                return 12;
            break;
        }
    case 1:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            int nResult;
            if (!ITEMMODE_EquipCursorItem(pGame,pPlayer,nId,ITEMS_GetBodyLocation(pItem),1,&nResult))
                return 12;
            break;
        }
    case 2:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            int nResult;
            if (!sub_6FC48940(pGame,pPlayer,nId,CLIENTS_GetUnitX(pItem),0,&nResult))
                return 12;
            break;
        }
    case 4:
        UNITS_ChangeAnimMode(pItem,4);
        INVENTORY_SetCursorItem(pPlayer->pInventory,pItem);
        if (!sub_6FC4B9D0(pGame,pPlayer,pItem))
            return 12;
        break;
    case 6:
        {
            UNITS_ChangeAnimMode(pItem,4);
            if (!pSocketItem) return 12;
            const int nSocketId = pSocketItem->dwUnitId;
            int nResult;
            if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame,pPlayer,GetId(pItem),nSocketId,&nResult,0,0,0,0))
                return 12;
            break;
        }
    default: return 12;
    }
    return 0;
}

// 0x00531390
static __declspec(noinline) int __stdcall PLRSAVE_CreateAndPlaceLegacyCorpseItem(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount, D2UnitStrc* pUnit)
{
    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
        return 13;

    switch (pItem->dwAnimMode)
    {
    case IMODE_STORED:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 0x1C2, pGame, pUnit, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 0, 0))
            return 13;
        break;
    }
    case IMODE_EQUIP:
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
        if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
            return 13;

        int nPage = 3;
        if (nBodyLoc == 11 || nBodyLoc == 12)
            nPage = 4;

        if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
            return 13;

        ITEMS_SetBodyLocation(pItem, nBodyLoc);
        pItem->dwFlags &= 0xFFFFFFFDu;
        UNITS_ChangeAnimMode(pItem, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        ITEMS_SetItemCMDFlag(pItem, 8, 1);
        pItem->dwFlags &= 0xFDFFFFFFu;
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
        QUESTS_ItemPickedUp(pGame, pUnit, pItem);
        break;
    }
    case 6:
    {
        if (!*ppItem)
            return 13;

        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pUnit, sub_00451F50(pItem), sub_00451F50(*ppItem), &nUnused, 0, 1, 0, 0))
            return 13;
        break;
    }
    default:
        return 13;
    }

    if (pSavedItem->nSocketedItems > 0)
        *ppItem = pItem;

    *pSocketedItemCount = pSavedItem->nSocketedItems;
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005316D0
int __stdcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nBitstreamSize, int a4, int a5, int a6)
{
    if (pItem)
    {
        const int bFlag = (pItem->dwFlagEx >> 15) & 1;
        if (!bFlag && (a4 != bFlag || a5 == bFlag || a6 != bFlag || D2GAME_Return1_6FC41900(pItem)))
        {
            const int nBits = ITEMS_SerializeItemToBitstream(pItem, pBitstream, nBitstreamSize, 1, 1, 0);
            D2_ASSERT(nBits, 1884);
            return nBits;
        }
    }
    return 0;
}

struct D2RunesTxt;

struct D2SkillStrc;

// 0x00531750
static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    if (!pInventory)
        return 0;
    if (INVENTORY_GetCursorItem(pInventory))
        nCount = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pIsItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pIsItem)
            ++nCount;
    }
    return (unsigned short)nCount;
}

// 0x005317B0
int __fastcall sub_005317B0_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pData, int nBufferSize, int a4, int a5, int a6)
{
    unsigned char tempBuffer[8192];
    unsigned char* pBuffer = pData;
    if (nBufferSize < 2) return 0;
    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    unsigned short nItems = sub_00531750_CountInventoryItems(pInventory);
    if (nBufferSize < pData - pBuffer + 2) return pData - pBuffer;
    unsigned short* pItemCount = (unsigned short*)pData;
    *pItemCount = nItems;
    pData += 2;
    if (pInventory)
    {
        D2UnitStrc* pLeft = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        D2UnitStrc* pCursor = INVENTORY_GetCursorItem(pInventory);
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                if (PREPARE_ITEM(pRight) < 0) return -1;
                if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
            }
            else
            {
                if (PREPARE_ITEM(pOther) < 0) return -1;
                if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            }
        }
        else
        {
            if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
        }
        if (pCursor && pCursor->dwUnitType == UNIT_ITEM && PREPARE_ITEM(pCursor) < 0) return -1;
        D2UnitStrc* pListItem = INVENTORY_GetFirstItem(pInventory);
        while (pListItem)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pListItem);
            unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (INVENTORY_GetItemNodePage(pListItem) != 3 || (nBodyLoc != 4 && nBodyLoc != 5))
            {
                WRITE_ITEM(pItem);
            }
            pListItem = INVENTORY_GetNextItem(pListItem);
        }
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                WRITE_ITEM(pRight);
                if (pOther) { WRITE_ITEM(pOther); }
            }
            else
            {
                WRITE_ITEM(pOther);
                if (pRight) { WRITE_ITEM(pRight); }
            }
        }
        else
        {
            if (pRight) { WRITE_ITEM(pRight); }
            if (pOther) { WRITE_ITEM(pOther); }
        }
        if (pCursor && pCursor->dwUnitType == UNIT_ITEM) { WRITE_ITEM(pCursor); }
        *pItemCount = nItems;
    }
    return pData - pBuffer;
}

void __stdcall sub_M93_Emit_00531750(int nUnused, D2InventoryStrc* pInventory)
{
    sub_M93_UseCount_00531750(sub_00531750_CountInventoryItems(pInventory));
}

// 0x00531BB0
int __fastcall sub_00531BB0_WriteItemList(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7)
{
    if (nArg5 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nResult = PLRTRADE_CopyTradeSaveDataToBuffer(pUnit, pBuffer, nBufferSize);
        if (nResult != 0)
        {
            return nResult;
        }
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    return sub_005317B0_WriteItems(pGame, pUnit, pInventory, pBuffer, nBufferSize, nArg5, nArg6, nArg7);
}

static __forceinline int sub_00531C10_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int sub_00531C10_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00531C10
int __fastcall sub_00531C10_WriteCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nSize, int a5)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pCorpse = 0;
    unsigned short nCorpses = 0;
    D2CorpseStrc* pCorpseNode = INVENTORY_GetFirstCorpse(pInventory);
    if (pCorpseNode)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetUnitGUIDFromCorpse(pCorpseNode));
        if (pCorpse)
        {
            nCorpses = 1;
        }
    }

    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    nSize -= 4;
    *(unsigned short*)pData = nCorpses;
    pData += 2;

    if (!pCorpse)
    {
        return 4;
    }

    D2CorpseSaveStrc tCorpse;
    const int nX = sub_00531C10_GetUnitX(pCorpse);
    const int nY = sub_00531C10_GetUnitY(pCorpse);

    D2_ASSERT(nSize >= sizeof(tCorpse), 0x97A);
    tCorpse.nX = nX;
    tCorpse.nY = nY;
    memcpy(pData, &tCorpse, sizeof(tCorpse));
    pData += sizeof(tCorpse);
    nSize -= sizeof(tCorpse);

    D2InventoryStrc* const tArg3 = pCorpse->pInventory;
    const int nWritten = sub_005317B0_WriteItems(pGame, pCorpse, tArg3, pData, nSize, 0, a5, 0);
    D2_ASSERT(nWritten > 0, 0x984);
    return nWritten + 16;
}

// 0x00531D30
static unsigned int __stdcall sub_00531D30_GetSaveFileSize(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nMaxSize, int a6, int a7)
{
    unsigned int nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, nMaxSize, a6, a7);
    return nSize;
}

unsigned int __fastcall sub_K10_EmitSaveFileSize(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    unsigned char aBuffer[4];
    return sub_00531D30_GetSaveFileSize(pGame, pPlayer, aBuffer, sizeof(aBuffer), 0, 0);
}

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

// 0x00531EB0
static int __stdcall sub_00531EB0_WriteFileOnRealm(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, char* szAccountName, int bInteractsWithPlayer, unsigned int nToken, unsigned int dwArg, unsigned int nClientInfo)
{
    unsigned char pData[0x2000];
    if (!gnGlobal_007310CC) return 0;
    unsigned int nTotalSize;
    {
    unsigned int nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData + 2, &nSize, 0x2000, bInteractsWithPlayer, dwArg);
    if ((int)nSize <= 0) return 0;
    nTotalSize = nSize + 2;
    }
    *(unsigned short*)pData = (unsigned short)nTotalSize;
    D2ClientStrc* pClient = UnitGetClient(pPlayer, szPlrSaveCppFile_006E09AC, 0xA3B);
    unsigned int nOldChecksum = D2GAME_GetSaveChecksumFromClient_6FC33940(pClient);
    unsigned int nChecksum = D2GAME_SAVE_CalculateChecksum_6FC8A140((D2SaveHeaderStrc*)(pData + 2), nTotalSize - 2);
    int bMatching = nChecksum == nOldChecksum;
    if (bMatching)
    {
        D2SaveHeaderStrc* pOldHeader = CLIENTS_GetSaveHeader(pClient);
        int nOldSize = CLIENTS_GetSaveHeaderSize(pClient);
        D2_ASSERT(pOldHeader, 0xA46);
        bMatching = 1;
        if (nOldSize == nTotalSize - 2)
        {
            const unsigned int nOldVersion = pOldHeader->dwVersion;
            int nOldCheck = 0;
            int nOldLast = 0;
            int nOldPlay = 0;
            int nOldMap = 0;
            if (nOldVersion > 91)
            {
                nOldCheck = pOldHeader->dwChecksum;
                nOldLast = pOldHeader->dwLasTime;
                nOldPlay = pOldHeader->dwPlayTime;
                nOldMap = *(int*)pOldHeader->dwMapSeed;
                pOldHeader->dwChecksum = 0;
                pOldHeader->dwLasTime = 0;
                pOldHeader->dwPlayTime = 0;
                *(int*)pOldHeader->dwMapSeed = 0;
            }
            D2SaveHeaderStrc* pNewHeader = (D2SaveHeaderStrc*)(pData + 2);
            const unsigned int nNewVersion = pNewHeader->dwVersion;
            int nNewCheck = 0;
            int nNewLast = 0;
            int nNewPlay = 0;
            int nNewMap = 0;
            if (nNewVersion > 91)
            {
                nNewCheck = pNewHeader->dwChecksum;
                nNewLast = pNewHeader->dwLasTime;
                nNewPlay = pNewHeader->dwPlayTime;
                nNewMap = *(int*)pNewHeader->dwMapSeed;
                pNewHeader->dwChecksum = 0;
                pNewHeader->dwLasTime = 0;
                pNewHeader->dwPlayTime = 0;
                *(int*)pNewHeader->dwMapSeed = 0;
            }
            for (int i = 0; i < nOldSize; ++i)
            {
                if (((unsigned char*)pOldHeader)[i] != pData[i + 2])
                {
                    bMatching = 0;
                    break;
                }
            }
            if (nOldVersion > 91)
            {
                pOldHeader->dwChecksum = nOldCheck;
                pOldHeader->dwLasTime = nOldLast;
                pOldHeader->dwPlayTime = nOldPlay;
                *(int*)pOldHeader->dwMapSeed = nOldMap;
            }
            if (nNewVersion > 91)
            {
                pNewHeader->dwChecksum = nNewCheck;
                pNewHeader->dwLasTime = nNewLast;
                pNewHeader->dwPlayTime = nNewPlay;
                *(int*)pNewHeader->dwMapSeed = nNewMap;
            }
        }
        else bMatching = 0;
    }
    if (bMatching)
    {
        ++gnGlobal_00883D6C;
        if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUpdate)
        {
            gpD2EventCallbackTable_6FD45830->pfUpdate(&nClientInfo, szName, szAccountName);
        }
        sub_00539320(pClient, nClientInfo);
        return 0;
    }
    sub_00539320(pClient, nClientInfo);
    D2GAME_SetSaveFileChecksum_6FC33970(pClient, nChecksum);
    if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfSaveDatabaseCharacter)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfSaveDatabaseCharacter), 0xADC);
        gpD2EventCallbackTable_6FD45830->pfSaveDatabaseCharacter(&nClientInfo, szName, szAccountName, pData, nTotalSize, nToken);
        CLIENTS_CopySaveDataToClient(pClient, pData + 2, nTotalSize - 2);
    }
    return 1;
}

// 0x00532240
static void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    if (!gnGlobal_007310CC)
    {
        return;
    }

    char szPath[0x400];
    char szFile[0x1F4];
    unsigned char pData[0x2000];
    unsigned int nSize;

    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFile, gszSaveFormat_006D4230, szPath, szName);
    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, dwArg);
    if ((int)nSize <= 0)
    {
        return;
    }

    _iobuf* pFile = fopen(szFile, gszFileModeWb_006D69E0);
    if (pFile)
    {
        fwrite(pData, nSize, 1, pFile);
        fclose(pFile);
    }
    else
    {
        sub_00410610_WriteLogLine(gszSaveOpenError_006E09C4, szFile);
    }
}

// 0x00532340
static __declspec(noinline) void __stdcall sub_00532340_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    unsigned char pData[0x2000];
    unsigned int nSize;

    if (CLIENTS_GetSaveHeader(pClient))
    {
        CLIENTS_FreeSaveHeader(pClient);
    }

    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, 0);
    const int nFileSize = nSize;
    D2_ASSERT(nFileSize > 0, 2866);
    const int nClientId = CLIENTS_GetClientId(pClient);
    CLIENTS_AttachSaveFile(nClientId, pData, nFileSize, nFileSize, 0, 0, 0);
    D2GAME_SetSaveLoadComplete_6FC34300(pClient);
}

// 0x00532400
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg)
{
    if (!pPlayer)
    {
        return 0;
    }

    pPlayer->dwFlagEx &= ~2;

    int bInteractsWithPlayer = 0;
    int nUnitType = 6;
    int nUnitGUID;
    if (sub_00554100(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 0)
    {
        bInteractsWithPlayer = 1;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, szPlrSaveCppFile_006E09AC, 2919);
    char szAccountName[50];
    CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
    unsigned int nToken;
    sub_00539300(pClient, &nToken);
    unsigned int nClientInfo;
    sub_00539310(pClient, &nClientInfo);

    int nResult = 1;
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        sub_00532340_SaveToClient(bInteractsWithPlayer, pGame, pPlayer, pClient);
    }
    else if (gpD2EventCallbackTable_6FD45830)
    {
        nResult = sub_00531EB0_WriteFileOnRealm(pGame, pPlayer, szName, szAccountName, bInteractsWithPlayer, nToken, dwArg, nClientInfo);
    }
    else
    {
        sub_00532240_SaveToLocalFile(bInteractsWithPlayer, (dwArg), pGame, pPlayer, szName);
    }

    return nResult;
}

static __forceinline D2CharStatsTxt* PLRSAVE_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00532520
static void __stdcall sub_00532520_AttachPlayerToClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    CLIENTS_SetPlayerInClient(pClient, pPlayer);
    SUNIT_InitClientInPlayerData(pPlayer, pClient);
    UNITS_SetNameInPlayerData(pPlayer, CLIENTS_GetName(pClient));
    SUNIT_InitSeed(pPlayer, &pGame->pGameSeed);
    UNITS_ChangeAnimMode(pPlayer, PLRMODE_NEUTRAL);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->hTrade = 0;
    pPlayerData->dwTradeState = 0;
    pPlayerData->dwAcceptTradeTick = 0;
    *(int*)pPlayerData->unk0x54 = 0;
}

// 0x00532580
void __cdecl sub_00532580_Empty()
{
}

// 0x00532590
static int __stdcall PLRSAVE_CreateNewPlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer)
{
    sub_6FC32220(pClient);
    const int nClassId = CLIENTS_GetClassId(pClient);
    D2UnitStrc* pPlayer = SUNIT_AllocUnitData(UNIT_PLAYER, nClassId, 0, 0, pGame, 0, 0, 0, 0);
    sub_00532520_AttachPlayerToClient(pGame, pPlayer, pClient);
    sub_00571F90(pGame, pPlayer, pClient);

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    PLAYERSTATS_SetStatsForStartingAct(pGame, pPlayer, nAct);
    PLAYER_CreateStartItemsFromCharStatsTxt(pPlayer, pGame, nAct);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = 0;
    pPlayerData->nRightSkillId = 0;

    if (nAct == ACT_I && pPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE_GetCharStatsTxtRecordInline(pPlayer->dwClassId);
        if (pCharStatsTxtRecord && pCharStatsTxtRecord->wStartSkill && SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, pCharStatsTxtRecord->wStartSkill))
        {
            D2GAME_AssignSkill_6FD13800(pPlayer, 0, pCharStatsTxtRecord->wStartSkill, -1);
            pPlayerData->nRightSkillId = pCharStatsTxtRecord->wStartSkill;
        }
    }

    QUESTS_SequenceCycler(pGame, pPlayer, 1);
    *ppPlayer = pPlayer;
    return 0;
}

static __forceinline int PLRSAVE_ConvertLegacySkill(unsigned char nSkill)
{
 int nId=nSkill;
 if(nId>=156 && nId<=216) nId+=65;
 else if(nId==255) nId=-1;
 return nId;
}

// 0x00532690
int __fastcall PLRSAVE_ReadLegacyHeader(D2GameStrc* pGame,D2ClientStrc* pClient,D2LegacySaveHeaderStrc* pSave,D2UnitStrc** ppPlayer,int* pNewPlayer,unsigned int* pVersion,int* pStats,int* pSkills,int* pLeft,int* pRight,int* pHeaderSize)
{
 char szGuildTag[4];
 *pHeaderSize=0;
 D2LegacySaveHeaderStrc header=*pSave;
 sub_00538630(pClient,0);
 if(header.dwMagic!=0xAA55AA55) {
  if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 0; }
  return 1;
 }
 if(header.nHeaderSize!=130) {
  if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 0; }
  return 14;
 }
 const unsigned int nVersion=header.dwVersion;
 *pVersion=nVersion;
 if(nVersion<71 || nVersion>96) goto invalidVersion;
 {
 header.szName[15]=0;
 char* szName=CLIENTS_GetName(pClient);
 szName[15]=0;
 if(_stricmp(szName,header.szName)) { *pNewPlayer=0;return 1; }
 const unsigned short nSaveFlags=(unsigned short)header.dwFlags;
 unsigned short bExpansion=(unsigned short)header.dwFlags;
 bExpansion &= 0x20;
 if(bExpansion) { if(!pGame->bExpansion) return 24; }
 else if(pGame->bExpansion) return 23;
 if(header.dwFlags & 4) {
  if(header.dwFlags & 8) return 21;
  if(!(ARENA_GetFlags(pGame)&0x800)) return 20;
 } else if(ARENA_GetFlags(pGame)&0x800) return 19;
 const int nProgress=(nSaveFlags>>8)&31;
 if(nProgress<8 && pGame->nDifficulty>1) return 18;
 if((nSaveFlags & 0x20) && nProgress<5 && pGame->nDifficulty>0) return 17;
 if(nProgress<4 && pGame->nDifficulty>0) return 17;
 sub_00539120_SetGuildFlags(pClient,*(int*)header.guildFlags);
 char szGuildName[28];
 memcpy(szGuildTag,header.guildTag,4);
 memcpy(szGuildName,header.guildName,28);
 szGuildTag[3]=0;szGuildName[27]=0;
 sub_00539140_SetGuildTag(pClient,szGuildTag);
 sub_00539170_SetGuildName(pClient,szGuildName);
 sub_005391C0_SetGuildColors(pClient,header.guildColors[0],*(int*)&header.guildColors[1],*(int*)&header.guildColors[2]);
 if(header.dwFlags & 1) {
  *pNewPlayer=1;header.dwFlags &= ~1;
  sub_00538630(pClient,header.dwFlags);
  return 0;
 }
 sub_00539230_SetFlag(pClient,(header.dwFlags>>13)&1);
 const int nClass=header.nClass;
 *pNewPlayer=0;
 CLIENTS_SetClassId(pClient,nClass);
 sub_00538630(pClient,nSaveFlags);
 unsigned char nAct=header.nLocation & 15;
 const unsigned char nDifficulty=header.nLocation>>4;
 if(nAct>=5 || nDifficulty>=3) return 9;
 if(pGame->nGameType==3 && !pGame->InitSeed && pGame->nDifficulty==nDifficulty) pGame->dwInitSeed=header.nMapSeed;
 if(pGame->nDifficulty!=nDifficulty) nAct=0;
 CLIENTS_SetActNo(pClient,nAct);
 *ppPlayer=SUNIT_AllocUnitData(0,nClass,0,0,pGame,0,0,0,0);
 sub_00532520_AttachPlayerToClient(pGame, *ppPlayer, pClient);
 sub_00571F90(CLIENTS_GetGame(pClient),*ppPlayer,pClient);
 *pStats=16;
 *pSkills=sgptDataTables->nSkillsTxtRecordCount;
 if(header.nStats>16 || header.nSkills>sgptDataTables->nSkillsTxtRecordCount) {
  if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 0; }
  return 1;
 }
 if(header.nStats!=16) *pStats=header.nStats;
 if(header.nSkills!=sgptDataTables->nSkillsTxtRecordCount) *pSkills=header.nSkills;
 unsigned char* pHotkey;
 int i;
 for(i=0,pHotkey=&header.hotkeys[0][1];i<8;++i,pHotkey+=2) CLIENTS_SetSkillHotKey(pClient,i,PLRSAVE_ConvertLegacySkill(pHotkey[-1]),*pHotkey,-1);
 *pLeft=PLRSAVE_ConvertLegacySkill(header.nLeftSkill);
 *pRight=PLRSAVE_ConvertLegacySkill(header.nRightSkill);
 *pHeaderSize=header.nHeaderSize;
 return 0;
 }
invalidVersion:
 if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 9; }
 return 1;
}

int __fastcall sub_Emit_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent)
{
    sub_00564CB0_Nop(pItem);
    return sub_00531520_PlaceSavedItem(pGame, pPlayer, pItem, pParent);
}

// 0x00532BE0
int __fastcall sub_00532BE0_ReadQuestData(D2UnitStrc* pPlayer, const D2QuestSaveSectionStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2QuestSaveSectionStrc tSection = *pSection;
    D2QuestSaveSectionStrc* pQuestSection = &tSection;
    if (pQuestSection->dwHeaderMagic != '!ooW')
    {
        return 2;
    }

    if (pQuestSection->dwVersion != 6)
    {
        return 2;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], pQuestSection->pQuestRecord[i], 96, 1);
    }

    *pSize = sizeof(D2QuestSaveSectionStrc);
    return 0;
}

// 0x00532C70
int __fastcall D2GAME_SAVE_ReadWaypointData_6FC8AD50(D2UnitStrc* pUnit, const unsigned char* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2WaypointSaveSectionStrc tSection = *(const D2WaypointSaveSectionStrc*)pSection;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    if (tSection.nMagic != WAYPOINT_MAGIC)
    {
        return SYSERROR_BAD_WAYPOINT;
    }

    int i = 0;
    D2WaypointDataStrc** ppWaypointData = pPlayerData->pWaypointData;
    const D2WaypointSaveRecordStrc* pRecord = tSection.pRecords;
    for (; i < 3; ++i, ++ppWaypointData, ++pRecord)
    {
        if (pRecord->nFlags != 0x102 && pRecord->nFlags != 0x101 && pRecord->nFlags != 0)
        {
            return SYSERROR_BAD_WAYPOINT;
        }

        WAYPOINTS_CopyAndValidateWaypointData(*ppWaypointData, pRecord);
    }

    *pSize = sizeof(D2WaypointSaveSectionStrc);
    return 0;
}

int __fastcall sub_M107_Emit_00532D90(int* pValue, int bClear)
{
    if (bClear)
        return sub_00532D90_ClearValue(pValue);
    return bClear + 1;
}

// 0x00532D00
int __fastcall sub_00532D00_ReadPlayerIntro(D2UnitStrc* pUnit, const D2PlrIntroSaveStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;
    D2PlrIntroSaveStrc plrIntro = *pSection;
    if (plrIntro.nHeader != 0x7701)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    for (int i = 0; i < NUM_DIFFICULTIES; ++i)
    {
        PLRINTRO_CopyBufferToQuestIntroFlags(UNITS_GetPlayerData(pUnit)->pPlayerIntro[i], plrIntro.unk0x04[i]);
        PLRINTRO_CopyBufferToNpcIntroFlags(UNITS_GetPlayerData(pUnit)->pPlayerIntro[i], plrIntro.unk0x1C[i]);
    }

    *pSize = sizeof(D2PlrIntroSaveStrc);
    return 0;
}

// 0x00532D90
static int sub_00532D90_ClearValue(int* pValue)
{
    *pValue = 0;
    return 0;
}

// 0x00532DA0
int __fastcall sub_00532DA0_ReadPlayerStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pData, int nStatCount, int nUnused, int* pSize)
{
    *pSize = 0;
    if (*(unsigned short*)pData != 0x6667) return 4;
    pData += 2;
    struct { int i; int nPresent; } tLoop;
    tLoop.nPresent = 0;
    tLoop.i = 0;
    if (nStatCount > 0) do
    {
        if (pData[(unsigned int)tLoop.i >> 3] & (1 << (tLoop.i & 7)))
        {
            const int nValue = *(int*)&pData[4 * tLoop.nPresent + 3];
            ++tLoop.nPresent;
            STATLIST_SetUnitStat(pUnit, tLoop.i, nValue, 0);
        }
        else
        {
            STATLIST_SetUnitStat(pUnit, tLoop.i, 0, 0);
        }
        ++tLoop.i;
    } while (tLoop.i < nStatCount);
    const int nSize = tLoop.nPresent * 4 + 5;
    if (ARENA_IsInArenaMode(pGame))
    {
        const int nLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, 6, nLife, 0);
        const int nMana = STATLIST_GetMaxManaFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, 8, nMana, 0);
    }
    const int nStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, 10, nStamina, 0);
    *pSize = nSize;
    return 0;
}

// 0x00532F30
int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData)
{
    memset(pSavedItem, 0, sizeof(D2SavedItemStrc));

    D2BitBufferStrc tBitBuffer;
    BITMANIP_Initialize(&tBitBuffer, pData, 0x40);

    pSavedItem->nItemFlags = sub_00411020_ReadBits(&tBitBuffer, 32);

    if (sub_006287A0(pSavedItem->nItemFlags, 0x100000))
    {
        if (sub_006287A0(pSavedItem->nItemFlags, 0x200000))
        {
            pSavedItem->nItemFormat = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 10);
            pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nItemLevel = 1;
            pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);

            if (sub_006287A0(pSavedItem->nItemFlags, 0x10000))
            {
                pSavedItem->nItemCode = 0x20726165;
                pSavedItem->nItemIndex = sub_00411020_ReadBits(&tBitBuffer, 3);
                pSavedItem->nEarLevel = sub_00411020_ReadBits(&tBitBuffer, 8);

                for (unsigned int i = 0; i < 16; ++i)
                {
                    pSavedItem->szName[i] = sub_00411020_ReadBits(&tBitBuffer, 7);
                }
            }
            else
            {
                pSavedItem->nItemCode = sub_00411020_ReadBits(&tBitBuffer, 32);
            }
        }
        else
        {
            pSavedItem->nItemFormat = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 10);
            pSavedItem->nItemCode = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nSocketedItems = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemLevel = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 12);
            pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemQuality = sub_00411020_ReadBits(&tBitBuffer, 4);
            pSavedItem->nQuantity = BITMANIP_ReadSigned(&tBitBuffer, 20);
            pSavedItem->nMinDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
            pSavedItem->nMaxDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
            pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
            pSavedItem->nSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nItemSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);
        }

        pSavedItem->nItemId = DATATBLS_GetItemIdFromItemCode(pSavedItem->nItemCode);
        return sub_00410E90(&tBitBuffer);
    }

    pSavedItem->nItemFormat = 0;

    if (sub_006287A0(pSavedItem->nItemFlags, 0x10000))
    {
        pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
        pSavedItem->nItemLevel = 1;
        BITMANIP_ReadSigned(&tBitBuffer, 10);
        pSavedItem->nItemId = DATATBLS_GetItemIdFromItemCode(0x20726165);
        pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
        pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
        pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
        pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
        pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);
        pSavedItem->nEarLevel = sub_00411020_ReadBits(&tBitBuffer, 8);

        for (unsigned int i = 0; i < 16; ++i)
        {
            pSavedItem->szName[i] = sub_00411020_ReadBits(&tBitBuffer, 7);
            if (!pSavedItem->szName[i])
            {
                break;
            }
        }

        pSavedItem->nItemCode = 0x20726165;
        return 25;
    }

    pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
    pSavedItem->nSocketedItems = sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemLevel = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 12);
    const int nItemId = BITMANIP_ReadSigned(&tBitBuffer, 10);
    pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemQuality = sub_00411020_ReadBits(&tBitBuffer, 4);
    pSavedItem->nQuantity = BITMANIP_ReadSigned(&tBitBuffer, 20);
    pSavedItem->nMinDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
    pSavedItem->nMaxDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
    pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
    pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
    pSavedItem->nSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
    pSavedItem->nItemSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
    pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);

    if (nItemId >= 0)
    {
        pSavedItem->nItemId = DATATBLS_MapOldItemIndexToCurrent(nItemId);

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pSavedItem->nItemId);
        if (pItemsTxtRecord)
        {
            pSavedItem->nItemCode = pItemsTxtRecord->dwCode;
            return 25;
        }
    }

    pSavedItem->nItemCode = 0;
    pSavedItem->nItemId = -1;
    return 25;
}

// 0x00533350
int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    D2ItemKeyStrc keys[0x400];
    struct D2ReadStateStrc { int* pSize; int nUnused; } state;
    D2ReadStateStrc* pState = &state;
    unsigned short nTotal16;
    pState->pSize = pSize;

    if (*(unsigned short*)pSection != 0x4D4A)
        return 14;

    unsigned char* pData = pSection + 2;
    nTotal16 = *(unsigned short*)pData;
    pData += 2;
    int nTotalSize = 4;
    nSize -= 4;
    int nKeys = 0;
    for (unsigned int j = 0; j < nTotal16; ++j)
    {
        D2SavedItemStrc savedItem;
        memset(&savedItem, 0, sizeof(savedItem));
        if (*(unsigned short*)pData != 0x4D4A)
            return 14;

        pData += 2;
        int nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
        nSize -= nDataSize + 2;
        pData += nDataSize;
        nTotalSize += nDataSize + 2;

        for (int k = 0; k < nKeys; ++k)
        {
            if (savedItem.nItemCode == keys[k].nCode && savedItem.nItemIndex == keys[k].nIndex && savedItem.nItemLevel == keys[k].nLevel
                && savedItem.nSeed == keys[k].nSeed && savedItem.nItemSeed == keys[k].nItemSeed)
            {
                for (int s = 0; s < savedItem.nSocketedItems; ++s)
                {
                    memset(&savedItem, 0, sizeof(savedItem));
                    if (*(unsigned short*)pData != 0x4D4A)
                        return 14;

                    pData += 2;
                    nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
                    nSize -= nDataSize + 2;
                    pData += nDataSize;
                    nTotalSize += nDataSize + 2;
                }
                goto next_item;
            }

            keys[nKeys].nCode = savedItem.nItemCode;
            keys[nKeys].nIndex = savedItem.nItemIndex;
            keys[nKeys].nLevel = savedItem.nItemLevel;
            keys[nKeys].nSeed = savedItem.nSeed;
            keys[nKeys].nItemSeed = savedItem.nItemSeed;
            ++nKeys;
        }

        {
            int nCount = 0;
            D2UnitStrc* pItem = 0;
            if (bCorpseItems)
            {
                const int nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &nCount, pPlayer);
                if (nResult)
                    return nResult;
            }
            else
            {
                if (PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &nCount))
                    continue;
            }

            for (int i = 0; i < nCount; ++i)
            {
                memset(&savedItem, 0, sizeof(savedItem));
                if (*(unsigned short*)pData != 0x4D4A)
                    return 14;

                pData += 2;
                nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
                nSize -= nDataSize + 2;
                pData += nDataSize;
                nTotalSize += nDataSize + 2;

                int nResult;
                if (bCorpseItems)
                    nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &pState->nUnused, pPlayer);
                else
                    nResult = PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &pState->nUnused);

                if (nResult)
                    return nResult;
            }
        }
next_item:
        ;
    }

    *pState->pSize = nTotalSize;
    return 0;
}

// 0x005335E0
int __fastcall sub_005335E0(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    unsigned char* pBegin = pSection;
    if (*(unsigned short*)pSection != 0x4D4A)
    {
        return 14;
    }

    pSection += 2;
    const int nItems = *(unsigned short*)pSection;
    pSection += 2;
    for (int i = 0; i < nItems; ++i)
    {
        D2ItemSaveStrc tItemSave;
        int nItemSize;
        int nResult = 0;
        ITEMS_GetCompactItemDataFromBitstream(pSection, nSize - (pSection - pBegin), 1, &tItemSave, dwVersion);
        if (tItemSave.nClassId == -1)
        {
            return 14;
        }

        D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize - (pSection - pBegin), 1, &tItemSave, &nItemSize, dwVersion);
        if (!pItem && nItemSize <= 0)
        {
            return 14;
        }

        pSection += nItemSize;
        if (pItem)
        {
            sub_00564CB0_Nop(pItem);
            if (bCorpseItems)
            {
                nResult = sub_00531520_PlaceSavedItem(pGame, pPlayer, pItem, 0);
            }
            else
            {
                nResult = sub_00531210_PlaceLoadedItem(pGame, pPlayer, pItem, 0);
            }
        }

        const int nSockets = tItemSave.nItemFileIndex;
        D2UnitStrc* pParent = pItem;
        if (nResult)
        {
            if (pItem)
            {
                SUNIT_RemoveUnit(pGame, pItem);
            }
            pParent = 0;
        }

        for (int j = 0; j < nSockets; ++j)
        {
            ITEMS_GetCompactItemDataFromBitstream(pSection, nSize - (pSection - pBegin), 1, &tItemSave, dwVersion);
            D2UnitStrc* pSocketed = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize - (pSection - pBegin), 1, &tItemSave, &nItemSize, dwVersion);
            if (!pSocketed && nItemSize <= 0)
            {
                return 14;
            }

            pSection += nItemSize;
            if (!pParent)
            {
                if (pSocketed)
                {
                    SUNIT_RemoveUnit(pGame, pSocketed);
                }
            }
            else if (pSocketed)
            {
                sub_00564CB0_Nop(pSocketed);
                if (bCorpseItems)
                {
                    sub_00531520_PlaceSavedItem(pGame, pPlayer, pSocketed, pParent);
                }
                else
                {
                    sub_00531210_PlaceLoadedItem(pGame, pPlayer, pSocketed, pParent);
                }
            }
        }

        if (pParent && (ITEMS_GetItemFlags(pParent) & 0x4000000) && !ITEMS_GetRunesTxtRecordFromItem(pParent))
        {
            ITEMMODE_DetachItemFromOwner(pGame, pPlayer, pParent);
        }
    }

    if (pSize)
    {
        *pSize = pSection - pBegin;
    }

    return 0;
}

// 0x005337F0
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize)
{
    int nResult;
    if (nVersion == 0x47)
        nResult = PLRSAVE_ReadLegacyItems(pGame, pUnit, pSection, 0x47, nSize, nUnused, pReadSize);
    else if (nVersion < 0x48 || nVersion > 0x60)
        return 1;
    else
        nResult = sub_005335E0(pGame, pUnit, pSection, nVersion, nSize, nUnused, pReadSize);
    return nResult;
}

// 0x00533850
static int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pUnit, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize)
{
    *pReadSize = 0;
    pData += 12;
    nSize -= 12;

    D2UnitStrc* pPlayer = pUnit;
    pUnit = SUNIT_AllocUnitData(0, !pPlayer ? -1 : pPlayer->dwClassId, 0, 0, pGame, 0, 1, 0x11, 0);
    if (!pUnit)
    {
        return 8;
    }

    pUnit->dwFlags &= ~4;
    {
        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlrSaveFile_006E09AC, 0x1511);
        SUNIT_InitClientInPlayerData(pUnit, pClient);
        char* const szName = CLIENTS_GetName(pClient);
        UNITS_SetNameInPlayerData(pUnit, szName);
    }
    SUNIT_InitSeed(pUnit, &pGame->pGameSeed);
    STATES_ToggleState(pUnit, 7, 1);
    pUnit->dwFlags &= ~0x10;
    INVENTORY_SetOwnerId(pUnit->pInventory, !pPlayer ? -1 : pPlayer->dwUnitId);

    {
        int nRead = 0;
        const int nResult = sub_005337F0_ReadItems(pGame, pUnit, pData, nVersion, nSize, 1, &nRead);
        if (nResult)
        {
            return nResult;
        }

        nSize = nRead + 12;
        INVENTORY_CreateCorpseForPlayer(pPlayer->pInventory, !pUnit ? -1 : pUnit->dwUnitId, 0, 1);
        const int nCorpseId = !pUnit ? -1 : pUnit->dwUnitId;
        const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, nPlayerId, nCorpseId, 1);
        *pReadSize = nSize;
        return 0;
    }
}

// 0x005339A0
int __fastcall PLRSAVE_ReadCorpseSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nRemainingSize, int* pSize)
{
    *pSize = 0;

    if (dwVersion < 71 || dwVersion > 96)
    {
        return 1;
    }

    if (*(unsigned short*)pSection != 'MJ')
    {
        return SYSERROR_UNK_14;
    }

    pSection += 2;
    const unsigned short nCount = *(unsigned short*)pSection;
    pSection += 2;
    nRemainingSize -= 4;
    int nSize = 4;

    for (unsigned int i = 0; i < nCount; ++i)
    {
        int nSectionSize;
        const int nErrorCode = sub_00533850_ReadCorpse(pPlayer, pGame, pSection, dwVersion, nRemainingSize, &nSectionSize);
        if (nErrorCode)
        {
            return nErrorCode;
        }

        nSize += nSectionSize;
        pSection += nSectionSize;
        nRemainingSize -= nSectionSize;
    }

    *pSize = nSize;
    return 0;
}

// 0x00533A60
int __fastcall sub_00533A60_CalcValue(int nA, int nB)
{
    return (nA + 1) * nA * nB * 3;
}

// 0x00533A70
__declspec(noinline) int __fastcall PLRSAVE_GetLegacyHirelingExpFactor(unsigned short nHirelingId, int nLevel)
{
    switch (nHirelingId)
    {
    case 0:
    case 1:
        if (nLevel >= 49)
            return 400;
        return (((nLevel < 25) - 1) & 100) + 100;
    case 2:
    case 3:
        return (((nLevel < 49) - 1) & 220) + 220;
    case 4:
    case 5:
    case 12:
    case 13:
    case 14:
    case 21:
    case 23:
        return 480;
    case 6:
    case 7:
    case 8:
        if (nLevel >= 55)
            return 420;
        return (((nLevel < 31) - 1) & 105) + 105;
    case 9:
    case 10:
    case 11:
        return (((nLevel < 55) - 1) & 230) + 230;
    case 15:
    case 17:
        if (nLevel >= 61)
            return 440;
        return (((nLevel < 37) - 1) & 110) + 110;
    case 16:
        if (nLevel >= 61)
            return 260;
        return (((nLevel < 37) - 1) & 115) + 115;
    case 18:
    case 20:
        return (((nLevel < 61) - 1) & 230) + 230;
    case 19:
        return (((nLevel < 61) - 1) & 240) + 240;
    case 22:
        return 500;
    case 24:
    case 25:
        if (nLevel >= 75)
            return 880;
        return (((nLevel < 42) - 1) & 220) + 220;
    case 26:
    case 27:
        return (((nLevel < 75) - 1) & 460) + 460;
    default:
        return 960;
    }
}

// 0x00533BF0
unsigned int __fastcall PLRSAVE_ConvertLegacyHirelingExperience(D2GameStrc* pGame, unsigned short nHirelingId, unsigned int nSavedExperience)
{
    int nLevel = 1;
    while ((unsigned int)((nLevel + 2) * (nLevel + 1) * PLRSAVE_GetLegacyHirelingExpFactor(nHirelingId, nLevel + 1) * 3) <= nSavedExperience && nLevel + 1 < 99)
        ++nLevel;

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
        return nSavedExperience;

    const unsigned int nExperience = MONSTERS_GetHirelingExpForNextLevel(nLevel, pHirelingTxtRecord->dwExpPerLvl);
    if (nExperience <= nSavedExperience)
        return nSavedExperience;

    return nExperience;
}

// 0x00533C70
static int __stdcall sub_00533C70_ReadLegacyMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int nVersion, unsigned int nSize, int* pSize)
{
    *pSize = 0;
    if (nVersion == 71)
    {
        if (*(unsigned short*)pSection != 0x4D4A)
            return 14;
        const unsigned int nSeed = *(unsigned int*)(pSection + 2);
        if (nSeed)
        {
            const unsigned short nName = *(unsigned short*)(pSection + 6);
            if (nName)
                D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, nName, nSeed, 0xFFFF, 0, 0);
        }
        *pSize = 8;
        goto Done;
    }
    if (nSize < 1)
    {
        sub_00410610_WriteLogLine("Premature end of save data.");
        return 14;
    }
    if (!*pSection)
    {
        *pSize = 1;
        return 0;
    }
    {
        unsigned char* pStart = pSection;
        *pSize = 0;
        if (nSize < sizeof(D2LegacyMercSaveStrc))
        {
            sub_00410610_WriteLogLine("Premature end of save data.");
            return 14;
        }
        D2LegacyMercSaveStrc* pMercSave = (D2LegacyMercSaveStrc*)pSection;
        pSection += sizeof(D2LegacyMercSaveStrc);
        int bDead = pMercSave->dwFlags & 0x10000;
        D2HirelingTxt* pHirelingTxt = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pMercSave->wHirelingId, 1);
        if (!pHirelingTxt)
        {
            sub_00410610_WriteLogLine("Unable to load merc.");
            return 14;
        }
        if (nVersion <= 89)
            pMercSave->dwExperience = PLRSAVE_ConvertLegacyHirelingExperience(pGame, pMercSave->wHirelingId, pMercSave->dwExperience);
        pMercSave->wName += pHirelingTxt->wNameFirst;
        if (pMercSave->wName > pHirelingTxt->wNameLast)
            pMercSave->wName = pHirelingTxt->wNameFirst;
        D2UnitStrc* pMerc = D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, pMercSave->wName, pMercSave->dwSeed, pMercSave->wHirelingId, pHirelingTxt->dwClass, bDead);
        int nRead;
        D2PetInfoStrc petInfo;
        if (!pMerc)
        {
            *pSize = pSection - pStart;
            goto Done;
        }
        else
        {
            petInfo.nSeed = pMercSave->dwSeed;
            petInfo.nName = pMercSave->wName;
            petInfo.nHirelingId = pMercSave->wHirelingId;
            PLAYERPETS_UpdatePetInfo(pPlayer, 7, !pMerc ? -1 : pMerc->dwUnitId, &petInfo);
            STATLIST_UnitGetStatValue(pPlayer, 12, 0);
            const int nMaxLevel = DATATBLS_GetMaxLevel(0);
            int nLevel = 1;
            const unsigned int nExperience = pMercSave->dwExperience;
            if ((unsigned int)STATLIST_UnitGetStatValue(pMerc, 13, 0) < nExperience)
                STATLIST_SetUnitStat(pMerc, 13, nExperience, 0);
            D2GAME_MERCS_SendStat_6FCC61D0(pMerc, 13, nExperience);
            for (;;)
            {
                D2HirelingTxt* pMercStats = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pMercSave->wHirelingId, nLevel);
                if (!pMercStats)
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1660);
                    exit(-1);
                }
                const int nNextLevel = nLevel + 1;
                if (nNextLevel > nMaxLevel)
                    break;
                if (nExperience < MONSTERS_GetHirelingExpForNextLevel(nNextLevel, pMercStats->dwExpPerLvl))
                    break;
                nLevel = nNextLevel;
            }
            MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pMerc, nLevel);
            if (!pMerc->pInventory)
                INVENTORY_AllocInventory(0, pMerc);
            if (bDead)
            {
                sub_6FC7D470(pGame, pPlayer, pMerc);
                pMerc->dwFlags |= 0x10000;
                SUNIT_SetCombatMode(pGame, pMerc, 12);
                sub_005738D0(pGame, pMerc);
            }
            unsigned char* pItems = pSection;
            {
            int nItemsRead;
            int nResult = sub_005337F0_ReadItems(pGame, pMerc, pItems, nVersion, pStart + nSize - pItems, 0, &nItemsRead);
            if (nResult)
                return nResult;
            sub_0055DF00_RecalcItemStates(pGame, pMerc, 0, 0);
            sub_0055F4F0(pGame, pMerc, 0);
            STATLIST_SetUnitStat(pMerc, 6, STATLIST_GetMaxLifeFromUnit(pMerc), 0);
            MONSTERAI_SendMercStats(pGame, pPlayer, 1);
            nRead = pItems + nItemsRead - pStart;
            }
        }
    *pSize = nRead;
    }
Done:
    return 0;
}

// 0x00533F70
int __stdcall sub_00533F70_ReadHotkeySection(D2UnitStrc* pPlayer, const unsigned char* pSection, unsigned int nSize, int* pSize)
{
    *pSize = 0;

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave.cpp", 5793);
    if (!pClient)
    {
        return 0;
    }

    *pSize = 0x30;
    if (nSize <= 0x48)
    {
        return 0;
    }

    const unsigned char* pKey = pSection;
    for (int i = 8; i < 16; ++i)
    {
        int nSkillId = pKey[0];
        if (nSkillId >= 156 && nSkillId <= 216)
        {
            nSkillId += 65;
        }
        else if (nSkillId == 255)
        {
            nSkillId = -1;
        }

        CLIENTS_SetSkillHotKey(pClient, i, nSkillId, pKey[1], -1);
        pKey += 6;
    }

    if (nSize > 0x51)
    {
        const int* pSwitch = (const int*)(pSection + *pSize);
        const int nRightSkillId = pSwitch[1];
        UNITS_SetSwitchLeftSkill(pPlayer, pSwitch[0], -1);
        UNITS_SetSwitchRightSkill(pPlayer, nRightSkillId, -1);
        *pSize += 8;
    }

    return 0;
}

// 0x00534020
int __fastcall D2GAME_SAVE_ProcessSaveFile_6FC8C0C0(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    D2UnitStrc* pLoadedPlayer = 0;
    *ppPlayer = 0;
    if (nSize < 130)
        return 9;
    int bCreateNew, nVersion, nStatCount, nSkillCount, nLeftSkillId, nRightSkillId, nRead;
    int nResult = PLRSAVE_ReadLegacyHeader(pGame, pClient, (D2LegacySaveHeaderStrc*)pSaveFile, &pLoadedPlayer, &bCreateNew, (unsigned int*)&nVersion, &nStatCount, &nSkillCount, &nLeftSkillId, &nRightSkillId, &nRead);
    if (nResult)
        return nResult;
    if (bCreateNew)
        return PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
    D2UnitStrc* pPlayer = pLoadedPlayer;
    *ppPlayer = pPlayer;
    unsigned char* pSection = pSaveFile + nRead;
    nSize -= nRead;
    nResult = sub_00532BE0_ReadQuestData(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = D2GAME_SAVE_ReadWaypointData_6FC8AD50(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = sub_00532D00_ReadPlayerIntro(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = sub_00532DA0_ReadPlayerStats(pGame, pPlayer, pSection, 16, nVersion, &nRead);
    if (nResult)
        return nResult;
    int nHitpoints = STATLIST_UnitGetStatValue(pPlayer, 6, 0);
    int nMana = STATLIST_UnitGetStatValue(pPlayer, 8, 0);
    int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    if (nGold < 0 || nGold > UNITS_GetInventoryGoldLimit(pPlayer))
    {
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == UNIT_PLAYER)
                UNITS_GetInventoryGoldLimit(pPlayer);
            STATLIST_SetUnitStat(pPlayer, 14, 0, 0);
        }
    }
    nGold = STATLIST_UnitGetStatValue(pPlayer, 15, 0);
    if (nGold < 0 || nGold > UNITS_GetStashGoldLimit(pPlayer))
    {
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == UNIT_PLAYER)
                UNITS_GetStashGoldLimit(pPlayer);
            STATLIST_SetUnitStat(pPlayer, 15, 0, 0);
        }
    }
    pSection += nRead;
    nSize -= nRead;
    nResult = sub_6FC8AEC0(pGame, pClient, pPlayer, pSection, nSkillCount, nVersion, &nRead);
    if (nResult)
        return nResult;
    sub_00568DB0(pGame, pPlayer);
    if (nLeftSkillId)
        D2GAME_AssignSkill_6FD13800(pPlayer, 1, nLeftSkillId, -1);
    if (nRightSkillId)
        D2GAME_AssignSkill_6FD13800(pPlayer, 0, nRightSkillId, -1);
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = nLeftSkillId;
    pPlayerData->nRightSkillId = nRightSkillId;
    nSize -= nRead;
    pSection += nRead;
    nResult = sub_005337F0_ReadItems(pGame, pPlayer, pSection, nVersion, nSize, 0, &nRead);
    if (!nResult)
    {
        nSize -= nRead;
        pSection += nRead;
        nResult = PLRSAVE_ReadCorpseSection(pGame, pPlayer, pSection, nVersion, nSize, &nRead);
        if (!nResult)
        {
            nSize -= nRead;
            pSection += nRead;
            nResult = sub_00533C70_ReadLegacyMerc(pGame, pPlayer, pSection, nVersion, nSize, &nRead);
            if (!nResult)
            {
                pSection += nRead;
                nRead = 0;
                sub_00533F70_ReadHotkeySection(pPlayer, pSection, nVersion, &nRead);
            }
        }
    }
    STATLIST_SetUnitStat(pPlayer, 6, nHitpoints, 0);
    STATLIST_SetUnitStat(pPlayer, 8, nMana, 0);
    STATLIST_SetUnitStat(pPlayer, 0x44, 100, 0);
    STATLIST_SetUnitStat(pPlayer, 0x43, 100, 0);
    STATLIST_SetUnitStat(pPlayer, 0x45, 100, 0);
    int nClass;
    if (!pPlayer)
        nClass = -1;
    else
        nClass = pPlayer->dwClassId;
    const int nLevel = STATLIST_GetUnitBaseStat(pPlayer, 12, 0);
    const int nNextExperience = DATATBLS_GetLevelThreshold(nClass, nLevel);
    STATLIST_SetUnitStat(pPlayer, 0x1E, nNextExperience, 0);
    if (CLIENTS_GetWeaponSwitch(pClient))
        D2GAME_PACKETS_SendPacket0x97_6FC3FB60(pClient);
    return 0;
}

// 0x005343A0
static int __stdcall D2GAME_SAVE_ReadFile_6FC8C9D0(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    char szPath[1024];
    char szFileName[500];
    unsigned char saveFile[0x2000];
    D2UnitStrc* pPlayer = 0;
    int nResult = 0;

    *ppPlayer = 0;
    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFileName, gszSaveFormat_006D4230, szPath, szName);

    _iobuf* pSaveFile = fopen(szFileName, gszModeRb_006CDC90);
    if (pSaveFile)
    {
        const unsigned int nFileSize = fread(saveFile, 1, sizeof(saveFile), pSaveFile);
        fclose(pSaveFile);
        if (nFileSize)
        {
            nResult = sub_00534330(pGame, pClient, (D2SaveHeaderStrc*)saveFile, nFileSize, &pPlayer, pRoomArg, nXArg, nYArg);
            if (nResult)
            {
                return nResult;
            }
        }
    }

    *ppPlayer = pPlayer;
    if (!pPlayer)
    {
        nResult = SYSERROR_UNK_14;
    }

    return nResult;
}

// 0x005344B0
static int __stdcall sub_005344B0_ReadSaveFromDisk(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    int nErrorCode = SYSERROR_UNK_14;
    D2UnitStrc* pPlayer = 0;
    if (!gpD2EventCallbackTable_6FD45830)
    {
        nErrorCode = D2GAME_SAVE_ReadFile_6FC8C9D0(pGame, pClient, szName, &pPlayer, pRoomArg, nXArg, nYArg);
        if (pPlayer)
        {
            QUESTS_SequenceCycler(pGame, pPlayer, 0);
        }
    }

    *ppPlayer = pPlayer;
    return nErrorCode;
}

// 0x00534520
static int __stdcall sub_00534520_ReadSaveFromClient(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    *ppPlayer = 0;
    D2SaveHeaderStrc* pSaveHeader = CLIENTS_GetSaveHeader(pClient);
    const int nSaveHeaderSize = CLIENTS_GetSaveHeaderSize(pClient);
    if (!nSaveHeaderSize)
    {
        return SYSERROR_UNK_14;
    }

    const int nErrorCode = sub_00534330(pGame, pClient, pSaveHeader, nSaveHeaderSize, ppPlayer, pRoomArg, nXArg, nYArg);
    if (nErrorCode)
    {
        *ppPlayer = 0;
        return nErrorCode;
    }

    if (*ppPlayer)
    {
        if (pGame->nGameType == GAMETYPE_1 || pGame->nGameType == GAMETYPE_2)
        {
            CLIENTS_FreeSaveHeader(pClient);
        }

        QUESTS_SequenceCycler(pGame, *ppPlayer, 0);
    }

    return 0;
}

// 0x005345A0
int __fastcall D2GAME_SAVE_GetUnitDataFromFile_6FC8CB40(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, int bLoadSave, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    int nErrorCode;
    if (pGame->nGameType != GAMETYPE_1 && pGame->nGameType != GAMETYPE_2 && !gpD2EventCallbackTable_6FD45830)
    {
        if (bLoadSave)
        {
            nErrorCode = sub_005344B0_ReadSaveFromDisk(pGame, pClient, szName, ppPlayer, pRoomArg, nXArg, nYArg);
        }
        else
        {
            nErrorCode = PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
        }
    }
    else
    {
        if (bLoadSave)
        {
            nErrorCode = sub_00534520_ReadSaveFromClient(pGame, pClient, ppPlayer, pRoomArg, nXArg, nYArg);
        }
        else
        {
            nErrorCode = PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
        }
    }

    if (nErrorCode)
    {
        return nErrorCode;
    }

    if (!*ppPlayer)
    {
        return SYSERROR_UNK_14;
    }

    sub_6FD14C30(*ppPlayer);
    return 0;
}

// 0x00534630
int __stdcall D2GAME_10029_SAVE_WriteFileInterface(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    return D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, szName, 0);
}

// 0x00534650
D2UnitStrc* __stdcall sub_00534650_GetServerUnitFromFirstGame(int nUnitType, int nUnitGUID)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    if (!pGame)
    {
        return 0;
    }

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    sub_0052DF40_UnlockFirstGame();
    return pUnit;
}

// 0x00534680
D2DrlgActStrc* __stdcall sub_00534680_GetActFromFirstGame(int nAct)
{
    D2GameStrc* ptGame = sub_0052F6E0_LockFirstGame();
    D2_ASSERT(ptGame, 105);

    D2DrlgActStrc* pAct = ptGame->pAct[nAct];
    sub_0052DF40_UnlockFirstGame();
    return pAct;
}

// 0x00534730
void* __stdcall sub_00534730_ActLookupInFirstGame(unsigned char bAct, int a2, int a3)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    D2_ASSERT(bAct < 5, 141);

    void* pResult = sub_00619DA0_ActLookup(pGame->pAct[bAct], a2, a3);
    sub_0052DF40_UnlockFirstGame();
    return pResult;
}

// 0x005348C0
void __fastcall PLAYER_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPlayerGUID)
{
    D2_ASSERT(pPlayer, 71);

    pPlayer->dwFlags |= UNITFLAG_ISVALIDTARGET | UNITFLAG_CANBEATTACKED | UNITFLAG_TARGETABLE;
    pPlayer->dwUnitId = nPlayerGUID;

    INVENTORY_AllocInventory(0, pPlayer);

    pPlayer->pSkills = SKILLS_AllocSkillList(pGame->pMemoryPool);
    SKILLS_InitSkillList(pPlayer);

    STATLIST_AllocStatListEx(pPlayer, 0, D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910, pGame);
    UNITS_AllocPlayerData(pPlayer);
    sub_00534800_CreatePlayerIntros(pGame, pPlayer);

    SUNIT_InitClientInPlayerData(pPlayer, 0);
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pPlayer);
    ARENA_AllocArenaUnit(pGame, pPlayer);
    PLAYERPETS_AllocPetList(pGame, pPlayer);
    sub_005543B0_AssignAlignment(pPlayer, 2, 1);
}

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00534F10
void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, void* pUnused)
{
    if (!pPlayer)
    {
        return;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        PLAYER_CreateStartItem(pGame, pPlayer, pCharStatsTxtRecord, i, &pCharStatsTxtRecord->pItems[i]);
    }
}

// 0x00534F80
void __fastcall PLAYER_SynchronizeItemsToClient(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit->pInventory, 391);

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(pClient, pUnit, pCheckedItem, 0);
        }
        else if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0) && INVENTORY_GetItemNodePage(pItem) == 1)
        {
            D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(pClient, pUnit, pCheckedItem, 0);
        }
        else if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0) && INVENTORY_GetItemNodePage(pItem) == 2)
        {
            D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(pClient, pUnit, pCheckedItem, 0);
        }
    }
}

// 0x00535060
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        return 1;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 1;
    }

    return UNITS_GetPlayerData(pUnit)->bBusy;
}

// 0x005350B0
void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* ptPlayerInfo = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(ptPlayerInfo->bBusy != 0, 0x1C7);

    ptPlayerInfo->bBusy = 0;
}

// 0x005350F0
void __fastcall sub_6FC7BEC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (pInteractUnit)
        {
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                D2GAME_NPC_ResetInteract_6FCCB4D0(pGame, pUnit, pInteractUnit);
                break;

            case UNIT_OBJECT:
                sub_6FC79B50(pGame, pUnit, pInteractUnit);
                break;

            case UNIT_PLAYER:
                sub_00568760_ResetPlayerInteract(pGame, pUnit);
                break;

            case UNIT_ITEM:
                if (DATATBLS_GetItemsTxtRecord(pInteractUnit->dwClassId)->dwCode == ' xob')
                {
                    sub_6FC92EF0(pGame, pUnit);
                }
                break;
            }
        }
    }

    ACT5Q5_OnPlayerDied(pGame, pUnit);
}

// 0x005352C0
void __fastcall sub_6FC7BFC0(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nPlayerGUID, D2CoordStrc* pCoord)
{
    D2_ASSERT(hRoom, 543);

    COLLISION_GetFreeCoordinatesEx(hRoom, pCoord, 2, COLLIDE_MASK_CORPSE, 4);

    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nPlayerGUID);
    if (!pPlayer)
    {
        return;
    }

    D2Common_10231(pPlayer->pDynamicPath, pPlayer, hRoom, pCoord->nX, pCoord->nY);
    pPlayer->dwFlags |= UNITFLAG_TARGETABLE;

    UNITS_ChangeAnimMode(pPlayer, PLRMODE_DEAD);
    pPlayer->dwFlags &= ~UNITFLAG_ISVALIDTARGET;

    STATES_ToggleState(pPlayer, STATE_PLAYERBODY, 1);
    pPlayer->dwFlags |= UNITFLAG_INITSEEDSET;

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_FREEHOVER, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_STATREGEN, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_TRAP, 0);

    const int nOwnerGUID = INVENTORY_GetOwnerId(pPlayer->pInventory);
    if (nOwnerGUID != -1)
    {
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, nOwnerGUID, nPlayerGUID, 1);
    }
}

// 0x005353F0
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer)
{
    D2_ASSERT(pPlayer, 0x24D);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x250);

    return pPlayerData->dwUniqueId;
}

// 0x00535610
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* a3)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (!pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pPlayer);
            return 0;
        }

        switch (nUnitType)
        {
        case UNIT_PLAYER:
            return sub_00567620(pGame, pPlayer, a3);

        case UNIT_MONSTER:
            return sub_6FC61F20(pInteractUnit, pPlayer);
        }
    }
    else
    {
        if (UNITS_GetPlayerData(pPlayer)->bBusy)
        {
            return 0;
        }
    }

    return sub_00567620(pGame, pPlayer, a3);
}

// 0x00535B10
int __fastcall PLAYER_HasHostilePlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2RosterIterateStrc rosterIterate = {};

    rosterIterate.bFlag = 0;
    rosterIterate.pUnit = pUnit;

    SUNIT_IterateLivingPlayers(pGame, sub_00535AF0_RosterFlagCb, &rosterIterate);
    return rosterIterate.bFlag;
}

// 0x00535BC0
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pEquippedWeapon;
    int nBodyLoc;
    int bIsLeftHandItem;
    INVENTORY_GetEquippedWeapon(pInventory, &pEquippedWeapon, &nBodyLoc, &bIsLeftHandItem);

    if (UNITS_CanDualWield(pUnit))
    {
        D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
        if (pSkill)
        {
            D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
            if (pSkillsTxtRecord)
            {
                D2UnitStrc* pWeapon = 0;
                switch (pSkillsTxtRecord->nWeapSel)
                {
                case 2:
                {
                    const int nFlag = SKILLS_GetFlags(pSkill) & 0x2000;
                    pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
                    D2UnitStrc* pTemp = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    if (!pWeapon || !ITEMSIsA(pWeapon, ITEMTYPE_WEAPON) || pTemp && ITEMSIsA(pTemp, ITEMTYPE_WEAPON) && nFlag)
                    {
                        pWeapon = pTemp;
                    }
                    break;
                }
                case 3:
                {
                    if (((pUnit->dwSeqFrame >> 8) % 2) != 0)
                    {
                        pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    }
                    else
                    {
                        pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
                    }
                    break;
                }
                case 4:
                {
                    pEquippedWeapon = 0;
                    break;
                }
                case 1:
                {
                    pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    break;
                }
                default:
                    pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
                    if (!pWeapon || !ITEMSIsA(pWeapon, ITEMTYPE_WEAPON))
                    {
                        pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
                    }
                    break;
                }

                if (ITEMSIsA(pWeapon, ITEMTYPE_WEAPON) && ITEMS_CanBeEquipped(pWeapon))
                {
                    return pWeapon;
                }
            }
        }
        return pEquippedWeapon;
    }
    return pEquippedWeapon;
}

// 0x00535D10
void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc* pAttacker, int bTemporaryWeaponStats)
{
    if (bTemporaryWeaponStats)
    {
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pAttacker->pInventory);
        if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
        {
            STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 0);
        }

        D2UnitStrc* pSecondaryWeapon = sub_0063BF90_GetSecondaryWeapon(pAttacker->pInventory);
        if (pSecondaryWeapon && pSecondaryWeapon != pLeftHandWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pAttacker, pSecondaryWeapon, 0);
        }
    }

    if (UNITS_CanDualWield(pAttacker))
    {
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pAttacker->pInventory);
        if (!pWeapon)
        {
            if (pLeftHandWeapon)
            {
                if (STATLIST_GetOwner(pLeftHandWeapon, 0))
                {
                    STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 1);
                }
            }
        }
        else if (pWeapon == pLeftHandWeapon)
        {
            D2UnitStrc* pSecondaryWeapon = sub_0063BF90_GetSecondaryWeapon(pAttacker->pInventory);
            if (STATLIST_GetOwner(pLeftHandWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 1);
            }

            if (pSecondaryWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pSecondaryWeapon, 0);
            }
        }
        else
        {
            if (STATLIST_GetOwner(pWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pWeapon, 1);
            }

            if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
            {
                STATLIST_MergeStatLists(pAttacker, pLeftHandWeapon, 0);
            }
        }
    }
}

// 0x00535E20
void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc* pTarget, int bTemporaryWeaponStats)
{
    if (!bTemporaryWeaponStats)
    {
        return;
    }

    D2UnitStrc* pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(pTarget->pInventory);
    if (pLeftHandWeapon && STATLIST_GetOwner(pLeftHandWeapon, 0))
    {
        STATLIST_MergeStatLists(pTarget, pLeftHandWeapon, 1);
    }

    D2UnitStrc* pSecondaryWeapon = sub_0063BF90_GetSecondaryWeapon(pTarget->pInventory);
    if (pSecondaryWeapon && pSecondaryWeapon != pLeftHandWeapon)
    {
        if (STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pTarget, pSecondaryWeapon, 0);
        }
    }
}

static D2NpcRecordStrc* D10_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc)
{
    int nIndex;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
}

// 0x00536510
static void __stdcall sub_00536510_RemoveInventoryItems(D2GameStrc* pGame, D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pUnit = INVENTORY_UnitIsItem(pItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        D2_ASSERT(pUnit, 0x1C6);
        INVENTORY_GetItemNodePage(pItem);
        SUNIT_RemoveUnit(pGame, pUnit);
        pItem = pNext;
    }
}

// 0x00536580
static void __stdcall SUNITPROXY_ClearNpcRecordData(D2NpcRecordStrc* pNpcRecord, D2GameStrc* pGame)
{
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pGamble = pNpcRecord->pGamble;
        while (pGamble)
        {
            D2NpcGambleStrc* pNextGamble = pGamble->pNext;
            if (pGamble->pInventory)
            {
                sub_00536510_RemoveInventoryItems(pGame, pGamble->pInventory);
                INVENTORY_FreeInventory(pGamble->pInventory);
                pGamble->pInventory = 0;
            }
            sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x1E6, 0);
            pGamble = pNextGamble;
        }
        pNpcRecord->pGamble = 0;
    }

    sub_00536510_RemoveInventoryItems(pGame, pNpcRecord->pInventory);
    INVENTORY_FreeInventory(pNpcRecord->pInventory);
    pNpcRecord->pInventory = 0;

    D2NpcEventStrc* pNpcEvent = pNpcRecord->pEvent;
    while (pNpcEvent)
    {
        D2NpcEventStrc* pNextEvent = pNpcEvent->pNext;
        if (pNpcEvent->field_C == 1 && pNpcEvent->pUnit)
        {
            ITEMS_RemoveFromAllPlayers(pGame, pNpcEvent->pUnit);
        }
        sub_0040B480(pGame->pMemoryPool, pNpcEvent, ".\\UNIT\\sunitproxy.cpp", 0x204, 0);
        pNpcEvent = pNextEvent;
    }
    pNpcRecord->pEvent = 0;
}

// build: context SUNITPROXY_FreeNpcControl
void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecords = pNpcControl->pFirstRecord;
    for (int i = 0; i < pNpcControl->nArraySize; ++i)
    {
        D2NpcRecordStrc* pRecord = &pRecords[i];

        D2NpcVendorChainStrc* pVendorChain = pRecord->pVendorChain;
        if (pVendorChain)
        {
            do
            {
                D2NpcVendorChainStrc* pNext = pVendorChain->pNext;
                sub_0040B480(pGame->pMemoryPool, pVendorChain, ".\\UNIT\\sunitproxy.cpp", 0x21E, 0);
                pVendorChain = pNext;
            }
            while (pVendorChain);
            pRecord->pVendorChain = 0;
        }

        SUNITPROXY_ClearNpcRecordData(pRecord, pGame);

        if (pRecord->pItemCache)
        {
            sub_0040B480(pGame->pMemoryPool, pRecord->pItemCache, ".\\UNIT\\sunitproxy.cpp", 0x227, 0);
            pRecord->pItemCache = 0;
        }

        if (pRecord->pPermCache)
        {
            sub_0040B480(pGame->pMemoryPool, pRecord->pPermCache, ".\\UNIT\\sunitproxy.cpp", 0x22C, 0);
            pRecord->pPermCache = 0;
        }

        if (pRecord->pMercData)
        {
            sub_0040B480(pGame->pMemoryPool, pRecord->pMercData, ".\\UNIT\\sunitproxy.cpp", 0x237, 0);
            pRecord->pMercData = 0;
        }

        pRecord->pEvent = 0;
    }

    sub_0040B480(pGame->pMemoryPool, pNpcControl->pFirstRecord, ".\\UNIT\\sunitproxy.cpp", 0x242, 0);
    sub_0040B480(pGame->pMemoryPool, pNpcControl, ".\\UNIT\\sunitproxy.cpp", 0x243, 0);
    pGame->pNpcControl = 0;
}

// build: context SUNITPROXY_FreeVendorChain
void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    D2NpcRecordStrc* pNpcRecord = D10_GetNpcRecordFromUnit(pGame, pNpc);
    if (!pNpcRecord)
    {
        return;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    sub_00536510_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x48F, 0);
                break;
            }

            pPreviousGamble = pGamble;
        }
    }

    D2NpcVendorChainStrc* pPreviousVendorChain = 0;
    for (D2NpcVendorChainStrc* pVendorChain = pNpcRecord->pVendorChain; pVendorChain; pVendorChain = pVendorChain->pNext)
    {
        if (pVendorChain->dwGUID == nPlayerGUID)
        {
            if (pPreviousVendorChain)
            {
                pPreviousVendorChain->pNext = pVendorChain->pNext;
            }
            else
            {
                pNpcRecord->pVendorChain = pVendorChain->pNext;
            }

            sub_0040B480(pGame->pMemoryPool, pVendorChain, ".\\UNIT\\sunitproxy.cpp", 0x4A7, 0);
            return;
        }

        pPreviousVendorChain = pVendorChain;
    }
}

// 0x00536D10
void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc)
{
    SUNITPROXY_ClearNpcRecordData(pNpcRecord, pGame);

    pNpcRecord->bVendorInit = 0;
    pNpcRecord->dwTicks = 0;
    pNpcRecord->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool, 0);

    if (pNpc)
    {
        pNpc->pInventory = pNpcRecord->pInventory;
    }
}

// 0x00537190
void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;

    if (pNpcRecord && pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    sub_00536510_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x5D0, 0);
                return;
            }

            pPreviousGamble = pGamble;
        }
    }
}

// build: context SUNITPROXY_GetVendorState
static __forceinline D2NpcVendorStateStrc* SUNITPROXY_GetVendorState(D2NpcRecordStrc* pNpcRecord)
{
    return (D2NpcVendorStateStrc*)&pNpcRecord->bVendorInit;
}

// 0x00537230
void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bNoMorePlayersInLevel)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecords = pNpcControl->pFirstRecord;
    int i = 0;
    const unsigned int nTickCount = GetTickCount();
    for (; i < pNpcControl->nArraySize; ++i)
    {
        D2NpcRecordStrc* pNpcRecord = &pRecords[i];
        D2NpcVendorStateStrc* pVendor = SUNITPROXY_GetVendorState(pNpcRecord);
        if (pVendor && pVendor->nAct == nAct && pVendor->bTrader == 1 && pNpcRecord->bTrading == 1 && pVendor->bVendorInit == 1)
        {
            if (bNoMorePlayersInLevel)
            {
                D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pNpcRecord->dwNPCGUID);
                if (pNpc && (!pNpc ? -1 : pNpc->dwClassId) == pNpcRecord->nNPC)
                {
                    if (!MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)))
                    {
                        SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, pNpc);
                    }
                    else
                    {
                        pVendor->bRefreshInventory = 1;
                    }
                }
                else
                {
                    SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, 0);
                }
            }
            else
            {
                if (nTickCount > pVendor->dwTicks + 240000)
                {
                    pVendor->bRefreshInventory = 1;
                    pVendor->dwTicks = nTickCount;
                }
            }
        }
    }
}

// 0x00537340
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId)
{
    D2UnitProxyArgStrc unitProxyArg;
    unitProxyArg.nLevelId = nCurrentLevelId;
    unitProxyArg.nCounter = 0;

    switch (nCurrentLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 0, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_LUTGHOLEIN:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 1, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_KURASTDOCKTOWN:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 2, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 3, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_HARROGATH:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 4, unitProxyArg.nCounter == 0);
        break;

    default:
        break;
    }

    switch (nDestLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 0);
        break;

    case LEVEL_LUTGHOLEIN:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 1);
        ACT1Q4_UpdateQuestStateOnActChange(pGame, pUnit);
        break;

    case LEVEL_KURASTDOCKTOWN:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 2);
        break;

    case LEVEL_HARROGATH:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 4);
        break;

    default:
        return;
    }
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

// 0x00537680
void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    D2GAME_INVMODE_First_6FC40FB0(pGame, pNpc, pClient, 0);

    D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNpc);
    if (pGambleInventory)
    {
        D2GAME_INVMODE_First_6FC40FB0(pGame, pNpc, pClient, pGambleInventory);
    }
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

// 0x00538CE0
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7)
{
    int nResult = 0;

    if (!gbClientListInitialized_008846D8)
    {
        return 0;
    }

    EnterCriticalSection(&gClientListLock_008846A8);

    D2ClientStrc* ptClient = gpClientList_008842A8[nClientId & 0xFF];
    while (ptClient)
    {
        if (ptClient->dwClientId == nClientId)
        {
            break;
        }

        ptClient = ptClient->pServerNext;
    }

    if (ptClient)
    {
        void* pDestination = 0;
        if (!ptClient->nSaveHeaderSize)
        {
            ptClient->pSaveHeader = (D2SaveHeaderStrc*)sub_0040B430(ptClient->pGame->pMemoryPool, nTotalSize, ".\\GAME\\Clients.cpp", 2858, 0);
            pDestination = ptClient->pSaveHeader;
        }
        else
        {
            pDestination = (char*)ptClient->pSaveHeader + ptClient->nSaveHeaderSize;
        }

        D2_ASSERT(ptClient->nSaveHeaderSize + nSize <= nTotalSize, 2863);

        memcpy(pDestination, pSaveData, nSize);

        ptClient->nSaveHeaderSize += nSize;
        ptClient->bUnlockCharacter = bUnlockCharacter;

        if (ptClient->nSaveHeaderSize == nTotalSize)
        {
            ptClient->dwFlags |= CLIENTFLAGEX_HAS_SAVE_CHECKSUM;
            ptClient->nSaveChecksum = D2GAME_SAVE_CalculateChecksum_6FC8A140(ptClient->pSaveHeader, ptClient->nSaveHeaderSize);
            nResult = 1;
        }
    }

    LeaveCriticalSection(&gClientListLock_008846A8);
    return nResult;
}

// 0x0053A420
void __fastcall sub_0053A420_RebuildPlayerWithClass(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char nClassId)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    pClient->nClassId = nClassId;
    const int nX = CLIENTS_GetUnitXInline(pPlayer);
    const int nY = CLIENTS_GetUnitYInline(pPlayer);
    const int nUnitId = pPlayer->dwUnitId;
    const int nUnitType = pPlayer->dwUnitType;
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPlayer), nUnitType, nUnitId);
    SUNIT_RemoveUnit(pGame, pPlayer);
    ClientAddPlayerToGame(pClient, pGame, 0, pRoom, nX, nY);
    D2UnitStrc* pClientPlayer = pClient->pPlayer;
    sub_005394A0(pClient, pClientPlayer, pGame, pRoom, nX, nY);
}

// 0x0053A770
void __fastcall LEVEL_RemoveUnitsExceptClientPlayer(D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(hRoom, 132);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(hRoom, &ppRoomList, &nNumRooms);

    D2UnitStrc* hUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2_ASSERT(hUnit, 136);

    const int nUnitType = hUnit->dwUnitType;
    const int nUnitGUID = hUnit->dwUnitId;
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2DrlgDeleteStrc* pDrlgDelete = DUNGEON_GetDrlgDeleteFromRoom(ppRoomList[i]); pDrlgDelete; pDrlgDelete = pDrlgDelete->pNext)
        {
            if (pDrlgDelete->nUnitType != nUnitType || pDrlgDelete->nUnitGUID != nUnitGUID)
            {
                sub_0053BDA0_SendUnitRemoval(pClient, 0x0A, pDrlgDelete->nUnitType, pDrlgDelete->nUnitGUID);
            }
        }
    }
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
void __fastcall LEVEL_RemoveClientFromAdjacentRooms(D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(hRoom, 334);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(hRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        DUNGEON_RemoveClientFromRoom(ppRoomList[i], pClient);
    }
}

// 0x0053FF00
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    const int nNewValue = nValue + STATLIST_UnitGetStatValue(pUnit, nStat, 0);
    if (nNewValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nNewValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case STAT_GOLDBANK:
            if (nNewValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
}

// 0x00540510
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs)
{
    D2_ASSERT(pGame->hParty, 210);

    for (D2PartyStrc* pParty = pGame->hParty->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            if (nPartyId != 0xFFFF)
            {
                for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
                {
                    D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
                    if (pPartyMember)
                    {
                        pCallback(pGame, pPartyMember, pArgs);
                    }
                }
            }
            return;
        }
    }
}

// 0x005489F0
void __fastcall sub_6FC82830(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer != pUnit)
    {
        for (int i = 0; dword_6FD307F8[i] != -1; ++i)
        {
            const int nStatId = dword_6FD307F8[i];
            const int nValue = STATLIST_GetUnitBaseStat(pUnit, nStatId, 0);
            D2GAME_UpdateAttribute_6FC822D0(pUnit, nStatId, nValue, pPlayer);
        }
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

// 0x005531E0
void __fastcall sub_005531E0_FixRoomIfInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (UNITS_IsCurrentRoomInvalid(pUnit))
    {
        int bFlag = 0;
        if (pUnit)
        {
            bFlag = (pUnit->dwFlags >> 4) & 1;
        }

        if (!bFlag)
        {
            sub_00538410_RemoveUnitIfNotAdjacent2(pClient, pUnit);
        }
    }
}

// 0x005538D0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* ptGame, SUNIT_IterateFn pfIterate, void* pArg)
{
    D2UnitStrc** ppSlot = ptGame->pUnitList[0];
    SUNIT_IterateFn pfCallback = pfIterate;
    D2_ASSERT(ptGame && pfCallback, 2022);

    for (int i = 0; i < 128; ++i, ++ppSlot)
    {
        for (D2UnitStrc* ptUnit = *ppSlot; ptUnit; ptUnit = ptUnit->pListNext)
        {
            if (!STATES_CheckState(ptUnit, STATE_PLAYERBODY))
            {
                pfCallback(ptGame, ptUnit, pArg);
            }

            D2_ASSERT(ptUnit, 222);
        }
    }
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
    const int nGroup = (short)pStatesTxtRecord->wGroup;
    const int nCount = sgptDataTables->nStatesTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (i != nStateId)
        {
            if ((short)STATES_GetStatesTxtRecordInline(i)->wGroup == nGroup && STATES_CheckState(pUnit, i))
            {
                nResult = 1;
            }
        }
    }

    return nResult;
}

#include "gen/data/Source/D2Game/PLAYER/PlrSave.inc"
