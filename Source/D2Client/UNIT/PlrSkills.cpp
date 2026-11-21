#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_MODIFIERLIST_SKILL 350
#define COLLISION_PATTERN_SMALL_UNIT_PRESENCE 1
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define STAT_UNIT_MODE 172
#define ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE 9

struct D2StaticPathStrc;
struct D2SkillsTxt;
union D2SeedStrc;
struct D2StatesTxt;
struct D2MissilesTxt;
struct D2MonStats2Txt;
struct D2MissileStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2ItemStatCostTxt;





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __fastcall sub_004C9060_DrawRotated(D2UnitStrc* pUnit, int nArg, int bForward); // 0x004C9060


extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
void __fastcall sub_0046F000_ResetGfx(D2UnitStrc* pUnit); // 0x0046F000
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nMode); // 0x00480E70
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __stdcall sub_004D97F0_UpdateStateColor(D2UnitStrc* pUnit); // 0x004D97F0
void __fastcall sub_004D9920_StartStateOverlays(D2UnitStrc* pUnit, int nState); // 0x004D9920
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit); // 0x00624390
int __stdcall STATLIST_GetState(D2StatListStrc* pStatList); // 0x006252F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList); // 0x00627340
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId); // 0x00664740
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId); // 0x00621CC0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_0046AE50_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce); // 0x0046AE50
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __stdcall sub_K06_EmitGettier1(int nValue);
void __stdcall sub_K06_EmitPuttier1(int nValue, int nOther);
int __stdcall sub_K06_EmitGettier2(int nValue);
void __stdcall sub_K06_EmitPuttier2(int nValue, int nOther);
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
int __stdcall STATES_CheckStateMaskAuraByStateId(int nState); // 0x0063A210
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall sub_004ADCE0_StateRequests(D2UnitStrc* pUnit); // 0x004ADCE0
void __fastcall sub_0044CE40(int nValue); // 0x0044CE40



typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern const unsigned char gnFrameDirections_006DBA08[8][9]; // 0x006DBA08
extern const unsigned char gnBaseDirections_006DBA50[8]; // 0x006DBA50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __fastcall sub_00472C50(int nArg); // 0x00472C50
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex); // 0x0063E7A0
int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int* pMode, int* pX, int* pY); // 0x0063EA70
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4); // 0x00649EF0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710


void __fastcall sub_00463C00_OnModeChange(D2UnitStrc* pUnit, unsigned char nOldMode, unsigned char nNewMode); // 0x00463C00
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

static __declspec(noinline) int sub_004D84C0_IsInSequenceMode(D2UnitStrc* pUnit)
{
    int nUnitType = UNIT_INVALID;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    switch (nUnitType)
    {
    case UNIT_MONSTER:
        return (pUnit ? pUnit->dwAnimMode : 0) == MONMODE_SEQUENCE;
    case UNIT_PLAYER:
        return (pUnit ? pUnit->dwAnimMode : 0) == PLRMODE_SEQUENCE;
    }
    return 0;
}

// 0x004D8520
void __fastcall sub_004D8520_SkillSeqDo1(D2UnitStrc* pUnit, int nArg)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    if (!sub_004D84C0_IsInSequenceMode(pUnit))
        return;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 38);
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
        return;

    switch (pSkillsTxtRecord->wSrvDoFunc)
    {
    case 0x4C:
        sub_004C9060_DrawRotated(pUnit, nArg, 1);
        break;
    case 0x43:
        if (SKILLS_GetFlags(pSkill) & 1)
            sub_004C9990(pUnit, nArg, 1);
        break;
    }
}

// 0x004D85B0
void __fastcall sub_004D85B0_SkillSeqDo1Thunk(D2UnitStrc* pUnit, int nArg)
{
    sub_004D8520_SkillSeqDo1(pUnit, nArg);
}

