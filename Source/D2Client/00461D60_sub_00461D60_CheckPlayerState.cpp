struct D2PlayerDataStrc
{
    char unk_000[0x154];
    int nState;
    int nValue1;
    int nValue2;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk_04[0x10];
    D2PlayerDataStrc* pPlayerData;
};

enum { UNIT_PLAYER = 0 };

D2UnitStrc* __fastcall sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

static __forceinline int PLAYER_GetValue1(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData->nValue1;
    return 0;
}

static __forceinline int PLAYER_GetValue2(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == UNIT_PLAYER)
        return pUnit->pPlayerData->nValue2;
    return 0;
}

// 0x00461D60
int __stdcall sub_00461D60_CheckPlayerState(int nValue1, int nValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nUnitType = !pPlayer ? 6 : pPlayer->dwUnitType;
    if (!pPlayer || nUnitType != UNIT_PLAYER)
        return 0;

    D2PlayerDataStrc* pPlayerData = pPlayer->pPlayerData;
    if (!pPlayerData || pPlayerData->nState != 19)
        return 0;

    const int nFirst = PLAYER_GetValue1(pPlayer);
    const int nSecond = PLAYER_GetValue2(pPlayer);
    if (nFirst == nValue1 && nSecond == nValue2)
        return 1;
    return 0;
}
