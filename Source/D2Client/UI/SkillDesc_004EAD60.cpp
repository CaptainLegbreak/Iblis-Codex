#include "D2Client.h"

struct D2SkillsTxt;
struct Unicode;
struct UnicodeChar;
struct D2SkillDescTxt;
struct D2MonStatsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x02];
    unsigned char nFlags[8];
    unsigned char unk_0C[0x48];
    short wAuraStat[6];
    char unk0x60[0x8];
    int dwAuraStatCalc[6];
    char unk0x80[0x18];
    short nPassiveStat[5];
    char unk0xA2[0x2];
    int dwPassiveCalc[5];
    char unk0xB8[0x4];
    short wSummon;
    unsigned char unk_BE[0x7A];
    unsigned int dwCalc[3];
    unsigned char unk_144[0x4];
    int dwParam[8];
    unsigned char unk_168[0x3D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

extern "C" const char gszEmptyAssertText;
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);
extern "C" const char szFmtD_006D57BC[];
extern "C" const char szFmtRange_006D9D70[];
extern "C" const char szFmtRangeKK_006DBEAC[];
extern "C" const char szFmtRangeK_006DBEB8[];
extern int gnGlobal_00711470;
extern int gnGlobal_007A2858;
extern int gnGlobal_007A285C;
extern unsigned int gdwBitMasks_006CE268[];
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);
int __fastcall sub_00502EF0(int nArg);
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);
int __cdecl sub_004E6FF0_SumProgressiveBonus();
short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc* pItem);
short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc* pItem);
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);
int __stdcall sub_0063A380(D2UnitStrc* pUnit);
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit);
int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill);
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId);
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType);
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
static int sub_004E6FB0_GetETypeColor(int nEType); // 0x004E6FB0
static void __stdcall sub_004E96E0_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight); // 0x004E96E0

struct D2SkillDescTxt
{
    char unk0x0[0x3C];
    short wDescMissile[3];
    unsigned char nDescLine[17];
    char unk0x53[0x1];
    unsigned short wDescTextA[17];
    unsigned short wDescTextB[17];
    int dwDescCalcA[17];
    int dwDescCalcB[17];
};

struct D2MonStatsTxt
{
    char unk0x0[0xAA];
    short nLevel[3];
    char unk0xB0[0xF8];
};

struct D2DataTablesStrc
{
    char unk0x0[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __fastcall sub_0044DCA0_GetGameType(); // 0x0044DCA0
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0

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

// 0x004E9660
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

// 0x004EAD60
void __fastcall sub_004EAD60_DrawWeaponPhysElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = sub_004E6FB0_GetETypeColor(pSkillsTxt->nEType);
    sub_004E9660_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, pSkillsTxt->nSrcDam);
    nMin += SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// build: context sub_004EAE70_DrawPhysWeaponElemDamage
void __fastcall sub_004EAE70_DrawPhysWeaponElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nColor = sub_004E6FB0_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    sub_004E9660_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, nSrcDam);
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }
    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x00483360
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

// 0x004EBB50
void __fastcall sub_004EBB50_DrawKickDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    int nColor = sub_004E6FB0_GetETypeColor(pSkillsTxt->nEType);
    const int nMinPhys = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    const int nMaxPhys = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    const int nBonus = sub_004E6FF0_SumProgressiveBonus();
    int nMin = 0;
    int nMax = 0;
    int nDamagePercent = nBonus;
    SKILLS_CalculateKickDamage(pUnit, &nMin, &nMax, &nDamagePercent);
    nMin += DATATBLS_ApplyRatio(nMin, nDamagePercent, 100) + nMinPhys + DATATBLS_ApplyRatio(nMinPhys, nBonus, 100);
    nMax += DATATBLS_ApplyRatio(nMax, nDamagePercent, 100) + nMaxPhys + DATATBLS_ApplyRatio(nMaxPhys, nBonus, 100);

    const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    nMin += DATATBLS_ApplyRatio(nMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nMax, nPercent, 100);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pOther = 0;
        if (pWeapon)
        {
            int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
            pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
        }

        if (ITEMS_CheckItemTypeId(pWeapon, 45) && sub_0062A4E0_TestItem(pWeapon) && STATLIST_GetOwner(pWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 0);
        }
        else
        {
            pWeapon = 0;
        }

        if (pOther && pOther != pWeapon && ITEMS_CheckItemTypeId(pOther, 45) && sub_0062A4E0_TestItem(pOther) && STATLIST_GetOwner(pOther, 0))
        {
            STATLIST_MergeStatLists(pUnit, pOther, 0);
        }

        sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
        if (pWeapon)
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 1);
        }
    }

    sub_004E96E0_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

