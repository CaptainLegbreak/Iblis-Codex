#include "D2Game.h"

#define D2MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2MIN(a, b) (((a) < (b)) ? (a) : (b))
struct D2MonStatsTxt;
struct D2SkillsTxt;
struct D2ModeChangeStrc;
struct D2DamageHitClassMappingStrc;
struct D2SeedStrc;
struct D2CurseStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
    unsigned char unk_14[0xC];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x88];
    unsigned int dwLastHitClass;
    char unk0xB4[0x10];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    unsigned char unk_10[0xC];
    short wMonType;
};

struct D2SkillsTxt
{
    char unk0x000[0x0FC];
    short wStSound;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    char unk0x08[0x44];
    int dwDmgTotal;
    char unk0x50[0x10];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit   ;
    int nX                        ;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

extern "C" const D2DamageHitClassMappingStrc gsDamageHitClassMapping_006E16D8[8]; // 0x006E16D8
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode); // 0x0046C140
void __fastcall sub_6FC62DF0(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A54F0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall sub_0057CB00(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nHitClass); // 0x0057CB00
void __fastcall sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A43A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned char __fastcall sub_6FC62F50(D2UnitStrc* pUnit); // 0x005A5650
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct D2StatStrc
{
    unsigned short nLayer;
    unsigned short nStat;
    int nValue;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, void* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit); // 0x006223F0
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2); // 0x0057A830
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_005347B0_Stub5(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nChance, int nRand); // 0x005347B0
void* __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940

static unsigned char s_nHitClassCounter_0088CAD0; // 0x0088CAD0

// 0x0057CE30
static unsigned int SUNITDMG_GetHitClass(D2DamageStrc* pDamage, unsigned int nBaseHitClass)
{
    unsigned int nHitClass = 0;
    int nIndex = s_nHitClassCounter_0088CAD0 % 0x04;
    ++s_nHitClassCounter_0088CAD0;

    const int nEnd = nIndex + 0x04;

    while (nIndex < nEnd)
    {
        if (*(int*)((char*)pDamage + gsDamageHitClassMapping_006E16D8[nIndex].nDamageStrcOffset) > 0)
        {
            nHitClass = gsDamageHitClassMapping_006E16D8[nIndex].nHitClass;
            break;
        }

        ++nIndex;
    }

    if (!nHitClass)
    {
        if (pDamage->wResultFlags & 0x2000)
        {
            nHitClass = 0x10;
        }
    }

    if (!nBaseHitClass)
    {
        nBaseHitClass = 0x0D;
    }

    return nBaseHitClass | nHitClass;
}

