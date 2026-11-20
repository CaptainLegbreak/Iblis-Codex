#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"

struct D2PlayerDataStrc;

enum D2C_ResultFlagsConstants
{
    PLRMODE_RUN = 3,
    STATE_UNINTERRUPTABLE = 0x36,
};


int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0
int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4, int a5); // 0x0057DFB0
int __fastcall sub_005A4EE0_IsMonster(D2UnitStrc* pUnit); // 0x005A4EE0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

struct D2PlayerDataStrc
{
    char unk0x000[0x154];
    int nField154;
};

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x0057EC10
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset)
{
    int nFlags = 0;

    if (!pAttacker || !pDefender)
    {
        return 0;
    }

    if (pAttacker->dwUnitType != UNIT_PLAYER && pAttacker->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pDefender->dwUnitType != UNIT_PLAYER && pDefender->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (!sub_00554200(pGame, pAttacker, pDefender))
    {
        return 0;
    }

    switch (pDefender->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pDefender->dwAnimMode == PLRMODE_RUN)
        {
            nFlags = 1;
        }
        break;

    case UNIT_MONSTER:
        if (!sub_005A4EE0_IsMonster(pDefender))
        {
            return 0;
        }
        break;
    }

    int nRange = sub_0044BE50(pAttacker) == UNIT_MONSTER ? 3 : 1;
    if (nRangeOffset)
    {
        nRange -= UNITS_GetMeleeRange(pAttacker) + nRangeOffset;
    }

    if (!UNITS_IsInMeleeRange(pAttacker, pDefender, nRange))
    {
        return 0;
    }

    if (!(nFlags & 1))
    {
        if (SUNITDMG_IsHitSuccessful(pAttacker, pDefender, nStatValue, 0))
        {
            nFlags |= 1;
        }
    }

    if (nFlags & 1)
    {
        const int nBlock = SUNITDMG_ApplyBlockOrDodge(pGame, pAttacker, pDefender, 0, 1);
        if (nBlock & 2)
        {
            nFlags |= 0x100;
        }
        if (nBlock & 4)
        {
            nFlags |= 0x80;
        }
        if (nBlock & 0x10)
        {
            nFlags |= 0x8000;
        }
        if (nBlock & 1)
        {
            nFlags |= 0x10;
        }
        if (nBlock)
        {
            nFlags &= 0xFFFE;
        }
    }

    if (nFlags & 0x10)
    {
        nFlags &= 0xFFFE;
    }

    if (nFlags & 1)
    {
        if (!STATES_CheckState(pDefender, STATE_UNINTERRUPTABLE))
        {
            nFlags |= 4;
        }
    }

    return nFlags;
}

// 0x0057ED50
void __fastcall sub_0057ED50_SetPlayerDataField154(D2UnitStrc* pUnit, int nValue)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nField154 = nValue;
    }
}
