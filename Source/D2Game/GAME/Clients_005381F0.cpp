#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }




struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    unsigned char nAct;
    char unk0x009[0x163];
    int dwUnitType;
    int dwUnitGUID;
    D2UnitStrc* pPlayer;
    char unk0x178[0x30];
    D2GameStrc* pGame;
    char unk0x1AC[4];
    int unk0x1B0;
    D2ActiveRoomStrc* pRoom;
    char unk0x1B8[0x21C];
    unsigned int dwFlags;
};

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define CLIENTFLAGEX_PLAYER_UNIT_ALIVE 1

void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom);            // 0x0061A110
void __stdcall D2Common_10077(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom);                      // 0x0061A9F0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
void __fastcall LEVEL_AddClient(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient);         // 0x0053A8E0
void __fastcall LEVEL_RemoveClient(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient);      // 0x0053A9B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
void __fastcall sub_6FC81650(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4);          // 0x00580860
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);                             // 0x006221E0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall LEVEL_RemoveUnitsExceptClientPlayer(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient);        // 0x0053A770
void __fastcall LEVEL_UpdateUnitsInAdjacentRooms(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient); // 0x0053A620
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, void(__fastcall* pfCallback)(D2UnitStrc*, unsigned short, unsigned int, D2UnitStrc*)); // 0x006258D0
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x0055F4F0
void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nSourceLevelId, int nDestinationLevelId, D2UnitStrc* pPlayer); // 0x00543B90
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId); // 0x00537340
void __fastcall ARENA_SynchronizeWithClients(D2GameStrc* pGame, D2ClientStrc* pClient);                     // 0x0053FC20
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall sub_00539760(D2ClientStrc* pClient, D2GameStrc* pGame, int a3, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00539760
void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005394A0

inline int M08_UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int M08_UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context sub_M08_GetClientPlayerUnit
static __forceinline D2UnitStrc* sub_M08_GetClientPlayerUnit(D2ClientStrc* pClient)
{
    if (pClient->dwFlags & CLIENTFLAGEX_PLAYER_UNIT_ALIVE)
    {
        return pClient->pPlayer;
    }
    if (!pClient->pPlayer)
    {
        return 0;
    }
    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pClient->pGame, pClient->dwUnitType, pClient->dwUnitGUID);
    if (!pUnit)
    {
        pClient->pPlayer = 0;
    }
    return pUnit;
}

static void __stdcall sub_00537B50_ChangeClientRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    if (!pClient || !pClient->pGame)
    {
        return;
    }
    D2ActiveRoomStrc* pClientRoom = pClient->pRoom;
    if (pClientRoom == pRoom)
    {
        return;
    }
    DUNGEON_ChangeClientRoom(pClientRoom, pRoom);
    D2Common_10077(pClientRoom, pRoom);

    D2ActiveRoomStrc** ppAdjacentRooms = 0;
    int nAdjacentRooms = 0;
    if (pRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppAdjacentRooms, &nAdjacentRooms);
    }

    D2ActiveRoomStrc** ppClientAdjacentRooms = 0;
    int nClientAdjacentRooms = 0;
    if (pClientRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppClientAdjacentRooms, &nClientAdjacentRooms);
    }

    for (int i = 0; i < nAdjacentRooms; ++i)
    {
        int j = 0;
        while (j < nClientAdjacentRooms)
        {
            if (ppAdjacentRooms[i] == ppClientAdjacentRooms[j])
            {
                break;
            }
            ++j;
        }
        if (j >= nClientAdjacentRooms)
        {
            LEVEL_AddClient(pClient->pGame, ppAdjacentRooms[i], pClient);
        }
    }

    for (int i = 0; i < nClientAdjacentRooms; ++i)
    {
        int j = 0;
        while (j < nAdjacentRooms)
        {
            if (ppClientAdjacentRooms[i] == ppAdjacentRooms[j])
            {
                break;
            }
            ++j;
        }
        if (j >= nAdjacentRooms)
        {
            LEVEL_RemoveClient(pClient->pGame, ppClientAdjacentRooms[i], pClient);
            if (pClient->pRoom == ppClientAdjacentRooms[i])
            {
                sub_6FC81650(pClient->pGame, sub_M08_GetClientPlayerUnit(pClient), pClient, 0);
            }
        }
    }

    pClient->pRoom = pRoom;
    if (pRoom && pClient->pPlayer)
    {
        UNITS_SetPlayerPortalFlags(pClient->pPlayer, UNITS_GetPlayerPortalFlags(pClient->pPlayer) | DUNGEON_GetPortalFlagFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)));
    }
}

static __forceinline int sub_M08_GetUnitFlagEx21(D2UnitStrc* pUnit)
{
    return (pUnit->dwFlagEx >> 21) & 1;
}

void __fastcall sub_6FC33670(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (!pGame || !pClient)
    {
        return;
    }
    D2ActiveRoomStrc* pClientRoom = pClient->pRoom;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    LEVEL_RemoveUnitsExceptClientPlayer(pClientRoom, pClient);
    LEVEL_UpdateUnitsInAdjacentRooms(pGame, pClientRoom, pClient);
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute_6FC822D0);
    if (sub_M08_GetUnitFlagEx21(pPlayer))
    {
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pPlayer, 1, 1);
        sub_0055F4F0(pGame, pPlayer, 1);
    }
    ++pClient->unk0x1B0;
    if (pClientRoom != pRoom)
    {
        const int nSourceLevelId = DUNGEON_GetLevelIdFromRoom(pClientRoom);
        const int nDestinationLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nSourceLevelId != nDestinationLevelId)
        {
            QUESTS_ChangeLevel(pGame, nSourceLevelId, nDestinationLevelId, pPlayer);
            SUNITPROXY_UpdateNpcsOnActChange(pGame, pPlayer, nSourceLevelId, nDestinationLevelId);
        }
        sub_00537B50_ChangeClientRoom(pRoom, pClient);
    }
    ARENA_SynchronizeWithClients(pGame, pClient);
    if (UNITS_GetRoom(pPlayer))
    {
        UNITROOM_RefreshUnit(pPlayer);
    }
}

// 0x005381F0
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pClient, 1951);
    if (pRoom != pClient->pRoom)
    {
        sub_00537B50_ChangeClientRoom(pRoom, pClient);
    }
    pClient->pRoom = pRoom;
}

static void sub_M08_RemoveUnitFromRoom(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit), pUnit->dwUnitType, pUnit->dwUnitId);
    SUNIT_RemoveUnit(pGame, pUnit);
}

void __fastcall sub_0053A2F0_ResetClientInAct(D2ClientStrc* pClient, int nAct)
{
    D2_ASSERT(pClient, 2386);
    pClient->nAct = nAct;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    pClient->nAct = nAct;
    const int nX = M08_UNITS_GetXPositionInline(pPlayer);
    const int nY = M08_UNITS_GetYPositionInline(pPlayer);
    D2GameStrc* pGame = pClient->pGame;
    sub_M08_RemoveUnitFromRoom(pGame, pPlayer);
    sub_00539760(pClient, pGame, 0, pRoom, nX, nY);
    sub_005394A0(pClient, pClient->pPlayer, pGame, pRoom, nX, nY);
    pClient->dwFlags &= ~CLIENTFLAGEX_PLAYER_UNIT_ALIVE;
    if (pRoom != pClient->pRoom)
    {
        sub_00537B50_ChangeClientRoom(pRoom, pClient);
    }
    pClient->pRoom = pRoom;
}
