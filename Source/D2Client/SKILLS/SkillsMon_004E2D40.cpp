#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
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
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_0045C3E0(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall sub_004B9A00(int nId, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5); // 0x004B9A00
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex); // 0x0063E7A0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x00648810
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900




struct D2MonTypeTxt
{
    char unk0x00[0x0A];
    unsigned short wStrPlur;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0
D2MonTypeTxt* __fastcall sub_004E4640_GetMonTypeTxtRecord(int nMonType); // 0x004E4640
void __fastcall sub_004E48B0_BuildText(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused); // 0x004E48B0
unsigned short __fastcall sub_004E6CE0_GetStringId(int nId, int nIndex); // 0x004E6CE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
extern D2CombinedStatIdStrc gaCombinedStatIds_0072CDD0[]; // 0x0072CDD0
extern D2FileIndexTextStrc gaFileIndexText_0072D6C0[]; // 0x0072D6C0
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
void __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pUnit, Unicode* pOut, int nUnused, int bQuantity, int nState, int nState2, int nFlag, int bNewline); // 0x004E60A0
int __fastcall sub_00526800(const Unicode* wszText); // 0x00526800
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void __fastcall sub_004E6720_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720
void __fastcall sub_004E67D0_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName); // 0x004FB1E0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
extern tagPALETTEENTRY gRGBAPalette_0081E668[]; // 0x0081E668

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[]; // 0x006D9D70
extern "C" const char szFmtRangeKK_006DBEAC[]; // 0x006DBEAC
extern "C" const char szFmtRangeK_006DBEB8[]; // 0x006DBEB8
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __fastcall sub_004E9870_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __cdecl sub_004E6FF0_SumProgressiveBonus(); // 0x004E6FF0
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0
int __stdcall sub_0063A380(D2UnitStrc* pUnit); // 0x0063A380
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit); // 0x0063A3A0
int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId); // 0x00626070
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
static int __stdcall sub_004E8EC0_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill); // 0x004E8EC0

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem);

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __fastcall sub_004E8FE0_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem); // 0x004E8FE0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004E2D40
D2UnitStrc* __fastcall sub_004E2D40_UpdateState22(D2UnitStrc* pUnit)
{
    int nX;
    int nY;
    D2UnitStrc* pMissile = 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pPath && sub_006505C0_TestPathFlag8(pPath))
    {
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_SPIDERLAY), 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        nX = UNITS_GetUnitXPosition(pUnit);
        nY = UNITS_GetUnitYPosition(pUnit);

        unsigned char aDirections[8];
        aDirections[0] = 10;
        aDirections[1] = 8;
        aDirections[2] = 22;
        aDirections[3] = 20;
        aDirections[4] = 18;
        aDirections[5] = 16;
        aDirections[6] = 14;
        aDirections[7] = 12;
        const unsigned char nDirection = aDirections[sub_0063E7A0_GetByteTableEntry(PATH_GetDirection(pPath))];

        int nDeltaX;
        int nDeltaY;
        sub_0063E7E0_GetDirectionDelta(nDirection, &nDeltaX, &nDeltaY);
        const int nSpawnX = nX + nDeltaX;
        const int nSpawnY = nY + nDeltaY;
        if (!DUNGEON_IsRoomInTown(sub_00463740_FindRoomAtPoint(pRoom, nSpawnX, nSpawnY)))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 0x25;
            tParams.pOwner = pUnit;
            tParams.nX = nSpawnX;
            tParams.nY = nSpawnY;
            tParams.nTargetX = nSpawnX + 2 * nDeltaX;
            tParams.nTargetY = nSpawnY + 2 * nDeltaY;
            tParams.nVelocity = 3;
            tParams.nSkillLevel = nSkillLevel;
            tParams.nMissile = MISSILE_SPIDERGOOLAY;
            pMissile = sub_004CD540_CreateMissile(&tParams);
            sub_004B9A00(0x726, pUnit, 0, 0, 0);
        }
    }

    return pMissile;
}

