#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2GameTypes.h"

typedef void (__fastcall* UMODCALLBACK)(void* pTarget, int nUMod, int bUnique);

struct D2UModCallbacksStrc
{
    UMODCALLBACK pCallbacks[5];
};

extern D2UModCallbacksStrc gaUModCallbacks_00724E28[]; // 0x00724E28

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GfxLightStrc;

struct D2RoomStrc;

struct D2MonStatsTxt;

struct D2MonsterDataStrc;

struct D2MonStats2Txt;

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2DirectionArgStrc;

struct D2DifficultyLevelsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex); // 0x0063E7A0

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

typedef char I07_check_unit_a[(I07_OFFSET(D2UnitStrc, pSeed) == 0x20 && I07_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C) ? 1 : -1];

typedef char I07_check_unit_b[(I07_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8 && I07_OFFSET(D2StaticPathStrc, nYPos) == 0x10) ? 1 : -1];

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, D2DirectionArgStrc tDirection); // 0x006488A0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit); // 0x00464930

void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg); // 0x00466CB0

void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall sub_004743D0_ReleaseOverlayResource(D2GfxLightStrc* pLight); // 0x004743D0

void __fastcall sub_004AE0A0_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags); // 0x004AE0A0

void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit); // 0x004AE210

void __fastcall sub_004DC510_InitGfxData(D2UnitStrc* pUnit); // 0x004DC510

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame); // 0x00626D40

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40

D2GfxLightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2); // 0x00643A00

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

static void sub_004AE4F0_MonsterEvent(D2UnitStrc* pUnit, int nEvent); // 0x004AE4F0

struct D2DifficultyLevelsTxt { char unk0[16]; int nMonsterSkillBonus; };

extern const char gszMonsterFile_006DA5C8[]; // 0x006DA5C8

int __cdecl sub_0044DCC0(); // 0x0044DCC0

void __stdcall sub_0063EEF0_AdjustMonsterStats(D2UnitStrc*, int, unsigned char); // 0x0063EEF0

void __stdcall PATH_AllocDynamicPath(void*, D2RoomStrc*, int, int, D2UnitStrc*, int); // 0x00649D00

int __stdcall MONSTERS_IsDead(D2UnitStrc*); // 0x0063EA40

void __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc*, int); // 0x00649560

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc*, int); // 0x00648C30

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0

void __stdcall sub_00644340_SetSkillMode(D2SkillStrc*, int); // 0x00644340

void __stdcall sub_0063EBC0(D2UnitStrc*, int); // 0x0063EBC0

int __fastcall sub_0046C140_TestMonModeFlag(int, int); // 0x0046C140

int __fastcall sub_004AE7B0_CheckMonsterFacing(D2UnitStrc*, D2UnitStrc*, int, int); // 0x004AE7B0

int __fastcall sub_0046C570_ForEachUnitInAdjacentRooms(D2UnitStrc*, int, int, int (__fastcall*)(D2UnitStrc*,D2UnitStrc*,int,int)); // 0x0046C570

D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

typedef unsigned int DWORD;

