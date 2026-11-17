struct D2PlayerDataStrc
{
    char unk0x00[0x150];
    int nState;
    int nMode;
    int nArg1;
    int nArg2;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[4];
    D2PlayerDataStrc* pPlayerData;
};

void __fastcall sub_00460780_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2);             // 0x00460780

#define UNIT_PLAYER 0
#define UNIT_INVALID 6

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x00641F20
void __fastcall sub_00641F20_SetPlayerModeState(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        if (D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit))
        {
            pPlayerData->nState = 1;
        }

        sub_00460780_SetPlayerMode(nMode, pUnit, nArg1, nArg2);
    }
}

// 0x006432C0
void __stdcall DUNGEON_ClientToGameTileCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;
    *pX = (2 * nY + nX) / 160;
    *pY = (2 * nY - nX) / 160;
}
