#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2Skills.h"

struct D2UnitStrc;

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2InventoryStrc;

struct D2SkillsTxt;

struct D2SkillCalcStrc;

struct D2CoordStrc;

struct D2StaticPathStrc;

struct D2SkillListStrc;

typedef int BOOL;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszSkillsSourceFile[]; // 0x006DAB88

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400

int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0063A510

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit); // 0x00644150

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

static __declspec(noinline) int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
};

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __fastcall sub_00646BE0(int nParamId, void* pUserData); // 0x00646BE0

int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage); // 0x00644B70

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

static int __stdcall sub_00645C60_IsOutsideTown(int nX, int nY, D2UnitStrc* pUnit); // 0x00645C60

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110

void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60

D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625E60

struct D2ItemsTxt;

struct D2MissilesTxt;

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __stdcall D2Common_11034(int nSkillLevel, int nSkillId); // 0x00645B70

int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nLevel); // 0x004CC7C0

int __stdcall D2Common_11035(int nSkillLevel, int nSkillId); // 0x00645BC0

int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0

int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId); // 0x00645C10

int __fastcall sub_00643580_GetSkillParam7Formula(int nSkillId, int nSkillLevel); // 0x00643580

int __stdcall D2Common_11033(int nLevel, int nParam1, int nParam2); // 0x00645B20

int __fastcall sub_004C9460_GetSkillParam1(int nSkillId); // 0x004C9460

int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId); // 0x004EFC20

int __fastcall sub_004EFC50_GetSkillParam3(int nSkillId); // 0x004EFC50

int __fastcall sub_004EFC80_FourthSkillParam(int nSkillId); // 0x004EFC80

int __fastcall sub_004E6C70(int nSkillId); // 0x004E6C70

int __fastcall sub_004F4110_GetSkillParam5(int nSkillId); // 0x004F4110

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644D50

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644E40

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644F20

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

int __stdcall D2Common_11032(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nType); // 0x00647E00

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId);

// 0x00644180
static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill || !pSkill->pSkillsTxt)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;

    int nSkillId = pSkillsTxtRecord->nSkillId;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    int nSkillLevel = pSkill->nLevelBonus;
    nSkillLevel += SKILLS_GetShrineSkillLevelBonus(pUnit);
    nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 127, 0);

    if (pUnit && pUnit->dwUnitType == 0)
    {
        const int nClassId = pUnit->dwClassId;
        if (pSkillsTxtRecord->nCharClass == nClassId)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 83, nClassId);

            D2SkillDescTxt* pSkillDescTxtRecord = sub_004A89D0(nSkillId);
            if (pSkillDescTxtRecord->nSkillPage)
            {
                const int nTab = (!pUnit ? -1 : pUnit->dwClassId) * 8 + pSkillDescTxtRecord->nSkillPage - 1;
                nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 188, nTab);
            }

            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus > 3)
            {
                nBonus = 3;
            }
            nSkillLevel += nBonus;
        }
        else
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
    }
    else
    {
        if (pSkill->nSkillLevel <= 0)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
        else
        {
            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus)
            {
                if (nBonus > 3)
                {
                    nBonus = 3;
                }
                nSkillLevel += nBonus;
            }
        }
    }

    const unsigned char nEType = pSkillsTxtRecord->nEType;
    if (nEType > 0)
    {
        nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 126, nEType);
    }

    return nSkillLevel + STATLIST_UnitGetStatValue(pUnit, 107, nSkillId);
}

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus)
{
    int nSkillLevel = 0;
    int nMaxLevel = 0;

    if (pUnit && pSkill)
    {
        nSkillLevel = pSkill->nSkillLevel;
        if (bBonus && pSkill->nOwnerGUID == -1)
        {
            nSkillLevel += SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }

        nSkillLevel = D2_MAX(nSkillLevel, 0);
        return D2_MIN(nSkillLevel, DATATBLS_GetMaxLevel(0));
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

__forceinline int SKILLS_EvaluateSkillFormulaInl(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    D2SkillCalcStrc pSkillCalc;

    if (!sgptDataTables->pSkillsCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nSkillsCodeSize)
    {
        return 0;
    }

    pSkillCalc.pUnit = pUnit;
    pSkillCalc.nSkillId = nSkillId;
    pSkillCalc.nSkillLevel = nSkillLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pSkillsCode[nCalc], sgptDataTables->nSkillsCodeSize - nCalc, sub_00646BE0, gpSkillsCalcFunctions, gnSkillsCalcFunctions, &pSkillCalc);
}

// 0x00644C90
static int __fastcall SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
    int nPercentage = 0;

    switch (nElemType)
    {
    case 1:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 329, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 2:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 330, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 4:
    case 12:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 331, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 5:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, 332, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    default:
        break;
    }

    return 0;
}

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        int nDamage = (pSkillsTxtRecord->dwEMin + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwEMinLev)) << pSkillsTxtRecord->nToHitShift;

        if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1 && (nDamage > 256 || pSkillsTxtRecord->dwEMinLev[0]))
        {
            int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

            if (nBonus)
            {
                nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
            }
        }

        if (a4 && pUnit)
        {
            nDamage += SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
        }

        return nDamage;
    }
}

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        int nDamage = (pSkillsTxtRecord->dwEMax + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwEMaxLev)) << pSkillsTxtRecord->nToHitShift;

        if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1)
        {
            int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

            if (nBonus)
            {
                nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
            }
        }

        if (a4 && pUnit)
        {
            nDamage += SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
        }

        return nDamage;
    }
}

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_00645C60_IsOutsideTown(int nX, int nY, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(pRoom);
}

