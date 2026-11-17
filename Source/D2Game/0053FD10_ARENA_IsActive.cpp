extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GAMEFLAG_ARENA_ACTIVE 0x10000

struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    volatile unsigned int fFlags;
};

struct D2GameStrc
{
    char unk0x0000[0x1D28];
    D2ArenaStrc* pArenaCtrl;
};

static int __stdcall ARENA_TestFlag_Inlined(D2GameStrc* pGame, unsigned int nFlag)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return (pArena->fFlags & nFlag) != 0;
}

// 0x0053FD10
int __fastcall ARENA_IsActive(D2GameStrc* pGame)
{
    return ARENA_TestFlag_Inlined(pGame, GAMEFLAG_ARENA_ACTIVE);
}
