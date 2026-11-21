#include "D2Client.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2TxtItems.h"

#define UNIT_ITEM 4
struct D2StaticPathStrc;
struct D2GfxLightStrc;
struct D2SkillDescTxt;
struct D2MissilesTxt;
struct Unicode;
struct D2SkillsTxt;
struct D2MissileStrc;
union D2SeedStrc;
struct D2MonsterDataStrc;
struct T00481920;
struct D2MonTypeTxt;
struct D2ItemStatCostTxt;
struct D2MonStatsTxt;
struct D2MonSoundsTxt;
struct D2DifficultyLevelsTxt;






typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

enum
{
    SKILLDO_FRAME_A = 6,
    SKILLDO_FRAME_A_SET = 7,
    SKILLDO_FRAME_A_COUNT = 0x3200,
    SKILLDO_FRAME_B = 22,
    SKILLDO_REPEATS = 4,
    SKILLDO_FRAME_B_SET = 40,
    SKILLDO_FRAME_B_COUNT = 0x1100,
    SKILLDO_FRAME_C = 30,
    SKILLDO_FRAME_C_STATE = 12,
    PATHINIT_MAX_FRAMES = 78,
    PATHINIT_CAP_FRAMES = 77,
    PATHTYPE_CHARGEDBOLT = 10,
};

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit); // 0x00464810
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue); // 0x00645F00
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __fastcall sub_004C21E0_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004E3050
void __fastcall sub_004E3170_SetMissileFrames(D2UnitStrc* pMissile, int nDivisor); // 0x004E3170
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __fastcall sub_004C53D0_ScaleDownDirection(int* pX, int* pY); // 0x004C53D0
int __fastcall sub_004C5EB0_ScanFind(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, int nArg, int* pOut); // 0x004C5EB0
void __fastcall sub_004C70D0_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
int __fastcall sub_004C7700(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel); // 0x004C7700
int __fastcall sub_004C7B20(D2UnitStrc* pUnit, int nMissile); // 0x004C7B20
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350
void __fastcall sub_004E2ED0_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset); // 0x004E2ED0
int __fastcall sub_004F16F0_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nMissile, int nSkillId, int nSkillLevel, int nArg6, int nArg7, int nArg8); // 0x004F16F0
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634

typedef char check_scalar_width[(sizeof(U32) == 4 && sizeof(int) == 4) ? 1 : -1];

extern "C" int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

typedef char check_int_width[sizeof(int)==4?1:-1];

typedef char check_uint_width[sizeof(unsigned int)==4?1:-1];

struct T00481920
{
    char unk0x00[0x4];
    int nDaySound;
    int nNightSound;
    int nDayAmbient;
    int nNightAmbient;
    unsigned int nAmbientDelay;
    char unk0x18[0x4];
    int nEntryA;
    int nEntryB;
};

extern int gnGlobal_007C8C7C; // 0x007C8C7C
extern int gnGlobal_007C8C80; // 0x007C8C80
extern int gnGlobal_007C8C84; // 0x007C8C84
extern int gnGlobal_007C8C88; // 0x007C8C88
extern int gnGlobal_007C8C8C; // 0x007C8C8C
extern int gnGlobal_007C8C90; // 0x007C8C90
extern unsigned int gnGlobal_007C8C94; // 0x007C8C94
extern unsigned int gnGlobal_007C8C98; // 0x007C8C98
int __cdecl sub_004DF870(); // 0x004DF870
int __cdecl sub_00481780_GetPlayerLevelId(); // 0x00481780
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
void __fastcall sub_004BA950_RefreshHintsInRangeA(int nGroupA, int nGroupB); // 0x004BA950
void __fastcall sub_004BA9D0_RefreshHintsInRangeB(int nGroupA, int nGroupB); // 0x004BA9D0
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue); // 0x004B9B50
int __fastcall sub_004B9B20(int nHandle); // 0x004B9B20
void __fastcall sub_004BA840(int nHandle); // 0x004BA840
extern "C" int __fastcall sub_004E4100_RandomInRange(int nMin, int nMax); // 0x004E4100

struct D2MonTypeTxt
{
    int unk0x00[3];
};


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
extern const int gnSetMaskToBonusMappingTable_006DBD90[0x40]; // 0x006DBD90
void __fastcall sub_004E5A10_UseBonusCount(int nCount);

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, int nArg, int nArg2, int nArg5); // 0x0065FEC0



extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId); // 0x00656F90


