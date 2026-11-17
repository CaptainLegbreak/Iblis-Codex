struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x60];
    int dwInteractGUID;
    int dwInteractType;
    unsigned char nInteract;
    char unk0x6D[0x13];
    D2GameStrc* pGame;
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00540710
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

#define UNIT_PLAYER 0
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_ENDANIM 1

// 0x00553990
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
}

// 0x00554630
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->pGame && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        return PARTY_GetPartyIdForUnitOwner(pPlayer->pGame, pPlayer);
    }

    return -1;
}

// 0x00554D00
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType = pUnit->dwInteractType;
    int nUnitGUID = pUnit->dwInteractGUID;
    if (pUnit->nInteract)
    {
        return SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    }

    return 0;
}
