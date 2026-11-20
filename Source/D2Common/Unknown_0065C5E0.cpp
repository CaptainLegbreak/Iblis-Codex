#include "D2Common.h"
#include "D2Structs.h"
struct D2SeedStrc;
struct D2InventoryStrc;
struct sub_M415_EmitArgs;
struct D2PropertyStrc;
struct D2MagicAffixTxt;
struct D2GradeModsStrc;
struct D2GemsTxt;


D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct sub_M415_EmitArgs
{
    int nPad0;
    int nPad4;
    int nPad8;
    int nMin;
    int nMax;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

void __stdcall sub_C01_EmitSink(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a11);

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0xC6C - 0xBA4];
    int nStuff;
    int nShiftedStuff;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag); // 0x00625730
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627220

// 0x0065C5E0
static __forceinline int sub_0065C5E0_RollItemRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
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
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

// 0x0065C620
static __forceinline int sub_0065C620_RollItemRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
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
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

int __stdcall sub_M415_EmitRoll_0065C5E0(D2UnitStrc* pItem, sub_M415_EmitArgs* pArgs, int nBias)
{
    return sub_0065C5E0_RollItemRange(pItem, pArgs->nMin, pArgs->nMax) + nBias;
}

int __stdcall sub_M415_EmitRoll_0065C620(D2UnitStrc* pItem, sub_M415_EmitArgs* pArgs, int nBias)
{
    return sub_0065C620_RollItemRange(pItem, pArgs->nMin, pArgs->nMax) + nBias;
}

// 0x0065C660
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

// 0x0065C6A0
static const D2PropertyStrc* sub_0065C6A0_GetGradeProperty(const D2GradeModsStrc* pMods, int nMod)
{
    if ((unsigned int)nMod < 12)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x81);
    return 0;
}

// 0x0065C6D0
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

// 0x0065C730
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

// build: context sub_C01_Emit_0065C730
void __stdcall sub_C01_Emit_0065C730(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType, int nProperties)
{
    for (int nMod = 0; nMod < nProperties; ++nMod)
    {
        const D2PropertyStrc* pProperty = sub_0065C730_GetModsProperty(nType, pMods, nPropSet, nMod);
        if (!pProperty || pProperty->nProperty < 0)
        {
            break;
        }

        sub_C01_EmitSink(nType, 0, pItem, pMods, nMod, nPropSet, nApplyType, pProperty, 0, 0x40, a2);
    }
}

// 0x0065C820
int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pValue, D2StatListStrc** ppStatList)
{
    if (pValue)
    {
        *pValue = 0;
    }

    if (ppStatList)
    {
        *ppStatList = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType != 4)
    {
        return 0;
    }

    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || nSkillLevel <= 0 || nSkillLevel > 63)
    {
        return 0;
    }

    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        const int nValue = STATLIST_GetStatValue(pStatList, 204, nLayer);
        if (nValue)
        {
            if (pValue)
            {
                *pValue = nValue & 0xFF;
            }

            if (ppStatList)
            {
                *ppStatList = pStatList;
            }

            return 1;
        }
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (ITEMMODS_GetItemCharges(pSocketed, nSkillId, nSkillLevel, pValue, ppStatList))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x0065C940
int __stdcall ITEMMODS_UpdateItemWithSkillCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType != 4)
    {
        return 0;
    }

    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        int nValue = STATLIST_GetStatValue(pStatList, 204, nLayer);
        if (nValue)
        {
            nValue >>= 8;
            if (nValue > 0 && nValue <= 255)
            {
                nCharges = nCharges > 0 ? nCharges : 0;
                if (nCharges >= nValue)
                {
                    nCharges = nValue;
                }
                STATLIST_SetBaseStat2(pStatList, 204, (nValue << 8) + (nCharges & 0xFF), nLayer, pItem);
                return 1;
            }
            return 0;
        }
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (ITEMMODS_UpdateItemWithSkillCharges(pSocketed, nSkillId, nSkillLevel, nCharges))
            {
                return 1;
            }
        }
    }

    return 0;
}
