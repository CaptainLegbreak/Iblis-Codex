#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define MONSTATSFLAGINDEX_NOAURA 27
#define ITEMTYPE_CROSSBOW 35
#define STAT_TOHIT 19
#define STAT_DAMAGEPERCENT 25
#define STATE_UNINTERRUPTABLE 0x36
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
#define STAT_MANA 8
#define STATE_BLOOD_MANA 114
#define STATE_BLOODMANA 114
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STAT_ATTACKRATE 68
#define SKILLSFLAGINDEX_AURA 5
#define SKILLSFLAGINDEX_PERIODIC 6
#define EVENTTYPE_PERIODICSTATS 9
#define ITEMTYPE_WEAPON 0x2D

struct D2SkillListStrc;
struct D2UnitFindArgStrc;
struct Obj006252D0;
struct Obj00625CE0;
struct D2StaticPathStrc;
struct D2DrlgCoordsStrc;
struct D2AuraCallbackStrc;
struct D2SkillsTxt;
struct D2_6FD106F0_Strc;
struct D2_6FD10880_Strc;
struct D2MonStatsTxt;
struct D2CharStatsTxt;
struct D2StatesTxt;
struct D2EffectStrc;
struct D2PetTypeTxt;
struct D2ObjectDataStrc;
struct D2MonsterDataStrc;
struct D2MissilesTxt;
struct D2MonSkillInfoStrc;
struct D2ActiveRoomStrc;
struct D2CoordStrc;
struct D2UnitStrc;
struct D2GameStrc;
struct D2DamageStrc;
struct D2DataTablesStrc;
struct D2MissileStrc;
struct D2UnitFindDataStrc;
struct D2ItemDropStrc;
union D2SeedStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};





struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0


int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall sub_6FD11340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0056C310
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4, int a5); // 0x0057DFB0
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall D2Common_11024(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType, int* pHasThrowBonus); // 0x00645720

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    unsigned char unk_0C[0x42];
    short wSrvOverlay;
    char unk0x50[0x60 - 0x50];
    unsigned int dwAuraLenCalc;
    char unk0x64[0x80 - 0x64];
    short nAuraState;
    short wAuraTargetState;
    unsigned char unk_84[0xA4];
    unsigned int dwPerDelay;
    unsigned char unk_12C[0x5A];
    short wMinMana;
    unsigned char nManaShift;
    unsigned char unk0x189;
    short wMana;
    short wLevelMana;
    unsigned char unk_18E[0x2];
    unsigned int dwDelay;
    unsigned char unk_194[0x10];
    unsigned char nToHitShift;
    char unk0x1A5[0x03];
    unsigned int dwMinDam;
    unsigned char unk_1AC[0x30];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused); // 0x0056B9C0
int __fastcall sub_6FD119C0(D2UnitStrc* pUnit); // 0x0056C4E0
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310
void __fastcall sub_6FC80E10(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
void __fastcall sub_0056C600_ApplyThrowBonuses(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon); // 0x0056C600
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0
int __fastcall sub_6FD13330(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel, int a6); // 0x0056CE70
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

struct D2_6FD106F0_Strc
{
    D2UnitStrc* pUnit;
    int nDistance;
    int nX;
    int nY;
    int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*);
};

struct D2_6FD10880_Strc
{
    D2UnitStrc* unk0x00;
    unsigned int unk0x04;
    D2UnitStrc* unk0x08;
    unsigned int unk0x0C;
    unsigned int unk0x10;
    int unk0x14;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pCharges, D2StatListStrc** ppStatList); // 0x0065C820
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pItem); // 0x00627220
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost); // 0x005D2B60
static int __stdcall sub_0056BEC0_SpendItemCharge(D2GameStrc* pGame, D2SkillStrc* pSkill, int nOwnerGUID, D2UnitStrc* pPlayer); // 0x0056BEC0

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char unk0x04[0x2E];
    short nVelocity;
    unsigned char unk_34[0x74];
    short wSkillDamage;
    char unk0x0AA[0xFE];
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    char unk0x41[0x83];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const int gnSignX_006E1510[4]; // 0x006E1510
extern const int gnSignY_006E14E4[4]; // 0x006E14E4
extern const int gnOffset1_006E14F4[7]; // 0x006E14F4
extern const int gnOffset2_006E14C8[7]; // 0x006E14C8
extern const int gnXOffsets_006E14A8[8]; // 0x006E14A8
extern const int gnYOffsets_006E1488[8]; // 0x006E1488

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    void* pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nFlags;
    int nIndex;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
};

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575900
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill); // 0x006438F0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60
void __fastcall sub_00553B10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x00553B10
int __fastcall sub_005DD480(D2UnitStrc* pUnit, int nArg); // 0x005DD480
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall AIGENERAL_DetachOwnedMinions(D2UnitStrc* pUnit); // 0x0058F260
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit); // 0x0058F160

typedef int (__stdcall* FARPROC)();

struct D2StatesTxt
{
    char unk0x00[0x1E];
    short wGroup;
    unsigned char unk_20[0x16];
    short callback;
    unsigned char unk_38[0x4];
};

