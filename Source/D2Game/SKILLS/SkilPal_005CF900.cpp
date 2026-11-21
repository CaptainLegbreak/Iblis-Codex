#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameAux.h"

struct D2DamageStrc { unsigned int dwHitFlags; unsigned short wResultFlags; unsigned short wExtra; int dwPhysDamage; int dwEnDmgPct; int pad10[20]; unsigned int dwHitClass; unsigned char nHitClassActiveSet; unsigned char nConvType; unsigned short unk66; int dwConvPct; int nOverlay; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" void* __cdecl memset(void*, int, unsigned int);

int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860

int __fastcall sub_00463900_GetValidMonsterId(int nClassId); // 0x00463900

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nCustom); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nFrame, int nCustom, int nParam); // 0x005417D0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nId); // 0x00552F60

void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553DC0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nRange, unsigned int nFilter, int nId, int* pArg); // 0x0056BD10

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId); // 0x00571B70

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nToHit); // 0x0057EC10

int __fastcall sub_005CF8C0_GetSeqEventFrame(D2UnitStrc* pUnit); // 0x005CF8C0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nBonus); // 0x00622C40

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nFlags); // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nUnused); // 0x006449F0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

static __forceinline int GetUnitType(D2UnitStrc* pUnit) { int nType = 6; if (pUnit) nType = pUnit->dwUnitType; return nType; }

static __forceinline int GetUnitId(D2UnitStrc* pUnit) { int nId = -1; if (pUnit) nId = pUnit->dwUnitId; return nId; }

struct D2RedemptionAuraCallbackArgStrc
{
    int nSkillId;
    int nSkillLevel;
    int nCounter;
};

enum D2C_J10SkillPalConstants
{
    STAT_HITPOINTS = 6,
    STAT_MANA = 8,
    STATE_REDEEMED = 0x63,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
};

int __fastcall sub_0045C390_SeedRollLimited(D2SeedStrc* pSeed, int nMax);                                    // 0x0045C390

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

static __forceinline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005CF900
int __fastcall SKILLS_SrvDo067_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pRecord = GetSkillsRecord(nSkillId);
    if (!pRecord) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    if (DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit)) DATATBLS_GetSeqFrameCount(pUnit);
    int nFrame = sub_005CF8C0_GetSeqEventFrame(pUnit);
    int nTargetType = SKILLS_GetParam1(pSkill);
    int nTargetId = SKILLS_GetParam2(pSkill);
    D2UnitStrc* pTarget = 0;
    if (nTargetType != 6) pTarget = SUNIT_GetServerUnit(pGame, nTargetType, nTargetId);
    int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
    {
        int nRange = 0;
        if (pUnit && pUnit->dwUnitType == 1 && (nFlags & 2)) nRange = 3;
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, nRange))
        {
            SKILLS_SetFlags(pSkill, 0);
            D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, nFrame + 1);
            sub_00571B70_SkillUpdate(pUnit, nSkillId);
            return 1;
        }
        if (nFlags & 2)
        {
            SKILLS_SetFlags(pSkill, 0);
            sub_00571B70_SkillUpdate(pUnit, nSkillId);
            pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, 3, 3, nTargetId, 0);
            if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                SKILLS_SetParam1(pSkill, GetUnitType(pTarget));
                SKILLS_SetParam2(pSkill, GetUnitId(pTarget));
            }
            else
            {
                if (!pUnit || pUnit->dwUnitType != 1 || sub_00463900_GetValidMonsterId(sub_00463860(pUnit)) != 436 || sub_00463900_GetValidMonsterId(sub_00463860(pUnit)) != 441)
                {
                    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
                    EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 1, 0, 0);
                }
                return 0;
            }
        }
        else
        {
            if (pGame->dwGameFrame - (pUnit->nSeqCurrentFramePrecise >> 8) >= nFrame)
            {
                D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 0);
                SKILLS_SetFlags(pSkill, 1);
            }
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
            EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 1, 1, 0);
            pUnit->dwFlags &= ~0x40;
        }
        return 1;
    }
    SKILLS_SetFlags(pSkill, 0);
    SKILLS_SetParam1(pSkill, 0);
    SKILLS_SetParam2(pSkill, 0);
    sub_00571B70_SkillUpdate(pUnit, nSkillId);
    D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, nFrame);
    if (pUnit) pUnit->dwFlags |= 0x40;
    if (!pTarget)
    {
        pTarget = sub_6FD107F0(pGame, pUnit, 0, 0, 3, 3, -1, 0);
        if (!pTarget)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
            EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 1, 0, 0);
            return 0;
        }
    }
    int nRange = 0;
    if (pUnit && pUnit->dwUnitType == 1) nRange = 3;
    if (UNITS_IsInMeleeRange(pUnit, pTarget, nRange) && !SUNIT_IsDead(pUnit))
    {
        D2DamageStrc damage;
        memset(&damage, 0, sizeof(damage));
        if (pUnit && pUnit->dwUnitType == 0)
        {
            damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel, 0)) | 8;
        }
        else damage.wResultFlags = 9;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0) damage.nConvType = pRecord->nEType;
        }
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        if (pUnit && pUnit->dwUnitType == 1)
        {
            int nMode;
            switch (sub_00463900_GetValidMonsterId(pUnit->dwClassId))
            {
            case 73: nMode = 8; break;
            case 211: case 436: nMode = 5; break;
            default: nMode = 4; break;
            }
            sub_6FC627B0(pUnit, nMode);
        }
        damage.dwHitClass = 0x70;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, pRecord->nSrcDam);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        UNITS_SetOverlay(pTarget, 147, 0);
    }
    return 1;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context SKILLS_ApplyRedemptionEffect
static __forceinline int SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillId, int nSkillLevel, int bSkipChanceRoll)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!pCorpse)
    {
        return 0;
    }

    if (!sub_006456D0_CanUnitCorpseBeSelected(pCorpse))
    {
        return 0;
    }

    if (!bSkipChanceRoll)
    {
        const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (sub_0045C390_SeedRollLimited(&pUnit->pSeed, 100) >= nChance)
        {
            return 0;
        }
    }

    {
        const int nLifeBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) << 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        int nNewHp = nLifeBonus + STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
        if (nMaxLife < nNewHp)
        {
            nNewHp = nMaxLife;
        }
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

        const int nManaBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel) << 8;
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
        int nNewMana = nManaBonus + STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
        if (nMaxMana < nNewMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewMana, 0);

        STATES_ToggleState(pCorpse, STATE_REDEEMED, 1);
        pCorpse->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_CANBEATTACKED);
        return 1;
    }
}

// 0x005D0D70
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2RedemptionAuraCallbackArgStrc* pArgs = (D2RedemptionAuraCallbackArgStrc*)pAuraCallback->pArgs;

    D2UnitStrc* pOwner = pAuraCallback->pOwner;
    const int nSkillLevel = pArgs->nSkillLevel;
    const int nSkillId = pArgs->nSkillId;

    const int nResult = SKILLS_ApplyRedemptionEffect(pAuraCallback->pGame, pOwner, pUnit, nSkillId, nSkillLevel, 0);
    if (nResult)
    {
        ++pArgs->nCounter;
    }

    return nResult;
}
