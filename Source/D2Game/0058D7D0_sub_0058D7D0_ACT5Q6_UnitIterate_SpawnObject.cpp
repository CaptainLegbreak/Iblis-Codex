struct D2GameStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

// 0x0058D7D0
int __fastcall sub_0058D7D0_ACT5Q6_UnitIterate_SpawnObject(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == 132)
    {
        D2CoordStrc coord;
        UNITS_GetCoords(pUnit, &coord);
        coord.nX += 5;
        D2ActiveRoomStrc* pFreeRoom = UNITS_GetRoom(pUnit);
        QUESTS_GetFreePosition(pRoom, &coord, 5, 0x400, &pFreeRoom, 18, 100);
        if (pFreeRoom)
        {
            SUNIT_AllocUnitData(2, 0x235, coord.nX, coord.nY, pGame, pFreeRoom, 1, 1, 0);
        }

        return 1;
    }

    return 0;
}
