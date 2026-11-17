#include "D2Game.h"

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))
struct D2SeedStrc;
struct D2SkillsTxt;
struct D2StaticPathStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x18];
    int dwFrameCountPrecise;
    char unk0x4C[0x14];
    D2InventoryStrc* pInventory;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
    char f_74[0x34];
    int dwGameFrame;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x58];
    int dwAuraRangeCalc;
    unsigned char unk_68[0x18];
    short nAuraState;
    char unk0x082[0xAC];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    unsigned int dwCalc[4];
    char unk0x148[0x5D];
    unsigned char nSrcDam;
    char unk0x1A6[0x96];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[20];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553DC0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2); // 0x005544B0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4, int a5, unsigned int a6, int a7, int* a8); // 0x0056BD10
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId); // 0x00571B70
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill); // 0x00644500
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill); // 0x00644530
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nFlags); // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pPath, int nMask); // 0x00648C30
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pPath, int nMask); // 0x00648CE0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

struct D2StaticPathStrc
{
    char unk0x000[0x0C];
    int nX;
    int nY;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
void __fastcall sub_6FC62D90(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x005A5490
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D92D0
static int sub_005D92D0_IsDualWieldingMelee(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pLeftHandWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
    D2UnitStrc* pRightHandWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
    if (pLeftHandWeapon && ITEMS_CheckItemTypeId(pLeftHandWeapon, 0x2E) && pRightHandWeapon && ITEMS_CheckItemTypeId(pRightHandWeapon, 0x2E))
    {
        return 1;
    }

    return 0;
}

// 0x005D9320
static int __stdcall sub_005D9320_GetWhirlwindHitCount(D2GameStrc* pGame, D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        if ((unsigned int)lSeed & 1)
            return 0;
        return 1;
    }

    if (!pGame->bExpansion)
    {
        return 1;
    }

    int nFrame = SKILLS_GetParam4(pSkill);
    if (!nFrame)
    {
        SKILLS_SetParam4(pSkill, pGame->dwGameFrame + 4);
        return 1;
    }

    if (pGame->dwGameFrame < nFrame)
    {
        return 0;
    }

    int nCount = 1;
    int nDuration = 0;
    D2UnitStrc* pWeapon = sub_6FC7C7B0(pUnit);
    if (!pWeapon)
    {
        nDuration = 10;
    }
    else
    {
        const int nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pUnit, pWeapon);
        if (nAttackSpeed < 12)
        {
            nDuration = 4;
        }
        else if (nAttackSpeed < 15)
        {
            nDuration = 6;
        }
        else if (nAttackSpeed < 18)
        {
            nDuration = 8;
        }
        else if (nAttackSpeed < 20)
        {
            nDuration = 10;
        }
        else if (nAttackSpeed < 23)
        {
            nDuration = 12;
        }
        else if (nAttackSpeed < 26)
        {
            nDuration = 14;
        }
        else
        {
            nDuration = 16;
        }
    }

    if (sub_005D92D0_IsDualWieldingMelee(pUnit))
    {
        nCount = 2;
    }

    nFrame += nDuration;
    if (nFrame < pGame->dwGameFrame)
    {
        nFrame = pGame->dwGameFrame + nDuration;
    }

    SKILLS_SetParam4(pSkill, nFrame);
    return nCount;
}

// 0x005D9460
int __fastcall SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSkillId, int nX, int nY)
{
    SKILLS_SetFlags(pSkill, 0);
    sub_6FCBDE90(pUnit, 0);
    sub_00571B70_SkillUpdate(pUnit, nSkillId);

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    const int bPlayer = nUnitType == 0;
    const int nFootprintMask = bPlayer ? 0x80 : 0x100;
    const int nMoveMask = bPlayer ? 0x1C09 : 0x3C01;
    if (nX && nY)
    {
        COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nFootprintMask);
    }

    PATH_SetFootprintCollisionMask(pPath, nFootprintMask);
    PATH_SetMoveTestCollisionMask(pPath, nMoveMask);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (pStatList)
        {
            D2Common_10474(pUnit, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
    }

    return 1;
}

