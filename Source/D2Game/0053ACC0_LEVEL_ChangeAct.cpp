struct D2DrlgActStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char f_74[0x08];
    unsigned int dwInitSeed;
    char unk0x80[0x3C];
    D2DrlgActStrc* pAct[5];
};

struct D2ClientStrc
{
    char unk0x00[0x1AC];
    unsigned char nAct;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[5];
    unsigned char nAct;
    unsigned char unk0x19[3];
    D2DrlgActStrc* pDrlgAct;
    int unk0x20[3];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xC8 - 0x30];
    unsigned int dwFlagEx;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

typedef void (__fastcall* AUTOMAPFN)(void*);
typedef void (__fastcall* TOWNAUTOMAPFN)(void*);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame);                                               // 0x0053FCE0
int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame);                                                // 0x0053F5D0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                            // 0x0061AB70
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap);   // 0x006194A0
void __fastcall sub_0059AC40(D2GameStrc* pGame, unsigned char nAct);                                          // 0x0059AC40
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                               // 0x006427F0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                              // 0x005386D0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int a2);                             // 0x00537860
void __fastcall sub_00575BC0(D2GameStrc* pGame, D2UnitStrc* pUnit);                              // 0x00575BC0
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit);                            // 0x00646020
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                          // 0x00620510
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize);   // 0x0061B060
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize);   // 0x0064E7E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                 // 0x00620BB0
int __stdcall D2Common_10229(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, unsigned int nX, unsigned int nY);   // 0x00650BE0
void __fastcall sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                  // 0x00554670
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom);                      // 0x005381F0
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);            // 0x0053B320
void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct);                                  // 0x005382E0
void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient);           // 0x0053ABE0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                       // 0x0064C040
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                           // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                           // 0x0045ADF0
void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY);      // 0x005754B0

static void sub_0053AC70_AllocAct(D2GameStrc* pGame, unsigned char nAct)
{
    int nTownLevelId;
    if (ARENA_IsInArenaMode(pGame))
    {
        nTownLevelId = ARENA_GetAlternateStartTown(pGame);
    }
    else
    {
        nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
    }

    pGame->pAct[nAct] = DUNGEON_AllocAct(nAct, pGame->dwInitSeed, 0, pGame, pGame->nDifficulty, pGame->pMemoryPool, nTownLevelId, 0, 0);
    sub_0059AC40(pGame, nAct);
}

// 0x0053ACC0
void __fastcall LEVEL_ChangeAct(D2GameStrc* pGame, D2ClientStrc* pClient, int nDestinationLevelId, int nTileCalc)
{
    if (ARENA_IsInArenaMode(pGame))
    {
        return;
    }

    const unsigned char nNewAct = DRLG_GetActNoFromLevelId(nDestinationLevelId);
    D2_ASSERT(nNewAct != pClient->nAct, 0x19F);

    if (!pGame->pAct[nNewAct])
    {
        sub_0053AC70_AllocAct(pGame, nNewAct);
    }

    CLIENTS_SetClientState(pClient, 5);

    D2UnitStrc* pUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2_ASSERT(pUnit, 0x1AF);

    if (!pGame->bExpansion && pUnit->dwUnitType == 0)
    {
        sub_00575BC0(pGame, pUnit);
    }

    SKILLS_RemoveTransformStatesFromShapeshiftedUnit(pUnit);

    int nX;
    int nY;
    D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nNewAct], nDestinationLevelId, nTileCalc, &nX, &nY, UNITS_GetUnitSizeX(pUnit));
    if (!pSpawnRoom)
    {
        return;
    }

    D2CoordStrc tSpawnPoint;
    tSpawnPoint.nX = nX;
    tSpawnPoint.nY = nY;

    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinatesEx(pSpawnRoom, &tSpawnPoint, UNITS_GetUnitSizeX(pUnit), 0x1C89, 5);
    if (!pRoom)
    {
        return;
    }

    nX = tSpawnPoint.nX;
    nY = tSpawnPoint.nY;

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(D2Common_10229(pPath, pUnit, 0, 0, 0), 0x1D1);

    sub_6FCBB190(pGame, pUnit, pOldRoom);
    D2_ASSERT(D2Common_10229(pPath, pUnit, pRoom, nX, nY), 0x1D6);

    CLIENTS_SetRoomInClient(pClient, 0);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 5);
    CLIENTS_SetActNo(pClient, nNewAct);
    pUnit->nAct = nNewAct;
    pUnit->pDrlgAct = pGame->pAct[nNewAct];
    LEVEL_SynchronizeDayNightCycleWithClient(pGame, pClient);
    CLIENTS_SetRoomInClient(pClient, pRoom);
    UNITROOM_RefreshUnit(pUnit);
    pUnit->dwFlagEx |= 0x10000;
    sub_6FCBB190(pGame, pUnit, 0);
    UNITROOM_RefreshUnit(pUnit);

    if (pUnit->dwUnitType == 0)
    {
        PLAYERPETS_UpdatePetsForOwnerMove(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
    }
}
