#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2ClientGame.h"
#include "D2Records.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2Drlg.h"
#include "D2Constants.h"
#include "D2DrlgMaps.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"
#include "D2LevelIds.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2GfxLightStrc;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MissilesTxt;

struct D2StatesTxt;

struct D2MissileStrc;

struct D2UnitSfxNodeStrc;

struct D2SetItemsTxt;

struct D2LevelSpeechStrc;

union D2SeedStrc;

struct D2CltUnitEventStrc;

struct D2CltRateStrc;

struct D2CltMissileFindArgStrc;

struct D2CltMissileModeStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2CoordStrc;

struct D2ItemsTxt;

struct D2PathPointStrc;

struct D2ScatterRateStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2LevelSpeechStrc
{
    int nLevels[10];
    int nCondition;
    unsigned short f_2C;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern const int gaEffectRingOffsetY[16]; // 0x006DAF08

extern const int gaEffectRingOffsetX[16]; // 0x006DAF48

extern D2LevelSpeechStrc* gapLevelSpeeches[20]; // 0x0072A2C4

extern int gnScreenWidth; // 0x0071146C

extern int gnScreenHeight; // 0x00711470

extern void* gpGlobal_007A0634; // 0x007A0634

extern unsigned int gdwFadeTick; // 0x007C89CC

int __cdecl sub_0044DB00(); // 0x0044DB00

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall sub_00474470_ReleaseLight(D2GfxLightStrc* pLight); // 0x00474470

int __fastcall SOUNDHDR_GetGroupStart(int nId); // 0x00481890

unsigned char __fastcall SOUNDHDR_GetGroupSize(int nId); // 0x004818C0

int __fastcall TEXT_TestQuestCondition(int nCondition); // 0x004A4180

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __cdecl sub_004B9C20_IsSpeechPlaying(); // 0x004B9C20

int __fastcall sub_004B9CA0_GetHintIdByKey(void* pKey); // 0x004B9CA0

void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall SKILLS_CallStartSkill(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6660

int __fastcall SKILLS_DoClientSkill(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6680

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nId); // 0x004CB9C0

D2UnitStrc* __fastcall GFXUTIL_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

int __cdecl sub_004DF880(); // 0x004DF880

int __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pItem, int nArg1, int nArg2, int nArg3, int nProp, int nArg5, int nArg6, int nArg7); // 0x004E60A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall sub_0061C0B0(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0

int __stdcall sub_0061C0E0(void* pAct); // 0x0061C0E0

D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* pUnit); // 0x00621150

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

void __fastcall MISSILE_SpawnPeriodicMissile(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame, int nCount); // 0x004CE850

void __fastcall sub_004CECC0(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame); // 0x004CECC0

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

int __fastcall CUNIT_IsPetSkillTarget(D2UnitStrc* unit, D2UnitStrc* target); // 0x00464EC0

int __fastcall CUNIT_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464F70

struct D2CltRateStrc
{
    int nThreshold;
    int nRate;
    int nValue;
};

extern const D2CltRateStrc gaCltRateTable[6]; // 0x006DB848

extern const int gaQuadOffsetY[4]; // 0x006DB7D0

extern const int gaQuadOffsetX[4]; // 0x006DB7E0

extern const int gaCltDoRingOffsetY[64]; // 0x006DB5D0

extern const int gaCltDoRingOffsetX[64]; // 0x006DB6D0

void __fastcall MISSILE_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CEF50

void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile); // 0x004D3630

void __fastcall MISSILE_CltDoSeekTarget(D2UnitStrc* pMissile); // 0x004D37F0

void __fastcall MISSILE_CltDoOwnerStep(D2UnitStrc* pMissile); // 0x004D3070

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nState); // 0x0063A7B0

D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall GFXUTIL_GetMotionFirstParam(D2UnitStrc* pUnit); // 0x004DA320

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0

int __stdcall sub_0064A3E0_GetMissileClassId(D2UnitStrc* pMissile); // 0x0064A3E0

int __stdcall sub_0064A510_GetSubMissile(D2UnitStrc* pMissile); // 0x0064A510