typedef char I20_check_unit_a[(I20_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && I20_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char I20_check_unit_b[(I20_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && I20_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char I20_check_unit_c[(I20_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && I20_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char I20_check_txt_a[(I20_OFFSET(D2MonStatsTxt, nByte1A7) == 0x1A7 && I20_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char I20_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && I20_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char I20_check_txt_c[(I20_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char I20_check_unit_d[(I20_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char I20_check_misc[(I20_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                              // 0x00681EF0


extern D2MonAnimRecStrc gaMonAnimRecords_00725220[];                                                        // 0x00725220

extern D2MonAnimRecStrc gaMonAnimRecordsMoving_007252E0[];                                                  // 0x007252E0

extern D2MonAnimRecStrc gMonAnimRecord_00725328;                                                            // 0x00725328

extern D2MonAnimRecStrc gMonAnimRecord_00725334;                                                            // 0x00725334

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0

D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730

void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70

void __fastcall sub_004ADE60(D2UnitStrc* pUnit);                                                            // 0x004ADE60

void __stdcall sub_004AF1B0(D2UnitStrc* pUnit, int nMissile, int nX, int nY);                               // 0x004AF1B0

int __fastcall sub_004C68F0_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0

void __fastcall sub_004C72F0(D2UnitStrc* pUnit);                                                            // 0x004C72F0

void __fastcall sub_004CB460_UpdateModeSound(D2UnitStrc* pUnit);                                                            // 0x004CB460

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540

D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                           // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

void __stdcall sub_00648750(D2DynamicPathStrc* pPath, int nArg);                                            // 0x00648750

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

void __fastcall sub_004B13A0_UpdateMonsterClient(D2UnitStrc* pUnit); // 0x004AF6A0

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

// build: context MONSTERS_CheckMonTypeFlag
static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

// build: context MONSTERUNIQUE_GetUMods
static unsigned char* MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
        return pMonsterData->nMonUmod;
    return 0;
}

// 0x004ADD90
void __stdcall sub_004ADD90_DispatchStates(D2UnitStrc* pUnit, void* pArgument, int nMode)
{
    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);
    if (nMode != 4)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks_00724E28[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pUnit, nUMod, bUnique);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks_00724E28[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pArgument, nUMod, bUnique);
            }
        }
    }
}

static D2MonStatsTxt* FACING_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int FACING_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = FACING_GetMonStatsTxtRecordInline(nClassId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nClassId;
}

// 0x004AE7B0
int __fastcall sub_004AE7B0_CheckMonsterFacing(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nArg3, int nArg4)
{
    const int nUnitType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nBaseId = FACING_GetBaseIdInline(pTarget->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_VILEMOTHER1)
    {
        return 0;
    }

    if (sub_006416D0_UnitEdgeDistance(pUnit, pTarget) > 1)
    {
        return 0;
    }

    const unsigned char nDirection = PATH_GetDirection(pTarget->pDynamicPath);
    unsigned char aDirections[8] = { 6, 7, 0, 1, 2, 3, 4, 5 };
    const unsigned char nNewDirection = aDirections[sub_0063E7A0_GetByteTableEntry(nDirection)];
    int nOffsetX;
    int nOffsetY;
    sub_0063E7E0_GetDirectionDelta(nNewDirection, &nOffsetX, &nOffsetY);
    const int nX = CLIENTS_GetUnitX(pTarget) + 3 * nOffsetX;
    const int nY = CLIENTS_GetUnitY(pTarget) + 3 * nOffsetY;
    if (nX == CLIENTS_GetUnitX(pUnit) && nY == CLIENTS_GetUnitY(pUnit))
    {
        return nDirection;
    }

    return 0;
}

static inline unsigned int sub_H12_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned __int64 sub_I07_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
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

static void sub_004AE400_CastRandomCurse(D2UnitStrc* pUnit)
{
    const int nIndex = sub_H12_SeedStep(&pUnit->pSeed) % 5;
    D2_ASSERT(nIndex < 5, 0x174);

    const int nSkill = gaRandomCurseSkills_006DA5DC[nIndex];
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nSkill, sub_H12_UnitX(pUnit), sub_H12_UnitY(pUnit), 0, 1);
    if (pMissile)
    {
        UNITS_StoreOwner(pMissile, pUnit);
        UNITS_StoreOwner(pUnit, pMissile);
        sub_004DA000_ResetGfxMotion(pMissile);
        sub_004DA620(pMissile, 1);
        pMissile->dwFlagEx |= 0x40000;
    }
}

static void sub_004AE4F0_MonsterEvent(D2UnitStrc* pUnit, int nEvent)
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
        D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, 0x188, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        if (pMissile)
        {
            UNITS_StoreOwner(pMissile, pUnit);
        }
        break;
    }
    case 0x23A:
        sub_004CDB40_SubmitRequest(pUnit, 0x265, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        break;
    }
}

static inline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static inline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = sub_F4B0_GetMonStatsTxt(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        const int nId = pMonStatsTxtRecord->wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }

    return 0;
}

static inline unsigned int MONSTERS_GetFlagInline(D2UnitStrc* pUnit, int nFlag)
{
    D2MonStatsTxt* pRecord=sub_F4B0_GetMonStatsTxt(pUnit->dwClassId);
    if (pRecord) return pRecord->nMonStatsFlags[nFlag>>3]&gdwBitMasks[nFlag&7];
    return 0;
}

static inline int MONSTERS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pRecord=sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pRecord) return nClassId;
    return pRecord->nBaseId;
}

static __forceinline int MONSTERS_GetUnitBaseIdInline(D2UnitStrc* pUnit)
{
    if(pUnit->dwUnitType==UNIT_MONSTER)
    {
        int nId=MONSTERS_GetBaseIdInline(pUnit->dwClassId);
        if(nId>=0 && nId<sgptDataTables->nMonStatsTxtRecordCount) return nId;
    }
    return -1;
}

// 0x004AE8D0
void __fastcall sub_004AE8D0_InitMonster(D2UnitStrc* pUnit, D2RoomStrc* pRoom, int nX, int nY, int nClassId, int nMode)
{
    D2MonStatsTxt* pMonStats = sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pMonStats) return;
    D2MonStats2Txt* pMonStats2 = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (!pMonStats2) return;
    int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 0x1F0);
    STATLIST_AllocStatListEx(pUnit,0,0,0);
    STATLIST_SetUnitStat(pUnit,STAT_LEVEL,pMonStats->nLevel[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_ATTACKRATE,100,0);
    STATLIST_SetUnitStat(pUnit,STAT_VELOCITYPERCENT,75,0);
    STATLIST_SetUnitStat(pUnit,STAT_OTHER_ANIMRATE,100,0);
    STATLIST_SetUnitStat(pUnit,STAT_DAMAGERESIST,pMonStats->wResDm[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_MAGICRESIST,pMonStats->wResMa[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_FIRERESIST,pMonStats->wResFi[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_LIGHTRESIST,pMonStats->wResLi[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_COLDRESIST,pMonStats->wResCo[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_POISONRESIST,pMonStats->wResPo[nDifficulty],0);
    sub_0063EEF0_AdjustMonsterStats(pUnit,sub_0044DCC0(),sub_0044DCD0_GetDifficulty());
    STATLIST_SetUnitStat(pUnit,STAT_MAXHP,0x6400,0);
    STATLIST_SetUnitStat(pUnit,STAT_HITPOINTS,0x6400,0);
    PATH_AllocDynamicPath(0,pRoom,nX,nY,pUnit,1);
    D2DynamicPathStrc* pPath=pUnit->pDynamicPath;
    PATH_SetVelocity(pPath,pMonStats->nVelocity<<8,gszMonsterFile_006DA5C8,0x208);
    if (!pUnit->pInventory && ((pMonStats->nMonStatsFlags[1]&gdwBitMasks[1]) || nClassId==0x123 || nClassId==0x165 || nClassId==0x1A1 || nClassId==0x1A2))
        pUnit->pInventory=INVENTORY_AllocInventory(0,pUnit);
    UNITS_ChangeAnimMode(pUnit,nMode);
    if (MONSTERS_IsDead(pUnit) && !(pMonStats2->nFlags[2]&gdwBitMasks[3]))
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit,1);
        sub_00649190_SetPathMode(pUnit,5);
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath,0x8000);
    }
    pUnit->nSeqCurrentFramePrecise=ITEMS_RollLimitedRandomNumber(&pUnit->pSeed,pUnit->dwFrameCountPrecise);
    if(pMonStats2->nFlags[0]&gdwBitMasks[3]) pUnit->dwFlags|=2; else pUnit->dwFlags&=~2;
    if(!(pMonStats2->nFlags[1]&gdwBitMasks[6])) pUnit->dwFlags|=0x20; else pUnit->dwFlags&=~0x20;
    pUnit->dwFlags|=8;
    if(pMonStats2->nFlags[1]&gdwBitMasks[1]) pUnit->dwFlags|=4; else pUnit->dwFlags&=~4;
    sub_004AE0A0_SetClientFlags(pUnit,0);
    sub_004AE4F0_MonsterEvent(pUnit,nClassId);
    sub_004AE210_SetMonsterLight(pUnit);
    pUnit->pSkills=SKILLS_AllocSkillList(0);
    sub_004AD020_RefreshMonster(pUnit);
    D2DifficultyLevelsTxt* pDiff=DATATBLS_GetDifficultyLevelsTxtRecord(nDifficulty);
    int nSkillBonus=pDiff->nMonsterSkillBonus;
    for (int i=0;i<8;++i)
    {
        if(pMonStats->nSkill[i]>=0 && pMonStats->nSkLvl[i]>0)
        {
            SKILLS_AssignSkill(pUnit,pMonStats->nSkill[i],pMonStats->nSkLvl[i]+nSkillBonus,1,gszMonsterFile_006DA5C8,0x23F);
            sub_00644340_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit,pMonStats->nSkill[i]),(char)pMonStats->nSkillMode[i]);
        }
    }
    sub_0063EBC0(pUnit,nSkillBonus);
    if(MONSTERS_GetFlagInline(pUnit,8)) return;
    D2DirectionArgStrc tDirection; tDirection.nDirection=0;
    int nBaseId=MONSTERS_GetUnitBaseIdInline(pUnit);
    if(sub_0046C140_TestMonModeFlag(pUnit->dwClassId,2)) tDirection.nDirection=sub_I07_SeedRoll(&pUnit->pSeed)&0x3F;
    if(nBaseId==MONSTER_MUMMY1) tDirection.nDirection=7;
    else if(nBaseId==MONSTER_VILECHILD1) tDirection.nDirection=sub_0046C570_ForEachUnitInAdjacentRooms(pUnit,0,0,sub_004AE7B0_CheckMonsterFacing);
    if(nClassId==0x15F) tDirection.nDirection=0x18;
    else if(nClassId==0x160) tDirection.nDirection=0;
    else if(nClassId==0x161) tDirection.nDirection=0x28;
    else if(nClassId==0x165 || nClassId==0x158) tDirection.nDirection=0;
    sub_006488A0_SetDirection(pPath,tDirection);
}

// 0x004AEDD0
void __fastcall sub_004AEDD0_ChangeMonsterClass(D2UnitStrc* pUnit, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    sub_0046EC10_FreeGfxData(pUnit);
    sub_00466CB0_RemoveInventoryUnits(pUnit, 0);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;
    sub_00464930_FreeLight(pUnit);
    D2GfxLightStrc* pLight = D2Common_10958(pUnit, 0);
    if (pLight)
    {
        sub_004743D0_ReleaseOverlayResource(pLight);
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->pAiParam)
        {
            FOG_Free(pMonsterData->pAiParam, ".\\UNIT\\Monster.cpp", 0x66, 0);
            pMonsterData->pAiParam = 0;
        }
    }

    pUnit->nPaletteIndex = 0;
    pUnit->dwClassId = nClassId;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return;
    }

    PATH_SetVelocity(pPath, pMonStatsTxtRecord->nVelocity << 8, ".\\UNIT\\Monster.cpp", 0x2B8);
    sub_00649FF0(pUnit, 0);
    if ((pMonStatsTxtRecord->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !pUnit->pInventory)
    {
        pUnit->pInventory = INVENTORY_AllocInventory(0, pUnit);
    }

    STATLIST_AllocStatListEx(pUnit, 0, 0, 0);
    STATLIST_SetUnitStat(pUnit, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_OTHER_ANIMRATE, 100, 0);
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, pMonStatsTxtRecord->wResDm[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, pMonStatsTxtRecord->wResMa[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, pMonStatsTxtRecord->wResFi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, pMonStatsTxtRecord->wResLi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, pMonStatsTxtRecord->wResCo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, pMonStatsTxtRecord->wResPo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, 0x8000, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0x8000, 0);
    UNITS_ChangeAnimMode(pUnit, 1);
    pUnit->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pUnit->dwFrameCountPrecise);

    if (pMonStats2TxtRecord->nFlags[3 >> 3] & gdwBitMasks[3 & 7])
    {
        pUnit->dwFlags |= 2;
    }
    else
    {
        pUnit->dwFlags &= ~2;
    }

    pUnit->dwFlagEx &= ~0x40000;
    if (!(pMonStats2TxtRecord->nFlags[14 >> 3] & gdwBitMasks[14 & 7]))
    {
        pUnit->dwFlags |= 0x20;
    }
    else
    {
        pUnit->dwFlags &= ~0x20;
    }

    pUnit->dwFlags |= 8;
    if (pMonStats2TxtRecord->nFlags[9 >> 3] & gdwBitMasks[9 & 7])
    {
        pUnit->dwFlags |= 4;
    }
    else
    {
        pUnit->dwFlags &= ~4;
    }

    sub_004AE0A0_SetClientFlags(pUnit, 0);
    sub_004AE4F0_MonsterEvent(pUnit, nClassId);
    sub_004AE210_SetMonsterLight(pUnit);
    sub_004AD020_RefreshMonster(pUnit);
    pUnit->pSkills = SKILLS_AllocSkillList(0);
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] >= 0)
        {
            SKILLS_AssignSkill(pUnit, pMonStatsTxtRecord->nSkill[i], pMonStatsTxtRecord->nSkLvl[i], 0, ".\\UNIT\\Monster.cpp", 0x2EA);
        }
    }

    if (!(pMonStatsTxtRecord->nMonStatsFlags[8 >> 3] & gdwBitMasks[8 & 7]))
    {
        PATH_SetDirection(pPath, (unsigned int)sub_I07_SeedRoll(&pUnit->pSeed) & 0x3F);
    }

    sub_004DC510_InitGfxData(pUnit);
    int nMode = 2;
    if (pMonStatsTxtRecord->nMode4D < 8)
    {
        nMode = pMonStatsTxtRecord->nMode4D + 2;
    }

    const int nId = (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount) ? pUnit->dwClassId : -1;
    switch (nId)
    {
    case 0x9C:
    case 0xD3:
    case 0xF2:
    case 0xF3:
        switch (sub_0044DCD0_GetDifficulty())
        {
        case 0:
            nMode = 2;
            break;

        case 1:
            nMode = 3;
            break;

        case 2:
            nMode = 4;
            break;
        }
        break;

    case 0x14D:
        nMode = 5;
        break;

    case 0x20F:
        sub_00470390(pUnit, 0xE3, 5, 0, 0, 0, 0, 0);
        break;
    }

    if (nMode >= 8)
    {
        nMode = 2;
    }

    sub_00463E20_SetUnitFlagA(pUnit, nMode);
    sub_00463E80_SetUnitFlagB(pUnit, nMode);
}