// 0x00645CA0
int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY)
{
    struct { int n; } tX2 = {}, tY2 = {};

    if (pUnit2 && UNITS_IsInMeleeRange(pUnit1, pUnit2, 0))
    {
        return 0;
    }

    const int nX1 = UNITS_GetXPositionForceInl(pUnit1);
    const int nY1 = UNITS_GetYPositionForceInl(pUnit1);

    if (pUnit2)
    {
        tX2.n = UNITS_GetXPositionForceInl(pUnit2);
        tY2.n = UNITS_GetYPositionForceInl(pUnit2);
    }
    else
    {
        tX2.n = D2COMMON_10175_PathGetFirstPointX(pUnit1->pDynamicPath);
        tY2.n = D2COMMON_10176_PathGetFirstPointY(pUnit1->pDynamicPath);
    }

    const int nDivisor = sub_006417F0_GetDistanceToXY(pUnit1, tX2.n, tY2.n);
    if (!nDivisor)
    {
        return 0;
    }

    int nX = tX2.n + 2 * (tX2.n - nX1) / nDivisor;
    int nY = tY2.n + 2 * (tY2.n - nY1) / nDivisor;

    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit1);
    D2_ASSERT(hRoom, 4286);

    const int nPattern = PATH_GetUnitCollisionPattern(pUnit1);
    if (COLLISION_CheckAnyCollisionWithPattern(hRoom, nX, nY, nPattern, COLLIDE_MASK_PLAYER_PATH))
    {
        D2CoordStrc tCoord;
        tCoord.nX = tX2.n;
        tCoord.nY = tY2.n;
        hRoom = COLLISION_GetFreeCoordinates(hRoom, &tCoord, UNITS_GetUnitSizeX(pUnit1), COLLIDE_MASK_PLAYER_PATH, 0);
        if (!hRoom)
        {
            return 0;
        }
        nX = tCoord.nX;
        nY = tCoord.nY;
    }

    if (!sub_00645910_TestLine(UNITS_GetXPositionForceInl(pUnit1), UNITS_GetYPositionForceInl(pUnit1), nX, nY, hRoom, COLLIDE_MASK_LINE))
    {
        return 0;
    }

    *pX = nX;
    *pY = nY;
    return sub_00645C60_IsOutsideTown(nX, nY, pUnit1) != 0;
}

