#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2Txt.h"
#include "D2DataTbls.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2GameTypes.h"

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC

extern "C" const char gszFmtRange[];                                                                // 0x006D9D70

extern int gnScreenHeight;                                                                               // 0x00711470

extern int gnPanelOffsetX;                                                                               // 0x007A2858

extern int gnPanelOffsetY;                                                                               // 0x007A285C

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644D50

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644E40

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                     // 0x0062A4E0

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem);                                          // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem);                                         // 0x006298A0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __fastcall SKILLDESC_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004E9610

int __fastcall SKILLDESC_ThrowDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004EA4A0

void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA010

struct Unicode;

struct D2SkillsTxt;

struct D2SkillDescTxt;

struct D2UnitStrc;

struct D2DataTablesStrc;

extern "C" const char gszFmtRangeKK[]; // 0x006DBEAC

extern "C" const char gszFmtRangeK[]; // 0x006DBEB8

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __cdecl SKILLDESC_SumProgressiveBonus(); // 0x004E6FF0

int __stdcall SKILLDESC_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor); // 0x004E7120

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

static void __stdcall SKILLDESC_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight); // 0x004E96E0

extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304

int __fastcall GAME_GetUnitClassId(D2UnitStrc*); // 0x00451F60

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

int __stdcall SKILLDESC_AddElemRange(int nMin, unsigned short nString, int nMax, Unicode* wszText, int nElemType); // 0x004EC140

static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel); // 0x004EC220

static void __stdcall SKILLDESC_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage);

void __fastcall SKILLDESC_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

int gbHasClassSkill; // 0x007C8CA0

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
#include "D2Client.h"

extern "C" __declspec(dllimport)
int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId);                          // 0x00626070

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit);                                        // 0x0063A380

int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A3A0

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0

void __stdcall sub_004E72D0_GetElemDamage(D2UnitStrc*, int*, int*, int*, D2SkillsTxt*, int); // 0x004E72D0

static int __stdcall sub_004E86F0_GetWeaponDamage(int*, int*, int*, int, D2SkillStrc*, int, D2UnitStrc*, int, D2UnitStrc*, int); // 0x004E86F0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

extern const D2ElemDamageStatsStrc gaElemDamageStats[4];                                          // 0x006DBEF4

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillTextPositionStrc { int nLeft, nY, nRight; };

typedef void (__fastcall* SKILLDAMAGEFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int, int, int);

typedef void (__fastcall* SKILLDESCFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int*, int*, int*, int*);

extern SKILLDAMAGEFN gpfnSkillDamageFuncs[]; // 0x0072D768

extern SKILLDESCFN gpfnSkillDescFuncs[]; // 0x0072D7F8

extern D2SkillTextPositionStrc gaSkillTextPositions[]; // 0x0072D840

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
extern "C" const char gszFormatD[]; // 0x006D57BC

extern const char gszSkillDescFile_006DBF24[]; // 0x006DBF24

void __fastcall GAME_StrToUpper(Unicode*); // 0x00452180

int __fastcall TEXT_SplitAtNewline(Unicode*, Unicode**); // 0x004A7660

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc*, D2SkillStrc*); // 0x004D9FC0

Unicode* __fastcall sub_005267E0(Unicode*, const Unicode*); // 0x005267E0

void __cdecl sub_005269D0(int, Unicode*, const Unicode*, ...); // 0x005269D0

static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue); // 0x004E9940

#define TP gaSkillTextPositions

#define DRAW_SKILL_TEXT(i, text) TEXT_DrawCenteredText(TP[i].nLeft + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + TP[i].nY - 480, TP[i].nRight + gnPanelOffsetX, text, 0)

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void* __fastcall MISSILE_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern const unsigned char gbSkillFlagMask_006CE270; // 0x006CE270

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

extern int gnChargedBoltTurnEvery; // 0x0072D98C

extern int gnChargedBoltTurnBase; // 0x0072D990

extern const int gaCurvingPathOffsetY[]; // 0x006DC1E8

extern const int gaCurvingPathOffsetX[]; // 0x006DC208

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pPath, int nPoints); // 0x00648790

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nFrame); // 0x0064A330

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

int __stdcall sub_004EC280_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel); // 0x004EC280

static inline int sub_I05_ETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

