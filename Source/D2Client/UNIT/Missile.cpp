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

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420

int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

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

void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nId); // 0x004CB9C0

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

D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050

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

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6);

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

int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType);

int __fastcall sub_004CFFA0_HitScanCallback(void* pArg, D2UnitStrc* pUnit);

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

// 0x004C95E0
int __fastcall MISSILE_SkillStartAtTargetPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = nX;
    tMissileParams.nTargetY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    PATH_SetType(pPath, 0xE);
    D2Common_10142(pPath, pMissile, 0);
    return 1;
}

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

// 0x004CA060
int __fastcall MISSILE_DoSkillWithTempTarget(D2UnitStrc* pUnit, int nSkillId, int nArg, D2UnitStrc* pTarget, int nX, int nY, unsigned short nMode)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pOldTarget = CUNIT_GetPathTargetUnit(pUnit);
    int nOldX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    int nOldY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    int bFlag = (pUnit->dwFlags >> 6) & 1;
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    }

    int nResult = 0;
    if (pSkillsTxtRecord->nFlags[4] & gnBitMasks_006CE268[2])
    {
        int bToggled = 0;
        if (pTarget && CUNIT_IsDeadOrDying(pTarget) && STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
        {
            bToggled = 1;
            STATES_ToggleState(pTarget, 0x76, 0);
        }

        if (!SKILLS_CallStartSkill(pUnit, nSkillId, nArg, -1))
        {
            goto restore;
        }

        if (bToggled)
        {
            STATES_ToggleState(pTarget, 0x76, 1);
        }
    }

    if (pSkillsTxtRecord->wItemStartSound >= 0)
    {
        sub_004B9A00(pSkillsTxtRecord->wItemStartSound, pUnit, 0, 0, 0);
    }

    if (pSkillsTxtRecord->wItemCastOverlay >= 0 && pSkillsTxtRecord->wItemCastOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        GFX_AddUnitOverlay(pUnit, pSkillsTxtRecord->wItemCastOverlay, 2, 0, 0, 0, 0, 0);
    }

    nResult = SKILLS_DoClientSkill(pUnit, nSkillId, nArg, nMode);

restore:
    if (pOldTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nOldX, nOldY);
    }

    if (bFlag)
    {
        pUnit->dwFlags |= 0x40;
    }
    else
    {
        pUnit->dwFlags &= ~0x40;
    }

    return nResult;
}

// 0x004CA900
void* __fastcall MISSILE_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId)
{
    D2_ASSERT(pUnit, 0xC47);
    if (!sub_004DF880())
    {
        return 0;
    }

    int nGroup = SOUNDHDR_GetGroupStart(nId);
    int nCount = SOUNDHDR_GetGroupSize(nGroup);
    for (D2UnitSfxNodeStrc* pNode = (D2UnitSfxNodeStrc*)pUnit->pUnitSfxData; pNode; pNode = pNode->pNext)
    {
        void* pUnitSfx = pNode->pUnitSfx;
        int nHintId = sub_004B9CA0_GetHintIdByKey(pUnitSfx);
        if (nHintId >= nGroup && nHintId < nGroup + nCount)
        {
            return pUnitSfx;
        }
    }

    return 0;
}

// 0x004CC270
void __cdecl MISSILE_CheckLevelSpeech()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount || nLevelId == gnLastLevelId)
    {
        return;
    }

    gnLastLevelId = nLevelId;
    if (gaLevelVisited[nLevelId])
    {
        return;
    }

    D2LevelSpeechStrc* pEntry;
    for (int i = 0; i < 20; ++i)
    {
        pEntry = gapLevelSpeeches[i];
        if (!pEntry)
        {
            return;
        }

        for (int j = 0; j < 10; ++j)
        {
            int nLevel = pEntry->nLevels[j];
            if (!nLevel)
            {
                break;
            }

            if (nLevel == nLevelId)
            {
                goto found;
            }
        }
    }

    return;

found:
    for (int j = 0; j < 10; ++j)
    {
        int nLevel = pEntry->nLevels[j];
        if (!nLevel)
        {
            break;
        }

        gaLevelVisited[nLevel] = 1;
    }

    if (pEntry->nCondition && !TEXT_TestQuestCondition(pEntry->nCondition))
    {
        return;
    }

    D2_ASSERT(pPlayer, 0xCBB);
    unsigned int dwSfxTicks = pPlayer->dwSfxTicks;
    if (sub_0044DB00() - dwSfxTicks <= 0x3E)
    {
        return;
    }

    if (sub_004B9C20_IsSpeechPlaying())
    {
        return;
    }

    sub_004CB9C0_Request(pPlayer, pEntry->f_2C);
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

// 0x004CC870
void __fastcall MISSILE_InitFromOwner(D2UnitStrc* pMissile, int nInitArg)
{
    D2UnitStrc* pOwner = (D2UnitStrc*)nInitArg;
    if (!pMissile)
        return;

    D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pOwner)
        return;

    int nOffset = 0;
    if (pMissilesTxtRecord->dwCltParam[1] > 0)
        nOffset = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pMissilesTxtRecord->dwCltParam[1]) - pMissilesTxtRecord->dwCltParam[1] / 2;

    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nOffset);
    PATH_SetDirection(pMissile->pDynamicPath, PATH_GetDirection(pOwner->pDynamicPath));
    D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
    pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nAnimLen) << 8;
}

// 0x004CC950
static int MISSILE_GetSubMissileCount(D2MissilesTxt* pMissilesTxt, int nFrame)
{
    if (nFrame < 30)
    {
        return 1;
    }

    if (nFrame < 85)
    {
        return (nFrame - 15) / 4;
    }

    const int nRange = pMissilesTxt->wRange;
    const int nStart = nRange - 50;
    if (nFrame < nStart)
    {
        return 12;
    }

    if (nFrame < nRange)
    {
        return 12 - (nFrame - nStart) / 4;
    }

    return 1;
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

// 0x004CCA00
static void __stdcall MISSILE_SteerMissile(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = GetUnitMissilesTxt_Inline(pUnit);
    if (!pTxt)
        return;
    if (pTarget && CUNIT_IsDeadOrDying(pTarget))
        pTarget = 0;
    const int nFrames = (MISSILE_GetLevel(pUnit) - 1) * pTxt->wLevRange + pTxt->wRange;
    MISSILE_SetTotalFrames(pUnit, nFrames);
    MISSILE_SetCurrentFrame(pUnit, nFrames);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDistance;
    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
        MISSILE_SetTargetX(pUnit, 5);
        nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
    }
    else
    {
        const unsigned int dwOffset = MISSILE_GetTargetY(pUnit);
        const short nOffsetX = (short)dwOffset;
        const short nOffsetY = (short)(dwOffset >> 16);
        const int nX = nOffsetX + GetUnitXPosition_Inline(pUnit);
        const int nY = nOffsetY + GetUnitYPosition_Inline(pUnit);
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        MISSILE_SetTargetX(pUnit, 6);
        nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    }
    if (nDistance < 0x19)
        D2Common_10142(pPath, pUnit, 0);
}

// 0x004CCB50
static int MISSILE_SeekTarget(D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = GetUnitMissilesTxt_Inline(pUnit);
    if (!pTxt)
        return 1;
    const int nRange = pTxt->dwParam[1];
    if (MISSILE_GetTargetX(pUnit) & 4)
        return 1;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner)
        return 1;
    MISSILE_SteerMissile(sub_004C5EB0_FindDestination(pOwner, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nRange, 3, -1, 0), pUnit);
    return 0;
}

// 0x004CCBE0
int __fastcall MISSILE_UpdateGuidedMissile(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner || CUNIT_IsDeadOrDying(pOwner))
        return 1;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        return 1;
    const int nFlags = MISSILE_GetTargetX(pUnit);
    if (!pTarget && (nFlags & 4))
        return 1;
    if (nFlags & 1)
    {
        if (pTarget && pTarget != PATH_GetTargetUnit(pPath))
            return 0;
    }
    else if (nFlags & 2)
    {
        if (sub_0064A380_GetRemainingFrames(pUnit) <= 0)
            return MISSILE_SeekTarget(pUnit) != 0;
        return ((unsigned char)nFlags >> 2) & 1;
    }
    return 1;
}

// 0x004CCD20
int __fastcall MISSILE_CltHitSpiral(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
        return 1;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
        return 1;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.nX = CLIENTS_GetUnitX(pMissile);
    tParams.nY = CLIENTS_GetUnitY(pMissile);
    tParams.pOwner = pOwner;
    tParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;
    int nCount = (MISSILE_GetLevel(pMissile) - 1) * pMissilesTxtRecord->dwCltHitPar[1] + pMissilesTxtRecord->dwCltHitPar[0];
    if (nCount <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
            return 1;
        nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
        if (nCount < 1)
            nCount = 1;
    }
    SKILLS_CreateSpiralMissiles(nCount, &tParams);
    return 1;
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

// 0x004CCE40
int __fastcall MISSILE_CltHitSpiralGrid(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pMissilesTxtRecord->dwCltHitPar[0] <= 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 3;
    tMissileParams.nX = CLIENTS_GetUnitX(pMissile);
    tMissileParams.nY = CLIENTS_GetUnitY(pMissile);
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    if (pMissilesTxtRecord->dwCltHitPar[1])
    {
        tMissileParams.pInitFunc = (MissileInitFunc)sub_004E2ED0_VolleyCallback;
    }
    SKILLS_CreateSpiralMissiles(pMissilesTxtRecord->dwCltHitPar[0], &tMissileParams);
    return 1;
}

// 0x004CD1C0
static void sub_004CD1C0_FlickerLight(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissile->nSeqCurrentFramePrecise & 0x300)
        return;
    D2GfxLightStrc* pLight = pMissile->pLight;
    if (!pLight)
        return;
    if (DLIGHTMAP_GetLightSize(pLight) < pMissilesTxtRecord->nLight)
        return;
    const int nRadius = pMissilesTxtRecord->nLight + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nFlicker);
    DLIGHTMAP_SetLightSize(pLight, nRadius);
}

