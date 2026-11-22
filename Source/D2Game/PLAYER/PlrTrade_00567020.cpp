#include "D2ObjectIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2GameAux.h"
#include "D2UnitData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2Constants.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"
#include "D2ObjModes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_OBJECT 2

#define EVENTTYPE_MODECHANGE 0

#define EVENTTYPE_STATREGEN 3

#define OBJECTS_CONSTANT_00552AB0 2

#define UNIT_LIST_SIZE 128

#define WELL_PARAM 2

struct D2TimerArg2Strc;

struct D2MonStatsTxt;

union D2SeedStrc;

struct D2ObjectDataStrc;

struct D2ObjectControlStrc;

struct D2ObjInitFnStrc;

struct D2LevelsTxt;

struct D2ObjectTableStrc;

struct ObjectData;

struct InitContext;

struct D2LvlWarpTxt;

struct D2PlayerDataStrc;

struct D2WarpDelayStrc;

struct D2WarpEventArgStrc;

struct R0052E0F0;

struct R00601DC0;

struct D2TimerArg2Strc
{
    union
    {
        int nUnitGUID;
        int unk0x00;
    };
    D2TimerArg2Strc* pNext;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
    unsigned int dwUnitId;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ObjectTableStrc
{
    int nObjectId;
    int nMin;
    int nMax;
};

extern const D2ObjectTableStrc gaShrineObjectTable_006E1080[6]; // 0x006E1080

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord); // 0x00621BB0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

D2UnitStrc* __fastcall ITEMS_DropGoldAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords); // 0x00559300

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

unsigned char __stdcall DRLG_GetActNoFromLevelId(int); // 0x006427F0

void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc*, unsigned char); // 0x005540A0

int __fastcall ACT2Q6_GetObjectIdForArcaneThing(D2GameStrc* pGame); // 0x0059D830

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct Seed
{
    U32 lo;
    U32 hi;
};

struct Unit
{
    int type;
    int classId;
    void* pool;
    int id;
    int mode;
    ObjectData* data;
    char reserved24[N20];
    Path* path;
    char reserved48[N148];
    U32 flags;
};

struct Room
{
    char reserved0[N108];
    Seed seed;
};

struct InitContext
{
    Game* game;
    Unit* object;
    Room* room;
    Seed* control;
    ObjectRecord* record;
    int x;
    int y;
};

Unit* __stdcall sub_00550A30_Spawn(Game*,int,int,int,Room*,int,int,Permit); // 0x00550A30

U32 __stdcall sub_0061A1B0_Level(Room*); // 0x0061A1B0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall OBJECTS_InitFunction02_Urn(D2ObjInitFnStrc* pOp); // 0x0054FBB0

struct D2WarpDelayStrc
{
    char unk0x00[0xDC];
    unsigned int dwWarpDelay;
};

struct D2WarpEventArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    D2ActiveRoomStrc* pRoom;
    int unk0x0C;
    D2WarpDelayStrc* pDelay;
    int nX;
    int nY;
};

extern "C" const char szSUnitCppFile_006E10F8[]; // 0x006E10F8

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0

int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nDestinationLevel); // 0x00545B80

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc* pRoom, int nSourceLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x006195A0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};

void __stdcall sub_M127_EmitSink(D2UnitStrc* pUnit);

void __fastcall OBJECTS_FreeTimerArg(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg); // 0x0054F580

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

#define GAMEV (game)

struct D2DrlgCoordsStrc;

struct D2ObjectPopulateStrc;

enum
{
    OBJECT_COUNTESSCHEST = 0x173,
};

D2UnitStrc* __fastcall OBJECTS_SpawnPresetChest(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused); // 0x0054F180

static int __stdcall OBJECTS_CanPlaceObject(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY);

struct D2ObjGroupTxt
{
    unsigned int dwId[8];
    unsigned char nDensity[8];
    unsigned char nProbability[8];
    unsigned char nShrines;
    unsigned char nWells;
    unsigned short pad0x32;
};