static void __stdcall sub_004E72D0_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        *pType = 2;
        nMin = nLength * SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pType)
    {
        const int nColor = sub_I05_ETypeColor(pSkillsTxt->nEType);
        if (nColor)
        {
            *pType = nColor;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

// build: symbol ?SKILLDESC_MergeOtherHandWeapon@* 0x004E9260
static D2UnitStrc* SKILLDESC_MergeOtherHandWeapon(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (!pOther || pOther == pWeapon)
        return 0;

    if (!ITEMSIsA(pOther, 45))
        return 0;

    if (!ITEMS_CanBeEquipped(pWeapon) || !ITEMS_CanBeEquipped(pOther))
        return 0;

    if (STATLIST_GetOwner(pWeapon, 0))
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
    if (STATLIST_GetOwner(pOther, 0))
        STATLIST_MergeStatLists(pUnit, pOther, 1);
    return pOther;
}

static D2UnitStrc* sub_004E9300_MergeWeaponPair(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (pOther && pOther != pWeapon)
    {
        if (ITEMSIsA(pOther, 45))
        {
            if (ITEMS_CanBeEquipped(pWeapon) && ITEMS_CanBeEquipped(pOther))
            {
                STATLIST_MergeStatLists(pUnit, pOther, 0);
                STATLIST_MergeStatLists(pUnit, pWeapon, 1);
                return pWeapon;
            }
        }
    }

    if (ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    return pWeapon;
}

// build: symbol ?SKILLDESC_EvaluateForEachWeapon@* 0x004E93A0
static int __stdcall SKILLDESC_EvaluateForEachWeapon(int* pValue1, int* pValue2, int* pColor1, int* pValue3, int* pValue4, int* pColor2, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nBonus, D2UnitStrc* pUnit, int nAdd)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (!ITEMS_CanBeEquipped(pRight) || ITEMSIsA(pRight, 0x26))
        pRight = 0;

    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!ITEMS_CanBeEquipped(pLeft) || ITEMSIsA(pLeft, 0x26))
        pLeft = 0;

    if (pRight && pLeft)
    {
        D2UnitStrc* pItem = SKILLDESC_MergeOtherHandWeapon(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue3, pValue4, pColor2, nBonus, nAdd, pSkill, 0, pItem);
        }
        else
        {
            *pValue3 = 0;
            *pValue4 = 0;
        }

        pItem = sub_004E9300_MergeWeaponPair(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue1, pValue2, pColor1, nBonus, nAdd, pSkill, 0, pItem);
        }
        else
        {
            *pValue1 = 0;
            *pValue2 = 0;
        }
        return 1;
    }

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pWeapon && ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    pfnEvaluate(pUnit, pValue1, pValue2, pColor1, nBonus, nAdd, pSkill, 0, 0);
    return 1;
}

// build: symbol ?SKILLDESC_AddElementalStatDamage@* 0x004E8D90
static void SKILLDESC_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType)
{
    switch (nType)
    {
    case 1:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMAXDAM, 0);
        break;
    case 2:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMAXDAM, 0);
        break;
    case 4:
    case 12:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMAXDAM, 0);
        break;
    case 3:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMAXDAM, 0);
        break;
    case 5:
    {
        int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (nCount <= 1)
                nCount = 1;
            nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
        }
        int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
        *pMinDamage += nMin * nLength >> 8;
        *pMaxDamage += nMax * nLength >> 8;
        break;
    }
    }
}

// 0x004E96E0
static void __stdcall SKILLDESC_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight)
{
    if (nMin >= nMax)
    {
        nMax = nMin + 1;
    }

    Unicode wszText[32];
    char szText[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText, szText, 32);
    int nWidth = 0;
    int nHeight = 0;
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    nWidth = nWidth * 11 / 7;
    if (nWidth > nRight - nLeft)
    {
        D2Win_10127_SetFont(6);
        --nY;
    }
    else
    {
        D2Win_10127_SetFont(1);
    }
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText, nColor);
}

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nCalcA, int nCalcB, int nLine, unsigned short nStringA, short nMissileId)
{
    switch (nLine)
    {
    case 2:
        SKILLDESC_AddElemRange(nCalcA, nStringA, nCalcB, wszText, pSkillsTxt->nEType);
        return 1;
    case 3:
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        return 1;
    case 4:
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 5:
        sub_004EC280_AddMissileElemDamage(pUnit, wszText, nStringA, nMissileId, nSkillLevel);
        return 1;
    }
    return 0;
}

