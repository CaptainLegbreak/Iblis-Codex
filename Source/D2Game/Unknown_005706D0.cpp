#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



#define STAT_ENERGY 1
#define STAT_DEXTERITY 2
#define STAT_VITALITY 3
#define STAT_HITPOINTS 6
#define STAT_MAXHP 7
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_MAXSTAMINA 11
#define STAT_LEVEL 12
#define STAT_TOHIT 19
#define STAT_TOBLOCK 20
#define STAT_ATTACKRATE 68

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

static void __stdcall sub_005706A0_UseActEntry(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }
    if (nAct >= gnActCount_007326B4)
    {
        nAct = 0;
    }
    sub_0057EB10(pGame, pUnit, gnActEntries_006E1520[nAct]);
}

// 0x005706D0
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }

    if (!pPlayer)
    {
        return;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }

    STATLIST_SetUnitStat(pPlayer, STAT_STRENGTH, pCharStatsTxtRecord->nStr, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ENERGY, pCharStatsTxtRecord->nInt, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_DEXTERITY, pCharStatsTxtRecord->nDex, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VITALITY, pCharStatsTxtRecord->nVit, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_TOHIT, 0, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_TOBLOCK, 0, 0);
    const int nLife = (pCharStatsTxtRecord->nVit + pCharStatsTxtRecord->nLifeAdd) << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXHP, nLife, 0);
    const int nMana = pCharStatsTxtRecord->nInt << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXMANA, nMana, 0);
    const int nStamina = pCharStatsTxtRecord->nStamina << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, nStamina, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXSTAMINA, nStamina, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_LEVEL, 1, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_NEXTEXP, DATATBLS_GetLevelThreshold(!pPlayer ? -1 : pPlayer->dwClassId, 1), 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_OTHER_ANIMRATE, 100, 0);

    if (nAct > 0)
    {
        sub_005706A0_UseActEntry(pGame, pPlayer, nAct);
    }
}
