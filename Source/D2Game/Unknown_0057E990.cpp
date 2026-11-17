#include "D2Game.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    unsigned short wName;
    short unk0x06;
    int nHirelingId;
};

struct D2HirelingTxt
{
    char unk0x00[0x20];
    int dwExpPerLvl;
};

struct D2PartyExpStrc
{
    D2UnitStrc* pDefenderUnit;
    D2UnitStrc* pMembers[8];
    int nMemberLevels[8];
    int nMembers;
    int nLevelSum;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_LEVEL 12
#define STAT_EXPERIENCE 13
#define STAT_LASTEXP 29
#define STAT_ITEM_ADDEXPERIENCE 85
#define UNITEVENT_LEVELUP 12
#define PETTYPE_HIREABLE 7
#define STATLIST_FLAG_EXP 0x800

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID);               // 0x00574BD0
int __stdcall DATATBLS_GetMaxLevel(int nClass);                                                             // 0x00611830
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel);                                           // 0x00611800
int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int nExperience);                        // 0x00611860
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00570880
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, void* pDamage); // 0x005C0C30
typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc*, D2UnitStrc*, void*);
void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0
void __fastcall SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x0057E5A0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, int nLevel); // 0x00572840
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3);                   // 0x005726C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630

// 0x0057E2F0
static int sub_0057E2F0_ApplyLevelDifferenceFactor(int nAttackerLevel, int nExperience, int nDefenderLevel)
{
    if (nDefenderLevel <= nAttackerLevel)
    {
        int nIndex = nAttackerLevel - nDefenderLevel;
        if (nIndex >= 11)
        {
            nIndex = 10;
        }

        const int nFactor = gnExpFactorLowerLevel_006E1668[nIndex];
        if (nFactor != 256)
        {
            return DATATBLS_ApplyRatio(nExperience, nFactor, 256);
        }
    }
    else
    {
        if (nAttackerLevel >= 25 && nDefenderLevel > 0)
        {
            return DATATBLS_ApplyRatio(nExperience, nAttackerLevel, nDefenderLevel);
        }

        int nIndex = nDefenderLevel - nAttackerLevel;
        if (nIndex >= 11)
        {
            nIndex = 10;
        }

        const int nFactor = gnExpFactorHigherLevel_006E1694[nIndex];
        if (nFactor != 256)
        {
            return DATATBLS_ApplyRatio(nExperience, nFactor, 256);
        }
    }

    return nExperience;
}

// 0x0057E390
static int __stdcall sub_0057E390_ApplyExpRatio(int nLevel, int nResult)
{
    if (nResult <= 0)
    {
        return nResult;
    }

    const int nRatio1 = DATATBLS_GetExpRatio(nLevel);
    const int nRatio2 = DATATBLS_GetExpRatio(0);
    if (nRatio2 > 0 && nRatio2 < 32)
    {
        if (nResult > (0x7FFFFFFF >> (nRatio2 + (nRatio1 >> nRatio2))))
        {
            nResult = nRatio1 * (nResult >> nRatio2);
        }
        else
        {
            nResult = nResult * nRatio1 >> nRatio2;
        }
    }

    return nResult;
}

// 0x0057E3F0
static unsigned int __stdcall sub_0057E3F0_CapHirelingExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, int nAttackerLevel, unsigned int nResult)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER)
    {
        return nResult;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pAttacker ? -1 : pAttacker->dwUnitId);
    if (!pPetInfo)
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nAttackerLevel);
    if (!pHirelingTxtRecord)
    {
        return 0;
    }

    const int nCurrentLevelExp = MONSTERS_GetHirelingExpForNextLevel(nAttackerLevel, pHirelingTxtRecord->dwExpPerLvl);
    const int nNextLevelExp = MONSTERS_GetHirelingExpForNextLevel(nAttackerLevel + 1, pHirelingTxtRecord->dwExpPerLvl);
    const unsigned int nMaxExp = (unsigned int)(nNextLevelExp - nCurrentLevelExp) >> 6;
    if (nResult > nMaxExp)
    {
        nResult = nMaxExp;
    }

    return nResult;
}

