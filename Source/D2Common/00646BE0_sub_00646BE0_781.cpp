struct D2UnitStrc;
struct T00646BE0 { D2UnitStrc* pUnit; int nSkillId; int nSkillLevel; };
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel); // 0x00646460
// 0x00646BE0
int __fastcall sub_00646BE0(int nParamId, void* pUserData)
{
    if (!pUserData) return 0;
    T00646BE0* pContext = (T00646BE0*)pUserData;
    return SKILLS_GetSpecialParamValue(pContext->pUnit, nParamId, pContext->nSkillId, pContext->nSkillLevel);
}
