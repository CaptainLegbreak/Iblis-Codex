struct D2GameStrc { char pad[0x70]; int bExpansion; };
struct D2UnitStrc { char pad[0x20]; unsigned nLowSeed; unsigned nHighSeed; };
struct D2ClientStrc;
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
int __stdcall ITEMS_HasDurability(D2UnitStrc*); // 0x00629930
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc*); // 0x00625E00
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*,D2UnitStrc*); // 0x00558530
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc*,D2UnitStrc*,int,int,int,int); // 0x0053D130
int __stdcall sub_006280A0(D2UnitStrc*,int,int,const char*); // 0x006280A0
void __fastcall sub_6FC4B580(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055F850
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
void __fastcall sub_6FC80A30(D2GameStrc*,D2UnitStrc*); // 0x00580310
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc*); // 0x006295B0
inline unsigned __int64 Roll(D2UnitStrc* pUnit) {
 unsigned __int64 seed=pUnit->nHighSeed+0x6AC690C5i64*pUnit->nLowSeed;
 pUnit->nHighSeed=(unsigned)(seed>>32);pUnit->nLowSeed=(unsigned)seed;return seed;
}
#define SEND(stat,value,line) D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pPlayer,".\\ITEMS\\Items.cpp",line),pItem,1,stat,value,0)
// 0x00559E30
void __fastcall sub_00559E30_DecreaseDurability(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem) {
 int bWeapon=ITEMS_CheckItemTypeId(pItem,50);
 int bStack=ITEMS_CheckItemTypeId(pItem,45);
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
