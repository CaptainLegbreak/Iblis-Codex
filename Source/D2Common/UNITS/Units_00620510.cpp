#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#define SIZE_PLAYER 2
#define SIZE_ITEM 1
#define UNITFLAG_DOUPDATE 0x00000001
#define MONSTATSFLAGINDEX_SWITCHAI 16
struct D2InventoryStrc;
struct D2AnimSeqTxt;
struct D2MonStats2Txt;
struct D2MissilesTxt;
struct D2ObjectsTxt;
struct D2ObjectDataStrc;
struct D2AnimDataRecordStrc;
struct D2MonStatsTxt;
struct D2CharStatsTxt;
struct D2MonsterDataStrc;
struct D2ItemsTxt;
struct D2InventoryRecordMapStrc;
struct D2SkillsTxt;
struct D2AnimModeModulatorStrc;
struct D2AnimModeStatBasePercentageStrc;
struct D2PlayerDataStrc;
struct D2StaticPathStrc;

struct D2MonStats2Txt
{
    char unk0x00[8];
    signed char nSizeX;
    signed char nSizeY;
};

struct D2MissilesTxt
{
    char unk0x00[394];
    unsigned char nSize;
};

struct D2ObjectsTxt
{
    char unk0x00[208];
    int dwSizeX;
    int dwSizeY;
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
unsigned int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190

struct D2AnimDataRecordStrc
{
    char szAnimDataName[8];
    unsigned int dwFrames;
    unsigned int dwAnimSpeed;
    unsigned char pFrameFlags[144];
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x22];
    short wVelocity;
    char unk0x34[0x02];
    short nWalkAnimSpeed;
    short nRunAnimSpeed;
    char unk0x3A[0x16E];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit); // 0x006209D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
D2UnitStrc* __stdcall sub_0063BF90_GetSecondaryWeapon(D2InventoryStrc* pInventory); // 0x0063BF90
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem); // 0x00628660

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    unsigned char nRunSpeed;
    char unk0x42[0x82];
};

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x006270B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

enum
{
};

enum
{
    INVPAGE_EQUIP = 1,
    INVPAGE_TRADE = 2,
    INVPAGE_CUBE = 3,
    INVPAGE_STASH = 4,
};

enum
{
    INVENTORYRECORD_MONSTER = 5,
    INVENTORYRECORD_TRADE_PAGE_1 = 6,
    INVENTORYRECORD_TRADE_PAGE_2 = 7,
    INVENTORYRECORD_BANK_PAGE_1 = 8,
    INVENTORYRECORD_TRANSMOGRIFY_BOX_PAGE_1 = 9,
    INVENTORYRECORD_GUILD_VAULT_PAGE_1 = 10,
    INVENTORYRECORD_TROPHY_CASE_PAGE_1 = 11,
    INVENTORYRECORD_BIG_BANK_PAGE_1 = 12,
};

enum
{
    OBJECT_GUILD_VAULT = 338,
    OBJECT_TROPHY_CASE = 339,
};

enum
{
    PLRMODE_WALK = 2,
    PLRMODE_RUN = 3,
    PLRMODE_TOWNWALK = 6,
};

enum
{
    MONMODE_WALK = 2,
    MONMODE_SKILL1 = 8,
    MONMODE_SKILL2 = 9,
    MONMODE_RUN = 15,
};

enum
{
    MONSTER_VULTURE1 = 110,
    MONSTER_DIABLO = 243,
    MONSTER_DOOMKNIGHT1 = 310,
    MONSTER_DIABLOCLONE = 333,
    MONSTER_ACT3HIRE = 359,
};

enum
{
    MONSTER_TENTACLE1 = 258,
    MONSTER_TENTACLEHEAD1 = 261,
};

enum
{
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

enum
{
    COMPOSIT_RIGHTHAND = 7,
};

enum
{
    ITEMTYPE_SHIELD = 2,
};

struct D2MonsterDataStrc
{
    int unk0x00;
    unsigned char nComponent[16];
};

struct D2ItemsTxt
{
    char unk0x000[0x11E];
    unsigned short wType[2];
};

struct D2InventoryRecordMapStrc
{
    int nClassId;
    int nRecord;
};

extern D2InventoryRecordMapStrc gInventoryRecordMap_00744544[]; // 0x00744544
extern unsigned int gnInventoryRecordMapCount_0074457C; // 0x0074457C
extern unsigned int gdwNoBlockItemCodes_00744580[]; // 0x00744580
extern unsigned int gnNoBlockItemCodeCount_00744584; // 0x00744584
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
int __stdcall sub_00622870_GetMeleeRange(D2UnitStrc* pUnit); // 0x00622870
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0
void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt* pMonSeqTxt, int nTargetFramePoint, int nCurrentFramePoint, int* pMode, int* pFrame, int* pDirection, int* pEvent); // 0x00663410
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit); // 0x006633B0
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit); // 0x006633D0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit); // 0x00623B10

struct D2SkillsTxt
{
    char unk0x00[0x12];
    char nSeqTrans;
    unsigned char unk_13[0x125];
    unsigned int dwCalc[4];
};

