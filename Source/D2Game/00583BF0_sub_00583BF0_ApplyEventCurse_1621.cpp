struct D2UnitStrc;
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
    void* pStateRemoveCallback;
};
struct D2StatListStrc;
struct D2SkillContext00583BF0Strc
{
    unsigned char unk_00[4];
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
};
struct D2Event00583BF0Strc
{
    unsigned char nType;
    unsigned char unk_01[0x0B];
    int nDuration;
};
struct D2EventState00583BF0Strc
{
    int nState;
    int f_4[2];
};
extern D2EventState00583BF0Strc gaEventStates_006E1858[]; // 0x006E1858
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit); // 0x0056DE40
void __fastcall sub_6FC77C10(); // 0x00583BD0

// 0x00583BF0
void __fastcall sub_00583BF0_ApplyEventCurse(D2SkillContext00583BF0Strc* pContext, D2Event00583BF0Strc* pEvent)
{
    D2CurseStrc tCurse = {};
    tCurse.pUnit = pContext->pUnit;
    tCurse.pTarget = pContext->pTarget;
    tCurse.nSkill = 0;
    tCurse.nSkillLevel = 0;
    tCurse.nDuration = pEvent->nDuration;
    tCurse.nStat = 11;
    tCurse.nStatValue = 0;
    tCurse.nState = gaEventStates_006E1858[pEvent->nType].nState;
    tCurse.pStateRemoveCallback = (void*)sub_6FC77C10;
    sub_0056E970(&tCurse);
    SKILLS_RefreshPassivesAndPetLimits(pContext->pTarget);
}
