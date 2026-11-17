struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjectDataStrc
{
    char unk0x00[0x18];
    D2CoordStrc DestRoomCooords;
    D2CoordStrc DestPortalCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
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
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00553590
void __fastcall sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond)
{
    D2_ASSERT(pFirst, 1875);
    D2_ASSERT(pSecond, 1877);

    pFirst->pObjectData->DestPortalCoords.nX = CLIENTS_GetUnitX(pSecond);
    pFirst->pObjectData->DestPortalCoords.nY = CLIENTS_GetUnitY(pSecond);

    pSecond->pObjectData->DestPortalCoords.nX = CLIENTS_GetUnitX(pFirst);
    pSecond->pObjectData->DestPortalCoords.nY = CLIENTS_GetUnitY(pFirst);

    D2ActiveRoomStrc* pSecondRoom = UNITS_GetRoom(pSecond);
    if (pSecondRoom)
    {
        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pSecondRoom, &drlgCoords);
        pFirst->pObjectData->DestRoomCooords.nX = drlgCoords.nTileXPos;
        pFirst->pObjectData->DestRoomCooords.nY = drlgCoords.nTileYPos;
    }

    D2ActiveRoomStrc* pFirstRoom = UNITS_GetRoom(pFirst);
    if (pFirstRoom)
    {
        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pFirstRoom, &drlgCoords);
        pSecond->pObjectData->DestRoomCooords.nX = drlgCoords.nTileXPos;
        pSecond->pObjectData->DestRoomCooords.nY = drlgCoords.nTileYPos;
    }
}