typedef char chkSkillsTxt_M125[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char chkSkillDescTxt_M125[sizeof(D2SkillDescTxt) == 0x120 ? 1 : -1];


D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
const wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
wchar_t* __fastcall sub_00526700(wchar_t* pDest, const wchar_t* pSource); // 0x00526700
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
extern int gnTextOffset1_0072D8D4; // 0x0072D8D4
extern int gnTextOffset2_0072D8D0; // 0x0072D8D0
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern int gnGlobal_0072D844; // 0x0072D844
extern int gnGlobal_0072D88C; // 0x0072D88C
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __fastcall sub_004ED570_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot); // 0x004ED570
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004E1FF0
int __fastcall sub_004E1FF0_SkillCltDoMissileWall(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nDX = nTargetX - nX;
    int nDY = nTargetY - nY;
    if (!nDX && !nDY)
    {
        return 0;
    }

    int nStepX = 0;
    int nStepY = 0;

    if (nDX < 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = -2;
    }
    else if (nDX == 0 && nDY < 0)
    {
        nStepX = 2;
    }
    else if (nDX > 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = 2;
    }
    else if (nDX > 0 && nDY == 0)
    {
        nStepY = 2;
    }
    else if (nDX > 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = 2;
    }
    else if (nDX == 0 && nDY > 0)
    {
        nStepX = -2;
    }
    else if (nDX < 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = -2;
    }
    else if (nDX < 0 && nDY == 0)
    {
        nStepY = -2;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    nDX -= nCount / 2 * nStepX;
    nDY -= nCount / 2 * nStepY;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    for (int i = 0; i < nCount; ++i)
    {
        tMissile.pOwner = pUnit;
        tMissile.nX = nX + nDX / 6;
        tMissile.nTargetX = nDX;
        tMissile.nTargetY = nDY;
        tMissile.nY = nY + nDY / 6;
        tMissile.nSkillLevel = nSkillLevel;
        tMissile.nMissile = nMissile;
        sub_004CD540_CreateMissile(&tMissile);
        nDX += nStepX;
        nDY += nStepY;
    }

    return 1;
}

// 0x004E2630
int __fastcall sub_004E2630_SkillDoFrameSteps(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    const int nRepeats = SKILLS_GetParam1(pSkill);

    switch (pUnit->nSeqCurrentFramePrecise >> 8)
    {
    case SKILLDO_FRAME_A:
        UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_A_SET);
        pUnit->dwFrameCountPrecise = SKILLDO_FRAME_A_COUNT;
        break;

    case SKILLDO_FRAME_B:
        if (nRepeats >= SKILLDO_REPEATS)
        {
            UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_B_SET);
            pUnit->dwFrameCountPrecise = SKILLDO_FRAME_B_COUNT;
        }
        else
        {
            SKILLS_SetParam1(pSkill, nRepeats + 1);
        }
        break;

    case SKILLDO_FRAME_C:
        sub_00480E70_SetUnitMode(pUnit, SKILLDO_FRAME_C_STATE);
        sub_00464810_SetUnitFlag16(pUnit);
        break;
    }

    return 1;
}

// 0x004E2ED0
void __fastcall sub_004E2ED0_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= PATHINIT_MAX_FRAMES)
    {
        nFrames = PATHINIT_CAP_FRAMES;
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath) + nSeedOffset);
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nFrames);
    D2Common_10142(pPath, pMissile, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline unsigned char MONSTER_GetComponent10(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[10];
    }

    return 0;
}

inline unsigned char MONSTER_GetComponent11(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[11];
    }

    return 0;
}

// 0x004E2A40
int __fastcall sub_004E2A40_ComponentMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    nMissile += MONSTER_GetComponent10(pUnit);
    if (nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (sub_0046ACE0(nMissile))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x40;
        }

        if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
        {
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
        }
        else
        {
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

// 0x004E2B30
int __fastcall sub_004E2B30_ComponentMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    nMissile += MONSTER_GetComponent11(pUnit);
    if (nMissile < sgptDataTables->nMissilesTxtRecordCount && sub_0046ACE0(nMissile))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x40;
        }

        if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
        {
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
        }
        else
        {
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_J03(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline_J03(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004E2C20
int __fastcall sub_004E2C20_WeaponOrSkillMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_J03(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissile = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
    if (nMissile && nMissile != 0x1F)
    {
        if (DATATBLS_GetMissilesTxtRecordInline_J03(nMissile))
        {
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
            return 1;
        }

        return 0;
    }

    const int nCltMissile = pSkillsTxtRecord->wCltMissileA;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount || !sub_0046ACE0(nCltMissile))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
    {
        sub_004CDC30(pUnit, nCltMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
    }
    else
    {
        sub_004C5420_CreateFirstMissile(pUnit, nCltMissile, nSkillId, nSkillLevel);
    }

    return 1;
}

// 0x004E3050
void __fastcall sub_004C21E0_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x004E3060
int __fastcall sub_004E3060_CltDoPrgState(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (!STATES_CheckState(pUnit, 12))
    {
        if (pSkillsTxtRecord->wPrgOverlay > 0 && pSkillsTxtRecord->wPrgOverlay < sgptDataTables->nOverlayTxtRecordCount)
        {
            sub_00470390(pUnit, pSkillsTxtRecord->wPrgOverlay, 2, 0, 0, 0, 0, 0);
        }
        if (pSkillsTxtRecord->wPrgSound > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wPrgSound, 0, 0, 0, 0);
        }
    }
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 12);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x15, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return 0;
        }
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, sub_004C21E0_StatRemoveCallback_ToggleStateOff);
        STATLIST_SetState(pStatList, 12);
        STATES_ToggleState(pUnit, 12, 1);
        return 1;
    }
    UNITS_SetAnimationFrame(pUnit, 8);
    pUnit->dwFrameCountPrecise = 0x500;
    D2COMMON_10476(pStatList, 7);
    return 1;
}

