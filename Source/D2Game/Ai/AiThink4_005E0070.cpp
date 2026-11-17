#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
struct D2MonStatsTxt;
struct D2SiegeBeastTowerAiCallbackArgStrc;
struct D2NihlathakOverseerAiCallbackArgStrc;
struct D2MinionSpawnerAiCallbackArgStrc;
struct D2ShadowMasterAiCallbackArgStrc;
struct D2FallenShamanAiCallbackArgStrc;
struct D2ZakarumPriestAiCallbackArgStrc;
struct D2FetishShamanAiCallbackArgStrc;
struct D2OblivionKnightAiCallbackArgStrc;
struct D2AiCmdStrc;
struct D2SkillsTxt;
struct D2ModeChangeStrc;
struct D2SeedStrc;
struct D2StaticPathStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

enum
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
};

enum
{
    UNIT_ALIGNMENT_EVIL = 0,
    UNIT_ALIGNMENT_GOOD = 2,
};

enum
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
};

enum
{
    MONMODE_DEAD = 12,
};

enum
{
    MONTYPEFLAG_UNIQUE = 0x08,
    MONTYPEFLAG_CHAMPION = 0x04,
};

enum
{
    ITEMQUAL_NORMAL = 2,
    ITEMQUAL_UNIQUE = 7,
};

enum
{
    STATE_BLOODLUST = 141,
};

enum
{
    MONSTER_FALLEN1 = 19,
    MONSTER_FALLENSHAMAN1 = 58,
    MONSTER_FETISH1 = 141,
    MONSTER_ZEALOT1 = 235,
    MONSTER_CANTOR1 = 238,
    MONSTER_DOOMKNIGHT1 = 310,
    MONSTER_FETISHBLOW1 = 396,
    MONSTER_WAKEOFDESTRUCTION = 410,
    MONSTER_CHARGEBOLTSENTRY = 411,
    MONSTER_LIGHTNINGSENTRY = 412,
    MONSTER_BLADECREEPER = 413,
    MONSTER_INFERNOSENTRY = 415,
    MONSTER_DEATHSENTRY = 416,
    MONSTER_MINION1 = 453,
    MONSTER_SUICIDEMINION1 = 461,
    MONSTER_IMP1 = 492,
    MONSTER_UBERMEPHISTO = 704,
    MONSTER_UBERDIABLO = 705,
    MONSTER_UBERBAAL = 709,
};

struct D2GameStrc
{
    union
    {
        struct
        {
            char unk0x00[0x8C];
        };
        struct
        {
            unsigned char unk_00[0x6D];
            unsigned char nDifficulty;
        };
    };
    int nClients;
    unsigned char unk_90[0x18];
    int dwGameFrame;
    unsigned char unk_AC[0x1D3C];
    int bUberBaalKilled;
    int bUberDiabloKilled;
    int bUberMephistoKilled;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        struct
        {
            char unk0x14[0xA4];
        };
        struct
        {
            unsigned char unk_14[0xC];
            D2SeedStrc pSeed;
            unsigned char unk_28[0x4];
            D2DynamicPathStrc* pDynamicPath;
        };
        struct
        {
            unsigned char unk_14_2[0x18];
            D2StaticPathStrc* pStaticPath;
        };
    };
    unsigned int dwDropItemCode;
    char unk0xBC[0x08];
    unsigned int dwFlags;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
    short wAiParam[8][3];
    unsigned char unk_86[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
    unsigned char unk_A84[0xE8];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB70];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2SiegeBeastTowerAiCallbackArgStrc
{
    int nMaxDistance;
};

struct D2NihlathakOverseerAiCallbackArgStrc
{
    int nMaxDistance;
    int nDistantMaxDistance;
    int nMaxLifePercentage;
    D2UnitStrc* pTarget;
    D2UnitStrc* pDistantTarget;
    int nCounter;
};

struct D2MinionSpawnerAiCallbackArgStrc
{
    int nMinions;
};

struct D2ShadowMasterAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    D2UnitStrc* unk0x04;
    int unk0x08;
    int unk0x0C;
    D2UnitStrc* unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    D2UnitStrc* unk0x24;
};

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
};

struct D2ZakarumPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nMaxLifePercentage;
    int nMaxDistance;
};

struct D2FetishShamanAiCallbackArgStrc
{
    D2UnitStrc* pClosestDeadTarget;
    int nSquaredDistanceToClosestDeadTarget;
    int nMaxSearchRangeSquared;
    D2UnitStrc* pClosestAliveTarget;
    int nSquaredDistanceToClosestAliveTarget;
    int nAliveTargets;
    int nHealCapability;
};