// build: symbol ?SKILLDESC_ApplyFireMasteryBonus@* 0x004E6EA0
static void __stdcall SKILLDESC_ApplyFireMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// build: symbol ?SKILLDESC_ApplyLightningMasteryBonus@* 0x004E6F00
static void __stdcall SKILLDESC_ApplyLightningMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004E99F0
static void __stdcall SKILLDESC_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage)
{
    if (!pSkill || !pSkillsTxt || !pfnEvaluate)
    {
        return;
    }

    int nElemMin = 0;
    int nElemMax = 0;
    int nColor1 = 0;
    int nColor2 = 0;
    if (bElemDamage)
    {
        sub_004E72D0_GetElemDamage(pUnit, &nElemMin, &nElemMax, &nColor1, pSkillsTxt, nSkillLevel);
    }
    nColor2 = nColor1;

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nMin1 = 0;
    int nMax1 = 0;
    int nMin2 = 0;
    int nMax2 = 0;
    SKILLDESC_EvaluateForEachWeapon(&nMin1, &nMax1, &nColor1, &nMin2, &nMax2, &nColor2, pSkill, pfnEvaluate, nBonus, pUnit, nAdd);
    if (nMin1 && nMax1)
    {
        nMin1 = nMin1 * nSrcDam / 128 + nElemMin;
        nMax1 = nMax1 * nSrcDam / 128 + nElemMax;
    }
    if (nMin2 && nMax2)
    {
        nMin2 = nMin2 * nSrcDam / 128 + nElemMin;
        nMax2 = nMax2 * nSrcDam / 128 + nElemMax;
    }

    if (!nMin1 && !nMax1)
    {
        SKILLDESC_DrawDamageRange(nColor2, nY, nMin2, nMax2, nLeft, nRight);
        return;
    }

    if (!nMin2 && !nMax2)
    {
        SKILLDESC_DrawDamageRange(nColor1, nY, nMin1, nMax1, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
    char szText[32];
    if (nMin1 == nMax1)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin1);
    }
    else if (nMin1 < 10000 && nMax1 < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin1, nMax1);
    }
    else if (nMin1 >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin1 + 500) / 1000, (nMax1 + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin1, (nMax1 + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nMin2 == nMax2)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin2);
    }
    else if (nMin2 < 10000 && nMax2 < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin2, nMax2);
    }
    else if (nMin2 >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin2 + 500) / 1000, (nMax2 + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin2, (nMax2 + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor1, nColor2);
}

// 0x004EA170
void __fastcall SKILLDESC_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
// build: symbol ?gszSkillDescFile@* 0x006DBF24
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9B8), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9B9), nSkillLevel);
        SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 1);
        return;
    }

    SKILLDESC_DrawSkillWeaponLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

// 0x004EA240
void __fastcall SKILLDESC_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9DD), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9DE), nSkillLevel);
        SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 0);
        return;
    }

    SKILLDESC_DrawSkillWeaponLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

// 0x004EAA30
void __fastcall SKILLDESC_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    D2UnitStrc* pItem = SKILLDESC_MergeOtherHandWeapon(pUnit);
    if (!pItem)
    {
        return;
    }

    SKILLDESC_ThrowDamageCallback(pUnit, &nMin, &nMax, &nColor, 0, 0, pSkill, 0, pItem);
    sub_004E9300_MergeWeaponPair(pUnit);
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EB240
void __fastcall SKILLDESC_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], pSkillsTxt->nSkillId, nSkillLevel);
    SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_ThrowDamageCallback, nBonus, 0, nLeft, nY, nRight, 1);
}

// 0x004EC220
static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(nMin >> 8, nString, nMax >> 8, wszText, pSkillsTxt->nEType);
}

// build: context ApplyRatio_Inline
// build: context AddPoisonDamage_Inline
// build: context AddPoisonDamageAndClamp_Inline

void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98C), nSkillLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98D), nSkillLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    if (pSkillsTxt->nSrcDam != 0x80)
    {
        const int nSrcDam = pSkillsTxt->nSrcDam;
        nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
        nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    }

    nMin += SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EBA30
void __fastcall SKILLDESC_DrawKickDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nColor = 0;
    const int nSkillId = pSkillsTxt->nSkillId;
    const int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    const int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    int nBonus = SKILLDESC_SumProgressiveBonus();
    nBonus += SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel);
    if (nBonus)
    {
        nColor = 3;
    }

    int nKickMin = 0;
    int nKickMax = 0;
    int nPercent = nBonus;
    SKILLS_CalculateKickDamage(pUnit, &nKickMin, &nKickMax, &nPercent);
    nKickMin += nMin + DATATBLS_ApplyRatio(nKickMin, nPercent, 100) + DATATBLS_ApplyRatio(nMin, nBonus, 100);
    nKickMax += nMax + DATATBLS_ApplyRatio(nKickMax, nPercent, 100) + DATATBLS_ApplyRatio(nMax, nBonus, 100);

    {
        int nElemMin = 0;
        int nElemMax = 0;
        SKILLDESC_AddProgressiveDamage(pUnit, &nElemMin, &nElemMax, &nColor);
        nKickMin += nElemMin;
        nKickMax += nElemMax;
    }
    SKILLDESC_DrawDamageRange(nColor, nY, nKickMin, nKickMax, nLeft, nRight);
}

// 0x004EA310
void __fastcall SKILLDESC_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA02), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA03), nSkillLevel);
        SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 1);
    }
    else
    {
        int nMin = 0;
        int nMax = 0;
        int nColor = 0;
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA0C), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA0D), nSkillLevel);
        SKILLDESC_WeaponDamageCallback(pUnit, &nMin, &nMax, &nColor, nBonus, nAdd, pSkill, 0, 0);
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
    }
}

// build: symbol ?SKILLDESC_GetETypeColor@* 0x004E6FB0
static int SKILLDESC_GetETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

