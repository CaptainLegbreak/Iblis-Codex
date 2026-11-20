#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MonStatsTxt;
struct D2SeqModeStrc;
struct D2UnitTargetStrc;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStats2Txt;
struct D2SkillsTxt;
struct D2MissileStrc;
struct Unicode;





struct D2SeqModeStrc
{
    int unk0x00;
    int nMode;
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int nParam3;
    int f_C;
    int f_10;
    int f_14;
    int f_18;
};

void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit); // 0x00623E00
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

typedef unsigned int DWORD;





typedef char I20_check_unit_a[(I20_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && I20_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char I20_check_unit_b[(I20_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && I20_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char I20_check_unit_c[(I20_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && I20_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char I20_check_txt_a[(I20_OFFSET(D2MonStatsTxt, nByte1A7) == 0x1A7 && I20_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char I20_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && I20_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char I20_check_txt_c[(I20_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char I20_check_unit_d[(I20_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char I20_check_misc[(I20_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2MonAnimRecStrc gaMonAnimRecords_00725220[]; // 0x00725220
extern D2MonAnimRecStrc gaMonAnimRecordsMoving_007252E0[]; // 0x007252E0
extern D2MonAnimRecStrc gMonAnimRecord_00725328; // 0x00725328
extern D2MonAnimRecStrc gMonAnimRecord_00725334; // 0x00725334
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall sub_004ADE60(D2UnitStrc* pUnit); // 0x004ADE60
void __stdcall sub_004AF1B0(D2UnitStrc* pUnit, int nMissile, int nX, int nY); // 0x004AF1B0
int __fastcall sub_004C68F0_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0
void __fastcall sub_004C72F0(D2UnitStrc* pUnit); // 0x004C72F0
void __fastcall sub_004CB460_UpdateModeSound(D2UnitStrc* pUnit); // 0x004CB460
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall sub_00648750(D2DynamicPathStrc* pPath, int nArg); // 0x00648750
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0

struct Unicode
{
    unsigned short wChar;
    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode sub_004B15F0() const;
};

enum { CASE_BOUND = 0x100 };

static D2MonStatsTxt* MONSTATS_GetRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2MonStatsTxt* MONSTATS_GetUnitRecord(D2UnitStrc* pUnit, int nType)
{
    if (pUnit && nType == UNIT_MONSTER)
    {
        return MONSTATS_GetRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x004B1280
int __fastcall sub_004B1280_HandleSequenceStop(D2UnitStrc* pUnit, D2SeqModeStrc* pMode)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nType = pUnit->dwUnitType;

    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetUnitRecord(pUnit, nType);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        switch (pMonStatsTxtRecord->nSplEndDeath)
        {
        case 1:
            if (!pUnit->dwAnimMode && UNITS_IsAtEndOfFrameCycle(pUnit))
            {
                D2UnitTargetStrc tTarget = {};
                sub_004AFF60_MonsterCommand(9, pUnit, &tTarget);
            }
            break;
        }
    }

    int nResult = 0;
    switch (pMode->nMode)
    {
    case 0:
        UNITS_StopSequence(pUnit);
        break;

    case 1:
        nResult = UNITS_IsAtEndOfFrameCycle(pUnit);
        if (!nResult)
        {
            UNITS_StopSequence(pUnit);
        }
        break;

    case 2:
        if (!UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            UNITS_StopSequence(pUnit);
            break;
        }

        pUnit->nSeqCurrentFramePrecise = pUnit->dwFrameCountPrecise - 0x100;
        pUnit->wAnimSpeed = 0;
        if (!pUnit->dwAnimMode)
        {
            pUnit->dwFlags |= 0x20;
        }
        break;

    case 3:
        pUnit->nSeqCurrentFramePrecise = 0x100;
        pUnit->wAnimSpeed = 0;
        break;
    }

    return nResult;
}

static __forceinline unsigned int sub_I20_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2SkillsTxt* sub_I20_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int sub_I20_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static __forceinline int sub_I20_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_I20_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static void sub_004AE400_CastRandomCurse(D2UnitStrc* pUnit)
{
    const int nIndex = sub_I20_SeedStep(&pUnit->pSeed) % 5;
    D2_ASSERT(nIndex < 5, 0x174);

    const int nSkill = gaRandomCurseSkills_006DA5DC[nIndex];
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nSkill, sub_I20_UnitX(pUnit), sub_I20_UnitY(pUnit), 0, 1);
    if (pMissile)
    {
        UNITS_StoreOwner(pMissile, pUnit);
        UNITS_StoreOwner(pUnit, pMissile);
        sub_004DA000_ResetGfxMotion(pMissile);
        sub_004DA620(pMissile, 1);
        pMissile->dwFlagEx |= 0x40000;
    }
}

static void sub_004AF2E0_MonsterSkillEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    const int nMissile = D2Common_11050(pUnit, 1);
    if (nMissile == -1)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x20;
    switch (nMissile)
    {
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x42:
        tMissile.dwFlags = 0x34;
        tMissile.nVelocity = 2;
        break;
    }
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nSkillLevel = 1;

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath)
        {
            return;
        }
        tMissile.nTargetX = D2COMMON_10175_PathGetFirstPointX(pPath);
        tMissile.nTargetY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
    }

    if (nMissile == 0xEE || nMissile == 0xEF)
    {
        if (pTarget)
        {
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, 0, 1, 0);
        }
    }
    else if (nMissile == 0x196)
    {
        sub_004AE3C0(pUnit);
        sub_004AE400_CastRandomCurse(pUnit);
    }
    else
    {
        sub_004CD540_CreateMissile(&tMissile);
    }

    sub_004AF1B0(pUnit, nMissile, tMissile.nTargetX, tMissile.nTargetY);
}

static D2MonAnimRecStrc* sub_004AF400_GetMonsterAnimRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != 1)
    {
        return 0;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    if (nClassId == 0xF3 && nMode == 0xB || nClassId == 0x14D && nMode == 0xB)
    {
        return &gMonAnimRecord_00725328;
    }

    if (nClassId == 0x21F && nMode == 0xA || nClassId == 0x220 && nMode == 0xA || nClassId == 0x23A && nMode == 0xA)
    {
        return &gMonAnimRecord_00725334;
    }

    D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
    if (!pMonStats2Txt)
    {
        return 0;
    }

    if (pMonStats2Txt->nModeEnabledWhenMovingFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
    {
        return &gaMonAnimRecordsMoving_007252E0[nMode];
    }

    if (!nMode && sub_0063E8D0(pUnit, nMode))
    {
        return &gaMonAnimRecordsMoving_007252E0[0];
    }

    return &gaMonAnimRecords_00725220[pUnit->dwAnimMode];
}

static void sub_004AF4C0_UpdateMonsterFrame(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2Txt;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_I20_GetSkillsTxt(SKILLS_GetSkillIdFromSkill(pSkill, gszMonsterSourceFile_006DA5C8, 0x3B5));
    if (!pSkillsTxt)
    {
        return;
    }

    int nFlags = SKILLS_GetFlags(pSkill);
    int bCheckFrame = 1;
    if ((nFlags & 1) && sub_004807C0(pUnit))
    {
        if (pSkillsTxt->wSrvDoFunc != 0x43)
        {
            nFlags |= 2;
            SKILLS_SetFlags(pSkill, nFlags);
        }
        sub_004C68F0_DoUsedSkill(pUnit);
        bCheckFrame = 0;
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame != 4)
    {
        if (!bCheckFrame || sub_00451F30_TestUnitFlag(pUnit, 0x40) || nActionFrame != 1 && nActionFrame != 2 && nActionFrame != 3)
        {
            switch (pSkillsTxt->wSrvDoFunc)
            {
            case 0x5F:
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt)
                {
                    return;
                }

                sub_004C68F0_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise >> 8) > pMonStats2Txt->nInfernoAnim)
                {
                    pUnit->nSeqCurrentFramePrecise = pMonStats2Txt->nInfernoRollback << 8;
                }
                return;

            case 0x7E:
                sub_004C68F0_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise & ~0xFF) >= 0xC00)
                {
                    pUnit->nSeqCurrentFramePrecise = 0x800;
                }
                return;

            case 0x98:
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt || !STATES_CheckState(pUnit, 0xC))
                {
                    return;
                }

                const int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
                if (nFrame >= pMonStats2Txt->nInfernoAnim)
                {
                    sub_004C68F0_DoUsedSkill(pUnit);
                }

                if (nFrame >= pMonStats2Txt->nInfernoRollback)
                {
                    pUnit->nSeqCurrentFramePrecise = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) + pMonStats2Txt->nInfernoRollback - 4) << 8;
                }
                return;
            }
            }
            return;
        }
    }

    sub_004C68F0_DoUsedSkill(pUnit);
}

