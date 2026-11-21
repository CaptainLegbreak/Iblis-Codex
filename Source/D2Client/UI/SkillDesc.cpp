#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2Txt.h"
#include "D2DataTbls.h"

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC

extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern int gnGlobal_007A2858;                                                                               // 0x007A2858

extern int gnGlobal_007A285C;                                                                               // 0x007A285C

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870

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

int __fastcall sub_004E9610_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004E9610

int __fastcall sub_004EA4A0_WeaponDamageCallback2(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004EA4A0

void __fastcall sub_004EA010_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA010

struct Unicode;

struct UnicodeChar;

struct D2SkillsTxt;

struct D2SkillDescTxt;

struct D2UnitStrc;

struct D2DataTablesStrc;

extern "C" const char szFmtRangeKK_006DBEAC[]; // 0x006DBEAC

extern "C" const char szFmtRangeK_006DBEB8[]; // 0x006DBEB8

int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __cdecl sub_004E6FF0_SumProgressiveBonus(); // 0x004E6FF0

int __stdcall sub_004E7120_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor); // 0x004E7120

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

static void __stdcall sub_004E96E0_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight);

extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc*); // 0x00451F60

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

int __stdcall sub_004EC140_AddElemRange(int nMin, unsigned short nString, int nMax, Unicode* wszText, int nElemType);

static int __stdcall sub_004EC220_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel);

static void __stdcall sub_004E99F0_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage);

void __fastcall sub_004EA170_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall sub_004EA240_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall sub_004EA310_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall sub_004EA790_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall sub_004EAA30_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall sub_004EB240_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

int gbHasClassSkill_007C8CA0; // 0x007C8CA0

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
#include "D2Client.h"

extern "C" __declspec(dllimport)
int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId);                          // 0x00626070

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

int __stdcall sub_0063A380(D2UnitStrc* pUnit);                                        // 0x0063A380

int __stdcall sub_0063A3A0(D2UnitStrc* pUnit);                                         // 0x0063A3A0

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0

void __stdcall sub_004E72D0_GetElemDamage(D2UnitStrc*, int*, int*, int*, D2SkillsTxt*, int); // 0x004E72D0

static int __stdcall sub_004E86F0_GetWeaponDamage(int*, int*, int*, int, D2SkillStrc*, int, D2UnitStrc*, int, D2UnitStrc*, int); // 0x004E86F0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

extern const D2ElemDamageStatsStrc gaElemDamageStats_006DBEF4[4];                                          // 0x006DBEF4

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))


static __forceinline int sub_I05_ETypeColor(int nEType)
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

static D2UnitStrc* sub_004E9260_MergeOtherHandWeapon(D2UnitStrc* pUnit)
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

static int __stdcall sub_004E93A0_EvaluateForEachWeapon(int* pValue1, int* pValue2, int* pColor1, int* pValue3, int* pValue4, int* pColor2, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nBonus, D2UnitStrc* pUnit, int nAdd)
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
        D2UnitStrc* pItem = sub_004E9260_MergeOtherHandWeapon(pUnit);
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

static void sub_004E8D90_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType)
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
static void __stdcall sub_004E96E0_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight)
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
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
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
        sub_00502EF0(6);
        --nY;
    }
    else
    {
        sub_00502EF0(1);
    }
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_00711470 + gnGlobal_007A285C + nY - 480, gnGlobal_007A2858 + nRight, wszText, nColor);
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

int __stdcall sub_004EC280_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel); // 0x004EC280

int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nCalcA, int nCalcB, int nLine, unsigned short nStringA, short nMissileId)
{
    switch (nLine)
    {
    case 2:
        sub_004EC140_AddElemRange(nCalcA, nStringA, nCalcB, wszText, pSkillsTxt->nEType);
        return 1;
    case 3:
        sub_004EC220_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        return 1;
    case 4:
        sub_004EC220_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 5:
        sub_004EC280_AddMissileElemDamage(pUnit, wszText, nStringA, nMissileId, nSkillLevel);
        return 1;
    }
    return 0;
}

static void __stdcall sub_004E6EA0_ApplyColdSkillBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
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

static void __stdcall sub_004E6F00_ApplyFireSkillBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
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
static void __stdcall sub_004E99F0_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage)
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
    sub_004E93A0_EvaluateForEachWeapon(&nMin1, &nMax1, &nColor1, &nMin2, &nMax2, &nColor2, pSkill, pfnEvaluate, nBonus, pUnit, nAdd);
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
        sub_004E96E0_DrawDamageRange(nColor2, nY, nMin2, nMax2, nLeft, nRight);
        return;
    }

    if (!nMin2 && !nMax2)
    {
        sub_004E96E0_DrawDamageRange(nColor1, nY, nMin1, nMax1, nLeft, nRight);
        return;
    }

    UnicodeChar wszText1[32];
    char szText[32];
    if (nMin1 == nMax1)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin1);
    }
    else if (nMin1 < 10000 && nMax1 < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nMin1, nMax1);
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

    UnicodeChar wszText2[32];
    if (nMin2 == nMax2)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin2);
    }
    else if (nMin2 < 10000 && nMax2 < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nMin2, nMax2);
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
    sub_004E9870_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor1, nColor2);
}