struct D2OblivionKnightAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    D2UnitStrc* unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80
int __fastcall sub_00463860(D2UnitStrc* pUnit); // 0x00463860
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463900
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall AITHINK_IsTargetKillableByShadowMaster(D2UnitStrc* a1, D2UnitStrc* a2); // 0x005EB650
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId); // 0x005EAB20
int __fastcall sub_005EB420_ShadowMasterSkillLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nParam, int nSkillId); // 0x005EB420

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2SkillsTxt
{
    char unk0x000[0x048];
    short wSrvMissileA;
    char unk0x04A[0x138 - 0x04A];
    unsigned int dwCalc[4];
    char unk0x148[0x23C - 0x148];
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit); // 0x0058EE80
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190
int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEE50
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMaxDistance); // 0x005DF530
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070

enum D2C_Y11AiConstants
{
    MONMODE_WALK = 2,
    STAT_TOHIT = 0x13,
    STAT_ITEM_TOHIT_PERCENT = 0x77,
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall sub_6FCF2E70(D2UnitStrc* pUnit); // 0x005DD2B0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x005E0070
void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nMonsterId;

    if (!pUnit)
    {
        nMonsterId = -1;
    }
    else
    {
        nMonsterId = pUnit->dwClassId;
    }

    switch (nMonsterId)
    {
    case MONSTER_UBERMEPHISTO:
        pGame->bUberMephistoKilled = 1;
        break;
    case MONSTER_UBERDIABLO:
        pGame->bUberDiabloKilled = 1;
        break;
    case MONSTER_UBERBAAL:
        pGame->bUberBaalKilled = 1;
        break;
    default:
        D2_ASSERT(0, 230);
        return;
    }

    if (pGame->bUberMephistoKilled && pGame->bUberDiabloKilled && pGame->bUberBaalKilled)
    {
        int nItemLevel;
        pUnit->dwDropItemCode = ' 2mc';
        D2UnitStrc* pItem = D2GAME_DropItemAtUnit_6FC4FEC0(pGame, pUnit, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 0);
        D2GAME_RechargeItem_6FC4BD50(pGame, 0, pItem);
        pUnit->dwDropItemCode = ' dts';
        const int nClients = pGame->nClients;
        for (int i = 0; i < nClients; i++)
        {
            D2GAME_DropItemAtUnit_6FC4FEC0(pGame, pUnit, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
        }
    }
}

// 0x005E1720
D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2SiegeBeastTowerAiCallbackArgStrc* pArg = (D2SiegeBeastTowerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nImp = MONSTERS_ValidateMonsterIdInline(MONSTER_IMP1);
    if (sub_00463860(pTarget) != nImp)
    {
        return 0;
    }

    if (!STATLIST_AreUnitsAligned(pUnit, pTarget))
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (SUNIT_GetOwner(pGame, pUnit))
    {
        return 0;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pTarget);
    if (pAiControl->dwAiParam[0] != -1)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    return pTarget;
}

// 0x005E26D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2NihlathakOverseerAiCallbackArgStrc* pArg = (D2NihlathakOverseerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget)) != MONSTER_MINION1 || MONSTERS_IsDead(pTarget) || sub_00554200(pGame, pUnit, pTarget) || STATES_CheckState(pTarget, STATE_BLOODLUST))
    {
        return 0;
    }

    ++pArg->nCounter;

    if (!pArg->pTarget && AITHINK_GetSquaredDistance(pUnit, pTarget) <= pArg->nMaxDistance && UNITS_GetCurrentLifePercentage(pTarget) < pArg->nMaxLifePercentage)
    {
        pArg->pTarget = pTarget;
    }

    if (!pArg->pDistantTarget && AITHINK_GetSquaredDistance(pUnit, pTarget) <= pArg->nDistantMaxDistance && !MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE))
    {
        pArg->pDistantTarget = pTarget;
    }

    return 0;
}

// 0x005E2B70
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2MinionSpawnerAiCallbackArgStrc* pArg = (D2MinionSpawnerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    switch (MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget)))
    {
    case MONSTER_MINION1:
    case MONSTER_SUICIDEMINION1:
        if (STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_EVIL)
        {
            ++pArg->nMinions;
        }
        break;
    }

    return 0;
}

