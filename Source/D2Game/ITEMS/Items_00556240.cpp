#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2Drlg.h"
struct D2ClientStrc;
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define SEND(stat,value,line) D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer,".\\ITEMS\\Items.cpp",line),pItem,1,stat,value,0)
union D2SeedStrc;
struct D2StatListExStrc;
struct D2ItemsTxt;
struct D2UniqueSelection;






struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    unsigned int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555E70
int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555FB0
int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x005560F0
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810
static __declspec(noinline) int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts);


struct D2UniqueItemsTxt { char unk00[0x24]; unsigned short wVersion; char unk26[2]; unsigned int dwCode; unsigned char nUniqueItemFlags[4]; int nRarity; short nLevel; char unk36[0x116]; };


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __fastcall sub_005564D0_IsDroppedUnique(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x005564D0

struct D2UniqueSelection { int nIndex,nRarity; };

extern D2UniqueSelection gUniqueSelections[]; // 0x008846F8
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall ITEMS_HasDurability(D2UnitStrc*); // 0x00629930
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0
int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc*); // 0x00628C70
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall ITEMMODE_AssignItemQualityAndProperties(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop); // 0x00557450
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem); // 0x00629660
int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem); // 0x006296F0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem); // 0x0062E8D0
void __stdcall sub_0065E8E0_InitItemFileIndex(D2UnitStrc* pItem); // 0x0065E8E0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc*); // 0x00625E00
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*,D2UnitStrc*); // 0x00558530
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
int __stdcall sub_006280A0(D2UnitStrc*,int,int,const char*); // 0x006280A0
void __fastcall sub_6FC4B580(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055F850
void __fastcall sub_6FC80A30(D2GameStrc*,D2UnitStrc*); // 0x00580310

// build: symbol ?$S1@?1??ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PATD2SeedStrc@@HHHH@Z@4IA 0x008846F0
// build: symbol ?s_nGoldItemId@?1??ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PATD2SeedStrc@@HHHH@Z@4HA 0x008846EC
// 0x00556240
static int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
{
    static int s_nGoldItemId = DATATBLS_GetItemIdFromItemCode(' dlg');

    D2_ASSERT(s_nGoldItemId != -1, 0x17C);
    D2_ASSERT(s_nGoldItemId != 0, 0x17F);
    D2_ASSERT(nLevelId <= 65, 0x180);

    const int nDiff = 65 - nLevelId;
    const int nBaseLayer = nLevelId >> 1;

    int nAdd = nBaseLayer + 10;
    if (nLevelId % 2)
    {
        nAdd += 1;
    }

    const int nBaseLayerChance = nBaseLayer + nDiff + 5;
    int nWeaponChance;
    int& nWeaponChanceRef = nWeaponChance;
    nWeaponChanceRef = nBaseLayerChance + nAdd;

    const int nRand = sub_00472280(pSeed, 0, 100);
    if (nRand < nDiff)
    {
        return s_nGoldItemId;
    }

    if (nRand < nBaseLayerChance)
    {
        return ITEMMODE_SelectRandomArmorItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < nWeaponChance)
    {
        return ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < 100)
    {
        return ITEMMODE_SelectRandomMiscItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity, bAllowBodyParts);
    }

    D2_ASSERT(0, 0x1BA);
}

D2UnitStrc* __fastcall sub_00559130_DropRandomItem(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDropOut)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    if (nItemLevel >= 65)
    {
        nItemLevel = 64;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    const int nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, nItemLevel, -1, 0, 0);

    D2CoordStrc coords1;
    D2CoordStrc coords2 = *pCoords;

    const int nX = coords2.nX + 2;
    const int nY = coords2.nY + 3;
    if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
    {
        coords1.nX = nX;
        coords1.nY = nY;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = 0;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.pGame = pGame;
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        if (pItemDropOut)
        {
            *pItemDropOut = itemDrop;
        }
        return pItem;
    }

    return 0;
}

