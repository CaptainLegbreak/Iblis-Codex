#include "D2StatIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
struct D2MissileDataStrc;
struct D2MissilesTxt;
struct D2MissileCalcStrc;

struct D2MissileDataStrc
{
    unsigned int unk0x00;
    short nStreamMissile;
    short nStreamRange;
    short nActivateFrame;
    short nSkill;
    short nLevel;
    short nTotalFrames;
    short nCurrentFrame;
    unsigned short unk0x12;
    unsigned int fFlags;
    int nOwnerType;
    int dwOwnerGUID;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
static int sub_0064ABA0_GetElementMasteryBonus(int nAmount, int nElement, D2UnitStrc* pUnit);
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax); // 0x00645B20
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

struct D2MissileCalcStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    int nMissileId;
    int nMissileLevel;
};

extern void* gpMissileCalcFunctions_00745828[]; // 0x00745828
extern int gnMissileCalcFunctions_00745848; // 0x00745848
int __fastcall MISSILE_GetCalcParamValue(int nParamId, void* pUserData); // 0x0064B6E0

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static inline unsigned int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0xFFFFFFFFu;
    return pUnit->dwUnitId;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit) return 6;
    return pUnit->dwUnitType;
}

// 0x0064A2B0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nTotalFrames = D2_MIN(D2_MAX(nTotalFrames, -32768), 32767);
        pMissile->pMissileData->nTotalFrames = nTotalFrames;
    }
}

// 0x0064A330
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        nCurrentFrame = D2_MIN(D2_MAX(nCurrentFrame, -32768), 32767);
        pMissile->pMissileData->nCurrentFrame = nCurrentFrame;
    }
}

// 0x0064A470
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pMissile && pUnit && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->nMissileFlags[0 >> 3] & gdwBitMasks[0 & 7])
        {
            D2MissileDataStrc* pData = pMissile->pMissileData;
            if (pData && pData->nOwnerType == GetUnitType(pUnit) && pData->dwOwnerGUID == GetUnitId(pUnit))
            {
                return 1;
            }
        }
    }

    return 0;
}
