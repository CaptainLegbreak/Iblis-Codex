#include "D2Game.h"

struct D2UnitStrc {
    int dwUnitType, dwClassId, unk08, dwUnitId;
    char unk10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
};
struct D2SkillsTxt { char unk[0x23C]; };
struct D2DataTablesStrc {
    char unk[0xB98]; D2SkillsTxt* pSkillsTxt; int unkB9C; int nSkillsTxtRecordCount;
};
struct D2MonStatsTxt { char unk[0x32]; short nVelocity, nRun; };
struct D2CharStatsTxt { char unk[0x40]; unsigned char nWalkSpeed, nRunSpeed; };
struct D2ModeChangeStrc {
    int nMode; D2UnitStrc* pUnit; D2UnitStrc* pTargetUnit;
    int nX, nY, unk14, unk18, unk1C;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __fastcall sub_00463900_GetValidMonsterId(int nMonsterId); // 0x00463900
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId); // 0x004833E0
int __fastcall sub_004C9460_GetSkillParam1(int nSkillId); // 0x004C9460
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
void __fastcall SUNIT_SetCombatMode(D2GameStrc*, D2UnitStrc*, int); // 0x00553570
int __fastcall sub_6FD150A0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0056E230
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc*, D2ModeChangeStrc*, int); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc*, int, D2ModeChangeStrc*); // 0x005A7E60
void __stdcall UNITS_SetUsedSkill(D2UnitStrc*, D2SkillStrc*); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*, D2UnitStrc*, int); // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc*, int); // 0x006445A0
void __stdcall SKILLS_SetParam4(D2SkillStrc*, int); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc*, int); // 0x00644660
void __stdcall PATH_SetVelocity(D2DynamicPathStrc*, int, const char*, int); // 0x00648690
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc*, unsigned char); // 0x00648E70
void __stdcall sub_00649050(D2DynamicPathStrc*); // 0x00649050
int __stdcall D2Common_10142(D2DynamicPathStrc*, D2UnitStrc*, int); // 0x00649970
static __forceinline int UNITS_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static __forceinline int UNITS_GetUnitIdChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
// 0x005CF6B0
int __fastcall sub_005CF6B0_StartCharge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId)) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath) return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget) {
        if (UNITS_IsInMeleeRange(pUnit, pTarget, 0)) {
            if (pUnit->dwUnitType == 0) return sub_6FD150A0(pGame, pUnit, pTarget);
            SUNIT_SetCombatMode(pGame, pUnit, 1);
            UNITS_SetUsedSkill(pUnit, 0);
            const int nMonsterId = sub_00463900_GetValidMonsterId(sub_00463860(pUnit));
            const int nMode = nMonsterId != 73 ? (nMonsterId == 211 ? 5 : 4) : 5;
            D2ModeChangeStrc modeChange;
            MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
            modeChange.pTargetUnit = pTarget;
            return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
        }
        if (!STATES_CheckState(pTarget, 54)) {
            SKILLS_SetParam1(pSkill, UNITS_GetUnitTypeChecked(pTarget));
            SKILLS_SetParam2(pSkill, UNITS_GetUnitIdChecked(pTarget));
        } else {
            SKILLS_SetParam1(pSkill, 6);
            SKILLS_SetParam2(pSkill, 0);
        }
    } else {
        SKILLS_SetParam1(pSkill, 6);
        SKILLS_SetParam2(pSkill, 0);
    }
    SKILLS_SetParam4(pSkill, 7);
    int nVelocity = 256;
    if (pUnit->dwUnitType == 0) {
        D2CharStatsTxt* pRecord = sub_004833E0_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pRecord) nVelocity = pRecord->nRunSpeed << 8;
    } else {
        const int nMonsterId = pUnit->dwClassId;
        D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pRecord) {
            nVelocity = pRecord->nRun << 8;
            if (nMonsterId == 211) SKILLS_SetParam4(pSkill, 15);
            sub_00649050(pPath);
            PATH_SetNewDistance(pPath, 20);
        }
    }
    int nBonus = STATLIST_UnitGetStatValue(pUnit, 67, 0);
    if (nBonus <= 50) nBonus = 50;
    PATH_SetVelocity(pPath, DATATBLS_ApplyRatio(nVelocity, sub_004C9460_GetSkillParam1(nSkillId) + nBonus, 100), ".\\SKILLS\\SkilPal.cpp", 816);
    D2Common_10142(pPath, pUnit, 0);
    SKILLS_SetFlags(pSkill, 0x1001);
    STATES_ToggleState(pUnit, 18, 1);
    return 1;
}
