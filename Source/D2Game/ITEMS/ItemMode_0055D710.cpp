#include "D2Game.h"
#include "D2Structs.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80

// build: symbol ?sub_6FC43160@@YAXPAUD2UnitStrc@@0PAUD2ItemModeArgStrc@@@Z 0x0055D560
static void sub_6FC43160(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ItemModeArgStrc* pItemModeArg)
{
    D2_ASSERT(pItem, 0x675);
    D2_ASSERT(pUnit, 0x676);
    memset(pItemModeArg, 0, sizeof(D2ItemModeArgStrc));
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 0 && pUnit->dwClassId == 4)
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    const int nUnitType2 = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType2 == 0 && pUnit->dwClassId == 6 && ITEMSIsA(pItem, 0x43))
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    if (ITEMSIsA(pItem, 0x1B))
    {
        pItemModeArg->bIsBow = 1;
    }
    if (ITEMSIsA(pItem, 0x23))
    {
        pItemModeArg->bIsCrossBow = 1;
    }
    if (ITEMSIsA(pItem, 5))
    {
        pItemModeArg->bIsBowQuiver = 1;
    }
    if (ITEMSIsA(pItem, 6))
    {
        pItemModeArg->bIsCrossBowQuiver = 1;
    }
    if (ITEMSIsA(pItem, 0x33))
    {
        pItemModeArg->bIsShield = 1;
    }
    if (ITEMS_CheckWeaponIfTwoHanded(pItem))
    {
        pItemModeArg->bIsTwoHanded = 1;
    }
    if (ITEMSIsA(pItem, 0x2D))
    {
        pItemModeArg->bIsWeapon = 1;
    }
    if (ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0))
    {
        pItemModeArg->bIsThrowable = 1;
    }
    if (ITEMSIsA(pItem, 0x0A))
    {
        pItemModeArg->bIsRing = 1;
    }
}

// 0x0055D670
static int sub_6FC43280(D2ItemModeArgStrc* pArg1, D2ItemModeArgStrc* pArg2)
{
    if (pArg1->bIsBow && pArg2->bIsBowQuiver || pArg1->bIsBowQuiver && pArg2->bIsBow)
    {
        return 1;
    }
    if (pArg1->bIsCrossBow && pArg2->bIsCrossBowQuiver || pArg1->bIsCrossBowQuiver && pArg2->bIsCrossBow)
    {
        return 1;
    }
    if (pArg1->bIsWeapon && !pArg1->bIsTwoHanded && pArg2->bIsShield || pArg2->bIsWeapon && !pArg2->bIsTwoHanded && pArg1->bIsShield)
    {
        return 1;
    }
    if (pArg1->bIsWeapon && !pArg1->bIsTwoHanded && pArg2->bIsWeapon && !pArg2->bIsTwoHanded && pArg1->bCanUse2Weapons && pArg2->bCanUse2Weapons)
    {
        return 1;
    }
    if (pArg1->bIsRing && pArg2->bIsRing)
    {
        return 1;
    }
    return 0;
}

// 0x0055D710
int __fastcall sub_6FC42F20(D2UnitStrc* pUnit, D2UnitStrc* hItem, int* pBodyLoc, int bSkipRequirementCheck)
{
    D2_ASSERT(pUnit, 0x6DC);
    D2_ASSERT(hItem, 0x6DD);
    if (bSkipRequirementCheck)
    {
        if (!ITEMS_IsBodyItem(hItem) || !sub_006280A0(hItem, 0x10, 0x6E2, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CanBeEquipped(hItem) || ITEMS_GetItemType(hItem) == 0x26)
        {
            return 0;
        }
    }
    else
    {
        if (!ITEMS_CheckRequirements(hItem, pUnit, 0, 0, 0, 0) || !ITEMS_IsBodyItem(hItem) || !sub_006280A0(hItem, 0x10, 0x6EB, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CanBeEquipped(hItem) || ITEMS_GetItemType(hItem) == 0x26)
        {
            return 0;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (ITEMS_GetQuiverTypeFromItemType(ITEMS_GetItemType(hItem)))
    {
        if (!pRightArmItem || !ITEMSIsA(hItem, ITEMS_GetAmmoType(pRightArmItem)))
        {
            if (!pLeftArmItem || !ITEMSIsA(hItem, ITEMS_GetAmmoType(pLeftArmItem)))
            {
                return 0;
            }
        }
    }
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    ITEMS_GetAllowedBodyLocations(hItem, &nBodyLoc1, &nBodyLoc2);
    if (nBodyLoc1 == nBodyLoc2)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc1))
        {
            *pBodyLoc = nBodyLoc1;
            return 1;
        }
        return 0;
    }
    D2ItemModeArgStrc itemModeArg1;
    D2ItemModeArgStrc itemModeArg2;
    sub_6FC43160(pUnit, hItem, &itemModeArg1);
    D2UnitStrc* pItem1 = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc1);
    D2UnitStrc* pItem2 = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc2);
    if (pItem1 && pItem2)
    {
        return 0;
    }
    if (!pItem1 && !pItem2)
    {
        *pBodyLoc = nBodyLoc1;
        return 1;
    }
    if (pItem1)
    {
        sub_6FC43160(pUnit, pItem1, &itemModeArg2);
        if (!sub_6FC43280(&itemModeArg1, &itemModeArg2))
        {
            return 0;
        }
        *pBodyLoc = nBodyLoc2;
        return 1;
    }
    sub_6FC43160(pUnit, pItem2, &itemModeArg2);
    if (!sub_6FC43280(&itemModeArg1, &itemModeArg2))
    {
        return 0;
    }
    *pBodyLoc = nBodyLoc1;
    return 1;
}
