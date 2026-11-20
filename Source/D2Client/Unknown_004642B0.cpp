#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[];                                                      // 0x00711F34
int __stdcall sub_O05_EmitArg_SkillId(D2UnitStrc* pUnit);

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall sub_O05_Emit_004642B0(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pPlayer)))
    {
        return 1;
    }

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pTarget)) != 0;
}

#include "gen/data/Source/D2Client/Unknown_004642B0.inc"