// build: symbol ?MISSILE_CltDoMissile@* 0x004D2C70
void __fastcall MISSILE_CltDoMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    if (pMissilesTxtRecord->nFlicker)
        sub_004CD1C0_FlickerLight(pMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        pRoom = sub_00463740_FindRoomAtPoint(0, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[10 >> 3] & gdwBitMasks[10 & 7]) && DUNGEON_IsRoomInTown(pRoom))
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    const short nCltDoFunc = pMissilesTxtRecord->wCltDoFunc;
// build: symbol ?gnCltDoFuncs@* 0x0072A34C
    if (nCltDoFunc > 0 && nCltDoFunc < gnCltDoFuncs)
        gpfnCltDoFuncs[nCltDoFunc](pMissile);
}

// 0x004D33E0
void __fastcall MISSILE_CltDoOnScreen(D2UnitStrc* pMissile)
{
    if (UNITS_IsAtEndOfFrameCycle(pMissile))
    {
        CUNIT_MarkUnitDead(pMissile);
// build: symbol ?gszMissileSourceFile@* 0x006DAEF4
        PATH_SetVelocity(pMissile->pDynamicPath, 0, gszMissileSourceFile, 0x7F);
    }

    int nX = UNITS_GetClientCoordX(pMissile) - PLAYER_GetScreenOffsetX();
    if (nX >= 0 && nX <= gnAutomapWidth)
    {
        int nY = UNITS_GetClientCoordY(pMissile) - PLAYER_GetScreenOffsetY();
        if (nY >= 0 && nY <= gnAutomapHeight_007A521C + 0x40)
        {
            MISSILE_SetCurrentFrame(pMissile, 0x80);
            MISSILE_CltDoCommon(pMissile);
            return;
        }
    }

    sub_004D2D70_CltMissileHit(pMissile, 0, 0);
}

// 0x004CE050
void __fastcall MISSILE_SpawnFollowUp(D2UnitStrc* pMissile, int nMissile, int nRange, int bFlag)
{
    if (!PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 5;
    if (nRange > 0)
    {
        tParams.nRange = nRange;
        tParams.dwFlags = 0x8005;
    }
    if (bFlag > 0)
        tParams.dwFlags |= 8;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.pOrigin = pMissile;
    tParams.nMissile = nMissile;
    tParams.nX = UNITS_GetUnitXPosition(pMissile);
    tParams.nY = UNITS_GetUnitYPosition(pMissile);
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    tParams.nSkillLevel = nLevel;
    tParams.nLoops = 2 * nLevel - 2;
    sub_004CD540_CreateMissile(&tParams);
}

// 0x004CE420
void __fastcall MISSILE_InitCltParamMotion(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nSpeed = MAX(pMissilesTxtRecord->dwCltParam[1], 1);
    const int nRange = nSpeed > pMissilesTxtRecord->dwCltParam[0] ? nSpeed : pMissilesTxtRecord->dwCltParam[0];
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nRange);
    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -nSpeed, 1);
    const int nFrames = nRange / nSpeed;
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);
}

