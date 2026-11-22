#include "D2StateIds.h"
#include "D2ClientUi.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Unicode.h"
#include "D2TxtItems.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2Path.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2ItemsWorld.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2AuxLevelEntryStrc;

struct Unicode;

struct D2InventoryGridInfoStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2AuxLevelEntryStrc
{
    int nType;
    const char* szFile;
    char bLocalized;
    char bFormat;
    char unk0x0A[2];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall sub_00478590(char nValue); // 0x00478590

void __fastcall INV_UpdateAuxBattleNetAddress(int nIndex); // 0x00482CA0

int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion); // 0x004FAD10

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480

void __fastcall sub_00460480(int bExpansion); // 0x00460480

int __cdecl sub_00460500_RunPopup(); // 0x00460500

int __cdecl sub_00460680_RunOkCancel(); // 0x00460680

int __cdecl sub_004605A0_RunPopup(); // 0x004605A0

void __cdecl sub_00477DD0(); // 0x00477DD0

void __cdecl sub_00481830(); // 0x00481830

void __cdecl sub_004DC0A0(); // 0x004DC0A0

void __fastcall sub_0044D530(int nValue); // 0x0044D530

void __cdecl sub_0044D510(); // 0x0044D510

void __cdecl sub_0044DD60(); // 0x0044DD60

extern "C" const char gsz640x146_006D4214[]; // 0x006D4214

extern "C" const char gsz640x292_006D421C[]; // 0x006D421C

extern int gnAuxLevelEntries_00721D94; // 0x00721D94

extern D2AuxLevelEntryStrc gaAuxLevelEntries_00721D98[]; // 0x00721D98

extern D2ConfigStrc* gpConfig_007A0438; // 0x007A0438

char gbCinematicStop_007BC9D4; // 0x007BC9D4

char gbCinematicPlaying_007BC9D5; // 0x007BC9D5

char gbCinematicWide_007BC9D6; // 0x007BC9D6

char gbCinematicBusy_007BC9D7; // 0x007BC9D7

char gbCinematicChain_007BC9D8; // 0x007BC9D8

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, int nFlags); // 0x0046EFD0

extern int gnScreenHeight_007A521C; // 0x007A521C

extern int gnScreenWidth_007A5220; // 0x007A5220

extern unsigned char gabGridColors_007BCAD8[]; // 0x007BCAD8

static void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY);

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2GemsTxt;

struct D2InvCompGridStrc;

struct D2CharStatsTxt;

struct D2UnitInvView;

struct D2SpeedNameStrc;

struct D2ItemTypeNameStrc;

struct D2DifficultyLevelsTxt;

struct D2MercStatLineStrc;

struct D2ElemDamageStrc;

struct D2SetItemsTxt;

struct D2SetsTxt;


extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth_007A5220; // 0x007A5220

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88

extern int gdwGlobal_007BCBE8; // 0x007BCBE8

extern int gdwGlobal_007BCBF0; // 0x007BCBF0

extern D2UnitStrc* gpHoverItem_007BCBF4; // 0x007BCBF4

extern int gnGlobal_007BCC20; // 0x007BCC20

extern int gnGlobal_007BCC4C; // 0x007BCC4C

extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58

extern "C" const char szCmnItemsH_006D9B90[]; // 0x006D9B90

extern "C" const char szInvCpp_006D9BC0[]; // 0x006D9BC0

int __cdecl sub_0044DCC0(); // 0x0044DCC0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __cdecl sub_00468830(); // 0x00468830

int __fastcall sub_0046EE80_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __cdecl INV_LoadUiRecords(); // 0x004835B0

void __stdcall INV_DrawItemSockets(D2UnitStrc*,D2InventoryGridInfoStrc*,int,int); // 0x00483E40

int __fastcall sub_004C2240(D2UnitStrc*); // 0x004C2240

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*,int,int); // 0x00621050

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMS_GetDimensions(D2UnitStrc*,unsigned char*,unsigned char*,const char*,int); // 0x006286C0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc*); // 0x00629900

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc*); // 0x0062A4E0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc*); // 0x0062BEB0

int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740

int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0

int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc*,int); // 0x0062ED50

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

int __stdcall INVENTORY_GetWieldType(D2UnitStrc*,D2InventoryStrc*); // 0x0063D340

struct D2UnitInvView
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2SpeedNameStrc
{
    unsigned short f_0;
    unsigned short unk0x02[2];
};

#pragma pack(push, 2)

struct D2ItemTypeNameStrc
{
    int nItemType;
    unsigned short f_4;
};

#pragma pack(pop)

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, void* pSkill, int bBonus); // 0x006442A0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A710

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId); // 0x00645C10

extern D2SpeedNameStrc gaSpeedNames_00721E88[6]; // 0x00721E88

extern D2ItemTypeNameStrc gaItemTypeNames_00721EB0[15]; // 0x00721EB0

extern int gaSpeedTable_00721F10[][5]; // 0x00721F10

extern int gaClassSpeedOffsets_00722078[][2]; // 0x00722078

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __fastcall sub_00479080_GetPetLife(int nUnitId); // 0x00479080

void __stdcall INV_DrawUnitName(D2UnitStrc* pUnit); // 0x0048A7D0

void __cdecl INV_DrawPanelLabels(); // 0x0048A890

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

void __stdcall sub_00525FB0_FormatInt(Unicode* pOut, int nValue, int nSize); // 0x00525FB0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

extern D2MercStatLineStrc gaMercStatLines_007221A8[12]; // 0x007221A8

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

static void INV_DrawMercStats(D2UnitStrc* pUnit); // 0x0048A990

struct D2SetsTxt
{
    char unk0x00[0x02];
    unsigned short wStrName;
    char unk0x04[0x08];
    int nSetItems;
    char unk0x10[0x100];
    D2SetItemsTxt* pSetItems[6];
};

Unicode* __fastcall sub_00452170(Unicode* pText); // 0x00452170

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId); // 0x00483410

D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex); // 0x00483440

int __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText); // 0x00485410

void __stdcall INV_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText); // 0x00485EE0

void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...); // 0x0048BE80

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410

void __fastcall sub_004E6560_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6560

void __fastcall sub_004E6680_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6680

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625E60

int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625EF0

int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit); // 0x00626020

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062BA60

int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem); // 0x0062C060

int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem); // 0x0062C0B0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

extern int gnGlobal_00721E38; // 0x00721E38

extern int gnGlobal_00721E3C; // 0x00721E3C

extern int gnGlobal_00721E40; // 0x00721E40

extern int gnGlobal_00721E44; // 0x00721E44

extern int gnGlobal_00721E48; // 0x00721E48

extern int gdwGlobal_007BCBE4; // 0x007BCBE4

extern D2InventoryGridInfoStrc gGrid_007BCA78;                                                              // 0x007BCA78

extern D2InventoryGridInfoStrc gGrid_007BCB40;                                                              // 0x007BCB40

extern int gnGlobal_007BCC50;                                                                               // 0x007BCC50

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                          // 0x00478680

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

int __cdecl sub_00486D10_CheckTick();                                                                      // 0x00486D10

void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt);                            // 0x0049FF90

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                  // 0x004B9A00

int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem);                                                            // 0x004C1E20

void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem);                                                           // 0x004C21F0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem);                                                             // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem);                                                             // 0x00628C70

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                 // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                 // 0x00648900

