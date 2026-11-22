#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2UnitData.h"

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

typedef void (__fastcall* UMODCALLBACK)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern const int gaUModList_006DA4C8[4];                                                                     // 0x006DA4C8

extern UMODCALLBACK gpfnUModCallbacks_00724D78[];                                                            // 0x00724D78

// 0x004ACD70
void __fastcall MONUNIQUE_AssignTeleportSkill(D2UnitStrc* pUnit, int nUnused, int bAssign)
{
    if (bAssign)
    {
        SKILLS_AssignSkill(pUnit, SKILL_MONTELEPORT, 1, 1, ".\\UNIT\\MonUnique.cpp", 0x157);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
    }
}

// build: context sub_0044BE50
static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

// build: context MONSTERS_CheckMonTypeFlag
static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

// 0x004AD020
void __fastcall MONUNIQUE_ApplyUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
    {
        unsigned char* pUMods = pMonsterData->nMonUmod;
        if (pUMods && *pUMods)
        {
        const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);

        for (int j = 0; j < 4; ++j)
        {
            const int nUMod = gaUModList_006DA4C8[j];
            if (gpfnUModCallbacks_00724D78[nUMod])
                gpfnUModCallbacks_00724D78[nUMod](pUnit, nUMod, bUnique);
        }

        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (gpfnUModCallbacks_00724D78[nUMod])
                gpfnUModCallbacks_00724D78[nUMod](pUnit, nUMod, bUnique);
        }
        }
    }
}

#include "gen/data/Source/D2Client/UNIT/MonUnique.inc"
