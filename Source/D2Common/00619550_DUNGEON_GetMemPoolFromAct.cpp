struct D2DrlgRoomStrc;
struct D2DrlgStrc;
struct D2DrlgEnvironmentStrc;
struct D2DrlgDeleteStrc;
struct D2UnitStrc;
struct D2PresetUnitStrc;
struct D2LvlWarpTxt;
struct D2DrlgTileDataStrc;
struct D2RoomCoordListStrc;
struct D2ActiveRoomStrc;
typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles;
    int nWalls;
    D2DrlgTileDataStrc* pFloorTiles;
    int nFloors;
    D2DrlgTileDataStrc* pRoofTiles;
    int nRoofs;
};
struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates;
    D2DrlgEnvironmentStrc* pEnvironment;
    int nTownId;
    char unk0x0C[4];
    D2ActiveRoomStrc* pRoom;
    char unk0x14[52];
    D2DrlgStrc* pDrlg;
    ACTCALLBACKFN pfnActCallBack;
    int bClient;
    char unk0x54[8];
    void* pMemPool;
};
struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList;
    char unk0x04[4];
    D2DrlgRoomTilesStrc* pRoomTiles;
    char unk0x0C[4];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[4];
    D2DrlgDeleteStrc* pDrlgDelete;
    D2UnitStrc* pUnitUpdate;
    void* pCollisionGrid;
    int nNumRooms;
    int nAllies;
    D2DrlgActStrc* pAct;
    char unk0x30[4];
    unsigned int dwFlags;
    char unk0x38[20];
    D2DrlgCoordsStrc tCoords;
    char unk0x6C[8];
    D2UnitStrc* pUnitFirst;
    char unk0x78[4];
    D2ActiveRoomStrc* pRoomNext;
};
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall DRLGWARP_ToggleRoomTilesEnableFlag(D2DrlgRoomStrc* pDrlgRoom, int bEnabled);                // 0x0066AB70
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromUnit(D2DrlgRoomStrc* pDrlgRoom, D2UnitStrc* pUnit); // 0x0066AF80
void __fastcall DRLGROOM_GetRGB_IntensityFromRoomEx(D2DrlgRoomStrc* pDrlgRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0066BFD0
D2ActiveRoomStrc* __fastcall sub_6FD788D0(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x0066B2B0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom);                            // 0x0066BFA0
void __fastcall DRLGACTIVATE_SetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B640
void __fastcall DRLGACTIVATE_UnsetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B690
void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2);      // 0x0061B6F0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_StreamRoomAtCoords(D2DrlgStrc* pDrlg, int nX, int nY);            // 0x0061B7B0
int __fastcall DRLGROOM_GetLevelId(D2DrlgRoomStrc* pDrlgRoom);                                              // 0x0066BAB0
int __fastcall DRLGROOM_GetLevelIdFromPopulatedRoom(D2DrlgRoomStrc* pDrlgRoom);                             // 0x0066BB20
int __fastcall DRLGROOM_HasWaypoint(D2DrlgRoomStrc* pDrlgRoom);                                             // 0x0066BB60
const char* __fastcall DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom);           // 0x0066BBA0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInClientSight(D2DrlgStrc* pDrlg);                         // 0x0061B840
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInSightButWithoutClient(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B870
int __fastcall DRLGACTIVATE_TestRoomCanUnTile(D2DrlgRoomStrc* pDrlgRoom);                                   // 0x0061BA30
void __fastcall sub_6FD745C0(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2);                       // 0x00643020
void __fastcall DRLG_UpdateAndFreeInactiveRooms(D2DrlgStrc* pDrlg);                                         // 0x00643200
int __fastcall DRLGROOM_CheckLOSDraw(D2DrlgRoomStrc* pDrlgRoom);                                            // 0x0066BA70
int __fastcall DRLG_IsTownLevel(int nLevelId);                                                              // 0x006426A0
int __fastcall DRLG_GetActNoFromLevelId(int nLevelId);                                                      // 0x00642740
int __fastcall sub_6FD779F0(D2DrlgRoomStrc* pDrlgRoom);                                                     // 0x0066BA90
int __fastcall DRLG_GetNumberOfPopulatedRoomsInLevel(D2DrlgStrc* pDrlg, int nLevelId);                      // 0x00642BE0
int* __fastcall DRLG_GetRoomCenterX_RoomWarpXFromRoom(D2DrlgRoomStrc* pDrlgRoom);                           // 0x00642380
void __fastcall DRLGWARP_UpdateWarpRoomSelect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId);                     // 0x0066AB90
void __fastcall DRLGWARP_UpdateWarpRoomDeselect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId);                   // 0x0066ABE0
void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom);           // 0x006671E0
D2RoomCoordListStrc* __fastcall sub_6FD77110(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);                    // 0x0066CEB0
D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordList(D2DrlgRoomStrc* pDrlgRoom);                      // 0x0066CF30
void __fastcall DRLGACTIVATE_ToggleHasPortalFlag(D2DrlgRoomStrc* pDrlgRoom, int bReset);                    // 0x0061BAC0
void __fastcall DRLGANIM_AnimateTiles(D2DrlgRoomStrc* pDrlgRoom);                                           // 0x0066D410
void __fastcall DRLGANIM_UpdateFrameInAdjacentRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x0066D750

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ROOMFLAG_2 0x00000002
#define ROOMFLAG_4 0x00000004

