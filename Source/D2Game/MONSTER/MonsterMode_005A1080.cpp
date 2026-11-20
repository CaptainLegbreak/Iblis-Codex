#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

enum D2C_P08MonsterConstants
{
    MONMODE_DEATH = 0,
    MONMODE_GETHIT = 3,
    MONMODE_SKILL1 = 8,
    MONMODE_DEAD = 12,
    MONLVL_DM = 6,
    STAT_LEVEL = 12,
    STAT_DAMAGERESIST = 36,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_COLDMINDAM = 54,
    STAT_COLDMAXDAM = 55,
    STAT_COLDLENGTH = 56,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
    STAT_MANADRAINMINDAM = 62,
    STAT_MANADRAINMAXDAM = 63,
    STATE_FREEZE = 1,
    SKILL_SHADOWWARRIOR = 268,
    MISSILE_NOVA = 90,
    EVENTTYPE_MONUMOD = 7,
};






struct D2MonStatsTxt
{
    char pad0x000[0x170];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char pad0x188[0x20];
};

struct D2MonStats2Txt
{
    char pad0x000[0x104];
    unsigned char nModeFlags[2];
};



typedef void (__fastcall* MonEventFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern MonEventFunc gpMonsterEventFunctions[15];                                                            // 0x006E2490

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
int __fastcall sub_005A00F0_GetMonUModConstant(int nIndex);                                                 // 0x005A00F0
extern "C" D2MonLvlTxt* __fastcall sub_005A0000_GetMonLvlTxtRecord(int nLevel); // 0x005A0000
void __fastcall sub_005A0E80_ApplyMonsterPenalty(D2UnitStrc* pUnit, int nUMod, int bUnique);                   // 0x005A0E80
int __fastcall MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A1370
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
void __fastcall sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                             // 0x00620210
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                       // 0x00451FE0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

__forceinline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

__forceinline D2MonsterDataStrc* MONSTER_GetMonsterData_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Static(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int UNITS_GetXPosition_Static(D2UnitStrc* pUnit)
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

static int UNITS_GetYPosition_Static(D2UnitStrc* pUnit)
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

// 0x005A1080
void __fastcall MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame || !bUnique)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterData_Inline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nTypeFlag |= 0x40;
    }

    STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, 80, 0);
    sub_005A0E80_ApplyMonsterPenalty(pUnit, nUMod, bUnique);

    bUnique = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    D2MonLvlTxt* pMonLvlTxtRecord = sub_005A0000_GetMonLvlTxtRecord(D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1));
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][bUnique];
    const int nMaxDamage = sub_005A00F0_GetMonUModConstant(bUnique + 25) * nDamage / 100;
    STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, sub_005A00F0_GetMonUModConstant(bUnique + 22) * nDamage / 100, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, nMaxDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDLENGTH, 150, 0);
}

// 0x005A1990
void __fastcall MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_FIREMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_FIREMAXDAM, nMaxDamage, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1B00
void __fastcall MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_LIGHTMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_LIGHTMAXDAM, nMaxDamage, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1C70
void __fastcall MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    nLevel = D2_MIN(D2_MAX(nLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_COLDMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDMAXDAM, nMaxDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_COLDLENGTH, 5 * nLevel + 100, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1E00
void __fastcall MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    nLevel = D2_MIN(D2_MAX(nLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_POISONMINDAM, nMinDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_POISONMAXDAM, nMaxDamage, 0);
    STATLIST_AddUnitStat(pUnit, STAT_POISONLENGTH, 2 * (5 * nLevel + 150), 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A1F90
void __fastcall MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    const int nStatLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nLevel = D2_MIN(D2_MAX(nStatLevel, 1), sgptDataTables->nMonLvlTxtRecordCount - 1);
    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord_Inline(nLevel);
    if (!pMonLvlTxtRecord)
    {
        return;
    }

    const int nDamage = pMonLvlTxtRecord->nValues[MONLVL_DM + nGameType][nDifficulty];
    int nMinDamage;
    int nMaxDamage;
    if (bUnique)
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 28) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 31) * nDamage / 100;
    }
    else
    {
        nMinDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 16) * nDamage / 100;
        nMaxDamage = sub_005A00F0_GetMonUModConstant(nDifficulty + 19) * nDamage / 100;
    }

    STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMINDAM, nMinDamage << 8, 0);
    STATLIST_AddUnitStat(pUnit, STAT_MANADRAINMAXDAM, nMaxDamage << 8, 0);
    MONSTERUNIQUE_UMod8_Resistant(pUnit, nUMod, bUnique);
}