// 0x00646280
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent)
{
    if (!pUnit)
    {
        return;
    }

    const int nKickDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x89, 0);
    *pMinDamage += nKickDamage;
    *pMaxDamage += nKickDamage;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    int nValue;
    D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(pInventory);
    D2UnitStrc* pOtherHand = 0;
    if (pLeftHand)
    {
        nValue = ITEMS_GetBodyLocation(pLeftHand);
        pOtherHand = INVENTORY_GetItemFromBodyLoc(pInventory, (nValue == 4) + 4);
    }

    if (ITEMSIsA(pLeftHand, 0x2D) && ITEMS_CanBeEquipped(pLeftHand) && STATLIST_GetOwner(pLeftHand, 0))
    {
        STATLIST_MergeStatLists(pUnit, pLeftHand, 0);
    }
    else
    {
        pLeftHand = 0;
    }

    if (pOtherHand && pOtherHand != pLeftHand && ITEMSIsA(pOtherHand, 0x2D) && ITEMS_CanBeEquipped(pOtherHand) && STATLIST_GetOwner(pOtherHand, 0))
    {
        STATLIST_MergeStatLists(pUnit, pOtherHand, 0);
    }

    D2UnitStrc* pBoots = INVENTORY_GetItemFromBodyLoc(pInventory, 9);
    if (pBoots && pBoots->dwUnitType == 4)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pBoots ? -1 : pBoots->dwClassId);
        if (pItemsTxtRecord)
        {
            int nMin = nKickDamage + pItemsTxtRecord->nMinDam;
            int nMax = nKickDamage + pItemsTxtRecord->nMaxDam;
            int nBonus = 0;
            nValue = ITEMS_GetStrengthBonus(pBoots);
            if (nValue)
            {
                nBonus = DATATBLS_ApplyRatio(STATLIST_UnitGetStatValue(pUnit, 0, 0), nValue, 100);
            }

            nValue = ITEMS_GetDexBonus(pBoots);
            if (nValue)
            {
                nBonus += DATATBLS_ApplyRatio(STATLIST_UnitGetStatValue(pUnit, 2, 0), nValue, 100);
            }

            nBonus += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
            if (nBonus <= -90)
            {
                nBonus = -90;
            }

            const int nPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
            if (nMin >= nMax)
            {
                nMax = nMin;
            }

            *pDamagePercent += nPercent + nBonus;
            *pMinDamage += nMin;
            *pMaxDamage += nMax;
        }
    }

    if (pLeftHand)
    {
        STATLIST_MergeStatLists(pUnit, pLeftHand, 1);
    }
}

// 0x00646460
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    int nIndex;
    int nMissileId;
    int nResult;
    const int nParam = (unsigned char)nParamId;
    switch (nParam)
    {
    case 0:
        nResult = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
        break;
    case 1:
        nResult = D2Common_11034(nSkillLevel, nSkillId);
        break;
    case 2:
        nResult = sub_004CC7C0_GetSkillMissileRange(nSkillId, nSkillLevel);
        break;
    case 3:
        nResult = D2Common_11035(nSkillLevel, nSkillId);
        break;
    case 4:
        nResult = sub_004EFCB0_GetSummonLevel(nSkillId, nSkillLevel);
        break;
    case 5:
        nResult = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nSkillId);
        break;
    case 6:
        nResult = sub_00643580_GetSkillParam7Formula(nSkillId, nSkillLevel);
        break;
    case 7:
        nResult = D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[6], pSkillsTxtRecord->dwParam[7]);
        break;
    case 8:
        nResult = sub_004C9460_GetSkillParam1(nSkillId);
        break;
    case 9:
        nResult = sub_004EFC20_GetSkillParam2(nSkillId);
        break;
    case 10:
        nResult = sub_004EFC50_GetSkillParam3(nSkillId);
        break;
    case 11:
        nResult = sub_004EFC80_FourthSkillParam(nSkillId);
        break;
    case 12:
        nResult = sub_004E6C70(nSkillId);
        break;
    case 13:
        nResult = sub_004F4110_GetSkillParam5(nSkillId);
        break;
    case 14:
        nResult = pSkillsTxtRecord->dwParam[6];
        break;
    case 15:
        nResult = pSkillsTxtRecord->dwParam[7];
        break;
    case 16:
        nResult = nSkillLevel;
        break;
    case 17:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
        break;
    case 18:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
        break;
    case 19:
        nResult = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 20:
        nResult = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
        break;
    case 21:
        if (nSkillLevel > 0)
        {
            nResult = ((pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift) >> 8;
            break;
        }
        nResult = 0;
        break;
    case 22:
        if (nSkillLevel > 0)
        {
            nResult = ((25 * (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) / 2) << pSkillsTxtRecord->nManaShift) >> 8;
            break;
        }
        nResult = 0;
        break;
    case 23:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 24:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 25:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 2);
        break;
    case 26:
    case 29:
    case 32:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 26) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
                break;
            }
        }
        nResult = 0;
        break;
    case 27:
    case 30:
    case 33:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 27) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
                break;
            }
        }
        nResult = 0;
        break;
    case 28:
    case 31:
    case 34:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 28) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = sub_0064B2A0_GetMissileElementLength(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 35:
    case 36:
    case 37:
    {
        pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        if (pSkillDescTxtRecord)
        {
            D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pSkillDescTxtRecord->wDescMissile[nParam - 35]);
            if (pMissilesTxtRecord)
            {
                nResult = pMissilesTxtRecord->wRange + nSkillLevel * pMissilesTxtRecord->wLevRange;
                break;
            }
        }
        nResult = 0;
        break;
    }
    case 38:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 39:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 40:
        if (pUnit)
        {
            nResult = STATLIST_UnitGetStatValue(pUnit, 12, 0);
            break;
        }
        nResult = 0;
        break;
    case 41:
        if (pUnit)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
            if (pSkill)
            {
                nResult = SKILLS_GetSkillLevel(pUnit, pSkill, 0);
                break;
            }
        }
        nResult = 0;
        break;
    case 42:
        if (nSkillLevel > 0)
        {
            nResult = (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
            break;
        }
        nResult = 0;
        break;
    case 43:
    case 45:
    case 47:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 43) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 44:
    case 46:
    case 48:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 44) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 49:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        break;
    case 50:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        break;
    case 51:
        nResult = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 52:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 53:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 54:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
        break;
    case 55:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        break;
    case 56:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        break;
    case 57:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        break;
    case 58:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
        break;
    case 59:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        break;
    case 60:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], nSkillId, nSkillLevel);
        break;
    case 61:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
        break;
    case 62:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[2], nSkillId, nSkillLevel);
        break;
    case 63:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[3], nSkillId, nSkillLevel);
        break;
    case 64:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[4], nSkillId, nSkillLevel);
        break;
    case 65:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[5], nSkillId, nSkillLevel);
        break;
    case 66:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[0], nSkillId, nSkillLevel);
        break;
    case 67:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);
        break;
    case 68:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[2], nSkillId, nSkillLevel);
        break;
    case 69:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[3], nSkillId, nSkillLevel);
        break;
    case 70:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[4], nSkillId, nSkillLevel);
        break;
    case 71:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
        break;
    case 72:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);
        break;
    default:
        nResult = 0;
        break;
    }

    return nResult;
}