int __stdcall sub_0064A570_GetSubMissileCount(D2UnitStrc* pMissile); // 0x0064A570

int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __fastcall SKILLS_ScatterRequestsAroundTarget(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel); // 0x004C7700

void __fastcall MISSILE_SpawnRingAround(D2UnitStrc* pMissile, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CE140

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

struct D2CltMissileFindArgStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

struct D2CltMissileModeStrc
{
    D2UnitFindCallback pfUnitFindCallback;
    int nCollisionMask;
};

extern D2CltMissileModeStrc gaCltMissileModes[]; // 0x0072A350

int __stdcall sub_0064A640(D2UnitStrc* pMissile); // 0x0064A640

int __stdcall sub_004DA6B0_TestMotionFlags(D2UnitStrc* pUnit); // 0x004DA6B0

void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate); // 0x00621330

int __cdecl GAME_GetPathFrame(); // 0x0044DB10

void __stdcall sub_00650840(D2UnitStrc* pUnit, int nValue); // 0x00650840

unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0

int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints); // 0x00648F40

D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0

extern int gnAutomapWidth; // 0x007A5220

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930

D2UnitStrc* __fastcall MISSILE_SpawnAtRandomUnitInRange(D2UnitStrc* pMissile, int nArg1, int nArg2, int nMissile); // 0x004CE320

void __fastcall MISSILE_InitCltParamMotion(D2UnitStrc* pMissile); // 0x004CE420

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

extern const D2CltRateStrc gaCltRateJitter[4]; // 0x006DB890

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pUnit); // 0x0064A210

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pUnit); // 0x0064A280

extern "C" int __stdcall sub_0064A380(D2UnitStrc* pUnit); // 0x0064A380

extern "C" int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);

struct D2ScatterRateStrc
{
    int nFrames;
    int nRateA;
    int nRateB;
};

extern const D2ScatterRateStrc gaScatterRates[4]; // 0x006DB8CC

typedef void (__fastcall* D2CltDoFunc)(D2UnitStrc* pMissile);

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern D2CltDoFunc gpfnCltDoFuncs[]; // 0x0072A398

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

void __fastcall DLIGHTMAP_SetLightSize(D2GfxLightStrc* pLight, int nSize); // 0x00474290

int __fastcall sub_00479150_FindRosterIndex(int nUnitId); // 0x00479150

enum
{
    CLTDO_TIMING_FRAME = 150,
    CLTDO_TIMING_ARG = 25,
    CLTDO_TIMING_LENGTH = 4000,
    CLTDO_SOUND_FRAME = 50,
    CLTDO_SOUND_ID = 0x121E,
    CLTDO_SLOW_FRAME = 8,
    CLTDO_FAST_FRAME = 0x23,
    CLTDO_SLOW_FLAG = 0x100,
};

int gaLevelVisited[1024]; // 0x007C78B8

int gnLastLevelId; // 0x007C88CC

unsigned char gnRoomColorBlue; // 0x007C8A6C

unsigned char gnRoomColorGreen; // 0x007C8A6D

unsigned char gnRoomColorIntensity; // 0x007C8A6E

unsigned char gnRoomColorRed; // 0x007C8A6F

typedef char cc_M439_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

typedef char cc_M338_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

void __fastcall MISSILE_SpawnFollowUp(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);             // 0x004CE050

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall SKILLS_CreateSpiralMissiles(int nCount, D2MissileStrc* pMissileParams); // 0x004C71F0

void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused); // 0x004CCCC0

extern const int gaCltHitRingOffsetY[8];                                                                 // 0x006DAF88

extern const int gaCltHitRingOffsetX[8];                                                                 // 0x006DAFA8

void __stdcall GFXUTIL_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1);                   // 0x004DA2F0

void __fastcall MISSILE_ClearMotionFlagTwo(D2UnitStrc* pMissile);                                                         // 0x004DA340

void __fastcall SKILLS_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0

void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile);                                          // 0x004E2ED0

struct D2RequestStrc;

struct D2MissileScanArgStrc;

