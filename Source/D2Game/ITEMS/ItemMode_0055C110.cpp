#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2StaticPathStrc;
struct D2BooksTxt;
struct D2SkillsTxt;
struct D2EquipmentRefreshStateStrc;

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

struct D2BooksTxt
{
    char unk0x00[0x08];
    int dwScrollSkillId;
    int dwBookSkillId;
};

struct D2SkillsTxt
{
    char unk0x00[0x14];
    unsigned char nRange;
    char unk0x15[0x18 - 0x14 - 1];
    short nITypeA[3];
};

struct D2EquipmentRefreshStateStrc
{
    int nHitpoints;
    int nMana;
    int nStamina;
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillOwnerGUID;
    int nLeftSkillOwnerGUID;
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    int* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    int unk0x24;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int unk0x2C;
    int nQuality;
    char unk0x34[0x40 - 0x34];
    int dwFlags1;
    int unk0x44;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    char unk0x50[0x84 - 0x50];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, int a3, int nStatId, int nValue, int a6); // 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGold); // 0x00540900
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAmount); // 0x0055B030
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50
void __fastcall D2GAME_ITEMS_UpdateItemStatlist_6FC42310(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0
void __fastcall sub_0055DBC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x0055DBC0
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId); // 0x00570080
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill); // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity); // 0x00645120
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D2E0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0
void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem);
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus);
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD);
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem);
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int bUnused, unsigned char nPage, const char* szFile, int nLine);
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem);
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem);
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused);
int __fastcall sub_6FC425F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055CC90
int __fastcall sub_6FC42F20(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x00562E00
int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C790
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60

typedef unsigned char U8;

typedef unsigned int U32;

struct Point
{
    int x;
    int y;
};

struct StaticPath
{
    U8 pad00[12];
    int x;
    int y;
};

struct Unit
{
    int type;
    int classId;
    U8 pad08[4];
    int id;
    int mode;
    U8 pad14[24];
    StaticPath* path;
    U8 pad30[48];
    void* inventory;
    U8 pad64[96];
    U32 flags;
};

struct Game
{
    U8 pad00[112];
    int expansion;
};

struct ItemRecord
{
    U8 pad00[128];
    U32 code;
};

extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void __fastcall sub_0053D010_Notify(void*, Unit*, Unit*, U32); // 0x0053D010
extern "C" Unit* __fastcall sub_00552F60_Find(Game*, int, int); // 0x00552F60
extern "C" void* __fastcall sub_005531C0_Client(Unit*, const char*, int); // 0x005531C0
extern "C" void* __fastcall sub_00555DA0_FreeSpot(void*, Point*, Point*, int, U8); // 0x00555DA0
extern "C" void __fastcall sub_00558AA0_Drop(Game*, Unit*, Unit*, void*, int, int); // 0x00558AA0
extern "C" void __fastcall sub_0055BF50_Check(Unit*, const char*, int); // 0x0055BF50
extern "C" void __fastcall sub_0055C270_Update(Unit*, Unit*); // 0x0055C270
extern "C" void __fastcall sub_0055C2C0_Apply(Game*, Unit*, Unit*, int); // 0x0055C2C0
extern "C" void __fastcall sub_0055DBC0_Refresh(Game*, Unit*, int); // 0x0055DBC0
extern "C" int __fastcall sub_0055F590_CheckItem(Unit*, const char*, int); // 0x0055F590
extern "C" void __fastcall sub_00568770_Special(Game*, Unit*, Unit*); // 0x00568770
extern "C" int __stdcall sub_00621050_Grid(Unit*, U8, int); // 0x00621050
extern "C" int __stdcall sub_006280A0_TestFlag(Unit*, U32, int, const char*); // 0x006280A0
extern "C" void __stdcall sub_006280D0_SetFlag(Unit*, U32, int); // 0x006280D0
extern "C" void __stdcall sub_00628170_CommandFlag(Unit*, U32, int); // 0x00628170
extern "C" U8 __stdcall sub_00628250_Page(Unit*); // 0x00628250
extern "C" void __stdcall sub_00628280_SetPage(Unit*, U8); // 0x00628280
extern "C" void __stdcall sub_00628320_SavePage(Unit*, U8); // 0x00628320
extern "C" void __stdcall sub_006287B0_Flags(U32*, U32, int); // 0x006287B0
extern "C" int __stdcall sub_0063B950_Place(void*, Unit*, int, int, U8, const char*, int); // 0x0063B950
extern "C" void __stdcall sub_0063BCF0_Trace(const char*, int, void*, int, int, int, int, U8); // 0x0063BCF0

static __forceinline int sub_E03_ItemGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int sub_E03_ItemGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static int sub_0055BFF0_GetBookSkillId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x1EC);

    if (ITEMS_CheckItemTypeId(pItem, 0x16) || ITEMS_CheckItemTypeId(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        if (pBooksTxtRecord)
        {
            if (ITEMS_CheckItemTypeId(pItem, 0x16))
            {
                return pBooksTxtRecord->dwScrollSkillId;
            }

            if (ITEMS_CheckItemTypeId(pItem, 0x12))
            {
                return pBooksTxtRecord->dwBookSkillId;
            }
        }
    }

    return -1;
}