extern D2InvRectStrc gInvRect_007BCAA0;                                                                     // 0x007BCAA0

#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)

#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)

#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)

#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30

void __cdecl UI_CancelCursorItemUse();                                                                                // 0x00453EC0

int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0

int __cdecl INV_ResetNpcButtons();                                                                    // 0x00487BE0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0

extern D2InventoryGridInfoStrc gGrid_007BCB58;                                                              // 0x007BCB58

#define gnGlobal_007BCB5C (gGrid_007BCB58.nGridLeft)

#define gnGlobal_007BCB60 (gGrid_007BCB58.nGridRight)

#define gnGlobal_007BCB64 (gGrid_007BCB58.nGridTop)

#define gnGlobal_007BCB68 (gGrid_007BCB58.nGridBottom)

extern D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4

#define gnGlobal_007BCA7C (gGrid_007BCA78.nGridLeft)

#define gnGlobal_007BCA80 (gGrid_007BCA78.nGridRight)

#define gnGlobal_007BCA84 (gGrid_007BCA78.nGridTop)

#define gnGlobal_007BCA88 (gGrid_007BCA78.nGridBottom)

#define gnGlobal_007BCB44 (gGrid_007BCB40.nGridLeft)

#define gnGlobal_007BCB48 (gGrid_007BCB40.nGridRight)

#define gnGlobal_007BCB4C (gGrid_007BCB40.nGridTop)

#define gnGlobal_007BCB50 (gGrid_007BCB40.nGridBottom)

extern D2InventoryGridInfoStrc gGrid_007BCB70;                                                              // 0x007BCB70

#define gnGlobal_007BCB74 (gGrid_007BCB70.nGridLeft)

#define gnGlobal_007BCB78 (gGrid_007BCB70.nGridRight)

#define gnGlobal_007BCB7C (gGrid_007BCB70.nGridTop)

#define gnGlobal_007BCB80 (gGrid_007BCB70.nGridBottom)

void __stdcall INV_GridClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004917C0

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY); // 0x00483AB0

int __cdecl sub_004888C0_CanUseCursor(); // 0x004888C0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

extern D2InventoryGridInfoStrc gGrid_007BCA30; // 0x007BCA30
D2InventoryGridInfoStrc gGrid_007BCA50; // 0x007BCA50
D2InventoryGridInfoStrc gGrid_007BCAB0; // 0x007BCAB0
extern D2InventoryGridInfoStrc gGrid_007BCB18; // 0x007BCB18
D2InvRectStrc gInvRect_007BCA68; // 0x007BCA68
D2InvRectStrc gInvRect_007BCA90; // 0x007BCA90
D2InvRectStrc gInvRect_007BCAC8; // 0x007BCAC8
D2InvRectStrc gInvRect_007BCAE0; // 0x007BCAE0
D2InvRectStrc gInvRect_007BCAF4; // 0x007BCAF4
D2InvRectStrc gInvRect_007BCB08; // 0x007BCB08
extern D2InvRectStrc gInvRect_007BCB30; // 0x007BCB30
D2InvRectStrc gInvRect_007BCBA0; // 0x007BCBA0
extern D2InventoryGridInfoStrc gInventoryGrid_007BCBC0; // 0x007BCBC0
extern D2InvRectStrc gRect_007BCBB0; // 0x007BCBB0
extern D2InvCompGridStrc gaBodyLocRects_007BCD38[11]; // 0x007BCD38
int gnGlobal_007BCBDC; // 0x007BCBDC
int gnGlobal_007BCBE0; // 0x007BCBE0
int gnUiRecordRow_007A5218; // 0x007A5218
int gnUiRecordRow_007BEEA8; // 0x007BEEA8

void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect); // 0x0065C180
void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0
void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270

// 0x00482E00
static int INV_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    SFileCloseFile(hFile);
    return 1;
}

// 0x00482E30
static void INV_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    sub_00525260(szLang, 0);
    sprintf(szOut, szFormat, gszDataLocal_006D41A8, szLang, szFile);
    if (INV_ArchiveFilePresent(szOut))
        return;
    if (STRTABLE_GetLanguage())
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "ENG", szFile);
        INV_ArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal_006D41A8, "CHI", szFile);
        INV_ArchiveFilePresent(szOut);
    }
}

// 0x00482EF0
void __fastcall INV_PlayCinematic(int nIndex)
{
    int nMode;
    int bPlayed;
    int bLoaded;
    int bExpansion;
    char szName[0x104];
    char szFile[0x104];

    D2_ASSERT(nIndex < gnAuxLevelEntries_00721D94, 0xEF);
    gbCinematicBusy_007BC9D7 = 1;
    INV_UpdateAuxBattleNetAddress(nIndex);
    if (gbCinematicPlaying_007BC9D5)
        return;

    if (nIndex >= gnAuxLevelEntries_00721D94)
    {
        sub_00478590(0x48);
        gbCinematicBusy_007BC9D7 = 0;
        return;
    }

    nMode = 0;
    if (gaAuxLevelEntries_00721D98[nIndex].bFormat)
    {
        if (gbCinematicWide_007BC9D6)
        {
            sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x292_006D421C);
        }
        else
        {
            nMode = 2;
            sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x146_006D4214);
        }
    }
    else
    {
        strcpy(szName, gaAuxLevelEntries_00721D98[nIndex].szFile);
    }

    sub_00481830();
    sub_004DCA30();
    sub_004FAD70();

    bExpansion = 0;
    bPlayed = bLoaded = 0;
    if (nIndex == 7)
    {
        bExpansion = 1;
        char szPath[0x104];
        FOG_GetInstallPath(szPath, 0x104);
        strcat(szPath, "d2game.dll");
        void* hFile = CreateFileA(szPath, 0, 1, 0, 3, 0x80, 0);
        if (hFile != (void*)-1)
        {
            CloseHandle(hFile);
        }
        else
        {
            sub_0044D530(0);
            goto lMissing;
        }
    }
    else if (nIndex == 6)
    {
        bExpansion = 1;
    }

    sub_00460480(bExpansion);
    if (ARCHIVE_LoadVideoArchives(bExpansion ? (void*)sub_00460500_RunPopup : (void*)sub_00460680_RunOkCancel, 0, bExpansion))
    {
        bLoaded = 1;
        if (gaAuxLevelEntries_00721D98[nIndex].bLocalized)
            INV_BuildLocalizedVideoPath(szFile, "%s\\video\\%s\\%s", szName);
        else
            sprintf(szFile, "%s\\video\\%s", szDataGlobal_006D4118, szName);

        gbCinematicPlaying_007BC9D5 = 1;
        sub_004DC0A0();
        sub_00455F20(0x12, 0, 0);
        if (sub_004F9050())
        {
            if (gbCinematicStop_007BC9D4)
                WINDOW_OpenSmackCutscene(szFile, nMode, 0);
            else
                WINDOW_OpenSmackCutscene(szFile, nMode, (void*)sub_00477DD0);
            bPlayed = 1;
        }

        if (nIndex != 5 || !gbCinematicChain_007BC9D8)
        {
            D2Win_10004(D2GFX_GetResolutionMode());
            sub_00455F20(0x12, 1, 0);
            gbCinematicPlaying_007BC9D5 = 0;
        }
    }

    if (gbCinematicChain_007BC9D8)
    {
        if (bLoaded)
            sub_004FAD70();
        if (bPlayed)
            D2Win_10004(D2GFX_GetResolutionMode());

        sub_00460480(1);
        if (ARCHIVE_LoadVideoArchives((void*)sub_00460500_RunPopup, 0, 1))
        {
            nIndex = 6;
            if (gbCinematicWide_007BC9D6)
            {
                sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x292_006D421C);
            }
            else
            {
                nMode = 2;
                sprintf(szName, gaAuxLevelEntries_00721D98[nIndex].szFile, gsz640x146_006D4214);
            }

            if (gaAuxLevelEntries_00721D98[nIndex].bLocalized)
                INV_BuildLocalizedVideoPath(szFile, "%s\\video\\%s\\%s", szName);
            else
                sprintf(szFile, "%s\\video\\%s", szDataGlobal_006D4118, szName);

            if (sub_004F9050())
            {
                WINDOW_OpenSmackCutscene(szFile, nMode, (void*)sub_00477DD0);
                INV_UpdateAuxBattleNetAddress(nIndex);
            }
        }

        D2Win_10004(D2GFX_GetResolutionMode());
        sub_00455F20(0x12, 1, 0);
        gbCinematicPlaying_007BC9D5 = 0;
        gbCinematicChain_007BC9D8 = 0;
        D2Win_10177(4);
    }

    sub_00478590(0x48);
    if (gbCinematicStop_007BC9D4)
    {
        gbCinematicStop_007BC9D4 = 0;
        sub_0044DD60();
    }
    else if (nIndex == 7)
    {
lMissing:
        sub_0044D530(0);
        gbCinematicStop_007BC9D4 = 0;
        sub_0044D510();
        sub_0044DD60();
    }

    sub_004FAD70();
    ARCHIVE_LoadExpansionArchives(sub_00460500_RunPopup, sub_004605A0_RunPopup, 0, gpConfig_007A0438);
    gbCinematicBusy_007BC9D7 = 0;
}

