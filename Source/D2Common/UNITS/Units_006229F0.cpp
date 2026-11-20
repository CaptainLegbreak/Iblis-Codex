#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
struct D2InventoryStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2AnimDataRecordStrc;
struct D2MonStatsTxt;
struct D2CharStatsTxt;
struct D2SkillsTxt;
struct D2AnimModeModulatorStrc;
struct D2AnimModeStatBasePercentageStrc;
union D2SeedStrc;
struct D2ObjectsTxt;
struct D2MissilesTxt;





int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit); // 0x006209D0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
static __declspec(noinline) int __stdcall sub_00622920_RayTraceBetweenBoxes(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask);

struct D2AnimDataRecordStrc
{
    char unk0x00[0x08];
    int dwFramesPerDirection;
    unsigned int dwAnimSpeed;
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
    unsigned char nRunSpeed;
    char unk0x42[0x82];
};

struct D2SkillsTxt
{
    char unk0x00[0x12];
    char nSeqTrans;
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2AnimModeModulatorStrc gaPlayerModesAnimModulators_006E8A00[]; // 0x006E8A00
extern D2AnimModeModulatorStrc gaMonModesAnimModulators_006E8B90[]; // 0x006E8B90
extern D2AnimModeModulatorStrc gaMonModesAnimModulatorsExpansion_006E8CD0[]; // 0x006E8CD0
extern D2AnimModeStatBasePercentageStrc gaAnimModeStatBasePercentage_006E8E24[]; // 0x006E8E24
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId); // 0x00621580
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int bSet); // 0x00623C80
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
unsigned int __stdcall D2Common_11043(D2UnitStrc* pUnit); // 0x00646170
static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId); // 0x006214A0

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    int dwFrameCnt[8];
    short nFrameDelta[8];
    char unk0x108[0x21];
    unsigned char nStart[8];
    char unk0x131[0x44];
    unsigned char nSync;
};

struct D2MissilesTxt
{
    char unk0x00[0xA0];
    short nAnimLen_2;
    char unk0xA2[0xD6];
    unsigned char nAnimLen;
};

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x006270B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall sub_00623B10_GetStartFrame(D2UnitStrc* pUnit); // 0x00623B10
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit); // 0x00621260
void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x00623F50
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
static __declspec(noinline) void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId);

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static int __stdcall sub_00622920_RayTraceBetweenBoxes(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask)
{
    COLLISION_RayTrace((D2ActiveRoomStrc*)nSize2, (D2CoordStrc*)nX1, (D2CoordStrc*)nX2, 0);
    return COLLISION_RayTrace(pRoom, (D2CoordStrc*)nY1, (D2CoordStrc*)nSize1, nY2 + nCollisionMask);
}

// 0x006229F0
int __stdcall sub_006229F0_IsRayFreeFromUnit(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask)
{
    if (!pUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nUnitX = UNITS_GetXPositionForceInl(pUnit);
    const int nUnitY = UNITS_GetYPositionForceInl(pUnit);
    const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
    return sub_00622920_RayTraceBetweenBoxes(nUnitX, nUnitY, nUnitSize, nX, nY, 2, pRoom, nCollisionMask);
}

// 0x00622B50
int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask)
{
    if (!pUnit1 || !pUnit2)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    if (!pRoom)
    {
        return 0;
    }

    const int nX1 = CLIENTS_GetUnitX(pUnit1);
    const int nY1 = CLIENTS_GetUnitY(pUnit1);
    const int nX2 = CLIENTS_GetUnitX(pUnit2);
    const int nY2 = CLIENTS_GetUnitY(pUnit2);
    int bRemoved1 = 0;
    int bRemoved2 = 0;
    if (UNITS_GetCollisionMask(pUnit1) & nCollisionMask)
    {
        bRemoved1 = PATH_RemoveCollisionFootprintForUnit(pUnit1, 0);
    }

    if (UNITS_GetCollisionMask(pUnit2) & nCollisionMask)
    {
        bRemoved2 = PATH_RemoveCollisionFootprintForUnit(pUnit2, 0);
    }

    const int nResult = sub_00622920_RayTraceBetweenBoxes(nX1, nY1, UNITS_GetUnitSizeX(pUnit1), nX2, nY2, UNITS_GetUnitSizeX(pUnit2), pRoom, nCollisionMask);
    if (bRemoved1)
    {
        PATH_AddCollisionFootprintForUnit(pUnit1);
    }

    if (bRemoved2)
    {
        PATH_AddCollisionFootprintForUnit(pUnit2);
    }

    return nResult;
}

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
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 9) return 1;
        break;
    case 1:
        if (nAnimMode == 6) return 1;
        break;
    }
    return 0;
}

static __forceinline int UNITS_IsAnimModeGetHit_Inl(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 4) return 1;
        break;
    case 1:
        if (nAnimMode == 3) return 1;
        break;
    }
    return 0;
}

static __forceinline int UNITS_IsAnimModeKnockBack_Inl(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0x13) return 1;
        break;
    case 1:
        if (nAnimMode == 0xD) return 1;
        break;
    }
    return 0;
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
static int __stdcall UNITS_GetBaseVelocity(int nUnitType, int nClassId)
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