static void sub_004AF6A0_MonsterAttackEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    const int nId = sub_00463860_GetMonsterId(pUnit);
    const int nMonsterId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    if (nMode == 0xD && nMonsterId != 0x4E)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            sub_00650590(pPath);
            sub_00648750(pPath, 0);
            sub_00648DC0(pPath);
            sub_00480E70_SetUnitMode(pUnit, 3);
        }
        return;
    }

    if (sub_004648F0_GetPathTargetUnit(pUnit))
    {
        sub_00465BF0(pUnit, 0);
    }

    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nByte1A7)
    {
        const unsigned int nCurrentMode = pUnit->dwAnimMode;
        switch (nCurrentMode)
        {
        case 8:
            if (nMonsterId == 0x6E)
            {
                return;
            }
        case 5:
        case 9:
            if (nMonsterId == 0x193 || nMonsterId == 0x194)
            {
                sub_00480E70_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 10:
            if (nMonsterId == 0x88)
            {
                sub_00480E70_SetUnitMode(pUnit, 0xB);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 11:
            if (nMonsterId == 0x88)
            {
                return;
            }
            break;

        case 2:
            if (nMonsterId == 0xE7 || nMonsterId == 0x76)
            {
                return;
            }
            break;

        case 4:
            if (nMonsterId == 0x193 || nMonsterId == 0x194)
            {
                sub_00480E70_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            if (nMonsterId == 0x1F1)
            {
                sub_004AE3C0(pUnit);
                sub_004AE400_CastRandomCurse(pUnit);
            }
            break;

        case 14:
            if (nMonsterId == 0xF7)
            {
                return;
            }
            break;

        case 12:
            if (nMonsterId == 0x11C)
            {
                return;
            }
            break;
        }
    }

    if (sub_I20_HasUnitFlagBit(pUnit))
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
        return;
    }

    if (!sub_00463720_TestUnitFlagEx(pUnit, 0x2000))
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
    }
}

