#define NOINLINE __declspec(noinline)
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
struct D2ItemsTxt { char unk00[0x80]; unsigned int dwCode; char unk84[0xA6]; unsigned char nQuest; };
struct D2UniqueItemsTxt { char unk00[0x24]; unsigned short wVersion; char unk26[2]; unsigned int dwCode; unsigned char nUniqueItemFlags[4]; int nRarity; short nLevel; char unk36[0x116]; };
struct D2DataTablesStrc
{
    char unk0x000[0xC24];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

struct D2GameStrc
{
    char unk00[0x6A]; unsigned char nGameType; char unk6B[9]; int bLadder; char unk78[0x1AAC];
    unsigned int dwUniqueFlags[128];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define UNIQUEITEMSFLAGINDEX_NOLIMIT 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __fastcall sub_005564D0_IsDroppedUnique(D2GameStrc* pGame, D2UnitStrc* pItem);                         // 0x005564D0

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

struct D2ItemDropStrc { char unk00[0x2C]; int bForce; char unk30[0x10]; unsigned int nItemIndex; };
struct D2UniqueSelection { int nIndex,nRarity; };
extern D2UniqueSelection gUniqueSelections[]; // 0x008846F8
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall ITEMS_HasDurability(D2UnitStrc*); // 0x00629930
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall sub_006253B0_GetBaseStat(D2UnitStrc*,int,int); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __stdcall ITEMS_SetFileIndex(D2UnitStrc*,int); // 0x00629DF0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*,int,int); // 0x006280D0
void __stdcall sub_0065FEC0_ApplyProperties(int,void*,D2UnitStrc*,int,int,int); // 0x0065FEC0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0
int __stdcall sub_00628C70_IsSpecial(D2UnitStrc*); // 0x00628C70
struct D2SeedStrc;
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
int __fastcall sub_00472280(D2SeedStrc*,int,int); // 0x00472280
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
  sub_0065FEC0_ApplyProperties(3,0,pItem,0,0,0);
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
     if(*pnGameType || pGame->bLadder || !(pRecord->nUniqueItemFlags[0]&gdwBitMasks[3]))
     {
      if(pItemsTxtRecord->dwCode==pRecord->dwCode)
      {
       if(!ITEMS_HasUniqueBeenDroppedAlready(pGame,i) || pItemsTxtRecord->nQuest)
       {
        ITEMS_SetFileIndex(pItem,i);
        ITEMS_SetItemFlag(pItem,16,0);
  sub_0065FEC0_ApplyProperties(3,0,pItem,0,0,0);
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
  if(!*pnGameType && !pGame->bLadder && (pUnique->nUniqueItemFlags[0]&gdwBitMasks[3])) continue;
  if(pUnique->nLevel>ITEMS_GetItemLevel(pItem)) continue;
  if(pItemDrop->nItemIndex>0 && pItemDrop->nItemIndex-1==i) nSelected=i;
  gUniqueSelections[nCount].nIndex=i;
  gUniqueSelections[nCount].nRarity=nTotalRarity;
  ++nCount;
  nTotalRarity+=pUnique->nRarity<1?1:pUnique->nRarity;
 }
 if(nCount<=0)
 {
  if(sub_00628C70_IsSpecial(pItem)) return 1;
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
  sub_0065FEC0_ApplyProperties(3,0,pItem,0,0,0);
  return 1;
 }
FailedUnique:
 ITEMS_SetFileIndex(pItem,-1);return 0;
}