// 0x0057CEC0
static void sub_0057CEC0_SetHitClassIfUnset(D2DamageStrc* pDamage)
{
    if (!pDamage->nHitClassActiveSet && !(pDamage->dwHitClass & 0xF0))
    {
        pDamage->dwHitClass = SUNITDMG_GetHitClass(pDamage, pDamage->dwHitClass);
    }
}

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (UNITS_GetRoom(pUnit) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!pAttacker || pAttacker->dwUnitType != 1)
        {
            return;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->nMonStatsFlags[0x0A >> 3] & gdwBitMasks[0x0A & 7]))
        {
            return;
        }
    }

    if (pDamage->wResultFlags & 1)
    {
        sub_0057CEC0_SetHitClassIfUnset(pDamage);
        pUnit->dwLastHitClass = pDamage->dwHitClass;
    }

    if (STATES_CheckState(pUnit, 0x36))
    {
        if (pDamage->wResultFlags & 0x02)
        {
            STATES_ToggleState(pUnit, 0x5C, 1);
        }
        return;
    }

    int nType = 0x06;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
    {
        if (pDamage->wResultFlags & 0x80)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x41);
            if (pStatList)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, 0x15E, 0));
                if (pSkill)
                {
                    SKILLS_SetFlags(pSkill, SKILLS_GetFlags(pSkill) | 0x04);
                    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, 0x0D, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x100)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x42);
            if (pStatList)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, 0x15E, 0));
                if (pSkill)
                {
                    SKILLS_SetFlags(pSkill, SKILLS_GetFlags(pSkill) | 0x04);
                    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, 0x0D, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x200)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 0x44);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);

                if (SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->wStSound > 0)
                    {
                        SUNIT_AttachSound(pUnit, 0x0C, pUnit);
                    }
                }
            }
            return;
        }
        else if (pDamage->wResultFlags & (0x10 | 0x8000))
        {
            if (pDamage->wResultFlags & 0x4000)
            {
                return;
            }

            const int nLastBlockFrame = STATLIST_UnitGetStatValue(pUnit, 0x5F, 0);
            const int nBlockRate = STATLIST_UnitGetStatValue(pUnit, 0x66, 0);
            if ((int)(pGame->dwGameFrame - nLastBlockFrame) > nBlockRate / 0x08 + 0x0F)
            {
                sub_6FC817D0(pGame, pUnit, 0, 0x09, 0, 0, 0);
                STATLIST_SetUnitStat(pUnit, 0x5F, pGame->dwGameFrame, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x02)
        {
            if (pUnit && pUnit->dwAnimMode != 0 && pUnit->dwAnimMode != 0x11)
            {
                D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 0, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            }
            return;
        }
        else if (pDamage->wResultFlags & 0x08)
        {
            D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, 0, 0x13, !pAttacker ? 0x06 : pAttacker->dwUnitType, !pAttacker ? -1 : pAttacker->dwUnitId, 0);
            return;
        }
        else
        {
            if (pDamage->wResultFlags & 0x04)
            {
                if (STATLIST_GetStatListFromUnitAndState(pUnit, 0x15) || !sub_0057CB00(pUnit, pDamage, pDamage->dwHitClass))
                {
                    sub_6FC817D0(pGame, pUnit, 0, 0x04, pDamage->dwDmgTotal, 0, 0);
                    return;
                }
            }
            else
            {
                if (!(pDamage->wResultFlags & 0x4000))
                {
                    return;
                }
            }

            UNITROOM_RefreshUnit(pUnit);
            if (pUnit)
            {
                pUnit->dwFlags |= 0x8000;
            }
            return;
        }
    }
    case 1:
    {
        if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 0x0C)
        {
            return;
        }

        const unsigned short wResultFlags = pDamage->wResultFlags;
        if (wResultFlags & 0x08)
        {
            if (!sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, 0x0D))
            {
                pDamage->wResultFlags = wResultFlags & (unsigned short)(~0x08) | 0x04;
            }
        }

        sub_6FC62DF0(pGame, pAttacker, pUnit, pDamage);

        if (pDamage->wResultFlags & 0x02)
        {
            SUNITDMG_KillMonster(pGame, pUnit, pAttacker, 1);
            return;
        }

        D2ModeChangeStrc modeChange;
        if (pDamage->wResultFlags & 0x08)
        {
            MONSTERMODE_GetModeChangeInfo(pUnit, 0x0D, &modeChange);
            modeChange.pTargetUnit = pAttacker;
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            return;
        }

        if (pDamage->wResultFlags & 0x10)
        {
            if (pDamage->wResultFlags & 0x4000 || pUnit->dwClassId == 0xF3 || pUnit->dwClassId == 0x14D || pUnit->dwClassId == 0x2C1
                || !sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, 0x06))
            {
                MONSTER_SetAiState(pUnit, 0x13);
                return;
            }

            MONSTERMODE_GetModeChangeInfo(pUnit, 0x06, &modeChange);
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            return;
        }

        if (pDamage->wResultFlags & 0x04)
        {
            if (STATLIST_GetStatListFromUnitAndState(pUnit, 0x15) || !sub_0057CB00(pUnit, pDamage, pDamage->dwHitClass))
            {
                MONSTERMODE_GetModeChangeInfo(pUnit, 0x03, &modeChange);
                D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                sub_6FC6E8A0(pGame, pUnit);
                return;
            }

            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlags |= 0x8000;
            MONSTER_SetAiState(pUnit, 0x13);
            sub_6FC6E8A0(pGame, pUnit);
            return;
        }

        if (pDamage->wResultFlags & 0x4000)
        {
            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlags |= 0x8000;
            MONSTER_SetAiState(pUnit, 0x13);
            sub_6FC6E8A0(pGame, pUnit);
            return;
        }

        if (pDamage->wResultFlags & 1 && pDamage->dwDmgTotal > 0)
        {
            const unsigned char nLastHpPct = (unsigned char)STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
            int nHpDiff = nLastHpPct - sub_6FC62F50(pUnit);
            if (nHpDiff < 0)
            {
                nHpDiff = -nHpDiff;
            }

            if (nHpDiff > 0x04)
            {
                UNITROOM_RefreshUnit(pUnit);
                pUnit->dwFlags |= 0x8000;
            }
        }
        return;
    }
    }
}

#include "gen/data/Source/D2Game/UNIT/SUnitDmg_0057CE30.inc"

// 0x0057D810
static void SUNITDMG_PreventMonsterHeal(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (pAttacker && pAttacker->dwUnitType == 0 && (pDefender ? pDefender->dwUnitType : 6) == 1 && STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 117, 0))
    {
        if (pDefender->dwClassId >= 704 && pDefender->dwClassId <= 709)
        {
            return;
        }

        D2CurseStrc curse = {};
        curse.pUnit = pAttacker;
        curse.pTarget = pDefender;
        curse.nSkill = 0;
        curse.nSkillLevel = 1;
        curse.nDuration = 120000;
        curse.nStat = 31;
        curse.nStatValue = 0;
        curse.nState = 52;
        sub_0056E970(&curse);
    }
}

