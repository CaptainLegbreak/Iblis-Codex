#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define UNITFLAG_SKSRVDOFUNC 0x40
#define AISPECIALSTATE_NONE 0
#define STAT_LEVEL 12
#define STATE_VINE_BEAST 150
#define SKILLDRUID_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2SummonArgStrc;
struct D2SkillsTxt;
union D2SeedStrc;





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

struct D2SkillsTxt
{
    char pad0[4];
    unsigned char nFlags[4];
    unsigned char unk_08[0x4C];
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    char pad68[0x18];
    short nAuraState;
    short wAuraTargetState;
    unsigned char unk_84[0x3A];
    signed char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    char unk0x0C4[0x74];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};


typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
void __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740
void __fastcall sub_6FD11BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056F020
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __fastcall sub_6FCFE030(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList); // 0x005C6C50
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
extern "C" void __stdcall sub_006252D0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x006252D0
extern "C" void __stdcall sub_00625CE0(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
extern "C" void __stdcall sub_006260B0(D2StatListStrc* pStatList, int nValue); // 0x006260B0
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

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
    int unk0x38[5];
    int nRange;
    int unk0x50;
    void (__fastcall* pInitFunc)(D2UnitStrc* pMissile, int nInitArg);
    int nInitArg;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall sub_005C7B10_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel); // 0x005C7B10

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

enum
{
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_REMOVESTATE = 12,
    STAT_MODIFIERLIST_SKILL = 350,
    STAT_MODIFIERLIST_LEVEL = 351,
};
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall sub_00645950_CheckTarget(int nX, int nY, D2UnitStrc* pUnit, int nMask); // 0x00645950
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

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
};
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline int SKILLS_IsValidPetType(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

// 0x005C6910
int __fastcall SKILLS_SrvDo114_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType(pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    pPet->dwFlags &= 0xFFFFFFFBu;
    STATLIST_SetUnitStat(pPet, STAT_HPREGEN, 0, 0);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C6A80
int __fastcall SKILLS_SrvDo115_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType(pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.nMonMode = 8;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    STATES_ToggleState(pPet, STATE_VINE_BEAST, 1);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    STATLIST_SetUnitStat(pPet, STAT_LEVEL, nLevel, 0);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C6EC0
int __fastcall SKILLS_SrvDo116_Wearwolf_Wearbear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (sub_6FD11C90(pUnit, pSkillsTxtRecord->nAuraState, 1))
    {
        sub_6FD11BA0(pGame, pUnit, nSkillId, nSkillLevel);
        return 0;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, pGame->dwGameFrame + nLength, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
    STATLIST_SetStatRemoveCallback(pStatList, sub_6FCFE030);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_REMOVESTATE, pGame->dwGameFrame + nLength, 0, 0);
    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (pSkill)
    {
        SKILLS_SetSkillMode(pSkill, 10);
    }

    return 1;
}

// 0x005C7520
int __fastcall sub_005C7520(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType(pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C77C0
int __fastcall SKILLS_SrvDo120_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 0x2AF) != nSkillId)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    if (!SKILLS_GetParam1(pSkill))
    {
        return 1;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nExpireFrame = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        sub_006252D0(pStatList, pSkillsTxtRecord->nAuraState);
        sub_00625CE0(pStatList, (unsigned int)sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    sub_006260B0(pStatList, nExpireFrame);
    sub_005417D0_DirectDated(pGame, pUnit, 0xC, nExpireFrame, 0, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nValue = SKILLDRUID_MIN(nParam, STATLIST_GetStatValue(pStatList, 0xA9, 0) + 1);

    STATLIST_SetStatIfListIsValid(pStatList, 0xA9, nValue, 0);
    STATLIST_SetStatIfListIsValid(pStatList, 0x15E, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, 0x15F, nSkillLevel, 0);
    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nValue);
    return 1;
}

// 0x005C7B10
int __stdcall sub_005C7B10_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nExpireFrame = pGame->dwGameFrame + nTimeout;
    if (STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }

    const unsigned int nUnitGUID = !pTarget ? -1 : pTarget->dwUnitId;
    const int nUnitType = !pTarget ? 6 : pTarget->dwUnitType;

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }

    sub_006252D0(pStatList, pSkillsTxtRecord->wAuraTargetState);
    sub_00625CE0(pStatList, (unsigned int)sub_6FD10E50);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
    sub_006260B0(pStatList, nExpireFrame);
    sub_005417D0_DirectDated(pGame, pTarget, 0xC, nExpireFrame, 0, 0);
    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return 1;
}

// 0x005C7CE0
static void __stdcall sub_005C7CE0_CreateAuraTargetMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimeout, int nSkillLevel, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x8000;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pTarget;
    missileParams.pOrigin = pTarget;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nRange = nTimeout;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    MISSILE_SetTargetX(pMissile, nUnitType);
    MISSILE_SetTargetY(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
}

// 0x005C7DB0
int __fastcall sub_6FCFEDD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel)
{
    if (nSkillLevel <= 0)
    {
        return 0;
    }

    if (sub_005C7B10_ApplyAuraTargetState(pGame, pUnit, pTarget, nTimeout, nSkillId, nSkillLevel))
    {
        sub_005C7CE0_CreateAuraTargetMissile(pGame, pUnit, nTimeout, nSkillLevel, pTarget, nSkillId);
    }
    return 1;
}

