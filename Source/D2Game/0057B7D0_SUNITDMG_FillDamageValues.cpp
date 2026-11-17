struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags; unsigned short wResultFlags,wExtra;
    int dwPhysDamage,dwEnDmgPct,dwFireDamage,dwBurnDamage,dwBurnLen,dwLtngDamage,dwMagDamage,dwColdDamage,dwPoisDamage,dwPoisLen,dwColdLen,dwFreezeLen,dwLifeLeech,dwManaLeech,dwStamLeech,dwStunLen;
    char unk48[0x1D]; unsigned char nConvType; char unk66[2]; int nConvPct;
};

#define ITEMTYPE_BLUNT 57
#define STAT_ITEM_UNDEADDAMAGE_PERCENT 122

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit);                                                     // 0x00535BC0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

// 0x0057A880
static int __stdcall sub_0057A880_AddRolledDamage(D2UnitStrc* pUnit, int nMin, int nMax, int nMinPct, int nMaxPct, int nDamage)
{
    if (nMax > 0)
    {
        nMin += DATATBLS_ApplyRatio(nMin, nMinPct, 100);
        nMax += DATATBLS_ApplyRatio(nMax, nMaxPct, 100);
        nDamage += nMin;
        if (nMax > nMin)
        {
            nDamage += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin);
        }
    }

    return nDamage < 0 ? 0 : nDamage;
}

// 0x0057A8E0
static int __stdcall sub_0057A8E0_AddStatDamage(int nStatMin, int nStatPct, int nMinPct, int nMaxPct, int nDamage, int nStatMax, D2UnitStrc* pUnit)
{
    const int nMax = STATLIST_UnitGetStatValue(pUnit, nStatMax, 0) << 8;
    if (nMax < 8)
    {
        return nDamage < 0 ? 0 : nDamage;
    }

    const int nMin = STATLIST_UnitGetStatValue(pUnit, nStatMin, 0) << 8;
    if (nStatPct != -1)
    {
        const int nPct = STATLIST_UnitGetStatValue(pUnit, nStatPct, 0);
        nMinPct += nPct;
        nMaxPct += nPct;
    }

    return sub_0057A880_AddRolledDamage(pUnit, nMin, nMax, nMinPct, nMaxPct, nDamage);
}

// 0x0057B660
static void sub_0057B660_AddUndeadDamagePercent(D2DamageStrc* pDamage, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (MONSTERS_IsUndead(pDefender))
    {
        int nPct = 0;
        D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
        if (pWeapon && ITEMS_CheckItemTypeId(pWeapon, ITEMTYPE_BLUNT))
        {
            nPct = 50;
        }

        nPct += STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
        if (nPct > 0)
        {
            pDamage->dwEnDmgPct += nPct;
        }
    }
}

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

struct D2MonStatsTxt
{
    char unk0x000[0x1C];
    short wMonType;
    char unk0x01E[0x18A];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1BC];
    int nMonTypeTxtRecordCount;
    unsigned int* pMonTypeNest;
    int nMonTypeIndex;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_DAMAGE_VS_MONTYPE 180

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);     // 0x006261D0

static __forceinline D2MonStatsTxt* U01_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2MonStatsTxt* U01_GetUnitMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return U01_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    return 0;
}

static __forceinline int U01_MonTypeMatches(int nMonType1, int nMonType2)
{
    if (nMonType1 > 0 && nMonType1 < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType2 > 0 && nMonType2 < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return sgptDataTables->pMonTypeNest[(nMonType1 >> 5) + nMonType2 * sgptDataTables->nMonTypeIndex] & gdwBitMasks[nMonType1 & 0x1F];
    }

    return 0;
}

// 0x0057B6A0
static void __stdcall sub_0057B6A0_AddMonTypeDamagePercent(D2UnitStrc* pAttacker, D2DamageStrc* pDamage, D2UnitStrc* pDefender)
{
    const int nType = pDefender ? pDefender->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStats = U01_GetUnitMonStatsTxtRecord(pDefender);
        if (pMonStats && pMonStats->wMonType > 0)
        {
            D2StatStrc tStats[128];
            const int nMonType = pMonStats->wMonType;
            const int nStats = STATLIST_CopyStats(pAttacker, STAT_DAMAGE_VS_MONTYPE, tStats, 128);
            for (int i = 0; i < nStats; ++i)
            {
                if (U01_MonTypeMatches(tStats[i].nLayer, nMonType))
                {
                    pDamage->dwEnDmgPct += tStats[i].nValue;
                }
            }
        }
    }
}