// 0x0057E480
static int __stdcall SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, D2UnitStrc* pAttacker, int nAttackerLevel, int nDefenderLevel, int nDefenderExperience)
{
    if (nDefenderExperience > 0x7FFFFF)
    {
        nDefenderExperience = 0x7FFFFF;
    }

    if (nDefenderExperience <= 0)
    {
        return 1;
    }

    const int nClassId = (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER) ? pAttacker->dwClassId : 0;
    if (nAttackerLevel >= DATATBLS_GetMaxLevel(nClassId))
    {
        return 0;
    }

    int nResult = sub_0057E2F0_ApplyLevelDifferenceFactor(nAttackerLevel, nDefenderExperience, nDefenderLevel);
    nResult = sub_0057E390_ApplyExpRatio(nAttackerLevel, nResult);

    const int nAddExpPct = STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_ADDEXPERIENCE, 0);
    if (nAddExpPct)
    {
        nResult += DATATBLS_ApplyRatio(nResult, nAddExpPct, 100);
    }

    return sub_0057E3F0_CapHirelingExperience(pGame, pAttacker, nAttackerLevel, nResult);
}

// 0x0057E510
static void __stdcall SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOldLevel, unsigned int nExperienceGained)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    const int nClassId = pUnit->dwClassId;
    unsigned int nNewExperience = nExperienceGained + nExperience;
    const unsigned int nMaxExperience = DATATBLS_GetLevelThreshold(nClassId, DATATBLS_GetMaxLevel(nClassId) - 1);
    if (nNewExperience > nMaxExperience)
    {
        nNewExperience = nMaxExperience;
    }

    STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nNewExperience - nExperience, 0);
    STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNewExperience, 0);

    if (nOldLevel != DATATBLS_GetCurrentLevelFromExp(nClassId, nNewExperience))
    {
        PLAYERSTATS_LevelUp(pGame, pUnit);
        SUNITEVENT_Trigger(pGame, UNITEVENT_LEVELUP, pUnit, 0, 0);
    }
}

// 0x0057E6C0
static void __stdcall sub_0057E6C0_DistributePartyExperience(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDefender, int nPlayerLevel, int nDefenderLevel, int nDefenderExperience)
{
    D2PartyExpStrc partyExp;
    memset(&partyExp, 0, sizeof(partyExp));
    partyExp.pDefenderUnit = pDefender;
    PARTY_IteratePartyMembersInSameLevel(pGame, pPlayer, SUNITDMG_PartyCallback_ComputePartyExperience, &partyExp);

    if (partyExp.nMembers <= 0 || partyExp.nLevelSum <= 0)
    {
        return;
    }

    if (partyExp.nMembers == 1)
    {
        const int nExperience = SUNITDMG_ComputeExperienceGain(pGame, pPlayer, nPlayerLevel, nDefenderLevel, nDefenderExperience);
        SUNITDMG_AddExperienceForPlayer(pGame, pPlayer, nPlayerLevel, nExperience);
        return;
    }

    const int nExperience = nDefenderExperience + 89 * nDefenderExperience * (partyExp.nMembers - 1) / 256;
    const float multiplier = (float)nExperience / (float)partyExp.nLevelSum;
    for (int i = 0; i < partyExp.nMembers; ++i)
    {
        const int nMemberLevel = partyExp.nMemberLevels[i];
        D2UnitStrc* pMember = partyExp.pMembers[i];
        const int nExperienceGained = SUNITDMG_ComputeExperienceGain(pGame, pMember, nMemberLevel, nDefenderLevel, (int)((float)nMemberLevel * multiplier));
        SUNITDMG_AddExperienceForPlayer(pGame, pMember, nMemberLevel, nExperienceGained);
    }
}

// 0x0057E7B0
static D2UnitStrc* __stdcall sub_0057E7B0_GetExperienceOwner(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    int nType = UNIT_INVALID;
    if (pAttacker)
    {
        nType = pAttacker->dwUnitType;
    }

    switch (nType)
    {
    case UNIT_MONSTER:
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        D2StatListStrc* pStatList = 0;
        if (STATES_CheckStateMaskExpOnUnit(pAttacker))
        {
            pStatList = STATLIST_GetStatListFromUnitAndFlag(pAttacker, STATLIST_FLAG_EXP);
        }

        if (pDefender && STATES_CheckStateMaskExpOnUnit(pDefender))
        {
            pStatList = STATLIST_GetStatListFromUnitAndFlag(pDefender, STATLIST_FLAG_EXP);
        }

        if (pStatList)
        {
            const int nOwnerType = STATLIST_GetOwnerType(pStatList);
            const int nOwnerGUID = STATLIST_GetOwnerGUID(pStatList);
            pOwner = SUNIT_GetServerUnit(pGame, nOwnerType, nOwnerGUID);
        }

        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            return pOwner;
        }

        return 0;
    }
    case UNIT_PLAYER:
        return pAttacker;
    }

    return 0;
}