struct D2AnimModeModulatorStrc
{
    int bCanUseVelocityModifierByPassiveSkill;
    int bCanUseVelocityModifier;
    int bCanUseSkillAttackRate;
    int bCanUseAttackRate;
    int bAllowAnimSpeed;
};

struct D2AnimModeStatBasePercentageStrc
{
    int bHasBasePercentage;
    int nBasePercentage;
    int nStatId;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2AnimModeModulatorStrc gaPlayerModesAnimModulators_006E8A00[]; // 0x006E8A00
extern D2AnimModeModulatorStrc gaMonModesAnimModulators_006E8B90[]; // 0x006E8B90
extern D2AnimModeModulatorStrc gaMonModesAnimModulatorsExpansion_006E8CD0[]; // 0x006E8CD0
extern D2AnimModeStatBasePercentageStrc gaAnimModeStatBasePercentage_006E8E24[]; // 0x006E8E24
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId); // 0x00621580
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int bSet); // 0x00623C80
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
unsigned int __stdcall D2Common_11043(D2UnitStrc* pUnit); // 0x00646170
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
void __stdcall D2Common_10534(D2UnitStrc* pUnit); // 0x00625A00
int __stdcall D2Common_10531_SetStatInStatListLayer0(D2StatListStrc* pStatList, int nStatId, int nValue, int nUnused); // 0x00627810
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0

struct D2PlayerDataStrc
{
    char szName[16];
    char unk0x10[0x60];
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillFlags;
    int nLeftSkillFlags;
    int nSwitchRightSkillId;
    int nSwitchLeftSkillId;
    int nSwitchRightSkillFlags;
    int nSwitchLeftSkillFlags;
    int nWeaponGUID;
    int unk0x94;
};

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0


int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem); // 0x00629FE0
void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit); // 0x006272E0
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit); // 0x00624390

static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId);

// 0x00620510
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            return SIZE_PLAYER;

        case UNIT_MONSTER:
            if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
            {
                return pMonStats2TxtRecord->nSizeX;
            }
            return 0;

        case UNIT_OBJECT:
            return pUnit->pObjectData->pObjectTxt->dwSizeX;

        case UNIT_ITEM:
            return SIZE_ITEM;

        case UNIT_MISSILE:
            if (D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pUnit->dwClassId))
            {
                return pMissilesTxtRecord->nSize;
            }
            return 0;

        case UNIT_TILE:
            return 0;

        default:
            return 0;
        }
    }

    return 0;
}

// 0x006205A0
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1867);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SIZE_PLAYER;

    case UNIT_MONSTER:
        if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(ptUnit->dwClassId))
        {
            return pMonStats2TxtRecord->nSizeY;
        }
        return 0;

    case UNIT_OBJECT:
        return ptUnit->pObjectData->pObjectTxt->dwSizeY;

    case UNIT_ITEM:
        return SIZE_ITEM;

    case UNIT_MISSILE:
        if (D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(ptUnit->dwClassId))
        {
            return pMissilesTxtRecord->nSize;
        }
        return 0;

    case UNIT_TILE:
        return 0;

    default:
        return 0;
    }
}

// 0x00620A70
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* hUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(hUnit, 2129);
    const int nSizeX = UNITS_GetUnitSizeX(hUnit);
    const int nSizeY = UNITS_GetUnitSizeY(hUnit);
    if (nSizeX && nSizeY)
    {
        COLLISION_SetMaskWithSizeXY(pRoom, nX, nY, nSizeX, nSizeY, UNITS_GetCollisionMask(hUnit));
    }
}

// 0x00620D80
void __stdcall sub_00620D80_SetMonsterAnimSpeed(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    switch (pUnit->dwUnitType)
    {
    case 1:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
        }
        if (!pMonStatsTxtRecord)
        {
            pUnit->wAnimSpeed = 0;
            return;
        }
        if (!pUnit->pStatListEx)
        {
            pUnit->wAnimSpeed = pMonStatsTxtRecord->nWalkAnimSpeed;
            return;
        }
        const int nVelocityPercent = STATLIST_UnitGetStatValue(pUnit, 67, 0);
        const short nBaseAnimSpeed = (pUnit->dwAnimMode == 15) ? pMonStatsTxtRecord->nRunAnimSpeed : pMonStatsTxtRecord->nWalkAnimSpeed;
        int nAnimSpeed = nBaseAnimSpeed * nVelocityPercent / 100;
        nAnimSpeed = nAnimSpeed > 0 ? nAnimSpeed : 0;
        if (nAnimSpeed >= 0x7FFF)
        {
            nAnimSpeed = 0x7FFF;
        }
        pUnit->wAnimSpeed = nAnimSpeed;
        break;
    }
    }
}

