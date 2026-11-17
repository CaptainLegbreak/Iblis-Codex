struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2MissilesTxt
{
    char unk0x00[0x18];
    short wSubMissile[3];
    char unk0x1E[0x18];
    short wProgOverlay;
    int dwParam[5];
    char unk0x4C[0x34];
    unsigned int dwSrvCalc;
    char unk0x84[0x24];
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    char unk0xAE[0xF6];
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    char unk0x054[0x10];
    unsigned int dwAuraRangeCalc;
    char unk0x068[0xD0];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
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
    int unk0x38[9];
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

#define STAT_HITPOINTS 6
#define STAT_MANA 8

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnSrvDo15_XPositions_006E2B78[64];                                                         // 0x006E2B78
extern const int gnSrvDo15_YPositions_006E2A78[64];                                                         // 0x006E2A78

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
D2UnitStrc* __fastcall MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int nMissileId, int nRange, int nLoops); // 0x005A9720
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile);                   // 0x005AE1F0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pMissile);                                      // 0x00553490
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                    // 0x00554200
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __fastcall sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel); // 0x0056D810
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

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

// 0x005AE400
int __fastcall MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->wSubMissile[0] >= 0)
        {
            MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(pGame, pMissile, pMissilesTxtRecord->wSubMissile[0], 0, MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwSrvCalc, nMissileId, MISSILE_GetLevel(pMissile)));
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AE680
int __fastcall MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pMissile)
    {
        return 2;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0 || !pMissile->pDynamicPath)
    {
        return 2;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pOwner;
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AE780
int __fastcall MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pMissile)))
    {
        return 2;
    }

    if (MISSILE_GetTargetX(pMissile) & 1)
    {
        sub_6FCBC7E0(pGame, pMissile);

        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pMissile);
        if (pTarget && (SUNIT_IsDead(pTarget) || !sub_00554200(pGame, pOwner, pTarget)))
        {
            pTarget = 0;
        }

        int nParam = pMissilesTxtRecord->dwParam[0];
        if (nParam <= 0)
        {
            nParam = 5;
        }

        if (pTarget && !(sub_0064A380_GetRemainingFrames(pMissile) % nParam))
        {
            const int nDistance = sub_006416D0_UnitEdgeDistance(pMissile, pTarget);
            if (nDistance > 3 && nDistance < 25)
            {
                D2Common_10142(pPath, pMissile, 0);
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AEB60
int __fastcall MISSMODE_SrvDo11_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pMissile);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pTarget && pOwner)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pOwner);
    }

    if (pTarget)
    {
        int nFrames = pMissilesTxtRecord->dwParam[0];
        if (nFrames <= 0)
        {
            nFrames = 5;
        }

        if (!(sub_0064A380_GetRemainingFrames(pMissile) % nFrames) && sub_006416D0_UnitEdgeDistance(pMissile, pTarget) <= pMissilesTxtRecord->dwParam[1])
        {
            const int nMissileX = CLIENTS_GetUnitX(pMissile);
            const int nMissileY = CLIENTS_GetUnitY(pMissile);
            const int nTargetX = CLIENTS_GetUnitX(pTarget);
            const int nTargetY = CLIENTS_GetUnitY(pTarget);

            int nParam = pMissilesTxtRecord->dwParam[2];
            if (nParam < 1)
            {
                nParam = 1;
            }

            int nX = 0;
            int nY = 0;
            if (nTargetX > nMissileX)
            {
                nX = nParam;
            }
            else if (nTargetX < nMissileX)
            {
                nX = -nParam;
            }

            if (nTargetY > nMissileY)
            {
                nY = nParam;
            }
            else if (nTargetY < nMissileY)
            {
                nY = -nParam;
            }

            D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, nX + CLIENTS_GetUnitX(pMissile), nY + CLIENTS_GetUnitY(pMissile));
            D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AECA0
int __fastcall MISSMODE_SrvDo12_DiabWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    if (!SUNIT_GetOwner(pGame, pMissile))
    {
        return 2;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AEF70
int __fastcall MISSMODE_SrvDo14_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nParam = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nParam)
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    if (nSkillId > 0 && nLevel > 0)
    {
        sub_6FD14400(pGame, pMissile, pMissilesTxtRecord->dwParam[1], nSkillId, nLevel);
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    return 2;
}

// 0x005AF030
int __fastcall MISSMODE_SrvDo15_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 2;
    }

    const int nFrames = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrames > 0)
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];

    int nIndex = MISSILE_GetTargetX(pMissile) % 64;
    nIndex = nIndex < 0 ? -nIndex : nIndex;
    missileParams.nTargetX = gnSrvDo15_XPositions_006E2B78[nIndex];
    missileParams.nTargetY = gnSrvDo15_YPositions_006E2A78[nIndex];
    MISSILE_SetTargetX(pMissile, (nIndex + pMissilesTxtRecord->dwParam[1]) % 64);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF620
