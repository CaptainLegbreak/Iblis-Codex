#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STAT_LEVEL 12
#define STAT_ARMORCLASS_VS_HTH 33
#define H12_OFFSET(s, m) ((unsigned int)&((s*)0)->m)

struct D2GfxLightStrc;
struct Unicode;
struct D2Vector3FStrc;
struct D2HirelingInfoStrc;
struct D2HirelingTxt;
struct D2MonStats2Txt;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2MonCmdRecordStrc;
struct D2MissileStrc;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2DirectionArgStrc;
struct D2ClientStringListStrc;
struct D2CoordStrc;
struct D2HirelingInitStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2MonStatsInitStrc;
struct D2MonAnimRecStrc;


struct D2Vector3FStrc
{
    float fX;
    float fY;
    float fZ;
};

struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
};




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0
int __cdecl UI_GetHoverClassId(); // 0x00466DD0
int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel); // 0x006562F0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName); // 0x0063E810
void __fastcall ITEM_RefreshUnitEquipment(D2UnitStrc* pUnit); // 0x004C1C10
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900
float __stdcall GFXUTIL_VectorLengthSquared(float fX, float fY); // 0x004E4160

extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg); // 0x00466CB0
void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10
void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0
void __stdcall MONSTER_RunUModCallbacks(D2UnitStrc* pUnit, void* pArg, int nMode); // 0x004ADD90
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2); // 0x00643A00
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460
void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

#pragma pack(push, 1)
#pragma pack(pop)

extern unsigned int gdwBitMasks[]; // 0x006CE268
void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall UNITMODE_RecacheUnitPath(D2UnitStrc* pUnit); // 0x00480490
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

typedef unsigned int DWORD;


