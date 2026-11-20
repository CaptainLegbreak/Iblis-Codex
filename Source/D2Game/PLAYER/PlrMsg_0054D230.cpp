#include "D2Game.h"
#include "D2Structs.h"

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
    char f_74[0x34];
    unsigned int dwGameFrame;
};


typedef char H15_CheckInventoryOffset[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];
typedef char H15_CheckGameFrameOffset[(int)&((D2GameStrc*)0)->dwGameFrame == 0xA8 ? 1 : -1];

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit);                                                            // 0x00535060
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);       // 0x005678A0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY); // 0x005BF240
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD90
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage);       // 0x0063B210
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc);                            // 0x00627D70
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage);                                    // 0x00628280
void __fastcall sub_0055C460_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats); // 0x0055C460
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x0055F4F0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);           // 0x0063CC70
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag);                                     // 0x00621000
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0
int __fastcall sub_6FC4B9D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);                       // 0x0055FB10
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

static __forceinline int UNITS_GetAnimMode_H15(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

static int __stdcall sub_0054CED0_EquipMercItem(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2GameStrc* pGame, D2UnitStrc* pMerc)
{
    if (!pGame->bExpansion)
    {
        return 3;
    }

    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    if (!pPlayerInventory)
    {
        return 0;
    }

    if (!pMerc->pInventory)
    {
        INVENTORY_AllocInventory(0, pMerc);
    }

    D2InventoryStrc* pMercInventory = pMerc->pInventory;
    if (!pMercInventory)
    {
        return 0;
    }

    unsigned char nBodyLoc2;
    unsigned char nBodyLoc1;
    ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

    D2UnitStrc* pItem1 = INVENTORY_GetItemFromBodyLoc(pMercInventory, nBodyLoc1);
    D2UnitStrc* pItem2 = INVENTORY_GetItemFromBodyLoc(pMercInventory, nBodyLoc2);

    D2UnitStrc* pExchangeItem;
    int nTargetBodyLoc;
    if (pMerc->dwClassId == 0x167 && ITEMS_CheckItemTypeId(pItem, 2))
    {
        pExchangeItem = pItem2;
        nTargetBodyLoc = nBodyLoc2;
    }
    else
    {
        pExchangeItem = pItem1;
        nTargetBodyLoc = nBodyLoc1;
    }

    if (pExchangeItem)
    {
        if (pExchangeItem != INVENTORY_RemoveItemFromInventory(pMercInventory, pExchangeItem))
        {
            return 0;
        }

        sub_0063BE30(pMercInventory, nTargetBodyLoc);
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pExchangeItem, pMerc, 0, 0);
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);

        if (!ITEMS_CheckRequirements(pItem, pMerc, 0, 0, 0, 0))
        {
            sub_0063BDB0(pMercInventory, pExchangeItem, nTargetBodyLoc);
            INVENTORY_PlaceItemInSocket(pMercInventory, pExchangeItem, 3);
            ITEMS_SetBodyLocation(pExchangeItem, nTargetBodyLoc);
            UNITS_ChangeAnimMode(pExchangeItem, 1);
            ITEMS_SetInvPage(pExchangeItem, 0xFF);
            sub_0055C460_UpdateItemStatlist(pGame, pExchangeItem, pMerc, 0);
            sub_0055F4F0(pGame, pMerc, 0);
            return 0;
        }

        ITEMS_SetItemCMDFlag(pExchangeItem, 0x10, 1);
        INVENTORY_AddItemToTradeInventory(pMercInventory, pExchangeItem);
        ITEMS_SetItemFlag(pExchangeItem, 0x20, 1);
        UNITS_RefreshInventory(pMerc, 1);
    }

    D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pItem, pMerc, 1);
    UNITS_ChangeAnimMode(pDupeItem, 4);

    const int nItemGUID = pItem->dwUnitId;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pMerc, 9, nItemGUID);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 9, nItemGUID);

    int nUnused;
    ITEMMODE_EquipCursorItem(pGame, pMerc, !pDupeItem ? -1 : pDupeItem->dwUnitId, nTargetBodyLoc, 1, &nUnused);

    D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
    INVENTORY_SetCursorItem(pPlayerInventory, 0);

    if (pExchangeItem)
    {
        D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pExchangeItem, pPlayer, 1);
        INVENTORY_SetCursorItem(pPlayerInventory, pCursorItem);
        sub_6FC4B9D0(pGame, pPlayer, pCursorItem);
    }

    D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);
    sub_0055F4F0(pGame, pMerc, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pMerc, 3, 0);
    EVENT_SetEvent(pGame, pMerc, 3, pGame->dwGameFrame + 1, 0, 0);
    return 1;
}

