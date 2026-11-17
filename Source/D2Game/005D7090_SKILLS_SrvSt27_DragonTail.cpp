struct D2GameStrc;
struct D2SkillStrc;
struct D2InventoryStrc;
struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
    char unk0x28[0x10];
    int dwSeqFrame;
    char unk0x3C[0x24];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[20];
    unsigned int dwHitClass;
    int unk0x64[3];
};

struct D2SkillsTxt
{
    char unk0x00[0x138];
    unsigned int dwCalc[4];
    int dwParam[4];
    char unk0x158[0x4D];
    unsigned char nSrcDam;
    char unk0x1A6[0x96];
};

struct D2LevelsTxt
{
    char unk0x00[0x4];
    unsigned char nTeleport;
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);                                     // 0x005D3AC0
void __fastcall sub_6FCF5870(D2UnitStrc* pUnit, D2DamageStrc* pDamage);                                     // 0x005D3BA0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent); // 0x00646280
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                           // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                        // 0x006444A0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);               // 0x0057D690
void __fastcall sub_6FCF77E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage);                  // 0x005D5220
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
int __stdcall MONSTERS_IsBoss(void* pMonStatsTxtRecord, D2UnitStrc* pMonster);                              // 0x0063E9F0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
void __fastcall sub_0056E210(D2UnitStrc* pUnit, int nArg);                                                  // 0x0056E210
void __fastcall sub_6FD15470(D2UnitStrc* pUnit, int nAttackRate);                                           // 0x0056E520
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask);      // 0x006229F0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                            // 0x004E6CA0

static __forceinline D2SkillsTxt* GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// build: context GetSkillParam3ById_Inline
static __forceinline int GetSkillParam3ById_Inline(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

static __forceinline int GetSkillParamByLevel_Inline(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
}

static __forceinline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor <= (nMultiplier >> 4))
        {
            return nValue * (nMultiplier / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

#define SEED_ROLL_LIMITED_INLINE(pSeed, nMax, nResult) \
    if ((nMax) <= 0) \
    { \
        nResult = 0; \
    } \
    else if (((nMax) - 1) & (nMax)) \
    { \
        unsigned __int64 lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed; \
        (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32); \
        (pSeed)->nLowSeed = (unsigned int)lSeed; \
        nResult = (unsigned int)lSeed % (nMax); \
    } \
    else \
    { \
        unsigned __int64 lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed; \
        (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32); \
        (pSeed)->nLowSeed = (unsigned int)lSeed; \
        nResult = (unsigned int)lSeed & ((nMax) - 1); \
    }

// 0x005D54B0
static void __stdcall sub_005D54B0_KickDamage(D2GameStrc* pGame, D2DamageStrc* pDamage, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    sub_005D3AC0(pUnit, pDamage);
    pDamage->dwHitFlags |= 3;

    int nMinDamage = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
    int nMaxDamage = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
    nMinDamage += ApplyRatio_Inline(nMinDamage, pDamage->dwEnDmgPct, 100);
    nMaxDamage += ApplyRatio_Inline(nMaxDamage, pDamage->dwEnDmgPct, 100);

    int nMinKickDamage = 0;
    int nMaxKickDamage = 0;
    int nDamagePercent = pDamage->dwEnDmgPct;
    SKILLS_CalculateKickDamage(pUnit, &nMinKickDamage, &nMaxKickDamage, &nDamagePercent);

    nMinKickDamage <<= 8;
    nMaxKickDamage <<= 8;
    nMinKickDamage += ApplyRatio_Inline(nMinKickDamage, nDamagePercent, 100);
    nMaxKickDamage += ApplyRatio_Inline(nMaxKickDamage, nDamagePercent, 100);
    nMinKickDamage += nMinDamage;
    nMaxKickDamage += nMaxDamage;
    const int nRange = nMaxKickDamage - nMinKickDamage;
    unsigned int nRoll;
    SEED_ROLL_LIMITED_INLINE(&pUnit->pSeed, nRange, nRoll);
    pDamage->dwPhysDamage += nRoll + nMinKickDamage;

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    D2UnitStrc* pSecondaryWeapon = 0;
    if (pMainWeapon)
    {
        const int nBodyLoc = ITEMS_GetBodyLocation(pMainWeapon);
        pSecondaryWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, (nBodyLoc == 4) ? 5 : 4);
    }

    if (ITEMS_CheckItemTypeId(pMainWeapon, 0x2D) && ITEMS_CanBeEquipped(pMainWeapon) && STATLIST_GetOwner(pMainWeapon, 0))
    {
        STATLIST_MergeStatLists(pUnit, pMainWeapon, 0);
    }
    else
    {
        pMainWeapon = 0;
    }

    if (pSecondaryWeapon && pSecondaryWeapon != pMainWeapon && ITEMS_CheckItemTypeId(pSecondaryWeapon, 0x2D) && ITEMS_CanBeEquipped(pSecondaryWeapon) && STATLIST_GetOwner(pSecondaryWeapon, 0))
    {
        STATLIST_MergeStatLists(pUnit, pSecondaryWeapon, 0);
    }

    SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, pDamage, 1, 0x80);
    sub_6FCF5870(pUnit, pDamage);

    if (pMainWeapon)
    {
        STATLIST_MergeStatLists(pUnit, pMainWeapon, 1);
    }
}