struct D2EffectStrc
{
    unsigned int nFlags;
    D2UnitStrc* pUnit;
    int nSkillId;
    int nX;
    int nY;
    int nParam;
    int nSkillLevel;
    int unk0x1C;
    void* pfAreaEffect;
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

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

typedef void (__fastcall* SKILLS_AREAEFFECTFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nParam);

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
void __fastcall sub_6FC7D260(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4); // 0x005750E0

struct D2PetTypeTxt { unsigned int type; unsigned char flags; };
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* player, int petId); // 0x00574A20
extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int petType); // 0x00478A20
void __stdcall SKILLS_SetParam1(D2SkillStrc* skill, int value); // 0x00644560
extern const unsigned char gnPetFlag_006CE274; // 0x006CE274

typedef char H15_CheckSkillsTxtSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char H15_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];

typedef char H15_CheckSkillsCount[(int)&((D2DataTablesStrc*)0)->nSkillsTxtRecordCount == 0xBA0 ? 1 : -1];

enum
{
    MONMODE_DEAD = 12,
    UNITFLAG_TARGETABLE = 0x00000002,
    PLRMODE_TOWNNEUTRAL = 5,
    SKILLSFLAGINDEX_INTOWN = 8,
    SKILLSFLAGINDEX_TARGETABLEONLY = 20,
    SKILLSFLAGINDEX_TARGETCORPSE = 24,
    SKILLSFLAGINDEX_TARGETALLY = 26,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges); // 0x00643B00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

struct D2ObjectDataStrc
{
    char unk0x00[0x04];
    unsigned char InteractType;
};


unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
int __fastcall QUESTS_PortalCheck(D2GameStrc* pGame, D2CoordStrc* pCoord, int nLevel, D2ActiveRoomStrc** ppRoom); // 0x00545830
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __fastcall sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond); // 0x00553590
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __fastcall sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056CDA0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    int* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    void* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int unk0x2C;
    int nQuality;
    char unk0x34[0x84 - 0x34];
};

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

typedef int (__fastcall *SkillCallback)(D2GameStrc*, D2UnitStrc*, int, int);
extern const SkillCallback gpSkillCallbacks_007322B0[]; // 0x007322B0
D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int); // 0x00452040
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine); // 0x006470F0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110

struct D2MissilesTxt
{
    char unk0x00[0x18A];
    unsigned char nSize;
    char unk0x18B[0x19];
};

int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056C3F0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800

struct D2MonSkillInfoStrc
{
    int nMinDamage;
    int nMaxDamage;
    int nToHit;
};

int __stdcall SKILLS_GetHighestSkillLevelById(D2UnitStrc* pUnit, int nSkillId); // 0x00644AA0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00647D00
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc* pUnit); // 0x00645680
int __stdcall UNITFINDS_TestUnit(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg); // 0x0065AA40
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay); // 0x0056EF90
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057D690
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40
extern "C" void __stdcall sub_006252D0(Obj006252D0* pObj, unsigned int dwValue); // 0x006252D0
extern "C" void __stdcall sub_00625CE0(Obj00625CE0* pObj, unsigned int dwValue); // 0x00625CE0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x0053C4A0
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055FDE0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __fastcall sub_0056C8E0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

static __forceinline int SKILLS_IsInRangeY(int nY, int nDistance, const D2DrlgCoordsStrc& drlgCoords)
{
    return nY + nDistance >= drlgCoords.nSubtileY || nY - nDistance <= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight;
}

// 0x0056B770
static int sub_0056B770_IsRoomInRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nDistance)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    if (nX + nDistance >= drlgCoords.nSubtileX)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    if (nX - nDistance <= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    return 0;
}

// 0x0056B7E0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine)
{
    if (!pGame || !pUnit || !pCallback || nAuraRange <= 0)
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pCurrentRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = CLIENTS_GetUnitX(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nAuraFilter)
    {
        nAuraFilter = 0x583;
    }

    D2AuraCallbackStrc auraCallback;
    auraCallback.pArgs = pCallbackArgs;
    auraCallback.pGame = pGame;
    auraCallback.pOwner = pUnit;
    auraCallback.nCounter = 0;
    const int nAuraRangeSq = nAuraRange * nAuraRange;

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pCurrentRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (!(nAuraFilter & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (sub_0056B770_IsRoomInRange(ppRoomList[i], nX, nY, nAuraRange))
            {
                D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst;
                while (pTarget)
                {
                    D2UnitStrc* pNextTarget = pTarget->ptRoomNext;
                    if (pTarget != pUnit && nAuraRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget)) && sub_6FD0FA00(pUnit, pTarget, nAuraFilter))
                    {
                        if (!bCheckMonAuraFlag || pTarget->dwUnitType != UNIT_MONSTER || !sub_00457490_CheckMonStatsFlag(pTarget->dwClassId, MONSTATSFLAGINDEX_NOAURA))
                        {
                            if (pCallback(&auraCallback, pTarget))
                            {
                                auraCallback.nCounter += 1;
                            }
                        }
                    }
                    pTarget = pNextTarget;
                }
            }
        }
    }
}

