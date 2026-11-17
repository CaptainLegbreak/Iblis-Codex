#include "D2Game.h"

#define UNIT_MONSTER 1
#define MONMODE_NEUTRAL 1
#define STAT_VELOCITYPERCENT 67
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MONSTER_BONEWALL 344
#define UNITFLAG_NOTC 0x00020000
#define UNIT_INVALID 6
#define MONSTER_BASEID_63 63
struct D2AiParamStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2ModeChangeStrc;
struct D2MonModeCallbackTableStrc;
struct D2Field14Strc;
struct D2MonStats2Txt;
struct D2MonModeInfoTableStrc;
struct D2MonVelocityParamStrc;
struct D2MonsterModeDataStrc;
struct D2StaticPathStrc;
struct D2SeedStrc;

struct D2MonStatsTxt
{
    char pad0x00[0x02];
    short nBaseId;
    unsigned char unk_04[0x4B];
    unsigned char nAIdel[3];
    unsigned char unk_52[0x10];
    short wMissileCount[3];
    unsigned char unk_68[0x13D];
    unsigned char nSplGetModeChart;
    char unk0x1A6[0x02];
};

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    unsigned char unk_30[0x1E];
    unsigned char nActionFrame;
    unsigned char unk_4F[0x61];
    int dwKillerGUID;
    unsigned char unk_B4[0x10];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x06];
    int dwGameType;
    char unk0x78[0x30];
    int dwGameFrame;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nEventFlag;
    unsigned short unk0x16;
    int unk0x18;
    int unk0x1C;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

struct D2MonModeCallbackTableStrc
{
    void* pfnCallbacks[4];
};

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const D2MonModeCallbackTableStrc gMonModeCallbacks[]; // 0x006E2260
extern const D2MonModeCallbackTableStrc gDiablo_Skill4_Callbacks; // 0x006E2360
extern const D2MonModeCallbackTableStrc gDiablo_Skill3_Callbacks; // 0x006E2370
extern const D2MonModeCallbackTableStrc gTrappedSoul_Attack_Callbacks; // 0x006E2380
extern const D2MonModeCallbackTableStrc gTrappedSoul_Skill_Callbacks; // 0x006E2390
extern const D2MonModeCallbackTableStrc gShadowMasterWarrior_Skill4_Callbacks; // 0x006E23A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg); // 0x005A5C70
void __fastcall sub_6FC7B460(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg); // 0x005A5CB0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

struct D2Field14Strc
{
    char unk0x00[0x14];
    int nField14;
};

struct D2MonStats2Txt
{
    char unk0x000[0x104];
    unsigned char nModeEventFlags[4];
};

struct D2MonModeInfoTableStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

struct D2MonVelocityParamStrc
{
    int unk0x00[4];
    int nVelocityPercent;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2MonModeInfoTableStrc gtMonsterModeEventPolicies[]; // 0x006E23D0
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange); // 0x005A73E0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

struct D2MonsterModeDataStrc { int unk_00; int unk_04; int unk_08; int unk_0C; int unk_10; int unk_14; int unk_18; int unk_1C; int unk_20; };

void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int nZero); // 0x0040B430
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlag, D2ModeChangeStrc* pModeChange); // 0x005A6600
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATES_CheckStateMaskLifeOnUnit(D2UnitStrc* pUnit); // 0x0063A750
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent); // 0x00571A10
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, void* pDamage); // 0x005C0C30

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nX;
    int nY;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

// 0x005A5650
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0x80;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nMaxHp > 0 && nHitpoints < nMaxHp)
    {
        return (nHitpoints << 7) / nMaxHp;
    }

    return 0x80;
}

// build: context PARTYSCREEN_PlayerLeftParty
void __fastcall PARTYSCREEN_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PARTY_IteratePartyMembers(pGame, SUNIT_GetPartyId(pPlayer1), PARTYSCREEN_PartyIterate_PlayerLeftParty, pPlayer1);
    PARTY_LeaveParty(pGame, pPlayer1);
}

// 0x005A5FF0
void __fastcall PARTYSCREEN_RefreshPartyRelationsAfterLeave(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    SUNIT_IterateLivingPlayers(pGame, sub_6FC7B460, pPlayer);
}

// 0x005A64D0
void __fastcall D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam)
{
    FOG_FreeServerMemory(pGame->pMemoryPool, pAiParam, ".\\MONSTER\\MonsterMode.cpp", 327, 0);
}

// 0x005A73E0
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, 1);

    if (EVENT_GetEventFrame(pGame, pUnit, 2) <= pGame->dwGameFrame)
    {
        if (STATES_CheckState(pUnit, 21))
        {
            EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 45, 0, 0);
            return 1;
        }

        if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStatsTxtRecord)
            {
                int nAiDelay;
                if (!pGame->nGameType && !pGame->dwGameType)
                {
                    nAiDelay = pMonStatsTxtRecord->nAIdel[0];
                }
                else
                {
                    nAiDelay = pMonStatsTxtRecord->nAIdel[pGame->nDifficulty];
                }

                if (nAiDelay <= 0)
                {
                    nAiDelay = 15;
                }

                EVENT_SetEvent(pGame, pUnit, 2, nAiDelay + pGame->dwGameFrame, 0, 0);
            }
        }
    }

    return 1;
}

