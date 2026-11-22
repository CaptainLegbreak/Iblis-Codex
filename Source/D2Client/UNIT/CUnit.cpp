#include "D2StateIds.h"
#include "D2Client.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2Drlg.h"
#include "D2ClientMenus.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Unicode.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2ObjModes.h"
#include "D2CelContext.h"

struct D2DynamicPathStrc;

struct D2UnitTargetStrc;

#define MONSTATS2FLAGINDEX_ISATT 9

#define UNITFLAG_CANBEATTACKED 0x00000004

#define UNITFLAG_ISDEAD 0x00010000

#define UNIT_HASH_BUCKETS 0x80

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define gpUnitTable_007A5670 (gpUnitHashTable_007A5270 + 2 * UNIT_HASH_BUCKETS)

#define gpUnitTable_007A6270 (gpUnitHashTable_007A5E70 + 2 * UNIT_HASH_BUCKETS)

#define SKILLSFLAGINDEX_PERIODIC 38

struct D2PacketListStrc;

struct D2PlayerDataStrc;

struct D2MapAIStrc;

struct D2StaticPathStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2SkillsTxt;

struct D2SetsTxt;

struct D2SetItemsTxt;

struct D2UniqueItemsTxt;

struct D2HotkeyStrc;

struct Unicode;

struct D2ObjectDataStrc;

struct D2DrlgCoordsStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2ObjectsTxt;

struct D2LevelsTxt;

struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2ItemsTxt;

struct D2PresetUnitStrc;

struct D2ModeArgStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2UnitStrc* gpPlayerUnit_007A6A70; // 0x007A6A70

extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634

D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80]; // 0x007A5270

D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80]; // 0x007A5E70

void __fastcall sub_00480810_OnUnitA(D2UnitStrc* pUnit); // 0x00480810

void __fastcall sub_0046D780(D2UnitStrc* pUnit); // 0x0046D780

char __fastcall sub_004BDEE0(D2UnitStrc* pUnit); // 0x004BDEE0

int __fastcall sub_0046F1F0_GetGfx34(D2GfxDataStrc* pGfxData); // 0x0046F1F0

int __fastcall sub_0046F250_GetGfx38(D2GfxDataStrc* pGfxData); // 0x0046F250

D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

int __fastcall sub_004BC5E0_UpdateEnvObject(D2UnitStrc* pUnit, int nArg); // 0x004BC5E0

void __fastcall sub_00480420_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

unsigned short __fastcall sub_00479C00_LookupPartyNumber(D2UnitStrc* pUnit); // 0x00479C00

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce); // 0x00461250

void __cdecl sub_00466FE0(); // 0x00466FE0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

void __cdecl sub_004DBFE0_StopSkill(); // 0x004DBFE0

void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged); // 0x0061ACD0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DATATBLS_GetNoPerFromLevelsTxt(int nLevelId); // 0x0061DBE0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20

void __cdecl AUTOMAP_SkipAutomapReveal(); // 0x00459140

void __fastcall sub_00472C20_PlayerMoved(int nArg); // 0x00472C20

int __stdcall D2Common_11020(D2UnitStrc* pUnit); // 0x00645630

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[]; // 0x00711F34

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __fastcall sub_M210_EmitTest(D2UnitStrc* pPlayer, D2UnitStrc* pUnit);

int __fastcall sub_M210_EmitUse(D2UnitStrc* pUnit);

struct D2SetsTxt { char unk0x000[0x128]; };

#pragma pack(push, 2)

#pragma pack(pop)

enum
{
    NUM_HOTKEYS = 114,
};

typedef int (__stdcall* D2FarProcFn)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_004743D0_ReleaseOverlayResource(D2GfxLightStrc* pLight); // 0x004743D0

void __cdecl TEXT_ResetTextBox(); // 0x0049F960

int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern int gdwGlobal_007BCBF0; // 0x007BCBF0

extern int gnGlobal_00721E34; // 0x00721E34

extern int gnGlobal_00721E3C; // 0x00721E3C

extern int gnGlobal_00721E40; // 0x00721E40

extern int gnGlobal_00721E44; // 0x00721E44

extern int gnGlobal_00721E48; // 0x00721E48

extern int gnGlobal_00721E4C; // 0x00721E4C

extern int gnGlobal_00721E50; // 0x00721E50

extern int gdwGlobal_007BCBE4; // 0x007BCBE4

extern int gdwGlobal_007BCBE8; // 0x007BCBE8

extern int gdwGlobal_007BCBF4; // 0x007BCBF4

extern int gdwGlobal_007BCBF8; // 0x007BCBF8

extern D2TextHeaderStrc* gpTextHeader_007BF250; // 0x007BF250

extern int gnGlobal_007C0E7C; // 0x007C0E7C

extern unsigned char* gpDDrawDebugFontGlyphs_008815AC; // 0x008815AC

extern void* gpReply_008818D0; // 0x008818D0

extern "C" void* gpCDKeyHandle_00882744; // 0x00882744

extern "C" void* gpCDKeyHandle_00882750; // 0x00882750

const Unicode* __fastcall sub_00463810_GetMonsterName(D2UnitStrc* pUnit); // 0x00463810

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

const Unicode* __fastcall sub_00464A30_GetWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pTile); // 0x00464A30

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000

void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0

void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0

D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

struct D2ModeArgStrc
{
    int nValue;
};

static inline void sub_00464E20_PlayOverlaySound(D2UnitStrc* pUnit, int nOverlay);

static void sub_004667F0_SpawnPresetUnitInRoom(D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit);

int gnPeriodOfDay_007A6A74; // 0x007A6A74

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

struct D2RectStrc;

struct D2CoordPairStrc;

struct D2MonStats2SelectStrc;

void __cdecl UI_FreePlayerUI(); // 0x00453DE0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

void __fastcall sub_0044BEA0_SetValue(int nValue); // 0x0044BEA0

void __cdecl UI_LoadPlayerUI(); // 0x00453D90

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall sub_004DAE60_UnitSupportsMode(D2UnitStrc* pUnit, int nMode); // 0x004DAE60

int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit); // 0x004DA0D0

int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit); // 0x004DA0F0

static int __stdcall sub_004640A0_GetUnitSelectRect(D2UnitStrc* pUnit, int nMode, D2RectStrc* pRect, unsigned int nFrame);

extern "C" __declspec(dllimport) int __stdcall PtInRect(const D2RectStrc*, D2CoordPairStrc);

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_0045AE90(); // 0x0045AE90

int __fastcall sub_00451F30(D2UnitStrc*,unsigned int); // 0x00451F30

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc*); // 0x00621190

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*,int*,int*,int*,const char*,int); // 0x00645270

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

int __fastcall sub_00470860_HitTestUnitGfx(D2UnitStrc*,int,int,int,int); // 0x00470860

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

int __fastcall sub_00463EE0_IsPointInTileRect(D2UnitStrc*,int,int); // 0x00463EE0

int __fastcall sub_004DB670_UpdateUnitGfx(D2UnitStrc*,int); // 0x004DB670

D2WheelCallbackFn gpfnWheelUp_007A7404; // 0x007A7404

D2WheelCallbackFn gpfnWheelDown_007A7408; // 0x007A7408

D2UnitStrc* gpAiTargets_007A7470[1]; // 0x007A7470

int gnGlobal_007BCE2C; // 0x007BCE2C

static int __stdcall sub_00464310_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer);

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);

#define gpUnitTable_007A5470 (gpUnitHashTable_007A5270 + 1 * 0x80)


