#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "D2Skills.h"
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2InventoryStrc;
struct D2SkillsTxt;

typedef int BOOL;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char nCharClass;
    unsigned char unk_0D[0x7];
    signed char nRange;
    unsigned char unk_15[0x3];
    short nITypeA[3];
    short nITypeB[3];
    short nETypeA[2];
    char unk0x028[0x06];
    short wSrvDoFunc;
    unsigned char unk_30[0x118];
    int dwParam[8];
    unsigned char unk_168[0x1C];
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
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
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
static __declspec(noinline) BOOL __stdcall sub_6FDB1130(D2UnitStrc* pItem, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nType); // 0x00643D90
static __declspec(noinline) BOOL __stdcall SKILLS_CheckSkillDelay(D2SkillStrc* pSkill, D2UnitStrc* pUnit); // 0x006478F0
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit); // 0x0064F460
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A710
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

// build: symbol ?SKILLS_GetBonusSkillLevel@@YGHPAUD2UnitStrc@@PAUD2SkillStrc@@@Z 0x00644180
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

// 0x006442A0
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

// 0x00643D60
static __declspec(noinline) D2UnitStrc* __stdcall sub_6FDB1050(int nBodyLoc, D2InventoryStrc* pInventory)
{
    if (nBodyLoc == 5)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    }

    return INVENTORY_GetItemFromBodyLoc(pInventory, 5);
}

// build: context sub_6FDB1130
static __declspec(noinline) BOOL __stdcall sub_6FDB1130(D2UnitStrc* pItem, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nType)
{
    if (!pItem)
    {
        if (pSkillsTxtRecord->nETypeA[2 * nType] <= 0 && pSkillsTxtRecord->nITypeA[3 * nType] <= 0)
        {
            return TRUE;
        }

        if ((pSkillsTxtRecord->nITypeA[0] == 0x2D || pSkillsTxtRecord->nITypeA[0] == 0x2E || pSkillsTxtRecord->nITypeA[0] == 0x43)
            && pSkillsTxtRecord->nITypeB[0] <= 0 && !ITEMSIsA(0, 0x2D) && !ITEMSIsA(pUnit, 0x2D))
        {
            return TRUE;
        }

        if (pSkillsTxtRecord->nITypeA[0] == 0x43 && pSkillsTxtRecord->nITypeB[0] <= 0 && !ITEMSIsA(0, 0x2D) && !ITEMSIsA(pUnit, 0x2D))
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

        if (ITEMSIsA(pItem, *pEType))
        {
            return FALSE;
        }

        ++pEType;
    }

    short* pIType = &pSkillsTxtRecord->nITypeA[3 * nType];
    for (i = 0; i < 3; ++i)
    {
        if (*pIType <= 0)
        {
            return i == 0;
        }

        if (ITEMSIsA(pItem, *pIType))
        {
            break;
        }

        ++pIType;
    }

    if (i >= 3)
    {
        return FALSE;
    }

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

        if (!pUnit || !ITEMSIsA(pUnit, ITEMS_GetAmmoType(pItem)))
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

// 0x00643F80
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

// 0x00644060
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

// 0x006440F0
static __declspec(noinline) BOOL D2Common_SKILLMANA_CheckStartStat_6FDB1400(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || pUnit->dwUnitType != 0 || pSkill->pSkillsTxt->wStartMana <= 0
        || STATLIST_UnitGetStatValue(pUnit, 8, 0) >= (int)pSkill->pSkillsTxt->wStartMana << 8 || STATES_CheckState(pUnit, 0xC))
    {
        return 1;
    }

    return FALSE;
}

// 0x00647540
static __declspec(noinline) BOOL D2Common_SKILLMANA_CheckStat_6FDB0F50(D2UnitStrc* pUnit, D2SkillStrc* hSkill)
{
    D2_ASSERT(hSkill, 0x637);

    if (hSkill->nOwnerGUID != -1)
    {
        return hSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxt = hSkill->pSkillsTxt;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, hSkill, 1) - 1;
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

// 0x00647640
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
                    bContinue = ITEMSIsA(pOtherItem, 0x2D);
                }
            }
            else
            {
                bContinue = ITEMSIsA(pItem, 0x2D);
            }
        }

        return bContinue;
    }

    return 1;
}

// 0x00647840
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

// build: context SKILLS_CheckSkillDelay
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

// 0x00647960
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* ptSkill)
{
    D2_ASSERT(ptSkill, 0x8E9);

    if (!ptSkill->pSkillsTxt || !SKILLS_HasFlag(ptSkill->pSkillsTxt, 10))
    {
        return 3;
    }

    if (!SKILLS_GetSkillLevel(pUnit, ptSkill, 1))
    {
        return 7;
    }

    if (SKILLS_HasFlag(ptSkill->pSkillsTxt, 5))
    {
        return 6;
    }

    if (SKILLS_HasFlag(ptSkill->pSkillsTxt, 4))
    {
        return 5;
    }

    if (!sub_00647640_CheckSkillQuantity(pUnit, ptSkill))
    {
        return 2;
    }

    if (!sub_00643F80_CheckWeaponTypes(pUnit, ptSkill))
    {
        return 2;
    }

    if (!D2Common_SKILLMANA_CheckStat_6FDB0F50(pUnit, ptSkill))
    {
        return 1;
    }

    if (!D2Common_SKILLS_CheckShapeRestriction_6FDB1380(pUnit, ptSkill))
    {
        return 4;
    }

    if (!D2Common_SKILLMANA_CheckStartStat_6FDB1400(pUnit, ptSkill))
    {
        return 1;
    }

    if (!sub_6FDB1070(pUnit, ptSkill))
    {
        return 2;
    }

    return SKILLS_CheckSkillDelay(ptSkill, pUnit) ? 0 : 8;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00645460
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    if (!pSkill->pSkillsTxt)
    {
        return 0;
    }

    int nRange = pSkill->pSkillsTxt->nRange;
    if (nRange != 3)
    {
        return nRange;
    }

    nRange = (COMPOSIT_IsWeaponBowOrXBow(pUnit) != 0) + 1;
    if (pUnit && pUnit->dwUnitType == 0 && nRange != 1 && STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return 1;
    }

    return nRange;
}

// 0x006459F0
int __stdcall sub_006459F0(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* ptSkill = DATATBLS_GetSkillsTxtRecord(nSkillId);
    SKILLS_ASSERT(ptSkill, 4108);

    int nMana = ((ptSkill->wMana + (nSkillLevel - 1) * ptSkill->wLevelMana) << ptSkill->nManaShift) >> 8;
    if (nMana < 0)
    {
        nMana = 0;
    }

    return nMana;
}

// 0x00646020
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit)
{
    if (!STATES_IsUnitShapeShifted(pUnit))
    {
        return 0;
    }

    for (int i = 0; i < sgptDataTables->nTransformStates; ++i)
    {
        short nState = sgptDataTables->pTransformStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            STATES_ToggleState(pUnit, nState, 0);
        }
    }

    return 1;
}

// 0x006461D0
int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId)
{
    if (!STATES_CheckState(pUnit, 42))
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 42);
    if (!pStatList)
    {
        return 0;
    }

    int nDamagePercent = STATLIST_GetStatValue(pStatList, 25, 0);
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    int nParam;
    if (!pSkillsTxtRecord)
    {
        nParam = 0;
    }
    else
    {
        nParam = pSkillsTxtRecord->dwParam[0];
    }

    return nDamagePercent * nParam / 8;
}

// 0x00645FF0
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}
