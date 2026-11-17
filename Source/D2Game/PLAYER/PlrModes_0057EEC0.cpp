#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SeedStrc;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ItemsTxt;
struct D2UnkPlrModeStrc2;

struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[4];
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x38];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    char unk0x00[0x07];
    unsigned char nFlags0;
    char unk0x08[0x2E - 0x08];
    unsigned short wSrvDoFunc;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __fastcall sub_0057ED70_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057ED70
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
extern const unsigned char gbMask_006CE284; // 0x006CE284

struct D2CharStatsTxt
{
    char unk0x00[0x42];
    unsigned char nRunDrain;
    char unk0x43[0xC4 - 0x43];
};

struct D2ItemsTxt
{
    char unk0x00[0xD8];
    int dwSpeed;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
void __fastcall sub_0057F240_EmitWalk(D2UnitStrc* pPlayer);
static __declspec(noinline) int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2UnkPlrModeStrc2
{
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillOwnerGUID;
    int nLeftSkillOwnerGUID;
};

extern "C" const char gszPlrModesSourceFile_006E17E0[]; // 0x006E17E0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, int nWeaponGUID); // 0x006233A0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __fastcall sub_6FC4B580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F850
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __fastcall sub_6FC45B30(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pPreviousItem); // 0x0063CD80
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
static void __stdcall sub_0057FF70_RestoreWeapon(D2GameStrc* pGame, unsigned char nBodyLoc, D2UnitStrc* pPlayer); // 0x0057FF70

static __forceinline int sub_GetConcStat(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x2A);
    return STATLIST_GetStatValue(pStatList, 0xA4, 0);
}

static __forceinline int sub_GetAnimMode(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

// 0x0057EEC0
int __fastcall sub_0057EEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int bCheckUsedSkill, D2SkillStrc* pSkill)
{
    if (STATES_CheckState(pUnit, 0x36))
    {
        return 0;
    }

    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 0;
    }

    if (nMode == 0 || !bCheckUsedSkill)
    {
        return 1;
    }

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
    {
        return 1;
    }

    const int nUsedSkillId = SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 185);

    D2SkillsTxt* pUsedSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nUsedSkillId);
    if (!pUsedSkillsTxtRecord)
    {
        return 1;
    }

    if (pSkill == pUsedSkill && (pUsedSkillsTxtRecord->wSrvDoFunc == 67 || pUsedSkillsTxtRecord->wSrvDoFunc == 76))
    {
        return 1;
    }

    if (pUsedSkillsTxtRecord->nFlags0 & gbMask_006CE284)
    {
        if ((STATES_CheckState(pUnit, 0x2A)
            && (int)(SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100)) < sub_GetConcStat(pUnit))
            || STATES_CheckState(pUnit, 0x0F))
        {
            if (sub_GetAnimMode(pUnit) == 1)
            {
                sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);
                return 1;
            }

            return 0;
        }

        return 1;
    }

    if (sub_GetAnimMode(pUnit) == 1)
    {
        sub_6FC817D0(pGame, pUnit, 0, 1, 0, 0, 1);
        return 1;
    }

    switch (nMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
    case 13:
    case 18:
        if (sub_0057ED70_IsEndAnimDue(pGame, pUnit) != 0)
        {
            return 1;
        }
        break;

    default:
        break;
    }

    return 0;
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x0057F240
static int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer)
{
    if (!pPlayer)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
    {
        return 1;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nStaminaLost = 2 * pCharStatsTxtRecord->nRunDrain;
    if (!pPlayer->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pTorsoArmor = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 3);
    if (pTorsoArmor)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pTorsoArmor ? -1 : pTorsoArmor->dwClassId);
        if (pItemsTxtRecord)
        {
            int nSpeed = pItemsTxtRecord->dwSpeed;
            nSpeed = nSpeed / 10 + 1;
            nStaminaLost *= nSpeed;
        }
    }

    const int nStaminaDrainPct = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 154, 0);
    if (nStaminaDrainPct)
    {
        nStaminaLost += nStaminaLost * nStaminaDrainPct / -100;
    }

    if (nStaminaLost < 1)
    {
        nStaminaLost = 1;
    }

    STATLIST_AddUnitStat(pPlayer, 10, -nStaminaLost, 0);

    if (STATLIST_UnitGetStatValue(pPlayer, 10, 0) <= 0)
    {
        STATLIST_SetUnitStat(pPlayer, 10, 0, 0);
        return 0;
    }

    return 1;
}

void __fastcall sub_0057F240_EmitCaller(void* pGame, D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->dwUnitType == 0 && !sub_0057F240_DrainRunStamina(pPlayer))
    {
        sub_0057F240_EmitWalk(pPlayer);
    }
}

