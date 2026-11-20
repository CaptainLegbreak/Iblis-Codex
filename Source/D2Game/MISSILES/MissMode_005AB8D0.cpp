#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2MissilesTxt;
struct D2SkillsTxt;
struct D2StaticPathStrc;


struct D2MissilesTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[4];
    char unk0x008[0x06];
    short wSrvHitFunc;
    short wSrvDmgFunc;
    unsigned char unk_12[0x12];
    short wHitSubMissile[4];
    char unk0x2C[0x20];
    int dwHitPar[2];
    char unk0x54[0x54];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned char unk_AE[0xD8];
    unsigned char nCollideKill;
    unsigned char nCollideFriend;
    unsigned char nNextHit;
    unsigned char nNextDelay;
    unsigned char unk0x18A;
    unsigned char nToHit;
    unsigned char nAlwaysExplode;
    char unk0x18D[0x17];
};

struct D2SkillsTxt
{
    char unk0x00[0x64];
    unsigned int dwAuraRangeCalc;
    unsigned char unk_68[0xD0];
    unsigned int dwCalc_0x138;
    char unk0x13C[0x100];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

enum D2C_M11MeteorConstants
{
    MONSTATS2FLAGINDEX_LARGE = 11,
};



struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[26];
};
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nLevel); // 0x004CC7C0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

typedef int (__fastcall* MISSILESRVHITFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);

typedef void (__fastcall* MISSILESRVDMGFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);
extern MISSILESRVHITFN gpfMissileSrvHitFn[]; // 0x0073C840
extern MISSILESRVDMGFN gpfMissileSrvDmgFn_0073C960[]; // 0x0073C960
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD730
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

static __forceinline D2MissilesTxt* MISSILE_GetMissilesTxtRecord_Inline(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return 0;
    }

    const int nMissileId = pMissile->dwClassId;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005AB8D0
int __fastcall sub_005AB8D0(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc_0x138, nSkillId, nSkillLevel);
        if (nRange < 5)
        {
            nRange = 5;
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x8001;
    missileParams.pOwner = pOwner;
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nRange = nRange;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005AAA90
static void __stdcall MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(D2GameStrc* pGame, int nMissileId, int nRange, int nStep, D2UnitStrc* pMissile)
{
    if (nMissileId < 0)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitXInline(pMissile);
    const int nY = CLIENTS_GetUnitYInline(pMissile);

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    const int nSkill = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    if (nRange > 0)
    {
        missileParams.dwFlags = 0x8001;
        missileParams.nRange = nRange;
    }

    missileParams.nSkill = nSkill;
    missileParams.pOwner = pOwner;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    if (nStep < 1)
    {
        nStep = 1;
    }

    for (int i = 0; i < 18; i += nStep)
    {
        missileParams.nX = nX + gnMeteorSubmissileOffsetsX_006E2550[i];
        missileParams.nY = nY + gnMeteorSubmissileOffsetsY_006E2598[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
}

// 0x005AC550
int __fastcall MISSMODE_SrvHit47_MoltenBoulder(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int bValidTarget = 1;
    if (pUnit && (pUnit->dwUnitType != UNIT_MONSTER || !sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_LARGE)))
    {
        bValidTarget = 0;
    }

    if (bValidTarget)
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        int nResult = 1;

        D2DamageStrc damage = {};
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);

        int nRange = pMissilesTxtRecord->dwHitPar[0];
        if (nRange <= 0)
        {
            const int nSkillId = sub_0064A280(pMissile);
            const int nLevel = sub_0064A210(pMissile);
            D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
            if (!pSkillsTxtRecord)
            {
                return 1;
            }

            nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
            if (nRange < 1)
            {
                nRange = 1;
            }
        }

        damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
        damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

        if (!sub_6FD10200(pGame, pOwner, nX, nY, nRange, &damage, 0))
        {
            nResult = 3;
        }

        int nParam = pMissilesTxtRecord->dwHitPar[1];
        if (nParam < 1)
        {
            nParam = 1;
        }

        MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(pGame, pMissilesTxtRecord->wHitSubMissile[0], nRange, nParam, pMissile);
        return nResult;
    }

    return 2;
}

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static int sub_005ADA40_CheckMissileMode(int nMissileMode, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    switch (nMissileMode)
    {
    case 0:
        return 0;
    case 1:
        if (nUnitType != 0)
            return 0;
        break;
    case 2:
        if (nUnitType != 1)
            return 0;
        break;
    case 3:
        break;
    }
    return 1;
}

