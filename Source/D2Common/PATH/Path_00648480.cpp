#include "D2Common.h"
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_MISSILE 3
#define COLLIDE_MISSILE_BARRIER 0x4
#define PATH_UNKNOWN_FLAG_0x00010 0x10
#define UNIT_INVALID 6
#define MONSTATSFLAGINDEX_INTERACT 9
#define UNITFLAG_ISASYNC 0x00200000
#define PATH_UNKNOWN_FLAG_0x02000 0x00002000
#define PATH_WITH_PREVIOUS_VELOCITY 0x00008000
struct D2MonStatsTxt;
struct D2CoordStrc;
struct D2FP32_16;
struct D2StaticPathStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    unsigned int dwPrecisionX;
    unsigned int dwPrecisionY;
    int dwClientCoordX;
    int dwClientCoordY;
    D2PathPointStrc tTargetCoord;
    D2PathPointStrc tPrevTargetCoord;
    D2PathPointStrc tFinalTargetCoord;
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x30 - 0x20];
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
    int unk0x38;
    unsigned int dwPathType;
    unsigned int dwPrevPathType;
    int dwUnitSize;
    int dwCollisionPattern;
    int nFootprintCollisionMask;
    int nMoveTestCollisionMask;
    unsigned char unk_54[0x4];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x8];
    unsigned char nDirection;
    unsigned char nNewDirection;
    unsigned char nDiffDirection;
    char unk0x67[0x15];
    int dwVelocity;
    unsigned int nPreviousVelocity;
    char unk0x84[0x0D];
    unsigned char nDistMax;
    unsigned char nIDAStarInitFScore;
    unsigned char nStepNum;
    char unk0x94[4];
    int nDirOffset;
    char unk0x9C[0x1D4 - 0x9C];
    int nSavedStepsCount;
    unsigned short SavedSteps;
    unsigned short f_1DA;
    char unk0x1DC[0x200 - 0x1DC];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    unsigned char unk_08[0x8];
    int dwAnimMode;
    char unk0x14[0x2C - 0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x1A8 - 0x10];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY); // 0x00643290
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize); // 0x00648580
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x0064C350
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster); // 0x0063E860
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2); // 0x00650350
int __stdcall D2Common_10227(D2UnitStrc* pUnit); // 0x00650540
extern int gaOffsetForPathType_006EB648[]; // 0x006EB648
extern int gaPathTypeFlags_006EB690[]; // 0x006EB690

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2FP32_16
{
    union
    {
        struct
        {
            unsigned short wOffsetX;
            unsigned short wPosX;
            unsigned short wOffsetY;
            unsigned short wPosY;
        };
        struct
        {
            unsigned int dwPrecisionX;
            unsigned int dwPrecisionY;
        };
    };
};

void __stdcall DUNGEON_ClientToGameCoords(int* pX, int* pY); // 0x00643540
void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit); // 0x006209D0
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_HasCollision(D2UnitStrc* pUnit); // 0x006219C0
void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90
void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EA00
void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x00648480
static int sub_00648480_GetMonsterMoveTestMask(D2UnitStrc* pUnit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? DATATBLS_GetMonStatsTxtRecordInl(pUnit->dwClassId) : 0;
    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_FLYING))
    {
        return COLLIDE_MASK_FLYING_UNIT;
    }
    return BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) ? COLLIDE_MASK_MONSTER_THAT_CAN_OPEN_DOORS : COLLIDE_MASK_MONSTER_PATH;
}

