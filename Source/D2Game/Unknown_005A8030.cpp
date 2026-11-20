#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2MonStatsTxt;
struct D2ModeChangeStrc;
struct D2MissilesTxt;
struct D2MissileUnitFindArgStrc;


struct D2MonStatsTxt { short nId; short nBaseId; char unk_04[0x1A2]; unsigned char nSpecialEnd; char unk_1A7; };


struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nX;
    int nY;
    union { int nFlags; struct { unsigned char nDirection; unsigned char nVelocity; unsigned char unk_16[2]; }; };
    int unk_18;
    int unk_1C;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned char gbModeReset_0073C6D0[]; // 0x0073C6D0

typedef void (__fastcall *ModeCallback)(D2GameStrc*, D2UnitStrc*, int, int);

extern ModeCallback gpModeCallback_006E2498; // 0x006E2498
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
void __fastcall sub_6FCBDE90(D2UnitStrc*, int); // 0x005544B0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc*, int); // 0x00620210
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*, D2UnitStrc*); // 0x00553540
int __stdcall sub_005A7C20_ChangeMode(D2GameStrc*, D2ModeChangeStrc*, int); // 0x005A7C20

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

// build: context MONSTATS_GetRecordInline
static __forceinline D2MonStatsTxt* MONSTATS_GetRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// build: context MONSTATS_GetBaseIdInline
static __forceinline int MONSTATS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
        return nClassId;
    return pMonStatsTxtRecord->nBaseId;
}

// build: context MONSTERS_GetBaseIdFromUnitInline
static __forceinline int MONSTERS_GetBaseIdFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
        return MONSTATS_GetBaseIdInline(pUnit->dwClassId);
    return -1;
}

// build: context MONSTERS_ValidateMonsterIdInline
static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return nMonsterId;
    return -1;
}

// build: context MONSTERMODE_AiThinkUnlessFrozen
static __forceinline void MONSTERMODE_AiThinkUnlessFrozen(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (STATES_CheckState(pUnit, 1) && !SUNIT_IsDead(pUnit)) return;
    if (gpModeCallback_006E2498) gpModeCallback_006E2498(pGame, pUnit, 0, 0);
}

// 0x005A8030
void __fastcall MONSTERMODE_HandleEndAnimation(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    const int nRawId = MONSTERS_GetBaseIdFromUnitInline(pUnit);
    const int nBaseId = MONSTERS_ValidateMonsterIdInline(nRawId);
    D2MonStatsTxt* pRecord = MONSTATS_GetRecordInline(nRawId);
    if (pRecord->nSpecialEnd)
    {
        if (nBaseId == 110)
        {
            if (nMode == 8) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == 247)
        {
            if (nMode == 14) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == 136)
        {
            if (nMode == 10 || nMode == 11) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == 230 || nBaseId == 231)
        {
            MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return;
        }
        else if (nBaseId == 118)
        {
            if (nMode == 2) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == 403)
        {
            MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return;
        }
    }
    if (gbModeReset_0073C6D0[nMode])
    {
        UNITS_ChangeAnimMode(pUnit, 1);
        MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit);
        return;
    }
    if (STATES_CheckState(pUnit, 54))
    {
        sub_6FCBDE90(pUnit, 0);
        if (SUNIT_IsDead(pUnit)) return;
    }
    UNITS_SetUsedSkill(pUnit, 0);
    D2ModeChangeStrc mode = {};
    mode.nMode = 1;
    mode.pUnit = pUnit;
    mode.nVelocity = 100;
    mode.pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    sub_005A7C20_ChangeMode(pGame, &mode, 1);
}

#include "gen/data/Source/D2Game/Unknown_005A8030.inc"

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

// 0x005A8730
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

    if (MISSILE_CheckUnitIfOwner(pMissile, pUnit))
    {
        return 0;
    }

    return !pOwner || sub_00554200(pGame, pOwner, pUnit) || pMissilesTxtRecord->nCollideFriend;
}

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