// 0x004D85C0
void __fastcall sub_004D85C0_SkillSeqDo0(D2UnitStrc* pUnit, int nArg)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    if (!sub_004D84C0_IsInSequenceMode(pUnit))
        return;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 79);
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
        return;

    switch (pSkillsTxtRecord->wSrvDoFunc)
    {
    case 0x4C:
        sub_004C9060_DrawRotated(pUnit, nArg, 0);
        break;
    case 0x43:
        if (SKILLS_GetFlags(pSkill) & 1)
            sub_004C9990(pUnit, nArg, 0);
        break;
    }
}

static __forceinline D2StatesTxt* GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }
    return 0;
}

static __forceinline int GetOverlay(short nOverlay)
{
    return nOverlay >= 0 ? nOverlay : -1;
}

static __forceinline int GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8660
static __declspec(noinline) void __stdcall sub_004D8660_OverlayVariants(D2UnitStrc* pUnit, int nOverlay)
{
    if (nOverlay == -1)
        return;

    const int nCount = DATATBLS_Get1OfNFromOverlayTxt(nOverlay);
    for (int i = 0; i < nCount; ++i)
    {
        sub_0046F0C0(pUnit, 0, nOverlay + i);
    }
}

// 0x004D86A0
void __fastcall sub_004D86A0_StatePrgOverlayLevel(D2UnitStrc* pUnit, int nState)
{
    if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt || !(pStatesTxt->nStateFlags[0] & gdwBitMasks_006CE268[4]))
    {
        return;
    }

    if (pStatesTxt->wPrgOverlay <= 0 || pStatesTxt->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount
        || pStatesTxt->wStat < 0 || pStatesTxt->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_0046F0C0(pUnit, 0, pStatesTxt->wPrgOverlay + i);
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, pStatesTxt->wStat, 0);
    if (nLevel >= 1 && nLevel <= 3)
    {
        sub_00470390(pUnit, pStatesTxt->wPrgOverlay + nLevel - 1, 3, 0, 0, 0, 0, 0);
    }
}

// 0x004D8760
void __fastcall sub_004D8760_StatePrgOverlays(D2UnitStrc* pUnit, int nState)
{
    if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt || !(pStatesTxt->nStateFlags[0] & gdwBitMasks_006CE268[4]))
    {
        return;
    }

    if (pStatesTxt->wPrgOverlay <= 0 || pStatesTxt->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount
        || pStatesTxt->wStat < 0 || pStatesTxt->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_0046F0C0(pUnit, 0, pStatesTxt->wPrgOverlay + i);
    }
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D87E0
void __fastcall sub_004D87E0_StateAuraEffect(D2UnitStrc* pUnit, int nState)
{
    int nLevel;
    D2StatListStrc* pStatList;
    int nSkillId;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    nLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    sub_0046AE50_StartTimedBox(5, nValue * 3 / 5, nValue * 2 / 5, nLevelId, 0);
}

// 0x004D88A0
void __fastcall sub_004D88A0_StateSkillLevel(D2UnitStrc* pUnit, int nState)
{
    int nLevel;
    D2StatListStrc* pStatList;
    int nSkillId;

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    nLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int nCurrent = pSkill ? SKILLS_GetSkillLevel(pUnit, pSkill, 1) : 0;
    if (nCurrent == nLevel)
    {
        return;
    }

    int nMax = sub_004AA8B0_GetSkillMaxLevel(nSkillId);
    if (nLevel > nMax)
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nMax, 0, ".\\UNIT\\PlrSkills.cpp", 0x11B);
        sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nLevel - nMax);
    }
    else
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nLevel, 0, ".\\UNIT\\PlrSkills.cpp", 0x120);
    }
}

// 0x004D8960
void __fastcall sub_004D8960_StateStoreOwner(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        unsigned int nOwnerType = STATLIST_GetStatValue(pStatList, STAT_SOURCE_UNIT_TYPE, 0);
        if (nOwnerType < 6)
        {
            UNITS_StoreOwnerTypeAndGUID(pUnit, nOwnerType, STATLIST_GetStatValue(pStatList, STAT_SOURCE_UNIT_ID, 0));
        }
    }
}