// 0x004CEFE0
void __fastcall MISSILE_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nOuterStep, int nInnerStep, int nLoops)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    if (!nMissile)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x17;
    if (nLoops > 0)
    {
        missileParams.dwFlags = 0x1F;
        missileParams.nLoops = nLoops;
    }

    missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nMissile = nMissile;
    missileParams.nX = UNITS_GetUnitXPosition(pMissile);
    missileParams.nY = UNITS_GetUnitYPosition(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    int nStep = nInnerStep < 1 ? 1 : nInnerStep;
    for (int i = 0; i < 16; i += nStep)
    {
        missileParams.nTargetX = gaEffectRingOffsetX[i];
        missileParams.nTargetY = gaEffectRingOffsetY[i];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (nOuterStep > 0)
    {
        missileParams.nVelocity = pMissilesTxtRecord->dwParam[1] << 7;
        for (int i = 1; i < 16; i += nOuterStep)
        {
            missileParams.nTargetX = gaEffectRingOffsetX[i];
            missileParams.nTargetY = gaEffectRingOffsetY[i];
            sub_004CD540_CreateMissile(&missileParams);
        }
    }
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

// 0x004CF150
int __fastcall MISSILE_CltHitRing(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 2;
    tMissileParams.pOwner = pOwner;
    tMissileParams.pOrigin = pMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    int nStep = pMissilesTxtRecord->dwCltHitPar[0];
    if (nStep < 1)
    {
        nStep = 1;
    }

    for (int i = 0; i < 8; i += nStep)
    {
        tMissileParams.nTargetX = gaCltHitRingOffsetX[i];
        tMissileParams.nTargetY = gaCltHitRingOffsetY[i];
        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pSubMissile)
        {
            MISSILE_SetTargetX(pSubMissile, gaCltHitRingOffsetX[i]);
            MISSILE_SetTargetY(pSubMissile, gaCltHitRingOffsetY[i]);
        }
    }
    return 1;
}

// 0x004D3460
void __fastcall MISSILE_CltDoFollowUp(D2UnitStrc* pMissile)
{
    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        const int nMissileId = pMissile->dwClassId;
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
        {
            MISSILE_SpawnFollowUp(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, MISSILE_EvaluateMissileFormula(pMissile, sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwCltCalc, nMissileId, sub_0064A210(pMissile)));
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D34E0
void __fastcall MISSILE_CltDoParamCall(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    MISSILE_SpawnRingAround(pMissile, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->wCltSubMissile[0]);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3540
void __fastcall MISSILE_CltDoSubLoop(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nFrame = pMissile->nSeqCurrentFramePrecise >> 8;
    if (nFrame == pMissilesTxtRecord->nSubStart - 1)
    {
        pMissile->nSeqCurrentFramePrecise = (ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart) + nFrame) << 8;
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    if (sub_0064A380(pMissile) == pMissilesTxtRecord->nSubStart)
    {
        const int nNewFrame = pMissilesTxtRecord->nSubStart - 3;
        pMissile->nSeqCurrentFramePrecise = (nNewFrame < 0 ? 0 : nNewFrame) << 8;
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    if (sub_0064A380(pMissile) < pMissilesTxtRecord->nSubStart)
    {
        nFrame -= 2;
        pMissile->nSeqCurrentFramePrecise = (nFrame < 0 ? 0 : nFrame) << 8;
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3630
void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
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
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
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

// 0x004CD390
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (pMissilesTxtRecord && (short)pMissilesTxtRecord->wTravelSound >= 0)
    {
        void* pUnitSfx = MISSILE_FindUnitSfxInRange(pMissile, (short)pMissilesTxtRecord->wTravelSound);
        if (pUnitSfx)
        {
            sub_004BA790_ReleaseUnitSfx(pUnitSfx, pMissile, 0);
        }
    }

    D2GfxLightStrc* pLight = UNITS_ResetLightMap(pMissile);
    if (pLight)
    {
        sub_00474470_ReleaseLight(pLight);
    }

    if (UNITS_IsAsyncInline(pMissile))
    {
        sub_00465F00_RemoveClientUnit(pMissile->dwUnitId, pMissile->dwUnitType);
    }
    else
    {
        CUNIT_RemoveClientSideUnit(pMissile->dwUnitId, pMissile->dwUnitType);
    }
}

// 0x004CDBA0
D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x20;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nArg5;
    tRequest.nArg6 = nArg6;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004D5C10
void __fastcall MISSILE_CltDoVolcano(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwCltParam[1];
    if (nAuraRange <= 0)
    {
        const int nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        nAuraRange = (nCalc >= 1) ? nCalc : 1;
    }

    int nFrames = pMissilesTxtRecord->dwCltParam[0];
    if (nFrames <= 0)
    {
        nFrames = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nFrames < 1)
        {
            nFrames = 1;
        }
    }

    const int nRemainingFrames = MISSILE_GetRemainingFrames(pMissile);
    if (nRemainingFrames > pMissilesTxtRecord->dwCltParam[2] && nRemainingFrames < pMissilesTxtRecord->dwCltParam[3] && !(nRemainingFrames % nFrames))
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed, MISSILE_GetTargetX(pMissile));
        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        nX += CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile) + SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
        MISSILE_SubmitOffsetRequest(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, nX, nY, MISSILE_GetSkill(pMissile), nLevel, pMissilesTxtRecord->dwCltParam[4]);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004CDC30
D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    if (!nRange)
    {
        nRange = 30;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x521;
    tRequest.pUnit = pOwner;
    tRequest.nArg1 = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    tRequest.nArg2 = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg7 = nRange;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004D37F0
void __fastcall MISSILE_CltDoSeekTarget(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pMissile)))
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (MISSILE_GetTargetX(pMissile) & 1)
    {
        GFX_RefreshPathTarget(pMissile);
        D2UnitStrc* pTarget = PATH_GetTargetUnit(pMissile->pDynamicPath);
        if (pTarget && (CUNIT_IsDeadOrDying(pTarget) || (pOwner && !sub_00465C60_CheckUnitPair(pOwner, pTarget))))
        {
            pTarget = 0;
        }

        int nRate = pMissilesTxtRecord->dwCltParam[0];
        if (nRate <= 0)
        {
            nRate = 5;
        }

        if (pTarget && !(sub_0064A3B0_GetElapsedFrames(pMissile) % nRate))
        {
            const int nDistance = sub_006416D0_UnitEdgeDistance(pMissile, pTarget);
            if (nDistance >= 4 && nDistance <= 0x18)
            {
                D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D38D0
void __fastcall MISSILE_CltDoTimedSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) >= pMissilesTxtRecord->nCanDestroy && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nX = CLIENTS_GetUnitX(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        int nLoops = pMissilesTxtRecord->dwCltParam[0];
        missileParams.nLoops = nLoops < 1 ? 1 : nLoops;
        missileParams.pInitFunc = (MissileInitFunc)sub_004CC870_SubMissileCallback;
        missileParams.nInitArg = (int)pMissile;
        sub_004CD540_CreateMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3C40
void __fastcall MISSILE_CltDoRangeSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nMissile = pMissilesTxtRecord->wCltSubMissile[0];
    if (nMissile < pMissilesTxtRecord->wCltSubMissile[1])
    {
        nMissile += ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->wCltSubMissile[1] - nMissile + 1);
    }

    int nLevel = MISSILE_GetLevel(pMissile);
    nLevel /= MAX(pMissilesTxtRecord->dwCltParam[2], 1);
    int nCount = pMissilesTxtRecord->dwCltParam[0] + MAX(nLevel, 2);
    int nRange = MAX(pMissilesTxtRecord->dwCltParam[1] - nLevel, 3);
    D2UnitStrc* pNew = MISSILE_SpawnAtRandomUnitInRange(pMissile, nCount, nRange, nMissile);
    if (pNew)
    {
        MISSILE_InitCltParamMotion(pNew);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3D00
void __fastcall MISSILE_CltDoFrameEndFree(D2UnitStrc* pMissile)
{
    if (UNITS_IsAtEndOfFrameCycle(pMissile))
    {
        CUNIT_MarkUnitDead(pMissile);
        CUNIT_FreeLight(pMissile);
    }
    else
    {
        MISSILE_CltDoCommon(pMissile);
    }
}

// 0x004D3D30
void __fastcall MISSILE_CltDoTiming(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->dwCltParam[0] <= 0 || pMissilesTxtRecord->dwCltParam[1] <= 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (!sub_0064A3B0_GetElapsedFrames(pMissile))
    {
        int nFrames = pMissilesTxtRecord->dwCltParam[1];
        int nThird = nFrames / 3;
        int nOuter = nThird * 25000 / 25;
        int nInner = (nFrames - 2 * nThird) * 25000 / 25;
        sub_00476A80_StartTiming(pMissilesTxtRecord->dwCltParam[0], nOuter, nInner, nOuter);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3E00
void __fastcall MISSILE_CltDoTimedRequests(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[0])
    {
        GFXUTIL_SubmitMissileRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[1])
    {
        GFXUTIL_SubmitMissileRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    if (pMissilesTxtRecord->wCltSubMissile[2] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[2])
    {
        GFXUTIL_SubmitMissileRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[2], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4040
void __fastcall MISSILE_CltDoHoming(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pMissile);
    if (!pTarget)
    {
        pTarget = CUNIT_GetPathTargetUnit(pOwner);
        if (!pTarget)
        {
            MISSILE_CltDoCommon(pMissile);
            return;
        }
    }

    int nRate = pMissilesTxtRecord->dwCltParam[2];
    if (nRate <= 0)
    {
        nRate = 5;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate == 0 && sub_006416D0_UnitEdgeDistance(pMissile, pTarget) <= pMissilesTxtRecord->dwCltParam[3])
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        int nTargetX = CLIENTS_GetUnitX(pTarget);
        int nTargetY = CLIENTS_GetUnitY(pTarget);
        int nStep = pMissilesTxtRecord->dwCltParam[4];
        if (nStep < 1)
        {
            nStep = 1;
        }

        int nOffsetX = 0;
        int nOffsetY = 0;
        if (nTargetX > nX)
        {
            nOffsetX = nStep;
        }
        else if (nTargetX < nX)
        {
            nOffsetX = -nStep;
        }

        if (nTargetY > nY)
        {
            nOffsetY = nStep;
        }
        else if (nTargetY < nY)
        {
            nOffsetY = -nStep;
        }

        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
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

// 0x004D4180
void __fastcall MISSILE_CltDoHomingSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nTargetX = MISSILE_GetTargetX(pMissile);
    if (nTargetX <= -pMissilesTxtRecord->dwCltParam[1])
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (nTargetX <= 0)
    {
        MISSILE_SetTargetX(pMissile, nTargetX - 1);
    }

    if (!PATH_GetVelocity(pMissile->pDynamicPath))
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pMissile->pDynamicPath);
    if (!pTarget)
    {
        pTarget = CUNIT_GetPathTargetUnit(pOwner);
    }

    int nRate = pMissilesTxtRecord->dwCltParam[2];
    if (nRate <= 0)
    {
        nRate = 5;
    }

    if (pTarget && !(sub_0064A380_GetRemainingFrames(pMissile) % nRate) && nTargetX > 0
        && sub_006416D0_UnitEdgeDistance(pMissile, pTarget) < pMissilesTxtRecord->dwCltParam[3])
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        int nTargetUnitX = CLIENTS_GetUnitX(pTarget);
        int nTargetUnitY = CLIENTS_GetUnitY(pTarget);
        int nStep = pMissilesTxtRecord->dwCltParam[4] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[4];

        int nDeltaX = 0;
        int nDeltaY = 0;
        if (nTargetUnitX > nX)
        {
            nDeltaX = nStep;
        }
        else if (nTargetUnitX < nX)
        {
            nDeltaX = -nStep;
        }

        if (nTargetUnitY > nY)
        {
            nDeltaY = nStep;
        }
        else if (nTargetUnitY < nY)
        {
            nDeltaY = -nStep;
        }

        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nDeltaX, CLIENTS_GetUnitY(pMissile) + nDeltaY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        int nPeriod = pMissilesTxtRecord->dwCltParam[0] > 1 ? pMissilesTxtRecord->dwCltParam[0] : 1;
        if (!(sub_0064A380_GetRemainingFrames(pMissile) % nPeriod) && nTargetX > 0)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 5;
            missileParams.nX = CLIENTS_GetUnitX(pMissile);
            missileParams.nY = CLIENTS_GetUnitY(pMissile);
            missileParams.nRange = MISSILE_GetTotalFrames(pMissile) - 1;
            missileParams.nVelocity = 0;
            missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            missileParams.pOwner = pOwner;
            missileParams.nSkill = MISSILE_GetSkill(pMissile);
            missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pSubMissile)
            {
                MISSILE_SetTargetX(pSubMissile, 0);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D43A0
void __fastcall MISSILE_CltDoRandomSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0 || !sub_004639D0_GetOwnerUnit(pMissile))
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        if (SEED_RollLimitedRandomNumber(&pMissile->pSeed, 4))
            tParams.dwFlags = 0x4021;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nX = CLIENTS_GetUnitX(pMissile);
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nTargetX = CLIENTS_GetUnitX(pMissile);
        tParams.nTargetY = CLIENTS_GetUnitY(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        sub_004CD540_CreateMissile(&tParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D44B0
void __fastcall MISSILE_CltDoBurst(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nSubMissile = sub_0064A510_GetSubMissile(pMissile);
    if (!nSubMissile)
    {
        nSubMissile = pMissilesTxtRecord->wCltSubMissile[0];
    }

    if (nSubMissile < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nCount = sub_0064A570_GetSubMissileCount(pMissile);
    if (nCount <= 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) < pMissilesTxtRecord->dwCltParam[0] && sub_0064A3B0_GetElapsedFrames(pMissile) % 3 == 0)
    {
        int nPerStep = nCount > 4 ? nCount / 2 : nCount;
        int nMult = nCount > 4 ? 2 : 1;
        MISSILE_SpawnBurst(pMissile, nCount, nSubMissile, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nPerStep, nMult);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4590
void __fastcall MISSILE_CltDoCopySubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0 && sub_0064A3B0_GetElapsedFrames(pMissile) >= pMissilesTxtRecord->nCanDestroy && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];

        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
        if (pSubMissile)
        {
            PATH_SetDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
            PATH_SetPrecisionX(pSubMissile->pDynamicPath, UNITS_GetPrecisionX(pMissile));
            PATH_SetPrecisionY(pSubMissile->pDynamicPath, UNITS_GetPrecisionY(pMissile));
            GFXUTIL_SetMotionVectorA(pSubMissile, 0, 0, GFXUTIL_GetMotionAZ(pMissile));
        }

        MISSILE_CltDoCommon(pMissile);
        return;
    }

    MISSILE_CltDoCommon(pMissile);
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

// 0x004D46D0
void __fastcall MISSILE_CltDoRing(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int nRate = pMissilesTxtRecord->dwCltParam[0] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate <= 0)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        int nIndex = MISSILE_GetTargetX(pMissile) % 64;
        if (nIndex < 0)
        {
            nIndex = -nIndex;
        }

        missileParams.nTargetX = gaCltDoRingOffsetX[nIndex];
        missileParams.nTargetY = gaCltDoRingOffsetY[nIndex];
        MISSILE_SetTargetX(pMissile, (pMissilesTxtRecord->dwCltParam[1] + nIndex) % 64);
        sub_004CD540_CreateMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4B80
void __fastcall MISSILE_CltDoFrameFloor(D2UnitStrc* pMissile)
{
    if (sub_0064A380_GetRemainingFrames(pMissile) < 100)
    {
        MISSILE_SetCurrentFrame(pMissile, 500);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4BB0
void __fastcall MISSILE_CltDoObjectSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nParam = pMissilesTxtRecord->dwCltParam[0];
    const int nEnd = nParam + 0x7D;
    if (nFrames < pMissilesTxtRecord->wRange - nParam && nFrames > nParam && pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        D2UnitStrc* pNew = MISSILE_SpawnAtRandomUnitInRange(pMissile, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->wCltSubMissile[0]);
        if (pNew)
        {
            MISSILE_InitMotion(pNew);
        }
    }

    if (nFrames < nEnd && nFrames > nParam)
    {
        D2UnitStrc* pUnit = UNITS_GetRoom(pMissile)->pUnitFirst;
        do
        {
            if (!pUnit)
                break;
            if (pUnit->dwUnitType == UNIT_OBJECT && (unsigned int)pUnit->dwClassId >= 0x11 && (unsigned int)pUnit->dwClassId < 0x16)
            {
                if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
                {
                    const int nLevel = MISSILE_GetLevel(pMissile);
                    D2UnitStrc* pNew = (D2UnitStrc*)GFXUTIL_SubmitMissileRequest(pOwner, pMissilesTxtRecord->wCltSubMissile[0], CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), MISSILE_GetSkill(pMissile), nLevel);
                    if (pNew)
                    {
                        MISSILE_InitMotion(pNew);
                    }
                }

                if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && !(nFrames % 8))
                {
                    int nTargetId = MISSILE_GetTargetX(pMissile);
                    D2UnitStrc* pTarget = nTargetId ? CUNIT_FindClientUnit(nTargetId, 2) : 0;
                    if (!pTarget)
                    {
                        MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                    }
                    else
                    {
                        D2MissileStrc tMissile;
                        memset(&tMissile, 0, sizeof(tMissile));
                        tMissile.dwFlags = 0x421;
                        tMissile.pOwner = pOwner;
                        tMissile.nX = CLIENTS_GetUnitX(pUnit);
                        tMissile.nY = CLIENTS_GetUnitY(pUnit);
                        tMissile.nSkill = MISSILE_GetSkill(pMissile);
                        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
                        tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
                        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
                        sub_004CD540_CreateMissile(&tMissile);
                        if (!SEED_RollLimitedRandomNumber(&pTarget->pSeed, 4))
                        {
                            MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                        }
                    }
                }
            }
            pUnit = pUnit->ptRoomNext;
        } while (pUnit);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5200
void __fastcall MISSILE_CltDoOwnerQuad(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[0])
    {
        int nX = CLIENTS_GetUnitX(pOwner);
        int nY = CLIENTS_GetUnitY(pOwner);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x2001;
        missileParams.pOwner = pOwner;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        for (int i = 0; i < 4; ++i)
        {
            missileParams.nX = gaQuadOffsetX[i] + nX;
            missileParams.nY = gaQuadOffsetY[i] + nY;
            sub_004CD540_CreateMissile(&missileParams);
        }
    }

    MISSILE_CltDoCommon(pMissile);
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

// 0x004D5470
void __fastcall MISSILE_CltDoScatterSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames == pMissilesTxtRecord->dwCltParam[0])
    {
        MISSILE_SetTargetY(pMissile, 1);
    }

    if (MISSILE_GetTargetY(pMissile))
    {
        const int nRate = pMissilesTxtRecord->dwCltParam[1] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[1];
        if (!(nFrames % nRate))
        {
            D2SeedStrc* pSeed = &pMissile->pSeed;
            const int nRange = pMissilesTxtRecord->dwCltParam[2];
            const int nOffsetX = ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;
            const int nOffsetY = ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;

            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0x21;
            tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
            tMissileParams.nX = CLIENTS_GetUnitX(pMissile);
            tMissileParams.nY = CLIENTS_GetUnitY(pMissile);
            tMissileParams.nTargetX = CLIENTS_GetUnitX(pMissile) + nOffsetX;
            tMissileParams.nTargetY = CLIENTS_GetUnitY(pMissile) + nOffsetY;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            sub_004CD540_CreateMissile(&tMissileParams);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D56B0
void __fastcall MISSILE_CltDoParamCallSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    MISSILE_SpawnRingAround(pMissile, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->wCltSubMissile[0]);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5880
void __fastcall MISSILE_CltDoPathSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wCltSubMissile[0])
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 9;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nX = CLIENTS_GetUnitX(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x004D5950
void __fastcall MISSILE_CltDoProgSound(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wProgSound > 0)
    {
        int nOldValue = MISSILE_GetTargetX(pMissile);
        int nNewValue = GFXUTIL_GetMotionFirstParam(pMissile);
        if (nOldValue && nOldValue != nNewValue)
        {
            sub_004B9A00(pMissilesTxtRecord->wProgSound, pMissile, 0, 0, 0);
        }

        MISSILE_SetTargetX(pMissile, nNewValue);
    }

    MISSILE_CltDoRandomTrail(pMissile);
}

// 0x004D5BA0
void __fastcall MISSILE_CltDoPeriodicSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    int nRate = pMissilesTxtRecord->dwCltParam[0];
    if (nRate < 1)
    {
        nRate = 1;
    }

    if (!(nFrames % nRate))
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltSubMissile[0]);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D65E0
void __fastcall MISSILE_CltDoOffsetMissileTimer(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    int nCounter = MISSILE_GetTargetY(pMissile);
    if (!nCounter)
    {
        const int nUnitId = MISSILE_GetTargetX(pMissile);
        ((D2SpawnOffsetMissileView*)nUnitId)->SKILLS_SpawnOffsetMissile(pMissile, pOwner);
        nCounter = (unsigned int)SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10;
    }

    --nCounter;
    MISSILE_SetTargetY(pMissile, nCounter);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004CF3C0
int __fastcall MISSILE_CltHitUnit(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pMissilesTxtRecord->dwCltHitPar[0] && pOwner && (CUNIT_IsPetSkillTarget(pOwner, pUnit) || CUNIT_IsTargetBlocked(pOwner, pUnit)))
    {
        if (pMissilesTxtRecord->wProgOverlay > 0)
        {
            GFX_AddUnitOverlay(pUnit, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
            return 1;
        }

        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pMissilesTxtRecord->dwCltHitPar[1])
        {
            return 0;
        }
        break;

    case UNIT_MONSTER:
        switch (pMissilesTxtRecord->dwCltHitPar[1])
        {
        case 2:
            if (!MONSTERS_IsDemon(pUnit))
            {
                return 0;
            }
            break;

        default:
            if (!MONSTERS_IsUndead(pUnit))
            {
                return 0;
            }
            break;
        }
        break;

    default:
        return 0;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2MissileStrc tMissile;
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.pOwner = pOwner;
        tMissile.pOrigin = pMissile;
        tMissile.nSkill = MISSILE_GetSkill(pMissile);
        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
        tMissile.nMissile = MISSILE_TEETHEXPLODE;
        sub_004CD540_CreateMissile(&tMissile);
    }

    return 1;
}

// 0x004CF500
int __fastcall MISSILE_CltHitSpawnSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int aSubMissiles[3];
    int nCount = 0;
    for (nCount = 0; nCount < 3; ++nCount)
    {
        const short nSubMissile = pMissilesTxtRecord->wCltHitSubMissile[nCount];
        if (nSubMissile < 0)
        {
            break;
        }
        aSubMissiles[nCount] = nSubMissile;
    }

    if (nCount <= 0)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[0];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile), pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nMissileId = pMissile->dwClassId;
    int nRange = MISSILE_EvaluateMissileFormula(pMissile, sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwHitCalc, nMissileId, nLevel);
    if (nRange <= 0)
    {
        nRange = pMissilesTxtRecord->wRange + pMissilesTxtRecord->wLevRange * (nLevel - 1);
    }

    sub_004CDDB0(pMissile, aSubMissiles, nCount, nParam, nRange, pMissilesTxtRecord->dwCltHitPar[1]);
    return 1;
}

// 0x004CF640
int __fastcall MISSILE_CltHitPatternSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] < 0)
    {
        return 1;
    }

    const unsigned int nPattern = SEED_RollRandomNumber(&pMissile->pSeed) % 3;
    const int nOffset = SEED_RollRandomNumber(&pMissile->pSeed) & 7;
    for (int i = 0; i < gaCltHitPatterns[nPattern].nCount; ++i)
    {
        const int nIndex = (gaCltHitPatterns[nPattern].aIndex[i] + nOffset) & 7;
        D2UnitStrc* pSubMissile = MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[1], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pSubMissile)
        {
            D2Common_10216(pSubMissile->pDynamicPath, gaCltHitOffsetX[nIndex] + nX, gaCltHitOffsetY[nIndex] + nY, 0);
        }
    }

    return 1;
}

// 0x004D0060
int __fastcall MISSILE_CltHitScanArea(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (!CUNIT_FindClientUnit(sub_0064A780_targetValue(pMissile), sub_0064A730_GetMissileTargetStatus(pMissile)))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    int nFlags = pSkillsTxtRecord->dwAuraFilter;
    if (nFlags)
    {
        nFlags = 0xA683;
    }

    D2MissileScanArgStrc tArg;
    tArg.pOwner = pOwner;
    tArg.pMissile = pMissile;
    tArg.nSkillId = nSkillId;
    tArg.nSkillLevel = nSkillLevel;
    tArg.f_14 = pMissilesTxtRecord->wCltHitSubMissile[0];
    sub_004C5C40_ScanArea(pOwner, nX, nY, nRange, nFlags, sub_004CFFA0_HitScanCallback, &tArg, 0);
    return 1;
}

// 0x004D06F0
int __fastcall MISSILE_CltHitSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, nSkill, nSkillLevel);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        MISSILE_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->wCltHitSubMissile[1], nSkill, nSkillLevel, pMissilesTxtRecord->dwCltHitPar[1], 1);
    }

    if (pUnit)
    {
        GFX_AddUnitOverlay(pUnit, 0x97, 2, 0, 0, 0, 0, 0);
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner && pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        GFX_AddUnitOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
    }
    return 1;
}

