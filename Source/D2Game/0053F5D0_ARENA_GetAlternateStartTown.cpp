struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    unsigned int fFlags;
    int nTemplate;
};

struct D2GameStrc
{
    char unk0x0000[0x1D28];
    D2ArenaStrc* pArenaCtrl;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0053F5D0
int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 99);

    return pArena->nAlternateStartTown;
}

// 0x0053FD40
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 313);

    return pArena->fFlags;
}

// 0x0053FD70
unsigned int __fastcall sub_0053FD70(D2GameStrc* pGame, unsigned int nMask)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 323);

    return pArena->fFlags & nMask;
}

// 0x0053FDA0
void __fastcall sub_0053FDA0(D2GameStrc* pGame, unsigned int nFlags, int bSet)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 333);

    if (bSet)
    {
        pArena->fFlags |= nFlags;
    }
    else
    {
        pArena->fFlags &= ~nFlags;
    }
}
