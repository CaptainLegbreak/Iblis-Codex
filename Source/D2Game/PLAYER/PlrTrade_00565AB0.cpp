#include "D2Game.h"

#define CUBE_MAX(a,b) ((a)>(b)?(a):(b))
#define CUBE_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SeedStrc;
struct D2ItemsTxt;
struct D2CubeItemStrc;
struct D2CubeParam;
struct D2CubeOutputItem;
struct D2PropertyStrc;
struct D2PlayerDataStrc;

struct D2SeedStrc { unsigned nLowSeed,nHighSeed; };

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk10[0x10];
    D2SeedStrc pSeed;
    char unk28[0x38];
    D2InventoryStrc* pInventory;
    char unk0x64[0x64];
    unsigned int dwFlagEx;
};

struct D2GameStrc
{
    char unk00[0x70];
    int bExpansion;
    int unk74;
    unsigned short wItemFormat;
    unsigned char unk_7A[0x2E];
    int dwGameFrame;
    unsigned char unk_AC[0x1A78];
    unsigned dwUniqueFlags[128];
};

struct D2ItemsTxt
{
    char unk00[0x80];
    unsigned dwCode;
    char unk84[0xa6];
    unsigned char nQuest;
    unsigned char unk_12B[0x1];
};

struct D2CubeItemStrc { D2UnitStrc* pItem; int nClassId,nItemLevel; };

struct D2CubeParam { int nMod; short nModParam,nModMin,nModMax; unsigned char nModChance,unkB; };

struct D2CubeOutputItem { unsigned short wItemFlags,wBaseItemId,wItemID; unsigned char nQuality,nQuantity,nType,nLvl,nPLvl,nILvl; unsigned short wPrefixId[3],wSuffixId[3]; D2CubeParam pParam[5]; };

struct D2CubeMainTxt { char unk00[0x4c]; D2CubeOutputItem pOutputItem[3]; };

struct D2ItemDropStrc {
 D2UnitStrc* pUnit; D2SeedStrc* pSeed; D2GameStrc* pGame; int nItemLvl; unsigned unk10; int nId,nSpawnType,nX,nY; D2ActiveRoomStrc* pRoom;
 unsigned short wUnitInitFlags,wItemFormat; int bForce,nQuality,nQuantity,nMinDur,nMaxDur,nItemIndex; unsigned dwFlags1,dwSeed,dwItemSeed; int eEarLvl,nQtyOverride; char szName[16]; int nPrefix[3],nSuffix[3]; unsigned dwFlags2;
};

extern "C" void* __cdecl memset(void*,int,unsigned);

typedef int (__fastcall *CubeOutputFunc)(D2GameStrc*,D2UnitStrc*);

