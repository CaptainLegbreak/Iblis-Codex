#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"

#define D2_MAX(a, b) ((a) < (b) ? (b) : (a))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2CurseStrc;
struct D2UnkNecSkillStrc;
struct D2DifficultyLevelsTxt;
struct D2SkillsTxt;
struct D2UnkNecSkillStrc3;
struct D2MonsterDataStrc;
union D2SeedStrc;
struct D2NecroSkeletonComponentStrc;
struct D2StaticPathStrc;
struct D2SummonArgStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x3A];
    int dwGameFrame;
};

union D2SeedStrc
{
    struct
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
    };
    unsigned __int64 lSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned char unk_10[0x4];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2PathRecordStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
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


enum D2SkillNecConstants
{
    STATE_DIMVISION = 23,
    STATE_TAUNT = 27,
    STATE_TERROR = 56,
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
int __fastcall sub_005C3420_ValidTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C3420
void __fastcall sub_6FD0B250(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3370
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __fastcall sub_005C34B0_ExecuteCurseTargetAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005C34B0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x1C];
    int dwAiCurseDiv;
};

struct D2ItemStatCostTxt
{
    unsigned short wStatId;
    unsigned short pad0x02;
    unsigned char nItemStatFlags[4];
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    char unk0x080[0x2];
    short wAuraTargetState;
    short wAuraEvent[3];
    short wAuraEventFunc[3];
    unsigned char unk_90[0x2E];
    unsigned char nPetType;
    char unk0x0BF[0x01];
    unsigned int dwPetMax;
    unsigned char unk_C4[0x48];
    short wSrvOverlay;
    char unk0x10E[0x2A];
    unsigned int dwCalc[4];
    int dwParam[8];
    char unk0x168[0x23C - 0x168];
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

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_6FD10360(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs); // 0x0056E780
int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs); // 0x005C35C0
int __fastcall sub_6FD0C060(D2UnitStrc* pUnit, void* pArgs); // 0x005C3DE0
int __fastcall sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg); // 0x005C3B30
void __fastcall sub_005C3B00_AttractStateRemove(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3B00
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall sub_005C31F0_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C31F0
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
void __fastcall sub_6FC40280(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x005B1990
void __fastcall sub_6FD154D0(D2UnitStrc* pUnit); // 0x0056E580

struct D2MonsterDataStrc
{
    char unk0x00[4];
    unsigned char nComponent[16];
    char unk0x14[0x14];
    D2AiControlStrc* pAiControl;
};

extern const D2NecroSkeletonComponentStrc gaNecroSkeletonComponents_00741940[]; // 0x00741940
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
static __declspec(noinline) void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel); // 0x005C4180

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

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
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
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

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
};

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall sub_006252B0(D2StatListStrc* pStatList); // 0x006252B0
int __stdcall sub_00625250(D2StatListStrc* pStatList); // 0x00625250
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

static __forceinline int AiSpecialStateFromAuraState(int nAuraState)
{
    switch (nAuraState)
    {
    case STATE_DIMVISION: return AISPECIALSTATE_DIMVISION;
    case STATE_TERROR: return AISPECIALSTATE_TERROR;
    case STATE_TAUNT: return AISPECIALSTATE_TAUNT;
    default: return AISPECIALSTATE_NONE;
    }
}

