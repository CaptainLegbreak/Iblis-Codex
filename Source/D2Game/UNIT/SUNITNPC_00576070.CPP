#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define SEND_GOLD(code,line,guid,kind) D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(pPlayer,gszNpcSourceFile,line),0x2A,code,STATLIST_UnitGetStatValue(pPlayer,14,0),guid,kind)
#define STAT_QUANTITY 70

struct D2SeedStrc;
struct D2RoomStrc;
struct D2NpcGambleStrc;
struct D2NpcRecordStrc;
struct D2ItemsTxt;
struct D2PlayerDataStrc;
struct D2StaticPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    char unk_6E[2];
    int nGameType;
};

struct D2HirelingTxt
{
    char unk0x000[0x08];
    int dwClass;
    char unk0x00C[0x108];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

struct D2NpcGambleStrc
{
    unsigned short nNameId;
    unsigned short unk0x02;
    unsigned int nSeed;
    int unk0x08;
    int bSelected;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x10];
    D2NpcGambleStrc* pGamble;
    char unk0x14[0x0D];
    unsigned char bGambleInit;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SeedStrc* __fastcall sub_00536B40_GetGameSeed(D2GameStrc* pGame); // 0x00536B40
D2HirelingTxt* __stdcall sub_006564D0_GetHirelingTxtRecord(int nGameType, int nId, int nDifficulty, int a4); // 0x006564D0

struct D2UnitStrc
{
    int type;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unknown10[28];
    union
    {
        D2PathRecordStrc* path;
        D2StaticPathStrc* staticPath;
    };
    unsigned char unk_30[0x30];
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x60];
    unsigned int flags;
    unsigned int flagsEx;
    int unknownCC;
    int owner;
};

struct D2ItemsTxt { char unk_00[0x88]; unsigned int dwUberCode; unsigned int dwUltraCode; char unk_90[0x10C]; unsigned int dwNightmareUpgrade; unsigned int dwHellUpgrade; };

extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9
extern const char gszNpcSourceFile[]; // 0x006E15F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
D2SeedStrc* __fastcall SUNITPROXY_GetSeedFromNpcControl(D2GameStrc* pGame); // 0x00536B40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc*, int, D2GameStrc*, int, int, int, int, int, int, int, int); // 0x00559CE0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
const char* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nIndex); // 0x006375C0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem); // 0x0062E880
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall UNITS_GetYPosition(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall D2GAME_PlaceItem_6FC44410(const char*, int, D2GameStrc*, D2UnitStrc*, int, int, int, int, int, D2InventoryStrc*); // 0x00560200
void __fastcall sub_00535F30(D2UnitStrc*, D2GameStrc*, D2UnitStrc*, int); // 0x00535F30
void __fastcall sub_005762C0_SetItemTradeFlags(D2UnitStrc*, D2UnitStrc*, D2GameStrc*, int, int); // 0x005762C0

struct D2PlayerDataStrc {char unk00[0x10];D2BitBufferStrc* pQuestData[3];char unk1C[0x50];int nBoughtItem;};

extern int gnSpecialItem1; // 0x00883E9C
extern int gnSpecialItem2; // 0x00883EA0
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
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
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0
int __fastcall sub_00536B40(D2GameStrc* pGame); // 0x00536B40
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nArg); // 0x00576890
int __fastcall sub_00576C90_RollTraderItemCode(D2GameStrc* pGame, D2UnitStrc* pNpc, int nValue, int nStockLevel, int* pItemCode, int* pArg); // 0x00576C90

struct D2StaticPathStrc { char unknown[12]; int x; int y; };

D2UnitStrc* __fastcall sub_00574EC0_FindPet(D2GameStrc* game,D2UnitStrc* player,int type,int index); // 0x00574EC0
void __fastcall sub_0058F030_SetOwner(D2GameStrc* game,D2UnitStrc* pet,int id,int type,int a,int b); // 0x0058F030
void __fastcall sub_005750E0_RemovePet(D2GameStrc* game,D2UnitStrc* player,int id,int flags); // 0x005750E0
D2RoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* unit); // 0x00620BB0
void __stdcall sub_0061A270_RemoveRoomUnit(D2RoomStrc* room,int type,int id); // 0x0061A270
void __fastcall sub_00555600_RemoveUnit(D2GameStrc* game,D2UnitStrc* unit); // 0x00555600
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* unit,int mode); // 0x00624690
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* unit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* unit,int stat,int value,int layer); // 0x00627260
void __fastcall sub_00574AB0_AttachPet(D2GameStrc* game,D2UnitStrc* player,D2UnitStrc* pet); // 0x00574AB0
void __fastcall sub_005B1900_InitAi(D2GameStrc* game,D2UnitStrc* pet,int flag,int owner); // 0x005B1900
void __stdcall STATES_ToggleState(D2UnitStrc* unit,int state,int set); // 0x00639DB0
void __fastcall sub_00577470_RefreshPet(D2UnitStrc* pet); // 0x00577470
int __stdcall PATH_GetXPosition(D2PathRecordStrc* path); // 0x006488C0
int __stdcall PATH_GetYPosition(D2PathRecordStrc* path); // 0x00648900
void __fastcall sub_005754B0_MovePets(D2GameStrc* game,D2UnitStrc* player,int x,int y); // 0x005754B0
void __fastcall sub_005726C0_RefreshPlayer(D2GameStrc* game,D2UnitStrc* player,int value); // 0x005726C0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00575FF0
int __fastcall sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = sub_006564D0_GetHirelingTxtRecord(pGame->nGameType, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    const int nCount = *pNameLast - *pNameFirst + 1;
    D2_ASSERT(nCount != -1, 96);
    return nCount;
}