typedef char H12_check_unit_a[(H12_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && H12_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char H12_check_unit_b[(H12_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && H12_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char H12_check_unit_c[(H12_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && H12_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char H12_check_txt_a[(H12_OFFSET(D2MonStatsTxt, nByte1A7) == 0x1A7 && H12_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char H12_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && H12_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char H12_check_txt_c[(H12_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char H12_check_unit_d[(H12_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char H12_check_misc[(H12_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

extern D2MonAnimRecStrc gaMonAnimRecords_00725220[]; // 0x00725220
extern D2MonAnimRecStrc gaMonAnimRecordsMoving_007252E0[]; // 0x007252E0
extern D2MonAnimRecStrc gMonAnimRecord_00725328; // 0x00725328
extern D2MonAnimRecStrc gMonAnimRecord_00725334; // 0x00725334
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit); // 0x004ADE60
void __stdcall MONSTER_SpawnQuillRatMissiles(D2UnitStrc* pUnit, int nMissile, int nX, int nY); // 0x004AF1B0
int __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
void __fastcall SKILLS_RunStateActiveFuncs(D2UnitStrc* pUnit); // 0x004C72F0
void __fastcall UNITSND_UpdateModeSound(D2UnitStrc* pUnit); // 0x004CB460
D2UnitStrc* __fastcall GFXUTIL_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall PATH_SetPathingFlag(D2DynamicPathStrc* pPath, int nArg); // 0x00648750
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0

typedef char I07_check_unit_a[(I07_OFFSET(D2UnitStrc, pSeed) == 0x20 && I07_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C) ? 1 : -1];

typedef char I07_check_unit_b[(I07_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8 && I07_OFFSET(D2StaticPathStrc, nYPos) == 0x10) ? 1 : -1];

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, D2DirectionArgStrc tDirection); // 0x006488A0
extern const int gnBloodOffsetY_006DA5F0[]; // 0x006DA5F0
extern const int gnBloodOffsetX_006DA610[]; // 0x006DA610
D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690
void __fastcall MISSILE_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0
extern int gdwGlobal_007C0D43; // 0x007C0D43
extern int gdwGlobal_007C0D47; // 0x007C0D47
extern int gdwGlobal_007C0DB0; // 0x007C0DB0
extern int gdwGlobal_007C0E54; // 0x007C0E54
extern int gdwGlobal_007C0E78; // 0x007C0E78
extern int gdwGlobal_007C0E68; // 0x007C0E68
extern int gdwGlobal_0072A348; // 0x0072A348
extern int gdwGlobal_007C8C78; // 0x007C8C78
extern char gData_0072AE40[]; // 0x0072AE40
extern char gData_0072AF18[]; // 0x0072AF18
extern char gData_0072B008[]; // 0x0072B008

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
extern D2ClientStringListStrc gtStringList_007C0D9A; // 0x007C0D9A
extern D2UnitStrc* gpUnit_007C0DD4; // 0x007C0DD4
extern unsigned short gwGlobal_007C0DD8; // 0x007C0DD8
void __stdcall sub_M103_EmitSink(int nValue);

typedef char I20_check_unit_a[(I20_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && I20_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char I20_check_unit_b[(I20_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && I20_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char I20_check_unit_c[(I20_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && I20_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char I20_check_txt_a[(I20_OFFSET(D2MonStatsTxt, nByte1A7) == 0x1A7 && I20_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char I20_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && I20_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char I20_check_txt_c[(I20_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char I20_check_unit_d[(I20_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char I20_check_misc[(I20_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pMonster, int bAlwaysReturnFalse); // 0x0063E8D0

static D2MonAnimRecStrc* sub_004AF400_GetMonsterAnimRecord(D2UnitStrc* pUnit);

static void sub_004AF2E0_MonsterSkillEvent(D2UnitStrc* pUnit);
static void MONSTER_ReplaySequence(D2UnitStrc* pUnit); // 0x004AFB60
static int MONSTER_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord); // 0x004AFBC0
static void MONSTER_CreateDeathMissiles(D2UnitStrc* pUnit); // 0x004AFC10
static inline void MONSTER_SetNpcMenuState(int nState); // 0x004B17D0
static inline void MONSTER_SetNpcMenuUnit(D2UnitStrc* pUnit); // 0x004B17E0
static inline void MONSTER_SetNpcMenuValue(unsigned short wValue); // 0x004B17F0
static inline bool MONSTER_IsStringUnused(unsigned short wString); // 0x004B1800
static inline int MONSTER_IsItemIdentified(D2UnitStrc* pItem); // 0x004B1F60

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x004A74A0
int __cdecl MONSTER_GetPlayerDefensePercent()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPercent = 100;
    int nDefense = UNITS_GetDefense(pPlayer);
    nDefense += STATLIST_UnitGetStatValue(pPlayer, STAT_ARMORCLASS_VS_HTH, 0);
    const int nDifficulty = GAME_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 470);

    const int nMonsterId = UI_GetHoverClassId();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 8, &monStatsInit);
    int nToHit = monStatsInit.nTH;
    if (!nToHit)
    {
        memset(&monStatsInit, 0, sizeof(monStatsInit));
        DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 0x10, &monStatsInit);
        nToHit = monStatsInit.nTH;
        if (!nToHit)
        {
            memset(&monStatsInit, 0, sizeof(monStatsInit));
            DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 0x20, &monStatsInit);
            nToHit = monStatsInit.nTH;
        }
    }

    if (pMonStatsTxtRecord->nAlign != 1 && !GAME_IsExpansion() && GAME_GetDifficulty())
    {
        nToHit = nToHit * 10 / 15;
    }

    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nPercent = nToHit * 100 / (nToHit + nDefense);
    }

    const int nLevel = pMonStatsTxtRecord->nLevel[nDifficulty];
    return 2 * nLevel * nPercent / (STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0) + nLevel);
}

static D2MonsterDataStrc* CLIENT_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x004AC740
unsigned char* __fastcall MONSTER_GetMonUmods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterData(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// 0x004ADE40
void __fastcall MONSTER_RunUModCommandCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 0);
}

// 0x004ADE50
void __fastcall MONSTER_RunUModUpdateCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 1);
}

// 0x004ADE60
void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 2);
}

// 0x004ADE70
void __fastcall MONSTER_RunUModHitCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 3);
}

// 0x004ADE80
void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pArg && pUnit->dwUnitType == UNIT_MONSTER)
    {
        MONSTER_RunUModCallbacks(pUnit, pArg, 4);
    }
}

static inline D2MonStatsTxt* CLIENT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004AE0A0
void __fastcall MONSTER_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nClientFlags = wFlags;
            pMonsterData->pMonstatsTxt = CLIENT_GetMonStatsTxtRecord(pUnit->dwClassId);
        }
    }
}

// 0x004AE0E0
void __fastcall MONSTER_FreeMonsterName(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->wszMonName)
        {
            FOG_Free(pMonsterData->wszMonName, gszMonsterSourceFile_006DA5C8, 0x66, 0);
            pMonsterData->wszMonName = 0;
        }
    }
}

// 0x004AE110
extern "C" __declspec(dllexport) unsigned int* __fastcall MONSTER_GetMonInteractPtr(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData) {
        return 0;
    }
    return (unsigned int*)&pMonsterData->pMonInteract;
}

static inline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x004AE130
int __fastcall MONSTER_GetOwnerGUID(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return -1;
    }

    return pMonsterData->nOwnerGUID;
}

// 0x004AE150
extern "C" __declspec(dllexport) void __fastcall MONSTER_SetOwnerGUID(D2UnitStrc* pUnit, int nValue) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        pUnit->pMonsterData->nOwnerGUID = nValue;
    }
}

// 0x004AE170
extern "C" __declspec(dllexport) int* __fastcall MONSTER_GetAiValuePtr(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData) {
        return 0;
    }
    return &pMonsterData->nAiValue;
}

// 0x004AE190
void __fastcall MONSTER_SetMinionSpawnClassId(D2UnitStrc* pUnit, int nValue)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nMinionSpawnClassId = nValue;
    }
}

