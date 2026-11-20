#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"


struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    unsigned char nTypeFlags;
};


struct D2MonCommandStrc
{
    int nParam00;
    int nParam04;
    int nParam08;
    int nParam0C;
    int nParam10;
    int nParam14;
    int nParam18;
};

struct D2MonStatsTxt
{
    short unk0x000;
    short nBaseId;
    char unk0x004[0x14];
    short wMonStatsEx;
    char unk0x01A[0x0C];
    short wSpawnId;
    char unk0x028[0x17C];
    unsigned char nSpawnType;
    char unk0x1A5[0x3];
};

struct D2MonStats2Txt
{
    int dwId;
    unsigned char nFlags[4];
    char unk0x008[0x3];
    unsigned char nValue0B;
    char unk0x00C[0xF8];
    unsigned char nModeFlags[16];
    char unk0x114[0x20];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[0x4];
    int nMonStats2TxtRecordCount;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int unk0x14[7];
    int nSkillLevel;
    int unk0x34[10];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2MonCmdRecordStrc gMonCmdRecords_006DA4D8[];                                                        // 0x006DA4D8

int __cdecl sub_0044BF00();                                                                                 // 0x0044BF00
int __cdecl sub_0044BF10();                                                                                 // 0x0044BF10
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
void __fastcall sub_00457460(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x00457460
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004643F0_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, int nUnitGUID);              // 0x004643F0
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit);                                       // 0x004647D0
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit);                                                // 0x00464810
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_00464C90_SetCounter58(D2UnitStrc* pUnit);                                               // 0x00464C90
void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg);                // 0x00464E50
void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg);                        // 0x00465BF0
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
void __fastcall sub_00467A70_RefreshHoverUnit(int nArg);                                                    // 0x00467A70
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                                     // 0x0046C140
void __fastcall sub_0046F170_RemoveOverlays(D2UnitStrc* pUnit);                                             // 0x0046F170
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
void __fastcall sub_00480490_RecacheUnitPath(D2UnitStrc* pUnit);                                            // 0x00480490
int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY);                           // 0x004804A0
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0
int __fastcall sub_00480780_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitGUID);            // 0x00480780
void __fastcall sub_00480D20_SetModeOverlay(D2UnitStrc* pUnit, int nMode);                                  // 0x00480D20
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode);                                     // 0x00480E70
void __fastcall sub_00480EC0_SetUnitModeNoOverlay(D2UnitStrc* pUnit, int nMode);                            // 0x00480EC0
void __fastcall sub_004AC840(D2UnitStrc* pUnit, int nFlag);                                                 // 0x004AC840
void __fastcall sub_004ADE40(D2UnitStrc* pUnit);                                                            // 0x004ADE40
void __fastcall sub_004ADE50(D2UnitStrc* pUnit);                                                            // 0x004ADE50
void __fastcall sub_004ADE70(D2UnitStrc* pUnit);                                                            // 0x004ADE70
void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit);                                            // 0x004AE210
void __fastcall sub_004AF890_SpawnBloodMissiles(D2UnitStrc* pUnit, int nArg1, int nArg2);                   // 0x004AF890
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);  // 0x004AFF60
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);          // 0x004B9A00
void __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nValue, int nArg2, int nArg3);          // 0x004C5420
void __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);              // 0x004C6EB0
void __fastcall sub_004C6F40(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);                                // 0x004C6F40
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit);                                          // 0x004DA0F0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit);                                       // 0x006272E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit);                                       // 0x0063A6F0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
D2SkillStrc* __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall sub_00648730(D2DynamicPathStrc* pDynamicPath);                                // 0x00648730
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648DC0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic);                             // 0x00649F70
void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit);                                // 0x0064A0E0
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath);                                   // 0x00650590

static void sub_004AE1D0_RefreshMonsterMode(D2UnitStrc* pUnit);                                             // 0x004AE1D0
static void sub_004AFB60_ReplaySequence(D2UnitStrc* pUnit);                                                // 0x004AFB60
static int sub_004AFBC0_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord);                    // 0x004AFBC0
static void sub_004AFC10_CreateDeathMissiles(D2UnitStrc* pUnit);                                            // 0x004AFC10
static void sub_004AFCE0_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode);                              // 0x004AFCE0