struct D2GameStrc;
void __fastcall sub_00535D10_PrepareWeapon(D2UnitStrc*,int); // 0x00535D10
void __fastcall sub_00535E20_RestoreWeapon(D2UnitStrc*,int); // 0x00535E20
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc*); // 0x006259B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
int __stdcall MONSTERS_IsDemon(D2UnitStrc*); // 0x0063E940
int __fastcall sub_0057B420_RollPhysicalDamage(D2UnitStrc*,int,int,int,int,int,int,unsigned char); // 0x0057B420
int __stdcall sub_00645830_GetCriticalStrikeChance(D2UnitStrc*,D2UnitStrc*,int,int); // 0x00645830
int __fastcall sub_00472280_RollRange(D2SeedStrc*,int,int); // 0x00472280
int __stdcall sub_0063EE90_IsHireling(D2UnitStrc*); // 0x0063EE90
int __fastcall SUNITEVENT_Trigger(D2GameStrc*,int,D2UnitStrc*,D2UnitStrc*,void*); // 0x005C0C30
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*,int); // 0x0045C390
void __fastcall sub_005A5560_AdjustDamage(D2UnitStrc*,D2UnitStrc*,D2DamageStrc*); // 0x005A5560

// 0x0057B7D0
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender,D2DamageStrc* pDamage,int nWeapon,unsigned char nSrcDam)
{
    if (!pAttacker || !pDefender) return;
    if (!nSrcDam) nSrcDam=128;
    sub_00535D10_PrepareWeapon(pAttacker,nWeapon);
    const int nAttackerType=pAttacker->dwUnitType;
    const int nDefenderType=pDefender->dwUnitType;
    pDamage->dwHitFlags|=0x20;
    if ((!nAttackerType || STATLIST_GetUnitAlignment(pAttacker)==2) && nDefenderType==1)
    {
        int nTargetDefense=STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker,120,0);
        if(nTargetDefense)
        {
            int nDefense=STATLIST_UnitGetStatValue(pDefender,31,0)+nTargetDefense;
            if(nDefense<0) nDefense=0;
            STATLIST_SetUnitStat(pDefender,31,nDefense,0);
        }
        if(MONSTERS_IsDemon(pDefender))
        {
            int nPct=STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker,121,0);
            if(nPct>0) pDamage->dwEnDmgPct+=nPct;
        }
        sub_0057B660_AddUndeadDamagePercent(pDamage,pAttacker,pDefender);
        sub_0057B6A0_AddMonTypeDamagePercent(pAttacker,pDamage,pDefender);
    }
    if(!(pDamage->dwHitFlags&1))
    {
        pDamage->dwPhysDamage=sub_0057B420_RollPhysicalDamage(pAttacker,1,0,0,0,pDamage->dwEnDmgPct,pDamage->dwPhysDamage,nSrcDam);
        if(!nWeapon)
        {
            D2UnitStrc* pWeapon=sub_6FC7C7B0(pAttacker);
            if(pWeapon)
            {
                int nChance=sub_00645830_GetCriticalStrikeChance(pAttacker,pWeapon,0,2);
                if(nChance>0 && sub_00472280_RollRange(&pAttacker->pSeed,0,100)<nChance) goto critical;
            }
        }
        {
            int nChance=STATLIST_UnitGetStatValue(pAttacker,337,0);
            if(nChance>0 && sub_00472280_RollRange(&pAttacker->pSeed,0,100)<nChance) goto critical;
            nChance=STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker,141,0);
            if(nChance<=0 || sub_00472280_RollRange(&pAttacker->pSeed,0,100)>=nChance) goto elemental;
        }
critical:
        pDamage->dwPhysDamage*=2;
        pDamage->wResultFlags|=0x2000;
    }