// 0x004D0920
int __fastcall MISSILE_CltHitCollisionBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    if (!COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), 3, 1))
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            sub_004CDDB0(pMissile, gaCollisionBurstMissiles, 3, pMissilesTxtRecord->dwParam[0], 0x19, 0x4B);
        }
    }

    return 1;
}

// 0x004D0A80
int __fastcall MISSILE_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    int nCount = pMissilesTxtRecord->dwCltHitPar[0] + (nSkillLevel - 1) * pMissilesTxtRecord->dwCltHitPar[1];
    if (nCount <= 0)
    {
        const int nSkill = MISSILE_GetSkill(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkill, nSkillLevel);
        if (nCount < 1)
        {
            nCount = 1;
        }
    }

    SKILLS_ScatterRequestsAroundTarget(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], nCount, nCount / 4, MISSILE_GetSkill(pMissile), nSkillLevel);
    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }
    return 1;
}

// 0x004D0FF0
int __fastcall MISSILE_CltHitCreateSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (!pUnit)
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0]);
        return 1;
    }

    return 0;
}

// 0x004D1040
int __fastcall MISSILE_CltHitTripleSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        sub_004CD540_CreateMissile(&missileParams);
    }

    return 1;
}

// 0x004D1110
int __fastcall MISSILE_CltHitSubMissileDir(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;

    D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
    if (pSubMissile)
    {
        PATH_SetDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
    }

    return 1;
}

