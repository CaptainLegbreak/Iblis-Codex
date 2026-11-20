#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1

struct D2DrlgCoordsStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2GameStrc;
struct D2CoordStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    unsigned int nNumClients;
};

struct D2ClientStrc
{
    char unk0x00[0x1AC];
    unsigned char nAct;
};

void __fastcall sub_005531E0_FixRoomIfInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005531E0


void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __fastcall sub_00534AB0_ClearTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00534AB0
void __fastcall sub_00573750_ClearTargetIfMatches(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00573750

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileX;
    int nTileY;
    int nTileWidth;
    int nTileHeight;
};
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*, D2DrlgCoordsStrc*); // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc*, int, int, int); // 0x0053BC50
void __stdcall DUNGEON_AddClientToRoom(D2ActiveRoomStrc*, D2ClientStrc*); // 0x0061A660
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
void __fastcall sub_00571F90(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00571F90

typedef void (__fastcall* AUTOMAPFN)(void*);

typedef void (__fastcall* TOWNAUTOMAPFN)(void*);

unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame); // 0x0053FCE0
int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame); // 0x0053F5D0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x006194A0
void __fastcall sub_0059AC40(D2GameStrc* pGame, unsigned char nAct); // 0x0059AC40


unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState); // 0x005386D0
void __fastcall sub_00575BC0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00575BC0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall D2Common_10229(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, unsigned int nX, unsigned int nY); // 0x00650BE0
void __fastcall sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom); // 0x005381F0
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader); // 0x0053B320
void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct); // 0x005382E0
void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0053ABE0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005754B0
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600
void __fastcall sub_005738D0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005738D0
void __fastcall D2GAME_PACKETS_SendPacket0x08_6FC3D160(D2ClientStrc* pClient, int nLevelId, int nX, int nY); // 0x0053BC90

static void sub_0053AA70_UpdateUnitTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

static inline int UNITS_GetUnitTypeOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x0053A6A0
static void sub_0053A6A0_FixRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x62);
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        sub_005531E0_FixRoomIfInvalid(pUnit, pClient);
}

// 0x0053A880
static void sub_0053A880_UpdateMonsterAiCallbacks(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 1:
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
            break;
        }
    }
}

// 0x0053A8B0
static void sub_0053A8B0_DeleteMonsterEvents(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 1:
            MONSTER_DeleteEvents(pGame, pUnit);
            break;
        }
    }
}

void __fastcall sub_M126_Emit_0053A6A0(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient, int nUnused)
{
    sub_0053A6A0_FixRoomUnits(pRoom, pClient);
}

void __fastcall sub_M126_Emit_0053A880(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused)
{
    sub_0053A880_UpdateMonsterAiCallbacks(pGame, pRoom);
}

void __fastcall sub_M126_Emit_0053A8B0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused)
{
    sub_0053A8B0_DeleteMonsterEvents(pGame, pRoom);
}

void __fastcall sub_M126_Emit_0053AA70(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        sub_0053AA70_UpdateUnitTarget(pGame, pUnit, pTarget);
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x0053A8E0
void __fastcall LEVEL_AddClient(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    if (!hRoom) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 207); exit(-1); }
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &tCoords);
    D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(hRoom), tCoords.nTileX, tCoords.nTileY);
    DUNGEON_AddClientToRoom(hRoom, pClient);
    if (hRoom->nNumClients <= 1)
    {
        for (D2UnitStrc* pUnit = hRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
            switch (nUnitType)
            {
            case 1: MONSTER_UpdateAiCallbackEvent(pGame, pUnit); break;
            }
        }
    }
    D2UnitStrc* pUnit = hRoom->pUnitFirst;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    while (pUnit)
    {
        if (pPlayer != pUnit) sub_00571F90(pGame, pUnit, pClient);
        pUnit = pUnit->pRoomNext;
    }
}

// 0x0053A9B0
void __fastcall LEVEL_RemoveClient(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(hRoom, 0x104);

    for (D2UnitStrc* pUnit = hRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        sub_00571600(pUnit, pClient);
    }

    DUNGEON_RemoveClientFromRoom(hRoom, pClient);

    if (!hRoom->nNumClients)
    {
        for (D2UnitStrc* pUnit = hRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                sub_005738D0(pGame, pUnit);
                break;
            }
        }
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &drlgCoords);
    D2GAME_PACKETS_SendPacket0x08_6FC3D160(pClient, DUNGEON_GetLevelIdFromRoom(hRoom), drlgCoords.nTileX, drlgCoords.nTileY);
}