static void __stdcall sub_0057FF70_RestoreWeapon(D2GameStrc* pGame, unsigned char nBodyLoc, D2UnitStrc* pPlayer)
{
    int nNewBodyLoc = nBodyLoc;
    const int nWeaponGUID = UNITS_GetWeaponGUID(pPlayer);
    if (!nWeaponGUID)
    {
        return;
    }

    D2UnitStrc* pWeaponItem = SUNIT_GetServerUnit(pGame, 0x04, nWeaponGUID);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (pWeaponItem && pInventory && !ITEMS_GetInvPage(pWeaponItem) && INVENTORY_CompareWithItemsParentInventory(pInventory, pWeaponItem) && sub_6FC42F20(pPlayer, pWeaponItem, &nNewBodyLoc, 0))
    {
        nBodyLoc = nNewBodyLoc;
        D2_ASSERT(!INVENTORY_GetItemFromBodyLoc(pInventory, nNewBodyLoc), 0x4EA);

        sub_6FC49F80(pGame, pPlayer, nWeaponGUID, nBodyLoc);
    }

    UNITS_SetWeaponGUID(pPlayer, 0);
}

// 0x00580030
static void __stdcall sub_6FC80B90(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pWeapon)
{
    if ((ITEMS_CheckIfStackable(pWeapon) || ITEMS_CheckIfThrowable(pWeapon) || STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x7D, 0)) && STATLIST_UnitGetStatValue(pWeapon, 0x46, 0) <= 0)
    {
        if (STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x7D, 0))
        {
            STATLIST_SetUnitStat(pWeapon, 0x46, 0, 0);
            return;
        }

        if (ITEMS_CheckItemTypeId(pWeapon, 0x2D) && ITEMS_IsMagSetRarUniCrfOrTmp(pWeapon))
        {
            if (!ITEMS_CheckItemFlag(pWeapon, 0x100, 0x513, gszPlrModesSourceFile_006E17E0))
            {
                sub_6FC4B580(pGame, pPlayer, pWeapon);
            }
            return;
        }

        const int bReload = ITEMS_GetReload(pWeapon);
        const int nItemType = ITEMS_GetItemType(pWeapon);
        unsigned char nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
        const int bReEquip = ITEMS_GetReEquip(pWeapon);
        UNITS_ChangeAnimMode(pPlayer, 1);

        int a5;
        sub_6FC45B30(pGame, pPlayer, nBodyLoc, 1, &a5);
        ITEMS_SetItemCMDFlag(pWeapon, 1, 1);

        if (bReload)
        {
            D2UnitStrc* pItem = 0;
            while ((pItem = INVENTORY_GetBackPackItemByType(pPlayer->pInventory, nItemType, pItem)) != 0)
            {
                const int nItemClassId = !pItem ? -1 : pItem->dwClassId;
                if (sub_00451F60_UnitClassId(pWeapon) == nItemClassId && !ITEMS_CheckItemFlag(pItem, 0x100, 0x531, gszPlrModesSourceFile_006E17E0))
                {
                    break;
                }
            }

            if (pItem)
            {
                const int nWeaponClassId = !pWeapon ? -1 : pWeapon->dwClassId;
                if (nWeaponClassId == pItem->dwClassId && !INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc) && sub_6FC49F80(pGame, pPlayer, !pItem ? -1 : pItem->dwUnitId, nBodyLoc))
                {
                    return;
                }
            }
        }

        if (bReEquip)
        {
            sub_0057FF70_RestoreWeapon(pGame, nBodyLoc, pPlayer);
        }
    }
}

static void sub_005801E0_SaveActiveSkills(D2UnitStrc* pUnit, D2UnkPlrModeStrc2* pSkills)
{
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pSkills->nLeftSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pSkills->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, gszPlrModesSourceFile_006E17E0, 0x56E);
    }
    else
    {
        pSkills->nLeftSkillOwnerGUID = -1;
        pSkills->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pSkills->nRightSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pSkills->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, gszPlrModesSourceFile_006E17E0, 0x57A);
    }
    else
    {
        pSkills->nRightSkillOwnerGUID = -1;
        pSkills->nRightSkillId = 0;
    }
}

static int sub_00580260_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 0x02:
    case 0x07:
        return 0;
    }

    return 1;
}

static void sub_00580280_RestoreActiveSkills(D2UnitStrc* pUnit, D2UnkPlrModeStrc2* pSkills)
{
    if (pSkills->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pSkills->nLeftSkillId, pSkills->nLeftSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit) && sub_00580260_IsSkillUsable(pUnit, pSkill))
        {
            D2GAME_AssignSkill_6FD13800(pUnit, 1, pSkills->nLeftSkillId, pSkills->nLeftSkillOwnerGUID);
        }
    }

    if (pSkills->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pSkills->nRightSkillId, pSkills->nRightSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit) && sub_00580260_IsSkillUsable(pUnit, pSkill))
        {
            D2GAME_AssignSkill_6FD13800(pUnit, 0, pSkills->nRightSkillId, pSkills->nRightSkillOwnerGUID);
        }
    }
}

void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        if (pInventory)
        {
            D2UnkPlrModeStrc2 tSkills;
            sub_005801E0_SaveActiveSkills(pUnit, &tSkills);

            D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 0x04);
            if (pRightWeapon)
            {
                sub_6FC80B90(pGame, pUnit, pRightWeapon);
            }

            D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 0x05);
            if (pLeftWeapon)
            {
                sub_6FC80B90(pGame, pUnit, pLeftWeapon);
            }

            sub_00580280_RestoreActiveSkills(pUnit, &tSkills);
        }
    }
}
