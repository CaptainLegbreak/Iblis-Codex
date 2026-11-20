#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameAux.h"
struct D2UnitStrc;

struct D2AuraCallbackStrc;

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

struct D2RedemptionAuraParamStrc
{
    int nSkillId;
    int nSkillLevel;
    int nRedeemed;
};

enum D2C_Y09BasicAuraConstants
{
    STAT_MANA = 8,
    STATE_NOMANAREGEN = 85,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall sub_0056B740_CallWithRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005CEDC0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005D0D70
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (!(nSkillId >= 0))
        return 0;
    if (!(nSkillId < sgptDataTables->nSkillsTxtRecordCount))
        return 0;
    return &sgptDataTables->pSkillsTxt[nSkillId];
}

// 0x005D0E90
int __fastcall sub_005D0E90(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nDuration = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    D2BasicAuraParamStrc args;
    memset(&args, 0, sizeof(args));
    args.nSkillLevel = nSkillLevel;
    args.nDuration = nDuration;
    args.nSkillId = nSkillId;
    args.nAuraState = pSkillsTxtRecord->nAuraState;

    for (int i = 0; i < 5; ++i)
    {
        const int nStat = pSkillsTxtRecord->nPassiveStat[i];
        args.nAuraStat[i] = nStat;
        if (nStat >= 0)
        {
            if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit) != UNIT_PLAYER || nMana >= nManaCost)
            {
                args.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
            }
        }
    }

    sub_0056B740_CallWithRecord(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args);

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return 1;
    }

    D2RedemptionAuraParamStrc redemptionArgs;
    redemptionArgs.nSkillId = nSkillId;
    redemptionArgs.nSkillLevel = nSkillLevel;
    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    sub_6FD0FE80(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_Redemption, &redemptionArgs, 1, gszSkillPalSourceFile, 0x753);

    if (nManaCost > 0)
    {
        if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == UNIT_PLAYER)
        {
            if (redemptionArgs.nRedeemed > 0)
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

    return 1;
}