// 0x00619550
void* __fastcall DUNGEON_GetMemPoolFromAct(D2DrlgActStrc* pAct)
{
    return pAct->pMemPool;
}

// 0x00619560
void __stdcall DUNGEON_ToggleRoomTilesEnableFlag(D2ActiveRoomStrc* pRoom, int bEnabled)
{
    D2_ASSERT(pRoom, 98);

    DRLGWARP_ToggleRoomTilesEnableFlag(pRoom->pDrlgRoom, bEnabled);
}

// 0x00619620
D2LvlWarpTxt* __stdcall DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    D2_ASSERT(pRoom, 138);

    return DRLGWARP_GetLvlWarpTxtRecordFromUnit(pRoom->pDrlgRoom, pUnit);
}

// 0x00619660
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount)
{
    if (pRoom && pRoom->pRoomTiles)
    {
        *pFloorCount = pRoom->pRoomTiles->nFloors;
        return pRoom->pRoomTiles->pFloorTiles;
    }

    *pFloorCount = 0;
    return 0;
}

// 0x006196A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount)
{
    D2_ASSERT(pRoom, 177);

    *pWallCount = pRoom->pRoomTiles->nWalls;
    return pRoom->pRoomTiles->pWallTiles;
}

// 0x006196E0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount)
{
    D2_ASSERT(pRoom, 190);

    *pRoofCount = pRoom->pRoomTiles->nRoofs;
    return pRoom->pRoomTiles->pRoofTiles;
}

// 0x00619730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords)
{
    D2_ASSERT(pCoords, 209);

    if (!pRoom)
    {
        memset(pCoords, 0x00, sizeof(D2DrlgCoordsStrc));
        return;
    }

    memcpy(pCoords, &pRoom->tCoords, sizeof(D2DrlgCoordsStrc));
}

// 0x00619790
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms)
{
    D2_ASSERT(pRoom, 236);

    *pNumRooms = pRoom->nNumRooms;
    *pppRoomList = pRoom->ppRoomList;
}

// 0x00619D70
void __stdcall DUNGEON_GetRGB_IntensityFromRoom(D2ActiveRoomStrc* pRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    DRLGROOM_GetRGB_IntensityFromRoomEx(pRoom->pDrlgRoom, pIntensity, pRed, pGreen, pBlue);
}

// 0x00619E50
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY)
{
    D2_ASSERT(pAct, 545);

    return sub_6FD788D0(pAct->pDrlg, nLevelId, nTileIndex, pX, pY);
}

// 0x00619F00
int __stdcall DUNGEON_GetAlliedCountFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return pRoom->nAllies;
}

// 0x00619F60
D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 646);

    return &pRoom->pUnitFirst;
}