// 0x005C8080
int __fastcall sub_005C8080_SrvDoProgressive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (!sub_6FD15340(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const unsigned char nRand = (unsigned char)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 256);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nRand);
    sub_6FCC6300(pUnit, 0, nSkillId, nSkillLevel, nX, nY, nRand);
    return 1;
}

// 0x005C8190
int __fastcall sub_005C8190(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillDruid.cpp", 1163) != nSkillId)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nParam = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 0x10000);
    int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (nDuration < 1)
    {
        nDuration = 1;
    }

    const int nExpireFrame = pGame->dwGameFrame + nDuration;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const unsigned int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    D2COMMON_10476(pStatList, nExpireFrame);
    sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    const int nFrame = sub_004EFC80_FourthSkillParam(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
    sub_005417D0_DirectDated(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nFrame, nSkillId, nSkillLevel);
    SKILLS_SetParam1(pSkill, nParam);
    return 1;
}

static __forceinline D2SkillsTxt* GetRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static __forceinline int DeleteEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 5, nSkillId);
    return 0;
}

// 0x005C8520
int __fastcall sub_005C8520_PeriodicMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pRecord = GetRecord(nSkillId);
    if (!pRecord || nSkillLevel <= 0 || pRecord->nAuraState < 0 || pRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!STATES_CheckState(pUnit, pRecord->nAuraState))
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!(pRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            D2StatListStrc* pList = STATLIST_GetStatListFromUnitAndState(pUnit, pRecord->nAuraState);
            if (pList)
            {
                D2Common_10474(pUnit, pList);
                STATLIST_FreeStatList(pList);
            }
            STATES_ToggleState(pUnit, pRecord->nAuraState, 0);
            return DeleteEvent(pGame, pUnit, nSkillId);
        }
    }
    int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSkill || !pSeed) return DeleteEvent(pGame, pUnit, nSkillId);
    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRange <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    int nFrame = sub_004EFC80_FourthSkillParam(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 5, nSkillId);
    sub_005417D0_DirectDated(pGame, pUnit, 5, nFrame, nSkillId, nSkillLevel);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
    SEED_InitLowSeed(pSeed, SKILLS_GetParam1(pSkill));
    SKILLS_SetParam1(pSkill, SEED_RollLimitedRandomNumber(pSeed, 1000000));
    UNITS_GetXPosition(pUnit);
    CLIENTS_GetUnitY(pUnit);
    int nX, nY;
    int i = 0;
    for (; i < 5; ++i)
    {
        int nMax = 2 * nRange + 1;
        nX = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nX += UNITS_GetXPosition(pUnit);
        nY = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nY += CLIENTS_GetUnitY(pUnit);
        if (sub_00645950_CheckTarget(nX, nY, pUnit, 0x805))
        {
            pRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
            if (pRoom && !COLLISION_CheckMask(pRoom, nX, nY, 1)) break;
        }
    }
    if (i >= 5) return 0;
    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
    sub_6FCC6300(pUnit, 0, nSkillId, nSkillLevel, nX, nY, 0);
    return 1;
}

inline int m12_Abs(int n)
{
    return n < 0 ? -n : n;
}

// 0x005C8780
static __declspec(noinline) int sub_005C8780_AbsorbDamage(int* pDamage, int nValue)
{
    if (nValue <= *pDamage)
    {
        *pDamage -= nValue;
        return 0;
    }

    nValue -= *pDamage;
    *pDamage = 0;
    return nValue;
}

// 0x005C87A0
int __fastcall sub_005C87A0(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    if (!pDamage)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        return 0;
    }

    const int nStat1 = pSkillsTxtRecord->wAuraStat[1];
    if (nStat1 < 0 || nStat1 >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    const int nValue1 = STATLIST_GetStatValue(pStatList, nStat1, 0);
    if (nValue1 <= 0)
    {
        return 0;
    }

    const int nStat0 = pSkillsTxtRecord->wAuraStat[0];
    if (nStat0 < 0 || nStat0 >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    int nValue0 = STATLIST_GetStatValue(pStatList, nStat0, 0);
    if (nValue0)
    {
        if (pDamage->dwFireDamage > 0)
        {
            nValue0 = sub_005C8780_AbsorbDamage(&pDamage->dwFireDamage, nValue0);
        }
        if (pDamage->dwColdDamage > 0)
        {
            nValue0 = sub_005C8780_AbsorbDamage(&pDamage->dwColdDamage, nValue0);
        }
        if (pDamage->dwLtngDamage > 0)
        {
            nValue0 = sub_005C8780_AbsorbDamage(&pDamage->dwLtngDamage, nValue0);
        }
        STATLIST_SetStatIfListIsValid(pStatList, nStat0, nValue0, 0);
    }

    if (nValue0 > 0)
    {
        const int nNewParamValue = DATATBLS_ApplyRatio(nValue0, 100, nValue1);
        const int nOldParamValue = STATLIST_GetStatValue(pStatList, 84, 0);
        if (m12_Abs(nNewParamValue - nOldParamValue >= 5))
        {
            STATES_ToggleGfxStateFlag(pAttacker, pSkillsTxtRecord->nAuraState, 1);
            STATLIST_SetStatIfListIsValid(pStatList, 84, nNewParamValue, 0);
        }
    }
    else
    {
        STATES_ToggleState(pAttacker, pSkillsTxtRecord->nAuraState, 0);
        D2Common_10474(pAttacker, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    return 1;
}