static void __stdcall sub_0055C070_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x202);
    D2_ASSERT(pItem, 0x203);

    const int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId == -1)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        const int nQuantity = SKILLS_GetQuantity(pSkill) + nQuantityBonus;
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitType = pUnit->dwUnitType;
        const int nUnitGUID = pUnit->dwUnitId;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x20B), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
}

// 0x0055C110
static int __stdcall sub_0055C110_UpdateBookScrollSkillQuantity(int bAddQuantity, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nSkillId = sub_0055BFF0_GetBookSkillId(pItem);
    if (nSkillId != -1)
    {
        int nQuantity = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
        if (nQuantity || !ITEMS_CheckItemTypeId(pItem, 0x12))
        {
            if (!nQuantity)
            {
                nQuantity = 1;
            }

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            int nNewQuantity;
            if (bAddQuantity)
            {
                if (!pSkill)
                {
                    nNewQuantity = nQuantity;
                    STATLIST_AddUnitStat(pUnit, 5, nNewQuantity, 0);
                    sub_6FD136E0(pUnit, nSkillId);
                    pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                    D2_ASSERT(pSkill, 0x225);
                }
                else
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) + nQuantity;
                }
            }
            else
            {
                if (pSkill)
                {
                    nNewQuantity = SKILLS_GetQuantity(pSkill) - nQuantity;
                    if (nNewQuantity < 0)
                    {
                        nNewQuantity = 0;
                    }
                }
                else
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x230);
                    exit(-1);
                }
            }

            SKILLS_SetQuantity(pSkill, nNewQuantity);

            int nUnitGUID;
            int nUnitType;
            if (!pUnit)
            {
                nUnitGUID = -1;
                nUnitType = 6;
            }
            else
            {
                nUnitGUID = pUnit->dwUnitId;
                nUnitType = pUnit->dwUnitType;
            }

            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x234), nUnitType, nUnitGUID, nSkillId, nNewQuantity);

            if (!nNewQuantity)
            {
                if (UNITS_GetLeftSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 1, 0, -1);
                }

                if (UNITS_GetRightSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
                }
            }

            return 1;
        }
    }

    return 0;
}

void __fastcall sub_0055C270_OnItemToBelt(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x24D);
    D2_ASSERT(pItem, 0x24E);

    if (pUnit->dwUnitType == 0)
    {
        sub_0055C110_UpdateBookScrollSkillQuantity(1, pUnit, pItem);
    }
}

void __fastcall sub_0055C460_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats)
{
    D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, bAllowBrokenItemStats);
}

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

static __declspec(noinline) int sub_0055C4D0_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }

    return 1;
}

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

// 0x0055C560
static int __stdcall sub_0055C560_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], 0x30) || pSkillsTxtRecord->nRange != 2)
    {
        return 0;
    }

    return sub_0055C4D0_IsSkillUsable(pUnit, pSkill) != 0;
}

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

void __fastcall sub_0055C6E0_OnItemToCursor(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x394);
    D2_ASSERT(pItem, 0x395);

    if (pUnit->dwUnitType == 0)
    {
        sub_0055C110_UpdateBookScrollSkillQuantity(0, pUnit, pItem);
    }
}

// 0x0055C850
static void __stdcall sub_0055C850_PickupGold(D2GameStrc* pGame, D2UnitStrc* pGoldPile, D2UnitStrc* pUnit)
{
    const int nInventoryLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nUnitGold = STATLIST_UnitGetStatValue(pUnit, 0xE, 0);
    const int nPileGold = STATLIST_UnitGetStatValue(pGoldPile, 0xE, 0);
    int nRemainingGold = 0;
    int nPickedGold = nPileGold;
    if (nPileGold + nUnitGold > nInventoryLimit)
    {
        nPickedGold = nInventoryLimit - nUnitGold;
        nRemainingGold = nPileGold - nPickedGold;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pGoldPile);
    if (pOwner && pOwner->dwUnitType == 0)
    {
        PLRTRADE_AddGold(pUnit, 0xE, nPickedGold);
    }
    else if (SUNIT_GetPartyId(pUnit) != -1)
    {
        nRemainingGold = PARTY_ShareGoldDrop(pGame, pUnit, nPileGold);
    }
    else if (pUnit)
    {
        const int nNewGold = STATLIST_UnitGetStatValue(pUnit, 0xE, 0) + nPickedGold;
        if (nNewGold < 0)
        {
            STATLIST_SetUnitStat(pUnit, 0xE, 0, 0);
        }
        else if (pUnit->dwUnitType == 0 && nNewGold > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, 0xE, 0, 0);
        }
        else
        {
            STATLIST_AddUnitStat(pUnit, 0xE, nPickedGold, 0);
        }
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pGoldPile), !pGoldPile ? 6 : pGoldPile->dwUnitType, !pGoldPile ? -1 : pGoldPile->dwUnitId);
    UNITS_FreeCollisionPath(pGoldPile);
    UNITROOM_RemoveUnitFromRoom(pGoldPile);
    if (pGoldPile)
    {
        pGoldPile->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pGoldPile);

    if (nRemainingGold > 0)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nRemainingGold);
        SUNIT_AttachSound(pUnit, 0x17, pUnit);
    }
}

