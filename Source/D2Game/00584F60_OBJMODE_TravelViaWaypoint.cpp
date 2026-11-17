struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2DrlgActStrc;
struct D2WaypointDataStrc;
struct D2ObjOperateFnStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2ObjectsTxt
{
    char unk0x00[0x1B3];
    unsigned char nOperateFn;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

typedef int (__fastcall* ObjOperateFunction)(D2ObjOperateFnStrc* pOp, int nOperate);

extern ObjOperateFunction gpObjOperateFnTable_00732D18[];                                                   // 0x00732D18
int __fastcall OBJECTS_OperateFunction23_Waypoint(D2ObjOperateFnStrc* pOp, int nOperate);                   // 0x00584E30
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
void __fastcall OBJRGN_AllocObjectRoomCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00547170
D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer);      // 0x00547F50
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);                                                  // 0x00554190
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x00619E50
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId);                                                          // 0x0061AAF0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit);                              // 0x00621B30
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, int* pWaypointNo);                           // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, int nWaypointNo);                            // 0x00660E50

static __forceinline int sub_F05_WpGetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x00584F60
void __fastcall OBJMODE_TravelViaWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nWaypointGUID, int nLevelId)
{
    D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
    if (!pWaypoint)
    {
        return;
    }

    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pWaypoint);
    if (!pObjectsTxtRecord)
    {
        return;
    }

    const unsigned char nOperateFn = pObjectsTxtRecord->nOperateFn;
    if (nOperateFn >= 0x65 || gpObjOperateFnTable_00732D18[nOperateFn] != OBJECTS_OperateFunction23_Waypoint)
    {
        return;
    }

    const int nDestLevelId = (unsigned short)nLevelId;
    const int nWaypointLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pWaypoint));
    SUNIT_ResetInteractInfo(pPlayer);

    if (nWaypointLevelId == nDestLevelId || !(unsigned short)nLevelId)
    {
        return;
    }

    D2WaypointDataStrc* pWaypointData = sub_00547F50(pGame, pPlayer);
    int nWaypointNo;
    if (!WAYPOINTS_GetWaypointNoFromLevelId(nDestLevelId, &nWaypointNo) || !WAYPOINTS_IsActivated(pWaypointData, nWaypointNo))
    {
        return;
    }

    int nTileIndex;
    if (DUNGEON_IsTownLevelId(nDestLevelId) || nDestLevelId == 46 || nDestLevelId == 74 || nDestLevelId == 133
        || nDestLevelId == 134 || nDestLevelId == 135 || nDestLevelId == 136)
    {
        nTileIndex = 13;
    }
    else
    {
        nTileIndex = 0;
    }

    LEVEL_WarpUnit(pGame, pPlayer, nDestLevelId, nTileIndex);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    int nX;
    int nY;
    if (pRoom && pRoom == DUNGEON_FindActSpawnLocation(pGame->pAct[DRLG_GetActNoFromLevelId(nDestLevelId)], nDestLevelId, nTileIndex, &nX, &nY))
    {
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 0x1072);
        const int nUnitGUID = sub_F05_WpGetUnitId(pPlayer);
        D2CoordStrc tCoord;
        UNITS_GetCoords(pPlayer, &tCoord);
        sub_6FC817D0(pGame, pPlayer, 0, 2, tCoord.nX, tCoord.nY, 0);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 13, 0, nUnitGUID, 1, tCoord.nX + 3, tCoord.nY + 3, 0, 0);
    }

    OBJRGN_AllocObjectRoomCoords(pGame, pPlayer, pRoom);
}