// 0x004E31C0
D2UnitStrc* __fastcall sub_004E31C0_CltDo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;

    int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB < 0 || nMissileB >= sgptDataTables->nMissilesTxtRecordCount)
        nMissileB = -1;

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
        return 0;

    if (nMissileB >= 0 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
        nMissile = nMissileB;

    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nRange < 1)
        nRange = 1;

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 0x8020;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nTargetX = nX;
    tMissileParams.nTargetY = nY;
    tMissileParams.nRange = nRange;

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
        sub_004E3170_SetMissileFrames(pMissile, nRange);

    if (STATES_CheckState(pUnit, 0xC))
    {
        if (pUnit->pAnimSeq)
        {
            UNITS_SetAnimationFrame(pUnit, 8);
            pUnit->dwFrameCountPrecise = 0x500;
        }
        else
        {
            pUnit->nSeqCurrentFramePrecise = (pUnit->nSeqCurrentFramePrecise & 0xFFFFFF00) - 0x200;
        }
    }

    return pMissile;
}

// 0x004E37C0
int __fastcall sub_004E37C0_MissileAtTargetOffset(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nOffsetX = 0;
    int nOffsetY = 0;
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        nOffsetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        nOffsetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    if (!tMissileParams.nTargetX || !tMissileParams.nTargetY)
    {
        return 0;
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nValue);
    return 1;
}

// 0x004E3910
int __fastcall sub_004E3910_MissileIfCollision(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!sub_004C7B20(pUnit, nMissile))
    {
        return 0;
    }

    return sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel) != 0;
}

// 0x004E3A30
int __fastcall sub_004E3A30_FirstMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel) != 0;
}

// 0x004E3D70
int __fastcall sub_004E3D70_OwnerMissileEvent(int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pMissileUnit, int nUnused, int nSkillId, int nSkillLevel)
{
    if (nEvent)
    {
        return 0;
    }

    if (!pUnit || !pMissileUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissileUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (!sub_00465C60_CheckUnitPair(pUnit, pOwner))
    {
        return 0;
    }

    if (!(sub_0046ACE0(pMissileUnit->dwClassId)->nMissileFlags[1] & gnBitMasks_006CE268[1]))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nSkill = nSkillId;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nTargetX = CLIENTS_GetUnitX(pOwner);
    tMissileParams.nTargetY = CLIENTS_GetUnitY(pOwner);
    sub_004CD540_CreateMissile(&tMissileParams);

    const short nOverlay = pSkillsTxtRecord->wCltOverlayA;
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

    return 1;
}

// 0x004EFCF0
int __fastcall sub_004EFCF0_TurnedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 2;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nTargetX = nX - CLIENTS_GetUnitX(pUnit);
    tMissileParams.nTargetY = nY - CLIENTS_GetUnitY(pUnit);
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -tMissileParams.nTargetY);
    MISSILE_SetTargetY(pMissile, tMissileParams.nTargetX);
    return 1;
}

// 0x004F0160
int __fastcall sub_004F0160_SoundMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const short nSound = pSkillsTxtRecord->wPrgSound;
    if (nSound > 0)
    {
        sub_004B9A00(nSound, 0, 0, 0, 0);
    }

    sub_004C5470_CreateMissileToTarget(pUnit, 0x222, nSkillId, nSkillLevel);
    return 1;
}

