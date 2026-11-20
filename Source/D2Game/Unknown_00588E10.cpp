#include "D2Game.h"
#include "D2Structs.h"

struct D2GameStrc
{
    unsigned char unk_00[0x6A];
    unsigned char nGameType;
};


struct D2ActiveRoomStrc
{
    unsigned char unk_00[0x74];
    D2UnitStrc* pUnitFirst;
};

D2ClientStrc* __fastcall sub_00539070_GetFirstClient(D2GameStrc* pGame); // 0x00539070
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bValidate); // 0x00537860
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

// 0x00588E10
int __fastcall sub_00588E10_IsMonsterNearby(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pDefault)
{
    if (!pUnit)
    {
        if (pGame->nGameType == 3)
        {
            D2ClientStrc* pClient = sub_00539070_GetFirstClient(pGame);
            if (pClient)
            {
                pUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
            }
        }
        if (!pUnit)
        {
            pUnit = pDefault;
        }
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        goto NotFound;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst; pTarget; pTarget = pTarget->pRoomNext)
        {
            if ((!pTarget ? 6 : pTarget->dwUnitType) == 1 && (!pTarget ? -1 : pTarget->dwClassId) == 0x1B2 && (!pTarget ? 0 : pTarget->dwAnimMode) == 12)
            {
                return 1;
            }
        }
    }

NotFound:
    return 0;
}