// build: symbol ?SKILLDESC_AddScaledWeaponDamage@* 0x004E9660
static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill, D2UnitStrc* pItem, int nRatio)
{
    if (!nRatio)
        return;

    int nMin = 0;
    int nMax = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, pColor, 0, pSkill, 128, pItem, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, pColor, pSkill);
    *pMinDamage += nMin * nRatio / 128;
    *pMaxDamage += nMax * nRatio / 128;
}

void __fastcall SKILLDESC_DrawWeaponAndSkillDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nWeaponMin = 0;
    int nWeaponMax = 0;
    int nWeaponColor = 0;
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nWeaponMin, &nWeaponMax, &nWeaponColor, pSkill, 0, pSkillsTxt->nSrcDam);
    const int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    SKILLDESC_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);

    if (!nWeaponMin && !nWeaponMax)
    {
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nWeaponColor, nY, nWeaponMin, nWeaponMax, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

int __stdcall SKILLDESC_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor)
{
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
            if (pStatList)
            {
                int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
                    if (pSkillsTxt)
                    {
                        int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
                        if (nSkillLevel > 0)
                        {
                            short nStatId = pSkillsTxt->wAuraStat[0];
                            if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
                            {
                                int nCharges = STATLIST_GetStatValue(pStatList, nStatId, 0);
                                if (nCharges > 0)
                                {
                                    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
                                    if (!pSkillDescTxt)
                                    {
                                        *pMinDamage += SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
                                        *pMaxDamage += SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
                                    }
                                    else
                                    {
                                        const int nIndex = D2_MIN(D2_MAX(nCharges, 1), 3);

                                        *pMinDamage += SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMin[nIndex - 1], nSkillId, nSkillLevel);
                                        *pMaxDamage += SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMax[nIndex - 1], nSkillId, nSkillLevel);
                                        const unsigned char* pElem = pSkillDescTxt->nPrgDamElem;
                                        if (pElem[nIndex - 1] > 0 && pElem[nIndex - 1] < 13)
                                            *pColor = sub_I05_ETypeColor(pElem[nIndex - 1]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

// build: context ApplyRatio_Inline
// build: context AddPoisonDamage_Inline
// build: context AddPoisonDamageAndClamp_Inline

// 0x004EB640
void __fastcall SKILLDESC_DrawMasteryWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    int nWeaponMin;
    int nWeaponMax;
    int nMin;
    int nMax;
    int nColor;

    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    nMin = 0;
    nMax = 0;
    nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, pSkillsTxt->nSrcDam);

    if (D2Common_10434(pUnit, 1))
    {
        if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
        {
            nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
            nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
        }
        else
        {
            nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
            nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
        }
    }
    else
    {
        nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
        nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    }

    if (nWeaponMin <= 1)
    {
        nWeaponMin = 1;
    }
    if (nWeaponMax <= 2)
    {
        nWeaponMax = 2;
    }
    if (nWeaponMax < nWeaponMin)
        {
            nWeaponMax = nWeaponMin;
        }

    const int nSkillId = pSkillsTxt->nSkillId;
    int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[2], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    if (!nColor)
    {
        nColor = 3;
    }
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EBD50
void __fastcall SKILLDESC_DrawDescWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], nSkillId, nSkillLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], nSkillId, nSkillLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);

    int nElemMin = 0;
    int nElemMax = 0;
    int nElemColor = 0;
    sub_004E72D0_GetElemDamage(pUnit, &nElemMin, &nElemMax, &nElemColor, pSkillsTxt, nSkillLevel);

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nElemColor, nY, nElemMin, nElemMax, nLeft, nRight);
        return;
    }

    if (!nElemMin && !nElemMax)
    {
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    const int nWeaponMin = nMin;
    const int nWeaponMax = nMax;

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nElemMin == nElemMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nElemMin);
    }
    else if (nElemMin < 10000 && nElemMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nElemMin, nElemMax);
    }
    else if (nElemMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nElemMin + 500) / 1000, (nElemMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nElemMin, (nElemMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor, nElemColor);
}

// build: context sub_I05_GetSkillsTxtRecord
static D2SkillsTxt* sub_I05_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// build: context sub_004E86F0_GetWeaponDamage
static int __stdcall sub_004E86F0_GetWeaponDamage(int* pMinDamage, int* pMaxDamage, int* pColor, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem, int bStatBonus, D2UnitStrc* pUnit, int nBonus)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!pItem)
        pItem = INVENTORY_GetLeftHandWeapon(pInventory);

    int nMin;
    int nMax;
    if (pItem)
    {
        DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (bStatBonus)
        {
            nMin = D2Common_11248(pUnit, pItem, 0x15);
            nMax = D2Common_11248(pUnit, pItem, 0x16);
        }
        else if (INVENTORY_GetWieldType(pUnit, pInventory) != 2)
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
        }
        else
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
        }
    }
    else
    {
        nMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0) + 1;
        nMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) + 2;
    }

    if (!nSrcDam)
        nSrcDam = pSkillsTxt->nSrcDam;

    if (nSrcDam != 128)
    {
        nMin = nMin * nSrcDam / 128;
        nMax = nMax * nSrcDam / 128;
    }

    if (nSrcDam)
    {
        if (nMin < 1)
            nMin = 1;
        *pMinDamage += nMin;
        if (nMax < 2)
            nMax = 2;
        *pMaxDamage += nMax;
    }

    nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
    nBonus += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
    int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
    int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = SKILLDESC_SumProgressiveBonus();
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pColor = 3;
        }
    }

    int nDamage = 0;
    if (pItem)
    {
        int nFactor = ITEMS_GetStrengthBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFactor / 100;
        nFactor = ITEMS_GetDexBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFactor / 100;
        nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_NORMALDAMAGE, 0);
    }
    else
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
        *pColor = 3;
    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
        *pColor = 1;

    if (nBonus <= -90)
        nBonus = -90;

    *pMinDamage = (nMinPercent + nBonus + 100) * *pMinDamage / 100 + nDamage + nAdd;
    *pMaxDamage = (nMaxPercent + nBonus + 100) * *pMaxDamage / 100 + nDamage + nAdd;
    return 1;
}