// 0x004AE1B0
int __fastcall MONSTER_GetMinionSpawnClassId(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return -1;
    }

    return pMonsterData->nMinionSpawnClassId;
}

// 0x004AE1D0
static void MONSTER_RefreshMonsterMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const unsigned int nMode = pUnit->dwAnimMode;
        if (nMode < 0x10 && nMode && nMode != 0xC)
        {
            sub_00465BF0(pUnit, 0);
            UNITMODE_RecacheUnitPath(pUnit);
            UNITMODE_SetUnitMode(pUnit, 1);
        }
    }
}

// 0x004AE210
void __fastcall MONSTER_SetMonsterLight(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    unsigned char nLight = MONSTERS_GetMaximalLightRadius(pUnit);
    if (nLight < pMonStats2TxtRecord->nLightRadius)
    {
        nLight = pMonStats2TxtRecord->nLightRadius;
    }

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_DENOFEVIL && INV_GetTableByte(0, 1) && !sub_00451F30_TestUnitFlag(pUnit, 0x200000)
        && pMonStatsTxtRecord->nAlign != 1 && pMonStatsTxtRecord->nAlign != 2)
    {
        nLight = 3;
    }
    else if (!nLight)
    {
        return;
    }

    D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pUnit, 0, nLight, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    if (pUnit->pLight)
    {
        CUNIT_FreeLight(pUnit);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, nLight);
}

void __cdecl sub_F03_Emit_004AE1D0(D2UnitStrc* pUnit)
{
    MONSTER_RefreshMonsterMode(pUnit);
}

void __cdecl sub_F03_Emit_004AFB60(D2UnitStrc* pUnit)
{
    MONSTER_ReplaySequence(pUnit);
}

int __cdecl sub_F03_Emit_004AFBC0(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    return MONSTER_HasMonStatsFlag(pUnit, pRecord);
}

void __cdecl sub_F03_Emit_004AFC10(D2UnitStrc* pUnit)
{
    MONSTER_CreateDeathMissiles(pUnit);
}

// 0x004AE320
int __fastcall MONSTER_IsChampionMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x04);
    return 0;
}

// 0x004AE340
int __fastcall MONSTER_IsGhostlyMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x40);
    return 0;
}

// 0x004AE360
int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x08);
    return 0;
}

// 0x004AE380
int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x10);
    return 0;
}

// 0x004AE3A0
int __fastcall MONSTER_IsSuperUniqueMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x02);
    return 0;
}

// 0x004AE3C0
void __fastcall MONSTER_OwnerMissileHit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (pOwner)
    {
        D2_ASSERT(pOwner->dwUnitType == UNIT_MISSILE, 353);
        sub_004D2D70_CltMissileHit(pOwner, 0, 0);
    }
}

static inline unsigned int sub_H12_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* sub_H12_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int sub_H12_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static inline int sub_H12_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_H12_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004AE400
static void sub_004AE400_CastRandomCurse(D2UnitStrc* pUnit)
{
    const int nIndex = sub_H12_SeedStep(&pUnit->pSeed) % 5;
    D2_ASSERT(nIndex < 5, 0x174);

    const int nSkill = gaRandomCurseSkills_006DA5DC[nIndex];
    D2UnitStrc* pMissile = GFXUTIL_SubmitMissileRequest(pUnit, nSkill, sub_H12_UnitX(pUnit), sub_H12_UnitY(pUnit), 0, 1);
    if (pMissile)
    {
        UNITS_StoreOwner(pMissile, pUnit);
        UNITS_StoreOwner(pUnit, pMissile);
        PARTICLE_ResetGfxMotion(pMissile);
        sub_004DA620(pMissile, 1);
        pMissile->dwFlagEx |= 0x40000;
    }
}

static void sub_004AF4C0_UpdateMonsterFrame(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2Txt;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_H12_GetSkillsTxt(SKILLS_GetSkillIdFromSkill(pSkill, gszMonsterSourceFile_006DA5C8, 0x3B5));
    if (!pSkillsTxt)
    {
        return;
    }

    int nFlags = SKILLS_GetFlags(pSkill);
    int bCheckFrame = 1;
    if ((nFlags & 1) && sub_004807C0(pUnit))
    {
        if (pSkillsTxt->wSrvDoFunc != 0x43)
        {
            nFlags |= 2;
            SKILLS_SetFlags(pSkill, nFlags);
        }
        SKILLS_DoUsedSkill(pUnit);
        bCheckFrame = 0;
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame != 4)
    {
        if (!bCheckFrame || sub_00451F30_TestUnitFlag(pUnit, 0x40) || nActionFrame != 1 && nActionFrame != 2 && nActionFrame != 3)
        {
            switch (pSkillsTxt->wSrvDoFunc)
            {
            case 0x5F:
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt)
                {
                    return;
                }

                SKILLS_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise >> 8) > pMonStats2Txt->nInfernoAnim)
                {
                    pUnit->nSeqCurrentFramePrecise = pMonStats2Txt->nInfernoRollback << 8;
                }
                return;

            case 0x7E:
                SKILLS_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise & ~0xFF) >= 0xC00)
                {
                    pUnit->nSeqCurrentFramePrecise = 0x800;
                }
                return;

            case 0x98:
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt || !STATES_CheckState(pUnit, STATE_INFERNO))
                {
                    return;
                }

                const int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
                if (nFrame >= pMonStats2Txt->nInfernoAnim)
                {
                    SKILLS_DoUsedSkill(pUnit);
                }

                if (nFrame >= pMonStats2Txt->nInfernoRollback)
                {
                    pUnit->nSeqCurrentFramePrecise = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) + pMonStats2Txt->nInfernoRollback - 4) << 8;
                }
                return;
            }
            }
            return;
        }
    }

    SKILLS_DoUsedSkill(pUnit);
}