// 0x0055C9A0
static void __stdcall sub_0055C9A0_DropBackToGround(int nSoundId, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
    ITEMS_SetInvPage(pItem, 0xFF);
    if (pItem)
    {
        pItem->dwFlags |= 0x1000;
    }

    UNITS_ChangeAnimMode(pItem, 3);
    SUNIT_AttachSound(pUnit, nSoundId, pUnit);
}

// build: context D2GAME_PickupItemEx_6FC42B80
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x558);
    D2_ASSERT(pUnit, 0x559);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x55E);

    if (INVENTORY_GetCursorItem(pInventory) || PLAYER_IsBusy(pUnit))
    {
        return;
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x56E);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem || pItem->dwUnitType != 4)
    {
        return;
    }

    if (pItem->dwAnimMode != 3)
    {
        *pItemStatus = 1;
        return;
    }

    if (!ITEMMODE_CanPickUpItem(pGame, pUnit, pItem))
    {
        sub_0055C9A0_DropBackToGround(0x13, pItem, pUnit);
        return;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), pItem->dwUnitType, pItem->dwUnitId);

    if (ITEMS_GetItemType(pItem) == 4)
    {
        sub_0055C850_PickupGold(pGame, pItem, pUnit);
    }
    else
    {
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
        pItem->dwFlags &= ~2;
        INVENTORY_SetCursorItem(pInventory, pItem);
        UNITS_ChangeAnimMode(pItem, 4);
        ITEMS_SetItemCMDFlag(pItem, 0x40, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        UNITS_RefreshInventory(pUnit, 1);
        pItem->dwFlags &= ~0x02000000;
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        QUESTS_ItemPickedUp(pGame, pUnit, pItem);
    }

    SUNIT_AttachSound(pUnit, 1, pUnit);
}

// build: context sub_0055D970_UpdateEquippedItemStats
static void __stdcall sub_0055D970_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return;
    }

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0xB || nBodyLoc == 0xC)
    {
        return;
    }

    sub_0063D1D0_InventoryItemCall(pUnit->pInventory, pItem);

    if (UNITS_GetAnimOrSeqMode(pItem) == 1 || !UNITS_GetAnimOrSeqMode(pItem) && ITEMS_IsCharmUsable(pItem, pUnit))
    {
        D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 1);
    }
}

static void sub_0055D9D0_SaveEquipmentRefreshState(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState)
{
    pRefreshState->nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pRefreshState->nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
    pRefreshState->nStamina = STATLIST_UnitGetStatValue(pUnit, 10, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pRefreshState->nLeftSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pRefreshState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\ITEMS\\ItemMode.cpp", 0x9DF);
    }
    else
    {
        pRefreshState->nLeftSkillOwnerGUID = -1;
        pRefreshState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pRefreshState->nRightSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pRefreshState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\ITEMS\\ItemMode.cpp", 0x9EB);
    }
    else
    {
        pRefreshState->nRightSkillOwnerGUID = -1;
        pRefreshState->nRightSkillId = 0;
    }
}

static void sub_0055DA70_RestoreSelectedSkills(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState)
{
    if (pRefreshState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRefreshState->nLeftSkillId, pRefreshState->nLeftSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (SKILLS_GetUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;

            default:
                D2GAME_AssignSkill_6FD13800(pUnit, 1, pRefreshState->nLeftSkillId, pRefreshState->nLeftSkillOwnerGUID);
                break;
            }
        }
    }

    if (pRefreshState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRefreshState->nRightSkillId, pRefreshState->nRightSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (SKILLS_GetUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;

            default:
                D2GAME_AssignSkill_6FD13800(pUnit, 0, pRefreshState->nRightSkillId, pRefreshState->nRightSkillOwnerGUID);
                break;
            }
        }
    }
}

// 0x0055E000
static void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pItem, 0);
}

static int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem)
{
    int nSkillId = -1;
    if (ITEMS_CheckItemTypeId(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFA4);
        nSkillId = pBooksTxtRecord->dwBookSkillId;
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x16))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFAB);
        nSkillId = pBooksTxtRecord->dwScrollSkillId;
    }

    return nSkillId;
}

