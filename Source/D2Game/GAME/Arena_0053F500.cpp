#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameServer.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID 0x100

struct D2ArenaStrc;
struct D2ArenaUnitStrc;
struct D2PlayerDataStrc;

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

// 0x0053F500
void __fastcall ARENA_FreeArena(D2GameStrc* pGame)
{
    if (pGame->pArenaCtrl)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pGame->pArenaCtrl, ".\\GAME\\Arena.cpp", 0x40, 0);
        pGame->pArenaCtrl = 0;
    }
}

static int ARENA_IsPlayerUnit_Inlined(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

static int __stdcall ARENA_TestFlag_Inlined(D2GameStrc* pGame, unsigned int nFlag)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return (pArena->fFlags & nFlag) != 0;
}

// 0x0053F530
void __fastcall ARENA_AllocArenaUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ArenaUnitStrc* pArenaUnit = (D2ArenaUnitStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ArenaUnitStrc), ".\\GAME\\Arena.cpp", 0x47, 0);
    memset(pArenaUnit, 0, sizeof(D2ArenaUnitStrc));

    D2PlayerDataStrc* ptPlayerInfo = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(ptPlayerInfo, 0x4A);

    ptPlayerInfo->pArenaUnit = pArenaUnit;
}

// 0x0053F580
void __fastcall ARENA_FreeArenaUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* ptPlayerInfo = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(ptPlayerInfo, 0x52);

    if (!ptPlayerInfo->pArenaUnit)
    {
        return;
    }

    FOG_FreePool(pGame->pMemoryPool, ptPlayerInfo->pArenaUnit, ".\\GAME\\Arena.cpp", 0x57, 0);
    ptPlayerInfo->pArenaUnit = 0;
}

// 0x0053FA90
void __fastcall sub_0053FA90_ClearArenaUnitUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(ARENA_IsPlayerUnit_Inlined(pUnit), 0xC5);

    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pUnit)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 0xC9);

    pArenaUnit->bUpdateScore = 0;
}

// 0x0053FAE0
void __fastcall sub_0053FAE0(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    if (pArena)
    {
        pArena->fFlags &= ~GAMEFLAG_ARENA_UPDATE;
    }
}

// 0x0053FCA0
unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 39);
    return ptArena->bUpdateClients;
}

// 0x0053FCE0
unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 39);
    return ptArena->bArenaMode;
}

// 0x0053FE70
unsigned int __fastcall ARENA_ShouldTreatClassIdAsTemplateId(D2GameStrc* pGame)
{
    return ARENA_TestFlag_Inlined(pGame, GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID);
}

// 0x0053FEA0
int __fastcall ARENA_GetTemplateType(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 0x172);
    return ptArena->nTemplate;
}
