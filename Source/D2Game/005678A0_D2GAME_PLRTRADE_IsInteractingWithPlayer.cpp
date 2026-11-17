struct D2GameStrc;
struct D2UnitStrc;

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100

#define UNIT_PLAYER 0

// 0x005678A0
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    int nUnitType;
    int nUnitGUID;

    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && nUnitType == UNIT_PLAYER && SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID))
    {
        return 1;
    }

    return 0;
}
