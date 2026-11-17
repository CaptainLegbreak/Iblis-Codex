struct D2MissileDataStrc
{
    char unk0x00[0x14];
    unsigned int fFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MissileDataStrc* pMissileData;
};

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

struct D2MissileDamageDataStrc
{
    int nFlags;
    int nMinDamage;
    int nMaxDamage;
    int nFireMinDamage;
    int nFireMaxDamage;
    int nFireLength;
    int nLightMinDamage;
    int nLightMaxDamage;
    int nMagicMinDamage;
    int nMagicMaxDamage;
    int nColdMinDamage;
    int nColdMaxDamage;
    int nColdLength;
    int nPoisonMinDamage;
    int nPoisonMaxDamage;
    int nPoisonLength;
    int nPoisonCount;
    int nLifeDrainMinDamage;
    int nLifeDrainMaxDamage;
    int nManaDrainMinDamage;
    int nManaDrainMaxDamage;
    int nStaminaDrainMinDamage;
    int nStaminaDrainMaxDamage;
    int nStunLength;
    int nBurningMin;
    int nBurningMax;
    int nBurnLength;
    int nDemonDamagePercent;
    int nUndeadDamagePercent;
    int nDamageTargetAC;
    int nDamagePercent;
};

enum
{
    UNIT_MISSILE = 3,
    UNIT_INVALID = 6,
    STAT_LEVEL = 12,
    STAT_MINDAMAGE = 21,
    STAT_MAXDAMAGE = 22,
    STAT_DAMAGEPERCENT = 25,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_MAGICMINDAM = 52,
    STAT_MAGICMAXDAM = 53,
    STAT_COLDMINDAM = 54,
    STAT_COLDMAXDAM = 55,
    STAT_COLDLENGTH = 56,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
    STAT_LIFEDRAINMINDAM = 60,
    STAT_LIFEDRAINMAXDAM = 61,
    STAT_MANADRAINMINDAM = 62,
    STAT_MANADRAINMAXDAM = 63,
    STAT_STAMDRAINMINDAM = 64,
    STAT_STAMDRAINMAXDAM = 65,
    STAT_STUNLENGTH = 66,
    STAT_SKILL_BYPASS_UNDEAD = 103,
    STAT_SKILL_BYPASS_DEMONS = 104,
    STAT_SKILL_BYPASS_BEASTS = 106,
    STAT_ITEM_DAMAGETARGETAC = 120,
    STAT_ITEM_DEMONDAMAGE_PERCENT = 121,
    STAT_ITEM_UNDEADDAMAGE_PERCENT = 122,
    STAT_ITEM_DEADLYSTRIKE = 141,
    STAT_DAMAGE_VS_MONTYPE = 180,
    STAT_FIRELENGTH = 315,
    STAT_BURNINGMIN = 316,
    STAT_BURNINGMAX = 317,
    STAT_POISON_COUNT = 326,
};

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0

inline unsigned int MISSILE_GetFlagsInline(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        return pMissile->pMissileData->fFlags;
    }

    return 0;
}

inline void MISSILE_SetFlagsInline(D2UnitStrc* pMissile, unsigned int dwFlags)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE && pMissile->pMissileData)
    {
        pMissile->pMissileData->fFlags = dwFlags;
    }
}

// 0x0064AC60
void __stdcall MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel)
{
    D2StatStrc pStat[128];

    const int nType = pMissile ? pMissile->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MISSILE)
    {
        unsigned int dwFlags = MISSILE_GetFlagsInline(pMissile);
        if (pMissileDamageData->nFlags & 1)
        {
            dwFlags |= 1;
        }
        if (pMissileDamageData->nFlags & 4)
        {
            dwFlags |= 2;
        }
        MISSILE_SetFlagsInline(pMissile, dwFlags);

        STATLIST_SetUnitStat(pMissile, STAT_LEVEL, nLevel, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MINDAMAGE, pMissileDamageData->nMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MAXDAMAGE, pMissileDamageData->nMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIREMINDAM, pMissileDamageData->nFireMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIREMAXDAM, pMissileDamageData->nFireMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIRELENGTH, pMissileDamageData->nFireLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIGHTMINDAM, pMissileDamageData->nLightMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIGHTMAXDAM, pMissileDamageData->nLightMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMINDAM, pMissileDamageData->nMagicMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMAXDAM, pMissileDamageData->nMagicMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_COLDMINDAM, pMissileDamageData->nColdMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_COLDMAXDAM, pMissileDamageData->nColdMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_COLDLENGTH, pMissileDamageData->nColdLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISONMINDAM, pMissileDamageData->nPoisonMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISONMAXDAM, pMissileDamageData->nPoisonMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISONLENGTH, pMissileDamageData->nPoisonLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_POISON_COUNT, pMissileDamageData->nPoisonCount, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIFEDRAINMINDAM, pMissileDamageData->nLifeDrainMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_LIFEDRAINMAXDAM, pMissileDamageData->nLifeDrainMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MANADRAINMINDAM, pMissileDamageData->nManaDrainMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_MANADRAINMAXDAM, pMissileDamageData->nManaDrainMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_STAMDRAINMINDAM, pMissileDamageData->nStaminaDrainMinDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_STAMDRAINMAXDAM, pMissileDamageData->nStaminaDrainMaxDamage, 0);
        STATLIST_SetUnitStat(pMissile, STAT_STUNLENGTH, pMissileDamageData->nStunLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_BURNINGMIN, pMissileDamageData->nBurningMin, 0);
        STATLIST_SetUnitStat(pMissile, STAT_BURNINGMAX, pMissileDamageData->nBurningMax, 0);
        STATLIST_SetUnitStat(pMissile, STAT_FIRELENGTH, pMissileDamageData->nBurnLength, 0);
        STATLIST_SetUnitStat(pMissile, STAT_ITEM_DEMONDAMAGE_PERCENT, pMissileDamageData->nDemonDamagePercent, 0);
        STATLIST_SetUnitStat(pMissile, STAT_ITEM_UNDEADDAMAGE_PERCENT, pMissileDamageData->nUndeadDamagePercent, 0);
        STATLIST_SetUnitStat(pMissile, STAT_ITEM_DAMAGETARGETAC, pMissileDamageData->nDamageTargetAC, 0);
        STATLIST_SetUnitStat(pMissile, STAT_DAMAGEPERCENT, pMissileDamageData->nDamagePercent, 0);

        if (pMissileDamageData->nFlags & 0x100)
        {
            STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_UNDEAD, 1, 0);
        }

        if (pMissileDamageData->nFlags & 0x200)
        {
            STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_DEMONS, 1, 0);
        }

        if (pMissileDamageData->nFlags & 0x400)
        {
            STATLIST_SetUnitStat(pMissile, STAT_SKILL_BYPASS_BEASTS, 1, 0);
        }

        if (pMissileDamageData->nFlags & 2)
        {
            STATLIST_SetUnitStat(pMissile, STAT_ITEM_DEADLYSTRIKE, 1, 0);
        }

        if (pOwner)
        {
            const int nStats = STATLIST_CopyStats(pOwner, STAT_DAMAGE_VS_MONTYPE, pStat, 128);
            for (int i = 0; i < nStats; ++i)
            {
                STATLIST_SetUnitStat(pMissile, STAT_DAMAGE_VS_MONTYPE, pStat[i].nValue, pStat[i].nLayer);
            }
        }
    }
}
