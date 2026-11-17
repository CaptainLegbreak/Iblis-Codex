struct D2GameStrc;
struct D2UnitStrc;

D2UnitStrc* __fastcall sub_6FC68D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

#define MONSTER_DEMONHOLE 711
#define MONMODE_NEUTRAL 1

// 0x005E9DD0
void __fastcall AITHINK_SpawnUberDiabloMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget)
    {
        sub_6FC68D70(pGame, pTarget, MONSTER_DEMONHOLE, MONMODE_NEUTRAL, 4, 64);
    }
}