// 0x0056B9C0
void __fastcall sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused)
{
    if (!pAttacker)
    {
        return;
    }

    if (!pUnit)
    {
        return;
    }

    if (pAttacker->dwUnitType == UNIT_MISSILE)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
        if (pOwner)
        {
            pAttacker = pOwner;
        }
    }

    if ((pDamage->wResultFlags == 0) & 1)
    {
        return;
    }

    const int nBlockFlags = SUNITDMG_ApplyBlockOrDodge(pGame, pAttacker, pUnit, 1, 0);
    if (nBlockFlags & 2)
    {
        pDamage->wResultFlags |= 0x100;
    }

    if (nBlockFlags & 4)
    {
        pDamage->wResultFlags |= 0x80;
    }

    if (nBlockFlags & 0x10)
    {
        pDamage->wResultFlags |= 0x8000;
    }

    if (nBlockFlags & 1)
    {
        pDamage->wResultFlags |= 0x10;
    }

    if (nBlockFlags)
    {
        pDamage->wResultFlags &= ~DAMAGERESULTFLAG_SUCCESSFULHIT;
    }

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT && !STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        pDamage->wResultFlags |= 4;
    }

    D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pAttacker, pUnit, pDamage);

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, pDamage);
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, pDamage);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056BA90
int __fastcall sub_6FCF5DE0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageStrc damage = *(D2DamageStrc*)pAuraCallback->pArgs;
    sub_6FD10140(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0);
    return 1;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x0056BB20
int __fastcall sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD106F0_Strc* pArgs = (D2_6FD106F0_Strc*)pAuraCallback->pArgs;

    if (!pArgs->pCallback || pArgs->pCallback(pAuraCallback->pGame, pUnit))
    {
        const int nXDiff = CLIENTS_GetUnitXInline(pUnit) - pArgs->nX;
        const int nYDiff = CLIENTS_GetUnitYInline(pUnit) - pArgs->nY;

        const int nDistance = nXDiff * nXDiff + nYDiff * nYDiff;
        if (nDistance < pArgs->nDistance)
        {
            pArgs->nDistance = nDistance;
            pArgs->pUnit = pUnit;
        }

        return 1;
    }

    return 0;
}

// 0x0056BC70
int __fastcall sub_0056BC70_CountAuraTargets(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    ++*(int*)pAuraCallback->pArgs;
    return 1;
}

// 0x0056BCD0
int __fastcall sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD10880_Strc* pArgs = (D2_6FD10880_Strc*)pAuraCallback->pArgs;

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;

    if ((unsigned int)nUnitGUID <= pArgs->unk0x10 || (unsigned int)nUnitGUID >= pArgs->unk0x04)
    {
        if ((unsigned int)nUnitGUID <= pArgs->unk0x0C)
        {
            pArgs->unk0x0C = nUnitGUID;
            pArgs->unk0x08 = pUnit;
        }
        ++pArgs->unk0x14;
    }
    else
    {
        pArgs->unk0x04 = nUnitGUID;
        pArgs->unk0x00 = pUnit;
        ++pArgs->unk0x14;
    }

    return 1;
}

static __forceinline int SKILLS_IsPlayerInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// build: context sub_0056BEC0_SpendItemCharge
static int __stdcall sub_0056BEC0_SpendItemCharge(D2GameStrc* pGame, D2SkillStrc* pSkill, int nOwnerGUID, D2UnitStrc* pPlayer)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nOwnerGUID);
    if (!pItem)
    {
        return 0;
    }
    const int nChargeSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 898);
    const int nChargeSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);
    int nCharges = 0;
    D2StatListStrc* pStatList = 0;
    if (!ITEMMODS_GetItemCharges(pItem, nChargeSkillId, nChargeSkillLevel, &nCharges, &pStatList) || nCharges <= 0)
    {
        return 0;
    }
    const int nLayer = (nChargeSkillId << sgptDataTables->nStuff) + (nChargeSkillLevel & sgptDataTables->nShiftedStuff);
    const int nStatValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nLayer);
    if (!nStatValue)
    {
        return 0;
    }
    const int nMaxCharges = nStatValue >> 8;
    nCharges -= 1;
    if (nMaxCharges <= 0 || nMaxCharges > 255)
    {
        return 0;
    }
    int nNewCharges = nCharges > 0 ? nCharges : 0;
    nNewCharges = nNewCharges < nMaxCharges ? nNewCharges : nMaxCharges;
    nCharges = nNewCharges;
    const int nNewValue = (nNewCharges & 0xFF) + (nMaxCharges << 8);
    STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, nNewValue, nLayer, pItem);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer, ".\\SKILLS\\Skills.cpp", 933), pItem, 1, STAT_ITEM_CHARGED_SKILL, nNewValue, nLayer);
    return 1;
}

// 0x0056BFE0
int __fastcall sub_0056BFE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_IsPlayerInline(pPlayer))
    {
        return 1;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 955) == nSkillId)
    {
        const int nOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pSkill);
        if (nOwnerGUID != -1)
        {
            return sub_0056BEC0_SpendItemCharge(pGame, pSkill, nOwnerGUID, pPlayer);
        }
    }
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (!pSkillsTxtRecord->wMana && !pSkillsTxtRecord->wLevelMana)
    {
        return 0;
    }
    const int nLevelBonus = nSkillLevel - 1 < 0 ? 0 : nSkillLevel - 1;
    int nManaCost = (pSkillsTxtRecord->wMana + nLevelBonus * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
    const int nMinManaCost = pSkillsTxtRecord->wMinMana << 8;
    if (nMinManaCost > nManaCost)
    {
        nManaCost = nMinManaCost;
    }
    if (STATES_CheckState(pPlayer, STATE_BLOOD_MANA))
    {
        return D2GAME_SKILLS_BloodMana_6FD025E0(pPlayer, nManaCost);
    }
    if (STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }
    sub_006272B0_UnitStatListCall(pPlayer, STAT_MANA, -nManaCost, 0);
    return 1;
}