// 0x005D5880
static void __stdcall sub_005D5880_KickAttack(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecordArg, int nSkillLevel, int bKnockback, int nSkillId, D2UnitStrc* pUnit)
{
    D2DamageStrc damage;

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);

    if (damage.wResultFlags & 1)
    {
        if (bKnockback)
        {
            damage.wResultFlags |= 0x0C;
        }

        damage.dwEnDmgPct = GetSkillParamByLevel_Inline(nSkillId, nSkillLevel);

        sub_005D54B0_KickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);
    }

    damage.dwHitClass = 1;

    unsigned char nSrcDam = pSkillsTxtRecordArg->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
}

// 0x005D5970
int __fastcall SKILLS_SrvSt24_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || !(pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId]))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0))
    {
        return 0;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) - 1;
    SKILLS_SetParam1(pSkill, nParam);
    sub_005D5880_KickAttack(pGame, pTargetUnit, pSkillsTxtRecord, nSkillLevel, nParam == 0, nSkillId, pUnit);
    return 1;
}

// 0x005D5A30
int __fastcall SKILLS_SrvDo042_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    sub_6FCF77E0(pGame, pUnit, SUNITDMG_GetDamageFromUnits(pUnit, pTarget));
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill) - 1;
    if (nParam < 0)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, nParam);

    int bKnockback = 0;
    if (nParam <= 0)
    {
        int nChance = 100;
        const int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 0x0C, 0);
        int nLevel = nSkillLevel + nTargetLevel - STATLIST_UnitGetStatValue(pTarget, 0x0C, 0);
        nLevel = MIN(MAX(nLevel, 1), nSkillLevel);

        if (pTarget->dwUnitType == 0 || MONSTERS_GetHirelingTypeId(pTarget))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        }
        else if (MONSTERS_IsBoss(0, pTarget))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pTarget, 8))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }

        if (nChance > 0 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
        {
            bKnockback = 1;
        }
    }

    sub_005D5880_KickAttack(pGame, pTarget, pSkillsTxtRecord, nSkillLevel, bKnockback, nSkillId, pUnit);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    if (nParam > 0)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~0x40;
        }

        sub_0056E210(pUnit, 100);
    }

    return 1;
}

// 0x005D7090
int __fastcall SKILLS_SrvSt27_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    sub_6FD15470(pUnit, GetSkillParam3ById_Inline(nSkillId));

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (!(damage.wResultFlags & 1))
    {
        return 0;
    }

    sub_005D54B0_KickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

// 0x005D7850
int __fastcall SKILLS_SrvDo052_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom)
        {
            return 0;
        }

        pUnit->dwFlags &= ~0x40;

        int nX;
        int nY;
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }

        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
        if (!pLevelsTxtRecord || pLevelsTxtRecord->nTeleport == 0 || (pLevelsTxtRecord->nTeleport == 2 && UNITS_TestCollisionByCoordinates(pUnit, nX, nY, 0x804)))
        {
            return 0;
        }

        sub_6FCBDFE0(pGame, pUnit, 0, nX, nY, 0, 0);
        return 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel);
        sub_005D54B0_KickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    sub_6FCF77E0(pGame, pUnit, SUNITDMG_GetDamageFromUnits(pUnit, pTarget));
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}
