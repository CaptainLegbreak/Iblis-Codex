#include "D2Game.h"

struct CriticalSection;
struct Game { char pad[0x18]; CriticalSection* lock; char pad1c[0x1DAC]; int mode; };
extern CriticalSection games_lock;  // 0x00882D18
extern int game_guids[1024];  // 0x00882D38
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection*);  // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection*);  // 0x006CC214
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
extern "C" int __cdecl strncmp(const char*,const char*,unsigned int);
Game* __fastcall sub_0052E860(int);  // 0x0052E860
void __fastcall sub_0054A9B0(Game*,const char*,unsigned char);  // 0x0054A9B0
#define CHECK(expr,line) if (!(expr)) { sub_00408A60(&empty_assert,sub_00408090(),line); exit(-1); }
enum { MODE_MASK = 15 };
// 0x0052F630
void __stdcall sub_0052F630(unsigned short gameId,unsigned char* message)
{
    int guid = 0;
    EnterCriticalSection(&games_lock);
    if (game_guids[gameId-1] && game_guids[gameId-1] != -1) guid = game_guids[gameId-1];
    LeaveCriticalSection(&games_lock);
    Game* game = sub_0052E860(guid);
    CHECK(game,0x1564);
    message[255] = 0;
    if (!strncmp("<ABEND> ",(const char*)message,8)) game->mode = message[8] & MODE_MASK;
    sub_0054A9B0(game,(const char*)message,1);
    CHECK(game->lock,0x1064);
    LeaveCriticalSection(game->lock);
}