void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag)
{
    D2DynamicPathStrc* pDynamicPath = (D2DynamicPathStrc*)FOG_AllocPool(pMemPool, sizeof(D2DynamicPathStrc), ".\\PATH\\Path.cpp", 1107, 0);
    memset(pDynamicPath, 0, sizeof(D2DynamicPathStrc));

    pUnit->pDynamicPath = pDynamicPath;
    pDynamicPath->pUnit = pUnit;
    pDynamicPath->dwUnitSize = UNITS_GetUnitSizeX(pUnit);
    pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);

    pDynamicPath->dwPrecisionX = (nX << 16) + 0x8000;
    pDynamicPath->dwPrecisionY = (nY << 16) + 0x8000;
    pDynamicPath->SavedSteps = nX;
    pDynamicPath->dwVelocity = 2048;
    pDynamicPath->pRoom = pRoom;
    pDynamicPath->nStepNum = 0;
    pDynamicPath->nSavedStepsCount = 1;
    pDynamicPath->f_1DA = nY;

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        pDynamicPath->nFootprintCollisionMask = COLLIDE_PLAYER;
        pDynamicPath->nMoveTestCollisionMask = COLLIDE_MASK_PLAYER_PATH;
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
        pDynamicPath->nDistMax = 73;
        pDynamicPath->nIDAStarInitFScore = 70;
        break;

    case UNIT_MONSTER:
    {
        pDynamicPath->nFootprintCollisionMask = COLLIDE_MONSTER;

        D2_ASSERT(!(pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER), 2145);
        pDynamicPath->dwFlags &= 0xFFF800FF;
        pDynamicPath->dwPathType = PATHTYPE_TOWARD;
        pDynamicPath->nDirOffset = 0;
        D2_ASSERT(pDynamicPath->dwPrevPathType != PATHTYPE_KNOCKBACK_CLIENT, 2161);
        D2_ASSERT(pDynamicPath->dwPrevPathType != PATHTYPE_KNOCKBACK_SERVER, 2162);

        const int nBaseId = sub_00463860(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_WRAITH1)
        {
            pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
            pDynamicPath->nMoveTestCollisionMask = COLLIDE_MISSILE_BARRIER | COLLIDE_DOOR;
            pDynamicPath->nDistMax = 14;
        }
        else
        {
            pDynamicPath->nMoveTestCollisionMask = sub_00648480_GetMonsterMoveTestMask(pUnit);
            pDynamicPath->nDistMax = 14;
        }
        break;
    }

    case UNIT_MISSILE:
        pDynamicPath->nFootprintCollisionMask = 0;
        pDynamicPath->nMoveTestCollisionMask = 0;
        PATH_SetType(pDynamicPath, PATHTYPE_MISSILE);
        break;
    }

    if (pRoom)
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
        UNITROOM_AddUnitToRoom(pUnit, pDynamicPath->pRoom);
    }

    int nClientX = pDynamicPath->dwPrecisionX >> 11;
    int nClientY = pDynamicPath->dwPrecisionY >> 11;
    DUNGEON_GameToClientCoords(&nClientX, &nClientY);
    pDynamicPath->dwClientCoordX = nClientX;
    pDynamicPath->dwClientCoordY = nClientY;

    if (bSetFlag)
    {
        pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00010;
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00648580
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize)
{
    if (nSize < 0 || nSize >= COLLISION_UNIT_SIZE_COUNT)
    {
        return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
    }

    int nCollisionPattern = gaCollisionPatternsFromSize[nSize];
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && MONSTERS_CanBeInTown(pUnit) && !sub_00457490_CheckMonStatsFlag(pUnit->dwClassId, MONSTATSFLAGINDEX_INTERACT))
    {
        switch (nCollisionPattern)
        {
        case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
            break;
        case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
            break;
        }
    }

    return nCollisionPattern;
}

// 0x00649210
void __stdcall D2Common_10213(D2UnitStrc* pUnit)
{
    if (pUnit && !UNIT_HasFlag(pUnit, UNITFLAG_ISASYNC) && UNIT_HasFlagEx(pUnit, UNITFLAGEX_UNK_PATH_RELATED))
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        D2_ASSERT(pDynamicPath, 2485);

        ++pDynamicPath->unk0x38;
        if (pDynamicPath->unk0x38 > 1)
        {
            pDynamicPath->unk0x38 = 0;
            if (!D2Common_10227(pUnit))
            {
                if (D2Common_10236(pUnit, PATH_GetTargetUnit(pUnit->pDynamicPath) != 0))
                {
                    UNITS_ChangeAnimMode(pUnit, 2);
                }
            }
        }
    }
}

// 0x006485F0
void __fastcall sub_6FDA9720(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection)
{
    nDirection &= 63;
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case 2:
    case 4:
        pDynamicPath->nDirection = nDirection;
        break;
    case 3:
        if (!(pDynamicPath->dwFlags & 0x40))
        {
            pDynamicPath->nDirection = nDirection;
        }
        break;
    default:
        if (nDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nDirection;
            const unsigned char nDiff = nDirection - pDynamicPath->nDirection;
            pDynamicPath->nDiffDirection = gnDirectionDiffTable_006EB548[nDiff & 63];
        }
        break;
    }
}

// 0x006489E0
void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX)
{
    pPath->dwClientCoordX = nX;
}

// 0x006489F0
void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY)
{
    pPath->dwClientCoordY = nY;
}

