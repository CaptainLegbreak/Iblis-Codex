#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
union D2SeedStrc;
struct D2MonStats2Txt;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2ClientSkillArgsStrc;
struct D2PathDirectionStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);



int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40
int __fastcall sub_004C5E20_CountCallback(void* pArg, D2UnitStrc* pUnit); // 0x004C5E20
extern "C" const char gszEmptyAssertText; // 0x006CC837





typedef int (__fastcall* CLIENTSKILLSTARTFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern CLIENTSKILLSTARTFN gpfnClientSkillStartFuncs_00727A90[]; // 0x00727A90
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464F70
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg); // 0x00480E70
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, int nArg); // 0x004CA4C0
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId); // 0x004CB9C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
int __fastcall sub_00623C20(D2UnitStrc* pUnit); // 0x00623C20
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem); // 0x0062A4E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall sub_00643B00(D2SkillStrc* pSkill, int* pArg2, int* pArg3, int* pSkillLevel, int* pCharges); // 0x00643B00
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, D2PathDirectionStrc tDirection); // 0x00648820
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);
extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs_00727BA8[]; // 0x00727BA8


struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[6];
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern const int gaRingTargetY_006DABC0[64]; // 0x006DABC0
extern const int gaRingTargetX_006DACC0[64]; // 0x006DACC0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

// 0x004C5E30
int __fastcall sub_004C5E30_ScanCount(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags)
{
    int nResult = 0;
    sub_004C5C40_ScanArea(pUnit, nX, nY, nRange, nFlags | 0xA783, sub_004C5E20_CountCallback, &nResult, 0);
    return nResult;
}

static __forceinline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return NULL;
}

static __forceinline D2MonStatsTxt* SKILLCLT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

static __forceinline unsigned int SKILLCLT_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static __forceinline unsigned char SKILLCLT_GetUnitTypeByte(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType;
}

static __forceinline int SKILLCLT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

static __forceinline void SKILLCLT_SetCastState(D2UnitStrc* pUnit)
{
    if (pUnit && (pUnit->dwUnitType == 0 || pUnit->dwUnitType == 1))
    {
        sub_00480E70_SetState(pUnit, 1);
    }
}

static __declspec(noinline) int sub_004C5710_GetAttackMode(D2UnitStrc* pUnit)
{
    int nMode = 7;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    int bRandom = 1;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        const char nType = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId)->nType;
        if (nType == 2)
        {
            bRandom = 0;
            nMode = 8;
        }
        if (nType == 1)
        {
            bRandom = 0;
        }
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        nMode = 7;
        bRandom = 0;
    }

    D2UnitStrc* pWeapon;
    int nBodyLoc;
    int bIsLeftHand;
    if (!INVENTORY_GetEquippedWeapon(pUnit->pInventory, &pWeapon, &nBodyLoc, &bIsLeftHand))
    {
        return 7;
    }

    if (bRandom)
    {
        const char nRoll = SKILLCLT_RollSeed(&pUnit->pSeed) & 0x3F;
        if (nRoll < 0x20)
        {
            return 8;
        }
    }

    return nMode;
}

static __declspec(noinline) int sub_004C58A0_CheckTarget(D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 21) && SKILLCLT_GetUnitType(pTarget) == 1 && pTarget->dwAnimMode == 12)
    {
        return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 24) != 0;
    }

    return 1;
}

