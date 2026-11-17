struct D2ActiveRoomStrc;
struct D2GameStrc;

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

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
};

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730

// 0x005459A0
D2UnitStrc* __fastcall sub_005459A0_SpawnMonsterNear(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int bQuestFlags, int nMonsterId)
{
    D2ActiveRoomStrc* pFreeRoom = pRoom;
    D2DrlgCoordsStrc tRoomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);

    D2CoordStrc tCoord;
    tCoord.nX = nX;
    tCoord.nY = nY;
    int nCounter = 0;
    while (tCoord.nX < tRoomCoords.nSubtileX || tCoord.nY < tRoomCoords.nSubtileY || tCoord.nX >= tRoomCoords.nSubtileX + tRoomCoords.nSubtileWidth - 1 || tCoord.nY >= tRoomCoords.nSubtileY + tRoomCoords.nSubtileHeight - 1)
    {
        ++nCounter;
        ++tCoord.nX;
        ++tCoord.nY;
        if (nCounter > 20)
        {
            tCoord.nX = nY;
            break;
        }
    }

    QUESTS_GetFreePosition(pRoom, &tCoord, 2, 0x100u, &pFreeRoom, 6, 100);

    D2ActiveRoomStrc* pSpawnRoom = pFreeRoom;
    int nSpawnX;
    int nSpawnY;
    if (!pFreeRoom)
    {
        pSpawnRoom = pRoom;
        nSpawnX = nX;
        nSpawnY = nY;
    }
    else
    {
        nSpawnY = tCoord.nY;
        nSpawnX = tCoord.nX;
    }

    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nSpawnX, nSpawnY, nMonsterId, 1, -1, 0);
    if (!pMonster)
    {
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nSpawnX, nSpawnY, nMonsterId, 1, 5, 0);
    }

    if (!pMonster)
    {
        int nTries = 0;
        int nTryX = nSpawnX;
        int nTryY = nSpawnY;
        do
        {
            ++nTryX;
            ++nTryY;
            tCoord.nX = nTryX;
            tCoord.nY = nTryY;
            pFreeRoom = COLLISION_GetRoomBySubTileCoordinates(pSpawnRoom, nTryX, nTryY);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                tCoord.nX = nX;
                tCoord.nY = nY;
            }

            QUESTS_GetFreePosition(pFreeRoom, &tCoord, 2, 0x100u, &pFreeRoom, 7, 100);
            pSpawnRoom = pFreeRoom;
            if (!pFreeRoom)
            {
                pSpawnRoom = pRoom;
                nTryX = nX;
                nTryY = nY;
            }
            else
            {
                nTryY = tCoord.nY;
                nTryX = tCoord.nX;
            }

            ++nTries;
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nTryX, nTryY, nMonsterId, 1, 10, 0);
        }
        while (!pMonster && nTries < 20);

        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, 15, 0);
        }
    }

    if (pMonster && bQuestFlags)
    {
        pMonster->dwFlags |= 0x3000000;
    }

    return pMonster;
}