// 0x004F01F0
int __fastcall sub_004F01F0_DirectionMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pUnit, &nDirX, &nDirY);
    if (!nDirX && !nDirY)
    {
        return 0;
    }

    D2UnitStrc* pMissile = sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    int nRange = pMissilesTxtRecord->wRange;
    if (nRange < 1)
    {
        nRange = 1;
    }

    const int nSpeed = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    int nStartX = -(nRange * nDirX);
    int nStartY = -(nRange * nDirY);
    sub_00643260(&nStartX, &nStartY);
    int nStepX = nDirX;
    int nStepY = nDirY;
    sub_00643260(&nStepX, &nStepY);
    sub_004DA1D0_SetMotionVectorA(pMissile, nStartX, nStartY, nSpeed * nRange);
    sub_004DA200_SetMotionVectorB(pMissile, nStepX, nStepY, -nSpeed, 1);
    sub_004DA350_UpdateMotion(pMissile);
    return 1;
}

// 0x004F11D0
int __fastcall sub_004F11D0_MissileLine(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nStepX = nX - CLIENTS_GetUnitX(pUnit);
    int nStepY = nY - CLIENTS_GetUnitY(pUnit);
    sub_004C5390_ScaleUpDirection(&nStepX, &nStepY);
    sub_004C53D0_ScaleDownDirection(&nStepX, &nStepY);
    nX += -(nStepX * nCount / 2);
    nY += -(nStepY * nCount / 2);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nRange = nRange;
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetY = nY;
        tMissileParams.nTargetX = nX;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004E3170_SetMissileFrames(pMissile, MISSILE_GetTotalFrames(pMissile));
        }

        nX += nStepX;
        nY += nStepY;
    }

    if (STATES_CheckState(pUnit, 0x0C))
    {
        UNITS_SetAnimationFrame(pUnit, 8);
        pUnit->dwFrameCountPrecise = 0x600;
    }

    return 1;
}

// 0x004F1370
int __fastcall sub_004F1370_FirstMissileTurned(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    const int nOffsetX = nX - CLIENTS_GetUnitX(pUnit);
    const int nOffsetY = nY - CLIENTS_GetUnitY(pUnit);
    MISSILE_SetTargetX(pMissile, -nOffsetY);
    MISSILE_SetTargetY(pMissile, nOffsetX);
    return 1;
}

// 0x004F1850
int __fastcall sub_004F1850_MissileFanA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    return sub_004F16F0_CreateMissileVolley(pUnit, nCount, nMissile, nSkillId, nSkillLevel, 0x200, 1, 0);
}

// 0x004F18F0
int __fastcall sub_004F18F0_MissileFanB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    return sub_004F16F0_CreateMissileVolley(pUnit, nCount, nMissile, nSkillId, nSkillLevel, 0x100, 0, 1);
}

// 0x004F1990
int __fastcall sub_004F1990_MissileFanC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    return sub_004F16F0_CreateMissileVolley(pUnit, nCount, nMissile, nSkillId, nSkillLevel, 0x200, 0, 1);
}

// 0x004F2340
int __fastcall sub_004F2340_MissileRows(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    const int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    const int nRows = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    sub_004C7700(pUnit, nMissile, nCount, nRows, nSkillId, nSkillLevel);
    return 1;
}

// 0x004F2720
int __fastcall sub_004F2720_TargetMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!sub_004648F0_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}

// 0x004F2E90
int __fastcall sub_004F2E90_UnitEffect(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    sub_004C70D0_StartUnitEffect(pUnit, pTarget, nMissile, -1, nSkillId, nSkillLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(nMissile, nSkillLevel));
    return 1;
}

// 0x004F33B0
int __fastcall sub_004F33B0_PositionMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    return 1;
}

// 0x004F38D0
int __fastcall sub_004F38D0_ParamMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2001;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nX = SKILLS_GetParam1(pSkill);
    tMissileParams.nY = SKILLS_GetParam2(pSkill);
    sub_004CD540_CreateMissile(&tMissileParams);
    SKILLS_SetParam1(pSkill, 0);
    SKILLS_SetParam2(pSkill, 0);
    return 1;
}

// 0x004F47B0
int __fastcall sub_004F47B0_TargetedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nTargetX = nX;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.pTarget = pTarget;
    tMissileParams.nTargetY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    if (!pTarget)
    {
        tMissileParams.dwFlags = 0x420;
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        if (pTarget)
        {
            MISSILE_SetTargetX(pMissile, 1);
        }
        else
        {
            MISSILE_SetTargetX(pMissile, 2);
        }

        const short nOffsetX = nX - CLIENTS_GetUnitX(pUnit);
        const short nOffsetY = nY - CLIENTS_GetUnitY(pUnit);
        MISSILE_SetTargetY(pMissile, (nOffsetY << 16) + nOffsetX);
    }

    return 1;
}