// build: symbol ?MONSTER_HandleAttackEvent@* 0x004AF6A0
static void MONSTER_HandleAttackEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    const int nId = sub_00463860_GetMonsterId(pUnit);
    const int nMonsterId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    if (nMode == 0xD && nMonsterId != MONSTER_SANDLEAPER1)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            sub_00650590(pPath);
            PATH_SetPathingFlag(pPath, 0);
            sub_00648DC0(pPath);
            UNITMODE_SetUnitMode(pUnit, 3);
        }
        return;
    }

    if (CUNIT_GetPathTargetUnit(pUnit))
    {
        sub_00465BF0(pUnit, 0);
    }

    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nByte1A7)
    {
        switch (pUnit->dwAnimMode)
        {
        case 8:
            if (nMonsterId == MONSTER_VULTURE1)
            {
                return;
            }
        case 5:
        case 9:
            if (nMonsterId == MONSTER_TRAPPEDSOUL1 || nMonsterId == MONSTER_TRAPPEDSOUL2)
            {
                UNITMODE_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 10:
            if (nMonsterId == MONSTER_BATDEMON1)
            {
                UNITMODE_SetUnitMode(pUnit, 0xB);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 11:
            if (nMonsterId == MONSTER_BATDEMON1)
            {
                return;
            }
            break;

        case 2:
            if (nMonsterId == MONSTER_ICEGLOBE || nMonsterId == MONSTER_WILLOWISP1)
            {
                return;
            }
            break;

        case 4:
            if (nMonsterId == MONSTER_TRAPPEDSOUL1 || nMonsterId == MONSTER_TRAPPEDSOUL2)
            {
                UNITMODE_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            if (nMonsterId == MONSTER_CATAPULT1)
            {
                sub_004AE3C0(pUnit);
                sub_004AE400_CastRandomCurse(pUnit);
            }
            break;

        case 14:
            if (nMonsterId == MONSTER_FROGDEMON1)
            {
                return;
            }
            break;

        case 12:
            if (nMonsterId == MONSTER_MAGGOTQUEEN1)
            {
                return;
            }
            break;
        }
    }

    if (sub_H12_HasUnitFlagBit(pUnit))
    {
        UNITMODE_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
        return;
    }

    if (!sub_00463720_TestUnitFlagEx(pUnit, 0x2000))
    {
        UNITMODE_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
    }
}

// build: symbol ?MONSTER_UpdateMonsterClient@* 0x004B13A0
void __fastcall MONSTER_UpdateMonsterClient(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_FREEZE) && !CUNIT_IsDeadOrDying(pUnit))
    {
        return;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    D2MonAnimRecStrc* pRecord = sub_004AF400_GetMonsterAnimRecord(pUnit);
    if (!pRecord)
    {
        return;
    }

    sub_004AF4C0_UpdateMonsterFrame(pUnit);

    int bResult;
    switch (pRecord->nType)
    {
    case 1:
        bResult = sub_004807C0(pUnit);
        break;

    default:
        bResult = 0;
        break;
    }

    if (nMode == 1 && !sub_004AE080(pUnit, nMode))
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath && PATH_GetTargetUnit(pPath))
        {
            int nUnitType;
            int nUnitGUID;
            PATH_GetTargetTypeAndGUID(pPath, &nUnitType, &nUnitGUID);
            D2UnitStrc* pTarget = CUNIT_FindClientUnit(nUnitGUID, nUnitType);
            PATH_SetTargetUnit(pPath, pTarget);
            if (pTarget)
            {
                D2Common_10213(pUnit);
            }
        }
        else
        {
            D2Common_10213(pUnit);
        }
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nClassId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if ((pMonStatsTxt->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !MONSTERREGION_CheckMonStats2Flag(nClassId, 0xD)
        && pUnit->dwAnimMode == 1 && !sub_00451F30_TestUnitFlag(pUnit, 0x200)
        && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && (unsigned int)sub_00641530(pUnit, pPlayer) < 7)
        {
            D2SeedStrc* pSeed = &pUnit->pSeed;
            if (pSeed && (int)SEED_RollLimitedRandomNumber(pSeed, 0x64) < 0xA)
            {
                D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
                if (pPath)
                {
                    D2Common_10216(pPath, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer), 0);
                }
            }
        }
    }

    const int nRet = sub_004B1280(pUnit, pRecord);
    int bAttack = 0;
    switch (pRecord->nAction)
    {
    case 1:
        bAttack = bResult;
        break;

    case 2:
    case 3:
        bAttack = nRet;
        break;

    case 4:
        if (bResult && sub_006217C0(pUnit))
        {
            bAttack = 1;
        }
        break;
    }

    sub_004AF2E0_MonsterSkillEvent(pUnit);
    MONSTER_RunUModFrameCallbacks(pUnit);
    if (pUnit->pDynamicPath)
    {
        D2COMMON_10193_PATH_AdjustDirection(pUnit->pDynamicPath);
    }

    if (bAttack)
    {
        MONSTER_HandleAttackEvent(pUnit);
    }

    if (!pUnit->dwAnimMode && pUnit->dwClassId == 0x210 && sub_00451F30_TestUnitFlag(pUnit, 1))
    {
        pUnit->dwFlags &= ~1;
        CUNIT_SpawnPresetUnit(0x1DE, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 2, 0);
    }

    if (sub_0063A340(pUnit))
    {
        SKILLS_RunStateActiveFuncs(pUnit);
    }

    UNITSND_UpdateModeSound(pUnit);
    sub_004CAF60(pUnit);
}

