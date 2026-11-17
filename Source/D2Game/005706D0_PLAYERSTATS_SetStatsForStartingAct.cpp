struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2CharStatsTxt
{
    char unk0x00[0x30];
    unsigned char nStr;
    unsigned char nDex;
    unsigned char nInt;
    unsigned char nVit;
    unsigned char nStamina;
    unsigned char nLifeAdd;
    char unk0x36[0x8E];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

#define STAT_STRENGTH 0
#define STAT_ENERGY 1
#define STAT_DEXTERITY 2
#define STAT_VITALITY 3
#define STAT_HITPOINTS 6
#define STAT_MAXHP 7
#define STAT_MANA 8
#define STAT_MAXMANA 9
#define STAT_STAMINA 10
#define STAT_MAXSTAMINA 11
#define STAT_LEVEL 12
#define STAT_TOHIT 19
#define STAT_TOBLOCK 20
#define STAT_NEXTEXP 30
#define STAT_VELOCITYPERCENT 67
#define STAT_ATTACKRATE 68
#define STAT_OTHER_ANIMRATE 69

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnActCount_007326B4;                                                                             // 0x007326B4
extern const int gnActEntries_006E1520[5];                                                                  // 0x006E1520
void __fastcall sub_0057EB10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEntry);                             // 0x0057EB10
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel);                                           // 0x00611800
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
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