inline void* UNITS_GetMemoryPool(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pMemoryPool;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x00643810
static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit->pSkills)
    {
        return 0;
    }

    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    D2SkillStrc* pHighestLevelSkill = 0;
    for (; pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && !pSkill->bExcludeFromHighestLevelLookup && (!pHighestLevelSkill
            || pSkill->nOwnerGUID == -1 || pHighestLevelSkill->nOwnerGUID != -1 && pSkill->nSkillLevel > pHighestLevelSkill->nSkillLevel))
        {
            pHighestLevelSkill = pSkill;
        }
    }

    return pHighestLevelSkill;
}

static D2StatListStrc* __stdcall sub_00643620(D2UnitStrc* pUnit, int nState, int nSkillLevel)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);

    if (nSkillLevel)
    {
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(UNITS_GetMemoryPool(pUnit), 0, 0, sub_0044BE50(pUnit), UNITS_GetUnitId(pUnit));
            STATLIST_SetState(pStatList, nState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        return pStatList;
    }

    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    return 0;
}

// 0x00646D60
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    short nPassiveState = pSkillsTxtRecord->nPassiveState;
    if (nPassiveState <= 0 || nPassiveState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
    if (!pSkill)
    {
        D2StatListStrc* pOldStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nPassiveState);
        if (pOldStatList)
        {
            D2Common_10474(pUnit, pOldStatList);
            STATLIST_FreeStatList(pOldStatList);
        }
        return;
    }

    if (pSkillsTxtRecord->nAuraState > 0 && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        int const tArg3 = pSkillsTxtRecord->nPassiveState;
        D2StatListStrc* pOldStatList = STATLIST_GetStatListFromUnitAndState(pUnit, tArg3);
        if (pOldStatList)
        {
            D2Common_10474(pUnit, pOldStatList);
            STATLIST_FreeStatList(pOldStatList);
        }
        return;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    D2StatListStrc* pStatList = sub_00643620(pUnit, pSkillsTxtRecord->nPassiveState, nSkillLevel);
    if (!pStatList || STATLIST_GetStatValue(pStatList, 351, 0) == nSkillLevel)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxtRecord->nPassiveStat[i] < 0 || pSkillsTxtRecord->nPassiveStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            break;
        }

        int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nPassiveIType <= 0)
        {
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, 0);
        }
        else
        {
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, pSkillsTxtRecord->nPassiveIType);
        }
    }

    STATLIST_SetStat(pStatList, 350, nSkillId, 0);
    STATLIST_SetStat(pStatList, 351, nSkillLevel, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nPassiveState, 1);
}

