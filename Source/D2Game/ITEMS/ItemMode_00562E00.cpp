#include "D2Txt.h"
struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2SkillStrc;

struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x20 - 0x14];
    int pSeed[2];
    unsigned int dwInitSeed;
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x60 - 0x2C - 4];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC4 - 0x60 - 4];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
    char f_74[0x78 - 0x70 - 4];
    unsigned short wItemFormat;
    char unk0x7A[0xA8 - 0x78 - 2];
    unsigned int dwGameFrame;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit);                                                     // 0x00622EA0
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit);                                                      // 0x00622F10
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID);                  // 0x00623060
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID);                   // 0x006230C0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
int __stdcall ITEMS_CheckType(int nItemType, int nItemTypeToCheck);                                         // 0x00629B50
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
int __stdcall sub_0063BDB0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);                   // 0x0063BDB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __stdcall sub_0063D1D0_InventoryItemCall(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                   // 0x00647960
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0

static __declspec(noinline) void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon);
static void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon); // 0x0055C470
// 0x0055C470
static void sub_0055C470_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon)
{
    *ppRightHandWeapon = 0;
    *ppMainWeapon = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        *ppMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRightHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (*ppMainWeapon == pRightHandWeapon)
        {
            *ppRightHandWeapon = pLeftHandWeapon;
        }
        else
        {
            *ppRightHandWeapon = pRightHandWeapon;
        }

        if (*ppRightHandWeapon && !ITEMS_CheckItemTypeId(*ppRightHandWeapon, 0x2D))
        {
            *ppRightHandWeapon = 0;
        }
    }
}

static __declspec(noinline) int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
static int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C4D0
// 0x0055C4D0
static int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }

    return 1;
}

static __declspec(noinline) void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft);
static void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft); // 0x0055C4F0
// 0x0055C4F0
static void sub_0055C4F0_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft)
{
    if (!pUnit || !pCurrentSkill)
    {
        return;
    }

    int nSkillId;
    int nOwnerGUID;
    if (bLeft)
    {
        UNITS_GetLeftSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }
    else
    {
        UNITS_GetRightSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill || pSkill == pCurrentSkill)
    {
        return;
    }

    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return;
    }

    D2GAME_AssignSkill_6FD13800(pUnit, bLeft, nSkillId, nOwnerGUID);
}

static __declspec(noinline) int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill);
static int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C560
// 0x0055C560
static int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], 0x30) || pSkillsTxtRecord->nAuraTargetState != 2)
    {
        return 0;
    }

    return sub_0055C4D0_IsSkillUsable(pUnit, pSkill) != 0;
}

static __declspec(noinline) void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit);
static void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit); // 0x0055C5C0
// 0x0055C5C0
static void sub_0055C5C0_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != 0)
    {
        return;
    }

    D2UnitStrc* pRightHandWeapon;
    D2UnitStrc* pMainWeapon;
    sub_0055C470_GetWeapons(pUnit, &pMainWeapon, &pRightHandWeapon);
    if (!pMainWeapon)
    {
        return;
    }

    int bThrown = ITEMS_CheckItemTypeId(pMainWeapon, 0x30) && !ITEMS_CheckItemTypeId(pMainWeapon, 0x2E);
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (bThrown && !sub_0055C560_IsThrowSkillUsable(pUnit, pLeftSkill))
    {
        UNITS_InitLeftSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 1, 2, -1);
        pLeftSkill = UNITS_GetLeftSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pLeftSkill))
    {
    case 2:
    case 7:
        sub_0055C4F0_RestoreSkill(pUnit, pLeftSkill, 1);
        break;
    }

    bThrown = pRightHandWeapon && ITEMS_CheckItemTypeId(pRightHandWeapon, 0x30) && !ITEMS_CheckItemTypeId(pRightHandWeapon, 0x2E);
    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (bThrown && !sub_0055C560_IsThrowSkillUsable(pUnit, pRightSkill))
    {
        UNITS_InitRightSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, 4, -1);
        pRightSkill = UNITS_GetRightSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pRightSkill))
    {
    case 2:
    case 7:
        sub_0055C4F0_RestoreSkill(pUnit, pRightSkill, 0);
        break;
    }
}