int __fastcall MISSMODE_SrvDo22_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    D2DynamicPathStrc* pPath;
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wSubMissile[0] || (pPath = pMissile->pDynamicPath) == 0)
    {
        return 2;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    if (sub_0064A3B0_GetElapsedFrames(pMissile) < 2)
    {
        const int nParam1 = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath) - nX;
        const int nParam2 = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath) - nY;
        MISSILE_SetTargetX(pMissile, -nParam2);
        MISSILE_SetTargetY(pMissile, nParam1);
    }

    if (sub_006505C0_TestPathFlag8(pPath))
    {
        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 11;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nLoops = pMissilesTxtRecord->dwParam[0];
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nTargetX = MISSILE_GetTargetX(pMissile);
        missileParams.nTargetY = MISSILE_GetTargetY(pMissile);
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
        missileParams.nTargetX = -MISSILE_GetTargetX(pMissile);
        missileParams.nTargetY = -MISSILE_GetTargetY(pMissile);
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF790
int __fastcall MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wSubMissile[0])
    {
        return 2;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 1;
        if (pMissilesTxtRecord->dwParam[0] > 0)
        {
            missileParams.dwFlags = 9;
            missileParams.nLoops = pMissilesTxtRecord->dwParam[0];
        }

        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = CLIENTS_GetUnitX(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AFA30
int __fastcall MISSMODE_SrvDo27_Tornado(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nParam0 = pMissilesTxtRecord->dwParam[0];
    if (nParam0 <= 0)
    {
        nParam0 = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nParam0 < 1)
        {
            nParam0 = 1;
        }
    }

    if (!(nFrames % nParam0))
    {
        D2DamageStrc damage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, 0, &damage);

        int nParam1 = pMissilesTxtRecord->dwParam[1];
        if (nParam1 <= 0)
        {
            nParam1 = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
            if (nParam1 < 1)
            {
                nParam1 = 1;
            }
        }

        damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
        damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
        sub_6FD10200(pGame, pMissile, 0, 0, nParam1, &damage, pSkillsTxtRecord->dwAuraFilter);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// build: context MISSMODE_SrvDo29_RecyclerDelay
int __fastcall MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner && !SUNIT_IsDead(pOwner))
    {
        const int nLevel = MISSILE_GetLevel(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
        {
            int nHitpoints = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0) >> 8;
            const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pOwner) >> 8;
            if (nHitpoints < nMaxHp)
            {
                nHitpoints += DATATBLS_ApplyRatio(nMaxHp, SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel), 100);
                if (nHitpoints >= nMaxHp)
                {
                    nHitpoints = nMaxHp;
                }

                STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nHitpoints << 8, 0);

                if (pMissilesTxtRecord->wProgOverlay > 0 && pMissilesTxtRecord->wProgOverlay < sgptDataTables->nOverlayTxtRecordCount)
                {
                    UNITS_SetOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 0);
                }
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// build: context MISSMODE_SrvDo33_VineRecyclerDelay
int __fastcall MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner && !SUNIT_IsDead(pOwner))
    {
        const int nLevel = MISSILE_GetLevel(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
        {
            int nMana = STATLIST_UnitGetStatValue(pOwner, STAT_MANA, 0) >> 8;
            const int nMaxMana = STATLIST_GetMaxManaFromUnit(pOwner) >> 8;
            if (nMana < nMaxMana)
            {
                nMana += DATATBLS_ApplyRatio(nMaxMana, SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel), 100);
                if (nMana >= nMaxMana)
                {
                    nMana = nMaxMana;
                }

                STATLIST_SetUnitStat(pOwner, STAT_MANA, nMana << 8, 0);

                if (pMissilesTxtRecord->wProgOverlay > 0 && pMissilesTxtRecord->wProgOverlay < sgptDataTables->nOverlayTxtRecordCount)
                {
                    UNITS_SetOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 0);
                }
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

#include "gen/data/Source/D2Game/005AE400_MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap.inc"