elemental:
    if(nSrcDam!=128)
    {
        pDamage->dwFireDamage=sub_0057A8E0_AddStatDamage(48,329,0,0,pDamage->dwFireDamage,49,pAttacker)*nSrcDam/128;
        pDamage->dwLtngDamage=sub_0057A8E0_AddStatDamage(50,330,0,0,pDamage->dwLtngDamage,51,pAttacker)*nSrcDam/128;
        pDamage->dwColdDamage=sub_0057A8E0_AddStatDamage(54,331,0,0,pDamage->dwColdDamage,55,pAttacker)*nSrcDam/128;
        pDamage->dwMagDamage=sub_0057A8E0_AddStatDamage(52,357,0,0,pDamage->dwMagDamage,53,pAttacker)*nSrcDam/128;
    }
    else
    {
        pDamage->dwFireDamage=sub_0057A8E0_AddStatDamage(48,329,0,0,pDamage->dwFireDamage,49,pAttacker);
        pDamage->dwLtngDamage=sub_0057A8E0_AddStatDamage(50,330,0,0,pDamage->dwLtngDamage,51,pAttacker);
        pDamage->dwColdDamage=sub_0057A8E0_AddStatDamage(54,331,0,0,pDamage->dwColdDamage,55,pAttacker);
        pDamage->dwMagDamage=sub_0057A8E0_AddStatDamage(52,357,0,0,pDamage->dwMagDamage,53,pAttacker);
    }
    int bHireling=sub_0063EE90_IsHireling(pAttacker);
    if(nAttackerType==1 && !bHireling)
    {
        if(!(pDamage->dwHitFlags&4)) pDamage->dwLifeLeech+=sub_0057A8E0_AddStatDamage(60,-1,0,0,pDamage->dwLifeLeech,61,pAttacker)*nSrcDam/128;
        if(!(pDamage->dwHitFlags&8)) pDamage->dwManaLeech+=sub_0057A8E0_AddStatDamage(62,-1,0,0,pDamage->dwManaLeech,63,pAttacker)*nSrcDam/128;
        if(!(pDamage->dwHitFlags&16)) pDamage->dwStamLeech+=sub_0057A8E0_AddStatDamage(64,-1,0,0,pDamage->dwStamLeech,65,pAttacker)*nSrcDam/128;
    }
    else if(!nAttackerType || bHireling)
    {
        if(!(pDamage->dwHitFlags&4)) pDamage->dwLifeLeech+=STATLIST_UnitGetStatValue(pAttacker,60,0);
        if(!(pDamage->dwHitFlags&8)) pDamage->dwManaLeech+=STATLIST_UnitGetStatValue(pAttacker,62,0);
        if(STATLIST_UnitGetStatValue(pAttacker,103,0)) pDamage->dwHitFlags|=0x100;
        if(STATLIST_UnitGetStatValue(pAttacker,104,0)) pDamage->dwHitFlags|=0x200;
        if(STATLIST_UnitGetStatValue(pAttacker,106,0)) pDamage->dwHitFlags|=0x400;
    }
    int nPoisonMin=STATLIST_UnitGetStatValue(pAttacker,57,0);
    int nPoisonMax=STATLIST_UnitGetStatValue(pAttacker,58,0);
    int nPoisonPct=0;
    if(nPoisonMax>0) nPoisonPct=STATLIST_UnitGetStatValue(pAttacker,332,0);
    pDamage->dwPoisDamage=sub_0057A880_AddRolledDamage(pAttacker,nPoisonMin,nPoisonMax,nPoisonPct,nPoisonPct,pDamage->dwPoisDamage)*nSrcDam/128;
    if(pDamage->dwPoisDamage)
    {
        int nOverride=STATLIST_UnitGetStatValue(pAttacker,101,0);
        if(nOverride>0) pDamage->dwPoisLen+=nOverride;
        else
        {
            pDamage->dwPoisLen+=STATLIST_UnitGetStatValue(pAttacker,59,0);
            int nCount=STATLIST_UnitGetStatValue(pAttacker,326,0);
            if(nCount>1) pDamage->dwPoisLen/=nCount;
        }
    }
    if(pDamage->dwColdDamage>0) pDamage->dwColdLen+=STATLIST_UnitGetStatValue(pAttacker,56,0)*nSrcDam/128;
    if(!pDamage->dwStunLen) pDamage->dwStunLen+=STATLIST_UnitGetStatValue(pAttacker,66,0)*nSrcDam/128;
    int nBurn=pDamage->dwBurnDamage*nSrcDam+316;
    nBurn+=ITEMS_RollLimitedRandomNumber(&pAttacker->pSeed,1);
    pDamage->dwBurnDamage+=(nBurn<0 ? 0:nBurn)/128;
    if(pDamage->dwBurnLen) pDamage->dwBurnLen+=STATLIST_UnitGetStatValue(pAttacker,315,0)*nSrcDam/128;
    if((!nAttackerType || bHireling) && !(pDamage->wResultFlags&0x20)) SUNITEVENT_Trigger(pGame,3,pDefender,pAttacker,pDamage);
    if(pDamage->nConvType>0)
    {
        int nConverted=DATATBLS_ApplyRatio(pDamage->dwPhysDamage,pDamage->nConvPct,100);
        pDamage->dwPhysDamage-=nConverted;
        pDamage->dwPhysDamage=pDamage->dwPhysDamage<=0 ? 0:pDamage->dwPhysDamage;
        unsigned char nType=pDamage->nConvType;
        if(nType==10) nType=(unsigned char)SEED_RollLimitedRandomNumber(&pAttacker->pSeed,5)+1;
        switch(nType)
        {
        case 1:pDamage->dwFireDamage+=nConverted;break;
        case 2:pDamage->dwLtngDamage+=nConverted;break;
        case 3:pDamage->dwMagDamage+=nConverted;break;
        case 4:pDamage->dwColdDamage+=nConverted;pDamage->dwColdLen=pDamage->dwColdLen<50 ? 50:pDamage->dwColdLen;break;
        case 5:pDamage->dwPoisDamage+=nConverted/8;pDamage->dwPoisLen=pDamage->dwPoisLen<50 ? 50:pDamage->dwPoisLen;break;
        case 11:pDamage->dwFireDamage+=nConverted;pDamage->dwBurnLen=pDamage->dwBurnLen<50 ? 50:pDamage->dwBurnLen;break;
        case 12:pDamage->dwColdDamage+=nConverted;pDamage->dwFreezeLen=pDamage->dwFreezeLen<50 ? 50:pDamage->dwFreezeLen;break;
        }
    }
    sub_005A5560_AdjustDamage(pAttacker,pDefender,pDamage);
    sub_00535E20_RestoreWeapon(pAttacker,nWeapon);
}