static __forceinline int ApplyPercent_2E0(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

static __forceinline int ApplyPercent_CF0(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

static __forceinline int ApplyPercent_150(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

static __forceinline int IsSingleValue(int nMin, int nMax)
{
    if (!nMin)
    {
        return !nMax;
    }
    return nMin == nMax;
}

static __forceinline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
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

static __declspec(noinline) void __stdcall sub_004E6EA0_ApplyFireMastery(int* pMin, int* pMax, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pPlayer, 0x149, 0);
        if (nMastery)
        {
            const int nMin = *pMin;
            *pMin = DATATBLS_ApplyRatio(nMin, nMastery, 100) + nMin;
            const int nMax = *pMax;
            *pMax = DATATBLS_ApplyRatio(nMax, nMastery, 100) + nMax;
        }
    }
}

static __declspec(noinline) void __stdcall sub_004E6F00_ApplyLightningMastery(int* pMin, int* pMax, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pPlayer, 0x14A, 0);
        if (nMastery)
        {
            const int nMin = *pMin;
            *pMin = DATATBLS_ApplyRatio(nMin, nMastery, 100) + nMin;
            const int nMax = *pMax;
            *pMax = DATATBLS_ApplyRatio(nMax, nMastery, 100) + nMax;
        }
    }
}