static inline unsigned __int64 sub_I07_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x004AE4F0
static void MONSTER_HandleMonsterEvent(D2UnitStrc* pUnit, int nEvent)
{
    switch (nEvent)
    {
    case 0x14B:
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer)
        {
            UNITS_SetTargetUnitForDynamicUnit(pUnit, pPlayer);
            sub_00465BF0(pUnit, 0);
        }
        break;
    }
    case 0x9D:
    case 0x9E:
    case 0x13F:
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        break;
    case 0x96:
        gpEventUnit_007C0C5C = pUnit;
        break;
    case 0x158:
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        D2DirectionArgStrc tDirection;
        tDirection.nDirection = sub_I07_SeedRoll(&pPlayer->pSeed) & 0x3F;
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 1);
        sub_006488A0_SetDirection(pPath, tDirection);
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
        break;
    }
    case 0x1F1:
    case 0x1F2:
    case 0x1F3:
    case 0x1F4:
        sub_004AE400_CastRandomCurse(pUnit);
        break;
    case 0x19D:
    {
        D2UnitStrc* pMissile = GFXUTIL_SubmitMissileRequest(pUnit, 0x188, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        if (pMissile)
        {
            UNITS_StoreOwner(pMissile, pUnit);
        }
        break;
    }
    case 0x23A:
        GFXUTIL_SubmitMissileRequest(pUnit, 0x265, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        break;
    }
}

// 0x004AED30
void __fastcall MONSTER_FreeClientUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    GFX_FreeGfxData(pUnit);
    CUNIT_RemoveInventoryUnits(pUnit, 1);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;

    if (gpAct_007A0634)
    {
        D2Common_10228(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
        CUNIT_FreeLight(pUnit);
    }

    PATH_FreeDynamicPath(0, pUnit->pDynamicPath);
    pUnit->pDynamicPath = 0;

    void* pResource = D2Common_10958(pUnit, 0);
    if (pResource)
    {
        DLIGHTMAP_ReleaseLight(pResource);
    }

    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->wszMonName)
        {
            FOG_Free(pMonsterData->wszMonName, gszMonsterSourceFile_006DA5C8, 102, 0);
            pMonsterData->wszMonName = 0;
        }
    }
}

// 0x004AF2E0
static void sub_004AF2E0_MonsterSkillEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    const int nMissile = D2Common_11050(pUnit, 1);
    if (nMissile == -1)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x20;
    switch (nMissile)
    {
    case MISSILE_MUMMY1:
    case MISSILE_MUMMY2:
    case MISSILE_MUMMY3:
    case MISSILE_MUMMY4:
        tMissile.dwFlags = 0x34;
        tMissile.nVelocity = 2;
        break;
    }
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nSkillLevel = 1;

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath)
        {
            return;
        }
        tMissile.nTargetX = D2COMMON_10175_PathGetFirstPointX(pPath);
        tMissile.nTargetY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
    }

    if (nMissile == MISSILE_PANTHERPOTORANGE || nMissile == MISSILE_PANTHERPOTGREEN)
    {
        if (pTarget)
        {
            MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, 0, 0, 0, 1, 0);
        }
    }
    else if (nMissile == MISSILE_CATAPULTCHARGEDBALL_ON)
    {
        sub_004AE3C0(pUnit);
        sub_004AE400_CastRandomCurse(pUnit);
    }
    else
    {
        sub_004CD540_CreateMissile(&tMissile);
    }

    MONSTER_SpawnQuillRatMissiles(pUnit, nMissile, tMissile.nTargetX, tMissile.nTargetY);
}