#define gpUnitTable_007A5870 (gpUnitHashTable_007A5270 + 3 * 0x80)

#define gpUnitTable_007A5E70 (gpUnitHashTable_007A5E70 + 0 * 0x80)

#define gpUnitTable_007A6070 (gpUnitHashTable_007A5E70 + 1 * 0x80)


#define gpUnitTable_007A6470 (gpUnitHashTable_007A5E70 + 3 * 0x80)

#define gpUnitTable_007A6670 (gpUnitHashTable_007A5E70 + 4 * 0x80)

struct D2GfxLightStrc;

union D2SeedStrc;

struct D2UnitSpawnExtraStrc;

struct D2UnitSpawnStrc;

struct D2UnitSpawnExtraStrc
{
    int nArg10;
    int nArg14;
};

struct D2UnitSpawnStrc
{
    unsigned int nUnitId;
    int nClassId;
    int nX;
    int nY;
    D2UnitSpawnExtraStrc tExtra;
    int nMode;
};

extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634

D2GfxLightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2); // 0x00643A00

void __stdcall sub_004DA080_FreeGfxMotion(D2UnitStrc* pUnit); // 0x004DA080

void __fastcall sub_004CA9C0_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce); // 0x004CA9C0

void __fastcall sub_004AED30_FreeClientUnit(D2UnitStrc* pUnit); // 0x004AED30

void __fastcall sub_004C1A70_ReleaseItemUnit(D2UnitStrc* pUnit); // 0x004C1A70

void __fastcall sub_004BCA50_ReleaseUnit(D2UnitStrc* pUnit); // 0x004BCA50

void __fastcall sub_004CD170_FreeMissileUnit(D2UnitStrc* pMissile); // 0x004CD170

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

void __fastcall sub_004DC0C0_FreeCltUnitEvents(D2UnitStrc* pUnit); // 0x004DC0C0

void __fastcall sub_0045F9F0_FreePacketBuffer(void* pArg); // 0x0045F9F0

void __fastcall sub_004879D0(D2UnitStrc* pUnit); // 0x004879D0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0

int __cdecl sub_0044DCC0(); // 0x0044DCC0

D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomBySubtile(int nX, int nY); // 0x00465420

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall sub_004CD0A0(D2UnitStrc* pMissile, D2ActiveRoomStrc* pRoom, int nTargetX, int nTargetY, int nUnused); // 0x004CD0A0

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620AE0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x0064C350

void __fastcall sub_004DC510_InitGfxData(D2UnitStrc* pUnit); // 0x004DC510

void __fastcall sub_004BC8D0_UpdateObjectOverlay(D2UnitStrc* pUnit); // 0x004BC8D0

D2UnitStrc* __fastcall sub_00466360_AddClientMonster(D2UnitSpawnStrc* pSpawn, void* pArg2, unsigned char* pArg3, int nArg4, int nArg5, int nArg6); // 0x00466360

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

void __stdcall sub_00463CC0_FreeUnitTable(D2UnitStrc** ppTable); // 0x00463CC0

void __fastcall sub_00463D80_OnUnitB(D2UnitStrc* pUnit); // 0x00463D80

void __fastcall sub_00465070_OnUnitC(D2UnitStrc* pUnit); // 0x00465070

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int id); // 0x0045C4B0

int __fastcall sub_00479150_FindRosterIndex(int unitId); // 0x00479150

extern const unsigned char gnSkillMask_006CE26C; // 0x006CE26C

static D2UnitStrc* sub_00465F20_InsertUnit(D2UnitStrc* pUnit);

static D2UnitStrc* __stdcall sub_00463940_FindUnitInTable(int nHash, unsigned int nUnitId, D2UnitStrc** ppTable, int nUnitType);

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int sub_00463A50_AddUnitToTable(D2UnitStrc* pUnit); // 0x00463A50

void __fastcall sub_004643F0_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId);

static int __stdcall sub_00464D20_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit);

static int __stdcall sub_00464D90_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem);

static void sub_00465870_FreeUnit(D2UnitStrc* pUnit);

void __cdecl sub_004659C0_FreeAllUnits();

static void sub_00465E80_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash);

void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType);

void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType);

void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner);

static D2UnitStrc* __stdcall sub_00465FD0_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX);

D2UnitStrc* __fastcall sub_00466200_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName);

D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5);

D2UnitStrc* __fastcall sub_00466300_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType);

void __fastcall sub_00463D90_SetPlayerUnit(D2UnitStrc* pUnit);

// build: context UNITS_GetMonStats2TxtRecordFromMonsterId_Inl
inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

static inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag);

static inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag);

// 0x004638A0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x00463900
int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

// 0x00463940
static D2UnitStrc* __stdcall sub_00463940_FindUnitInTable(D2UnitStrc** ppTable, unsigned int nUnitId, int nHash, int nUnitType)
{
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
    }
    return 0;
}

// 0x00463990
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType)
{
    return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

// 0x004639B0
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId, nUnitId & 0x7F, nUnitType);
}

// 0x004639D0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x83);
    if (UNIT_HasFlagEx(pUnit, 0x400))
    {
        const int nOwnerType = pUnit->dwOwnerType;
        const unsigned int nOwnerGUID = pUnit->dwOwnerGUID;
        const int nHash = nOwnerGUID & 0x7F;
        if (nOwnerType == 3)
        {
            return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5270[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
        }
        return sub_00463940_FindUnitInTable(&gpUnitHashTable_007A5E70[nOwnerType * 0x80], nOwnerGUID, nHash, nOwnerType);
    }
    return 0;
}

// 0x00463B80
static void sub_00463B80_QueueIdleMove(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nMode = pUnit->dwAnimMode;
        if (UNITS_GetRoom(pUnit))
        {
            switch (nMode)
            {
            case PLRMODE_NEUTRAL:
            case PLRMODE_TOWNNEUTRAL:
                sub_00461250_QueueMove(7, pUnit, 0, 1);
                break;
            }
        }
    }
}


// 0x00463C70
void __cdecl sub_00463C70()
{
    for (int i = 0; i < 6 * 0x80; ++i) gpUnitHashTable_007A5E70[i] = 0;
    for (int i = 0; i < 6 * 0x80; ++i) gpUnitHashTable_007A5270[i] = 0;
}

// 0x00463C90
static void __stdcall sub_00463C90_ForEachUnitInTable(D2UnitStrc** ppTable, UNITFN pfnCallback)
{
    for (int i = 0; i < 0x80; ++i)
    {
        D2UnitStrc* pUnit = ppTable[i];
        while (pUnit)
        {
            D2UnitStrc* pNext = pUnit->pListNext;
            pfnCallback(pUnit);
            pUnit = pNext;
        }
    }
}

// build: context CLIENT_FindUnitInHashTable_Inl
static inline D2UnitStrc* CLIENT_FindUnitInHashTable_Inl(int nUnitId, int nUnitType)
{
    D2UnitStrc* pUnit = gpUnitHashTable_007A5270[(nUnitType << 7) + (nUnitId & 0x7F)];
    while (pUnit)
    {
        if (pUnit->dwUnitId == nUnitId)
        {
            D2_ASSERT(pUnit->dwUnitType == nUnitType, 0x5A);
            return pUnit;
        }
        pUnit = pUnit->pListNext;
    }
    return 0;
}