// 0x0056C110
int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    if (STATES_CheckState(pUnit, STATE_BLOODMANA))
    {
        return D2GAME_SKILLS_BloodMana_6FD025E0(pUnit, nManaCost);
    }

    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }

    STATLIST_AddUnitStat(pUnit, STAT_MANA, -nManaCost, 0);
    return 1;
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClassId];
    }

    return 0;
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }

    return nMonsterId;
}

// 0x0056C2A0
void __fastcall SKILLS_FreeUnitSearch(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData)
{
    UNITFINDS_FreeUnitFindData(pUnitFindData);
    FOG_FreeServerMemory(pGame->pMemoryPool, pUnitFindData, ".\\SKILLS\\Skills.cpp", 0x465, 0);
}

// 0x0056C3F0
int __fastcall sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pUnit);
        int bNoBow = 1;

        if (ITEMSIsA(pWeapon, ITEMTYPE_BOW) || ITEMSIsA(pWeapon, ITEMTYPE_CROSSBOW))
        {
            bNoBow = 0;
        }

        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return sub_6FD11340(pGame, pUnit, pItem);
        }

        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return sub_6FD11340(pGame, pUnit, pItem);
        }
    }

    return 0;
}

// 0x0056C600
void __fastcall sub_0056C600_ApplyWeaponBonusToMissile(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon)
{
    if (pUnit && pMissile && pWeapon)
    {
        const int nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
        const int nToHitBonus = D2Common_11024(pUnit, pWeapon, 0, 0, 0);
        STATLIST_SetUnitStat(pMissile, STAT_TOHIT, nToHitBonus + nToHit, 0);
        const int nDamageBonus = D2Common_11024(pUnit, pWeapon, 0, 1, 0);
        STATLIST_AddUnitStat(pMissile, STAT_DAMAGEPERCENT, nDamageBonus, 0);
    }
}

#include "gen/data/Source/D2Game/SKILLS/Skills.inc"

// 0x0056C670
static D2UnitStrc* __stdcall sub_0056C670_GetOtherHandItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (nBodyLoc == BODYLOC_LARM)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
}

D2UnitStrc* __fastcall sub_K11_Emit0056C670(D2InventoryStrc* pInventory, int nBodyLoc)
{
    return sub_0056C670_GetOtherHandItem(pInventory, nBodyLoc + 1);
}

static inline D2StatesTxt* STATES_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x0056C740
int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nStateId, int a3)
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
        if (i != nStateId || a3)
        {
            if (STATES_GetStatesTxtRecordInline(i)->wGroup == nGroup && STATES_CheckState(pUnit, i))
            {
                nResult = 1;
                STATES_ToggleState(pUnit, i, 0);

                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, i);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }
        }
    }

    return nResult;
}

// 0x0056CA40
int __fastcall SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->nSeqCurrentFramePrecise = UNITS_GetFrameBonus(pUnit) << 8;
    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return sub_6FD00370(pGame, pUnit, nSkillLevel);
    }

    if (!COMPOSIT_IsWeaponBowOrXBow(pUnit) || sub_6FD119C0(pUnit))
    {
        return 1;
    }

    sub_6FC80A30(pGame, pUnit);
    sub_6FC80E10(pGame, pUnit);
    return 0;
}

// 0x0056CAB0
int __fastcall SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_6FD119C0(pUnit))
    {
        sub_6FC80A30(pGame, pUnit);
        sub_6FC80E10(pGame, pUnit);
        return 0;
    }

    return 1;
}

// 0x0056CAF0
int __fastcall SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = 9;
    damage.dwHitFlags = 2;
    damage.dwPhysDamage = pSkillsTxtRecord->dwMinDam << pSkillsTxtRecord->nToHitShift;
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    return 1;
}

static inline unsigned int sub_0056CBA0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int sub_0056CBA0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0056CBA0
int __fastcall SKILLS_SrvSt03_Unsummon(D2GameStrc* game, D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2UnitStrc* target = SUNIT_GetTargetUnit(game, unit);
    if (!target)
        return 0;
    if (sub_0056CBA0_GetUnitType(target) != 1)
        return 0;
    if (!unit)
        return 0;
    if (unit->dwUnitType != 0)
        return 0;
    if (AIGENERAL_GetMinionOwner(target) != unit)
        return 0;
    D2PetTypeTxt* petType = sub_00478A20_GetPetTypeTxtRecord(PLAYERPETS_GetPetTypeFromPetGUID(unit, target->dwUnitId));
    if (!petType)
        return 0;
    if (!(petType->flags & gnPetFlag_006CE274))
        return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill)
        return 0;
    SKILLS_SetParam1(skill, sub_0056CBA0_GetUnitId(target));
    return 1;
}

