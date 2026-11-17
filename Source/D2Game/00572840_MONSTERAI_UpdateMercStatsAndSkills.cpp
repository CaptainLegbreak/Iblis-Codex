struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2PetInfoStrc
{
    char unk0x00[0x08];
    int nHirelingId;
};

struct D2SkillsTxt
{
    char unk0x000[0x174];
    short wReqLevel;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
};

struct D2HirelingTxt
{
    char unk0x00[0x1C];
    int nHirelingLevel;
    int dwExpPerLvl;
    int dwHitpoints;
    int dwHitpointsPerLvl;
    int dwDefense;
    int dwDefensePerLvl;
    int nStr;
    int nStrPerLvl;
    int nDex;
    int nDexPerLvl;
    int dwAttackRate;
    int dwAttackRatePerLvl;
    int dwShare;
    int nDmgMin;
    int nDmgMax;
    int nDmgPerLvl;
    int dwResist;
    int dwResistPerLvl;
    char unk0x64[0x14];
    int dwSkill[6];
    char unk0x90[0x30];
    signed char nMode[6];
    signed char nLevel[6];
    signed char nSLvlPerLvl[6];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __fastcall AITACTICS_AddMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScrollTarget, unsigned short wMessage, int bScrollMessage); // 0x005DE330
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID);               // 0x00574BD0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0
int __stdcall DATATBLS_GetMaxLevel(int nClass);                                                             // 0x00611830
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel);                            // 0x00663790
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0

// 0x00572840
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, int nLevel)
{
    D2_ASSERT(pGame, 0xE0);
    D2_ASSERT(pPlayer, 0xE1);
    D2_ASSERT(pPlayer->dwUnitType == 0, 0xE2);

    D2UnitStrc* pHireling = pMerc;
    if (!pHireling)
    {
        pHireling = sub_6FC7E8B0(pGame, pPlayer, 7, 0);
        if (!pHireling)
        {
            return;
        }
    }

    STATLIST_UnitGetStatValue(pPlayer, 0xC, 0);
    const int nHirelingLevel = STATLIST_UnitGetStatValue(pHireling, 0xC, 0);
    if (!nLevel)
    {
        nLevel = nHirelingLevel + 1;
    }

    AITACTICS_AddMessage(pGame, pHireling, pPlayer, 0xD7C, 1);
    STATLIST_SetUnitStat(pHireling, 0xC, nLevel, 0);

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, pHireling->dwUnitId);
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    const int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;

    const int nNextExp = nLevel >= DATATBLS_GetMaxLevel(0) - 1 ? 0 : MONSTERS_GetHirelingExpForNextLevel(nLevel + 1, pHirelingTxtRecord->dwExpPerLvl);
    STATLIST_SetUnitStat(pHireling, 0x1E, nNextExp, 0);

    const int nExperience = MONSTERS_GetHirelingExpForNextLevel(nLevel, pHirelingTxtRecord->dwExpPerLvl);
    if (STATLIST_UnitGetStatValue(pHireling, 0xD, 0) < nExperience)
    {
        STATLIST_SetUnitStat(pHireling, 0xD, nExperience, 0);
    }

    int nStrength = pHirelingTxtRecord->nStr + nLevelUps * pHirelingTxtRecord->nStrPerLvl / 8;
    nStrength = nStrength < 10 ? 10 : nStrength;
    STATLIST_SetUnitStat(pHireling, 0, nStrength, 0);

    int nDexterity = pHirelingTxtRecord->nDex + nLevelUps * pHirelingTxtRecord->nDexPerLvl / 8;
    nDexterity = nDexterity < 10 ? 10 : nDexterity;
    STATLIST_SetUnitStat(pHireling, 2, nDexterity, 0);

    int nHitpoints = (pHirelingTxtRecord->dwHitpoints << 8) + nLevelUps * (pHirelingTxtRecord->dwHitpointsPerLvl << 8);
    nHitpoints = nHitpoints < 0x2800 ? 0x2800 : nHitpoints;
    STATLIST_SetUnitStat(pHireling, 7, nHitpoints, 0);
    STATLIST_SetUnitStat(pHireling, 6, nHitpoints, 0);

    int nDefense = pHirelingTxtRecord->dwDefense + nLevelUps * pHirelingTxtRecord->dwDefensePerLvl;
    nDefense = nDefense < 0 ? 0 : nDefense;
    STATLIST_SetUnitStat(pHireling, 0x1F, nDefense, 0);

    int nMinDamage = pHirelingTxtRecord->nDmgMin + nLevelUps * pHirelingTxtRecord->nDmgPerLvl / 8;
    nMinDamage = nMinDamage < 0 ? 0 : nMinDamage;
    STATLIST_SetUnitStat(pHireling, 0x17, nMinDamage, 0);

    int nMaxDamage = pHirelingTxtRecord->nDmgMax + nLevelUps * pHirelingTxtRecord->nDmgPerLvl / 8;
    nMaxDamage = nMaxDamage < 1 ? 1 : nMaxDamage;
    STATLIST_SetUnitStat(pHireling, 0x18, nMaxDamage, 0);

    int nAttackRate = pHirelingTxtRecord->dwAttackRate + nLevelUps * pHirelingTxtRecord->dwAttackRatePerLvl;
    nAttackRate = nAttackRate < 0 ? 0 : nAttackRate;
    STATLIST_SetUnitStat(pHireling, 0x13, nAttackRate, 0);

    int nResist = pHirelingTxtRecord->dwResist + nLevelUps * pHirelingTxtRecord->dwResistPerLvl / 4;
    nResist = nResist < 0 ? 0 : nResist;
    STATLIST_SetUnitStat(pHireling, 0x27, nResist, 0);
    STATLIST_SetUnitStat(pHireling, 0x29, nResist, 0);
    STATLIST_SetUnitStat(pHireling, 0x2B, nResist, 0);
    STATLIST_SetUnitStat(pHireling, 0x2D, nResist, 0);

    int nHpRegen = STATLIST_GetUnitBaseStat(pHireling, 7, 0) / 2000;
    nHpRegen = nHpRegen < 0 ? 0 : nHpRegen;
    STATLIST_SetUnitStat(pHireling, 0x4A, nHpRegen, 0);

    for (int i = 0; i < 6; ++i)
    {
        if (pHirelingTxtRecord->dwSkill[i] <= 0 || pHirelingTxtRecord->dwSkill[i] >= sgptDataTables->nSkillsTxtRecordCount || pHirelingTxtRecord->nMode[i] >= 16)
        {
            return;
        }

        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pHirelingTxtRecord->dwSkill[i]);
        if (pSkillsTxtRecord && nLevel >= pSkillsTxtRecord->wReqLevel)
        {
            int nSkillLevel = pHirelingTxtRecord->nLevel[i] + (nLevelUps * pHirelingTxtRecord->nSLvlPerLvl[i] >> 5);
            nSkillLevel = nSkillLevel > 0 ? nSkillLevel : 0;
            nSkillLevel = nSkillLevel < 32 ? nSkillLevel : 32;
            if (nSkillLevel > 0)
            {
                D2GAME_SetSkills_6FD14C60(pHireling, pHirelingTxtRecord->dwSkill[i], nSkillLevel, 0);
            }
        }
    }
}
