#include "D2Structs.h"
#include "D2DataTbls.h"
#ifdef MOVED_TEST
#define SHIFT 4
#define INVALID_UNIT 8
#else
#define SHIFT 0
#define INVALID_UNIT 6
#endif
struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillsTxt {
    char unk0x000[4 + SHIFT];
    unsigned char nFlags[8];
    char unk0x00C[0x120-0xC];
    unsigned char nItemTarget;
    char unk0x121[0x16A-0x121];
    short wItemEffect;
    char unk0x16C[0x23C-0x16C];
};
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __fastcall SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005FD850
int __fastcall sub_005FD9C0_SelectSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pUnitType, int* pUnitGUID); // 0x005FD9C0
int __fastcall sub_005FDA10_SelectOtherTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pUnitType, int* pUnitGUID); // 0x005FDA10
int __fastcall sub_6FD12950(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056F640
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0
inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}
// 0x005FDA80
int __fastcall sub_005FDA80_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int a7)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId) return 0;
    if (!pSkillsTxtRecord->wItemEffect) return 0;
    D2UnitStrc* pOldTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nOldX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    int nOldY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    int bOldFlag = (pUnit->dwFlags >> 6) & 1;
    if (pTargetUnit) UNITS_SetTargetUnitForDynamicUnit(pUnit, pTargetUnit);
    else D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    if (pUnitType) { *pUnitType = INVALID_UNIT; *pUnitGUID = -1; }
    if (pX) { *pX = 0; *pY = 0; }
    int nResult = 0;
    switch (pSkillsTxtRecord->nItemTarget) {
    case 1:
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pUnit);
        if (pUnitType) { *pUnitType = pUnit->dwUnitType; *pUnitGUID = pUnit->dwUnitId; }
        break;
    case 2:
        if (!SKILLITEM_FindTargetPosition(pGame, pUnit, nSkillId, nSkillLevel)) goto restore;
        if (pX) *pX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        if (pY) *pY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
        break;
    case 3:
        if (!sub_005FD9C0_SelectSkillTarget(pGame, pUnit, nSkillId, nSkillLevel, pUnitType, pUnitGUID)) goto restore;
        break;
    case 4:
        if (!sub_005FDA10_SelectOtherTarget(pGame, pUnit, nSkillId, nSkillLevel, pUnitType, pUnitGUID)) goto restore;
        break;
    }
    if ((pSkillsTxtRecord->nFlags[4] & gdwBitMasks[1]) && !sub_6FD12950(pGame, pUnit, nSkillId, nSkillLevel, 1)) goto restore;
    nResult = sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 0, 1, a7);
restore:
    if (pOldTarget) UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    else D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nOldX, nOldY);
    if (bOldFlag) pUnit->dwFlags |= 0x40;
    else pUnit->dwFlags &= ~0x40;
    return nResult;
}