// 0x00463CC0
void __stdcall sub_00463CC0_FreeUnitTable(D2UnitStrc** ppTable)
{
    for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
    {
        D2UnitStrc* pUnit = ppTable[i];
        while (pUnit)
        {
            D2UnitStrc* pNext = pUnit->pListNext;
            const int nUnitId = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            sub_00480810_OnUnitA(pUnit);
            D2UnitStrc* pFound = CLIENT_FindUnitInHashTable_Inl(nUnitId, nUnitType);
            if (pFound)
            {
                if (pFound->dwUnitType == UNIT_MONSTER)
                {
                    sub_0046D780(pFound);
                }
                else if (pFound->dwUnitType == UNIT_OBJECT)
                {
                    sub_004BDEE0(pFound);
                }
            }
            pUnit = pNext;
        }
    }
}

static inline int CUNIT_GetUnitClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x00463D90
void __fastcall sub_00463D90_SetPlayerUnit(D2UnitStrc* pUnit)
{
    if (gpPlayerUnit_007A6A70)
    {
        UI_FreePlayerUI();
    }

    if (pUnit)
    {
        sub_006488A0_SetDirection(pUnit->pDynamicPath, 0);
        gnCharClass_007A0522 = (unsigned char)CUNIT_GetUnitClassId(pUnit);
        sub_0044BEA0_SetValue(0);
        UI_LoadPlayerUI();
    }

    gpPlayerUnit_007A6A70 = pUnit;
}

// 0x00463DE0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit()
{
    return gpPlayerUnit_007A6A70;
}

// 0x00463DF0
int __cdecl sub_00463DF0()
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (!pPlayer)
    {
        return 1;
    }
    return pPlayer->dwAnimMode == PLRMODE_DEAD;
}

// 0x00463E20
void __fastcall sub_00463E20_SetGfxField34(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0x563);
    sub_0046F1C0(pUnit->pGfxData, nValue);
}

// 0x00463E50
int __fastcall sub_00463E50_GetGfxField34(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x56C);
    return sub_0046F1F0_GetGfx34(pUnit->pGfxData);
}

// 0x00463E80
void __fastcall sub_00463E80_SetGfxField38(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0x575);
    sub_0046F220(pUnit->pGfxData, nValue);
}

// 0x00463EB0
int __fastcall sub_00463EB0_GetGfxField38(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x57E);
    return sub_0046F250_GetGfx38(pUnit->pGfxData);
}

// build: context UNITS_InlineGetXPosition
inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// build: context UNITS_InlineGetYPosition
inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static int __stdcall sub_00463FE0_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, D2UnitStrc* pUnit, int nX)
{
    int nUnitX = UNITS_InlineGetXPosition(pUnit);
    int nUnitY = UNITS_InlineGetYPosition(pUnit);
    DUNGEON_GameSubtileToClientCoords(&nUnitX, &nUnitY);

    const int nLeft = pObjectsTxtRecord->dwLeft + nUnitX;
    const int nTop = pObjectsTxtRecord->dwTop + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= pObjectsTxtRecord->dwWidth + nLeft && nY <= pObjectsTxtRecord->dwHeight + nTop)
    {
        return 1;
    }

    return 0;
}

// 0x004640A0
static int __stdcall sub_004640A0_GetUnitSelectRect(D2UnitStrc* pUnit, int nMode, D2RectStrc* pRect, unsigned int nFrame)
{
    if (sub_004DAE60_UnitSupportsMode(pUnit, nMode))
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));

        int nOut;
        if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, nMode, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2CelStrc* pCell = tContext.pCel;
            if (pCell)
            {
                D2_ASSERT(nFrame <= tContext.nFrames, 0x5DF);

                pRect->nLeft = (CelGetOffsetX(pCell) - 12) + UNITS_GetClientCoordX(pUnit);
                pRect->nRight = CelGetWidth(pCell) + pRect->nLeft + 24;
                pRect->nTop = CelGetOffsetY(pCell) + UNITS_GetClientCoordY(pUnit) + 12;
                pRect->nBottom = pRect->nTop - CelGetHeight(pCell) - 24;

                const int nTop = pRect->nTop;
                const int nWidth = pRect->nRight - pRect->nLeft;
                if (nWidth < 32)
                {
                    pRect->nLeft -= (32 - nWidth) >> 1;
                    pRect->nRight = ((32 - nWidth) >> 1) + pRect->nRight;
                }

                const int nHeight = nTop - pRect->nBottom;
                if (nHeight < 32)
                {
                    const int nPad = (32 - nHeight) >> 1;
                    pRect->nTop = nTop + nPad;
                    pRect->nBottom -= nPad;
                }

                const int nGfxOffsetX = sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
                const int nGfxOffsetY = sub_004DA0D0_GetGfxMotionField38(pUnit) + sub_004DA0F0_GetGfxMotionField3C(pUnit);
                pRect->nLeft += nGfxOffsetX;
                pRect->nRight += nGfxOffsetX;
                pRect->nTop += nGfxOffsetY;
                pRect->nBottom += nGfxOffsetY;
                return 1;
            }
        }
    }

    return 0;
}

// 0x00464210
int __fastcall sub_00464210_SkillSelectProc1(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11021(pTarget);
}

void __fastcall sub_M109_Emit_00464E20(D2UnitStrc* pUnit, int nOverlay)
{
    if (pUnit)
        sub_00464E20_PlayOverlaySound(pUnit, nOverlay);
}

// 0x00464220
int __fastcall sub_00464220_SkillSelectProc2(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

// 0x00464230
int __fastcall sub_00464230_SkillSelectProc3(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (!pTarget)
        return 0;
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
        return 0;
    if (!sub_004B11F0(pTarget))
        return 0;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return 0;
    int nClass = sub_00463860(pTarget);
    if (nClass >= 0 && nClass < sgptDataTables->nMonStatsTxtRecordCount && nClass == 0x4E)
        return 0;
    return 1;
}

// 0x00464280
int __fastcall sub_00464280_SkillSelectProc4(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11018(pTarget);
}

// 0x00464290
int __fastcall sub_00464290_SkillSelectProc6(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2Common_11020(pTarget);
}

// 0x004642A0
int __fastcall sub_004642A0_SkillSelectProc5(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    return D2COMMON_11019(pTarget);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

// 0x00464310
static int __stdcall sub_00464310_CheckMonsterSkillSelect(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetLeftSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1674)))
        return 1;

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pUnit, SKILLS_GetSkillIdFromSkill(UNITS_GetRightSkill(pPlayer), ".\\UNIT\\CUnit.cpp", 1678)) != 0;
}

// 0x00464370
int __fastcall sub_00464370_IsSelectedUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pSelected = sub_00467A10();
    if (pSelected && pSelected->dwUnitType == UNIT_OBJECT && (DATATBLS_GetObjectsTxtRecord(pSelected->dwClassId)->nSubClass & 0x80))
    {
        return 0;
    }
    return sub_00467A10() == pUnit;
}

// 0x004643B0
int __fastcall sub_004643B0_IsPlayerOrMonster(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x793);
    const int nType = pUnit->dwUnitType;
    return nType == 0 || nType == 1;
}

