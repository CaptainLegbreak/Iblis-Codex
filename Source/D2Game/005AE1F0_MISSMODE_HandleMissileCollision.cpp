struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; int unk08[2]; int dwAnimMode; int unk14[6]; D2DynamicPathStrc* pDynamicPath; };
struct D2MissilesTxt { int unk00[105]; };
struct D2DataTablesStrc { char unk000[0xB64]; D2MissilesTxt* pMissilesTxt; int unkB68; int nMissilesTxtRecordCount; };
struct D2PathPointStrc { unsigned short X; unsigned short Y; };
struct D2MissileUnitFindTableStrc { void* pfUnitFindCallback; int nCollisionMask; };
struct D2MissileFindArgStrc { D2GameStrc* pGame; D2UnitStrc* pMissile; D2UnitStrc* pOwner; D2MissilesTxt* pMissilesTxtRecord; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2MissileUnitFindTableStrc gtMissileCollisionModes[]; // 0x0073C720
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __fastcall SUNIT_UpdateUnitPath(D2GameStrc*, D2UnitStrc*); // 0x00554CA0
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005ADF10
int __stdcall PATH_GetVelocity(D2DynamicPathStrc*); // 0x006486C0
int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc*, int); // 0x0064A330
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned short __stdcall D2Common_10201(D2DynamicPathStrc*); // 0x00648EB0
int __stdcall MISSILE_GetActivateFrame(D2UnitStrc*); // 0x0064A640
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc*, D2PathPointStrc**); // 0x00648F40
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*, int, int, int, int); // 0x0064D9B0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc*, int, int, void*, void*, int); // 0x00641CB0
static D2MissilesTxt* GetMissilesTxt(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}
// 0x005AE1F0
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxt(pMissile);
    if (!pMissilesTxtRecord) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    if (PATH_GetVelocity(pMissile->pDynamicPath) && SUNIT_UpdateUnitPath(pGame, pMissile) == 2)
        return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    const int nFrame = MISSILE_GetCurrentFrame(pMissile) - 1;
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    if (nFrame <= 0) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    const int nMode = pMissile->dwAnimMode;
    if (nMode)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        if (!pRoom || !pPath) return 2;
        unsigned short nCollision = D2Common_10201(pPath);
        if (nCollision & 5) return 2;
        if (nMode != 6 && MISSILE_GetCurrentFrame(pMissile) <= MISSILE_GetActivateFrame(pMissile) && nCollision)
        {
            if (!gtMissileCollisionModes[nMode].pfUnitFindCallback) return 2;
            D2MissileFindArgStrc tFindArg;
            tFindArg.pGame = pGame;
            tFindArg.pMissile = pMissile;
            tFindArg.pOwner = SUNIT_GetOwner(pGame, pMissile);
            tFindArg.pMissilesTxtRecord = pMissilesTxtRecord;
            const int nSize = UNITS_GetUnitSizeX(pMissile);
            D2PathPointStrc* pPoints;
            const int nPoints = D2COMMON_10198_PathGetSaveStep(pPath, &pPoints);
            for (int i = 0; i < nPoints; ++i)
            {
                const int nX = pPoints[i].X;
                const int nY = pPoints[i].Y;
                nCollision = COLLISION_CheckMaskWithSize(pRoom, nX, nY, nSize, gtMissileCollisionModes[nMode].nCollisionMask);
                if (nCollision)
                {
                    D2UnitStrc* pTarget = D2Common_10407(pRoom, nX, nY, gtMissileCollisionModes[nMode].pfUnitFindCallback, &tFindArg, nSize);
                    if (pTarget) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, pTarget, 0);
                    if (nCollision & 4)
                    {
                        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
                        return 2;
                    }
                }
            }
        }
    }
    return 1;
}

#include "gen/data/Source/D2Game/005AE1F0_MISSMODE_HandleMissileCollision.inc"
