struct D2UnitStrc;
struct D2StatListStrc;

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2PropertiesTxt
{
    unsigned short wProp;
    unsigned char nSet[7];
    char unk0x09;
    unsigned short wVal[7];
    unsigned char nFunc[7];
    char unk0x1F;
    unsigned short wStat[7];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA4];
    D2PropertiesTxt* pPropertiesTxt;
    char unk0x0A8[0x04];
    int nPropertiesTxtRecordCount;
    char unk0x0B0[0xAF0];
    int nSkillsTxtRecordCount;
};

struct D2MagicAffixTxt
{
    char unk0x00[0x24];
    D2PropertyStrc pProperties[3];
    char unk0x54[0x16];
    short wIType[7];
    short wEType[5];
};

struct D2RareAffixTxt
{
    char unk0x00[0x0E];
    unsigned short wVersion;
    short wIType[7];
    short wEType[4];
};

struct D2QualityItemsTxt
{
    unsigned char nArmor;
    unsigned char nWeapon;
    unsigned char nShield;
    unsigned char nScepter;
    unsigned char nWand;
    unsigned char nStaff;
    unsigned char nBow;
    unsigned char nBoots;
    unsigned char nGloves;
    unsigned char nBelt;
};

struct D2ItemTypeCheckStrc
{
    unsigned char bItemType;
    int nItemType;
};

struct D2RunesTxt
{
    char unk0x00[0xB0];
    D2PropertyStrc pProperties[7];
};

typedef int(__fastcall* PROPERTYASSIGNFN)(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern int gnPropertyFunctionCount;                                                                          // 0x00745B54
extern PROPERTYASSIGNFN gpfPropertyFunctions[];                                                              // 0x007462F8

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                           // 0x006289F0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
void __stdcall ITEMS_SetSockets(D2UnitStrc* pItem, int nSockets);                                           // 0x0062BE00
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem);                             // 0x0062BED0
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax);                      // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50
int __fastcall ITEMMODS_PropertyFunc05(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065ECF0
int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065EE80

inline const D2PropertiesTxt* DATATBLS_GetPropertiesTxtRecord(int nProperty)
{
    if (nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
    {
        return &sgptDataTables->pPropertiesTxt[nProperty];
    }

    return 0;
}

// 0x0065D220
int __fastcall sub_6FD93170(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(pProperty, 786);

    ITEMS_SetItemFlag(pItem, 0x800, 1);
    ITEMS_SetSockets(pItem, pProperty->nLayer);

    return 1;
}

// 0x0065E4D0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1798);

    ITEMS_SetItemFlag(pItem, 0x400000, 1);

    if (ITEMS_CheckItemTypeId(pItem, 45))
    {
        STATLIST_SetUnitStat(pItem, 21, 3 * STATLIST_GetUnitBaseStat(pItem, 21, 0) / 2, 0);
        STATLIST_SetUnitStat(pItem, 22, 3 * STATLIST_GetUnitBaseStat(pItem, 22, 0) / 2, 0);
        STATLIST_SetUnitStat(pItem, 23, 3 * STATLIST_GetUnitBaseStat(pItem, 23, 0) / 2, 0);
        STATLIST_SetUnitStat(pItem, 24, 3 * STATLIST_GetUnitBaseStat(pItem, 24, 0) / 2, 0);
        STATLIST_SetUnitStat(pItem, 159, 3 * STATLIST_GetUnitBaseStat(pItem, 159, 0) / 2, 0);
        STATLIST_SetUnitStat(pItem, 160, 3 * STATLIST_GetUnitBaseStat(pItem, 160, 0) / 2, 0);
    }
    else
    {
        STATLIST_SetUnitStat(pItem, 31, 3 * STATLIST_GetUnitBaseStat(pItem, 31, 0) / 2, 0);
    }
}

// 0x0065E620
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc* pItem, const D2MagicAffixTxt* pMagicAffixTxtRecord)
{
    if (ITEMS_GetItemFormat(pItem) < 100 && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem)))
    {
        return 0;
    }

    if (!(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0))
    {
        const int nProperty = pMagicAffixTxtRecord->pProperties[0].nProperty;
        if (nProperty >= 0)
        {
            const D2PropertiesTxt* pPropertiesTxtRecord = DATATBLS_GetPropertiesTxtRecord(nProperty);
            if (!pPropertiesTxtRecord || pPropertiesTxtRecord->wStat[0] == 194)
            {
                return 0;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pMagicAffixTxtRecord->wEType[i] <= 0)
        {
            break;
        }

        if (ITEMS_CheckItemTypeId(pItem, pMagicAffixTxtRecord->wEType[i]))
        {
            return 0;
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        if (pMagicAffixTxtRecord->wIType[i] <= 0)
        {
            break;
        }

        if (ITEMS_CheckItemTypeId(pItem, pMagicAffixTxtRecord->wIType[i]))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0065E710
int __stdcall ITEMMODS_CanItemHaveRareAffix(D2UnitStrc* pItem, const D2RareAffixTxt* pRareAffixTxtRecord)
{
    if (ITEMS_GetItemFormat(pItem) < 100 && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem)))
    {
        return 0;
    }

    if (pRareAffixTxtRecord->wVersion >= 100 && ITEMS_GetItemFormat(pItem) < 100)
    {
        return 0;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (pRareAffixTxtRecord->wEType[i] <= 0)
        {
            break;
        }

        if (ITEMS_CheckItemTypeId(pItem, pRareAffixTxtRecord->wEType[i]))
        {
            return 0;
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        if (pRareAffixTxtRecord->wIType[i] <= 0)
        {
            break;
        }

        if (ITEMS_CheckItemTypeId(pItem, pRareAffixTxtRecord->wIType[i]))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0065E7D0
int __stdcall ITEMMODS_CanItemBeHighQuality(D2UnitStrc* pItem, const D2QualityItemsTxt* pQualityItemsTxtRecord)
{
    D2ItemTypeCheckStrc pItemTypeCheck[9] =
    {
        { pQualityItemsTxtRecord->nShield, 2 },
        { pQualityItemsTxtRecord->nScepter, 24 },
        { pQualityItemsTxtRecord->nWand, 25 },
        { pQualityItemsTxtRecord->nStaff, 26 },
        { pQualityItemsTxtRecord->nBow, 27 },
        { pQualityItemsTxtRecord->nBow, 35 },
        { pQualityItemsTxtRecord->nBoots, 15 },
        { pQualityItemsTxtRecord->nGloves, 16 },
        { pQualityItemsTxtRecord->nBelt, 19 },
    };

    const int nItemType = ITEMS_GetItemType(pItem);

    if (pQualityItemsTxtRecord->nWeapon && ITEMS_CheckItemTypeId(pItem, 45) && nItemType != 26 && nItemType != 27 && nItemType != 35 && nItemType != 24 && nItemType != 25)
    {
        return 1;
    }

    if (pQualityItemsTxtRecord->nArmor && ITEMS_CheckItemTypeId(pItem, 50) && nItemType != 2 && nItemType != 15 && nItemType != 16 && nItemType != 19)
    {
        return 1;
    }

    for (unsigned int i = 0; i < sizeof(pItemTypeCheck) / sizeof(pItemTypeCheck[0]); ++i)
    {
        if (nItemType == pItemTypeCheck[i].nItemType && pItemTypeCheck[i].bItemType)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0065F2B0
int __fastcall ITEMMODS_PropertyFunc08(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065F310
int __fastcall ITEMMODS_PropertyFunc09(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (!nMin)
        {
            return 0;
        }
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nSkillId, nMin, nState);
    }

    return 0;
}

// 0x0065F3F0
int __fastcall ITEMMODS_PropertyFunc10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (!nMin)
        {
            return 0;
        }
    }

    const int nSkillLayer = pProperty->nLayer % 3 + 8 * (pProperty->nLayer / 3);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nSkillLayer, nMin, nState);
}

// 0x0065F960
int __fastcall ITEMMODS_PropertyFunc15(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = pProperty->nMin;
    if (nStatId == 21)
    {
        ITEMMODS_PropertyFunc05(nType, pUnit, pItem, pProperty, nSet, 21, 0, nMin, nState, fStatList, a11);
    }
    else
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
    }

    return nMin;
}

// 0x0065F9D0
int __fastcall ITEMMODS_PropertyFunc16(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMax = pProperty->nMax;
    if (nStatId == 22)
    {
        ITEMMODS_PropertyFunc06(nType, pUnit, pItem, pProperty, nSet, 22, 0, nMax, nState, fStatList, a11);
    }
    else
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMax, nState);
    }

    return nMax;
}