void __fastcall sub_M103_Emit_004B1000(D2UnitStrc* pItem, int nArg)
{
    if (MONSTER_IsStringUnused((unsigned short)nArg))
    {
        sub_M103_EmitSink(MONSTER_IsItemIdentified(pItem));
    }
    MONSTER_SetNpcMenuState(nArg);
    MONSTER_SetNpcMenuUnit(pItem);
    MONSTER_SetNpcMenuValue((unsigned short)nArg);
}

static inline unsigned int sub_J20_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* sub_J20_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline unsigned int sub_J20_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

static inline int sub_J20_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static inline int sub_J20_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_J20_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004AF400
static D2MonAnimRecStrc* sub_004AF400_GetMonsterAnimRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return 0;
    }

    if (pUnit->dwClassId == 0xF3 && nMode == 0xB || pUnit->dwClassId == 0x14D && nMode == 0xB)
    {
        return &gMonAnimRecord_00725328;
    }

    if (pUnit->dwClassId == 0x21F && nMode == 0xA || pUnit->dwClassId == 0x220 && nMode == 0xA || pUnit->dwClassId == 0x23A && nMode == 0xA)
    {
        return &gMonAnimRecord_00725334;
    }

    D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2Txt)
    {
        return 0;
    }

    if (pMonStats2Txt->nModeEnabledWhenMovingFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
    {
        return &gaMonAnimRecordsMoving_007252E0[nMode];
    }

    if (!nMode && MONSTERS_IsSandLeaper(pUnit, nMode))
    {
        return &gaMonAnimRecordsMoving_007252E0[0];
    }

    return &gaMonAnimRecords_00725220[pUnit->dwAnimMode];
}

void __fastcall sub_I07_Emit_004AE4F0(D2UnitStrc* pUnit, int nEvent)
{
    MONSTER_HandleMonsterEvent(pUnit, nEvent);
}

static inline unsigned int sub_M165_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int sub_M165_RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return sub_M165_SeedStep(pSeed) % nMax;
    }

    return sub_M165_SeedStep(pSeed) & (nMax - 1);
}

static inline D2MonStats2Txt* sub_M165_GetMonStats2Txt(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            const int nMonStatsEx = sgptDataTables->pMonStatsTxt[pUnit->dwClassId].wMonStatsEx;
            if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
            {
                return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
            }
        }
    }

    return 0;
}

static inline int sub_M165_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_M165_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004AF890
void __fastcall MONSTER_SpawnBloodMissiles(D2UnitStrc* pUnit, int nDefaultCount, int bRandomChance)
{
    if (bRandomChance && sub_M165_SeedStep(&pUnit->pSeed) % 25)
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_GETHIT && sub_M165_SeedStep(&pUnit->pSeed) % 3)
    {
        return;
    }

    int nCount = nDefaultCount;
    const int nExtraBlood = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_EXTRABLOOD, 0);
    if (nExtraBlood)
    {
        nCount = nExtraBlood;
    }

    D2MonStats2Txt* pMonStats2Txt = sub_M165_GetMonStats2Txt(pUnit);
    if (!pMonStats2Txt || pMonStats2Txt->nBleed <= 0)
    {
        return;
    }

    for (int i = 0; i < nCount; ++i)
    {
        int nDirection;
        if (PATH_GetVelocity(pUnit->pDynamicPath))
        {
            const int nUnitDirection = UNITS_GetDirection(pUnit) >> 3;
            nDirection = (nUnitDirection + sub_M165_SeedStep(&pUnit->pSeed) % 7 - 3) & 7;
        }
        else
        {
            nDirection = sub_M165_RollLimited(&pUnit->pSeed, 8);
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        int nDir = nDirection;
        const int nLastDirection = (nDirection - 1) & 7;
        int nX;
        int nY;
        if (nDir == nLastDirection)
        {
            return;
        }

        do
        {
            nX = gnBloodOffsetX_006DA610[nDir] + sub_M165_UnitX(pUnit);
            nY = gnBloodOffsetY_006DA5F0[nDir] + sub_M165_UnitY(pUnit);
            if (!COLLISION_CheckMask(pRoom, nX, nY, 1))
            {
                goto LABEL_SPAWN;
            }

            nDir = (nDir + 1) & 7;
        }
        while (nDir != nLastDirection);

        return;

LABEL_SPAWN:
        MISSILE_SubmitOwnerRequest(pUnit, 0x12 + sub_M165_RollLimited(&pUnit->pSeed, 2 * pMonStats2Txt->nBleed), nX, nY, 0, 1);
    }
}

// 0x004AFB60
static void MONSTER_ReplaySequence(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pSequenceRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    const int nCount = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
    for (int i = 0; i < nCount; ++i)
    {
        int nMode;
        int nFrame;
        int nDirection;
        int nEvent;
        DATATBLS_ComputeSequenceAnimation(pSequenceRecord, i << 8, i << 8, &nMode, &nFrame, &nDirection, &nEvent);
        pUnit->dwAnimMode = nMode;
        GFX_RefreshUnitGfx(pUnit, 0);
    }
}