struct D2SpawnOffsetMissileView;

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    D2UnitStrc* pOtherUnit;
    int unk0x0C;
    int nArg0;
    int nArg1;
    int nArg2;
    int nArg5;
    int nArg6;
    int nArg7;
    int unk0x28;
    int nArg3;
    int nArg4;
    int unk0x34[8];
    void* pfCallback;
    int nIndex;
};

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

int __stdcall sub_006488C0_PathGetX(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall sub_00648900_PathGetY(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall sub_00649030_SetPathFlag40(D2DynamicPathStrc* pPath, int bClear); // 0x00649030

struct D2MissileScanArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pMissile;
    int nSkillId;
    int nSkillLevel;
    int f_10;
    int f_14;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

int __fastcall SKILLS_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __fastcall MISSILE_HitScanCallback(void* pArg, D2UnitStrc* pUnit); // 0x004CFFA0

extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);

struct D2SpawnOffsetMissileView
{
    void __thiscall SKILLS_SpawnOffsetMissile(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x004D16C0
};

void __cdecl GFXUTIL_DrawFadeBox(); // 0x004DC000

struct D2CltHitPatternStrc
{
    int nCount;
    int aIndex[4];
};

extern const int gaCltHitOffsetX[8];                                                               // 0x006DAFC8

extern const int gaCltHitOffsetY[8];                                                               // 0x006DAFE8

extern const D2CltHitPatternStrc gaCltHitPatterns[3];                                              // 0x006DB008

void __fastcall sub_004CDDB0(D2UnitStrc* pUnit, const int* pArg, int nArg1, int nArg2, int nArg3, int nArg4);

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

extern const int gaCollisionBurstMissiles[]; // 0x0072A33C


void __fastcall MISSILE_InitMotion(D2UnitStrc* pMissile);                                              // 0x004CE4B0

D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile);                                             // 0x0064A3B0


unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50

extern "C" const char gszMissileFile_006DAEF4[]; // 0x006DAEF4

void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690

void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile); // 0x004D66E0

static void __stdcall MISSILE_SpawnScattered(int nRange, int nMissile, D2UnitStrc* pMissile); // 0x004D1300

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

void __fastcall MISSILE_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nOuterStep, int nInnerStep, int nLoops); // 0x004CEFE0

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}


void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0

void __fastcall MISSILE_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0

static inline unsigned __int64 SEED_RollRandomNumber64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline unsigned __int64 SEED_RollNextHL_Inline(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

D2UnitStrc* __fastcall WARDENCLIENT_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A400

extern const int gaRing5OffsetX[]; // 0x006DB0EC

extern const int gaRing5OffsetY[]; // 0x006DB0D8

extern const int gaRing18OffsetX[]; // 0x006DB090

extern const int gaRing18OffsetY[]; // 0x006DB048

static int __stdcall sub_004CC800_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

struct D2StormPhaseStrc { int nFrameLimit,nPeriod,bSpawn; };

extern D2StormPhaseStrc gaBaalStormPhases[5]; // 0x006DB908

int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380

D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc*,int,int); // 0x0065A620

// build: context MISSILE_RollInRange
static inline int MISSILE_RollInRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin < nMax)
    {
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }

    return nMin;
}

struct D2StatListStrc;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

typedef int (__fastcall* CLTHITFUNC)(D2UnitStrc* pMissile, D2UnitStrc* pTarget);

extern "C" unsigned char gbChargeMissileMask_006CE270;                                                     // 0x006CE270

extern int gnCltHitFuncCount;                                                                      // 0x0072A504

extern CLTHITFUNC gpfnCltHitFuncs[];                                                                // 0x0072A508

void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00

void* __fastcall MISSILE_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900

void __fastcall sub_004CD380_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004CD380

int __stdcall GFXUTIL_GetMotionAX(D2UnitStrc* pUnit);                                             // 0x004DA110

int __stdcall GFXUTIL_GetMotionAY(D2UnitStrc* pUnit);                                             // 0x004DA130

void __stdcall sub_004DA640_SetMotionFlag1(D2UnitStrc* pUnit);                                              // 0x004DA640