// 0x0057E860
static void __stdcall SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, int nLevel, int nExperienceBonus)
{
    if (nExperienceBonus <= 0)
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, !pHireling ? -1 : pHireling->dwUnitId);
    if (!pPetInfo)
    {
        return;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord || nLevel >= STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0))
    {
        return;
    }

    const unsigned int nCurrentExp = STATLIST_GetUnitBaseStat(pHireling, STAT_EXPERIENCE, 0);
    const unsigned int nNewExp = nCurrentExp + 2 * nExperienceBonus;
    const int nMaxLevel = DATATBLS_GetMaxLevel(0) - 1;
    if (nLevel >= nMaxLevel)
    {
        return;
    }

    STATLIST_SetUnitStat(pHireling, STAT_EXPERIENCE, nNewExp, 0);
    D2GAME_PACKETS_SendPacket0xA0_A1_A2_6FC3D610(SUNIT_GetClientFromPlayer(pPlayer, ".\\UNIT\\SUnitDmg.cpp", 4029), pHireling, STAT_EXPERIENCE, nCurrentExp, nNewExp);

    int nNewLevel = nLevel;
    do
    {
        if ((unsigned int)MONSTERS_GetHirelingExpForNextLevel(nNewLevel + 1, pHirelingTxtRecord->dwExpPerLvl) > nNewExp)
        {
            break;
        }

        nNewLevel += 1;
    }
    while (nNewLevel < nMaxLevel);

    if (nNewLevel > nLevel)
    {
        MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pHireling, nNewLevel);
        MONSTERAI_SendMercStats(pGame, pPlayer, 0);
        SUNIT_AttachSound(pHireling, 0x5B, pPlayer);
        SUNITEVENT_Trigger(pGame, UNITEVENT_LEVELUP, pHireling, 0, 0);
    }
}

// 0x0057E990
void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender || pAttacker->dwUnitType != UNIT_PLAYER && pAttacker->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    const int nDefenderExperience = STATLIST_GetUnitBaseStat(pDefender, STAT_EXPERIENCE, 0);
    if (nDefenderExperience <= 0)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_0057E7B0_GetExperienceOwner(pGame, pAttacker, pDefender);
    if (!pPlayer)
    {
        return;
    }

    const int nDefenderLevel = STATLIST_GetUnitBaseStat(pDefender, STAT_LEVEL, 0);
    D2UnitStrc* pPet = sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0);
    if (pPet)
    {
        const int nPetLevel = STATLIST_GetUnitBaseStat(pPet, STAT_LEVEL, 0);
        int nExperienceBonus = SUNITDMG_ComputeExperienceGain(pGame, pPet, nPetLevel, nDefenderLevel, nDefenderExperience);
        if (pAttacker != pPet)
        {
            nExperienceBonus = 86 * nExperienceBonus / 256;
        }

        SUNITDMG_AddExperienceForHireling(pGame, pPlayer, pPet, nPetLevel, nExperienceBonus);
    }

    const int nPlayerLevel = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0);
    if (SUNIT_GetPartyId(pPlayer) != -1)
    {
        sub_0057E6C0_DistributePartyExperience(pGame, pPlayer, pDefender, nPlayerLevel, nDefenderLevel, nDefenderExperience);
    }
    else
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pPlayer, nPlayerLevel, SUNITDMG_ComputeExperienceGain(pGame, pPlayer, nPlayerLevel, nDefenderLevel, nDefenderExperience));
    }
}

// 0x0057EAB0
void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, int nExperienceBonus)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nLevel, nExperienceBonus);
    }
    else
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            SUNITDMG_AddExperienceForHireling(pGame, pOwner, pUnit, nLevel, nExperienceBonus);
        }
    }
}

// build: context SUNITDMG_SetExperienceForTargetLevel
void __fastcall SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel)
{
    int nClassId;
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
    if (nTargetLevel <= nLevel)
    {
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nClassId = pUnit->dwClassId;
        const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        const unsigned int nThreshold = DATATBLS_GetLevelThreshold(nClassId, nTargetLevel);
        if (nThreshold > nExperience)
        {
            SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nLevel, nThreshold - nExperience);
        }
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER || nLevel >= DATATBLS_GetMaxLevel(0))
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, pUnit->dwUnitId);
    if (!pPetInfo)
    {
        return;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    const int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    SUNITDMG_AddExperienceForHireling(pGame, pOwner, pUnit, nLevel, MONSTERS_GetHirelingExpForNextLevel(nTargetLevel, pHirelingTxtRecord->dwExpPerLvl) - nExperience);
}
