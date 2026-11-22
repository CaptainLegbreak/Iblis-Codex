#include "D2Game.h"

#include "D2GameServer.h"
D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster(D2UnkMonCreateStrc* pMonCreate); // 0x005B2A00

// 0x005B2F20
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags)
{
    D2UnkMonCreateStrc monCreate;

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

    return D2GAME_SpawnNormalMonster(&monCreate);
}
