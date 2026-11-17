struct D2GameStrc;
struct D2UnitStrc;

int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);                                       // 0x00554CA0
void __fastcall sub_005A8030(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005A8030
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x005C9D90
void __fastcall SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x005CE4F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

#define STATE_BLAZE 0x0D
#define STATE_SPIDERLAY 0x16

// 0x005A8490
int __fastcall sub_6FC64480(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (STATES_CheckState(pUnit, STATE_BLAZE))
    {
        SKILLS_CreateBlazeMissile(pGame, pUnit);
    }

    if (STATES_CheckState(pUnit, STATE_SPIDERLAY))
    {
        SKILLS_CreateSpiderLayMissile(pGame, pUnit);
    }

    if (sub_6FCBC930(pGame, pUnit) == 2)
    {
        sub_005A8030(pGame, pUnit);
        return 2;
    }

    return 1;
}

// 0x005A84F0
int __fastcall sub_6FC64510(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (sub_6FCBC930(pGame, pUnit) == 2)
    {
        sub_005A8030(pGame, pUnit);
        return 2;
    }

    return 1;
}
