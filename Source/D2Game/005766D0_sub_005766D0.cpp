struct Game;
struct Inventory;
struct Unit { unsigned type; unsigned classId; void* pool; unsigned id; char pad10[0x50]; Inventory* inventory; char pad64[0x64]; unsigned flags; };
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
extern "C" const char text_006CC837[];  // 0x006CC837
void __fastcall sub_00560420(Game*,Unit*,unsigned,int*,int,int,int,int);  // 0x00560420
void __stdcall sub_00621000(Unit*,int);  // 0x00621000
void __stdcall sub_0063CC70(Inventory*,Unit*);  // 0x0063CC70
void __stdcall sub_00628170(Unit*,int,int);  // 0x00628170
void __fastcall sub_00557FD0(Game*,Unit*);  // 0x00557FD0
#define CHECK(p,line) if (!(p)) { sub_00408A60(text_006CC837,sub_00408090(),line); sub_00681E09(-1); }
// 0x005766D0
void __fastcall sub_005766D0(Unit* npc,Unit* item,Game* game,int init)
{
    CHECK(game,423);
    CHECK(npc,424);
    CHECK(item,425);
    int unused;
    unsigned id = item ? item->id : -1;
    sub_00560420(game,npc,id,&unused,0,0,0,0);
    if(init) {
        item->flags |= 0x10;
        sub_00621000(npc,1);
        sub_0063CC70(npc->inventory,item);
        sub_00628170(item,1,1);
    } else {
        sub_00557FD0(game,item);
    }
}
