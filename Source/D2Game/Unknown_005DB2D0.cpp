#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

#define STAT_DAMAGEPERCENT 25
struct D2SkillsTxt;
struct D2StaticPathStrc;
struct Skills;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct Skills { char pad0[0x138]; unsigned rangeCalc,durationCalc; char pad140[0xFC]; };

struct Tables { char pad0[0xB6C]; int missileCount; char padB70[0x28]; Skills* skills; void* linker; int skillCount; };
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

int __stdcall sub_00646CA0(D2UnitStrc*,unsigned,int,int); // 0x00646CA0
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc*,D2UnitStrc*,int,int,int,unsigned,int,int*); // 0x0056BD10
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc*,int); // 0x005D3CF0
extern "C" void* __cdecl memset(void*,int,unsigned);
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
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
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}
