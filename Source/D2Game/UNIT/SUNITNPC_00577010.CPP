#include "D2Game.h"
#include "D2Txt.h"

#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
struct D2MercDataStrc;
struct D2NpcRecordStrc;
struct D2SeedStrc;
struct D2NpcGambleStrc;
struct D2GambleStrc;
struct D2DifficultyLevelsTxt;
struct D2ItemsTxt;

struct D2GameStrc
{
    char unk00[0x1C];
    void* pMemoryPool;
    char unk20[0x4D];
    unsigned char nDifficulty;
    char unk6E[2];
    int nGameType;
};

struct D2MercDataStrc { unsigned short nName; unsigned short unk02; unsigned int unk04; int bHired; int unk0C; };

struct D2NpcRecordStrc
{
    int nNpc;
    D2InventoryStrc* pInventory;
    D2NpcGambleStrc* pGamble;
    unsigned char unk_0C[0x4];
    D2MercDataStrc* pMercData;
    char unk14[0xD];
    unsigned char bInitialized;
    unsigned char unk_22[0x2];
};

struct D2HirelingTxt { char unk000[8]; int dwClass; char unk00C[0x108]; unsigned short wNameFirst; unsigned short wNameLast; };

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" const char gszNpcSourceFile[]; // 0x006E15F0
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x006564D0
void __fastcall FOG_FreeServerMemory(void*, void*, const char*, int, int); // 0x0040B480
void __fastcall sub_00576070_InitGamble(D2GameStrc*, int, D2NpcRecordStrc*); // 0x00576070

struct D2SeedStrc { unsigned int nLowSeed,nHighSeed; };

struct D2PathRecordStrc { char unk00[0xC]; int nX,nY; };

struct D2UnitStrc { int dwUnitType,dwClassId; void* pMemoryPool; int dwUnitId; char unk10[0x1C]; D2PathRecordStrc* pPath; };

struct D2NpcGambleStrc { D2InventoryStrc* pInventory; int dwGUID; D2NpcGambleStrc* pNext; };

struct D2GambleStrc { int unk00; int* pItemIds; int nCount[100]; };

struct D2DifficultyLevelsTxt { char unk00[0x44]; int nRare,nSet,nUnique,nUber,nUltra; };


D2GambleStrc* __fastcall sub_00638CC0_GetGambleRecord(); // 0x00638CC0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int,int*); // 0x00633640
void* __fastcall sub_0040B430(void*,int,const char*,int,int); // 0x0040B430
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void*,D2UnitStrc*); // 0x0063ABD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
D2SeedStrc* __fastcall SUNITPROXY_GetSeedFromNpcControl(D2GameStrc*); // 0x00536B40
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*,int); // 0x0045C3E0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc*,int,D2GameStrc*,int,int,int,int,int,int,int,int); // 0x00559CE0
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall PATH_GetX(D2PathRecordStrc*); // 0x006488C0
int __stdcall PATH_GetY(D2PathRecordStrc*); // 0x00648900
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc*,D2UnitStrc*); // 0x00557FD0
extern const char gszSUnitNpc[]; // 0x006E15F0

static __forceinline int sub_00575FF0(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pRecord = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->nGameType, nHirelingId, 0, 0);
    if (!pRecord) { *pNameFirst = 0; *pNameLast = 0; *pClass = 0; return -1; }
    *pNameFirst = pRecord->wNameFirst;
    *pNameLast = pRecord->wNameLast;
    if (pClass) *pClass = pRecord->dwClass;
    D2_ASSERT((*pNameLast - *pNameFirst + 1) != -1, 96);
    return (*pNameLast - *pNameFirst + 1);
}

// 0x00577010
void __fastcall sub_00577010_VendorRefresh(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord)
{
    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    int nAvailable = 0;
    int nFirst, nLast;
    const int nCount = sub_00575FF0(pGame, nVendorId, &nFirst, &nLast, 0);
    D2_ASSERT(nCount != -1, 0x632);
    for (int i = 0; i < nCount; ++i)
    {
        if (pMercData[i].unk0C && !pMercData[i].bHired) ++nAvailable;
    }
    if (!nAvailable)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pNpcRecord->pMercData, gszNpcSourceFile, 0x63D, 0);
        pNpcRecord->pMercData = 0;
        pNpcRecord->bInitialized = 0;
        sub_00576070_InitGamble(pGame, nVendorId, pNpcRecord);
    }
}

int gnRingId; // 0x0088CACC

int gnAmuletId; // 0x0088CAC8

static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
 const unsigned __int64 n = pSeed->nHighSeed + 0x6AC690C5i64*pSeed->nLowSeed;
 pSeed->nHighSeed=(unsigned int)(n>>32); pSeed->nLowSeed=(unsigned int)n; return (unsigned int)n;
}

static __forceinline unsigned int RollLimited(D2SeedStrc* pSeed,int nMax)
{
 if(nMax<=0) return 0;
 if(nMax & (nMax-1)) return RollSeed(pSeed)%(unsigned int)nMax;
 return RollSeed(pSeed)&(nMax-1);
}

