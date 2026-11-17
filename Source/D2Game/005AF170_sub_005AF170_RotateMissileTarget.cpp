struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; char unk08[0x24]; D2DynamicPathStrc* pDynamicPath; };
struct D2MissilesTxt { char unk00[0x38]; int dwParam[5]; char unk4C[0x158]; };
struct D2DataTablesStrc { char unk000[0xB64]; D2MissilesTxt* pMissilesTxt; int unkB68; int nMissilesTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc*); // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc*); // 0x0064A730
int __stdcall MISSILE_GetTargetY(D2UnitStrc*); // 0x0064A780
void __stdcall MISSILE_SetTargetX(D2UnitStrc*, int); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc*, int); // 0x0064A760
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc*, int, int); // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc*, D2UnitStrc*, int); // 0x00649970
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc*, D2UnitStrc*); // 0x005AE1F0
static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}
// 0x005AF170
int __fastcall sub_005AF170_RotateMissileTarget(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pRecord) return 2;
    const int nPeriod = pRecord->dwParam[1] < 1 ? 1 : pRecord->dwParam[1];
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < pRecord->dwParam[0] && !(nFrames % nPeriod))
    {
        int nNewX = MISSILE_GetTargetX(pMissile);
        int nNewY = MISSILE_GetTargetY(pMissile);
        const int nOldX = nNewX;
        const int nNegY = -nNewY;
        __assume(nNegY != (-2147483647 - 1));
        nNewX = (nNegY + nNewX) / 2;
        nNewY = (nOldX + nNewY) / 2;
        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nNewX, CLIENTS_GetUnitY(pMissile) + nNewY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        MISSILE_SetTargetX(pMissile, nNewX);
        MISSILE_SetTargetY(pMissile, nNewY);
    }
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}