// 0x00648CF0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType)
{
    D2_ASSERT(!(pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 0 && nPathType == 2), 0x861);

    int nFlag = gaPathTypeFlags_006EB690[nPathType];
    if ((nFlag & 0x2000) && !(pDynamicPath->dwFlags & 0x4000))
    {
        pDynamicPath->dwPrevPathType = pDynamicPath->dwPathType;
    }

    if ((nFlag & 0x8000) && !(pDynamicPath->dwFlags & 0x10000))
    {
        pDynamicPath->nPreviousVelocity = pDynamicPath->dwVelocity;
    }

    pDynamicPath->dwPathType = nPathType;
    pDynamicPath->dwFlags = nFlag | pDynamicPath->dwFlags & 0xFFF800FF;
    pDynamicPath->nDirOffset = gaOffsetForPathType_006EB648[nPathType];

    D2_ASSERT(pDynamicPath->dwPrevPathType != 0xB, 0x871);
    D2_ASSERT(pDynamicPath->dwPrevPathType != 8, 0x872);
    D2_ASSERT((nPathType != 4) || (pDynamicPath->nDistMax < 78), 0x873);
}

// 0x006505C0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath)
{
    if (!pPath)
    {
        return 0;
    }

    return pPath->dwFlags & 8;
}

#include "gen/data/Source/D2Common/PATH/Path_00648480.inc"

// 0x006486C0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwVelocity;
}

// 0x006487F0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->nDirection;
}

// 0x00648A00
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.X;
}

// 0x00648A10
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.Y;
}

// 0x00648BF0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->pTargetUnit;
}

// 0x00648E30
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwPathType;
}

// 0x00648B00
void __stdcall sub_00648B00_SetTargetCoordFromClient(D2DynamicPathStrc* pDynamicPath, int nX, int nY)
{
    DUNGEON_ClientToGameCoords(&nX, &nY);
    nX >>= 11;
    nY >>= 11;
    pDynamicPath->tTargetCoord.X = nX;
    pDynamicPath->tTargetCoord.Y = nY;
}

// 0x0064FD70
void __fastcall sub_0064FD70_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint)
{
    D2CoordStrc tStart;
    D2CoordStrc tTarget;
    tStart.nX = (tStartPoint.X << 16) + 0x8000;
    tStart.nY = (tStartPoint.Y << 16) + 0x8000;
    tTarget.nX = (tTargetPoint.X << 16) + 0x8000;
    tTarget.nY = (tTargetPoint.Y << 16) + 0x8000;
    PATH_GetDirectionVector(pDirectionVector, pOutDirection, tStart.nX, tStart.nY, tTarget.nX, tTarget.nY);
}

// 0x0064FDC0
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2)
{
    D2CoordStrc tCoords;
    int nDirection;
    D2CoordStrc tStart;
    D2CoordStrc tTarget;
    tStart.nX = (nX1 << 16) + 0x8000;
    tStart.nY = (nY1 << 16) + 0x8000;
    tTarget.nX = (nX2 << 16) + 0x8000;
    tTarget.nY = (nY2 << 16) + 0x8000;
    PATH_GetDirectionVector(&tCoords, &nDirection, tStart.nX, tStart.nY, tTarget.nX, tTarget.nY);
    return nDirection;
}

// 0x00648DC0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath->pUnit, 2174);

    if (pDynamicPath->dwFlags & PATH_WITH_PREVIOUS_VELOCITY)
    {
        pDynamicPath->dwVelocity = pDynamicPath->nPreviousVelocity;
    }

    if (pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER)
    {
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
    }
    else if (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x02000)
    {
        PATH_SetType(pDynamicPath, pDynamicPath->dwPrevPathType);
    }
}

inline int __fastcall UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int __fastcall UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00649400
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    switch (nType)
    {
    case 0:
    case 1:
    {
        const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
        COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
        break;
    }

    case 2:
        COLLISION_SetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
        break;

    default:
        COLLISION_SetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        break;
    }
}

// 0x00649560
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
        if ((pUnit && pUnit->dwAnimMode != 17 && pUnit->dwAnimMode != 0) || bForce)
        {
ResetPattern:
            const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
            COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    case 1:
        if ((pUnit && pUnit->dwAnimMode != 12 && pUnit->dwAnimMode != 0) || bForce)
        {
            goto ResetPattern;
        }
        break;

    case 2:
        if (UNITS_HasCollision(pUnit) || bForce)
        {
            COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    default:
        COLLISION_ResetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        return 1;
    }

    return 0;
}
