struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0xC4 - 0x30];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc* pUnit, int* pMonsterId, int* pX, int* pY, int* pSpawnMode, int a6, int (__fastcall* pfnGetClassId)(D2UnitStrc*)); // 0x0063EFA0

static __forceinline int CLIENTS_GetUnitXForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int CLIENTS_GetUnitYForceInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

#define SKILLS_ROLL_SEED(pSeed, lSeed) \
    (lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
     (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32), \
     (pSeed)->nLowSeed = (unsigned int)lSeed, \
     (unsigned int)lSeed)

// 0x005D2C20
int __fastcall SKILLS_SrvDo140_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit)
    {
        return 0;
    }

    unsigned __int64 lSeed;
    const int nMinionCount = pGame->nDifficulty + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 3 + 2;

    int nMinionSpawnMode;
    int nMinionId;
    int nMinionX;
    int nMinionY;
    MONSTERS_GetMinionSpawnInfo(pUnit, &nMinionId, &nMinionX, &nMinionY, &nMinionSpawnMode, pGame->nDifficulty, 0);

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    const int nX = pTarget ? CLIENTS_GetUnitXForceInline(pTarget) : CLIENTS_GetUnitXForceInline(pUnit);
    const int nY = pTarget ? CLIENTS_GetUnitYForceInline(pTarget) : CLIENTS_GetUnitYForceInline(pUnit);

    for (int i = 0; i < nMinionCount; ++i)
    {
        nMinionX = nX + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 18 - 9;
        nMinionY = nY + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 18 - 9;

        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nMinionX, nMinionY);
        if (pRoom)
        {
            D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nMinionX, nMinionY);
            D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nMinionX, nMinionY, nMinionId, nMinionSpawnMode, -1, 0);
            if (pMinion)
            {
                pMinion->dwFlags |= 0x4020000;
                AITACTICS_Idle(pGame, pMinion, 15);
                UNITS_StoreOwner(pMinion, pUnit);
            }
        }
    }

    return 1;
}
