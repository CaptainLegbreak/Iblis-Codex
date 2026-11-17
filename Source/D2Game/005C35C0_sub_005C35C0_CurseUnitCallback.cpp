struct D2StatListStrc;
struct D2UnitEventStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
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

struct D2DataTablesStrc
{
    char unk0x000[0xBD4];
    int nItemStatCostTxtRecordCount;
};

enum D2SkillNecConstants
{
    UNIT_MONSTER = 1,
    STATE_DIMVISION = 23,
    STATE_TAUNT = 27,
    STATE_TERROR = 56,
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState);                                        // 0x0056E2F0
int __fastcall sub_6FD0B3D0(D2UnitStrc* pUnit, int nStatId, int nResist);                                    // 0x005C3540
int __fastcall sub_005C3420_ValidTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);         // 0x005C3420
void __fastcall sub_6FD0B250(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x005C3370
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970
void __fastcall sub_005C34B0_ExecuteCurseTargetAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005C34B0
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4);    // 0x005C0B50
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

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
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\SKILLS\\SkillNec.cpp", 582);
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