// 0x0056CC20
int __fastcall SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;

    sub_6FC7D260(pGame, pUnit, SKILLS_GetParam1(pSkill), 1);
    return 1;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_H15(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int UNIT_HasFlag_H15(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056CC60
static int __stdcall sub_0056CC60_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETABLEONLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETABLEONLY & 7])
    {
        if (!sub_00554200(pGame, pUnit, pTarget) && !SUNIT_CanPetBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId) && !SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId))
        {
            return 0;
        }
    }

    if (!UNIT_HasFlag_H15(pTarget, UNITFLAG_TARGETABLE))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
    else
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7]))
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
        else
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7])
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
    }

    return 1;
}

int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xBFF);
    if (!sub_0056CC60_CheckUsedSkillTarget(pGame, pUnit, nSkillId))
    {
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
        }
        return 0;
    }

    int nOwnerGUID;
    int nInfoSkillId;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nCharges;
    if (SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, &nInfoSkillId, &nSkillLevel, &nCharges) && !nCharges)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]) && SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTargetUnit, nSkillId))
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]))
    {
        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
            switch (nType)
            {
            case UNIT_PLAYER:
                sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                return 0;
            case UNIT_MONSTER:
                return nType - UNIT_MONSTER;
            }
            return 0;
        }
    }

    const int nResult = sub_6FD12950(pGame, pUnit, nSkillId, nSkillLevel, 0);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && !nResult)
    {
        sub_6FC817D0(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
    }
    return nResult;
}

inline int SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPerDelay, nSkillId, nSkillLevel);
    if (nDelay <= 5)
    {
        nDelay = 5;
    }

    return (pGame->dwGameFrame + nDelay - 1) / nDelay * nDelay + 1;
}

// 0x0056CDA0
int __fastcall sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7] || pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
        if (a5)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, -1, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nSkillId);
            sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

// 0x0056CE70
int __fastcall sub_6FD13330(D2GameStrc* pGame, D2UnitStrc* pUnit, int a5, int nSkillId, int nSkillLevel, int a6)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7] || pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
        if (a6)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, -1, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_PERIODICSTATS, a5);
            sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nExpireFrame, a5, nSkillId);
        }

        return 1;
    }

    return 0;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0056CF40
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, int nUnused, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nDestLevel);
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nDestLevel, 11, &nX, &nY, 3);
    D2ActiveRoomStrc* pDestinationRoom = pRoom;

    sub_6FC385A0(pGame, pRoom);

    if (!pRoom)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPortal), 2, !pPortal ? -1 : pPortal->dwUnitId);
        SUNIT_RemoveUnit(pGame, pPortal);
        return 0;
    }

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (QUESTS_PortalCheck(pGame, &coords, nSourceLevel, &pRoom))
    {
        pRoom = D2GAME_GetRoom_6FC52070(pRoom, coords.nX, coords.nY);
    }

    if (!pRoom)
    {
        pRoom = pDestinationRoom;
        coords.nX = nX;
        coords.nY = nY;
    }

    pRoom = COLLISION_GetFreeCoordinatesEx(pRoom, &coords, 3, 0xBE11u, 5);
    if (!pRoom)
    {
        pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nDestLevel, 11, &nX, &nY, 3);
        if (!pRoom)
        {
            pRoom = pDestinationRoom;
            D2_ASSERT(pDestinationRoom, 0xE08);
        }
    }

    nX = coords.nX;
    nY = coords.nY;

    D2UnitStrc* pLinkPortal = SUNIT_AllocUnitData(2, !pPortal ? -1 : pPortal->dwClassId, coords.nX, coords.nY, pGame, pRoom, 1, 2, 0);
    if (!pLinkPortal)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPortal), 2, !pPortal ? -1 : pPortal->dwUnitId);
        SUNIT_RemoveUnit(pGame, pPortal);
        return 0;
    }

    const int eLevelIdLocal = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal));
    D2_ASSERT(eLevelIdLocal <= 255, 0xE2B);

    pLinkPortal->pObjectData->InteractType = eLevelIdLocal;
    const unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, nPortalFlags);
    UNITS_ChangeAnimMode(pLinkPortal, 2);
    sub_6FCBC9C0(pPortal, pLinkPortal);
    UNITS_StoreOwner(pPortal, pLinkPortal);
    UNITS_StoreOwner(pLinkPortal, pPortal);

    return pLinkPortal;
}

// 0x0056D4E0
void __fastcall SKILLS_CreateMissilePattern(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nMissiles - 1) / 5 <= 7, 0xF0D);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    MISSILES_CreateMissileFromParams(pGame, pMissileParams);

    int nSubMissiles = nMissiles - 1;
    for (int j = 0; j < 7 && nSubMissiles; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (nSubMissiles <= 0)
            {
                break;
            }

            pMissileParams->nTargetX = gnOffset1_006E14F4[j] * gnSignX_006E1510[i];
            pMissileParams->nTargetY = gnOffset2_006E14C8[j] * gnSignY_006E14E4[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);

            pMissileParams->nTargetX = gnOffset2_006E14C8[j] * gnSignX_006E1510[i];
            pMissileParams->nTargetY = gnOffset1_006E14F4[j] * gnSignY_006E14E4[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);
            nSubMissiles -= 2;
        }

        pMissileParams->nTargetX = gnXOffsets_006E14A8[j];
        pMissileParams->nTargetY = gnYOffsets_006E1488[j];
        MISSILES_CreateMissileFromParams(pGame, pMissileParams);
        nSubMissiles -= 1;
    }
}

