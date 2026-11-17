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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70
extern "C" const char szFmtRangeKK_006DBEAC[];                                                              // 0x006DBEAC
extern "C" const char szFmtRangeK_006DBEB8[];                                                               // 0x006DBEB8
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);              // 0x00526320
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20

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
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall ITEMS_GetMissileType(D2UnitStrc*); // 0x006288A0
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc*); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc*); // 0x006298A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80
int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0
D2UnitStrc* __stdcall sub_0063BEF0(D2InventoryStrc*); // 0x0063BEF0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc*,D2UnitStrc*,D2SkillStrc*,int); // 0x00645830
int __stdcall MISSILE_GetMinDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064AFF0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B1D0

// 0x004EA4A0
void __fastcall sub_004EA4A0_WeaponDamageCallback2(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    *pMin=0;
    *pMax=0;
    if (!pSkill) return;
    if (!pItem) {
        if (!pUnit->pInventory) return;
        pItem=sub_0063BEF0(pUnit->pInventory);
        if (!pItem) return;
    }
    if (!ITEMS_CheckIfThrowable(pItem)) return;
    if (ITEMS_CheckItemTypeId(pItem,38)) {
        int nMissile=ITEMS_GetMissileType(pItem);
        *pColor=0;
        int nMin=MISSILE_GetMinDamage(0,pUnit,nMissile,1);
        nMin+=MISSILE_GetMinElemDamage(0,pUnit,nMissile,1);
        int nMax=MISSILE_GetMaxDamage(0,pUnit,nMissile,1);
        nMax+=MISSILE_GetMaxElemDamage(0,pUnit,nMissile,1);
        switch (MISSILE_GetElemTypeFromMissileId(nMissile)) {
        case 5: {
            *pColor=2;
            int nLength=sub_0064B2A0_GetMissileElementLength(0,pUnit,nMissile,1)/25;
            if(nLength<=0)nLength=1;
            nMin/=nLength;
            nMax/=nLength;
            break;
        }
        case 4: *pColor=3; break;
        case 1: *pColor=1; break;
        case 2: *pColor=4; break;
        }
        nMin>>=8;
        nMax>>=8;
        if(nMax<=nMin)nMax=nMin;
        *pMin=nMin;
        *pMax=nMax;
        return;
    }
    int nStatBonus=0;
    int nFactor=ITEMS_GetStrengthBonus(pItem);
    if(nFactor)nStatBonus=STATLIST_UnitGetStatValue(pUnit,0,0)*nFactor/100;
    nFactor=ITEMS_GetDexBonus(pItem);
    if(nFactor)nStatBonus+=STATLIST_UnitGetStatValue(pUnit,2,0)*nFactor/100;
    *pMin=STATLIST_UnitGetStatValue(pUnit,159,0);
    *pMax=STATLIST_UnitGetStatValue(pUnit,160,0);
    nStatBonus+=STATLIST_UnitGetStatValue(pUnit,25,0);
    int nMinPercent=STATLIST_UnitGetStatValue(pUnit,18,0);
    int nMaxPercent=STATLIST_UnitGetStatValue(pUnit,17,0);
    if(nStatBonus<=-90)nStatBonus=-90;
    *pMin+=*pMin*(nMinPercent+nStatBonus)/100;
    *pMax+=*pMax*(nMaxPercent+nStatBonus)/100;
    int nSkillBonus=nBonus;
    if(STATES_CheckState(pUnit,78))nSkillBonus+=SKILLS_GetWeaponMasteryBonus(pUnit,pItem,pSkill,1);
    *pMin+=DATATBLS_ApplyRatio(*pMin,nSkillBonus,100);
    *pMax+=DATATBLS_ApplyRatio(*pMax,nSkillBonus,100);
    if(*pMax<*pMin)*pMax=*pMin;
    {
        int nElemMin=0;
        int nElemMax=0;
        sub_004E89A0(pUnit,&nElemMin,&nElemMax,pColor,pSkill);
        if(nElemMax<nElemMin)nElemMax=nElemMin;
        *pMin+=nElemMin;
        *pMax+=nElemMax;
    }
}

// build: context sub_I05_ETypeColor
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

// build: context sub_004E72D0_GetElemDamage
static __declspec(noinline) void __stdcall sub_004E72D0_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel);

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
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_007A285C + gnGlobal_00711470 + nY - 480, gnGlobal_007A2858 + nRight, wszText, nColor);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004EAAA0
void __fastcall sub_004EAAA0_DrawCallbackElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nElemMin;
    int nElemMax;
    int nElemColor;
    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    sub_004EA4A0_WeaponDamageCallback2(pUnit, &nMin, &nMax, &nColor, 0, 0, pSkill, 0, 0);
    nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 128);
    nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 128);

    nElemMin = 0;
    nElemMax = 0;
    nElemColor = 0;
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

    UnicodeChar wszText1[32];
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
