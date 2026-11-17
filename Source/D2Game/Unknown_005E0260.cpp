#include "D2Game.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define MONSTER_SUCKERNEST1 334
#define MONMODE_ATTACK2 5
struct Obj00648AD0;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2AiCmdStrc;
struct D2MapAIPathPositionStrc;
struct D2HighPriestAiCallbackArgStrc;
struct D2SiegeBeastTowerAiCallbackArgStrc;
struct D2MinionSpawnerAiCallbackArgStrc;
struct D2PetMoveStrc;
struct D2StaticPathStrc;
struct D2SeedStrc;
struct D2PlayerDataStrc;
struct D2MonStats2Txt;
struct D2PetInfoStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
    char unk0x20[0x1C];
    int nMinionSpawnClassId;
};

struct D2MonStatsTxt
{
    char unk0x000[0x56];
    short wAiParam[8][3];
    char unk0x086[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
    char unk0x188[0x20];
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
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    unsigned char unk_30[0x94];
    unsigned int dwFlags;
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
    D2MonStats2Txt* pMonstats2Txt;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall sub_005FD350_SpawnNearby(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int a5); // 0x005FD350
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

enum D2C_F41AiThinkConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_ALIGNMENT_EVIL = 0,
    MONMODE_ATTACK1 = 4,
    MONMODE_SKILL1 = 8,
    MONMODE_SKILL2 = 9,
    MONMODE_NEUTRAL = 1,
    STATE_INFERNO = 12,
    EVENTTYPE_AITHINK = 2,
    UNITFLAG_NOTC = 0x20000,
    MONSTER_EVILHUT = 528,
    SKILL_NEST = 167,
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd;
    D2AiCmdStrc* pPrevCmd;
    int nCmdParam[5];
};

struct D2HighPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nLifePercentage;
    int nMaxDistance;
};

struct D2SiegeBeastTowerAiCallbackArgStrc
{
    int nMaxDistance;
    int unk0x04;
    int unk0x08[8];
};

struct D2MinionSpawnerAiCallbackArgStrc
{
    int nMinions;
    int unk0x04[10];
};

struct D2PetMoveStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nCounter;
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E1720
void __fastcall sub_005E17E0_SiegeBeastSetTower(D2UnitStrc* pUnit, D2UnitStrc* pTower); // 0x005E17E0
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E2B70
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall sub_005E4830(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4830
void __fastcall sub_005E4AC0_NecroPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4AC0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
bool __fastcall sub_005E6020_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId); // 0x005E6020
bool __fastcall sub_6FCE61E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition); // 0x005E6DE0
D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode); // 0x0046C140

struct D2CoordStrc { int nX; int nY; };

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

extern "C" const int gnDesertTurretIndices_006E33E0[64]; // 0x006E33E0
extern "C" const D2CoordStrc gDesertTurretOffsets_006E33A0[8]; // 0x006E33A0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
extern "C" void __stdcall sub_00648AD0(Obj00648AD0* pObj, unsigned short wA, unsigned short wB); // 0x00648AD0
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY);
int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40
D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit); // 0x0058EE80
void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10

struct D2PlayerDataStrc { char unk_00[0x148]; int nX; int nY; };

int __fastcall PLAYERPETS_GetTotalPetCount(D2UnitStrc*); // 0x00574F40
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc*, int, int); // 0x005DC5C0
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3EA0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
int __stdcall sub_0061B130_GetCollision(D2ActiveRoomStrc*, int, int); // 0x0061B130
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10
unsigned int __stdcall sub_00648A20_GetLastPointX(D2DynamicPathStrc*); // 0x00648A20
unsigned int __stdcall sub_00648A30_GetLastPointY(D2DynamicPathStrc*); // 0x00648A30

struct D2MonStats2Txt { char unk_00[0xE]; unsigned char nSteps; };

struct D2PetInfoStrc { int unk_00[2]; int nHirelingId; };

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc*, int); // 0x00574BD0
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005DF530
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
void __fastcall AITHINK_SelectHirelingAction(D2GameStrc*, D2UnitStrc*, int, int, D2UnitStrc*, D2SeedStrc*); // 0x005E4D30
void __stdcall PATH_SetStepNum(D2DynamicPathStrc*, unsigned char); // 0x00649070
int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DED00

static __forceinline int MONSTERS_ValidateMonsterId(int nMonsterId)
{
    return nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : nMonsterId;
}