// 0x004D89A0
void __fastcall sub_004D89A0_StateClearOwner(D2UnitStrc* pUnit, int nState)
{
    UNITS_StoreOwner(pUnit, 0);
}

// 0x004D89B0
void __fastcall sub_004D89B0_ApplyStateMonster(D2UnitStrc* pUnit, int nState)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, STAT_SHORTPARAM1, 0);
    const int nMode = pUnit->dwAnimMode;
    sub_004AEDD0(pUnit, nValue);
    if (nMode == 8)
    {
        sub_00480E70_SetUnitMode(pUnit, 8);
    }
    else
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
    }

    if (nValue == 0x21F)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2Common_10216(pPath, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit) + 10, 1);
    }
}

// 0x004D8A30
static int __stdcall sub_004D8A30_GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8A60
void __fastcall sub_004D8A60_StateOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    const int nCast = GetOverlay((short)pTxt->wCastOverlay);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOverlay4 = GetOverlay(pTxt->wOverlay[3]);
    if (nCast != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nCast);
        sub_004D8660_OverlayVariants(pUnit, nCast);
        sub_004D8660_OverlayVariants(pUnit, nCast);
    }
    if (nOverlay1 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
    }
    if (nOverlay2 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
    }
    if (nOverlay3 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay3);
    }
    if (nOverlay4 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay4);
    }
}

// 0x004D8B90
void __fastcall sub_004D8B90_StateTier4(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
        return;

    const int nValue = STATLIST_GetStatValue(pStatList, STAT_BONEARMOR, 0);
    const int nTotal = STATLIST_GetStatValue(pStatList, STAT_BONEARMORMAX, 0);
    const int nCast = GetOverlay((short)pTxt->wCastOverlay);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOverlay4 = GetOverlay(pTxt->wOverlay[3]);
    const int nOldTier = STATLIST_GetStatValue(pStatList, STAT_SHORTPARAM1, 0);
    const int nTier = GetThirdsTier(nValue, nTotal);
    STATLIST_SetStat(pStatList, STAT_SHORTPARAM1, nTier, 0);
    if (nTier > nOldTier)
    {
        sub_004D8A60_StateOverlays(pUnit, nState);
        if (nOverlay3 != -1 && nTier >= 3)
        {
            sub_00470390(pUnit, nOverlay3, 7, 0, 0, 0, 0, 0);
        }
        if (nOverlay4 != -1 && nTier >= 2)
        {
            sub_00470390(pUnit, nOverlay4, 7, 0, 0, 0, 0, 0);
        }
        if (nCast != -1 && nOverlay1 != -1 && nOverlay2 != -1)
        {
            sub_00470390(pUnit, nCast, 4, 0, nOverlay1, nOverlay2, 0, 0);
        }
    }
    else if (nTier < nOldTier)
    {
        for (int i = nTier; i < nOldTier; ++i)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay1);
            sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        }
    }
}

void __stdcall sub_K06_Emittier1(int a, int b)
{
    const int v = sub_K06_EmitGettier1(a);
    const int t = sub_K06_EmitGettier1(b);
    sub_K06_EmitPuttier1(sub_004D8A30_GetThirdsTier(v, t), v);
}

// 0x004D8D60
static int __stdcall sub_004D8D60_GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8D90
void __fastcall sub_004D8D90_StateOverlayPairs(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    if (nOverlay1 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay1);
        sub_004D8660_OverlayVariants(pUnit, nOverlay1 + 1);
    }
    if (nOverlay2 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay2);
        sub_004D8660_OverlayVariants(pUnit, nOverlay2 + 1);
    }
    if (nOverlay3 != -1)
    {
        sub_004D8660_OverlayVariants(pUnit, nOverlay3);
        sub_004D8660_OverlayVariants(pUnit, nOverlay3 + 1);
    }
}

