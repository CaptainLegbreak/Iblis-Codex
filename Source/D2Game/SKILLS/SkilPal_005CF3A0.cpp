#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

struct D2AuraCallbackStrc;
struct D2BasicAuraParamStrc;
struct D2DamageAuraParamStrc;
struct D2SkillsTxt;
union D2SeedStrc;
struct D2MonStatsTxt;




struct D2BasicAuraParamStrc
{
    int nAuraState;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalcValue[6];
    int field_40;
    D2StatListStrc* pStatList;
    int nPassiveState;
    D2DamageStrc* pDamage;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[9];
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int unk0x40[3];
    int dwDmgTotal;
    int unk0x50[4];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

struct D2DamageAuraParamStrc
{
    int nAuraState;
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraStat[6];
    int nAuraStatCalcValue[6];
    int field_40;
    D2StatListStrc* pStatList;
    int nPassiveState;
    D2DamageStrc* pDamage;
};

struct D2SkillsTxt
{
    char unk0x000[0x4E];
    short wSrvOverlay;
    unsigned int dwAuraFilter;
    short wAuraStat[6];
    unsigned int dwAuraLenCalc;
    unsigned int dwAuraRangeCalc;
    unsigned int dwAuraStatCalc[6];
    short nAuraState;
    short wAuraTargetState;
    char unk0x084[0x14];
    short nPassiveStat[5];
    char unk0x0A2[0x02];
    unsigned int dwPassiveCalc[5];
    char unk0x0B8[0x76];
    unsigned short wResultFlags;
    unsigned int dwHitFlags;
    unsigned int dwHitClass;
    char unk0x138[0x104];
};


typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

enum D2C_Y09HolyFreezeConstants
{
    STAT_MANA = 8,
    STATE_NOMANAREGEN = 85,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall sub_0056B740_CallWithRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
void __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int unk0x08;
    D2BasicAuraParamStrc* pArgs;
};

int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CEDC0
int __fastcall SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CF2A0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);

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
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc*, int); // 0x005D3CF0
void __stdcall UNITS_SetOverlay(D2UnitStrc*, int, int); // 0x00621E40
void __stdcall MISSILE_SetTargetX(D2UnitStrc*, int); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc*, int); // 0x0064A760

struct D2MonStatsTxt
{
    char unk0x000[0x168];
    char nColdEffect[3];
    char unk0x16B[0x1A8 - 0x16B];
};

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return pRecord;
}

// 0x005CF3A0
int __fastcall sub_005CF3A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    D2BasicAuraParamStrc args1;
    memset(&args1, 0, sizeof(args1));
    args1.nSkillId = nSkillId;
    args1.nSkillLevel = nSkillLevel;
    args1.nAuraState = pSkillsTxtRecord->nAuraState;
    args1.nDuration = nFrame;

    for (int i = 0; i < 5; ++i)
    {
        args1.nAuraStat[i] = pSkillsTxtRecord->nPassiveStat[i];
        if (sub_0044BE50_GetUnitTypeOrInvalid(pUnit) != UNIT_PLAYER || nMana >= nManaCost)
        {
            args1.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
    }

    sub_0056B740_CallWithRecord(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args1);

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return 1;
    }

    D2DamageAuraParamStrc args2;
    args2.nSkillId = nSkillId;
    args2.nSkillLevel = nSkillLevel;
    args2.nDuration = nFrame;
    args2.nAuraState = pSkillsTxtRecord->wAuraTargetState;
    args2.pDamage = 0;
    args2.field_40 = 0;
    args2.nPassiveState = 0;

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        for (int i = 0; i < 6; ++i)
        {
            args2.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
            if (nMana >= nManaCost)
            {
                args2.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
                if (args2.nAuraStatCalcValue[i])
                {
                    args2.nPassiveState = 1;
                }
            }
            else
            {
                args2.nAuraStatCalcValue[i] = 0;
            }
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    if (D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel))
    {
        damage.dwHitClass |= 0xD;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags | 0x20;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        args2.pDamage = &damage;
    }

    unsigned int const tArg7 = pSkillsTxtRecord->dwAuraRangeCalc;
    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, tArg7, nSkillId, nSkillLevel);

    sub_6FD0FE80(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction, &args2, 0, gszSkillPalSourceFile, 698);

    if (nManaCost > 0 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (args2.field_40 > 0)
        {
            STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 1);
            D2GAME_SKILLMANA_AuraConsume_6FD10C90(pUnit, nManaCost);
        }
        else
        {
            STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
        }
    }

    return 1;
}

static __forceinline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005D0670
int __fastcall sub_005D0670_CreateTargetedSkillMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
        return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return 0;
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pTarget);
    missileParams.nY = CLIENTS_GetUnitY(pTarget);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
        return 0;
    MISSILE_SetTargetX(pMissile, !pTarget ? 6 : pTarget->dwUnitType);
    MISSILE_SetTargetY(pMissile, !pTarget ? -1 : pTarget->dwUnitId);
    if (pSkillsTxt->wSrvOverlay >= 0 && pSkillsTxt->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
        UNITS_SetOverlay(pTarget, pSkillsTxt->wSrvOverlay, 0);
    return 1;
}

static __forceinline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005D07C0
int __fastcall SKILLS_AuraCallback_HolyFreeze(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pAuraCallback->pGame;
    D2UnitStrc* pOwner = pAuraCallback->pOwner;
    D2BasicAuraParamStrc* pArgs = pAuraCallback->pArgs;
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }
        if (pMonStatsTxtRecord->nColdEffect[pGame->nDifficulty] >= 0)
        {
            return 0;
        }
    }

    if (pArgs->nPassiveState)
    {
        D2BasicAuraParamStrc args;
        memset(&args, 0, sizeof(args));
        args.nAuraState = pArgs->nAuraState;
        args.nSkillId = pArgs->nSkillId;
        args.nSkillLevel = pArgs->nSkillLevel;
        args.nDuration = pArgs->nDuration;
        int i = 0;
        do
        {
            args.nAuraStat[i] = pArgs->nAuraStat[i];
            args.nAuraStatCalcValue[i] = pArgs->nAuraStatCalcValue[i];
            ++i;
        } while (i < 6);

        D2AuraCallbackStrc auraCallback;
        auraCallback.pOwner = pOwner;
        auraCallback.pArgs = &args;
        auraCallback.pGame = pGame;
        SKILLS_AuraCallback_BasicAura(&auraCallback, pUnit);
    }

    D2DamageStrc* pDamage = pArgs->pDamage;
    if (pDamage)
    {
        D2DamageStrc damage = *pDamage;
        SUNITDMG_ExecuteEvents(pGame, pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pOwner, pUnit, &damage);
    }

    const int nRoll = ITEMS_RollRandomNumber(&pUnit->pSeed) % 100;
    if (nRoll < 20)
    {
        STATES_ToggleState(pUnit, 0x6B, 1);
        return 1;
    }

    STATES_ToggleState(pUnit, 0x6B, 0);
    return 1;
}
