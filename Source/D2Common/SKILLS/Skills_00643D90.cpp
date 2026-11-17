#include "D2Common.h"
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2InventoryStrc;
struct D2SkillsTxt;
struct D2SkillListStrc;

typedef int BOOL;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char nCharClass;
    unsigned char unk_0D[0x3];
    signed char nAnim;
    signed char nMonAnim;
    unsigned char unk_12[0x6];
    short nITypeA[3];
    short nITypeB[3];
    short nETypeA[2];
    char unk0x028[0x06];
    short wSrvDoFunc;
    char unk0x030[0x154];
    short wStartMana;
    short unk0x186;
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    short unk0x18E;
    unsigned int dwDelay;
    char unk0x194[0x48];
    unsigned char nEType;
    char unk0x1DD[0x4B];
    unsigned char nRestrict;
    char unk0x229;
    short nState[3];
    char unk0x230[0x0C];
};

struct D2SkillDescTxt
{
    char unk0x00[2];
    char nSkillPage;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    int dwSkillMode;
    char unk0x0C[0x28 - 0x0C];
    int nSkillLevel;
    int nLevelBonus;
    int nQuantity;
    int nOwnerGUID;
    int nCharges;
    int dwFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x44];
    D2SkillListStrc* pSkills;
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400
int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit); // 0x0063A510
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit); // 0x00644150
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill || !pSkill->pSkillsTxt)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;

    int nSkillId = pSkillsTxtRecord->nSkillId;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    int nSkillLevel = pSkill->nLevelBonus;
    nSkillLevel += SKILLS_GetShrineSkillLevelBonus(pUnit);
    nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 127, 0);

    if (pUnit && pUnit->dwUnitType == 0)
    {
        if (pSkillsTxtRecord->nCharClass == pUnit->dwClassId)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 83, pUnit->dwClassId);

            D2SkillDescTxt* pSkillDescTxtRecord = sub_004A89D0(nSkillId);
            if (pSkillDescTxtRecord->nSkillPage)
            {
                nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 188, pSkillDescTxtRecord->nSkillPage + 8 * pUnit->dwClassId - 1);
            }

            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus > 3)
            {
                nBonus = 3;
            }
            nSkillLevel += nBonus;
        }
        else
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
    }
    else
    {
        if (pSkill->nSkillLevel <= 0)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
        else
        {
            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus)
            {
                if (nBonus > 3)
                {
                    nBonus = 3;
                }
                nSkillLevel += nBonus;
            }
        }
    }

    if (pSkillsTxtRecord->nEType > 0)
    {
        nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 126, pSkillsTxtRecord->nEType);
    }

    return nSkillLevel + STATLIST_UnitGetStatValue(pUnit, 107, nSkillId);
}

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus)
{
    int nSkillLevel = 0;
    int nMaxLevel = 0;

    if (pUnit && pSkill)
    {
        nSkillLevel = pSkill->nSkillLevel;
        if (bBonus && pSkill->nOwnerGUID == -1)
        {
            nSkillLevel += SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }

        nSkillLevel = D2_MAX(nSkillLevel, 0);
        return D2_MIN(nSkillLevel, DATATBLS_GetMaxLevel(0));
    }

    return 0;
}

static __declspec(noinline) D2UnitStrc* __stdcall sub_6FDB1050(int nBodyLoc, D2InventoryStrc* pInventory)
{
    if (nBodyLoc == 5)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    }

    return INVENTORY_GetItemFromBodyLoc(pInventory, 5);
}

