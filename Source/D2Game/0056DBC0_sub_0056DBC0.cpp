struct D2DynamicPathStrc;
struct D2CoordStrc { int nX; int nY; };
struct D2StaticPathStrc { char unk0x00[0x0C]; D2CoordStrc tGameCoords; };
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
};
enum D2C_UnitTypes { UNIT_OBJECT = 2, UNIT_ITEM = 4, UNIT_TILE = 5 };
struct D2ActiveRoomStrc;
struct D2GameStrc { char unk_00[0x1C]; void* pMemoryPool; };
struct D2UnitFindArgStrc
{
    int nFlags; int unk_04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk_28; int unk_2C; int unk_30; int unk_34;
};
struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};
typedef void (__fastcall* CurseCallbackFunc)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*); // 0x006CC34C
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc*, int, int); // 0x00463740
void __stdcall UNITFINDS_InitializeUnitFindData(void*, D2UnitFindDataStrc*, D2ActiveRoomStrc*, int, int, int, void*, D2UnitFindArgStrc*); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc*); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc*); // 0x0065AA00
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DynamicPathStrc;
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056DBC0
void __fastcall sub_0056DBC0(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse)
{
    D2_ASSERT(pfCurse, 0x1047);
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        D2UnitFindArgStrc findArg = {};
        findArg.nFlags = nFlags;
        findArg.pUnit = pUnit;
        findArg.nX = nX;
        findArg.nY = nY;
        findArg.nSize = nRange;
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitFindDataStrc findData;
            UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &findData, pRoom, nX, nY, nRange, 0, &findArg);
            UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&findData);
            D2_ASSERT(!IsBadCodePtr((void*)pfCurse), 0x1061);
            for (int i = 0; i < findData.nIndex; ++i)
                pfCurse(pGame, pUnit, findData.pUnitsArray[i], nSkillLevel);
            UNITFINDS_FreeUnitFindData(&findData);
        }
    }
}
