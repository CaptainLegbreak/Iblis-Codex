struct D2GameStrc;
struct D2ClientStrc;
struct D2ObjectControlStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xC0];
    unsigned int dwFlagEx;
    char unk0xCC[0x1C];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

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

#define UNIT_OBJECT 2
#define UNITFLAGEX_TELEPORTED 0x10000

extern "C" const char gszObjModeSourceFile_006E1970[];                                                      // 0x006E1970
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);          // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                      // 0x0061A1B0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                           // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

static __declspec(noinline) void sub_00581B50_TeleportToUnit(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ActiveRoomStrc* pRoom);

// 0x00581B50
static void sub_00581B50_TeleportToUnit(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ActiveRoomStrc* pRoom)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    if (COLLISION_GetFreeCoordinates(pRoom, &tCoord, 3, 0x1C09, 0) && sub_6FCBDFE0(SUNIT_GetGameFromUnit(pPlayer), pPlayer, pRoom, tCoord.nX, tCoord.nY, 0, 0))
    {
        D2DrlgCoordsStrc tRoomCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(SUNIT_GetClientFromPlayer(pPlayer, gszObjModeSourceFile_006E1970, 865), DUNGEON_GetLevelIdFromRoom(pRoom), tRoomCoords.nTileXPos, tRoomCoords.nTileYPos);
        UNITROOM_RefreshUnit(pPlayer);
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= UNITFLAGEX_TELEPORTED;
        }
    }
}

// 0x00581BF0
int __fastcall OBJECTS_OperateFunction27_TeleportPad(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    if (pRoom)
    {
        const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwClassId;

        D2UnitStrc* pUnit = pRoom->pUnitFirst;
        while (pUnit && ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_OBJECT || pUnit == pOp->pObject || (!pUnit ? -1 : pUnit->dwClassId) != nUnitId))
        {
            pUnit = pUnit->pRoomNext;
        }

        if (pUnit)
        {
            sub_00581B50_TeleportToUnit(pUnit, pOp->pPlayer, pRoom);
            return 0;
        }

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] != pRoom)
            {
                pUnit = ppRoomList[i]->pUnitFirst;
                while (pUnit && ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_OBJECT || pUnit == pOp->pObject || (!pUnit ? -1 : pUnit->dwClassId) != nUnitId))
                {
                    pUnit = pUnit->pRoomNext;
                }

                if (pUnit)
                {
                    sub_00581B50_TeleportToUnit(pUnit, pOp->pPlayer, ppRoomList[i]);
                    return 0;
                }
            }
        }
    }

    return 0;
}
