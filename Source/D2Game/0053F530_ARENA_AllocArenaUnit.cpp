extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID 0x100
#define GAMEFLAG_ARENA_UPDATE 0x400

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
        };
    };
    unsigned char nTemplate;
    unsigned char pad0x0D[3];
};

struct D2ArenaUnitStrc
{
    int nScore;
    int bUpdateScore;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x34];
    D2ArenaUnitStrc* pArenaUnit;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2GameStrc
{
    char unk0x0000[0x1C];
    void* pMemoryPool;
    char unk0x0020[0x1D08];
    D2ArenaStrc* pArenaCtrl;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

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

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(pPlayerData, 0x4A);

    pPlayerData->pArenaUnit = pArenaUnit;
}

// 0x0053F580
void __fastcall ARENA_FreeArenaUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x52);

    if (!pPlayerData->pArenaUnit)
    {
        return;
    }

    FOG_FreePool(pGame->pMemoryPool, pPlayerData->pArenaUnit, ".\\GAME\\Arena.cpp", 0x57, 0);
    pPlayerData->pArenaUnit = 0;
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
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return pArena->bUpdateClients;
}

// 0x0053FCE0
unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return pArena->bArenaMode;
}

// 0x0053FE70
unsigned int __fastcall ARENA_ShouldTreatClassIdAsTemplateId(D2GameStrc* pGame)
{
    return ARENA_TestFlag_Inlined(pGame, GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID);
}

// 0x0053FEA0
int __fastcall ARENA_GetTemplateType(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x172);
    return pArena->nTemplate;
}
