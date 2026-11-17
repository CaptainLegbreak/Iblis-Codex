struct D2GameStrc;

struct D2MonStatsTxt
{
    char unk0x00[0x170];
    short wSkill0x170;
};

struct D2DamageStrc
{
    char unk0x00[0x4C];
    int dwDmgTotal;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_HITPOINTS 6

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall sub_004E6C70(int nSkillId);                                                   // 0x004E6C70
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x005C6690
int __fastcall sub_005C6690_ShareDamageWithOwner(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pDamage)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pDamage->dwDmgTotal <= 0)
    {
        return 0;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (SUNIT_IsDead(pOwner))
    {
        return 0;
    }

    int nLife = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
    if (nLife < 0x100)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->wSkill0x170 >= 0)
    {
        const int nDamage = DATATBLS_ApplyRatio(pDamage->dwDmgTotal, sub_004E6C70(pMonStatsTxtRecord->wSkill0x170), 100);
        nLife -= nDamage;
        if (nLife < 0x100)
        {
            nLife = 0x100;
        }

        STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nLife, 0);
        pDamage->dwDmgTotal -= nDamage;
        pDamage->dwDmgTotal = pDamage->dwDmgTotal > 0 ? pDamage->dwDmgTotal : 0;
        return 1;
    }

    return 0;
}