// 0x00643D90
static __declspec(noinline) BOOL __stdcall sub_6FDB1130(D2UnitStrc* pItem, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nType)
{
    if (!pItem)
    {
        if (pSkillsTxtRecord->nETypeA[2 * nType] <= 0 && pSkillsTxtRecord->nITypeA[3 * nType] <= 0)
        {
            return TRUE;
        }

        if ((pSkillsTxtRecord->nITypeA[0] == 0x2D || pSkillsTxtRecord->nITypeA[0] == 0x2E || pSkillsTxtRecord->nITypeA[0] == 0x43)
            && pSkillsTxtRecord->nITypeB[0] <= 0 && !ITEMS_CheckItemTypeId(0, 0x2D) && !ITEMS_CheckItemTypeId(pUnit, 0x2D))
        {
            return TRUE;
        }

        if (pSkillsTxtRecord->nITypeA[0] == 0x43 && pSkillsTxtRecord->nITypeB[0] <= 0 && !ITEMS_CheckItemTypeId(0, 0x2D) && !ITEMS_CheckItemTypeId(pUnit, 0x2D))
        {
            return TRUE;
        }

        return FALSE;
    }

    int i = 0;
    short* pEType = &pSkillsTxtRecord->nETypeA[2 * nType];
    for (; i < 2; ++i)
    {
        if (*pEType <= 0)
        {
            break;
        }

        if (ITEMS_CheckItemTypeId(pItem, *pEType))
        {
            return FALSE;
        }

        ++pEType;
    }

    i = 0;
    short* pIType = &pSkillsTxtRecord->nITypeA[3 * nType];
    for (; i < 3; ++i)
    {
        if (*pIType <= 0)
        {
            return i == 0;
        }

        if (ITEMS_CheckItemTypeId(pItem, *pIType))
        {
            if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x810, ".\\SKILLS\\Skills.cpp") || ITEMS_CheckItemFlag(pItem, 0x100, 0x811, ".\\SKILLS\\Skills.cpp"))
            {
                return pSkillsTxtRecord->nSkillId == 0;
            }

            if (ITEMS_GetAmmoType(pItem))
            {
                if (SKILLS_HasFlag(pSkillsTxtRecord, 16))
                {
                    return TRUE;
                }

                if (!pSkillsTxtRecord->nSkillId && STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x9D, 0))
                {
                    return TRUE;
                }

                if (!pUnit || !ITEMS_CheckItemTypeId(pUnit, ITEMS_GetAmmoType(pItem)))
                {
                    return FALSE;
                }

                if (!pSkillsTxtRecord->nSkillId && STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x9D, 0))
                {
                    return TRUE;
                }

                if (!ITEMS_GetTotalMaxStack(pUnit))
                {
                    return TRUE;
                }

                if (STATLIST_UnitGetStatValue(pUnit, 0x46, 0) <= 0)
                {
                    return FALSE;
                }
            }

            return TRUE;
        }

        ++pIType;
    }

    return FALSE;
}

static __declspec(noinline) BOOL __stdcall sub_00643F80_CheckWeaponTypes(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return FALSE;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;
    if (!pSkillsTxtRecord)
    {
        return FALSE;
    }

    if (pSkillsTxtRecord->nETypeA[0] <= 0 && pSkillsTxtRecord->nITypeA[0] <= 0)
    {
        return 1;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return FALSE;
    }

    D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pSkillsTxtRecord->nSkillId == 4 || pSkillsTxtRecord->nSkillId == 5)
    {
        D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pInventory);
        if (pItem == pRightHandItem)
        {
            pRightHandItem = 0;
        }
        else if (pItem == pLeftHandItem)
        {
            pLeftHandItem = 0;
        }
    }

    if (sub_6FDB1130(pRightHandItem, pLeftHandItem, pSkillsTxtRecord, 0))
    {
        return sub_6FDB1130(pLeftHandItem, pRightHandItem, pSkillsTxtRecord, 1);
    }

    if (sub_6FDB1130(pRightHandItem, pLeftHandItem, pSkillsTxtRecord, 1))
    {
        return sub_6FDB1130(pLeftHandItem, pRightHandItem, pSkillsTxtRecord, 0);
    }

    return FALSE;
}