// 0x0056D5F0
int __fastcall sub_0056D5F0_SpawnItemInFreeHand(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        int nBodyLoc;
        int bEquip = 0;
        if (!pRightArmItem && !pLeftArmItem)
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && !ITEMSIsA(pLeftArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pLeftArmItem && pRightArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem) && !ITEMSIsA(pRightArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_LARM;
            bEquip = 1;
        }

        if (bEquip)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = pUnit;
            itemDrop.pGame = pGame;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = DATATBLS_GetItemIdFromItemCode(dwItemCode);
            D2_ASSERT(itemDrop.nId != -1, 0xF4C);

            itemDrop.nSpawnType = 4;
            itemDrop.nX = 0;
            itemDrop.nY = 0;
            itemDrop.pRoom = 0;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            D2UnitStrc* pNewItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
            D2_ASSERT(pNewItem, 0xF55);

            {
                int nUnused;
                ITEMMODE_EquipCursorItem(pGame, pUnit, pNewItem->dwUnitId, nBodyLoc, 0, &nUnused);
            }
            return 1;
        }
    }

    return 0;
}

static __forceinline SkillCallback GetSkillCallback(short nIndex)
{
    if (nIndex < 0)
        return 0;
    if (nIndex >= 191)
        return 0;
    return gpSkillCallbacks_007322B0[nIndex];
}

// 0x0056D790
void __fastcall sub_0056D790_DispatchAuraCallback(D2GameStrc* game, D2UnitStrc* unit, int skill, int level)
{
    if (skill <= 0)
        return;
    if (skill >= sgptDataTables->nSkillsTxtRecordCount)
        return;
    D2SkillsTxt* record = &sgptDataTables->pSkillsTxt[skill];
    if (!record)
        return;
    const short state = record->nAuraState;
    if (state < 0)
        return;
    if (state >= sgptDataTables->nStatesTxtRecordCount)
        return;
    D2StatesTxt* states = sub_00452040_GetStatesTxtRecord(state);
    if (!states)
        return;
    SkillCallback callback = GetSkillCallback(states->callback);
    if (!callback)
        return;
    callback(game, unit, skill, level);
}

// 0x0056DCC0
void __fastcall sub_6FD149B0(D2GameStrc* pGame, D2EffectStrc* pEffect)
{
    D2_ASSERT(pEffect, 4280);
    D2_ASSERT(pEffect->pfAreaEffect, 4281);

    int nParam = pEffect->nParam;
    if (!nParam)
    {
        nParam = sub_004E6CA0_GetSkillParamByLevel(pEffect->nSkillId, pEffect->nSkillLevel);
    }

    D2UnitFindArgStrc unitFindArg = {};
    unitFindArg.nFlags = pEffect->nFlags;
    unitFindArg.pUnit = pEffect->pUnit;
    unitFindArg.nX = pEffect->nX;
    unitFindArg.nY = pEffect->nY;
    unitFindArg.nSize = nParam;

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pEffect->pUnit), pEffect->nX, pEffect->nY);
    if (pRoom)
    {
        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, pEffect->nX, pEffect->nY, nParam, 0, &unitFindArg);
        unitFindData.nFlags = pEffect->nFlags;
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        D2_ASSERT(!IsBadCodePtr((FARPROC)pEffect->pfAreaEffect), 4315);

        for (int i = 0; i < unitFindData.nIndex; ++i)
        {
            ((SKILLS_AREAEFFECTFN)pEffect->pfAreaEffect)(pGame, pEffect->pUnit, unitFindData.pUnitsArray[i], pEffect->nSkillLevel, pEffect->unk0x1C);
        }

        UNITFINDS_FreeUnitFindData(&unitFindData);
    }
}

// 0x0056DE40
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit)
{
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
    }
}

// 0x0056DE70
D2SkillStrc* __fastcall sub_0056DE70_AddSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
    return pSkill;
}

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0056DEB0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, bRemove, ".\\SKILLS\\Skills.cpp", 4394);
        SKILLS_RefreshPassiveSkills(pUnit);
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
        }
    }
}

// 0x0056DF10
void __fastcall sub_0056DF10_RemoveSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    SKILLS_RemoveSkill(pUnit, nSkillId, ".\\SKILLS\\Skills.cpp", 4405);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// 0x0056DF50
int __fastcall sub_0056DF50_IsActiveSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4416) == nSkillId)
        return 1;
    pSkill = UNITS_GetLeftSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4419) == nSkillId)
        return 1;
    return 0;
}

// 0x0056DFA0
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* i = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills); i; i = SKILLS_GetNextSkill(i))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(i, ".\\SKILLS\\Skills.cpp", 0x1153);
            const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
            if (nPassiveState > 0)
            {
                STATES_ToggleState(pUnit, nPassiveState, 1);
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }
    }
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0056E000
static void __stdcall sub_0056E000_FillMonSkillInfo(D2UnitStrc* pOwner, int nSkillId, D2MonSkillInfoStrc* pMonSkillInfo)
{
    const int nSkillLevel = SKILLS_GetHighestSkillLevelById(pOwner, nSkillId);
    pMonSkillInfo->nMinDamage = SKILLS_GetMinPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nMaxDamage = SKILLS_GetMaxPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nToHit = SKILLS_GetToHitFactor(pOwner, nSkillId, nSkillLevel);
}

