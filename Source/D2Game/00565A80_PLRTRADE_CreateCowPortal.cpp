struct D2GameStrc;
struct D2UnitStrc;

int __fastcall ACT1Q4_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00594140

// 0x00565A80
int __fastcall PLRTRADE_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateCowPortal(pGame, pUnit);
}
