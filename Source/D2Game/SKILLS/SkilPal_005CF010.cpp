#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"


struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};

struct D2AuraCallbackStrc;

struct D2BasicAuraParamStrc
{
    int nAuraState;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalcValue[6];
    int field_40;
    D2StatListStrc* pStatList;
    int nPassiveState;
    void* pStateRemoveCallback;
};

struct D2SkillsTxt
{
    char unk0x000[0x50];
    unsigned int dwAuraFilter;
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    short wAuraTargetState;
    char unk0x084[0x10];
    short nPassiveState;
    char unk0x096[0x02];
    short nPassiveStat[5];
    char unk0x0A2[0x02];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x184];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xAD0];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x30];
    int nItemStatCostTxtRecordCount;
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

enum D2C_Y09BasicAuraConstants
{
    STAT_MANA = 8,
    STATE_NOMANAREGEN = 85,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall sub_0056B740_CallWithRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost);                    // 0x0056C110
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005CEDC0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005CF010
int __fastcall SKILLS_SrvDo065_BasicAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);

    D2BasicAuraParamStrc args;
    memset(&args, 0, sizeof(args));
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    if (pSkillsTxtRecord->nPassiveState > 0)
    {
        args.nPassiveState = pSkillsTxtRecord->nPassiveState;
    }

    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER || nMana >= nManaCost)
    {
        for (int i = 0; i < 6; ++i)
        {
            const int nAuraStat = pSkillsTxtRecord->wAuraStat[i];
            if (nAuraStat < 0)
            {
                break;
            }

            args.nAuraStat[i] = nAuraStat;
            args.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
    }

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        args.nAuraState = pSkillsTxtRecord->nAuraState;

        sub_0056B740_CallWithRecord(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args);

        if (args.pStatList && nMana > nManaCost && pSkillsTxtRecord->nPassiveState <= 0)
        {
            for (int i = 0; i < 5; ++i)
            {
                const int nStat = pSkillsTxtRecord->nPassiveStat[i];
                const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
                if (nValue && nStat > 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    STATLIST_SetStat(args.pStatList, nStat, nValue, 0);
                }
            }
        }
    }

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        args.nAuraState = pSkillsTxtRecord->wAuraTargetState;

        const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

        sub_6FD0FE80(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_BasicAura, &args, 1, ".\\SKILLS\\SkilPal.cpp", 502);

        if (nManaCost > 0)
        {
            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
            {
                if (args.field_40 > 0)
                {
                    STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 1);
                    D2GAME_SKILLMANA_AuraConsume_6FD10C90(pUnit, nManaCost);
                }
                else
                {
                    STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
                }
            }
        }
    }

    return 1;
}