// 0x005564A0
static unsigned int ITEMS_HasUniqueBeenDroppedAlready(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

// build: context ITEMS_GetUniqueItemsTxtRecord
inline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecord(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }

    return 0;
}

// 0x00556530
static int __stdcall ITEMS_CanUniqueItemBeDropped(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nFileIndex = ITEMS_GetFileIndex(pItem);
    D2UniqueItemsTxt* pUniqueItemsTxtRecord = ITEMS_GetUniqueItemsTxtRecord(nFileIndex);
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    if (pUniqueItemsTxtRecord->nUniqueItemFlags[0] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_NOLIMIT])
    {
        return 1;
    }

    if ((pItemsTxtRecord->nQuest || !sub_005564D0_IsDroppedUnique(pGame, pItem)) && nFileIndex <= 4096)
    {
        pGame->dwUniqueFlags[nFileIndex >> 5] |= gdwBitMasks[nFileIndex & 0x1F];
        return 1;
    }

    return 0;
}

// 0x005566B0
int __stdcall sub_005566B0_RollUniqueItem(D2GameStrc* pGame,D2UnitStrc* pItem,D2ItemDropStrc* pItemDrop)
{
 unsigned char* const pnGameType = &pGame->nGameType;
 D2ItemsTxt* pItemsTxtRecord=DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
 if(!pItemsTxtRecord) return 0;
 unsigned short nFormat=ITEMS_GetItemFormat(pItem);
 if(ITEMS_HasDurability(pItem) && !nFormat)
 {
  int nDur=STATLIST_UnitGetStatValue(pItem,72,0);
  int nMaxDur=sub_006253B0_GetBaseStat(pItem,73,0);
  STATLIST_SetUnitStat(pItem,72,D2_MIN(5*nDur,255),0);
  STATLIST_SetUnitStat(pItem,73,D2_MIN(5*nMaxDur,255),0);
 }
 if(pItemDrop->bForce)
 {
  D2UniqueItemsTxt* pUnique=ITEMS_GetUniqueItemsTxtRecord(pItemDrop->nItemIndex);
  if(!pUnique) return 0;
  ITEMS_SetFileIndex(pItem,pItemDrop->nItemIndex);
  if(pUnique->dwCode!=pItemsTxtRecord->dwCode) return 1;
  ITEMS_SetItemFlag(pItem,16,0);
  ITEMMODS_AssignProperty(3,0,pItem,0,0,0);
  return 1;
 }
 D2UniqueItemsTxt* pUnique=sgptDataTables->pUniqueItemsTxt;
 if(!nFormat)
 {
  for(int i=0;i<sgptDataTables->nUniqueItemsTxtRecordCount;++i)
  {
   D2UniqueItemsTxt* pRecord=&sgptDataTables->pUniqueItemsTxt[i];
   if(pRecord->wVersion<100)
   {
    if(pRecord->nUniqueItemFlags[0]&gdwBitMasks[0])
    {
     if(*pnGameType || pGame->dwGameType || !(pRecord->nUniqueItemFlags[0]&gdwBitMasks[3]))
     {
      if(pItemsTxtRecord->dwCode==pRecord->dwCode)
      {
       if(!ITEMS_HasUniqueBeenDroppedAlready(pGame,i) || pItemsTxtRecord->nQuest)
       {
        ITEMS_SetFileIndex(pItem,i);
        ITEMS_SetItemFlag(pItem,16,0);
  ITEMMODS_AssignProperty(3,0,pItem,0,0,0);
  return 1;
       }
      }
     }
    }
   }
  }
  return 0;
 }
 int nCount=0;
 int nTotalRarity=0;
 int nSelected=-1;
 for(int i=0;i<sgptDataTables->nUniqueItemsTxtRecordCount;++i,++pUnique)
 {
  if(pUnique->wVersion>=100 && nFormat<100) continue;
  if(!(pUnique->nUniqueItemFlags[0]&gdwBitMasks[0]) || pItemsTxtRecord->dwCode!=pUnique->dwCode) continue;
  if(!*pnGameType && !pGame->dwGameType && (pUnique->nUniqueItemFlags[0]&gdwBitMasks[3])) continue;
  if(pUnique->nLevel>ITEMS_GetItemLevel(pItem)) continue;
  if(pItemDrop->nItemIndex>0 && pItemDrop->nItemIndex-1==i) nSelected=i;
  gUniqueSelections[nCount].nIndex=i;
  gUniqueSelections[nCount].nRarity=nTotalRarity;
  ++nCount;
  nTotalRarity+=pUnique->nRarity<1?1:pUnique->nRarity;
 }
 if(nCount<=0)
 {
  if(ITEMS_GetUniqueColumnFromItemsTxt(pItem)) return 1;
  ITEMS_SetFileIndex(pItem,-1);
  return 0;
 }
 int nUniqueItemId;
 if(nSelected<0)
 {
  int nRoll=sub_00472280(ITEMS_GetItemSeed(pItem),0,nTotalRarity);
  int i=1;
  while(i<nCount && nRoll>=gUniqueSelections[i].nRarity) ++i;
  nUniqueItemId=gUniqueSelections[i-1].nIndex;
 }
 else
 {
  nUniqueItemId=nSelected;
 }
 if(!pItemsTxtRecord->nQuest && ITEMS_HasUniqueBeenDroppedAlready(pGame,nUniqueItemId))
 {
  goto FailedUnique;
 }
 pUnique=ITEMS_GetUniqueItemsTxtRecord(nUniqueItemId);
 if(!pUnique || pItemsTxtRecord->dwCode!=pUnique->dwCode) return 0;
 ITEMS_SetFileIndex(pItem,nUniqueItemId);
 if(ITEMS_CanUniqueItemBeDropped(pGame,pItem))
 {
  ITEMS_SetItemFlag(pItem,16,0);
  ITEMMODS_AssignProperty(3,0,pItem,0,0,0);
  return 1;
 }
FailedUnique:
 ITEMS_SetFileIndex(pItem,-1);return 0;
}