static inline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

static inline void AddPoisonDamage_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
{
    int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
    if (nMax)
    {
        int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
        if (nMastery)
        {
            nMin += ApplyRatio_Inline(nMin, nMastery, 100);
            nMax += ApplyRatio_Inline(nMax, nMastery, 100);
        }

        int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (nCount <= 1)
            {
                nCount = 1;
            }
            nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
        }

        nMax = nLength * nMax >> 8;
        nMin = nLength * nMin >> 8;
        *pColor = 2;
        *pMinDamage += nMin;
        *pMaxDamage += nMax;
    }
    else
    {
    }
}

static inline void AddPoisonDamageAndClamp_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
{
    AddPoisonDamage_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (*pMaxDamage > 0)
    {
        *pMinDamage = *pMinDamage < 1 ? 1 : *pMinDamage;
        *pMaxDamage = D2_MAX(*pMinDamage + 1, *pMaxDamage);
    }
}

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill)
{
    for (int i = 0; i < 4; ++i)
    {
        int nMin = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMinStat, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMaxStat, 0);
        if (gaElemDamageStats[i].nMasteryStat != -1)
        {
            int nMastery = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMasteryStat, 0);
            if (nMastery)
            {
                nMin += ApplyRatio_Inline(nMin, nMastery, 100);
                nMax += ApplyRatio_Inline(nMax, nMastery, 100);
            }
        }

        if (nMin >= nMax)
        {
            nMin = nMax;
        }

        *pMinDamage += nMin;
        *pMaxDamage += nMax;
        if (nMin || nMax)
        {
// build: symbol ?gaElemDamageColors@* 0x006DBEE4
            *pColor = gaElemDamageColors[i];
        }
    }

    AddPoisonDamageAndClamp_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7]))
        {
            SKILLDESC_AddProgressiveDamage(pUnit, pMinDamage, pMaxDamage, pColor);
        }
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
    {
        *pColor = 1;
    }

    return 1;
}

// build: context ApplyRatio_Inline
// build: context AddPoisonDamage_Inline
// build: context AddPoisonDamageAndClamp_Inline

// 0x004EA790
void __fastcall SKILLDESC_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nColor = 0;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pItem || !sub_0062BA80_CheckItem(pItem))
    {
        return;
    }

    int nBonus = 0;
    int nFactor = ITEMS_GetStrengthBonus(pItem);
    if (nFactor)
    {
        nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFactor / 100;
    }
    nFactor = ITEMS_GetDexBonus(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFactor / 100;
    }

    int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_THROW_MINDAMAGE, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_THROW_MAXDAMAGE, 0);
    nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
    if (nBonus <= -90)
    {
        nBonus = -90;
    }
    nMin += (nMinPercent + nBonus) * nMin / 100;
    nMax += (nMaxPercent + nBonus) * nMax / 100;

    int nMastery = 0;
    if (STATES_CheckState(pUnit, STATE_THROWINGMASTERY))
    {
        nMastery = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
    }
    nMin += DATATBLS_ApplyRatio(nMin, nMastery, 100);
    nMax += DATATBLS_ApplyRatio(nMax, nMastery, 100);
    SKILLDESC_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);
    if (nMax < nMin)
    {
        nMax = nMin;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
    nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    sub_004E72D0_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

static unsigned short sub_004E6F60_GetElemDamageText(int nElemType)
{
    switch (nElemType)
    {
    case 1:
        return 0x10A1;
    case 2:
        return 0x10A3;
    case 4:
        return 0x10A2;
    case 3:
        return 0x10C3;
    case 5:
        return 0x10A4;
    case 6:
        return 0xDC4;
    }
    return 0;
}

// 0x004EC140
static int __stdcall SKILLDESC_AddElemRange(int nMin, unsigned short nString, int nMax, Unicode* wszText, int nElemType)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nString)
    {
        nString = sub_004E6F60_GetElemDamageText(nElemType);
        if (!nString)
        {
            return 0;
        }
    }

    if ((nMin || nMax) && nMin != nMax)
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EAF90
void __fastcall SKILLDESC_DrawWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nWeaponMinOutput = 0;
    int nWeaponMaxOutput = 0;
    int nWeaponColor = 0;
    sub_004E86F0_GetWeaponDamage(&nWeaponMinOutput, &nWeaponMaxOutput, &nWeaponColor, 0, pSkill, 0x80, 0, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nWeaponMinOutput, &nWeaponMaxOutput, &nWeaponColor, pSkill);

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    sub_004E72D0_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);

    if (!nWeaponMinOutput && !nWeaponMaxOutput)
    {
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nWeaponColor, nY, nWeaponMinOutput, nWeaponMaxOutput, nLeft, nRight);
        return;
    }

    int nWeaponMin = nWeaponMinOutput;
    int nWeaponMax = nWeaponMaxOutput;

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

