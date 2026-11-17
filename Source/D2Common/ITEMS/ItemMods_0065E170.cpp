struct D2StatListStrc;
struct D2SeedStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

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

static D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter);
__declspec(noinline) static D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter);
// 0x0065CBF0
static D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter)
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

struct D2DataTablesStrc
{
    char unk_000[0xBA0];
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

// 0x0065E170
int __fastcall sub_0065E170_AddSingleSkillStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nPropertyId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (!pProperty)
    {
        return 0;
    }

    int nValue;
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    if (nMin == nMax)
    {
        nValue = nMin;
    }
    else
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls;
        if (ITEMS_GetItemFormat(pItem) < 1)
        {
            nPossibleRolls = nMax - nMin;
        }
        else
        {
            nPossibleRolls = nMax - nMin + 1;
        }

        nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    if (nApplyType)
    {
        nValue = -sub_006254E0_GetStatValue(pStatList, 107, nSkillId);
    }

    STATLIST_AddStat(pStatList, 107, nValue, nSkillId);
    return 1;
}
