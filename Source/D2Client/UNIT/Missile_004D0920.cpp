#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2StaticPathStrc;
struct D2MissilesTxt;
struct D2SeedStrc;
struct D2MissileStrc;





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
    short wProgOverlay;
    int dwCltHitPar38;
    unsigned char unk_3C[0x10];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x1E];
    short wRange;
    char unk0x98[0x10C];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnUnk_0072A33C[]; // 0x0072A33C
void __fastcall sub_004CDDB0(D2UnitStrc* pUnit, const int* pArg, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDDB0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[5];
    int nRange;
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

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

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004D0920
int __fastcall sub_004D0920_HitCollisionBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    if (!COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), 3, 1))
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            sub_004CDDB0(pMissile, gnUnk_0072A33C, 3, pMissilesTxtRecord->dwCltHitPar38, 0x19, 0x4B);
        }
    }

    return 1;
}

// 0x004D0FF0
int __fastcall sub_004D0FF0_HitCreateSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (!pUnit)
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0]);
        return 1;
    }

    return 0;
}

#include "gen/data/Source/D2Client/UNIT/Missile_004D0920.inc"

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D3630
void __fastcall sub_004D3630_CltDoCommon2(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
        {
            sub_004CD390_CltDoDefault(pMissile);
            return;
        }

        const int nX = UNITS_GetXPosition(pMissile);
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = pOwner;
        tParams.nX = nX;
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        D2MissilesTxt* pSubMissileTxtRecord = SKILLS_GetMissilesTxtRecord(tParams.nMissile);
        if (!pSubMissileTxtRecord)
        {
            sub_004CD390_CltDoDefault(pMissile);
            return;
        }

        const short nRange = pSubMissileTxtRecord->wRange;
        if (nRange)
        {
            tParams.dwFlags = 0x8021;
            tParams.nRange = nRange;
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] >= 0)
        {
            if (pMissilesTxtRecord->wCltSubMissile[2] >= 0)
            {
                switch (SEED_RollLimitedRandomNumber(&pMissile->pSeed, 3))
                {
                case 0:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                    break;
                case 1:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[2];
                    break;
                }
            }
            else if (!SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2))
            {
                tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            }
        }

        const int nChance = pMissilesTxtRecord->dwCltParam[0];
        if (!nChance || SEED_RollLimitedRandomNumber(&pMissile->pSeed, nChance))
            tParams.dwFlags |= 0x4000;

        tParams.nTargetX = UNITS_GetXPosition(pMissile);
        tParams.nTargetY = CLIENTS_GetUnitY(pMissile);
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&tParams);
        if (pNew)
        {
            const int nPrecisionX = UNITS_GetPrecisionX(pMissile);
            const int nPrecisionY = UNITS_GetPrecisionY(pMissile);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            PATH_SetPrecisionX(pPath, nPrecisionX);
            PATH_SetPrecisionY(pPath, nPrecisionY);
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
