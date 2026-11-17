struct D2InventoryStrc;
struct D2SkillStrc;
struct D2UnitStrc { char unk_00[0x60]; D2InventoryStrc* pInventory; };

// 0x00483360
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

int __stdcall sub_004E89A0(D2UnitStrc*, int*, int*, int*, D2SkillStrc*); // 0x004E89A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480
int __stdcall ITEMS_GetMissileType(D2UnitStrc*); // 0x006288A0
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc*); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc*); // 0x006298A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc*,int); // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80
int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0
D2UnitStrc* __stdcall sub_0063BEF0(D2InventoryStrc*); // 0x0063BEF0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc*,D2UnitStrc*,D2SkillStrc*,int); // 0x00645830
int __stdcall MISSILE_GetMinDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064AFF0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B1D0
int __stdcall sub_0064B2A0_GetMissileElementLength(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B2A0

// 0x004EA4A0
void __fastcall sub_004EA4A0_WeaponDamageCallback2(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    *pMin=0;
    *pMax=0;
    if (!pSkill) return;
    if (!pItem) {
        if (!pUnit->pInventory) return;
        pItem=sub_0063BEF0(pUnit->pInventory);
        if (!pItem) return;
    }
    if (!ITEMS_CheckIfThrowable(pItem)) return;
    if (ITEMS_CheckItemTypeId(pItem,38)) {
        int nMissile=ITEMS_GetMissileType(pItem);
        *pColor=0;
        int nMin=MISSILE_GetMinDamage(0,pUnit,nMissile,1);
        nMin+=MISSILE_GetMinElemDamage(0,pUnit,nMissile,1);
        int nMax=MISSILE_GetMaxDamage(0,pUnit,nMissile,1);
        nMax+=MISSILE_GetMaxElemDamage(0,pUnit,nMissile,1);
        switch (MISSILE_GetElemTypeFromMissileId(nMissile)) {
        case 5: {
            *pColor=2;
            int nLength=sub_0064B2A0_GetMissileElementLength(0,pUnit,nMissile,1)/25;
            if(nLength<=0)nLength=1;
            nMin/=nLength;
            nMax/=nLength;
            break;
        }
        case 4: *pColor=3; break;
        case 1: *pColor=1; break;
        case 2: *pColor=4; break;
        }
        nMin>>=8;
        nMax>>=8;
        if(nMax<=nMin)nMax=nMin;
        *pMin=nMin;
        *pMax=nMax;
        return;
    }
    int nStatBonus=0;
    int nFactor=ITEMS_GetStrengthBonus(pItem);
    if(nFactor)nStatBonus=STATLIST_UnitGetStatValue(pUnit,0,0)*nFactor/100;
    nFactor=ITEMS_GetDexBonus(pItem);
    if(nFactor)nStatBonus+=STATLIST_UnitGetStatValue(pUnit,2,0)*nFactor/100;
    *pMin=STATLIST_UnitGetStatValue(pUnit,159,0);
    *pMax=STATLIST_UnitGetStatValue(pUnit,160,0);
    nStatBonus+=STATLIST_UnitGetStatValue(pUnit,25,0);
    int nMinPercent=STATLIST_UnitGetStatValue(pUnit,18,0);
    int nMaxPercent=STATLIST_UnitGetStatValue(pUnit,17,0);
    if(nStatBonus<=-90)nStatBonus=-90;
    *pMin+=*pMin*(nMinPercent+nStatBonus)/100;
    *pMax+=*pMax*(nMaxPercent+nStatBonus)/100;
    int nSkillBonus=nBonus;
    if(STATES_CheckState(pUnit,78))nSkillBonus+=SKILLS_GetWeaponMasteryBonus(pUnit,pItem,pSkill,1);
    *pMin+=DATATBLS_ApplyRatio(*pMin,nSkillBonus,100);
    *pMax+=DATATBLS_ApplyRatio(*pMax,nSkillBonus,100);
    if(*pMax<*pMin)*pMax=*pMin;
    {
        int nElemMin=0;
        int nElemMax=0;
        sub_004E89A0(pUnit,&nElemMin,&nElemMax,pColor,pSkill);
        if(nElemMax<nElemMin)nElemMax=nElemMin;
        *pMin+=nElemMin;
        *pMax+=nElemMax;
    }
}
