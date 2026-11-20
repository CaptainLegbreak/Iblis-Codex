#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"


struct D2SkillsTxt
{
    char unk0x000[0x23C];
};


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);              // 0x004B9A00
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0
void __fastcall sub_004C76D0_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent);                            // 0x004C76D0
int __fastcall sub_004C7BD0_GetMeleeRangePlus4(D2UnitStrc* pUnit);                                          // 0x004C7BD0
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg);                                                   // 0x004CA4C0
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId);                                                   // 0x004EFC20
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);               // 0x00622C40
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit);                                                        // 0x00623C20
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F4C20
int __fastcall sub_004F4C20_CltDoRepeatAttack(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nTargetId = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = sub_00463990(nTargetId, SKILLS_GetParam2(pSkill));
    const int nRange = sub_004C7BD0_GetMeleeRangePlus4(pUnit);
    if (!pTarget || !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 0x20003, nTargetId, 0);
        if (!pTarget)
        {
            return 0;
        }
    }

    const int nCount = SKILLS_GetParam1(pSkill) - 1;
    SKILLS_SetParam1(pSkill, nCount);
    if (nCount > 0)
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 0x20003, !pTarget ? -1 : pTarget->dwUnitId, 0);
        if (!pTarget)
        {
            return 0;
        }

        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        SKILLS_SetParam2(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam3(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        sub_004C76D0_ScaleFramePrecise(pUnit, sub_004EFC20_GetSkillParam2(SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillsAma.cpp", 592)));
        const int nHitClass = UNITS_GetHitClass(pUnit);
        sub_004B9A00(sub_004CA4C0(pUnit, nHitClass), pUnit, 0, 0, 0);
    }

    return 1;
}
