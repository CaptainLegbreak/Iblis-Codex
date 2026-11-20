#include "D2GameStrc.h"
#include "D2GameServer.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0053F470
static int __stdcall sub_0053F470_ArenaHasFlag(D2GameStrc* pGame, unsigned int nFlag)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return (pArena->fFlags & nFlag) != 0;
}

int __fastcall sub_K10_EmitArenaTestFlag(D2GameStrc* pGame)
{
    return sub_0053F470_ArenaHasFlag(pGame, 0x800);
}
