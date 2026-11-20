#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
struct D2PropertyStrc;
struct D2PropertiesTxt;
struct D2MagicAffixTxt;
struct D2RareAffixTxt;
struct D2QualityItemsTxt;
struct D2ItemTypeCheckStrc;
struct D2RunesTxt;
struct D2GradeModsStrc;
struct D2GemsTxt;
struct D2UniqueItemsTxt;
struct D2SetItemsTxt;
struct D2PropertyAssignStrc;


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


struct D2MagicAffixTxt
{
    char unk0x00[0x24];
    D2PropertyStrc pProperties[3];
    char unk0x54[0x16];
    short wIType[7];
    short wEType[5];
    unsigned char unk_82[0x2];
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

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gnPropertyFunctionCount; // 0x00745B54
extern PROPERTYASSIGNFN gpfPropertyFunctions[]; // 0x007462F8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
unsigned char __stdcall sub_0062BC20(D2UnitStrc* pItem); // 0x0062BC20
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BE00
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax); // 0x0065E9E0
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50
int __fastcall ITEMMODS_PropertyFunc05(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065ECF0
int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065EE80

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



struct D2SetsTxt
{
    char pad0x00[0x0C];
    int nSetItems;
    D2PropertyStrc pBoni2[8];
    D2PropertyStrc pFBoni[8];
};

typedef int (__fastcall* ITEMMODS_PROPERTYFN)(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatlist, D2UnitStrc* a9);

struct D2PropertyAssignStrc
{
    ITEMMODS_PROPERTYFN pfAssign;
    int nStatId;
};

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nUniqueItemId); // 0x00483470
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex); // 0x00483440
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem); // 0x0065E4D0
extern D2PropertyAssignStrc gtPropertyAssignTable_00745B58[]; // 0x00745B58

int __fastcall ITEMMODS_PropertyFunc08(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc09(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc15(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc16(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc17(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc21(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc36(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc22(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);
int __fastcall ITEMMODS_PropertyFunc12(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

inline const D2PropertiesTxt* DATATBLS_GetPropertiesTxtRecord(int nProperty)
{
    if (nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
    {
        return &sgptDataTables->pPropertiesTxt[nProperty];
    }

    return 0;
}

// 0x0065D220
int __fastcall sub_6FD93170(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 786);

    ITEMS_SetItemFlag(pItem, 0x800, 1);
    ITEMS_AddSockets(pItem, ptProperty->nLayer);

    return 1;
}

// 0x0065E4D0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1798);

    ITEMS_SetItemFlag(hItem, 0x400000, 1);

    if (ITEMSIsA(hItem, 45))
    {
        STATLIST_SetUnitStat(hItem, 21, 3 * STATLIST_GetUnitBaseStat(hItem, 21, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, 22, 3 * STATLIST_GetUnitBaseStat(hItem, 22, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, 23, 3 * STATLIST_GetUnitBaseStat(hItem, 23, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, 24, 3 * STATLIST_GetUnitBaseStat(hItem, 24, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, 159, 3 * STATLIST_GetUnitBaseStat(hItem, 159, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, 160, 3 * STATLIST_GetUnitBaseStat(hItem, 160, 0) / 2, 0);
    }
    else
    {
        STATLIST_SetUnitStat(hItem, 31, 3 * STATLIST_GetUnitBaseStat(hItem, 31, 0) / 2, 0);
    }
}

// 0x0065E620
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc* pItem, const D2MagicAffixTxt* pMagicAffixTxtRecord)
{
    if (ITEMS_GetItemFormat(pItem) < 100 && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem)))
    {
        return 0;
    }

    if (!(ITEMS_CheckIfSocketable(pItem) && sub_0062BC20(pItem) > 0))
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

        if (ITEMSIsA(pItem, pMagicAffixTxtRecord->wEType[i]))
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

        if (ITEMSIsA(pItem, pMagicAffixTxtRecord->wIType[i]))
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

        if (ITEMSIsA(pItem, pRareAffixTxtRecord->wEType[i]))
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

        if (ITEMSIsA(pItem, pRareAffixTxtRecord->wIType[i]))
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

    if (pQualityItemsTxtRecord->nWeapon && ITEMSIsA(pItem, 45) && nItemType != 26 && nItemType != 27 && nItemType != 35 && nItemType != 24 && nItemType != 25)
    {
        return 1;
    }

    if (pQualityItemsTxtRecord->nArmor && ITEMSIsA(pItem, 50) && nItemType != 2 && nItemType != 15 && nItemType != 16 && nItemType != 19)
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

#include "gen/data/Source/D2Common/ITEMS/ItemMods_0065D220.inc"

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
static void __stdcall sub_0065FE10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* ptProperty, int nState, int fStatlist, D2UnitStrc* a11)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2COMMON_11292_ItemAssignProperty(nType, pUnit, pItem, pMods, nIndex, nPropSet, ptProperty, nState, fStatlist, a11);
    }
    else
    {
        D2_ASSERT(ptProperty, 0x66D);

        const int nProperty = ptProperty->nProperty;
        if (nProperty != -1 && nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
        {
            ITEMMODS_PROPERTYFN pfAssign = gtPropertyAssignTable_00745B58[nProperty].pfAssign;
            if (pfAssign)
            {
                pfAssign(nType, pUnit, pItem, ptProperty, gtPropertyAssignTable_00745B58[nProperty].nStatId, nApplyType, nState, fStatlist, a11);
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
            D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
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