static __declspec(noinline) BOOL D2Common_SKILLS_CheckShapeRestriction_6FDB1380(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
    {
        return FALSE;
    }

    D2SkillsTxt* pSkillsTxt = pSkill->pSkillsTxt;
    if (!pSkillsTxt)
    {
        return FALSE;
    }

    switch (pSkillsTxt->nRestrict)
    {
    case 0:
        return !STATES_CheckStateMaskRestrictOnUnit(pUnit);

    case 1:
        return TRUE;

    case 2:
        break;

    default:
        return TRUE;
    }

    if (!STATES_CheckStateMaskRestrictOnUnit(pUnit))
    {
        return FALSE;
    }

    for (int i = 0; i < 3; ++i)
    {
        const int nState = pSkillsTxt->nState[i];
        if (nState < 0)
        {
            return FALSE;
        }

        if (STATES_CheckState(pUnit, nState))
        {
            return TRUE;
        }
    }

    return FALSE;
}

static __declspec(noinline) BOOL D2Common_SKILLMANA_CheckStartStat_6FDB1400(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || pUnit->dwUnitType != 0 || pSkill->pSkillsTxt->wStartMana <= 0
        || STATLIST_UnitGetStatValue(pUnit, 8, 0) >= (int)pSkill->pSkillsTxt->wStartMana << 8 || STATES_CheckState(pUnit, 0xC))
    {
        return 1;
    }

    return FALSE;
}

static __declspec(noinline) BOOL D2Common_SKILLMANA_CheckStat_6FDB0F50(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2_ASSERT(pSkill, 0x637);

    if (pSkill->nOwnerGUID != -1)
    {
        return pSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxt = pSkill->pSkillsTxt;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1) - 1;
    D2_ASSERT(pSkillsTxt, 0x6EE);
    if (nSkillLevel < 0)
    {
        nSkillLevel = 0;
    }

    const int nRequiredMana = (pSkillsTxt->wMana + nSkillLevel * pSkillsTxt->wLevelMana) << pSkillsTxt->nManaShift;
    if (STATES_CheckState(pUnit, 0x72))
    {
        return STATLIST_UnitGetStatValue(pUnit, 6, 0) >= nRequiredMana;
    }

    if (pSkillsTxt->wSrvDoFunc == 0x74 && STATES_IsUnitShapeShifted(pUnit))
    {
        return 1;
    }

    return STATLIST_UnitGetStatValue(pUnit, 8, 0) >= nRequiredMana;
}

// build: context sub_00647640_CheckSkillQuantity
static __declspec(noinline) BOOL sub_00647640_CheckSkillQuantity(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2UnitStrc* pItem;
    int nBodyLoc;
    BOOL bIsLeftHandItem;
    BOOL bContinue;

    if (!pUnit || !pSkill)
    {
        return FALSE;
    }

    D2SkillsTxt* pSkillsTxt = pSkill->pSkillsTxt;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pSkillsTxt && SKILLS_HasFlag(pSkillsTxt, 36))
    {
        BOOL bResult = FALSE;
        if (pInventory)
        {
            bResult = pSkill->nQuantity > 0;
        }

        return bResult;
    }

    switch (pSkillsTxt->nSkillId)
    {
    case 2:
        bContinue = FALSE;
        if (!pInventory)
        {
            return FALSE;
        }

        if (UNITS_CanDualWield(pUnit))
        {
            if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem))
            {
                if (!bIsLeftHandItem)
                {
                    pItem = sub_6FDB1050(nBodyLoc, pInventory);
                }

                if (pItem)
                {
                    bContinue = ITEMS_CheckIfThrowable(pItem);
                    if (!bContinue)
                    {
                        bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0);
                    }
                }
            }
        }
        else
        {
            if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem) && bIsLeftHandItem)
            {
                bContinue = ITEMS_CheckIfThrowable(pItem);
                if (!bContinue)
                {
                    bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0);
                }
            }
        }

        return bContinue;

    case 4:
        bContinue = FALSE;
        if (!pInventory)
        {
            return FALSE;
        }

        if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem))
        {
            if (bIsLeftHandItem)
            {
                D2UnitStrc* pOtherItem = sub_6FDB1050(nBodyLoc, pInventory);
                if (pOtherItem)
                {
                    bContinue = ITEMS_CheckIfThrowable(pOtherItem);
                    if (!bContinue)
                    {
                        bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pOtherItem, 0x7D, 0);
                    }
                }
            }
            else
            {
                bContinue = ITEMS_CheckIfThrowable(pItem);
                if (!bContinue)
                {
                    bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0);
                }
            }
        }

        return bContinue;

    case 5:
        if (!pInventory || !UNITS_CanDualWield(pUnit))
        {
            return FALSE;
        }

        bContinue = FALSE;
        if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem))
        {
            if (bIsLeftHandItem)
            {
                D2UnitStrc* pOtherItem = sub_6FDB1050(nBodyLoc, pInventory);
                if (pOtherItem)
                {
                    bContinue = ITEMS_CheckItemTypeId(pOtherItem, 0x2D);
                }
            }
            else
            {
                bContinue = ITEMS_CheckItemTypeId(pItem, 0x2D);
            }
        }

        return bContinue;
    }

    return 1;
}