// 0x004D8E60
void __fastcall sub_004D8E60_StateTier3(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
        return;

    const int nValue = STATLIST_GetStatValue(pStatList, STAT_BONEARMOR, 0);
    const int nTotal = STATLIST_GetStatValue(pStatList, STAT_BONEARMORMAX, 0);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOldTier = STATLIST_GetStatValue(pStatList, STAT_SHORTPARAM1, 0);
    const int nTier = GetThirdsTier(nValue, nTotal);
    STATLIST_SetStat(pStatList, STAT_SHORTPARAM1, nTier, 0);
    if (nTier > nOldTier)
    {
        sub_004D8D90_StateOverlayPairs(pUnit, nState);
        if (nOverlay3 != -1 && nTier >= 3)
        {
            sub_00470390(pUnit, nOverlay3, 3, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, nOverlay3 + 1, 3, 0, 0, 0, 0, 0);
        }
        if (nOverlay2 != -1 && nTier >= 2)
        {
            sub_00470390(pUnit, nOverlay2, 3, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, nOverlay2 + 1, 3, 0, 0, 0, 0, 0);
        }
        if (nOverlay1 != -1 && nTier >= 1)
        {
            sub_00470390(pUnit, nOverlay1, 3, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, nOverlay1 + 1, 3, 0, 0, 0, 0, 0);
        }
    }
    else
    {
        if (nOverlay3 && nTier <= 2)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay3);
            sub_004D8660_OverlayVariants(pUnit, nOverlay3 + 1);
        }
        if (nOverlay2 && nTier <= 1)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay2);
            sub_004D8660_OverlayVariants(pUnit, nOverlay2 + 1);
        }
        if (nOverlay1 && nOverlay1 <= 1)
        {
            sub_004D8660_OverlayVariants(pUnit, nOverlay1);
            sub_004D8660_OverlayVariants(pUnit, nOverlay1 + 1);
        }
    }
}

void __stdcall sub_K06_Emittier2(int a, int b)
{
    const int v = sub_K06_EmitGettier2(a);
    const int t = sub_K06_EmitGettier2(b);
    sub_K06_EmitPuttier2(sub_004D8D60_GetThirdsTier(v, t), v);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x004D9090
void __fastcall sub_004D9090_StatePlaySkillSound(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (pSkillsTxtRecord && pSkillsTxtRecord->wPrgSound > 0)
    {
        sub_004B9A00(pSkillsTxtRecord->wPrgSound, pUnit, 0, 0, 0);
    }
}

// 0x004D90F0
void __fastcall sub_004D90F0_StateStopSkillSound(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (pSkillsTxtRecord && pSkillsTxtRecord->wPrgSound > 0)
    {
        void* pUnitSfx = sub_004CA900_FindUnitSfxInRange(pUnit, pSkillsTxtRecord->wPrgSound);
        if (pUnitSfx)
        {
            sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
        }
    }
}

// 0x004D9260
void __fastcall sub_004D9260_StateClearCollision(D2UnitStrc* pUnit, int nState)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 759) != SKILL_NEST)
    {
        return;
    }

    int nX = SKILLS_GetParam2(pSkill);
    int nY = SKILLS_GetParam3(pSkill);
    if (!nX && !nY)
    {
        return;
    }

    SKILLS_SetParam2(pSkill, 0);
    SKILLS_SetParam3(pSkill, 0);
    if (sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY))
    {
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        COLLISION_ResetMaskWithPattern(pRoom, nX, nY, COLLISION_PATTERN_SMALL_UNIT_PRESENCE, 0x100);
    }
}

// 0x004D9310
void __fastcall sub_004D9310_SetStateFlagEx(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
    }
}

// 0x004D9320
void __fastcall sub_004D9320_SetStateFlags(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags |= 0x20;
    }
}

// 0x004D9340
void __fastcall sub_004D9340_ClearStateFlags(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx &= ~0x40000;
        pUnit->dwFlags &= ~0x20;
    }
}

