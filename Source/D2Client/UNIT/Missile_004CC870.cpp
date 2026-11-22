#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2ClientGame.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNITFLAGEX_0x40000 0x40000
#define PATHTYPE_CHARGEDBOLT 10
struct D2TimedHintEntryStrc;
struct D2UnitSfxNodeStrc;
struct D2MonSoundsTxt;
struct D2UnitSndPlayerStrc;
struct D2UnitSndObjectStrc;
struct D2SuperUniquesTxt;
struct D2MonStatsTxt;
struct D2DirRateStrc;
struct D2SkillsTxt;
struct D2TimedHintNodeStrc;
struct D2StaticPathStrc;
struct D2DrlgCoordsStrc;
struct D2TileLibraryEntryStrc;
struct T00481920;
union D2SeedStrc;
struct D2MissilesTxt;
struct D2MissileStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2UnitSndPlayerStrc* gpUnitSndPlayer_0072A008[]; // 0x0072A008
extern D2UnitSndObjectStrc* gpUnitSndObject_007295F8[]; // 0x007295F8
extern D2UnitSndObjectStrc gUnitSndObject_00729328; // 0x00729328
extern int gnUnitSndObject3D_00728338[]; // 0x00728338
extern D2DirRateStrc gaDirRate_00727ED8[]; // 0x00727ED8
extern unsigned int gnNeutralTick_007C88B8; // 0x007C88B8
extern unsigned int gnSfxTick_007C88BC; // 0x007C88BC
extern unsigned int gnNeutralDelay_007C88C0; // 0x007C88C0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId); // 0x00656F90
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId); // 0x00656FC0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit); // 0x004AC7C0
int __fastcall sub_004AE360_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360
int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit); // 0x004AE380
int __fastcall sub_004AE3A0_IsSuperUniqueMonster(D2UnitStrc* pUnit); // 0x004AE3A0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue); // 0x004B9B50
int __fastcall sub_004B9BE0_HasActiveHint(void* pEntry); // 0x004B9BE0
int __fastcall sub_004B9CA0_GetHintIdByKey(void* pKey); // 0x004B9CA0
int __fastcall sub_004B9E10_IsNearPlayer(D2UnitStrc* pUnit); // 0x004B9E10
int __fastcall sub_004B9E90_HasUnitSound(D2UnitStrc* pUnit); // 0x004B9E90
void __fastcall sub_004B9EF0_ArmHint(void* pEntry, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790
int __fastcall sub_00481890_GetCacheFirst(int nId); // 0x00481890
void __fastcall sub_004822B0_AddVariantRefs(int nIndex, int nDelta); // 0x004822B0
int __cdecl sub_0044DB00(); // 0x0044DB00
int __fastcall sub_004E40A0(int nRange); // 0x004E40A0
extern "C" int __fastcall sub_004E4100_RandomInRange(int nMin, int nMax); // 0x004E4100
int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength); // 0x004E4180
int __fastcall sub_004CA810_GetModeSound(D2UnitStrc* pUnit, int nMode); // 0x004CA810
int __fastcall sub_004CADB0_GetUnitFloorMaterial(D2UnitStrc* pUnit); // 0x004CADB0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __fastcall sub_004CAA10_PurgeUnitHints(D2UnitStrc* pUnit); // 0x004CAA10
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall sub_004A0200_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId); // 0x004A0200
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType); // 0x004E0590
void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg); // 0x004DCE10
void __stdcall sub_004CB2C0_ReleaseMonsterSfx(D2UnitStrc* pUnit);
void __fastcall sub_004CC160_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta);


void __fastcall sub_00516950_LinkEntry(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry); // 0x00516950
void __fastcall sub_00516980_RemoveNode(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry); // 0x00516980
int __fastcall sub_004818F0_GetCacheKind(int nIndex); // 0x004818F0

struct T00481920
{
    int unk0x00[7];
    int nMaterial1;
};

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __cdecl sub_00476AF0_ClearGlobals(); // 0x00476AF0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, unsigned int nDirection);
static void sub_004CB890_PlaySkillSound(D2UnitStrc* pUnit, int nMode);

static int sub_004CA2C0_GetUnitSndClassId(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB01);
    return nClass;
}

static int sub_004CA320_GetUnitSndType(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB0D);
    return nType;
}

static int sub_004CA380_GetUnitSndMode(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB19);
    return nMode;
}

static D2UnitSndPlayerStrc* sub_004CA3E0_GetPlayerSoundRecord(unsigned int nClass)
{
    D2_ASSERT(nClass < 7, 0xB22);
    return gpUnitSndPlayer_0072A008[nClass];
}

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x004CC870
void __fastcall sub_004CC870_InitFromOwner(D2UnitStrc* pMissile, int nInitArg)
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

    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nOffset);
    PATH_SetDirection(pMissile->pDynamicPath, PATH_GetDirection(pOwner->pDynamicPath));
    D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
    pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nAnimLen) << 8;
}