typedef int (__fastcall* OBJTHEMEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

struct D2ObjectPopulateStrc
{
    int bActive;
    OBJTHEMEFN pfPopulate;
};

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern D2ObjectPopulateStrc gObjectThemeTable_00731E68[7]; // 0x00731E68

extern OBJECTPOPULATEFN sgPopulateTable[10]; // 0x00731D00

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

#define LEVEL_FRIGIDHIGHLANDS 111

struct D2CoordInitStrc;

typedef D2UnitStrc* (__fastcall* PRESETSPAWNFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode);

extern PRESETSPAWNFN sgPresetStuff_00731D28[]; // 0x00731D28

extern int sgnPresetStuffCount_00731D4C; // 0x00731D4C

void __stdcall OBJECTS_SpawnFliesOnCorpse(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00551150

struct D2CoordInitStrc
{
    D2CoordStrc* pCoords;
    int nCount;
};

extern D2CoordInitStrc gaCoordInit_00731EB4[]; // 0x00731EB4

D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom); // 0x00550380

#define ROOM_MIN_SUBTILES 2

#define CREATE_TRIES 5

#define CREATE_SIZE_GROW 6

#define LINE_CREATE_ROOM 1358

#define IFLAG_IDENTIFIED 0x00000010

#define PACKETSIZE06_HEADER 0x92

#define UPDATEUI_TRADEACCEPTED 6

#define TRADESTATE_ACCEPTED 3

#define D2_PAIR_CAPACITY 0x3FF

#define D2S_ERROR_WRITE 3

#define D2S_ERROR_READ_SIZE 0x14

struct D2StaticPathStrc;

struct D2PlayerListStrc;

struct D2ItemTradeStrc;

struct D2PlayerTradeStrc;

struct D2ItemsTxt;

struct D2SkillsTxt;

struct D2UnkPairStrc;

struct D2UnkFieldPairStrc;

struct D2LocalDateStrc;

struct D2PackedWordStrc;

struct D2UnkCallRecordStrc;

struct D2Unk0056DCC0Strc;

typedef void (__fastcall* D2ObjInitFn)(D2ObjInitFnStrc* pOp);

extern D2ObjInitFn sgInitTable[80]; // 0x00731BC0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

D2TimerArgStrc* __fastcall OBJECTS_AllocTimerArg(D2GameStrc* pGame); // 0x0054F520

void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, D2TimerArgStrc* pTimerArg); // 0x006234C0

struct D2UnkPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2UnkFieldPairStrc
{
    char unk0x00[0x80];
    int nValue;
};

struct D2LocalDateStrc
{
    int nDayOfWeek;
    int f_4;
    int nDay;
    int f_C;
};

struct D2UnkCallRecordStrc
{
    void* pArg1;
    void* pArg2;
    int nZero;
    int nArg4;
};

struct D2Unk0056DCC0Strc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    void* pUnk0x20;
};

enum D2C_UnitFlags
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISVALIDTARGET = 0x00000008,
};

enum D2C_ElemTypes
{
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* lpSystemTime); // 0x006CC1D4

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

D2UnitStrc* __fastcall OBJECTS_PopulateFn3_CommonObjects(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability); // 0x00551470

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

int __fastcall PLRSAVE_WriteUnitItems(void* pArg1, void* pArg2, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

void __fastcall sub_0053DA90(D2UnitStrc* pUnit, int nArg); // 0x0053DA90

void __fastcall SCMD_BroadcastPlayerRelationship(D2GameStrc* pGame, int dwPlayerId1, int dwPlayerId2, short wRelationState); // 0x0053DE20

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0

void __fastcall sub_0056DCC0(D2GameStrc* pGame, D2Unk0056DCC0Strc* pRecord); // 0x0056DCC0

int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit); // 0x0058F710

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame); // 0x00626D40

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

void __stdcall sub_0063C550_Return(D2InventoryStrc* pInventory, int nX); // 0x0063C550

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall sub_0063EA70_GetMonsterId(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0063EA70

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AA0

void __stdcall PATH_ClearNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AB0

#define EVENTTYPE_PERIODICSTATS 9

static void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack); // 0x00552200

typedef char (__fastcall* SPAWNCHECKFN)(D2GameStrc* pGame, int nArg, int nX, int nY);

static int __stdcall OBJECTS_CanPlaceObjectWithClearance(D2ActiveRoomStrc*, int, D2DrlgCoordsStrc*, D2CoordStrc*, int); // 0x00550220

extern int gnValues_00731D50[]; // 0x00731D50