// 0x00576070
void __fastcall sub_00576070_InitGamble(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord)
{
    if (pNpcRecord->bGambleInit)
    {
        return;
    }

    pNpcRecord->bGambleInit = 1;
    if (pNpcRecord->pGamble)
    {
        return;
    }

    pNpcRecord->pGamble = (D2NpcGambleStrc*)FOG_AllocPool(pGame->pMemoryPool, 0x450, ".\\UNIT\\SUNITNPC.CPP", 0x6E, 0);
    memset(pNpcRecord->pGamble, 0, 0x450);

    D2SeedStrc* pSeed = sub_00536B40_GetGameSeed(pGame);
    D2NpcGambleStrc* pGamble = pNpcRecord->pGamble;

    int nMin;
    int nMax;
    const int nCount = sub_00575FF0(pGame, nVendorId, &nMin, &nMax, 0);
    D2_ASSERT(nCount != -1, 0x7A);

    if (nMin <= nMax)
    {
        int i = 0;
        do
        {
            if (i >= nCount)
            {
                break;
            }

            pGamble[i].nNameId = nMin + i;
            pGamble[i].nSeed = SEED_RollRandomNumber(pSeed);
            pGamble[i].unk0x08 = 0;
            pGamble[i].bSelected = 0;
            ++i;
        } while (nMin + i <= nMax);
    }

    for (nMin = 0; nMin < 10; ++nMin)
    {
        int nIndex = SEED_RollLimitedRandomNumber(pSeed, nCount);
        const int nStart = nIndex;
        for (;;)
        {
            if (!pGamble[nIndex].bSelected && !pGamble[nIndex].unk0x08)
            {
                pGamble[nIndex].bSelected = 1;
                break;
            }

            ++nIndex;
            if (nIndex >= nCount)
            {
                nIndex = 0;
            }

            if (nIndex == nStart)
            {
                return;
            }
        }
    }
}