// 0x004834E0
void __fastcall INV_ReplaceToken(Unicode* pText, int nIndex, const Unicode* pInsert)
{
    Unicode wszBuffer[400];
    const int nDigit = nIndex + '0';
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength - 1; ++i)
    {
        if (pText[i].wChar == '%' && pText[i + 1].wChar == nDigit)
        {
            sub_00526700(wszBuffer, pInsert);
            const Unicode* pEnd = &wszBuffer[sub_00526800(wszBuffer) - 1];
            const int bSpace = pEnd->wChar == ' ';
            Unicode* pDest = pText;
            const Unicode* pRest;
            if (!(bSpace && pDest[i + 2].wChar == ' '))
            {
                pRest = &pDest[i + 2];
                sub_00526700(wszBuffer, pRest);
            }
            else
            {
                pRest = &pDest[i + 3];
                sub_00526700(wszBuffer, pRest);
            }
            sub_005267E0(pDest, wszBuffer);
            return;
        }
        wszBuffer[i] = pText[i];
    }
}


// 0x004835B0
void __cdecl INV_LoadUiRecords()
{
    if (gnUiRecordRow_007A5218 != gnUiRecordRow_007BEEA8)
    {
        gnUiRecordRow_007BEEA8 = gnUiRecordRow_007A5218;
        gnGlobal_007BCBDC = 0;
        gnGlobal_007BCBE0 = 0;
    }

    if (!gnGlobal_007BCBDC)
    {
        const int nClass = sub_00621050(sub_00463DD0_GetPlayerUnit(), 0, sub_0044DCC0());
        sub_0065C180_2(nClass, gnUiRecordRow_007A5218, &gInvRect_007BCAA0);
        sub_0065C1F0_2(nClass, gnUiRecordRow_007A5218, &gGrid_007BCB88);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[4], 0);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[3], 1);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[5], 2);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[1], 3);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[2], 4);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[6], 5);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[7], 6);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[8], 7);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[9], 8);
        sub_0065C270_2(nClass, gnUiRecordRow_007A5218, &gaCompGrids_007BCC58[10], 9);
        sub_0065C180_2(13, gnUiRecordRow_007A5218, &gInvRect_007BCB08);
        sub_0065C1F0_2(13, gnUiRecordRow_007A5218, &gInventoryGrid_007BCBC0);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[4], 0);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[3], 1);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[5], 2);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[1], 3);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[2], 4);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[6], 5);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[7], 6);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[8], 7);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[9], 8);
        sub_0065C270_2(13, gnUiRecordRow_007A5218, &gaBodyLocRects_007BCD38[10], 9);
        sub_0065C180_2(6, gnUiRecordRow_007A5218, &gInvRect_007BCAE0);
        sub_0065C1F0_2(6, gnUiRecordRow_007A5218, &gGrid_007BCB18);
        sub_0065C180_2(7, gnUiRecordRow_007A5218, &gInvRect_007BCA90);
        sub_0065C1F0_2(7, gnUiRecordRow_007A5218, &gGrid_007BCA30);
        sub_0065C180_2(8, gnUiRecordRow_007A5218, &gInvRect_007BCA68);
        sub_0065C1F0_2(8, gnUiRecordRow_007A5218, &gGrid_007BCB40);
        sub_0065C180_2(12, gnUiRecordRow_007A5218, &gInvRect_007BCAF4);
        sub_0065C1F0_2(12, gnUiRecordRow_007A5218, &gGrid_007BCA78);
        sub_0065C180_2(9, gnUiRecordRow_007A5218, &gInvRect_007BCB30);
        sub_0065C1F0_2(9, gnUiRecordRow_007A5218, &gGrid_007BCB70);
        sub_0065C180_2(10, gnUiRecordRow_007A5218, &gInvRect_007BCBA0);
        sub_0065C1F0_2(10, gnUiRecordRow_007A5218, &gGrid_007BCAB0);
        sub_0065C180_2(11, gnUiRecordRow_007A5218, &gInvRect_007BCAC8);
        sub_0065C1F0_2(11, gnUiRecordRow_007A5218, &gGrid_007BCA50);
        gnGlobal_007BCBDC = 1;
    }

    int nUnitId;
    if (!gnGlobal_007BCBE0 && gdwGlobal_007BCBF0 && NPCMENU_GetInteractNpcId(&nUnitId))
    {
        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
        if (pUnit)
        {
            const int nClass = sub_00621050(pUnit, 0, sub_0044DCC0());
            sub_0065C180_2(nClass, gnUiRecordRow_007A5218, &gRect_007BCBB0);
            sub_0065C1F0_2(nClass, gnUiRecordRow_007A5218, &gGrid_007BCB58);
            gnGlobal_007BCBE0 = 1;
        }
    }
}

// 0x004839D0
static void __stdcall sub_004839D0_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY)
{
    for (int nRow = nY; nRow < nY + nHeight; ++nRow)
    {
        for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
        {
            const int nLeft = pGrid->nGridBoxWidth * nColumn + pGrid->nGridLeft;
            const int nTop = pGrid->nGridBoxHeight * nRow + pGrid->nGridTop;
            if (nLeft >= 0 && nLeft < gnScreenWidth_007A5220 && nTop >= 0 && nTop < gnScreenHeight_007A521C)
            {
                sub_0046EFD0_DrawFramedBox(nLeft, nTop, pGrid->nGridBoxWidth, pGrid->nGridBoxHeight, gabGridColors_007BCAD8[nColor], 0);
            }
        }
    }
}