extern const CubeOutputFunc gCubeOutputFunctions_006E11C8[]; // 0x006E11C8
extern const unsigned gdwBitMasks[]; // 0x006CE268
extern const unsigned gdwInvBitMasks[]; // 0x006CE2E8
extern const char gszPlrTradeCpp[]; // 0x006E11D8
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
void __fastcall SUNIT_RemoveUnit(D2GameStrc*,D2UnitStrc*); // 0x00555600
void __fastcall sub_00557AB0_InitItemStats(D2GameStrc*,D2UnitStrc**,int,int); // 0x00557AB0
void __fastcall ITEMS_DestroyRunewordStatList(D2GameStrc*,D2UnitStrc*); // 0x00558C50
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc*,D2ItemDropStrc*,int); // 0x00558D90
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055A2A0
void __fastcall sub_0055F900_EquipItemRefresh(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055F900
void __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055FE80
unsigned short __fastcall sub_00565930_RollClass(D2GameStrc*,int,int); // 0x00565930
void __fastcall ACT2Q2_UpdateHoradricItemCounts(D2GameStrc*,D2UnitStrc*); // 0x0059E5C0
void __fastcall ACT3Q2_UpdateKhalimItemCounts(D2GameStrc*,D2UnitStrc*); // 0x005B86E0
unsigned short __fastcall sub_005C1BC0_RollTemperedAffix(D2UnitStrc*,int); // 0x005C1BC0
int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*,int,unsigned short); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,unsigned short); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,unsigned short); // 0x00627260
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
void __stdcall ITEMS_SetItemQuality(D2UnitStrc*,int); // 0x00627EA0
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc*,unsigned short); // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc*,unsigned short); // 0x00628070
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned,int,const char*); // 0x006280A0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*,unsigned,int); // 0x006280D0
unsigned __stdcall ITEMS_GetItemFlags(D2UnitStrc*); // 0x00628110
int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280
void __stdcall ITEMS_SetItemCell(D2UnitStrc*,int); // 0x00628320
void __stdcall ITEMS_SetOrRemoveFlag(int*,int,int); // 0x006287B0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc*); // 0x006289F0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc*); // 0x006295B0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc*); // 0x00629DA0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20
void __stdcall ITEMS_AddSockets(D2UnitStrc*,int); // 0x0062BCB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc*); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc*); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc*); // 0x0063DFD0
void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc*,D2PropertyStrc*,int); // 0x00660240
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc*,D2UnitStrc*,D2UnitStrc*,unsigned); // 0x0053D010
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055DF10

struct D2PlayerDataStrc
{
    char unk0x00[0x50];
    int dwTradeState;
    char unk0x54[0x08];
    void* pTrade;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame); // 0x005B5810
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

// 0x00564F30
static int __stdcall sub_00564F30_RemoveCubeInputs(D2GameStrc* game,D2UnitStrc* unit,D2ClientStrc* client)
{
 if (!unit->pInventory) return 0;
 int count=0;
 D2UnitStrc* next=INVENTORY_GetFirstItem(unit->pInventory);
 while(next) {
  D2UnitStrc* item=INVENTORY_UnitIsItem(next);
  next=INVENTORY_GetNextItem(next);
  if(item && ITEMS_GetInvPage(item)==3) {
   int flags=0; ITEMS_SetOrRemoveFlag(&flags,32,1); ITEMS_SetItemCell(item,3);
   D2GAME_UpdateClientItem_6FC3E9D0(client,unit,item,flags);
   D2GAME_RemoveItem_6FC471F0(game,unit,item,0); ++count;
  }
 }
 return count;
}

static __forceinline int CubePercentage(int value,int multiplier,int divisor)
{
 if(!divisor) return 0;
 int result;
 if(value>0x100000) {
  if(divisor>(value>>4)) result=(int)((__int64)value*multiplier/divisor);
  else result=(value/divisor)*multiplier;
 } else if(multiplier>0x10000) {
  if(divisor>(multiplier>>4)) result=(int)((__int64)value*multiplier/divisor);
  else result=(multiplier/divisor)*value;
 } else result=(int)((unsigned)value*(unsigned)multiplier)/divisor;
 return result;
}

static __forceinline unsigned RollCubeSeed(D2SeedStrc* seed)
{
 unsigned __int64 n=0x6AC690C5ui64*seed->nLowSeed+seed->nHighSeed;
 seed->nHighSeed=(unsigned)(n>>32);seed->nLowSeed=(unsigned)n;return (unsigned)n;
}