// 0x0057D8A0
static void __stdcall sub_0057D8A0_ApplyTargetDefenseModifiers(int* pAttackRate, int* pDefense, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    if (STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 115, 0) && pDefender && pDefender->dwUnitType == 1
        && !MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 10) && !MONSTERS_IsBoss(0, pDefender) && !MONSTERS_GetHirelingTypeId(pDefender))
    {
        *pDefense = 0;
    }

    int nFractionalTargetAc = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 116, 0);
    if (nFractionalTargetAc > 0)
    {
        if (pDefender && (pDefender->dwUnitType == 0 || pDefender->dwUnitType == 1
            && (MONSTERS_IsBoss(0, pDefender) || MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 2) || MONSTERS_GetHirelingTypeId(pDefender))))
        {
            nFractionalTargetAc /= 2;
        }

        nFractionalTargetAc = D2MIN(D2MAX(nFractionalTargetAc, 0), 100);

        const int nDefense = *pDefense;
        *pDefense = nDefense - DATATBLS_ApplyRatio(nDefense, nFractionalTargetAc, 100);
    }

    const int nDemonToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 123, 0);
    if (nDemonToHit && MONSTERS_IsDemon(pDefender))
    {
        *pAttackRate += nDemonToHit;
    }

    const int nUndeadToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 124, 0);
    if (nUndeadToHit && MONSTERS_IsUndead(pDefender))
    {
        *pAttackRate += nUndeadToHit;
    }
}

static inline int I13_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static inline D2MonStatsTxt* I13_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x0057D9B0
int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile)
{
    if (!pDefender || !pAttacker)
    {
        return 0;
    }

    const int nDefenderLevel = STATLIST_UnitGetStatValue(pDefender, 12, 0);
    int nTotalDefense = UNITS_GetDefense(pDefender);
    if (bMissile)
    {
        nTotalDefense += STATLIST_UnitGetStatValue(pDefender, 32, 0);
    }
    else
    {
        nTotalDefense += STATLIST_UnitGetStatValue(pDefender, 33, 0);
    }
    const int nAttackerLevel = STATLIST_UnitGetStatValue(pAttacker, 12, 0);

    int nAttackRate = 0;
    int nToHitPercent = 0;
    const int nAttackerType = I13_GetUnitType(pAttacker);
    if (nAttackerType == 0)
    {
        nAttackRate = UNITS_GetAttackRate(pAttacker);
        sub_0057D8A0_ApplyTargetDefenseModifiers(&nAttackRate, &nTotalDefense, pDefender, pAttacker);

        if (!bMissile)
        {
            D2UnitStrc* pWeapon = sub_6FC7C7B0(pAttacker);
            if (pWeapon)
            {
                nToHitPercent = SKILLS_GetWeaponMasteryBonus(pAttacker, pWeapon, 0, 0);
            }
        }

        nToHitPercent += nStatValue + STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 119, 0);

        {
            D2MonStatsTxt* pMonStatsTxtRecord = I13_GetMonStatsTxtRecord(pDefender);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType > 0)
            {
                const int nMonType = pMonStatsTxtRecord->wMonType;
                D2StatStrc stats[128];
                const int nStats = STATLIST_CopyStats(pAttacker, 179, stats, 128);
                for (int i = 0; i < nStats; ++i)
                {
                    if (SUNITDMG_CheckMonType(stats[i].nLayer, nMonType))
                    {
                        nToHitPercent += stats[i].nValue;
                    }
                }
            }
        }
    }

    else
    {
        nAttackRate = STATLIST_UnitGetStatValue(pAttacker, 19, 0);
        nAttackRate += nStatValue + 5 * STATLIST_UnitGetStatValue(pAttacker, 2, 0);
        nToHitPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, 119, 0);
    }

    nAttackRate += DATATBLS_ApplyRatio(nAttackRate, nToHitPercent, 100);
    if (nTotalDefense < 0)
    {
        nAttackRate -= nTotalDefense;
        nTotalDefense = 0;
    }

    if (nAttackRate < 0)
    {
        nTotalDefense -= nAttackRate;
        nAttackRate = 0;
    }

    if (nTotalDefense < 0)
    {
        nTotalDefense = 0;
    }

    const int nDivisor = nAttackRate + nTotalDefense;
    int nToHitFactor = 100;
    if (nDivisor)
    {
        nToHitFactor = 100 * nAttackRate / nDivisor;
    }

    int nChanceToHit = 2 * nAttackerLevel * nToHitFactor / (nDefenderLevel + nAttackerLevel);
    nChanceToHit = D2MIN(D2MAX(nChanceToHit, 5), 95);

    D2SeedStrc* pSeed = &pAttacker->pSeed;
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    const int nRand = (unsigned int)lSeed % 100;

    sub_005347B0_Stub5(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pDefender, nChanceToHit, nRand);
    if (nRand < nChanceToHit)
    {
        SUNITDMG_PreventMonsterHeal(pAttacker, pDefender);
        return 1;
    }

    return 0;
}