// 0x006218D0
void __stdcall UNITS_SetAnimActionFrame(D2UnitStrc* pUnit, int nFrame)
{
    if (pUnit && pUnit->pAnimData && nFrame < 144)
    {
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 1)
        {
            pUnit->nActionFrame = 1;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 2)
        {
            pUnit->nActionFrame = 2;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 3)
        {
            pUnit->nActionFrame = 3;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 4)
        {
            pUnit->nActionFrame = 4;
        }
    }
}

// 0x00623C80
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int a2)
{
    if (!UNITS_CanDualWield(pUnit))
    {
        return;
    }
    D2UnitStrc* pWeapon = D2Common_10434(pUnit, a2);
    D2UnitStrc* pPrimaryWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    if (!pWeapon)
    {
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 1);
        }
    }
    else if (pWeapon == pPrimaryWeapon)
    {
        D2UnitStrc* pSecondaryWeapon = sub_0063BF90_GetSecondaryWeapon(pUnit->pInventory);
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 1);
        }
        if (pSecondaryWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pSecondaryWeapon, 0);
        }
    }
    else
    {
        if (STATLIST_GetOwner(pWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 1);
        }
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 0);
        }
    }
}

// 0x00623D60
unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 5 || nBodyLoc == 4)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!sub_0062A4E0_TestItem(pRightHandItem))
        {
            pRightHandItem = 0;
        }
        D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (!sub_0062A4E0_TestItem(pLeftHandItem))
        {
            pLeftHandItem = 0;
        }
        if (pRightHandItem && pLeftHandItem && !ITEMS_CheckWeaponIfTwoHanded(pRightHandItem) && !ITEMS_CheckWeaponIfTwoHanded(pLeftHandItem)
            && UNITS_CanDualWield(pUnit) && pItem != INVENTORY_GetLeftHandWeapon(pInventory))
        {
            return 6;
        }
    }
    return ITEMS_GetComponent(pItem);
}

// 0x00620E80
static void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    D2CharStatsTxt* pCharStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
    const int nWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    if (nWalkSpeed)
    {
        sub_006270B0(pStatList, 0x43, 100 * pCharStatsTxtRecord->nRunSpeed / nWalkSpeed - 100, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

// calling-convention shim (not game code)
int __stdcall sub_K14_EmitCharacterStartRunning(D2UnitStrc* pUnit, int nClass)
{
    if (UNITS_GetUnitSizeX(pUnit) == 3)
        UNITS_CharacterStartRunningOrKnockback(pUnit, nClass);
    if (UNITS_GetUnitSizeX(pUnit) == 5)
        UNITS_CharacterStartRunningOrKnockback(pUnit, pUnit->dwClassId);
    return 1;
}

// 0x00621050
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD)
{
    D2_ASSERT(hUnit, 2607);

    int nRet = -1;
    switch (hUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        switch ((unsigned char)nInvPage)
        {
        case INVPAGE_EQUIP:
            return INVENTORYRECORD_TRADE_PAGE_1;

        case INVPAGE_TRADE:
            return INVENTORYRECORD_TRADE_PAGE_2;

        case INVPAGE_STASH:
            return bLoD != 0 ? INVENTORYRECORD_BIG_BANK_PAGE_1 : INVENTORYRECORD_BANK_PAGE_1;

        case INVPAGE_CUBE:
            return INVENTORYRECORD_TRANSMOGRIFY_BOX_PAGE_1;

        default:
        {
            const int nClassId = hUnit->dwClassId;
            for (unsigned int i = 0; i < gnInventoryRecordMapCount_0074457C; ++i)
            {
                if (nClassId == gInventoryRecordMap_00744544[i].nClassId)
                {
                    nRet = gInventoryRecordMap_00744544[i].nRecord;
                    break;
                }
            }
            break;
        }
        }
        break;

    case UNIT_MONSTER:
        return INVENTORYRECORD_MONSTER;

    case UNIT_OBJECT:
        switch (hUnit->dwClassId)
        {
        case OBJECT_GUILD_VAULT:
            return INVENTORYRECORD_GUILD_VAULT_PAGE_1;

        case OBJECT_TROPHY_CASE:
            return INVENTORYRECORD_TROPHY_CASE_PAGE_1;

        default:
            return -1;
        }
    }

    return nRet;
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

inline unsigned char MONSTERS_GetComponentInline(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }
    return 0;
}

// 0x006225F0
int __fastcall sub_006225F0_MonsterCanBlock(D2UnitStrc* pUnit)
{
    switch (MONSTERS_ValidateMonsterIdInline(UNITS_GetClassIdInline(pUnit)))
    {
    case MONSTER_DIABLO:
    case MONSTER_DOOMKNIGHT1:
    case MONSTER_DIABLOCLONE:
        return 1;

    case MONSTER_ACT3HIRE:
        return 0;

    default:
        break;
    }

    const unsigned int dwCode = D2Common_11069(pUnit, COMPOSIT_RIGHTHAND, MONSTERS_GetComponentInline(pUnit, COMPOSIT_RIGHTHAND));
    if (!dwCode)
    {
        return 0;
    }

    for (unsigned int i = 0; i < gnNoBlockItemCodeCount_00744584; ++i)
    {
        if (dwCode == gdwNoBlockItemCodes_00744580[i])
        {
            return 0;
        }
    }

    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    if (pItemsTxtRecord && pItemsTxtRecord->wType[0] == ITEMTYPE_SHIELD)
    {
        return 1;
    }

    return 0;
}

// 0x00622C40
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus)
{
    if (pUnit2 && pUnit1)
    {
        const int nType = pUnit2 ? pUnit2->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER)
        {
            switch (MONSTERS_ValidateMonsterIdInline(sub_00463860(pUnit2)))
            {
            case MONSTER_TENTACLE1:
            case MONSTER_TENTACLEHEAD1:
            {
                const int nDistance = D2Common_10399(pUnit1, pUnit2);
                if (sub_00622870_GetMeleeRange(pUnit1) + 8 > nDistance)
                {
                    return 1;
                }
                break;
            }
            }
        }

        const int nRange = sub_00622870_GetMeleeRange(pUnit1) + nRangeBonus + 1;
        const int nDistance = D2Common_10399(pUnit1, pUnit2);
        if (nDistance > 0 && nRange < nDistance)
        {
            return 0;
        }

        if (nDistance <= 0)
        {
            return 1;
        }

        return UNITS_TestCollisionWithUnit(pUnit1, pUnit2, COLLIDE_MASK_PLAYER_FLYING) == 0;
    }

    return 0;
}

inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

// 0x00622D00
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* hUnit)
{
    if (!hUnit)
    {
        return 0;
    }

    switch (hUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        switch (UNITS_GetAnimOrSeqMode(hUnit))
        {
        case PLRMODE_WALK:
        case PLRMODE_RUN:
        case PLRMODE_TOWNWALK:
            return 1;

        default:
            return 0;
        }

    case UNIT_MONSTER:
        switch (UNITS_GetAnimModeInline(hUnit))
        {
        case MONMODE_WALK:
        case MONMODE_RUN:
            return 1;

        case MONMODE_SKILL1:
        case MONMODE_SKILL2:
            return MONSTERS_GetBaseIdFromMonsterId(sub_00463860(hUnit)) == MONSTER_VULTURE1;

        default:
            return 0;
        }

    case UNIT_MISSILE:
        D2_ASSERT(hUnit->dwUnitType != UNIT_MISSILE, 4901);
        return 0;

    default:
        return 0;
    }
}

#include "gen/data/Source/D2Common/UNITS/Units_00620510.inc"

// 0x00621210
static int __stdcall sub_00621210(D2UnitStrc* pUnit, int nPrevFrame)
{
    const int nOldMode = pUnit->dwSeqMode;
    int nFrame;
    int nDirection;
    int nEvent;
    DATATBLS_ComputeSequenceAnimation(pUnit->pAnimSeq, pUnit->dwSeqFrame, nPrevFrame, &nPrevFrame, &nFrame, &nDirection, &nEvent);
    pUnit->nSeqCurrentFramePrecise = nFrame << 8;
    pUnit->dwSeqMode = nPrevFrame;
    pUnit->nActionFrame = nEvent;
    return nPrevFrame != nOldMode;
}

// 0x00621260
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->pAnimSeq = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
        if (pUnit->pAnimSeq)
        {
            pUnit->dwSeqFrameCount = DATATBLS_GetSeqFramePointsCount(pUnit);
            pUnit->dwSeqFrame = 0;
            pUnit->dwSeqSpeed = 0x100;
            pUnit->dwFrameCountPrecise = DATATBLS_GetSeqFrameCount(pUnit) << 8;
            sub_00621210(pUnit, 0);
            pUnit->dwFlags |= 0x4000;
        }
    }
}

void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit)
{
    pUnit->nActionFrame = 0;

    if (pUnit->pAnimSeq)
    {
        const int nOldFrame = pUnit->dwSeqFrame;
        pUnit->dwFlags &= ~0x4000;
        pUnit->dwSeqFrame += pUnit->dwSeqSpeed;
        if (pUnit->dwSeqFrame >= pUnit->dwSeqFrameCount)
            pUnit->dwSeqFrame -= pUnit->dwSeqFrameCount;
        pUnit->dwFrameCountPrecise -= pUnit->dwSeqSpeed;
        if (sub_00621210(pUnit, nOldFrame))
            pUnit->dwFlags |= 0x4000;
    }
    else
    {
        int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
        if (pUnit->wAnimSpeed >= 0x100)
            nFrame++;

        pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

        while (pUnit->nSeqCurrentFramePrecise >= pUnit->dwFrameCountPrecise)
        {
            const int nFrameCount = pUnit->dwFrameCountPrecise >> 8;
            for (int i = nFrame; i < nFrameCount; i++)
            {
                if (pUnit->pAnimData && i < 144)
                {
                    if (pUnit->pAnimData->pFrameFlags[i] == 1)
                        pUnit->nActionFrame = 1;
                    if (pUnit->pAnimData->pFrameFlags[i] == 2)
                        pUnit->nActionFrame = 2;
                    if (pUnit->pAnimData->pFrameFlags[i] == 3)
                        pUnit->nActionFrame = 3;
                    if (pUnit->pAnimData->pFrameFlags[i] == 4)
                        pUnit->nActionFrame = 4;
                }
            }
            nFrame = 0;
            pUnit->nSeqCurrentFramePrecise -= pUnit->dwFrameCountPrecise;
            pUnit->nSeqCurrentFramePrecise += UNITS_GetFrameBonus(pUnit) << 8;
        }

        const int nLastFrameReached = pUnit->nSeqCurrentFramePrecise >> 8;
        for (; nFrame <= nLastFrameReached; nFrame++)
        {
            if (pUnit->pAnimData && nFrame < 144)
            {
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 1)
                    pUnit->nActionFrame = 1;
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 2)
                    pUnit->nActionFrame = 2;
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 3)
                    pUnit->nActionFrame = 3;
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 4)
                    pUnit->nActionFrame = 4;
            }
        }
    }
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nCharId)
{
    if (nCharId >= 0 && nCharId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nCharId];
    }

    return 0;
}