// build: context sub_004839D0_Shim
// calling-convention shim (not game code)
void __fastcall sub_004839D0_Shim(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight)
{
    sub_004839D0_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
    sub_004839D0_DrawGridCells(pGrid, nY, 0, nHeight, nWidth, nX);
}

static void sub_00483A70_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor)
{
    if (nColor == 2)
    {
        return;
    }
    const int nLeft = pCompGrid->rect.nLeft;
    const int nTop = pCompGrid->rect.nTop;
    if (nLeft >= 0 && nLeft < gnAutomapWidth_007A5220 && nTop >= 0 && nTop < gnAutomapHeight_007A521C)
    {
        sub_0046EFD0_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[nColor], 0);
    }
}

static int sub_004843E0_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gdwGlobal_007BCBF0 == 0xA || gdwGlobal_007BCBF0 == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, szInvCpp_006D9BC0))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (ITEMS_GetMaxSockets(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, szInvCpp_006D9BC0))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, szInvCpp_006D9BC0))
    {
        return 0;
    }
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    return INVENTORY_GetItemCount(pInventory) < ITEMS_GetSockets(pItem);
}

// 0x004844A0
static void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory)
{
    if (gdwGlobal_007BCBF0 == 1 && sub_00468730() < gnGlobal_0071146C / 2)
    {
        return;
    }
    if (sub_00468740() >= gnGlobal_00711470 - 0x27)
    {
        return;
    }
    if (sub_00468730() < gnGlobal_0071146C / 2)
    {
        gnGlobal_007BCC20 = 0;
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (!pCursorItem || !gdwGlobal_007BCBE8)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, szCmnItemsH_006D9B90, 0x6DC);
    if (ITEMS_CheckBodyLocation(pCursorItem, gnGlobal_007BCC20) && ITEMS_CheckRequirements(pCursorItem, sub_00463DD0_GetPlayerUnit(), 0, 0, 0, 0))
    {
        sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[gnGlobal_007BCC20], 1);
    }
    else if (sub_004843E0_CanSocketInto(INVENTORY_GetItemFromBodyLoc(pInventory, gnGlobal_007BCC20), pCursorItem))
    {
        sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[gnGlobal_007BCC20], 1);
    }
    else
    {
        sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[gnGlobal_007BCC20], 0);
    }
}

static __forceinline void sub_004845A0_DrawOtherHandFrame(D2InvCompGridStrc* pCompGrid)
{
    const int nLeft = pCompGrid->rect.nLeft;
    if (nLeft >= 0 && nLeft < gnAutomapWidth_007A5220)
    {
        const int nTop = pCompGrid->rect.nTop;
        if (nTop >= 0 && nTop < gnAutomapHeight_007A521C)
        {
            sub_0046EFD0_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[0], 0);
        }
    }
}

// 0x004845A0
void __cdecl INV_DrawEquippedItems()
{
    unsigned char nWidth,nHeight;
    D2UnitStrc* pItem;
    D2UnitStrc* pOther;
    int nBodyLoc;
    int nOffsetX=0;
    int nOffsetY=0;
    if(sub_0044DCC0() && gnGlobal_007BCC4C)
    {
        nOffsetX=4;
        nOffsetY=-4;
    }
    D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    UNITS_GetInventoryRecordId(pPlayer,0,sub_0044DCC0());
    INV_LoadUiRecords();
    for(nBodyLoc=0;nBodyLoc<11;++nBodyLoc)
    {
        pOther=0;
        pItem=INVENTORY_GetItemFromBodyLoc(pInventory,nBodyLoc);
        if(!pItem)continue;
        ITEMS_GetDimensions(pItem,&nWidth,&nHeight,szCmnItemsH_006D9B90,0x6DC);
        int bDualWield=INVENTORY_GetWieldType(pPlayer,pInventory)==2;
        switch(nBodyLoc)
        {
        case 5:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,4);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                sub_0046EE80_DrawItemCel(pItem,gaCompGrids_007BCC58[4].rect.nLeft+((gaCompGrids_007BCC58[5].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids_007BCC58[4].rect.nTop+((gaCompGrids_007BCC58[5].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids_007BCC58[4]);
            }
            break;
        case 4:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,5);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                sub_0046EE80_DrawItemCel(pItem,gaCompGrids_007BCC58[5].rect.nLeft+((gaCompGrids_007BCC58[4].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids_007BCC58[5].rect.nTop+((gaCompGrids_007BCC58[4].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids_007BCC58[5]);
            }
            break;
        }
        int nX=gaCompGrids_007BCC58[nBodyLoc].rect.nLeft+((gaCompGrids_007BCC58[nBodyLoc].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1);
        int nY=gaCompGrids_007BCC58[nBodyLoc].rect.nTop+((gaCompGrids_007BCC58[nBodyLoc].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1);
        switch(nBodyLoc)
        {
        case 8:nX+=2;
        case 2:case 6:case 7:case 10:nY-=2;break;
        case 3:nX+=3;break;
        case 9:nX+=2;nY-=4;break;
        case 4:case 5:nX+=nOffsetX;nY+=nOffsetY;break;
        }
        if(pItem==gpHoverItem_007BCBF4 && gdwGlobal_007BCBE8)
        {
            if(sub_00468830()==8)sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
            else sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],1);
            sub_0046EE80_DrawItemCel(pItem,nX,nY);
            if(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem)>0 && ITEMS_CheckItemFlag(pItem,0x800,0x673,szInvCpp_006D9BC0))
                INV_DrawItemSockets(pItem,&gGrid_007BCB88,nX,nY);
        }
        else
        {
            if (pOther || (!ITEMS_GetAmmoType(pItem) && !ITEMS_GetQuiverType(pItem)))
            {
                if (ITEMS_CheckRequirements(pItem,pPlayer,0,0,0,0) && !sub_004C2240(pItem) && ITEMS_CanBeEquipped(pItem))
                {
                    if(!ITEMS_CheckItemFlag(pItem,0x10,0x682,szInvCpp_006D9BC0))sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],4);
                }
                else
                {
                    sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
                }
            }
            else
            {
                sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
            }
            sub_0046EE80_DrawItemCel(pItem,nX,nY);
        }
    }
    INV_DrawBodyLocPlacement(pInventory);
}

// 0x00484B10
static void __stdcall INV_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText)
{
    int bEthereal = 0;
    Unicode wszLabel[16];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_00526F20(wszLabel, &gszEmptyAssertText, 15);
    sub_005267E0(pText, wszLabel);
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x6C1, ".\\UI\\inv.cpp"))
    {
        sub_00526F20(wszLabel, "Ethereal", 15);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x58D9));
        bEthereal = 1;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x800, 0x6C9, ".\\UI\\inv.cpp"))
    {
        if (bEthereal)
        {
            sub_00526F20(wszLabel, ", ", 15);
            sub_00526700(pText, wszLabel);
        }
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD7D));
        Unicode wszNumber[10];
        char szNumber[10];
        const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
        SStrPrintf(szNumber, 10, "(%i)", ITEMS_GetSockets(pItem));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
        return;
    }
    if (bEthereal)
    {
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484DB0
static void __stdcall INV_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf(szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
    }
}

