#include "D2Structs.h"
struct T005A61F0 { char unk_00[0x18]; int nVelocity; int nVelocityPercent; unsigned char nVelocityFlags; };
struct D2MonsterDataStrc { char unk_00[0x2C]; T005A61F0* pMode; };
static inline int GetUnitType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }
inline T005A61F0* __fastcall GetMonsterMode(D2UnitStrc* pUnit)
{
    if (GetUnitType(pUnit) == 1)
    {
        D2MonsterDataStrc* pData = pUnit->pMonsterData;
        if (pData) return pData->pMode;
    }
    return 0;
}

// 0x005A61F0
void __fastcall D2GAME_MONSTERMODE_ResetVelocityParams_6FC62F90(D2UnitStrc* pUnit)
{
    T005A61F0* pMode = GetMonsterMode(pUnit);
    pMode->nVelocity = 0;
    pMode->nVelocityPercent = 0;
    pMode->nVelocityFlags = 0;
}
