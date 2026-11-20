#include "D2Structs.h"
struct D2PlayerDataStrc
{
    char unk0x00[128];
    int nSwitchRightSkillId;
    int nSwitchLeftSkillId;
    int nSwitchRightSkillFlags;
    int nSwitchLeftSkillFlags;
    int nWeaponGUID;
};


struct D2MonStats2Txt
{
    int dwId;
    unsigned char nFlags[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MONMODE_DEAD 12
#define MONSTATS2FLAGINDEX_CORPSESEL 7
#define MONSTATS2FLAGINDEX_DEADCOL 19

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x00623300
void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSwitchLeftSkillId, int nSwitchLeftSkillFlags)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 5288);

        pPlayerData->nSwitchLeftSkillId = nSwitchLeftSkillId;
        pPlayerData->nSwitchLeftSkillFlags = nSwitchLeftSkillFlags;
    }
}

// 0x00623350
void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSwitchRightSkillId, int nSwitchRightSkillFlags)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 5303);

        pPlayerData->nSwitchRightSkillId = nSwitchRightSkillId;
        pPlayerData->nSwitchRightSkillFlags = nSwitchRightSkillFlags;
    }
}

// 0x006233A0
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 5317);

        if (pWeapon)
        {
            D2_ASSERT(pWeapon->dwUnitType == UNIT_ITEM, 5321);

            pPlayerData->nWeaponGUID = pWeapon->dwUnitId;
        }
        else
        {
            pPlayerData->nWeaponGUID = 0;
        }
    }
}

// 0x00623600
int __stdcall UNITS_IsCorpseUseable(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (pUnit->dwAnimMode != MONMODE_DEAD)
        return 0;

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2TxtRecord)
        return 0;

    if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_DEADCOL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_DEADCOL & 7])
        return 0;

    if (!(pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_CORPSESEL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_CORPSESEL & 7]))
        return 0;

    return STATES_CheckStateMaskUdeadOnUnit(pUnit) == 0;
}
