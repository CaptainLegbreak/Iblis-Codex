struct Game; struct Unit; struct Room;
struct Client {char pad[0x1A8];Game* game;char pad1AC[8];Room* room;};
extern const char data_006CC837;  // 0x006CC837
const char* __cdecl sub_00408090();  // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
__declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
Unit* __stdcall sub_00537860(Client*,int);  // 0x00537860
Room* __fastcall sub_005545C0(Game*,Unit*);  // 0x005545C0
void __stdcall sub_00619790(Room*,Room***,unsigned int*);  // 0x00619790
void __fastcall sub_00571F90(Game*,Unit*,Client*);  // 0x00571F90
#define ASSERT(x,line) if(!(x)){sub_00408A60(&data_006CC837,sub_00408090(),line);sub_00681E09(-1);}
// 0x00538410
void __fastcall sub_00538410(Client* client,Unit* unit)
{
 Game* game=client->game;
 if(unit==sub_00537860(client,0)) return;
 Room* unitRoom=sub_005545C0(game,unit);
 if(!unitRoom) return;
 Room* clientRoom=client->room;
 ASSERT(clientRoom,2107);
 Room** list;
 unsigned int count;
 sub_00619790(clientRoom,&list,&count);
 unsigned int i=0;
 for(;i<count;++i) {
  Room* room=list[i];
  ASSERT(room,2112);
  if(unitRoom==room) break;
 }
 if(i>=count) sub_00571F90(game,unit,client);
}
