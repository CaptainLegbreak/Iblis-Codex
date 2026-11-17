struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2AnimDataRecordStrc
{
    char unk0x00[0x0C];
    unsigned int dwAnimSpeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x0C];
    int dwSeqSpeed;
    char unk0x40[0x0C];
    short wAnimSpeed;
    char unk0x4E[0x02];
    D2AnimDataRecordStrc* pAnimData;
    char unk0x54[0x0C];
    D2InventoryStrc* pInventory;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x22];
    short wVelocity;
    char unk0x34[0x02];
    short nWalkAnimSpeed;
    short nRunAnimSpeed;
    char unk0x3A[0x16E];
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    char unk0x41[0x83];
};

struct D2SkillsTxt
{
    char unk0x00[0x12];
    char nSeqTrans;
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x140];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

struct D2AnimModeModulatorStrc
{
    int bCanUseVelocityModifierByPassiveSkill;
    int bCanUseVelocityModifier;
    int bCanUseSkillAttackRate;
    int bCanUseAttackRate;
    int bAllowAnimSpeed;
};

struct D2AnimModeStatBasePercentageStrc
{
    int bHasBasePercentage;
    int nBasePercentage;
    int nStatId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2AnimModeModulatorStrc gaPlayerModesAnimModulators_006E8A00[];                                      // 0x006E8A00
extern D2AnimModeModulatorStrc gaMonModesAnimModulators_006E8B90[];                                         // 0x006E8B90
extern D2AnimModeModulatorStrc gaMonModesAnimModulatorsExpansion_006E8CD0[];                                // 0x006E8CD0
extern D2AnimModeStatBasePercentageStrc gaAnimModeStatBasePercentage_006E8E24[];                            // 0x006E8E24
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall sub_00620F00(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nAnimMode);     // 0x00620F00
int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId);// 0x00621580
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int bSet);                            // 0x00623C80
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine);// 0x00645270
unsigned int __stdcall D2Common_11043(D2UnitStrc* pUnit);                                                   // 0x00646170
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine);// 0x00648690

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nCharId)
{
    if (nCharId >= 0 && nCharId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nCharId];
    }

    return 0;
}

static __forceinline int UNITS_IsAnimModeBlocking_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 9;
        break;
    case 1:
        nMode = 6;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline int UNITS_IsAnimModeGetHit_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 4;
        break;
    case 1:
        nMode = 3;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline int UNITS_IsAnimModeKnockBack_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 0x13;
        break;
    case 1:
        nMode = 0xD;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline void UNITS_SetAnimationSpeed_Inl(D2UnitStrc* pUnit, int nSpeed)
{
    int nAnimSpeed = nSpeed > 0 ? nSpeed : 0;
    if (nAnimSpeed >= 0x7FFF)
    {
        nAnimSpeed = 0x7FFF;
    }

    pUnit->wAnimSpeed = (short)nAnimSpeed;
}

// 0x00621360
static int UNITS_GetBaseVelocity(int nUnitType, int nClassId)
{
    switch (nUnitType)
    {
    case 0:
        return DATATBLS_GetCharStatsTxtRecord_Inl(nClassId)->nWalkSpeed << 8;
    case 1:
        return DATATBLS_GetMonStatsTxtRecord_Inl(nClassId)->wVelocity << 8;
    }

    return 0;
}

// 0x006213D0
static int UNITS_GetBaseAnimSpeed(int nUnitType, int nClassId, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        return nAnimMode == 3 ? 0x65 : 0xD5;
    case 1:
    {
        const D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId);
        if (nAnimMode != 0xF)
        {
            return pMonStatsTxtRecord->nWalkAnimSpeed;
        }

        return pMonStatsTxtRecord->nRunAnimSpeed;
    }
    }

    return 0;
}

static __forceinline unsigned int DATATBLS_CheckMonStatsFlag_Inl(D2MonStatsTxt* pMonStatsTxtRecord)
{
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }

    return 0;
}

