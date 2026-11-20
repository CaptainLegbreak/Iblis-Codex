#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2SkillsTxt;
struct D2SummonArgStrc;



struct D2SkillsTxt
{
    char unk0x000[0x54];
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    char unk0x082[0x16];
    short wPassiveStat[5];
    char unk0x0A2[0x2];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x6];
    unsigned char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    char unk0x0C4[0x20];
    short wSumUMod;
    char unk0x0E6[0x62];
    int dwParam;
    char unk0x14C[0xF0];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850



int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nLevel, int a7); // 0x005D6B60
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D6CF0
static void __stdcall sub_005D6CF0_SetSummonStats(D2GameStrc* pGame, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2UnitStrc* pPet)
{
    if (nSkillLevel <= 1)
    {
        return;
    }

    D2SkillsTxt* pSkillsRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pSkillsRecord ? 0 : pSkillsRecord->dwParam;
    int nHp = STATLIST_GetMaxLifeFromUnit(pPet);
    nHp += DATATBLS_ApplyRatio(nHp, (nSkillLevel - 1) * nParam, 100);
    STATLIST_SetUnitStat(pPet, 7, nHp, 0);
    STATLIST_SetUnitStat(pPet, 6, nHp, 0);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pPet ? 6 : pPet->dwUnitType, !pPet ? -1 : pPet->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pPet, pStatList, 1);

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pPet, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxtRecord->wPassiveStat[i] >= 0 && pSkillsTxtRecord->wPassiveStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pPet, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->wPassiveStat[i], nValue, 0);
        }
    }

    if (pSkillsTxtRecord->wSumUMod > 0 && pSkillsTxtRecord->wSumUMod < 43)
    {
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, pSkillsTxtRecord->wSumUMod, 1);
    }
}

D2UnitStrc* __fastcall sub_M98_Emit_005D6CF0(D2GameStrc* pGame, D2UnitStrc* pPet, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, int nExtra)
{
    sub_005D6CF0_SetSummonStats(pGame, pSkillsTxtRecord, nSkillId, nSkillLevel + nExtra, pPet);
    return pPet;
}

// 0x005D6E70
int __fastcall sub_005D6E70_SrvDoSummonPet(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
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

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = 0;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    STATLIST_SetUnitStat(pPet, 12, STATLIST_UnitGetStatValue(pUnit, 12, 0), 0);
    sub_005D6CF0_SetSummonStats(pGame, pSkillsTxtRecord, nSkillId, nSkillLevel, pPet);

    int nLevel = sub_004EFCB0_GetSummonLevel(nSkillId, nSkillLevel);
    nLevel = D2_MAX(nLevel, 1) < DATATBLS_GetMaxLevel(0) ? D2_MAX(nLevel, 1) : DATATBLS_GetMaxLevel(0);
    SKILLS_EquipMonsterFromTable(pGame, pUnit, pPet, nSkillId, nSkillLevel, nLevel, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, 2, 0);
    EVENT_SetEvent(pGame, pPet, 2, pGame->dwGameFrame + 20, 0, 0);

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        STATES_ToggleState(pPet, pSkillsTxtRecord->nAuraState, 1);
    }

    UNITS_StoreOwner(pPet, pUnit);

    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (nDuration > 0)
    {
        EVENT_SetEvent(pGame, pPet, 7, pGame->dwGameFrame + nDuration, 0, 0);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 21, 0);
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}