// 0x005C35C0
int __fastcall sub_005C35C0_CurseUnitCallback(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs)
{
    if (pArgs->unk0x08)
    {
        const int nType = pUnit ? pUnit->dwUnitType : 6;
        if (nType != UNIT_MONSTER)
        {
            return 0;
        }

        if (STATLIST_GetUnitAlignment(pUnit) == 1)
        {
            return 0;
        }

        if (!sub_6FD15190(pUnit, AiSpecialStateFromAuraState(pArgs->nAuraTargetState)))
        {
            return 0;
        }
    }

    int nValue = 0;
    if (pArgs->nAuraStat[0] >= 0)
    {
        nValue = sub_6FD0B3D0(pUnit, pArgs->nAuraStat[0], pArgs->nAuraStatCalc[0]);
        if (!nValue)
        {
            return 0;
        }
    }

    if (!sub_005C3420_ValidTarget(pArgs->pGame, pArgs->pUnit, pUnit))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pArgs->pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = pArgs->nAuraStat[0];
    curse.nStatValue = nValue;
    curse.nState = pArgs->nAuraTargetState;
    curse.pStateRemoveCallback = pArgs->unk0x08 ? sub_6FD0B250 : 0;

    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
    {
        return 0;
    }

    if (pArgs->unk0x08)
    {
        sub_005C34B0_ExecuteCurseTargetAi(pArgs->pGame, pArgs->pUnit, pUnit, pArgs->nSkillId, pArgs->nSkillLevel);
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pArgs->nAuraStat[i] >= 0 && pArgs->nAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nStatValue = sub_6FD0B3D0(pUnit, pArgs->nAuraStat[i], pArgs->nAuraStatCalc[i]);
            if (nStatValue)
            {
                STATLIST_SetStatIfListIsValid(pStatList, pArgs->nAuraStat[i], nStatValue, 0);
            }
        }
    }

    if (pArgs->bUpdateAnimRate)
    {
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillNec.cpp", 582);
    }

    if (pArgs->nAuraEvent[0] >= 0 && pArgs->nAuraEventFunc[0] > 0)
    {
        SUNITEVENT_Unregister(pArgs->pGame, pUnit, 1, pArgs->nAuraTargetState);

        for (int i = 0; i < 3; ++i)
        {
            if (pArgs->nAuraEvent[0] >= 0 && pArgs->nAuraEventFunc[0] > 0)
            {
                sub_6FD156A0(pArgs->pGame, pUnit, pArgs->nAuraEvent[i], pArgs->nSkillId, pArgs->nSkillLevel, pArgs->nAuraEventFunc[i], 1, pArgs->nAuraTargetState);
            }
        }
    }

    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C3400
int __fastcall sub_005C3400_IsDimVisionOrTerror(int nState)
{
    if (nState != 23)
    {
        return nState == 56;
    }
    return 1;
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

// 0x005C37C0
int __fastcall SKILLS_SrvDo030_Curse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int bIsDimVisionOrTerrorCurse = sub_005C3400_IsDimVisionOrTerror(pSkillsTxtRecord->wAuraTargetState);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (bIsDimVisionOrTerrorCurse)
    {
        nLength = sub_005C37A0_ApplyAiCurseDivisor(pGame->nDifficulty, nLength);
    }

    D2UnkNecSkillStrc args = {};
    args.pGame = pGame;
    args.pUnit = pUnit;
    args.unk0x08 = bIsDimVisionOrTerrorCurse;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = nLength;
    args.bUpdateAnimRate = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] < 0 || pSkillsTxtRecord->wAuraStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            args.nAuraStat[i] = -1;
            break;
        }

        D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            break;
        }

        if (pItemStatCostTxtRecord->nItemStatFlags[1] & gdwBitMasks[1])
        {
            args.bUpdateAnimRate = 1;
        }

        args.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    for (int i = 0; i < 3; ++i)
    {
        args.nAuraEvent[i] = pSkillsTxtRecord->wAuraEvent[i];
        args.nAuraEventFunc[i] = pSkillsTxtRecord->wAuraEventFunc[i];
    }

    return sub_6FD10360(pGame, pSkillsTxtRecord->dwAuraFilter, pUnit, nRange, sub_6FD0B450, &args);
}

// build: context SKILLS_SrvDo059_Attract
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

    sub_6FCBDD30(pTarget, 1, 1);
    sub_6FC40280(pGame, pTarget, 0, 9);
    sub_6FD154D0(pTarget);

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    nLength = sub_005C37A0_ApplyAiCurseDivisor(pGame->nDifficulty, nLength);

    int nUnitType = 6;
    if (pTarget)
    {
        nUnitType = pTarget->dwUnitType;
    }

    D2UnkNecSkillStrc3 arg;
    arg.pGame = pGame;
    arg.pUnit = pUnit;
    arg.nSkillId = nSkillId;
    arg.nSkillLevel = nSkillLevel;
    arg.nLength = nLength;
    arg.nUnitType = nUnitType;
    arg.nUnitGUID = !pTarget ? -1 : pTarget->dwUnitId;
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

