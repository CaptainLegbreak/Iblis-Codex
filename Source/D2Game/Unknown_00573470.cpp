#include "D2Game.h"

#define UNIT_MONSTER 1
#define BONUS_TABLE_SIZE 9
#define HP_BONUS_STEP 50
#define HP_BONUS_BASE 2
#define XP_BONUS_BASE 130

struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2MonsterDataStrc;
struct Data005734C0;
struct Unit005734C0;
struct Data005734E0;
struct Unit005734E0;
struct Data00573500;
struct Unit00573500;
struct Data00573520;
struct Unit00573520;
struct Data00573540;
struct Unit00573540;
struct Data00573570;
struct Unit00573570;

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

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnHpBonusTable[9]; // 0x006E1590
extern const int gnExperienceBonusTable[9]; // 0x006E15B4

struct Data005734C0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };

struct Unit005734C0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005734C0* pData;
};

struct Data005734E0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };

struct Unit005734E0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data005734E0* pData; };

struct Data00573500 { unsigned char bUnknown00[0x58]; unsigned int dwValue58; };

struct Unit00573500 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573500* pData;
};

struct Data00573520 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwValue58;
};

struct Unit00573520 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573520* pData;
};

struct Data00573540 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned short wFlags5C;
};

struct Unit00573540 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573540* pData;
};

struct Data00573570 { unsigned char bUnknown00[0x5C]; unsigned short wFlags5C; };

struct Unit00573570 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00573570* pData; };

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

#include "gen/data/Source/D2Game/Unknown_00573470.inc"

// 0x005734C0
extern "C" __declspec(dllexport) void __fastcall sub_005734C0(Unit005734C0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue54 = dwValue;
    }
}

// 0x005734E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005734E0(Unit005734E0* pUnit) {
    Data005734E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 1;
    }
    return pData->dwValue54;
}

// 0x00573500
extern "C" __declspec(dllexport) void __fastcall sub_00573500(Unit00573500* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue58 = dwValue;
    }
}

// 0x00573520
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00573520(Unit00573520* pUnit) {
    Data00573520* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return pData->dwValue58;
}

// 0x00573540
extern "C" __declspec(dllexport) int __fastcall sub_00573540(Unit00573540* pUnit, unsigned short wMask) {
    Data00573540* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags5C & wMask) != 0;
}

// 0x00573570
extern "C" __declspec(dllexport) void __fastcall sub_00573570(Unit00573570* pUnit, unsigned short wMask, int bSet) {
    if (pUnit && pUnit->nType == 1) {
        Data00573570* pData = pUnit->pData;
        if (pData) {
            if (bSet) {
                pData->wFlags5C |= wMask;
            } else {
                pData->wFlags5C &= ~wMask;
            }
        }
    }
}