// 0x004F48F0
int __fastcall sub_004F48F0_MirrorMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nMirrorX = 2 * nTargetX - CLIENTS_GetUnitX(pUnit);
    const int nMirrorY = 2 * nTargetY - CLIENTS_GetUnitY(pUnit);
    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nTargetX = nMirrorX;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nTargetX;
    tMissileParams.nY = nTargetY;
    tMissileParams.dwFlags = 0x21;
    tMissileParams.nTargetY = nMirrorY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = sub_004E2ED0_InitCappedChargedPath;
    for (int i = 0; i < nCount; i += 1)
    {
        tMissileParams.nInitArg = i;
        sub_004CD540_CreateMissile(&tMissileParams);
    }

    return 1;
}

#include "gen/data/Source/D2Client/UI/SkillDesc_004E1FF0.inc"
struct D2StatListStrc;
struct D2UnitStrc;

// 0x004E3EB0
int __fastcall sub_004E3EB0_ScatterMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nFrequency = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nFrequency <= 0)
    {
        return 0;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel);
    if (nSpread <= 0)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[2], nSkillId, nSkillLevel);
    if (nRange <= 0)
    {
        return 0;
    }

    const int nCounter = SKILLS_GetParam1(pSkill);
    SKILLS_SetParam1(pSkill, nCounter + 1);
    if (!(nCounter % nFrequency))
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        if (!pSeed)
        {
            return 0;
        }

        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nSpread + 1) - nSpread;
        nX += CLIENTS_GetUnitX(pUnit);
        int nY = SEED_RollLimitedRandomNumber(pSeed, 2 * nSpread + 1) - nSpread;
        nY += CLIENTS_GetUnitY(pUnit);
        sub_004CDC30(pUnit, nMissile, 0, 0, nX, nY, nSkillId, nSkillLevel, SEED_RollLimitedRandomNumber(pSeed, nRange));
    }

    return 1;
}

// 0x004E4030
void __cdecl sub_004E4030_Nothing()
{
}

// 0x004E41E0
int __cdecl sub_004E41E0_IsCycleOutside1To3()
{
    const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct_007A0634);
    return nCycle < 1 || nCycle > 3;
}

// 0x004E4220
void __cdecl sub_004E4220_TouchRange()
{
    for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
    {
        sub_00482370(nId);
    }
}

// 0x004E4100
extern "C" int __fastcall sub_004E4100_RandomInRange(int nMin, int nMax)
{
    U32 width = (U32)nMax - (U32)nMin + 1u;
    return sub_004E40A0((int)width) + nMin;
}

// 0x004E4120
extern "C" int __fastcall sub_004E4120_RandomSpread(int nRange)
{
    const unsigned int uRange = (unsigned int)nRange;
    const unsigned int uWidth = 2u * uRange + 1u;
    const unsigned int uRoll = (unsigned int)sub_004E40A0((int)uWidth);
    return (int)(uRoll - uRange);
}

// 0x004E4240
static void sub_004E4240_ResetEntryPairs(int nIndex)
{
    int nId = nIndex * 4 + 0xA9C;
    for (int i = 3; i; --i)
    {
        sub_004822B0(nId, 1);
        sub_004822B0(nId + 0x18, 1);
        nId += 0x30;
    }
}

static __forceinline float GetEnvironVolume_Inline()
{
    return sub_00473C40() ? sub_00473C80() : 0.0f;
}