// 0x00576330
D2UnitStrc* __fastcall D2GAME_NPC_GenerateStoreItem_6FCC6A60(D2UnitStrc* pNpc, unsigned int dwCode, D2GameStrc* pGame, int bVendorItem, int nQuality, int nItemLevel, int nPlayerLevel)
{
    D2_ASSERT(pGame, 0x102);
    D2_ASSERT(pNpc, 0x103);
    int nItemId;
    D2ItemsTxt* pRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    unsigned int dwNewCode = dwCode;
    if (pGame->nDifficulty > 0 && nPlayerLevel > 25)
    {
        if (pGame->nDifficulty == 1)
        {
            unsigned int nChance = ITEMS_RollLimitedRandomNumber(SUNITPROXY_GetSeedFromNpcControl(pGame), 100000);
            if (nChance < (unsigned int)(64 * nItemLevel + 4000) && pRecord->dwUberCode && pRecord->dwUberCode != 0x20202020)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUberCode, &nItemId);
                dwNewCode = pRecord->dwUberCode;
            }
            else if (pRecord->dwNightmareUpgrade != 0x20787878)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwNightmareUpgrade, &nItemId);
                dwNewCode = pRecord->dwNightmareUpgrade;
            }
        }
        else
        {
            unsigned int nChance = ITEMS_RollLimitedRandomNumber(SUNITPROXY_GetSeedFromNpcControl(pGame), 100000);
            if (pGame->nGameType && nChance < (unsigned int)(16 * nItemLevel + 1000) && pRecord->dwUltraCode && pRecord->dwUltraCode != 0x20202020)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUltraCode, &nItemId);
                dwNewCode = pRecord->dwUltraCode;
            }
            else if (nChance < (unsigned int)(128 * nItemLevel + 5000) && pRecord->dwUberCode != 0x20202020 && pRecord->dwUberCode)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUberCode, &nItemId);
                dwNewCode = pRecord->dwUberCode;
            }
            if (pRecord->dwHellUpgrade != 0x20787878)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwHellUpgrade, &nItemId);
                dwNewCode = pRecord->dwHellUpgrade;
            }
        }
    }
    D2UnitStrc* pItem;
    for (int i = 0; i < 2; ++i)
    {
        int bValid;
        int j = 0;
        do
        {
            bValid = 1;
            pItem = D2GAME_CreateItemUnit_6FC501A0(pNpc, nItemId, pGame, 4, nQuality, 0, 1, nItemLevel, 0, 0, 0);
            if (ITEMS_GetItemQuality(pItem) == 1)
            {
                const char* szName = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (!_stricmp(szName, "Cracked"))
            {
                ITEMS_RemoveFromAllPlayers(pGame, pItem);
                pItem = 0;
                bValid = 0;
                }
            }
            ++j;
        } while (!bValid && j < 5);
        if (!bValid) return 0;
        if (dwNewCode != ITEMS_GetBaseCode(pItem))
        {
            ITEMS_RemoveFromAllPlayers(pGame, pItem);
            nQuality = 2;
            pItem = 0;
        }
        else
        {
            i = 2;
        }
    }
    if (pItem)
    {
        unsigned char nPage = ITEMS_GetStorePage(pItem);
        if (nPage == 0xFF)
        {
            ITEMS_RemoveFromAllPlayers(pGame, pItem);
            return 0;
        }
        ITEMS_SetInvPage(pItem, nPage);
        D2GAME_NPC_RepairItem_6FCC6970(pGame, pItem, 0);
        int nUnitId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0x16C, pGame, pNpc, nUnitId, UNITS_GetXPosition(pItem), UNITS_GetYPosition(pItem), 1, 1, 0))
        {
            if (nPage == 1)
            {
                ITEMS_SetInvPage(pItem, 2);
                int nRetryUnitId = pItem->dwUnitId;
                if (D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0x172, pGame, pNpc, nRetryUnitId, UNITS_GetXPosition(pItem), UNITS_GetYPosition(pItem), 1, 1, 0))
                {
                    sub_005762C0_SetItemTradeFlags(pNpc, pItem, pGame, bVendorItem, 0);
                    return pItem;
                }
            }
            sub_00535F30(pNpc, pGame, pItem, 0);
            return 0;
        }
        sub_005762C0_SetItemTradeFlags(pNpc, pItem, pGame, bVendorItem, 0);
    }
    return pItem;
}

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

// 0x00579030
int __fastcall sub_00579030_RollTraderItems(D2GameStrc* pGame, D2UnitStrc* pNpc, int nArg, int nArg2)
{
    const int nValue = sub_00536B40(pGame);
    int i = 0;
    const int nStockLevel = sub_00576890(pGame, pNpc, nArg);
    int nItemCode;
    while ((i < 5 ? sub_00576C90_RollTraderItemCode(pGame, pNpc, nValue, nStockLevel, &nItemCode, &nArg2) : 0) != 0)
        ++i;
    return 0;
}

static __forceinline int GetId(D2UnitStrc* u){ if(u) return u->dwUnitId; return -1; }

static __forceinline int GetX(D2UnitStrc* unit) {
 switch(unit->type) { case 2:case 4:case 5:return unit->staticPath->x; }
 return unit->path?PATH_GetXPosition(unit->path):0;
}

static __forceinline int GetY(D2UnitStrc* unit) {
 switch(unit->type) { case 2:case 4:case 5:return unit->staticPath->y; }
 return unit->path?PATH_GetYPosition(unit->path):0;
}

static __forceinline void RemoveExistingPet(D2GameStrc* game,D2UnitStrc* player)
{
 D2UnitStrc* old=sub_00574EC0_FindPet(game,player,7,0);
 if(old) {
  sub_0058F030_SetOwner(game,old,-1,1,0,0);
  sub_005750E0_RemovePet(game,player,GetId(old),0);
  sub_0061A270_RemoveRoomUnit(UNITS_GetRoom(old),1,GetId(old));
  sub_00555600_RemoveUnit(game,old);
 }
}

// 0x00579AA0
void __fastcall sub_00579AA0_ReplacePet(D2GameStrc* game,D2UnitStrc* player,D2UnitStrc* pet)
{
 if(!pet || !player) return;
 RemoveExistingPet(game,player);
 UNITS_ChangeAnimMode(pet,1);
 STATLIST_SetUnitStat(pet,6,STATLIST_GetMaxLifeFromUnit(pet),0);
 sub_00574AB0_AttachPet(game,player,pet);
 sub_005B1900_InitAi(game,pet,0,player->owner);
 STATES_ToggleState(pet,1,0);
 STATES_ToggleState(pet,107,0);
 STATES_ToggleState(pet,154,0);
 pet->flags|=0x402000E;
 pet->flagsEx&=~0x40000;
 sub_00577470_RefreshPet(pet);
 sub_005754B0_MovePets(game,player,GetX(player),GetY(player));
 sub_005726C0_RefreshPlayer(game,player,0);
}
