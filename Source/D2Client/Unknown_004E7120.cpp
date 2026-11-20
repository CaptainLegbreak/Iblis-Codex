#include "D2Client.h"
#include "D2Structs.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2SkillsTxt;
struct D2SkillDescTxt;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength); // 0x00526320
const wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
wchar_t* __fastcall sub_00526700(wchar_t* pDest, const wchar_t* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, wchar_t* pBuffer, const wchar_t* pFormat, ...); // 0x005269D0
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC
extern "C" const char szFmtPlusDec_006DBE9C[]; // 0x006DBE9C
extern "C" const char szFmtDec_006DBE94[]; // 0x006DBE94
extern "C" const char szFmtRange_006D9D70[]; // 0x006D9D70


struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x02];
    unsigned char nFlags[8];
    char unk0x0C[0x48];
    short wAuraStat[6];
    char unk0x60[0x126];
    short wMinMana;
    short nManaShift;
    short wMana;
    short wLevelMana;
    char unk0x18E[0x06];
    short wSkillDesc;
    char unk0x196[0x0F];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2SkillDescTxt
{
    char unk0x00[0x0C];
    unsigned short wStrLong;
    char unk0x0E[0x02];
    unsigned short wStrMana;
    char unk0x12[0x0E];
    unsigned char nPrgDamElem[3];
    char unk0x23[0x01];
    int dwProgDmgMin[3];
    int dwProgDmgMax[3];
    char unk0x3C[0xE4];
};

struct D2DataTablesStrc
{
    char unk0x00[0x16C];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x172[0xA1A];
    D2SkillDescTxt* pSkillDescTxt;
    char unk0xB90[0x04];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId); // 0x00626070
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __cdecl sub_004E6FF0_SumProgressiveBonus(); // 0x004E6FF0
short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc* pItem); // 0x00629860
short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc* pItem); // 0x006298A0
int __stdcall sub_0063A380(D2UnitStrc* pUnit); // 0x0063A380
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit); // 0x0063A3A0
int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem);

__declspec(noinline) static int __stdcall sub_004E73E0_FormatSignedInt(wchar_t* wszText, int bPrefixSign, int nValue);
__declspec(noinline) static int __stdcall sub_004E7430_FormatSignedDecimal(wchar_t* wszText, int bPrefixSign, int nValue, int nFraction);

static int sub_004E7480_FormatIntOrDecimal(wchar_t* wszText, int bPrefixSign, int nValue, int nFraction);
int __fastcall sub_004E8FE0_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem);

static D2SkillsTxt* sub_D05_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static __declspec(noinline) unsigned short sub_004E6DE0_GetSkillDescStrLong(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = sub_D05_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0x1506;

    int nSkillDesc = pSkillsTxt->wSkillDesc;
    if (nSkillDesc < 0 || nSkillDesc >= sgptDataTables->nSkillDescTxtRecordCount)
        return 0x1506;

    D2SkillDescTxt* pSkillDescTxt = &sgptDataTables->pSkillDescTxt[nSkillDesc];
    if (!pSkillDescTxt)
        return 0x1506;

    return pSkillDescTxt->wStrLong;
}

