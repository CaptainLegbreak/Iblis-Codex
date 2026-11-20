#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2Path.h"

struct D2DifficultyLevelsTxt;
struct D2SkillsTxt;
struct D2UnkNecSkillStrc;
struct D2UnkNecSkillStrc3;
struct D2CurseStrc;
struct D2MonsterDataStrc;
union D2SeedStrc;
struct D2NecroSkeletonComponentStrc;
struct D2StaticPathStrc;
struct D2SummonArgStrc;
struct D2MonStatsTxt;

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
static __declspec(noinline) int sub_005C3300_CorpseConsumedCheck(D2UnitStrc* pUnit);

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x1C];
    int dwAiCurseDiv;
};

struct D2UnkNecSkillStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int unk0x08;
    int bUpdateAnimRate;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalc[6];
    int nAuraTargetState;
    int nAuraEvent[3];
    int nAuraEventFunc[3];
};

struct D2UnkNecSkillStrc3
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
    unsigned char nUnitType;
    unsigned char pad0x11;
    unsigned short pad0x12;
    int nUnitGUID;
    int nLength;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_6FD10360(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs); // 0x0056E780
int __fastcall sub_005C35C0_CurseUnitCallback(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs); // 0x005C35C0
int __fastcall sub_6FD0C060(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs); // 0x005C3DE0
int __fastcall sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg); // 0x005C3B30
void __fastcall sub_005C3B00_AttractStateRemove(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3B00
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_005C31F0_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C31F0
void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
void __fastcall sub_6FC40280(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x005B1990
void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit); // 0x0056E580
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970

extern const D2NecroSkeletonComponentStrc gaNecroSkeletonComponents_00741940[]; // 0x00741940
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
static __declspec(noinline) void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel);

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
void __stdcall sub_006488A0_SetDirection(D2PathRecordStrc* pPath, int nDirection); // 0x006488A0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit); // 0x0055B7E0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId); // 0x004F4110

// 0x005C3300
static int sub_005C3300_CorpseConsumedCheck(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwUnitType : 6) != 1)
    {
        return 0;
    }

    if (!sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 8))
    {
        return 0;
    }

    if (!SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pUnit, 0))
    {
        return 0;
    }

    return sub_6FD15190(pUnit, 7) != 0;
}

// build: context sub_005C3300_Shim
// calling-convention shim (not game code)
int __fastcall sub_005C3300_Shim(D2UnitStrc* pUnit)
{
    return sub_005C3300_CorpseConsumedCheck(pUnit);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x005C37A0
static __declspec(noinline) int sub_005C37A0_ApplyAiCurseDivisor(unsigned char nDifficulty, int nLength)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(nDifficulty);
    if (pDifficultyLevelsTxtRecord && pDifficultyLevelsTxtRecord->dwAiCurseDiv)
    {
        return nLength / pDifficultyLevelsTxtRecord->dwAiCurseDiv;
    }
    return nLength;
}

// 0x005C3B90
int __fastcall SKILLS_SrvDo059_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!sub_005C31F0_IsValidAttractTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_005543B0_AssignAlignment(pTarget, 1, 1);
    sub_6FC40280(pGame, pTarget, 0, 9);
    SKILLS_ClearMonsterMinionOwnership(pTarget);

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    const int nBaseLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nLength = sub_005C37A0_ApplyAiCurseDivisor(pGame->nDifficulty, nBaseLength);

    D2UnkNecSkillStrc3 arg;
    arg.pGame = pGame;
    arg.pUnit = pUnit;
    arg.nSkillId = nSkillId;
    arg.nSkillLevel = nSkillLevel;
    arg.nLength = nLength;
    arg.nUnitType = sub_0044BE50(pTarget);
    arg.nUnitGUID = UNITS_GetUnitId(pTarget);
    sub_6FD10360(pGame, pSkillsTxtRecord->dwAuraFilter, pUnit, nRange, sub_6FD0BDA0, &arg);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = nLength;
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = sub_005C3B00_AttractStateRemove;
    sub_0056E970(&curse);
    return 1;
}

