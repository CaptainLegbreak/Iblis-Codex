extern "C" void* __cdecl memset(void*,int,unsigned int);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
struct D2UnitStrc;
struct D2ClientStrc;
struct D2RoomStrc;
struct D2BitBufferStrc;
struct D2QuestDataStrc;
typedef bool (__fastcall* D2QuestStatusFilter)(D2QuestDataStrc*,D2UnitStrc*,D2BitBufferStrc*,D2BitBufferStrc*,unsigned char*);
struct D2QuestDataStrc { int number; int unknown04; unsigned char act; char unknown09[0xB]; unsigned int flags; char unknown18[0xC8]; int filter; int unknownE4; D2QuestStatusFilter statusFilter; char unknownEC[8]; D2QuestDataStrc* next; };
struct D2QuestControlBlockStrc { D2QuestDataStrc* first; char unknown04[8]; D2BitBufferStrc* flags; };
struct D2GameStrc { char unknown00[0x6D]; unsigned char difficulty; char unknown6E[0x1086]; D2QuestControlBlockStrc* questControl; };
struct D2PlayerDataStrc { char unknown00[0x10]; D2BitBufferStrc* questFlags[3]; };
struct D2GSPacketSrv5D { unsigned char header,id,flags,state; unsigned short remaining; };
extern const char gszQuestsSourceFile[]; // 0x006E0BE4
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*,const char*,int); // 0x005531C0
D2RoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2RoomStrc*); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int); // 0x006427F0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc*,unsigned char*,D2BitBufferStrc*); // 0x00543F90
unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc*); // 0x005901E0
unsigned short __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc*); // 0x00588C50
void __fastcall sub_0053D710_SendQuestStatus(D2ClientStrc*,D2GSPacketSrv5D*); // 0x0053D710
typedef int (__stdcall* D2FarProc)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProc);
static __forceinline D2QuestDataStrc* GetQuest(D2GameStrc* game,int id) {
 D2QuestControlBlockStrc* control=game->questControl;
 D2_ASSERT(id>=0,119);
 if(!control) return 0;
 for(D2QuestDataStrc* quest=control->first;quest;quest=quest->next)
  if(quest->number==id) return quest;
 return 0;
}
// 0x00544190
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id)
{
 D2QuestDataStrc* quest=GetQuest(game,id);
 if(!quest) return;
 D2ClientStrc* client=SUNIT_GetClientFromPlayer(player,gszQuestsSourceFile,1406);
 D2RoomStrc* room=UNITS_GetRoom(player);
 if(!room) return;
 int level=DUNGEON_GetLevelIdFromRoom(room);
 if(level && quest->act==DRLG_GetActNoFromLevelId(level)) {
  D2GSPacketSrv5D packet;
  memset(&packet,0,sizeof(packet));
  packet.header=0x5D;packet.flags=(unsigned char)quest->flags;packet.id=id;packet.state=0;
  D2BitBufferStrc* flags=UNITS_GetPlayerData(player)->questFlags[game->difficulty];
  if(!quest->statusFilter) QUESTS_RefreshStatus(quest,&packet.state,flags);
  else {
   unsigned char state=0;
   D2_ASSERT(!IsBadCodePtr((D2FarProc)quest->statusFilter),1429);
   if(quest->statusFilter(quest,player,game->questControl->flags,flags,&state)==1)
    packet.state=state;
  }
  if(quest->filter==1) packet.remaining=ACT1Q1_GetMonstersToBeKilled(quest);
  else if(quest->filter==36) packet.remaining=ACT5Q2_GetBarbsToBeRescued(quest);
  sub_0053D710_SendQuestStatus(client,&packet);
 }
}
