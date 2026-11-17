struct D2GameStrc;
struct D2UnitStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
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

typedef char (__fastcall* SPAWNCHECKFN)(D2GameStrc* pGame, int nArg, int nX, int nY);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(SPAWNCHECKFN lpfn);                             // 0x006CC34C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// build: context SEED_RollRandomNumber
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// build: context SEED_RollLimitedRandomNumberInl
static __forceinline unsigned int SEED_RollLimitedRandomNumberInl(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0045C3E0
int __fastcall sub_0045C3E0_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInl(pSeed, nMax);
}

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800

// 0x00550540
D2UnitStrc* __stdcall sub_00550540_SpawnObjectInRoom(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom, int nArg, SPAWNCHECKFN pfnCheck)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (tCoords.nSubtileWidth < 2 || tCoords.nSubtileHeight < 2 || tCoords.nSubtileWidth <= nSizeX || tCoords.nSubtileHeight <= nSizeY)
    {
        return 0;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    int nX;
    int nY;
    int i;
    for (i = 0; i < 5; ++i)
    {
        nX = tCoords.nSubtileX + sub_0045C3E0_RollLimitedRandomNumber(pSeed, tCoords.nSubtileWidth - nSizeX - 1);
        nY = tCoords.nSubtileY + sub_0045C3E0_RollLimitedRandomNumber(pSeed, tCoords.nSubtileHeight - nSizeY - 1);
        if (nX && nY
            && (unsigned short)nX >= tCoords.nSubtileX + 1 && (unsigned short)nY >= tCoords.nSubtileY + 1
            && (unsigned short)nX < tCoords.nSubtileX + tCoords.nSubtileWidth - 1 && (unsigned short)nY < tCoords.nSubtileY + tCoords.nSubtileHeight - 1)
        {
            D2_ASSERT(!IsBadCodePtr(pfnCheck), 0x588);

            if (!COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + 6, nSizeY + 6, 0x3F11) && pfnCheck(pGame, nArg, nX, nY))
            {
                break;
            }
        }
    }

    if (i >= 5)
    {
        return 0;
    }

    D2_ASSERT(pRoom, 0x593);
    return SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}
