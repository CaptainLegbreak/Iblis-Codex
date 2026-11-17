#include "D2Game.h"

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
struct D2SeedStrc;
struct D2MonStatsTxt;
struct D2StaticPathStrc;

struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };

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
    char unk0x86[0xEA];
    short nSkill[8];
    unsigned char nSkillMode[8];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    unsigned char unk_14[0xC];
    D2SeedStrc pSeed;
    char unk0x28[4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
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
};

int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pKiller, int bSkipLoot); // 0x0057CCB0
void __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0
void __fastcall sub_005F2EB0_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2EB0
D2ActiveRoomStrc* __fastcall sub_00463740_GetRoomAtPosition(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall sub_0063EFA0_GetSpawnInfo(D2UnitStrc* pUnit, int* pMonsterId, int* pX, int* pY, int* pAnimMode, int a6, int a7); // 0x0063EFA0

// 0x005EF820
void __fastcall AITHINK_Fn139_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pAiTickParam->pAiControl->dwAiParam[2])
    {
        const int nDuration = AI_PARAM(pGame, pMonStatsTxt, 2);
        const int nFrames = 25 * (SEED_RollLimitedRandomNumber(pSeed, nDuration) + nDuration);
        pAiTickParam->pAiControl->dwAiParam[2] = pGame->dwGameFrame + nFrames;
    }

    if (pGame->dwGameFrame > pAiTickParam->pAiControl->dwAiParam[2])
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    if (bCombat && SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

static __forceinline int UNITS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int UNITS_GetUnitYInline(D2UnitStrc* pUnit)
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

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x005F56D0
void __fastcall AITHINK_Fn033_HellMeteor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pMonStatsTxt->nSkill[0] >= 0 && (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        const int nX = UNITS_GetUnitXInline(pUnit) + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 2)) - AI_PARAM(pGame, pMonStatsTxt, 2);
        const int nY = UNITS_GetUnitYInline(pUnit) + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 2)) - AI_PARAM(pGame, pMonStatsTxt, 2);
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// 0x005F81D0
void __fastcall AITHINK_SpecialFn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
	D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
	const int nAiSpecialState = pAiControl->nAiSpecialState;
	D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

	if (nAiSpecialState != 10 && nAiSpecialState != 11)
	{
		const short nSkillId = pMonStatsTxt->nSkill[0];
		if (nSkillId >= 0 && pAiControl->dwAiParam[2] >= 2)
		{
			AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pAiTickParam->pTarget, 0, 0);
			pAiControl->dwAiParam[2] = 1;
			sub_005F2EB0_RemoveGroundCollision(pGame, pUnit);
			return;
		}

		AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
		AITACTICS_Idle(pGame, pUnit, 1);
		return;
	}

	AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
	AITACTICS_Idle(pGame, pUnit, 1);
}

static int UNITS_GetAnimMode_FB410(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005FB410
void __fastcall sub_005FB410_AiThinkSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nMode = UNITS_GetAnimMode_FB410(pUnit);

    if (pAiControl->dwAiParam[0] <= 0)
    {
        pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;
        pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, 0);
    }

    if (nMode == 1)
    {
        if (nDistance > 5)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 10, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 10)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 11, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 11 && pAiControl->dwAiParam[1] > 0)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;

            int nMonsterId;
            int nX;
            int nY;
            int nAnimMode;
            sub_0063EFA0_GetSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nAnimMode, 0, 0);

            D2ActiveRoomStrc* pRoom = sub_00463740_GetRoomAtPosition(UNITS_GetRoom(pUnit), nX, nY);
            if (pRoom)
            {
                D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 2, 0x42);
                if (pMonster)
                {
                    --pAiControl->dwAiParam[1];
                    pMonster->dwFlags |= 0x4020000;

                    if (pUnit && pUnit->dwClassId == 0x2C7)
                    {
                        STATES_ToggleState(pMonster, 0xB8, 1);
                        UNITS_SetOverlay(pMonster, 0xCA, 0);
                    }
                }
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
}

// 0x005FB900
void __fastcall sub_005FB900_ThinkLimitedCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (nTargetDistance > pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    const short nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId >= 0 && pAiControl->dwAiParam[1] == 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pTarget, 0, 0);
        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 1;
        return;
    }
    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
}

// 0x005FB9B0
void __fastcall sub_005FB9B0_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (nTargetDistance > pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    const short nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId >= 0 && pAiControl->dwAiParam[1] == 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pTarget, 0, 0);
        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 1;
        return;
    }
    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
}
