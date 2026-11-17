struct D2GameStrc { char unk00[0xA8]; int dwGameFrame; };
struct D2UnitStrc { int dwUnitType; char unk04[0xC]; int dwAnimMode; char unk14[0xD4]; D2UnitStrc* pRoomNext; };
struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2CoordStrc { int nX; int nY; };
struct D2ObjOperateFnStrc { D2GameStrc* pGame; D2UnitStrc* pObject; D2UnitStrc* pPlayer; int unk0C; int nObjectIdx; };
struct D2ObjectsTxt { char unk00[0xDC]; unsigned int dwFrameCnt3; };
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc*, D2CoordStrc*); // 0x00620870
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc*); // 0x006205A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*, D2ActiveRoomStrc***, unsigned int*); // 0x00619790
void __fastcall SUNIT_WarpPlayer(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x005550B0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
// 0x00581F60
int __fastcall sub_00581F60_OperateWarpObject(D2ObjOperateFnStrc* pOp)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pObject);
    D2CoordStrc coords;
    UNITS_GetCoords(pOp->pObject, &coords);
    UNITS_GetUnitSizeX(pOp->pObject);
    UNITS_GetUnitSizeY(pOp->pObject);
    switch (!pOp->pObject ? 0 : pOp->pObject->dwAnimMode)
    {
    case 0:
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        {
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxt->dwFrameCnt3 >> 8) + 1, 0, 0);
        }
        break;
    case 2:
        {
            D2UnitStrc* pTile = pRoom->pUnitFirst;
            while (pTile)
            {
                if ((!pTile ? 6 : pTile->dwUnitType) == 5) goto found;
                pTile = pTile->pRoomNext;
            }
            D2ActiveRoomStrc** ppRooms;
            unsigned int nRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            unsigned int i = 0;
            if (i >= nRooms) goto done;
            do
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = ppRooms[i]->pUnitFirst;
                    while (pTile)
                    {
                        if ((!pTile ? 6 : pTile->dwUnitType) == 5) goto found;
                        pTile = pTile->pRoomNext;
                    }
                }
            } while (++i < nRooms);
            return 1;
        found:
            SUNIT_WarpPlayer(pOp->pGame, pOp->pPlayer, pTile);
            return 1;
        }
        break;
    }
done:
    return 1;
}
