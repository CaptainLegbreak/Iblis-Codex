struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2MonStatsTxt
{
    char unk0x000[0x32];
    short nVelocity;
    char unk0x034[0x1A8 - 0x34];
};

struct D2MonUModTxt
{
    char unk0x00[0x1C];
    int dwConstants;
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x34];
    int nDamageBonusPercent;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC50 - 0xA84];
    D2MonUModTxt* pMonUModTxt;
    int nMonUModTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                    // 0x00611D30
int __fastcall sub_00463860_GetMonsterId(D2UnitStrc* pUnit);                                                // 0x00463860
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId);                                             // 0x00463900

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline int MONSTERUNIQUE_GetUModConstantInline(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }
    D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nUMod];
    if (!pMonUModTxtRecord)
    {
        return 0;
    }
    return pMonUModTxtRecord->dwConstants;
}

// 0x005A0E80
void __fastcall sub_005A0E80_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nMode, int bApply)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pUnit->dwClassId);
    if (!pMonStatsTxtRecord || !bApply)
    {
        return;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    STATLIST_SetUnitStat(pUnit, 12, nLevel + -1, 0);
    const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, 13, 0);
    STATLIST_SetUnitStat(pUnit, 13, nExperience - 2 * (nExperience / 5), 0);

    int nDamage = MONSTERUNIQUE_GetUModConstantInline(11);
    int nToHit = MONSTERUNIQUE_GetUModConstantInline(10);

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pDifficultyLevelsTxtRecord)
    {
        nDamage = nDamage * pDifficultyLevelsTxtRecord->nDamageBonusPercent / 100;
        nToHit = nToHit * pDifficultyLevelsTxtRecord->nDamageBonusPercent / 100;
        if (MONSTERS_GetBaseIdFromMonsterId(sub_00463860_GetMonsterId(pUnit)) == 118)
        {
            nDamage /= 2;
        }
    }

    STATLIST_AddUnitStat(pUnit, 25, nDamage, 0);
    STATLIST_AddUnitStat(pUnit, 119, nToHit, 0);

    if (pMonStatsTxtRecord->nVelocity <= 0 || nMode == 36)
    {
        return;
    }

    switch (nMode)
    {
    case 36:
        STATLIST_AddUnitStat(pUnit, 67, -33, 0);
        break;

    case 37:
    {
        int nVelocity = 0x800 / pMonStatsTxtRecord->nVelocity;
        nVelocity -= 0x80;
        nVelocity = D2_MIN(D2_MAX(nVelocity, 10), 100);
        STATLIST_AddUnitStat(pUnit, 67, nVelocity, 0);
        break;
    }

    default:
        STATLIST_AddUnitStat(pUnit, 67, 20, 0);
        break;
    }
}
