struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xE4];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    unsigned int nNumClients;
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

struct D2UnkAiTableStrc
{
    int nType;
    AIUTIL_TargetCallback pfCallback;
};

struct D2PartyCallbackArgStrc
{
    AIUTIL_TargetCallback pfCallback;
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    void* unk0x0C;
};

extern const D2UnkAiTableStrc gAiTargetSearchTable_006E3300[];                                              // 0x006E3300
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380
void __fastcall sub_6FCF20E0(D2UnitStrc* pUnit, void* pArg, void* ppUnit);                                  // 0x005DD020
D2UnitStrc* __stdcall sub_005DCEE0_FindPlayerTargetInAdjacentRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback); // 0x005DCEE0

// 0x005DCE60
static D2UnitStrc* __stdcall AIUTIL_FindTargetInAdjacentRooms(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst; pTarget; pTarget = pTarget->pRoomNext)
        {
            D2UnitStrc* pResult = pfCallback(pGame, pUnit, pTarget, pCallbackArg);
            if (pResult)
            {
                return pResult;
            }
        }
    }

    return 0;
}

// build: context sub_005DCF70_FindTargetInAdjacentActiveRooms
// calling-convention shim (not game code)
static D2UnitStrc* __stdcall sub_005DCF70_FindTargetInAdjacentActiveRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    if (!pUnit || SUNIT_IsDead(pUnit))
        return 0;
    D2UnitStrc* pTarget = (D2UnitStrc*)UNITS_GetRoom(pUnit);
    if (!pTarget || SUNIT_IsDead(pTarget) || SUNIT_IsDead(pTarget->pRoomNext))
        return 0;
    return pfCallback(pGame, pUnit, pTarget, pCallbackArg);
}

// 0x005DD050
static D2UnitStrc* __stdcall sub_005DD050_FindTargetAmongMinions(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (pOwner->dwUnitType != 1)
    {
        return 0;
    }

    D2UnitStrc* pTarget = 0;
    D2PartyCallbackArgStrc partyCallbackArg;
    partyCallbackArg.pfCallback = pfCallback;
    partyCallbackArg.pGame = pGame;
    partyCallbackArg.pUnit = pUnit;
    partyCallbackArg.unk0x0C = pCallbackArg;

    AIGENERAL_ExecuteCallbackOnMinions(pOwner, &partyCallbackArg, &pTarget, sub_6FCF20E0);
    return pTarget;
}

// 0x005DD0B0
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfFallbackCallback, int nCallbackId)
{
    const int nType = gAiTargetSearchTable_006E3300[nCallbackId].nType;
    AIUTIL_TargetCallback pfCallback = gAiTargetSearchTable_006E3300[nCallbackId].pfCallback ? gAiTargetSearchTable_006E3300[nCallbackId].pfCallback : pfFallbackCallback;
    if (!pfCallback)
    {
        return 0;
    }

    switch (nType)
    {
    case 1:
        return sub_005DCEE0_FindPlayerTargetInAdjacentRooms(pGame, pUnit, pCallbackArg, pfCallback);
    case 2:
        return sub_005DCF70_FindTargetInAdjacentActiveRooms(pGame, pUnit, pCallbackArg, pfCallback);
    case 3:
        return sub_005DD050_FindTargetAmongMinions(pGame, pCallbackArg, pfCallback, pUnit);
    default:
        return AIUTIL_FindTargetInAdjacentRooms(pGame, pCallbackArg, pfCallback, pUnit);
    }
}
