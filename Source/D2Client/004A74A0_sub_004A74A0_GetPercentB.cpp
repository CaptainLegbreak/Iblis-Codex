struct D2GfxLightStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct Unicode;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2Vector3FStrc
{
    float fX;
    float fY;
    float fZ;
};

struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
};

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

struct D2HirelingTxt
{
    char unk0x00[0x1C];
    int nHirelingLevel;
    char unk0x20[0x58];
    int dwSkill[6];
    char unk0x90[0x30];
    char nMode[6];
    char nLevel[6];
    char nSLvlPerLvl[6];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x5C];
    D2GfxLightStrc* pLight;
    char unk0x68[0x5C];
    unsigned int dwFlags;
};

struct D2MonStats2Txt
{
    char unk0x000[0x11E];
    unsigned char nLight;
    unsigned char nLight_R;
    unsigned char nLight_G;
    unsigned char nLight_B;
    char unk0x122[0x12];
};

struct D2MonStatsTxt
{
    char unk0x00[0x4C];
    unsigned char nAlign;
    char unk0x4D[0x5D];
    short nLevel[3];
    char unk0xB0[0xF8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x11C];
    int nSkillsTxtRecordCount;
};

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit);                                                          // 0x006223F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
int __cdecl sub_00466DD0();                                                                                 // 0x00466DD0
int __cdecl sub_0044DCA0_GetGameType();                                                                     // 0x0044DCA0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
unsigned char __stdcall sub_0063EBD0_GetLightRadius(D2UnitStrc* pUnit);                                     // 0x0063EBD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_00464CF0(D2UnitStrc* pUnit, int nRadius);                                // 0x00464CF0

int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, unsigned short nNameId);        // 0x00663750
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);        // 0x0063E810
void __fastcall sub_004C1C10(D2UnitStrc* pUnit);                                                            // 0x004C1C10
extern "C" const char gszMonsterSourceFile_006DA5C8[];                                                       // 0x006DA5C8

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                     // 0x00620900
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY);                                           // 0x004E4160

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_LEVEL 12
#define STAT_ARMORCLASS_VS_HTH 33

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x004A74A0
int __cdecl sub_004A74A0_GetPercentB()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    int nPercent = 100;
    int nDefense = UNITS_GetDefense(pPlayer);
    nDefense += STATLIST_UnitGetStatValue(pPlayer, STAT_ARMORCLASS_VS_HTH, 0);
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 470);

    const int nMonsterId = sub_00466DD0();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 8, &monStatsInit);
    int nToHit = monStatsInit.nTH;
    if (!nToHit)
    {
        memset(&monStatsInit, 0, sizeof(monStatsInit));
        DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 0x10, &monStatsInit);
        nToHit = monStatsInit.nTH;
        if (!nToHit)
        {
            memset(&monStatsInit, 0, sizeof(monStatsInit));
            DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 0x20, &monStatsInit);
            nToHit = monStatsInit.nTH;
        }
    }

    if (pMonStatsTxtRecord->nAlign != 1 && !sub_0044DCC0() && sub_0044DCD0_GetDifficulty())
    {
        nToHit = nToHit * 10 / 15;
    }

    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nPercent = nToHit * 100 / (nToHit + nDefense);
    }

    const int nLevel = pMonStatsTxtRecord->nLevel[nDifficulty];
    return 2 * nLevel * nPercent / (STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0) + nLevel);
}

// 0x004AE210
void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    unsigned char nLight = sub_0063EBD0_GetLightRadius(pUnit);
    if (nLight < pMonStats2TxtRecord->nLight)
    {
        nLight = pMonStats2TxtRecord->nLight;
    }

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == 8 && sub_004B92E0_GetTableByte(0, 1) && !sub_00451F30_TestUnitFlag(pUnit, 0x200000)
        && pMonStatsTxtRecord->nAlign != 1 && pMonStatsTxtRecord->nAlign != 2)
    {
        nLight = 3;
    }
    else if (!nLight)
    {
        return;
    }

    D2GfxLightStrc* pLight = sub_00474160_MakeLightEntry(pUnit, 0, nLight, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    if (pUnit->pLight)
    {
        sub_00464930_FreeLight(pUnit);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, nLight);
}

// 0x004B1090
void __fastcall sub_004B1090_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo)
{
    if (!pUnit || !pInfo)
    {
        return;
    }

    pUnit->dwFlags |= 0x202;
    const int nAct = MONSTERS_GetActFromHirelingTxt(sub_0044DCC0(), 0, pInfo->f_0);
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2HirelingInitStrc hirelingInit;
    if (!MONSTERS_HirelingInit(sub_0044DCC0(), sub_00463DD0(), pInfo->nSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    const int nLevel = hirelingInit.nLevel;
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(sub_0044DCC0(), hirelingInit.nId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;
    if (nLevelUps < 0)
    {
        nLevelUps = 0;
    }

    for (int i = 0; i < 6; ++i)
    {
        const int nSkillId = pHirelingTxtRecord->dwSkill[i];
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        int nSkillLevel = (pHirelingTxtRecord->nSLvlPerLvl[i] * nLevelUps >> 5) + pHirelingTxtRecord->nLevel[i];
        if (nSkillLevel >= 32)
        {
            nSkillLevel = 32;
        }

        const int nMode = pHirelingTxtRecord->nMode[i];
        SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, gszMonsterSourceFile_006DA5C8, 2504);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), nMode);
    }

    unsigned short wNameId = pInfo->f_0;
    if (wNameId == 0x421)
    {
        wNameId = 0x2B0D;
    }

    MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(wNameId));
    sub_004C1C10(pUnit);
}

// 0x004B9E10
int __fastcall sub_004B9E10_IsNearPlayer(D2UnitStrc* pUnit)
{
    D2Vector3FStrc tDelta;
    D2CoordStrc tPlayerCoords;
    D2CoordStrc tUnitCoords;
    D2UnitStrc* pPlayer = sub_00463DD0();
    UNITS_GetClientCoords(pPlayer, &tPlayerCoords);
    UNITS_GetClientCoords(pUnit, &tUnitCoords);
    tDelta.fX = tUnitCoords.nX - tPlayerCoords.nX;
    tDelta.fY = (tUnitCoords.nY - tPlayerCoords.nY) * 2.0f;
    if (sub_004E4160_LengthSquared2D(tDelta.fX, tDelta.fY) <= 490000.0)
    {
        return 1;
    }

    return 0;
}
