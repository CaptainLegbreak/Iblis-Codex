#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
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

#define STAT_GOLD 14

#define ITEMACTION_DROPTOGROUND 2

#define ITEMACTION_ONGROUND 3

#define ACT_II 1

#define ACT_III 2

#define EVENTTYPE_REMOVESTATE 12

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

static D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem); // 0x00530F40

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

static int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize);

extern D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8
extern int gbClientListInitialized_008846D8; // 0x008846D8
extern D2ClientStrc* gpClientList_008842A8[256]; // 0x008842A8
#define CLIENTFLAGEX_HAS_SAVE_CHECKSUM 0x08
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
