#include "D2Game.h"

#define STAT_DAMAGEPERCENT 25
struct D2SkillsTxt;
struct D2StaticPathStrc;
struct Skills;

struct D2UnitStrc
{
    int dwUnitType;
    char pad4[8];
    int dwUnitId;
    char pad10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
    char unk0x000[0x138];
    unsigned int dwCalc[4];
    char unk0x148[0x5D];
    unsigned char nSrcDam;
    char unk0x1A6[0x36];
    unsigned char nEType;
    char unk0x1DD[0x5F];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

enum D2C_UnitTypes
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct D2StaticPathStrc { int unknown[3]; int nXPos,nYPos; };

struct Skills { char pad0[0x138]; unsigned rangeCalc,durationCalc; char pad140[0xFC]; };

struct Tables { char pad0[0xB6C]; int missileCount; char padB70[0x28]; Skills* skills; void* linker; int skillCount; };
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

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
int __stdcall sub_00646CA0(D2UnitStrc*,unsigned,int,int); // 0x00646CA0
D2UnitStrc* __fastcall sub_0056BD10(D2GameStrc*,D2UnitStrc*,int,int,int,unsigned,int,int*); // 0x0056BD10
int __fastcall sub_005D3CF0(D2UnitStrc*,int); // 0x005D3CF0
extern "C" void* __cdecl memset(void*,int,unsigned);
int __fastcall sub_0045ADF0(D2UnitStrc*); // 0x0045ADF0
int __fastcall sub_0045AE20(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __fastcall sub_0059FA30(D2GameStrc*,D2MissileStrc*); // 0x0059FA30
void __stdcall sub_0064A710(D2UnitStrc*,int); // 0x0064A710

enum { MISSILE_FLAGS = 0x20 };

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005DB2D0
int __fastcall SKILLS_SrvDo007_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
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

    int nType;
    if (!pUnit)
    {
        nType = UNIT_INVALID;
    }
    else
    {
        nType = pUnit->dwUnitType;
    }

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (nType == UNIT_MONSTER)
    {
        sub_6FC627B0(pUnit, 8);
    }

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005DB6A0
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int nBonus)
{
    if (nBonus)
    {
        const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
        STATLIST_SetUnitStat(pUnit, STAT_DAMAGEPERCENT, nValue + nBonus, 0);
    }
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}

// 0x005DBE50
int __fastcall sub_005DBE50(D2GameStrc* game,D2UnitStrc* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
    if(!target) return 0;
    SUNITDMG_DrainItemDurability(game,unit,target,0);
    int range=sub_00646CA0(unit,record->rangeCalc,skillId,level);
    const int targetId=target->dwUnitId;
    D2UnitStrc* other=sub_0056BD10(game,unit,UNITS_GetUnitXPosition(target),UNITS_GetUnitYPosition(target),range,3,targetId,0);
    if(!other) return 0;
    int missileId=sub_005D3CF0(unit,skillId);
    if(missileId<0 || missileId>=tables->missileCount) return 0;
    int duration=sub_00646CA0(unit,record->durationCalc,skillId,level);
    D2MissileStrc params;
    memset(&params,0,sizeof(params));
    params.dwFlags=MISSILE_FLAGS;
    params.pOwner=unit;
    params.pOrigin=target;
    params.nSkill=skillId;
    params.nSkillLevel=level;
    params.nMissile=missileId;
    params.nTargetX=sub_0045ADF0(other);
    params.nTargetY=sub_0045AE20(other);
    D2UnitStrc* missile=sub_0059FA30(game,&params);
    if(missile) sub_0064A710(missile,duration);
    return 1;
}
