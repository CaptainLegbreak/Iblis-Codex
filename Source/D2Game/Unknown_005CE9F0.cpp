#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"


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
    int unk0x40;
    int dwStunLen;
    int unk0x48;
    int dwDmgTotal;
    int unk0x50[4];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};




#define UNIT_PLAYER 0
#define STATE_HOLYSHIELD 101
#define MONMODE_ATTACK2 5
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
#define HITFLAG_SMITE 2
#define HITCLASS_SMITE 0x65
#define SRCDAM_SMITE 0x80

typedef int BOOL;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus);               // 0x00622C40
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
D2SkillStrc* __stdcall sub_006260E0(D2StatListStrc* pStatList);                                        // 0x006260E0
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc* pStatList);                                            // 0x00626100
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
BOOL __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem);              // 0x0063C8F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);           // 0x00647BC0
int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);           // 0x00647D00

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005CE9F0
int __fastcall SKILLS_SrvDo150_Smite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pShield;
        if (!INVENTORY_GetEquippedShield(pUnit->pInventory, &pShield))
        {
            return 0;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pShield ? -1 : pShield->dwClassId);
        if (!pItemsTxtRecord)
        {
            return 0;
        }

        int nMinDamage = pItemsTxtRecord->nMinDam << 8;
        int nMaxDamage = pItemsTxtRecord->nMaxDam << 8;
        if (STATES_CheckState(pUnit, STATE_HOLYSHIELD))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HOLYSHIELD);
            if (pStatList)
            {
                const int nHolyShieldId = (int)sub_006260E0(pStatList);
                const int nHolyShieldLevel = STATLIST_GetSkillLevel(pStatList);
                nMinDamage += SKILLS_GetMinPhysDamage(pUnit, nHolyShieldId, nHolyShieldLevel, 1);
                nMaxDamage += SKILLS_GetMaxPhysDamage(pUnit, nHolyShieldId, nHolyShieldLevel, 1);
            }
        }

        const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pUnit, 0, pShield, nMinDamage, nMaxDamage, nDamagePercent, 0, SRCDAM_SMITE);

        const int nStunLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);

        damage.dwStunLen = nStunLength;
        damage.dwHitFlags = HITFLAG_SMITE;
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0) | DAMAGERESULTFLAG_SUCCESSFULHIT;
    }
    else
    {
        sub_6FC627B0(pUnit, MONMODE_ATTACK2);
        damage.dwStunLen = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
    }

    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    }

    damage.dwHitClass = HITCLASS_SMITE;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, SRCDAM_SMITE);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}
