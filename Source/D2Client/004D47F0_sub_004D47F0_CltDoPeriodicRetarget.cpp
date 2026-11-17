#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    int unk0x20[2];
    int unk0x28;
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MissilesTxt
{
    char unk0x00[0x58];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline void RotateOffsets(int* pX,int* pY)
{
    const int nOldX=*pX;
    const int nNegY=-*pY;
    __assume(nNegY != (-2147483647 - 1));
    *pX=(nNegY+nOldX)/2;
    *pY=(nOldX+*pY)/2;
}

// 0x004D47F0
void __fastcall sub_004D47F0_CltDoPeriodicRetarget(D2UnitStrc* pMissile)
{
    int nOffsetX = 0;
    int nOffsetY = 0;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nPeriod = MAX(pMissilesTxtRecord->dwCltParam[1], 1);

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < pMissilesTxtRecord->dwCltParam[0] && !(nFrames % nPeriod))
    {
        nOffsetX = MISSILE_GetTargetX(pMissile);
        nOffsetY = MISSILE_GetTargetY(pMissile);
        RotateOffsets(&nOffsetX,&nOffsetY);
        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, UNITS_GetXPosition(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        MISSILE_SetTargetX(pMissile, nOffsetX);
        MISSILE_SetTargetY(pMissile, nOffsetY);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