// 0x004AFBC0
static int MONSTER_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    if (!pUnit || !pRecord)
        return 0;

    if (pRecord->bSet)
    {
        const int nIndex = pRecord->nIndex;
        if (nIndex < 0x10)
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2Txt)
                return pMonStats2Txt->nModeEnabledWhenMovingFlags[nIndex >> 3] & gdwBitMasks[nIndex & 7];
        }
    }
    return 0;
}

// 0x004AFC10
static void MONSTER_CreateDeathMissiles(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return;

    D2MissileStrc tMissile;
    if (STATES_CheckState(pUnit, STATE_UBERMINION) && !STATES_CheckState(pUnit, STATE_FREEZE))
    {
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2020;
        tMissile.pOwner = pUnit;
        tMissile.pOrigin = pUnit;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = MISSILE_SUICIDEFIREEXPLODE;
        sub_004CD540_CreateMissile(&tMissile);
        tMissile.nMissile = MISSILE_SUICIDECORPSEEXPLODE;
        sub_004CD540_CreateMissile(&tMissile);
        return;
    }

    const int nMissile = (unsigned char)UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId)->nType + 0x10F;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x2020;
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nSkillLevel = 1;
    tMissile.nMissile = nMissile;
    sub_004CD540_CreateMissile(&tMissile);
    tMissile.nMissile = MISSILE_ICEBREAKSMOKE;
    sub_004CD540_CreateMissile(&tMissile);
}

static inline int sub_J10_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_J10_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004AFCE0
static void MONSTER_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode == 12)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~14;
        }
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        if (sub_004DA0F0_GetUnitGfxOffsetZ(pUnit))
        {
            return;
        }
        PARTICLE_ResetGfxMotion(pUnit);
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        MISSILE_SetMotionFlagMask(pUnit, 1);
        GFXUTIL_SetMotionVectorB(pUnit, 0, 0, 2, 1);
        GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0xA0, 0);
    }
    else if (nMode == 14 || nMode == 10)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 14;
        }
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        if (!sub_004DA0F0_GetUnitGfxOffsetZ(pUnit))
        {
            return;
        }
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        MISSILE_SetMotionFlagMask(pUnit, 0);
        GFXUTIL_SetMotionVectorB(pUnit, 0, 0, -8, 1);
        GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0, 0);
    }
}

void __fastcall sub_J10_Emit_004AFCE0(D2UnitStrc* pUnit, int nMode, int nOtherMode)
{
    MONSTER_UpdateCollisionForMode(pUnit, nMode);
    MONSTER_UpdateCollisionForMode(pUnit, nOtherMode);
}

int gdwGlobal_007C0C5C; // 0x007C0C5C

int gdwGlobal_007C0E5C; // 0x007C0E5C

char gData_007C0E84[4]; // 0x007C0E84

// 0x004B1020
int __cdecl sub_004B1020()
{
    return gdwGlobal_007C0C5C;
}

// 0x004B1030
D2UnitStrc* __fastcall MONSTER_GetLinkedPlayer(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nOwnerGUID != -1)
    {
        return CUNIT_FindClientUnit(pUnit->pMonsterData->nOwnerGUID, 0);
    }
    return 0;
}

// 0x004B1090
void __fastcall MONSTER_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo)
{
    if (!pUnit || !pInfo)
    {
        return;
    }

    pUnit->dwFlags |= 0x202;
    const int nAct = MONSTERS_GetActFromHirelingTxt(GAME_IsExpansion(), 0, pInfo->f_0);
    const int nDifficulty = GAME_GetDifficulty();
    D2HirelingInitStrc hirelingInit;
    if (!MONSTERS_HirelingInit(GAME_IsExpansion(), sub_00463DD0_GetPlayerUnit(), pInfo->nSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    const int nLevel = hirelingInit.nLevel;
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(GAME_IsExpansion(), hirelingInit.nId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;
    if (nLevelUps < 0)
    {
        nLevelUps = 0;
    }

    for (int i = 0; i < 6; ++i)
    {
        const int nSkillId = pHirelingTxtRecord->dwSkill[i];
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        int nSkillLevel = (pHirelingTxtRecord->nSLvlPerLvl[i] * nLevelUps >> 5) + pHirelingTxtRecord->nLevel[i];
        if (nSkillLevel >= 32)
        {
            nSkillLevel = 32;
        }

        const int nMode = pHirelingTxtRecord->nMode[i];
        SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, gszMonsterSourceFile_006DA5C8, 2504);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), nMode);
    }

    unsigned short wNameId = pInfo->f_0;
    if (wNameId == 0x421)
    {
        wNameId = 0x2B0D;
    }

    MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(wNameId));
    ITEM_RefreshUnitEquipment(pUnit);
}

// 0x004B1670
int __cdecl MONSTER_GetUseItemMode()
{
    return gdwGlobal_007C0D2D;
}