static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int GetBaseId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }
    return pMonStatsTxtRecord->nBaseId;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004AF1B0
void __stdcall sub_004AF1B0(D2UnitStrc* pUnit, int nMissile, int nX, int nY)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1)
    {
        return;
    }

    const int nBaseId = GetBaseId(pUnit->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_QUILLRAT1)
    {
        return;
    }
    else
    {

        D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return;
        }

        int nOffsetX = 5;
        int nOffsetY = 5;
        D2SeedStrc tSeed;
        SEED_InitSeed(&tSeed);
        SEED_InitLowSeed(&tSeed, 'SEIS');
        tSeed.nHighSeed = pUnit->dwUnitId;

        for (int nCount = pMonStatsTxtRecord->wAiParam[2][sub_0044DCD0_GetDifficulty()]; nCount > 0; --nCount)
        {
            if (SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetX = -nOffsetX;
            }

            if (SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetY = -nOffsetY;
            }

            sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, nX + nOffsetX, nY + nOffsetY, 0, 1);
        }
    }
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

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
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
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, 0, 1, 0);
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

    sub_004AF1B0(pUnit, nMissile, tMissile.nTargetX, tMissile.nTargetY);
}

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

    const int nClassId = pUnit->dwClassId;
    if (nClassId == 0xF3 && nMode == 0xB || nClassId == 0x14D && nMode == 0xB)
    {
        return &gMonAnimRecord_00725328;
    }

    if (nClassId == 0x21F && nMode == 0xA || nClassId == 0x220 && nMode == 0xA || nClassId == 0x23A && nMode == 0xA)
    {
        return &gMonAnimRecord_00725334;
    }

    D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
    if (!pMonStats2Txt)
    {
        return 0;
    }

    if (pMonStats2Txt->nModeEnabledWhenMovingFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
    {
        return &gaMonAnimRecordsMoving_007252E0[nMode];
    }

    if (!nMode && sub_0063E8D0(pUnit, nMode))
    {
        return &gaMonAnimRecordsMoving_007252E0[0];
    }

    return &gaMonAnimRecords_00725220[pUnit->dwAnimMode];
}

