#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct Unicode
{
    unsigned short ch;
    Unicode() : ch(0)
    {
    }

    static Unicode* __fastcall strcat(Unicode* dest, const Unicode* src);   // 0x00526700
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);   // 0x00526F20
};


struct D2ItemStatCostTxt
{
    char unk0x00[0x144];
};


extern D2DataTablesStrc* sgptDataTables;   // 0x00744304
extern D2UnitStrc* gdwGlobal_007BCBF4;   // 0x007BCBF4
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);   // 0x004521C0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);   // 0x00483360
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);   // 0x00524A30
extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);   // 0x005267E0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);   // 0x0061C100
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);   // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);   // 0x00625480
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);   // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);   // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);   // 0x00627910
int __stdcall sub_00626020_GetUnitDefense(D2UnitStrc* pUnit);

// 0x00485EE0
void __stdcall sub_00485EE0_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText)
{
    if (!pUnit)
    {
        return;
    }

    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);

    int nStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(gdwGlobal_007BCBF4, &nStatNotDynamic);
    const int bHasOwner = pOwner != 0;
    if (pOwner && pUnit != pOwner)
    {
        pUnit = pOwner;
    }

    STATLIST_MergeStatLists(pUnit, gdwGlobal_007BCBF4, 1);
    int nDefense = sub_00626020_GetUnitDefense(gdwGlobal_007BCBF4);
    if (!bHasOwner)
    {
        STATLIST_ExpireUnitStatlist(pUnit, gdwGlobal_007BCBF4);
    }
    else
    {
        STATLIST_MergeStatLists(pOwner, gdwGlobal_007BCBF4, nStatNotDynamic);
    }

    int bModified = 0;
    if (STATLIST_GetUnitBaseStat(pItem, 0x1F, 0) != nDefense)
    {
        bModified = 1;
    }

    int nByTime = STATLIST_UnitGetStatValue(pItem, 0x10C, 0);
    if (nByTime && 0x10C < sgptDataTables->nItemStatCostTxtRecordCount && &sgptDataTables->pItemStatCostTxt[0x10C] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nAdd = ITEMMODS_GetByTimeAdjustment(nByTime, nPeriod, nBaseTime, 0, 0, 0);
        nDefense += nAdd;
        if (nAdd)
        {
            bModified = 1;
        }
    }

    nByTime = STATLIST_UnitGetStatValue(pItem, 0x10D, 0);
    if (nByTime && 0x10D < sgptDataTables->nItemStatCostTxtRecordCount && &sgptDataTables->pItemStatCostTxt[0x10D] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nPercent = ITEMMODS_GetByTimeAdjustment(nByTime, nPeriod, nBaseTime, 0, 0, 0);
        nDefense += DATATBLS_ApplyRatio(nDefense, nPercent, 100);
        if (nPercent)
        {
            bModified = 1;
        }
    }

    sub_005267E0((unsigned short*)pText, (const unsigned short*)D2LANG_GetStringFromTblIndex(0xD85));
    Unicode::strcat(pText, pColorStart);
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nDefense);
    Unicode::win2Unicode(wszNumber, szNumber, 9);
    if (bModified)
    {
        sub_004521C0_PrefixLevelText(wszNumber, 3);
    }

    Unicode::strcat(pText, wszNumber);
    Unicode::strcat(pText, pColorEnd);
}
