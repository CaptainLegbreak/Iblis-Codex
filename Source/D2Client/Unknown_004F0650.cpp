#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall shim_1(void* p1, void* p2);

// build: context sub_004F0590_CreateCltMissileRequest
static __declspec(noinline) void __stdcall sub_004F0590_CreateCltMissileRequest(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel, int a5)
{

    pUnit->dwFlags = 0;
    shim_1(&nMissile, &nSkillId);
    shim_1(&nSkillLevel, &a5);
}

// build: context sub_004F04F0_CreateMissileFan
static __declspec(noinline) void __stdcall sub_004F04F0_CreateMissileFan(D2UnitStrc* pUnit, int nCount, int nMissile, int nSkillId, int nSkillLevel)
{

    pUnit->dwFlags = 0;
    for (int i = 0; i < nCount; ++i)
    {
        shim_1(&nMissile, (void*)i);
    }
    shim_1(&nSkillId, &nSkillLevel);
}

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004F0650
int __fastcall sub_004F0650_CreateClientMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0 && nMissileA < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004F0590_CreateCltMissileRequest(pUnit, nMissileA, nSkillId, nSkillLevel, 0);
    }

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
        sub_004F04F0_CreateMissileFan(pUnit, nCount, nMissileB, nSkillId, nSkillLevel);
    }

    return 1;
}