// 0x005C3F20
int __fastcall SKILLS_SrvDo061_Confuse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    nLength = sub_005C37A0_ApplyAiCurseDivisor(pGame->nDifficulty, nLength);

    D2UnkNecSkillStrc args = {};
    args.pGame = pGame;
    args.pUnit = pUnit;
    args.nDuration = nLength;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.bUpdateAnimRate = 0;

    for (int i = 1; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] < 0 || pSkillsTxtRecord->wAuraStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            args.nAuraStat[i] = -1;
            break;
        }

        D2ItemStatCostTxt* pItemStatCostTxtRecord = sub_0045C4F0_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            break;
        }

        if (pItemStatCostTxtRecord->nItemStatFlags[1] & gdwBitMasks[1])
        {
            args.bUpdateAnimRate = 1;
        }

        args.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    return sub_6FD10360(pGame, pSkillsTxtRecord->dwAuraFilter, pUnit, nRange, sub_6FD0C060, &args);
}

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static void SKILLS_SetMonsterComponent_Inline(D2UnitStrc* pMonster, int nIndex, char nComponent)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER && pMonster->pMonsterData)
    {
        pMonster->pMonsterData->nComponent[nIndex] = nComponent;
    }
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context D2GAME_SetUnitComponent_6FD0C3A0
static __declspec(noinline) void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel)
{
    if (nLevel > 10)
    {
        nLevel = 10;
    }

    SKILLS_SetMonsterComponent_Inline(pPet, 0, gaNecroSkeletonComponents_00741940[nLevel].nHead);
    SKILLS_SetMonsterComponent_Inline(pPet, 1, gaNecroSkeletonComponents_00741940[nLevel].nTorso);
    SKILLS_SetMonsterComponent_Inline(pPet, 8, gaNecroSkeletonComponents_00741940[nLevel].nSpecial1);
    SKILLS_SetMonsterComponent_Inline(pPet, 9, gaNecroSkeletonComponents_00741940[nLevel].nSpecial2);
    SKILLS_SetMonsterComponent_Inline(pPet, 2, gaNecroSkeletonComponents_00741940[nLevel].nLegs);
    SKILLS_SetMonsterComponent_Inline(pPet, 3, gaNecroSkeletonComponents_00741940[nLevel].nRightArm);
    SKILLS_SetMonsterComponent_Inline(pPet, 4, gaNecroSkeletonComponents_00741940[nLevel].nLeftArm);

    if (bHasShield)
    {
        SKILLS_SetMonsterComponent_Inline(pPet, 7, gaNecroSkeletonComponents_00741940[nLevel].nShield);
    }

    if (bSpecial)
    {
        const unsigned char nComponent = SEED_RollRandomNumber_Inline(&pUnit->pSeed) & 3;
        SKILLS_SetMonsterComponent_Inline(pPet, 11, nComponent);
        SKILLS_SetMonsterComponent_Inline(pPet, 12, nComponent);
        AITHINK_SetAiControlParams(pPet && pPet->dwUnitType == UNIT_MONSTER && pPet->pMonsterData ? pPet->pMonsterData->pAiControl : 0, 1, 0, -666);
    }
    else
    {
        SKILLS_SetMonsterComponent_Inline(pPet, 5, gaNecroSkeletonComponents_00741940[nLevel].nRightHand);
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

#include "gen/data/Source/D2Game/SKILLS/SkillNec_005C35C0.inc"

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX(pUnit->pDynamicPath) : 0;
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

    return pUnit->pDynamicPath ? sub_00648900_PathGetY(pUnit->pDynamicPath) : 0;
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

    if (DUNGEON_IsRoomInTown(D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY)))
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

// build: context SKILLS_SrvDo062_BonePrison
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
                AIGENERAL_SetOwnerData(pGame, pPet, pOwner->dwUnitId, pOwner->dwUnitType, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pOwner, pPet);
            }

            UNITS_StoreOwner(pPet, pUnit);
            sub_006488A0_SetDirection(pPet->pDynamicPath, PATH_ComputeDirection(UNITS_GetXPositionInline(pPet), UNITS_GetYPositionInline(pPet), nTargetX, nTargetY));
        }
    }

    return 1;
}

// 0x005C61E0
int __fastcall sub_005C61E0_ApplyLifeTap(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }
    if (pAttacker->dwUnitType != 0 && pAttacker->dwUnitType != 1)
    {
        return 0;
    }
    if ((pUnit->dwUnitType != 0 && pUnit->dwUnitType != 1) || SUNIT_IsDead(pUnit) || !pDamage || pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (nSkillLevel < 0)
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

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, sub_00625250(pStatList), sub_006252B0(pStatList));
    const int nPercent = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    const int nLifeGain = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercent, 100);
    int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nLife <= 0 || nMaxLife <= 0)
    {
        return 0;
    }
    nLife += nLifeGain;
    nLife = D2_MIN(D2_MAX(nLife, 1), nMaxLife);
    STATLIST_SetUnitStat(pUnit, 6, nLife, 0);
    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wSrvOverlay, 0);
    }
    return 1;
}