int __fastcall sub_004DC210_RunCltUnitEvents(int nType, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nArg);   // 0x004DC210

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

int __stdcall sub_0064A3E0(D2UnitStrc* pMissile);                                                         // 0x0064A3E0

int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                           // 0x0064A470

static int sub_004CD310_UseMissileCharge(D2UnitStrc* pMissile);                                            // 0x004CD310

static inline int UNITS_TestFlagBit(D2UnitStrc* pUnit, int nBit)
{
    if (pUnit)
    {
        return (pUnit->dwFlags >> nBit) & 1;
    }
    return 0;
}

static int sub_004CD310_UseMissileCharge(D2UnitStrc* pMissile);

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(D2UnitStrc* pItem)
{
    int nFileIndex = ITEMS_GetFileIndex(pItem);
    if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nFileIndex];
    }

    return 0;
}

inline int UNITS_IsAsyncInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 21) & 1;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumberInline
static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    return (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nMissileId] : 0;
}

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static D2MissilesTxt* GetMissilesTxtRecord_Inline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}

static D2MissilesTxt* GetUnitMissilesTxt_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return GetMissilesTxtRecord_Inline(pUnit->dwClassId);
}

static int GetUnitXPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nYPos;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

extern "C" int __stdcall sub_0064A300(D2UnitStrc* pUnit); // 0x0064A300

void __fastcall DLIGHTMAP_ResetLightSize(D2GfxLightStrc* pLight, int nSize); // 0x004742D0

void* __fastcall ROSTER_GetLinkFirst(D2UnitStrc* pUnit); // 0x004CA990

#define UNIT_INVALID 6

struct D2GfxEntryStrc;

struct D2CltMissileSpawnArgStrc;

struct D2AreaScanStrc;

extern D2DrlgActStrc* gpAct; // 0x007A0634

void __stdcall MISSTREAM_FreeMissileStream(D2UnitStrc* pMissile); // 0x00663D90

void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile); // 0x0064A150

void __stdcall PARTICLE_FreeGfxMotion(D2UnitStrc* pUnit); // 0x004DA080

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10

void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460

void __fastcall MISSILE_CreateBurstAt(D2UnitStrc* pMissile, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CED60

void __fastcall PLRSKILLS_SkillSeqDoBackward(D2UnitStrc* pUnit, int nArg); // 0x004D85C0

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

struct D2CltMissileSpawnArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkill;
    int nSkillLevel;
    int nMaxCount;
    int nMissile;
};

struct D2AreaScanStrc
{
    int unk0x00;
    int nCount;
    D2CltMissileSpawnArgStrc* pArg;
};

int __fastcall sub_004CC790_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790

void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000

int __fastcall MISSILE_CreateMissileFan(D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissile, int nSkill, int nSkillLevel, int nStep); // 0x004D01D0

extern const int gaHitRing64OffsetY[64]; // 0x006DB140

extern const int gaHitRing64OffsetX[64]; // 0x006DB240

extern const int gaRingOffsetY_006DB340[64]; // 0x006DB340

extern const int gaRingOffsetX_006DB440[64]; // 0x006DB440

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

extern "C" void __stdcall sub_006488A0(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

#define TEST_OFFSET 0

#define LIGHT_LIMIT 60

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);

void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce);

struct D2OwnerStrc_004CA990;

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);         // 0x0064CB30

#define SPAWN_FLAGS 0x2001

#define COLLISION_MASK 0x45

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290

inline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
}

static inline int sub_CanHitUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    return MONSTERREGION_CheckMonStats2Flag(nClassId, 0xB);
}