// 0x005D9580
int __fastcall SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, nSkillId, nX, nY);
        return 0;
    }

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if ((nSkillFlags & 3) == 3)
    {
        SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, nSkillId, nX, nY);
        return 1;
    }

    if (!(nSkillFlags & 1) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == 0)
    {
        D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 3);
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, 0);
        pUnit->dwFrameCountPrecise = 0x400;
    }

    int nCount = sub_005D9320_GetWhirlwindHitCount(pGame, pSkill, pUnit);
    for (int i = 0; i < nCount; ++i)
    {
        const int nParam3 = SKILLS_GetParam3(pSkill);
        D2UnitStrc* pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, 5, 3, nParam3, 0);
        if (!pTarget)
        {
            SKILLS_SetParam3(pSkill, -1);
            nCount = 0;
        }
        else
        {
            SKILLS_SetParam3(pSkill, !pTarget ? -1 : pTarget->dwUnitId);

            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
            if (damage.wResultFlags & 1)
            {
                damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
                damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
                if (pSkillsTxtRecord->dwHitClass)
                {
                    damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
                }

                damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
            }

            unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
            if (!pSkillsTxtRecord->nSrcDam)
            {
                nSrcDam = 0x80;
            }

            SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
            SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }

        int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 0x2000)
        {
            nFlags &= ~0x2000;
        }
        else
        {
            nFlags |= 0x2000;
        }

        SKILLS_SetFlags(pSkill, nFlags);
    }

    return 1;
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005D9A10
static int __stdcall sub_005D9A10_FindLeapTargetPosition(D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, *pX, *pY);
    if (nDistance <= 1)
    {
        nDistance = 1;
    }

    if (nDistance > nAuraRange)
    {
        const int nOffsetX = *pX - nUnitX;
        const int nOffsetY = *pY - nUnitY;
        *pX = nUnitX + nOffsetX * nAuraRange / nDistance;
        *pY = nUnitY + nOffsetY * nAuraRange / nDistance;
    }

    int nY = *pY;
    int nDiffY = nY - nUnitY;
    int nX;
    int nDiffX;
    D2CoordStrc coords;
    int nCounter;
    nDiffY = D2_MIN(D2_MAX(nDiffY, -2), 2);
    nX = *pX;
    nDiffX = nUnitX - nX;
    nDiffX = D2_MIN(D2_MAX(nDiffX, -2), 2);
    coords.nX = nX;
    coords.nY = nY;
    nCounter = 3;
    while (nCounter)
    {
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), coords.nX, coords.nY);
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &coords, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
        nX = coords.nX;
        nY = coords.nY;
        if (pRoom && !COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x1C09) && sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0x804) && UNITS_GetDistanceToCoordinates(pUnit, nX, nY) <= nAuraRange)
        {
            *pX = nX;
            *pY = nY;
            return 1;
        }

        --nCounter;

        if (nCounter == 2)
        {
            coords.nX = *pX + nDiffY;
            coords.nY = *pY + nDiffX;
        }
        else if (nCounter == 1)
        {
            coords.nX = *pX - nDiffY;
            coords.nY = *pY - nDiffX;
        }
    }

    return 0;
}

// 0x005D9C80
static int __stdcall sub_005D9C80_StartMonsterLeapAttack(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    if (!pTarget || !pSkill)
    {
        return 0;
    }

    sub_6FC627B0(pUnit, 4);
    sub_6FC62D90(pUnit, pGame);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
    SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    return 1;
}

// 0x005D9CE0
static int __stdcall sub_005D9CE0_CheckLeapRoom(D2UnitStrc* pUnit, int nX, int nY, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    return 1;
}

// 0x005D9D50
int __fastcall SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    const int bIsMonster = nUnitType == 1;

    int nX;
    int nY;
    D2CoordStrc coords;

    if (bIsMonster)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
            {
                UNITS_SetUsedSkill(pUnit, 0);
                return 0;
            }

            SKILLS_SetParam4(pSkill, -1);
        }
        else
        {
            sub_005D9C80_StartMonsterLeapAttack(pGame, pTarget, pSkill, pUnit);
            if (SUNIT_IsDead(pUnit))
            {
                return 0;
            }

            nX = UNITS_GetXPosition(pTarget);
            nY = CLIENTS_GetUnitY(pTarget);
            nX = 2 * nX - UNITS_GetXPosition(pUnit);
            nY = 2 * nY - CLIENTS_GetUnitY(pUnit);
        }

        coords.nX = nX;
        coords.nY = nY;
        if (!COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &coords, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            return 0;
        }

        nX = coords.nX;
        nY = coords.nY;
    }
    else
    {
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }

        if (!sub_005D9CE0_CheckLeapRoom(pUnit, nX, nY, nSkillId))
        {
            return 0;
        }

        if (!sub_005D9A10_FindLeapTargetPosition(pUnit, nSkillLevel, &nX, &nY, nSkillId))
        {
            return 0;
        }
    }

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
    sub_6FCBDE90(pUnit, 1);
    STATES_ToggleState(pUnit, 0x12, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);

    if (bIsMonster)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }

    SKILLS_SetFlags(pSkill, 0x80);
    return 1;
}
