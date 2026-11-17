extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct D2StatListStrc;
struct D2SeedStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ItemStatCostTxt
{
    char unk0x000[0x144];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C3E0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer);  // 0x00627030
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall sub_006254E0_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);     // 0x006254E0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x0065CBF0
static __declspec(noinline) D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter)
{
    D2StatListStrc* pStatList;

    if (pUnit)
    {
        pStatList = sub_00625790_UnitFindStatList(pUnit, nState, fFilter);
        if (!pStatList)
        {
            int nUnitGUID = pUnit->dwUnitId;
            void* pMemPool = pUnit->pMemoryPool;
            pStatList = STATLIST_AllocStatList(pMemPool, fFilter, 0, 4, nUnitGUID);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATLIST_SetState(pStatList, nState);
        }
    }
    else
    {
        pStatList = sub_00625790_UnitFindStatList(pItem, nState, fFilter);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, fFilter, 0, 4, !pItem ? -1 : pItem->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            STATLIST_SetState(pStatList, nState);
        }
    }

    D2_ASSERT(pStatList, 513);
    return pStatList;
}

static __declspec(noinline) void sub_0065CE40_ShiftStatValue(int nStatId, int* pValue);

// 0x0065CE40
static void sub_0065CE40_ShiftStatValue(int nStatId, int* pValue)
{
    switch (nStatId)
    {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 216:
    case 217:
        *pValue <<= 8;
        break;
    case 57:
    case 58:
        break;
    default:
        return;
    }
}

// 0x0065E070
int __fastcall sub_6FD94AB0(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{

    const int nMinValue = (nStatId == (int)pProperty) ? pProperty->nMin : pProperty->nMin;
    int nMin = nMinValue;
    const int nMaxValue = pProperty->nMax;
    int nLayer = pProperty->nLayer;
    int nMax = nStatId ? nMaxValue : nMaxValue;
    _ReadWriteBarrier();
    const int nStatId1 = nStatId + 1;
    const int nStatId2 = nStatId + 2;
    sub_0065CE40_ShiftStatValue(nStatId, &nMin);
    sub_0065CE40_ShiftStatValue(nStatId1, &nMax);
    sub_0065CE40_ShiftStatValue(nStatId2, &nLayer);

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 1197);
    if (nApplyType)
    {
        nMin = -STATLIST_GetStatValue(pStatList, nStatId, 0);
        nMax = -STATLIST_GetStatValue(pStatList, nStatId1, 0);
        nLayer = -STATLIST_GetStatValue(pStatList, nStatId2, 0);
    }
    STATLIST_AddStat(pStatList, nStatId, nMin, 0);
    STATLIST_AddStat(pStatList, nStatId1, nMax, 0);
    STATLIST_AddStat(pStatList, nStatId2, nLayer, 0);
    if (nStatId == 57)
    {
        STATLIST_AddStat(pStatList, 326, 1, 0);
    }
    return 1;
}