// 0x004E6EA0
static void __stdcall sub_004E6EA0_ApplyColdSkillBonus(int* pValue1, int* pValue2, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, 0x149, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// 0x004E6F00
static void __stdcall sub_004E6F00_ApplyFireSkillBonus(int* pValue1, int* pValue2, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, 0x14A, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// 0x004E6F60
static unsigned short sub_004E6F60_GetETypeDamageStr(int nEType)
{
    switch (nEType)
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

// 0x004E6FB0
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
                                            *pColor = sub_004E6FB0_GetETypeColor(pElem[nIndex - 1]);
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

// 0x004E73E0
static int __stdcall sub_004E73E0_FormatSignedInt(wchar_t* wszText, int bPrefixSign, int nValue)
{
    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

// 0x004E7430
static int __stdcall sub_004E7430_FormatSignedDecimal(wchar_t* wszText, int bPrefixSign, int nValue, int nFraction)
{
    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusDec_006DBE9C, nValue, nFraction);
    else
        wsprintfA(szText, szFmtDec_006DBE94, nValue, nFraction);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

// 0x004E7650
static int __stdcall sub_004E7650_AppendFrameRange(wchar_t* wszOut, unsigned short wStr, int nMinFrames, int nMaxFrames)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int nMin = nMinFrames / 25;
    int nMinFraction = nMinFrames % 25 * 10 / 25;
    int nMax = nMaxFrames / 25;
    int nMaxFraction = nMaxFrames % 25 * 10 / 25;
    if (!nMin && !nMinFraction && !nMax)
        return 0;

    char szText[32];
    if (nMinFraction || nMaxFraction)
        wsprintfA(szText, szFmtDecRange_006DBEC8, nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10AC));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E77A0
static int __stdcall sub_004E77A0_AppendScaledRange(wchar_t* wszOut, unsigned short wStr1, unsigned short wStr2, int nMaxValue, int nMultiplier, int nMinValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int nMin = nMinValue / 256;
    int nMinFraction = nMinValue % 256 * nMultiplier / 256;
    int nMax = nMaxValue / 256;
    int nMaxFraction = nMaxValue % 256 * nMultiplier / 256;
    if (!nMin && !nMax && !nMinFraction && !nMaxFraction)
        return 0;

    char szText[32];
    if (nMinFraction || nMaxFraction)
        wsprintfA(szText, szFmtDecRange_006DBEC8, nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7930
static int __stdcall sub_004E7930_AppendFormattedValue(int nValue, unsigned short wStr, wchar_t* wszOut)
{
    wchar_t wszText[256];
    for (int i = 0; i < 256; ++i)
        wszText[i] = 0;

    if (wStr == 0x1506)
    {
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x1506));
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
        return 1;
    }

    sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(wStr), nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszOut, wszText);
    return 1;
}

// 0x004E79E0
static int __stdcall sub_004E79E0_AppendLabelValue(unsigned short wStr, int bPrefixSign, wchar_t* wszOut, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7A90
static int __stdcall sub_004E7A90_AppendScaledValue(unsigned short wStr1, unsigned short wStr2, int nMultiplier, wchar_t* wszOut, int bPrefixSign, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    sub_004E7480_FormatIntOrDecimal(wszText, bPrefixSign, nValue / 256, nValue % 256 * nMultiplier / 256);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7B90
static int __stdcall sub_004E7B90_AppendLabelDecimal(unsigned short wStr, wchar_t* wszOut, int bPrefixSign, int nValue, int nFraction)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue && nFraction <= 0)
        return 0;

    sub_004E7480_FormatIntOrDecimal(wszText, bPrefixSign, nValue, nFraction);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7C30
static int __stdcall sub_004E7C30_AppendValueLabel(unsigned short wStr, int bPrefixSign, wchar_t* wszOut, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7CE0
static int __stdcall sub_004E7CE0_AppendValueTwoLabels(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, wchar_t* wszOut, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7DB0
static int __stdcall sub_004E7DB0_AppendValueCountLabel(int nStr1, int nStr2, int bPrefixSign, wchar_t* wszOut, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(nValue == 1 ? nStr1 : nStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7E70
static int __stdcall sub_004E7E70_AppendLabelValueLabel(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, wchar_t* wszOut, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7F40
static int __stdcall sub_004E7F40_AppendLabelRangeLabel(wchar_t* wszOut, int bPrefixSign, unsigned short wStr2, unsigned short wStr1, int nMin, int nMax)
{
    if (nMin == nMax)
        return sub_004E7E70_AppendLabelValueLabel(wStr1, wStr2, 0, wszOut, nMin);

    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, szFmtPlusRange_006DBEA4, nMin, nMax);
    else
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E8020
static int __stdcall sub_004E8020_AppendLabelsRange(wchar_t* wszOut, int bPrefixSign, unsigned short wStr1, unsigned short wStr2, int nMin, int nMax)
{
    if (nMin == nMax)
        return sub_004E7E70_AppendLabelValueLabel(wStr1, wStr2, 0, wszOut, nMin);

    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, szFmtPlusRange_006DBEA4, nMin, nMax);
    else
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E80F0
static int __stdcall sub_004E80F0_AppendLabelRange(wchar_t* wszOut, int bSeparator, int bPrefixSign, unsigned short wStr, int nMin, int nMax)
{
    if (nMin == nMax)
        return sub_004E79E0_AppendLabelValue(wStr, bPrefixSign, wszOut, nMin);

    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, szFmtPlusRange_006DBEA4, nMin, nMax);
    else
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    if (bSeparator)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E81C0
static int __stdcall sub_004E81C0_AppendLabelValueLabels(unsigned short wStr1, unsigned short wStr2, unsigned short wStr3, int bPrefixSign, wchar_t* wszOut, int nValue)
{
    wchar_t wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    else
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr3));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E83B0
static int sub_004E83B0_AppendSkillDescStrLong(wchar_t* wszOut, int nSkillId)
{
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(sub_004E6DE0_GetSkillDescStrLong(nSkillId)));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E84F0
static int __stdcall sub_004E84F0_AppendManaValue(int nValue, wchar_t* wszOut)
{
    const wchar_t* wszStr1 = D2LANG_GetStringFromTblIndex(0x5300);
    const wchar_t* wszStr2 = D2LANG_GetStringFromTblIndex(0x5304);
    const wchar_t* wszStr3 = D2LANG_GetStringFromTblIndex(0x5305);
    const wchar_t* wszStr4 = D2LANG_GetStringFromTblIndex(0xF9B);
    wchar_t wszText[16];
    for (int i = 0; i < 16; ++i)
        wszText[i] = 0;

    char szText[32];
    wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszStr2);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, wszStr4);
    sub_00526700(wszOut, wszStr1);
    sub_00526700(wszOut, wszStr3);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E85C0_AppendManaCost(wchar_t* wszOut, int nSkillId, int nLevel, int nMultiplier, D2SkillsTxt* pSkillsTxt, int nValue)
{
    short nMana = pSkillsTxt->wMana;
    if (!nMana && !pSkillsTxt->wLevelMana)
        return 0;

    if (nValue)
        return sub_004E84F0_AppendManaValue(nValue, wszOut);

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
        return 0;

    unsigned short wStr = pSkillDescTxt->wStrMana;
    int nCost = ((nLevel - 1) * pSkillsTxt->wLevelMana + nMana) << pSkillsTxt->nManaShift;
    int nMinCost = pSkillsTxt->wMinMana << 8;
    if (nMinCost > nCost)
        nCost = nMinCost;

    if (pSkillsTxt->nManaShift == 8 || pSkillsTxt->wLevelMana << pSkillsTxt->nManaShift > 0x100 || nCost > 0x1900)
        return sub_004E79E0_AppendLabelValue(wStr, 0, wszOut, nCost >> 8);

    if (nMultiplier > 10)
        return sub_004E7A90_AppendScaledValue(wStr, 0x1506, nMultiplier, wszOut, 0, nCost);

    return sub_004E7B90_AppendLabelDecimal(wStr, wszOut, 0, nCost / 256, nCost % 256 * 10 / 256);
}

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
        int nFactor = sub_00629860_GetStrengthFactor(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
        nFactor = sub_006298A0_GetDexterityFactor(pItem);
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

// 0x004E8D90
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

// 0x004E8EC0
static int __stdcall sub_004E8EC0_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue2 = 0;
    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == 38)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);
    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x77, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pValue2 = 3;
        }
    }
    *pValue1 += *pValue1 * nBonus / 100;

    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

// 0x004E9260
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

static int __stdcall sub_004E93A0_EvaluateForEachWeapon(int* pValue1, int* pValue2, int nArg3, int* pValue3, int* pValue4, int nArg6, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nArg9, D2UnitStrc* pUnit, int nLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (!sub_0062A4E0_TestItem(pRight) || ITEMS_CheckItemTypeId(pRight, 38))
        pRight = 0;

    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!sub_0062A4E0_TestItem(pLeft) || ITEMS_CheckItemTypeId(pLeft, 38))
        pLeft = 0;

    if (pRight && pLeft)
    {
        D2UnitStrc* pItem = sub_004E9260_MergeOtherHandWeapon(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue3, pValue4, nArg6, nArg9, nLevel, pSkill, 0, pItem);
        }
        else
        {
            *pValue3 = 0;
            *pValue4 = 0;
        }

        pItem = sub_004E9300_MergeWeaponPair(pUnit);
        if (!pItem)
        {
            *pValue1 = 0;
            *pValue2 = 0;
            return 1;
        }
        pfnEvaluate(pUnit, pValue1, pValue2, nArg3, nArg9, nLevel, pSkill, 0, pItem);
        return 1;
    }

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pWeapon && sub_0062A4E0_TestItem(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    pfnEvaluate(pUnit, pValue1, pValue2, nArg3, nArg9, nLevel, pSkill, 0, 0);
    return 1;
}

// 0x004E94E0
static int __stdcall sub_004E94E0_AttackRatingForEachWeapon(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pValue3, int* pValue4, D2SkillStrc* pSkill, int nLevel)
{
    return sub_004E93A0_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, sub_004E8FE0_AttackRatingCallback, 0, pUnit, nLevel);
}

// 0x004E9510
void __fastcall sub_004E9510_SkillDescAttackRating(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    if (UNITS_CanDualWield(pUnit))
    {
        sub_004E94E0_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
        return;
    }

    D2UnitStrc* pItem = 0;
    if (pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    *pValue1 = 0;
    *pValue2 = 0;
    sub_004E8EC0_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}

// 0x004E95C0
void __fastcall sub_004E95C0_SkillDescAttackRatingOffhand(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    sub_004E94E0_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
    *pValue1 = *pValue3;
    *pValue2 = *pValue4;
    *pValue3 = 0;
    *pValue4 = 0;
}

// 0x004E9610
int __fastcall sub_004E9610_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    sub_004E86F0_GetWeaponDamage(pMinDamage, pMaxDamage, pColor, nAdd, pSkill, nSrcDam, pItem, 0, pUnit, nBonus);
    return sub_004E89A0_GetElementalDamage(pUnit, pMinDamage, pMaxDamage, pColor, pSkill);
}

// 0x004E9660
static void __stdcall sub_004E9660_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, D2UnitStrc* pItem, int* pColor, D2SkillStrc* pSkill, int nRatio)
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

