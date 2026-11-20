#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Path.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern D2DataTablesStrc* sgptDataTables;                                                                         // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                             // 0x00620510
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY);                                                // 0x00643290
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize);                             // 0x00648580
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                     // 0x00648CF0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit);                                             // 0x00649400
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                                           // 0x0064C350

#define COLLIDE_MISSILE_BARRIER 0x4
#define PATH_UNKNOWN_FLAG_0x00010 0x10

inline unsigned int PATH_ToFP16Center(int nValue)
{
    return (nValue << 16) + 0x8000;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int sub_00648480_GetMonsterMoveTestMask(D2UnitStrc* pUnit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? DATATBLS_GetMonStatsTxtRecordInl(pUnit->dwClassId) : 0;
    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_FLYING))
    {
        return COLLIDE_MASK_FLYING_UNIT;
    }
    return BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) ? COLLIDE_MASK_MONSTER_THAT_CAN_OPEN_DOORS : COLLIDE_MASK_MONSTER_PATH;
}

// 0x00649D00
void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag)
{
    D2DynamicPathStrc* pDynamicPath = (D2DynamicPathStrc*)FOG_AllocPool(pMemPool, sizeof(D2DynamicPathStrc), ".\\PATH\\Path.cpp", 1107, 0);
    memset(pDynamicPath, 0, sizeof(D2DynamicPathStrc));

    pUnit->pDynamicPath = pDynamicPath;
    pDynamicPath->pUnit = pUnit;
    pDynamicPath->dwUnitSize = UNITS_GetUnitSizeX(pUnit);
    pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);

    pDynamicPath->dwPrecisionX = PATH_ToFP16Center(nX);
    pDynamicPath->dwPrecisionY = PATH_ToFP16Center(nY);
    pDynamicPath->dwVelocity = 2048;
    pDynamicPath->pRoom = pRoom;
    pDynamicPath->nStepNum = 0;
    pDynamicPath->nSavedStepsCount = 1;
    pDynamicPath->SavedSteps[0].X = nX;
    pDynamicPath->SavedSteps[0].Y = nY;

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        pDynamicPath->nFootprintCollisionMask = COLLIDE_PLAYER;
        pDynamicPath->nMoveTestCollisionMask = COLLIDE_MASK_PLAYER_PATH;
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
        pDynamicPath->bDistMax = 73;
        pDynamicPath->nIDAStarInitFScore = 70;
        break;

    case UNIT_MONSTER:
    {
        pDynamicPath->nFootprintCollisionMask = COLLIDE_MONSTER;

        D2_ASSERT(!(pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER), 2145);
        pDynamicPath->dwFlags &= 0xFFF800FF;
        pDynamicPath->eType = PATHTYPE_TOWARD;
        pDynamicPath->nDirOffset = 0;
        D2_ASSERT(pDynamicPath->ePrevType != PATHTYPE_KNOCKBACK_CLIENT, 2161);
        D2_ASSERT(pDynamicPath->ePrevType != PATHTYPE_KNOCKBACK_SERVER, 2162);

        const int nBaseId = sub_00463860(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            switch (nBaseId)
            {
            case MONSTER_WRAITH1:
                pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
                pDynamicPath->nMoveTestCollisionMask = COLLIDE_MISSILE_BARRIER | COLLIDE_DOOR;
                pDynamicPath->bDistMax = 14;
                break;

            default:
                pDynamicPath->nMoveTestCollisionMask = sub_00648480_GetMonsterMoveTestMask(pUnit);
                pDynamicPath->bDistMax = 14;
                break;
            }
        }
        else
        {
            pDynamicPath->nMoveTestCollisionMask = sub_00648480_GetMonsterMoveTestMask(pUnit);
            pDynamicPath->bDistMax = 14;
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
