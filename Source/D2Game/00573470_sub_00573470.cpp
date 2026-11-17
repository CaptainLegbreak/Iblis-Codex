struct D2MonStatsTxt
{
    char unk0x00[26];
    short wMonStatsEx;
    char unk0x1C[396];
};
struct D2MonStats2Txt
{
    char unk0x00[312];
};
struct D2DataTablesStrc
{
    char unk0x00[2680];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[428];
    D2MonStats2Txt* pMonStats2Txt;
    int nMonStats2TxtRecordCount;
};
struct D2MonsterDataStrc
{
    char unk0x00[4];
    unsigned char nComponent[16];
};
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnHpBonusTable[9];                                                                         // 0x006E1590
extern const int gnExperienceBonusTable[9];                                                                 // 0x006E15B4

#define UNIT_MONSTER 1
#define BONUS_TABLE_SIZE 9
#define HP_BONUS_STEP 50
#define HP_BONUS_BASE 2
#define XP_BONUS_BASE 130

// 0x00573470
D2MonStats2Txt* __fastcall sub_00573470(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (pMonStatsTxtRecord)
    {
        if (pMonStatsTxtRecord->wMonStatsEx >= 0 && pMonStatsTxtRecord->wMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[pMonStatsTxtRecord->wMonStatsEx];
        }
    }

    return 0;
}

// 0x005738F0
int __fastcall MONSTER_GetHpBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnHpBonusTable[nPlayerCount];
    }

    return (nPlayerCount - HP_BONUS_BASE) * HP_BONUS_STEP;
}

// 0x00573910
int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnExperienceBonusTable[nPlayerCount];
    }

    return 2 * (5 * nPlayerCount + XP_BONUS_BASE);
}

#include "gen/data/Source/D2Game/00573470_sub_00573470.inc"