// build: symbol ?SKILLDESC_AddElemRatePerSecond@* 0x004EC540
static int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, int nMin, int nMax, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin == nMax)
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nMin);
    }
    else
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10E2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10BE));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC620
static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int* const pMax = &nMax;
    SKILLDESC_ApplyFireMasteryBonus(&nMin, pSkillsTxt, pMax);
    SKILLDESC_ApplyLightningMasteryBonus(&nMin, pSkillsTxt, pMax);
    const int nMinRate = nMin >> 8;
    const int nMaxRate = nMax >> 8;
    unsigned short nString;
    switch (MISSILE_GetElemTypeFromMissileId(nMissileId))
    {
    case 2:
        nString = 0x10A3;
        break;
    case 4:
        nString = 0x10A2;
        break;
    case 3:
        nString = 0x10C3;
        break;
    case 5:
        nString = 0x10A4;
        break;
    case 6:
        nString = 0xDC4;
        break;
    case 1:
        nString = 0x10A1;
        break;
    default:
        nString = 0x10A1;
        break;
    }

    return SKILLDESC_AddElemRatePerSecond(nString, nMinRate, nMaxRate, wszText);
}

int __fastcall sub_M346_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLine, short nMissileId)
{
    if (nLine == 7)
    {
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, nMissileId, nSkillLevel);
        return 3;
    }
    return 5;
}

static inline D2SkillsTxt* GetSkillsRecord(D2DataTablesStrc* pTables, int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < pTables->nSkillsTxtRecordCount)
        return &pTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004ED480
int __stdcall SKILLDESC_HasClassSkill(D2UnitStrc* pUnit)
{
    int nSkillId = 0;
    if (gbHasClassSkill)
        return 1;
    D2DataTablesStrc* pTables = gpDataTables_00744304;
    for (; nSkillId < pTables->nSkillsTxtRecordCount; ++nSkillId)
    {
        D2SkillsTxt* pRecord = GetSkillsRecord(pTables, nSkillId);
        if (pRecord && (unsigned char)pRecord->nCharClass == (unsigned char)GAME_GetUnitClassId(pUnit))
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0))
            {
                gbHasClassSkill = 1;
                return 1;
            }
            pTables = gpDataTables_00744304;
        }
    }
    return 0;
}

// 0x004ED530
static inline int SKILLDESC_HasOnlyBonusLevels(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 1) && !SKILLS_GetSkillLevel(pUnit, pSkill, 0))
    {
        return 1;
    }
    return 0;
}

int __fastcall sub_M119_Emit_004ED530(D2UnitStrc* pUnit, int nSkillId)
{
    return SKILLDESC_HasOnlyBonusLevels(pUnit, nSkillId);
}

void __fastcall SKILLDESC_DrawWeaponDamageWithParam(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, 0, pSkill, 0, 0, 0, pUnit, 0);
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xD40);
    D2SkillsTxt* pRecord = sub_I05_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pRecord ? 0 : pRecord->dwParam[4];
    nMin += nParam * nMin / 100;
    nMax += nParam * nMax / 100;
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

static unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    if (pSkillsTxtRecord)
    {
        const int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        pSkillDescTxtRecord = (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount) ? &sgptDataTables->pSkillDescTxt[nSkillDesc] : 0;
    }
    if (!pSkillDescTxtRecord) return 0x1506;
    return pSkillDescTxtRecord->wStrAlt;
}

// build: context sub_004E9940_DrawNumberCentered
static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    Unicode wszText[32];
    char szText[32];
    wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (nValue < 1000) D2Win_10127_SetFont(1);
    else D2Win_10127_SetFont(0); // 0x00502EF0
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText, nColor);
}