// build: context sub_0055E590_MergeStacks
static void __stdcall sub_0055E590_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2)
{
    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    const int nSrcValue = STATLIST_UnitGetStatValue(pItem1, 0x46, 0);
    D2_ASSERT(nSrcValue >= 0, 0x114B);

    const int nDstValue = STATLIST_UnitGetStatValue(pItem2, 0x46, 0);
    D2_ASSERT(nDstValue >= 0, 0x114D);

    const int nMaxStack = ITEMS_GetTotalMaxStack(pItem2);
    D2_ASSERT(nMaxStack >= 0, 0x114F);

    const int nQuantity = nSrcValue + nDstValue;
    if (nQuantity > nMaxStack)
    {
        STATLIST_SetUnitStat(pItem2, 0x46, nMaxStack, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1155), pItem2, 1, 0x46, nMaxStack, 0);

        const int nRemaining = nDstValue - nMaxStack + nSrcValue;
        D2_ASSERT(nRemaining >= 0, 0x1158);

        STATLIST_SetUnitStat(pItem1, 0x46, nRemaining, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x115B), pItem1, 1, 0x46, nRemaining, 0);

        if (ITEMS_GetItemType(pItem1) == 0x12 && ITEMS_GetItemType(pItem2) == 0x12)
        {
            sub_0055C070_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pItem2) - nDstValue, pUnit, pItem2);
        }

        ITEMS_SetItemFlag(pItem2, 8, 1);
    }
    else
    {
        if (ITEMS_HasDurability(pItem1))
        {
            const int nDurability = STATLIST_UnitGetStatValue(pItem1, 0x48, 0);
            if (nDurability < STATLIST_UnitGetStatValue(pItem2, 0x48, 0))
            {
                STATLIST_SetUnitStat(pItem2, 0x48, nDurability, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1170), pItem2, 1, 0x48, nDurability, 0);
            }
        }

        D2_ASSERT(nQuantity >= 0, 0x1176);

        STATLIST_SetUnitStat(pItem2, 0x46, nQuantity, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1179), pItem2, 1, 0x46, nQuantity, 0);

        if (ITEMS_GetItemType(pItem1) == 0x12 && ITEMS_GetItemType(pItem2) == 0x12)
        {
            sub_0055C070_AddBookScrollSkillQuantity(nSrcValue, pUnit, pItem2);
        }

        INVENTORY_SetCursorItem(pInventory, 0);
        D2GAME_PACKETS_SendPacket0x42_6FC3EE40(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1184), pUnit);
        ITEMS_RemoveFromAllPlayers(pGame, pItem1);
    }
}

int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x1192);
    D2_ASSERT(pUnit, 0x1193);

    *pItemStatus = 0;
    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1198);

    if (nItemGUID1 == nItemGUID2)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2UnitStrc* pItem1 = SUNIT_GetServerUnit(pGame, 4, nItemGUID1);
    if (!pItem1)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem1->dwUnitType != 4)
    {
        return 0;
    }

    D2UnitStrc* pItem2 = SUNIT_GetServerUnit(pGame, 4, nItemGUID2);
    if (!pItem2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem2->dwUnitType != 4)
    {
        return 0;
    }

    if (ITEMS_GetInvPage(pItem2) == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return 0;
    }

    if (pItem1->dwClassId != pItem2->dwClassId)
    {
        return 1;
    }

    sub_0055E590_MergeStacks(pGame, pItem1, pUnit, pItem2);
    ITEMS_SetItemCMDFlag(pItem2, 0x100, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem2);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}

static void __stdcall sub_0055E8E0_InitItemDrop(int nId, D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    memset(pItemDrop, 0, sizeof(D2ItemDropStrc));
    pItemDrop->pGame = pGame;
    pItemDrop->nItemLvl = ITEMS_GetItemLevel(pItem);
    pItemDrop->wItemFormat = pGame->wItemFormat;
    pItemDrop->nId = nId;
    pItemDrop->nSpawnType = 4;
    pItemDrop->nX = sub_E03_ItemGetUnitX(pItem);
    pItemDrop->nY = sub_E03_ItemGetUnitY(pItem);
    pItemDrop->pSeed = pItem->pSeed;
    pItemDrop->wUnitInitFlags = 1;
    pItemDrop->nQuality = 2;
    pItemDrop->dwSeed = pItem->dwInitSeed;
    const unsigned int nItemSeed = ITEMS_GetItemStartSeed(pItem);
    pItemDrop->dwFlags1 = 2;
    pItemDrop->dwItemSeed = nItemSeed;
}

