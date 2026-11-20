#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};



enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    SKILL_HOWL = 130,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax);                                     // 0x00472210
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C3E0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5); // 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6); // 0x005FDD60
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005BFA10
int __fastcall SKILLITEM_EventFunc08_Howl(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (sub_00472210_SeedRollMasked(&pAttacker->pSeed, 128) >= nChance)
    {
        return 0;
    }

    AIUTIL_ApplyTerrorCurseState(pGame, pAttacker, pUnit, SKILL_HOWL, 20, 20);
    return 1;
}

// 0x005C0470
int __fastcall SKILLITEM_EventFunc20_SkillOnAttackHitKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if (pDamage && !(pDamage->dwHitFlags & DAMAGEHITFLAG_0x20))
    {
        return 0;
    }

    if ((int)(SEED_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nTriggeredSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_ITEMTGTDO >> 3] & gdwBitMasks[SKILLSFLAGINDEX_ITEMTGTDO & 7])
    {
        if (pUnit)
        {
            SKILLITEM_CastSkillOnTarget(pUnit, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
            return 1;
        }
    }
    else
    {
        if (pUnit)
        {
            SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 1);
            return 1;
        }

        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 1);
    }

    return 1;
}

// 0x005C05A0
int __fastcall SKILLITEM_EventFunc21_SkillOnGetHit(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if (!pDamage)
    {
        return 0;
    }

    if (!(pDamage->wResultFlags & DAMAGERESULTFLAG_GETHIT))
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    if (!sub_0045C4B0_GetSkillsTxtRecord(nTriggeredSkillId))
    {
        return 0;
    }

    if (!pUnit)
    {
        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 0);
    }
    else
    {
        SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
    }

    return 1;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C0670
int __fastcall SKILLITEM_EventFunc30_SkillOnDeathLevelup(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    const int nLayer = (unsigned short)nSkillId;
    const int nTriggeredSkillId = nLayer >> sgptDataTables->nStuff;
    const int nTriggeredSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
    if ((int)(SEED_RollRandomNumber(&pAttacker->pSeed) % 100) >= nChance)
    {
        return 0;
    }

    if (!SKILLS_GetSkillsTxtRecord(nTriggeredSkillId))
    {
        return 0;
    }

    if (!pUnit)
    {
        SKILLITEM_CastSkillOnPosition(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, D2COMMON_10175_PathGetFirstPointX(pAttacker->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pAttacker->pDynamicPath), 0);
    }
    else
    {
        SKILLITEM_CastSkillOnTarget(pAttacker, nTriggeredSkillId, nTriggeredSkillLevel, pUnit, 0);
    }

    return 1;
}