static __forceinline int UNITS_IsAnimModeBlocking_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 9;
        break;
    case 1:
        nMode = 6;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline int UNITS_IsAnimModeGetHit_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 4;
        break;
    case 1:
        nMode = 3;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline int UNITS_IsAnimModeKnockBack_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 0x13;
        break;
    case 1:
        nMode = 0xD;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline void UNITS_SetAnimationSpeed_Inl(D2UnitStrc* pUnit, int nSpeed)
{
    int nAnimSpeed = nSpeed > 0 ? nSpeed : 0;
    if (nAnimSpeed >= 0x7FFF)
    {
        nAnimSpeed = 0x7FFF;
    }

    pUnit->wAnimSpeed = (short)nAnimSpeed;
}

// 0x00621360
static int UNITS_GetBaseVelocity(int nUnitType, int nClassId)
{
    switch (nUnitType)
    {
    case 0:
        return DATATBLS_GetCharStatsTxtRecord_Inl(nClassId)->nWalkSpeed << 8;
    case 1:
        return DATATBLS_GetMonStatsTxtRecord_Inl(nClassId)->wVelocity << 8;
    }

    return 0;
}

// 0x006213D0
static int UNITS_GetBaseAnimSpeed(int nUnitType, int nClassId, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        return nAnimMode == 3 ? 0x65 : 0xD5;
    case 1:
    {
        const D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId);
        if (nAnimMode != 0xF)
        {
            return pMonStatsTxtRecord->nWalkAnimSpeed;
        }

        return pMonStatsTxtRecord->nRunAnimSpeed;
    }
    }

    return 0;
}

static __forceinline unsigned int DATATBLS_CheckMonStatsFlag_Inl(D2MonStatsTxt* pMonStatsTxtRecord)
{
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }

    return 0;
}

// 0x00621630
static int __stdcall UNITS_AnimModeAllowsAnimSpeed(int nUnitType, int nAnimMode, int nClassId)
{
    switch (nUnitType)
    {
    case 0:
        return gaPlayerModesAnimModulators_006E8A00[nAnimMode].bAllowAnimSpeed;
    case 1:
    {
        D2AnimModeModulatorStrc* pAnimModeModulators;
        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }

        return pAnimModeModulators->bAllowAnimSpeed;
    }
    }

    return 0;
}

// 0x006216E0
static int UNITS_IsSeqAnimSpeedModulatedByFCR(int nAnimMode, int nUnitType, D2UnitStrc* pUnit)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0xA)
        {
            return 1;
        }

        if (nAnimMode == 0x12 && pUnit)
        {
            if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\UNITS\\Units.cpp", 0xC48));
                if (pSkillsTxtRecord && pSkillsTxtRecord->nSeqTrans == 0xA)
                {
                    return 1;
                }
            }
        }

        break;
    case 1:
        if (nAnimMode == 7)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00621740
static int UNITS_GetAnimStatBasePercentage(D2UnitStrc* pUnit, int nStat)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, gaAnimModeStatBasePercentage_006E8E24[nStat].nStatId, 0);
    switch (gaAnimModeStatBasePercentage_006E8E24[nStat].bHasBasePercentage)
    {
    case 1:
        if (nValue)
        {
            return nValue * gaAnimModeStatBasePercentage_006E8E24[nStat].nBasePercentage / (nValue + gaAnimModeStatBasePercentage_006E8E24[nStat].nBasePercentage);
        }
        break;
    }

    return nValue;
}