enum { UNIT_INVALID = 6 };
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
struct D2ItemModeArgStrc
{
    int bIsBow;
    int bIsCrossBow;
    int bIsBowQuiver;
    int bIsCrossBowQuiver;
    int bIsShield;
    int bIsWeapon;
    int bIsTwoHanded;
    int bCanUse2Weapons;
    int bIsThrowable;
    int bIsRing;
};
int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem);                                                          // 0x0062FDF0
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType);                                               // 0x00628480
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
    if (nUnitType2 == 0 && pUnit->dwClassId == 6 && ITEMS_CheckItemTypeId(pItem, 0x43))
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 0x1B))
    {
        pItemModeArg->bIsBow = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 0x23))
    {
        pItemModeArg->bIsCrossBow = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 5))
    {
        pItemModeArg->bIsBowQuiver = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 6))
    {
        pItemModeArg->bIsCrossBowQuiver = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 0x33))
    {
        pItemModeArg->bIsShield = 1;
    }
    if (ITEMS_CheckWeaponIfTwoHanded(pItem))
    {
        pItemModeArg->bIsTwoHanded = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 0x2D))
    {
        pItemModeArg->bIsWeapon = 1;
    }
    if (ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, 0x7D, 0))
    {
        pItemModeArg->bIsThrowable = 1;
    }
    if (ITEMS_CheckItemTypeId(pItem, 0x0A))
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
int __fastcall sub_6FC42F20(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pBodyLoc, int bSkipRequirementCheck)
{
    D2_ASSERT(pUnit, 0x6DC);
    D2_ASSERT(pItem, 0x6DD);
    if (bSkipRequirementCheck)
    {
        if (!ITEMS_IsBodyItem(pItem) || !sub_006280A0(pItem, 0x10, 0x6E2, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CanBeEquipped(pItem) || ITEMS_GetItemType(pItem) == 0x26)
        {
            return 0;
        }
    }
    else
    {
        if (!ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0) || !ITEMS_IsBodyItem(pItem) || !sub_006280A0(pItem, 0x10, 0x6EB, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CanBeEquipped(pItem) || ITEMS_GetItemType(pItem) == 0x26)
        {
            return 0;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (ITEMS_GetQuiverTypeFromItemType(ITEMS_GetItemType(pItem)))
    {
        if (!pRightArmItem || !ITEMS_CheckItemTypeId(pItem, ITEMS_GetAmmoType(pRightArmItem)))
        {
            if (!pLeftArmItem || !ITEMS_CheckItemTypeId(pItem, ITEMS_GetAmmoType(pLeftArmItem)))
            {
                return 0;
            }
        }
    }
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);
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
    sub_6FC43160(pUnit, pItem, &itemModeArg1);
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

// 0x00562E00
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nBodyLoc;
    if (sub_6FC42F20(pUnit, pItem, &nBodyLoc, bSkipRequirementCheck))
    {
        if (sub_0063BDB0(pInventory, pItem, nBodyLoc))
        {
            if (nBodyLoc != 0xB && nBodyLoc != 0xC)
            {
                if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
                {
                    ITEMS_SetBodyLocation(pItem, nBodyLoc);
                    sub_0063D1D0_InventoryItemCall(pInventory, pItem);
                    INVENTORY_SetCursorItem(pInventory, 0);
                    D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 0);
                    if (pItem)
                    {
                        pItem->dwFlags &= ~2;
                    }
                    UNITS_ChangeAnimMode(pItem, 1);
                    ITEMS_SetItemCMDFlag(pItem, 0x200, 1);
                    if (pItem)
                    {
                        pItem->dwFlags &= ~0x2000000;
                    }
                    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                    UNITS_RefreshInventory(pUnit, 1);
                    ITEMS_SetInvPage(pItem, 0xFF);
                    sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
                    return 1;
                }
                sub_0063BE30(pInventory, nBodyLoc);
                D2_ASSERT(0, 0x1671);
            }
            D2_ASSERT(0, 0x1656);
        }
        D2_ASSERT(0, 0x1674);
    }
    return 0;
}
