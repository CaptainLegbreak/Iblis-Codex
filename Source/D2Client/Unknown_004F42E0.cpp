#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2SkillsTxt
{
    char pad00[0x138];
    unsigned int calc1;
    char pad13C[0x100];
};
struct D2DataTablesStrc
{
    char pad00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc*); // 0x00620250
int __fastcall sub_004C7BD0_GetMeleeRangePlus4(D2UnitStrc*); // 0x004C7BD0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc*); // 0x004648F0
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc*, int, int, int, int, int, int*); // 0x004C5EB0
int __fastcall sub_004C5E30_ScanCount(D2UnitStrc*, int, int, int, int); // 0x004C5E30
void __stdcall SKILLS_SetParam1(D2SkillStrc*, int); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc*, int); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc*, int); // 0x006445E0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
void __stdcall D2Common_10216(D2DynamicPathStrc*, int, int, int); // 0x00649EF0

static __forceinline int UNITS_GetXPosition(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case 2: case 4: case 5: return unit->pStaticPath->nXPos;
    }
    return unit->pDynamicPath ? PATH_GetXPosition(unit->pDynamicPath) : 0;
}
static __forceinline int UNITS_GetYPosition(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case 2: case 4: case 5: return unit->pStaticPath->nYPos;
    }
    return unit->pDynamicPath ? PATH_GetYPosition(unit->pDynamicPath) : 0;
}

// 0x004F42E0
int __fastcall sub_004F42E0_SkillStartMeleeTarget(D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2SkillsTxt* record = 0;
    if (skillId >= 0 && skillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        record = &sgptDataTables->pSkillsTxt[skillId];
    }
    if (!record) return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill) return 0;
    int range = sub_004C7BD0_GetMeleeRangePlus4(unit);
    D2UnitStrc* target = sub_004648F0_GetTargetUnit(unit);
    int count = 0;
    if (!target)
    {
        target = sub_004C5EB0_FindDestination(unit, 0, 0, range, 0x20003, -1, &count);
        if (!target)
        {
            SKILLS_SetParam1(skill, 0);
            return 1;
        }
    }
    else
    {
        count = sub_004C5E30_ScanCount(unit, 0, 0, range, 0x20003);
    }
    int max = SKILLS_EvaluateSkillFormula(unit, record->calc1, skillId, skillLevel);
    if (count >= max)
    {
        count = max;
    }
    SKILLS_SetParam1(skill, count);
    int posY = UNITS_GetYPosition(target);
    D2Common_10216(unit->pDynamicPath, UNITS_GetXPosition(target), posY, 0);
    int targetType = target ? target->dwUnitType : 6;
    SKILLS_SetParam2(skill, targetType);
    range = target ? target->dwUnitId : -1;
    SKILLS_SetParam3(skill, range);
    return 1;
}
