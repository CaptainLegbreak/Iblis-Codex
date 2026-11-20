#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Path.h"


#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
struct D2MissilesTxt;
struct D2PathPointStrc;
struct D2MissileUnitFindTableStrc;
struct D2MissileFindArgStrc;
struct D2SkillsTxt;
struct D2StaticPathStrc;
union D2SeedStrc;





struct D2MissileFindArgStrc { D2GameStrc* pGame; D2UnitStrc* pMissile; D2UnitStrc* pOwner; D2MissilesTxt* pMissilesTxtRecord; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2MissileUnitFindTableStrc gtMissileCollisionModes[]; // 0x0073C720
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __fastcall SUNIT_UpdateUnitPath(D2GameStrc*, D2UnitStrc*); // 0x00554CA0
int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005ADF10
int __stdcall PATH_GetVelocity(D2DynamicPathStrc*); // 0x006486C0
int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc*, int); // 0x0064A330
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned short __stdcall D2Common_10201(D2DynamicPathStrc*); // 0x00648EB0
int __stdcall MISSILE_GetActivateFrame(D2UnitStrc*); // 0x0064A640
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc*, D2PathPointStrc**); // 0x00648F40
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*, int, int, int, int); // 0x0064D9B0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc*, int, int, void*, void*, int); // 0x00641CB0


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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
D2UnitStrc* __fastcall MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int nMissileId, int nRange, int nLoops); // 0x005A9720
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE1F0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath); // 0x006505C0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x00553490
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3); // 0x00649970
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __fastcall sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel); // 0x0056D810
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40


int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB90
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
int __fastcall MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AF540
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
int __fastcall MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE780
void __fastcall ACT5Q6_SpawnTyrael(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMissile); // 0x0058E920
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId); // 0x005444B0
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

static D2MissilesTxt* GetMissilesTxt(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}

// 0x005AE1F0
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxt(pMissile);
    if (!pMissilesTxtRecord) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    if (PATH_GetVelocity(pMissile->pDynamicPath) && SUNIT_UpdateUnitPath(pGame, pMissile) == 2)
        return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    const int nFrame = MISSILE_GetCurrentFrame(pMissile) - 1;
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    if (nFrame <= 0) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    const int nMode = pMissile->dwAnimMode;
    if (nMode)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        if (!pRoom || !pPath) return 2;
        unsigned short nCollision = D2Common_10201(pPath);
        if (nCollision & 5) return 2;
        if (nMode != 6 && MISSILE_GetCurrentFrame(pMissile) <= MISSILE_GetActivateFrame(pMissile) && nCollision)
        {
            if (!gtMissileCollisionModes[nMode].pfUnitFindCallback) return 2;
            D2MissileFindArgStrc tFindArg;
            tFindArg.pGame = pGame;
            tFindArg.pMissile = pMissile;
            tFindArg.pOwner = SUNIT_GetOwner(pGame, pMissile);
            tFindArg.pMissilesTxtRecord = pMissilesTxtRecord;
            const int nSize = UNITS_GetUnitSizeX(pMissile);
            D2PathPointStrc* pPoints;
            const int nPoints = D2COMMON_10198_PathGetSaveStep(pPath, &pPoints);
            for (int i = 0; i < nPoints; ++i)
            {
                const int nX = pPoints[i].X;
                const int nY = pPoints[i].Y;
                nCollision = COLLISION_CheckMaskWithSize(pRoom, nX, nY, nSize, gtMissileCollisionModes[nMode].nCollisionMask);
                if (nCollision)
                {
                    D2UnitStrc* pTarget = D2Common_10407(pRoom, nX, nY, gtMissileCollisionModes[nMode].pfUnitFindCallback, &tFindArg, nSize);
                    if (pTarget) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, pTarget, 0);
                    if (nCollision & 4)
                    {
                        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
                        return 2;
                    }
                }
            }
        }
    }
    return 1;
}