static int sub_00463A50_AddUnitToTable(D2UnitStrc* pUnit)
{
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        if (sub_004639B0_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!sub_004639B0_FindServerSideUnit(pUnit->dwUnitId, pUnit->dwUnitType), 0x9C);
    }
    else
    {
        if (sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType))
        {
            return 0;
        }
        D2_ASSERT(!sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType), 0xA5);
    }

    sub_004CC160(pUnit, 1);

    const unsigned int nUnitId = pUnit->dwUnitId;
    const int nHash = nUnitId & 0x7F;
    D2UnitStrc** ppTable;
    if (UNIT_HasFlag(pUnit, 0x200000))
    {
        ppTable = &gpUnitHashTable_007A5270[pUnit->dwUnitType * 0x80];
    }
    else
    {
        ppTable = &gpUnitHashTable_007A5E70[pUnit->dwUnitType * 0x80];
    }

    D2UnitStrc* pNext = ppTable[nHash];
    D2UnitStrc* pPrev = 0;
    while (pNext && pNext->dwUnitId > nUnitId)
    {
        pPrev = pNext;
        pNext = pNext->pListNext;
    }

    pUnit->pListNext = pNext;
    if (pPrev)
    {
        pPrev->pListNext = pUnit;
    }
    else
    {
        ppTable[nHash] = pUnit;
    }

    return 1;
}

// 0x004643F0
void __fastcall sub_004643F0_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId)
{
    UNITS_SetTargetUnitForDynamicUnit(pUnit, sub_00463990(nUnitId, nUnitType));
}

static inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x00464420
void __fastcall sub_00464420_TurnTowardPlayer(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    D2_ASSERT(pPath, 0x7F3);
    UNITS_ChangeAnimMode(pUnit, 1);
    D2Common_10216(pPath, UNITS_GetXPositionInline(pPlayer), UNITS_GetYPositionInline(pPlayer), 0);
}

// 0x004644E0
void __fastcall sub_004644E0_PlayerFaceUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pPlayer && (pPlayer->dwAnimMode == PLRMODE_NEUTRAL || pPlayer->dwAnimMode == PLRMODE_TOWNNEUTRAL))
    {
        D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
        D2_ASSERT(pPath, 0x802);
        D2Common_10216(pPath, UNITS_GetXPositionInline(pUnit), UNITS_GetYPositionInline(pUnit), 0);
    }
}

void __fastcall sub_00466820_SpawnRoomPresets(D2ActiveRoomStrc* pRoom)
{
    for (D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom); pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->bSpawned & 1)
        {
            sub_004667F0_SpawnPresetUnitInRoom(pRoom, pPresetUnit);
        }
    }
}

// build: context sub_004645B0_CanInterruptSequence
static int __stdcall sub_004645B0_CanInterruptSequence(D2UnitStrc* pUnit, D2ModeArgStrc tUnused)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAnim != 0x12)
    {
        return 1;
    }

    if (!pSkillsTxtRecord->nSeqInput || pSkillsTxtRecord->nSeqInput == 0xFF)
    {
        return 0;
    }

    return (pUnit->dwSeqFrame >> 8) >= pSkillsTxtRecord->nSeqInput;
}

// 0x00464600
int __fastcall sub_00464600_CanStartMode(D2UnitStrc* pUnit, int nArg)
{
    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    switch (pUnit->dwAnimMode)
    {
    case 0:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 17:
    case 19:
        return 0;

    case 18:
    {
        D2ModeArgStrc tArg = { nArg };
        return sub_004645B0_CanInterruptSequence(pUnit, tArg);
    }

    case 13:
        if (pUnit->dwClassId == 3)
        {
            return 0;
        }
        break;

    case 14:
        if (pUnit->dwClassId == 6)
        {
            return 0;
        }
        break;

    case 15:
    case 16:
    {
        const int nClass = pUnit->dwClassId;
        if (nClass == 4 || nClass == 6 || nClass == 5)
        {
            return 0;
        }
        break;
    }

    default:
        break;
    }

    return 1;
}

// 0x004646A0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom()
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pPlayer)
    {
        return UNITS_GetRoom(pPlayer);
    }
    return 0;
}

// 0x004646C0
void __cdecl sub_004646C0_UpdateObjectsForPeriod()
{
    const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    if (nPeriod != gnPeriodOfDay_007A6A74)
    {
        gnPeriodOfDay_007A6A74 = nPeriod;
        for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
        {
            D2UnitStrc* pUnit = gpUnitTable_007A6270[i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 0x88C);
                sub_004BC5E0_UpdateEnvObject(pUnit, 0);
                pUnit = pNext;
            }
        }
        for (int i = 0; i < UNIT_HASH_BUCKETS; ++i)
        {
            D2UnitStrc* pUnit = gpUnitTable_007A5670[i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 0x896);
                sub_004BC5E0_UpdateEnvObject(pUnit, 0);
                pUnit = pNext;
            }
        }
    }
}

// 0x00464770
D2PacketListStrc* __fastcall sub_00464770_GetPacketList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x8A5);
    return pUnit->pPacketList;
}

// 0x004647A0
void __fastcall sub_004647A0_SetPacketList(D2UnitStrc* pUnit, D2PacketListStrc* pPacketList)
{
    D2_ASSERT(pUnit, 0x8AF);
    pUnit->pPacketList = pPacketList;
}

// 0x004647D0
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit)
{
    unsigned int dwFlags = pUnit->dwFlags & ~UNITFLAG_ISDEAD;
    pUnit->dwFlags = dwFlags;
    if (pUnit->dwUnitType != UNIT_MONSTER || sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_ISATT))
    {
        dwFlags |= UNITFLAG_CANBEATTACKED;
        pUnit->dwFlags = dwFlags;
    }
}

int __fastcall sub_M210_Emit_00464310(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    if (!sub_M210_EmitTest(pPlayer, pUnit))
        return 0;
    if (sub_00464310_CheckMonsterSkillSelect(pUnit, pPlayer))
        return sub_M210_EmitUse(pUnit);
    return sub_M210_EmitUse(pPlayer);
}

// 0x00464810
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// 0x00464820
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x004648F0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit)
{
    sub_00480420_RefreshPathTarget(pUnit);
    D2_ASSERT(pUnit->pDynamicPath, 0x946);
    return PATH_GetTargetUnit(pUnit->pDynamicPath);
}

// 0x00464930
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

// 0x00464950
void __fastcall sub_00464950(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x961);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, pfnCallback);
}

// 0x00464990
void __fastcall sub_00464990(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x96C);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6070, pfnCallback);
}

// 0x004649D0
void __fastcall sub_004649D0(UNITFN pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x977);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6270, pfnCallback);
}

// 0x00464A10
static D2UnitStrc* sub_00464A10_FindTileUnit(D2UnitStrc* pUnit)
{
    for (; pUnit; pUnit = pUnit->ptRoomNext)
    {
        if (pUnit->dwUnitType == UNIT_TILE)
        {
            return pUnit;
        }
    }
    return 0;
}

// 0x00464A30
const unsigned short* __fastcall sub_00464A30_GetTileLevelWarpName(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    const int nLevelId = sub_0061A1D0_GetTileLevelId(pRoom, !pUnit ? -1 : pUnit->dwClassId);
    if (nLevelId)
    {
        return DATATBLS_GetLevelsTxtRecord(nLevelId)->wszLevelWarp;
    }
    return 0;
}