// 0x004AF4C0
static void sub_004AF4C0_UpdateMonsterFrame(D2UnitStrc* pUnit)
{
    D2MonStats2Txt* pMonStats2Txt;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_J20_GetSkillsTxt(SKILLS_GetSkillIdFromSkill(pSkill, gszMonsterSourceFile_006DA5C8, 0x3B5));
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
        sub_004C68F0_DoUsedSkill(pUnit);
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
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt)
                {
                    return;
                }

                sub_004C68F0_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise >> 8) > pMonStats2Txt->nInfernoAnim)
                {
                    pUnit->nSeqCurrentFramePrecise = pMonStats2Txt->nInfernoRollback << 8;
                }
                return;
            }

            case 0x7E:
                sub_004C68F0_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise & ~0xFF) >= 0xC00)
                {
                    pUnit->nSeqCurrentFramePrecise = 0x800;
                }
                return;

            case 0x98:
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
                if (pMonStats2Txt && STATES_CheckState(pUnit, STATE_INFERNO))
                {
                    const int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
                    if (nFrame >= pMonStats2Txt->nInfernoAnim)
                    {
                        sub_004C68F0_DoUsedSkill(pUnit);
                    }

                    if (nFrame >= pMonStats2Txt->nInfernoRollback)
                    {
                        pUnit->nSeqCurrentFramePrecise = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) + pMonStats2Txt->nInfernoRollback - 4) << 8;
                    }
                }
                return;
            }
            }
            return;
        }
    }

    sub_004C68F0_DoUsedSkill(pUnit);
}

