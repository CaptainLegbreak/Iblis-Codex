struct D2UnitStrc;
struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgCoordsStrc;
struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    int tCoords[8];
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

typedef int (__stdcall* D2FarProcFn)();
typedef char (__fastcall* D2ObjectSpawnCallback)(D2GameStrc* pGame, int nArg, int nX, int nY);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

static __forceinline int sub_00550A30_IsInsideRoom(D2DrlgCoordsStrc* pCoords, unsigned short nX, unsigned short nY)
{
    return nX >= pCoords->nSubtileX + 1 && nY >= pCoords->nSubtileY + 1
        && nX < pCoords->nSubtileX + pCoords->nSubtileWidth - 1 && nY < pCoords->nSubtileY + pCoords->nSubtileHeight - 1;
}

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

__declspec(noinline) void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);

// 0x00619730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords)
{
    D2_ASSERT(pCoords, 209);

    if (!pRoom)
    {
        memset(pCoords, 0x00, sizeof(D2DrlgCoordsStrc));
        return;
    }

    memcpy(pCoords, &pRoom->tCoords, sizeof(D2DrlgCoordsStrc));
}

// 0x00550A30
D2UnitStrc* __stdcall sub_00550A30_SpawnObjectInRoom(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom, int nMode, int nArg, D2ObjectSpawnCallback pfnCallback)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    int nWidth = tCoords.nSubtileWidth;
    int nHeight = tCoords.nSubtileHeight;
    if (nWidth < nSizeX + 2 || nHeight < nSizeY + 2)
    {
        return 0;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    int nX;
    int nY;
    int i;
    for (i = 0; i < 5; ++i)
    {
        nWidth = tCoords.nSubtileWidth;
        nHeight = tCoords.nSubtileHeight;
        switch (nMode)
        {
        case 1:
            nX = tCoords.nSubtileX + ITEMS_RollLimitedRandomNumber(pSeed, nWidth / 2) + nWidth / 4;
            nY = tCoords.nSubtileY + OBJECTS_RollRandomNumber(pSeed, 1, 2);
            break;

        case 2:
            nX = tCoords.nSubtileX + OBJECTS_RollRandomNumber(pSeed, 1, 2);
            nY = tCoords.nSubtileY + ITEMS_RollLimitedRandomNumber(pSeed, nHeight / 2) + nHeight / 4;
            break;

        default:
            nX = tCoords.nSubtileX + ITEMS_RollLimitedRandomNumber(pSeed, nWidth - nSizeX - 1);
            nY = tCoords.nSubtileY + ITEMS_RollLimitedRandomNumber(pSeed, nHeight - nSizeY - 1);
            break;
        }

        if (nX && nY && sub_00550A30_IsInsideRoom(&tCoords, nX, nY))
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)pfnCallback), 0x634);

            if (!COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + 6, nSizeY + 6, 0x3F11))
            {
                if (pfnCallback(pGame, nArg, nX, nY))
                {
                    break;
                }
            }
        }
    }

    if (i >= 5)
    {
        return 0;
    }

    D2_ASSERT(pRoom, 0x64D);
    return SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}