// 0x00484E90
static void __stdcall INV_AppendDurability(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (ITEMS_HasDurability(pItem) && STATLIST_GetMaxDurabilityFromUnit(pItem) > 0 && !ITEMS_CheckIfThrowable(pItem))
    {
        int bBonus = 0;
        if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MAXDURABILITY_PERCENT, 0))
        {
            bBonus = 1;
        }
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD81));
        SStrPrintf(szNumber, 10, szFmtInt_006D6454, STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0));
        sub_00526700(pText, pColorStart);
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD87));
        sub_00526700(pText, pColorStart);
        SStrPrintf(szNumber, 10, szFmtInt_006D6454, STATLIST_GetMaxDurabilityFromUnit(pItem));
        sub_00526F20(wszNumber, szNumber, 9);
        if (bBonus)
        {
            INV_PrefixColorCode(wszNumber, 3);
        }
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484FF0
static void __stdcall INV_AppendLabeledNumber(int nValue, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD8D));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x004850A0
static void __stdcall INV_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqStr + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD82));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x00485170
static void __stdcall INV_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqDex + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD83));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x00485BE0
static void __stdcall INV_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem)
{
    int nBlock = STATLIST_UnitGetStatValue(pItem, STAT_TOBLOCK, 0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        const int nClass = pPlayer->dwClassId;
        D2CharStatsTxt* pCharStats = (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClass] : 0;
        nBlock += pCharStats->nBlockFactor;
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_HOLYSHIELD);
        if (pSkill && STATES_CheckState(pPlayer, STATE_HOLYSHIELD))
        {
            const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            nBlock += D2COMMON_11036_GetMonCurseResistanceSubtraction(nLevel, SKILL_HOLYSHIELD);
        }
        if (nBlock > 0x4B)
        {
            nBlock = 0x4B;
        }
    }
    if (!nBlock)
    {
        return;
    }
    Unicode wszBlock[32];
    char szBlock[32];
    Unicode wszText[256];
    SStrPrintf(szBlock, 32, "%d%%\n", nBlock);
    sub_00526F20(wszBlock, szBlock, 32);
    if (nBlock > pItemsTxt->nBlock)
    {
        INV_PrefixColorCode(wszBlock, 3);
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x2B0A));
    INV_PrefixColorCode(wszText, 0);
    sub_005267E0(pText, wszText);
    sub_00526700(pText, wszBlock);
}

// 0x00485D40
static void __stdcall INV_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    int nMin = pItemsTxt->nMinDam;
    int nMax = pItemsTxt->nMaxDam;
    int nStringId;
    if (ITEMSIsA(pItem, 0x33))
    {
        nStringId = 0xD8C;
        D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_HOLYSHIELD);
        if (pSkill && STATES_CheckState(pUnit, STATE_HOLYSHIELD))
        {
            const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            nMin += SKILLS_GetMinPhysDamage(pUnit, SKILL_HOLYSHIELD, nLevel, 1) >> 8;
            nMax += SKILLS_GetMaxPhysDamage(pUnit, SKILL_HOLYSHIELD, nLevel, 1) >> 8;
        }
    }
    else
    {
        if (!ITEMSIsA(pItem, 0xF))
        {
            return;
        }
        nStringId = 0x5516;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(nStringId));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nMin);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD88));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nMax);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x00486100
static void __stdcall sub_00486100_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf(szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x004861D0
static void __stdcall INV_AppendAttackSpeed(Unicode* pText, D2UnitStrc* pItem)
{
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pColorAlt = D2LANG_GetStringFromTblIndex(0xF9C);
    D2UnitStrc* pStoredUnit = sub_00463DE0_GetPlayerUnit();
    const int nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pStoredUnit, pItem);
    int bBonus = 0;
    if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_FASTERATTACKRATE, 0))
    {
        bBonus = 1;
    }
    int nSpeed;
    if (nAttackSpeed >= 0x1C)
    {
        nSpeed = 5;
    }
    else if (nAttackSpeed < 10)
    {
        nSpeed = 1;
    }
    else
    {
        D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
        const int bMissile = (ITEMSIsA(pItem, 0x23) || ITEMSIsA(pItem, 0x1B)) ? 1 : 0;
        const int nClass = !pUnit ? -1 : pUnit->dwClassId;
        nSpeed = gaSpeedTable_00721F10[nAttackSpeed - 10][gaClassSpeedOffsets_00722078[nClass][bMissile]];
    }
    int nFound = -1;
    for (int i = 0; i < 15; ++i)
    {
        if (ITEMSIsA(pItem, gaItemTypeNames_00721EB0[i].nItemType))
        {
            nFound = i;
            break;
        }
    }
    if (nFound >= 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(gaItemTypeNames_00721EB0[nFound].f_4));
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, pColorAlt);
        sub_00526700(pText, pColorStart);
    }
    Unicode wszText[256];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(gaSpeedNames_00721E88[nSpeed].f_0));
    if (bBonus)
    {
        INV_PrefixColorCode(wszText, 3);
    }
    sub_00526700(pText, wszText);
    sub_00526700(pText, pColorEnd);
}

// build: context sub_E05_Emit_Tooltip
void __stdcall sub_E05_Emit_Tooltip(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, int nValue, Unicode* pText)
{
    INV_AppendEtherealSocketed(pItem, pText);
    INV_AppendQuantity(pItemsTxt, pItem, pText + 0x100);
    INV_AppendDurability(pItem, pText + 0x200);
    INV_AppendLabeledNumber(nValue, pText + 0x300);
    INV_AppendReqStr(pItemsTxt, nValue, pText + 0x400);
    INV_AppendReqDex(pItemsTxt, nValue, pText + 0x500);
    INV_AppendThrowDamage(pItem, pItemsTxt, pText + 0x600);
    sub_00486100_AppendStackQuantity(pItem, pText + 0x700);
    INV_AppendBlockChance(pText + 0x800, pItemsTxt, pItem);
    INV_AppendAttackSpeed(pText + 0x900, pItem);
}

struct D2InventoryStrc;

struct D2SkillStrc;

struct D2UnitStrc;

