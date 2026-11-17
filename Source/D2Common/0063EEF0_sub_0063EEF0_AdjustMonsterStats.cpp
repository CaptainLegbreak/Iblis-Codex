struct D2UnitStrc { int dwUnitType; int dwClassId; };
struct D2MonStatsTxt { char unk_00[0x4C]; unsigned char nSpecial; char unk_4D[0x5D]; short nLevel; };
struct D2DifficultyStatStrc { int stat; int numerator1; int denominator1; int numerator2; int denominator2; };
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int monsterId); // 0x00451F80
int __fastcall DATATBLS_ApplyRatio(int value, int numerator, int denominator); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* unit, int stat, int layer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* unit, int stat, int value, int layer); // 0x00627260
extern const D2DifficultyStatStrc gaDifficultyStats_006EA9F0[3]; // 0x006EA9F0

// 0x0063EEF0
void __stdcall sub_0063EEF0_AdjustMonsterStats(D2UnitStrc* unit, int mode, unsigned char difficulty)
{
    if (mode || !difficulty)
        return;
    const int nType = unit ? unit->dwUnitType : 6;
    if (nType != 1)
        return;
    D2MonStatsTxt* record = DATATBLS_GetMonStatsTxtRecord(unit->dwClassId);
    if (!record || record->nSpecial == 1)
        return;
    const D2DifficultyStatStrc* p = gaDifficultyStats_006EA9F0;
    for (int i = 0; i < 3; ++i, ++p)
    {
        int value = STATLIST_UnitGetStatValue(unit, p->stat, 0);
        int numerator;
        int denominator;
        if (difficulty == 1)
        {
            numerator = p->numerator1;
            denominator = p->denominator1;
        }
        else
        {
            numerator = p->numerator2;
            denominator = p->denominator2;
        }
        STATLIST_SetUnitStat(unit, p->stat, DATATBLS_ApplyRatio(value, numerator, denominator), 0);
    }
    STATLIST_SetUnitStat(unit, 12, record->nLevel + 25 * difficulty, 0);
}

#include "gen/data/Source/D2Common/0063EEF0_sub_0063EEF0_AdjustMonsterStats.inc"