static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pMissile)
{
    int nResult = 3;
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if ((pTxt->nFlags[0] & gdwBitMasks_006CE268[2]))
    {
        const int nPierce = STATLIST_UnitGetStatValue(pMissile, 0x148, 0);
        if (nPierce)
        {
            STATLIST_SetUnitStat(pMissile, 0x148, nPierce - 1, 0);
            nResult = 2;
        }
    }
    return nResult;
}

// 0x005ADB00
static void __fastcall sub_005ADB00_SetJustHitState(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pTxt->nNextHit || !pUnit)
        return;

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pMissile);
    const int nDelay = pTxt->nNextDelay + pGame->dwGameFrame;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nDelay, pUnit->dwUnitType, pUnit->dwUnitId);
    if (!pStatList)
        return;

    EVENT_SetEvent(pGame, pUnit, 0xC, nDelay, 0, 0);
    STATLIST_SetState(pStatList, 0x56);
    STATLIST_SetStatRemoveCallback(pStatList, MISSMODE_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, 0x56, 1);
}

// 0x005ADCD0
static void __fastcall sub_005ADCD0_ApplyDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    MISSMODE_SetDamageFlags(pGame, pMissile, pUnit, pDamage);
    if (pUnit && pUnit->dwUnitType == 1 && !MONSTERS_GetHirelingTypeId(pUnit))
    {
        const int nDamageTargetAc = STATLIST_UnitGetStatValue(pMissile, 0x78, 0);
        if (nDamageTargetAc)
        {
            int nArmor = nDamageTargetAc + STATLIST_UnitGetStatValue(pUnit, 0x1F, 0);
            if (nArmor < 0)
                nArmor = 0;
            STATLIST_SetUnitStat(pUnit, 0x1F, nArmor, 0);
        }
    }
}

int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int bForceCollision)
{
    D2MissilesTxt* pTxt = 0;
    if (pMissile)
    {
        pTxt = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nHitResult = 2;
    int nPierceFlags = 3;
    if (pTxt->nFlags[0] & gdwBitMasks_006CE268[1])
    {
        nHitResult = 0;
    }

    if (pUnit)
    {
        if ((pTxt->nNextHit && STATES_CheckState(pUnit, 0x56)) || MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        {
            return 1;
        }

        MISSILE_SetOwner(pMissile, pUnit);
        if (!sub_005ADA40_CheckMissileMode(pMissile ? pMissile->dwMissileMode : 0, pUnit))
        {
            return 1;
        }

        if (pOwner && !sub_00554200(pGame, pOwner, pUnit) && !pTxt->nCollideFriend)
        {
            return 1;
        }
    }

    if (pOwner && pUnit && (pTxt->nFlags[0] & gdwBitMasks_006CE268[2])
        && (STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0)))
    {
        nPierceFlags = sub_005ADA80_GetPierceFlags(pMissile);
    }

    if (pTxt->nCollideKill)
    {
        nHitResult |= 1;
    }

    if (pUnit)
    {
        if (pTxt->nToHit)
        {
            int nToHit = 0;
            if (pMissile)
            {
                nToHit = STATLIST_UnitGetStatValue(pMissile, 0x13, 0);
            }

            if (!SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1))
            {
                sub_005ADB00_SetJustHitState(pMissile, pUnit);
                SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
                if (pTxt->nAlwaysExplode)
                {
                    const short nHitFunc = pTxt->wSrvHitFunc;
                    if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
                    {
                        if (gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit) & 4)
                        {
                            return 1;
                        }
                    }
                }
                return 2;
            }
        }
    }
    else if (!bForceCollision && !pTxt->nAlwaysExplode)
    {
        if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
        {
            return 1;
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
        }
        return 2;
    }

    if (nPierceFlags & 2)
    {
        sub_005ADB00_SetJustHitState(pMissile, pUnit);
        SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
        const short nHitFunc = pTxt->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            nHitResult = gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit);
            if (nHitResult & 4)
            {
                return 1;
            }
        }
    }

    if (pUnit && (nHitResult & 2))
    {
        D2DamageStrc tDamage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
        const short nDmgFunc = pTxt->wSrvDmgFunc;
        if (nDmgFunc > 0 && nDmgFunc < gnMissileSrvDmgFnCount_0073C95C)
        {
            gpfMissileSrvDmgFn_0073C960[nDmgFunc](pGame, pMissile, pUnit, &tDamage);
        }
        sub_005ADCD0_ApplyDamageFlags(pGame, pMissile, pUnit, &tDamage);
    }

    if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (pRoom)
    {
        COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
    }
    return 2;
}
