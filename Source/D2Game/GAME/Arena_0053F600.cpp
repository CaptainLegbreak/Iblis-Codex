#include "D2GameStrc.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    union
    {
        unsigned int fFlags;
        struct
        {
            unsigned char bFlag0 : 1;
            unsigned char bArenaMode : 1;
            unsigned char bUpdateClients : 1;
            unsigned char bFlag3 : 1;
            unsigned char bFlag4 : 1;
            unsigned char bTemplate : 1;
            unsigned char bFlag40 : 1;
            unsigned char bFlag80 : 1;
        };
    };
    unsigned char nTemplate;
    unsigned char pad0x0D[3];
};


// 0x0053F600
static int sub_0053F600_GetArenaType(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x6C);
    return pArena->nType;
}

int __fastcall sub_M116_Emit_0053F600(D2GameStrc* pGame)
{
    return sub_0053F600_GetArenaType(pGame) == 3;
}

// 0x0053FE00
unsigned int __fastcall sub_0053FE00_TestArenaFlag40(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return pArena->bFlag40;
}

// 0x0053FE40
unsigned int __fastcall sub_0053FE40_TestArenaFlag80(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return pArena->bFlag80;
}

// 0x0053FED0
unsigned int __fastcall sub_0053FED0_TestArenaFlag200(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return (pArena->fFlags & 0x200) != 0;
}