void __fastcall sub_004E42E0_UpdateEnvironSounds(unsigned int dwTick)
{
    if (!sub_004DF870())
        return;
    const int nLevelId = sub_00481780_GetPlayerLevelId();
    if (!nLevelId)
        return;
    int nSound = 0;
    int nAmbient = 0;
    int nVolume = 0;
    const int bNight = 2 < (unsigned int)(ENVIRONMENT_GetCycleIndexFromAct(gpAct_007A0634) - 1);
    const int nEnviron = sub_004817A0_GetPlayerSoundEnviron();
    T00481920* pEnv = sub_00481920_GetSoundEnvironTxtRecord(nEnviron);
    if (pEnv)
    {
        if (bNight)
        {
            nAmbient = pEnv->nNightAmbient;
            nSound = pEnv->nNightSound;
        }
        else
        {
            nAmbient = pEnv->nDayAmbient;
            nSound = pEnv->nDaySound;
        }
    }
    int nSecond = sub_00473C40() ? 0x40 : 0;
    if (GetEnvironVolume_Inline() != 0.0f)
    {
        const float fVolume = GetEnvironVolume_Inline();
        nVolume = (int)(fVolume * 255.0);
    }
    if (nSound != gnGlobal_007C8C88)
    {
        int bCross = 0;
        if (nSound == pEnv->nDaySound && gnGlobal_007C8C88 == pEnv->nNightSound)
            bCross = 1;
        if (nSound == pEnv->nNightSound && gnGlobal_007C8C88 == pEnv->nDaySound)
            bCross = 1;
        if (bCross)
        {
            sub_004B9EF0_ArmHint(gnGlobal_007C8C80, 0, 0, 0xFA);
        }
        else
        {
            sub_004BA950_RefreshHintsInRangeA(nSound, nSecond);
            sub_004BA9D0_RefreshHintsInRangeB(nAmbient, 0);
        }
        if (nSound != gnGlobal_007C8C88)
        {
            if (nSound)
            {
                gnGlobal_007C8C80 = sub_004B9A00(nSound, 0, 0, 0, 0);
                if (bCross)
                {
                    sub_004B9B50_SetValue(gnGlobal_007C8C80, 0);
                    sub_004B9EF0_ArmHint(gnGlobal_007C8C80, 0xFF, 0, 0xFA);
                }
                gnGlobal_007C8C88 = nSound;
            }
            else
            {
                gnGlobal_007C8C80 = 0;
                gnGlobal_007C8C88 = 0;
            }
        }
    }
    if (nSecond)
    {
        if (nVolume && !gnGlobal_007C8C84)
        {
            gnGlobal_007C8C84 = sub_004B9A00(gnGlobal_007C8C8C, 0, 0, 0, 0);
            if (gnGlobal_007C8C84)
                sub_004B9B50_SetValue(gnGlobal_007C8C84, nVolume);
        }
        if (gnGlobal_007C8C84)
        {
            const int nCurrent = sub_004B9B20(gnGlobal_007C8C84);
            int nNext;
            if (nVolume > nCurrent)
            {
                nNext = nCurrent + 6;
                if (nVolume < nNext)
                    nNext = nVolume;
            }
            else
            {
                nNext = nCurrent - 6;
                if (nVolume > nNext)
                    nNext = nVolume;
            }
            if (nNext)
            {
                sub_004B9B50_SetValue(gnGlobal_007C8C84, nNext);
            }
            else
            {
                sub_004BA840(gnGlobal_007C8C84);
                gnGlobal_007C8C84 = 0;
            }
        }
        gnGlobal_007C8C8C = nSecond;
    }
    else
    {
        sub_004BA840(gnGlobal_007C8C84);
        gnGlobal_007C8C84 = 0;
        gnGlobal_007C8C8C = 0;
    }
    sub_004DF6C0(nEnviron);
    if (nAmbient)
    {
        if (nAmbient != gnGlobal_007C8C90)
        {
            gnGlobal_007C8C94 = sub_004E4120(pEnv->nAmbientDelay / 3) + pEnv->nAmbientDelay;
            gnGlobal_007C8C98 = dwTick - sub_004E40A0(gnGlobal_007C8C94);
            gnGlobal_007C8C90 = nAmbient;
        }
        if (dwTick - gnGlobal_007C8C98 >= gnGlobal_007C8C94)
        {
            const int nHandle = sub_004B9A00(nAmbient, 0, 0, 0, 0);
            if (nHandle)
            {
                const int nSign = sub_004E40A0(2) ? 1 : -1;
                const int nPan = sub_004E4100_RandomInRange(0x1C2, 0x2EE) * nSign;
                const int nPanVolume = sub_004E4120(0x64);
                sub_004B99A0(nHandle, nPan, nPanVolume, 0);
                gnGlobal_007C8C98 = dwTick;
                gnGlobal_007C8C94 = sub_004E4120(pEnv->nAmbientDelay / 3) + pEnv->nAmbientDelay;
            }
        }
    }
    if (nLevelId != gnGlobal_007C8C7C)
    {
        const int nEntryA = pEnv->nEntryA;
        const int nEntryB = pEnv->nEntryB;
        for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
            sub_00482370(nId);
        if (nEntryA)
            sub_004E4240_ResetEntryPairs(nEntryA);
        if (nEntryB)
            sub_004E4240_ResetEntryPairs(nEntryB);
        gnGlobal_007C8C7C = nLevelId;
    }
}

// 0x004E4640
D2MonTypeTxt* __fastcall sub_004E4640_GetMonTypeTxtRecord(int nMonType)
{
    if (nMonType >= 0 && nMonType < sgptDataTables->nMonPropTxtRecordCount)
        return &sgptDataTables->pMonTypeTxt[nMonType];
    return sgptDataTables->pMonTypeTxt;
}