int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x144E);
    D2_ASSERT(pUnit, 0x144F);

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1452);

    *pItemStatus = 0;

    D2UnitStrc* pScroll = SUNIT_GetServerUnit(pGame, 4, nScrollGUID);
    if (!pScroll)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pScroll->dwUnitType != 4)
    {
        return 0;
    }

    if (pScroll->dwAnimMode != 3 && pScroll->dwAnimMode != 4 || !ITEMS_CheckItemTypeId(pScroll, 0x16))
    {
        *pItemStatus = 1;
        return 0;
    }

    D2UnitStrc* pBook = SUNIT_GetServerUnit(pGame, 4, nBookGUID);
    if (!pBook)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pBook->dwUnitType != 4)
    {
        return 0;
    }

    if (pBook->dwAnimMode != 0 || ITEMS_GetItemType(pBook) != 0x12)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x1481);

    if (ITEMS_GetSuffixId(pBook, 0) == ITEMS_GetSuffixId(pScroll, 0))
    {
        if (STATLIST_UnitGetStatValue(pBook, 0x46, 0) >= ITEMS_GetTotalMaxStack(pBook))
        {
            return 0;
        }

        if (!D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pUnit, pScroll))
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pScroll);
            if (pRoom)
            {
                DUNGEON_AllocDrlgDelete(pRoom, pScroll->dwUnitType, pScroll->dwUnitId);
                UNITS_FreeCollisionPath(pScroll);
                UNITROOM_RemoveUnitFromRoom(pScroll);
            }

            pScroll->dwFlags &= ~2;
            ITEMS_RemoveFromAllPlayers(pGame, pScroll);
            INVENTORY_SetCursorItem(pInventory, 0);
        }

        STATLIST_AddUnitStat(pBook, 0x46, 1, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1494), pBook, 1, 0x46, STATLIST_UnitGetStatValue(pBook, 0x46, 0), 0);
        sub_0055C070_AddBookScrollSkillQuantity(1, pUnit, pBook);
        return 1;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x149C);
    exit(-1);
}

int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 0x15F3);
    D2_ASSERT(pUnit, 0x15F4);

    sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x15F7);

    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pUnit->pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMS_CheckItemTypeId(pItem, 0x29) && !ITEMS_GetInvPage(pItem))
        {
            if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) - 1 > 0)
            {
                STATLIST_AddUnitStat(pItem, 0x46, -1, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1605), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, 0x46, 0), 0);
                return 1;
            }

            sub_0055E000_RemoveItemAndNotify(pGame, pUnit, pItem);
            return 1;
        }
    }

    return 0;
}

void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2EquipmentRefreshStateStrc refreshState;
    sub_0055D9D0_SaveEquipmentRefreshState(pUnit, &refreshState);

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        int nStatNotDynamic = 0;
        if (pItem && pItem->dwUnitType == 4 && STATLIST_GetOwner(pItem, &nStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
        }

        pCurrent = pNext;
    }

    sub_0055DA70_RestoreSelectedSkills(pUnit, &refreshState);
}

// 0x0055F6E0
void __fastcall sub_0055F6E0_AddItemQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue)
{
    STATLIST_AddUnitStat(pItem, 0x46, nValue, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x18E0), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, 0x46, 0), 0);
    sub_0055C070_AddBookScrollSkillQuantity(nValue, pUnit, pItem);
}

void __fastcall sub_0055F900_EquipItemRefresh(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }

    ITEMS_SetItemFlag(pItem, 0x200, 1);
    ITEMS_SetItemFlag(pItem, 0x100, 0);
    if (pInventory)
    {
        sub_0055D970_UpdateEquippedItemStats(pGame, pItem, pUnit);
        sub_0055DBC0(pGame, pUnit, 0);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
    if (nMaxDurability > 0)
    {
        STATLIST_SetUnitStat(pItem, 0x48, nMaxDurability, 0);
        if (pUnit)
        {
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x193C), pItem, 1, 0x48, nMaxDurability, 0);
        }
    }

    ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    if (pUnit)
    {
        sub_0055C5C0_RefreshSkillsForEquippedWeapons(pUnit);
    }
}

int __fastcall sub_E03_EmitItemDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nId)
{
    D2ItemDropStrc itemDrop;
    sub_0055E8E0_InitItemDrop(nId, pGame, pItem, &itemDrop);
    sub_0055E000_RemoveItemAndNotify(pGame, pUnit, pItem);
    return sub_00558D90_SpawnItem(pGame, &itemDrop, 0) != 0;
}

int __fastcall sub_E03_EmitBookSkillA(D2UnitStrc* pItem)
{
    return sub_0055E050_GetBookSkillIdChecked(pItem);
}

