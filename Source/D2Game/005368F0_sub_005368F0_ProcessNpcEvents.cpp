struct D2InventoryStrc;
struct D2UnitStrc { int type,classId; int pad8,id; char pad10[0x50]; D2InventoryStrc* inv; };
struct D2NpcRecordStrc;
struct D2NpcControlStrc { int nArraySize; D2NpcRecordStrc* pFirstRecord; };
struct D2GameStrc { char pad0[0x1c]; void* pool; char pad20[0x1D04]; D2NpcControlStrc* pNpcControl; };
struct D2NpcEventStrc { D2UnitStrc* item; int quality,active,mode; D2NpcEventStrc* next; };
struct D2NpcRecordStrc { int nNPC; char pad4[0x10]; D2NpcEventStrc* events; char pad18[0x2C]; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MAX_NPC_RECORDS 64

// 0x00535EA0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex)
{
    D2NpcRecordStrc* pRecords = pGame->pNpcControl->pFirstRecord;
    for (*pIndex = 0; *pIndex < MAX_NPC_RECORDS; ++*pIndex)
    {
        if (pRecords[*pIndex].nNPC == nNpcClassId)
        {
            return &pRecords[*pIndex];
        }
    }

    D2_ASSERT(nNpcClassId, 114);
    return 0;
}
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc*); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc*); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc*); // 0x0063DFD0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
void __fastcall sub_005766D0(D2UnitStrc*,D2UnitStrc*,D2GameStrc*,int); // 0x005766D0
int __fastcall D2GAME_PlaceItem_6FC44410(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280
void __fastcall sub_005762C0_SetItemTradeFlags(D2UnitStrc*,D2UnitStrc*,D2GameStrc*,int,int); // 0x005762C0
int __fastcall sub_00579030(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00579030
void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480
// 0x005368F0
void __fastcall sub_005368F0_ProcessNpcEvents(D2GameStrc* game,D2UnitStrc* npc)
{
 int count=0;
 D2NpcRecordStrc* record;
 record=SUNITPROXY_GetNpcRecordFromClassId(game,!npc?-1:npc->classId,(int*)&record);
 if(!record)return;
 D2NpcEventStrc* prev=0;
 for(D2NpcEventStrc* event=record->events;event;event=event->next) {
  if(event->active) { event->active=0;if(!event->mode && event->quality==4)++count; }
 }
 if(count && npc->inv) {
  D2UnitStrc* iter=INVENTORY_GetFirstItem(npc->inv);
  while(iter && count) {
   D2UnitStrc* item=INVENTORY_UnitIsItem(iter);
   iter=INVENTORY_GetNextItem(iter);
   if(ITEMS_GetItemQuality(item)==4){sub_005766D0(npc,item,game,0);--count;}
  }
 }
 D2NpcEventStrc* event=record->events;
 while(event) {
  if(event->mode==1) {
   int placed=D2GAME_PlaceItem_6FC44410(".\\UNIT\\sunitproxy.cpp",0x3cb,game,npc,!event->item?-1:event->item->id,0,0,1,1,0);
   if(!placed) {
    if(ITEMS_GetInvPage(event->item)==1){
     ITEMS_SetInvPage(event->item,2);
     placed=D2GAME_PlaceItem_6FC44410(".\\UNIT\\sunitproxy.cpp",0x3d1,game,npc,!event->item?-1:event->item->id,0,0,1,1,0);
    }else if(ITEMS_GetInvPage(event->item)==2){
     ITEMS_SetInvPage(event->item,1);
     placed=D2GAME_PlaceItem_6FC44410(".\\UNIT\\sunitproxy.cpp",0x3d9,game,npc,!event->item?-1:event->item->id,0,0,1,1,0);
    }
   }
   if(!placed){prev=event;event=event->next;continue;}
   sub_005762C0_SetItemTradeFlags(npc,event->item,game,0,0);
   if(event==record->events){record->events=event->next;FOG_FreePool(game->pool,event,".\\UNIT\\sunitproxy.cpp",0x3ea,0);event=record->events;prev=0;}
   else{prev->next=event->next;FOG_FreePool(game->pool,event,".\\UNIT\\sunitproxy.cpp",0x3f1,0);event=prev->next;}
  }else {
   if(!sub_00579030(game,npc,event->item,event->quality)){prev=event;event=event->next;continue;}
   if(event==record->events){record->events=event->next;FOG_FreePool(game->pool,event,".\\UNIT\\sunitproxy.cpp",0x403,0);event=record->events;prev=0;}
   else{prev->next=event->next;FOG_FreePool(game->pool,event,".\\UNIT\\sunitproxy.cpp",0x40a,0);event=prev->next;}
  }
 }
}
