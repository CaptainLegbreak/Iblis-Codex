extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2MagicAffixTxt
{
    char pad0x00[0x24];
    D2PropertyStrc pProperties[3];
};

struct D2GradeModsStrc
{
    char pad0x00[0xC];
    D2PropertyStrc pProperties[12];
};

struct D2GemsTxt
{
    char pad0x00[0x30];
    D2PropertyStrc pProperties[3][3];
};

struct D2UniqueItemsTxt
{
    char pad0x00[0x8C];
    D2PropertyStrc pProperties[12];
};

struct D2SetItemsTxt
{
    char pad0x00[0x2C];
    short nSetId;
    char pad0x2E[0x59];
    unsigned char nAddFunc;
    D2PropertyStrc pProperties[9];
    D2PropertyStrc pPartialBoni[10];
};

struct D2SetsTxt
{
    char pad0x00[0x0C];
    int nSetItems;
    D2PropertyStrc pBoni2[8];
    D2PropertyStrc pFBoni[8];
};

struct D2DataTablesStrc
{
    char pad0x00[0xAC];
    int nPropertiesTxtRecordCount;
};

typedef int (__fastcall* ITEMMODS_PROPERTYFN)(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatlist, D2UnitStrc* a9);

struct D2PropertyAssignStrc
{
    ITEMMODS_PROPERTYFN pfAssign;
    int nStatId;
};

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
D2UniqueItemsTxt* __fastcall sub_00483470(int nUniqueItemId);                           // 0x00483470
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId);                                            // 0x00483410
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem);                                                // 0x0065E4D0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2PropertyAssignStrc gtPropertyAssignTable_00745B58[];                                               // 0x00745B58
extern const int gnSetItemsCount_006EDA40[];                                                                // 0x006EDA40
extern const int gnSetItemStates_006EDB40[];                                                                // 0x006EDB40
extern const int gnSetItemStatlistFlags_006EDB5C[];                                                         // 0x006EDB5C

static const D2PropertyStrc* sub_0065C660_GetAffixProperty(const D2MagicAffixTxt* pMods, int nMod)
{
    D2_ASSERT(pMods, 0x79);
    if ((unsigned int)nMod < 3)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x7A);
    return 0;
}

static const D2PropertyStrc* sub_0065C6A0_GetGradeProperty(const D2GradeModsStrc* pMods, int nMod)
{
    if ((unsigned int)nMod < 12)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x81);
    return 0;
}

static const D2PropertyStrc* sub_0065C6D0_GetGemProperty(const D2GemsTxt* pMods, int nPropSet, int nMod)
{
    const D2PropertyStrc* pProperties[3];
    pProperties[0] = pMods->pProperties[0];
    pProperties[1] = pMods->pProperties[1];
    pProperties[2] = pMods->pProperties[2];
    D2_ASSERT((unsigned int)nPropSet < 3, 0x8F);
    if ((unsigned int)nMod < 3)
    {
        return &pProperties[nPropSet][nMod];
    }

    D2_ASSERT(0, 0x90);
    return 0;
}

static const D2PropertyStrc* sub_0065C730_GetModsProperty(int nType, const void* pMods, int nPropSet, int nMod)
{
    switch (nType)
    {
    case 0:
        return sub_0065C660_GetAffixProperty((const D2MagicAffixTxt*)pMods, nMod);
    case 1:
        return sub_0065C6A0_GetGradeProperty((const D2GradeModsStrc*)pMods, nMod);
    case 2:
        return sub_0065C6D0_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 5:
        return sub_0065C6D0_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 3:
    case 4:
        return 0;
    case 6:
    case 7:
        return (const D2PropertyStrc*)pMods;
    default:
        D2_ASSERT(0, 0xAF);
        return 0;
    }
}

