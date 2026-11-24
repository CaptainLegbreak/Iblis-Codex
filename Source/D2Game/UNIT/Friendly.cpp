#include "D2Game.h"
#include "D2Structs.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073C538


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags, int bSet); // 0x0055B260

#define UNIT_PLAYER 0
#define UNIT_INVALID 6

// 0x005A6080
int __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2)
{
    D2_ASSERT((hPlayer ? hPlayer->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 21);

    PLAYERLIST_AllocPlayerList(pGame, hPlayer, pPlayer2);
    PLAYERLIST_ToggleFlag(pGame, hPlayer, pPlayer2, PLAYERLIST_FLAG_HOSTILE, 0);
    return 1;
}