// 0x005A78A0
const D2MonModeCallbackTableStrc* __fastcall MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (nMode < 0 || nMode >= 16)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nSplGetModeChart)
    {
        switch (nClassId)
        {
        case 403:
            if (nMode == 4)
            {
                return &gTrappedSoul_Attack_Callbacks;
            }

            if (nMode == 5)
            {
                return &gTrappedSoul_Attack_Callbacks;
            }

            if (nMode == 9)
            {
                return &gTrappedSoul_Skill_Callbacks;
            }

            if (nMode == 8)
            {
                return &gTrappedSoul_Skill_Callbacks;
            }
            break;

        case 417:
        case 418:
            if (nMode == 11)
            {
                return &gShadowMasterWarrior_Skill4_Callbacks;
            }
            break;

        case 243:
        case 333:
        case 705:
            if (nMode == 11)
            {
                return &gDiablo_Skill4_Callbacks;
            }

            if (nMode == 10)
            {
                return &gDiablo_Skill3_Callbacks;
            }
            break;

        case 543:
            if (nMode == 10)
            {
                return &gMonModeCallbacks[7];
            }
            break;

        case 544:
        case 570:
        case 709:
            if (nMode == 10)
            {
                return &gMonModeCallbacks[7];
            }
            break;

        default:
            break;
        }
    }

    return &gMonModeCallbacks[nMode];
}

#include "gen/data/Source/D2Game/MONSTER/MonsterMode.inc"

// 0x005A6250
int* __fastcall sub_005A6250_GetField14(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

// 0x005A64F0
static __forceinline int sub_005A64F0_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = sub_005A64F0_IsActionFrame(pUnit) + 1;
}

// 0x005A6380
static void sub_005A6380_SetVelocityPercent(D2MonVelocityParamStrc* pParam, D2UnitStrc* pUnit)
{
    const int nVelocityPercent = pParam->nVelocityPercent;
    if (!nVelocityPercent)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x4000);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0x4004, 0, UNIT_MONSTER, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return;
        }

        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    sub_006270B0(pStatList, STAT_VELOCITYPERCENT, nVelocityPercent, 0);
    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\MONSTER\\MonsterMode.cpp", 269);
}

// 0x005A68E0
static void sub_005A68E0_SetAiStateForMode(int nMode, D2UnitStrc* pMonster)
{
    const int nAiState = MONSTER_GetAiState(pMonster);
    if (nAiState >= 16)
    {
        nMode = nAiState - 16;
    }
    else if (nAiState == 13 && nMode == 3)
    {
        nMode = nAiState;
    }

    MONSTER_SetAiState(pMonster, nMode);
}

// 0x005A6B10
static int sub_005A6B10_IsModeEventEnabled(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || nMode >= 16)
    {
        return 0;
    }

    const D2MonModeInfoTableStrc* pMonModeInfoTableRecord = &gtMonsterModeEventPolicies[nMode];
    if (pMonModeInfoTableRecord->unk0x00)
    {
        return 1;
    }

    if (!pMonModeInfoTableRecord->unk0x04 && pMonModeInfoTableRecord->unk0x08)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            return pMonStats2TxtRecord->nModeEventFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
        }
    }

    return 0;
}

// 0x005A7B30
static int __stdcall sub_005A7B30_TryStartNeutral(D2GameStrc* pGame, int nMode, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);
    if (nMode && nMode != 12 && SUNIT_IsDead(pUnit))
    {
        return 1;
    }

    D2ModeChangeStrc tModeChange = {};
    tModeChange.pUnit = pUnit;
    tModeChange.nMode = MONMODE_NEUTRAL;
    MONSTERMODE_StartNeutral(pGame, &tModeChange);
    return 0;
}

// 0x005A7E60
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange)
{
    D2_ASSERT(nMode < 16, 1976);
    UNITS_SetUsedSkill(pUnit, 0);
    memset(pModeChange, 0, sizeof(D2ModeChangeStrc));
    pModeChange->nMode = nMode;
    pModeChange->pUnit = pUnit;
    int nEventFlag = 100;
    if (sub_005A6B10_IsModeEventEnabled(pUnit, nMode))
    {
        nEventFlag = 101;
    }

    pModeChange->nEventFlag = nEventFlag;
}

// calling-convention shim (not game code)
void __stdcall sub_A08_EmitModeHelpers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonVelocityParamStrc* pParam, int a, int b)
{
    sub_005A68E0_SetAiStateForMode(a, pUnit);
    if (sub_005A7B30_TryStartNeutral(pGame, b, pUnit))
    {
        sub_005A6380_SetVelocityPercent(pParam, pUnit);
    }
    sub_005A68E0_SetAiStateForMode(b, pParam->unk0x00[0] ? pUnit : 0);
    sub_005A6380_SetVelocityPercent(pParam + 1, pUnit);
    sub_005A7B30_TryStartNeutral(pGame, a, pUnit);
}