// 0x004ED570
void __fastcall SKILLDESC_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot)
{
    int nValue1, nValue2, nColor1, nColor2;
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt) return;
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile_006DBF24, 0x1588);
    D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pDesc) return;
    D2Win_10127_SetFont(6);
    Unicode wszName[32];
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(sub_004E6E30_GetSkillDescAltStr(nSkillId)));
    GAME_StrToUpper(wszName);
    int nIndex = nSlot;
    DRAW_SKILL_TEXT(nIndex, wszName);
    int bDamage = 0;
    int bDescription = 0;
    switch (sub_004D9FC0(pUnit, pSkill))
    {
    case 0: case 1: case 6: case 8:
        bDamage = 1;
        bDescription = 1;
        break;
    }
    if (pDesc->wDescDam >= 144 || !gpfnSkillDamageFuncs[pDesc->wDescDam]) bDamage = 0;
    if (pDesc->wDescFunc >= 72 || !gpfnSkillDescFuncs[pDesc->wDescFunc]) bDescription = 0;
    ++nIndex;
    if (bDamage)
        DRAW_SKILL_TEXT(nIndex, D2LANG_GetStringFromTblIndex(0xFDD));
    ++nIndex;
    if (bDamage)
        gpfnSkillDamageFuncs[pDesc->wDescDam](pUnit, pSkill, pSkillsTxt, nLevel, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight);
    if (!bDescription)
        return;
    Unicode wszDescription[200];
    nValue1 = 0;
    nValue2 = 0;
    nColor1 = 0;
    nColor2 = 0;
    gpfnSkillDescFuncs[pDesc->wDescFunc](pUnit, pSkill, pSkillsTxt, nLevel, &nValue1, &nColor1, &nValue2, &nColor2);
    ++nIndex;
    if (nValue1 || nValue2)
    {
        D2Win_10127_SetFont(6);
        if (nSkillId)
            sub_005269D0(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFDF), wszName);
        else
            sub_005269D0(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFE1), wszName);
        wszDescription[199].wChar = 0;
        Unicode* pNext;
        if (TEXT_SplitAtNewline(wszDescription, &pNext))
        {
            TEXT_DrawCenteredText(TP[nIndex].nLeft + gnPanelOffsetX, gnPanelOffsetY + gnScreenHeight + TP[nIndex].nY - 484, TP[nIndex].nRight + gnPanelOffsetX, wszDescription, 0);
            TEXT_DrawCenteredText(TP[nIndex].nLeft + gnPanelOffsetX, gnPanelOffsetY + gnScreenHeight + TP[nIndex].nY - 476, TP[nIndex].nRight + gnPanelOffsetX, pNext, 0);
        }
        else
            DRAW_SKILL_TEXT(nIndex, wszName);
    }
    nIndex += 2;
    if (nValue2)
    {
        Unicode wszValue1[32];
        Unicode wszValue2[32];
        char szValue[32];
        wsprintfA(szValue, gszFormatD, nValue1);
        sub_00526320_ToUnicode(wszValue1, szValue, 32);
        wsprintfA(szValue, gszFormatD, nValue2);
        sub_00526320_ToUnicode(wszValue2, szValue, 32);
        SKILLDESC_DrawTwoTexts(wszValue1, wszValue2, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight, nColor1, nColor2);
    }
    else if (nValue1)
        sub_004E9940_DrawNumberCentered(nColor1, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight, nValue1);
}

static inline unsigned int SEED_RollRandomNumber_Spray(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Spray(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static inline int CLIENTS_GetUnitX_Spray(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitY_Spray(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    default:
        if (pUnit->pDynamicPath)
            nResult = PATH_GetYPosition(pUnit->pDynamicPath);
        else
            nResult = 0;
        break;
    }
    return nResult;
}

// 0x004F1A30
static void __stdcall SKILLDESC_CreateSprayMissile(D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    const int nIndex = SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 7;
    const int nUnitX = CLIENTS_GetUnitX_Spray(pUnit);
    const int nUnitY = CLIENTS_GetUnitY_Spray(pUnit);
// build: symbol ?gaSprayOffsetX@* 0x006DBFA8
    const int nOffsetX = gaSprayOffsetX[nIndex];
// build: symbol ?gaSprayOffsetY@* 0x006DBFC8
    const int nOffsetY = gaSprayOffsetY[nIndex];
    const int nX = nUnitX + nOffsetX;
    const int nY = nUnitY + nOffsetY;

    int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0)
    {
        return;
    }

    if (pSkillsTxt->wCltMissileB >= 0)
    {
        if (pSkillsTxt->wCltMissileC >= 0)
        {
            switch (SEED_RollRandomNumber_Spray(&pUnit->pSeed) % 3)
            {
            case 0:
                nMissile = pSkillsTxt->wCltMissileB;
                break;

            case 1:
                nMissile = pSkillsTxt->wCltMissileC;
                break;
            }
        }
        else if (!(SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 1))
        {
            nMissile = pSkillsTxt->wCltMissileB;
        }
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nTargetX = nOffsetY;
    tMissile.nTargetY = -nOffsetX;

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissile);
    if (!pMissile)
    {
        return;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[1], nSkillId, nSkillLevel);
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, SEED_RollLimitedRandomNumber(&pUnit->pSeed, nSpread));
    MISSILE_SetTargetX(pMissile, CLIENTS_GetUnitX_Spray(pUnit));
    MISSILE_SetTargetY(pMissile, CLIENTS_GetUnitY_Spray(pUnit));
}