// 0x00464A60
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit)
{
    const Unicode* pName;
    D2ActiveRoomStrc* pRoom;
    D2UnitStrc* pTile;
    D2ActiveRoomStrc** ppRooms;
    unsigned int nRooms;
    int nValue;
    D2_ASSERT(pUnit, 0x99D);
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    {
        if (pUnit->pObjectData->pObjectTxt->nOpenWarp && pUnit->dwAnimMode == OBJMODE_OPENED)
        {
            pRoom = UNITS_GetRoom(pUnit);
            pTile = sub_00464A10_FindTileUnit(pRoom->pUnitFirst);
            if (pTile)
            {
                return sub_00464A30_GetWarpName(pRoom, pTile);
            }
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            for (unsigned int i = 0; i < nRooms; ++i)
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = sub_00464A10_FindTileUnit(ppRooms[i]->pUnitFirst);
                    if (pTile)
                    {
                        return sub_00464A30_GetWarpName(ppRooms[i], pTile);
                    }
                }
            }
        }
        if (pUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            nValue = pUnit->dwAnimMode;
            unsigned short nStringId = 0xC9B;
            if (nValue == 5 || nValue == 4)
            {
                nStringId = 0xC9C;
            }
            else if (nValue == 0)
            {
                nStringId = 0xC99;
            }
            else if (nValue == 6)
            {
                nStringId = 0xC9D;
            }
            return D2LANG_GetStringFromTblIndex(nStringId);
        }
        if (UNITS_IsShrine(pUnit))
        {
            return D2LANG_GetStringFromTblIndex(pUnit->pObjectData->InteractType + 0x2A39);
        }
        D2ObjectDataStrc* pObjectData = pUnit->pObjectData;
        if (pObjectData->pObjectTxt->nLockable && (pObjectData->InteractType & 0x80))
        {
            return D2LANG_GetStringFromTblIndex(0xCBE);
        }
        return (const Unicode*)pObjectData->pObjectTxt->wszName;
    }
    case UNIT_MONSTER:
    {
        pName = sub_00463810_GetMonsterName(pUnit);
        if (!sub_00526800(pName))
        {
            return D2LANG_GetStringFromTblIndex(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId)->wNameStr);
        }
        return pName;
    }
    case UNIT_PLAYER:
    case UNIT_MISSILE:
    case UNIT_TILE:
        return 0;
    case UNIT_ITEM:
        nValue = pUnit->dwClassId;
        return D2LANG_GetStringFromTblIndex(DATATBLS_GetItemsTxtRecord(nValue)->wNameStr);
    }
    return 0;
}

// 0x00464C40
int __fastcall sub_00464C40_DecrementCounter58(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA19);
    if (!*(int*)&pUnit->pGfxDataCopy)
    {
        return 0;
    }
    --*(int*)&pUnit->pGfxDataCopy;
    return !STATES_CheckState(pUnit, STATE_ATTACHED);
}

// 0x00464C90
void __fastcall sub_00464C90_SetCounter58(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA34);
    *(int*)&pUnit->pGfxDataCopy = 3;
}

// 0x00464CC0
int __fastcall sub_00464CC0_GetField68(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xA3F);
    return pUnit->dwStartLight;
}

// 0x00464CF0
void __fastcall sub_00464CF0_SetStartLight(D2UnitStrc* pUnit, int nValue)
{
    D2_ASSERT(pUnit, 0xA4A);
    pUnit->dwStartLight = nValue;
}

// 0x00464D20
static int __stdcall sub_00464D20_IsItemInInventory(D2UnitStrc* pOwner, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (pOwner == pUnit)
    {
        return 0;
    }

    if (pUnit->pInventory)
    {
        for (D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pUnit->pInventory); pEntry; pEntry = INVENTORY_GetNextItem(pEntry))
        {
            D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pEntry);
            D2_ASSERT(pInvItem, 0xA5B);
            if (pInvItem == pItem)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00464D90
static int __stdcall sub_00464D90_IsItemOwnedByOther(D2UnitStrc* pOwner, D2UnitStrc* pItem)
{
    D2UnitStrc** ppTable = gpUnitHashTable_007A5E70;
    for (int nTable = 0; nTable < 2; ++nTable)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
            {
                if (sub_00464D20_IsItemInInventory(pOwner, pItem, pUnit))
                {
                    return 1;
                }
            }
        }
        ppTable = &gpUnitHashTable_007A5E70[0x80];
    }
    return 0;
}

// 0x00464E20
static inline void sub_00464E20_PlayOverlaySound(D2UnitStrc* pUnit, int nOverlay)
{
    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

// 0x00464E50
void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        sub_00470390(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

static inline int sub_00464EC0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int sub_00464EC0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00464EC0
int __fastcall sub_00464EC0_CheckSkillOwner(D2UnitStrc* unit, D2UnitStrc* target)
{
    int enabled = 0;
    if (unit && target && (sub_00464EC0_GetUnitType(unit) == 0 || target->dwUnitType == UNIT_MONSTER))
    {
        D2SkillStrc* skill = UNITS_GetLeftSkill(unit);
        if (skill)
        {
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(skill, ".\\UNIT\\CUnit.cpp", 0xB4A));
            if (record && (record->nFlags[3] & gnSkillMask_006CE26C))
                enabled = 1;
        }
        skill = UNITS_GetRightSkill(unit);
        if (skill)
        {
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(skill, ".\\UNIT\\CUnit.cpp", 0xB55));
            if (record && (record->nFlags[3] & gnSkillMask_006CE26C))
                enabled = 1;
        }
        if (enabled)
        {
            const int nRosterId = sub_00479150_FindRosterIndex(target->dwUnitId);
            return nRosterId == sub_00464EC0_GetUnitId(unit);
        }
    }
    return 0;
}

// 0x00465400
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return sub_00479C00_LookupPartyNumber(pUnit);
    }
    return -1;
}

// 0x004654C0
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int bFlag)
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pUnit == pPlayer)
    {
        sub_00466FE0();
    }
    D2ActiveRoomStrc* pRoom = sub_00465420_FindRoomAt(nX, nY);
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2_ASSERT(pDynamicPath, 0x166);
    if (nX && nY)
    {
        D2_ASSERT(pRoom, 0x168);
    }
    if (pUnit->dwFlags & 0x10000)
    {
        return;
    }
    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == PLRMODE_DEATH || nMode == PLRMODE_DEAD)
        {
            return;
        }
        break;
    case UNIT_MONSTER:
        if (nMode == MONMODE_DEATH || nMode == MONMODE_DEAD)
        {
            return;
        }
        break;
    }
    if (pUnit == pPlayer)
    {
        D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pUnit);
        if (pOldRoom)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
            D2SkillsTxt* pSkillsTxtRecord;
            if (pSkill && (pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill)) != 0 && (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7]))
            {
                bFlag = 0;
            }
            else if (bFlag)
            {
                D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x17D);
                sub_004DBFE0_StopSkill();
            }
        }
        if (pRoom)
        {
            DUNGEON_UpdatePops(pRoom, nX, nY, pOldRoom != pRoom);
            sub_004F5190_SetTownMode(!DATATBLS_GetNoPerFromLevelsTxt(DUNGEON_GetLevelIdFromRoom(pRoom)));
            if (pOldRoom)
            {
                D2LevelsTxt* pOldLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pOldRoom));
                D2LevelsTxt* pNewLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (pOldLevel->nPal != pNewLevel->nPal)
                {
                    sub_004FB480_SetActA(pNewLevel->nPal);
                    sub_00600C00_SetActB(pNewLevel->nPal);
                }
            }
        }
    }
    if (!sub_00650BE0_PlaceUnit(pDynamicPath, pUnit, pRoom, nX, nY))
    {
        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
        COLLISION_GetFreeCoordinates(pRoom, &tCoord, nUnitSize, 0x1C09, 1);
        D2_ASSERT(D2Common_10231(pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY), 0x1A9);
    }
    AUTOMAP_SkipAutomapReveal();
    if (pUnit == pPlayer)
    {
        sub_00472C20_PlayerMoved(bFlag);
    }
    sub_00463B80_QueueIdleMove(pUnit);
}