static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimModeModulatorStrc* pAnimModeModulators;
    switch (nUnitType)
    {
    case 0:
        pAnimModeModulators = &gaPlayerModesAnimModulators_006E8A00[nAnimMode];
        break;
    case 1:
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId))
        {
            if (DATATBLS_CheckMonStatsFlag_Inl(pMonStatsTxtRecord))
            {
                switch (nAnimMode)
                {
                case 2:
                case 0xF:
                    return 1;
                }

                return 0;
            }
        }

        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }
        break;
    default:
        D2_ASSERT(nUnitType == 0 || nUnitType == 1, 0xBD2);
        return 0;
    }

    if (pAnimModeModulators->bCanUseVelocityModifier)
    {
        return 1;
    }

    if (pAnimModeModulators->bCanUseVelocityModifierByPassiveSkill)
    {
        if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
        {
            const int nFlags = SKILLS_GetFlags(pUsedSkill);
            if ((nFlags & 1) && !(nFlags & 0x1000))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00621630
static int __stdcall UNITS_AnimModeAllowsAnimSpeed(int nUnitType, int nAnimMode, int nClassId)
{
    switch (nUnitType)
    {
    case 0:
        return gaPlayerModesAnimModulators_006E8A00[nAnimMode].bAllowAnimSpeed;
    case 1:
    {
        D2AnimModeModulatorStrc* pAnimModeModulators;
        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }

        return pAnimModeModulators->bAllowAnimSpeed;
    }
    }

    return 0;
}

// 0x006216E0
static int UNITS_IsSeqAnimSpeedModulatedByFCR(int nAnimMode, int nUnitType, D2UnitStrc* pUnit)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0xA)
        {
            return 1;
        }

        if (nAnimMode == 0x12 && pUnit)
        {
            if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\UNITS\\Units.cpp", 0xC48));
                if (pSkillsTxtRecord && pSkillsTxtRecord->nSeqTrans == 0xA)
                {
                    return 1;
                }
            }
        }

        break;
    case 1:
        if (nAnimMode == 7)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00621740
static int UNITS_GetAnimStatBasePercentage(D2UnitStrc* pUnit, int nStat)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, gaAnimModeStatBasePercentage_006E8E24[nStat].nStatId, 0);
    switch (gaAnimModeStatBasePercentage_006E8E24[nStat].bHasBasePercentage)
    {
    case 1:
        if (nValue)
        {
            return nValue * gaAnimModeStatBasePercentage_006E8E24[nStat].nBasePercentage / (nValue + gaAnimModeStatBasePercentage_006E8E24[nStat].nBasePercentage);
        }
        break;
    }

    return nValue;
}