// 0x004AE1D0
static __declspec(noinline) void sub_004AE1D0_RefreshMonsterMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        const unsigned int nMode = pUnit->dwAnimMode;
        if (nMode < 0x10 && nMode && nMode != 0xC)
        {
            sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 0);
            sub_00480490_RecacheUnitPath(pUnit);
            sub_00480E70_SetUnitMode(pUnit, 1);
        }
    }
}

// 0x004AFB60
static __declspec(noinline) void sub_004AFB60_ReplaySequence(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pSequenceRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    const int nCount = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
    for (int i = 0; i < nCount; ++i)
    {
        int nMode;
        int nFrame;
        int nDirection;
        int nEvent;
        DATATBLS_ComputeSequenceAnimation(pSequenceRecord, i << 8, i << 8, &nMode, &nFrame, &nDirection, &nEvent);
        pUnit->dwAnimMode = nMode;
        sub_00470610_Refresh(pUnit, 0);
    }
}

// 0x004AFBC0
static __declspec(noinline) int sub_004AFBC0_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    if (!pUnit || !pRecord)
        return 0;

    if (pRecord->bSet)
    {
        const int nIndex = pRecord->nIndex;
        if (nIndex < 0x10)
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2Txt)
                return pMonStats2Txt->nModeFlags[nIndex >> 3] & gdwBitMasks[nIndex & 7];
        }
    }
    return 0;
}

// 0x004AFC10
static __declspec(noinline) void sub_004AFC10_CreateDeathMissiles(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
        return;

    D2MissileStrc tMissile;
    if (STATES_CheckState(pUnit, 0xB8) && !STATES_CheckState(pUnit, 1))
    {
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2020;
        tMissile.pOwner = pUnit;
        tMissile.pOrigin = pUnit;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = 0x1AB;
        sub_004CD540_CreateMissile(&tMissile);
        tMissile.nMissile = 0x1AA;
        sub_004CD540_CreateMissile(&tMissile);
        return;
    }

    const int nMissile = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId)->nValue0B + 0x10F;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x2020;
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nSkillLevel = 1;
    tMissile.nMissile = nMissile;
    sub_004CD540_CreateMissile(&tMissile);
    tMissile.nMissile = 0x113;
    sub_004CD540_CreateMissile(&tMissile);
}

static __forceinline int sub_J10_UnitX(D2UnitStrc* pUnit)
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

static __forceinline int sub_J10_UnitY(D2UnitStrc* pUnit)
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

// 0x004AFCE0
static __declspec(noinline) void sub_004AFCE0_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode == 12)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~14;
        }
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        if (sub_004DA0F0_GetGfxMotionField3C(pUnit))
        {
            return;
        }
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 2, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0xA0, 0);
    }
    else if (nMode == 14 || nMode == 10)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 14;
        }
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        if (!sub_004DA0F0_GetGfxMotionField3C(pUnit))
        {
            return;
        }
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        sub_004DA6E0_SetMotionFlag20(pUnit, 0);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, -8, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0, 0);
    }
}

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

__declspec(noinline) void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        sub_00470390(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

static __forceinline int sub_n5b_IsClassId(D2UnitStrc* pUnit, int nClassId)
{
    return pUnit->dwClassId == nClassId;
}

static __forceinline int sub_n5b_Distance(int nDelta)
{
    if (nDelta < 0)
        nDelta = -nDelta;
    return nDelta;
}

static __forceinline int sub_n5b_IsTypeFlag1(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        return pUnit->pMonsterData->nTypeFlags & 1;
    return 0;
}

static __forceinline D2MonStatsTxt* sub_n5b_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline D2MonStats2Txt* sub_n5b_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

__declspec(noinline) int __fastcall sub_00463860(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_n5b_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
            return pUnit->dwClassId;
        return pMonStatsTxtRecord->nBaseId;
    }
    return -1;
}

static __forceinline int sub_n5b_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return nMonsterId;
    return -1;
}