// 0x004656C0
static void sub_004656C0_ClassEffects(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0xF2:
    case 0x2C0:
        sub_00470390(pUnit, 0x7A, 3, 0, 0, 0, 0, 0);
        break;
    case 0x14D:
        sub_00470390(pUnit, 0xBA, 2, 0, 0, 0, 0, 0);
        break;
    case 0x154:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, -0x20, 0);
        break;
    case 0x155:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, -0x20, 0x20, 0);
        break;
    case 0x156:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, 0x20, 0);
        break;
    case 0x157:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0x20, -0x20, 0);
        break;
    case 0x15F:
    case 0x160:
    case 0x161:
    {
        const int nBase = (!pUnit ? -1 : pUnit->dwClassId) - 0xB3;
        sub_00470390(pUnit, nBase, 4, 0, nBase + 3, 0, 0, 0);
        break;
    }
    case 0x196:
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, -0x37);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 1, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0x32, 0);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        break;
    case 0x1A1:
    case 0x1A2:
        if (pUnit)
        {
            sub_00470390(pUnit, 0x10E, 2, 0, 0, 0, 0, 0);
        }
        break;
    case 0x209:
        sub_0046BFF0(pUnit);
        break;
    case 0x21F:
        sub_00470390(pUnit, 0x113, 3, 0, 0, 0, 0, 0);
        break;
    }
}

// 0x00465870
static void sub_00465870_FreeUnit(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pUnit->pLight);
        pUnit->pLight = 0;
    }

    D2GfxLightStrc* pRoomLight = D2Common_10958(pUnit, 0);
    if (pRoomLight)
    {
        sub_004743D0_ReleaseOverlayResource(pRoomLight);
    }

    sub_004DA080_FreeGfxMotion(pUnit);
    sub_004CA9C0_ReleaseUnitHints(pUnit, 0);
    sub_004CC160(pUnit, -1);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_00460D50_FreePlayerUnit(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MONSTER:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_004AED30_FreeClientUnit(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_ITEM:
        sub_004C1A70_ReleaseItemUnit(pUnit);
        ITEMS_FreeItemData(0, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_OBJECT:
        if (pUnit->pHoverText)
        {
            sub_0049F3D0(pUnit->pHoverText);
            pUnit->pHoverText = 0;
        }
        sub_004BCA50_ReleaseUnit(pUnit);
        UNITS_FreeStaticPath(pUnit);
        sub_004CA9C0_ReleaseUnitHints(pUnit, 1);
        break;

    case UNIT_MISSILE:
        sub_004CD170_FreeMissileUnit(pUnit);
        break;

    case UNIT_TILE:
        if (gpAct_007A0634)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    sub_004DC0C0_FreeCltUnitEvents(pUnit);
    sub_0045F9F0_FreePacketBuffer(pUnit);

    if (pUnit == gpPlayerUnit_007A6A70)
    {
        sub_00463D90_SetPlayerUnit(0);
    }

    UNITS_FreeUnit(pUnit);
}

// 0x004659C0
void __cdecl sub_004659C0_FreeAllUnits()
{
    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gpUnitHashTable_007A5E70[gnUnitTypes_006D6ABC[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                sub_00465870_FreeUnit(pUnit);
                pUnit = pNext;
                gpUnitHashTable_007A5E70[gnUnitTypes_006D6ABC[nType] * 0x80 + i] = pUnit;
            }
        }
    }

    for (int nType = 0; nType < 6; ++nType)
    {
        for (int i = 0; i < 0x80; ++i)
        {
            D2UnitStrc* pUnit = gpUnitHashTable_007A5270[gnUnitTypes_006D6ABC[nType] * 0x80 + i];
            while (pUnit)
            {
                D2UnitStrc* pNext = pUnit->pListNext;
                sub_00465870_FreeUnit(pUnit);
                pUnit = pNext;
                gpUnitHashTable_007A5270[gnUnitTypes_006D6ABC[nType] * 0x80 + i] = pUnit;
            }
        }
    }
}

static __forceinline void WalkUnitTable(D2UnitStrc** ppTable)
{
    for (int i = 0; i < 0x80; ++i)
    {
        for (D2UnitStrc* pUnit = ppTable[i]; pUnit; pUnit = pUnit->pListNext)
        {
        }
    }
}

// 0x00465AA0
void __cdecl sub_00465AA0_ResetUnitTables()
{
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6470, sub_00480810_OnUnitA);
    sub_00463CC0_FreeUnitTable(gpUnitTable_007A5870);
    sub_00463CC0_FreeUnitTable(gpUnitTable_007A5670);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, sub_00480810_OnUnitA);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6070, sub_00480810_OnUnitA);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6270, sub_00480810_OnUnitA);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6670, sub_00480810_OnUnitA);
    sub_00463CC0_FreeUnitTable(gpUnitTable_007A5470);
    WalkUnitTable(gpUnitTable_007A5470);
    WalkUnitTable(gpUnitTable_007A6670);
    WalkUnitTable(gpUnitTable_007A5E70);
    WalkUnitTable(gpUnitTable_007A6070);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5470, sub_00463D80_OnUnitB);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6670, sub_00463D80_OnUnitB);
    sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, sub_00463D80_OnUnitB);
    if (!gdwGlobal_007A0610)
    {
        sub_00463C90_ForEachUnitInTable(gpUnitTable_007A5E70, sub_00465070_OnUnitC);
        sub_00463C90_ForEachUnitInTable(gpUnitTable_007A6070, sub_00465070_OnUnitC);
    }
}

// 0x00465BF0
void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg)
{
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget && pTarget != pUnit)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2_ASSERT(pPath, 0x7E2);
        D2Common_10216(pPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nArg);
    }
}

// 0x00465E80
static void sub_00465E80_RemoveUnitFromTable(unsigned int nUnitId, int nUnitType, D2UnitStrc** ppTable, int nHash)
{
    D2UnitStrc* pPrev = 0;
    for (D2UnitStrc* pUnit = ppTable[nHash]; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitId && pUnit->dwUnitType == nUnitType)
        {
            if (!pPrev)
            {
                ppTable[nHash] = pUnit->pListNext;
            }
            else
            {
                pPrev->pListNext = pUnit->pListNext;
            }

            if (pUnit->dwUnitType == UNIT_ITEM)
            {
                sub_004879D0(pUnit);
            }

            sub_00465870_FreeUnit(pUnit);
            return;
        }
        pPrev = pUnit;
    }
}

// 0x00465EE0
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType)
{
    sub_00465E80_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5E70[nUnitType * 0x80], nUnitId & 0x7F);
}

// 0x00465F00
void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType)
{
    sub_00465E80_RemoveUnitFromTable(nUnitId, nUnitType, &gpUnitHashTable_007A5270[nUnitType * 0x80], nUnitId & 0x7F);
}

// 0x00465F20
static D2UnitStrc* sub_00465F20_InsertUnit(D2UnitStrc* pUnit)
{
    if (!sub_00463A50_AddUnitToTable(pUnit))
    {
        D2UnitStrc* pOld = sub_00463990(pUnit->dwUnitId, pUnit->dwUnitType);
        D2_ASSERT(pOld != pUnit, 0x1C6);
        if (pOld)
        {
            if (UNIT_HasFlag(pOld, 0x200000))
            {
                sub_00465F00_RemoveServerSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }
            else
            {
                sub_00465EE0_RemoveClientSideUnit(pOld->dwUnitId, pOld->dwUnitType);
            }

            if (sub_00463A50_AddUnitToTable(pUnit))
            {
                return pUnit;
            }
        }

        sub_00465870_FreeUnit(pUnit);
        pUnit = 0;
    }

    return pUnit;
}

