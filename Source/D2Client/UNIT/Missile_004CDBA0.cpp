#include "D2Client.h"

struct D2PathRecordStrc;
struct D2StaticPathStrc;
struct D2RequestStrc;
struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2MissileScanArgStrc;
struct D2SeedStrc;
struct D2SpawnOffsetMissileView;

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2PathRecordStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    D2UnitStrc* pOtherUnit;
    int unk0x0C;
    int nArg0;
    int nArg1;
    int nArg2;
    int nArg5;
    int nArg6;
    int nArg7;
    int unk0x28;
    int nArg3;
    int nArg4;
    int unk0x34[8];
    void* pfCallback;
    int nIndex;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540
void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile); // 0x004E2ED0
int __stdcall sub_006488C0_PathGetX(D2PathRecordStrc* pPath); // 0x006488C0
int __stdcall sub_00648900_PathGetY(D2PathRecordStrc* pPath); // 0x00648900
void __stdcall sub_00649030_SetPathFlag40(D2PathRecordStrc* pPath, int bClear); // 0x00649030

struct D2MissilesTxt
{
    char unk0x000[0x24];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    char unk0x034[0x38];
    int dwCltHitPar[3];
    char unk0x078[0x12C];
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    char unk0x054[0x10];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0xDC];
    unsigned int dwCalc144;
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

struct D2MissileScanArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pMissile;
    int nSkillId;
    int nSkillLevel;
    int f_10;
    int f_14;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType);
int __fastcall sub_004CFFA0_HitScanCallback(void* pArg, D2UnitStrc* pUnit);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280
extern "C" int __stdcall sub_0064A730_GetMissileTargetStatus(D2UnitStrc* pMissile);
extern "C" int __stdcall sub_0064A780_targetValue(D2UnitStrc* pMissile);

struct D2SpawnOffsetMissileView
{
    void __thiscall sub_004D16C0_SpawnOffsetMissile(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x004D16C0
};

void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? sub_00648900_PathGetY(pUnit->pDynamicPath) : 0;
}

// 0x004CDBA0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x20;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nArg5;
    tRequest.nArg6 = nArg6;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004CDC30
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    if (!nRange)
    {
        nRange = 30;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x521;
    tRequest.pUnit = pOwner;
    tRequest.nArg1 = UNITS_GetXPosition(pUnit) + nOffsetX;
    tRequest.nArg2 = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg7 = nRange;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004CDD10
D2UnitStrc* __fastcall sub_004CDD10_SubmitTargetRequest(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1)
    {
        pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pOwner, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x420;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004F16F0
int __fastcall sub_004F16F0_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nArg0, int nArg3, int nArg4, int nMissileArg, int bFirst, int bClearPathFlag)
{
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (bFirst)
    {
        --nCount;
        D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nArg0, nArg3, nArg4);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x21;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = UNITS_GetXPositionInline(pUnit);
    tRequest.nArg2 = UNITS_GetYPositionInline(pUnit);
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    tRequest.pfCallback = sub_004E2ED0_VolleyCallback;
    if (bClearPathFlag)
    {
        tRequest.nType |= 0x2000;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tRequest.nIndex = i;
        D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                sub_00649030_SetPathFlag40(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    return 1;
}

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004D0060
int __fastcall sub_004D0060_HitScanArea(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (!sub_00463990(sub_0064A780_targetValue(pMissile), sub_0064A730_GetMissileTargetStatus(pMissile)))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc144, nSkillId, nSkillLevel);
    }

    int nFlags = pSkillsTxtRecord->dwAuraFilter;
    if (nFlags)
    {
        nFlags = 0xA683;
    }

    D2MissileScanArgStrc tArg;
    tArg.pOwner = pOwner;
    tArg.pMissile = pMissile;
    tArg.nSkillId = nSkillId;
    tArg.nSkillLevel = nSkillLevel;
    tArg.f_14 = pMissilesTxtRecord->wCltHitSubMissile[0];
    sub_004C5C40_ScanArea(pOwner, nX, nY, nRange, nFlags, sub_004CFFA0_HitScanCallback, &tArg, 0);
    return 1;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004D65E0
void __fastcall sub_004D65E0_CltDoOffsetMissileTimer(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    int nCounter = MISSILE_GetTargetY(pMissile);
    if (!nCounter)
    {
        const int nUnitId = MISSILE_GetTargetX(pMissile);
        ((D2SpawnOffsetMissileView*)nUnitId)->sub_004D16C0_SpawnOffsetMissile(pMissile, pOwner);
        nCounter = (unsigned int)SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10;
    }

    --nCounter;
    MISSILE_SetTargetY(pMissile, nCounter);
    sub_004D30C0_CltDoCommon(pMissile);
}