// 0x004D11D0
int __fastcall MISSILE_CltHitBurstNoUnit(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pHitUnit)
    {
        return 0;
    }

    MISSILE_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->wCltHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwCltHitPar[1], 1);
    return 1;
}

// 0x004D1240
int __fastcall MISSILE_CltHitSubMissilesWithMotion(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
        if (pSubMissile)
        {
            GFXUTIL_SetMotionVectorA(pSubMissile, 0, 0, pMissilesTxtRecord->dwCltHitPar[0]);
        }
    }

    return 1;
}

// 0x004D1300
static void __stdcall MISSILE_SpawnScattered(int nRange, int nMissile, D2UnitStrc* pMissile)
{
    const int nOffsetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    const int nOffsetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x21;
    tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile);
    tParams.nY = UNITS_GetUnitYPosition(pMissile);
    tParams.nTargetX = UNITS_GetUnitXPosition(pMissile) + nOffsetX;
    tParams.nTargetY = UNITS_GetUnitYPosition(pMissile) + nOffsetY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = nMissile;
    sub_004CD540_CreateMissile(&tParams);
}

// 0x004CD2D0
static int MISSILE_GetFrameDelay(int nFrames)
{
    if (nFrames < 0x96)
        return 0x14;
    if (nFrames < 0xC8)
        return 0xF;
    if (nFrames < 0xE1)
        return 0xA;
    return nFrames < 0x177 ? 5 : 0x19;
}

// 0x004D1FA0
static void __stdcall MISSILE_SpawnBehindOwner(int nMissileId, D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pOwner, &nDirX, &nDirY);
    D2_ASSERT(nDirX || nDirY, 0x1850);
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    tParams.pOwner = pOwner;
    tParams.nMissile = nMissileId;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile) + SEED_RollRandomNumber(&pMissile->pSeed) % 20 - 10;
    tParams.nY = UNITS_GetUnitYPosition(pMissile) + SEED_RollRandomNumber(&pMissile->pSeed) % 20 - 10;
    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
    if (!pNew)
        return;
    D2_ASSERT(SKILLS_GetMissilesTxtRecord(nMissileId)->wRange == 25, 0x1861);
    int nScreenX = nDirX * -25;
    int nScreenY = nDirY * -25;
    int nOffsetX = nDirX;
    int nOffsetY = nDirY;
    DUNGEON_GameSubtileToClientCoords(&nScreenX, &nScreenY);
    DUNGEON_GameSubtileToClientCoords(&nOffsetX, &nOffsetY);
    GFXUTIL_SetMotionVectorA(pNew, nScreenX, nScreenY, 0x190);
    GFXUTIL_SetMotionVectorB(pNew, nOffsetX, nOffsetY, -0x10, 1);
    sub_004DA350_UpdateMotion(pNew);
}

// 0x004D7690
void __fastcall MISSILE_CltDoOwnerSpawner(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    int nValue = MISSILE_GetTargetX(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    if (!nValue)
    {
        if (SEED_RollRandomNumber(&pMissile->pSeed) & 1)
            MISSILE_SpawnBehindOwner(MISSILE_CATAPULT_COLD_BALL, pOwner, pMissile);
        else
            MISSILE_SpawnBehindOwner(MISSILE_CATAPULT_METEOR_BALL, pOwner, pMissile);
        nValue = MISSILE_GetFrameDelay(sub_0064A3B0_GetElapsedFrames(pMissile));
    }
    MISSILE_SetTargetX(pMissile, nValue - 1);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D7E00
void __fastcall MISSILE_CltDoStateTarget(D2UnitStrc* pMissile)
{
    D2UnitStrc* pStateUnit;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    const int nState = MISSILE_GetTargetY(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    unsigned int const tArg1 = MISSILE_GetTargetX(pMissile);
    pStateUnit = CUNIT_FindServerSideUnit(tArg1, 3);
    if (pStateUnit)
    {
        const int nNewState = MISSILE_GetTargetX(pStateUnit);
        if (nState != nNewState && nNewState >= 2 && !SEED_RollLimitedRandomNumber(pSeed, 25))
        {
            MISSILE_SetTargetY(pMissile, nNewState);
            switch (nNewState)
            {
            case 2:
                PATH_SetVelocity(pPath, 0xF00, gszMissileFile_006DAEF4, 0x19DB);
                D2COMMON_10170_PathSetTargetPos(pPath, 0x3B1F, 0x170C);
                D2Common_10142(pPath, pMissile, 0);
                break;
            }
        }
        else if (nState == 0)
        {
            if (!(SEED_RollRandomNumber(pSeed) % 10))
            {
                MISSILE_SetTargetY(pMissile, 1);
                sub_004DA690_ReplaceMotionFlag1With8(pMissile);
                PATH_SetVelocity(pPath, 0xF00, gszMissileFile_006DAEF4, 0x19E6);
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 1, 1);
                    MISSILE_CltDoCommon(pMissile);
                    return;
                }
            }
        }
        else if (nState == 1)
        {
            int nDX = CLIENTS_GetUnitX(pMissile) - CLIENTS_GetUnitX(pStateUnit);
            int nDY = CLIENTS_GetUnitY(pMissile) - CLIENTS_GetUnitY(pStateUnit);
            if (pMissile->dwUnitId & 2)
            {
                nDX = -nDX;
                nDY = -nDY;
            }
            if (nDX || nDY)
            {
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pMissile) - nDY, CLIENTS_GetUnitY(pMissile) + nDX);
                D2Common_10142(pPath, pMissile, 0);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004DAAB0
void __fastcall MISSILE_GetArmorComponents(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int bSkip, unsigned char* pComponents)
{
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 3);
    if (!bSkip && ITEMS_CanBeEquipped(pItem))
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(pItem));
        if (!pItemsTxtRecord)
        {
            return;
        }

        pComponents[0] = pItemsTxtRecord->nArmorComp[0];
        pComponents[1] = pItemsTxtRecord->nArmorComp[1];
        pComponents[2] = pItemsTxtRecord->nArmorComp[2];
        pComponents[3] = pItemsTxtRecord->nArmorComp[3];
        pComponents[4] = pItemsTxtRecord->nArmorComp[4];
        pComponents[5] = pItemsTxtRecord->nArmorComp[5];
        return;
    }

    memset(pComponents, 0, 6);
}

// 0x004DED20
void __cdecl MISSILE_UpdateRoomColor()
{
    sub_0061C0B0(gpGlobal_007A0634, &gnRoomColorRed, &gnRoomColorGreen, &gnRoomColorBlue);
    gnRoomColorIntensity = sub_0061C0E0(gpGlobal_007A0634);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    sub_00619D70(pRoom, &nIntensity, &nRed, &nGreen, &nBlue);
    if (nRed || nGreen || nBlue)
    {
        gnRoomColorIntensity = nIntensity;
        gnRoomColorRed = nRed;
        gnRoomColorGreen = nGreen;
        gnRoomColorBlue = nBlue;
    }
}

static D2UnitStrc* __stdcall sub_004CE530_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile)
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

    D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissile);
    if (pNew)
    {
        MISSILE_SetTargetX(pNew, nX);
        MISSILE_SetTargetY(pNew, nY);
    }

    return pNew;
}