#include "gen/data/Source/D2Game/Unknown_005AE1F0.inc"

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

        if (pTarget && !(MISSILE_GetCurrentFrame(pMissile) % nParam))
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

        if (!(MISSILE_GetCurrentFrame(pMissile) % nFrames) && sub_006416D0_UnitEdgeDistance(pMissile, pTarget) <= pMissilesTxtRecord->dwParam[1])
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

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005AE480
int __fastcall MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (pMissile->pDynamicPath && PATH_GetVelocity(pMissile->pDynamicPath))
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    COLLISION_SetMask(UNITS_GetRoom(pMissile), CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), 0x40);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005AE940
int __fastcall MISSMODE_SrvDo09_BatLightningBolt(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissileStrc missileParams;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord && pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    const int nX = UNITS_InlineGetXPosition(pMissile);
    const int nY = UNITS_InlineGetYPosition(pMissile);
    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF590
int __fastcall MISSMODE_SrvDo21_Distraction(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    if (pMissilesTxtRecord->wSubMissile[0] && sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    return MISSMODE_SrvDo20_BladeCreeper(pGame, pMissile);
}

// 0x005AF980
int __fastcall MISSMODE_SrvDo26_Vines_PlagueVines(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] == 0)
    {
        return 2;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    const int nParam = pMissilesTxtRecord->dwParam[0] >= 1 ? pMissilesTxtRecord->dwParam[0] : 1;

    if (!(nFrames % nParam))
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
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

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static void sub_005A99E0_MISSMODE_PlacePathAtOwner(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (pOwner && pPath)
    {
        sub_00650BE0_PlaceUnit(pPath, pMissile, UNITS_GetRoom(pOwner), UNITS_GetXPositionInline(pOwner), UNITS_GetYPositionInline(pOwner));
    }
}

// 0x005B0010
int __fastcall sub_005B0010_MISSMODE_SrvDo(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(MISSILE_GetSkill(pMissile));
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, MISSILE_GetTargetX(pMissile), MISSILE_GetTargetY(pMissile));
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pTarget || !pOwner || SUNIT_IsDead(pOwner) || MISSILE_GetCurrentFrame(pMissile) < 0)
    {
        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
        return 2;
    }

    sub_005A99E0_MISSMODE_PlacePathAtOwner(pGame, pMissile);

    const int nFrames = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (!(sub_0064A3B0_GetElapsedFrames(pMissile) % nFrames))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.pOwner = pTarget;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

        const int nRange = pMissilesTxtRecord->dwParam[1];
        missileParams.nTargetX = SEED_RollLimitedRandomNumber(&pTarget->pSeed, 2 * nRange + 1) - nRange;
        missileParams.nTargetY = SEED_RollLimitedRandomNumber(&pTarget->pSeed, 2 * nRange + 1) - nRange;

        D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pSkillsTxtRecord->wAuraTargetState > 0)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pOwner, pSkillsTxtRecord->wAuraTargetState);
            if (pSubMissile && pStatList)
            {
                MISSILE_SetTargetX(pSubMissile, D2COMMON_10473(pStatList));
            }
        }
    }

    MISSMODE_HandleMissileCollision(pGame, pMissile);
    return 1;
}

// 0x005B03E0
int __fastcall MISSMODE_SrvDo32_TigerFury(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 1;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(pGame, pMissile);
}

// 0x005B0A40
int __fastcall MISSMODE_SrvDo36_BaalFxControl(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    const int nFrame = MISSILE_GetCurrentFrame(pMissile);
    if (!MISSILE_GetTargetX(pMissile) && nFrame <= 100)
    {
        MISSILE_SetTargetX(pMissile, 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (QUESTS_CheckNotIntroQuest(pGame, 36))
        {
            ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
        }

        DUNGEON_ToggleHasPortalFlag(pRoom, 1);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005B0AA0
int __fastcall sub_005B0AA0(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    if (pMissilesTxtRecord->wSubMissile[0] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile),
                                      pMissilesTxtRecord->wSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    if (pMissilesTxtRecord->wSubMissile[1] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[1])
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile),
                                      pMissilesTxtRecord->wSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    if (pMissilesTxtRecord->wSubMissile[2] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[2])
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile),
                                      pMissilesTxtRecord->wSubMissile[2], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}
