#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"

struct D2StaticPathStrc;
struct D2SkillsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc*, D2UnitStrc*, int*, int*); // 0x0056D2C0
void __fastcall SKILLS_EnlargeVector(int*, int*); // 0x0056D370
void __fastcall SKILLS_MakeShortPerpendicularVector(int*, int*); // 0x0056D3B0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
int __fastcall UNITS_GetWeaponClass(D2UnitStrc*); // 0x00623C60
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __stdcall SKILLS_GetParam1(D2SkillStrc*); // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc*); // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc*); // 0x00644500
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc*, int); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc*, int); // 0x006445E0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc*, D2UnitStrc*, int, int, int, unsigned int, int, int*); // 0x0056BD10
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*, D2UnitStrc*); // 0x00620C10
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc*, int); // 0x005DB6A0
int __fastcall SKILLDESC_GetSkillParamSix(int); // 0x004F4110
void __fastcall SKILLS_RewindUnitAnimation(D2UnitStrc*, int); // 0x0056E210

typedef char DamageSizeCheck[sizeof(D2DamageStrc) == 0x70 ? 1 : -1];
int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit); // 0x0056E510
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

// 0x005DB410
int __fastcall sub_005DB410_CreateMissileWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missile;
    if (pUnit) pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    if (!pSkillsTxtRecord) goto ReturnZero;
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        const int nTotal = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        int nUnitX;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nUnitX = pUnit->pStaticPath->nXPos;
            break;
        default:
            nUnitX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
            break;
        }
        int nDx = nX - nUnitX;
        int nUnitY;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nUnitY = pUnit->pStaticPath->nYPos;
            break;
        default:
            nUnitY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
            break;
        }
        int nDy = nY - nUnitY;
        SKILLS_EnlargeVector(&nDx, &nDy);
        SKILLS_MakeShortPerpendicularVector(&nDx, &nDy);
        nX += -(nDx * nTotal / 2);
        nY += -(nDy * nTotal / 2);
        int nMissile = pSkillsTxtRecord->wSrvMissileA;
        if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxtRecord->wSrvMissileB >= 0) nMissile = pSkillsTxtRecord->wSrvMissileB;
        if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount) goto ReturnZero;
        int nActive = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (!nActive) nActive = nTotal;
        memset(&missile, 0, sizeof(missile));
        missile.dwFlags = 0x820;
        missile.pOwner = pUnit;
        missile.pOrigin = pUnit;
        missile.nSkill = nSkillId;
        missile.nSkillLevel = nSkillLevel;
        missile.nMissile = nMissile;
        missile.nActivateFrame = SKILLS_EvaluateSkillFormula(missile.pOwner, pSkillsTxtRecord->dwCalc[1], missile.nSkill, missile.nSkillLevel);
        missile.dwFlags |= 0x10000;
        const int nOutside = (nTotal - nActive) / 2;
        if (nOutside > 0)
        {
            int i = nOutside;
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--i);
        }
        missile.dwFlags &= ~0x10000u;
        if (nActive > 0)
        {
            int i = nActive;
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--i);
        }
        missile.dwFlags |= 0x10000;
        int nRemaining = nTotal - nOutside - nActive;
        if (nRemaining > 0)
        {
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--nRemaining);
        }
    }
    return 1;
ReturnZero:
    return 0;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline int GetTargetType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static inline int GetTargetId(D2UnitStrc* pUnit)
{
    int nId = -1;
    if (pUnit)
    {
        nId = pUnit->dwUnitId;
    }
    return nId;
}

// 0x005DBA40
int __fastcall sub_005DBA40_CreateSkillMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nCount = SKILLS_GetParam1(pSkill);
    if (!nCount) return 0;
    const int nTargetId = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), nTargetId);
    if (!pTarget)
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 3, nTargetId, 0);
        if (!pTarget) return 1;
    }
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    int nX = 0;
    int nY = 0;
    D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY);
    int nMissile = pSkillsTxt->wSrvMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxt->wSrvMissileB >= 0)
        nMissile = pSkillsTxt->wSrvMissileB;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount) return 0;
    const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    D2MissileStrc missile;
    memset(&missile, 0, sizeof(missile));
    missile.dwFlags = 0x21;
    missile.pOwner = pUnit;
    missile.nX = CLIENTS_GetUnitX(pUnit);
    missile.nY = CLIENTS_GetUnitY(pUnit);
    missile.nSkill = nSkillId;
    missile.nSkillLevel = nSkillLevel;
    missile.nMissile = nMissile;
    missile.nTargetX = nX;
    missile.nTargetY = nY;
    missile.pInitFunc = SKILLS_AddDamagePercentBonus;
    missile.nInitArg = nDamage;
    MISSILES_CreateMissileFromParams(pGame, &missile);
    --nCount;
    SKILLS_SetParam1(pSkill, nCount);
    if (nCount <= 0) return 0;
    D2UnitStrc* pNextTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 3, !pTarget ? -1 : pTarget->dwUnitId, 0);
    if (pNextTarget)
    {
        SKILLS_SetParam2(pSkill, GetTargetType(pNextTarget));
        SKILLS_SetParam3(pSkill, GetTargetId(pNextTarget));
        SKILLS_RewindUnitAnimation(pUnit, SKILLDESC_GetSkillParamSix(nSkillId));
    }
    return 1;
}