// 0x00565AB0
D2UnitStrc* __fastcall PLRTRADE_CreateCubeOutputs(D2GameStrc* game,D2UnitStrc* player,D2CubeMainTxt* recipe,D2CubeItemStrc* inputs,int unused)
{
 int nSocketables=0,bSuccess=0,bAddCraftStats=1;
 D2UnitStrc* socketables[18];
 D2UnitStrc* outputs[3]={0,0,0};
 int remove[3]={0,0,0};
 {
 for (int index=0; index<3; ++index)
 {
  D2CubeOutputItem* out=&recipe->pOutputItem[index];
  outputs[index]=0;
  if((out->wItemFlags&0x10)||(out->wItemFlags&0x20)) remove[index]=1;
  int level=0;
  if(out->nLvl) level=out->nLvl;
  else {
   if(out->nPLvl) level=CubePercentage(STATLIST_UnitGetStatValue(player,12,0),out->nPLvl,100);
   if(out->nILvl) level+=CubePercentage(inputs[index].nItemLevel,out->nILvl,100);
  }
  level=CUBE_MIN(CUBE_MAX(level,1),DATATBLS_GetMaxLevel(0));
  if(out->nType && out->nType<4) {
   CubeOutputFunc f=gCubeOutputFunctions_006E11C8[out->nType];
   if(f) bSuccess=f(game,player);
  }
  if(out->wItemFlags&1) {
   D2UnitStrc* original=inputs[index].pItem;
   ITEMS_SetInvPage(original,255);UNITS_ChangeAnimMode(original,4);
   D2UnitStrc* item=ITEMS_Duplicate(game,original,0,remove[index]==0);
   int id=0;
   if(out->nType==254) { if(inputs[index].nClassId>=0) id=inputs[index].nClassId; }
   else if(out->nType==255) id=inputs[index].nClassId;
   else if(out->nType==252) id=out->wBaseItemId;
   else if(out->nType==253) id=sub_00565930_RollClass(game,level,out->wBaseItemId);
   if(item) item->dwClassId=id;
   sub_00557AB0_InitItemStats(game,&item,0,0);outputs[index]=item;
   UNITS_ChangeAnimMode(item,4);ITEMS_SetInvPage(original,3);
  } else if(out->nType==254) {
   D2UnitStrc* original=inputs[index].pItem;
   ITEMS_SetInvPage(original,255);UNITS_ChangeAnimMode(original,4);
   D2UnitStrc* item=ITEMS_Duplicate(game,original,0,remove[index]==0);
   outputs[index]=item;UNITS_ChangeAnimMode(item,4);ITEMS_SetInvPage(original,3);
   if(out->nQuality==9) {
    unsigned short prefix=sub_005C1BC0_RollTemperedAffix(item,1);
    unsigned short suffix=sub_005C1BC0_RollTemperedAffix(item,0);
    if(prefix&&suffix) { ITEMS_SetItemQuality(item,9);ITEMS_AssignRarePrefix(item,prefix);ITEMS_AssignRareSuffix(item,suffix); }
    else bAddCraftStats=0;
   }
  } else {
   unsigned char quality=out->nQuality;
   unsigned short itemIndex=out->wItemID;
   int bCreate=0;int unique=-1,id;
   if(out->nType==255) {
    bCreate=1;
    id=inputs[index].nClassId;
    if(out->wItemFlags&0x40) {
     D2UnitStrc* item=inputs[index].pItem;
     if(item) {
      quality=(unsigned char)ITEMS_GetItemQuality(item);
      int file=ITEMS_GetFileIndex(item);itemIndex=(unsigned short)(file+1);
      level=ITEMS_GetItemLevel(item);
      if(quality==7 && !(game->dwUniqueFlags[file>>5]&gdwBitMasks[file&31])) unique=file;
     }
    }
   } else if(out->nType==252) { bCreate=1; id=out->wBaseItemId; }
   else if(out->nType==253) { bCreate=1; id=sub_00565930_RollClass(game,level,out->wBaseItemId); }
   if(bCreate) {
    D2ItemDropStrc drop;memset(&drop,0,sizeof(drop));
    drop.pUnit=player;drop.wItemFormat=game->wItemFormat;drop.nId=id;drop.nQuality=quality;drop.nItemIndex=itemIndex;drop.nItemLvl=level;drop.pGame=game;
    drop.nSpawnType=4;drop.nX=0;drop.nY=0;drop.pRoom=0;drop.wUnitInitFlags=1;
    for(int i=0;3 > i;++i) drop.nPrefix[i]=out->wPrefixId[i];
    for(int i=0;3 > i;++i) drop.nSuffix[i]=out->wSuffixId[i];
    if((out->wItemFlags&2)&&!out->nQuantity) drop.dwFlags2|=16;else drop.dwFlags2|=8;
    if(out->wItemFlags&4) drop.dwFlags2|=4;else drop.dwFlags2|=2;
    outputs[index]=D2GAME_CreateItemEx_6FC4ED80(game,&drop,0);
    if(unique>=0) game->dwUniqueFlags[unique>>5]&=gdwInvBitMasks[unique&31];
   }
  }
  D2UnitStrc* current=outputs[index];
  if(current) {
  bSuccess=1;
  if(remove[index]) {
   ITEMS_DestroyRunewordStatList(game,current);
   if(out->wItemFlags&0x20) {
    D2UnitStrc* input=inputs[index].pItem;
    if(input && input->pInventory) {
     D2UnitStrc* item=INVENTORY_GetFirstItem(input->pInventory);
     while(item) {
      D2UnitStrc* next=INVENTORY_GetNextItem(item);
      D2UnitStrc* checked=INVENTORY_UnitIsItem(item);
      if(checked) {
       D2UnitStrc* copy=ITEMS_Duplicate(game,checked,0,1);
       if(copy) {ITEMS_SetInvPage(copy,255);UNITS_ChangeAnimMode(copy,4);socketables[nSocketables++]=copy;}
      }
      item=next;
     }
    }
   }
  }
  if(bAddCraftStats) for(int i=0;i<5;++i) {
   D2CubeParam* param=&out->pParam[i];
   if(param->nMod>=0 && (param->nModChance<=0 || param->nModChance>=100 || (int)(RollCubeSeed(&current->pSeed)%100)<=param->nModChance)) {
    D2PropertyStrc property;
    property.nProperty=param->nMod;property.nLayer=param->nModParam;property.nMin=param->nModMin;property.nMax=param->nModMax;
    ITEMMODS_AddCraftPropertyList(current,&property,game->bExpansion);
   }
  }
  if(out->wItemFlags&0x200) {
   if(ITEMS_CheckIfStackable(current) && out->nQuantity>0) {
    int n=ITEMS_GetTotalMaxStack(current);if(n>=out->nQuantity)n=out->nQuantity;
    STATLIST_SetUnitStat(current,70,n,0);
   }
   if(ITEMS_CheckItemFlag(current,0x100,0x504,gszPlrTradeCpp)) sub_0055F900_EquipItemRefresh(game,player,current);
   else {
    int max=STATLIST_UnitGetStatValue(current,73,0);
    if(STATLIST_GetUnitBaseStat(current,72,0)<max)STATLIST_SetUnitStat(current,72,max,0);
   }
  }
  if(out->wItemFlags&0x400)D2GAME_RechargeItem_6FC4BD50(game,player,current);
  if(out->wItemFlags&2) {
   if(out->nQuantity && !STATLIST_UnitGetStatValue(current,194,0) && !(ITEMS_GetItemFlags(current)&0x800)) {
    int n=ITEMS_GetMaxSockets(current);if(n>=out->nQuantity)n=out->nQuantity;
    switch(ITEMS_GetItemQuality(current)) {
     case 4:case 9:if(n>3)n=3;break;
     case 5:case 6:case 7:case 8:if(n>1)n=1;break;
    }
    if(n>0){ITEMS_SetItemFlag(current,0x800,1);ITEMS_AddSockets(current,n);}
   }
  } else if(out->nQuantity && ITEMS_CheckIfStackable(current)) {
   int n=ITEMS_GetTotalMaxStack(current);if(n>=out->nQuantity)n=out->nQuantity;
   STATLIST_SetUnitStat(current,70,n,0);
  }
 }
 }
 }
 if(bSuccess) {
  sub_00564F30_RemoveCubeInputs(game,player,SUNIT_GetClientFromPlayer(player,gszPlrTradeCpp,0x54e));
  SUNIT_AttachSound(player,4,player);
  for(int i=0;i<3;++i) {
   D2UnitStrc* item=outputs[i];if(!item)continue;
   ITEMS_SetInvPage(item,3);
   if(!sub_00560200_PlaceItem(gszPlrTradeCpp,0x55b,game,player,!item ? -1 : item->dwUnitId,0,0,1,1,0))SUNIT_RemoveUnit(game,item);
   else {
    ITEMS_SetItemFlag(item,16,1);
    D2ItemsTxt* record=DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
    if(record->nQuest) {
     if(record->dwCode==' tsh') ACT2Q2_UpdateHoradricItemCounts(game,player);
    else if(record->dwCode==' 2fq') ACT3Q2_UpdateKhalimItemCounts(game,player);
    }
   }
  }
  for(int i=0;i<nSocketables;++i) {
   D2UnitStrc* item=socketables[i];if(!item)continue;
   ITEMS_SetInvPage(item,3);
   if(!sub_00560200_PlaceItem(gszPlrTradeCpp,0x57c,game,player,!item ? -1 : item->dwUnitId,0,0,1,1,0))SUNIT_RemoveUnit(game,item);
   else ITEMS_SetItemFlag(item,16,1);
  }
  return outputs[0];
 }
 return 0;
}