void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine)
{
    if (!pUnit)
    {
        return;
    }

    int nUnitType = pUnit->dwUnitType;
    if (nUnitType >= 5)
    {
        return;
    }

    if (nUnitType == 4)
    {
        return;
    }

    int nClassId = pUnit->dwClassId;
    int nAnimMode = pUnit->dwAnimMode;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nAnimMode, ".\\UNITS\\Units.cpp", 0xCB9);
    sub_00620F00(pUnit, nUnitType, nClassId, nAnimMode);
    D2AnimDataRecordStrc* pAnimData = pUnit->pAnimData;

    if (UNITS_IsSeqAnimSpeedModulatedByFCR(nAnimMode, nUnitType, pUnit))
    {
        int nRate = UNITS_GetAnimStatBasePercentage(pUnit, 2) + 0x64;
        if (nRate > 0xAF)
        {
            nRate = 0xAF;
        }

        UNITS_SetAnimationSpeed_Inl(pUnit, nRate * pAnimData->dwAnimSpeed / 100);
        pUnit->dwSeqSpeed = pUnit->wAnimSpeed;
        return;
    }

    if (UNITS_IsAnimModeBlocking_Inl(nUnitType, nAnimMode))
    {
        const int nFasterBlockRate = UNITS_GetAnimStatBasePercentage(pUnit, 3);
        int nBlockRateBonus = 0x32;
        if (STATES_CheckState(pUnit, 0x65))
        {
            nBlockRateBonus = 0x64;
        }

        unsigned int nAnimSpeed = pAnimData->dwAnimSpeed * (nBlockRateBonus + nFasterBlockRate) / 100;
        if (nAnimSpeed < 1)
        {
            nAnimSpeed = 1;
        }

        UNITS_SetAnimationSpeed_Inl(pUnit, nAnimSpeed);
        return;
    }

    if (UNITS_IsAnimModeGetHit_Inl(nUnitType, nAnimMode))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, pAnimData->dwAnimSpeed * (UNITS_GetAnimStatBasePercentage(pUnit, 1) + 0x32) / 100);
        return;
    }

    if (UNITS_IsAnimModeKnockBack_Inl(nUnitType, nAnimMode))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, UNITS_GetBaseAnimSpeed(nUnitType, nClassId, nAnimMode));
        PATH_SetVelocity(pUnit->pDynamicPath, 0x1000, ".\\UNITS\\Units.cpp", 0xCE9);
        return;
    }

    if (UNITS_CanAnimModeUseVelocityModifier(nUnitType, nAnimMode, pUnit, nClassId))
    {
        if (pUnit->pDynamicPath)
        {
            const int nFasterMoveVelocity = UNITS_GetAnimStatBasePercentage(pUnit, 4);
            int nVelocityPercent = nFasterMoveVelocity + STATLIST_UnitGetStatValue(pUnit, 0x43, 0);
            if (nVelocityPercent < 0x19)
            {
                nVelocityPercent = 0x19;
            }

            UNITS_SetAnimationSpeed_Inl(pUnit, nVelocityPercent * UNITS_GetBaseAnimSpeed(nUnitType, nClassId, nAnimMode) / 100);
            PATH_SetVelocity(pUnit->pDynamicPath, nVelocityPercent * UNITS_GetBaseVelocity(nUnitType, nClassId) / 100, ".\\UNITS\\Units.cpp", 0xD0A);
        }
        return;
    }

    if (UNITS_CanAnimModeUseAttackRate(nAnimMode, nUnitType, pUnit, nClassId))
    {
        UNITS_MergeDualWieldWeaponStatLists(pUnit, 1);
        const int nFasterAttackRate = UNITS_GetAnimStatBasePercentage(pUnit, 0);
        int nRate = nFasterAttackRate + STATLIST_UnitGetStatValue(pUnit, 0x44, 0);
        if (UNITS_CanDualWield(pUnit))
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            if (!sub_0062A4E0_TestItem(pRightWeapon))
            {
                pRightWeapon = 0;
            }

            D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            if (!sub_0062A4E0_TestItem(pLeftWeapon))
            {
                pLeftWeapon = 0;
            }

            if (ITEMSIsA(pRightWeapon, 0x2D) && ITEMSIsA(pLeftWeapon, 0x2D))
            {
                const int nRightAttackRate = STATLIST_UnitGetStatValue(pRightWeapon, 0x44, 0);
                const int nLeftAttackRate = STATLIST_UnitGetStatValue(pLeftWeapon, 0x44, 0);
                nRate += (nRightAttackRate + nLeftAttackRate) / 2 - nRightAttackRate;
            }
        }

        if (!pUnit->dwUnitType && pUnit->dwAnimMode == 0x12)
        {
            nRate -= 0x1E;
        }

        if (nRate < 0xF)
        {
            nRate = 0xF;
        }
        else if (nRate > 0xAF)
        {
            nRate = 0xAF;
        }

        unsigned int nBaseSpeed = 0;
        if (STATES_CheckStateMaskOnUnit(pUnit, 0x26))
        {
            nBaseSpeed = D2Common_11043(pUnit);
        }

        if (!nBaseSpeed)
        {
            nBaseSpeed = pAnimData->dwAnimSpeed;
        }

        int nAnimSpeed = nRate * nBaseSpeed / 100;
        nAnimSpeed = nAnimSpeed > 0 ? nAnimSpeed : 0;
        if (nAnimSpeed >= 0x7FFF)
        {
            nAnimSpeed = 0x7FFF;
        }

        pUnit->dwSeqSpeed = (short)nAnimSpeed;
        pUnit->wAnimSpeed = (short)nAnimSpeed;
        return;
    }

    if (UNITS_AnimModeAllowsAnimSpeed(nUnitType, nAnimMode, nClassId))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, pAnimData->dwAnimSpeed);
        return;
    }

    int nOtherAnimRate = STATLIST_UnitGetStatValue(pUnit, 0x45, 0);
    if (nOtherAnimRate < 0xF)
    {
        nOtherAnimRate = 0xF;
    }
    else if (nOtherAnimRate > 0xAF)
    {
        nOtherAnimRate = 0xAF;
    }

    UNITS_SetAnimationSpeed_Inl(pUnit, nOtherAnimRate * pAnimData->dwAnimSpeed / 100);
}

