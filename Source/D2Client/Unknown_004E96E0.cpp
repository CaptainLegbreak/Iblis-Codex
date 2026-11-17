#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x136];
    unsigned int dwCalc;
    char unk0x13C[0x69];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2SkillDescTxt
{
    char unk0x00[0x18];
    unsigned int dwDamCalc[2];
    char unk0x20[0x100];
};

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C

void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
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
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc* pItem);                                          // 0x00629860
short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc* pItem);                                         // 0x006298A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __fastcall sub_004E9610_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004E9610
int __fastcall sub_004EA4A0_WeaponDamageCallback2(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004EA4A0
void __fastcall sub_004EA010_SkillDescLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA010

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

    if (!ITEMS_CheckItemTypeId(pOther, 45))
        return 0;

    if (!sub_0062A4E0_TestItem(pWeapon) || !sub_0062A4E0_TestItem(pOther))
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
        if (ITEMS_CheckItemTypeId(pOther, 45))
        {
            if (sub_0062A4E0_TestItem(pWeapon) && sub_0062A4E0_TestItem(pOther))
            {
                STATLIST_MergeStatLists(pUnit, pOther, 0);
                STATLIST_MergeStatLists(pUnit, pWeapon, 1);
                return pWeapon;
            }
        }
    }

    if (sub_0062A4E0_TestItem(pWeapon))
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
    if (!sub_0062A4E0_TestItem(pRight) || ITEMS_CheckItemTypeId(pRight, 0x26))
        pRight = 0;

    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!sub_0062A4E0_TestItem(pLeft) || ITEMS_CheckItemTypeId(pLeft, 0x26))
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
    if (pWeapon && sub_0062A4E0_TestItem(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    pfnEvaluate(pUnit, pValue1, pValue2, pColor1, nBonus, nAdd, pSkill, 0, 0);
    return 1;
}

static void sub_004E8D90_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType)
{
    switch (nType)
    {
    case 1:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, 0x30, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, 0x31, 0);
        break;
    case 2:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, 0x32, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, 0x33, 0);
        break;
    case 4:
    case 12:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, 0x36, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, 0x37, 0);
        break;
    case 3:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, 0x34, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, 0x35, 0);
        break;
    case 5:
    {
        int nLength = STATLIST_UnitGetStatValue(pUnit, 0x65, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, 0x146, 0);
            if (nCount <= 1)
                nCount = 1;
            nLength = STATLIST_UnitGetStatValue(pUnit, 0x3B, 0) / nCount;
        }
        int nMin = STATLIST_UnitGetStatValue(pUnit, 0x39, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, 0x3A, 0);
        *pMinDamage += nMin * nLength >> 8;
        *pMaxDamage += nMax * nLength >> 8;
        break;
    }
    }
}

// 0x004E96E0
static __declspec(noinline) void __stdcall sub_004E96E0_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight)
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

    sub_004EA010_SkillDescLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

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

    sub_004EA010_SkillDescLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

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
    int nFactor = sub_00629860_GetStrengthFactor(pItem);
    if (nFactor)
    {
        nBonus = STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
    }
    nFactor = sub_006298A0_GetDexterityFactor(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFactor / 100;
    }

    int nMin = STATLIST_UnitGetStatValue(pUnit, 0x9F, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, 0xA0, 0);
    nBonus += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
    if (nBonus <= -90)
    {
        nBonus = -90;
    }
    nMin += (nMinPercent + nBonus) * nMin / 100;
    nMax += (nMaxPercent + nBonus) * nMax / 100;

    int nMastery = 0;
    if (STATES_CheckState(pUnit, 0x4E))
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

void __fastcall sub_004EB240_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc, pSkillsTxt->nSkillId, nSkillLevel);
    sub_004E99F0_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, sub_004EA4A0_WeaponDamageCallback2, nBonus, 0, nLeft, nY, nRight, 1);
}