// 0x004B13A0
void __fastcall sub_004B13A0_UpdateMonsterClient(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return;
    }

    if (STATES_CheckState(pUnit, 1) && !sub_00464820_IsDeadOrDying(pUnit))
    {
        return;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    D2MonAnimRecStrc* pRecord = sub_004AF400_GetMonsterAnimRecord(pUnit);
    if (!pRecord)
    {
        return;
    }

    sub_004AF4C0_UpdateMonsterFrame(pUnit);

    int bResult = 0;
    switch (pRecord->nType)
    {
    case 1:
        bResult = sub_004807C0(pUnit);
        break;
    }

    if (nMode == 1 && !sub_004AE080(pUnit, nMode))
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath && PATH_GetTargetUnit(pPath))
        {
            int nUnitType;
            int nUnitGUID;
            PATH_GetTargetTypeAndGUID(pPath, &nUnitType, &nUnitGUID);
            D2UnitStrc* pTarget = sub_00463990(nUnitGUID, nUnitType);
            PATH_SetTargetUnit(pPath, pTarget);
            if (pTarget)
            {
                D2Common_10213(pUnit);
            }
        }
        else
        {
            D2Common_10213(pUnit);
        }
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nClassId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if ((pMonStatsTxt->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !sub_004638A0_CheckMonStats2Flag(nClassId, 0xD)
        && pUnit->dwAnimMode == 1 && !sub_00451F30_TestUnitFlag(pUnit, 0x200)
        && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && (unsigned int)sub_00641530(pUnit, pPlayer) < 7)
        {
            D2SeedStrc* pSeed = &pUnit->pSeed;
            if (pSeed && (int)SEED_RollLimitedRandomNumber(pSeed, 0x64) < 0xA)
            {
                D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
                if (pPath)
                {
                    D2Common_10216(pPath, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer), 0);
                }
            }
        }
    }

    const int nRet = sub_004B1280(pUnit, pRecord);
    int bAttack = 0;
    switch (pRecord->nAction)
    {
    case 1:
        bAttack = bResult;
        break;

    case 2:
    case 3:
        bAttack = nRet;
        break;

    case 4:
        if (bResult && sub_006217C0(pUnit))
        {
            bAttack = 1;
        }
        break;
    }

    sub_004AF2E0_MonsterSkillEvent(pUnit);
    sub_004ADE60(pUnit);
    if (pUnit->pDynamicPath)
    {
        D2COMMON_10193_PATH_AdjustDirection(pUnit->pDynamicPath);
    }

    if (bAttack)
    {
        sub_004AF6A0_MonsterAttackEvent(pUnit);
    }

    if (!pUnit->dwAnimMode && pUnit->dwClassId == 0x210 && sub_00451F30_TestUnitFlag(pUnit, 1))
    {
        pUnit->dwFlags &= ~1;
        sub_00466730_SpawnPresetUnit(0x1DE, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 2, 0);
    }

    if (sub_0063A340(pUnit))
    {
        sub_004C72F0(pUnit);
    }

    sub_004CB460_UpdateModeSound(pUnit);
    sub_004CAF60(pUnit);
}

// 0x004B15F0
Unicode Unicode::sub_004B15F0() const
{
    return Unicode(wChar < CASE_BOUND ? gaCaseTable_00730778[wChar] : wChar);
}

#include "gen/data/Source/D2Client/Unknown_004B1280.inc"
struct D2UnitStrc;
