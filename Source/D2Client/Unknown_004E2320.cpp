#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2Txt.h"
#include "D2MonTypeTxt.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GemsTxt;
struct tagPALETTEENTRY;
union D2SeedStrc;
struct D2SkillsTxt;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct Unicode;
struct D2ItemStatCostTxt;
struct D2CharStatsTxt;
struct D2MonStatsTxt;
struct D2MonTypeTxt;
struct D2CombinedStatStrc;
struct D2CombinedStatsStrc;
struct D2CombinedStatIdStrc;
struct D2FileIndexTextStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40
int __fastcall sub_0045C3E0(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall sub_004B9A00(int nId, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5); // 0x004B9A00
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0
int __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x00648810






extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0
void __fastcall TEXT_AppendUndeadDamageBonus(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused); // 0x004E48B0
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
extern D2CombinedStatIdStrc gaCombinedStatIds[]; // 0x0072CDD0
extern D2FileIndexTextStrc gaFileIndexText[]; // 0x0072D6C0
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
void __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pUnit, Unicode* pOut, int nUnused, int bQuantity, int nState, int nState2, int nFlag, int bNewline); // 0x004E60A0
int __fastcall UNICODE_StrLen(const Unicode* wszText); // 0x00526800
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void __fastcall TEXT_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720
void __fastcall SKILLDESC_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
int __stdcall PALETTE_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName); // 0x004FB1E0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
extern tagPALETTEENTRY gatRGBAPalette[]; // 0x0081E668

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC
extern "C" const char gszFmtRange[]; // 0x006D9D70
extern "C" const char gszFmtRangeKK[]; // 0x006DBEAC
extern "C" const char gszFmtRangeK[]; // 0x006DBEB8
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
static int __stdcall SKILLDESC_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill); // 0x004E8EC0

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem);

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __fastcall SKILLDESC_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem); // 0x004E8FE0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static void __stdcall sub_004E49C0_CollectCombinedStats(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2CombinedStatsStrc* pCombined); // 0x004E49C0

static int __stdcall sub_004E5A20_BuildCombinedStatText(int nStatId, Unicode* pOut, D2CombinedStatsStrc* pCombined); // 0x004E5A20

// 0x004E2320
int __fastcall sub_004E2320_StartSkillRollParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, (!pUnit ? -1 : pUnit->dwUnitId) + (!pTarget ? -1 : pTarget->dwUnitId));

    const int nMin = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    int nValue = sub_0045C3E0(&tSeed, nMax - nMin) + nMin;
    if (nValue < 1)
    {
        nValue = 1;
    }

    SKILLS_SetParam1(pSkill, nValue);
    SKILLS_SetParam2(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
    return 1;
}
