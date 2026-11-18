// Functional replacement for the function at 0x005EDC50, not the original code: only the ordinary build (tools/link.py) uses it.

struct D2SeedStrc { unsigned int nLowSeed,nHighSeed; };
struct D2PathRecordStrc { char pad[0xC]; int nX,nY; };
struct D2UnitStrc { int dwUnitType; char pad04[0x1C]; D2SeedStrc pSeed; int pad28; D2PathRecordStrc* pPath; char pad30[0xA0]; int nNodeIndex; };
struct D2GameStrc { char pad00[0x6D]; unsigned char nDifficulty; };
struct D2MonStatsTxt { char pad00[0x56]; short wAiParam[8][3]; };
struct D2AiTickParamStrc { void* pAiControl; int unk04; D2UnitStrc* pTarget; int unk0C[2]; int nTargetDistance,bCombat; D2MonStatsTxt* pMonstatsTxt; };
void __fastcall sub_005B1990_AddTargetNode(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*,D2UnitStrc*,int); // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc*,D2UnitStrc*,int); // 0x005DE0F0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*,int,int,unsigned char); // 0x005DE190
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x005DED20
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc*,D2UnitStrc*,int,int); // 0x005DEE50
int __stdcall PATH_GetX(D2PathRecordStrc*); // 0x006488C0
int __stdcall PATH_GetY(D2PathRecordStrc*); // 0x00648900
static __forceinline unsigned int RollSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}
static __forceinline void RollSeedFromHalves(D2UnitStrc* pUnit, unsigned int nLow, unsigned int nHigh, unsigned int& nNextLow, unsigned int& nNextHigh)
{
    const unsigned __int64 lSeed = nHigh + 0x6AC690C5i64 * nLow;
    nNextHigh = (unsigned int)(lSeed >> 32);
    nNextLow = (unsigned int)lSeed;
    pUnit->pSeed.nHighSeed = nNextHigh;
    pUnit->pSeed.nLowSeed = nNextLow;
}
static __forceinline void RollSeedHalves(D2UnitStrc* pUnit, unsigned int& nLow, unsigned int& nHigh)
{
    RollSeedFromHalves(pUnit, pUnit->pSeed.nLowSeed, pUnit->pSeed.nHighSeed, nLow, nHigh);
}
static __forceinline int UnitX(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pPath->nX;
    default: return pUnit->pPath ? PATH_GetX(pUnit->pPath) : 0;
    }
}
static __forceinline int UnitY(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pPath->nY;
    default: return pUnit->pPath ? PATH_GetY(pUnit->pPath) : 0;
    }
}
#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])
// 0x005EDC50
void __fastcall sub_005EDC50_ThinkWander(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pTick)
{
    int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    int nDistance = pTick->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pTick->pMonstatsTxt;
    if (pUnit->nNodeIndex == 11) sub_005B1990_AddTargetNode(pGame,pUnit,0,8);
    if (pTarget)
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,4,pTarget);
            AITACTICS_Idle(pGame,pUnit,AI_PARAM(0));
            return;
        }
        if (nDistance < AI_PARAM(2) && (int)(RollSeed(pUnit) % 100) < AI_PARAM(1))
        {
            AITACTICS_SetVelocity(pUnit,0,100,0);
            AITACTICS_RunToTargetUnit(pGame,pUnit,pTarget);
            return;
        }
    }
    const int nX = UnitX(pUnit);
    const int nY = UnitY(pUnit);
    unsigned int nRollX, nHighX;
    unsigned int nRollY, nHighY;
    RollSeedHalves(pUnit, nRollX, nHighX);
    RollSeedFromHalves(pUnit, nRollX, nHighX, nRollY, nHighY);
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pUnit,nX + (int)(nRollX % 20) - 40,nY + (int)(nRollY % 20) - 10)) return;
    unsigned int nDirectionLow, nDirectionHigh;
    RollSeedHalves(pUnit, nDirectionLow, nDirectionHigh);
    const int bDirection = nDirectionLow & 1;
    RollSeedFromHalves(pUnit, nDirectionLow, nDirectionHigh, nRollX, nHighX);
    RollSeedFromHalves(pUnit, nRollX, nHighX, nRollY, nHighY);
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pUnit,nX + (int)(nRollX % 20) - 10,-30 * (bDirection ? 1 : -1) + (int)(nRollY % 20) + nY - 10)) return;
    RollSeedHalves(pUnit, nRollX, nHighX);
    RollSeedFromHalves(pUnit, nRollX, nHighX, nRollY, nHighY);
    if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pUnit,nX + (int)(nRollX % 20) - 10,-30 * (!bDirection ? 1 : -1) + (int)(nRollY % 20) + nY - 10))
        AITACTICS_IdleInNeutralMode(pGame,pUnit,15);
}