static int __stdcall sub_0055D0D0_AutoStackPickup(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pStackItem = 0;
    int nCounter = 0;

    while (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0)
    {
        ++nCounter;

        if (ITEMS_GetAutoStack(pItem))
        {
            if (ITEMS_GetQuiverType(pItem))
            {
                pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
                if (!pStackItem)
                {
                    pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
                }
            }
            else
            {
                pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
            }
        }

        if (!pStackItem)
        {
            return 0;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity1 = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
            const int nQuantity2 = STATLIST_UnitGetStatValue(pStackItem, 0x46, 0);
            if (nQuantity1 + nQuantity2 > ITEMS_GetTotalMaxStack(pStackItem))
            {
                const int nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
                D2_ASSERT(nMaxStack >= 0, 0x5C7);

                STATLIST_SetUnitStat(pStackItem, 0x46, nMaxStack, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5CA), pStackItem, 1, 0x46, nMaxStack, 0);

                const int nRest = nQuantity2 - nMaxStack + nQuantity1;
                D2_ASSERT(nRest >= 0, 0x5CC);

                STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);

                if (ITEMS_GetItemType(pItem) == 0x12 && ITEMS_GetItemType(pStackItem) == 0x12)
                {
                    sub_0055C070_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pStackItem) - nQuantity2, pUnit, pStackItem);
                }
            }
            else
            {
                const int nQuantity = nQuantity2 + nQuantity1;
                D2_ASSERT(nQuantity >= 0, 0x5D7);

                if (ITEMS_HasDurability(pItem))
                {
                    const int nDurability = STATLIST_UnitGetStatValue(pItem, 0x48, 0);
                    if (nDurability < STATLIST_UnitGetStatValue(pStackItem, 0x48, 0))
                    {
                        STATLIST_SetUnitStat(pStackItem, 0x48, nDurability, 0);
                        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5E4), pStackItem, 1, 0x48, nDurability, 0);
                    }
                }

                STATLIST_SetUnitStat(pStackItem, 0x46, nQuantity, 0);
                STATLIST_SetUnitStat(pItem, 0x46, 0, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x5ED), pStackItem, 1, 0x46, nQuantity, 0);

                if (ITEMS_GetItemType(pItem) == 0x12 && ITEMS_GetItemType(pStackItem) == 0x12)
                {
                    sub_0055C070_AddBookScrollSkillQuantity(nQuantity1, pUnit, pStackItem);
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                if (pRoom)
                {
                    DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (pItem)
                {
                    pItem->dwFlags &= ~2;
                }

                ITEMS_RemoveFromAllPlayers(pGame, pItem);
                INVENTORY_SetCursorItem(pInventory, 0);
                return 1;
            }
        }
    }

    if (nCounter)
    {
        D2_ASSERT(0, 0x606);
    }

    return 0;
}

int __stdcall sub_0055D370_TryMergeBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x622);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pInventory, pItem, 0);
    if (!pBook)
    {
        return 0;
    }

    const int nSrcValue = STATLIST_UnitGetStatValue(pItem, 0x46, 0);
    D2_ASSERT(nSrcValue >= 0, 0x62E);

    const int nDstValue = STATLIST_UnitGetStatValue(pBook, 0x46, 0);
    D2_ASSERT(nDstValue >= 0, 0x630);

    const int nDstMaxValue = ITEMS_GetTotalMaxStack(pBook);
    D2_ASSERT(nDstMaxValue >= 0, 0x632);

    const int nQuantity = nDstValue + nSrcValue;
    if (nQuantity > nDstMaxValue)
    {
        STATLIST_SetUnitStat(pBook, 0x46, nDstMaxValue, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x638), pBook, 1, 0x46, nDstMaxValue, 0);

        const int nRest = nDstValue - nDstMaxValue + nSrcValue;
        D2_ASSERT(nRest >= 0, 0x63A);

        STATLIST_SetUnitStat(pItem, 0x46, nRest, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x63D), pItem, 1, 0x46, nRest, 0);
        sub_0055C070_AddBookScrollSkillQuantity(nDstMaxValue - nDstValue, pUnit, pBook);
        return 1;
    }

    D2_ASSERT(nQuantity >= 0, 0x645);

    STATLIST_SetUnitStat(pBook, 0x46, nQuantity, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x648), pBook, 1, 0x46, nQuantity, 0);
    sub_0055C070_AddBookScrollSkillQuantity(nSrcValue, pUnit, pBook);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    if (pItem)
    {
        pItem->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pItem);
    INVENTORY_SetCursorItem(pInventory, 0);
    return 1;
}

static int sub_0055FFA0_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScroll)
{
    D2_ASSERT(pGame, 0x610);

    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pUnit->pInventory, pScroll, 0);
    if (pBook)
    {
        int nItemStatus;
        const int nBookGUID = pBook->dwUnitId;
        return ITEMMODE_AddScrollToBook(pGame, pUnit, !pScroll ? -1 : pScroll->dwUnitId, nBookGUID, &nItemStatus);
    }

    return 0;
}

static int sub_00560020_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x65F);

    if (ITEMS_CheckItemTypeId(pItem, 0x16))
    {
        return sub_0055FFA0_AddScrollToBook(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x12))
    {
        return sub_0055D370_TryMergeBookQuantity(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckIfStackable(pItem) && ITEMS_GetAutoStack(pItem))
    {
        return sub_0055D0D0_AutoStackPickup(pGame, pUnit, pItem);
    }

    return 0;
}

