struct D2UnitStrc
{
    int dwUnitType;
};

struct D2ItemTypesTxt
{
    char szCode[4];
    short nEquiv1;
    short nEquiv2;
    unsigned char nRepair;
    unsigned char nBody;
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    short wShoots;
    short wQuiver;
    unsigned char nThrowable;
    unsigned char nReload;
    unsigned char nReEquip;
    unsigned char nAutoStack;
    char unk0x14[0xD0];
};

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    char unk0xC8[0xB30];
    D2ItemTypesTxt* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit);                           // 0x00625BB0
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit);                        // 0x00625BE0

#define UNIT_ITEM 4

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x0062E6F0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->wShoots;
        }
    }

    return 0;
}

// 0x0062E740
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->wQuiver;
        }
    }

    return 0;
}

// 0x0062E790
unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->nAutoStack;
        }
    }

    return 0;
}

// 0x0062E7E0
unsigned int __stdcall ITEMS_GetReload(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->nReload;
        }
    }

    return 0;
}

// 0x00639E90
int __stdcall STATES_CheckGfxStateFlag(D2UnitStrc* pUnit, int nState)
{
    unsigned int* pGfxFlags = 0;

    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
        if (pGfxFlags)
        {
            return pGfxFlags[nState >> 5] & gdwBitMasks[nState & 31];
        }
    }

    return 0;
}

// 0x00639EE0
void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);

    if (pGfxFlags)
    {
        memset(pGfxFlags, 0x00, sizeof(unsigned int) * ((sgptDataTables->nStatesTxtRecordCount + 31) / 32));
    }
}

// 0x00639F20
int __stdcall STATES_IsAnyGfxStateFlagSet(D2UnitStrc* pUnit)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);

    if (pGfxFlags)
    {
        for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
        {
            if (pGfxFlags[i])
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00639F70
unsigned int* __stdcall STATES_GetGfxStateFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 153);

    return D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
}

// 0x0063A100
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit)
{
    return D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);
}