// 0x005EB490
void __fastcall sub_005EB490(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = 0;
    pAiControl->dwAiParam[1] = 0;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    const int nParam = pAiControl->dwAiParam[2];

    if (!SKILLS_GetSkillById(pUnit, 0, -1))
    {
        SKILLS_AssignSkill(pUnit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 3054);
    }

    SKILLS_SetLeftActiveSkill(pUnit, 0, -1);
    SKILLS_SetRightActiveSkill(pUnit, 0, -1);

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(sub_00451F60_UnitClassId(pOwner)); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(sub_00451F60_UnitClassId(pOwner), i);

        if (AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId))
        {
            SKILLS_GetSkillById(pUnit, nSkillId, -1);
            const int nLevel = sub_005EB420_ShadowMasterSkillLevel(pGame, pUnit, pOwner, nParam, nSkillId);
            SKILLS_AssignSkill(pUnit, nSkillId, nLevel, 0, ".\\Ai\\AiThink4.cpp", 3069);
        }
    }
}

// 0x005EB6D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2ShadowMasterAiCallbackArgStrc* pArg = (D2ShadowMasterAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget || SUNIT_IsDead(pTarget) || !pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && STATLIST_AreUnitsAligned(pUnit, pTarget))
    {
        const int nClassId = MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget));
        switch (nClassId)
        {
        case MONSTER_WAKEOFDESTRUCTION:
        case MONSTER_CHARGEBOLTSENTRY:
        case MONSTER_LIGHTNINGSENTRY:
        case MONSTER_BLADECREEPER:
        case MONSTER_INFERNOSENTRY:
        case MONSTER_DEATHSENTRY:
            ++pArg->unk0x20;
            return 0;

        default:
            break;
        }
    }

    if (!UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || !sub_00554200(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (pArg->unk0x00)
    {
        const int nDistance = AITHINK_GetSquaredDistance(pArg->unk0x00, pTarget);

        if (nDistance <= 100)
        {
            ++pArg->unk0x18;
        }

        if (nDistance < pArg->unk0x14)
        {
            pArg->unk0x10 = pTarget;
            pArg->unk0x14 = nDistance;
        }
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance <= 1024)
    {
        ++pArg->unk0x1C;

        if (nDistance <= 100)
        {
            ++pArg->unk0x0C;
        }

        if (nDistance < pArg->unk0x08)
        {
            pArg->unk0x04 = pTarget;
            pArg->unk0x08 = nDistance;
        }

        if (AITHINK_IsTargetKillableByShadowMaster(pUnit, pTarget))
        {
            pArg->unk0x24 = pTarget;
        }
    }

    return 0;
}

// 0x005F1380
D2UnitStrc* __fastcall AITHINK_TargetCallback_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FallenShamanAiCallbackArgStrc* pArg = (D2FallenShamanAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget));
    if ((nClassId != MONSTER_FALLEN1 && nClassId != MONSTER_FALLENSHAMAN1)
        || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL
        || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE)
        || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    const int nMode = pTarget ? pTarget->dwAnimMode : 0;
    if (nMode != MONMODE_DEAD || STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->nMaxDistance || MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE | MONTYPEFLAG_CHAMPION))
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    ++pArg->nCounter;
    return 0;
}

// 0x005F7240
D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2ZakarumPriestAiCallbackArgStrc* pArg = (D2ZakarumPriestAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_GOOD || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    switch (MONSTERS_GetBaseIdFromMonsterId(sub_00463860(pTarget)))
    {
    case MONSTER_ZEALOT1:
    case MONSTER_CANTOR1:
        break;

    default:
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 60)
    {
        return 0;
    }

    if (pArg->nMaxLifePercentage <= 0)
    {
        pArg->nMaxLifePercentage = 0x7FFFFFFF;
    }

    ++pArg->nCounter;

    if (nLifePercentage < pArg->nMaxLifePercentage)
    {
        pArg->pTarget = pTarget;
    }

    return 0;
}

