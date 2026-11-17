struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk14[0x60-0x14];
    D2InventoryStrc* pInventory;
};
struct D2BooksTxt
{
    char unk00[8];
    int dwScrollSkillId;
    int dwBookSkillId;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" const char szItemModeCpp[]; // 0x006E1164
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*, const char*, int); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc*, unsigned char, int, int); // 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc*, unsigned char, int, int, int); // 0x0053C520
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc*, D2UnitStrc*, int, int, int, int); // 0x0053D130
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, unsigned int); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0055DF10
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc*, const char*, int); // 0x0055BF50
void __fastcall sub_00561E70_RemoveFromBelt(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00561E70
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc*, D2UnitStrc*, int); // 0x005678A0
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005BF240
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*, int); // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc*); // 0x0062B400
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc*, int); // 0x00627F80
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int); // 0x006374B0
void __stdcall ITEMS_SetOrRemoveFlag(int*, int, int); // 0x006287B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0
int __stdcall SKILLS_GetQuantity(D2SkillStrc*); // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc*, int); // 0x00645120
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0

static __declspec(noinline) void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc*, D2UnitStrc*, D2UnitStrc*);
// 0x0055E000
static void __stdcall sub_0055E000_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem_6FC471F0(pGame, pUnit, pItem, 0);
}

static __declspec(noinline) int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc*);
// 0x0055E050
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

static __declspec(noinline) void __stdcall sub_0055E0D0_DecrementBookScrollSkillQuantity(D2UnitStrc*, int);
// 0x0055E0D0
static void __stdcall sub_0055E0D0_DecrementBookScrollSkillQuantity(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
        if (nQuantity <= 0)
        {
            if (UNITS_GetRightSkill(pUnit) == pSkill)
                D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
            nQuantity = 0;
        }
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0xFC2), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFC4);
        exit(-1);
    }
}

// 0x00561ED0
int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus)
{
    D2_ASSERT(pGame, 0xFCF);
    D2_ASSERT(pUnit, 0xFD0);
    D2UnitStrc* pTargetItem = SUNIT_GetServerUnit(pGame, 4, nTargetGUID);
    D2UnitStrc* pUseItem = SUNIT_GetServerUnit(pGame, 4, nUseItemGUID);
    *pItemStatus = 0;
    if (!pUseItem)
    {
        *pItemStatus = 1;
        return 0;
    }
    if (!pTargetItem || pTargetItem == pUseItem)
    {
        sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0xFDD);
        return 0;
    }
    if ((!pUseItem ? 0 : pUseItem->dwAnimMode) == 2 && !ITEMS_CheckItemTypeId(pUseItem, 0x16))
    {
        *pItemStatus = 1;
        return 0;
    }
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        *pItemStatus = 0;
        return 0;
    }
    if ((!pTargetItem ? 6 : pTargetItem->dwUnitType) != 4 || pUseItem->dwUnitType != 4)
        return 0;
    if ((!pTargetItem ? 6 : pTargetItem->dwUnitType) != (!pUseItem ? 6 : pUseItem->dwUnitType))
    {
        sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x1004);
        return 0;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
        return 0;
    const int nTargetAnimMode = pTargetItem->dwAnimMode;
    const int nUseItemAnimMode = pUseItem->dwAnimMode;
    if (nTargetAnimMode != 0 && nTargetAnimMode != 1)
    {
        if (nUseItemAnimMode == 2)
        {
            sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x1010);
            sub_00561E70_RemoveFromBelt(pGame, pUnit, pUseItem);
        }
        else if (nUseItemAnimMode == 0)
        {
            if (ITEMS_GetItemType(pUseItem) == 0x12)
            {
                int nQuantity = STATLIST_UnitGetStatValue(pUseItem, 0x46, 0) - 1;
                if (nQuantity < 0)
                    nQuantity = 0;
                STATLIST_SetUnitStat(pUseItem, 0x46, nQuantity, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0x1019), pUseItem, 1, 0x46, nQuantity, 0);
            }
        }
        else
        {
            *pItemStatus = 1;
        }
        return 0;
    }
    if (ITEMS_GetItemType(pUseItem) == 0x12 && STATLIST_UnitGetStatValue(pUseItem, 0x46, 0) <= 0)
    {
        sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x1023);
        const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
        const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0x1024), 0x7C, nUnitType, nUnitGUID);
        return 0;
    }
    if (!SKILLITEM_pSpell_Handler(pGame, pUnit, pUseItem, pTargetItem, 0, 0))
        goto Success;
    if (nUseItemAnimMode == 2)
    {
        const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pUseItem);
        if (nSkillId != -1)
        {
            sub_0055E0D0_DecrementBookScrollSkillQuantity(pUnit, nSkillId);
            sub_00561E70_RemoveFromBelt(pGame, pUnit, pUseItem);
            sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x1034);
            goto Success;
        }
        const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
        const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0x1032), 0x7C, nUnitType, nUnitGUID);
        sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x1034);
        goto Success;
    }
    if (nUseItemAnimMode)
    {
        *pItemStatus = 1;
        return 0;
    }
    if (ITEMS_GetItemType(pUseItem) == 0x12)
    {
        const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pUseItem);
        if (nSkillId != -1 && STATLIST_UnitGetStatValue(pUseItem, 0x46, 0) > 0)
        {
            STATLIST_AddUnitStat(pUseItem, 0x46, -1, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0x103C), pUseItem, 1, 0x46, STATLIST_UnitGetStatValue(pUseItem, 0x46, 0), 0);
            sub_0055E0D0_DecrementBookScrollSkillQuantity(pUnit, nSkillId);
            const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
            const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, szItemModeCpp, 0x104A), 0x7C, nUnitType, nUnitGUID);
            sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x104C);
            return 1;
        }
    }
    else
    {
        const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pUseItem);
        if (nSkillId != -1)
            sub_0055E0D0_DecrementBookScrollSkillQuantity(pUnit, nSkillId);
    }
    sub_0055E000_RemoveItemAndNotify(pGame, pUnit, pUseItem);
    sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x104C);
Success:
    return 1;
}
