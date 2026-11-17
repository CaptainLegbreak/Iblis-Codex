struct D2DynamicPathStrc;

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

struct D2ObjGroupTxt
{
    char unk0x00[0x34];
};

struct D2ShrinesTxt
{
    char unk0x00[0xB8];
};

struct D2LevelDefBin
{
    char unk0x00[0x34];
    int dwLevelType;
    char unk0x38[0x94 - 0x38];
    int dwSaveMonsters;
    int dwLOSDraw;
};

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1AC];
    D2DrlgLevelStrc* pNextLevel;
    char unk0x1B0[0x1D0 - 0x1B0];
    int nLevelId;
};

struct D2DrlgStrc
{
    char unk0x000[0x47C];
    D2DrlgLevelStrc* pLevel;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2ShrinesTxt* gpShrinesTxt;                                                                          // 0x0096D468
extern int gnShrinesTxtRecordCount;                                                                         // 0x0096D46C
extern D2ObjGroupTxt* gpObjgroupTxt;                                                                        // 0x0096D478
int gnObjgroupTxtRecordCount;                                                                               // 0x0096D47C
extern const int gnTownLevelIds_006EB2F0[];                                                                 // 0x006EB2F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
D2LvlTypesTxt* __stdcall DATATBLS_GetLevelTypesTxtRecord(int nLevelType);                                   // 0x0061EAA0
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId);                               // 0x00642AE0

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
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

// 0x006412F0
D2ObjGroupTxt* __stdcall DATATBLS_GetObjGroupTxtRecord(int nId)
{
    if (gnObjgroupTxtRecordCount > nId)
    {
        return &gpObjgroupTxt[nId];
    }

    return 0;
}

// 0x006414B0
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId)
{
    D2_ASSERT(nShrineId < gnShrinesTxtRecordCount, 351);
    D2_ASSERT(nShrineId >= 0, 352);
    return &gpShrinesTxt[nShrineId];
}

// 0x00641890
int __stdcall UNITS_IsInRange(D2UnitStrc* pUnit, D2CoordStrc* pCoord, int nDistance)
{
    const int nDiffX = pCoord->nX - UNITS_InlineGetXPosition(pUnit);
    const int nDistanceX = nDiffX < 0 ? -nDiffX : nDiffX;
    int nDistanceY = pCoord->nY - UNITS_InlineGetYPosition(pUnit);
    if (nDistanceY < 0)
    {
        nDistanceY = -nDistanceY;
    }

    return nDistanceX * nDistanceX + nDistanceY * nDistanceY <= nDistance * nDistance;
}

// 0x00642750
int __stdcall DRLG_GetLevelTypeFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwLevelType;
}

// 0x006427F0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId)
{
    for (int nAct = 1; nAct <= 5; ++nAct)
    {
        if (nLevelId < gnTownLevelIds_006EB2F0[nAct])
        {
            return nAct - 1;
        }
    }

    return 0;
}

// 0x00642820
int __stdcall DRLG_GetSaveMonstersFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwSaveMonsters;
}

// 0x00642840
int __stdcall DRLG_GetLOSDrawFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwLOSDraw;
}

// 0x006429E0
unsigned char __stdcall sub_006429E0_GetActFromLevelType(int nLevelType)
{
    return DATATBLS_GetLevelTypesTxtRecord(nLevelType)->nAct;
}

// 0x00642BB0
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->nLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00643260
void __stdcall sub_00643260(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    *pX = 16 * (nX - nY);
    *pY = 8 * (nX + nY);
}

// 0x00643290
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    *pX = (nX - nY) >> 1;
    *pY = (nX + nY) >> 2;
}

// 0x00643310
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    *pX = 80 * (nX - nY);
    *pY = (80 * (nX + nY)) >> 1;
}

#include "gen/data/Source/D2Common/006412F0_DATATBLS_GetObjGroupTxtRecord.inc"
