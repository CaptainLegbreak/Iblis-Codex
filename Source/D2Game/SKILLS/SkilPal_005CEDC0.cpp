#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2CurseStrc;
struct D2BasicAuraParamStrc;
struct D2AuraCallbackStrc;
struct D2SeedStrc;
struct D2SkillsTxt;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

struct D2CurseStrc {
    D2UnitStrc* pUnit; D2UnitStrc* pTarget;
    int nSkill, nSkillLevel, nDuration, nStat, nStatValue, nState;
    StatListRemoveCallback pStateRemoveCallback;
};

struct D2BasicAuraParamStrc {
    int nAuraState, nSkillId, nSkillLevel, nDuration;
    int nAuraStat[6], nAuraStatCalcValue[6];
    int field_40; D2StatListStrc* pStatList;
    int nPassiveState; StatListRemoveCallback pStateRemoveCallback;
};

struct D2AuraCallbackStrc { D2GameStrc* pGame; D2UnitStrc* pOwner; int nCounter; D2BasicAuraParamStrc* pArgs; };

struct D2ItemStatCostTxt { unsigned short wStatId, pad2; unsigned char nItemStatFlags[4]; char pad8[0x2A]; unsigned short wMaxStat; };


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970



void __fastcall SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005CEC50
int __stdcall sub_005CEC90_ShortenPoisonAndCurses(D2GameStrc* pGame, D2UnitStrc* pUnit, int nPercent); // 0x005CEC90
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057AF30
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

struct D2SkillsTxt
{
    char pad_0[302];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    char pad_134[4];
    unsigned int dwCalcFire;
    unsigned int dwCalcCold;
    unsigned int dwCalcLightning;
    char pad_144[97];
    unsigned char nSrcDam;
    char pad_end[150];
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int nPhysical;
    int field_0C;
    int nFire;
    int field_14;
    int field_18;
    int nLightning;
    int field_20;
    int nCold;
    int field_28;
    int field_2C;
    int nColdLength;
    int field_34;
    int field_38;
    int dwManaLeech;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int nOverlay;
    int field_64;
    int field_68;
    int field_6C;
};

extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0
extern D2UnitStrc* __fastcall sub_00535BC0_SecondaryWeapon(D2UnitStrc*); // 0x00535BC0
extern int __stdcall sub_0063D340_WeaponClass(D2UnitStrc*,D2InventoryStrc*); // 0x0063D340
extern int __stdcall sub_00625480_GetStat(D2UnitStrc*,int,int); // 0x00625480
extern D2SkillStrc* __stdcall sub_00620250_UsedSkill(D2UnitStrc*); // 0x00620250
extern D2UnitStrc* __stdcall sub_00553540_TargetUnit(D2GameStrc*,D2UnitStrc*); // 0x00553540
extern int __stdcall sub_006449F0_ToHit(D2UnitStrc*,int,int); // 0x006449F0
extern unsigned short __fastcall sub_0057EC10_ResultFlags(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x0057EC10
extern int __fastcall sub_0057B420_PhysicalDamage(D2UnitStrc*,int,int,int,int,int,int,unsigned char); // 0x0057B420
extern int __stdcall sub_00646CA0_EvaluateFormula(D2UnitStrc*,unsigned int,int,int); // 0x00646CA0
extern int __fastcall sub_00483360_ApplyRatio(int,int,int); // 0x00483360
extern int __stdcall sub_00644F20(D2UnitStrc*,int,int,int); // 0x00644F20
extern int __stdcall sub_006444A0_GetParameter(D2SkillStrc*); // 0x006444A0
extern void __stdcall sub_00644560_SetParameter(D2SkillStrc*,int); // 0x00644560
extern void __fastcall sub_0057DBF0_AllocateCombat(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,D2DamageStrc*,int); // 0x0057DBF0

// 0x005CEDC0
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2CurseStrc curse = {};
    D2BasicAuraParamStrc* pArgs = pAuraCallback->pArgs;
    curse.pTarget = pUnit;
    curse.pUnit = pAuraCallback->pOwner;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = -1;
    curse.nStatValue = 0;
    curse.nState = pArgs->nAuraState;
    if (pArgs->pStateRemoveCallback)
        curse.pStateRemoveCallback = pArgs->pStateRemoveCallback;
    else if (pAuraCallback->pOwner == pUnit)
        curse.pStateRemoveCallback = SKILLS_CurseStateCallback_BasicAura;
    D2StatListStrc* pStatList = sub_0056E970(&curse);
    if (!pStatList) return 0;
    pArgs->pStatList = pStatList;
    int* pAuraStat = pArgs->nAuraStat;
    for (int i = 0; i < 6; ++i, ++pAuraStat)
    {
        if (!pAuraStat[6]) continue;
        int nStat = *pAuraStat;
        if (nStat <= 0 || nStat >= sgptDataTables->nItemStatCostTxtRecordCount) continue;
        if (nStat == 110)
        {
            if (sub_005CEC90_ShortenPoisonAndCurses(pAuraCallback->pGame, pUnit, pAuraStat[6]))
                ++pArgs->field_40;
            continue;
        }
        int nValue = sub_6FD0B3D0(pUnit, nStat, pAuraStat[6]);
        if (!nValue) continue;
        D2ItemStatCostTxt* pRecord = sub_0045C4F0_GetItemStatCostTxtRecord(nStat);
        if (!pRecord) continue;
        if (!(pRecord->nItemStatFlags[0] & gdwBitMasks[4]))
        {
            if (STATLIST_GetStatValue(pStatList, nStat, 0) != nValue)
                STATES_ToggleGfxStateFlag(pUnit, curse.nState, 1);
            switch (nStat)
            {
            case 67:
            case 68:
            {
                int nColdEffect = SUNITDMG_GetColdEffect(SUNIT_GetGameFromUnit(pUnit), pUnit);
                if (nValue < nColdEffect) nValue = nColdEffect;
                break;
            }
            }
            STATLIST_SetStat(pStatList, nStat, nValue, 0);
            if (nStat == 68) STATLIST_SetStat(pStatList, 69, nValue, 0);
            ++pArgs->field_40;
        }
        else
        {
            int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStat, 0);
            nValue += nOldValue;
            int nMaxStat = pRecord->wMaxStat;
            if (nMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                int nMax = STATLIST_UnitGetStatValue(pUnit, nMaxStat, 0);
                if (nValue >= nMax) nValue = nMax;
            }
            if (nValue != nOldValue)
            {
                STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
                ++pArgs->field_40;
            }
        }
    }
    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkilPal.cpp", 413);
    STATLIST_SetStat(pStatList, 350, pArgs->nSkillId, 0);
    STATLIST_SetStat(pStatList, 351, pArgs->nSkillLevel, 0);
    if (pArgs->nPassiveState > 0)
    {
        D2StatListStrc* pPassive = STATLIST_GetStatListFromUnitAndState(pUnit, pArgs->nPassiveState);
        if (pPassive)
        {
            D2Common_10474(pUnit, pPassive);
            STATLIST_FreeStatList(pPassive);
            STATES_ToggleGfxStateFlag(pUnit, pArgs->nPassiveState, 1);
        }
    }
    return 1;
}

static __forceinline unsigned int RollLimited(D2SeedStrc* pSeed,int nRange)
{
    if (nRange<=0) return 0;
    if (nRange & (nRange-1))
    {
        const unsigned __int64 nSeed=pSeed->nHighSeed+0x6ac690c5i64*pSeed->nLowSeed;
        pSeed->nHighSeed=(unsigned int)(nSeed>>32);
        pSeed->nLowSeed=(unsigned int)nSeed;
        return (unsigned int)nSeed % nRange;
    }
    const unsigned __int64 nSeed=pSeed->nHighSeed+0x6ac690c5i64*pSeed->nLowSeed;
    pSeed->nLowSeed=(unsigned int)nSeed;
    pSeed->nHighSeed=(unsigned int)(nSeed>>32);
    return (unsigned int)nSeed & (nRange-1);
}

