struct D2DynamicPathStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; char unk_10[0x1C]; D2DynamicPathStrc* pDynamicPath; };
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2AiControlStrc { char unk_00[0x14]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk_00[0x56]; short wAiParam[8][3]; };
struct D2MonStats2Txt { char unk_00[0xE]; unsigned char nSteps; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk_04[6]; D2MonStatsTxt* pMonstatsTxt; D2MonStats2Txt* pMonstats2Txt; };
struct D2PetInfoStrc { int unk_00[2]; int nHirelingId; };
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc*, int); // 0x00574BD0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005DF530
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc*, D2UnitStrc*, int, int); // 0x00540E60
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
void __fastcall AITHINK_SelectHirelingAction(D2GameStrc*, D2UnitStrc*, int, int, D2UnitStrc*, D2SeedStrc*); // 0x005E4D30
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*, D2UnitStrc*, int); // 0x00622C40
void __stdcall PATH_SetStepNum(D2DynamicPathStrc*, unsigned char); // 0x00649070
int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DED00
static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}
// 0x005E5050
void __fastcall sub_005E5050_RunHirelingAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, D2UnitStrc* pOwner, D2UnitStrc* pTarget, D2SeedStrc* pSeed, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nChance;
    if (nMonsterId == 338 || nMonsterId > 559 && nMonsterId <= 561)
        nChance = 98;
    else
    {
        const int nBaseChance = pAiControl->dwAiParam[0] + 40;
        nChance = nBaseChance + 2 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
        if (nChance >= 95) nChance = 95;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pPetInfo)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    const int nHirelingId = pPetInfo->nHirelingId;
    int bAction = 0;
    if ((int)(RollSeed(pSeed) % 100) < nChance)
    {
        bAction = 1;
        pAiControl->dwAiParam[0] = 0;
    }
    else
        pAiControl->dwAiParam[0] += 10;
    if (!pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (nDistance < 4 && (int)(RollSeed(pSeed) % 100) < 50)
        {
            if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 4)) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 4, 1)) return;
        }
        else if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    if (nDistance < 3 && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);
    AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 1);
}
