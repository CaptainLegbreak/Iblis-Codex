struct D2UnitStrc;struct D2BitBufferStrc;
struct D2GameStrc{char pad[0x6D];unsigned char difficulty;};
struct D2PlayerDataStrc{char pad[0x10];D2BitBufferStrc* flags[3];};
struct D2Act5Quest5Strc{unsigned char defeated,activated;char pad2[10];int portals;unsigned char active,activatable;char pad12[0x1E];int modes[3];};
struct D2QuestDataStrc{int id;D2GameStrc* game;unsigned char act,intro,active,last,state;char padD[7];unsigned int flags;D2Act5Quest5Strc* ex;char pad1C[0xC4];int filter;};
struct D2QuestArgStrc{char pad0[12];D2UnitStrc* player;char pad10[4];unsigned short npc;char pad16[2];short message;};
typedef int (__fastcall *Iter)(D2GameStrc*,D2UnitStrc*,void*);
void __fastcall QUESTS_StateDebug(D2QuestDataStrc*,int,const char*,int); // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc*,int,int,Iter,int); // 0x00544300
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc*,D2UnitStrc*,void*); // 0x0058BE20
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc*,int,void*,Iter); // 0x005537D0
int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc*,D2UnitStrc*,void*); // 0x0058C210
int __stdcall sub_0058BF40_ActivateAncientStatues(D2QuestDataStrc*,D2Act5Quest5Strc*); // 0x0058BF40
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*,int,int); // 0x0065C360
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520
extern const char gszA5Q5SourceFile[]; // 0x006E1ABC
// 0x0058C290
void __fastcall ACT5Q5_Callback11_ScrollMessage(D2QuestDataStrc* q,D2QuestArgStrc* a)
{
 short msg=a->message;
 unsigned short npc=a->npc;
 D2Act5Quest5Strc* ex=q->ex;
 if(msg==20153){
  if(npc==515){
   if(!q->intro||q->state!=1)return;
   QUESTS_StateDebug(q,2,gszA5Q5SourceFile,413);
   if(q->last!=1){q->flags&=0xFFFFFF00;QUESTS_UnitIterate(q,1,0,ACT5Q5_UnitIterate_StatusCyclerEx,1);}
   SUNIT_IterateUnitsOfType(q->game,0,0,ACT5Q5_UnitIterate_UpdateQuestStateFlags);
   ex->activated=1;return;
  }
 }else if(msg==20002){
  if(q->intro&&q->state<4&&q->last!=3){q->flags&=0xFFFFFF00;QUESTS_UnitIterate(q,3,0,ACT5Q5_UnitIterate_StatusCyclerEx,1);}
  if(ex->portals>0)return;
  for(int i=0;i<3;++i)if(ex->modes[i])return;
  if(sub_0058BF40_ActivateAncientStatues(q,ex)){ex->active=1;ex->activatable=1;}
  return;
 }else if(msg==20169){
 D2GameStrc* game=q->game;
 D2BitBufferStrc* pQuestFlags=UNITS_GetPlayerData(!a ? 0 : a->player)->flags[game->difficulty];
 QUESTRECORD_SetQuestState(pQuestFlags,39,4);
 return;}
 switch(npc){
 case 511: if(msg==20167)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,5);break;
 case 520: if(msg==20165)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,6);break;
 case 512: if(msg==20166)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,7);break;
 case 513: if(msg==20168)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,8);break;
 case 515: if(msg==20164)QUESTRECORD_SetQuestState(sub_00543520(q->game,a->player),q->filter,9);break;
 }
}
