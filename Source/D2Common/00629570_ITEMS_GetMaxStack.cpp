struct D2ItemsTxt
{
    char unk0x00[128];
    unsigned int dwCode;
    char unk0x84[4];
    unsigned int dwUberCode;
    unsigned int dwUltraCode;
    char unk0x90[84];
    unsigned int dwMinStack;
    unsigned int dwMaxStack;
    unsigned int dwSpawnStack;
    char unk0xF0[46];
    short wType[2];
    char unk0x122[8];
    unsigned char nQuest;
    char unk0x12B[14];
    unsigned char nTransmogrify;
    char unk0x13A[4];
    unsigned char nGemApplyType;
    char unk0x13F[105];
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
struct D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                       // 0x006335F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType);                                    // 0x00629A90

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00629570
int __stdcall ITEMS_GetMaxStack(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3407);

    return pItemsTxtRecord->dwMaxStack;
}

// 0x00629620
int __stdcall ITEMS_GetSpawnStackFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3436);

    return pItemsTxtRecord->dwSpawnStack;
}

// 0x006296B0
int __stdcall ITEMS_GetMinStackFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3466);

    return pItemsTxtRecord->dwMinStack;
}

// 0x00629A00
int __stdcall ITEMS_GetGemApplyTypeFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3880);

    return pItemsTxtRecord->nGemApplyType;
}

// 0x0062A060
unsigned int __stdcall ITEMS_GetTransmogrifyFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4437);

    return pItemsTxtRecord->nTransmogrify != 0;
}

// 0x0062B4D0
int __stdcall ITEMS_GetQuestFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    if (!ITEMS_CheckItemTypeIdByItemId(nItemId, 50) && !ITEMS_CheckItemTypeIdByItemId(nItemId, 45))
    {
        return 0;
    }

    if (pItemsTxtRecord->dwUberCode != pItemsTxtRecord->dwCode && pItemsTxtRecord->dwUltraCode != pItemsTxtRecord->dwCode)
    {
        return 0;
    }

    struct D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pRecord, 1677);
    if (pRecord->wType[0] == 38)
    {
        return 0;
    }

    return !pItemsTxtRecord->nQuest;
}

// 0x006295B0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3418);
    D2_ASSERT(pItem->dwUnitType == 4, 3419);

    int nMaxStack = ITEMS_GetMaxStack(pItem->dwClassId) + STATLIST_UnitGetStatValue(pItem, 254, 0);
    if (nMaxStack >= 511)
    {
        nMaxStack = 511;
    }

    return nMaxStack;
}

// 0x00629660
int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3451);
    D2_ASSERT(pItem->dwUnitType == 4, 3452);

    return ITEMS_GetSpawnStackFromItemId(pItem->dwClassId);
}

// 0x006296F0
int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3475);
    D2_ASSERT(pItem->dwUnitType == 4, 3476);

    return ITEMS_GetMinStackFromItemId(pItem->dwClassId);
}

// 0x00629A40
int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3901);
    D2_ASSERT(pItem->dwUnitType == 4, 3902);

    return ITEMS_GetGemApplyTypeFromItemId(pItem->dwClassId);
}

// 0x0062A0A0
unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4450);
    D2_ASSERT(pItem->dwUnitType == 4, 4451);

    return ITEMS_GetTransmogrifyFromItemId(pItem->dwClassId);
}

// 0x0062B560
int __stdcall ITEMS_GetQuest(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1932);
    D2_ASSERT(pItem->dwUnitType == 4, 1933);

    return ITEMS_GetQuestFromItemId(pItem->dwClassId);
}
