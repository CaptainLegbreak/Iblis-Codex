struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2AiControlStrc { char unk_00[0x14]; int dwAiParam[3]; };
struct D2MonsterDataStrc { char unk_00[0x28]; D2AiControlStrc* pAiControl; };
struct D2UnitStrc { int dwUnitType; char dwClassId[0x10]; D2MonsterDataStrc* pMonsterData; char unk_18[8]; D2SeedStrc pSeed; };
struct D2GameStrc { char unk_00[0x6D]; unsigned char nDifficulty; };
struct D2MonStatsTxt { char unk_00[0x56]; short wAiParam[8][3]; char unk_86[0xEA]; short nSkill[8]; signed char nSkillMode[8]; char unk_188[0x20]; };
struct D2DataTablesStrc { char unk_00[0xA78]; D2MonStatsTxt* pMonStatsTxt; int unk_A7C; int nMonStatsTxtRecordCount; };
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; int unk_04; D2UnitStrc* pTarget; int unk_0C[2]; int nTargetDistance; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int); // 0x005B0E00
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0
void __fastcall AITACTICS_UseSkillInRange(D2UnitStrc* pUnit, int nRange, int nSkillId, int nMode); // 0x005DF850
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc*); // 0x006259B0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
// build: context MONSTERMODE_GetMonStatsTxtRecord
static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}
// build: context AIGENERAL_GetAiControlFromUnit
static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData) return pUnit->pMonsterData->pAiControl;
    return 0;
}

// 0x005E2D80
void __fastcall sub_005E2D80_ThinkControlledMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (STATES_CheckState(pUnit, 143) && pOwner)
    {
        D2MonStatsTxt* pRecords[2] = { MONSTERMODE_GetMonStatsTxtRecord(492), MONSTERMODE_GetMonStatsTxtRecord(493) };
        D2SeedStrc* pSeed = &pUnit->pSeed;
        if (nTargetDistance <= 24 && !SUNIT_IsDead(pOwner) && !STATLIST_GetUnitAlignment(pOwner) && pAiControl->dwAiParam[1])
        {
            if (nTargetDistance < pRecords[1]->wAiParam[1][pGame->nDifficulty]
                && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < pRecords[1]->wAiParam[2][pGame->nDifficulty])
            {
                const int nSkillIndex = pAiTickParam->pAiControl->dwAiParam[1];
                const int bScatter = pAiTickParam->pAiControl->dwAiParam[2];
                CLIENTS_GetUnitX(pTarget);
                CLIENTS_GetUnitY(pTarget);
                if (bScatter)
                {
                    SEED_RollLimitedRandomNumber(pSeed, 2 * pRecords[1]->wAiParam[3][pGame->nDifficulty]);
                    SEED_RollLimitedRandomNumber(pSeed, 2 * pRecords[1]->wAiParam[3][pGame->nDifficulty]);
                }
                if (pRecords[0]->nSkill[nSkillIndex] >= 0)
                {
                    AITACTICS_UseSkill(pGame, pUnit, pRecords[0]->nSkillMode[nSkillIndex], pRecords[0]->nSkill[nSkillIndex], pTarget, 0, 0);
                    return;
                }
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, pTarget);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }
        AITACTICS_UseSkillInRange(pUnit, pRecords[0]->wAiParam[1][pGame->nDifficulty], pRecords[0]->nSkill[0], pRecords[0]->nSkillMode[0]);
        AIGENERAL_GetAiControlFromUnit(pUnit)->dwAiParam[0] = -1;
        return;
    }
    AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}
