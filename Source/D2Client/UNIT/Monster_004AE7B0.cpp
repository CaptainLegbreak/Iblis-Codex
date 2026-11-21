#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Path.h"
#include "D2Txt.h"

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
    const int nUnitType = pTarget ? pTarget->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nBaseId = FACING_GetBaseIdInline(pTarget->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != 298)
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

static __forceinline unsigned int sub_H12_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned __int64 sub_I07_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static __forceinline int sub_H12_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_H12_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __declspec(noinline) void sub_004AE400_CastRandomCurse(D2UnitStrc* pUnit)
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

static __declspec(noinline) void sub_004AE4F0_MonsterEvent(D2UnitStrc* pUnit, int nEvent)
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

static __forceinline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static __forceinline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
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

static __forceinline unsigned int MONSTERS_GetFlagInline(D2UnitStrc* pUnit, int nFlag)
{
    D2MonStatsTxt* pRecord=sub_F4B0_GetMonStatsTxt(pUnit->dwClassId);
    if (pRecord) return pRecord->nMonStatsFlags[nFlag>>3]&gdwBitMasks[nFlag&7];
    return 0;
}

static __forceinline int MONSTERS_GetBaseIdInline(int nClassId)
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
    STATLIST_SetUnitStat(pUnit,12,pMonStats->nLevel[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,0x44,100,0);
    STATLIST_SetUnitStat(pUnit,0x43,75,0);
    STATLIST_SetUnitStat(pUnit,0x45,100,0);
    STATLIST_SetUnitStat(pUnit,0x24,pMonStats->wResDm[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,0x25,pMonStats->wResMa[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,0x27,pMonStats->wResFi[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,0x29,pMonStats->wResLi[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,0x2B,pMonStats->wResCo[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,0x2D,pMonStats->wResPo[nDifficulty],0);
    sub_0063EEF0_AdjustMonsterStats(pUnit,sub_0044DCC0(),sub_0044DCD0_GetDifficulty());
    STATLIST_SetUnitStat(pUnit,7,0x6400,0);
    STATLIST_SetUnitStat(pUnit,6,0x6400,0);
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
    if(nBaseId==0x60) tDirection.nDirection=7;
    else if(nBaseId==0x12D) tDirection.nDirection=sub_0046C570_ForEachUnitInAdjacentRooms(pUnit,0,0,sub_004AE7B0_CheckMonsterFacing);
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

    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
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
    STATLIST_SetUnitStat(pUnit, 0x44, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x43, 100, 0);
    STATLIST_SetUnitStat(pUnit, 0x45, 100, 0);
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    STATLIST_SetUnitStat(pUnit, 0x24, pMonStatsTxtRecord->wResDm[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x25, pMonStatsTxtRecord->wResMa[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x27, pMonStatsTxtRecord->wResFi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x29, pMonStatsTxtRecord->wResLi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x2B, pMonStatsTxtRecord->wResCo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 0x2D, pMonStatsTxtRecord->wResPo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, 7, 0x8000, 0);
    STATLIST_SetUnitStat(pUnit, 6, 0x8000, 0);
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

static __forceinline int GetBaseId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }
    return pMonStatsTxtRecord->nBaseId;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
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
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != 63)
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

#include "gen/data/Source/D2Client/UNIT/Monster_004AE7B0.inc"