void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine)
{
    if (!pUnit)
    {
        return;
    }

    int nUnitType = pUnit->dwUnitType;
    if (nUnitType >= 5)
    {
        return;
    }

    if (nUnitType == 4)
    {
        return;
    }

    int nClassId = pUnit->dwClassId;
    int nAnimMode = pUnit->dwAnimMode;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nAnimMode, ".\\UNITS\\Units.cpp", 0xCB9);
    sub_00620F00(pUnit, nUnitType, nClassId, nAnimMode);
    D2AnimDataRecordStrc* pAnimData = pUnit->pAnimData;

    if (UNITS_IsSeqAnimSpeedModulatedByFCR(nAnimMode, nUnitType, pUnit))
    {
        int nRate = UNITS_GetAnimStatBasePercentage(pUnit, 2) + 0x64;
        if (nRate > 0xAF)
        {
            nRate = 0xAF;
        }

        UNITS_SetAnimationSpeed_Inl(pUnit, nRate * pAnimData->dwAnimSpeed / 100);
        pUnit->dwSeqSpeed = pUnit->wAnimSpeed;
        return;
    }

    if (UNITS_IsAnimModeBlocking_Inl(nUnitType, nAnimMode))
    {
        const int nFasterBlockRate = UNITS_GetAnimStatBasePercentage(pUnit, 3);
        int nBlockRateBonus = 0x32;
        if (STATES_CheckState(pUnit, 0x65))
        {
            nBlockRateBonus = 0x64;
        }

        unsigned int nAnimSpeed = pAnimData->dwAnimSpeed * (nBlockRateBonus + nFasterBlockRate) / 100;
        if (nAnimSpeed < 1)
        {
            nAnimSpeed = 1;
        }

        UNITS_SetAnimationSpeed_Inl(pUnit, nAnimSpeed);
        return;
    }

    if (UNITS_IsAnimModeGetHit_Inl(nUnitType, nAnimMode))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, pAnimData->dwAnimSpeed * (UNITS_GetAnimStatBasePercentage(pUnit, 1) + 0x32) / 100);
        return;
    }

    if (UNITS_IsAnimModeKnockBack_Inl(nUnitType, nAnimMode))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, UNITS_GetBaseAnimSpeed(nUnitType, nClassId, nAnimMode));
        PATH_SetVelocity(pUnit->pDynamicPath, 0x1000, ".\\UNITS\\Units.cpp", 0xCE9);
        return;
    }

    if (UNITS_CanAnimModeUseVelocityModifier(nUnitType, nAnimMode, pUnit, nClassId))
    {
        if (pUnit->pDynamicPath)
        {
            const int nFasterMoveVelocity = UNITS_GetAnimStatBasePercentage(pUnit, 4);
            int nVelocityPercent = nFasterMoveVelocity + STATLIST_UnitGetStatValue(pUnit, 0x43, 0);
            if (nVelocityPercent < 0x19)
            {
                nVelocityPercent = 0x19;
            }

            UNITS_SetAnimationSpeed_Inl(pUnit, nVelocityPercent * UNITS_GetBaseAnimSpeed(nUnitType, nClassId, nAnimMode) / 100);
            PATH_SetVelocity(pUnit->pDynamicPath, nVelocityPercent * UNITS_GetBaseVelocity(nUnitType, nClassId) / 100, ".\\UNITS\\Units.cpp", 0xD0A);
        }
        return;
    }

    if (UNITS_CanAnimModeUseAttackRate(nAnimMode, nUnitType, pUnit, nClassId))
    {
        UNITS_MergeDualWieldWeaponStatLists(pUnit, 1);
        const int nFasterAttackRate = UNITS_GetAnimStatBasePercentage(pUnit, 0);
        int nRate = nFasterAttackRate + STATLIST_UnitGetStatValue(pUnit, 0x44, 0);
        if (UNITS_CanDualWield(pUnit))
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            if (!sub_0062A4E0_TestItem(pRightWeapon))
            {
                pRightWeapon = 0;
            }

            D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            if (!sub_0062A4E0_TestItem(pLeftWeapon))
            {
                pLeftWeapon = 0;
            }

            if (ITEMS_CheckItemTypeId(pRightWeapon, 0x2D) && ITEMS_CheckItemTypeId(pLeftWeapon, 0x2D))
            {
                const int nRightAttackRate = STATLIST_UnitGetStatValue(pRightWeapon, 0x44, 0);
                const int nLeftAttackRate = STATLIST_UnitGetStatValue(pLeftWeapon, 0x44, 0);
                nRate += (nRightAttackRate + nLeftAttackRate) / 2 - nRightAttackRate;
            }
        }

        if (!pUnit->dwUnitType && pUnit->dwAnimMode == 0x12)
        {
            nRate -= 0x1E;
        }

        if (nRate < 0xF)
        {
            nRate = 0xF;
        }
        else if (nRate > 0xAF)
        {
            nRate = 0xAF;
        }

        unsigned int nBaseSpeed = 0;
        if (STATES_CheckStateMaskOnUnit(pUnit, 0x26))
        {
            nBaseSpeed = D2Common_11043(pUnit);
        }

        if (!nBaseSpeed)
        {
            nBaseSpeed = pAnimData->dwAnimSpeed;
        }

        int nAnimSpeed = nRate * nBaseSpeed / 100;
        nAnimSpeed = nAnimSpeed > 0 ? nAnimSpeed : 0;
        if (nAnimSpeed >= 0x7FFF)
        {
            nAnimSpeed = 0x7FFF;
        }

        pUnit->dwSeqSpeed = (short)nAnimSpeed;
        pUnit->wAnimSpeed = (short)nAnimSpeed;
        return;
    }

    if (UNITS_AnimModeAllowsAnimSpeed(nUnitType, nAnimMode, nClassId))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, pAnimData->dwAnimSpeed);
        return;
    }

    int nOtherAnimRate = STATLIST_UnitGetStatValue(pUnit, 0x45, 0);
    if (nOtherAnimRate < 0xF)
    {
        nOtherAnimRate = 0xF;
    }
    else if (nOtherAnimRate > 0xAF)
    {
        nOtherAnimRate = 0xAF;
    }

    UNITS_SetAnimationSpeed_Inl(pUnit, nOtherAnimRate * pAnimData->dwAnimSpeed / 100);
}

#include "gen/data/Source/D2Common/00621360_UNITS_GetBaseVelocity.inc"
