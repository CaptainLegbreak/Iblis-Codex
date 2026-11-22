#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

union D2SeedStrc;
struct D2ObjectControlStrc;
struct D2PortalFlags00581410Strc;

typedef int (__fastcall* D2ModeCheckFn)(D2GameStrc*, D2UnitStrc*, int, int);

extern D2ModeCheckFn gpModeChecks_00732C10[]; // 0x00732C10

void __fastcall PLRMODE_EndAnimation(D2GameStrc*, D2UnitStrc*, int, int); // 0x00581020

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, int nUnused, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel); // 0x0056CF40

struct D2PortalFlags00581410Strc
{
    unsigned char nFlags;
};

void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, D2PortalFlags00581410Strc tFlags); // 0x00622300
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

// 0x005811D0
void __fastcall sub_005811D0_CheckPlayerMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    if (gpModeChecks_00732C10[!pUnit ? 0 : pUnit->dwAnimMode])
    {
        if (gpModeChecks_00732C10[nMode](pGame, pUnit, nSkillId, nSkillLevel) == 2)
        {
            PLRMODE_EndAnimation(pGame, pUnit, nSkillId, nSkillLevel);
        }
    }
}

#include "gen/data/Source/D2Game/Unknown_005811D0.inc"
#include "D2Txt.h"
#include "D2ItemsWorld.h"

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00581250
void __fastcall sub_00581250_ObjectTimer_Light(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    if (pObject && pObject->dwClassId == 0x18F)
    {
        switch ((unsigned short)nMode)
        {
        case 0:
        case 2:
        {
            D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + (unsigned int)SEED_RollRandomNumber(&pObjectControl->pSeed) % 250 + 25, 0, 0);
            UNITS_ChangeAnimMode(pObject, 1);
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
            EVENT_SetEvent(pGame, pObject, 1, (pObjectsTxt->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            break;
        }
        }
        return;
    }

    switch (ENVIRONMENT_GetPeriodOfDayFromAct(pGame->pAct[0], 0))
    {
    case 0:
        if ((unsigned short)nMode == 2 || (unsigned short)nMode == 1)
        {
            UNITS_ChangeAnimMode(pObject, 0);
        }
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 1000, 0, 0);
        return;

    case 1:
    case 2:
    case 3:
        if (!(unsigned short)nMode)
        {
            UNITS_ChangeAnimMode(pObject, 1);
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
            EVENT_SetEvent(pGame, pObject, 1, (pObjectsTxt->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
        }
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 1000, 0, 0);
        return;

    default:
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 600, 0, 0);
        return;
    }
}

// 0x00581410
void __fastcall sub_00581410_OpenLinkPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    int nPortalLevel = 0x7F;
    switch (nLevelId)
    {
    case LEVEL_ID_ACT5_BARRICADE_1:
        nPortalLevel = 0x7D;
        break;
    case LEVEL_ARREATPLATEAU:
        nPortalLevel = 0x7E;
        break;
    }
    D2UnitStrc* pPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, 0, pUnit, nPortalLevel, nLevelId);
    if (pPortal)
    {
        D2PortalFlags00581410Strc tFlags;
        tFlags.nFlags = UNITS_GetObjectPortalFlags(pPortal) | 3;
        UNITS_SetObjectPortalFlags(pPortal, tFlags);
    }
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit), 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pPortal), 0);
}