static __forceinline int UNITS_IsWalkOrRunMode_Inl(int nAnimMode)
{
    switch (nAnimMode)
    {
    case 2:
    case 0xF:
        return 1;
    }

    return 0;
}

// 0x006214A0
static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimModeModulatorStrc* pAnimModeModulators;
    switch (nUnitType)
    {
    case 0:
        pAnimModeModulators = &gaPlayerModesAnimModulators_006E8A00[nAnimMode];
        break;
    case 1:
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId))
        {
            if (DATATBLS_CheckMonStatsFlag_Inl(pMonStatsTxtRecord))
            {
                return UNITS_IsWalkOrRunMode_Inl(nAnimMode);
            }
        }

        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }
        break;
    default:
        D2_ASSERT(nUnitType == 0 || nUnitType == 1, 0xBD2);
        return 0;
    }

    if (pAnimModeModulators->bCanUseVelocityModifier)
    {
        return 1;
    }

    if (pAnimModeModulators->bCanUseVelocityModifierByPassiveSkill)
    {
        if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
        {
            const int nFlags = SKILLS_GetFlags(pUsedSkill);
            if (!(nFlags & 1) || (nFlags & 0x1000))
            {
                return 0;
            }

            return 1;
        }
    }

    return 0;
}

int __stdcall sub_O05_Emit_006214A0(D2UnitStrc* pUnit, int nUnitType, int nAnimMode, int nClassId)
{
    if (UNITS_CanAnimModeUseVelocityModifier(nUnitType, nAnimMode, pUnit, nClassId))
    {
        return nClassId;
    }
    return 0;
}

// build: symbol ?UNITS_StoreOwnerInfo@@YGXPAUD2UnitStrc@@HH@Z 0x00621C30
static void __stdcall UNITS_StoreOwnerInfo(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    D2StatListStrc* pStatList = 0;

    if (pUnit)
    {
        pUnit->dwOwnerType = nOwnerType;
        pUnit->dwOwnerGUID = nOwnerId;

        if (pUnit->pStatListEx)
        {
            STATES_ToggleState(pUnit, 0x62, 1);
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x62);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pUnit->pMemoryPool, 0, 0, pUnit->dwUnitType, pUnit->dwUnitId);
                if (!pStatList)
                    return;

                STATLIST_SetState(pStatList, 0x62);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            }

            STATLIST_SetStat(pStatList, 0x161, nOwnerType, 0);
            STATLIST_SetStat(pStatList, 0x162, nOwnerId, 0);
        }

        pUnit->dwFlagEx |= 0x400;
    }
}

// 0x00621CC0
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    UNITS_StoreOwnerInfo(pUnit, nOwnerType, nOwnerId);
}

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    D2StatListStrc* pStatList = 0;

    if (pOwner)
    {
        UNITS_StoreOwnerInfo(pUnit, pOwner->dwUnitType, pOwner->dwUnitId);
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwOwnerType = 0;
            pUnit->dwOwnerGUID = 0;

            if (pUnit->pStatListEx)
            {
                STATES_ToggleState(pUnit, 0x62, 0);

                pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x62);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }

            pUnit->dwFlagEx &= ~0x400;
        }
    }
}

// 0x00621E40
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x80);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0x80, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }
        D2Common_10534(pUnit);
        D2Common_10531_SetStatInStatListLayer0(pStatList, 0xB2, (unsigned short)nOverlay, nUnused);
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x006223F0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit)
{
    int nDefense = STATLIST_UnitGetStatValue(pUnit, 0x1F, 0);
    nDefense += STATLIST_UnitGetStatValue(pUnit, 2, 0) / 4;
    int nArmorPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0xAB, 0);
    nArmorPercent += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 0x10, 0);

    if (STATES_CheckState(pUnit, 0x65))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x65);
        if (pStatList)
        {
            const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
            const int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
            if (nSkillId > 0 && nSkillLevel > 0)
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (pSkillsTxtRecord)
                {
                    D2UnitStrc* pShieldItem = 0;
                    INVENTORY_GetEquippedShield(pUnit->pInventory, &pShieldItem);
                    if (pShieldItem)
                    {
                        nArmorPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                    }
                }
            }
        }
    }

    if (nDefense > 0)
    {
        nDefense += nDefense * nArmorPercent / 100;
    }
    else
    {
        nDefense += nDefense * nArmorPercent / -100;
    }

    const int nArmorOverridePercent = STATLIST_UnitGetStatValue(pUnit, 0xB6, 0);
    if (nArmorOverridePercent)
    {
        nDefense += DATATBLS_ApplyRatio(nDefense, nArmorOverridePercent, 100);
    }
    return nDefense;
}