// 0x004D9360
void __fastcall sub_004D9360_ResetGfxMotion(D2UnitStrc* pUnit, int nState)
{
    sub_004DA000_ResetGfxMotion(pUnit);
    sub_004DA620(pUnit, 1);
}

// 0x004D9380
void __fastcall sub_004D9380_ClearMotion(D2UnitStrc* pUnit, int nState)
{
    sub_004DA620(pUnit, 0);
    sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, 0);
}

// 0x004D93A0
void __fastcall sub_004D93A0_StateEndRequests(D2UnitStrc* pUnit, int nState)
{
    sub_004ADCE0_StateRequests(pUnit);
}

// 0x004D9450
void __fastcall sub_004D9450_StateSetMode(D2UnitStrc* pUnit, int nState)
{
    sub_00480E70_SetUnitMode(pUnit, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 0x80000000;
    }
    D2Common_10214(pUnit);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D9480
void __fastcall sub_004D9480_StateOverlaySpread(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    int nSelect = STATLIST_GetStatValue(pStatList, STAT_SKILL_FRENZY, 0);
    int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return;
    }

    int nEnd = pStatesTxtRecord->wOverlay[1];
    int nStart = pStatesTxtRecord->wOverlay[0];
    nCount = D2_MIN(nCount, nEnd - nStart + 1);
    nSelect = D2_MIN(nSelect, nEnd - nStart + 1);
    if (nStart >= 0 && nEnd >= nStart)
    {
        int nIndex = (nSelect - 1) * (nEnd - nStart + 1) / nCount;
        for (int i = 0; i < nEnd - nStart + 1; ++i)
        {
            if (i != nIndex)
            {
                sub_0046F0C0(pUnit, 0, nStart + i);
            }
            else if (!sub_0046E100(pUnit, nStart + i))
            {
                sub_00470390(pUnit, nStart + i, 3, 0, 0, 0, 0, 0);
            }
        }
    }

    nStart = pStatesTxtRecord->wOverlay[2];
    nEnd = pStatesTxtRecord->wOverlay[3];
    if (nStart >= 0 && nEnd >= nStart)
    {
        int nRange = nEnd - nStart + 1;
        int nIndex = (nSelect - 1) * nRange / nCount;
        for (int i = 0; i < nRange; ++i, ++nStart)
        {
            if (i != nIndex)
            {
                sub_0046F0C0(pUnit, 0, nStart);
            }
            else if (!sub_0046E100(pUnit, nStart))
            {
                sub_00470390(pUnit, nStart, 3, 0, 0, 0, 0, 0);
            }
        }
    }
}

#include "gen/data/Source/D2Client/UNIT/PlrSkills.inc"

static D2StatesTxt* STATES_GetStatesTxtRecord_J03(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

// 0x004D9740
void __fastcall sub_004D9740_StateCreateMissile(D2UnitStrc* pUnit, int nState)
{
    sub_004AF890(pUnit, 5, 0);

    D2StatesTxt* pStatesTxt = STATES_GetStatesTxtRecord_J03(nState);
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->wMissile < 0 || pStatesTxt->wMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = pStatesTxt->wMissile;
    tMissile.nSkill = pStatesTxt->wSkill >= 0 ? pStatesTxt->wSkill : 0;
    tMissile.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissile);
}

// 0x004D97E0
void __fastcall sub_004D97E0_StateResetValue(D2UnitStrc* pUnit, int nState)
{
    sub_0044CE40(0);
}