// build: context UNITS_CanAnimModeUseVelocityModifier
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
static int UNITS_IsSeqAnimSpeedModulatedByFCR(int nUnitType, int nAnimMode, D2UnitStrc* pUnit)
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

// 0x00623F50
void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine)
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

    if (UNITS_IsSeqAnimSpeedModulatedByFCR(nUnitType, nAnimMode, pUnit))
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

        nBlockRateBonus += nFasterBlockRate;
        UNITS_SetAnimationSpeed_Inl(pUnit, D2_MAX(1u, pAnimData->dwAnimSpeed * nBlockRateBonus / 100));
        return;
    }

    if (UNITS_IsAnimModeGetHit_Inl(nUnitType, nAnimMode))
    {
        const int nRate = UNITS_GetAnimStatBasePercentage(pUnit, 1) + 0x32;
        UNITS_SetAnimationSpeed_Inl(pUnit, nRate * pAnimData->dwAnimSpeed / 100);
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

            if (ITEMSIsA(pRightWeapon, 0x2D) && ITEMSIsA(pLeftWeapon, 0x2D))
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

// 0x00620E80
static void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    D2CharStatsTxt* pCharStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
    const int nWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    if (nWalkSpeed)
    {
        sub_006270B0(pStatList, 0x43, 100 * pCharStatsTxtRecord->nRunSpeed / nWalkSpeed - 100, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

static __forceinline int UNITS_ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x00624390
int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0x951);

    ptUnit->nActionFrame = 0;
    ptUnit->nSeqCurrentFramePrecise = sub_00623B10_GetStartFrame(ptUnit) << 8;

    int nUnitType = ptUnit->dwUnitType;
    int nMode = ptUnit->dwAnimMode;
    int nClassId = ptUnit->dwClassId;
    D2COMMON_11013_ConvertMode(ptUnit, &nUnitType, &nClassId, &nMode, ".\\UNITS\\Units.cpp", 0x958);

    switch (nUnitType)
    {
    case 0:
        if (nMode == 3 || nMode == 0x13)
        {
            UNITS_CharacterStartRunningOrKnockback(ptUnit, nClassId);
        }

        if (nMode == 0x12)
        {
            UNITS_InitializeSequence(ptUnit);
            UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x967);
            return 1;
        }

        ptUnit->pAnimSeq = 0;
        UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x96A);
        ptUnit->dwFrameCountPrecise = ptUnit->pAnimData->dwFramesPerDirection << 8;
        return 1;

    case 1:
        if (ptUnit->dwUnitType == 0 && STATES_IsUnitShapeShifted(ptUnit))
        {
            switch (nMode)
            {
            case 0xD:
            case 0xF:
                UNITS_CharacterStartRunningOrKnockback(ptUnit, ptUnit->dwClassId);
                break;
            }
        }

        if (nMode == 0xE)
        {
            UNITS_InitializeSequence(ptUnit);
            UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x97E);
            return 1;
        }

        UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x980);
        ptUnit->pAnimSeq = 0;
        ptUnit->dwFrameCountPrecise = ptUnit->pAnimData->dwFramesPerDirection << 8;
        return 1;

    case 2:
    {
        const int nNewMode = nMode;
        D2_ASSERT(nNewMode < 8, 0x98A);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(ptUnit->dwClassId);
        ptUnit->dwFrameCountPrecise = pObjectsTxtRecord->dwFrameCnt[nNewMode];
        const int nStartFrame = pObjectsTxtRecord->nStart[nNewMode] << 8;
        short nAnimSpeed = pObjectsTxtRecord->nFrameDelta[nNewMode];
        ptUnit->nSeqCurrentFramePrecise = nStartFrame;
        if (pObjectsTxtRecord->nSync)
        {
            ptUnit->wAnimSpeed = nAnimSpeed;
            return 1;
        }

        int nSpeed = ITEMS_RollLimitedRandomNumber(&ptUnit->pSeed, nAnimSpeed >> 3) + nAnimSpeed - (short)(nAnimSpeed >> 4);
        nSpeed = nSpeed <= 0 ? 0 : nSpeed;
        if (nSpeed >= 0x7FFF)
        {
            nSpeed = 0x7FFF;
        }
        ptUnit->wAnimSpeed = nSpeed;
        return 1;
    }

    case 4:
        switch (nMode)
        {
        case 5:
            ptUnit->wAnimSpeed = 0x100;
            ptUnit->dwFrameCountPrecise = 0x1100;
            return 1;

        case 3:
            ptUnit->wAnimSpeed = 0;
            ptUnit->dwFrameCountPrecise = 0x1100;
            ptUnit->nSeqCurrentFramePrecise = 0x1000;
            return 1;
        }
        break;

    case 3:
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(ptUnit->dwClassId);
        if (!pMissilesTxtRecord)
        {
            return 0;
        }

        ptUnit->wAnimSpeed = UNITS_ApplyRatio_Inline(256, pMissilesTxtRecord->nAnimLen_2, 1024);
        ptUnit->dwFrameCountPrecise = pMissilesTxtRecord->nAnimLen << 8;
        break;
    }
    }

    return 1;
}