// 0x0065FE10
static void __stdcall sub_0065FE10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a11)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2COMMON_11292_ItemAssignProperty(nType, pUnit, pItem, pMods, nIndex, nPropSet, pProperty, nState, fStatlist, a11);
    }
    else
    {
        D2_ASSERT(pProperty, 0x66D);

        const int nProperty = pProperty->nProperty;
        if (nProperty != -1 && nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
        {
            ITEMMODS_PROPERTYFN pfAssign = gtPropertyAssignTable_00745B58[nProperty].pfAssign;
            if (pfAssign)
            {
                pfAssign(nType, pUnit, pItem, pProperty, gtPropertyAssignTable_00745B58[nProperty].nStatId, nApplyType, nState, fStatlist, a11);
            }
        }
    }
}

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType)
{
    int nProperties = 0;
    switch (nType)
    {
    case 0:
    case 2:
    case 5:
        nProperties = 3;
        break;

    case 1:
        nProperties = 2;
        break;

    case 3:
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxtRecord)
            {
                for (int i = 0; i < 12; ++i)
                {
                    sub_0065FE10(3, 0, pItem, 0, 0, 0, nApplyType, &pUniqueItemsTxtRecord->pProperties[i], 0, 0x40, 0);
                }
                return;
            }
        }
        break;

    case 4:
    {
        D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (!pSetItemsTxtRecord)
        {
            return;
        }

        if (!ITEMS_GetItemFormat(pItem))
        {
            for (int i = 0; i < 2; ++i)
            {
                sub_0065FE10(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pProperties[i], 0, 0x40, 0);
            }
            return;
        }

        for (int i = 0; i < 9; ++i)
        {
            sub_0065FE10(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pProperties[i], 0, 0x40, 0);
        }

        for (int i = 0; i < 10; ++i)
        {
            int nState;
            int nFlag;
            if (pSetItemsTxtRecord->nAddFunc)
            {
                nFlag = gnSetItemStatlistFlags_006EDB5C[i / 2 + 2];
                nState = gnSetItemStates_006EDB40[i / 2 + 2];
            }
            else
            {
                nState = 0;
                nFlag = 0x40;
            }

            sub_0065FE10(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pPartialBoni[i], nState, nFlag, 0);
        }
        return;
    }
    }

    for (int nMod = 0; nMod < nProperties; ++nMod)
    {
        const D2PropertyStrc* pProperty = sub_0065C730_GetModsProperty(nType, pMods, nPropSet, nMod);
        if (!pProperty || pProperty->nProperty < 0)
        {
            break;
        }

        sub_0065FE10(nType, 0, pItem, pMods, nMod, nPropSet, nApplyType, pProperty, 0, 0x40, a2);
    }
}

// 0x00660120
void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState)
{
    if (!nState)
    {
        return;
    }

    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType == 4 && ITEMS_GetItemQuality(pItem) == 5)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxtRecord)
        {
            D2SetsTxt* pSetsTxtRecord = sub_00483410_GetSetsTxtRecord(pSetItemsTxtRecord->nSetId);
            if (pSetsTxtRecord)
            {
                const unsigned int nMask = ITEMS_GetSetItemsMask(pUnit, pItem, 1);
                int nItems;
                if (nMask >= 0x40)
                {
                    nItems = 0;
                }
                else
                {
                    nItems = gnSetItemsCount_006EDA40[nMask];
                }

                const int nCount = nItems < pSetsTxtRecord->nSetItems - 1 ? nItems : pSetsTxtRecord->nSetItems - 1;
                for (int i = 0; i < 2 * (nCount - 1); ++i)
                {
                    const D2PropertyStrc* pProperty = &pSetsTxtRecord->pBoni2[i];
                    if (pProperty->nProperty >= 0)
                    {
                        sub_0065FE10(4, pUnit, pItem, 0, i, 0, 0, pProperty, nState, 0, 0);
                    }
                }

                if (nItems >= pSetsTxtRecord->nSetItems)
                {
                    for (int i = 0; i < 8; ++i)
                    {
                        const D2PropertyStrc* pProperty = &pSetsTxtRecord->pFBoni[i];
                        if (pProperty->nProperty < 0)
                        {
                            break;
                        }

                        sub_0065FE10(4, pUnit, pItem, 0, i, 0, 0, pProperty, nState, 0, 0);
                    }
                }
            }
        }
    }
}

// 0x00660240
void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc* pItem, D2PropertyStrc* pProperty, int nUnused)
{
    if (pItem)
    {
        sub_0065FE10(7, 0, pItem, pProperty, 0, 0, 0, pProperty, 0, 0x40, 0);
        if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x858, ".\\ITEMS\\ItemMods.cpp"))
        {
            ITEMMODS_ApplyEthereality(pItem);
        }
    }
}

#include "gen/data/Source/D2Common/0065FE10_sub_0065FE10.inc"
