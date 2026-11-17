struct D2GameStrc;
struct D2ClientStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    unsigned int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2BooksTxt
{
    char unk0x00[0x04];
    int dwPSpell;
    int dwScrollSkillId;
    int dwBookSkillId;
};

struct D2ItemsTxt
{
    char unk0x00[0x94];
    int dwPspell;
};

typedef int (__fastcall* PSPELLFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId);

struct D2pSpellTblStrc
{
    PSPELLFN pfSpellPrepare;
    PSPELLFN pfSpellDo;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define IFLAG_TARGETING 4
#define ITEMTYPE_BOOK 18
#define ITEMTYPE_SCROLL 22

extern int gnPSpellTableCount_0074178C;                                                                      // 0x0074178C
extern D2pSpellTblStrc gPSpellTable_00741790[];                                                              // 0x00741790
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                   // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                               // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                              // 0x0063DFA0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);    // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                          // 0x006280D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);      // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char a3, int a4, int a5, unsigned short a6); // 0x0053D220
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                       // 0x00629BB0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                                // 0x00627F80
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                                // 0x006374B0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                               // 0x006335F0

static void sub_005BE1C0_SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit)
{
    if (!pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pUnit->pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 119, ".\\SKILLS\\SkillItem.cpp"))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 0);
            D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillItem.cpp", 122), pItem, -1, 1, 0, -1);
        }
    }
}

// 0x005BF240
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nUnitType = pUnit->dwUnitType;
    if (nUnitType != UNIT_PLAYER && nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nItemType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nItemType == UNIT_ITEM)
    {
        int nPSpell = -1;
        int nSkillId = -1;

        if (ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BOOK) || ITEMS_CheckItemTypeId(pItem, ITEMTYPE_SCROLL))
        {
            D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
            if (pBooksTxtRecord)
            {
                nPSpell = pBooksTxtRecord->dwPSpell;
                nSkillId = pBooksTxtRecord->dwBookSkillId;
            }
        }

        if (nPSpell <= 0)
        {
            const int nClassId = pItem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            if (pItemsTxtRecord)
            {
                nPSpell = pItemsTxtRecord->dwPspell;
            }

            if (nPSpell <= 0)
            {
                return 0;
            }
        }

        if (nPSpell >= gnPSpellTableCount_0074178C)
        {
            return 0;
        }

        if (gPSpellTable_00741790[nPSpell].pfSpellPrepare && !ITEMS_CheckItemFlag(pItem, IFLAG_TARGETING, 1130, ".\\SKILLS\\SkillItem.cpp"))
        {
            if (!gPSpellTable_00741790[nPSpell].pfSpellPrepare(pGame, pUnit, pItem, 0, nX, nY, nSkillId))
            {
                sub_005BE1C0_SKILLITEM_ClearTargetingItems(pUnit);
                const unsigned int nItemGUID = pItem->dwUnitId;
                const int nItemType = pItem->dwUnitType;
                D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillItem.cpp", 1135), 0x7C, nItemType, nItemGUID);
            }

            return 0;
        }

        if (!gPSpellTable_00741790[nPSpell].pfSpellDo)
        {
            return 0;
        }

        ITEMS_SetItemFlag(pItem, IFLAG_TARGETING, 1);

        const int nResult = gPSpellTable_00741790[nPSpell].pfSpellDo(pGame, pUnit, pItem, pTarget, nX, nY, nSkillId);
        if (!nResult)
        {
            sub_005BE1C0_SKILLITEM_ClearTargetingItems(pUnit);
            const unsigned int nItemGUID = pItem->dwUnitId;
            const int nItemType = pItem->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\SkillItem.cpp", 1151), 0x7C, nItemType, nItemGUID);
        }

        return nResult;
    }

    return 0;
}

#include "gen/data/Source/D2Game/005BF240_SKILLITEM_pSpell_Handler.inc"