static int __stdcall sub_0054D130_UnequipMercItem(D2UnitStrc* pPlayer, int nBodyLoc, D2GameStrc* pGame, D2UnitStrc* pMerc)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!pMerc->pInventory)
    {
        return 3;
    }

    if (nBodyLoc <= 0 || nBodyLoc >= 11)
    {
        return 3;
    }

    D2UnitStrc* pEquippedItem = INVENTORY_GetItemFromBodyLoc(pMerc->pInventory, nBodyLoc);
    if (!pEquippedItem || UNITS_GetAnimMode_H15(pEquippedItem) != 1 || pEquippedItem != INVENTORY_RemoveItemFromInventory(pMerc->pInventory, pEquippedItem))
    {
        return 2;
    }

    {
        sub_0063BE30(pMerc->pInventory, nBodyLoc);
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pEquippedItem, pMerc, 0, 0);
        ITEMS_SetItemCMDFlag(pEquippedItem, 0x10, 1);
        INVENTORY_AddItemToTradeInventory(pMerc->pInventory, pEquippedItem);
        UNITS_RefreshInventory(pMerc, 1);
        D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pEquippedItem, pPlayer, 1);
        INVENTORY_SetCursorItem(pInventory, pCursorItem);
        sub_6FC4B9D0(pGame, pPlayer, pCursorItem);
        ITEMS_SetItemFlag(pEquippedItem, 0x20, 1);
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);
        D2GAME_UpdatePlayerVitals_6FC4B240(pGame, pMerc);
        sub_0055F4F0(pGame, pMerc, 0);
        return 0;
    }
}

// 0x0054D230
static int __stdcall sub_0054D230_TryEquipMercItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x1728, ".\\PLAYER\\PlrMsg.cpp") || ITEMS_CheckItemFlag(pItem, 0x100, 0x172B, ".\\PLAYER\\PlrMsg.cpp"))
    {
        return 0;
    }

    if (ITEMS_CheckItemTypeId(pItem, 0x4C) || ITEMS_CheckItemTypeId(pItem, 0x51) || ITEMS_CheckItemTypeId(pItem, 0x50))
    {
        SKILLITEM_pSpell_Handler(pGame, pMerc, pItem, pItem, 0, 0);
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        return 1;
    }

    int bCanBeEquipped = 0;
    if (ITEMS_CheckItemTypeId(pItem, 3) || ITEMS_CheckItemTypeId(pItem, 0x25))
    {
        bCanBeEquipped = 1;
    }

    switch (!pMerc ? -1 : (unsigned int)pMerc->dwClassId)
    {
    case 0x10F:
        if (ITEMS_CheckItemTypeId(pItem, 0x1B))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x152:
        if (ITEMS_CheckItemTypeId(pItem, 0x21) || ITEMS_CheckItemTypeId(pItem, 0x22))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x167:
        if (!(ITEMS_CheckItemTypeId(pItem, 2) || ITEMS_CheckItemTypeId(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem)))
        {
            break;
        }

        bCanBeEquipped = 1;
        break;

    case 0x230:
        if (ITEMS_CheckItemTypeId(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bCanBeEquipped = 1;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x47))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x231:
        if (ITEMS_CheckItemTypeId(pItem, 0x1E))
        {
            bCanBeEquipped = 1;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x47))
        {
            bCanBeEquipped = 1;
        }
        break;
    }

    if (!bCanBeEquipped || !ITEMS_CheckRequirements(pItem, pMerc, 0, 0, 0, 0))
    {
        SUNIT_AttachSound(pMerc, 0x55, pPlayer);
        return 0;
    }

    if (sub_0054CED0_EquipMercItem(pPlayer, pItem, pGame, pMerc))
    {
        SUNIT_AttachSound(pMerc, 0x57, pPlayer);
        return 1;
    }

    SUNIT_AttachSound(pMerc, 0x56, pPlayer);
    return 0;
}

int __fastcall sub_0054D430(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    if (!pGame->bExpansion)
    {
        return 3;
    }

    const unsigned short nBodyLoc = *(unsigned short*)((char*)pPacket + 1);

    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    if (UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pMerc = sub_6FC7E8B0(pGame, pUnit, 7, 0);
    if (!pMerc)
    {
        return 0;
    }

    if (SUNIT_IsDead(pMerc))
    {
        return 0;
    }

    if (!UNITFINDS_AreUnitsInNeighboredRooms(pMerc, pUnit))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 3;
    }

    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pUnit->pInventory);
    if (!pItem)
    {
        if (nBodyLoc <= 0)
        {
            return 0;
        }
        return sub_0054D130_UnequipMercItem(pUnit, nBodyLoc, pGame, pMerc);
    }

    if (ITEMS_IsQuestItem(pItem))
    {
        return 0;
    }

    sub_0054D230_TryEquipMercItem(pGame, pUnit, pMerc, pItem);
    return 0;
}
