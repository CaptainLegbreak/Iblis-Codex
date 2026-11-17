#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc tSeed;
    int unk0x28;
    D2DynamicPathStrc* pDynamicPath;
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
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern "C" const char gszMissileSourceFile_006DAEF4[];                                                      // 0x006DAEF4

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_00464810(D2UnitStrc* pUnit);                                                            // 0x00464810
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004CE140(D2UnitStrc* pMissile, int nArg1, int nArg2, int nArg3, int nArg4);             // 0x004CE140
D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nArg1, int nArg2, int nMissile);              // 0x004CE320
void __fastcall sub_004CE420(D2UnitStrc* pMissile);                                                         // 0x004CE420
void __fastcall sub_004D2D70_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg);            // 0x004D2D70
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit);                                                 // 0x006217C0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                         // 0x0064A3B0

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D33E0
void __fastcall sub_004D33E0_CltDoOnScreen(D2UnitStrc* pMissile)
{
    if (UNITS_IsAtEndOfFrameCycle(pMissile))
    {
        sub_00464810(pMissile);
        PATH_SetVelocity(pMissile->pDynamicPath, 0, gszMissileSourceFile_006DAEF4, 0x7F);
    }

    int nX = UNITS_GetClientCoordX(pMissile) - sub_0045AFC0();
    if (nX >= 0 && nX <= gnAutomapWidth_007A5220)
    {
        int nY = UNITS_GetClientCoordY(pMissile) - sub_0045AFD0_GetMouseYOffset();
        if (nY >= 0 && nY <= gnAutomapHeight_007A521C + 0x40)
        {
            MISSILE_SetCurrentFrame(pMissile, 0x80);
            sub_004D30C0_CltDoCommon(pMissile);
            return;
        }
    }

    sub_004D2D70_CltMissileHit(pMissile, 0, 0);
}

// 0x004D34E0
void __fastcall sub_004D34E0_CltDoParamCall(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    sub_004CE140(pMissile, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->wCltSubMissile[0]);
    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D3C40
void __fastcall sub_004D3C40_CltDoRangeSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nMissile = pMissilesTxtRecord->wCltSubMissile[0];
    if (nMissile < pMissilesTxtRecord->wCltSubMissile[1])
    {
        nMissile += ITEMS_RollLimitedRandomNumber(&pMissile->tSeed, pMissilesTxtRecord->wCltSubMissile[1] - nMissile + 1);
    }

    int nLevel = MISSILE_GetLevel(pMissile);
    nLevel /= MAX(pMissilesTxtRecord->dwCltParam[2], 1);
    int nCount = pMissilesTxtRecord->dwCltParam[0] + MAX(nLevel, 2);
    int nRange = MAX(pMissilesTxtRecord->dwCltParam[1] - nLevel, 3);
    D2UnitStrc* pNew = sub_004CE320(pMissile, nCount, nRange, nMissile);
    if (pNew)
    {
        sub_004CE420(pNew);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// 0x004D3D00
void __fastcall sub_004D3D00_CltDoFrameEndFree(D2UnitStrc* pMissile)
{
    if (UNITS_IsAtEndOfFrameCycle(pMissile))
    {
        sub_00464810(pMissile);
        sub_00464930_FreeLight(pMissile);
    }
    else
    {
        sub_004D30C0_CltDoCommon(pMissile);
    }
}

// 0x004D3E00
void __fastcall sub_004D3E00_CltDoTimedRequests(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[0])
    {
        sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[0], UNITS_GetXPosition(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[1])
    {
        sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[1], UNITS_GetXPosition(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    if (pMissilesTxtRecord->wCltSubMissile[2] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[2])
    {
        sub_004CDB40_SubmitRequest(sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[2], UNITS_GetXPosition(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
