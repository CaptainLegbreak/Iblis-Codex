struct D2SeedStrc
{
    union
    {
        struct
        {
            unsigned int nLowSeed;
            unsigned int nHighSeed;
        };
        unsigned __int64 lSeed;
    };
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2ObjectDataStrc
{
    char pad00[4];
    unsigned char nType;
};

struct D2UnitStrc
{
    char pad00[0x14];
    D2ObjectDataStrc* pObjectData;
    char pad18[0xAC];
    unsigned int dwFlags;
};

struct D2GameStrc;
struct D2ActiveRoomStrc;

enum
{
    LEVEL_TOWERCELLARLEV5 = 25,
    LEVEL_MAGGOTLAIRLEV1 = 62,
    LEVEL_MAGGOTLAIRLEV3 = 64,
    OBJECT_COUNTESSCHEST = 0x173,
};

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall sub_0054F180_SelectAndSpawnObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused); // 0x0054F180
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest);                // 0x005540A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// build: context SEED_RollRandomNumber
inline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x0054F370
D2UnitStrc* __fastcall sub_0054F370_SpawnChestObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    D2UnitStrc* pObject = sub_0054F180_SelectAndSpawnObject(pGame, pRoom, nLevelId == LEVEL_TOWERCELLARLEV5 ? OBJECT_COUNTESSCHEST : nClassId, nX, nY, nUnused);
    if (pObject)
    {
        if (nLevelId >= LEVEL_MAGGOTLAIRLEV1 && nLevelId <= LEVEL_MAGGOTLAIRLEV3
            && (int)((unsigned int)SEED_RollRandomNumber(&OBJRGN_GetObjectControlFromGame(pGame, pRoom)->pSeed) % 100) > 50)
        {
            pObject->dwFlags |= 0x80;
            UNITS_ChangeAnimMode(pObject, 0);
            return pObject;
        }

        D2GAME_SetSparkChest_6FCBD7C0(pObject, 1);
        if (nLevelId == LEVEL_TOWERCELLARLEV5)
        {
            pObject->pObjectData->nType = 3;
        }

        pObject->dwFlags |= 0x80;
        UNITS_ChangeAnimMode(pObject, 0);
    }

    return pObject;
}
