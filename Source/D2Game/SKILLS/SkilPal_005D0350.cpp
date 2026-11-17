#include "D2Game.h"

// build: context SKILLS_GetSkillsTxtRecord

struct D2SeedStrc { unsigned int nLowSeed, nHighSeed; };
struct D2GameStrc { char pad00[0x1c]; void* pMemoryPool; char pad20[0x88]; int dwGameFrame; };
struct D2UnitStrc {
 int dwUnitType; int dwClassId; int pad08; int dwUnitId;
 char pad10[0x10]; D2SeedStrc pSeed; char pad28[0x9c]; unsigned int dwFlags;
 char padC8[8]; int nNodeIndex;
};
struct D2SkillsTxt {
 char pad00[0x60]; unsigned int dwAuraLenCalc; char pad64[0x1e]; short wAuraTargetState;
 char pad84[0xb4]; unsigned int dwCalc[4]; char pad148[0xf4];
};
struct D2DataTablesStrc {
 char pad00[0xc4]; int nStatesTxtRecordCount; char padC8[0xad0];
 D2SkillsTxt* pSkillsTxt; int padB9C; int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc*); // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc*, int); // 0x0056E2F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc*, D2UnitStrc*); // 0x0057D690
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0057D4F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, void (__fastcall*)(D2UnitStrc*,int,D2StatListStrc*)); // 0x00625CE0
void __fastcall SKILLS_StatRemoveCallback_Conversion(D2UnitStrc*,int,D2StatListStrc*); // 0x005D01A0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
void __stdcall D2COMMON_10476(D2StatListStrc*, int); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
void __fastcall sub_6FD154D0(D2UnitStrc*); // 0x0056E580
void __fastcall sub_6FCBDD30(D2UnitStrc*, unsigned char, int); // 0x005543B0
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc*, D2UnitStrc*, int, int); // 0x005B1900
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc*, D2UnitStrc*); // 0x00620C10
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc*, int); // 0x00625760
void __stdcall D2Common_10474(D2UnitStrc*, D2StatListStrc*); // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc*); // 0x00626CD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, unsigned short); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150
int __fastcall DATATBLS_ApplyRatio(int, int, int); // 0x00483360
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, unsigned short); // 0x00627260
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D02B0
static int __stdcall sub_005D02B0_CanConvertTarget(D2UnitStrc* pUnit, int nSkillLevel, int bRoll, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && !MONSTERS_GetHirelingTypeId(pTarget))
    {
        const int nType = pTarget ? pTarget->dwUnitType : 6;
        if (nType == 1 && !STATLIST_GetUnitAlignment(pTarget) && sub_6FD15190(pTarget, 11))
        {
            const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
            if (!bRoll || (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x005D0350
int __fastcall SKILLS_SrvDo079_Conversion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
 D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
 if (!pSkillsTxtRecord) return 0;
 if (pUnit) pUnit->dwFlags |= 0x40;
 D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
 if (!pTarget) return 0;
 int bConverted = 0;
 if (SUNITDMG_GetDamageFromUnits(pUnit, pTarget))
  bConverted = sub_005D02B0_CanConvertTarget(pUnit, nSkillLevel, 1, pTarget, nSkillId);
 if (pSkillsTxtRecord->wAuraTargetState < 0)
 {
Drain:
  SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
  return 1;
 }
 if (pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
  goto Drain;
 if (!bConverted)
  goto Drain;
 int nFrame = pGame->dwGameFrame;
 int nExpireFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel) + nFrame;
 if (nExpireFrame <= nFrame + 1) nExpireFrame = nFrame + 1;
 D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState);
 if (!pStatList)
 {
  int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
  int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
  pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0x802, nExpireFrame, nUnitType, nUnitId);
  if (!pStatList) return 0;
  STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
  STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_Conversion);
  D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
  STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
 }
 D2COMMON_10476(pStatList, nExpireFrame);
 EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
 sub_6FD154D0(pTarget);
 sub_6FCBDD30(pTarget, 2, 1);
 D2GAME_UpdateSummonAI_6FC401F0(pGame, pTarget, 0, pUnit->nNodeIndex);
 UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
 for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pTarget, 8); i; i = STATLIST_GetStatListFromUnitAndFlag(pTarget, 8))
 {
  D2Common_10474(pTarget, i);
  STATLIST_FreeStatList(i);
 }
 int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 12, 0);
 int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
 if (nTargetLevel && nUnitLevel < nTargetLevel && !STATLIST_GetStatListFromUnitAndState(pTarget, 109))
 {
  int nTargetId = pTarget->dwUnitId;
  int nTargetType = pTarget->dwUnitType;
  D2StatListStrc* pSave = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, nTargetType, nTargetId);
  if (pSave)
  {
   STATLIST_SetState(pSave, 109);
   D2COMMON_10475_PostStatToStatList(pTarget, pSave, 1);
   int nHp = STATLIST_UnitGetStatValue(pTarget, 6, 0) >> 8;
   int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget) >> 8;
   STATLIST_SetStatIfListIsValid(pSave, 176, nTargetLevel, 0);
   STATLIST_SetStatIfListIsValid(pSave, 177, nMaxHp, 0);
   int nNewHp = DATATBLS_ApplyRatio(nHp, nUnitLevel, nTargetLevel) << 8;
   int nNewMaxHp = DATATBLS_ApplyRatio(nMaxHp, nUnitLevel, nTargetLevel) << 8;
   if (nNewMaxHp < 1) nNewMaxHp = 1;
   nNewHp = (nNewHp > 1 ? nNewHp : 1) < nNewMaxHp ? (nNewHp > 1 ? nNewHp : 1) : nNewMaxHp;
   STATLIST_SetUnitStat(pTarget, 12, nUnitLevel, 0);
   STATLIST_SetUnitStat(pTarget, 6, nNewHp, 0);
   STATLIST_SetUnitStat(pTarget, 7, nNewMaxHp, 0);
  }
 }
 return 1;
}