static inline unsigned __int64 SEED_RollNext64(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline unsigned __int64 SEED_RollNextHL(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (unsigned __int64)(unsigned int)(lPrev >> 32) + (unsigned __int64)(unsigned int)lPrev * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned __int64 SEED_RollHL64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int sub_004D2610_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? sub_00648900_PathGetY(pUnit->pDynamicPath) : 0;
}

// 0x004D3630
void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
        {
            MISSILE_CltDoDefault(pMissile);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pMissile);
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = pOwner;
        tParams.nX = nX;
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        D2MissilesTxt* pSubMissileTxtRecord = SKILLS_GetMissilesTxtRecord(tParams.nMissile);
        if (!pSubMissileTxtRecord)
        {
            MISSILE_CltDoDefault(pMissile);
            return;
        }

        const short nRange = pSubMissileTxtRecord->wRange;
        if (nRange)
        {
            tParams.dwFlags = 0x8021;
            tParams.nRange = nRange;
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] >= 0)
        {
            if (pMissilesTxtRecord->wCltSubMissile[2] >= 0)
            {
                switch (SEED_RollLimitedRandomNumber(&pMissile->pSeed, 3))
                {
                case 0:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                    break;
                case 1:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[2];
                    break;
                }
            }
            else if (!SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2))
            {
                tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            }
        }

        const int nChance = pMissilesTxtRecord->dwCltParam[0];
        if (!nChance || SEED_RollLimitedRandomNumber(&pMissile->pSeed, nChance))
            tParams.dwFlags |= 0x4000;

        tParams.nTargetX = CLIENTS_GetUnitX(pMissile);
        tParams.nTargetY = CLIENTS_GetUnitY(pMissile);
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
        if (pNew)
        {
            const int nPrecisionX = UNITS_GetPrecisionX(pMissile);
            const int nPrecisionY = UNITS_GetPrecisionY(pMissile);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            PATH_SetPrecisionX(pPath, nPrecisionX);
            PATH_SetPrecisionY(pPath, nPrecisionY);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < sgptDataTables->nSkillsTxtRecordCount && nSkillId >= 0)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

inline unsigned int SEED_RollLimitedRandomNumber_004D1EC0(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        if ((nMax - 1) & nMax)
        {
            return (unsigned int)lSeed % nMax;
        }
        return (unsigned int)lSeed & (nMax - 1);
    }
    return 0;
}

inline int UNITS_GetClassId_004D1EC0(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// build: symbol ?MISSILE_SpawnSubMissile@* 0x004CE530
static D2UnitStrc* __stdcall MISSILE_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 2;
    tMissile.nMissile = nMissile;
    tMissile.pOwner = pOwner;
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);

    const int nMax = 2 * nSpread + 1;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    tMissile.nTargetX = SEED_RollLimitedRandomNumberInline(pSeed, nMax) - nSpread;
    tMissile.nTargetY = SEED_RollLimitedRandomNumberInline(pSeed, nMax) - nSpread;
    int nX = tMissile.nTargetX;
    const int nY = tMissile.nTargetY;
    if (!nX && !nY)
    {
        nX = SEED_RollLimitedRandomNumber(pSeed, nSpread - 1) + 1;
        tMissile.nTargetX = nX;
    }

    D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
    if (pNew)
    {
        MISSILE_SetTargetX(pNew, nX);
        MISSILE_SetTargetY(pNew, nY);
    }

    return pNew;
}

// build: symbol ?MISSILE_SpawnFragmentRing@* 0x004D19D0
static void __stdcall MISSILE_SpawnFragmentRing(int nTargetUnitId, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_HFFRAGMENT1);
    int aOffsetX[14] = { -4, 2, 4, -3, -2, 3, 5, -3, -5, 5, -6, -1, 0, 6 };
    int aOffsetY[14] = { 6, 4, -4, -2, 1, 7, 0, 3, -4, -3, 4, -5, 5, -3 };
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x8102;
    tParams.nMissile = MISSILE_HFFRAGMENT1;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    for (int i = 0; i < 14; ++i)
    {
        const int nX = aOffsetX[i];
        const int nY = aOffsetY[i];
        tParams.nTargetX = nX;
        tParams.nTargetY = nY;
        const int nAbsX = nX < 0 ? -nX : nX;
        const int nAbsY = nY < 0 ? -nY : nY;
        const int nDistance = (nX >= nY ? nAbsX + 2 * nAbsY : nAbsY + 2 * nAbsX) >> 1;
        tParams.nRange = pMissilesTxtRecord->wRange * nDistance / 6;
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, nTargetUnitId);
            MISSILE_SetTargetY(pNew, SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10);
        }
    }
}