// 0x0048A990
static void INV_DrawMercStats(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    const int nOldFont = sub_00502EF0(0);
    for (unsigned int i = 0; i < 12; ++i)
    {
        int nColor = 0;
        Unicode wszText[0x80];
        char szText[0x80];
        for (int k = 0; k < 0x80; k++)
            wszText[k].wChar = 0;
        int nValue = STATLIST_UnitGetStatValue(pUnit, gaMercStatLines_007221A8[i].nStatId, 0);
        const int nBase = STATLIST_GetUnitBaseStat(pUnit, gaMercStatLines_007221A8[i].nStatId, 0);
        if (nValue > nBase)
        {
            nColor = 3;
        }
        else if (nValue < nBase)
        {
            nColor = 1;
        }

        const int nLeft = gaMercStatLines_007221A8[i].nLeft + gnGlobal_007A2858;
        const int nRight = gaMercStatLines_007221A8[i].nRight + gnGlobal_007A2858;
        int nY = gaMercStatLines_007221A8[i].nY - gnGlobal_007A285C - 2;

        switch (gaMercStatLines_007221A8[i].nStatId)
        {
        case 6:
        {
            const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
            int nLife = sub_00479080_GetPetLife(sub_00451F50_GetUnitGUID(pUnit)) * nMaxLife / 100;
            if (!sub_00464820_IsDeadOrDying(pUnit) && nLife < 0)
            {
                nLife = 1;
            }
            SStrPrintf(szText, 0x80, "%d / %d", nLife, nMaxLife);
            sub_00526320_ToUnicode(wszText, szText, 0x80);
            if ((STATLIST_GetUnitBaseStat(pUnit, STAT_MAXHP, 0) >> 8) < nMaxLife)
            {
                nColor = 3;
            }
            break;
        }
        case 0x15:
        {
            D2UnitStrc* pWeapon = 0;
            int nFlat = 0;
            int nPercent = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
            const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
            const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
            if (nMinPercent + nPercent > 0)
            {
                nColor = 3;
            }
            else if (nMinPercent + nPercent < 0)
            {
                nColor = 1;
            }

            if (pUnit->pInventory)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, 4);
            }

            int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
            if (pWeapon)
            {
                if (ITEMS_CheckWeaponIfTwoHanded(pWeapon))
                {
                    nValue -= STATLIST_UnitGetStatValue(pWeapon, STAT_MINDAMAGE, 0);
                    nMaxDamage -= STATLIST_UnitGetStatValue(pWeapon, STAT_MAXDAMAGE, 0);
                    nValue += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
                    nMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
                }

                nFlat = ITEMS_GetStrengthBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFlat / 100;
                }

                nFlat = ITEMS_GetDexBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFlat / 100;
                }

                nPercent += SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, 0, 1);
                nFlat = STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_NORMALDAMAGE, 0);
            }
            else
            {
                if (sub_00451F60_UnitClassId(pUnit) == 0x10F)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
                }
                else
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
                }
            }

            if (nPercent <= -90)
            {
                nPercent = -90;
            }

            int nMin = (nMinPercent + nPercent + 100) * nValue / 100 + nFlat;
            int nMax = (nMaxPercent + nPercent + 100) * nMaxDamage / 100 + nFlat;

            const D2ElemDamageStrc aElem[4] =
            {
                { 0x30, 0x31, 1 },
                { 0x32, 0x33, 9 },
                { 0x34, 0x35, 3 },
                { 0x36, 0x37, 3 },
            };
            for (int k = 0; k < 4; ++k)
            {
                nValue = STATLIST_UnitGetStatValue(pUnit, aElem[k].nMinStat, 0);
                const int nElemMax = STATLIST_UnitGetStatValue(pUnit, aElem[k].f_4, 0);
                if (nValue || nElemMax)
                {
                    nColor = aElem[k].nColor;
                }
                nMin += nValue;
                nMax += nElemMax;
            }

            nValue = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
            nFlat = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
            if (nValue || nFlat)
            {
                int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
                if (nLength <= 0)
                {
                    int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
                    if (nCount < 1)
                    {
                        nCount = 1;
                    }
                    nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
                }
                nMin += (nLength * nValue) >> 8;
                nColor = 2;
                nMax += (nLength * nFlat) >> 8;
            }

            SStrPrintf(szText, 0x80, "%d-%d", nMin, nMax);
            sub_00526320_ToUnicode(wszText, szText, 0x80);
            break;
        }
        case 0x1F:
        {
            const int nDefense = UNITS_GetDefense(pUnit);
            if (STATES_CheckStateMaskArmBlueOnUnit(pUnit))
            {
                nColor = 3;
            }
            sub_00525FB0_FormatInt(wszText, nDefense, 0x80);
            break;
        }
        case 0x27:
        case 0x29:
        case 0x2B:
        case 0x2D:
        {
            D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(sub_0044DCD0_GetDifficulty());
            int nMaxResist = 0;
            switch (gaMercStatLines_007221A8[i].nStatId)
            {
            case 0x27:
                if (STATES_CheckStateMaskRFBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRFRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXFIRERESIST, 0);
                break;
            case 0x29:
                if (STATES_CheckStateMaskRLBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRLRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXLIGHTRESIST, 0);
                break;
            case 0x2B:
                if (STATES_CheckStateMaskRCBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRCRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXCOLDRESIST, 0);
                break;
            case 0x2D:
                if (STATES_CheckStateMaskRPBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRPRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXPOISONRESIST, 0);
                break;
            }

            if (sub_0044DCC0())
            {
                nValue += pDifficulty->dwResistPenalty;
            }
            else
            {
                switch (sub_0044DCD0_GetDifficulty())
                {
                case 1:
                    nValue -= 20;
                    break;
                case 2:
                    nValue -= 50;
                    break;
                }
            }

            nMaxResist = D2_MIN(nMaxResist + 75, 95);
            nValue = D2_MIN(D2_MAX(nValue, -100), nMaxResist);
            if (nValue >= nMaxResist)
            {
                nValue = nMaxResist;
                nColor = 4;
            }
            else if (nValue < 0)
            {
                nColor = 1;
            }
            sub_00525FB0_FormatInt(wszText, nValue, 0x80);
            break;
        }
        default:
            sub_00525FB0_FormatInt(wszText, nValue, 0x80);
            break;
        }

        sub_00502EF0(0);
        int nWidth = 0;
        int nHeight = 0;
        D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
        if (gaMercStatLines_007221A8[i].nMaxWidth && nWidth > gaMercStatLines_007221A8[i].nMaxWidth)
        {
            sub_00502EF0(6);
            ++nY;
        }

        if (!gaMercStatLines_007221A8[i].nLeft)
        {
            sub_00502320(wszText, nRight - sub_00501820(wszText), nY, nColor, 0);
        }
        else if (!gaMercStatLines_007221A8[i].nRight)
        {
            sub_00502320(wszText, nLeft, nY, nColor, 0);
        }
        else
        {
            TEXT_DrawCenteredText(nLeft, nY, nRight, wszText, nColor);
        }
    }
    sub_00502EF0(nOldFont);
}

void __cdecl sub_19F4_Emit_0048A990(D2UnitStrc* pUnit)
{
    INV_DrawUnitName(pUnit);
    INV_DrawPanelLabels();
    INV_DrawMercStats(pUnit);
    sub_0048B0A0(pUnit);
}

static D2UnitStrc* sub_00486770_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, ".\\UI\\inv.cpp"))
        {
            const unsigned char nPage = ITEMS_GetInvPage(pItem);
            if (nPage == 0 || nPage == 3 || nPage == 4 || nPage == 0xFF)
            {
                const int nNodePage = INVENTORY_GetItemNodePage(pNode);
                if (nNodePage == 1 || nNodePage == 3 || nNodePage == 4)
                {
                    const int nFileIndex = ITEMS_GetFileIndex(pItem);
                    D2SetItemsTxt* pSetItemsTxt = (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nFileIndex] : 0;
                    if (pSetItemsTxt && pSetItemsTxt->wSetItemId == nSetItemId)
                    {
                        return pItem;
                    }
                }
            }
        }
    }
    return 0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048D1D0
