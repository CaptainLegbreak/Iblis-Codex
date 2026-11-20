#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define UNITFLAG_SKSRVDOFUNC 0x00000040
#define ITEMTYPE_MISSILE_POTION 38
#define STAT_PROGRESSIVE_TOHIT 325
struct D2StaticPathStrc;

struct D2CoordStrc { int nX; int nY; };

struct D2StaticPathStrc { char unk0x00[0x0C]; D2CoordStrc tGameCoords; };

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
unsigned int __stdcall sub_006417F0(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

D2UnitStrc* __fastcall sub_0059FA30(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, void* pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventFrame, int a5, int a6); // 0x005417D0
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
static __declspec(noinline) void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay);

D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
int __fastcall sub_0056C2D0_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel); // 0x0056C2D0
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender,D2DamageStrc* pDamage,int nWeapon,unsigned char nSrcDam); // 0x0057B7D0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4); // 0x0057D4F0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int a5); // 0x0057DBF0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nToHit, int a5); // 0x0057EC10
void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3AC0
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0
void __fastcall sub_005D5220_DischargeProgressiveSkills(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D5220
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480
unsigned int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
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
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056EDE0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!nX && !nY)
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY);
        if (!nX && !nY)
        {
            return 0;
        }
    }

    if (sub_006417F0(pUnit, nX, nY) > 100)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nMissile = nMissileId;

    return sub_0059FA30(pGame, &missileParams);
}

// 0x0056EF90
static void __stdcall D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay)
{
    const int nExpireFrame = nDelay + pGame->dwGameFrame;
    if (pUnit && !pUnit->dwUnitType && nDelay)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x79);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (!pStatList)
            {
                return;
            }

            STATLIST_SetState(pStatList, 0x79);
            STATLIST_SetStatRemoveCallback(pStatList, (void*)sub_6FD10E50);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, 0x79, 1);
        }

        D2COMMON_10476(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
    }
}

// calling-convention shim (not game code)
void __stdcall shim_4(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay)
{
    D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nDelay);
}

// 0x0056F070
int __fastcall SKILLS_SrvDo001_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pWeapon = sub_6FC7C7B0(pUnit);
    if (pWeapon && ITEMS_GetItemType(pWeapon) == ITEMTYPE_MISSILE_POTION)
    {
        return 0;
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        const int nItemType = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
        if (nItemType != ITEMTYPE_BOW)
        {
            sub_6FD11420(pGame, nItemType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
        }
        else
        {
            sub_6FD11420(pGame, ITEMTYPE_BOW, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        }
        return 1;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage = {};
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0), 0);
    damage.dwHitFlags |= 2;
    sub_005D3AC0(pUnit, &damage);
    SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, 128);
    SKILLS_ApplyProgressiveLeechAndElementalDamage(pUnit, &damage);
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);

    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return sub_0056C2D0_DrainTargetDurability(pGame, pUnit, nSkillLevel);
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage)
    {
        sub_005D5220_DischargeProgressiveSkills(pGame, pUnit, pDamage);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}
