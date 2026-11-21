#include "D2LevelIds.h"
#include "D2Drlg.h"

// 0x006801F0
int __fastcall sub_006801F0_GetCliffPresetId(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->eLevelId == LEVEL_BLOODMOOR) + 0x33;
}
