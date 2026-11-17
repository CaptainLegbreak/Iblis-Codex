struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define UNIT_PLAYER 0
#define UNIT_INVALID 6
#define STATE_BLOODMANA 114
#define STAT_MANA 8

int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost);                          // 0x005D2B60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

// 0x0056C110
int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    if (STATES_CheckState(pUnit, STATE_BLOODMANA))
    {
        return D2GAME_SKILLS_BloodMana_6FD025E0(pUnit, nManaCost);
    }

    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }

    STATLIST_AddUnitStat(pUnit, STAT_MANA, -nManaCost, 0);
    return 1;
}