// 0x005A2910
void __fastcall MONSTERUNIQUE_CastNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!bUnique)
    {
        return;
    }

    int nSkillLevel = 1;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, SKILL_SHADOWWARRIOR);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 1) / 2 + 1;
        }
    }

    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), 15);
    if (UNITS_GetCurrentLifePercentage(pUnit) > 10)
    {
        nSkillLevel = 1;
    }

    sub_6FD14170(pGame, pUnit, pUnit, MISSILE_NOVA, 0, nSkillLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_NOVA, 0));
}

// 0x005A3E70
void __fastcall MONSTERUNIQUE_SuicideModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int nUMod, int bUnique)
{
    if (pBoss)
    {
        const int nMode = pBoss->dwAnimMode;
        if (nMode == MONMODE_GETHIT)
        {
            D2ModeChangeStrc modeChange;
            MONSTERMODE_GetModeChangeInfo(pBoss, MONMODE_DEATH, &modeChange);
            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
            return;
        }

        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD)
        {
            return;
        }
    }

    EVENT_SetEvent(pGame, pBoss, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 4, 0, 0);
}

// 0x005A6EB0
void __stdcall sub_6FC64090(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMonster = SUNIT_GetOwner(pGame, pUnit);
    if (pMonster)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Static(pMonster->dwClassId);
        if (pMonStatsTxtRecord)
        {
            D2CoordStrc pCoord;
            pCoord.nX = UNITS_GetXPosition_Static(pMonster);
            pCoord.nY = UNITS_GetYPosition_Static(pMonster);
            const int bFree = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pMonster), &pCoord, UNITS_GetUnitSizeX(pMonster), 0x3C01, 0) != 0;
            if (STATLIST_GetUnitAlignment(pUnit) == 0 && bFree && AITACTICS_UseSkill(pGame, pMonster, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], 0, pCoord.nX, pCoord.nY))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
            }
            else
            {
                SUNITDMG_KillMonster(pGame, pMonster, 0, 1);
            }
        }
    }
}

// 0x005A8330
void __fastcall sub_6FC63940(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);

    D2ModeChangeStrc modeChange = {};
    modeChange.nMode = MONMODE_SKILL1;
    modeChange.pUnit = pUnit;
    int nFlag = 100;

    if (pUnit)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord ? pMonStats2TxtRecord->nModeFlags[MONMODE_SKILL1 >> 3] & gdwBitMasks[MONMODE_SKILL1 & 7] : 0)
        {
            nFlag = 101;
        }
    }

    modeChange.nEventFlag = nFlag;
    modeChange.pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);

    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

    if (!STATES_CheckState(pUnit, STATE_FREEZE) || SUNIT_IsDead(pUnit))
    {
        if (gpMonsterEventFunctions[2])
        {
            gpMonsterEventFunctions[2](pGame, pUnit, 0, 0);
        }
    }
}

// 0x005A83E0
void __fastcall sub_6FC63A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);

    D2ModeChangeStrc modeChange = {};
    modeChange.nMode = MONMODE_SKILL1;
    modeChange.pUnit = pUnit;
    int nFlag = 100;

    if (pUnit)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord ? pMonStats2TxtRecord->nModeFlags[MONMODE_SKILL1 >> 3] & gdwBitMasks[MONMODE_SKILL1 & 7] : 0)
        {
            nFlag = 101;
        }
    }

    modeChange.nEventFlag = nFlag;
    modeChange.pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);

    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

    if (!STATES_CheckState(pUnit, STATE_FREEZE) || SUNIT_IsDead(pUnit))
    {
        if (gpMonsterEventFunctions[2])
        {
            gpMonsterEventFunctions[2](pGame, pUnit, 0, 0);
        }
    }
}

#include "gen/data/Source/D2Game/MONSTER/MonsterMode_005A1080.inc"
