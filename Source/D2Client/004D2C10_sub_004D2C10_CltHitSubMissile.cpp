struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[9];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char unk0x00[0x2C];
    unsigned short wCltHitSubMissile[4];
    char unk0x34[0x6C - 0x34];
    int dwCltHitPar[3];
    char unk0x78[0x1A4 - 0x78];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __fastcall sub_004CEFE0_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nArg1, int nArg2, int nArg3); // 0x004CEFE0
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit);                                                  // 0x004DA150
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D2C10
int __fastcall sub_004D2C10_CltHitSubMissile(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            const short nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
            if (nSubMissile >= 0)
            {
                int nPar = pMissilesTxtRecord->dwCltHitPar[0];
                if (nPar < 1)
                {
                    nPar = 1;
                }

                sub_004CEFE0_AddMissileEffect(pMissile, nSubMissile, nPar, 2, 0);
            }
        }
    }

    return 1;
}

// 0x004D7FC0
void __fastcall sub_004D7FC0_CltDoZRange(D2UnitStrc* pMissile)
{
    const int nMin = -MISSILE_GetTargetX(pMissile);
    const int nMax = MISSILE_GetTargetY(pMissile);
    const int nZ = sub_004DA150_GetMotionAZ(pMissile);
    if (nZ >= nMin && nZ <= nMax)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    sub_004CD390_CltDoDefault(pMissile);
}
