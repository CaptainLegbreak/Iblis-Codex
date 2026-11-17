#include "D2Game.h"

struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { char unk_00[0x20]; D2SeedStrc pSeed; char unk_28[0x9C]; unsigned int dwFlags; };
struct D2DamageStrc { int unk_00; unsigned short wResultFlags; };
struct D2SkillsTxt { char unk_00[4]; unsigned char nFlags[4]; char f_8[0x28]; short wProgFunc[3]; char unk_36[0x1E]; short wAuraStat[6]; };
struct D2DataTablesStrc { char unk_00[0x16C]; short* pProgressiveStates; short nProgressiveStates; char unk_172[0xA62]; int nItemStatCostTxtRecordCount; };
typedef int (__fastcall *SkillDoFunc)(D2GameStrc*, D2UnitStrc*, int, int);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern const int gnSkillSrvDoFnCount_006E1274; // 0x006E1274
extern const SkillDoFunc gpSkillSrvDoFnTable_007322B0[]; // 0x007322B0
unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc*); // 0x0045C370
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
void __fastcall sub_00571AA0_SendProgressiveEvent(D2UnitStrc*, D2UnitStrc*, short, short, int, int, unsigned char); // 0x00571AA0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*, D2UnitStrc*, int); // 0x00622C40
int __stdcall UNITS_IsInMovingMode(D2UnitStrc*); // 0x00622D00
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc*, int, unsigned short); // 0x00625D00
void __stdcall STATLIST_FreeStatList(D2StatListStrc*); // 0x00626CD0
void __stdcall STATLIST_SetStat(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc*, D2StatListStrc*); // 0x006277E0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall STATES_UpdatePgsvFlags(D2UnitStrc*); // 0x0063A2D0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
void __fastcall sub_00650E60(D2SeedStrc*, unsigned int, unsigned int); // 0x00650E60
void __fastcall sub_00650E70(D2SeedStrc*, unsigned int*, unsigned int*); // 0x00650E70

#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
// 0x005D5220
void __fastcall sub_005D5220_DischargeProgressiveSkills(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
        return;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return;
    UNITS_IsInMovingMode(pTarget);
    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        return;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (!STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
            continue;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
        if (!pStatList)
            continue;
        int nSkill = STATLIST_GetStatValue(pStatList, 350, 0);
        D2SkillsTxt* pSkills = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
        if (pSkills)
        {
            int nLevel = STATLIST_GetStatValue(pStatList, 351, 0);
            int nCurrentLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkill), 1);
            if (nCurrentLevel > nLevel)
                nLevel = nCurrentLevel;
            if (nLevel > 0 && pSkills->wAuraStat[0] >= 0 && pSkills->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                int nCharges = STATLIST_GetStatValue(pStatList, pSkills->wAuraStat[0], 0);
                nCharges = D2_MIN(D2_MAX(nCharges,1),3);
                unsigned int nLowSeed, nHighSeed;
                sub_00650E70(&pUnit->pSeed, &nLowSeed, &nHighSeed);
                int nSeed = (int)SEED_RollRandomNumber(&pUnit->pSeed);
                sub_00650E60(&pUnit->pSeed, nLowSeed, nHighSeed);
                --nCharges;
                if (pSkills->nFlags[0] & (unsigned char)gdwBitMasks[7])
                {
                    for (int j = 0; j < nCharges; ++j)
                    {
                        if (pSkills->wProgFunc[j] > 0 && pSkills->wProgFunc[j] < gnSkillSrvDoFnCount_006E1274)
                        {
                            STATLIST_SetStat(pStatList, pSkills->wAuraStat[0], j + 1, 0);
                            SkillDoFunc pDo = gpSkillSrvDoFnTable_007322B0[pSkills->wProgFunc[j]];
                            if (pDo)
                                pDo(pGame, pUnit, nSkill, nLevel);
                        }
                    }
                    STATLIST_SetStat(pStatList, pSkills->wAuraStat[0], nCharges + 1, 0);
                }
                if (pSkills->wProgFunc[nCharges] > 0 && pSkills->wProgFunc[nCharges] < gnSkillSrvDoFnCount_006E1274)
                {
                    SkillDoFunc pDo = gpSkillSrvDoFnTable_007322B0[pSkills->wProgFunc[nCharges]];
                    if (pDo)
                        pDo(pGame, pUnit, nSkill, nLevel);
                }
                sub_00571AA0_SendProgressiveEvent(pUnit, pTarget, (short)nSkill, (short)nLevel, nSeed, 0, (unsigned char)(nCharges + 1));
            }
        }
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    STATES_UpdatePgsvFlags(pUnit);
}

#include "gen/data/Source/D2Game/SKILLS/SkillAss_005D5220.inc"
