struct D2GameStrc;
struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc tSeed;
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

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2ObjectsTxt
{
    char unk0x000[0xC4];
    unsigned char nHasCollision[8];
    char unk0x0CC[0x04];
    int dwSizeX;
    int dwSizeY;
};

typedef bool (__fastcall* OBJRGN_SpawnCheckFn)(D2GameStrc* pGame, int nLevelId, int nX, int nY);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId);                               // 0x00547300
bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY);                       // 0x005473A0
void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY);                 // 0x00547400
D2UnitStrc* __stdcall sub_00550540_SpawnObjectInBox(D2GameStrc* pGame, int nObjectId, int nWidth, int nHeight, D2ActiveRoomStrc* pRoom, int nLevelId, OBJRGN_SpawnCheckFn pfnCheck); // 0x00550540
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A1F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005516C0
D2UnitStrc* __fastcall sub_005516C0_SpawnWell(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nWellType, int nObjectId, unsigned short nChance)
{
    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    if (OBJRGN_CanNotSpawnMoreWells(pGame, nLevelId))
    {
        return 0;
    }

    D2_ASSERT(nWellType <= 128, 0x8D0);

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2SeedStrc* pSeed = pRoom ? &pRoom->tSeed : 0;
    if (SEED_RollRandomNumber(pSeed) % 100 > nChance)
    {
        return 0;
    }

    D2UnitStrc* pUnit = sub_00550540_SpawnObjectInBox(pGame, nObjectId, 2 * nSizeX + 1, 2 * nSizeY + 1, pRoom, nLevelId, OBJRGN_CanSpawnWell);
    if (pUnit)
    {
        const int nMode = pUnit ? pUnit->dwAnimMode : 0;
        if (pObjectsTxtRecord->nHasCollision[nMode])
        {
            pUnit->dwFlags |= 2;
        }
        else
        {
            pUnit->dwFlags &= ~2;
        }

        OBJRGN_SetWellCoordinates(pGame, nLevelId, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit));
    }

    return pUnit;
}