// 0x00465FD0
static D2UnitStrc* __stdcall sub_00465FD0_InitUnit(unsigned int nUnitId, int nClassId, int nY, int nUnitType, int nArg5, int nArg6, D2UnitStrc* pUnit, int nX)
{
    const int bFlag = sub_0044DCC0();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwUnitType = nUnitType;
    pUnit->dwClassId = nClassId;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwTickCount = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom = 0;
    if (nX || nY)
    {
        pRoom = sub_00465420_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct_007A0634;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (nUnitType == 4)
    {
        ITEMS_AllocItemData(0, pUnit);
        ITEMS_InitItemSeed(pUnit);
    }

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    switch (nUnitType)
    {
    case 0:
        sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
        break;

    case 1:
        D2_ASSERT(0, 0x202);
        break;

    case 2:
        UNITS_AllocStaticPath(pUnit);
        sub_004BC720_InitObjectUnit(pUnit, pRoom, nX, nY, nClassId, nArg6);
        break;

    case 4:
        UNITS_AllocStaticPath(pUnit);
        sub_004C1910_InitItemUnit(pUnit, pRoom, nX, nY, nArg5, 1);
        break;

    case 3:
        sub_004CD0A0(pUnit, pRoom, nX, nY, nClassId);
        break;

    case 5:
        UNITS_AllocStaticPath(pUnit);
        pUnit->dwFlags |= 0x22;
        UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pUnit, pRoom);
        break;
    }

    if (nUnitType != 5)
    {
        sub_004DC510_InitGfxData(pUnit);
        if (nUnitType == 0 || nUnitType == 1)
        {
            UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\CUnit.cpp", 0x21D);
        }
    }

    pUnit = sub_00465F20_InsertUnit(pUnit);
    if (pUnit && nUnitType == 2)
    {
        sub_004BC8D0_UpdateObjectOverlay(pUnit);
    }

    return pUnit;
}

// 0x004661C0
D2UnitStrc* __fastcall sub_004661C0_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    return sub_00465FD0_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, 0, pUnit, nX);
}

// 0x00466200
D2UnitStrc* __fastcall sub_00466200_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, 0);
    if (!pUnit)
    {
        return 0;
    }

    const int bFlag = sub_0044DCC0();
    if (pUnit)
    {
        if (bFlag)
        {
            pUnit->dwFlagEx |= 0x2000000;
        }
        else
        {
            pUnit->dwFlagEx &= ~0x2000000;
        }
    }

    pUnit->dwClassId = nClassId;
    pUnit->dwUnitType = 0;
    pUnit->dwUnitId = nUnitId;
    pUnit->dwTickCount = 0;
    pUnit->pMemoryPool = 0;

    D2ActiveRoomStrc* pRoom;
    if (nX || nY)
    {
        pRoom = sub_00465420_FindRoomBySubtile(nX, nY);
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpAct_007A0634;
    }
    else
    {
        pRoom = 0;
    }

    SEED_InitSeed(&pUnit->pSeed);

    if (pRoom)
    {
        unsigned __int64 lSeed = pRoom->pSeed.nHighSeed + 0x6AC690C5i64 * pRoom->pSeed.nLowSeed;
        pRoom->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pRoom->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->dwInitSeed = (unsigned int)lSeed;
        SEED_InitLowSeed(&pUnit->pSeed, (unsigned int)lSeed);
    }

    sub_00460BF0_InitPlayerUnit(pUnit, pRoom, nX, nY);
    sub_004DC510_InitGfxData(pUnit);
    UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\CUnit.cpp", 0x21D);

    pUnit = sub_00465F20_InsertUnit(pUnit);
    if (pUnit)
    {
        UNITS_SetNameInPlayerData(pUnit, szName);
    }

    return pUnit;
}

// 0x00466300
D2UnitStrc* __fastcall sub_00466300_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType)
{
    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit = sub_00465FD0_InitUnit(nUnitId, nClassId, nY, nUnitType, nArg5, nArg6, pUnit, nX);
    if (pUnit)
    {
        pUnit->pObjectData->InteractType = nInteractType;
        if (UNITS_IsShrine(pUnit))
        {
            sub_004BD6B0_InitShrine(pUnit);
        }
    }

    return pUnit;
}

// 0x00466730
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg)
{
    if (++gnPresetUnitId_00711F30 == -1)
    {
        gnPresetUnitId_00711F30 = 0;
    }

    if (nUnitType == 1)
    {
        D2UnitSpawnStrc tSpawn = {};
        tSpawn.nUnitId = gnPresetUnitId_00711F30;
        tSpawn.nClassId = nClassId;
        tSpawn.nX = nX;
        tSpawn.nY = nY;
        tSpawn.nMode = nUnitType;
        return sub_00466360_AddClientMonster(&tSpawn, 0, 0, 0, 0, nUnitType);
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(0, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x600000;
    return sub_00465FD0_InitUnit(gnPresetUnitId_00711F30, nClassId, nY, nUnitType, nArg, 0, pUnit, nX);
}

void sub_I08_Emit_004656C0(D2UnitStrc* pUnit, int nClassId)
{
    sub_004656C0_ClassEffects(pUnit, nClassId);
}

// 0x004667F0
static void sub_004667F0_SpawnPresetUnitInRoom(D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    sub_00466730_SpawnPresetUnit(pPresetUnit->nIndex, pPresetUnit->nXpos + tCoords.nSubtileX, pPresetUnit->nYpos + tCoords.nSubtileY, pPresetUnit->nUnitType, pPresetUnit->nMode);
}

// 0x00466CB0
void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int bCheckOwner)
{
    D2_ASSERT(pUnit, 0xA80);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pEntry = INVENTORY_GetFirstItem(pInventory);
    while (pEntry)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pEntry);
        D2UnitStrc* pItem = sub_00463990(INVENTORY_GetItemGUID(pEntry), 4);
        if (pItem)
        {
            int bRemove = 1;
            if (bCheckOwner)
            {
                bRemove = !sub_00464D90_IsItemOwnedByOther(pUnit, pItem);
            }

            if (bRemove)
            {
                sub_004C0EC0_UpdateItemLink(pItem, pUnit, 0, 0);
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA92);
                sub_00465EE0_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
            }
            else
            {
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, pItem), 0xA96);
            }
        }
        pEntry = pNext;
    }
}

// 0x004693B0
void __fastcall sub_004693B0(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp_007A7404)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp_007A7404), 0x383);
            gpfnWheelUp_007A7404();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown_007A7408)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown_007A7408), 0x38B);
            gpfnWheelDown_007A7408();
        }
    }
}

