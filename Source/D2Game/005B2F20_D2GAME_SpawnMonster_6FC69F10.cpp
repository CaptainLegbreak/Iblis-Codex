struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2RoomCoordListStrc;
struct D2UnitStrc;

struct D2MonsterSpawnParamsStrc
{
    D2GameStrc* pGame;
    D2ActiveRoomStrc* pRoom;
    D2RoomCoordListStrc* pRoomCoordList;
    int nMonsterId;
    int nAnimMode;
    int nUnitGUID;
    int nX;
    int nY;
    int nMaxSearchRings;
    short nFlags;
};

D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster_6FC68E30(D2MonsterSpawnParamsStrc* pMonCreate); // 0x005B2A00

// 0x005B2F20
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags)
{
    D2MonsterSpawnParamsStrc monCreate;

    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.nMaxSearchRings = nMaxSearchRings;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;

    return D2GAME_SpawnNormalMonster_6FC68E30(&monCreate);
}
