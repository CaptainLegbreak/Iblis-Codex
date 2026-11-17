#include "D2Game.h"

#define STATE_BLAZE 0x0D
#define STATE_SPIDERLAY 0x16
struct D2ModeChangeStrc;
struct D2MonStatsTxt;
struct D2MissilesTxt;
struct D2MissileUnitFindArgStrc;

struct D2GameStrc
{
    char pad0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char pad0x30[0x80];
    int dwLastHitClass;
    unsigned char unk_B4[0x10];
    unsigned int dwFlags;
};

int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x00554CA0
void __fastcall sub_005A8030(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A8030
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C9D90
void __fastcall SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CE4F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

enum D2C_Q05MonsterConstants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONMODE_GETHIT = 3,
    EVENTTYPE_AITHINK = 2,
    MONSTER_SANDLEAPER1 = 78,
    STATE_STUNNED = 21,
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nFlag;
    unsigned char unk0x16;
    unsigned char unk0x17;
    int unk0x18;
    int unk0x1C;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode); // 0x0046C140
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __fastcall sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A8520

struct D2MissilesTxt
{
    char unk0x000[0x187];
    unsigned char nCollideFriend;
    unsigned char nNextHit;
};

struct D2MissileUnitFindArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

// 0x005A8490
int __fastcall sub_6FC64480(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (STATES_CheckState(pUnit, STATE_BLAZE))
    {
        SKILLS_CreateBlazeMissile(pGame, pUnit);
    }

    if (STATES_CheckState(pUnit, STATE_SPIDERLAY))
    {
        SKILLS_CreateSpiderLayMissile(pGame, pUnit);
    }

    if (sub_6FCBC930(pGame, pUnit) == 2)
    {
        sub_005A8030(pGame, pUnit);
        return 2;
    }

    return 1;
}

// 0x005A84F0
int __fastcall sub_6FC64510(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (sub_6FCBC930(pGame, pUnit) == 2)
    {
        sub_005A8030(pGame, pUnit);
        return 2;
    }

    return 1;
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline_Q05(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int MONSTERMODE_GetBaseIdInline_Q05(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline_Q05(nClassId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nClassId;
}

// 0x005A8520
void __fastcall sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    PATH_ResetToPreviousType(pUnit->pDynamicPath);

    const int nClassId = pUnit->dwClassId;
    if (!sub_0046C140_CheckMonStats2ModeFlag(nClassId, MONMODE_GETHIT))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    int bSandLeaper = 0;
    if (nUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERMODE_GetBaseIdInline_Q05(nClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_SANDLEAPER1)
        {
            bSandLeaper = 1;
        }
    }

    if (!bSandLeaper)
    {
        UNITS_SetUsedSkill(pUnit, 0);

        D2ModeChangeStrc modeChange = {};
        modeChange.nMode = MONMODE_GETHIT;
        modeChange.pUnit = pUnit;
        modeChange.nFlag = 100;
        pUnit->dwLastHitClass = 160;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
        return;
    }

    int nFrame;
    if (STATES_CheckState(pUnit, STATE_STUNNED))
    {
        nFrame = pGame->dwGameFrame + 45;
    }
    else
    {
        nFrame = pGame->dwGameFrame + 15;
    }
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrame, 0, 0);
}

// 0x005A8630
int __fastcall sub_6FC64E20(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_6FCBC930(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        sub_6FC64CD0(pGame, pUnit);
        return 2;
    }

    return 1;
}

inline int UNITS_IsValidTargetInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 3) & 1;
}

inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 2) & 1;
}

static int __stdcall sub_005A8730_MISSMODE_CanCollideWithUnit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2UnitStrc* pOwner, D2MissilesTxt* pMissilesTxtRecord)
{
    if (!UNITS_IsValidTargetInline(pUnit))
    {
        return 0;
    }

    if (!UNITS_CanBeAttackedInline(pUnit))
    {
        return 0;
    }

    if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pUnit, 0x56))
    {
        return 0;
    }

    if (MISSILE_CheckUnitIfOwner(pMissile, pUnit) || (pOwner && !sub_00554200(pGame, pOwner, pUnit) && !pMissilesTxtRecord->nCollideFriend))
    {
        return 0;
    }

    return 1;
}

// 0x005A87B0
int __fastcall MISSMODE_UnitFindCallback_CanCollideWithMonster(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return 0;
    }

    return sub_005A8730_MISSMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x005A87F0
int __fastcall MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    switch (nType)
    {
    case 0:
        break;
    case 1:
        if (STATLIST_GetUnitAlignment(pUnit) != 2)
        {
            return 0;
        }
        break;
    default:
        return 0;
    }

    return sub_005A8730_MISSMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x005A8850
int __fastcall MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1)
    {
        return 0;
    }

    return sub_005A8730_MISSMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}