// 0x004D5310
void __fastcall MISSILE_CltDoSubMissiles(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxt = pMissile ? DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pMissilesTxt)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pMissilesTxt->wCltSubMissile[0] > 0 && nFrame > 10)
    {
        MISSILE_SpawnPeriodicMissile(pOwner, pMissile, pMissilesTxt->wCltSubMissile[0], nFrame, MISSILE_GetSubMissileCount(pMissilesTxt, nFrame));
    }

    const int nPeriod = pMissilesTxt->dwCltParam[0] < 1 ? 1 : pMissilesTxt->dwCltParam[0];
    if (pMissilesTxt->wCltSubMissile[1] > 0 && !(nFrame % nPeriod))
    {
        sub_004CE530_SpawnSubMissile(pOwner, pMissilesTxt->wCltSubMissile[1], 0x14, pMissile);
    }

    const int nParam = pMissilesTxt->dwCltParam[1];
    if (nParam > 0 && nFrame == 90)
    {
        const int nA = nParam / 3;
        const int nTimeA = nA * 25000 / 25;
        const int nTimeB = (nParam - 2 * nA) * 25000 / 25;
        sub_00476A80_StartTiming(8, nTimeA, nTimeB, nTimeA);
    }

    if (pMissilesTxt->wCltSubMissile[2] > 0 && (unsigned int)(nFrame - 0x74) <= 0xC6)
    {
        sub_004CECC0(pOwner, pMissile, pMissilesTxt->wCltSubMissile[2], nFrame);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5DD0
void __fastcall MISSILE_CltDoTimedBurst(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pMissilesTxtRecord->wCltSubMissile[0] >= 0 && nFrame == pMissilesTxtRecord->dwCltParam[0])
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        tParams.dwFlags = 0x2001;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nX = nX;
        tParams.nY = nY;
        sub_004CD540_CreateMissile(&tParams);
        const int nRange = pMissilesTxtRecord->dwCltParam[3];
        for (int i = 0; i < pMissilesTxtRecord->dwCltParam[2]; ++i)
        {
            tParams.nX = nX - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);
            tParams.nY = nY - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);
            sub_004CD540_CreateMissile(&tParams);
        }
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] >= 0 && nFrame == pMissilesTxtRecord->dwCltParam[1])
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        if (pOwner)
        {
            pOwner->dwFlagEx |= 0x40000;
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 0x2000;
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
            if (pNew && pMissilesTxtRecord->wProgSound > 0)
                sub_004B9A00(pMissilesTxtRecord->wProgSound, pNew, 0, 0, 0);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5F80
void __fastcall MISSILE_CltDoMirrorPair(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        int nTargetX = MISSILE_GetTargetX(pMissile);
        int nTargetY = MISSILE_GetTargetY(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
        sub_004CD540_CreateMissile(&missileParams);
        missileParams.nTargetX = -nTargetX;
        missileParams.nTargetY = -nTargetY;
        sub_004CD540_CreateMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D6080
void __fastcall MISSILE_CltDoOwnerSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        sub_004CD540_CreateMissile(&missileParams);
    }

    MISSILE_CltDoSeekTarget(pMissile);
}

// 0x004D62B0
void __fastcall MISSILE_CltDoOwnerTarget(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    MISSILE_CltDoOwnerStep(pMissile);

    int nX;
    int nY;
    if (sub_004C52E0_GetTargetPosition(pOwner, &nX, &nY))
    {
        int nCount = MISSILE_GetTargetY(pMissile);
        if (nCount < MISSILE_GetTargetX(pMissile))
        {
            MISSILE_SetTargetY(pMissile, nCount + 1);
        }

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pOwner;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
        if (pSubMissile)
        {
            PATH_SetType(pSubMissile->pDynamicPath, 0xE);
            D2Common_10142(pSubMissile->pDynamicPath, pSubMissile, 0);
        }

        MISSILE_SetTargetY(pMissile, 0);
        MISSILE_CltDoCommon(pMissile);
    }
}

// 0x004D9180
void __fastcall MISSILE_StateStartMissile(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || pStatesTxtRecord->wSkill < 0)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(pStatesTxtRecord->wSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wCltMissileA < 0 || pSkillsTxtRecord->wCltMissileA >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = pSkillsTxtRecord->wCltMissileA;
    missileParams.nSkill = pStatesTxtRecord->wSkill;
    missileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&missileParams);

    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags |= 0x20;
    }
}

// 0x004D96B0
void __fastcall MISSILE_StateMissile(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || pStatesTxtRecord->wMissile < 0 || pStatesTxtRecord->wMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = pStatesTxtRecord->wMissile;
    missileParams.nSkill = pStatesTxtRecord->wSkill >= 0 ? pStatesTxtRecord->wSkill : 0;
    missileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&missileParams);
}

// 0x004E0A40
int __fastcall MISSILE_SkillStartPlace(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    UNITS_SetAnimStartFrame(pUnit);
    if (pUnit)
    {
        pUnit->dwFlags |= 0xE;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile > 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == 1 && pSkillsTxtRecord->wCltMissileB > 0 && pSkillsTxtRecord->wCltMissileB < sgptDataTables->nMissilesTxtRecordCount)
        {
            nMissile = pSkillsTxtRecord->wCltMissileB;
        }

        MISSILE_SubmitOwnerRequest(pUnit, nMissile, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nSkillId, nSkillLevel);
    }

    D2CoordStrc tCoord;
    tCoord.nX = UNITS_GetUnitXPosition(pUnit);
    tCoord.nY = UNITS_GetUnitYPosition(pUnit);
    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
    if (!pRoom)
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    if (!D2Common_10231(pUnit->pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY))
    {
        return 0;
    }

    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, 0x1000);
    return 1;
}

// 0x004E1090
int __fastcall MISSILE_SkillDoClearTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam2(pSkill);
    int nY = SKILLS_GetParam3(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, 0);
    SKILLS_SetParam3(pSkill, 0);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    COLLISION_ResetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    return 1;
}

// 0x004E18F0
int __fastcall MISSILE_SkillStartCltCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    return 1;
}

// 0x004E27C0
int __fastcall MISSILE_SkillStartSpawnRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pMissileA = sub_004C5470_CreateMissileToTarget(pUnit, MISSILE_HELLMETEORDOWN, nSkillId, nSkillLevel);
    D2UnitStrc* pMissileB = sub_004C5470_CreateMissileToTarget(pUnit, MISSILE_HELLMETEORBALL, nSkillId, nSkillLevel);
    D2UnitStrc* pRequestA = GFXUTIL_SubmitMissileRequest(pUnit, 0x14F, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestB = GFXUTIL_SubmitMissileRequest(pUnit, 0x151, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestC = GFXUTIL_SubmitMissileRequest(pUnit, 0x14E, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestD = GFXUTIL_SubmitMissileRequest(pUnit, 0x14D, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);

    if (pRequestA)
    {
        GFXUTIL_SetMotionVectorB(pRequestA, 0, 0, 15, 1);
    }

    if (pRequestB)
    {
        GFXUTIL_SetMotionVectorB(pRequestB, 0, 0, 15, 1);
    }

    if (pMissileA)
    {
        GFXUTIL_SetMotionVectorA(pMissileA, 0, 0, 0x15F9);
        GFXUTIL_SetMotionVectorB(pMissileA, 0, 0, -25, 1);
    }

    if (pMissileB)
    {
        GFXUTIL_SetMotionVectorA(pMissileB, 0, 0, 0x15F9);
        GFXUTIL_SetMotionVectorB(pMissileB, 0, 0, -25, 1);
    }

    if (pRequestC)
    {
        sub_00621780_SetMissileArg(pRequestD, 0x80);
        sub_00621780_SetMissileArg(pRequestC, 0x80);
    }

    return 1;
}

// 0x004E3350
int __fastcall MISSILE_CheckTargetInRange(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    nRange *= nRange;
    if (PATH_ComputeSquaredDistance(CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), CLIENTS_GetUnitXInline(pTarget), CLIENTS_GetUnitYInline(pTarget)) > nRange)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return 0;
        }

        pRoom = UNITS_GetRoom(pTarget);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return 0;
        }

        if (!sub_00465C60_CheckUnitPair(pUnit, pTarget))
        {
            return 0;
        }
        break;
    }
    }

    return 1;
}

static void __stdcall sub_004D19D0_SpawnRing(int nTargetUnitId, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_HFFRAGMENT1);
    int aOffsetX[14] = { -4, 2, 4, -3, -2, 3, 5, -3, -5, 5, -6, -1, 0, 6 };
    int aOffsetY[14] = { 6, 4, -4, -2, 1, 7, 0, 3, -4, -3, 4, -5, 5, -3 };
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
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
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, nTargetUnitId);
            MISSILE_SetTargetY(pNew, SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10);
        }
    }
}

// 0x004D6680
void __fastcall MISSILE_CltDoObjectRing(D2UnitStrc* pMissile)
{
    const int nTargetUnitId = MISSILE_GetTargetX(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!CUNIT_FindClientUnit(nTargetUnitId, 2))
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    if (nFrames == 10)
    {
        sub_004D19D0_SpawnRing(nTargetUnitId, pMissile);
        sub_00476A80_StartTiming(nFrames - 6, nFrames + 0x46, 0x50, 0x190);
    }
    MISSILE_CltDoCommon(pMissile);
}