// 0x004E4C50
static int __stdcall sub_004E4C50_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId)
{
    if (pRecord->nOp >= 2 && pRecord->nOp <= 5)
    {
        const int nOpBase = pRecord->wOpBase;
        D2ItemStatCostTxt* pBase = (nOpBase >= 0 && nOpBase < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[nOpBase] : 0;
        if (!pBase)
            return 0;

        nValue = (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), nOpBase, 0) >> pBase->nValShift) * nValue >> pRecord->nOpParam;
    }

    nValue >>= pRecord->nValShift;
    if (nStatId == 122 && pUnit && pUnit->dwUnitType == UNIT_ITEM && ITEMSIsA(pUnit, 57))
        nValue += 50;

    return nValue;
}

// 0x004E4CE0
int __stdcall sub_004E4CE0_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame)
{
    if (!pRecord->wDescGrp)
        return 0;

    for (int i = sgptDataTables->nItemStatCostTxtRecordCount - 1; i >= 0; --i)
    {
        D2ItemStatCostTxt* pOther = (i >= 0 && i < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[i] : 0;
        if (!pOther)
            return 0;

        if (pRecord->wDescGrp == pOther->wDescGrp)
        {
            *pIsSame = i == nStatId;
            const int nStat = STATLIST_GetStatValue(pStatList, i, 0);
            if (nValue != sub_004E4C50_GetStatDisplayValue(nStat, pOther, pUnit, i))
                return 0;
        }
    }

    return 1;
}

// 0x004E5A10
static __declspec(noinline) int sub_004E5A10_GetSetBonusCount(unsigned int nSetItemMask)
{
    if (nSetItemMask >= sizeof(gnSetMaskToBonusMappingTable_006DBD90) / sizeof(gnSetMaskToBonusMappingTable_006DBD90[0]))
        return 0;
    return gnSetMaskToBonusMappingTable_006DBD90[nSetItemMask];
}

void __stdcall sub_004E5A10_Emit(int nUnused, unsigned int nSetItemMask)
{
    sub_004E5A10_UseBonusCount(sub_004E5A10_GetSetBonusCount(nSetItemMask));
}

// 0x004E67D0
void __fastcall sub_004E67D0_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4)
{
    sub_0065FEC0_ItemApplyProps(2, 0, pItem, nArg, nArg2, 0);
    sub_004E6410_BuildPropText(pItem, wszText, nArg3, 0, nArg4);

    D2StatListStrc* pStatList = sub_00625790_UnitFindStatList(pItem, 0, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    if (wszText[sub_00526800(wszText) - 1].isNewline())
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
}

// 0x004E6C50
int __fastcall sub_004E6C50_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E6C70
int __fastcall sub_004E6C70(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4];
}

// 0x004E6CA0
int __fastcall sub_004E6CA0_GetSkillParamByLevel(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
}

// 0x004E6FF0
int __cdecl sub_004E6FF0_SumProgressiveBonus()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return 0;
    }

    int nSum = 0;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (!STATES_CheckState(pPlayer, sgptDataTables->pProgressiveStates[i]))
        {
            continue;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, sgptDataTables->pProgressiveStates[i]);
        if (!pStatList)
        {
            continue;
        }

        const int nSkillId = STATLIST_GetStatValue(pStatList, 0x15E, 0);
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            continue;
        }

        D2SkillsTxt* pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        if (nSkillLevel <= 0 || pSkillsTxtRecord->nPrgDamage != 1)
        {
            continue;
        }

        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            continue;
        }

        const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        if (nValue > 0)
        {
            nSum += sub_004E6CA0_GetSkillParamByLevel(nSkillId, nSkillLevel) * nValue;
        }
    }

    return nSum;
}

// 0x004EFC20
int __fastcall sub_004EFC20_GetSkillParam2(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[1];
}

// 0x004EFC50
int __fastcall sub_004EFC50_GetSkillParam3(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[2];
}

// 0x004EFC80
int __fastcall sub_004EFC80_FourthSkillParam(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x004EFCB0
int __fastcall sub_004EFCB0_GetSummonLevel(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
}

// build: context sub_004F21B0_GetCltMissileId
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                if (nIndex > 1)
                {
                    if (nIndex >= 3)
                    {
                        nIndex = 3;
                    }
                }
                else
                {
                    nIndex = 1;
                }

                return pSkillsTxtRecord->wCltMissile[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wCltMissile[1];
}

// 0x004F4110
int __fastcall sub_004F4110_GetSkillParam5(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[5];
}

// 0x004F4F40
int __fastcall sub_004F4F40_GetMonSkillSound(D2UnitStrc* pUnit, int nSkillId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (pUnit)
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nClassId];
        }
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonSoundsTxt* pMonSoundsTxtRecord = DATATBLS_GetMonSoundsTxtRecordFromSoundId(pMonStatsTxtRecord->wMonSound);
    if (!pMonSoundsTxtRecord)
    {
        return 0;
    }

    int nSound = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            switch (i)
            {
            case 0:
                nSound = pMonSoundsTxtRecord->dwSkill[0];
                break;

            case 1:
                nSound = pMonSoundsTxtRecord->dwSkill[1];
                break;

            case 2:
                nSound = pMonSoundsTxtRecord->dwSkill[2];
                break;

            case 3:
                nSound = pMonSoundsTxtRecord->dwSkill[3];
                break;
            }
        }
    }

    return nSound < 0 ? 0 : nSound;
}