// 0x00619F90
D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate)
{
    D2_ASSERT(pRoom, 685);

    if (bUpdate)
    {
        pRoom->pAct->bHasPendingUnitListUpdates = 1;
    }

    return &pRoom->pUnitUpdate;
}

// 0x00619FD0
D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 699);

    return DRLGROOM_GetPresetUnits(pRoom->pDrlgRoom);
}

// 0x0061A010
void* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 709);

    return pRoom->pCollisionGrid;
}

// 0x0061A040
void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, void* pCollisionGrid)
{
    D2_ASSERT(pRoom, 718);

    pRoom->pCollisionGrid = pCollisionGrid;
}

// 0x0061A070
void __stdcall DUNGEON_SetClientIsInSight(D2DrlgActStrc* pAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 727);

    DRLGACTIVATE_SetClientIsInSight(pAct->pDrlg, nLevelId, nX, nY, pRoom ? pRoom->pDrlgRoom : 0);
}

// 0x0061A0C0
void __stdcall DUNGEON_UnsetClientIsInSight(D2DrlgActStrc* pAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 745);

    DRLGACTIVATE_UnsetClientIsInSight(pAct->pDrlg, nLevelId, nX, nY, pRoom ? pRoom->pDrlgRoom : 0);
}

// 0x0061A110
void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = 0;
    D2DrlgRoomStrc* pDrlgRoom2 = 0;

    if (pRoom1)
    {
        pDrlgRoom1 = pRoom1->pDrlgRoom;
    }

    if (pRoom2)
    {
        pDrlgRoom2 = pRoom2->pDrlgRoom;
    }

    DRLGACTIVATE_ChangeClientRoom(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061A140
D2ActiveRoomStrc* __stdcall DUNGEON_StreamRoomAtCoords(D2DrlgActStrc* pAct, int nX, int nY)
{
    D2_ASSERT(pAct, 787);

    return DRLGACTIVATE_StreamRoomAtCoords(pAct->pDrlg, nX, nY);
}

// 0x0061A180
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 798);

    return pAct->pRoom;
}

// 0x0061A1B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetLevelId(pRoom->pDrlgRoom);
}

// 0x0061A1F0
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetLevelIdFromPopulatedRoom(pRoom->pDrlgRoom);
}

// 0x0061A210
int __stdcall DUNGEON_HasWaypoint(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 867);

    return DRLGROOM_HasWaypoint(pRoom->pDrlgRoom);
}

// 0x0061A250
const char* __stdcall DUNGEON_GetPickedLevelPrestFilePathFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(pRoom->pDrlgRoom);
}

// 0x0061A330
D2DrlgDeleteStrc* __stdcall DUNGEON_GetDrlgDeleteFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 934);

    return pRoom->pDrlgDelete;
}

// 0x0061A360
D2ActiveRoomStrc* __stdcall DUNGEON_GetARoomInClientSight(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 965);

    return DRLGACTIVATE_GetARoomInClientSight(pAct->pDrlg);
}

// 0x0061A3A0
D2ActiveRoomStrc* __stdcall DUNGEON_GetARoomInSightButWithoutClient(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 974);

    D2_ASSERT(pRoom, 977);

    return DRLGACTIVATE_GetARoomInSightButWithoutClient(pAct->pDrlg, pRoom->pDrlgRoom);
}

// 0x0061A3F0
int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 989);
    D2_ASSERT(!pAct->bClient, 990);
    D2_ASSERT(pRoom, 991);

    return DRLGACTIVATE_TestRoomCanUnTile(pRoom->pDrlgRoom);
}

// 0x0061A4D0
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1071);

    return pRoom->dwFlags & ROOMFLAG_2;
}

// 0x0061A510
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet)
{
    D2_ASSERT(pRoom, 1080);

    if (bSet)
    {
        pRoom->dwFlags |= ROOMFLAG_2;
    }
    else
    {
        pRoom->dwFlags &= ~ROOMFLAG_2;
    }
}

