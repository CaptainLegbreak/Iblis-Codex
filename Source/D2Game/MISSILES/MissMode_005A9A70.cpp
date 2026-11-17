#include "D2Game.h"

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char pad0x000[0x24];
    short wHitSubMissile[4];
    char pad0x02C[0x20];
    int dwHitPar[3];
    char pad0x058[0x50];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char pad0x0AE[0xD8];
    unsigned char nCollideKill;
    char pad0x187[0x1D];
};

struct D2SkillsTxt
{
    char pad0x000[0x50];
    int dwAuraFilter;
    char pad0x054[0x0C];
    int dwAuraLenCalc;
    int dwAuraRangeCalc;
    char pad0x068[0x1A];
    short wAuraTargetState;
    char pad0x084[0xB4];
    int dwCalc[4];
    char pad0x148[0xF4];
};

struct D2DataTablesStrc
{
    char pad0x000[0xC4];
    int nStatesTxtRecordCount;
    char pad0x0C8[0xA9C];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
    char pad0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char pad0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[26];
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);
typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit);             // 0x00554DE0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x0056E900
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops); // 0x005A9370
int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70
void __fastcall sub_005A8F20_SetElementalLength(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength); // 0x005A8F20
int __fastcall MISSMODE_SrvHit44_ExplodingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x005A9E10
int __fastcall MISSMODE_CreatePantherPotGreenSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nStep); // 0x005AB700
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_HITPOINTS 6
#define EVENTTYPE_REMOVESTATE 12

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: symbol ?xOffsets@?L@??sub_005ABC40@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2938
// build: symbol ?xOffsets@?O@??MISSMODE_SrvHit29_FrozenOrb@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2738
// build: symbol ?yOffsets@?L@??sub_005ABC40@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2838
// build: symbol ?yOffsets@?O@??MISSMODE_SrvHit29_FrozenOrb@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2638
// 0x005A9A70
int __fastcall MISSMODE_SrvHit01_Fireball_ExplodingArrow_FreezingArrowExplosion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    sub_6FD10200(pGame, pOwner, nX, nY, nParam, &damage, 0);
    return 1;
}

// 0x005A9D80
int __fastcall MISSMODE_SrvHit02_PlagueJavelin_PoisonPotion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 3;
    }

    D2UnitStrc* pOrigin = pUnit;
    if (!pUnit)
    {
        pOrigin = pMissile;
    }

    MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, SUNIT_GetOwner(pGame, pMissile), pOrigin, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1], pMissilesTxtRecord->dwHitPar[2]);
    return 3;
}

// 0x005A9F90
int __fastcall MISSMODE_SrvHit03_ExplosivePotion_BombOnGround(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return MISSMODE_SrvHit44_ExplodingJavelin(pGame, pMissile, 0);
    }

    return 0;
}

// 0x005AA8B0
int __fastcall MISSMODE_SrvHit13_GlacialSpike_HellMeteorDown(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nLength = pMissilesTxtRecord->dwHitPar[1];
    if (nLength <= 0)
    {
        nLength = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);

    if (nLength > 0)
    {
        sub_005A8F20_SetElementalLength(pGame, pMissile, pUnit, &damage, nLength);
    }

    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

    if (sub_6FD10200(pGame, SUNIT_GetOwner(pGame, pMissile), nX, nY, nRange, &damage, 0))
    {
        return 1;
    }

    return 3;
}

// 0x005AAD40
int __fastcall MISSMODE_SrvHit15_SpiderGooLay(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pOwner;
    missileParams.nX = UNITS_GetXPosition(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    return 0;
}

// 0x005AAE10
int __fastcall MISSMODE_SrvHit16_SpiderGoo_VinesTrail_VinesWither(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nLength = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
    if (nLength < 5)
    {
        nLength = 5;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        const int nOwnerId = pOwner->dwUnitId;
        const int nOwnerType = pOwner->dwUnitType;
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nLength + pGame->dwGameFrame, nOwnerType, nOwnerId);
        if (!pNewStatList)
        {
            return 1;
        }

        STATLIST_SetState(pNewStatList, pSkillsTxtRecord->wAuraTargetState);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pNewStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    }

    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    D2COMMON_10476(pStatList, nLength + pGame->dwGameFrame);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nLength + pGame->dwGameFrame, 0, 0);
    return 0;
}

// 0x005AB0B0
int __fastcall MISSMODE_SrvHit18_Shout_BattleCommand_BattleOrders(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pUnit && SUNIT_AreUnitsAligned(pGame, pOwner, pUnit))
    {
        SKILLS_ApplyWarcryStats(pGame, pUnit, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    return 0;
}

// 0x005AB110
int __fastcall MISSMODE_SrvHit19_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nLength = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    if (nLength < 5)
    {
        nLength = 5;
    }

    const int nTimeout = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        const int nOwnerId = pOwner->dwUnitId;
        const int nOwnerType = pOwner->dwUnitType;
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nTimeout, nOwnerType, nOwnerId);
        if (!pNewStatList)
        {
            return 1;
        }

        STATLIST_SetState(pNewStatList, pSkillsTxtRecord->wAuraTargetState);
        STATLIST_SetStatRemoveCallback(pNewStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pNewStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    }

    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    D2COMMON_10476(pStatList, nTimeout);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nTimeout, 0, 0);
    return 3;
}

// 0x005AB500
int __fastcall MISSMODE_SrvHit21_BattleCry(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (nAuraFilter)
    {
        nAuraFilter = 0xA783;
    }

    if (!sub_6FD0FA00(pOwner, pUnit, nAuraFilter))
    {
        return 1;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = 0;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (pStatList)
    {
        sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    }

    return 0;
}

// 0x005AB820
int __fastcall MISSMODE_SrvHit25_PantherPotGreen(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        pUnit = pMissile;
    }

    int nHitPar = pMissilesTxtRecord->dwHitPar[0];
    if (nHitPar < 1)
    {
        nHitPar = 1;
    }

    MISSMODE_CreatePantherPotGreenSubmissiles(pGame, pOwner, pUnit, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nHitPar);
    return 3;
}

// 0x005ABB00
int __fastcall MISSMODE_SrvHit29_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (sub_0064A380_GetRemainingFrames(pMissile))
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    static const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nParam)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, xOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, yOffsets[i]);
        }
    }

    return 3;
}

// 0x005ABC40
int __fastcall sub_005ABC40(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    static const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nParam)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, xOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, yOffsets[i]);
        }
    }

    return 3;
}

// 0x005ABD70
int __fastcall MISSMODE_SrvHit31_FireHead(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    D2DamageStrc damage = {};
    const int nDamage = MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    const int nHeal = nDamage < 0 ? 0 : nDamage;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pOwner);
    const int nHp = nHeal + STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
    const int nNewHp = nHp < nMaxHp ? nHp : nMaxHp;
    STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nNewHp, 0);

    if (pMissilesTxtRecord->nCollideKill)
    {
        return 3;
    }

    return 2;
}

// 0x005ABF70
int __fastcall MISSMODE_SrvHit36_MissileInAir(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pUnit)
    {
        return 0;
    }

    D2UnitStrc* pHitSubMissile = D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wHitSubMissile[0], UNITS_GetXPosition(pMissile), CLIENTS_GetUnitY(pMissile));
    if (pHitSubMissile)
    {
        MISSILE_SetTargetX(pHitSubMissile, MISSILE_GetTargetX(pMissile));
    }

    return 1;
}