// build: context SEED_RollRandomNumber_Inline
static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// build: context MONSTERUNIQUE_GetMonsterDataInl
inline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInl(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// build: context MONSTERS_SetComponentInl
inline void MONSTERS_SetComponentInl(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterDataInl(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nComponent[nComponent] = nValue;
    }
}

// build: context SKILLS_GetSkillsTxtRecord_Inline
static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C4180
static void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel)
{
    if (nLevel > 10)
    {
        nLevel = 10;
    }

    const char nHead = gaNecroSkeletonComponents_00741940[nLevel].nHead;
    MONSTERS_SetComponentInl(pPet, 0, nHead);
    const char nTorso = gaNecroSkeletonComponents_00741940[nLevel].nTorso;
    MONSTERS_SetComponentInl(pPet, 1, nTorso);
    const char nSpecial1 = gaNecroSkeletonComponents_00741940[nLevel].nSpecial1;
    MONSTERS_SetComponentInl(pPet, 8, nSpecial1);
    const char nSpecial2 = gaNecroSkeletonComponents_00741940[nLevel].nSpecial2;
    MONSTERS_SetComponentInl(pPet, 9, nSpecial2);
    const char nLegs = gaNecroSkeletonComponents_00741940[nLevel].nLegs;
    MONSTERS_SetComponentInl(pPet, 2, nLegs);
    const char nRightArm = gaNecroSkeletonComponents_00741940[nLevel].nRightArm;
    MONSTERS_SetComponentInl(pPet, 3, nRightArm);
    const char nLeftArm = gaNecroSkeletonComponents_00741940[nLevel].nLeftArm;
    MONSTERS_SetComponentInl(pPet, 4, nLeftArm);

    if (bHasShield)
    {
        const char nShield = gaNecroSkeletonComponents_00741940[nLevel].nShield;
        MONSTERS_SetComponentInl(pPet, 7, nShield);
    }

    if (bSpecial)
    {
        const int nComponent = SEED_RollRandomNumber_Inline(&pUnit->pSeed) & 3;
        MONSTERS_SetComponentInl(pPet, 11, nComponent);
        MONSTERS_SetComponentInl(pPet, 12, nComponent);
        AITHINK_SetAiControlParams(pPet && pPet->dwUnitType == UNIT_MONSTER && pPet->pMonsterData ? pPet->pMonsterData->pAiControl : 0, 1, 0, -666);
    }
    else
    {
        const char nRightHand = gaNecroSkeletonComponents_00741940[nLevel].nRightHand;
        MONSTERS_SetComponentInl(pPet, 5, nRightHand);
    }
}

// 0x005C4300
static __declspec(noinline) void __stdcall sub_005C4300_SetSkeletonComponents(D2UnitStrc* pPet, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    int nLevel = 1;
    if (STATES_CheckState(pUnit, 0x61))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x61);
        if (pStatList)
        {
            STATLIST_GetStatValue(pStatList, 0x15E, 0);
            nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        }
    }

    int bHasShield = 0;
    if (nSkillLevel > 2)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
        const int nParam = !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[0];
        const int nRoll = SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100;
        if (nRoll < nParam)
        {
            bHasShield = 1;
        }
    }

    D2GAME_SetUnitComponent_6FD0C3A0(bHasShield, 0, pUnit, pPet, nLevel);
}

// 0x005C43D0
static __declspec(noinline) void __stdcall sub_005C43D0_SetMageComponents(D2UnitStrc* pPet, D2UnitStrc* pUnit)
{
    int nLevel = 1;
    if (STATES_CheckState(pUnit, 0x61))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x61);
        if (pStatList)
        {
            STATLIST_GetStatValue(pStatList, 0x15E, 0);
            nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        }
    }

    D2GAME_SetUnitComponent_6FD0C3A0(0, 1, pUnit, pPet, nLevel);
}

// 0x005C4430
void __fastcall sub_005C4430_SetNecroPetComponents(D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel)
{
    switch (!pPet ? -1 : pPet->dwClassId)
    {
    case 0x16B:
        sub_005C4300_SetSkeletonComponents(pPet, nSkillLevel, pUnit, nSkillId);
        break;
    case 0x16C:
        sub_005C43D0_SetMageComponents(pPet, pUnit);
        break;
    }
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

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX((D2PathRecordStrc*)pUnit->pDynamicPath) : 0;
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

    return pUnit->pDynamicPath ? sub_00648900_PathGetY((D2PathRecordStrc*)pUnit->pDynamicPath) : 0;
}

