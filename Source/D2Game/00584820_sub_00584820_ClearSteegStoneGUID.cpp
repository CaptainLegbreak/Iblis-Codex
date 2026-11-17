struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2TimerArg2Strc
{
    int nUnitGUID;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
    int dwUnitId;
};

#define UNIT_PLAYER 0
#define OBJECT_STEEG_STONE 337

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit);                                            // 0x006234F0

// 0x00584820
void __fastcall sub_00584820_ClearSteegStoneGUID(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwClassId == OBJECT_STEEG_STONE)
    {
        D2TimerArg2Strc* pArg = UNITS_GetTimerArg(pObject)->unk0x00;
        if (!pUnit || (pArg && SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pArg->nUnitGUID) == pUnit))
        {
            if (pArg)
            {
                pArg->nUnitGUID = -1;
            }
        }
    }
}