static __declspec(noinline) BOOL sub_6FDB1070(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
    {
        return FALSE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 1;
    }

    if (pSkill->nOwnerGUID == -1)
    {
        return 1;
    }

    const int nSkillId = pSkill->pSkillsTxt->nSkillId;
    const int nLayer = (nSkillId << 6) + (SKILLS_GetSkillLevel(pUnit, pSkill, FALSE) & 0x3F);
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pChargedItem = INVENTORY_UnitIsItem(pItem);
        if (pChargedItem && pChargedItem->dwUnitId == pSkill->nOwnerGUID)
        {
            return (STATLIST_UnitGetStatValue(pChargedItem, 0xCC, nLayer) & 0xFF) > 0;
        }
    }

    return 1;
}

static __declspec(noinline) BOOL __stdcall SKILLS_CheckSkillDelay(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != 0 || !STATES_CheckState(pUnit, 0x79))
    {
        return 1;
    }

    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxt = pSkill->pSkillsTxt;
    if (!pSkillsTxt)
    {
        return 1;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwDelay, nSkillId, SKILLS_GetSkillLevel(pUnit, pSkill, 1)) <= 0;
}

int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2_ASSERT(pSkill, 0x8E9);

    if (!pSkill->pSkillsTxt || !SKILLS_HasFlag(pSkill->pSkillsTxt, 10))
    {
        return 3;
    }

    if (!SKILLS_GetSkillLevel(pUnit, pSkill, 1))
    {
        return 7;
    }

    if (SKILLS_HasFlag(pSkill->pSkillsTxt, 5))
    {
        return 6;
    }

    if (SKILLS_HasFlag(pSkill->pSkillsTxt, 4))
    {
        return 5;
    }

    if (!sub_00647640_CheckSkillQuantity(pUnit, pSkill))
    {
        return 2;
    }

    if (!sub_00643F80_CheckWeaponTypes(pUnit, pSkill))
    {
        return 2;
    }

    if (!D2Common_SKILLMANA_CheckStat_6FDB0F50(pUnit, pSkill))
    {
        return 1;
    }

    if (!D2Common_SKILLS_CheckShapeRestriction_6FDB1380(pUnit, pSkill))
    {
        return 4;
    }

    if (!D2Common_SKILLMANA_CheckStartStat_6FDB1400(pUnit, pSkill))
    {
        return 1;
    }

    if (!sub_6FDB1070(pUnit, pSkill))
    {
        return 2;
    }

    return SKILLS_CheckSkillDelay(pSkill, pUnit) ? 0 : 8;
}

// 0x00646000
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

// 0x00646010
void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

// 0x006460C0
void __stdcall sub_006460C0_Empty(int nUnused)
{
}

// 0x006460D0
void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

