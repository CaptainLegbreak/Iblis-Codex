struct D2ClientStrc;struct D2InventoryStrc;struct D2BitBufferStrc;
struct D2GameStrc {char unk00[0x6D];unsigned char nDifficulty;};
struct D2UnitStrc {int dwUnitType,dwClassId;void* pMemoryPool;int dwUnitId;char unk10[0x50];D2InventoryStrc* pInventory;};
struct D2PlayerDataStrc {char unk00[0x10];D2BitBufferStrc* pQuestData[3];char unk1C[0x50];int nBoughtItem;};
extern const char gszNpcSourceFile[]; // 0x006E15F0
extern const char gszEmptyAssertText; // 0x006CC837
extern int gnSpecialItem1; // 0x00883E9C
extern int gnSpecialItem2; // 0x00883EA0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
D2InventoryStrc* __fastcall sub_00536C50_GetTradeInventory(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00536C50
void __fastcall sub_0053D130_SendItemStat(D2ClientStrc*,D2UnitStrc*,int,int,int,int); // 0x0053D130
void __fastcall D2GAME_SendPacket0x2A_6FC3F3B0(D2ClientStrc*,unsigned char,int,int,int,int); // 0x0053D740
void __fastcall sub_0053FF00_AddGold(D2UnitStrc*,int,int); // 0x0053FF00
D2BitBufferStrc* __fastcall sub_00543520_GetQuestFlags(D2GameStrc*,D2UnitStrc*); // 0x00543520
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall sub_00557FD0_RemoveItem(D2GameStrc*,D2UnitStrc*); // 0x00557FD0
int __fastcall sub_00557FF0_CheckVendorItem(D2UnitStrc*,D2UnitStrc*,D2InventoryStrc*); // 0x00557FF0
D2UnitStrc* __fastcall sub_0055A2A0_DuplicateItem(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055A2A0
int __fastcall sub_0055E9B0_PlaceBelt(D2GameStrc*,D2UnitStrc*,int,int,int,int*); // 0x0055E9B0
D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int*); // 0x0055F640
void __fastcall sub_0055F6E0_AddScrolls(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055F6E0
int __fastcall D2GAME_PlaceItem_6FC44410(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200
int __fastcall sub_00562E00_AutoEquip(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00562E00
int __fastcall sub_00576D90_SpendGold(D2GameStrc*,D2UnitStrc*,int); // 0x00576D90
unsigned char __fastcall sub_00576ED0_CanMultibuy(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00576ED0
void __fastcall sub_00576F50_UpdateVendor(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00576F50
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __fastcall sub_00623C60(D2UnitStrc*); // 0x00623C60
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*,int,int,int); // 0x006272B0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*,int,int); // 0x006280D0
void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280
int __stdcall sub_006289F0(D2UnitStrc*); // 0x006289F0
int __stdcall sub_00628BA0_CanPlaceInBelt(D2InventoryStrc*,D2UnitStrc*); // 0x00628BA0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
int __stdcall sub_0062E790_CheckStackable(D2UnitStrc*); // 0x0062E790
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc*,D2UnitStrc*,int,D2BitBufferStrc*,int,int); // 0x0062FDC0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
#define SEND_GOLD(code,line,guid,kind) D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer,gszNpcSourceFile,line),0x2A,code,STATLIST_UnitGetStatValue(pPlayer,14,0),guid,kind)
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                                    // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2);                              // 0x0062C850
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem);                                                        // 0x0062E790
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
#define STAT_QUANTITY 70

// 0x00577700
D2UnitStrc* __fastcall sub_00577700_FindStack(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* a4)
{
    *a4 = 1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_GetAutoStack(pItem))
    {
        return 0;
    }

    D2UnitStrc* pStackItem = 0;
    int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
    while (1)
    {
        pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    int nQuantity = 0;
    while (1)
    {
        pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    *a4 = nMaxStack;
    return 0;
}

// 0x00577830
int __fastcall sub_00577830_BuyItem(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pNpc,int nItemGuid,int nItemMode,unsigned short nTransaction,int nQuotedCost,int bMultibuy)
{
    if(!pGame){sub_00408A60(&gszEmptyAssertText,sub_00408090(),2010);exit(-1);}
    D2UnitStrc* pItem=SUNIT_GetServerUnit(pGame,4,nItemGuid);
    D2UnitStrc* pVendorItem=pItem;
    if(pItem)
    {
    int nTransactionType=nTransaction;
    if(nTransactionType==0)
    {
        if(!sub_00557FF0_CheckVendorItem(pNpc,pItem,0)){SEND_GOLD(7,2039,nItemGuid,0);return 1;}
    }
    else if(nTransactionType==2)
    {
        D2InventoryStrc* pTrade=sub_00536C50_GetTradeInventory(pGame,pPlayer,pNpc);
        if(pTrade)
        {
            if(sub_00557FF0_CheckVendorItem(pNpc,pItem,pTrade)!=1){SEND_GOLD(7,2053,nItemGuid,0);return 1;}
        }
        else {SEND_GOLD(7,2059,nItemGuid,0);return 1;}
    }
    int nNpcClass=!pNpc ? -1:pNpc->dwClassId;
    int nDifficulty=pGame->nDifficulty;
    D2BitBufferStrc* pQuestFlags=UNITS_GetPlayerData(pPlayer)->pQuestData[nDifficulty];
    int nCost=ITEMS_GetTransactionCost(pPlayer,pItem,nDifficulty,pQuestFlags,nNpcClass,nTransaction);
    int nGold=STATLIST_UnitGetStatValue(pPlayer,14,0);
    int nStashGold=STATLIST_UnitGetStatValue(pPlayer,15,0);
    if(nCost>(nGold+nStashGold)){SEND_GOLD(12,2085,-1,0);return 0;}
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    if(INVENTORY_GetCursorItem(pInventory)){SEND_GOLD(7,2129,-1,0);return 1;}
    if(!sub_00576ED0_CanMultibuy(pGame,pNpc,pItem))bMultibuy=0;
    if(ITEMS_CheckItemTypeId(pItem,22))
    {
        int nFree;
        D2UnitStrc* pBook=ITEMMODE_FindMatchingBookWithSpace(pGame,pPlayer,pItem,&nFree);
        if(pBook)
        {
            int nCount=1;
            if(bMultibuy)
            {
                nCount=(unsigned int)(nGold+nStashGold)/(unsigned int)nCost;
                if(nCount>nFree)nCount=nFree;
            }
            if(!sub_00576D90_SpendGold(pGame,pPlayer,nCount*nCost)){SEND_GOLD(12,2162,-1,0);return 0;}
            sub_0055F6E0_AddScrolls(pGame,pPlayer,pBook,nCount);
            sub_00576F50_UpdateVendor(pGame,pNpc,pItem,pPlayer,nTransaction);
            SEND_GOLD(0,2171,!pBook ? -1 : pBook->dwUnitId,5);return 0;
        }
    }
    int nQuantity=STATLIST_UnitGetStatValue(pItem,70,0);
    if(bMultibuy && sub_0062E790_CheckStackable(pItem))
    {
        int nFree;
        int nOldQuantity=STATLIST_UnitGetStatValue(pItem,70,0);
        STATLIST_SetUnitStat(pItem,70,1,0);
        nCost=ITEMS_GetTransactionCost(pPlayer,pItem,pGame->nDifficulty,sub_00543520_GetQuestFlags(pGame,pPlayer),!pNpc ? -1:pNpc->dwClassId,0);
        STATLIST_SetUnitStat(pItem,70,nOldQuantity,0);
        int nAffordable=(unsigned int)(nGold+nStashGold)/(unsigned int)nCost;
        D2UnitStrc* pStack=sub_00577700_FindStack(pGame,pPlayer,pItem,&nFree);
        int nCount=nFree<nAffordable ? nFree:nAffordable;
        if(pStack)
        {
            nCount=nFree<nAffordable ? nFree:nAffordable;
            if(nCount<=0){SEND_GOLD(12,2202,-1,0);return 0;}
            if(!sub_00576D90_SpendGold(pGame,pPlayer,nCount*nCost)){SEND_GOLD(12,2207,-1,0);return 0;}
            sub_00576F50_UpdateVendor(pGame,pNpc,pItem,pPlayer,nTransaction);
            STATLIST_AddUnitStat(pStack,70,nCount,0);
            sub_0053D130_SendItemStat(SUNIT_GetClientFromPlayer(pPlayer,gszNpcSourceFile,2214),pStack,1,70,STATLIST_UnitGetStatValue(pStack,70,0),0);
            int nGuid=pStack->dwUnitId;
            SEND_GOLD(0,2216,nGuid,5);return 0;
        }
        nQuantity=nCount;
        if(nQuantity<=1)nQuantity=1;
        nCost=nQuantity*nCost;
    }
    int bPlaced=0;
    int bBought=0;
    if(!sub_00628BA0_CanPlaceInBelt(pInventory,pItem))bMultibuy=0;
    while(1)
    {
        if(bBought && !bMultibuy)return 0;
        nGold=STATLIST_UnitGetStatValue(pPlayer,14,0);
        int nBank=STATLIST_UnitGetStatValue(pPlayer,15,0);
        pItem=sub_0055A2A0_DuplicateItem(pGame,pItem,pNpc,1);
        if(!pItem){SEND_GOLD(9,2249,-1,0);return 1;}
        if(bMultibuy && sub_006289F0(pItem) && nQuantity)STATLIST_SetUnitStat(pItem,70,nQuantity,0);
        if(!sub_00576D90_SpendGold(pGame,pPlayer,nCost)){SEND_GOLD(12,2260,-1,0);return 0;}
        D2PlayerDataStrc* pPlayerData=UNITS_GetPlayerData(pPlayer);
        pPlayerData->nBoughtItem=!pItem ? -1 : pItem->dwUnitId;
        UNITS_ChangeAnimMode(pItem,4);
        int nItemClass=pItem->dwClassId;
        if(sub_00628BA0_CanPlaceInBelt(pInventory,pItem))
        {
            int nBeltSlot;
            bPlaced=sub_0055E9B0_PlaceBelt(pGame,pPlayer,!pItem ? -1 : pItem->dwUnitId,0,1,&nBeltSlot);
            if(!bPlaced)bMultibuy=0;
        }
        if(!bPlaced)
        {
            unsigned char bAutoEquip=1;
            D2UnitStrc* pWeapon=INVENTORY_GetLeftHandWeapon(pInventory);
            int nPlayerClass=sub_00623C60(pPlayer);
            if(nItemClass==gnSpecialItem1 && pWeapon && nPlayerClass!=7)bAutoEquip=0;
            if(nItemClass==gnSpecialItem2 && pWeapon && nPlayerClass!=1)bAutoEquip=0;
            if((pWeapon && ITEMS_CheckItemTypeId(pItem,45)) || (!pWeapon && (nItemClass==gnSpecialItem1 || nItemClass==gnSpecialItem2)))goto inventory;
            if(bAutoEquip)
            {
                bPlaced=sub_00562E00_AutoEquip(pGame,pPlayer,pItem,0);
                if(bPlaced)goto placed;
            }
inventory:
            if(bBought)goto failed;
            ITEMS_SetInvPage(pItem,0);
            bPlaced=D2GAME_PlaceItem_6FC44410(gszNpcSourceFile,2316,pGame,pPlayer,!pItem ? -1 : pItem->dwUnitId,0,0,1,1,0);
            if(!bPlaced)goto failed;
        }
placed:
        sub_00576F50_UpdateVendor(pGame,pNpc,pVendorItem,pPlayer,nTransaction);
        ITEMS_SetItemFlag(pItem,2,1);
        {
            int nGuid=!pItem ? -1 : pItem->dwUnitId;
            SEND_GOLD(0,2354,nGuid,4);
        }
        pItem=pVendorItem;
        bBought=1;
        continue;
failed:
        if(nGold-STATLIST_UnitGetStatValue(pPlayer,14,0))sub_0053FF00_AddGold(pPlayer,14,nGold-STATLIST_UnitGetStatValue(pPlayer,14,0));
        if(nBank-STATLIST_UnitGetStatValue(pPlayer,15,0))sub_0053FF00_AddGold(pPlayer,15,nBank-STATLIST_UnitGetStatValue(pPlayer,15,0));
        sub_00557FD0_RemoveItem(pGame,pItem);
        if(!bBought){SEND_GOLD(10,2332,-1,0);return 0;}
        return 0;
    }
    }
    SEND_GOLD(7,2016,nItemGuid,0);
    return 1;
}