static __declspec(noinline) int __stdcall sub_004C6140_StartSkill(int nOwnerGUID, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    int nItemSkillArg;
    if (pSkillsTxtRecord->nLineOfSight && sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1:
            nCollisionMask = 4;
            break;
        case 2:
            nCollisionMask = 0x1C09;
            break;
        case 3:
            nCollisionMask = 0x180;
            break;
        case 4:
            nCollisionMask = 0x804;
            break;
        case 5:
            nCollisionMask = 0x805;
            break;
        default:
            return 0;
        }

        if (!sub_00645950_CheckTargetPos(nX, nY, pUnit, nCollisionMask))
        {
            return 0;
        }
    }

    if (!sub_004C58A0_CheckTarget(pUnit, nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x504) != nSkillId)
    {
        pSkill = SKILLS_GetSkill(pUnit, nSkillId, nOwnerGUID);
        if (!pSkill)
        {
            SKILLS_AddSkill(pUnit, nSkillId);
            pSkill = SKILLS_GetSkill(pUnit, nSkillId, nOwnerGUID);
            if (pSkill && pUnit == sub_00463DD0() && nOwnerGUID == -1)
            {
                SKILLS_SetFlags(pSkill, 8);
            }

            const int nMaxLevel = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
            if (nSkillLevel > nMaxLevel)
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x513);
                sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
            }
            else
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x518);
            }

            if (!pSkill)
            {
                return 0;
            }
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }

    if (nOwnerGUID != -1)
    {
        if (!sub_00643B00(pSkill, &nItemSkillArg, &nY, &nSkillLevel, &nX) || !nX)
        {
            return 0;
        }
    }

    if (pUnit != sub_00463DD0())
    {
        const int nMaxLevel = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
        if (nSkillLevel > nMaxLevel)
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53A);
            sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
        }
        else
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53F);
        }
    }
    else
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget && !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26) && sub_00464F70_IsTargetBlocked(pUnit, pTarget))
    {
        return 0;
    }

    if (!BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 8) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        UNITS_SetUsedSkill(pUnit, NULL);
        int aArgs[7] = { 0, 0, 0, 0, 0, 0, 0 };
        sub_00480C10_UnitEvent(7, pUnit, aArgs, 0);
        if (pUnit == sub_00463DD0())
        {
            sub_004CB9C0_Request(pUnit, 0x18);
        }
        return 0;
    }

    int nMode;
    if (pUnit && !SKILLCLT_GetUnitTypeByte(pUnit) && !nSkillId)
    {
        nMode = sub_004C5710_GetAttackMode(pUnit);
    }
    else
    {
        nMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    }

    if (nMode)
    {
        sub_00480E70_SetState(pUnit, nMode);
    }
    else if (!STATES_CheckState(pUnit, 12) || !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 11))
    {
        SKILLCLT_SetCastState(pUnit);
    }

    nY = 1;
    const short nStartFunc = pSkillsTxtRecord->wStartFunc;
    if (nStartFunc >= 0 && nStartFunc < gnClientSkillStartFuncs_00727A8C && gpfnClientSkillStartFuncs_00727A90[nStartFunc])
    {
        nY = gpfnClientSkillStartFuncs_00727A90[nStartFunc](pUnit, nSkillId, nSkillLevel);
        if (!nY)
        {
            UNITS_SetUsedSkill(pUnit, NULL);
            SKILLCLT_SetCastState(pUnit);
            if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 12))
            {
                return nY;
            }
        }
    }

    short nSound = pSkillsTxtRecord->wStSound;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemStartSound > 0)
    {
        nSound = pSkillsTxtRecord->wItemStartSound;
    }

    if (nSound > 0)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = sub_00623C20(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nDelay = sub_004CA500_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nSound, pUnit, 0, 0, 0);
        }
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 14))
    {
        const int nSoundId = sub_004CA4C0(pUnit, sub_00623C20(pUnit));
        if (nSoundId)
        {
            const int nDirection = sub_00623C20(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nRate = sub_004CA500_GetAnimRate(pUnit, nDirection);
            sub_004B9A00(nSoundId, pUnit, nRate, 0, 0);
        }
    }

    const short nClassSound = pSkillsTxtRecord->wStartSoundClass;
    if ((nOwnerGUID == -1 || pSkillsTxtRecord->wItemStartSound <= 0) && nClassSound > 0 && pUnit && pUnit->dwUnitType == 0 && pUnit->dwClassId == pSkillsTxtRecord->nCharClass)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = sub_00623C20(pUnit);
            sub_004CA500_GetAnimRate(pUnit, nDirection);
            const int nDelay = sub_004CA500_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nClassSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nClassSound, pUnit, 0, 0, 0);
        }
    }

    int nOverlay = pSkillsTxtRecord->wCastOverlay;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemCastOverlay > 0)
    {
        nOverlay = pSkillsTxtRecord->wItemCastOverlay;
    }

    if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount && !sub_0046E100(pUnit, nOverlay))
    {
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

    if (nY && pSkillsTxtRecord->wAuraFunc > 0)
    {
        sub_004C5680_StartAura(pUnit, pSkillsTxtRecord->wAuraFunc);
    }

    return nY;
}

// 0x004C6660
int __fastcall sub_004C6660_StartSkillWrapper(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID)
{
    return sub_004C6140_StartSkill(nOwnerGUID, nSkillLevel, pUnit, nSkillId);
}

static __declspec(noinline) void __stdcall sub_004C6DE0_SwapDualWieldSkill(D2ClientSkillArgsStrc* pArgs, D2UnitStrc* pUnit)
{
    if (pArgs->nSkillId != 0)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightHand = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pRightHand && (!sub_0062A4E0_TestItem(pRightHand) || ITEMS_GetItemType(pRightHand) == 0x26))
    {
        pRightHand = NULL;
    }

    D2UnitStrc* pLeftHand = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pLeftHand && (!sub_0062A4E0_TestItem(pLeftHand) || ITEMS_GetItemType(pLeftHand) == 0x26))
    {
        pLeftHand = NULL;
    }

    if (ITEMSIsA(pRightHand, 0x2D) && ITEMSIsA(pLeftHand, 0x2D))
    {
        D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, 0, -1);
        if (!SKILLS_GetParam4(pSkill))
        {
            pArgs->nSkillId = 5;
            SKILLS_SetParam4(pSkill, 5);
            pSkill = SKILLS_GetSkill(pUnit, 5, -1);
            UNITS_SetUsedSkill(pUnit, pSkill);
        }
        else
        {
            SKILLS_SetParam4(pSkill, 0);
            UNITS_SetUsedSkill(pUnit, pSkill);
        }
    }
}