static int __stdcall sub_005600A0_PlaceItemInInventory(D2GameStrc* pGame, int bRemove, int nPage, const char* szFile, int nLine, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x746);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x749);

    if (INVENTORY_PlaceItemAtFreePosition(pInventory, pItem, UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion), 0, 0, szFile, nLine))
    {
        if (bRemove)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
            if (pRoom)
            {
                const int nUnitGUID = !pItem ? -1 : pItem->dwUnitId;
                const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
                DUNGEON_AllocDrlgDelete(pRoom, nUnitType, nUnitGUID);
                UNITS_FreeCollisionPath(pItem);
                UNITROOM_RemoveUnitFromRoom(pItem);
            }
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
        {
            INVENTORY_SetCursorItem(pInventory, 0);
            sub_0055C270_OnItemToBelt(pUnit, pItem);

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 0);
            }

            if (pItem)
            {
                pItem->dwFlags &= ~2u;
            }

            UNITS_ChangeAnimMode(pItem, 0);
            ITEMS_SetItemCMDFlag(pItem, 0x80, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pUnit, 1);

            if (pItem)
            {
                pItem->dwFlags &= ~0x02000000u;
            }

            ITEMS_SetInvPage(pItem, nPage);
            QUESTS_ItemPickedUp(pGame, pUnit, pItem);

            if (ITEMS_IsCharmUsable(pItem, pUnit))
            {
                sub_0055DBC0(pGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        D2_ASSERT(0, 0x76F);
    }

    return 0;
}