// 0x005E0260
void __fastcall sub_005E0260_AiThinkSuckerNest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->nTargetDistance <= AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        if (pAiControl->dwAiParam[1] > AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            if (pUnit)
            {
                pUnit->dwFlags |= UNITFLAG_NOTC;
            }

            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0]
            && sub_005FD350_SpawnNearby(MONSTERS_ValidateMonsterId(MONSTER_SUCKERNEST1), UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, 2);
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005E0430
D2UnitStrc* __fastcall AITHINK_TargetCallback_HighPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2HighPriestAiCallbackArgStrc* pArg = (D2HighPriestAiCallbackArgStrc*)pCallbackArg;
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 75 || nLifePercentage >= pArg->nLifePercentage)
    {
        return 0;
    }

    pArg->nLifePercentage = nLifePercentage;
    pArg->pTarget = pTarget;
    return 0;
}

// 0x005E0F60
void __fastcall AITHINK_Fn093_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[1][pGame->nDifficulty];
        }
    }
    else
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[4][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[5][pGame->nDifficulty];
        }
    }
}

// 0x005E1860
void __fastcall AITHINK_Fn113_SiegeTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        if (pTarget)
        {
            D2SiegeBeastTowerAiCallbackArgStrc arg;
            arg.nMaxDistance = 400;
            arg.unk0x04 = 0;
            D2UnitStrc* pBeast = sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_SiegeBeast, 1);
            if (pBeast)
            {
                sub_005E17E0_SiegeBeastSetTower(pBeast, pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
}

// build: context AITHINK_Fn121_MinionSpawner
void __fastcall AITHINK_Fn121_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        return;
    }

    if (pAiTickParam->nTargetDistance > pMonStatsTxt->wAiParam[3][pGame->nDifficulty])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    D2MinionSpawnerAiCallbackArgStrc arg;
    arg.nMinions = 0;
    sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_MinionSpawner, 1);
    if (pMonStatsTxt->nSkill[0] >= 0 && arg.nMinions < pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        ++pAiControl->dwAiParam[1];
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005E3900
void __fastcall sub_6FCE34B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2PetMoveStrc* pArg = (D2PetMoveStrc*)pCallbackArg;
    if (pArg->pUnit == pTarget)
    {
        return;
    }

    if (AIUTIL_GetDistanceToCoordinates_FullUnitSize(pArg->pUnit, pTarget) > 1)
    {
        return;
    }

    pArg->nCounter += 1;
    pArg->pTarget = pTarget;
}

// 0x005E4CF0
void __fastcall AITHINK_Fn067_NecroPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    if (pAiTickParam->pAiControl->dwAiParam[0] != 0)
    {
        sub_005E4AC0_NecroPetFollowOwner(pGame, pUnit, pAiTickParam);
    }
    else
    {
        sub_005E4830(pGame, pUnit, pAiTickParam);
    }
}

// 0x005E5280
void __fastcall D2GAME_AI_SpecialState04_6FCDC170(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E61B0
void __fastcall AITHINK_Fn129_GenericSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->nMinionSpawnClassId == -1 && !sub_005E6020_SelectGenericSpawnClass(pGame, pUnit, &pAiControl->nMinionSpawnClassId))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (nTargetDistance > 20)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    int nDiff = pGame->dwGameFrame - pAiControl->dwAiParam[0];
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        const int nMonsterId = MONSTER_EVILHUT >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : MONSTER_EVILHUT;
        if (sub_005FD350_SpawnNearby(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSequenceSkill(pGame, pUnit, SKILL_NEST, pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E6EF0
bool __fastcall sub_005E6EF0_MapAiActionWalkToPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    return sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
}

// 0x005E6F00
bool __fastcall sub_6FCE6340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, MONMODE_SKILL1) ? MONMODE_SKILL1 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

// 0x005E6FC0
bool __fastcall sub_6FCE64D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = sub_6FCE61E0(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_CheckMonStats2ModeFlag(pUnit->dwClassId, MONMODE_SKILL2) ? MONMODE_SKILL2 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

static short AITHINK_GetParam_Desert(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

static __forceinline int GetXInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5:
        return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetYInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5:
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E0980
void __fastcall AITHINK_Fn094_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
        pAiControl->dwAiParam[2] = 0;
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (nTargetDistance > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 3))
    {
        if (pAiControl->dwAiParam[1] > 0)
        {
            --pAiControl->dwAiParam[1];
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    const int nTargetX = GetXInl_Desert(pTarget);
    const int nTargetY = GetYInl_Desert(pTarget);
    const int nUnitX = GetXInl_Desert(pUnit);
    const int nUnitY = GetYInl_Desert(pUnit);
    const int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY);
    const int nIndex1 = pAiControl->dwAiParam[2] % 8;
    const int nIndex2 = sub_0063E7A0_GetByteTableEntry(nDirection) % 8;
    pAiControl->dwAiParam[2] = gnDesertTurretIndices_006E33E0[nIndex1 + 8 * nIndex2];

    const int nSpread = AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 4);
    const int nX = nUnitX + nSpread * gDesertTurretOffsets_006E33A0[pAiControl->dwAiParam[2]].nX;
    const int nY = nUnitY + nSpread * gDesertTurretOffsets_006E33A0[pAiControl->dwAiParam[2]].nY;

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);

    if (pMonStatsTxt->nSkill[0] >= 0 && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, nX, nY)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        sub_00648AD0((Obj00648AD0*)pUnit->pDynamicPath, nX, nY);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 1))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 0);
        }
        return;
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        --pAiControl->dwAiParam[1];
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