// 0x005A6490
D2MonsterModeDataStrc* __fastcall sub_005A6490_AllocateMonsterModeData(D2GameStrc* pGame)
{
    D2MonsterModeDataStrc* pData = (D2MonsterModeDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2MonsterModeDataStrc), ".\\MONSTER\\MonsterMode.cpp", 319, 0);
    memset(pData, 0, sizeof(D2MonsterModeDataStrc));
    return pData;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A6830
void __fastcall sub_005A6830(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    D2_ASSERT(pUnit, 493);

    if (UNIT_HasFlag(pUnit, UNITFLAG_NOTC))
    {
        return;
    }

    D2_ASSERT(pUnit->dwClassId != MONSTER_BONEWALL, 504);

    if (!COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0x801))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pRoom, 511);

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        D2_ASSERT(pMonStatsTxtRecord, 516);

        sub_6FC631B0(pGame, pUnit, 0, pModeChange);
    }
}

// 0x005A6920
void __fastcall sub_005A6920_MonsterRegenEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nParam)
{
    int nRegen = STATLIST_UnitGetStatValue(pUnit, 0x4A, 0);
    if (STATES_CheckStateMaskLifeOnUnit(pUnit))
    {
        nRegen -= STATLIST_GetUnitBaseStat(pUnit, 0x4A, 0);
    }

    if (STATES_CheckState(pUnit, 0x34) && nRegen >= 0)
    {
        return;
    }

    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
    if (!nRegen)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
        return;
    }

    int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nRegen < 0 && nHitpoints < 0x100)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return;
        }
    }

    nHitpoints += nRegen;
    if (nHitpoints > nMaxHp)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 3, 0);
        nHitpoints = nMaxHp;
    }

    if (nHitpoints < 1)
    {
        nHitpoints = 0;
    }

    STATLIST_SetUnitStat(pUnit, 6, nHitpoints, 0);

    const unsigned char nOldPercent = STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
    const unsigned char nNewPercent = MONSTERMODE_GetHpPercent128(pUnit);
    int nDiff = nOldPercent - nNewPercent;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }
    if (nDiff > 4)
    {
        SUNITMSG_QueueLifeUpdate(pUnit, nNewPercent);
        STATLIST_SetUnitStat(pUnit, 0x160, nNewPercent, 0);
    }

    if (nHitpoints || !pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 12)
    {
        return;
    }

    D2StatListStrc* pStatList = 0;
    int nStates[2];
    nStates[0] = 2;
    nStates[1] = 0x3E;
    for (int i = 0; i < 2; ++i)
    {
        if (pStatList)
        {
            break;
        }
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nStates[i]);
    }

    D2UnitStrc* pKiller = 0;
    pUnit->dwKillerGUID = 0;
    if (pStatList)
    {
        pKiller = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    }

    if (STATES_CheckState(pUnit, 0x36))
    {
        STATES_ToggleState(pUnit, 0x5C, 1);
        return;
    }

    SUNITDMG_KillMonster(pGame, pUnit, pKiller, 1);
    SUNITEVENT_Trigger(pGame, 10, pUnit, pKiller, 0);
    if (pKiller)
    {
        SUNITEVENT_Trigger(pGame, 9, pKiller, pUnit, 0);
    }
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static int D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }

        return pUnit->dwClassId;
    }

    return -1;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static __forceinline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline void sub_005A6B70_GetTargetCoords(D2UnitStrc* pTarget, D2DynamicPathStrc* pPath, int* pX, int* pY)
{
    if (!pTarget)
    {
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
}

// 0x005A6B70
void __stdcall sub_005A6B70_FireMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId)
{
    const int nBaseId = D2GAME_GetMonsterBaseId_6FC64B10(pUnit);
    if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_BASEID_63)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        int nX;
        int nY;
        sub_005A6B70_GetTargetCoords(pTarget, pPath, &nX, &nY);

        int nOffsetX = 5;
        int nOffsetY = 5;
        PATH_SetTargetUnit(pPath, 0);

        D2SeedStrc tSeed;
        SEED_InitSeed(&tSeed);
        SEED_InitLowSeed(&tSeed, 0x53454953);
        const int nClassId = pUnit->dwClassId;
        tSeed.nHighSeed = pUnit->dwUnitId;

        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        for (int nCount = pMonStatsTxtRecord->wMissileCount[pGame->nDifficulty]; nCount > 0; --nCount)
        {
            if ((unsigned int)SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetX = -nOffsetX;
            }
            if ((unsigned int)SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetY = -nOffsetY;
            }
            D2COMMON_10170_PathSetTargetPos(pPath, nOffsetX + nX, nOffsetY + nY);
            sub_6FD11420(pGame, nMissileId, pUnit, 0, 1, 0, 0, 0, 0, 0);
        }

        PATH_SetTargetUnit(pPath, pTarget);
    }
}

// 0x005A6DE0
int __fastcall D2GAME_RemoveModeChangeEventCallback_6FC63B20(D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 0, 0);
    return 1;
}