// 0x0061A9F0
void __stdcall D2Common_10077(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = pRoom1 ? pRoom1->pDrlgRoom : 0;
    D2DrlgRoomStrc* pDrlgRoom2 = pRoom2 ? pRoom2->pDrlgRoom : 0;
    sub_6FD745C0(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061AA20
void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct)
{
    DRLG_UpdateAndFreeInactiveRooms(pAct->pDrlg);
}

// 0x0061AA40
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_CheckLOSDraw(pRoom->pDrlgRoom);
}

// 0x0061AA60
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1351);

    return pAct->pEnvironment;
}

// 0x0061AA90
D2DrlgStrc* __stdcall DUNGEON_GetDrlgFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1360);

    return pAct->pDrlg;
}

// 0x0061AAE0
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom)
{
    return pRoom->pDrlgRoom;
}

// 0x0061AAF0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId)
{
    return DRLG_IsTownLevel(nLevelId);
}

// 0x0061AB00
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLG_IsTownLevel(DRLGROOM_GetLevelId(pRoom->pDrlgRoom));
}

// 0x0061AB30
int __stdcall sub_0061AB30(D2ActiveRoomStrc* pRoom)
{
    return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
}

// 0x0061AB60
int __stdcall D2Common_10084(D2ActiveRoomStrc* pRoom)
{
    return pRoom->dwFlags & ROOMFLAG_4;
}

// 0x0061ABB0
int __stdcall D2Common_10087(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1445);

    return sub_6FD779F0(pRoom->pDrlgRoom);
}

// 0x0061ABF0
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId)
{
    return DRLG_GetNumberOfPopulatedRoomsInLevel(pAct->pDrlg, nLevelId);
}

// 0x0061AC10
int* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1465);

    return DRLG_GetRoomCenterX_RoomWarpXFromRoom(pRoom->pDrlgRoom);
}

// 0x0061AC50
void __stdcall DUNGEON_UpdateWarpRoomSelect(D2ActiveRoomStrc* pRoom, int nLevelId)
{
    D2_ASSERT(pRoom, 1476);

    DRLGWARP_UpdateWarpRoomSelect(pRoom->pDrlgRoom, nLevelId);
}

// 0x0061AC90
void __stdcall DUNGEON_UpdateWarpRoomDeselect(D2ActiveRoomStrc* pRoom, int nLevelId)
{
    D2_ASSERT(pRoom, 1487);

    DRLGWARP_UpdateWarpRoomDeselect(pRoom->pDrlgRoom, nLevelId);
}

// 0x0061ACD0
void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* pRoom, int nX, int nY, int bOtherRoom)
{
    D2_ASSERT(pRoom, 1498);

    DRLGPRESET_UpdatePops(pRoom->pDrlgRoom, nX, nY, bOtherRoom);
}

// 0x0061AD30
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return sub_6FD77110(pRoom->pDrlgRoom, nX, nY);
}

// 0x0061AD50
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom)
{
    return DRLGLOGIC_GetRoomCoordList(pRoom->pDrlgRoom);
}

// 0x0061AE80
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1588);

    return pAct->nTownId;
}

// 0x0061AED0
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset)
{
    if (pRoom)
    {
        DRLGACTIVATE_ToggleHasPortalFlag(pRoom->pDrlgRoom, bReset);
    }
}

// 0x0061AEF0
void __stdcall DUNGEON_AnimateTiles(D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        DRLGANIM_AnimateTiles(pRoom->pDrlgRoom);
    }
}

// 0x0061AF10
void __stdcall DUNGEON_InitRoomTileAnimation(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = 0;
    D2DrlgRoomStrc* pDrlgRoom2 = 0;

    if (pRoom1)
    {
        for (D2ActiveRoomStrc* pRoom = pAct->pRoom; pRoom; pRoom = pRoom->pRoomNext)
        {
            if (pRoom == pRoom1)
            {
                pDrlgRoom1 = pRoom1->pDrlgRoom;
                break;
            }
        }
    }

    if (pRoom2)
    {
        pDrlgRoom2 = pRoom2->pDrlgRoom;
    }

    DRLGANIM_UpdateFrameInAdjacentRooms(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061AF60
void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction)
{
    D2_ASSERT(pAct, 1663);

    pAct->pfnActCallBack = pActCallbackFunction;
}
