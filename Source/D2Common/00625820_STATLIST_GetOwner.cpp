struct D2UnitStrc;
struct D2StatStrc;

struct D2ModStatsArrayStrc
{
    void* pStat;
    unsigned short nStatCount;
    unsigned short nCapacity;
};

struct D2StatListStrc
{
    void* pMemPool;
    D2UnitStrc* pUnit;
    unsigned int dwOwnerType;
    unsigned int dwOwnerId;
    unsigned int dwFlags;
    unsigned int dwStateNo;
    int dwExpireFrame;
    char unk0x1C[16];
    D2StatListStrc* pPrevLink;
    D2StatListStrc* pNextLink;
    D2StatListStrc* pParent;
    void* fpStatRemove;
    D2StatListStrc* pMyLastList;
    D2StatListStrc* pMyStats;
    D2UnitStrc* pOwner;
    char unk0x48[8];
    D2ModStatsArrayStrc ModStats;
    unsigned int* StatFlags;
};

struct D2UnitStrc
{
    char unk0x00[92];
    D2StatListStrc* pStatListEx;
};

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pItem;
};

struct D2DataTablesStrc
{
    char unk0x00[0x98];
    char* pItemsCode;
    unsigned int nItemsCodeSize;
    char unk0xA0[0x24];
    int nStatesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern void* gpItemsCalcFunctions[];                                                                        // 0x0074463C
extern int gnItemsCalcFunctions;                                                                            // 0x0074465C
int __fastcall sub_00626200_GetStatFromLayer(D2StatListStrc* pStatListEx, int nLayer_StatId);               // 0x00626200
int __fastcall ITEMMODS_GetCalcParamValue_Return0(int nParam, void* pUserData);                             // 0x00627B40
int __stdcall DATATBLS_CalcEvaluateExpression(char* pCode, unsigned int nSize, int (__fastcall* pfParam)(int, void*), void** pFuncs, int nFuncs, void* pUserData); // 0x006C0BC0

#define STATLIST_DYNAMIC 0x40000000
#define STATLIST_EXTENDED 0x80000000

// 0x00625820
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic)
{
    if (!pUnit)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    D2StatListStrc* pParent = pStatListEx->pParent;
    if (!pParent)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    if (!(pParent->dwFlags & STATLIST_EXTENDED))
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    if (pStatNotDynamic)
        *pStatNotDynamic = !(pStatListEx->dwFlags & STATLIST_DYNAMIC);

    return pParent->pOwner;
}

// 0x00625B70
int __stdcall sub_00625B70_CheckStatFlag(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return 0;

    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return pStatListEx->StatFlags[nState >> 5] & gdwBitMasks[nState & 31];
}

// 0x00625BB0
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;

    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return pStatListEx->StatFlags;
}

// 0x00625BE0
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;

    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return &pStatListEx->StatFlags[(sgptDataTables->nStatesTxtRecordCount + 31) / 32];
}

// 0x00627830
int __stdcall sub_00627830_GetStatAccumulated(D2UnitStrc* pUnit, int nStatId)
{
    D2StatListStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return sub_00626200_GetStatFromLayer(pStatListEx, nStatId << 16);
}

// 0x00627C20
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc)
{
    if (!sgptDataTables->pItemsCode)
        return 0;

    if (nCalc >= sgptDataTables->nItemsCodeSize)
        return 0;

    D2ItemCalcStrc pItemCalc;
    pItemCalc.pUnit = pUnit;
    pItemCalc.pItem = pItem;
    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pItemsCode[nCalc], sgptDataTables->nItemsCodeSize - nCalc, ITEMMODS_GetCalcParamValue_Return0, gpItemsCalcFunctions, gnItemsCalcFunctions, &pItemCalc);
}

#include "gen/data/Source/D2Common/00625820_STATLIST_GetOwner.inc"
