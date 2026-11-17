struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2CharStatsTxt
{
    char unk0x00[0x3C];
    int dwToHitFactor;
    char unk0x40[0x84];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

#define UNIT_PLAYER 0
#define STAT_DEXTERITY 2
#define STAT_TOHIT 19

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00622520
static __forceinline int sub_00622520_GetToHitFactor(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != UNIT_PLAYER)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    return pCharStatsTxtRecord->dwToHitFactor;
}

int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker)
{
    D2_ASSERT((pAttacker ? pAttacker->dwUnitType : 6) == UNIT_PLAYER, 4223);

    int nToHit = STATLIST_UnitGetStatValue(pAttacker, STAT_TOHIT, 0);
    int nDexterity = STATLIST_UnitGetStatValue(pAttacker, STAT_DEXTERITY, 0);
    int nAttackRate = nToHit + 5 * (nDexterity - 7);
    return nAttackRate + sub_00622520_GetToHitFactor(pAttacker);
}