#include "gen/data/Source/D2Game/Unknown_005E0260.inc"

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x005E1B60
void __fastcall AITHINK_Fn116_Minion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStats = pAiTickParam->pMonstatsTxt;
    int bForced = 0;

    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd)
    {
        if (pCurrentAiCmd->nCmdParam[0] == 1 && pCurrentAiCmd->nCmdParam[3] > pGame->dwGameFrame)
        {
            D2UnitStrc* pTargetUnit = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[1], pCurrentAiCmd->nCmdParam[2]);
            if (pTargetUnit && !SUNIT_IsDead(pTargetUnit))
            {
                bForced = 1;
                if (pTarget != pTargetUnit)
                {
                    pTarget = pTargetUnit;
                    sub_006416D0_UnitEdgeDistance(pUnit, pTargetUnit);
                    bCombat = UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0);
                }
            }
            else
            {
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            }
        }
        else
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }

    if (bCombat)
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[1][pGame->nDifficulty])
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][pGame->nDifficulty]);
        }
    }
    else
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[2][pGame->nDifficulty])
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[3][pGame->nDifficulty]);
        }
    }
}

static __forceinline int GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2: case 4: case 5: return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E45D0
int __fastcall sub_005E45D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int bCombat, D2AiTickParamStrc* pAiTickParam, int bSkipIdle, int nRange)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nMode = pOwner->dwAnimMode;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOwner);
    int nOwnerCollision;
    int nUnitCollision;
    int nFirstX;
    int nFirstY;
    unsigned int nLastX;
    unsigned int nLastY;
    int nMove;
    nRange += PLAYERPETS_GetTotalPetCount(pOwner) >> 1;
    if (nRange > 36) nRange = 36;
    if (nDistance <= 1 && nMode == 1 && !bCombat)
        return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 5, 0, 0, nRange);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (nDistance > 80)
            return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, nRange);
        goto ReturnZero;
    }
    nOwnerCollision = sub_0061B130_GetCollision(UNITS_GetRoom(pOwner), GetUnitX(pOwner), GetUnitY(pOwner));
    nUnitCollision = sub_0061B130_GetCollision(UNITS_GetRoom(pUnit), GetUnitX(pUnit), GetUnitY(pUnit));
    nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);
    nLastX = sub_00648A20_GetLastPointX(pPath);
    nLastY = sub_00648A30_GetLastPointY(pPath);
    nMove = 2;
    if (nMode == 2 || nMode == 6 || nMode == 3) nMove = 0;
    if (nFirstX != nLastX && nFirstY != nLastY) nMove = 0;
    if (nOwnerCollision != nUnitCollision) nMove = 1;
    if (nDistance > nRange) nMove = 1;
    if (nDistance > 50) nMove = 3;
    if (AIUTIL_GetDistanceToCoordinates(pUnit, pPlayerData->nX, pPlayerData->nY) < 28)
    {
        if ((nMove == 1 && nDistance < 30) || nMove == 2) nMove = 4;
    }
    if (bSkipIdle && nMove == 2)
    {
ReturnZero:
        return 0;
    }
    return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, nMove, 0, 0, nRange);
}

static __forceinline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}

// 0x005E5050
void __fastcall sub_005E5050_RunHirelingAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, D2UnitStrc* pOwner, D2UnitStrc* pTarget, D2SeedStrc* pSeed, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nChance;
    if (nMonsterId == 338 || nMonsterId > 559 && nMonsterId <= 561)
        nChance = 98;
    else
    {
        const int nBaseChance = pAiControl->dwAiParam[0] + 40;
        nChance = nBaseChance + 2 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
        if (nChance >= 95) nChance = 95;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pPetInfo)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    const int nHirelingId = pPetInfo->nHirelingId;
    int bAction = 0;
    if ((int)(RollSeed(pSeed) % 100) < nChance)
    {
        bAction = 1;
        pAiControl->dwAiParam[0] = 0;
    }
    else
        pAiControl->dwAiParam[0] += 10;
    if (!pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (nDistance < 4 && (int)(RollSeed(pSeed) % 100) < 50)
        {
            if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 4)) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            if (D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 4, 1)) return;
        }
        else if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    if (nDistance < 3 && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);
    AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 1);
}

// 0x005E5710
void __fastcall sub_6FCE4FD0(D2UnitStrc* pUnit, void* a2, void* a3)
{
    if (!pUnit || MONSTERS_IsDead(pUnit))
    {
        *(int*)a2 = 1;
    }
}
