struct D2StatListStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x88];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    char unk0x10[0x10];
    D2SeedStrc pSeed;
    char unk0x28[0xA8];
    int dwNodeIndex;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int dwAbsLife;
    int dwDmgTotal;
    unsigned int unk0x50;
    int dwPiercePct;
    int dwDamageRate;
    unsigned int unk0x5C;
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2SrvDo51Strc
{
    D2DamageStrc* pDamage;
    int nMonCurseResSubstraction;
    int nParam1;
    int nParam2;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState);                                        // 0x0056E2F0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall sub_6FD154D0(D2UnitStrc* pUnit);                                                            // 0x0056E580
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3);                           // 0x005543B0
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
void __fastcall SKILLS_StatRemoveCallback_MindBlast(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D7310

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x005D72B0
static int __stdcall sub_005D72B0_CanConvertTarget(D2UnitStrc* pOwner, int nChance, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (MONSTERS_GetHirelingTypeId(pUnit))
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 0;
    }

    if (!sub_6FD15190(pUnit, 11))
    {
        return 0;
    }

    return (int)SEED_RollLimitedRandomNumber(&pOwner->pSeed, 100) <= nChance;
}

// 0x005D7430
static int __stdcall sub_005D7430_ApplyConversion(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, D2SrvDo51Strc* pArgs)
{
    if (!sub_005D72B0_CanConvertTarget(pOwner, pArgs->nMonCurseResSubstraction, pUnit))
    {
        return 0;
    }

    const int nExpireFrame = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pArgs->nParam2) + pGame->dwGameFrame + pArgs->nParam1;
    D2StatListStrc* pConversionStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x35);
    if (!pConversionStatList)
    {
        const int nUnitGUID = !pOwner ? -1 : pOwner->dwUnitId;
        const int nUnitType = !pOwner ? 6 : pOwner->dwUnitType;

        pConversionStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0x802, nExpireFrame, nUnitType, nUnitGUID);
        if (!pConversionStatList)
        {
            return 0;
        }

        STATLIST_SetState(pConversionStatList, 0x35);
        STATLIST_SetStatRemoveCallback(pConversionStatList, SKILLS_StatRemoveCallback_MindBlast);
        D2COMMON_10475_PostStatToStatList(pUnit, pConversionStatList, 1);
        STATES_ToggleState(pUnit, 0x35, 1);
    }

    D2COMMON_10476(pConversionStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
    sub_6FD154D0(pUnit);
    sub_6FCBDD30(pUnit, 2, 1);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pUnit, 0, pOwner->dwNodeIndex);

    for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8); i; i = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8))
    {
        D2Common_10474(pUnit, i);
        STATLIST_FreeStatList(i);
    }

    UNITS_SetTargetUnitForDynamicUnit(pOwner, 0);

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    const int nOwnerLevel = STATLIST_UnitGetStatValue(pOwner, 12, 0);
    if (!nLevel || nOwnerLevel >= nLevel || STATLIST_GetStatListFromUnitAndState(pUnit, 0x6D))
    {
        return 1;
    }

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

    D2StatListStrc* pConversionSaveStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, nUnitType, nUnitGUID);
    if (!pConversionSaveStatList)
    {
        return 1;
    }

    STATLIST_SetState(pConversionSaveStatList, 0x6D);
    D2COMMON_10475_PostStatToStatList(pUnit, pConversionSaveStatList, 1);
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    STATLIST_SetStat(pConversionSaveStatList, 0xB0, nLevel, 0);
    STATLIST_SetStat(pConversionSaveStatList, 0xB1, nMaxHp, 0);

    int nNewHitpoints = DATATBLS_ApplyRatio(nHitpoints, nOwnerLevel, nLevel) << 8;
    int nNewMaxHp = DATATBLS_ApplyRatio(nMaxHp, nOwnerLevel, nLevel) << 8;
    if (nNewMaxHp < 1)
    {
        nNewMaxHp = 1;
    }

    nNewHitpoints = MIN(MAX(nNewHitpoints, 1), nNewMaxHp);

    STATLIST_SetUnitStat(pUnit, 12, nOwnerLevel, 0);
    STATLIST_SetUnitStat(pUnit, 6, nNewHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, 7, nNewMaxHp, 0);
    return 1;
}

// 0x005D7680
int __fastcall SKILLS_AuraCallback_MindBlast(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo51Strc* pArgs = (D2SrvDo51Strc*)pAuraCallback->pArgs;

    if (!sub_005D7430_ApplyConversion(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, pArgs))
    {
        D2DamageStrc damage = *pArgs->pDamage;
        SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage);
    }

    return 1;
}