// 0x0056E050
void __fastcall sub_6FD14D20(D2UnitStrc* pUnit, int nUnused, D2MonSkillInfoStrc* pMonSkillInfo)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wSkillDamage > 0 && pMonStatsTxtRecord->wSkillDamage <= sgptDataTables->nSkillsTxtRecordCount)
            {
                sub_0056E000_FillMonSkillInfo(pOwner, pMonStatsTxtRecord->wSkillDamage, pMonSkillInfo);
            }
        }
    }
}

// 0x0056E0C0
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;

    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    const int nMinDamage = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMaxDamage = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nDamage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage;
    sub_0056C8E0(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, nLength, 0, 0);
    return nDamage;
}

// 0x0056E170
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMinDamage = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
        const int nMaxDamage = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
        const int nDamage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage;
        pDamage->dwPhysDamage += nDamage;
    }
}

// 0x0056E1E0
int __fastcall sub_0056E1E0_GetCrossbowClassFlag(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == 7 ? 0x1F : 0;
}

// 0x0056E210
void __fastcall sub_0056E210(D2UnitStrc* pUnit, int nArg)
{
    sub_00553B10(SUNIT_GetGameFromUnit(pUnit), pUnit, nArg);
}

// 0x0056E2F0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == 0x1EC && STATES_CheckState(pUnit, 0x8F))
        {
            return 0;
        }
    }

    return sub_005DD480(pUnit, nAiSpecialState) != 0;
}

// 0x0056E370
int __fastcall sub_6FD15320(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg)
{
    if (sub_00645680_CanUnitCorpseBeSelected(pUnit))
    {
        return UNITFINDS_TestUnit(pUnit, pArg);
    }

    return 0;
}

// 0x0056E450
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    nMissileId = 0;
    int nY = 0;
    D2_ASSERT(pMissilesTxtRecord, 4737);

    if (pRoom)
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nMissileId, &nY);
        if (nMissileId && nY)
        {
            return !COLLISION_CheckMaskWithSizeXY(pRoom, nMissileId, nY, pMissilesTxtRecord->nSize, pMissilesTxtRecord->nSize, 5);
        }
    }
    return 0;
}

// 0x0056E510
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit)
{
    return UNITS_GetMeleeRange(pUnit) + 4;
}

// 0x0056E520
void __fastcall SKILLS_ApplyAttackRateModifier(D2UnitStrc* pUnit, int nAttackRate)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, STAT_ATTACKRATE, nAttackRate, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 0x12AB);
    }
}

// 0x0056E580
void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_MONSTER)
    {
        if (pOwner == pUnit)
        {
            AIGENERAL_DetachOwnedMinions(pUnit);
        }
        else
        {
            AIGENERAL_FreeMinionList(pUnit);
        }
    }
}

// 0x0056E5B0
int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord(pUnit->dwClassId);
            if (pCharStatsTxtRecord)
            {
                return pCharStatsTxtRecord->nWalkSpeed << 8;
            }
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                return pMonStatsTxtRecord->nVelocity << 8;
            }
        }
    }

    return 0x600;
}

// 0x0056E780
int __fastcall sub_6FD10360(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs)
{
    if (!pCallback)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    const int nDistanceSq = nDistance * nDistance;
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (int i = 0; i < nNumRooms; ++i)
    {
        if (!(nFlags & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (sub_0056B770_IsRoomInRange(ppRoomList[i], nX, nY, nDistance))
            {
                for (D2UnitStrc* j = ppRoomList[i]->pUnitFirst; j; j = j->ptRoomNext)
                {
                    if (nDistanceSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(j), UNITS_GetUnitYPosition(j)) && sub_6FD0FA00(pUnit, j, nFlags))
                    {
                        pCallback(j, pArgs);
                    }
                }
            }
        }
    }

    return 1;
}

// 0x0056E900
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 1157);
        SKILLS_RefreshPassiveSkills(pUnit);

        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
        }
    }
}

// 0x0056ECB0
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX + UNITS_GetUnitXPosition(pUnit);
    missileParams.nY = nY + UNITS_GetUnitYPosition(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    if (nTargetX && nTargetY)
    {
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
    }
    else if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    if (missileParams.nTargetX && missileParams.nTargetY)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            const int nToHit = STATLIST_UnitGetStatValue(pUnit, STAT_TOHIT, 0);
            if (nToHit)
            {
                missileParams.nAttBonus = nToHit;
                missileParams.dwFlags |= 0x1000;
            }
        }

        if (!bCheckItemQuantity || pUnit->dwUnitType || sub_6FD118C0(pGame, pUnit) > 0)
        {
            return MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
    return 0;
}

// 0x0056EE90
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bSkipCheck)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x420;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = nX + UNITS_GetUnitXPosition(pUnit);
    missileParams.nY = nY + UNITS_GetUnitYPosition(pUnit);
    missileParams.nMissile = nMissileId;

    if (nTargetX && nTargetY)
    {
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
    }
    else if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    if (!bSkipCheck || pUnit->dwUnitType != UNIT_PLAYER || sub_6FD118C0(pGame, pUnit) > 0)
    {
        return MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
    return 0;
}

