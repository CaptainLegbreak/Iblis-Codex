struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { int dwUnitType; char dwClassId[8]; int dwUnitId; char unk_10[0x10]; D2SeedStrc pSeed; };
struct D2GameStrc { char unk_00[0x1C]; void* pMemoryPool; char unk_20[0x4D]; unsigned char nDifficulty; char unk_6E[0x3A]; int dwGameFrame; };
struct D2AiControlStrc { char unk_00[0x14]; int dwAiParam[3]; };
struct D2MonStatsTxt { char unk_00[0x56]; short wAiParam[8][3]; char unk_86[0xEA]; short nSkill[8]; unsigned char nSkillMode[8]; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk_04; D2UnitStrc* pTarget; int unk_0C[2]; int nDistance; int bCombat; D2MonStatsTxt* pMonstatsTxt; };
struct D2SkillsTxt { char unk_00[0x80]; short nAuraState; short nAuraTargetState; };
struct D2DataTablesStrc { char unk_00[0xC4]; int nStatesTxtRecordCount; };
struct D2SuperUniquesTxt { int unk_00; int nClass; };
struct D2StatListStrc;
struct D2BaalThroneAiCallbackArgStrc { D2UnitStrc* pTarget1; int nDistance1; D2UnitStrc* pTarget2; int nDistance2; int unk_10[6]; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnBaalThroneSuperUniqueIds[]; // 0x006E3528
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecord(int nSkill); // 0x0045C4B0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860
void __fastcall sub_00553380_SetUnitFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00553380
void __fastcall sub_00571C00_RemoveMonsterCorpses(D2UnitStrc* pUnit, int nClass); // 0x00571C00
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClass, int nMode); // 0x00574370
int __fastcall sub_00586B30_GetSuperUniqueId(int nIndex); // 0x00586B30
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nState); // 0x005B0E00
D2UnitStrc* __fastcall sub_005DD0B0_FindTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, void* pCallback, int nCallbackId); // 0x005DD0B0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkill, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall sub_005EF210_BaalThroneSpawnMinion(D2UnitStrc* pUnit, int nSuperUnique, D2AiTickParamStrc* pTick); // 0x005EF210
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pPool, int nFlags, int nExpire, int nType, int nUnitId); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pList, int nState); // 0x006252D0
void __stdcall sub_00626E10(D2UnitStrc* pUnit, D2StatListStrc* pList, int bReset); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc* pList, int nStat, int nValue, int nLayer); // 0x00627150
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUnique); // 0x006556E0
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique); // 0x00659B80
// build: context BAALTHRONE_GetSuperUniqueClass
static __forceinline int BAALTHRONE_GetSuperUniqueClass(int nSuperUnique)
{
    D2SuperUniquesTxt* pSuperUnique = DATATBLS_GetSuperUniquesTxtRecord(nSuperUnique);
    if (!pSuperUnique)
    {
        return -1;
    }
    return pSuperUnique->nClass;
}
// 0x005EF320
void __fastcall sub_005EF320_ThinkBaalThrone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    if (!pMonStats)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pGame->dwGameFrame - pAiControl->dwAiParam[2]);
        return;
    }
    D2BaalThroneAiCallbackArgStrc arg;
    int nWave = pAiControl->dwAiParam[0];
    arg.pTarget1 = 0;
    arg.nDistance2 = 64;
    arg.pTarget2 = 0;
    arg.nDistance1 = 64;
    sub_005DD0B0_FindTarget(pGame, pUnit, &arg, 0, 3);
    if (!arg.pTarget2)
    {
        if (!(pTick->pAiControl->dwAiParam[1] & 1))
        {
            if ((unsigned int)nWave <= 4)
            {
                nWave = BAALTHRONE_GetSuperUniqueClass(sub_00586B30_GetSuperUniqueId(gnBaalThroneSuperUniqueIds[nWave]));
                if (nWave < 0) return;
                sub_00571C00_RemoveMonsterCorpses(pUnit, nWave);
                switch (nWave)
                {
                case 62: sub_00571C00_RemoveMonsterCorpses(pUnit, 23); break;
                case 105: sub_00571C00_RemoveMonsterCorpses(pUnit, 381); break;
                }
            }
            AITACTICS_UseSkill(pGame, pUnit, 10, 285, pUnit, 0, 0);
            pTick->pAiControl->dwAiParam[1] |= 1;
            pTick->pAiControl->dwAiParam[2] = pGame->dwGameFrame + 250;
            sub_00553380_SetUnitFlag(pUnit, 16, 0);
            return;
        }
        if (nWave >= 5)
        {
            MONSTER_Reinitialize(pGame, pUnit, 559, 1);
            AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
            STATES_ToggleState(pUnit, 142, 1);
            D2StatListStrc* pList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0,
                !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (pList)
            {
                sub_00626E10(pUnit, pList, 1);
                STATLIST_SetState(pList, 142);
                STATLIST_SetStat(pList, 355, 559, 0);
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }
        int nSuperUnique = DATATBLS_MapSuperUniqueId(2, sub_00586B30_GetSuperUniqueId(gnBaalThroneSuperUniqueIds[nWave]));
        sub_005EF210_BaalThroneSpawnMinion(pUnit, nSuperUnique, pTick);
        return;
    }
    D2UnitStrc* pTarget = pTick->pTarget;
    if (pMonStats->nSkill[0] > 0 && pTarget)
    {
        D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(pMonStats->nSkill[0]);
        if (pSkills)
        {
            if (pSkills->nAuraState >= 0 && pSkills->nAuraState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pUnit, pSkills->nAuraState)) goto Idle;
            if (pSkills->nAuraTargetState >= 0 && pSkills->nAuraTargetState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pTarget, pSkills->nAuraTargetState)) goto Idle;
            if (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], pTarget, 0, 0);
                return;
            }
        }
    }
Idle:
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

#include "gen/data/Source/D2Game/005EF320_sub_005EF320_ThinkBaalThrone.inc"
