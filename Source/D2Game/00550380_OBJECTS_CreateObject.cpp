struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;

#define UNIT_OBJECT 2
#define ROOM_MIN_SUBTILES 2
#define CREATE_TRIES 5
#define CREATE_SIZE_GROW 6
#define COLLIDE_MASK_PLACEMENT 0x3F11
#define LINE_CREATE_ROOM 1358

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00550380
D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    if (drlgCoords.nSubtileWidth < ROOM_MIN_SUBTILES || drlgCoords.nSubtileHeight < ROOM_MIN_SUBTILES)
    {
        return 0;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    int nX;
    int nY;
    int i;
    for (i = 0; i < CREATE_TRIES; ++i)
    {
        nX = OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileWidth - nSizeX - 1) + drlgCoords.nSubtileX;
        nY = OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileHeight - nSizeY - 1) + drlgCoords.nSubtileY;
        if (nX && nY && (unsigned short)nX >= drlgCoords.nSubtileX + 1 && (unsigned short)nY >= drlgCoords.nSubtileY + 1
            && (unsigned short)nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth - 1 && (unsigned short)nY < drlgCoords.nSubtileY + drlgCoords.nSubtileHeight - 1
            && !COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + CREATE_SIZE_GROW, nSizeY + CREATE_SIZE_GROW, COLLIDE_MASK_PLACEMENT))
        {
            break;
        }
    }

    if (i >= CREATE_TRIES)
    {
        return 0;
    }

    D2_ASSERT(pRoom, LINE_CREATE_ROOM);
    return SUNIT_AllocUnitData(UNIT_OBJECT, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}