// 0x0065FA40
int __fastcall ITEMMODS_PropertyFunc17(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nTemp = pProperty->nLayer;
    if (!nTemp)
    {
        nTemp = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (!nTemp)
        {
            return 0;
        }
    }

    if (nStatId == 22)
    {
        ITEMMODS_PropertyFunc06(nType, pUnit, pItem, pProperty, nSet, 22, 0, nTemp, nState, fStatList, a11);
    }
    else
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nTemp, nState);
    }

    return nTemp;
}

// 0x0065FB50
int __fastcall ITEMMODS_PropertyFunc21(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nLayer, nMin, nState);
}

// 0x0065FBA0
int __fastcall ITEMMODS_PropertyFunc36(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nMin, (short)nLayer, nState);
}

// 0x0065FBF0
int __fastcall ITEMMODS_PropertyFunc22(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, (unsigned short)pProperty->nLayer, nMin, nState);
}

// 0x0065FC40
int __fastcall ITEMMODS_PropertyFunc12(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nMin, pProperty->nLayer, nState);
}

// 0x0065FD70
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10)
{
    if (pProperty)
    {
        const D2PropertiesTxt* pPropertiesTxtRecord = DATATBLS_GetPropertiesTxtRecord(pProperty->nProperty);
        if (pPropertiesTxtRecord)
        {
            int nFirstValue = 0;
            for (int i = 0; i < 7; ++i)
            {
                if (pPropertiesTxtRecord->nFunc[i] >= gnPropertyFunctionCount)
                {
                    break;
                }

                PROPERTYASSIGNFN pfAssign = gpfPropertyFunctions[pPropertiesTxtRecord->nFunc[i]];
                if (!pfAssign)
                {
                    break;
                }

                const int nResult = pfAssign(nType, pUnit, pItem, pProperty, pPropertiesTxtRecord->nSet[i], pPropertiesTxtRecord->wStat[i], pPropertiesTxtRecord->wVal[i], nFirstValue, nState, fStatlist, a10);
                if (!i)
                {
                    nFirstValue = nResult;
                }
            }
        }
    }
}

#include "gen/data/Source/D2Common/0065D220_sub_6FD93170.inc"