// 0x004EA170
void __fastcall sub_004EA170_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0x9B8), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0x9B9), nSkillLevel);
        sub_004E99F0_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, sub_004E9610_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 1);
        return;
    }

    sub_004EA010_DrawSkillWeaponLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

// 0x004EA240
void __fastcall sub_004EA240_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0x9DD), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0x9DE), nSkillLevel);
        sub_004E99F0_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, sub_004E9610_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 0);
        return;
    }

    sub_004EA010_DrawSkillWeaponLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

// 0x004EA310
void __fastcall sub_004EA310_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0xA02), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0xA03), nSkillLevel);
        sub_004E99F0_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, sub_004E9610_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 1);
    }
    else
    {
        int nMin = 0;
        int nMax = 0;
        int nColor = 0;
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0xA0C), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0xA0D), nSkillLevel);
        sub_004E9610_WeaponDamageCallback(pUnit, &nMin, &nMax, &nColor, nBonus, nAdd, pSkill, 0, 0);
        sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
    }
}

// 0x004EA790
void __fastcall sub_004EA790_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
    sub_004E8D90_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);
    if (nMax < nMin)
    {
        nMax = nMin;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
    nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    sub_004E72D0_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EAA30
void __fastcall sub_004EAA30_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    D2UnitStrc* pItem = sub_004E9260_MergeOtherHandWeapon(pUnit);
    if (!pItem)
    {
        return;
    }

    sub_004EA4A0_WeaponDamageCallback2(pUnit, &nMin, &nMax, &nColor, 0, 0, pSkill, 0, pItem);
    sub_004E9300_MergeWeaponPair(pUnit);
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// build: context ApplyRatio_Inline
// build: context AddPoisonDamage_Inline
// build: context AddPoisonDamageAndClamp_Inline

void __fastcall sub_004EA010_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
    const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0x98C), nSkillLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0x98D), nSkillLevel);
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
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EAF90
void __fastcall sub_004EAF90_DrawWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
        sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        sub_004E96E0_DrawDamageRange(nWeaponColor, nY, nWeaponMinOutput, nWeaponMaxOutput, nLeft, nRight);
        return;
    }

    int nWeaponMin = nWeaponMinOutput;
    int nWeaponMax = nWeaponMaxOutput;

    UnicodeChar wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    UnicodeChar wszText2[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    sub_004E9870_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

// 0x004EB240
void __fastcall sub_004EB240_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], pSkillsTxt->nSkillId, nSkillLevel);
    sub_004E99F0_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, sub_004EA4A0_WeaponDamageCallback2, nBonus, 0, nLeft, nY, nRight, 1);
}

static int sub_004E6FB0_GetETypeColor(int nEType)
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

static void __stdcall sub_004E9660_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill, D2UnitStrc* pItem, int nRatio)
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

void __fastcall sub_004E9D20_DrawWeaponAndSkillDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
    sub_004E9660_AddScaledWeaponDamage(pUnit, &nWeaponMin, &nWeaponMax, &nWeaponColor, pSkill, 0, pSkillsTxt->nSrcDam);
    const int nColor = sub_004E6FB0_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    sub_004E8D90_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);

    if (!nWeaponMin && !nWeaponMax)
    {
        sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        sub_004E96E0_DrawDamageRange(nWeaponColor, nY, nWeaponMin, nWeaponMax, nLeft, nRight);
        return;
    }

    UnicodeChar wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    UnicodeChar wszText2[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    sub_004E9870_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

int __stdcall sub_004E7120_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor)
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
void __fastcall sub_004EB640_DrawMasteryWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
    nColor = sub_004E6FB0_GetETypeColor(pSkillsTxt->nEType);
    sub_004E9660_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, pSkillsTxt->nSrcDam);

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
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EBA30
void __fastcall sub_004EBA30_DrawKickDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
    int nBonus = sub_004E6FF0_SumProgressiveBonus();
    nBonus += sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
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
        sub_004E7120_AddProgressiveDamage(pUnit, &nElemMin, &nElemMax, &nColor);
        nKickMin += nElemMin;
        nKickMax += nElemMax;
    }
    sub_004E96E0_DrawDamageRange(nColor, nY, nKickMin, nKickMax, nLeft, nRight);
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

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
        int nProgressive = sub_004E6FF0_SumProgressiveBonus();
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

    if (sub_0063A380(pUnit))
        *pColor = 3;
    if (sub_0063A3A0(pUnit))
        *pColor = 1;

    if (nBonus <= -90)
        nBonus = -90;

    *pMinDamage = (nMinPercent + nBonus + 100) * *pMinDamage / 100 + nDamage + nAdd;
    *pMaxDamage = (nMaxPercent + nBonus + 100) * *pMaxDamage / 100 + nDamage + nAdd;
    return 1;
}


