#include "D2Client.h"

struct Unicode
{
    unsigned short ch;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2UnitStrc
{
    char unk0x00[0x1C];
    D2DrlgActStrc* pDrlgAct;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x144];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0xBD4 - 0xBD0];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

static __declspec(noinline) void __stdcall sub_00485240_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified);

// 0x00485240
static void __stdcall sub_00485240_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified)
{
    *pnMin = 1;
    *pnMax = 2;
    if (!pUnit || !pItem)
        return;
    int nStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(gpOwnerSource_007BCBF4, &nStatNotDynamic);
    const int bOwner = pOwner != 0;
    if (pOwner && pOwner != pUnit)
        pUnit = pOwner;
    STATLIST_MergeStatLists(pUnit, pItem, 1);
    const int nMin = STATLIST_UnitGetStatValue(pItem, nStatMin, 0);
    int nMax = STATLIST_UnitGetStatValue(pItem, nStatMax, 0);
    if (!bOwner)
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    else
        STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
    const int nBaseMin = STATLIST_GetUnitBaseStat(pItem, nStatMin, 0);
    const int nBaseMax = STATLIST_GetUnitBaseStat(pItem, nStatMax, 0);
    if (nBaseMin < nMin || nBaseMax < nMax)
        *pbModified = 1;
    if (nMax <= nMin)
        nMax = nMin;
    const int nByTimeMax = STATLIST_UnitGetStatValue(pItem, 0x110, 0);
    if (nByTimeMax && sgptDataTables->nItemStatCostTxtRecordCount > 0x110 && &sgptDataTables->pItemStatCostTxt[0x110] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nAdd = ITEMMODS_GetByTimeAdjustment(nByTimeMax, nPeriod, nBaseTime, 0, 0, 0);
        nMax += nAdd;
        if (nAdd)
            *pbModified = 1;
    }
    const int nByTimePct = STATLIST_UnitGetStatValue(pItem, 0x111, 0);
    if (nByTimePct && sgptDataTables->nItemStatCostTxtRecordCount > 0x111 && &sgptDataTables->pItemStatCostTxt[0x111] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nPct = ITEMMODS_GetByTimeAdjustment(nByTimePct, nPeriod, nBaseTime, 0, 0, 0);
        nMax += DATATBLS_ApplyRatio(nMax, nPct, 100);
        if (nPct)
            *pbModified = 1;
    }
    *pnMin = nMin;
    *pnMax = nMax;
}

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSrc);                                    // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSrc);                                    // 0x005267E0
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
void __fastcall sub_004521C0_SetTextColor(Unicode* pText, int nColor);                                     // 0x004521C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625560
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem);                                                      // 0x006288A0
int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                              // 0x006289C0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem);                                   // 0x0062A1E0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);   // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);   // 0x0064AFF0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId);                                   // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);  // 0x0064B2A0

// 0x00485410
void __stdcall sub_00485410_BuildItemDamageText(D2UnitStrc* pItem, Unicode* pBuffer)
{
    Unicode wszValue[256];
    char szValue[256];
    int bModified;
    int nMax;
    int nMin;

    for (int i = 0; i < sizeof(wszValue) / sizeof(wszValue[0]); ++i)
        wszValue[i].ch = 0;
    const Unicode* wszSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    D2UnitStrc* pPlayer = sub_00463DD0();

    if (ITEMS_CheckItemTypeId(pItem, 0x26))
    {
        int nElemMin;
        nMin = ITEMS_GetMissileType(pItem);
        Unicode wszText[256];
        for (int i = 0; i < sizeof(wszText) / sizeof(wszText[0]); ++i)
            wszText[i].ch = 0;
        int nColor = 0;
        nElemMin = MISSILE_GetMinElemDamage(0, pPlayer, nMin, 1);
        nMax = MISSILE_GetMaxElemDamage(0, pPlayer, nMin, 1);
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);

        switch (MISSILE_GetElemTypeFromMissileId(nMin))
        {
        case 5:
        {
            nColor = 2;
            int nLength = sub_0064B2A0(0, pPlayer, nMin, 1) / 25;
            if (nLength <= 0)
                nLength = 1;
            nElemMin /= nLength;
            nMax /= nLength;
            break;
        }
        case 4:
            nColor = 3;
            break;
        case 1:
            nColor = 1;
            break;
        case 2:
            nColor = 4;
            break;
        }

        nElemMin += MISSILE_GetMinDamage(0, pPlayer, nMin, 1);
        int nElemMax = nMax + MISSILE_GetMaxDamage(0, pPlayer, nMin, 1);
        nElemMin >>= 8;
        nElemMax >>= 8;
        if (nElemMax <= nElemMin)
            nElemMax = nElemMin;

        SStrPrintf(szValue, sizeof(szValue), "%i", nElemMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        if (nElemMin != nElemMax)
        {
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
            SStrPrintf(szValue, sizeof(szValue), "%i", nElemMax);
            sub_00526F20(wszValue, szValue, 9);
            sub_004521C0_SetTextColor(wszValue, nColor);
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, wszValue);
        }
        sub_00526700(wszText, wszNewLine);
        sub_005267E0(pBuffer, wszText);
        return;
    }

    bModified = 0;
    if (ITEMS_Is1Or2Handed(pPlayer, pItem))
    {
        Unicode wszTwoHand[128];
        Unicode wszOneHand[128];

        sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszTwoHand) / sizeof(wszTwoHand[0]); ++i)
            wszTwoHand[i].ch = 0;
        sub_005267E0(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD8A));
        sub_00526700(wszTwoHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszNewLine);

        sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszOneHand) / sizeof(wszOneHand[0]); ++i)
            wszOneHand[i].ch = 0;
        sub_005267E0(wszOneHand, D2LANG_GetStringFromTblIndex(0xD89));
        sub_00526700(wszOneHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszNewLine);

        sub_004521C0_SetTextColor(wszTwoHand, 0);
        sub_004521C0_SetTextColor(wszOneHand, 0);
        sub_005267E0(pBuffer, wszTwoHand);
        sub_00526700(pBuffer, wszOneHand);
    }
    else
    {
        unsigned short nString;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
            nString = 0xD8A;
        }
        else
        {
            sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
            nString = 0xD89;
        }
        if (nMax <= nMin + 1)
            nMax = nMin + 1;

        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(nString));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszNewLine);
    }

    bModified = 0;
    if (STATLIST_GetUnitStatBonus(pItem, 0x12, 0) || STATLIST_GetUnitStatBonus(pItem, 0x11, 0)
        || STATLIST_GetUnitStatBonus(pItem, 0x9F, 0) || STATLIST_GetUnitStatBonus(pItem, 0xA0, 0))
        bModified = 1;

    if (ITEMS_CheckIfThrowable(pItem))
    {
        Unicode wszText[256];
        for (int i = 0; i < sizeof(wszText) / sizeof(wszText[0]); ++i)
            wszText[i].ch = 0;
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);
        sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x9F, 0xA0, &nMin, &nMax, &bModified);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        const int nColor = bModified ? 3 : 0;
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszNewLine);
        sub_00526700(pBuffer, wszText);
    }
}