static D2SkillsTxt* sub_H14_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static D2SkillDescTxt* sub_H14_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    return 0;
}

// 0x004E6D40
static __declspec(noinline) unsigned short sub_004E6D40_GetSkillDescStrName(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrName;
}

// 0x004E6D90
static __declspec(noinline) unsigned short sub_004E6D90_GetSkillDescStrShort(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrShort;
}

unsigned short __stdcall sub_M125_Emit_004E6D40(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return sub_004E6D40_GetSkillDescStrName(nSkillId);
}

unsigned short __stdcall sub_M125_Emit_004E6D90(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return sub_004E6D90_GetSkillDescStrShort(nSkillId);
}

// 0x004E6E80
static __declspec(noinline) int sub_004E6E80_ApplyAiCurseDivisor(int nValue)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(sub_0044DCD0_GetDifficulty());
    const int nDivisor = pDifficultyLevelsTxt->dwAiCurseDivisor;
    if (nDivisor > 0)
        nValue /= nDivisor;
    return nValue;
}

int __stdcall sub_M125_Emit_004E6E80(int nUnused1, int nUnused2, int nUnused3, int nValue)
{
    return sub_004E6E80_ApplyAiCurseDivisor(nValue);
}

// 0x004E7900
static __declspec(noinline) int sub_004E7900_AppendStringLine(wchar_t* wszOut, unsigned short wStr)
{
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

void __stdcall sub_M24_Emit_004E7900(wchar_t* wszOut, unsigned short wStr, int nOther)
{
    if (nOther)
        sub_004E7900_AppendStringLine(wszOut, wStr);
}

// 0x004E9160
static int __stdcall sub_004E9160_GetAttackRateValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == 38)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = 0;
    if (STATES_CheckState(pUnit, 78))
        nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);

    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, 119, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    *pValue1 += *pValue1 * nBonus / 100;

    *pValue2 = 0;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

// 0x004E9590
void __fastcall sub_004E9590_SkillDescAttackRate(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    *pValue1 = 0;
    *pValue2 = 0;
    sub_004E9160_GetAttackRateValues(pUnit, 0, pValue1, pValue2, nLevel, pSkill);
}

char gbTextOffsetInit_007C8C9C; // 0x007C8C9C

char gbSkillRefreshInit_007C8CA4; // 0x007C8CA4

// 0x004E9870
void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2)
{
    sub_00502EF0(6);
    if (!gbTextOffsetInit_007C8C9C)
    {
        if (STRTABLE_GetLanguage() >= 6 && STRTABLE_GetLanguage() <= 9)
        {
            gnTextOffset1_0072D8D4 = -7;
        }
        else
        {
            gnTextOffset1_0072D8D4 = -6;
        }

        gbTextOffsetInit_007C8C9C = 1;
    }

    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_00711470 + gnGlobal_007A285C + gnTextOffset1_0072D8D4 + nY - 480, gnGlobal_007A2858 + nRight, wszText1, nColor1);
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnTextOffset2_0072D8D0 + gnGlobal_00711470 + gnGlobal_007A285C + nY - 480, gnGlobal_007A2858 + nRight, wszText2, nColor2);
}

// 0x004EDA20
void __fastcall sub_004EDA20_RefreshSkills(D2UnitStrc* pUnit)
{
    if (!gbSkillRefreshInit_007C8CA4)
    {
        if (STRTABLE_GetLanguage() >= 6 && STRTABLE_GetLanguage() <= 9)
        {
            gnGlobal_0072D844 -= 1;
            gnGlobal_0072D88C -= 1;
        }

        gbSkillRefreshInit_007C8CA4 = 1;
    }

    if (pUnit)
    {
        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        sub_004ED570_DrawSkillPanel(pUnit, pSkill, 0);
        pSkill = UNITS_GetRightSkill(pUnit);
        sub_004ED570_DrawSkillPanel(pUnit, pSkill, 6);
    }
}
