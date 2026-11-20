#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

struct D2SummonArgStrc;
struct D2SkillsTxt;
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStatsInitStrc;
struct D2ModeChangeStrc;

extern "C" void* __cdecl memset(void*, int, unsigned int);





struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};

struct D2SkillsTxt
{
    char unk0x000[0xBE];
    signed char nPetType;
    char unk0x0BF;
    unsigned int dwPetMax;
    char unk0x0C4[0x74];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
void __fastcall D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet); // 0x005C40D0
void __fastcall sub_005C4430_SetNecroPetComponents(D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel); // 0x005C4430
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0


struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int unk0x08[12];
};

struct D2ModeChangeStrc
{
    int unk0x00[8];
};
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __fastcall sub_6FD154D0(D2UnitStrc* pUnit); // 0x0056E580
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit); // 0x00573120
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005C4B00
int __fastcall SKILLS_SrvDo031_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SummonArgStrc summonArg;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        sub_005C2FF0_DamagePaladinCaster(pGame, pUnit, nSkillId, nSkillLevel);

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            int nSpawnMode;
            const int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
            if (nMonsterId >= 0)
            {
                const int nPetType = pSkillsTxtRecord->nPetType;
                if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
                {
                    const int nX = CLIENTS_GetUnitX(pTarget);
                    const int nY = CLIENTS_GetUnitY(pTarget);
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
                    SUNIT_RemoveUnit(pGame, pTarget);
                    memset(&summonArg, 0, sizeof(summonArg));
                    summonArg.nHcIdx = nMonsterId;
                    summonArg.nAiSpecialState = 0;
                    summonArg.nMonMode = nSpawnMode;
                    summonArg.dwFlags = 1;
                    summonArg.pOwner = pUnit;
                    summonArg.pPosition.nX = nX;
                    summonArg.pPosition.nY = nY;
                    summonArg.nPetType = nPetType;
                    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

                    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
                    if (pPet)
                    {
                        D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
                        sub_005C4430_SetNecroPetComponents(pUnit, pPet, nSkillId, nSkillLevel);
                        D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
                        D2GAME_SetSummonResistance_6FD0C2E0(pUnit, pPet);
                        D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static int sub_005C3300_CanReviveTarget(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }
    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }
    if (!SUNIT_IsDead(pTarget))
    {
        return 0;
    }
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }
    return sub_6FD15190(pTarget, 7) != 0;
}

int __fastcall SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    return sub_005C3300_CanReviveTarget(pTarget);
}

// 0x005C5430
static int __stdcall sub_005C5430_MoveRevivedTarget(D2GameStrc* pGame, D2UnitStrc* pTarget)
{
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pTarget), UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget), PATH_GetUnitCollisionPattern(pTarget), 0x8000);
    D2CoordStrc tCoords;
    tCoords.nX = UNITS_GetUnitXPosition(pTarget);
    tCoords.nY = UNITS_GetUnitYPosition(pTarget);
    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pTarget), &tCoords, UNITS_GetUnitSizeX(pTarget), 0x3C01, 1);
    if (!pRoom)
    {
        return 0;
    }
    pTarget->dwFlags |= 0x402000E;
    MONSTER_UpdateAiCallbackEvent(pGame, pTarget);
    D2ModeChangeStrc tModeChange = {};
    MONSTERMODE_GetModeChangeInfo(pTarget, 1, &tModeChange);
    D2GAME_ModeChange_6FC65220(pGame, &tModeChange, 1);
    sub_6FD154D0(pTarget);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 8, 0);
    if (UNITS_GetRightSkill(pTarget))
    {
        SKILLS_SetRightActiveSkill(pTarget, 0, -1);
    }
    return sub_6FCBDFE0(pGame, pTarget, pRoom, tCoords.nX, tCoords.nY, 0, 0);
}

// 0x005C55C0
static void __stdcall sub_005C55C0_InitializeRevivedMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (nSkillId)
    {
        AIGENERAL_SetOwnerData(pGame, pMonster, !pUnit ? -1 : pUnit->dwUnitId, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, 0, 0);
        AIUTIL_SetOwnerGUIDAndType(pMonster, (pUnit));
        D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
        EVENT_SetEvent(pGame, pMonster, 2, pGame->dwGameFrame + 15, 0, 0);
        sub_6FCBDD30(pMonster, 2, 0);
        sub_00573120_ClearMonsterPair(pMonster);

        if (pMonster)
        {
            pMonster->dwFlags |= 0x80000000;
        }

        STATES_ToggleState(pMonster, 0x60, 1);

        const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (nDuration > 0)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pMonster, 0x15, 0);
            EVENT_SetEvent(pGame, pMonster, 7, nDuration + pGame->dwGameFrame, 0, 0);
        }
    }
}

int __fastcall SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }
    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (!sub_005C3300_CanReviveTarget(pTarget))
    {
        return 0;
    }
    sub_005C2FF0_DamagePaladinCaster(pGame, pUnit, nSkillId, nSkillLevel);
    sub_005C5430_MoveRevivedTarget(pGame, pTarget);
    const int bExpansion = pGame->nGameType || pGame->dwGameType;
    D2MonStatsInitStrc tMonStatsInit = {};
    DATATBLS_CalculateMonsterStatsByLevel(pTarget->dwClassId, bExpansion, pGame->nDifficulty, STATLIST_UnitGetStatValue(pTarget, 12, 0), 1, &tMonStatsInit);
    const int nNewHp = (ITEMS_RollLimitedRandomNumber(&pTarget->pSeed, tMonStatsInit.nMaxHP - tMonStatsInit.nMinHP + 1) + tMonStatsInit.nMinHP) << 8;
    STATLIST_SetUnitStat(pTarget, 7, nNewHp, 0);
    STATLIST_SetUnitStat(pTarget, 6, nNewHp, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    const int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 12, 0);
    if (nTargetLevel && nUnitLevel < nTargetLevel)
    {
        int nHitpoints = DATATBLS_ApplyRatio(nNewHp, nUnitLevel, nTargetLevel);
        if (nHitpoints < 1)
        {
            nHitpoints = 1;
        }
        STATLIST_SetUnitStat(pTarget, 7, nHitpoints, 0);
        STATLIST_SetUnitStat(pTarget, 6, nHitpoints, 0);
        STATLIST_SetUnitStat(pTarget, 12, nUnitLevel, 0);
    }
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pTarget, nSkillId, nSkillLevel, 0);
    sub_005C55C0_InitializeRevivedMonster(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    sub_6FC7D7A0(pGame, pUnit, pTarget, nPetType, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel));
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pTarget, 0, pUnit->dwNodeIndex);
    D2Common_10214(pTarget);
    return 1;
}