// 0x004D66E0
void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(MISSILE_IZUAL_CONTROL);
    MISSILE_SpawnScattered(10, MISSILE_IZUAL_MIST_LOOP, pMissile);
    if (nRemaining < pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[0] && nRemaining > pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[1])
    {
        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
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
            D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
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

// 0x004D6C00
void __fastcall MISSILE_CltDoRateTable(D2UnitStrc* pMissile)
{
    int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);

    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        if (nRemaining > gaCltRateTable[i].nThreshold)
        {
            break;
        }
    }

    if (nRemaining % gaCltRateTable[i].nRate == 0)
    {
        int nY = UNITS_GetUnitYPosition(pMissile);
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nLevel = MISSILE_GetLevel(pMissile);
        int nSkill = MISSILE_GetSkill(pMissile);
        if (pOwner)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 1;
            missileParams.pOwner = pOwner;
            missileParams.nX = nX;
            missileParams.nY = nY;
            missileParams.nSkill = nSkill;
            missileParams.nSkillLevel = nLevel;
            missileParams.nMissile = MISSILE_RADAMENTHANDOFGOD;

            D2UnitStrc* pNewMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pNewMissile)
            {
                MISSILE_SetTargetX(pNewMissile, gaCltRateTable[i].nValue);
                MISSILE_SetTargetY(pNewMissile, nRemaining);
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

// 0x004D6D40
void __fastcall MISSILE_CltDoRateJitterSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380(pMissile);

    int i = 0;
    for (i = 0; i < 4; ++i)
    {
        if (nRemaining > gaCltRateJitter[i].nThreshold)
        {
            break;
        }
    }

    if (nRemaining % gaCltRateJitter[i].nRate == 0)
    {
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nY = UNITS_GetUnitYPosition(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        missileParams.nMissile = MISSILE_TAINTEDSUNFLASH;
        sub_0064A280(pMissile);
        missileParams.nSkill = sub_0064A280(pMissile);
        missileParams.nSkillLevel = sub_0064A210(pMissile);

        for (int j = 0; j < gaCltRateJitter[i].nValue; ++j)
        {
            int nOffsetX = (int)(SEED_RollUnitSeedInline(pMissile) % 10) - 5;
            if ((nOffsetX < 0 ? -nOffsetX : nOffsetX) < 2)
                nOffsetX = 5;

            int nOffsetY = (int)(SEED_RollUnitSeedInline(pMissile) % 10) - 5;
            if ((nOffsetY < 0 ? -nOffsetY : nOffsetY) < 2)
                nOffsetY = 5;

            missileParams.nX = nX + 2 * nOffsetX;
            missileParams.nY = nY + 2 * nOffsetY;
            D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pSubMissile)
                MISSILE_SetTargetX(pSubMissile, sub_00451F50_GetUnitGUID(pMissile));
        }
    }

    if (nRemaining < 0x19)
        MISSILE_SetTargetX(pMissile, 3);
    else if (nRemaining < 0x4B)
        MISSILE_SetTargetX(pMissile, 2);

    if (nRemaining <= 1)
    {
        D2UnitStrc* pTarget = CUNIT_FindClientUnit(sub_0064A780_targetValue(pMissile), 2);
        if (pTarget)
        {
            GFX_AddUnitOverlay(pTarget, 0xB6, 3, 0, 0, 0, 0, 0);
            if (!pTarget->pLight)
                pTarget->pLight = sub_00474160_MakeLightEntry(pTarget, 2, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }

    MISSILE_CltDoCommon(pMissile);
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

// 0x004D7400
void __fastcall MISSILE_CltDoScatterRate(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    if (nFrames == 325)
    {
        sub_00476A80_StartTiming(0x14, 0, 6000, 0);
    }

    int nIndex = 0;
    while (nIndex < 4 && nFrames <= gaScatterRates[nIndex].nFrames)
    {
        ++nIndex;
    }

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (!(nFrames % gaScatterRates[nIndex].nRateA))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x2001;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nMissile = MISSILE_EXPLODINGARROWEXP;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        D2SeedStrc tSeed;
        const int nOffsetX = SEED_RollFromInline(pSeed, &tSeed) % 40 - 20;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pSeed->nHighSeed = tSeed.nHighSeed;
        pSeed->nLowSeed = tSeed.nLowSeed;
        const int nOffsetY = nRoll % 40 - 20;
        tParams.nX = nX + nOffsetX;
        tParams.nY = nY + nOffsetY;
        sub_004CD540_CreateMissile(&tParams);
    }

    if (!(nFrames % gaScatterRates[nIndex].nRateB))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x2001;
        tParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tParams.nMissile = MISSILE_DURIELDEATHROCK;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        D2SeedStrc tSeed;
        const int nOffsetX = SEED_RollFromInline(pSeed, &tSeed) % 40 - 20;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pSeed->nHighSeed = tSeed.nHighSeed;
        pSeed->nLowSeed = tSeed.nLowSeed;
        const int nOffsetY = nRoll % 40 - 20;
        tParams.nX = nX + nOffsetX;
        tParams.nY = nY + nOffsetY;
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            GFXUTIL_SetMotionVectorA(pNew, 0, 0, 150);
            GFXUTIL_SetMotionVectorB(pNew, 0, 0, -10, 1);
            MISSILE_SetTotalFrames(pNew, 15);
            MISSILE_SetCurrentFrame(pNew, 15);
            sub_0064A690_SetMissileAnimSpeed(pNew, 0x80);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D9630
void __fastcall MISSILE_StateOverlayRanges(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord)
    {
        return;
    }

    int nEnd = pStatesTxtRecord->wOverlay[1];
    int nStart = pStatesTxtRecord->wOverlay[0];
    if (nStart >= 0)
    {
        for (int i = nStart; i <= nEnd; ++i)
        {
            AUTOMAP_RemoveUnitOverlay(pUnit, 0, i);
        }
    }

    nStart = pStatesTxtRecord->wOverlay[2];
    nEnd = pStatesTxtRecord->wOverlay[3];
    if (nStart >= 0)
    {
        for (int i = nStart; i <= nEnd; ++i)
        {
            AUTOMAP_RemoveUnitOverlay(pUnit, 0, i);
        }
    }
}

// 0x004E2F40
int __fastcall MISSILE_VolleyAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = SKILLDESC_InitCappedChargedPath;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nInitArg = i;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
    return 1;
}

// 0x004E34E0
int __fastcall MISSILE_StartMissileEffect(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissile, nSkillLevel);
    nVelocity += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    SKILLS_StartUnitEffect(pUnit, pUnit, nMissile, -1, nSkillId, nSkillLevel, nVelocity);
    return 1;
}

// 0x004E6680
void __fastcall MISSILE_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nArg1, int nArg2)
{
    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_SET)
    {
        return;
    }

    D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordInline(pItem);
    if (!pSetItemsTxt)
    {
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
// build: symbol ?gaSetPropIds@* 0x006DBD70
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, gaSetPropIds[i]);
        if (pStatList && pSetItemsTxt->nSetId == STATLIST_GetStatValue(pStatList, STAT_VALUE, 0))
        {
            sub_004E60A0_AddSetPropText(pUnit, nArg1, nArg2, 0, gaSetPropIds[i], 0, 0, 1);
            return;
        }
    }
}

// 0x004D14A0
int __fastcall MISSILE_CltHitFollowUp(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    int nFollowUp = -1;
    switch (sub_0064A3E0_GetMissileClassId(pMissile))
    {
    case 0x110:
        nFollowUp = 0x158;
        break;

    case 0x111:
    case 0x112:
    case 0x1A1:
        nFollowUp = 0x159;
        break;
    }

    D2UnitStrc* pNewMissile = GFXUTIL_SubmitMissileRequest(sub_004639D0_GetOwnerUnit(pMissile), nFollowUp, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNewMissile)
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2DynamicPathStrc* pNewPath = pNewMissile->pDynamicPath;
        PATH_SetDirection(pNewPath, PATH_GetDirection(pPath));
        sub_00621780_SetMissileArg(pNewMissile, 0x80);
    }

    return 1;
}

// 0x004D97F0
void __stdcall MISSILE_UpdateStateColor(D2UnitStrc* pUnit)
{
    int nBestState = -1;
    unsigned char nBestPri = 0;
    for (int i = 0; i < sgptDataTables->nStatesTxtRecordCount; ++i)
    {
        D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(i);
        if (pStatesTxtRecord && STATES_CheckState(pUnit, i) && pStatesTxtRecord->nColorPri > nBestPri)
        {
            nBestState = i;
            nBestPri = pStatesTxtRecord->nColorPri;
        }
    }

    if (nBestState > 0)
    {
        D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nBestState);
        if (!pStatesTxtRecord)
        {
            return;
        }

// build: symbol ?D2GFX_IsHardwareRenderMode@* 0x004F51C0
        if (pStatesTxtRecord->nColorShift == 0x68 && pUnit == sub_00463DD0_GetPlayerUnit() && D2GFX_IsHardwareRenderMode())
        {
            pUnit->nPaletteIndex = 0;
        }
        else
        {
            pUnit->nPaletteIndex = pStatesTxtRecord->nColorShift;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit() && pUnit->pLight)
        {
            SCMD_SetLightColorBytes(pUnit->pLight, pStatesTxtRecord->nLightRGB[0], pStatesTxtRecord->nLightRGB[1], pStatesTxtRecord->nLightRGB[2]);
        }
    }
    else
    {
        pUnit->nPaletteIndex = 0;
        if (pUnit == sub_00463DD0_GetPlayerUnit() && pUnit->pLight)
        {
            SCMD_SetLightColorBytes(pUnit->pLight, 0xFF, 0xFF, 0xFF);
        }
    }
}

// 0x004D1D70
int __fastcall MISSILE_CltHitLinkMissile(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_FindServerSideUnit(MISSILE_GetTargetX(pMissile), 3);
    if (pTarget)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0xA021;
        tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tMissileParams.nMissile = MISSILE_TAINTEDSUNBALL;
        tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
        tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tMissileParams.nRange = sub_0064A380_GetRemainingFrames(pTarget);
        tMissileParams.nX = UNITS_GetUnitXPosition(pMissile);
        tMissileParams.nY = UNITS_GetUnitYPosition(pMissile);
        tMissileParams.nTargetX = UNITS_GetUnitXPosition(pTarget);
        tMissileParams.nTargetY = UNITS_GetUnitYPosition(pTarget);
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tMissileParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }

    return 1;
}