extern "C" int __stdcall sub_D05_Emit_4E7650(wchar_t* p, unsigned short w, int a, int b) { return sub_004E7650_AppendFrameRange(p, w, a, b); }

extern "C" int __stdcall sub_D05_Emit_4E77A0(wchar_t* p, unsigned short w1, unsigned short w2, int a, int m, int b) { return sub_004E77A0_AppendScaledRange(p, w1, w2, a, m, b); }

extern "C" int __stdcall sub_D05_Emit_4E7930(int n, unsigned short w, wchar_t* p) { return sub_004E7930_AppendFormattedValue(n, w, p); }

extern "C" int __stdcall sub_D05_Emit_4E79E0(unsigned short w, int b, wchar_t* p, int n) { return sub_004E79E0_AppendLabelValue(w, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7A90(unsigned short w1, unsigned short w2, int m, wchar_t* p, int b, int n) { return sub_004E7A90_AppendScaledValue(w1, w2, m, p, b, n); }

extern "C" int __stdcall sub_D05_Emit_4E7C30(unsigned short w, int b, wchar_t* p, int n) { return sub_004E7C30_AppendValueLabel(w, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7CE0(unsigned short w1, unsigned short w2, int b, wchar_t* p, int n) { return sub_004E7CE0_AppendValueTwoLabels(w1, w2, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7DB0(unsigned short w1, unsigned short w2, int b, wchar_t* p, int n) { return sub_004E7DB0_AppendValueCountLabel(w1, w2, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7E70(unsigned short w1, unsigned short w2, int b, wchar_t* p, int n) { return sub_004E7E70_AppendLabelValueLabel(w1, w2, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7F40(wchar_t* p, int b, unsigned short w2, unsigned short w1, int a, int c) { return sub_004E7F40_AppendLabelRangeLabel(p, b, w2, w1, a, c); }

extern "C" int __stdcall sub_D05_Emit_4E8020(wchar_t* p, int b, unsigned short w2, unsigned short w1, int a, int c) { return sub_004E8020_AppendLabelsRange(p, b, w1, w2, a, c); }

extern "C" int __stdcall sub_D05_Emit_4E80F0(wchar_t* p, int f, int b, unsigned short w, int a, int c) { return sub_004E80F0_AppendLabelRange(p, f, b, w, a, c); }

extern "C" int __stdcall sub_D05_Emit_4E81C0(unsigned short w1, unsigned short w2, unsigned short w3, int b, wchar_t* p, int n) { return sub_004E81C0_AppendLabelValueLabels(w1, w2, w3, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E83B0(wchar_t* p, int n) { return sub_004E83B0_AppendSkillDescStrLong(p, n); }

extern "C" int __stdcall sub_D05_Emit_4E85C0(wchar_t* p, int s, int l, int m, D2SkillsTxt* t, int v) { return sub_004E85C0_AppendManaCost(p, s, l, m, t, v); }

extern "C" void __stdcall sub_D05_Emit_4E6EA0(int* a, int* b, D2SkillsTxt* t) { sub_004E6EA0_ApplyColdSkillBonus(a, b, t); }

extern "C" void __stdcall sub_D05_Emit_4E6F00(int* a, int* b, D2SkillsTxt* t) { sub_004E6F00_ApplyFireSkillBonus(a, b, t); }

extern "C" unsigned short __stdcall sub_D05_Emit_4E6F60(int n) { return sub_004E6F60_GetETypeDamageStr(n); }

extern "C" void __stdcall sub_D05_Emit_4E8D90(D2UnitStrc* u, int* a, int* b, unsigned char t) { sub_004E8D90_AddElementalStatDamage(u, a, b, t); }

extern "C" void __stdcall sub_D05_Emit_4E9660(D2UnitStrc* u, int* a, int* b, D2UnitStrc* i, int* c, D2SkillStrc* k, int r) { sub_004E9660_AddScaledWeaponDamage(u, a, b, i, c, k, r); }

// 0x004E7480
static int sub_004E7480_FormatIntOrDecimal(wchar_t* wszText, int bPrefixSign, int nValue, int nFraction)
{
    if (!nValue && !nFraction)
        return 0;
    if (nFraction)
        return sub_004E7430_FormatSignedDecimal(wszText, bPrefixSign, nValue, nFraction);
    return sub_004E73E0_FormatSignedInt(wszText, bPrefixSign, nValue);
}

// 0x004E8FE0
int __fastcall sub_004E8FE0_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem)
{
    return sub_004E8EC0_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}