// 0x00563560
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x77A);
    D2_ASSERT(pUnit, 0x77B);

    *pItemStatus = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x780);

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType == 4)
    {
        if (pItem->dwAnimMode != 3)
        {
            *pItemStatus = 1;
            return 0;
        }

        sub_0055BF50_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x7A2);

        if (!sub_6FC425F0(pGame, pUnit, pItem))
        {
            sub_0055C9A0_DropBackToGround(0x13, pItem, pUnit);
            return 0;
        }

        SUNIT_AttachSound(pUnit, 1, pUnit);

        if (ITEMS_GetItemType(pItem) == 4)
        {
            sub_0055C850_PickupGold(pGame, pItem, pUnit);
            return 1;
        }

        if (!sub_00560020_PickupStackable(pGame, pUnit, pItem))
        {

            if (sub_6FC42F20(pUnit, pItem, &nItemGUID, 0))
            {
                if (D2Common_10299(pUnit, nItemGUID, pItem, 0) != 1)
                {
                    *pItemStatus = 1;
                    return 0;
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                if (pRoom)
                {
                    DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (ITEMMODE_EquipItemAtResolvedBodyLocation(pGame, pUnit, pItem, 0))
                {
                    QUESTS_ItemPickedUp(pGame, pUnit, pItem);
                    return 1;
                }
            }
            else if (ITEMS_CheckIfBeltable(pItem) && ITEMS_CheckIfAutoBeltable(pInventory, pItem) && INVENTORY_PlaceItemInFreeBeltSlot(pInventory, pItem))
            {
                if (UNITS_GetRoom(pItem))
                {
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
                {
                    INVENTORY_SetCursorItem(pInventory, 0);
                    sub_0055C270_OnItemToBelt(pUnit, pItem);

                    if (ITEMS_IsCharmUsable(pItem, pUnit))
                    {
                        D2GAME_ITEMS_UpdateItemStatlist_6FC42310(pGame, pItem, pUnit, 0);
                    }

                    pItem->dwFlags &= ~2u;
                    UNITS_ChangeAnimMode(pItem, 2);
                    ITEMS_SetInvPage(pItem, 0xFF);
                    ITEMS_SetItemCMDFlag(pItem, 0x2000, 1);
                    pItem->dwFlags &= ~0x02000000u;
                    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                    UNITS_RefreshInventory(pUnit, 1);

                    if (ITEMS_IsCharmUsable(pItem, pUnit))
                    {
                        sub_0055DBC0(pGame, pUnit, 0);
                        UNITS_RefreshInventory(pUnit, 1);
                    }

                    return 1;
                }

                D2_ASSERT(0, 0x7ED);
            }
            else
            {
                if (sub_005600A0_PlaceItemInInventory(pGame, 1, 0, ".\\ITEMS\\ItemMode.cpp", 0x7EF, pUnit, pItem))
                {
                    return 1;
                }

                sub_0055C9A0_DropBackToGround(0x17, pItem, pUnit);
            }
        }
    }

    return 0;
}

// 0x00563840
static __declspec(noinline) void __stdcall sub_00563840_Contents(Game* game, Unit* box, Unit* player)
{
    int classId;
    if (!box) classId = -1;
    else classId = box->classId;
    ItemRecord* record = sub_006335F0_Record(classId);
    D2_ASSERT(record, 0x7FF);
    if (record->code != 0x20786F62) return;
    void* inventory = player->inventory;
    Unit* node = sub_0063B2C0_First(inventory);
    while (node) {
        Unit* item = sub_0063DFD0_Item(node);
        Unit* next = sub_0063DFA0_Next(node);
        if (sub_00628250_Page(item) == 3) {
            U32 flags = 0;
            sub_006287B0_Flags(&flags, 32, 1);
            sub_00628320_SavePage(box, 3);
            sub_0053D010_Notify(sub_005531C0_Client(player, ".\\ITEMS\\ItemMode.cpp", 0x80D), player, item, flags);
            Unit* removed = sub_0063AD90_Remove(inventory, item);
            D2_ASSERT(removed, 0x80F);
            D2_ASSERT(item == removed, 0x810);
            U8 page = sub_00628250_Page(item);
            int grid = sub_00621050_Grid(player, page, game->expansion);
            int y;
            switch (item->type) {
            case 2: case 4: case 5: y = item->path->y; break;
            default: y = item->path ? sub_00648900_Y(item->path) : 0; break;
            }
            int x;
            switch (item->type) {
            case 2: case 4: case 5: x = item->path->x; break;
            default: x = item->path ? sub_006488C0_X(item->path) : 0; break;
            }
            sub_0063BCF0_Trace(".\\ITEMS\\ItemMode.cpp", 0x813, inventory, x, y, grid, 0, page);
            sub_00624690_Mode(removed, 4);
            sub_00628280_SetPage(item, 0);
            int itemId = item->id;
            sub_0055BF50_Check(player, ".\\ITEMS\\ItemMode.cpp", 0x87B);
            Unit* placed = sub_00552F60_Find(game, 4, itemId);
            if (!placed || placed->type != 4 || placed->mode != 4) goto dropFailure;
            {
                U8 targetPage = sub_00628250_Page(placed);
                void* targetInventory = player->inventory;
                if (!targetInventory) goto dropFailure;
                int special = 0;
                int clearCursor = 1;
                int targetGrid = sub_00621050_Grid(player, targetPage, game->expansion);
                if (player->type == 0) {
                    switch (targetPage) {
                    case 1: clearCursor = 0; break;
                    case 2: special = 1; break;
                    }
                }
                if (!sub_0063B950_Place(targetInventory, placed, targetGrid, 0, targetPage, ".\\ITEMS\\ItemMode.cpp", 0x817)) goto dropFailure;
                if (!sub_0063B210_Add(targetInventory, placed, 1)) goto dropFailure;
                if (sub_00628250_Page(placed) != 4) sub_0055C270_Update(player, placed);
                placed->flags &= -3;
                if (sub_0062FF70_Check(placed, player)) sub_0055C2C0_Apply(game, placed, player, 0);
                if (clearCursor) sub_0063C180_Cursor(targetInventory, 0);
                sub_00624690_Mode(placed, 0);
                sub_00628170_CommandFlag(placed, 2, 1);
                if (sub_0055F590_CheckItem(placed, ".\\ITEMS\\ItemMode.cpp", 0x8EA)) sub_006280D0_SetFlag(placed, 1, 1);
                if (sub_006280A0_TestFlag(placed, 0x4000, 0x8EE, ".\\ITEMS\\ItemMode.cpp")) sub_006280D0_SetFlag(placed, 0x4000, 0);
                sub_00621000_SetFlag(player, 1);
                sub_0063CC70_Refresh(targetInventory, placed);
                if (special == 1) sub_00568770_Special(game, player, placed);
                if (sub_0062FF70_Check(placed, player)) {
                    sub_0055DBC0_Refresh(game, player, 0);
                    sub_00621000_SetFlag(player, 1);
                }
                goto nextItem;
            }
        dropFailure:
            sub_00628280_SetPage(item, 255);
            Point playerPosition;
            Point dropPosition;
            sub_00620870_Position(player, &playerPosition);
            void* room = sub_00555DA0_FreeSpot(sub_00620BB0_Room(player), &playerPosition, &dropPosition, 1, 1);
            if (!room) continue;
            sub_00558AA0_Drop(game, player, item, room, dropPosition.x, dropPosition.y);
        }
    nextItem:
        node = next;
    }
}

// 0x00563C00
extern "C" void __fastcall sub_00563C00_Drop(Game* game, Unit* player, int itemId)
{
    D2_ASSERT(game, 0x833);
    D2_ASSERT(player, 0x834);
    sub_0055BF50_Check(player, ".\\ITEMS\\ItemMode.cpp", 0x837);
    Unit* item = sub_00552F60_Find(game, 4, itemId);
    if (!item || item->type != 4 || item->mode != 4) return;
    Point playerPosition;
    Point dropPosition;
    sub_00620870_Position(player, &playerPosition);
    void* room = sub_00555DA0_FreeSpot(sub_00620BB0_Room(player), &playerPosition, &dropPosition, 1, 1);
    if (!room) return;
    sub_00558AA0_Drop(game, player, item, room, dropPosition.x, dropPosition.y);
    sub_0063C180_Cursor(player->inventory, 0);
    if (sub_0055F590_CheckItem(item, ".\\ITEMS\\ItemMode.cpp", 0x85B)) sub_006280D0_SetFlag(item, 1, 1);
    if (sub_006280A0_TestFlag(item, 0x4000, 0x85E, ".\\ITEMS\\ItemMode.cpp")) sub_006280D0_SetFlag(item, 0x4000, 0);
    sub_00563840_Contents(game, item, player);
}