// 0x005F99A0
D2UnitStrc* __fastcall AITHINK_TargetCallback_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FetishShamanAiCallbackArgStrc* pArg = (D2FetishShamanAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE) || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    if (!pArg->nHealCapability && AIGENERAL_GetMinionOwner(pTarget) != pUnit)
    {
        return 0;
    }

    const int nClassId = MONSTERS_GetBaseIdFromMonsterId(sub_00463860(pTarget));
    if ((nClassId == MONSTER_FETISH1 || nClassId == MONSTER_FETISHBLOW1 && pArg->nHealCapability != 1)
        && STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_EVIL
        && (pArg->nHealCapability >= 3 || !MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE | MONTYPEFLAG_CHAMPION)))
    {
        const int nDistanceSquared = AITHINK_GetSquaredDistance(pUnit, pTarget);
        if (nDistanceSquared <= pArg->nMaxSearchRangeSquared)
        {
            if (pTarget->dwAnimMode != MONMODE_DEAD)
            {
                ++pArg->nAliveTargets;

                if (nDistanceSquared < pArg->nSquaredDistanceToClosestAliveTarget)
                {
                    pArg->pClosestAliveTarget = pTarget;
                    pArg->nSquaredDistanceToClosestAliveTarget = nDistanceSquared;
                }
            }
            else
            {
                if (nDistanceSquared < pArg->nSquaredDistanceToClosestDeadTarget)
                {
                    pArg->pClosestDeadTarget = pTarget;
                    pArg->nSquaredDistanceToClosestDeadTarget = nDistanceSquared;
                }
            }
        }
    }

    return 0;
}

// 0x005FAE40
D2UnitStrc* __fastcall AITHINK_TargetCallback_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2OblivionKnightAiCallbackArgStrc* pArg = (D2OblivionKnightAiCallbackArgStrc*)pCallbackArg;

    if (pTarget == pUnit)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE))
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(sub_00463860(pTarget)) != MONSTER_DOOMKNIGHT1)
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->unk0x08 || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (nDistance < pArg->unk0x0C)
    {
        pArg->unk0x00 = pTarget;
        pArg->unk0x0C = nDistance;
    }

    if (nDistance < pArg->unk0x10 && UNITS_GetCurrentLifePercentage(pTarget) < 40)
    {
        pArg->unk0x04 = pTarget;
        pArg->unk0x10 = nDistance;
    }

    return 0;
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005EA2B0
int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] < 0)
    {
        const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
        if (!pSkill)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        D2AiControlStrc* pAiControlSet = pAiTickParam->pAiControl;
        pAiControlSet->dwAiParam[1] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        if (bDecreaseParam)
        {
            pAiControl->dwAiParam[1] -= 1;
        }
        return 0;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
    return 1;
}

// 0x005EA540
void __fastcall AITHINK_Fn102_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (pAiControl->dwAiParam[0] < 0)
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (!pAiControl->dwAiParam[2])
    {
        if (pSkillsTxtRecord->wSrvMissileA >= 0 && pSkillsTxtRecord->wSrvMissileA < sgptDataTables->nMissilesTxtRecordCount)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
            if (!pOwner)
            {
                pOwner = pUnit;
            }

            D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pGame, pOwner, nSkillId, nSkillLevel, pSkillsTxtRecord->wSrvMissileA, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            if (pMissile)
            {
                UNITS_StoreOwner(pMissile, pUnit);
                const int nAttackRate = UNITS_GetAttackRate(pOwner);
                STATLIST_AddUnitStat(pUnit, STAT_TOHIT, nAttackRate, 0);

                int nToHitPercent = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_TOHIT_PERCENT, 0);
                D2UnitStrc* pWeapon = sub_6FC7C7B0(pOwner);
                if (pWeapon)
                {
                    nToHitPercent += SKILLS_GetWeaponMasteryBonus(pOwner, pWeapon, 0, 0);
                }

                STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHitPercent, 0);
            }

            pAiControl->dwAiParam[2] = 1;
        }
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (!pAiCmd)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return;
    }

    AITACTICS_SetVelocity(pUnit, 15, 0, 20);

    if (pAiControl->dwAiParam[1])
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }
    }
    else
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }
    }

    D2UnitStrc* pWalkOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pWalkOwner, 5))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
    }
}

// 0x005ECBC0
void __fastcall sub_005ECBC0_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2)
{
    AITACTICS_SetVelocity(pUnit, a2, 0, a4);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.pTargetUnit = pTarget;
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005EA7A0
void __fastcall AITHINK_Fn103_InvisoPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);

    int nParam = AI_GetParam(pGame, pMonStatsTxt, 0);
    const int nAnimMode = !pOwner ? 0 : pOwner->dwAnimMode;

    const int bOwnerGetHit = nAnimMode == 3;
    if (bOwnerGetHit)
    {
        nParam /= 2;
    }

    if (pAiControl->dwAiParam[0] >= pGame->dwGameFrame && !bOwnerGetHit && !sub_6FCF2E70(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    const int nX = CLIENTS_GetUnitXInline(pOwner) + SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nParam) - nParam;
    const int nY = CLIENTS_GetUnitYInline(pOwner) + SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nParam) - nParam;

    AITACTICS_UseSkill(pGame, pUnit, 9, 0x124, 0, nX, nY);
    pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, 1);
}
