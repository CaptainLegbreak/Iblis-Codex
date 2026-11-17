struct D2InventoryStrc;
struct D2SkillStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    char unk0x000[0x198];
    int dwToHit;
    int dwLevToHit;
};

struct D2CharStatsTxt
{
    char unk0x00[0x3C];
    int dwToHitFactor;
    char unk0x40[0x84];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

struct D2GameStrc;

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
};

struct D2ShrinesTxt
{
    unsigned char nCode;
    char unk0x01[0x03];
    int dwArg0;
    int dwArg1;
    int dwDurationInFrames;
};

typedef void(__fastcall* ObjShrineFunction)(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);
typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2ShrineTableStrc
{
    ObjShrineFunction pfShrineCallback;
    int unk0x04;
    int unk0x08;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const D2ShrineTableStrc gpShrineTable_006E1850[];                                                    // 0x006E1850
extern int gnShrineTableCount_00732EAC;                                                                     // 0x00732EAC

int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0
D2StatListStrc* __fastcall sub_00582800_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback); // 0x00582800
void __fastcall sub_6FC77AB0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                    // 0x00583A40

static __declspec(noinline) void __stdcall OBJMODE_GetToHitPercentage(int* pToHit, int nSkillLevel, D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2UnitStrc* pWeapon)
{
    *pToHit = UNITS_GetAttackRate(pUnit);
    D2_ASSERT(pSkill, 0x963);

    if (!pWeapon)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (pWeapon && ITEMS_GetItemType(pWeapon) == 0x26)
    {
        *pToHit = 0;
    }

    const int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, pSkill, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x77, 0);
    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    const int nToHit = *pToHit;
    *pToHit = nToHit + nToHit * (pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit + nBonus) / 100;

    if (pUnit && pUnit->dwUnitType == 0)
    {
        const int nClassId = pUnit->dwClassId;
        D2CharStatsTxt* pCharStatsTxtRecord = 0;
        if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        {
            pCharStatsTxtRecord = &sgptDataTables->pCharStatsTxt[nClassId];
        }

        if (pCharStatsTxtRecord)
        {
            *pToHit += pCharStatsTxtRecord->dwToHitFactor;
        }
    }
}

static __forceinline int OBJMODE_GetToHitPercentageValue(D2UnitStrc* pUnit, D2UnitStrc* pWeapon, D2SkillStrc* pSkill)
{
    int nPercentage;
    OBJMODE_GetToHitPercentage(&nPercentage, 1, pUnit, pSkill, pWeapon);
    return nPercentage;
}

static __forceinline int OBJMODE_GetMinDamagePercentage(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    int bTwoHanded = 0;
    if (D2Common_10434(pUnit, 1) || pWeapon)
    {
        bTwoHanded = INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2;
    }

    if (bTwoHanded)
    {
        return STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
    }
    return STATLIST_UnitGetStatValue(pUnit, 0x15, 0);
}

static __declspec(noinline) int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit); // 0x00583840

// build: context OBJMODE_CalculateShrineStatBonus
static __declspec(noinline) int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit && pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    switch (nStatId)
    {
    case 0x0B:
    case 0x1B:
    case 0x27:
    case 0x29:
    case 0x2B:
    case 0x2D:
    case 0x55:
    case 0xAB:
        return nValue;

    case 0x13:
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
        return nValue * OBJMODE_GetToHitPercentageValue(pUnit, pWeapon, pSkill) / 100;
    }

    case 0x15:
        return nValue * OBJMODE_GetMinDamagePercentage(pUnit, pWeapon) / 100;

    default:
        return nValue * STATLIST_UnitGetStatValue(pUnit, nStatId, 0) / 100;
    }
}

// 0x005839B0
void __fastcall D2GAME_SHRINES_CombatBoost_6FC77690(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pShrinesTxtRecord->nCode < gnShrineTableCount_00732EAC, 0x9C1);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[pShrinesTxtRecord->nCode];
    const int nValue = OBJMODE_CalculateShrineStatBonus(0x13, pShrinesTxtRecord->dwArg0, pOp->pPlayer);
    D2StatListStrc* pStatList = sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, pShrinesTxtRecord->dwDurationInFrames, pShrinesTxtRecord->dwArg1, 0x19, pShrineRecord->unk0x08, 0);
    sub_006270B0(pStatList, 0x13, nValue, 0);
}

// 0x00583A70
void __fastcall D2GAME_SHRINES_Stamina_6FC779C0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pShrinesTxtRecord->nCode < gnShrineTableCount_00732EAC, 0x9E7);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[pShrinesTxtRecord->nCode];
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pOp->pPlayer);
    STATLIST_SetUnitStat(pOp->pPlayer, 0x0A, nMaxStamina, 0);
    const int nStatValue = OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, pShrinesTxtRecord->dwArg0, pOp->pPlayer);
    D2StatListStrc* pStatList = sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, pShrinesTxtRecord->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, sub_6FC77AB0);
    sub_006270B0(pStatList, 0x0A, 2 * nStatValue, 0);
    sub_006270B0(pStatList, 0x1C, 1000, 0);
}

// 0x00583B30
void __fastcall D2GAME_SHRINES_DefensiveBoost_6FC77AE0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pShrinesTxtRecord->nCode < gnShrineTableCount_00732EAC, 0x9F9);

    const D2ShrineTableStrc* pShrineRecord = &gpShrineTable_006E1850[pShrinesTxtRecord->nCode];
    const int nStatValue = pShrineRecord->unk0x04 != -1 ? OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, pShrinesTxtRecord->dwArg0, pOp->pPlayer) : 0;

    sub_00582800_ApplyShrineCurse(pOp->pObject, pOp->pPlayer, pShrinesTxtRecord->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, 0);
}

#include "gen/data/Source/D2Game/005839B0_D2GAME_SHRINES_CombatBoost_6FC77690.inc"