// 0x004D9920
void __fastcall sub_004D9920_StartStateOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || (pStatesTxtRecord->nStateFlags[4] & gdwBitMasks_006CE268[3]))
    {
        return;
    }

    int nCastOverlay = (short)pStatesTxtRecord->wCastOverlay >= 0 ? (short)pStatesTxtRecord->wCastOverlay : -1;
    int nOverlay1 = pStatesTxtRecord->wOverlay[0] >= 0 ? pStatesTxtRecord->wOverlay[0] : -1;
    int nOverlay2 = pStatesTxtRecord->wOverlay[1] >= 0 ? pStatesTxtRecord->wOverlay[1] : -1;
    const int bMask = STATES_CheckStateMaskAuraByStateId(nState);

    if (nCastOverlay != -1)
    {
        nCastOverlay += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nCastOverlay));
    }

    if (nOverlay1 != -1)
    {
        nOverlay1 += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay1));
    }

    if (nOverlay2 != -1)
    {
        nOverlay2 += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay2));
    }

    if (bMask)
    {
        STATES_ToggleState(pUnit, nState, 0);
        if (sub_0063A250(pUnit))
        {
            nCastOverlay = -1;
        }
        STATES_ToggleState(pUnit, nState, 1);
    }

    if (nCastOverlay != -1)
    {
        if (bMask)
        {
            sub_00470390(pUnit, nCastOverlay, 9, 0, nOverlay1, nOverlay2, nState, 0);
        }
        else
        {
            sub_00470390(pUnit, nCastOverlay, 4, 0, nOverlay1, nOverlay2, 0, 0);
        }
        return;
    }

    if (nOverlay1 != -1)
    {
        if (bMask)
        {
            sub_00470390(pUnit, nOverlay1, 8, 0, nState, 0, 0, 0);
        }
        else
        {
            sub_00470390(pUnit, nOverlay1, 3, 0, 0, 0, 0, 0);
        }
    }

    if (nOverlay2 != -1)
    {
        if (bMask)
        {
            sub_00470390(pUnit, nOverlay2, 8, 0, nState, 0, 0, 0);
        }
        else
        {
            sub_00470390(pUnit, nOverlay2, 3, 0, 0, 0, 0, 0);
        }
    }
}

// 0x004D9AD0
static __declspec(noinline) void sub_004D9AD0_ResetTransform(D2UnitStrc* pUnit)
{
    sub_0046F000_ResetGfx(pUnit);
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (pUnit->dwAnimMode == 0x12)
                return;
            sub_00480E70_SetUnitMode(pUnit, 1);
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            sub_00480E70_SetUnitMode(pUnit, 1);
        }
    }
    sub_00470610_Refresh(pUnit, 1);
    sub_00624390_AnimInit(pUnit);
    pUnit->nSeqCurrentFramePrecise = 0;
    UNITS_SetUsedSkill(pUnit, 0);
}

// 0x004D9B20
void __fastcall sub_004D9B20_BeginState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return;

    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    if (pTxt->nStateFlags[39 >> 3] & gdwBitMasks_006CE268[39 & 7])
    {
        if ((pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == 0xC) || (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == 0x11))
        {
            STATES_ToggleState(pUnit, nState, 1);
            return;
        }
    }

    if (STATES_CheckState(pUnit, nState))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (!(pTxt->nStateFlags[36 >> 3] & gdwBitMasks_006CE268[36 & 7]))
        {
            STATLIST_RemoveAllStats(pStatList);
        }
    }
    else if (pTxt->wOnSound >= 0)
    {
        sub_004B9A00(pTxt->wOnSound, pUnit, 0, 0, 0);
    }

    STATES_ToggleState(pUnit, nState, 1);
    if (pTxt->nColorShift)
    {
        sub_004D97F0_UpdateStateColor(pUnit);
    }
    sub_004D9920_StartStateOverlays(pUnit, nState);
    if (sub_00464820_IsDeadOrDying(pUnit) && STATES_CheckStateMaskHideOnUnit(pUnit))
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags &= ~2;
        pUnit->dwFlags |= 0x20;
    }
    if (pTxt->nStateFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        sub_004D9AD0_ResetTransform(pUnit);
    }
}