// 0x00469AA0
unsigned short __fastcall sub_00469AA0(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x00469D70
void __fastcall sub_00469D70(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// 0x00469D90
int __fastcall sub_00469D90(int nA, int nB)
{
    return sub_00469AA0(nA, nB) != 0xFFFF;
}

// 0x0046D750
void __cdecl sub_0046D750()
{
    for (int i = 0; i < 8; ++i)
    {
        gpAiTargets_007A7470[i] = 0;
    }
}

// 0x00483410
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// 0x00483440
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483470
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}

// 0x00483960
void __cdecl sub_00483960()
{
    gabColors_007BCAD8[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabColors_007BCAD8[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabColors_007BCAD8[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabColors_007BCAD8[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = D2Win_10034_MixRGB(0x80, 0x40, 0x40);
}

// 0x00489840
int __cdecl sub_00489840_IsNpcState123()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3)
    {
        return 1;
    }

    return 0;
}

// 0x004898A0
void __fastcall sub_004898A0(int nMode)
{
    gnGlobal_007BCE2C = 1;
    if (gdwGlobal_007BCBF0 == 13)
    {
        gdwGlobal_007BCBF0 = 12;
    }

    sub_00455F20(5, 1, 0);
}

// 0x004898D0
void __fastcall sub_004898D0(int nState)
{
    gnGlobal_00721E34 = nState;
    if (nState == 0)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x004A1730
void __cdecl sub_004A1730_ClearPanel()
{
    TEXT_ResetTextBox();
    gnGlobal_007BF1FA = 0;
    if (gpTextHeader_007BF250)
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

// 0x004B8A10
int __cdecl sub_004B8A10()
{
    if (gnGlobal_007C0E7C == 1 || gnGlobal_007C0E7C == 2)
    {
        return 1;
    }

    return 0;
}

void __cdecl sub_005125B0_DDrawFreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs_008815AC)
    {
        FOG_Free(gpDDrawDebugFontGlyphs_008815AC, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs_008815AC = 0;
    }
}

void __cdecl sub_0051B210_FreeBuffer()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

void __cdecl sub_005239C0_UnlockCDKeys()
{
    if (gpCDKeyHandle_00882744)
    {
        SFileUnloadFile(gpCDKeyHandle_00882744);
        gpCDKeyHandle_00882744 = 0;
    }

    if (gpCDKeyHandle_00882750)
    {
        SFileUnloadFile(gpCDKeyHandle_00882750);
        gpCDKeyHandle_00882750 = 0;
    }
}

// build: context UNIT_HasFlag
static inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (!pUnit)
        return 0;
    return (pUnit->dwFlags & nFlag) != 0;
}

// build: context UNIT_HasFlagEx
static inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

int __fastcall sub_00466870_IsUnitSelectable(D2UnitStrc* pUnit, int nX, int nY, int bHitTest)
{
    const int nMouseX=sub_00468730();
    switch(sub_0045AE90())
    {
    case 3: return 0;
    case 1: if(nMouseX>=gnScreenWidth_0071146C/2) return 0; break;
    case 2: if(nMouseX<gnScreenWidth_0071146C/2) return 0; break;
    }
    D2UnitStrc* pPlayer=gpPlayerUnit_007A6A70;
    if(UNIT_HasFlag(pUnit,0x200000)) return 0;
    if(!sub_00465C60(pPlayer,pUnit) && !sub_00464EC0(pPlayer,pUnit) && !sub_00464F70(pPlayer,pUnit)) return 0;
    int bSelectable=0;
    if(sub_00464310_CheckMonsterSkillSelect(pUnit,pPlayer))
    {
        if(!pUnit) return 0;
        if(UNIT_HasFlag(pUnit,2) || (pUnit->dwUnitType==UNIT_MONSTER && sub_00464820_IsDeadOrDying(pUnit) && sub_00451F30(pUnit,4))) bSelectable=1;
    }
    else
    {
        if(!pUnit) return 0;
        if(UNIT_HasFlag(pUnit,2)) bSelectable=1;
    }
    if(!UNIT_HasFlagEx(pUnit,0x80) || !bSelectable) return 0;
    if(!bHitTest) return 1;
    int nMode=UNITS_GetAnimOrSeqMode(pUnit);
    int nClassId=pUnit->dwClassId;
    int nType=pUnit->dwUnitType;
    D2COMMON_11013_ConvertMode(pUnit,&nType,&nClassId,&nMode,gszCUnitFile_006D6A48,0x6ED);
    D2ObjectsTxt* pObject=0;
    int nUnitX=UNITS_GetClientCoordX(pUnit);
    int nUnitY=UNITS_GetClientCoordY(pUnit);
    switch(nType)
    {
    case 1:
    {
        D2MonStats2SelectStrc* pStats=(D2MonStats2SelectStrc*)UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if(pStats->nFlags[0]&gdwBitMasks[0])
        {
            D2RectStrc tBox;
            const int nTop=nUnitY+pStats->nTop;
            const int nLeft=nUnitX+pStats->nLeft;
            tBox.nLeft=nLeft;
            tBox.nTop=nTop;
            tBox.nRight=nLeft+pStats->nWidth;
            tBox.nBottom=nTop+pStats->nHeight;
            D2CoordPairStrc tPoint={nX,nY};
            return PtInRect(&tBox,tPoint)!=0;
        }
        if(!sub_00470860_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY)) return 0;
        break;
    }
    case 0:
        if(!sub_00470860_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY)) return 0;
        break;
    case 2:
        pObject=DATATBLS_GetObjectsTxtRecord(nClassId);
        if(!sub_00470860_HitTestUnitGfx(pUnit,nUnitX,nUnitY,nX,nY) && !pObject->nIsDoor && !pObject->nSelectBox) return 0;
        break;
    case 4:
        if(pUnit->dwAnimMode!=3 || sub_004538D0(13)) return 0;
        break;
    case 5: return sub_00463EE0_IsPointInTileRect(pUnit,nX,nY);
    }
    int bAllComponents=0;
    switch(nType)
    {
    case 2:
        D2_ASSERT(pObject,0x741);
        if(pObject->nIsDoor)
        {
            if(pUnit->dwAnimMode==2 || pUnit->dwAnimMode==4 || pUnit->dwAnimMode==5)
                return sub_00463FE0_IsInObjectSelectBox(nY,pObject,pUnit,nX);
        }
        else if(pObject->nSelectBox) return sub_00463FE0_IsInObjectSelectBox(nY,pObject,pUnit,nX);
        if(pObject->nComponents>1) bAllComponents=1;
        break;
    case 1:
    {
        D2MonStats2SelectStrc* pStats=(D2MonStats2SelectStrc*)UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if(pStats && pStats->nComponents>1) bAllComponents=1;
        break;
    }
    case 0:bAllComponents=1;break;
    }
    int nFrame,nFrameCount;
    {
        D2RectStrc tRect;
        UNITS_GetShiftedFrameMetrics(pUnit,&nFrame,&nFrameCount);
        tRect.nBottom=tRect.nRight=tRect.nTop=tRect.nLeft=0;
        if(pUnit->dwUnitType==UNIT_PLAYER && pUnit->dwClassId==4 && pUnit->dwAnimMode==PLRMODE_SEQUENCE) return 1;
        if(bAllComponents)
        {
            for(unsigned int nComponent=0;nComponent<16;++nComponent)
                if(sub_004640A0_GetUnitSelectRect(pUnit,nComponent,&tRect,nFrame) && sub_004DB670_UpdateUnitGfx(pUnit,nComponent) && nX>=tRect.nLeft && nX<=tRect.nRight && nY>=tRect.nBottom && nY<=tRect.nTop) return 1;
            return 0;
        }
        if(sub_004640A0_GetUnitSelectRect(pUnit,1,&tRect,nFrame) && nX>=tRect.nLeft && nX<=tRect.nRight && nY>=tRect.nBottom && nY<=tRect.nTop) return 1;
        return 0;
    }
}

#include "gen/data/Source/D2Client/UNIT/CUnit.inc"