int __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    if (UNITS_CanDualWield(pUnit) && (!pUnit || pUnit->dwUnitType != 1))
    {
        sub_004C6DE0_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2UnitStrc* pTarget = sub_00463990(pArgs->nArg2, pArgs->nArg1);
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        sub_00465BF0(pUnit, 0);
        return sub_004C6140_StartSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
    }

    sub_00480C10_UnitEvent(7, pUnit, NULL, 0);
    sub_006248E0_Log(1, 2, 4, 0x40, ".\\SKILLS\\Skills.cpp", 0x7C2, "StartsStartSkillID - Invalid Target");
    return 0;
}

int __fastcall sub_004C6F40_StartSkillAtPos(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    const int nX = pArgs->nArg1;
    const int nY = pArgs->nArg2;
    if (UNITS_CanDualWield(pUnit))
    {
        sub_004C6DE0_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    sub_00621C00_SetTargetPos(pUnit, nX, nY);
    if (pUnit->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SKILLCLT_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->dwCode == 0x20204250)
        {
            D2PathDirectionStrc tDirection;
            tDirection.nDirection = (PATH_GetNewDirection(pUnit->pDynamicPath) + 0x38) % 64;
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, tDirection);
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, NULL);
    return sub_004C6140_StartSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C6930
void __fastcall sub_004C6930_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nOldValue = pUnit->dwInitSeed;
    int nTargetX;
    int nTargetY;
    const int bHasTargetPos = sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY);
    D2UnitStrc* pOldTarget = sub_004648F0_GetTargetUnit(pUnit);

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        pUnit->dwInitSeed = nMode;
    }
    else if (nX && nY)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
        pUnit->dwInitSeed = nMode;
    }

    if (nX && !nY)
    {
        pUnit->dwInitSeed = nX;
    }

    const short nFunc = pSkillsTxtRecord->wCltPrgFunc[0];
    if (nFunc >= 0 && nFunc < gnClientSkillDoFuncs_00727DB0 && gpfnClientSkillDoFuncs_00727BA8[nFunc]
        && gpfnClientSkillDoFuncs_00727BA8[nFunc](pUnit, nSkillId, nSkillLevel))
    {
        if (pSkillsTxtRecord->wDoSound > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSound, pUnit, 0, 0, 0);
        }

        if (pSkillsTxtRecord->wTgtSound > 0)
        {
            D2UnitStrc* pCurrentTarget = sub_004648F0_GetTargetUnit(pUnit);
            if (pCurrentTarget)
            {
                sub_004B9A00(pSkillsTxtRecord->wTgtSound, pCurrentTarget, 0, 0, 0);
            }
        }

        if (pSkillsTxtRecord->wTgtOverlay > 0)
        {
            D2UnitStrc* pCurrentTarget = sub_004648F0_GetTargetUnit(pUnit);
            if (pCurrentTarget)
            {
                sub_00470390(pCurrentTarget, pSkillsTxtRecord->wTgtOverlay, 2, 0, 0, 0, 0, 0);
            }
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    if (bHasTargetPos && !pOldTarget)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
    }

    pUnit->dwInitSeed = nOldValue;
}

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x004C7000
static void __stdcall sub_004C7000_SpawnRing(D2MissileStrc* pAltParams, D2MissileStrc* pParams)
{
    if (pAltParams)
    {
        for (int i = 0; i < 64; ++i)
        {
            if (SEED_RollRandomNumber(&pParams->pOwner->pSeed) % 6)
            {
                pParams->nTargetX = gaRingTargetX_006DACC0[i];
                pParams->nTargetY = gaRingTargetY_006DABC0[i];
                sub_004CD540_CreateMissile(pParams);
            }
            else
            {
                pAltParams->nTargetX = gaRingTargetX_006DACC0[i];
                pAltParams->nTargetY = gaRingTargetY_006DABC0[i];
                sub_004CD540_CreateMissile(pAltParams);
            }
        }
    }
    else
    {
        for (int i = 0; i < 64; ++i)
        {
            pParams->nTargetX = gaRingTargetX_006DACC0[i];
            pParams->nTargetY = gaRingTargetY_006DABC0[i];
            if (pParams->nMissile == 0xB0)
                pParams->dwFlags ^= 0x4000;
            sub_004CD540_CreateMissile(pParams);
        }
    }
}

// 0x004C70D0
void __fastcall sub_004C70D0_StartUnitEffect(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nAltMissile,
    int nSkill, int nSkillLevel, int nVelocity)
{
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.nX = UNITS_GetUnitXPosition(pUnit);
    tParams.nY = UNITS_GetUnitYPosition(pUnit);
    tParams.nMissile = nMissile;
    tParams.pOwner = pOwner;
    tParams.nSkill = nSkill;
    tParams.nSkillLevel = nSkillLevel;
    if (nVelocity)
    {
        tParams.dwFlags |= 4;
        tParams.nVelocity = nVelocity;
    }
    if (nAltMissile == -1)
    {
        sub_004C7000_SpawnRing(0, &tParams);
        return;
    }
    D2MissileStrc tAltParams = tParams;
    tAltParams.nMissile = nAltMissile;
    sub_004C7000_SpawnRing(&tAltParams, &tParams);
}

#include "gen/data/Source/D2Client/SKILLS/Skills_004C5E30.inc"
