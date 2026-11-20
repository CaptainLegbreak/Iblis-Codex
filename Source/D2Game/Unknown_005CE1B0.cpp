#include "D2Game.h"
#include "D2Structs.h"

struct D2MissilesTxt;


struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x3C];
    short wSrvMissileA;
    char unk0x04A[0x1F2];
};
typedef char chk_D2SkillsTxt_size[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                          // 0x0046ACE0
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
D2UnitStrc* __fastcall sub_6FD11710(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005CE1B0
int __fastcall SKILLS_SrvDo110_Hireable_RogueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nMissileId = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
    if (nMissileId && nMissileId != 0x1F)
    {
        if (sub_0046ACE0(nMissileId))
        {
            sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
            return 1;
        }

        return 0;
    }

    nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !sub_0046ACE0(nMissileId))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[1 >> 3] & gdwBitMasks[1 & 7])
    {
        sub_6FD11710(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        return 1;
    }

    sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
}
