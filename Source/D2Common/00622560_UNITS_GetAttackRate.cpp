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
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

#define UNIT_PLAYER 0
#define STAT_TOHIT 19
#define STAT_DEXTERITY 2

// build: context UNITS_GetCharStatsTxtRecord
static __forceinline D2CharStatsTxt* UNITS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        return &sgptDataTables->pCharStatsTxt[nClassId];
    return 0;
}

// build: context UNITS_GetToHitFactor
static __forceinline int UNITS_GetToHitFactor(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = UNITS_GetCharStatsTxtRecord(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    return pCharStatsTxtRecord->dwToHitFactor;
}

// 0x00622560
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker)
{
    const int bValid = pAttacker && pAttacker->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bValid, 0x107F);

    int nAttackRate = STATLIST_UnitGetStatValue(pAttacker, STAT_TOHIT, 0);
    int nDexterity = STATLIST_UnitGetStatValue(pAttacker, STAT_DEXTERITY, 0);
    nDexterity -= 7;
    nAttackRate += 5 * nDexterity;

    return nAttackRate + UNITS_GetToHitFactor(pAttacker);
}