// 0x004B17D0
static inline void MONSTER_SetNpcMenuState(int nState)
{
    gnGlobal_007C0C6B = nState;
}

// 0x004B17E0
static inline void MONSTER_SetNpcMenuUnit(D2UnitStrc* pUnit)
{
    gpUnit_007C0DD4 = pUnit;
}

// 0x004B17F0
static inline void MONSTER_SetNpcMenuValue(unsigned short wValue)
{
    gwGlobal_007C0DD8 = wValue;
}

// 0x004B1800
static inline bool MONSTER_IsStringUnused(unsigned short wString)
{
    for (int i = 0; i < gtStringList_007C0D9A.wCount; ++i)
    {
        if (gtStringList_007C0D9A.awStrings[i] == wString)
        {
            return false;
        }
    }
    return true;
}

// 0x004B1970
void __cdecl MONSTER_ResetUsedStrings()
{
    gtStringList_007C0D9A.wCount = 0;
}

// 0x004B1D50
void __cdecl MONSTER_CloseNpcResource()
{
    if (gpRes_007C0D6B)
    {
        DIALOG_DestroyDialog(gpRes_007C0D6B);
        gpRes_007C0D6B = 0;
    }
}

// 0x004B1DC0
int __cdecl sub_004B1DC0()
{
    return 0;
}

// 0x004B1F60
static inline int MONSTER_IsItemIdentified(D2UnitStrc* pItem)
{
    return ITEMS_CheckItemFlag(pItem, 0x10, 2457, ".\\UI\\npcmenu.cpp");
}

// 0x004B2010
int __cdecl sub_004B2010()
{
    return 0;
}

// 0x004B32D0
int __cdecl MONSTER_GetQuestFlags()
{
    return gdwGlobal_007C0D43;
}

// 0x004B32E0
int __cdecl MONSTER_GetGameQuestFlags()
{
    return gdwGlobal_007C0D47;
}

// 0x004B3500
int __cdecl sub_004B3500()
{
    return gdwGlobal_007C0DB0;
}

// 0x004B70F0
int __cdecl sub_004B70F0()
{
    return gdwGlobal_007C0E54;
}

// 0x004B85E0
int __cdecl sub_004B85E0()
{
    return gdwGlobal_007C0E5C;
}

// 0x004B9060
void* __cdecl MONSTER_GetTradePartnerName()
{
    return gData_007C0E84;
}

// 0x004B90F0
int __cdecl MONSTER_GetSecondaryTradeGold()
{
    return gdwGlobal_007C0E78;
}

// 0x004B9100
int __cdecl MONSTER_GetPrimaryTradeGold()
{
    return gdwGlobal_007C0E68;
}

// 0x004B9E10
int __fastcall MONSTER_IsNearPlayer(D2UnitStrc* pUnit)
{
    D2Vector3FStrc tDelta;
    D2CoordStrc tPlayerCoords;
    D2CoordStrc tUnitCoords;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    UNITS_GetClientCoords(pPlayer, &tPlayerCoords);
    UNITS_GetClientCoords(pUnit, &tUnitCoords);
    tDelta.fX = tUnitCoords.nX - tPlayerCoords.nX;
    tDelta.fY = (tUnitCoords.nY - tPlayerCoords.nY) * 2.0f;
    if (GFXUTIL_VectorLengthSquared(tDelta.fX, tDelta.fY) <= 490000.0)
    {
        return 1;
    }

    return 0;
}

// 0x004BAC50
int __cdecl sub_004BAC50()
{
    return 0;
}

// 0x004BB5D0
int __cdecl sub_004BB5D0()
{
    return 0;
}

// 0x004BF9B0
int __cdecl sub_004BF9B0()
{
    return 0;
}

// 0x004C2530
int __cdecl sub_004C2530()
{
    return 0;
}

// 0x004CCF30
int __cdecl sub_004CCF30()
{
    return gdwGlobal_0072A348;
}

// 0x004D9160
void __fastcall sub_004D9160(D2UnitStrc* pArg)
{
    SKILLS_RefreshPassiveSkills(pArg);
}

// 0x004D9170
void __fastcall sub_004D9170(D2UnitStrc* pArg)
{
    SKILLS_RefreshPassiveSkills(pArg);
}

// 0x004DF870
int __cdecl sub_004DF870()
{
    return gdwGlobal_007C8C78;
}

// 0x004DF880
int __cdecl sub_004DF880()
{
    return gdwGlobal_007C8C78;
}

void* __cdecl sub_004E03B0(); // 0x004E03B0

void* __cdecl sub_004E03E0(); // 0x004E03E0

void* __cdecl sub_004E0410(); // 0x004E0410

// 0x004E0680
int __cdecl sub_004E0680()
{
    return gdwGlobal_0072AE24;
}

// 0x004E4040
void __stdcall sub_004E4040(int nUnused1)
{
}

#include "gen/data/Source/D2Client/UNIT/Monster.inc"