extern int gnValues_00731D5C[]; // 0x00731D5C

extern int gnValues_00731D64[]; // 0x00731D64

extern int gnValues_00731D78[]; // 0x00731D78

extern int gnValues_00731D80[]; // 0x00731D80

extern int gnValues_00731B7C[]; // 0x00731B7C

extern int gnValues_00731B9C[]; // 0x00731B9C

extern int gnCount_00731D88; // 0x00731D88

extern int gnCount_00731D8C; // 0x00731D8C

extern int gnCount_00731D90; // 0x00731D90

extern int gnCount_00731D94; // 0x00731D94

extern int gnCount_00731D98; // 0x00731D98

struct D2ItemDropStrc;

D2UnitStrc* __fastcall ITEMS_DropRandomItemNearCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDrop); // 0x00559130

extern int gnArmorStandOrRackIds_00731EA0[];                                                                // 0x00731EA0

extern int gnArmorStandOrRackCount_00731EB0;                                                                // 0x00731EB0

extern int gnCoordInitCount_00731E64;                                                                       // 0x00731E64

extern int gaDirectionX_00731B7C[]; // 0x00731B7C

extern int gaDirectionY_00731B9C[]; // 0x00731B9C

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

#define D2_MAX(a,b) ((a)>(b)?(a):(b))

typedef char (__fastcall* D2ObjectSpawnCallback)(D2GameStrc* pGame, int nArg, int nX, int nY);

typedef bool (__fastcall* OBJRGN_SpawnCheckFn)(D2GameStrc* pGame, int nLevelId, int nX, int nY);

bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId); // 0x00547300

bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY); // 0x005473A0

void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY); // 0x00547400

D2UnitStrc* __stdcall sub_00550540_SpawnObjectInBox(D2GameStrc* pGame, int nObjectId, int nWidth, int nHeight, D2ActiveRoomStrc* pRoom, int nLevelId, OBJRGN_SpawnCheckFn pfnCheck); // 0x00550540

extern int gnBarrelXOffsets_00731B7C[8]; // 0x00731B7C

extern int gnBarrelYOffsets_00731B9C[8]; // 0x00731B9C

extern int gnObjectIds_00731D64[]; // 0x00731D64

D2UnitStrc* __fastcall OBJECTS_PopulateFn7_RogueOnStick(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

Unit* __fastcall OBJECTS_PopulateFn2_WaypointShrine(Game* game,Room* room,int unusedGroup,int classId,unsigned short probability);

int __fastcall OBJECTS_SpawnBarrel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

int __fastcall OBJECTS_SpawnRandomItemGrid(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

static int gnObjectCount_00731D90; // 0x00731D90

static int __stdcall OBJECTS_PopulateRoomTheme(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned int nThemes, D2ObjectRegionStrc* pObjectRegion);

static int __stdcall OBJECTS_CanPopulateRoom(D2GameStrc* pGame, D2LevelsTxt* pLevelsTxtRecord, D2ActiveRoomStrc* pRoom);

void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);

static int __stdcall OBJECTS_GetShrineId(Game* game,U32 level,Room* room,unsigned char category);

void __fastcall OBJECTS_InitFunction01_Shrine(InitContext* context);

static void __cdecl OBJECTS_ApplySubclassClassId(Unit* unit);

struct Data00552D60 { unsigned char bUnknown00[0x50]; unsigned int dwValue50; };

struct Unit00552D60 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00552D60* pData;
};

void __stdcall DUNGEON_GetRoomCoordinates_Local(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);

int __stdcall SKILLS_Return1(int nArg)
{
    return 1;
}

int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

int __fastcall SKILLS_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall MISSILE_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall SKILLS_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __fastcall MISSILE_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// build: symbol ?SKILLS_ScaleUpDirection@* 0x004C5390
void __fastcall SKILLS_ScaleUpDirection(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

// 0x00567020
void __fastcall PLRTRADE_SetTradeAccepted(D2UnitStrc* pPlayer, int nUnused, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData)
{
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2422), UPDATEUI_TRADEACCEPTED);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 2423), UPDATEUI_TRADEACCEPTED);

    pPlayerData->dwTradeState = TRADESTATE_ACCEPTED;
    pInteractPlayerData->dwTradeState = TRADESTATE_ACCEPTED;
}