static __forceinline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
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

static __forceinline void AddPoisonDamage_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
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

static __forceinline void AddPoisonDamageAndClamp_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
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
        int nMin = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats_006DBEF4[i].nMinStat, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats_006DBEF4[i].nMaxStat, 0);
        if (gaElemDamageStats_006DBEF4[i].nMasteryStat != -1)
        {
            int nMastery = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats_006DBEF4[i].nMasteryStat, 0);
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
            *pColor = gaElemDamageColors_006DBEE4[i];
        }
    }

    AddPoisonDamageAndClamp_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7]))
        {
            sub_004E7120_AddProgressiveDamage(pUnit, pMinDamage, pMaxDamage, pColor);
        }
    }

    if (sub_0063A380(pUnit))
    {
        *pColor = 3;
    }

    if (sub_0063A3A0(pUnit))
    {
        *pColor = 1;
    }

    return 1;
}

// build: context ApplyRatio_Inline
// build: context AddPoisonDamage_Inline
// build: context AddPoisonDamageAndClamp_Inline

// 0x004EBD50
void __fastcall sub_004EBD50_DrawDescWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
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
        sub_004E96E0_DrawDamageRange(nElemColor, nY, nElemMin, nElemMax, nLeft, nRight);
        return;
    }

    if (!nElemMin && !nElemMax)
    {
        sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    const int nWeaponMin = nMin;
    const int nWeaponMax = nMax;

    UnicodeChar wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    UnicodeChar wszText2[32];
    if (nElemMin == nElemMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nElemMin);
    }
    else if (nElemMin < 10000 && nElemMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nElemMin, nElemMax);
    }
    else if (nElemMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nElemMin + 500) / 1000, (nElemMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nElemMin, (nElemMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    sub_004E9870_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor, nElemColor);
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
static int __stdcall sub_004EC140_AddElemRange(int nMin, unsigned short nString, int nMax, Unicode* wszText, int nElemType)
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
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
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

// 0x004EC220
static int __stdcall sub_004EC220_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return sub_004EC140_AddElemRange(nMin >> 8, nString, nMax >> 8, wszText, pSkillsTxt->nEType);
}

static int __stdcall sub_004EC540_AddElemRatePerSecond(unsigned short nString, int nMin, int nMax, Unicode* wszText)
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
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
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
static int __stdcall sub_004EC620_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int* const pMax = &nMax;
    sub_004E6EA0_ApplyColdSkillBonus(&nMin, pSkillsTxt, pMax);
    sub_004E6F00_ApplyFireSkillBonus(&nMin, pSkillsTxt, pMax);
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

    return sub_004EC540_AddElemRatePerSecond(nString, nMinRate, nMaxRate, wszText);
}

int __fastcall sub_M346_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLine, short nMissileId)
{
    if (nLine == 7)
    {
        sub_004EC620_AddMissileElemRate(pUnit, wszText, pSkillsTxt, nMissileId, nSkillLevel);
        return 3;
    }
    return 5;
}

static __forceinline D2SkillsTxt* GetSkillsRecord(D2DataTablesStrc* pTables, int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < pTables->nSkillsTxtRecordCount)
        return &pTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004ED480
int __stdcall sub_004ED480_HasClassSkill(D2UnitStrc* pUnit)
{
    int nSkillId = 0;
    if (gbHasClassSkill_007C8CA0)
        return 1;
    D2DataTablesStrc* pTables = gpDataTables_00744304;
    for (; nSkillId < pTables->nSkillsTxtRecordCount; ++nSkillId)
    {
        D2SkillsTxt* pRecord = GetSkillsRecord(pTables, nSkillId);
        if (pRecord && (unsigned char)pRecord->nCharClass == (unsigned char)sub_00451F60_UnitClassId(pUnit))
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0))
            {
                gbHasClassSkill_007C8CA0 = 1;
                return 1;
            }
            pTables = gpDataTables_00744304;
        }
    }
    return 0;
}

// 0x004ED530
static __forceinline int sub_004ED530_HasOnlyBonusLevels(D2UnitStrc* pUnit, int nSkillId)
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
    return sub_004ED530_HasOnlyBonusLevels(pUnit, nSkillId);
}

void __fastcall sub_004EB940_DrawWeaponDamageWithParam(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, 0, pSkill, 0, 0, 0, pUnit, 0);
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 0xD40);
    D2SkillsTxt* pRecord = sub_I05_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pRecord ? 0 : pRecord->dwParam[4];
    nMin += nParam * nMin / 100;
    nMax += nParam * nMax / 100;
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

#include "gen/data/Source/D2Client/UI/SkillDesc.inc"