#include "gen/data/Source/D2Game/PLAYER/PlrTrade_00565AB0.inc"

// 0x00566E20
static int sub_00566E20_HasItemsInCube(D2UnitStrc* pPlayer)
{
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer->pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(INVENTORY_UnitIsItem(pItem)) == 3)
        {
            return 1;
        }
    }
    return 0;
}

int __fastcall sub_00567620(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        if (nUnitType != 0)
        {
            return 1;
        }
        D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (pOtherPlayer)
        {
            D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
            if (!pPlayerData2->pTrade)
            {
                return 0;
            }
            if (ACT4Q2_HasDiabloBeenKilled(pGame))
            {
                return 0;
            }
            if (sub_00463720_TestUnitFlagEx(pPlayer, 0x800000) || sub_00463720_TestUnitFlagEx(pOtherPlayer, 0x800000))
            {
                return 0;
            }
            D2_ASSERT(pPlayerData1->pTrade, 0xD3C);
            int nResult = 1;
            if (pPlayerData1->dwTradeState == 4)
            {
                nResult = 0;
            }
            if (pItem && pItem->dwUnitType == 4)
            {
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                if (pItemsTxtRecord->nQuest)
                {
                    if (pItemsTxtRecord->dwCode == 0x20786F62)
                    {
                        if (sub_00566E20_HasItemsInCube(pPlayer))
                        {
                            nResult = 0;
                            PLRTRADE_SendEventPacketToPlayer(pPlayer, 0xA, 0);
                        }
                    }
                    if (ITEMS_FindQuestItem(pGame, pOtherPlayer, pItemsTxtRecord->dwCode))
                    {
                        nResult = 0;
                    }
                }
                else
                {
                    if (ITEMS_CheckItemFlag(pItem, 0x1000, 0xD58, ".\\PLAYER\\PlrTrade.cpp"))
                    {
                        nResult = 0;
                    }
                    else
                    {
                        ITEMS_GetItemQuality(pItem);
                    }
                }
            }
            if (pPlayer)
            {
                pPlayer->dwFlagEx |= 0x400000;
            }
            pPlayerData1->dwTradeState = 7;
            pPlayerData2->dwTradeState = 7;
            EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pGame, pOtherPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD6E), 6);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(SUNIT_GetClientFromPlayer(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD6F), 6);
            return nResult;
        }
    }
    return pPlayerData1->dwTradeState <= 4;
}
