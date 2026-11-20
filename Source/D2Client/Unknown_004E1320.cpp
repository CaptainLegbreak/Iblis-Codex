#include "D2Structs.h"
#ifdef MOVED_TEST
#define UNIT_FLAG 0x20
#define COUNT_BIAS 8
#define MIN_COUNT 2
#define BURST_MULT 3
#else
#define UNIT_FLAG 0x40
#define COUNT_BIAS 6
#define MIN_COUNT 1
#define BURST_MULT 1
#endif
struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2InventoryStrc;
struct D2GfxLightStrc;
struct D2MissilesTxt;
struct D2SkillsTxt
{
#ifdef MOVED_TEST
    int movedPrefix[2];
#endif
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char unk0x00C[0x0A];
    unsigned char nSeqInput;
    char unk0x017[0x4D];
    int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    short wCltMissileD;
    char unk0x0F2[0x1A];
    short wPrgOverlay;
    short wPrgSound;
    char unk0x110[0x04];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    int dwParam[8];
    char unk0x168[0xD4];
};
struct D2DataTablesStrc
{
#ifdef MOVED_TEST
    int movedPrefix;
#endif
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall sub_004CED60(D2UnitStrc* pMissile, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CED60
static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}
// 0x004E1320
int __fastcall sub_004E1320(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= UNIT_FLAG;
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;
    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraRangeCalc, nSkillId, nSkillLevel) - COUNT_BIAS;
    if (nCount < MIN_COUNT)
        nCount = MIN_COUNT;
    int nPerStep = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkillId, nSkillLevel);
    sub_004CED60(pUnit, nTargetX, nTargetY, nCount, nMissile, nSkillId, nSkillLevel, nPerStep, BURST_MULT);
    return 1;
}
