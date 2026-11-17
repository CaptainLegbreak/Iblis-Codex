struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x2C - 0x04];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0xE8 - 0x30];
    D2UnitStrc* pRoomNext;
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

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    char unk0x5C[0x74 - 0x5C];
    D2UnitStrc* pUnitFirst;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall sub_00619EE0(D2ActiveRoomStrc* pRoom);                                                       // 0x00619EE0
D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom);                               // 0x00619F60
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

#define TRUE 1
#define FALSE 0
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_ALIGNMENT_GOOD 2

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x0064BF60
static int __stdcall sub_0064BF60_CanAddUnitToRoom(int bAssertIfPresent, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc tRoomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);

    const int nX = UNITS_GetXPositionInline(pUnit);
    const int nY = UNITS_GetYPositionInline(pUnit);
    D2_ASSERT(pRoom && nX >= pRoom->nSubtileX && nX < pRoom->nSubtileX + pRoom->nSubtileWidth
        && nY >= pRoom->nSubtileY && nY < pRoom->nSubtileY + pRoom->nSubtileHeight, 46);

    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->pRoomNext)
    {
        if (pUnit == i)
        {
            if (!bAssertIfPresent)
            {
                return FALSE;
            }
            D2_ASSERT(pUnit != i, 60);
        }
    }
    return TRUE;
}

// 0x0064C2C0
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused)
{
    D2_ASSERT(pUnit, 72);
    D2_ASSERT(pRoom, 73);
    D2_ASSERT(sub_0064BF60_CanAddUnitToRoom(TRUE, pUnit, pRoom), 82);

    D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitListFromRoom(pRoom);
    D2_ASSERT(ppUnitFirst, 87);
    pUnit->pRoomNext = *ppUnitFirst;
    *ppUnitFirst = pUnit;

    UNITROOM_RefreshUnit(pUnit);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        sub_00619EE0(pRoom);
        break;
    case UNIT_MONSTER:
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
        {
            sub_00619EE0(pRoom);
        }
        break;
    }
    return TRUE;
}
