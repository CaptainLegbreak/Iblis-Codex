#include "D2Game.h"

#define UNIT_MONSTER 1
#define STAT_HITPOINTS 6
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
};

struct D2SkillsTxt
{
    unsigned char unk0x000[0x138];
    unsigned int dwCalc[4];
    unsigned char unk0x148[0x23C - 0x148];
};

struct D2DataTablesStrc
{
    unsigned char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005CDC10
int __fastcall sub_005CDC10_ConsumeCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        const int nType = pTarget ? pTarget->dwUnitType : 6;
        if (nType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pTarget) && pTarget->dwAnimMode == 12)
        {
            const int nCorpseLife = STATLIST_GetMaxLifeFromUnit(pTarget);
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), UNIT_MONSTER, !pTarget ? -1 : pTarget->dwUnitId);
            SUNIT_RemoveUnit(pGame, pTarget);

            int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
            const int nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (nCorpseLife > 0)
            {
                nHitpoints += DATATBLS_ApplyRatio(nCorpseLife, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel), 100);
                nHitpoints = D2_MIN(D2_MAX(nHitpoints, 1), nMaxHitpoints);
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
            }

            return 1;
        }
    }

    return 0;
}
