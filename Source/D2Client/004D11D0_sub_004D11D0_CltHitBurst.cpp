struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned int dwMissileFlags;
    unsigned short wCltDoFunc;
    unsigned short wCltHitFunc;
    unsigned short wSrvDoFunc;
    unsigned short wSrvHitFunc;
    unsigned short wSrvDmgFunc;
    unsigned short wTravelSound;
    unsigned short wHitSound;
    unsigned short wExplosionMissile;
    short wSubMissile[3];
    short wCltSubMissile[3];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    short wProgSound;
    unsigned short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
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

void __fastcall sub_004C7700(D2UnitStrc* pMissile, int nMissile, int nCount, int nRows, int nSkill, int nSkillLevel); // 0x004C7700
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __fastcall sub_004CE140(D2UnitStrc* pMissile, int nArg1, int nArg2, int nArg3, int nArg4);             // 0x004CE140
void __fastcall sub_004CED20(D2UnitStrc* pMissile, int nMissile);                                           // 0x004CED20
void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CEF50
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x004D11D0
int __fastcall sub_004D11D0_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pHitUnit)
    {
        return 0;
    }

    sub_004CEF50_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->wCltHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwCltHitPar[1], 1);
    return 1;
}

// 0x004D1F50
int __fastcall sub_004D1F50_CltHitSpawnRequest(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    sub_004C7700(pMissile, 0x16D, 3, 6, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    sub_004CDBA0_SubmitOwnerRequest(pMissile, 0x16E, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    return 1;
}

// 0x004D56B0
void __fastcall sub_004D56B0_CltDoParamCallSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    sub_004CE140(pMissile, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->wCltSubMissile[0]);
    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D5BA0
void __fastcall sub_004D5BA0_CltDoPeriodicSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    int nRate = pMissilesTxtRecord->dwCltParam[0];
    if (nRate < 1)
    {
        nRate = 1;
    }

    if (!(nFrames % nRate))
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltSubMissile[0]);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