static __forceinline void sub_b1_WalkTo(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand, int nMode)
{
    if (sub_004AE080(pUnit, 1) || !sub_004804A0_SetPathTargetPos(pUnit, pCommand->nParam00, pCommand->nParam04)
        || STATES_CheckState(pUnit, 0x8F) || !sub_0046C140_TestMonModeFlag(pUnit->dwClassId, nMode))
    {
        sub_004AE1D0_RefreshMonsterMode(pUnit);
        return;
    }

    sub_00480E70_SetUnitMode(pUnit, nMode);
}

// 0x004AFF60
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pCommand)
{
    int nMonId;
    D2MonStats2Txt* pMonStats2Txt;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pUnit->dwAnimMode == 0xD)
    {
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_ResetToPreviousType(pPath);
    }

    if (!sub_00464820_IsDeadOrDying(pUnit))
    {
        PATH_AddCollisionFootprintForOptionalUnit(pUnit);
    }
    else if (nCommand != 8 && nCommand != 9)
    {
        sub_00649FF0(pUnit, 0);
        sub_004AE210_SetMonsterLight(pUnit);
        pUnit->dwFlagEx &= ~0x40000;
    }

    int bUpdateVelocity = 0;
    if (nCommand != 0x13 && nCommand != 0x16 && nCommand != 0x15 && pCommand)
    {
        bUpdateVelocity = 1;
        if (pCommand->nParam0C > 0)
        {
            PATH_SetType(pPath, pCommand->nParam0C);
            if (nCommand == 0x14)
            {
                PATH_SetNewDistance(pPath, (unsigned char)pCommand->nParam14);
                PATH_SetStepNum(pPath, (unsigned char)pCommand->nParam08);
            }
        }
        UNITS_SetUsedSkill(pUnit, 0);
        sub_004ADE40(pUnit);
    }

    if (!sub_n5b_GetMonStatsTxtRecord(pUnit->dwClassId))
        return;

    pMonStats2Txt = sub_n5b_GetMonStats2TxtRecord(pUnit->dwClassId);
    if (!pMonStats2Txt)
        return;

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    const int nBaseId = sub_00463860(pUnit);
    if (nBaseId >= 0 && nBaseId < nMonStatsCount)
        nMonId = nBaseId;
    else
        nMonId = -1;

    int nValue;
    D2MonCmdRecordStrc* pRecord = &gMonCmdRecords_006DA4D8[nCommand];
    switch (nCommand)
    {
    case 1:
    case 0x17:
        D2_ASSERT(pCommand, 0x6E2);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 1);
        if (sub_004AE080(pUnit, 1) || !sub_004804A0_SetPathTargetPos(pUnit, pCommand->nParam00, pCommand->nParam04))
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        if (nCommand == 1)
            sub_00480E70_SetUnitMode(pUnit, 2);
        else
            sub_00480E70_SetUnitMode(pUnit, 0xF);
        break;

    case 0:
    case 0x18:
    {
        D2_ASSERT(pCommand, 0x6F7);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 1);
        nValue = pCommand->nParam00;
        sub_004643F0_SetTargetByGUID(pUnit, nValue, pCommand->nParam04);
        if (sub_004AE080(pUnit, 1) || !sub_00480780_SetPathTargetUnit(pUnit, nValue, pCommand->nParam04))
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        if (nCommand == 0)
            sub_00480E70_SetUnitMode(pUnit, 2);
        else
            sub_00480E70_SetUnitMode(pUnit, 0xF);
        break;
    }

    case 5:
    case 0xA:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x1B:
    case 0x1D:
    {
        D2_ASSERT(pCommand, 0x70F);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        nValue = pCommand->nParam00;
        if (nMonId == 0xE7)
            break;

        sub_004643F0_SetTargetByGUID(pUnit, nValue, pCommand->nParam04);
        if (nMonId == 0x130 && nCommand == 0xA)
        {
            D2UnitStrc* pTargetUnit = sub_004648F0_GetPathTargetUnit(pUnit);
            sub_00464E50_SetOverlayWithSound(pTargetUnit, 0xA9, 0);
        }

        sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 0);
        if (nMonId == 0x6E)
            sub_004AFCE0_UpdateCollisionForMode(pUnit, nCommand);
        else if (nMonId == 0x9A && nCommand == 0xD)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x38);

        if ((!pUnit ? -1 : pUnit->dwClassId) == 0x195 && nCommand == 0xD)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);

        if (pUnit->dwClassId == 0x195 && nCommand == 0xF)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x30);

        if (nMonId == 0x9B)
        {
            if (nCommand == 0xD)
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
        }
        else if (nMonId == 0xB2 && nCommand == 0xD)
        {
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 4);
        }

        sub_00480E70_SetUnitMode(pUnit, pRecord->nIndex);
        if (sub_004AFBC0_HasMonStatsFlag(pUnit, pRecord))
            sub_00480780_SetPathTargetUnit(pUnit, nValue, pCommand->nParam04);
        break;
    }

    case 4:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x11:
    case 0x1A:
    case 0x1C:
        D2_ASSERT(pCommand, 0x741);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        if ((pCommand->nParam00 || pCommand->nParam04)
            && (pCommand->nParam00 != CLIENTS_GetUnitX(pUnit) || pCommand->nParam04 != CLIENTS_GetUnitY(pUnit)))
        {
            UNITS_UpdateDirectionAndSpeed(pUnit, pCommand->nParam00, pCommand->nParam04);
        }

        sub_00480E70_SetUnitMode(pUnit, pRecord->nIndex);
        if (sub_004AFBC0_HasMonStatsFlag(pUnit, pRecord))
            sub_004804A0_SetPathTargetPos(pUnit, pCommand->nParam00, pCommand->nParam04);

        if (nMonId == 0x6E)
            sub_004AFCE0_UpdateCollisionForMode(pUnit, nCommand);
        break;

    case 6:
    {
        if (!pCommand)
            break;

        sub_004AC840(pUnit, pCommand->nParam08 & 0x80);
        pCommand->nParam08 &= 0x7F;
        if (pCommand->nParam08 > 1)
            ++pCommand->nParam08;

        int bBlood = 1;
        if (pCommand->nParam08)
        {
            const int nOldValue = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
            if (nOldValue == pCommand->nParam08)
                bBlood = 0;
            else
                STATLIST_SetUnitStat(pUnit, 6, pCommand->nParam08 << 8, 0);
        }

        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        pUnit->dwLastHitClass = pCommand->nParam18;
        PATH_RecacheRoomIfNeeded(pPath);
        sub_00480E70_SetUnitMode(pUnit, 3);
        if (bBlood)
            sub_004AF890_SpawnBloodMissiles(pUnit, 1, 0);

        sub_00464C90_SetCounter58(pUnit);
        sub_004ADE70(pUnit);
        break;
    }

    case 0x13:
        D2_ASSERT(pCommand, 0x781);
        sub_004AC840(pUnit, pCommand->nParam04 & 0x80);
        pCommand->nParam04 &= 0x7F;
        if (pCommand->nParam04 > 1)
            ++pCommand->nParam04;

        if (pCommand->nParam04)
            STATLIST_SetUnitStat(pUnit, 6, pCommand->nParam04 << 8, 0);

        pUnit->dwLastHitClass = pCommand->nParam00;
        sub_004AF890_SpawnBloodMissiles(pUnit, 1, 1);
        sub_00464C90_SetCounter58(pUnit);
        sub_00480D20_SetModeOverlay(pUnit, 0xD);
        sub_004CC5B0_RequestMode(pUnit, 0xD, 1);
        sub_004ADE70(pUnit);
        break;

    case 0x14:
        D2_ASSERT(pCommand, 0x79A);
        if (pCommand->nParam14)
            STATLIST_SetUnitStat(pUnit, 6, pCommand->nParam14 << 8, 0);

        pUnit->dwLastHitClass = pCommand->nParam18;
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_SetType(pPath, 0xB);
        D2COMMON_10190_PATH_SetDistance(pPath, (unsigned char)pCommand->nParam08);
        D2COMMON_10170_PathSetTargetPos(pPath, (unsigned short)pCommand->nParam00, (unsigned short)pCommand->nParam04);
        D2Common_10142(pPath, pUnit, 0);
        sub_00480E70_SetUnitMode(pUnit, 0xD);
        break;

    case 0x12:
        D2_ASSERT(pCommand, 0x7B0);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        PATH_RecacheRoomIfNeeded(pPath);
        sub_004643F0_SetTargetByGUID(pUnit, pCommand->nParam00, pCommand->nParam04);
        sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 0);
        sub_00480E70_SetUnitMode(pUnit, 6);
        break;

    case 8:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        pUnit->dwLastHitClass = pCommand->nParam18;
        if (sub_00467A10() == pUnit)
        {
            if (!(sub_0044BF00() & 8) && !(sub_0044BF10() & 8))
            {
                sub_00466FE0();
            }
            else
            {
                sub_0044DA40();
                sub_00467A70_RefreshHoverUnit(0);
            }
        }

        STATLIST_SetUnitStat(pUnit, 6, 0, 0);
        if (STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags &= ~2;
            pUnit->dwFlags |= 0x20;
        }

        if (STATES_CheckStateMaskShatterOnUnit(pUnit))
        {
            sub_004AFC10_CreateDeathMissiles(pUnit);
            pUnit->dwLastHitClass = (pUnit->dwLastHitClass & 0xF) | 0xA0;
        }

        if (!(pMonStats2Txt->nFlags[2] & gdwBitMasks[3]))
            PATH_SetUnitDeadCollision(pUnit, 0);

        nValue = pUnit->dwClassId;
        D2MonStatsTxt* pDeadMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nValue);
        if (!pDeadMonStatsTxt)
            return;

        switch (pDeadMonStatsTxt->nSpawnType)
        {
        case 1:
            if (pDeadMonStatsTxt->wSpawnId >= 0 && pDeadMonStatsTxt->wSpawnId < sgptDataTables->nMonStatsTxtRecordCount)
            {
                D2UnitStrc* pSpawned = sub_00466730_SpawnPresetUnit(nValue, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, 0);
                if (pSpawned)
                    pSpawned->dwFlags &= ~2;

                pSpawned->dwLastHitClass = pUnit->dwLastHitClass;
                sub_00480E70_SetUnitMode(pSpawned, 0);
                sub_004AEDD0(pUnit, pDeadMonStatsTxt->wSpawnId);
            }
            break;
        }

        switch (nMonId)
        {
        case 0x7F:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x4F, 0);
        LABEL_MODE0:
            sub_00480E70_SetUnitMode(pUnit, 0);
        LABEL_CLEAR:
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        case 0xBE:
            if (pUnit->dwAnimMode == 0xE)
            {
                sub_00480EC0_SetUnitModeNoOverlay(pUnit, 0);
                pUnit->dwFlags &= ~2;
                pUnit->nSeqCurrentFramePrecise = 0xE00;
                sub_00464930_FreeLight(pUnit);
            }
            else
            {
                sub_00480E70_SetUnitMode(pUnit, 0);
                pUnit->dwFlags &= ~2;
                sub_00464930_FreeLight(pUnit);
            }
            break;

        case 0xEE:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x4E, 0);
            goto LABEL_MODE0;

        case 0xF7:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x52, 0);
            goto LABEL_MODE0;

        case 0x6E:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x92, 0);
            sub_00480E70_SetUnitMode(pUnit, 0);
            if (!sub_004DA0F0_GetGfxMotionField3C(pUnit))
                goto LABEL_CLEAR;

            sub_004DA690_ReplaceMotionFlag1With8(pUnit);
            sub_004DA6E0_SetMotionFlag20(pUnit, 0);
            sub_004DA200_SetMotionVectorB(pUnit, 0, 0, -0x10, 1);
            sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0, 0);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        case 0x102:
        case 0x105:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x9D, 0);
            goto LABEL_MODE0;

        case 0x164:
            sub_004C5420_RequestAtTarget(pUnit, 0x148, 0, 1);
            goto LABEL_MODE0;

        case 0x15F:
        case 0x160:
        case 0x161:
            sub_0046F170_RemoveOverlays(pUnit);
            sub_00464E50_SetOverlayWithSound(pUnit, (!pUnit ? -1 : pUnit->dwClassId) - 0xAD, 0);
            goto LABEL_MODE0;

        case 0x11C:
        {
            D2MonCommandStrc tCommand = {};
            tCommand.nParam00 = 0xD8;
            tCommand.nParam10 = 1;
            sub_004AFF60_MonsterCommand(0x15, pUnit, &tCommand);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;
        }

        case 0x76:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xB8, 0);
            goto LABEL_MODE0;

        case 0x136:
        case 0x137:
        case 0x138:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xBB, 0);
            goto LABEL_MODE0;

        case 0xD4:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xBC, 0);
            sub_00464E50_SetOverlayWithSound(pUnit, 0xBD, 0);
            goto LABEL_MODE0;

        case 0x1A1:
        case 0x1A2:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x10F, 0);
            goto LABEL_MODE0;

        case 0x168:
        case 0x22E:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xB9, 0);
            goto LABEL_MODE0;

        case 0x1C5:
        {
            unsigned char nDirection = UNITS_GetDirection(pUnit);
            switch (sub_0063E7A0_GetByteTableEntry(nDirection) % 4)
            {
            case 0:
                sub_004B9A00(0x51C, pUnit, 0, 0, 0);
                break;
            case 1:
                sub_004B9A00(0x51F, pUnit, 0, 0, 0);
                break;
            case 2:
                sub_004B9A00(0x522, pUnit, 0, 0, 0);
                break;
            case 3:
                sub_004B9A00(0x525, pUnit, 0, 0, 0);
                break;
            }
            sub_00480E70_SetUnitMode(pUnit, 0);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;
        }

        case 0x1CD:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xCC, 0);
            sub_004B9A00(0x973, pUnit, 0, 0, 0);
            goto LABEL_MODE0;

        case 0x1A9:
        case 0x1AA:
        case 0x1AB:
            sub_004CDB40_SubmitRequest(pUnit, 0x1D6, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
            sub_00480E70_SetUnitMode(pUnit, 0);
            sub_004B9A00(0x316, pUnit, 0, 0, 0);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        case 0x1F1:
        {
            int nOverlay;
            switch (pUnit->dwClassId)
            {
            case 0x1F1:
            case 0x1F3:
                nOverlay = 0xE1;
                break;
            case 0x1F2:
                nOverlay = 0xE2;
                break;
            default:
                goto LABEL_MODE0;
            }
            sub_00464E50_SetOverlayWithSound(pUnit, nOverlay, 0);
            goto LABEL_MODE0;
        }

        case 0x1D5:
        case 0x1DA:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xE5, 0);
            goto LABEL_MODE0;

        case 0x1B9:
        {
            D2DynamicPathStrc* pDeadPath = pPath;
            D2COMMON_10160_PathUpdateDirection(pDeadPath, (PATH_GetDirection(pDeadPath) + 0x20) % 0x40);
            goto LABEL_MODE0;
        }

        case 0x23A:
            sub_004CDB40_SubmitRequest(pUnit, 0x266, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        case 0x22F:
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags |= 0x20;
            sub_00480E70_SetUnitMode(pUnit, 0xC);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        default:
            goto LABEL_MODE0;
        }
        break;
    }

    case 9:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (!(pMonStats2Txt->nFlags[2] & gdwBitMasks[3]))
            PATH_SetUnitDeadCollision(pUnit, 0);

        STATLIST_SetUnitStat(pUnit, 6, 0, 0);
        if (sub_004648F0_GetPathTargetUnit(pPlayer) == pUnit)
            UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);

        if (nMonId == 0x11C && pUnit->dwAnimMode == 0xE)
        {
            UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0xD8));
        }
        else
        {
            sub_00480E70_SetUnitMode(pUnit, 0xC);
            sub_00464810_SetUnitFlag16(pUnit);
        }

        if (pUnit->dwClassId != 0xD3 && nMonId != 0x1F1 && nMonId != 0x1A1 && nMonId != 0x1A2)
            sub_0046F170_RemoveOverlays(pUnit);

        if (nMonId == 0x1B3)
            sub_00464810_SetUnitFlag16(sub_004CDB40_SubmitRequest(pUnit, 0x1A8, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1));

        switch (nMonId)
        {
        case 0x158:
        case 0x22F:
        case 0x23A:
            pUnit->dwFlagEx |= 0x40000;
            break;
        }

        pUnit->dwFlags &= ~2;
        pUnit->dwFlags |= 0x20;
        if (STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags &= ~4;
            pUnit->dwFlags |= 0x20;
        }

        sub_00464930_FreeLight(pUnit);
        break;
    }

    case 7:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        if (pCommand && pCommand->nParam08)
            STATLIST_SetUnitStat(pUnit, 6, pCommand->nParam08 << 8, 0);

        if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            pUnit->dwFlags |= 2;
        else
            sub_00457460(pUnit, 2, pMonStats2Txt->nFlags[0] & gdwBitMasks[3]);

        sub_00457460(pUnit, 0x20, !(pMonStats2Txt->nFlags[1] & gdwBitMasks[6]));
        sub_004647D0_UpdateAttackableFlag(pUnit);
        if (!pCommand)
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        sub_004804E0_SetPosition(pUnit, (unsigned short)pCommand->nParam00, (unsigned short)pCommand->nParam04, 0, 0, 0);
        if (sub_n5b_Distance(CLIENTS_GetUnitX(pUnit) - pCommand->nParam00) <= 1 && sub_n5b_Distance(CLIENTS_GetUnitY(pUnit) - pCommand->nParam04) <= 1)
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        sub_b1_WalkTo(pUnit, pCommand, 2);
        break;
    }

    case 0x16:
    {
        D2_ASSERT(pCommand, 0x911);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        nValue = pCommand->nParam00;
        SKILLS_AssignSkill(pUnit, nValue, pCommand->nParam10, 0, gszMonsterSourceFile_006DA5C8, 0x914);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nValue);
        UNITS_SetUsedSkill(pUnit, pSkill);
        nValue = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
        if (nValue == 0xE)
            sub_004AFB60_ReplaySequence(pUnit);

        pCommand->nParam04 = -1;
        sub_00480E70_SetUnitMode(pUnit, nValue);
        sub_004C6EB0_StartSkillOnUnit(pUnit, pCommand);
        break;
    }

    case 0x15:
    {
        D2_ASSERT(pCommand, 0x924);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        nValue = pCommand->nParam00;
        SKILLS_AssignSkill(pUnit, nValue, pCommand->nParam10, 0, gszMonsterSourceFile_006DA5C8, 0x929);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nValue);
        UNITS_SetUsedSkill(pUnit, pSkill);
        nValue = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
        if (nValue == 0xE)
            sub_004AFB60_ReplaySequence(pUnit);

        pCommand->nParam04 = -1;
        sub_00480E70_SetUnitMode(pUnit, nValue);
        sub_004C6F40(pUnit, pCommand);
        break;
    }

    default:
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        sub_004AE1D0_RefreshMonsterMode(pUnit);
        break;
    }

    if (bUpdateVelocity && pCommand && pCommand->nParam10)
    {
        const int nVelocity = STATLIST_UnitGetStatValue(pUnit, 0x43, 0);
        if (nVelocity != pCommand->nParam10)
        {
            STATLIST_DeactivateTemporaryStates(pUnit);
            STATLIST_AddUnitStat(pUnit, 0x43, pCommand->nParam10 - nVelocity, 0);
            UNITS_UpdateAnimRateAndVelocity(pUnit, gszMonsterSourceFile_006DA5C8, 0x946);
        }
    }

    sub_004ADE50(pUnit);
    if (sub_n5b_IsTypeFlag1(pUnit))
    {
        if (pUnit->dwAnimMode != 1)
            sub_004AE1D0_RefreshMonsterMode(pUnit);

        if (pPath)
            sub_00648730(pPath);
    }
}

#include "gen/data/Source/D2Client/UNIT/Monster_004AFF60.inc"
