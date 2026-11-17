#include "D2Game.h"

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STAT_ATTACKRATE 68
#define STAT_OTHER_ANIMRATE 69
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
struct D2StaticPathStrc;
struct D2SkillsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

void __fastcall sub_6FD11C90(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int pInitArgs;
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

struct D2SkillsTxt
{
    char unk0x000[0x54];
    short wAuraStat[6];
    char unk0x060[0x08];
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    unsigned char unk_82[0x16];
    short nPassiveStat[5];
    char unk0x0A2[0x02];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x80];
    unsigned int dwCalc[4];
    char unk0x148[0x5D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2ItemStatCostTxt
{
    char unk0x000[0x144];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xB98 - 0xC8];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x28];
    D2ItemStatCostTxt* pItemStatCostTxt;
    void* pItemStatCostLinker;
    int nItemStatCostTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

// 0x005C6CB0
void __fastcall sub_005C6CB0_SetStateOn(D2UnitStrc* pUnit, int nState)
{
    sub_6FD11C90(pUnit, nState, 1);
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005C6CC0
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pStatList)
    {
        return;
    }

    if (!pSkillsTxtRecord)
    {
        pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    }

    if (!pSkillsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        const int nStatId = pSkillsTxtRecord->wAuraStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        }

        if (pItemStatCostTxtRecord)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                sub_006270B0(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_ATTACKRATE)
                {
                    STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
                }
            }
        }
    }

    UNITS_UpdateAnimRateAndVelocity(pUnit, gszSkillDruidSourceFile, 248);
}

// 0x005C6DC0
void __fastcall sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pStatList)
    {
        return;
    }

    if (!pSkillsTxtRecord)
    {
        pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    }

    if (!pSkillsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        const int nStatId = pSkillsTxtRecord->nPassiveStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        }

        if (pItemStatCostTxtRecord)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                sub_006270B0(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_ATTACKRATE)
                {
                    STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
                }
            }
        }
    }

    UNITS_UpdateAnimRateAndVelocity(pUnit, gszSkillDruidSourceFile, 300);
}

// 0x005C7040
int __fastcall sub_6FCFE4C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7)
{
    if (a7)
    {
        sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        --nSubMissiles;
        if (nSubMissiles <= 0)
        {
            return 1;
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 33;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 1;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.pInitArgs = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005C7690
int __fastcall SKILLS_SrvSt56_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SKILLS_SetParam1(pSkill, 1);
    }
    else
    {
        SKILLS_SetParam1(pSkill, 0);
    }

    return 1;
}

// 0x005C79E0
int __fastcall SKILLS_SrvSt57_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 753) != nSkillId)
    {
        return 0;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }
    SKILLS_SetParam1(pSkill, 0);
    D2DamageStrc damage;
    D2DamageStrc* pDamage = &damage;
    pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (!(pDamage->wResultFlags & 1))
    {
        return 0;
    }
    SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType > 0)
    {
        SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }
    SKILLS_SetParam1(pSkill, 1);
    return 1;
}