static __forceinline unsigned int D2_MinU(unsigned int a, unsigned int b) { return a < b ? a : b; }

// 0x00556360
static __declspec(noinline) void sub_00556360_RollArmorClass(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1C9);

    const unsigned int nMinAc = pItemsTxtRecord->dwMinAc;
    const unsigned int nMaxAc = pItemsTxtRecord->dwMaxAc;
    const unsigned int nACValue = sub_00472280(&pItem->pSeed, nMinAc, nMaxAc - nMinAc + 1);
    D2_ASSERT(nACValue <= nMaxAc, 0x1CE);
    STATLIST_SetUnitStat(pItem, 31, nACValue, 0);
}

// 0x005563D0
static __declspec(noinline) void sub_005563D0_SetWeaponDamage(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1DB);

    if (pItemsTxtRecord->nMaxDam)
    {
        STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
    }

    if (pItemsTxtRecord->nMinDam)
    {
        STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMinDam)
    {
        STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMaxDam)
    {
        STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
    }

    if (pItemsTxtRecord->nMaxMisDam)
    {
        STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
        STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
    }
}

static __forceinline void ITEMS_SetGoldStat(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == 0)
    {
        if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
            return;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

static void sub_00557A70_RollVarInvGfx(D2UnitStrc* pItem)
{
    if (ITEMS_GetVarInvGfxCount(pItem))
    {
        const unsigned char nIndex = sub_00472280(&pItem->pSeed, 0, ITEMS_GetVarInvGfxCount(pItem));
        ITEMS_SetVarGfxIndex(pItem, nIndex);
    }
}

// 0x00557AB0
int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int bQuestItem)
{
    if (ITEMS_GetItemType(*ppItem) == 4)
    {
        int nQuantity = 1;
        if (pItemDrop)
        {
            const int nItemLevel = pItemDrop->nItemLvl;
            nQuantity = SEED_RollLimitedRandomNumber(&(*ppItem)->pSeed, 5 * nItemLevel) + nItemLevel;
            if (nQuantity <= 0)
            {
                nQuantity = 1;
            }

            if (pItemDrop->nQtyOverride > 0)
            {
                nQuantity = pItemDrop->nQtyOverride;
            }
        }

        ITEMS_SetGoldStat(*ppItem, 14, nQuantity);
    }
    else if (ITEMS_GetQuiverType(*ppItem))
    {
        const int nMinStack = ITEMS_GetMinStack(*ppItem);
        int nQuantity = nMinStack + ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, ITEMS_GetTotalMaxStack(*ppItem) - nMinStack);
        if (nQuantity < 1)
        {
            nQuantity = 1;
        }

        if (pItemDrop && pItemDrop->nQtyOverride > 0)
        {
            nQuantity = pItemDrop->nQtyOverride;
        }

        STATLIST_SetUnitStat(*ppItem, 70, nQuantity, 0);
    }
    else
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!*ppItem ? -1 : (*ppItem)->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x686);

        if (ITEMSIsA(*ppItem, 50))
        {
            STATLIST_SetUnitStat(*ppItem, 20, pItemsTxtRecord->nBlock, 0);
            STATLIST_SetUnitStat(*ppItem, 67, -pItemsTxtRecord->dwSpeed, 0);
            const unsigned int nMaxDurability = pItemsTxtRecord->nDurability;
            const unsigned int nDurability = nMaxDurability >> 1;
            unsigned int nValue = ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nDurability) + nDurability;
            if (nValue >= 255)
            {
                nValue = 255;
            }
            STATLIST_SetUnitStat(*ppItem, 72, nValue, 0);
            STATLIST_SetUnitStat(*ppItem, 73, nMaxDurability >= 255 ? 255 : nMaxDurability, 0);
            sub_00556360_RollArmorClass(*ppItem);
        }
        else if (ITEMSIsA(*ppItem, 45))
        {
            if (ITEMS_CheckIfStackable(*ppItem))
            {
                const int nMinStack = ITEMS_GetMinStack(*ppItem);
                const int nMaxStack = ITEMS_GetTotalMaxStack(*ppItem);
                unsigned int nQuantity = ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nMaxStack - nMinStack) + nMinStack;
                if (pItemDrop && pItemDrop->nQtyOverride > 0)
                {
                    nQuantity = pItemDrop->nQtyOverride;
                }

                if (nQuantity < 1)
                {
                    nQuantity = 1;
                }

                if (ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem))
                {
                    nQuantity = 1;
                }

                STATLIST_SetUnitStat(*ppItem, 70, nQuantity, 0);
            }

            const unsigned int nDurability = pItemsTxtRecord->nDurability;
            STATLIST_SetUnitStat(*ppItem, 72, D2_MinU(ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nDurability >> 1) + (nDurability >> 1), 255), 0);
            STATLIST_SetUnitStat(*ppItem, 73, D2_MinU(nDurability, 255), 0);
            sub_005563D0_SetWeaponDamage(*ppItem);
            STATLIST_SetUnitStat(*ppItem, 68, -pItemsTxtRecord->dwSpeed, 0);
        }
        else
        {
            if (ITEMS_CheckIfStackable(*ppItem))
            {
                const int nMinStack = ITEMS_GetMinStack(*ppItem);
                const int nMaxStack = ITEMS_GetTotalMaxStack(*ppItem);
                int nSpawnStack = ITEMS_GetSpawnStack(*ppItem);
                if (nSpawnStack < nMinStack || !nSpawnStack)
                {
                    nSpawnStack = nMinStack > nMaxStack ? nMinStack : nMaxStack;
                }

                unsigned int nQuantity = ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nSpawnStack - nMinStack) + nMinStack;
                if (pItemDrop && pItemDrop->nQtyOverride > 0)
                {
                    nQuantity = pItemDrop->nQtyOverride;
                }

                if (ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem) || nQuantity < 1)
                {
                    nQuantity = 1;
                }

                STATLIST_SetUnitStat(*ppItem, 70, nQuantity, 0);
            }

            if (ITEMS_GetItemType(*ppItem) == 11)
            {
                sub_0065E8E0_InitItemFileIndex(*ppItem);
            }
        }
    }

    sub_00557A70_RollVarInvGfx(*ppItem);

    int nResult = 1;
    if (bQuestItem && pItemDrop)
    {
        nResult = ITEMMODE_AssignItemQualityAndProperties(pGame, ppItem, pItemDrop);

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!*ppItem ? -1 : (*ppItem)->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(*ppItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(!*ppItem ? 0 : (*ppItem)->pMemoryPool, 0x40, 0, 4, !*ppItem ? -1 : (*ppItem)->dwUnitId);
                D2COMMON_10475_PostStatToStatList(*ppItem, pStatList, 1);
            }

            STATLIST_SetStatIfListIsValid(pStatList, 356, pGame->nDifficulty, 0);
            ITEMS_SetItemFlag(*ppItem, 0x10, 1);
        }
    }

    return nResult;
}

