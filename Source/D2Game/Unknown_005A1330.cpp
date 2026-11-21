#include "D2Structs.h"
#include "D2GameStrc.h"


D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005A1330
void __fastcall MONSTERUNIQUE_UMod41_AlwaysRun(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
        if (pGame)
        {
            EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 75, 0, 0);
        }
    }
}