// 0x005CFD20
static __declspec(noinline) int __cdecl sub_005CFD20_RangeRoll(D2UnitStrc* pUnit)
{
    int nMinimum;
    int nMaximum;
    if (sub_00535BC0_SecondaryWeapon(pUnit))
    {
        if (sub_0063D340_WeaponClass(pUnit,pUnit->pInventory)==2)
        {
            nMinimum=sub_00625480_GetStat(pUnit,23,0);
            nMaximum=sub_00625480_GetStat(pUnit,24,0);
        }
        else
        {
            nMinimum=sub_00625480_GetStat(pUnit,21,0);
            nMaximum=sub_00625480_GetStat(pUnit,22,0);
        }
    }
    else
    {
        nMinimum=sub_00625480_GetStat(pUnit,21,0);
        if (nMinimum<=0) nMinimum=1;
        nMaximum=sub_00625480_GetStat(pUnit,22,0);
        if (nMaximum<=1) nMaximum=2;
    }
    nMinimum<<=8;
    nMaximum<<=8;
    if (nMinimum<1) nMinimum=256;
    if (nMaximum<=nMinimum) nMaximum=nMinimum+256;
    return RollLimited(&pUnit->pSeed,nMaximum-nMinimum)+nMinimum;
}

// 0x005CFE10
int __fastcall sub_005CFE10_ElementalStrike(D2GameStrc* pGame,D2UnitStrc* pUnit,int nSkillId,int nSkillLevel)
{
    D2SkillsTxt* pRecord;
    if (nSkillId>=0 && nSkillId<sgptDataTables->nSkillsTxtRecordCount)
        pRecord=&sgptDataTables->pSkillsTxt[nSkillId];
    else
        pRecord=0;
    if (!pRecord) return 0;
    D2SkillStrc* pSkill=sub_00620250_UsedSkill(pUnit);
    if (!pSkill) return 0;
    D2UnitStrc* pTarget=sub_00553540_TargetUnit(pGame,pUnit);
    if (!pTarget) return 0;
    D2DamageStrc damage;
    memset(&damage,0,sizeof(damage));
    damage.wResultFlags=sub_0057EC10_ResultFlags(pGame,pUnit,pTarget,sub_006449F0_ToHit(pUnit,nSkillId,nSkillLevel),0);
    if (damage.wResultFlags & 1)
    {
        damage.nPhysical=sub_0057B420_PhysicalDamage(pUnit,1,0,0,0,0,0,pRecord->nSrcDam);
        damage.dwHitFlags=1;
        damage.wResultFlags|=pRecord->wResultFlags;
        damage.dwHitFlags=pRecord->dwHitFlags|1;
        const int nDamage=sub_005CFD20_RangeRoll(pUnit);
        int nPercent=sub_00646CA0_EvaluateFormula(pUnit,pRecord->dwCalcFire,nSkillId,nSkillLevel);
        if (nPercent)
        {
            const int nMastery=sub_00625480_GetStat(pUnit,329,0);
            if (nMastery) nPercent+=sub_00483360_ApplyRatio(nPercent,nMastery,100);
        }
        damage.nFire+=sub_00483360_ApplyRatio(nDamage,nPercent,100);
        nPercent=sub_00646CA0_EvaluateFormula(pUnit,pRecord->dwCalcCold,nSkillId,nSkillLevel);
        if (nPercent)
        {
            const int nMastery=sub_00625480_GetStat(pUnit,331,0);
            if (nMastery) nPercent+=sub_00483360_ApplyRatio(nPercent,nMastery,100);
        }
        damage.nCold+=sub_00483360_ApplyRatio(nDamage,nPercent,100);
        nPercent=sub_00646CA0_EvaluateFormula(pUnit,pRecord->dwCalcLightning,nSkillId,nSkillLevel);
        if (nPercent)
        {
            const int nMastery=sub_00625480_GetStat(pUnit,330,0);
            if (nMastery) nPercent+=sub_00483360_ApplyRatio(nPercent,nMastery,100);
        }
        damage.nLightning+=sub_00483360_ApplyRatio(nDamage,nPercent,100);
        damage.nColdLength+=sub_00644F20(pUnit,nSkillId,nSkillLevel,1);
        const int nParameter=sub_006444A0_GetParameter(pSkill);
        switch(nParameter)
        {
        case 0: damage.nOverlay=32; break;
        case 1: damage.nOverlay=48; break;
        case 2: damage.nOverlay=64; break;
        }
        sub_00644560_SetParameter(pSkill,(nParameter+1)%3);
    }
    sub_0057DBF0_AllocateCombat(pGame,pUnit,pTarget,&damage,128);
    return 1;
}
