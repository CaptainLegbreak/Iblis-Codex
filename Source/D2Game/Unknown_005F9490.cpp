#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

extern "C" int __cdecl abs(int);
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2AiControlStrc { char unk_00[0x14]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk_00[0x56]; short wAiParam[8][3]; char unk_86[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk_04; D2UnitStrc* pTarget; int unk_0C[2]; int nTargetDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*, D2UnitStrc*); // 0x00620C10
unsigned char __stdcall UNITS_GetDirectionToCoords(D2UnitStrc*, int, int); // 0x00621DC0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc*, int); // 0x006488A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
extern const unsigned char gnDirectionMap_006E3540[]; // 0x006E3540
extern const unsigned char gnDirectionAxis_006E353C[]; // 0x006E353C
// build: context CLIENTS_GetUnitXInline
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

// build: context CLIENTS_GetUnitYInline
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

// build: context AI_RollPercentage
static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}
#define AI_PARAM(n) pMonStatsTxt->wAiParam[n][pGame->nDifficulty]
// build: context ABS_VALUE
static __forceinline int ABS_VALUE(int n) { return n < 0 ? -n : n; }
// 0x005F9490
void __fastcall sub_005F9490_ThinkAxisCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[0] > 0)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiControl->dwAiParam[0]);
        pAiControl->dwAiParam[0] = 0;
        return;
    }
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    const int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const int nTargetY = CLIENTS_GetUnitYInline(pTarget);
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    int nX = nTargetX;
    int nY = nTargetY;
    if (ABS_VALUE(nTargetX - nUnitX) < ABS_VALUE(nTargetY - nUnitY))
    {
        nX = nUnitX;
    }
    else
    {
        nY = nUnitY;
    }
    const unsigned char nDirection = UNITS_GetDirectionToCoords(pUnit, nX, nY);
    sub_006488A0_SetDirection(pUnit->pDynamicPath, gnDirectionAxis_006E353C[gnDirectionMap_006E3540[nDirection]]);
    if ((ABS_VALUE(nTargetX - nUnitX) < 6 || ABS_VALUE(nTargetY - nUnitY) < 6)
        && pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < AI_PARAM(0) && AI_RollPercentage(pUnit) < AI_PARAM(1))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        pAiControl->dwAiParam[0] = AI_PARAM(2);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(3));
}

#include "gen/data/Source/D2Game/Unknown_005F9490.inc"
