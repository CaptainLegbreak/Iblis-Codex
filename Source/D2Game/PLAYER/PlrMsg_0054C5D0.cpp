#include "D2Game.h"
#include "D2Structs.h"

struct D2PlayerDataStrc;

struct D2StaticPathStrc
{
    char unk0x00[0xC];
    int nX;
    int nY;
};


struct D2GameStrc
{
    int unk0x00;
};

struct D2DataTablesStrc
{
    char unk0x00[0xC5C];
    int nLevelsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer);    // 0x00547F50
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x00554D00
unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);             // 0x0055B6C0
void __fastcall sub_00584F60(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId); // 0x00584F60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo);                // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField);                      // 0x00660E50

static __forceinline int PLRMSG_J07_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int PLRMSG_J07_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __declspec(noinline) int __stdcall sub_6FC83C60(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance)
{
    const int nUnitX = PLRMSG_J07_GetUnitX(pUnit);
    const int nUnitY = PLRMSG_J07_GetUnitY(pUnit);

    int nXDiff = nUnitX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    if (nXDiff <= nMaxDistance)
    {
        int nYDiff = nUnitY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff <= nMaxDistance)
        {
            return 0;
        }
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_00549570_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    if (!pObject)
    {
        return 1;
    }

    const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject))))
    {
        return 2;
    }

    struct
    {
        unsigned short nWaypointNo;
        int nX;
    } tLocal;
    tLocal.nX = PLRMSG_J07_GetUnitX(pObject);
    const int nY = PLRMSG_J07_GetUnitY(pObject);
    int nMaxDistance = 0xA;
    if (pUnit && pUnit->dwClassId == 1)
    {
        nMaxDistance = 0x16;
    }

    const int nResult = sub_6FC83C60(tLocal.nX, nY, pUnit, nMaxDistance);
    if (nResult)
    {
        return nResult;
    }

    if (!nLevelId)
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 3;
    }

    D2_ASSERT(UNITS_GetPlayerData(pUnit), 0x632);

    if (!WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &tLocal.nWaypointNo))
    {
        return 3;
    }

    return WAYPOINTS_IsActivated(sub_00547F50(pGame, pUnit), tLocal.nWaypointNo) ? 0 : 2;
}

// 0x0054C5D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp_6FC87E60(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nWaypointGUID = *(int*)(pPacket + 1);
    const int nLevelId = *(unsigned short*)(pPacket + 5);
    const unsigned int nTick = PLAYERLIST_GetHostileDelay(pUnit, 0) + 0x2710;
    if (nTick > GetTickCount())
    {
        SUNIT_AttachSound(pUnit, 0x13, pUnit);
        SUNIT_ResetInteractInfo(pUnit);
        return 1;
    }

    const int nResult = sub_00549570_CheckWaypointObject(pGame, nLevelId, pUnit, nWaypointGUID);
    if (nResult)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
        if (pWaypoint && pWaypoint == pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pUnit);
        }

        return nResult;
    }

    sub_00584F60(pGame, pUnit, nWaypointGUID, nLevelId);
    return 0;
}