// 0x004D1EC0
int __fastcall MISSILE_CltHitRolledRequest(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2SeedStrc* pSeed = &pMissile->pSeed;
    if ((int)SEED_RollLimitedRandomNumber_004D1EC0(pSeed, 2) > 0)
    {
        return 1;
    }

    const int nMissile = UNITS_GetClassId_004D1EC0(pMissile) + SEED_RollLimitedRandomNumber_004D1EC0(pSeed, 2) + 1;
    D2UnitStrc* pNew = MISSILE_SubmitOwnerRequest(pMissile, nMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNew)
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2DynamicPathStrc* pNewPath = pNew->pDynamicPath;
        PATH_SetDirection(pNewPath, PATH_GetDirection(pPath));
        D2COMMON_10203_PATH_SetRotateFlag(pNewPath, 0);
    }

    return 1;
}

// 0x004CD240
int __fastcall MISSILE_IsOwnersPet(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pOwner->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nRosterId = sub_00479150_FindRosterIndex(pUnit->dwUnitId);
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    return nRosterId == nOwnerId;
}

// 0x004CD290
static inline void MISSILE_ApplyAnimSpeedSteps(D2UnitStrc* pMissile, int nFrame)
{
    switch (nFrame)
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }
}

// 0x004D1F50
int __fastcall MISSILE_CltHitSpawnRequest(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    SKILLS_ScatterRequestsAroundTarget(pMissile, MISSILE_DURIELDEATHDEBRIS, 3, 6, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    MISSILE_SubmitOwnerRequest(pMissile, 0x16E, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    return 1;
}

// 0x004D1890
int __fastcall MISSILE_SpawnHellfireFragments(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord;
    if (sgptDataTables->nMissilesTxtRecordCount<=0x175) pRecord=0;
    else pRecord=&sgptDataTables->pMissilesTxt[0x175];
    D2UnitStrc* pOwner=sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner) {
        D2MissileStrc tParams;
        memset(&tParams,0,sizeof(tParams));
        tParams.dwFlags=0x8005;
        tParams.pOwner=pOwner;
        tParams.nMissile=MISSILE_HFFRAGMENT3;
        tParams.nSkill=MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel=MISSILE_GetLevel(pMissile);
        tParams.nVelocity=0;
        tParams.nRange=pRecord->wRange;
        tParams.nX=UNITS_GetUnitXPosition(pMissile);
        tParams.nY=UNITS_GetUnitYPosition(pMissile);
        D2UnitStrc* pNew=sub_004CD540_CreateMissile(&tParams);
        if(pNew) {
            MISSILE_SetTargetX(pNew,MISSILE_GetTargetX(pMissile));
            MISSILE_SetTargetY(pNew,SEED_RollRandomNumber(&pMissile->pSeed)%35+10);
        }
    }
    return 1;
}

// 0x004D0EB0
int __fastcall MISSILE_CltHitLob(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    tMissileParams.nX = UNITS_GetUnitXPosition(pMissile);
    tMissileParams.nY = UNITS_GetUnitYPosition(pMissile);
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
    tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);

    D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pSubMissile)
    {
        return 1;
    }

    GFXUTIL_SetMotionParams(pSubMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1]);
    SKILLS_SetBallistic(pSubMissile, 0, pMissilesTxtRecord->dwCltHitPar[2]);
    MISSILE_ClearMotionFlagTwo(pSubMissile);
    return 1;
}

// 0x004D2AF0
int __fastcall MISSILE_CltDoScatterHit(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSeed = CLIENTS_GetUnitX(pMissile);
    SEED_InitLowSeed(&pMissile->pSeed, nSeed);
    const int nRange = pMissilesTxtRecord->dwCltHitPar[0] < 1 ? 1 : pMissilesTxtRecord->dwCltHitPar[0];
    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);
    const int nTargetX = nX - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);
    const int nTargetY = nY - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x20;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tParams.nTargetX = nTargetX;
    tParams.nTargetY = nTargetY;
    sub_004CD540_CreateMissile(&tParams);
    return 1;
}

// 0x004D30C0
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile)
{
    if (!pMissile)
        return;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
        return;
    int bRepeat = 0;
    switch (gdwGlobal_007A0610)
    {
    case 0:
    case 1:
    case 6:
    case 8:
        if (sub_004639D0_GetOwnerUnit(pMissile) == sub_00463DD0_GetPlayerUnit())
            bRepeat = 1;
        break;
    }
    D2CltMissileFindArgStrc tFindArg;
    for (;;)
    {
        const int bActive = sub_0064A380_GetRemainingFrames(pMissile) <= sub_0064A640(pMissile);
        if (bActive && sub_0064A3B0_GetElapsedFrames(pMissile) > pMissilesTxtRecord->nCanDestroy)
            pMissile->dwFlagEx &= ~0x40000;
        if (!sub_004DA6B0_TestMotionFlags(pMissile))
        {
            sub_004D2D70_CltMissileHit(pMissile, 0, 1);
            return;
        }
        if (bActive)
        {
            if (!pMissilesTxtRecord->nLoopAnim)
            {
                if (!sub_006217C0(pMissile))
                    UNITS_UpdateFrame(pMissile);
            }
            else
            {
                if (pMissilesTxtRecord->nSubLoop)
                {
                    const int nSubStop = pMissilesTxtRecord->nSubStop;
                    if (sub_0064A380_GetRemainingFrames(pMissile) <= pMissilesTxtRecord->nAnimLen - nSubStop + 1)
                        UNITS_UpdateFrame(pMissile);
                    else
                        D2COMMON_10375_UNITS_SetFrameNonRate(pMissile, pMissilesTxtRecord->nSubStart, nSubStop);
                }
                else
                {
                    UNITS_UpdateFrame(pMissile);
                }
            }
        }
        D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
        if (PATH_GetVelocity(pDynamicPath))
            sub_00650840(pMissile, GAME_GetPathFrame());
        MISSILE_SetCurrentFrame(pMissile, sub_0064A380_GetRemainingFrames(pMissile) - 1);
        if (sub_0064A380_GetRemainingFrames(pMissile) <= 0)
        {
            sub_004D2D70_CltMissileHit(pMissile, 0, 0);
            return;
        }
        if (!bActive)
            return;
        if (pMissilesTxtRecord->nCltSrcTown > 0)
        {
            D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
            D2ActiveRoomStrc* pOwnerRoom;
            if (!pOwner || ((pOwnerRoom = UNITS_GetRoom(pOwner)) != 0 && DUNGEON_IsRoomInTown(pOwnerRoom)))
            {
                const int nFrame = pMissilesTxtRecord->nCltSrcTown;
                if (sub_0064A380_GetRemainingFrames(pMissile) >= nFrame)
                {
                    MISSILE_SetCurrentFrame(pMissile, nFrame);
                    if (!pMissilesTxtRecord->nLoopAnim)
                    {
                        const int nDelta = pMissilesTxtRecord->nAnimLen - pMissilesTxtRecord->nCltSrcTown;
                        if (nDelta > 0)
                            pMissile->nSeqCurrentFramePrecise = nDelta << 8;
                    }
                }
            }
        }
        const int nMissileMode = sub_00451F70_GetUnitMode(pMissile);
        if (!nMissileMode)
            return;
        const unsigned short nCollisionFlags = D2Common_10201(pDynamicPath);
        if (nCollisionFlags & 5)
        {
            sub_004D2D70_CltMissileHit(pMissile, 0, 1);
            return;
        }
        if (nMissileMode == 6)
            return;
        tFindArg.pMissile = pMissile;
        tFindArg.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tFindArg.pMissilesTxtRecord = pMissilesTxtRecord;
        if (pMissilesTxtRecord->nClientCol && nCollisionFlags)
        {
            D2PathPointStrc* pPathPoints;
            const int nPathPoints = D2COMMON_10198_PathGetSaveStep(pDynamicPath, &pPathPoints);
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
            for (int i = 0; i < nPathPoints; ++i)
            {
                D2UnitStrc* pTarget = D2Common_10407(pRoom, pPathPoints[i].X, pPathPoints[i].Y, gaCltMissileModes[nMissileMode].pfUnitFindCallback, &tFindArg, UNITS_GetUnitSizeX(pMissile));
                if (pTarget && !CUNIT_IsDeadOrDying(pTarget))
                {
                    sub_004D2D70_CltMissileHit(pMissile, pTarget, 0);
                    return;
                }
            }
        }
        if (!bRepeat)
            return;
        if (sub_0064A3B0_GetElapsedFrames(pMissile) != 1)
            return;
        if (!PATH_GetVelocity(pDynamicPath))
            return;
        bRepeat = 0;
    }
}

// 0x004CDD10
D2UnitStrc* __fastcall MISSILE_SubmitTargetRequest(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pOwner, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x420;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

void __fastcall sub_M130_Emit_004CD290(D2UnitStrc* pMissile)
{
    MISSILE_ApplyAnimSpeedSteps(pMissile, sub_0064A3B0_GetElapsedFrames(pMissile));
}

// 0x004F16F0
int __fastcall MISSILE_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nArg0, int nArg3, int nArg4, int nMissileArg, int bFirst, int bClearPathFlag)
{
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (bFirst)
    {
        --nCount;
        D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nArg0, nArg3, nArg4);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x21;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = UNITS_GetXPositionInline(pUnit);
    tRequest.nArg2 = UNITS_GetYPositionInline(pUnit);
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    tRequest.pfCallback = SKILLDESC_InitCappedChargedPath;
    if (bClearPathFlag)
    {
        tRequest.nType |= 0x2000;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tRequest.nIndex = i;
        D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/UNIT/Missile.inc"