// build: context SKILLS_GetSkillInl
static __forceinline D2SkillStrc* SKILLS_GetSkillInl(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillStrc* pSkill;
    if (pUnit->pSkills)
    {
        for (pSkill = pUnit->pSkills->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
        {
            if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            {
                goto found;
            }
        }
    }

    pSkill = 0;
found:
    return pSkill;
}

// 0x00647B20
void __stdcall D2Common_11031(D2UnitStrc* pUnit, int nSkillId, int a3)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillInl(pUnit, nSkillId, -1);

    if (!pSkill)
    {
        if (a3 <= 0)
        {
            return;
        }

        pSkill = SKILLS_AddSkill(pUnit, nSkillId);
        if (!pSkill)
        {
            return;
        }

        D2SkillStrc* pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (!pAssigned)
        {
            SKILLS_AddSkill(pUnit, nSkillId);
            pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
        }

        if (pAssigned)
        {
            pAssigned->nSkillLevel = 0;
            SKILLS_RefreshSkill(pUnit, nSkillId);
        }
    }

    if (pSkill->nOwnerGUID == -1)
    {
        pSkill->nLevelBonus += a3;
        if (pSkill->nLevelBonus < 0)
        {
            pSkill->nLevelBonus = 0;
        }
    }
}

static int __stdcall sub_00644C20(D2UnitStrc* pUnit, int bMin)
{
    int nDamage;

    if (pUnit && pUnit->dwUnitType == 0)
    {
        nDamage = STATLIST_UnitGetStatValue(pUnit, 2, 0) + STATLIST_UnitGetStatValue(pUnit, 0, 0) - 20;
    }
    else
    {
        nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
    }

    if (nDamage < 1)
    {
        nDamage = 1;
    }

    if (bMin)
    {
        return nDamage / 4 << 8;
    }

    return nDamage / 3 << 8;
}

// @ref 0x00647BC0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
        {
            return sub_00644C20(pUnit, 1);
        }
        else
        {
            int nDamage = 0;
            if (pSkillsTxtRecord->nSrcDam && a4)
            {
                D2UnitStrc* pItem = D2Common_10434(pUnit, 0);
                int nWeaponDamage = 0;
                if (pItem && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
                {
                    nWeaponDamage = STATLIST_GetMinDamageFromUnit(pItem, 1);
                }
                else
                {
                    nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, 21, 0);
                }
                nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
            }

            nDamage += pSkillsTxtRecord->dwMinDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMinLvlDam);

            if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
            {
                int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

                if (nBonus)
                {
                    nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
                }
            }

            return nDamage << pSkillsTxtRecord->nToHitShift;
        }
    }
}

// 0x00647D00
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    int nDamage = 0;
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
        {
            return sub_00644C20(pUnit, nDamage);
        }
        else
        {
            D2UnitStrc* const pSource = pUnit;
            if (pSkillsTxtRecord->nSrcDam && a4)
            {
                D2UnitStrc* pItem = D2Common_10434(pSource, 0);
                int nWeaponDamage = 0;
                if (pItem)
                {
                    if (INVENTORY_GetWieldType(pSource, pSource->pInventory) == 2)
                    {
                        nWeaponDamage = STATLIST_GetMaxDamageFromUnit(pItem, 24);
                    }
                    else
                    {
                        nWeaponDamage = STATLIST_UnitGetStatValue(pSource, 22, 0);
                    }
                }
                else
                {
                    nWeaponDamage = STATLIST_UnitGetStatValue(pSource, 22, 0);
                }
                nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
            }

            nDamage += pSkillsTxtRecord->dwMaxDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMaxLvlDam);

            if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
            {
                int nBonus = SKILLS_EvaluateSkillFormula(pSource, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

                if (nBonus)
                {
                    nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
                }
            }

            return nDamage << pSkillsTxtRecord->nToHitShift;
        }
    }
}