// 0x006460E0
void __stdcall sub_006460E0_Empty(int nUnused)
{
}

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline void SKILLS_RemoveChargedSkill(D2UnitStrc* pUnit, D2SkillListStrc* pSkillList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nOwnerGUID)
{
    D2SkillStrc* pLeftSkill = pSkillList->pLeftSkill;
    D2SkillStrc* pRightSkill = pSkillList->pRightSkill;
    const int nRightSkillId = pRightSkill->pSkillsTxt->nSkillId;
    const int nLeftSkillId = pLeftSkill->pSkillsTxt->nSkillId;
    if (nSkillId == nLeftSkillId && pLeftSkill->nOwnerGUID == nOwnerGUID)
    {
        SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    }

    if (nSkillId == nRightSkillId && pRightSkill->nOwnerGUID == nOwnerGUID)
    {
        SKILLS_SetRightActiveSkill(pUnit, 0, -1);
    }

    if (pSkillList->pUsedSkill && nSkillId == pSkillList->pUsedSkill->pSkillsTxt->nSkillId)
    {
        pSkillList->pUsedSkill = 0;
    }

    D2SkillStrc* pPreviousSkill = 0;
    D2SkillStrc* pSkill = pSkillList->pFirstSkill;
    while (pSkill && (pSkill->nOwnerGUID != nOwnerGUID || pSkill->pSkillsTxt != pSkillsTxtRecord))
    {
        pPreviousSkill = pSkill;
        pSkill = pSkill->pNextSkill;
    }

    if (pSkill)
    {
        if (pPreviousSkill)
        {
            pPreviousSkill->pNextSkill = pSkill->pNextSkill;
        }
        else
        {
            pSkillList->pFirstSkill = pSkill->pNextSkill;
        }

        FOG_FreePool(pUnit->pMemoryPool, pSkill, ".\\SKILLS\\Skills.cpp", 1511, 0);
    }
}

// 0x00647320
void __stdcall sub_00647320_UpdateChargedSkill(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bRemove)
{
    if (!pUnit || pUnit->dwUnitType != 0)
    {
        return;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return;
    }

    if (bRemove)
    {
        SKILLS_RemoveChargedSkill(pUnit, pSkillList, pSkillsTxtRecord, nSkillId, nOwnerGUID);
        return;
    }

    D2SkillStrc* pPreviousSkill = 0;
    D2SkillStrc* pFoundSkill = pSkillList->pFirstSkill;
    while (pFoundSkill && (pFoundSkill->nOwnerGUID != nOwnerGUID || pFoundSkill->pSkillsTxt != pSkillsTxtRecord))
    {
        pPreviousSkill = pFoundSkill;
        pFoundSkill = pFoundSkill->pNextSkill;
    }

    if (pFoundSkill)
    {
        pFoundSkill->nSkillLevel = nSkillLevel;
        pFoundSkill->dwFlags = 1;
        pFoundSkill->nCharges = nCharges;
        return;
    }

    D2SkillStrc* pSkill = (D2SkillStrc*)FOG_AllocPool(pSkillList->pMemPool, sizeof(D2SkillStrc), ".\\SKILLS\\Skills.cpp", 1534, 0);
    memset(pSkill, 0x00, sizeof(D2SkillStrc));
    pSkill->pSkillsTxt = pSkillsTxtRecord;
    switch (pSkillsTxtRecord->nAnim)
    {
    case 7:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 8:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 10:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 11:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    case 18:
        pSkill->dwSkillMode = pSkillsTxtRecord->nAnim;
        break;

    default:
        pSkill->dwSkillMode = 10;
        break;
    }

    pSkill->nSkillLevel = nSkillLevel;
    pSkill->dwFlags = 1;
    pSkill->nCharges = nCharges;
    pSkill->nOwnerGUID = nOwnerGUID;
    pSkill->pNextSkill = 0;
    if (pPreviousSkill)
    {
        pPreviousSkill->pNextSkill = pSkill;
    }
    else
    {
        pSkillList->pFirstSkill = pSkill;
    }
}