// 0x00558610
int __fastcall sub_00558610_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2)
{
    if (nMagicFind <= 110) return nMagicFind;
    nMagicFind -= 100;
    nFactor2 *= nMagicFind;
    nMagicFind += nFactor;
    return nFactor2 / nMagicFind + 100;
}

inline unsigned __int64 Roll(D2UnitStrc* pUnit) {
 unsigned __int64 seed=pUnit->pSeed.nHighSeed+0x6AC690C5i64*pUnit->pSeed.nLowSeed;
 pUnit->pSeed.nHighSeed=(unsigned)(seed>>32);pUnit->pSeed.nLowSeed=(unsigned)seed;return seed;
}

// 0x00559E30
void __fastcall sub_00559E30_DecreaseDurability(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem) {
 int bWeapon=ITEMSIsA(pItem,50);
 int bStack=ITEMSIsA(pItem,45);
 if ((!bWeapon && !bStack) || !ITEMS_HasDurability(pItem)) return;
 int chance=4;
 if (bWeapon) chance=10;
 else if (ITEMS_CheckIfThrowable(pItem)) { if (!pGame->bExpansion) return; chance=10; }
 if ((int)((unsigned)Roll(pPlayer)%100)>=chance) return;
 int durability=STATLIST_UnitGetStatValue(pItem,72,0)-1;
 if (durability>0) {
  if(durability>=STATLIST_GetMaxDurabilityFromUnit(pItem)) durability=STATLIST_GetMaxDurabilityFromUnit(pItem);
  ITEMS_ScheduleDurabilityReplenishment(pGame,pItem);
  STATLIST_SetUnitStat(pItem,72,durability,0);
  SEND(72,durability,0xc5a);
 } else {
  if(!bStack && !sub_006280A0(pItem,0x100,0xc5f,".\\ITEMS\\Items.cpp")) {sub_6FC4B580(pGame,pPlayer,pItem);return;}
  if(ITEMS_GetItemFormat(pItem)>=1) {
   int quantity=STATLIST_UnitGetStatValue(pItem,70,0);
   if(quantity>1) {
    --quantity;STATLIST_SetUnitStat(pItem,70,quantity,0);SEND(70,quantity,0xc70);
    durability=STATLIST_GetMaxDurabilityFromUnit(pItem);
    STATLIST_SetUnitStat(pItem,72,durability,0);SEND(72,durability,0xc73);
   } else {
    STATLIST_SetUnitStat(pItem,72,0,0);SEND(72,0,0xc78);
    STATLIST_SetUnitStat(pItem,70,0,0);SEND(70,quantity,0xc7b);
    sub_6FC80A30(pGame,pPlayer);
   }
   if(ITEMS_GetTotalMaxStack(pItem)>0) ITEMS_ScheduleDurabilityReplenishment(pGame,pItem);
  } else {STATLIST_SetUnitStat(pItem,72,0,0);SEND(72,0,0xc87);}
 }
}