static __forceinline int UnitX(D2UnitStrc* pUnit)
{
 switch(pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pPath->nX; default: return pUnit->pPath ? PATH_GetX(pUnit->pPath) : 0; }
}

static __forceinline int UnitY(D2UnitStrc* pUnit)
{
 switch(pUnit->dwUnitType) { case 2: case 4: case 5: return pUnit->pPath->nY; default: return pUnit->pPath ? PATH_GetY(pUnit->pPath) : 0; }
}

// 0x005786A0
static int __stdcall sub_005786A0_RollGambleUpgrade(int nItemId, int nUberChance, int nUltraChance, D2GameStrc* pGame, int nItemLevel)
{
    if (!pGame->nGameType)
    {
        return nItemId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return nItemId;
    }

    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUltraItemId;
    if (pItemsTxtRecord->dwUberCode != 0x20202020 && pItemsTxtRecord->dwUberCode)
    {
        int nUberItemId;
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemsTxtRecord->dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            const int nUberItemChance = (nItemLevel - pUberItemsTxtRecord->nLevel) * nUberChance + 1;
            if (nUberItemChance > 0)
            {
                if (ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUberItemChance)
                {
                    return nUberItemId;
                }

                if (pItemsTxtRecord->dwUltraCode != 0x20202020 && pItemsTxtRecord->dwUltraCode)
                {
                    D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
                    if (pUltraItemsTxtRecord)
                    {
                        const int nUltraItemChance = (nItemLevel - pUltraItemsTxtRecord->nLevel) * nUltraChance + 1;
                        if (nUltraItemChance > 0 && ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUltraItemChance)
                        {
                            return nUltraItemId;
                        }
                    }
                }
            }
        }
    }

    return nItemId;
}

// 0x00578790
void __fastcall D2GAME_STORES_FillGamble_6FCCA9F0(D2GameStrc* pGame,D2UnitStrc* pNpc,D2UnitStrc* pPlayer,D2NpcRecordStrc* pNpcRecord)
{
 D2GambleStrc* pGamble = sub_00638CC0_GetGambleRecord();
 if(!pGamble) return;
 D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
 if(!pDifficulty) return;
 int nQualityChance = pDifficulty->nRare+pDifficulty->nSet+pDifficulty->nUnique;
 if(!gnRingId) DATATBLS_GetItemRecordFromItemCode(0x206E6972,&gnRingId);
 if(!gnAmuletId) DATATBLS_GetItemRecordFromItemCode(0x20756D61,&gnAmuletId);
 D2NpcGambleStrc* pNpcGamble = (D2NpcGambleStrc*)sub_0040B430(pGame->pMemoryPool,sizeof(D2NpcGambleStrc),gszSUnitNpc,0xD94,0);
 if(!pNpcGamble) return;
 pNpcGamble->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool,0);
 pNpcGamble->dwGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
 pNpcGamble->pNext = pNpcRecord->pGamble;
 pNpcRecord->pGamble = pNpcGamble;
 int nPlayerLevel = STATLIST_UnitGetStatValue(pPlayer,12,0);
 D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
 for(int nItems = 0; nItems < 14;)
 {
  int nItemLevel = (int)(RollSeed(pSeed)%10)+nPlayerLevel-5;
  nItemLevel=D2_MIN(D2_MAX(nItemLevel,5),99);
  int nItemId = pGamble->pItemIds[RollLimited(pSeed,pGamble->nCount[nItemLevel])];
  if(!pGame->nGameType)
  {
   D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nItemId);
   if(!pItemsTxt) return;
   if(pItemsTxt->wVersion>=100) continue;
  }
  if(nItems<2)
  {
   nItemId=gnRingId;
   if(nItems) nItemId=gnAmuletId;
  }
  nItemId = sub_005786A0_RollGambleUpgrade(nItemId,pDifficulty->nUber,pDifficulty->nUltra,pGame,nItemLevel);
  int nQuality = 4;
  if(nQualityChance>0)
  {
   int nRoll=(int)(RollSeed(pSeed)%100000);
   if(nRoll<nQualityChance)
   {
    if(nRoll<pDifficulty->nUnique) nQuality=7;
    else if(nRoll<pDifficulty->nUnique+pDifficulty->nSet) nQuality=5;
    else nQuality=6;
   }
  }
  ++nItems;
  D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pNpc,nItemId,pGame,4,nQuality,0,1,nItemLevel,0,0,0);
  if(!pItem) continue;
  {
   ITEMS_SetInvPage(pItem,0);
   D2GAME_NPC_RepairItem_6FCC6970(pGame,pItem,0);
   ITEMS_SetItemFlag(pItem,16,0);
   const int nY = UnitY(pItem);
   const int nX = UnitX(pItem);
   const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
   if(!sub_00560200_PlaceItem(gszSUnitNpc,0xDE4,pGame,pNpc,nItemGUID,nX,nY,1,0,pNpcGamble->pInventory))
   {
    ITEMS_RemoveFromAllPlayers(pGame,pItem);
    return;
   }
  }
 }
}