void __fastcall INV_DrawSetItemTooltip(D2UnitStrc* pUnit)
{
    Unicode wszText[1024];
    Unicode wszPopup[2048];
    Unicode wszName[256];
    Unicode wszSetName[256];
    Unicode wszDurability[256];
    Unicode wszLevelReq[256];
    Unicode wszStrReq[256];
    Unicode wszDexReq[256];
    Unicode wszDamage[256];
    Unicode wszBlock[256];
    Unicode wszThrow[256];
    Unicode wszDefense[256];
    Unicode wszStats[1024];
    Unicode wszSpeed[256];
    Unicode wszSetItems[512];
    Unicode wszProps[1024];
    Unicode wszSetProps[512];
    Unicode wszStateProps[512];
    Unicode wszClass[256];
    int bLevelRed = 0;
    int bStrRed = 0;
    int bDexRed = 0;
    int bClassRed = 0;

    const Unicode* pNewline = D2LANG_GetStringFromTblIndex(0xF9E);

    D2UnitStrc* pPlayer = pUnit;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pUnit))
        pPlayer = sub_00463DD0_GetPlayerUnit();

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!gdwGlobal_007BCBE8 && !gdwGlobal_007BCBE4)
        return;
    if (!gpHoverItem_007BCBF4)
        return;
    if (INVENTORY_GetCursorItem(pInventory))
        return;

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gpHoverItem_007BCBF4 ? -1 : gpHoverItem_007BCBF4->dwClassId);
    D2_ASSERT(pItemsTxt, 0xD56);

    D2SetItemsTxt* pSetItemsTxt = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(gpHoverItem_007BCBF4));
    if (!pSetItemsTxt)
        return;

    D2SetsTxt* pSetsTxt = sub_00483410_GetSetsTxtRecord(pSetItemsTxt->nSetId);
    if (!pSetsTxt)
        return;

    sub_005267E0(wszSetName, D2LANG_GetStringFromTblIndex(pSetsTxt->wStrName));
    sub_00526700(wszSetName, pNewline);

    int bStrength;
    int bDexterity;
    int bLevel;
    ITEMS_CheckRequirements(gpHoverItem_007BCBF4, pPlayer, 0, &bStrength, &bDexterity, &bLevel);

    INV_AppendDurability(gpHoverItem_007BCBF4, wszDurability);

    const int nLevelReq = ITEMS_GetLevelRequirement(gpHoverItem_007BCBF4, pPlayer);
    if (nLevelReq > 1)
    {
        if (!bLevel)
            bLevelRed = 1;
        INV_AppendLabeledNumber(nLevelReq, wszLevelReq);
    }

    if (ITEMSIsA(gpHoverItem_007BCBF4, 0x2D) || ITEMSIsA(gpHoverItem_007BCBF4, 0x32))
    {
        int nStrBonus = 0;
        int nDexBonus = 0;
        const int nPercent = STATLIST_UnitGetItemStatOrSkillStatValue(gpHoverItem_007BCBF4, STAT_ITEM_REQ_PERCENT, 0);
        if (nPercent)
        {
            nStrBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqStr, nPercent, 100);
            nDexBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqDex, nPercent, 100);
        }

        if (ITEMS_CheckItemFlag(gpHoverItem_007BCBF4, 0x400000, 0xD88, ".\\UI\\inv.cpp"))
        {
            nStrBonus -= 10;
            nDexBonus -= 10;
        }

        if (pItemsTxt->wReqStr > 0)
        {
            if (!bStrength)
                bStrRed = 1;
            INV_AppendReqStr(pItemsTxt, nStrBonus, wszStrReq);
        }

        if (pItemsTxt->wReqDex > 0)
        {
            if (!bDexterity)
                bDexRed = 1;
            INV_AppendReqDex(pItemsTxt, nDexBonus, wszDexReq);
        }
    }

    sub_005267E0(wszStats, INV_PrefixColorCode(wszLevelReq, bLevelRed));
    sub_00526700(wszStats, INV_PrefixColorCode(wszStrReq, bStrRed));
    sub_00526700(wszStats, INV_PrefixColorCode(wszDexReq, bDexRed));

    const int nClass = ITEMS_GetClassOfClassSpecificItem(gpHoverItem_007BCBF4);
    if (nClass != 7)
    {
        sub_00526700(wszClass, D2LANG_GetStringFromTblIndex(nClass + 0x2AA5));
        sub_00526700(wszClass, pNewline);
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->dwClassId != nClass)
            bClassRed = 1;
        sub_00526700(wszStats, INV_PrefixColorCode(wszClass, bClassRed));
    }

    sub_00526700(wszStats, INV_PrefixColorCode(wszDurability, 0));

    if (ITEMSIsA(gpHoverItem_007BCBF4, 0x2D))
    {
        INV_AppendAttackSpeed(wszSpeed, gpHoverItem_007BCBF4);
        INV_PrefixColorCode(wszSpeed, 0);
        sub_00526700(wszStats, wszSpeed);

        if (STATLIST_GetMinDamageFromUnit(gpHoverItem_007BCBF4, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(gpHoverItem_007BCBF4, 0) >= 0)
        {
            sub_00485410_AppendDamage(gpHoverItem_007BCBF4, wszDamage);
            INV_PrefixColorCode(wszDamage, 0);
            sub_00526700(wszStats, wszDamage);
        }
    }

    if (ITEMSIsA(gpHoverItem_007BCBF4, 0x33))
    {
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            const int nPlayerClass = pPlayer->dwClassId;
            if (nPlayerClass == 3 && (!ITEMS_IsClassValid(gpHoverItem_007BCBF4) || ITEMS_GetClassOfClassSpecificItem(gpHoverItem_007BCBF4) == nPlayerClass))
            {
                INV_AppendThrowDamage(gpHoverItem_007BCBF4, pItemsTxt, wszThrow);
                INV_PrefixColorCode(wszThrow, 0);
                sub_00526700(wszStats, wszThrow);
            }
        }

        INV_AppendBlockChance(wszBlock, pItemsTxt, gpHoverItem_007BCBF4);
        INV_PrefixColorCode(wszBlock, 0);
        sub_00526700(wszStats, wszBlock);
    }

    if (ITEMSIsA(gpHoverItem_007BCBF4, 0x32) && STATLIST_GetDefenseFromUnit(gpHoverItem_007BCBF4) > 0)
    {
        INV_AppendDefense(pPlayer, gpHoverItem_007BCBF4, wszDefense);
        INV_PrefixColorCode(wszDefense, 0);
        sub_00526700(wszStats, wszDefense);
    }

    INV_BuildItemName(gpHoverItem_007BCBF4, wszName, 0x100);
    if (ITEMS_CheckItemFlag(gpHoverItem_007BCBF4, 0x100, 0xDDB, ".\\UI\\inv.cpp"))
    {
        INV_PrefixColorCode(wszName, 1);
    }
    else
    {
        INV_PrefixColorCode(wszName, 2);
    }
    sub_00526700(wszStats, wszName);

    wszProps[0].wChar = 0;
    if (ITEMS_CheckItemFlag(gpHoverItem_007BCBF4, 0x800, 0xDE4, ".\\UI\\inv.cpp"))
    {
        Unicode wszSockets[300];
        INV_AppendEtherealSocketed(gpHoverItem_007BCBF4, wszSockets);
        sub_005267E0(wszProps, wszSockets);
    }

    sub_004E6410_BuildPropText(gpHoverItem_007BCBF4, wszProps, 0x400, 1, 0);

    wszSetProps[0].wChar = 0;
    sub_004E6560_SetItemPropTexts(pPlayer, gpHoverItem_007BCBF4, wszSetProps, 0x200);

    wszStateProps[0].wChar = 0;
    if (gpHoverItem_007BCBF4 && gpHoverItem_007BCBF4->dwAnimMode == 1)
        sub_004E6680_AddSetStatePropText(pPlayer, gpHoverItem_007BCBF4, wszStateProps, 0x200);

    for (int i = 0; i < pSetsTxt->nSetItems; ++i)
    {
        D2SetItemsTxt* pSetItem = pSetsTxt->pSetItems[i];
        if (!pSetItem)
            break;

        D2UnitStrc* pFound = sub_00486770_FindSetItem(pInventory, pSetItem->wSetItemId);
        if (pSetItem->wTblIndex)
        {
            INV_FormatArgs(wszText, D2LANG_GetStringFromTblIndex(0x2769), D2LANG_GetStringFromTblIndex(pSetItem->wTblIndex), 0);
            sub_00526700(wszText, pNewline);
        }

        if (pFound)
            INV_PrefixColorCode(wszText, 2);
        else
            INV_PrefixColorCode(wszText, 1);
        sub_00526700(wszSetItems, wszText);
    }

    sub_005267E0(wszText, INV_PrefixColorCode(wszSetItems, 2));
    sub_00526700(wszText, INV_PrefixColorCode(wszSetName, 4));
    if (wszStateProps[0].wChar)
    {
        sub_00526700(wszText, pNewline);
        sub_00526700(wszText, INV_PrefixColorCode(wszStateProps, 4));
    }
    sub_00526700(wszText, pNewline);
    if (wszSetProps[0].wChar)
        sub_00526700(wszText, INV_PrefixColorCode(wszSetProps, 2));
    sub_00526700(wszText, INV_PrefixColorCode(wszProps, 3));
    sub_00526700(wszText, wszStats);

    if (gdwGlobal_007BCBF0)
    {
        switch (gdwGlobal_007BCBF0)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        {
            Unicode wszCost[64];
            int nCost;
            if (NPCMENU_GetTradeCostText(gpHoverItem_007BCBF4, gnGlobal_00721E38, &nCost, wszCost, 0x40))
            {
                sub_005267E0(wszPopup, wszText);
                if (wszCost[0].wChar)
                    sub_00526700(wszPopup, pNewline);
                sub_00526700(wszPopup, wszCost);
            }
            else
            {
                sub_005267E0(wszPopup, wszText);
                if (gdwGlobal_007BCBF0 != 4)
                {
                    Unicode wszNote[64];
                    sub_005267E0(wszNote, D2LANG_GetStringFromTblIndex(0xD05));
                    sub_00526700(wszPopup, pNewline);
                    sub_00526700(wszPopup, INV_PrefixColorCode(wszNote, 1));
                }
            }
            break;
        }
        default:
            sub_005267E0(wszPopup, wszText);
            break;
        }
    }
    else
    {
        sub_005267E0(wszPopup, wszText);
    }

    sub_00452170(wszPopup);
    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszPopup, &nWidth, &nHeight);
    if (gnGlobal_00721E40 - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszPopup, gnGlobal_00721E3C, gnGlobal_00721E40, 0, 1);
        return;
    }

    D2Win_10129_DrawFramedText(wszPopup, gnGlobal_00721E44, nHeight + gnGlobal_00721E48, 0, 1);
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