// 0x005C5BC0
static D2UnitStrc* __stdcall sub_005C5BC0_SpawnBonePrisonPet(D2GameStrc* pGame, int nSkillId, D2UnitStrc* pUnit, int nX, int nY, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (DUNGEON_IsRoomInTown(sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY)))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.dwFlags = 9;
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = nX;
    summonArg.pPosition.nY = nY;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 15, 0);
    sub_6FC40280(pGame, pPet, 0, 9);
    return pPet;
}

// 0x005C5D00
int __fastcall SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pOwner = 0;
    for (int i = 0; i < 12; ++i)
    {
        D2UnitStrc* pPet = sub_005C5BC0_SpawnBonePrisonPet(pGame, nSkillId, pUnit, nTargetX + gnBonePrisonOffsetX_006E304C[i], nTargetY + gnBonePrisonOffsetY_006E307C[i], nSkillLevel);
        if (pPet)
        {
            if (!pOwner)
            {
                pOwner = pPet;
                AIGENERAL_SetOwnerData(pGame, pPet, sub_00451F50_GetUnitGUID(pUnit), sub_0044BE50_GetUnitTypeOrInvalid(pUnit), 0, 1);
            }
            else
            {
                AIGENERAL_SetOwnerData(pGame, pPet, !pOwner ? -1 : pOwner->dwUnitId, !pOwner ? 6 : pOwner->dwUnitType, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pOwner, pPet);
            }

            UNITS_StoreOwner(pPet, pUnit);
            sub_006488A0_SetDirection((D2PathRecordStrc*)pPet->pDynamicPath, PATH_ComputeDirection(UNITS_GetXPositionInline(pPet), UNITS_GetYPositionInline(pPet), nTargetX, nTargetY));
        }
    }

    return 1;
}

// 0x005C5F10
static int sub_005C5F10_AddLifeAndGetGain(D2UnitStrc* pUnit, int nValue)
{
    if (nValue <= 0)
    {
        return 0;
    }

    int nNewHp = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    nNewHp += nValue;
    if (nNewHp > nMaxHp)
    {
        nValue += (nMaxHp - nNewHp);
        nNewHp = nMaxHp;
    }

    STATLIST_SetUnitStat(pUnit, 6, nNewHp, 0);
    return nValue;
}

// 0x005C5F50
int __fastcall SKILLS_EventFunc04_ReflectPhysicalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pAttacker)
    {
        return 0;
    }

    if (pAttacker->dwUnitType == UNIT_PLAYER || pAttacker->dwUnitType == UNIT_MONSTER)
    {
        goto LABEL_ALIVE;
    }
    return 0;

LABEL_ALIVE:
    if (SUNIT_IsDead(pAttacker) || !pDamage || pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel < 0)
    {
        nLevel = 1;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || !STATES_CheckState(pAttacker, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        return 0;
    }

    D2UnitStrc* pStatListOwner = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    int nDamagePercent = 0;
    if (pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pAttacker))
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }
        else
        {
            nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
    }
    else
    {
        nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    }

    D2DamageStrc damage = {};
    damage.dwPhysDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nDamagePercent, 100);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags | 0x20;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    SUNITDMG_ExecuteEvents(pGame, pUnit, pAttacker, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pAttacker, &damage);

    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER || pUnit->dwClassId != 0x122)
    {
        return 1;
    }

    unsigned char nDrain = 100;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
        if (!pMonStatsTxtRecord)
        {
            return 1;
        }

        nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return 1;
        }
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 1;
    }

    int nBaseDamage = damage.dwPhysDamage;
    if (nDrain != 100)
    {
        nBaseDamage = DATATBLS_ApplyRatio(damage.dwPhysDamage, nDrain, 100);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (pOwner && SUNIT_IsDead(pOwner) || SUNIT_IsDead(pAttacker))
    {
        return 1;
    }

    int nDamage = DATATBLS_ApplyRatio(nBaseDamage, 20, 100);
    if (nDamage <= 0)
    {
        return 1;
    }

    if (pOwner)
    {
        nDamage -= sub_005C5F10_AddLifeAndGetGain(pOwner, DATATBLS_ApplyRatio(nDamage, 50, 100));
    }

    nDamage -= sub_005C5F10_AddLifeAndGetGain(pAttacker, nDamage);
    if (pOwner && nDamage > 0)
    {
        sub_005C5F10_AddLifeAndGetGain(pOwner, nDamage);
    }

    UNITS_SetOverlay(pAttacker, 0x97, 0);
    if (pOwner)
    {
        UNITS_SetOverlay(pOwner, 0x97, 0);
    }

    return 1;
}
