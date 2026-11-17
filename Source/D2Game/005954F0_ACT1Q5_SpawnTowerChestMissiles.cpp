struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12];
    unsigned short nUnitCount1;
    unsigned char pad0x32[2];
    int nUnitGUIDs2[12];
    unsigned short nUnitCount2;
    unsigned char pad0x66[2];
    int nObjectGUIDs[8];
    unsigned short nCountessChestCount;
    unsigned char pad0x8A[2];
    D2QuestGUIDStrc tPlayerGUIDs;
    D2CoordStrc pCoord;
    unsigned char bCountessKilled;
    unsigned char bDeathMissilesCreated;
    unsigned char bTriggerSeqFilter;
    unsigned char bTowerTomeActivated;
    unsigned char unk0x11C;
    unsigned char pad0x11D[3];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
};

D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY);  // 0x00463740
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                             // 0x0061AED0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                    // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005954F0
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx)
{
    if (!pQuestDataEx->bCountessKilled || pQuestDataEx->bDeathMissilesCreated)
    {
        return;
    }

    D2UnitStrc* pTrapFirebolt = 0;

    for (int i = 0; i < pQuestDataEx->nCountessChestCount; ++i)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nObjectGUIDs[i]);
        if (pObject)
        {
            D2CoordStrc pCoord;
            pCoord.nX = pQuestDataEx->pCoord.nX;
            pCoord.nY = pQuestDataEx->pCoord.nY;

            if (!pTrapFirebolt)
            {
                D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pObject), pCoord.nX, pCoord.nY);

                if (pRoom)
                {
                    pTrapFirebolt = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, 0x146, 0xC, -1, 8);
                }

                if (!pTrapFirebolt)
                {
                    UNITS_GetCoords(pObject, &pCoord);

                    pCoord.nX += 5;
                    pCoord.nY += 5;

                    pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pObject), pCoord.nX, pCoord.nY);
                    pTrapFirebolt = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, 0x146, 0xC, -1, 8);
                }
            }

            if (pTrapFirebolt)
            {
                pQuestDataEx->bDeathMissilesCreated = 1;

                D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pQuestData->pGame, pTrapFirebolt, 0, 1, 0x14C, CLIENTS_GetUnitXInline(pObject), CLIENTS_GetUnitYInline(pObject));
                if (pMissile)
                {
                    MISSILE_SetTargetX(pMissile, pQuestDataEx->nObjectGUIDs[i]);
                    MISSILE_SetTargetY(pMissile, 0);
                    D2ActiveRoomStrc* pMissileRoom = UNITS_GetRoom(pMissile);
                    DUNGEON_ToggleHasPortalFlag(pMissileRoom, 0);
                }
            }
        }
    }
}