// 0x004D9C30
void __fastcall sub_004D9C30_EndState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return;

    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    if (STATES_CheckState(pUnit, nState))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList && nState == STATLIST_GetState(pStatList))
        {
            D2Common_10474(pUnit, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
        if (pTxt->wOffSound >= 0)
        {
            sub_004B9A00(pTxt->wOffSound, pUnit, 0, 0, 0);
        }
    }

    STATES_ToggleState(pUnit, nState, 0);
    if (pTxt->nColorShift)
    {
        sub_004D97F0_UpdateStateColor(pUnit);
    }
    if ((short)pTxt->wRemoveOverlay >= 0)
    {
        int nOverlay = (short)pTxt->wRemoveOverlay;
        if (nOverlay != -1)
        {
            nOverlay += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay));
        }
        sub_00470390(pUnit, nOverlay, 4, 0, -1, -1, 0, 0);
    }
    if (pTxt->wOverlay[0] >= 0)
    {
        sub_004D8660_OverlayVariants(pUnit, pTxt->wOverlay[0]);
    }
    if (pTxt->wOverlay[1] >= 0)
    {
        sub_004D8660_OverlayVariants(pUnit, pTxt->wOverlay[1]);
    }
    if (pTxt->nStateFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        sub_004D9AD0_ResetTransform(pUnit);
    }
    UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\PlrSkills.cpp", 0x59C);
}

inline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecordInline(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

// 0x004D9D70
D2StatListStrc* __fastcall sub_004D9D70_SetStateStat(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nState, int nStatId, int nValue, int nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    int nOldValue = 0;
    if (nStatId == STAT_UNIT_MODE)
    {
        nOldValue = 4;
    }

    if (!pStatList)
    {
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pStatList, (unsigned int)pStatList, (unsigned int)pStatList, (!pUnit ? 6 : pUnit->dwUnitType), (!pUnit ? -1 : pUnit->dwUnitId));
            STATLIST_SetState(pStatList, nState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }
        else
        {
            nOldValue = STATLIST_GetStatValue(pStatList, nStatId, nLayer);
        }
    }

    STATLIST_SetStat(pStatList, nStatId, nValue, nLayer);

    if (nStatId == STAT_UNIT_MODE)
    {
        sub_00463C00_OnModeChange(pUnit, nOldValue, nValue);
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = DATATBLS_GetItemStatCostTxtRecordInline(nStatId);
    if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE >> 3] & gdwBitMasks_006CE268[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE & 7])
    {
        UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\PlrSkills.cpp", 1490);
    }

    return pStatList;
}

// 0x004E0D40
int __fastcall sub_004E0D40_SkillDoFrameOffset(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam1(pSkill);
    int nY = SKILLS_GetParam2(pSkill);
    if ((!nX || !nY) && !sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    unsigned char nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nX, nY);
    unsigned char nIndex = sub_0063E7A0_GetByteTableEntry(nDirection) & 7;
    nX = CLIENTS_GetUnitX(pUnit);
    nY = CLIENTS_GetUnitY(pUnit);

    int nOffsetX;
    int nOffsetY;
    sub_0063E7E0_GetDirectionDelta(gnBaseDirections_006DBA50[nIndex], &nOffsetX, &nOffsetY);
    nX += nOffsetX;
    nY += nOffsetY;

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    nFrame -= 4;
    int nClamp = nFrame > 0 ? nFrame : 0;
    nFrame = nClamp < 8 ? nClamp : 8;

    unsigned char nDir = gnFrameDirections_006DBA08[nIndex][nFrame];
    if (nDir != 99)
    {
        sub_0063E7E0_GetDirectionDelta(nDir, &nOffsetX, &nOffsetY);
        nX += nOffsetX;
        nY += nOffsetY;
    }

    sub_004CDBA0_SubmitOwnerRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    return 1;
}

// 0x004E0FD0
int __fastcall sub_004E0FD0_SkillStartMarkTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nMode;
    int nY;
    int nX;
    if (MONSTERS_GetSpawnMode_XY(pUnit, 1, nSkillId, nSkillLevel, &nMode, &nX, &nY) < 0)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, nX);
    SKILLS_SetParam3(pSkill, nY);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    return 1;
}

