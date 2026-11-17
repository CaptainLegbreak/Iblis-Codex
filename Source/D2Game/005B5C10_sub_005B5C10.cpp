struct D2BitBufferStrc;struct D2InventoryStrc;
struct D2GameStrc { char pad00[0x6d];unsigned char difficulty;char pad6e[0x3a];int frame; };
struct D2UnitStrc { int type,classId;void* pool;int id,mode;char pad14[0x4c];D2InventoryStrc* inventory; };
struct D2PlayerDataStrc { char pad00[0x10];D2BitBufferStrc* quest[3]; };
struct D2Act4Quest3Strc { unsigned short forgeMode;unsigned char unused02,completionStarted,rewardPending;char pad05[3];int rewardState,hammerHits;int unused10,playersInAct; };
struct D2QuestDataStrc { int number;D2GameStrc* game;unsigned char act,notIntro,active,lastState,state,init;unsigned short unused0e;int sequence;unsigned char flagsLow;char flagsHigh[3];D2Act4Quest3Strc* data;char pad1c[0xc4];int filter; };
struct D2ObjectsTxt { char pad00[0xdc];unsigned int animation1,animation2,animation3; };
struct D2ItemsTxt { char pad00[0x80];unsigned int code; };
struct D2ObjectOperateStrc { D2GameStrc* game;D2UnitStrc* object;D2UnitStrc* player; };
typedef int (__fastcall* UnitCallback)(D2GameStrc*,D2UnitStrc*,void*);
typedef void (__fastcall* PartyCallback)(D2GameStrc*,D2UnitStrc*,void*);
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*,int); // 0x00543640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*,int,int); // 0x0065C310
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int); // 0x00640E90
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc*,D2UnitStrc*,unsigned int); // 0x00558110
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
void __fastcall QUESTS_DeleteItem(D2GameStrc*,D2UnitStrc*,int); // 0x00544160
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*,int,int); // 0x0065C360
void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc*,int); // 0x0065C3E0
short __fastcall SUNIT_GetPartyId(D2UnitStrc*); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc*,unsigned short,PartyCallback,void*); // 0x00540510
void __fastcall QUESTS_StateDebug(D2QuestDataStrc*,int,const char*,int); // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*,int,D2UnitStrc*,UnitCallback,bool); // 0x00544300
void __fastcall EVENT_SetEvent(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x005417D0
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc*,int,void*,UnitCallback); // 0x005537D0
void __fastcall QUESTS_TriggerFX(D2GameStrc*,unsigned char); // 0x00545760
int __fastcall sub_005B59C0(D2GameStrc*,D2UnitStrc*,void*); // 0x005B59C0
void __fastcall sub_005B5B00(D2GameStrc*,D2UnitStrc*,void*); // 0x005B5B00
int __fastcall sub_005B5BB0(D2GameStrc*,D2UnitStrc*,void*); // 0x005B5BB0
static __forceinline int UNITS_GetClassIdInline(D2UnitStrc* unit){ if(!unit)return -1; return unit->classId; }
static __forceinline int UNITS_GetAnimModeInline(D2UnitStrc* unit){ if(!unit)return 0; return unit->mode; }

// 0x005B5C10
int __fastcall sub_005B5C10(D2ObjectOperateStrc* operation)
{
 D2QuestDataStrc* quest=QUESTS_GetQuestData(operation->game,24);
 if(!quest)return 0;
 D2GameStrc* game=operation->game;
 D2BitBufferStrc* flags=UNITS_GetPlayerData(operation->player)->quest[game->difficulty];
 if(QUESTRECORD_GetQuestState(flags,27,0)==1 || QUESTRECORD_GetQuestState(flags,27,1)==1)goto playSound;
 {
  D2Act4Quest3Strc* data=quest->data;
  D2ObjectsTxt* record=DATATBLS_GetObjectsTxtRecord(UNITS_GetClassIdInline(operation->object));
  int mode=UNITS_GetAnimModeInline(operation->object);
  switch(mode){
   case 0:
    if(ITEMS_FindQuestItem(operation->game,operation->player,0x2073736d)){
     UNITS_ChangeAnimMode(operation->object,1);
     EVENT_SetEvent(operation->game,operation->object,1,operation->game->frame+(record->animation1>>8),0,0);
     data->forgeMode=2;quest->flagsLow=0;
     QUESTS_UnitIterate(quest,3,0,sub_005B59C0,true);
     QUESTS_DeleteItem(operation->game,operation->player,0x2073736d);
     return 0;
    }
    SUNIT_AttachSound(operation->player,19,operation->player);
    if(quest->notIntro && !quest->state)QUESTS_StateDebug(quest,1,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp",241);
    break;
   case 2: {
    D2UnitStrc* item=ITEMS_FindQuestItem(operation->game,operation->player,0x20686668);
    if(!item)goto playSound;
    D2InventoryStrc* inventory=operation->player->inventory;
    if(!inventory){SUNIT_AttachSound(operation->player,19,operation->player);return 0;}
    item=INVENTORY_GetLeftHandWeapon(inventory);
    if(!item || DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(item))->code!=0x20686668)goto playSound;
    if(++data->hammerHits>2){
    UNITS_ChangeAnimMode(operation->object,3);
    data->forgeMode=3;
    QUESTS_DeleteItem(operation->game,operation->player,0x20686668);
    flags=sub_00543520(operation->game,operation->player);
    QUESTRECORD_SetQuestState(flags,27,13);
    QUESTRECORD_SetQuestState(flags,27,1);
    QUESTRECORD_ResetIntermediateStateFlags(flags,quest->filter);
    data->rewardPending=1;data->completionStarted=1;data->rewardState=4;data->playersInAct=1;
    unsigned short party=SUNIT_GetPartyId(operation->player);
    if(party!=0xffff)PARTY_IteratePartyMembers(operation->game,party,sub_005B5B00,0);
    QUESTS_StateDebug(quest,4,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp",293);
    quest->flagsLow=0;
    QUESTS_UnitIterate(quest,13,0,sub_005B59C0,true);
    EVENT_SetEvent(operation->game,operation->object,7,operation->game->frame+(record->animation3>>8),0,0);
    SUNIT_IterateUnitsOfType(operation->game,0,operation->player,sub_005B5BB0);
    QUESTS_TriggerFX(operation->game,14);
    return 0;
    }
    break;
   }
  }
 }
 return 0;
playSound:
 SUNIT_AttachSound(operation->player,19,operation->player);
 return 0;
}
