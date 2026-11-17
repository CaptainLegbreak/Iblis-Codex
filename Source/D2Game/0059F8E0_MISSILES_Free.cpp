struct D2GameStrc;
struct D2UnitStrc;

void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile);                                               // 0x0064A150
void __fastcall sub_6FC349F0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0

// 0x0059F8E0
void __fastcall MISSILES_Free(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    MISSILE_FreeMissileData(pMissile);
    sub_6FC349F0(pGame, pMissile);
}