// build: context D2GAME_SKILLS_SetDelay_6FD11C00
static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay)
{
    const int nExpireFrame = nDelay + pGame->dwGameFrame;
    if (pUnit && !pUnit->dwUnitType && nDelay)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x79);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, pUnit->dwUnitType, pUnit->dwUnitId);
            if (!pStatList)
            {
                return;
            }
            STATLIST_SetState(pStatList, 0x79);
            STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, 0x79, 1);
        }
        D2COMMON_10476(pStatList, nExpireFrame);
        sub_005417D0_DirectDated(pGame, pUnit, 12, nExpireFrame, 0, 0);
    }
}

// 0x0056F020
void __fastcall sub_6FD11BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nSkillDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDelay, nSkillId, nSkillLevel);
        if (nSkillDelay > 0)
        {
            D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nSkillDelay);
        }
    }
}

static __forceinline int sub_0056F1F0_DrainTargetItemDurability(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056F1F0
int __fastcall SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget;

    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            return 0;
        }

        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (!pDamage)
        {
            return 1;
        }

        if (pDamage->wResultFlags & 1)
        {
            UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
        }
    }

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            return 0;
        }

        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (!pDamage)
        {
            return 1;
        }

        if (pDamage->wResultFlags & 1)
        {
            const int nFormula = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
            const int nLength = nFormula < 1 ? 1 : nFormula;

            const int nExpireFrame = pGame->dwGameFrame + nLength;
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
                if (!pStatList)
                {
                    return 1;
                }
            }

            sub_005417D0_DirectDated(pGame, pTarget, 0xC, nExpireFrame, 0, 0);
            STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
            sub_006252D0((Obj006252D0*)pStatList, pSkillsTxtRecord->wAuraTargetState);
            D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
            sub_00625CE0((Obj00625CE0*)pStatList, (unsigned int)sub_6FD10E50);
            sub_6FCFE0E0(pTarget, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
        }
    }

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 4u, 0, nUnitType, nUnitGUID);
            if (!pStatList)
            {
                return 1;
            }

            sub_006252D0((Obj006252D0*)pStatList, pSkillsTxtRecord->nAuraState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            sub_00625CE0((Obj00625CE0*)pStatList, (unsigned int)sub_6FD10E50);
        }

        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
        sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return sub_0056F1F0_DrainTargetItemDurability(pGame, pUnit);
}

// 0x0056F460
int __fastcall SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (!bIsLeftHandItem)
        {
            if (nBodyLoc == 5)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            }
            else
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            }
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 125, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pWeapon, 38))
    {
        pMissile = sub_6FD11710(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = sub_6FD11420(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    sub_0056C600_ApplyThrowBonuses(pUnit, pMissile, pWeapon);
    return 1;
}

// 0x0056F550
int __fastcall SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (bIsLeftHandItem)
        {
            if (nBodyLoc == 5)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            }
            else
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            }
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 125, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pWeapon, 38))
    {
        pMissile = sub_6FD11710(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = sub_6FD11420(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    sub_0056C600_ApplyThrowBonuses(pUnit, pMissile, pWeapon);
    return 1;
}

// 0x0056FCB0
void __fastcall sub_0056FCB0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillIdArg, int a4)
{
    if (nSkillIdArg == -1)
    {
        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        if (pSkill)
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xCBB);
            const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[5 >> 3] & gdwBitMasks[5 & 7] && !SUNIT_IsDead(pUnit))
            {
                sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                sub_6FD13260(pGame, pUnit, nSkillId, nSkillLevel, 1);
                return;
            }
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, -1);
    }
    else if (nSkillIdArg > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillIdArg);
        if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        if (!STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        if (SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillIdArg) && nSkillIdArg == STATLIST_GetStatValue(pStatList, 0x15E, 0))
        {
            sub_0056F7F0(pGame, pUnit, nSkillIdArg, nSkillLevel, 1, 0, 0);
            sub_6FD13260(pGame, pUnit, nSkillIdArg, nSkillLevel, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, nSkillIdArg);
        }
    }
}

// 0x0056FE40
void __fastcall sub_0056FE40(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    if (SUNIT_IsDead(pUnit))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    const int nAura = STATLIST_UnitGetStatValue(pUnit, 151, nSkillId);
    if (nAura <= 0)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 9, a3);
        return;
    }

    sub_0056F7F0(pGame, pUnit, nSkillId, nAura, 1, 1, 0);
    sub_6FD13330(pGame, pUnit, a3, nSkillId, nAura, 0);
}

// 0x00570360
void __fastcall sub_00570360(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const int nClassId = pUnit->dwClassId;
    const int nSkillCount = SKILLS_GetPlayerSkillCount(nClassId);
    int nSkillPoints = 0;
    for (int i = 0; i < nSkillCount; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (pSkill)
        {
            nSkillPoints += SKILLS_GetSkillLevel(pUnit, pSkill, 0);
            D2GAME_SetSkills_6FD14C60(pUnit, nSkillId, 0, 1);
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 4257), pUnit, nSkillId, 0, 1);
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nSkillPoints, 0);
    D2GAME_UpdatePlayerVitals_6FC4B240(pGame, pUnit);
    D2GAME_UpdatePlayerItems_6FC4BB90(pGame, pUnit, 1);
}

// 0x00570530
void __fastcall sub_00570530_StatRemoveCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (STATES_CheckState(pUnit, 0x36))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType == 1)
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnitInline(pUnit), 0);
    }

    sub_6FD10E50(pUnit, nState, pStatList);
}