// 0x004E1B10
int __fastcall sub_004E1B10_FireAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        tMissileParams.nTargetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        tMissileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - CLIENTS_GetUnitX(pUnit);
        tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nSkillLevel);
    }

    return pMissilesTxtRecord ? 1 : 0;
}

// 0x004E3C50
int __fastcall sub_004E3C50_MissileAtTargetUnit(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget && pUnit)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.pOwner = pUnit;
        tMissileParams.dwFlags = 1;
        tMissileParams.nX = CLIENTS_GetUnitX(pTarget);
        tMissileParams.nY = CLIENTS_GetUnitY(pTarget);
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, 0x118);
            sub_004DA200_SetMotionVectorB(pMissile, 0, 0, -0x28, 1);
        }

        sub_00472C50(0);
        const short nOverlay = pSkillsTxtRecord->wPrgOverlay;
        if (nOverlay > 0)
        {
            sub_00470390(pTarget, nOverlay, 2, 0, 0, 0, 0, 0);
        }

        return 1;
    }

    return 0;
}

// 0x004E9040
void __fastcall sub_004E9040_AttackRating(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nSkillLevel, int* pValue, int* pColor, int nArg5, int nArg6)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    *pValue = 0;
    *pColor = 0;
    if (!pArg)
    {
        return;
    }

    if (pWeapon)
    {
        int bStatNotDynamic = 0;
        D2UnitStrc* pOwner = STATLIST_GetOwner(pWeapon, &bStatNotDynamic);
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
        *pValue = UNITS_GetAttackRate(pUnit);
        if (pOwner)
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, bStatNotDynamic);
        }
        else
        {
            STATLIST_ExpireUnitStatlist(pUnit, pWeapon);
        }
    }
    else
    {
        *pValue = UNITS_GetAttackRate(pUnit);
    }

    int nToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    nToHit += SKILLS_GetToHitFactor(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[3])
    {
        const int nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0);
        if (nBonus)
        {
            nToHit += nBonus;
            *pColor = 3;
        }
    }

    *pValue += *pValue * nToHit / 100;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
    {
        *pColor = 1;
    }
}

// 0x004F1D80
int __fastcall sub_004F1D80_MotionMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel) <= 0)
    {
        return 0;
    }

    const int nA = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nA <= 0)
    {
        return 0;
    }

    const int nB = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel);
    if (nB <= 0)
    {
        return 0;
    }

    const int nC = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[2], nSkillId, nSkillLevel);
    if (nC <= 0)
    {
        return 0;
    }

    const int nZ = nB * nA;
    const int nX = nC * nA;
    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pUnit;
    tMissileParams.dwFlags = 1;
    tMissileParams.nX = nTargetX;
    tMissileParams.nY = nTargetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;

    const short nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0)
    {
        tMissileParams.nMissile = nMissileA;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, nX, 0, nZ);
            sub_004DA200_SetMotionVectorB(pMissile, -nC, 0, -nB, 1);
        }
    }

    const short nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0)
    {
        tMissileParams.nMissile = nMissileB;
        D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004DA1D0_SetMotionVectorA(pMissile, nX, 0, nZ);
            sub_004DA200_SetMotionVectorB(pMissile, -nC, 0, -nB, 1);
        }
    }

    return 1;
}

// 0x004F4000
int __fastcall sub_004F4000_MissileByOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    if (!sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }

    if (!sub_004B11F0(pTarget))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    switch (pMonStats2TxtRecord->nOverlayHeight)
    {
    case 1:
        nMissile = pSkillsTxtRecord->wCltMissileB;
        break;

    case 3:
        nMissile = pSkillsTxtRecord->wCltMissileC;
        break;
    }

    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2000;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pTarget;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    return sub_004CD540_CreateMissile(&tMissileParams) != 0;
}
