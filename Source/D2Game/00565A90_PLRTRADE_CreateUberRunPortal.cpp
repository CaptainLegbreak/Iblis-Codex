struct D2GameStrc;
struct D2UnitStrc;

int __fastcall ACT1Q4_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00594270
int __fastcall ACT1Q4_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00594280

// 0x00565A90
int __fastcall PLRTRADE_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateUberRunPortal(pGame, pUnit);
}

// 0x00565AA0
int __fastcall PLRTRADE_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateUberFinalePortal(pGame, pUnit);
}