int __fastcall sub_004F1C80_SkillCltDoSpray(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_Spray(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int bInTown = !pRoom || DUNGEON_IsRoomInTown(pRoom);
    if (pSkillsTxt->wPrgSound > 0)
    {
        void* pUnitSfx = MISSILE_FindUnitSfxInRange(pUnit, pSkillsTxt->wPrgSound);
        if (bInTown)
        {
            if (pUnitSfx)
            {
                sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
            }
        }
        else if (!pUnitSfx)
        {
            sub_004B9A00(pSkillsTxt->wPrgSound, pUnit, 0, 0, 0);
        }
    }

    if (bInTown)
    {
        return 0;
    }

    const int nSkill = nSkillId;
    const int nPasses = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkill, nSkillLevel);
    for (int i = 0; i < nPasses; ++i)
    {
        SKILLDESC_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        SKILLDESC_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        SKILLDESC_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
    }

    return 1;
}

// build: context sub_004F21B0_GetSkillsTxtRecord
static inline D2SkillsTxt* sub_004F21B0_GetSkillsTxtRecord(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}
	return 0;
}

// 0x004F21B0
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId)
{
	D2SkillsTxt* pSkillsTxtRecord = sub_004F21B0_GetSkillsTxtRecord(nSkillId);
	if (!pSkillsTxtRecord)
	{
		return -1;
	}

	if (pSkillsTxtRecord->nFlags[0] & gbSkillFlagMask_006CE270)
	{
		if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
			&& pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
		{
			D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
			if (pStatList)
			{
				int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
				nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
				return pSkillsTxtRecord->wCltMissile[nIndex];
			}
		}
	}

	return pSkillsTxtRecord->wCltMissile[1];
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
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

// 0x004F28A0
void __fastcall SKILLDESC_MissileScatter(D2UnitStrc* pUnit, int nSeed, int nMissile, int nX, int nY, int nRadius, int nSkillId, int nSkillLevel)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nSeed);

    const int nRadiusSq = nRadius * nRadius;
    const int nRange = 2 * nRadius;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 1;
    tMissile.pOwner = pUnit;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    for (int i = 0; i < nRadiusSq; ++i)
    {
        const int nOffsetX = nRadius - SEED_RollLimitedRandomNumberInline(&tSeed, nRange);
        const int nOffsetY = nRadius - SEED_RollLimitedRandomNumberInline(&tSeed, nRange);
        if (nOffsetX * nOffsetX + nOffsetY * nOffsetY <= nRadiusSq)
        {
            tMissile.nX = nX + nOffsetX;
            tMissile.nY = nY + nOffsetY;
            if (sub_00463740_FindRoomAtPoint(pRoom, tMissile.nX, tMissile.nY))
            {
                MISSILE_CreateClientMissile(&tMissile);
            }
        }
    }
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

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->nXPos;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->nYPos;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x004F2BE0
void __fastcall SKILLDESC_InitCurvingMissilePath(D2UnitStrc* pMissile, int nInitSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 78)
    {
        nFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2SeedStrc* const pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nInitSeed);
    PATH_SetType(pPath, 10);
    PATH_SetNewDistance(pPath, nFrames);

    D2PathPointStrc* pPathPoints;
    PATH_GetPathPoints(pPath, &pPathPoints);

    int nX = CLIENTS_GetUnitXInline(pMissile);
    int nY = CLIENTS_GetUnitYInline(pMissile);
    int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pMissile, D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath));

    D2SeedStrc tSeed;
    int nSign = (SEED_RollFromInline(pSeed, &tSeed) & 1) ? 1 : -1;
    const unsigned int nRoll = SEED_RollLowInline(&tSeed);
    pSeed->nHighSeed = tSeed.nHighSeed;
    pSeed->nLowSeed = tSeed.nLowSeed;
    // volatile: the original reads the turn base from memory inside each sum
    int nStep = nRoll % 3 + *(volatile int*)&gnChargedBoltTurnBase;
    for (int i = 0; i < nFrames; ++i)
    {
        nDirection += nSign * nStep;
        const unsigned char nIndex = INVENTORY_GetEightWayDirection(nDirection & 63);
        nX += gaCurvingPathOffsetX[nIndex];
        nY += gaCurvingPathOffsetY[nIndex];
        pPathPoints[i].X = nX;
        pPathPoints[i].Y = nY;

        if (!(i % gnChargedBoltTurnEvery))
        {
            nSign = -nSign;
            nStep = SEED_RollRandomNumber(pSeed) % 3 + *(volatile int*)&gnChargedBoltTurnBase;
        }
    }

    PATH_SetNumberOfPathPoints(pPath, nFrames);
}

#include "gen/data/Source/D2Client/UI/SkillDesc.inc"
