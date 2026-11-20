// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



struct D2SkillDescTxt
{
    char unk0x0[0x18];
    unsigned int dwDamCalc[2];
    unsigned char nPrgDamElem[3];
    char unk0x23[0x1];
    int dwProgDmgMin[3];
    int dwProgDmgMax[3];
    char unk0x3C[0xE4];
};


struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(dllimport)
int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70
extern "C" const char szFmtRangeKK_006DBEAC[];                                                              // 0x006DBEAC
extern "C" const char szFmtRangeK_006DBEB8[];                                                               // 0x006DBEB8
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId);                          // 0x00626070
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __cdecl sub_004E6FF0_SumProgressiveBonus();                                                             // 0x004E6FF0
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem);                                          // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem);                                         // 0x006298A0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall sub_0063A380(D2UnitStrc* pUnit);                                        // 0x0063A380
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit);                                         // 0x0063A3A0
void __fastcall sub_004EA4A0_WeaponDamageCallback2(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004EA4A0
int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0

static void __stdcall sub_004E72D0_GetElemDamage(D2UnitStrc*, int*, int*, int*, D2SkillsTxt*, int); // 0x004E72D0
static int __stdcall sub_004E86F0_GetWeaponDamage(int*, int*, int*, int, D2SkillStrc*, int, D2UnitStrc*, int, D2UnitStrc*, int); // 0x004E86F0
static void __stdcall sub_004E96E0_DrawDamageRange(int, int, int, int, int, int); // 0x004E96E0

// build: context sub_I05_GetSkillsTxtRecord
static D2SkillsTxt* sub_I05_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E6FB0
static int sub_I05_ETypeColor(int nEType)
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

// build: context sub_004E72D0_GetElemDamage
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
            nMin = STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
        }
        else
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, 0x18, 0);
        }
    }
    else
    {
        nMin = STATLIST_UnitGetStatValue(pUnit, 0x15, 0) + 1;
        nMax = STATLIST_UnitGetStatValue(pUnit, 0x16, 0) + 2;
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

    nBonus += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
    nBonus += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
    int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
    int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
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
            nBonus += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
        nFactor = ITEMS_GetDexBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFactor / 100;
        nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x6F, 0);
    }
    else
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, 0, 0);
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

// 0x004E96E0
// build: context sub_004E96E0_DrawDamageRange
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
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
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
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
extern const D2ElemDamageStatsStrc gaElemDamageStats_006DBEF4[4];                                          // 0x006DBEF4
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x004E7120
int __stdcall sub_004E7120_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor)
{
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
            if (pStatList)
            {
                int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
                    if (pSkillsTxt)
                    {
                        int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
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
    int nMin = STATLIST_UnitGetStatValue(pUnit, 0x39, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, 0x3A, 0);
    if (nMax)
    {
        int nMastery = STATLIST_UnitGetStatValue(pUnit, 0x14C, 0);
        if (nMastery)
        {
            nMin += ApplyRatio_Inline(nMin, nMastery, 100);
            nMax += ApplyRatio_Inline(nMax, nMastery, 100);
        }

        int nLength = STATLIST_UnitGetStatValue(pUnit, 0x65, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, 0x146, 0);
            if (nCount <= 1)
            {
                nCount = 1;
            }
            nLength = STATLIST_UnitGetStatValue(pUnit, 0x3B, 0) / nCount;
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

// 0x004E89A0
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
