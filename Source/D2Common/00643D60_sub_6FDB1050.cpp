typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct D2InventoryStrc;
struct D2SkillStrc;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char nCharClass;
    char unk0x00D[0x0B];
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
    char unk0x08[0x20];
    int nSkillLevel;
    int nLevelBonus;
    int nQuantity;
    int nOwnerGUID;
    int nCharges;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SKILLS_HasFlag(pSkillsTxt, nFlag) ((pSkillsTxt)->nFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])

D2SkillDescTxt* __fastcall sub_004A89D0(int nSkillId);                         // 0x004A89D0
int __stdcall DATATBLS_GetMaxLevel(int nClass);                                                             // 0x00611830
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit);                                                 // 0x0063A400
int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit);                                      // 0x0063A510
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit);                                           // 0x00644150
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

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

static __declspec(noinline) BOOL __stdcall sub_6FDB1130(D2UnitStrc* pItem, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nType); // 0x00643D90

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

    short* pIType = &pSkillsTxtRecord->nITypeA[3 * nType];
    for (i = 0; i < 3; ++i)
    {
        if (*pIType <= 0)
        {
            return i == 0;
        }

        if (ITEMS_CheckItemTypeId(pItem, *pIType))
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

static __declspec(noinline) BOOL __stdcall SKILLS_CheckSkillDelay(D2SkillStrc* pSkill, D2UnitStrc* pUnit); // 0x006478F0

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