static void __stdcall sub_004E72D0_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        *pType = 2;
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pType)
    {
        switch (pSkillsTxt->nEType)
        {
        case 1:
            *pType = 1;
            break;
        case 2:
            *pType = 9;
            break;
        case 3:
        case 4:
            *pType = 3;
            break;
        case 5:
            *pType = 2;
            break;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

static int __stdcall sub_004E73E0_FormatValue(Unicode* pDest, int bPlus, int nValue)
{
    char szText[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szText, szFmtPlusD_006DBE90, nValue);
    }
    else
    {
        wsprintfA(szText, gszFormatD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004E7430_FormatDecimal(Unicode* pDest, int bPlus, int nWhole, int nFraction)
{
    char szText[32];
    if (bPlus && nWhole >= 0)
    {
        wsprintfA(szText, szFmtPlusDecimal_006DBE9C, nWhole, nFraction);
    }
    else
    {
        wsprintfA(szText, szFmtDecimal_006DBE94, nWhole, nFraction);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004E79E0_AddValueText(unsigned short nString, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, szFmtPlusD_006DBE90, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E7C30_AddValueTextAfter(unsigned short nString, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, szFmtPlusD_006DBE90, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E7E70_AddValueTwoTexts(unsigned short nString1, unsigned short nString2, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, szFmtPlusD_006DBE90, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E80F0_AddRangeText(Unicode* wszText, int bSeparator, int nMin, int nMax, unsigned short nString, int bPlus)
{
    if (nMin == nMax)
    {
        return sub_004E79E0_AddValueText(nString, bPlus, nMin, wszText);
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus)
    {
        wsprintfA(szNumber, szFmtPlusRange_006DBEA4, nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    if (bSeparator)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    }
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC090
static void __stdcall sub_004EC090_AddSummonLife(Unicode* wszText, int nPercent, int nBonus, int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = &sgptDataTables->pMonStatsTxt[nMonsterId];
    if (!pMonStatsTxt)
    {
        return;
    }

    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    if (!DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxt->nLevel[nDifficulty], 1, &monStatsInit))
    {
        return;
    }

    int nLife = (monStatsInit.nMinHP + monStatsInit.nMaxHP) / 2;
    nLife += nLife * nPercent / 100 + nBonus;
    if (nLife)
    {
        sub_004E79E0_AddValueText(0x10C6, 0, nLife, wszText);
    }
}

static int __stdcall sub_004EC140_AddElemRange(int nElemType, unsigned short nString, int nMax, int nMin, Unicode* wszText)
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

    if (IsSingleValue(nMin, nMax))
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
    }
    else
    {
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004EC220_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return sub_004EC140_AddElemRange(pSkillsTxt->nEType, nString, nMax >> 8, nMin >> 8, wszText);
}

static int __stdcall sub_004EC280_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel)
{
    const int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    const int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    if (!nMin && !nMax)
    {
        return 0;
    }

    return sub_004EC140_AddElemRange(MISSILE_GetElemTypeFromMissileId(nMissileId), nString, nMax, nMin, wszText);
}

// 0x004EC2E0
static int __stdcall sub_004EC2E0_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nPercent, int nSkillLevel)
{
    Unicode wszNumber[32];
    char szNumber[32];
    int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    nMin += ApplyPercent_2E0(nMin, nPercent) + nBonus;
    nMax += ApplyPercent_2E0(nMax, nPercent) + nBonus;
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin != nMax)
    {
        wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
    }
    else if (nMin >= 0)
    {
        wsprintfA(szNumber, szFmtPlusD_006DBE90, nMin);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10A0));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC510
static int sub_004EC510_AddToHit(int nSkillLevel, int nSkillId, D2UnitStrc* pUnit, Unicode* wszText)
{
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (!nToHit)
    {
        return 0;
    }

    return sub_004E7E70_AddValueTwoTexts(0x10A6, 0x10B3, 1, nToHit, wszText);
}

// 0x004EC540
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
        wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
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

static int __stdcall sub_004EC620_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    sub_004E6EA0_ApplyFireMastery(&nMin, &nMax, pSkillsTxt);
    sub_004E6F00_ApplyLightningMastery(&nMin, &nMax, pSkillsTxt);
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
    default:
        nString = 0x10A1;
        break;
    }

    return sub_004EC540_AddElemRatePerSecond(nString, nMinRate, nMaxRate, wszText);
}

static int __stdcall sub_004EC6F0_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return sub_004EC540_AddElemRatePerSecond(0x10A1, nMin, nMax, wszText);
}

static int __stdcall sub_004EC740_AddSkillElemRateByType(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, D2UnitStrc* pUnit, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x19 >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x19 >> 8;
    unsigned short nString;
    switch (pSkillsTxt->nEType)
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
    default:
        nString = 0x10A1;
        break;
    }

    return sub_004EC540_AddElemRatePerSecond(nString, nMin, nMax, wszText);
}

// 0x004EC7E0
static int __stdcall sub_004EC7E0_AddValueLine(unsigned short nStringAfter, int bPlus, int bPercent, int nValue, unsigned short nStringBefore, Unicode* wszText)
{
    if (!nValue)
    {
        return 0;
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, szFmtPlusD_006DBE90, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    if (nStringBefore != 0x1506)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    }
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC900
static int __stdcall sub_004EC900_AddDecimalLine(unsigned short nStringAfter, int bPlus, int bPercent, int nWhole, int nFraction, unsigned short nStringBefore, Unicode* wszText)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nWhole && !nFraction)
    {
        return 0;
    }

    Unicode wszNumber[32];
    sub_004E7430_FormatDecimal(wszNumber, bPlus, nWhole, nFraction);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004ECA00
static int __stdcall sub_004ECA00_AddValueOverTime(unsigned short nStringAfter, int nValue, int bPlus, int nCount, unsigned short nStringBefore, Unicode* wszText)
{
    if (nStringBefore != 0x1506 && nValue && nCount > 0)
    {
    char szNumber[32];
    Unicode wszNumber[32];
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_004E73E0_FormatValue(wszNumber, bPlus, nValue);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
    wsprintfA(szNumber, gszFormatD_006D57BC, nCount);
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
    }

    return 0;
}

// 0x004ECB10
static int sub_004ECB10_AddTextPair(unsigned short nString1, unsigned short nString2, Unicode* wszText)
{
    if (nString1 != 0x1506 && nString2 != 0x1506)
    {
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
    }

    return 0;
}

// 0x004ECB80
static int __stdcall sub_004ECB80_AddValueAfterText(unsigned short nStringAfter, int bPlus, int bPercent, int nValue, unsigned short nStringBefore, Unicode* wszText)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nValue)
    {
        return 0;
    }

    Unicode wszNumber[32];
    sub_004E73E0_FormatValue(wszNumber, bPlus, nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004ECC80
static int __stdcall sub_004ECC80_AddFormattedText(int nValue, unsigned short nString, Unicode* wszText)
{
    if (nString == 0x1506)
    {
        return 0;
    }

    Unicode wszLine[0x100];
    sub_005269D0(0x100, wszLine, D2LANG_GetStringFromTblIndex(nString), nValue);
    sub_00526700(wszText, wszLine);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004ECCF0_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(pSkillsTxt->wSummon, sub_0044DCA0_GetGameType(), sub_0044DCD0_GetDifficulty(), pMonStatsTxt->nLevel[sub_0044DCD0_GetDifficulty()], 8, &monStatsInit);
    int nMin = monStatsInit.nA1MinD;
    int nMax = monStatsInit.nA1MaxD;
    int nPercent = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxt->wAuraStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
    }

    if (nPercent)
    {
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += ApplyPercent_CF0(nMin, nPercent);
        nMax += ApplyPercent_CF0(nMax, nPercent);
    }

    sub_004EC140_AddElemRange(0, 0x10A0, nMax, nMin, wszText);
    return 1;
}

// 0x004ECF50
int __stdcall sub_004ECF50_AddMonsterDamage(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nBonusMin, int nBonusMax)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    const int nMonsterId = sgptDataTables->nMonStatsTxtRecordCount <= 0x124 ? -1 : 0x124;
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxt->nLevel[nDifficulty], 8, &monStatsInit);
    const int nMin = monStatsInit.nA1MinD + nBonusMin;
    const int nMax = monStatsInit.nA1MaxD + nBonusMax;
    const int nElemType = pSkillsTxt->nEType;
    Unicode wszNumber[32];
    char szNumber[32];
    const unsigned short nString = sub_004E6F60_GetElemDamageText(nElemType);
    if (nString)
    {
        if ((nMin || nMax) && nMin != nMax)
        {
            wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
        }
        else
        {
            wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
        }
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

static __forceinline D2SkillsTxt* SkillsTxtRecord_0D0(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int SkillParam_0D0(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxt = SkillsTxtRecord_0D0(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }
    return pSkillsTxt->dwParam[0] + (nLevel - 1) * pSkillsTxt->dwParam[1];
}

// 0x004ED0D0
static int sub_004ED0D0_AddNextLevelParam(int nSkillLevel, int nSkillId, Unicode* wszText)
{
    if (nSkillLevel > 1)
    {
        sub_004E7C30_AddValueTextAfter(0x10D5, 0, SkillParam_0D0(nSkillId, nSkillLevel - 1), wszText);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x110D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

int __stdcall sub_004ED150_AddSummonDamageBonus(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(pSkillsTxt->wSummon, sub_0044DCA0_GetGameType(), sub_0044DCD0_GetDifficulty(), pMonStatsTxt->nLevel[sub_0044DCD0_GetDifficulty()], 8, &monStatsInit);
    int nMin = monStatsInit.nA1MinD;
    int nMax = monStatsInit.nA1MaxD;
    int nPercent = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxt->wAuraStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
        if (pSkillsTxt->wAuraStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
        if (pSkillsTxt->nPassiveStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    if (nPercent)
    {
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += ApplyPercent_150(nMin, nPercent);
        nMax += ApplyPercent_150(nMax, nPercent);
    }

    sub_004EC140_AddElemRange(0, 0x10A0, nMax, nMin, wszText);
    return 1;
}

// 0x004EDB30
static int __stdcall sub_004EDB30_AddSeconds(unsigned short nString, int bPlus, int nFrames, Unicode* wszText)
{
    Unicode wszNumber[32];
    const int nSeconds = nFrames / 25;
    const int nTenths = nFrames % 25 * 10 / 25;
    if (!nSeconds && !nTenths)
    {
        return 0;
    }

    if (nTenths)
    {
        sub_004E7430_FormatDecimal(wszNumber, bPlus, nSeconds, nTenths);
    }
    else
    {
        sub_004E73E0_FormatValue(wszNumber, bPlus, nSeconds);
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nSeconds == 1 && !nTenths ? 0x10AB : 0x10AC));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004EDC40_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId, D2UnitStrc* pUnit)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    if (nLength)
    {
        switch (pSkillsTxt->nEType)
        {
        case 5:
            return sub_004EDB30_AddSeconds(0x10AA, 0, nLength, wszText);
        case 4:
            return sub_004EDB30_AddSeconds(0x10A9, 0, nLength, wszText);
        }
    }
    return 0;
}

static int __stdcall sub_004EDCA0_AddElemDamageOverTime(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    sub_004EDB30_AddSeconds(0x2B0E, 0, nLength, wszText);
    const int nElemType = pSkillsTxt->nEType;
    Unicode wszNumber[32];
    char szNumber[32];
    const unsigned short nString = sub_004E6F60_GetElemDamageText(nElemType);
    if (nString)
    {
        if (IsSingleValue(nMin, nMax))
        {
            wsprintfA(szNumber, gszFormatD_006D57BC, nMin);
        }
        else
        {
            wsprintfA(szNumber, szFmtRange_006D9D70, nMin, nMax);
        }
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

static int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, D2UnitStrc* pUnit)
{
    if (sub_0044DCC0())
    {
        sub_004EDC40_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        sub_004EC220_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        sub_004EC2E0_AddPhysDamage(pUnit, wszText, nSkillId, 0, 0, nSkillLevel);
        sub_004EC510_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    }

    int nMin = 0;
    int nMax = 0;
    int nType;
    sub_004E72D0_GetElemDamage(pUnit, &nMin, &nMax, &nType, pSkillsTxt, nSkillLevel);
    sub_004E80F0_AddRangeText(wszText, 0, nMin, nMax, 0x10A0, 0);
    return 1;
}

int __fastcall sub_D06_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nArg4, int nLine, int nArg5)
{
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    const int nCalcA = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcA[nLine], nSkillId, nSkillLevel);
    const int nCalcB = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcB[nLine], nSkillId, nSkillLevel);
    const unsigned short nStringA = pSkillDescTxt->wDescTextA[nLine];
    const unsigned short nStringB = pSkillDescTxt->wDescTextB[nLine];
    switch (pSkillDescTxt->nDescLine[nLine])
    {
    case 1:
        sub_004EC090_AddSummonLife(wszText, nCalcA, nCalcB, pSkillsTxt->wSummon);
        return 1;
    case 2:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC140_AddElemRange(pSkillsTxt->nEType, nStringA, nCalcB, nCalcA, wszText);
        return 1;
    case 3:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC220_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        return 1;
    case 4:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC220_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 5:
        sub_004EC280_AddMissileElemDamage(pUnit, wszText, nStringA, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        return 1;
    case 6:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC2E0_AddPhysDamage(pUnit, wszText, nSkillId, nCalcB, nCalcA, nSkillLevel);
        return 1;
    case 7:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC510_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    case 8:
        sub_004EC620_AddMissileElemRate(pUnit, wszText, pSkillsTxt, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        return 1;
    case 9:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC6F0_AddSkillElemRate(pUnit, wszText, nSkillId, nSkillLevel);
        return 1;
    case 10:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EC740_AddSkillElemRateByType(wszText, pSkillsTxt, nSkillId, pUnit, nSkillLevel);
        return 1;
    case 11:
        sub_004EC7E0_AddValueLine(nStringB, 1, 1, nCalcA, nStringA, wszText);
        return 1;
    case 12:
        sub_004EC7E0_AddValueLine(nStringB, 1, 0, nCalcA, nStringA, wszText);
        return 1;
    case 13:
        sub_004EC900_AddDecimalLine(nStringB, 1, 0, nCalcA, nCalcB, nStringA, wszText);
        return 1;
    case 14:
        sub_004ECA00_AddValueOverTime(nStringB, nCalcA, 1, nCalcB, nStringA, wszText);
        return 1;
    case 15:
        sub_004ECB10_AddTextPair(nStringA, nStringB, wszText);
        return 1;
    case 16:
        sub_004ECB80_AddValueAfterText(nStringB, 0, 0, nCalcA, nStringA, wszText);
        return 1;
    case 17:
        sub_004ECC80_AddFormattedText(nCalcA, nStringA, wszText);
        return 1;
    case 18:
        sub_004ECCF0_AddSummonDamage(pUnit, wszText, nSkillId, nSkillLevel, pSkillsTxt);
        return 1;
    case 19:
        sub_004ECF50_AddMonsterDamage(wszText, pSkillsTxt, nCalcA, nCalcB);
        return 1;
    case 20:
        sub_004ED0D0_AddNextLevelParam(nSkillLevel, nSkillId, wszText);
        return 1;
    case 21:
        sub_004ED150_AddSummonDamageBonus(pUnit, wszText, nSkillId, pSkillsTxt, nSkillLevel);
        return 1;
    case 22:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EDB30_AddSeconds(nStringA, 0, nCalcA, wszText);
        return 1;
    case 23:
        sub_004EDB30_AddSeconds(nStringA, 1, nCalcA, wszText);
        return 1;
    case 24:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EDC40_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        return 1;
    case 25:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }

        return 1;
    case 26:
        sub_004EDDD0_AddAttackInfo(wszText, nSkillId, pSkillsTxt, nSkillLevel, pUnit);
        return 1;
    case 27:
        sub_004E7E70_AddValueTwoTexts(nStringA, nStringB, 1, nCalcA, wszText);
        return 1;
    case 28:
        sub_004E79E0_AddValueText(nStringA, 1, nCalcA, wszText);
        return 1;
    case 29:
        sub_004E7C30_AddValueTextAfter(nStringA, 1, nCalcA, wszText);
        return 1;
    case 30:
        sub_004E80F0_AddRangeText(wszText, 1, nCalcA, nCalcB, nStringA, 1);
        return 1;
    }
    return 0;
}
