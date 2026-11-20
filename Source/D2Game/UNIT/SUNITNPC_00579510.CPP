#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

struct D2NpcRecordStrc;
struct D2NpcVendorChainStrc { int unknown00; unsigned char gamble; };
struct D2BooksTxt { int unknown00[2]; int scrollSkill, bookSkill; };
struct D2LowQualityItemsTxt { char name[32]; };
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9
extern const char gszNullGame_006CC837[]; // 0x006CC837
int __fastcall UNITS_GetXPosition(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc*,D2UnitStrc*); // 0x00554D00
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
void __fastcall D2GAME_SendPacket0x2A_6FC3F3B0(D2ClientStrc*,unsigned char,int,int,int,int); // 0x0053D740
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc*,D2UnitStrc*,D2UnitStrc*,unsigned int); // 0x0053D010
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc*,D2UnitStrc*,int*); // 0x00535F10
D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc*,D2NpcRecordStrc*,D2UnitStrc*); // 0x00536CB0
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc*,D2UnitStrc*,D2InventoryStrc*); // 0x00557FF0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc*,D2UnitStrc*); // 0x00557FD0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055A2A0
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc*,D2UnitStrc*,unsigned int); // 0x0055B060
void __fastcall D2GAME_RemoveItem_6FC471F0(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055DF10
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055EEA0
int __fastcall sub_0055F590_CheckItem(D2UnitStrc*,const char*,int); // 0x0055F590
int __fastcall D2GAME_PlaceItem_6FC44410(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200
int __fastcall sub_6FC45B30(D2GameStrc*,D2UnitStrc*,unsigned char,int,int*); // 0x00560CD0
int __fastcall sub_00575FA0_IsUniqueCarryOneItem(D2UnitStrc*); // 0x00575FA0
void __fastcall sub_005762C0_SetItemTradeFlags(D2UnitStrc*,D2UnitStrc*,D2GameStrc*,int,int); // 0x005762C0
void __fastcall sub_00576E40_DecreaseSkillQuantity(D2UnitStrc*,int,int); // 0x00576E40
bool __fastcall sub_00576ED0(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00576ED0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,unsigned short); // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc*); // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc*); // 0x00627D40
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc*,int); // 0x00627F80
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280
void __stdcall ITEMS_SetItemCell(D2UnitStrc*,unsigned char); // 0x00628320
void __stdcall ITEMS_SetOrRemoveFlag(int*,int,int); // 0x006287B0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc*); // 0x006295B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc*); // 0x00629DA0
int __stdcall sub_0062A130(D2UnitStrc*); // 0x0062A130
int __stdcall ITEMS_GetItemType(D2UnitStrc*); // 0x0062B400
unsigned char __stdcall sub_0062E880(D2UnitStrc*); // 0x0062E880
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int); // 0x006374B0
D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int); // 0x006375C0
static __forceinline int GetMode(D2UnitStrc* unit) { if (unit) return unit->dwAnimMode; return 0; }
static __forceinline int GetId(D2UnitStrc* unit) { if (unit) return unit->dwUnitId; return -1; }
#define SEND_ERROR(code,line) D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(player,gszNpcSource_006E15F0,line),0x2A,code,STATLIST_UnitGetStatValue(player,14,0),-1,0)
// 0x00579510
int __fastcall D2GAME_STORES_SellItem_6FCC7680(D2GameStrc* game,D2UnitStrc* player,int npcId,int itemId,unsigned short itemMode,int unused)
{
    if (!game) { sub_00408A60(gszNullGame_006CC837,sub_00408090(),0x4AE); exit(-1); }
    D2UnitStrc* interact=SUNIT_GetInteractUnit(game,player);
    D2UnitStrc* npc=SUNIT_GetServerUnit(game,1,npcId);
    D2UnitStrc* item=SUNIT_GetServerUnit(game,4,itemId);
    if (!item) return 1;
    if (!npc || interact!=npc) { SEND_ERROR(9,0x4B9); return 1; }
    if (!ITEMS_IsInPlayersInventory(player,item,0)) { SEND_ERROR(11,0x4C2); return 3; }
    if (GetMode(item)==itemMode) {
    if (!sub_0062A130(item)) { SEND_ERROR(9,0x4DE); return 3; }
    const int vendorId=npc->dwClassId;
    int price=ITEMS_GetTransactionCost(player,item,game->nDifficulty,sub_00543520(game,player),vendorId,1);
    int keep=1;
    if (ITEMS_GetItemQuality(item)==1) { const char* name=DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(item))->name; if (!_stricmp(name,"Cracked")) keep=0; }
    if (ITEMS_CheckItemFlag(item,0x100,0x505,gszNpcSource_006E15F0)) keep=0;
    if (ITEMS_GetItemType(item)==7) keep=0;
    if (ITEMS_CheckItemFlag(item,0x1000000,0x50D,gszNpcSource_006E15F0)) keep=0;
    if (ITEMS_CheckItemFlag(item,0x400000,0x511,gszNpcSource_006E15F0)) keep=0;
    if (sub_0055F590_CheckItem(item,gszNpcSource_006E15F0,0x513)) keep=0;
    if (sub_00575FA0_IsUniqueCarryOneItem(item)) keep=0;
    int npcIndex;
    D2NpcRecordStrc* npcRecord=SUNITPROXY_GetNpcRecordFromUnit(game,npc,&npcIndex);
    if (SUNITPROXY_GetVendorChain(game,npcRecord,player)->gamble) keep=0;
    D2UnitStrc* copy=0;
    if (keep && !sub_00576ED0(game,npc,item)) {
        copy=ITEMS_Duplicate(game,item,npc,1);
        if (!copy) { SEND_ERROR(9,0x546); return 3; }
        UNITS_ChangeAnimMode(copy,4);
        unsigned char page=sub_0062E880(copy);
        if (page==255) { ITEMS_RemoveFromAllPlayers(game,copy); copy=0; }
        else {
            ITEMS_SetInvPage(copy,page);
            const int copyId=GetId(copy);
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSource_006E15F0,0x558,game,npc,copyId,UNITS_GetXPosition(copy),CLIENTS_GetUnitY(copy),1,1,0)) {
                if (page==1) {
                    ITEMS_SetInvPage(copy,2);
                    const int copyId=GetId(copy);
                    if (!D2GAME_PlaceItem_6FC44410(gszNpcSource_006E15F0,0x55E,game,npc,copyId,UNITS_GetXPosition(copy),CLIENTS_GetUnitY(copy),1,1,0)) ITEMS_RemoveFromAllPlayers(game,copy);
                    else {
                        sub_005762C0_SetItemTradeFlags(npc,copy,game,1,1);
                        const int durability=STATLIST_GetMaxDurabilityFromUnit(copy);
                        STATLIST_SetUnitStat(copy,72,durability,0);
                        const int quantity=ITEMS_GetTotalMaxStack(copy);
                        STATLIST_SetUnitStat(copy,70,quantity,0);
                        const int vendorId=npc->dwClassId;
                        int newPrice=ITEMS_GetTransactionCost(player,copy,game->nDifficulty,sub_00543520(game,player),vendorId,1);
                        if (price>newPrice) price=newPrice;
                    }
                }
                else ITEMS_RemoveFromAllPlayers(game,copy);
            }
            else {
                sub_005762C0_SetItemTradeFlags(npc,copy,game,1,1);
                const int durability=STATLIST_GetMaxDurabilityFromUnit(copy);
                        STATLIST_SetUnitStat(copy,72,durability,0);
                const int quantity=ITEMS_GetTotalMaxStack(copy);
                        STATLIST_SetUnitStat(copy,70,quantity,0);
                const int vendorId=npc->dwClassId;
                        int newPrice=ITEMS_GetTransactionCost(player,copy,game->nDifficulty,sub_00543520(game,player),vendorId,1);
                if (price>newPrice) price=newPrice;
            }
        }
    }
    if (itemMode==0) {
        if (ITEMS_CheckItemTypeId(item,22)) sub_00576E40_DecreaseSkillQuantity(player,DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(item,0))->scrollSkill,1);
        else if (ITEMS_CheckItemTypeId(item,18)) {
            int quantity=STATLIST_UnitGetStatValue(item,70,0);
            if (quantity>=0) sub_00576E40_DecreaseSkillQuantity(player,DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(item,0))->bookSkill,quantity);
        }
        D2ClientStrc* client=SUNIT_GetClientFromPlayer(player,gszNpcSource_006E15F0,0x594);
        int flags=0;
        ITEMS_SetOrRemoveFlag(&flags,0x20,1);
        ITEMS_SetItemCell(item,ITEMS_GetInvPage(item));
        D2GAME_UpdateClientItem_6FC3E9D0(client,player,item,flags);
        D2GAME_RemoveItem_6FC471F0(game,player,item,0);
    }
    else if (itemMode==4) {
        if (!D2GAME_RemoveItemIfOnCursor_6FC49760(game,player,item)) { SEND_ERROR(9,0x59F); return 1; }
    }
    else {
        int flag;
        if (!sub_6FC45B30(game,player,ITEMS_GetBodyLocation(item),1,&flag)) {
            if (copy) ITEMS_RemoveFromAllPlayers(game,copy);
            return 1;
        }
    }
    ITEMS_HandleGoldTransaction(game,player,price);
    D2GAME_SendPacket0x2A_6FC3F3B0(SUNIT_GetClientFromPlayer(player,gszNpcSource_006E15F0,0x5BD),0x2A,1,STATLIST_UnitGetStatValue(player,14,0),itemId,3);
    return 0;
    }
    SEND_ERROR(9,0x4C7);
    return 3;
}
