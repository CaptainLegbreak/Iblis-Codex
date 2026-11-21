#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
#include "D2GameObjs.h"

#define UNIT_PLAYER 0
#define PLRMODE_DEAD 17
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_PERIODICSTATS 9

struct D2ObjectDataStrc;
union D2SeedStrc;
struct D2ObjectControlStrc;
struct D2ObjOperateFnStrc;



void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00581680
static void __stdcall sub_00581680_DamagePlayersInRange(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->ptRoomNext)
    {
        const int nType = (i ? i->dwUnitType : 6);
        const int nMode = (i ? i->dwAnimMode : 0);
        if (nType == UNIT_PLAYER && nMode != PLRMODE_DEAD && sub_006416D0_UnitEdgeDistance(pObject, i) <= pObjectsTxtRecord->dwParm[0] + 1)
        {
            OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, i, 1);
        }
    }
}

void __fastcall OBJMODE_UpdateTrappedSoul(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    switch (nMode)
    {
    case 1:
        EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 10, 0, 0);
        break;

    case 2:
    {
        D2ObjectDataStrc* pObjectData = pObject->pObjectData;
        const unsigned char nInteract = pObjectData->InteractType + 1;
        pObjectData->InteractType = nInteract;
        if (nInteract > 1)
        {
            D2ObjOperateFnStrc tOp;
            tOp.pGame = pGame;
            tOp.hObject = pObject;
            tOp.hPlayer = 0;
            tOp.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            tOp.nObjectIdx = pObject->dwClassId;
            if (OBJMODE_DropFromChestTCWithQuality(&tOp, 0))
            {
                UNITS_ChangeAnimMode(pObject, 3);
                EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, (pObjectsTxtRecord->dwFrameCnt[3] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            }
        }
        else
        {
            OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            sub_00581680_DamagePlayersInRange(pGame, pObject);
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 25, 0, 0);
        }
        break;
    }

    case 3:
        UNITS_ChangeAnimMode(pObject, 4);
        break;
    }
}

// 0x00581700
void __fastcall OBJMODE_UpdateTrapProximity(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwAnimMode == 1)
    {
        pObject->dwAnimMode = 2;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
    sub_00581680_DamagePlayersInRange(pGame, pObject);
    EVENT_SetEvent(pGame, pObject, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + SEED_RollRandomNumber_Inline(&pObjectControl->pSeed) % 35 + 15, 0, 0);
}