// 0x0053AA70
static void sub_0053AA70_UpdateUnitTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
    {
    case 0:
        sub_00534AB0_ClearTargetIfMatch(pGame, pUnit, pTarget);
        break;

    case 1:
        sub_00573750_ClearTargetIfMatches(pGame, pUnit, pTarget);
        break;
    }
}

// 0x0053AAA0
void __fastcall sub_0053AAA0_UpdateRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    D2_ASSERT(pRoom, 0x131);

    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 0:
            sub_00534AB0_ClearTargetIfMatch(pGame, pUnit, pTarget);
            break;

        case 1:
            sub_00573750_ClearTargetIfMatches(pGame, pUnit, pTarget);
            break;
        }
    }
}

// 0x0053AC70
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
void __fastcall LEVEL_ChangeAct(D2GameStrc* pGame, D2ClientStrc* ptClient, int nDestinationLevelId, int nTileCalc)
{
    if (ARENA_IsInArenaMode(pGame))
    {
        return;
    }

    const unsigned char bNewAct = DRLG_GetActNoFromLevelId(nDestinationLevelId);
    D2_ASSERT(bNewAct != ptClient->nAct, 0x19F);

    if (!pGame->pAct[bNewAct])
    {
        sub_0053AC70_AllocAct(pGame, bNewAct);
    }

    CLIENTS_SetClientState(ptClient, 5);

    D2UnitStrc* hUnit = CLIENTS_GetPlayerFromClient(ptClient, 0);
    D2_ASSERT(hUnit, 0x1AF);

    if (!pGame->bExpansion && hUnit->dwUnitType == 0)
    {
        sub_00575BC0(pGame, hUnit);
    }

    SKILLS_RemoveTransformStatesFromShapeshiftedUnit(hUnit);

    int nX;
    int nY;
    D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[bNewAct], nDestinationLevelId, nTileCalc, &nX, &nY, UNITS_GetUnitSizeX(hUnit));
    if (!pSpawnRoom)
    {
        return;
    }

    D2CoordStrc tSpawnPoint;
    tSpawnPoint.nX = nX;
    tSpawnPoint.nY = nY;

    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinatesEx(pSpawnRoom, &tSpawnPoint, UNITS_GetUnitSizeX(hUnit), 0x1C89, 5);
    if (!pRoom)
    {
        return;
    }

    nX = tSpawnPoint.nX;
    nY = tSpawnPoint.nY;

    D2DynamicPathStrc* pPath = hUnit->pDynamicPath;
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(hUnit);
    D2_ASSERT(D2Common_10229(pPath, hUnit, 0, 0, 0), 0x1D1);

    sub_6FCBB190(pGame, hUnit, pOldRoom);
    D2_ASSERT(D2Common_10229(pPath, hUnit, pRoom, nX, nY), 0x1D6);

    CLIENTS_SetRoomInClient(ptClient, 0);
    D2GAME_PACKETS_SendHeaderOnlyPacket(ptClient, 5);
    CLIENTS_SetActNo(ptClient, bNewAct);
    hUnit->nAct = bNewAct;
    hUnit->pDrlgAct = pGame->pAct[bNewAct];
    LEVEL_SynchronizeDayNightCycleWithClient(pGame, ptClient);
    CLIENTS_SetRoomInClient(ptClient, pRoom);
    UNITROOM_RefreshUnit(hUnit);
    hUnit->dwFlagEx |= 0x10000;
    sub_6FCBB190(pGame, hUnit, 0);
    UNITROOM_RefreshUnit(hUnit);

    if (hUnit->dwUnitType == 0)
    {
        PLAYERPETS_UpdatePetsForOwnerMove(pGame, hUnit, CLIENTS_GetUnitX(hUnit), CLIENTS_GetUnitY(hUnit));
    }
}

// 0x0053AFB0
void __fastcall sub_0053AFB0_EnsureAct(D2GameStrc* pGame, unsigned char nAct)
{
    if (!pGame->pAct[nAct])
    {
        sub_0053AC70_AllocAct(pGame, nAct);
    }
}
