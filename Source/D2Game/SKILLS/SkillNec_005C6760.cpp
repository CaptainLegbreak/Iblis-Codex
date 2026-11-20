#include "D2Structs.h"
#ifdef MOVED_TEST
#define SLOW_STAT 152
#define SMALL_CAP 52
#define LARGE_CAP 92
#define UNITMASK_MONSTER 14
#define CURSE_DURATION 754
#define STAT_A 69
#define STAT_B 70
#define STAT_C 71
#define CURSE_STATE 26
#define SOURCE_LINE 0xB66
#else
#define SLOW_STAT 150
#define SMALL_CAP 50
#define LARGE_CAP 90
#define UNITMASK_MONSTER 12
#define CURSE_DURATION 750
#define STAT_A 67
#define STAT_B 68
#define STAT_C 69
#define CURSE_STATE 24
#define SOURCE_LINE 0xB62
#endif
struct D2UnitStrc;
struct D2StatListStrc;
struct D2GameStrc;
struct D2DamageStrc;
struct Unit005A0180;
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
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask);                         // 0x005A0180
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);          // 0x006270B0
// 0x005C6760
int __fastcall sub_005C6760(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pTarget)
        return 0;
    int nSlow = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, SLOW_STAT, 0);
    if (!nSlow)
        return 0;
    if (pTarget->dwUnitType == 0)
    {
        if (nSlow >= SMALL_CAP)
            nSlow = SMALL_CAP;
    }
    else if (pTarget->dwUnitType == 1)
    {
        if (sub_005A0180((Unit005A0180*)pTarget, UNITMASK_MONSTER))
        {
            if (nSlow >= SMALL_CAP)
                nSlow = SMALL_CAP;
        }
        else if (nSlow >= LARGE_CAP)
            nSlow = LARGE_CAP;
    }
    else
        return 0;
    D2CurseStrc curse = {};
    nSlow = -nSlow;
    curse.pUnit = pAttacker;
    curse.pTarget = pTarget;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = CURSE_DURATION;
    curse.nStat = STAT_A;
    curse.nStatValue = nSlow;
    curse.nState = CURSE_STATE;
    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList)
        return 0;
    sub_006270B0(pStatList, STAT_B, nSlow, 0);
    sub_006270B0(pStatList, STAT_C, nSlow, 0);
    UNITS_UpdateAnimRateAndVelocity(pTarget, ".\\SKILLS\\SkillNec.cpp", SOURCE_LINE);
    return 1;
}
