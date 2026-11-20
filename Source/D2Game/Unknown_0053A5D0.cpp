#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Drlg.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }



struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates;
};


#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
void __fastcall sub_6FC81650(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4);          // 0x00580860
void __fastcall sub_6FC75350(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient);                  // 0x00581AD0
void __fastcall sub_6FC420B0(D2UnitStrc* pUnit, D2ClientStrc* pClient);                                     // 0x0055BF30
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

static void __stdcall sub_0053A500_UpdateUnitForClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit, 21);
    const int nUnitType = pUnit->dwUnitType;
    int v10 = 0;
    if (pUnit->dwFlags)
    {
        if (CLIENTS_GetPlayerFromClient(pClient, 0) != pUnit)
        {
            if (nUnitType == UNIT_MISSILE)
            {
                return;
            }
            sub_00571F90(pGame, pUnit, pClient);
            v10 = 1;
        }
    }
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        sub_6FC81650(pGame, pUnit, pClient, v10);
        break;
    case UNIT_MONSTER:
        sub_6FC659E0(pGame, pUnit, pClient, v10);
        break;
    case UNIT_OBJECT:
        sub_6FC75350(pGame, pUnit, pClient);
        break;
    case UNIT_ITEM:
        sub_6FC420B0(pUnit, pClient);
        break;
    default:
        break;
    }
}

// 0x0053A5D0
static void __stdcall sub_0053A5D0_UpdateRoomUnitsForClient(D2GameStrc* pGame, D2ActiveRoomStrc* pAdjacentRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pAdjacentRoom, 68);
    D2UnitStrc* pUnit = pAdjacentRoom->pUnitUpdate;
    while (pUnit)
    {
        D2UnitStrc* pNextUnit = pUnit->pChangeNextUnit;
        sub_0053A500_UpdateUnitForClient(pGame, pUnit, pClient);
        pUnit = pNextUnit;
    }
}

// 0x0053A620
void __fastcall LEVEL_UpdateUnitsInAdjacentRooms(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    if (!pGame->pAct[CLIENTS_GetActNo(pClient)]->bHasPendingUnitListUpdates)
    {
        return;
    }
    D2_ASSERT(pRoom, 87);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        sub_0053A5D0_UpdateRoomUnitsForClient(pGame, ppRoomList[i], pClient);
    }
}
