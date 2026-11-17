struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

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
    char unk0x08[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MissilesTxt
{
    char pad0x00[0x38];
    int dwParam[5];
    char pad0x4C[0x158];
};

struct D2DataTablesStrc
{
    char pad0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char pad0xB68[0x04];
    int nMissilesTxtRecordCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

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

struct D2HitFunc22ParamStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkillId;
    int nLevel;
    int nParam;
    int nHitSubMissile;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                              // 0x0061AED0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_TOHIT 19

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

// build: symbol ?xOffsets@?7??MISSMODE_CreatePantherPotGreenSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHH@Z@4QBHB 0x006E2618
// build: symbol ?xOffsets@?BB@??MISSMODE_CreatePoisonCloudHitSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHHHH@Z@4QBHB 0x006E2510
// build: symbol ?yOffsets@?7??MISSMODE_CreatePantherPotGreenSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHH@Z@4QBHB 0x006E25F8
// build: symbol ?yOffsets@?BB@??MISSMODE_CreatePoisonCloudHitSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHHHH@Z@4QBHB 0x006E24D0
// 0x005A88E0
int __fastcall sub_005A88E0_RollMissileHit(D2UnitStrc* pMissile, int nUnused, D2UnitStrc* pOwner, D2UnitStrc* pUnit)
{
    int nToHit = 0;
    if (pMissile)
    {
        nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
    }

    return SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1) != 0;
}

// 0x005A9370
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pOwner || !pOrigin)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x17;
    if (nLoops > 0)
    {
        missileParams.dwFlags = 0x1F;
        missileParams.nLoops = nLoops;
    }

    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPosition(pOrigin);
    missileParams.nY = CLIENTS_GetUnitY(pOrigin);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    if (nMainStep < 1)
    {
        nMainStep = 1;
    }

    static const int xOffsets[16] = { 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1 };
    static const int yOffsets[16] = { 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 2 };

    for (int i = 0; i < 16; i += nMainStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (nSubStep)
    {
        missileParams.nVelocity = pMissilesTxtRecord->dwParam[1] << 7;

        for (int i = 0; i < 15; i += nSubStep)
        {
            missileParams.nTargetX = xOffsets[i + 1];
            missileParams.nTargetY = yOffsets[i + 1];
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }

    return 1;
}

// 0x005A9930
void __fastcall sub_005A9930_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam)
{
    MISSILE_SetTargetX(pMissile, 1);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    D2GAME_CreatePortalObject_6FD13DF0(pGame, pOwner, UNITS_GetRoom(pMissile), UNITS_GetXPositionInline(pMissile), UNITS_GetYPositionInline(pMissile), nParam, 0, 60, 1);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pMissile), 1);
}

// 0x005AB2A0
int __fastcall MISSMODE_LightningFury_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget)
{
    D2HitFunc22ParamStrc* pParams = (D2HitFunc22ParamStrc*)pAuraCallback->pArgs;
    if (pAuraCallback->nCounter >= pParams->nParam)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pParams->pOwner;
    missileParams.pOrigin = pParams->pOrigin;
    missileParams.nSkill = pParams->nSkillId;
    missileParams.nSkillLevel = pParams->nLevel;
    missileParams.nMissile = pParams->nHitSubMissile;
    missileParams.nTargetX = UNITS_GetXPositionInline(pTarget);
    missileParams.nTargetY = UNITS_GetYPositionInline(pTarget);
    MISSILES_CreateMissileFromParams(pAuraCallback->pGame, &missileParams);

    return 1;
}

// 0x005AB630
int __fastcall MISSMODE_FistOfTheHeavensDelay_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget)
{
    D2HitFunc22ParamStrc* pParams = (D2HitFunc22ParamStrc*)pAuraCallback->pArgs;
    if (pParams->nParam > 0 && pAuraCallback->nCounter >= pParams->nParam)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pParams->pOwner;
    missileParams.pOrigin = pParams->pOrigin;
    missileParams.nSkill = pParams->nSkillId;
    missileParams.nSkillLevel = pParams->nLevel;
    missileParams.nMissile = pParams->nHitSubMissile;
    missileParams.nTargetX = UNITS_GetXPositionInline(pTarget);
    missileParams.nTargetY = UNITS_GetYPositionInline(pTarget);
    MISSILES_CreateMissileFromParams(pAuraCallback->pGame, &missileParams);

    return 1;
}

// 0x005AB700
int __fastcall MISSMODE_CreatePantherPotGreenSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nStep)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x1F;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPositionInline(pOrigin);
    missileParams.nY = UNITS_GetYPositionInline(pOrigin);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = nSkillLevel - 1;
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    static const int xOffsets[8] = { 0, 2, 2, 2, 0, -2, -2, -2 };
    static const int yOffsets[8] = { 2, 2, 0, -2, -2, -2, 0, 2 };

    for (int i = 0; i < 8; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}