// 0x004D1300
static void __stdcall MISSILE_SpawnScattered(int nRange, int nMissile, D2UnitStrc* pMissile)
{
    const int nOffsetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    const int nOffsetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x21;
    tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile);
    tParams.nY = UNITS_GetUnitYPosition(pMissile);
    tParams.nTargetX = UNITS_GetUnitXPosition(pMissile) + nOffsetX;
    tParams.nTargetY = UNITS_GetUnitYPosition(pMissile) + nOffsetY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = nMissile;
    MISSILE_CreateClientMissile(&tParams);
}

// 0x004D66E0
void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(MISSILE_IZUAL_CONTROL);
    MISSILE_SpawnScattered(10, MISSILE_IZUAL_MIST_LOOP, pMissile);
    if (nRemaining < pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[0] && nRemaining > pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[1])
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        if (pOwner)
        {
            const int nTargetX = CLIENTS_GetUnitX(pOwner) + SEED_RollLimitedRandomNumber(pSeed, 10) - 5;
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.nTargetX = nTargetX;
            tParams.dwFlags = 0x20;
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nTargetY = SEED_RollLimitedRandomNumber(pSeed, 10) - 5 + CLIENTS_GetUnitY(pOwner);
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = MISSILE_IZUAL_LIGHTNING;
            D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
            if (pNew)
            {
                int nRoll = SEED_RollLimitedRandomNumber(pSeed, 3);
                nRoll += 3;
                sub_004DA250(pNew, 0, 0, -nRoll, 1);
                SKILLS_SetBallistic(pNew, 0, 0xF);
                MISSILE_ClearMotionFlagTwo(pNew);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

static inline unsigned int SEED_RollUnitSeedInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

static inline void RotateOffsets(int* pX,int* pY)
{
    const int nOldX=*pX;
    const int nNegY=-*pY;
    __assume(nNegY != (-2147483647 - 1));
    *pX=(nNegY+nOldX)/2;
    *pY=(nOldX+*pY)/2;
}

static inline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
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

static __forceinline unsigned int SEED_RollLimitedRandomNumberForceInl(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberInline(pSeed) % nMax;
    }

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x004D6130
void __fastcall sub_004D6130_CltDoRandomSubMissile3(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nCount = 0;
    do
    {
        if (pMissilesTxtRecord->wCltSubMissile[nCount] < 0 || pMissilesTxtRecord->dwCltParam[nCount + 1] <= 0)
        {
            break;
        }

        ++nCount;
    }
    while (nCount < 3);

    if (nCount <= 0)
    {
        sub_004D2D70_CltMissileHit(pMissile, 0, 0);
        return;
    }

    if (nFrames < pMissilesTxtRecord->dwCltParam[0])
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    SEED_InitLowSeed(&pMissile->pSeed, UNITS_GetXPositionForceInl(pMissile));

    const int nIndex = SEED_RollLimitedRandomNumberForceInl(&pMissile->pSeed, nCount);
    if (nFrames % pMissilesTxtRecord->dwCltParam[nIndex + 1])
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2MissileStrc tMissile = {};
    tMissile.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[nIndex];
    tMissile.nSkillLevel = nSkillLevel;

    D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
    if (pNew)
    {
        sub_004D2D70_CltMissileHit(pNew, 0, 1);
    }

    MISSILE_CltDoCommon(pMissile);
}

// build: context sub_004CD310_UseMissileCharge
static int sub_004CD310_UseMissileCharge(D2UnitStrc* pMissile)
{
    int nResult = 3;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(sub_0064A3E0(pMissile));

    if (!(pMissilesTxtRecord->nMissileFlags[0] & gbChargeMissileMask_006CE270))
        return nResult;
    const int nValue = STATLIST_UnitGetStatValue(pMissile, STAT_PIERCE_IDX, 0);
    if (nValue)
    {
        nResult = 2;
        STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, nValue - 1, 0);
    }

    return nResult;
}