void __fastcall sub_004B13A0_UpdateMonsterClient(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_FREEZE) && !sub_00464820_IsDeadOrDying(pUnit))
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

    int bResult = 0;
    switch (pRecord->nType)
    {
    case 1:
        bResult = sub_004807C0(pUnit);
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
            D2UnitStrc* pTarget = sub_00463990(nUnitGUID, nUnitType);
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

    if ((pMonStatsTxt->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !sub_004638A0_CheckMonStats2Flag(nClassId, 0xD)
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
    sub_004ADE60(pUnit);
    if (pUnit->pDynamicPath)
    {
        D2COMMON_10193_PATH_AdjustDirection(pUnit->pDynamicPath);
    }

    if (bAttack)
    {
        sub_004B13A0_UpdateMonsterClient(pUnit);
    }

    if (!pUnit->dwAnimMode && pUnit->dwClassId == 0x210 && sub_00451F30_TestUnitFlag(pUnit, 1))
    {
        pUnit->dwFlags &= ~1;
        sub_00466730_SpawnPresetUnit(0x1DE, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 2, 0);
    }

    if (sub_0063A340(pUnit))
    {
        sub_004C72F0(pUnit);
    }

    sub_004CB460_UpdateModeSound(pUnit);
    sub_004CAF60(pUnit);
}

#include "gen/data/Source/D2Client/UNIT/Monster_004AE7B0.inc"
