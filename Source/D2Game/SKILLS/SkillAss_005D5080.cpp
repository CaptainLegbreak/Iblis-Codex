#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#ifdef MOVED_TEST
#define BURST_CENTER 22
#define MISSILE_FLAGS 7
#else
#define BURST_CENTER 20
#define MISSILE_FLAGS 3
#endif
struct D2GameStrc;
typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                       // 0x005D3CF0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);       // 0x005D3DA0
static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}
static unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
// 0x005D5080
int __fastcall sub_005D5080_CreateMissileBurst(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, SEED_RollRandomNumberInline(&pUnit->pSeed));
    if (!SKILLS_GetSkillsTxtRecordInline(nSkillId)) return 0;
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY)) return 0;
    const int nMissile = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissile <= 0) return 0;
    const int nCount = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nCount) return 0;
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nX;
    tMissileParams.dwFlags = MISSILE_FLAGS;
    tMissileParams.nY = nY;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetX = SEED_RollRandomNumberInline(&tSeed) % 40 - BURST_CENTER;
        tMissileParams.nTargetY = SEED_RollRandomNumberInline(&tSeed) % 40 - BURST_CENTER;
        if (!tMissileParams.nTargetX && !tMissileParams.nTargetY) tMissileParams.nTargetX = BURST_CENTER;
        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &tMissileParams);
        if (pMissile)
        {
            MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(&tSeed));
            MISSILE_SetTargetY(pMissile, ((unsigned short)tMissileParams.nTargetY << 16) + (unsigned short)tMissileParams.nTargetX);
        }
    }
    return 1;
}
