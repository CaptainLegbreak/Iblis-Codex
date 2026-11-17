struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;
struct D2RoomCoordListStrc;
struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int field_20;
    short nFlags;
};
D2UnitStrc* __fastcall sub_005B2A00_SpawnNormalMonster(D2UnkMonCreateStrc*); // 0x005B2A00

// 0x005B3040
D2UnitStrc* __fastcall sub_005B3040_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.field_20 = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = pCoordList;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return sub_005B2A00_SpawnNormalMonster(&monCreate);
}
