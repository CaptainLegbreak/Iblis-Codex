#include "D2Game.h"
#include "D2Structs.h"
#include "D2Txt.h"

D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int bIncludeDead); // 0x00574EC0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, unsigned short nLayer); // 0x00627260
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, unsigned short nLayer); // 0x00625480

int SKILLS_AddLifeAndGetGain(D2UnitStrc* pUnit, int nValue); // 0x005C5F10

static __forceinline int sub_IsBloodGolem(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_MONSTER && (!pUnit ? -1 : pUnit->dwClassId) == 290;
}

// 0x005C6870
int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nLife)
{
    if (!pUnit)
    {
        return nLife;
    }

    D2UnitStrc* pBloodGolem = PLAYERPETS_GetFirstPetByType(pGame, pUnit, 3, 0);
    if (!sub_IsBloodGolem(pBloodGolem))
    {
        return nLife;
    }

    if (nLife)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pBloodGolem->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill[0] >= 0)
        {
            const int nParam = SKILLDESC_GetSkillParamSix(pMonStatsTxtRecord->nSkill[0]);
            const int nResult = nLife - SKILLS_AddLifeAndGetGain(pBloodGolem, nParam * nLife / 100);

            return nResult;
        }
    }
    else
    {
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pBloodGolem);
        STATLIST_SetUnitStat(pBloodGolem, 6, nMaxHp, 0);
    }

    return nLife;
}
