struct D2GameStrc;
struct D2UnitEventStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
};

enum D2C_SkillItemConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    UNITEVENT_13 = 13,
};

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2);

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __fastcall sub_005C07A0_UnitEventCallback(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2); // 0x005C07A0
D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_INVALID;
    }

    return pUnit->dwUnitType;
}

// 0x005C09E0
int __fastcall sub_005C09E0_SkillItemEventFunc_Reanimate(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE_CHAMPION))
    {
        return 0;
    }

    const int nChance = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (nChance <= 0)
    {
        return 0;
    }

    if (ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed, 100) >= nChance)
    {
        return 0;
    }

    while (pAttacker)
    {
        if (sub_0044BE50(pAttacker) == UNIT_PLAYER)
        {
            const int nOwnerId = pAttacker->dwUnitId;
            D2UnitStrc* pEventUnit = static_cast<D2UnitStrc* const volatile&>(pUnit);
            D2GameStrc* pOwnerGame = static_cast<D2GameStrc* const volatile&>(pGame);
            SUNITEVENT_Register(pOwnerGame, pEventUnit, UNITEVENT_13, static_cast<unsigned short>(nSkillId), nOwnerId, sub_005C07A0_UnitEventCallback, 0, nOwnerId);
            return 1;
        }

        pAttacker = AIGENERAL_GetMinionOwner(pAttacker);
    }

    return 0;
}
