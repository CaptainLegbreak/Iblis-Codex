struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int nPad08;
    int nPad0C;
    int dwAnimMode;
};

struct D2GameStrc
{
    char pad0x00[0xA8];
    int dwGameFrame;
};

struct D2CharStatsTxt
{
    char pad0x00[0x3A];
    unsigned char nManaRegen;
    char pad0x3B[0xC4 - 0x3B];
};

struct D2DataTablesStrc
{
    char pad0x00[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit);                                            // 0x00625DB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                           // 0x00626CD0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent);                    // 0x00571A10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                            // 0x00639DF0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

static __forceinline unsigned char UNITS_GetHpPercent_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
        if (nMaxLife > 0 && nHitpoints < nMaxLife)
            return (nHitpoints << 7) / nMaxLife;
    }
    return 0x80;
}

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord_Inline(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        return &sgptDataTables->pCharStatsTxt[nClassId];
    return 0;
}

static __declspec(noinline) void EVENTS_StaminaRegen(D2UnitStrc* pUnit); // 0x00580500

// build: context EVENTS_StaminaRegen
static __declspec(noinline) void EVENTS_StaminaRegen(D2UnitStrc* pUnit)
{
    int nStamina = STATLIST_UnitGetStatValue(pUnit, 0xA, 0);
    int nShift = 8;
    const int nStaminaRecoveryBonus = STATLIST_UnitGetStatValue(pUnit, 0x1C, 0);

    switch (!pUnit ? 0 : pUnit->dwAnimMode)
    {
    case 6:
        nShift = 9;
        break;

    case 2:
        nShift = 9;
        if (nStamina >> 8)
            break;
        return;

    case 1:
    case 5:
        break;

    default:
        if (nStaminaRecoveryBonus < 1000)
            return;
        break;
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (nStamina < nMaxStamina)
    {
        int nAdd = nMaxStamina >> nShift;
        if (nStaminaRecoveryBonus)
            nAdd += (nStaminaRecoveryBonus * nAdd) / 100;

        nStamina += nAdd;
        if (nStamina > nMaxStamina)
            nStamina = nMaxStamina;

        STATLIST_SetUnitStat(pUnit, 0xA, nStamina, 0);
    }
}

static __declspec(noinline) int EVENTS_HpRegen(D2UnitStrc* pUnit); // 0x00580610

// build: context EVENTS_HpRegen
static __declspec(noinline) int EVENTS_HpRegen(D2UnitStrc* pUnit)
{
    const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, 0x4A, 0);
    if (nHpRegen)
    {
        const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
        int nLife = nHpRegen + nHitpoints;
        if (nLife > nMaxHp)
        {
            nLife = nMaxHp;
            D2StatListStrc* pHealthPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x64);
            if (pHealthPotStatList)
            {
                D2Common_10474(pUnit, pHealthPotStatList);
                STATLIST_FreeStatList(pHealthPotStatList);
            }
        }

        if (nLife < 0x100)
            nLife = 0x100;

        STATLIST_SetUnitStat(pUnit, 6, nLife, 0);

        const unsigned char nLastSentHpPct = STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
        const unsigned char nHpPct = UNITS_GetHpPercent_Inline(pUnit);

        int nHpPctDiff = nLastSentHpPct - nHpPct;
        if (nHpPctDiff < 0)
            nHpPctDiff = -nHpPctDiff;

        if (nHpPctDiff > 4)
        {
            SUNITMSG_QueueLifeUpdate(pUnit, nHpPct);
            STATLIST_SetUnitStat(pUnit, 0x160, nHpPct, 0);
        }
    }
    return 1;
}

// 0x005806F0
static __declspec(noinline) void EVENTS_ManaRegen(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);

        int nManaRecovery = 0;
        if (!STATES_CheckState(pUnit, 0x55))
        {
            D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord_Inline(pUnit->dwClassId);
            if (!pCharStatsTxtRecord)
                return;

            int nManaRegen = 25 * pCharStatsTxtRecord->nManaRegen;
            if (!nManaRegen)
                nManaRegen = 7500;

            int nManaMultiplier = nMaxMana / nManaRegen;
            if (nManaMultiplier < 1)
                nManaMultiplier = 1;

            nManaRecovery = DATATBLS_ApplyRatio(nManaMultiplier, STATLIST_UnitGetStatValue(pUnit, 0x1B, 0) + 100, 100);
        }

        nManaRecovery += STATLIST_UnitGetStatValue(pUnit, 0x1A, 0);
        if (nMaxMana <= nMana && nManaRecovery > 0)
        {
            D2StatListStrc* pManaPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x6A);
            if (pManaPotStatList)
            {
                D2Common_10474(pUnit, pManaPotStatList);
                STATLIST_FreeStatList(pManaPotStatList);
            }
        }

        if (nManaRecovery > nMaxMana - nMana)
            nManaRecovery = nMaxMana - nMana;

        if (nManaRecovery < -nMana)
            nManaRecovery = -nMana;

        if (nManaRecovery)
            STATLIST_AddUnitStat(pUnit, 8, nManaRecovery, 0);
    }
}

// 0x00580810
void __fastcall D2GAME_EVENTS_StatRegen_6FC80F80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, nEventCustomId, nEventCustomParam);
    if (SUNIT_IsDead(pUnit))
        return;

    if (EVENTS_HpRegen(pUnit))
    {
        EVENTS_StaminaRegen(pUnit);
        EVENTS_ManaRegen(pUnit);
    }
}
