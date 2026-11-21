#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#define UNIT_FLAG 0x40
struct D2DynamicPathStrc;
struct D2GameStrc;
struct D2MissilesTxt;
struct D2MonsterDataStrc;
struct D2SkillsTxt;
struct D2StaticPathStrc;
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
int __fastcall sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId);                          // 0x0056E450
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}
// 0x005CA3E0
int __fastcall sub_005CA3E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= UNIT_FLAG;
    if (!sub_6FD15340(pGame, pUnit, nMissileId))
        return 0;
    return D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, 0, 0) != 0;
}