static int __stdcall sub_00487740_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gGrid_007BCB88.nGridLeft) / gGrid_007BCB88.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB88.nGridTop) / gGrid_007BCB88.nGridBoxHeight;
    }
    else if (sub_0044DCC0())
    {
        nGridX = (nX - gGrid_007BCA78.nGridLeft) / gGrid_007BCA78.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCA78.nGridTop) / gGrid_007BCA78.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gGrid_007BCB40.nGridLeft) / gGrid_007BCB40.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB40.nGridTop) / gGrid_007BCB40.nGridBoxHeight;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && ITEMS_GetTransmogrify(pItem))
        {
            if (!sub_004C2240(pItem))
            {
                sub_00478680_SendPacket5(0x4C, pItem->dwUnitId);
                sub_004C21F0_SetState36(pItem);
                return 1;
            }
        }
        else if (ITEMS_CheckIfUseable(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
            {
                if (sub_004538D0(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gnGlobal_007BCC50 = 1;
                }

                sub_004786D0_SendDwords3(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                sub_004C21F0_SetState36(pItem);
                sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
                gdwGlobal_007BCBE4 = 0;
                return 1;
            }
        }
        else if (ITEMS_GetUniqueColumnFromItemsTxt(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                TEXT_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

static int sub_00483B40_IsInRect(int nX, int nY)
{
    if (sub_0044DCC0())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

static inline int INV_IsModeInRange(int nMode)
{
    if (nMode < 2)
    {
        return 0;
    }
    if (nMode > 4)
    {
        return 0;
    }
    return 1;
}

// 0x00491AD0
void __stdcall INV_InventoryClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_0044DA30() || !pPlayer || sub_00463DF0())
    {
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (nX >= gGrid_007BCB88.nGridLeft && nX <= gGrid_007BCB88.nGridRight && nY >= gGrid_007BCB88.nGridTop && nY <= gGrid_007BCB88.nGridBottom)
    {
        INV_GridClickMsg(pMsg);
        return;
    }

    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        return;
    }

    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    else if (sub_00468830() == 8)
    {
        sub_00478680_SendPacket5(0x4C, -1);
    }
    else if (!INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2)
        {
            if (nX >= 0 && nX <= gnGlobal_007BCAA0 && nY >= 0 && nY <= gnGlobal_007BCAAC)
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                if (nX >= gnGlobal_007BCB5C && nX <= gnGlobal_007BCB60 && nY >= gnGlobal_007BCB64 && nY <= gnGlobal_007BCB68 && gdwGlobal_007BCBF4)
                {
                    int nUnitId;
                    if (!NPCMENU_GetInteractNpcId(&nUnitId))
                    {
                        INV_ResetNpcButtons();
                    }
                    else
                    {
                        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
                        if (!pUnit)
                        {
                            INV_ResetNpcButtons();
                        }
                        else
                        {
                            const unsigned int nParam = pMsg->wParam;
                            if (gdwGlobal_007BCBF4 && sub_004B3870_HandleTradeClick(pUnit, gdwGlobal_007BCBF4, 0, nX, nY, nParam, 1, 0))
                            {
                                sub_00468070_SetCursorItemState(0);
                            }
                        }
                    }
                }
                else if (sub_004888C0_CanUseCursor())
                {
                    INV_ResetNpcButtons();
                }
            }
        }
        else if (gdwGlobal_007BCBF0 == 0xE)
        {
            if (sub_00483BF0_IsInRect(nX, nY))
            {
                sub_004CB9C0_Request(pPlayer, 0x13);
            }
        }
        else if (gdwGlobal_007BCBF0 == 0xC && sub_00483B40_IsInRect(nX, nY))
        {
            if (sub_00483AB0_IsInInvRect(nX, nY))
            {
                INV_GridClickMsg(pMsg);
            }
            else if (sub_00483B40_IsInRect(nX, nY))
            {
                sub_00487740_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
            }
            else
            {
                sub_004CB9C0_Request(pPlayer, 0x13);
            }
        }
        else if (INV_IsModeInRange(gdwGlobal_007BCBF0))
        {
            INV_ResetNpcButtons();
        }
    }
    else
    {
        switch (gdwGlobal_007BCBF0)
        {
        case 2:
        case 3:
        case 4:
            INV_ResetNpcButtons();
            break;
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

#include "gen/data/Source/D2Client/UI/inv_004844A0.inc"