// 0x00622830
D2UnitStrc* __stdcall UNITS_GetEquippedWeaponFromMonster(D2UnitStrc* pMonster)
{
    D2UnitStrc* pItem;
    int bIsLeftHandItem;
    int nBodyLoc;

    const int nType = pMonster ? pMonster->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (!pMonster->pInventory)
    {
        return 0;
    }

    return INVENTORY_GetEquippedWeapon(pMonster->pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem) ? pItem : 0;
}

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x006220F0
unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName)
{
    D2_ASSERT(ptUnit, 0xF97);
    D2_ASSERT(ptUnit->pPlayerData, 0xF99);
    D2_ASSERT(ptUnit->dwUnitType == UNIT_PLAYER, 0xF9A);

    return SStrCopy(ptUnit->pPlayerData->szName, szName, 0x7FFFFFFF);
}

// 0x00622EA0
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x13F6);

        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        pPlayerData->nRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x13FA);
        pPlayerData->nRightSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622F10
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1405);

        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        pPlayerData->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1409);
        pPlayerData->nLeftSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622F80
void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1414);

        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        pPlayerData->nSwitchRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1419);
        pPlayerData->nSwitchRightSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622FF0
void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1424);

        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        pPlayerData->nSwitchLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1429);
        pPlayerData->nSwitchLeftSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00623060
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pRightSkillId, int* pRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pRightSkillId = 0;
        *pRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1438);

        *pRightSkillId = pPlayerData->nRightSkillId;
        *pRightSkillFlags = pPlayerData->nRightSkillFlags;
    }
}

// 0x006230C0
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pLeftSkillId, int* pLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pLeftSkillId = 0;
        *pLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1449);

        *pLeftSkillId = pPlayerData->nLeftSkillId;
        *pLeftSkillFlags = pPlayerData->nLeftSkillFlags;
    }
}

// 0x00623120
void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchRightSkillId = 0;
        *pSwitchRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x145A);

        *pSwitchRightSkillId = pPlayerData->nSwitchRightSkillId;
        *pSwitchRightSkillFlags = pPlayerData->nSwitchRightSkillFlags;

        pPlayerData->nRightSkillId = 0;
        pPlayerData->nRightSkillFlags = -1;
        pPlayerData->nWeaponGUID = -1;
        pPlayerData->unk0x94 = 0;
    }
}

// 0x006231A0
void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchLeftSkillId = 0;
        *pSwitchLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1470);

        *pSwitchLeftSkillId = pPlayerData->nSwitchLeftSkillId;
        *pSwitchLeftSkillFlags = pPlayerData->nSwitchLeftSkillFlags;

        pPlayerData->nLeftSkillId = 0;
        pPlayerData->nLeftSkillFlags = -1;
        pPlayerData->nWeaponGUID = -1;
        pPlayerData->unk0x94 = 0;
    }
}

// 0x00623220
void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchLeftSkillId = 0;
        *pSwitchLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1487);

        *pSwitchLeftSkillId = pPlayerData->nSwitchLeftSkillId;
        *pSwitchLeftSkillFlags = pPlayerData->nSwitchLeftSkillFlags;
    }
}

// 0x00623290
void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchRightSkillId = 0;
        *pSwitchRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x1499);

        *pSwitchRightSkillId = pPlayerData->nSwitchRightSkillId;
        *pSwitchRightSkillFlags = pPlayerData->nSwitchRightSkillFlags;
    }
}

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetXPosition(pUnit->pDynamicPath);
        return 0;
    }
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetYPosition(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x00623470
int __fastcall UNITS_CanSwitchAI(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
        return 0;
    if (!sub_0046C140_TestMonModeFlag(nMonsterId, MONMODE_WALK))
        return 0;
    if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7])
        return 0;
    return (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_SWITCHAI >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_SWITCHAI & 7]) != 0;
}

// 0x00623830
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit)
{
    int nY = UNITS_GetYPositionInline(pUnit);
    int nX = UNITS_GetXPositionInline(pUnit);
    COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), nX, nY, UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
}

// 0x00623C60
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (D2UnitStrc* pItem = D2Common_10434(pUnit, 1))
        return ITEMS_GetWeaponClassId(pItem);
    return 0;
}

// 0x00624690
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || pUnit->dwUnitType == UNIT_TILE)
        return 0;
    if (pUnit->dwAnimMode != nMode)
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwAnimMode = nMode;
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        STATLIST_DeactivateTemporaryStates(pUnit);
        sub_00624390_AnimInit(pUnit);
        return 1;
    }
    if (!(pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_NEUTRAL))
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
    }
    return 0;
}
