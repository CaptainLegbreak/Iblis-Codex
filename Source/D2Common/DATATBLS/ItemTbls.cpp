#include "D2Common.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2TxtItems.h"
#include "D2GameRecords.h"

// build: base-profile
#define NULL 0

struct D2ItemRatioTxt;

struct D2RunesTxt;

struct D2BinFieldStrc;

struct D2ItemsTxt;

struct D2MagicAffixTxt;

struct D2RareAffixTxt;

struct D2QualityItemsTxt;

struct D2GemsTxt;

struct D2BooksTxt;

struct D2LowQualityItemsTxt;

struct D2ItemStatCostDescStrc;

struct D2ItemDataTbl;

struct D2MagicAffixDataTbl;

struct D2RareAffixDataTbl;

struct D2QualityItemDataTbl;

struct D2GemDataTbl;

struct D2BookDataTbl;

struct D2LowQualityItemDataTbl;

struct D2ItemRatioDataTbl;

struct D2GambleDataTbl;

struct D2RuneDataTbl;

struct D2UniqueItemsTxt;

struct D2GambleTxt;

struct D2TxtLinkStrc;

struct Unicode;

struct D2PropertyStrc;

struct D2DataTablesStrc;

extern D2TxtLinkStrc* gpItemTypesLinker_0096C824; // 0x0096C824

extern D2TxtLinkStrc* gpSoundsLinker_0096BDC8; // 0x0096BDC8

extern D2TxtLinkStrc* gpStatesLinker_0096BCF0; // 0x0096BCF0

extern D2TxtLinkStrc* gpItemStatCostLinker_0096C800; // 0x0096C800

extern int gbCompileTxt; // 0x0096C8B4

unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference); // 0x006117B0

void __fastcall DATATBLS_ItemCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x00631530

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx); // 0x00613E90

void __stdcall sub_006BD230_AddLinkCode(D2TxtLinkStrc* pLinker, unsigned int dwCode); // 0x006BD230


struct D2RareAffixTxt { char unk[0x48]; };

struct D2QualityItemsTxt
{
    char unk0x00[0x2C];
    char szEffect1[32];
    char szEffect2[32];
    unsigned short wEffect1TblId;
    unsigned short wEffect2TblId;
};

struct D2BooksTxt { char unk[0x20]; };

struct D2LowQualityItemsTxt
{
    char szName[32];
    unsigned short wTblId;
};

struct D2ItemStatCostDescStrc
{
    unsigned short wStatId;
    short nDescPriority;
};

struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };

struct D2RareAffixDataTbl { int nRareAffixTxtRecordCount; D2RareAffixTxt* pRareAffixTxt; };

struct D2QualityItemDataTbl { int nQualityItemsTxtRecordCount; D2QualityItemsTxt* pQualityItemsTxt; };

struct D2GemDataTbl { int nGemsTxtRecordCount; D2GemsTxt* pGemsTxt; };

struct D2BookDataTbl { int nBooksTxtRecordCount; D2BooksTxt* pBooksTxt; };

struct D2LowQualityItemDataTbl { int nLowQualityItemsTxtRecordCount; D2LowQualityItemsTxt* pLowQualityItemsTxt; };

struct D2ItemRatioDataTbl { int nItemRatioTxtRecordCount; D2ItemRatioTxt* pItemRatioTxt; };

D2TxtLinkStrc* gpItemsLinker_0096BCC4; // 0x0096BCC4

D2TxtLinkStrc* gTxtLink_0096BCD8; // 0x0096BCD8

D2ItemStatCostTxt* gpItemStatCostTxt; // 0x0096C7FC

int gnItemStatCostTxtRecordCount; // 0x0096C804

unsigned short* gpStatsWithDescFunc; // 0x0096C808

int gnStatsWithDescFunc; // 0x0096C80C

extern void* gp_0096C828; // 0x0096C828

int gnUniqueitemsTxtRecordCount; // 0x0096C858

extern D2ItemDataTbl gItemDataTables; // 0x0096CA58

unsigned short* gpIndexOldToCurrent_0096CA78; // 0x0096CA78

extern D2GemDataTbl gGemDataTables; // 0x0096CA90

extern D2RuneDataTbl sgtRuneWordsTblDesc; // 0x0096CA98

extern D2ItemRatioDataTbl gItemRatioDataTables; // 0x0096CC48

extern D2QualityItemDataTbl gQualityItemDataTables; // 0x0096CC50

extern D2LowQualityItemDataTbl gLowQualityItemDataTables; // 0x0096CC58

extern D2BookDataTbl gBookDataTables; // 0x0096CC60

extern "C" const char gszEmptyAssertText; // 0x006CC837

int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC

extern D2TxtLinkStrc* gpMonTypeLinker_0096C868; // 0x0096C868

extern "C" const char gszTxtField_index[]; // 0x006E9CCC

extern D2TxtLinkStrc* gTxtLink_0096C5E4; // 0x0096C5E4

void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x006336A0

void __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szName); // 0x006BD500

unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode); // 0x00524D30

D2ItemsTxt* gpItemsTxt_0096CA5C; // 0x0096CA5C

struct D2ItemRatioTxt
{
    int dwUnique;
    int dwUniqueDivisor;
    int dwUniqueMin;
    int dwRare;
    int dwRareDivisor;
    int dwRareMin;
    int dwSet;
    int dwSetDivisor;
    int dwSetMin;
    int dwMagic;
    int dwMagicDivisor;
    int dwMagicMin;
    int dwHiQuality;
    int dwHiQualityDivisor;
    int dwNormal;
    int dwNormalDivisor;
    unsigned short wVersion;
    unsigned char nUber;
    unsigned char nClassSpecific;
};

int __stdcall ITEMS_IsClassValidByItemId(int nItemId); // 0x00629F70

int __stdcall ITEMS_GetQuestFromItemId(int nItemId); // 0x0062B4D0

void* gpPropertiesTxt; // 0x0096BCD4

struct D2GambleTxt
{
    unsigned int dwItemCode;
    int nLevel;
    int nItemId;
};

extern "C" const char gszGambleTxtName[]; // 0x006EA750

extern "C" const char gszItemsTblsSourceFile[]; // 0x006E90E4

D2GambleDataTbl gGambleDataTables; // 0x0096CAB0

typedef void* HD2ARCHIVE;

typedef void* HSFILE;

enum D2C_TxtFieldTypes
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_UNKNOWN3 = 11,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETODWORD = 19,
    TXTFIELD_CALCTODWORD = 25,
};

extern "C" unsigned int __security_cookie; // 0x00749DE0

extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468

int __fastcall sub_00516E46_OpenFile(HD2ARCHIVE hArchive, const char* szFilePath, HSFILE* phFile, int bQuiet); // 0x00516E46

void __fastcall sub_00516E84_CloseFile(HD2ARCHIVE hArchive, HSFILE hFile); // 0x00516E84

short __stdcall sub_00524D30_FindString(const char* szReference, const Unicode** ppUnicode); // 0x00524D30

extern D2DataTablesStrc sgtDataTables; // 0x0096BC30

D2TxtLinkStrc* gpHitClassLinker_0096BC54; // 0x0096BC54

void* gpItemsCode_0096BCC8; // 0x0096BCC8

int gnItemsCodeSize_0096BCCC; // 0x0096BCCC

int gnItemsCodeSizeEx_0096BCD0; // 0x0096BCD0

int gnItemsTxtRecordCount_0096CA58; // 0x0096CA58

D2ItemsTxt* gpWeaponsTxt_0096CA60; // 0x0096CA60

int gnWeaponsTxtRecordCount_0096CA64; // 0x0096CA64

D2ItemsTxt* gpArmorTxt_0096CA68; // 0x0096CA68

int gnArmorTxtRecordCount_0096CA6C; // 0x0096CA6C

D2ItemsTxt* gpMiscTxt_0096CA70; // 0x0096CA70

int gnMiscTxtRecordCount_0096CA74; // 0x0096CA74

struct D2OpStatDataStrc;

struct D2ItemStatCostTxt;

extern D2TxtLinkStrc* gpEventsLinker_0096BCA8; // 0x0096BCA8

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __cdecl DATATBLS_CompareItemStatCostDescs(const void* pRecord1, const void* pRecord2); // 0x006379D0

int __cdecl DATATBLS_CompareGambleTxtRecords(const void* pRecord1, const void* pRecord2); // 0x00638AC0

int gnItemStatCostStuff_0096C89C; // 0x0096C89C

int gnItemStatCostStuffMask_0096C8A0; // 0x0096C8A0

D2TxtLinkStrc* gpRunesLinker; // 0x0096BCE0

void* gpItemTypesEquivalenceLUTs; // 0x0096C834

D2TxtLinkStrc* gpSetsLinker; // 0x0096C838

void* gpSetsTxt; // 0x0096C83C

int gnSetsTxtRecordCount; // 0x0096C840

int gnSetItemsTxtRecordCount; // 0x0096C84C

D2MagicAffixDataTbl sgtMagicItemModsDataTblDesc; // 0x0096CA7C

D2RareAffixDataTbl sgtRareItemModsDataTblDesc; // 0x0096CAA0

D2UniqueItemsTxt* gpUniqueitemsTxt; // 0x0096C854

D2TxtLinkStrc* gpUniqueitemsLinker; // 0x0096C850

D2QualityItemsTxt* gpQualityitemsTxt; // 0x0096CC54

int gnQualityitemsTxtRecordCount; // 0x0096CC50

D2GemsTxt* gpGemsTxt; // 0x0096CA94

int gnGemsTxtRecordCount; // 0x0096CA90

void* gpBooksTxt; // 0x0096CC64

int gnBooksTxtRecordCount; // 0x0096CC60

D2LowQualityItemsTxt* gpLowqualityitemsTxt; // 0x0096CC5C

int gnLowqualityitemsTxtRecordCount; // 0x0096CC58

void* gpItemratioTxt; // 0x0096CC4C

int gnItemratioTxtRecordCount; // 0x0096CC48

int gnPropertiesTxtRecordCount; // 0x0096BCDC

// 0x006315D0
void __fastcall DATATBLS_LoadItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 10, 0, 128, &gpItemsLinker_0096BCC4 },
        { "namestr", 22, 0, 244, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_version, 3, 0, 246, 0 },
        { "compactsave", 6, 0, 323, 0 },
        { "type", 15, 0, 286, &gpItemTypesLinker_0096C824 },
        { "type2", 15, 0, 288, &gpItemTypesLinker_0096C824 },
        { "hit class", 13, 0, 316, &gpHitClassLinker_0096BC54 },
        { "gemapplytype", 4, 0, 318, 0 },
        { "levelreq", 4, 0, 319, 0 },
        { "magic lvl", 4, 0, 320, 0 },
        { "auto prefix", 3, 0, 248, 0 },
        { "gamble cost", 2, 0, 212, 0 },
        { "alternategfx", 9, 0, 144, 0 },
        { "spawnable", 4, 0, 307, 0 },
        { "rarity", 4, 0, 252, 0 },
        { "level", 4, 0, 253, 0 },
        { "mindam", 6, 0, 254, 0 },
        { "maxdam", 6, 0, 255, 0 },
        { "2handmindam", 6, 0, 258, 0 },
        { "2handmaxdam", 6, 0, 259, 0 },
        { "minmisdam", 4, 0, 256, 0 },
        { "maxmisdam", 4, 0, 257, 0 },
        { "minac", 2, 0, 204, 0 },
        { "maxac", 2, 0, 208, 0 },
        { "block", 6, 0, 273, 0 },
        { "absorbs", 6, 0, 270, 0 },
        { "rangeadder", 6, 0, 260, 0 },
        { "speed", 2, 0, 216, 0 },
        { "strbonus", 3, 0, 262, 0 },
        { "dexbonus", 3, 0, 264, 0 },
        { "reqstr", 3, 0, 266, 0 },
        { "reqdex", 3, 0, 268, 0 },
        { "invwidth", 4, 0, 271, 0 },
        { "invheight", 4, 0, 272, 0 },
        { "stackable", 4, 0, 306, 0 },
        { "minstack", 2, 0, 228, 0 },
        { "maxstack", 2, 0, 232, 0 },
        { "spawnstack", 2, 0, 236, 0 },
        { "flippyfile", 1, 31, 0, 0 },
        { "invfile", 1, 31, 32, 0 },
        { "uniqueinvfile", 1, 31, 64, 0 },
        { "setinvfile", 1, 31, 96, 0 },
        { "durability", 6, 0, 274, 0 },
        { "nodurability", 4, 0, 275, 0 },
        { "missile", 6, 0, 276, 0 },
        { "component", 4, 0, 277, 0 },
        { "cost", 2, 0, 224, 0 },
        { "normcode", 9, 0, 132, 0 },
        { "ubercode", 9, 0, 136, 0 },
        { "ultracode", 9, 0, 140, 0 },
        { "wclass", 9, 0, 192, 0 },
        { "2handedwclass", 9, 0, 196, 0 },
        { "1or2handed", 6, 0, 317, 0 },
        { "BetterGem", 9, 0, 188, 0 },
        { "rArm", 6, 0, 278, 0 },
        { "lArm", 6, 0, 279, 0 },
        { "torso", 6, 0, 280, 0 },
        { "legs", 6, 0, 281, 0 },
        { "rspad", 6, 0, 282, 0 },
        { "lspad", 6, 0, 283, 0 },
        { "2handed", 6, 0, 284, 0 },
        { "useable", 4, 0, 285, 0 },
        { "subtype", 6, 0, 290, 0 },
        { "dropsound", 20, 0, 292, &gpSoundsLinker_0096BDC8 },
        { "dropsfxframe", 4, 0, 296, 0 },
        { "usesound", 20, 0, 294, &gpSoundsLinker_0096BDC8 },
        { "unique", 4, 0, 297, 0 },
        { "quest", 4, 0, 298, 0 },
        { "questdiffcheck", 4, 0, 299, 0 },
        { "transparent", 4, 0, 300, 0 },
        { "transtbl", 4, 0, 301, 0 },
        { "lightradius", 4, 0, 303, 0 },
        { "belt", 4, 0, 304, 0 },
        { "autobelt", 4, 0, 305, 0 },
        { "missiletype", 3, 0, 250, 0 },
        { "spellicon", 6, 0, 308, 0 },
        { "durwarning", 4, 0, 309, 0 },
        { "qntwarning", 4, 0, 310, 0 },
        { "hasinv", 6, 0, 311, 0 },
        { "gemsockets", 6, 0, 312, 0 },
        { "gemoffset", 2, 0, 240, 0 },
        { "pSpell", 2, 0, 148, 0 },
        { "state", 20, 0, 152, &gpStatesLinker_0096BCF0 },
        { "cstate1", 20, 0, 154, &gpStatesLinker_0096BCF0 },
        { "cstate2", 20, 0, 156, &gpStatesLinker_0096BCF0 },
        { "len", 25, 0, 176, (void*)DATATBLS_ItemCalcLinker },
        { "stat1", 20, 0, 158, &gpItemStatCostLinker_0096C800 },
        { "calc1", 25, 0, 164, (void*)DATATBLS_ItemCalcLinker },
        { "stat2", 20, 0, 160, &gpItemStatCostLinker_0096C800 },
        { "calc2", 25, 0, 168, (void*)DATATBLS_ItemCalcLinker },
        { "stat3", 20, 0, 162, &gpItemStatCostLinker_0096C800 },
        { "calc3", 25, 0, 172, (void*)DATATBLS_ItemCalcLinker },
        { "spelldesc", 4, 0, 180, 0 },
        { "spelldescstr", 22, 0, 182, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "spelldesccalc", 25, 0, 184, (void*)DATATBLS_ItemCalcLinker },
        { "SkipName", 4, 0, 324, 0 },
        { "bitfield1", 2, 0, 220, 0 },
        { "CharsiMin", 4, 0, 328, 0 },
        { "CharsiMax", 4, 0, 345, 0 },
        { "CharsiMagicMin", 4, 0, 362, 0 },
        { "CharsiMagicMax", 4, 0, 379, 0 },
        { "CharsiMagicLvl", 4, 0, 396, 0 },
        { "GheedMin", 4, 0, 327, 0 },
        { "GheedMax", 4, 0, 344, 0 },
        { "GheedMagicMin", 4, 0, 361, 0 },
        { "GheedMagicMax", 4, 0, 378, 0 },
        { "GheedMagicLvl", 4, 0, 395, 0 },
        { "AkaraMin", 4, 0, 326, 0 },
        { "AkaraMax", 4, 0, 343, 0 },
        { "AkaraMagicMin", 4, 0, 360, 0 },
        { "AkaraMagicMax", 4, 0, 377, 0 },
        { "AkaraMagicLvl", 4, 0, 394, 0 },
        { "FaraMin", 4, 0, 329, 0 },
        { "FaraMax", 4, 0, 346, 0 },
        { "FaraMagicMin", 4, 0, 363, 0 },
        { "FaraMagicMax", 4, 0, 380, 0 },
        { "FaraMagicLvl", 4, 0, 397, 0 },
        { "LysanderMin", 4, 0, 330, 0 },
        { "LysanderMax", 4, 0, 347, 0 },
        { "LysanderMagicMin", 4, 0, 364, 0 },
        { "LysanderMagicMax", 4, 0, 381, 0 },
        { "LysanderMagicLvl", 4, 0, 398, 0 },
        { "DrognanMin", 4, 0, 331, 0 },
        { "DrognanMax", 4, 0, 348, 0 },
        { "DrognanMagicMin", 4, 0, 365, 0 },
        { "DrognanMagicMax", 4, 0, 382, 0 },
        { "DrognanMagicLvl", 4, 0, 399, 0 },
        { "HraltiMin", 4, 0, 332, 0 },
        { "HraltiMax", 4, 0, 349, 0 },
        { "HraltiMagicMin", 4, 0, 366, 0 },
        { "HraltiMagicMax", 4, 0, 383, 0 },
        { "HraltiMagicLvl", 4, 0, 400, 0 },
        { "AlkorMin", 4, 0, 333, 0 },
        { "AlkorMax", 4, 0, 350, 0 },
        { "AlkorMagicMin", 4, 0, 367, 0 },
        { "AlkorMagicMax", 4, 0, 384, 0 },
        { "AlkorMagicLvl", 4, 0, 401, 0 },
        { "OrmusMin", 4, 0, 334, 0 },
        { "OrmusMax", 4, 0, 351, 0 },
        { "OrmusMagicMin", 4, 0, 368, 0 },
        { "OrmusMagicMax", 4, 0, 385, 0 },
        { "OrmusMagicLvl", 4, 0, 402, 0 },
        { "ElzixMin", 4, 0, 335, 0 },
        { "ElzixMax", 4, 0, 352, 0 },
        { "ElzixMagicMin", 4, 0, 369, 0 },
        { "ElzixMagicMax", 4, 0, 386, 0 },
        { "ElzixMagicLvl", 4, 0, 403, 0 },
        { "AshearaMin", 4, 0, 336, 0 },
        { "AshearaMax", 4, 0, 353, 0 },
        { "AshearaMagicMin", 4, 0, 370, 0 },
        { "AshearaMagicMax", 4, 0, 387, 0 },
        { "AshearaMagicLvl", 4, 0, 404, 0 },
        { "CainMin", 4, 0, 337, 0 },
        { "CainMax", 4, 0, 354, 0 },
        { "CainMagicMin", 4, 0, 371, 0 },
        { "CainMagicMax", 4, 0, 388, 0 },
        { "CainMagicLvl", 4, 0, 405, 0 },
        { "HalbuMin", 4, 0, 338, 0 },
        { "HalbuMax", 4, 0, 355, 0 },
        { "HalbuMagicMin", 4, 0, 372, 0 },
        { "HalbuMagicMax", 4, 0, 389, 0 },
        { "HalbuMagicLvl", 4, 0, 406, 0 },
        { "JamellaMin", 4, 0, 339, 0 },
        { "JamellaMax", 4, 0, 356, 0 },
        { "JamellaMagicMin", 4, 0, 373, 0 },
        { "JamellaMagicMax", 4, 0, 390, 0 },
        { "JamellaMagicLvl", 4, 0, 407, 0 },
        { "MalahMin", 4, 0, 340, 0 },
        { "MalahMax", 4, 0, 357, 0 },
        { "MalahMagicMin", 4, 0, 374, 0 },
        { "MalahMagicMax", 4, 0, 391, 0 },
        { "MalahMagicLvl", 4, 0, 408, 0 },
        { "LarzukMin", 4, 0, 341, 0 },
        { "LarzukMax", 4, 0, 358, 0 },
        { "LarzukMagicMin", 4, 0, 375, 0 },
        { "LarzukMagicMax", 4, 0, 392, 0 },
        { "LarzukMagicLvl", 4, 0, 409, 0 },
        { "DrehyaMin", 4, 0, 342, 0 },
        { "DrehyaMax", 4, 0, 359, 0 },
        { "DrehyaMagicMin", 4, 0, 376, 0 },
        { "DrehyaMagicMax", 4, 0, 393, 0 },
        { "DrehyaMagicLvl", 4, 0, 410, 0 },
        { "Transmogrify", 6, 0, 313, 0 },
        { "TMogType", 9, 0, 200, 0 },
        { "TMogMin", 6, 0, 314, 0 },
        { "TMogMax", 6, 0, 315, 0 },
        { "Transform", 4, 0, 321, 0 },
        { "InvTrans", 4, 0, 322, 0 },
        { "PermStoreItem", 4, 0, 420, 0 },
        { "multibuy", 4, 0, 421, 0 },
        { "NightmareUpgrade", 9, 0, 412, 0 },
        { "HellUpgrade", 9, 0, 416, 0 },
        { "Nameable", 4, 0, 325, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpItemsLinker_0096BCC4 = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 392);

    D2ItemsTxt* pWeapons = (D2ItemsTxt*)DATATBLS_CompileTxt(hArchive, "weapons", pTbl, &gnWeaponsTxtRecordCount_0096CA64, sizeof(D2ItemsTxt));
    D2ItemsTxt* pArmor = (D2ItemsTxt*)DATATBLS_CompileTxt(hArchive, "armor", pTbl, &gnArmorTxtRecordCount_0096CA6C, sizeof(D2ItemsTxt));
    D2ItemsTxt* pMisc = (D2ItemsTxt*)DATATBLS_CompileTxt(hArchive, "misc", pTbl, &gnMiscTxtRecordCount_0096CA74, sizeof(D2ItemsTxt));

    gnItemsTxtRecordCount_0096CA58 = gnWeaponsTxtRecordCount_0096CA64 + gnArmorTxtRecordCount_0096CA6C + gnMiscTxtRecordCount_0096CA74;

    gpItemsTxt_0096CA5C = (D2ItemsTxt*)FOG_AllocPool(0, sizeof(D2ItemsTxt) * gnItemsTxtRecordCount_0096CA58, ".\\DATATBLS\\ItemTbls.cpp", 399, 0);
    D2ItemsTxt* pItems = gpItemsTxt_0096CA5C;
    gpWeaponsTxt_0096CA60 = gpItemsTxt_0096CA5C;
    memcpy(gpWeaponsTxt_0096CA60, pWeapons, sizeof(D2ItemsTxt) * gnWeaponsTxtRecordCount_0096CA64);

    pItems += gnWeaponsTxtRecordCount_0096CA64;
    gpArmorTxt_0096CA68 = pItems;
    memcpy(pItems, pArmor, sizeof(D2ItemsTxt) * gnArmorTxtRecordCount_0096CA6C);

    pItems += gnArmorTxtRecordCount_0096CA6C;
    gpMiscTxt_0096CA70 = pItems;
    memcpy(pItems, pMisc, sizeof(D2ItemsTxt) * gnMiscTxtRecordCount_0096CA74);

    DATATBLS_UnloadBin(pWeapons);
    DATATBLS_UnloadBin(pArmor);
    DATATBLS_UnloadBin(pMisc);

    DATATBLS_GetBinFileHandle(hArchive, "itemscode", &gpItemsCode_0096BCC8, &gnItemsCodeSize_0096BCCC, &gnItemsCodeSizeEx_0096BCD0);

    if (!gbCompileTxt)
    {
        for (int i = 0; i < gnItemsTxtRecordCount_0096CA58; ++i)
        {
            sub_006BD230_AddLinkCode(gpItemsLinker_0096BCC4, gpItemsTxt_0096CA5C[i].dwCode);
        }
    }

    gpIndexOldToCurrent_0096CA78 = (unsigned short*)FOG_AllocPool(0, sizeof(unsigned short) * gnItemsTxtRecordCount_0096CA58, ".\\DATATBLS\\ItemTbls.cpp", 431, 0);
    memset(gpIndexOldToCurrent_0096CA78, 0, sizeof(unsigned short) * gnItemsTxtRecordCount_0096CA58);

    int i = 0;
    if (i < gnItemsTxtRecordCount_0096CA58)
    {
        D2ItemsTxt* pItemsTxt = gpItemsTxt_0096CA5C;
        int nCount = 0;
        do
        {
            if (pItemsTxt[i].wVersion == 0)
            {
                gpIndexOldToCurrent_0096CA78[nCount] = i;
                ++nCount;
            }
            ++i;
        }
        while (i < gnItemsTxtRecordCount_0096CA58);
    }
}

// 0x00633540
void __fastcall DATATBLS_UnloadItemsTxt()
{
    FOG_FreeLinker(gpItemsLinker_0096BCC4);

    if (gItemDataTables.pItemsTxt)
    {
        sub_0040B480(0, gItemDataTables.pItemsTxt, ".\\DATATBLS\\ItemTbls.cpp", 456, 0);
    }

    if (gpIndexOldToCurrent_0096CA78)
    {
        sub_0040B480(0, gpIndexOldToCurrent_0096CA78, ".\\DATATBLS\\ItemTbls.cpp", 459, 0);
    }

    gItemDataTables.pItemsTxt = 0;
}

// 0x00633590
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables()
{
    return &gItemDataTables;
}

// 0x006335A0
int __stdcall DATATBLS_MapOldItemIndexToCurrent(int nItemId)
{
    if (nItemId >= gItemDataTables.nItemsTxtRecordCount)
    {
        return -1;
    }

    if (nItemId < 0)
    {
        return -1;
    }

    ITEM_ASSERT(gpIndexOldToCurrent_0096CA78, 482);
    return gpIndexOldToCurrent_0096CA78[nItemId];
}

// 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId)
{
    if ((unsigned int)nItemId >= (unsigned int)gItemDataTables.nItemsTxtRecordCount)
        return 0;

    D2_ASSERT(gItemDataTables.pItemsTxt, 0x1EF);
    return &gItemDataTables.pItemsTxt[nItemId];
}

// 0x00633640
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId)
{
    int nItemId = FOG_GetLinkIndex(gpItemsLinker_0096BCC4, dwCode, 0);
    if (nItemId < 0)
    {
        *pItemId = 0;
        return 0;
    }

    *pItemId = nItemId;
    return &gItemDataTables.pItemsTxt[nItemId];
}

// 0x00633680
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode)
{
    return FOG_GetLinkIndex(gpItemsLinker_0096BCC4, dwCode, 0);
}

// 0x006336A0
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nRow = 0;

    if (pRecord)
    {
        int* pValue = (int*)((char*)pRecord + nOffset);
        if (pSrc && *pSrc)
        {
            if (*pSrc == '-' || *pSrc >= '0' && *pSrc <= '9')
            {
                *pValue = atoi(pSrc);
                return;
            }

            if (gpSkillsLinker_0096C7CC)
            {
                nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, pSrc, 0);
                if (nRow >= 0)
                {
                    *pValue = nRow;
                    return;
                }
            }

            if (gpMonTypeLinker_0096C868)
            {
                nRow = FOG_GetRowFromTxt(gpMonTypeLinker_0096C868, pSrc, 0);
                if (nRow >= 0)
                {
                    *pValue = nRow;
                    return;
                }
            }

            if (!gpStatesLinker_0096BCF0 || (nRow = FOG_GetRowFromTxt(gpStatesLinker_0096BCF0, pSrc, 0)) < 0)
            {
                *pValue = 0;
                return;
            }

            *pValue = nRow;
            return;
        }

        *pValue = 0;
    }
}

// 0x00633EA0
void __fastcall DATATBLS_UnloadMagicSuffix_Prefix_AutomagicTxt()
{
    if (sgtMagicItemModsDataTblDesc.pMagicAffixTxt)
    {
        sub_0040B480(0, sgtMagicItemModsDataTblDesc.pMagicAffixTxt, ".\\DATATBLS\\ItemTbls.cpp", 695, 0);
    }
    sgtMagicItemModsDataTblDesc.pMagicAffixTxt = 0;
}

// 0x00633ED0
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables()
{
    return &sgtMagicItemModsDataTblDesc;
}

// 0x00633EE0
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex)
{
    ITEM_ASSERT(sgtMagicItemModsDataTblDesc.pMagicAffixTxt, 712);
    if (nIndex > sgtMagicItemModsDataTblDesc.nMagicAffixTxtRecordCount || nIndex <= 0)
    {
        return 0;
    }
    else
    {
        return &sgtMagicItemModsDataTblDesc.pMagicAffixTxt[nIndex - 1];
    }
}

// 0x00634220
void __fastcall DATATBLS_UnloadRareSuffix_PrefixTxt()
{
    if (sgtRareItemModsDataTblDesc.pRareAffixTxt)
    {
        sub_0040B480(0, sgtRareItemModsDataTblDesc.pRareAffixTxt, ".\\DATATBLS\\ItemTbls.cpp", 779, 0);
    }
    sgtRareItemModsDataTblDesc.pRareAffixTxt = 0;
}

// 0x00634250
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables()
{
    return &sgtRareItemModsDataTblDesc;
}

// 0x00634260
D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId)
{
    if (nId > sgtRareItemModsDataTblDesc.nRareAffixTxtRecordCount || nId <= 0)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(sgtRareItemModsDataTblDesc.pRareAffixTxt, 799);
        return &sgtRareItemModsDataTblDesc.pRareAffixTxt[nId - 1];
    }
}

// 0x006342B0
void __fastcall DATATBLS_LoadUniqueItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_index, 1, 31, 2, 0 },
        { gszTxtField_version, 3, 0, 36, 0 },
        { "enabled", 26, 0, 44, 0 },
        { "ladder", 26, 3, 44, 0 },
        { gszTxtField_code, 9, 0, 40, 0 },
        { "rarity", 3, 0, 48, 0 },
        { "lvl", 3, 0, 52, 0 },
        { "lvl req", 3, 0, 54, 0 },
        { "nolimit", 26, 1, 44, 0 },
        { "carry1", 26, 2, 44, 0 },
        { "chrtransform", 13, 0, 56, &gTxtLink_0096C5E4 },
        { "invtransform", 13, 0, 57, &gTxtLink_0096C5E4 },
        { "flippyfile", 1, 31, 58, 0 },
        { "invfile", 1, 31, 90, 0 },
        { "cost mult", 2, 0, 124, 0 },
        { "cost add", 2, 0, 128, 0 },
        { "dropsound", 20, 0, 132, &gTxtLink_0096BDC8 },
        { "dropsfxframe", 4, 0, 136, 0 },
        { "usesound", 20, 0, 134, &gTxtLink_0096BDC8 },
        { "prop1", 19, 0, 140, &gTxtLink_0096BCD8 },
        { "par1", 25, 0, 144, (void*)DATATBLS_ItemParamLinker },
        { "min1", 2, 0, 148, 0 },
        { "max1", 2, 0, 152, 0 },
        { "prop2", 19, 0, 156, &gTxtLink_0096BCD8 },
        { "par2", 25, 0, 160, (void*)DATATBLS_ItemParamLinker },
        { "min2", 2, 0, 164, 0 },
        { "max2", 2, 0, 168, 0 },
        { "prop3", 19, 0, 172, &gTxtLink_0096BCD8 },
        { "par3", 25, 0, 176, (void*)DATATBLS_ItemParamLinker },
        { "min3", 2, 0, 180, 0 },
        { "max3", 2, 0, 184, 0 },
        { "prop4", 19, 0, 188, &gTxtLink_0096BCD8 },
        { "par4", 25, 0, 192, (void*)DATATBLS_ItemParamLinker },
        { "min4", 2, 0, 196, 0 },
        { "max4", 2, 0, 200, 0 },
        { "prop5", 19, 0, 204, &gTxtLink_0096BCD8 },
        { "par5", 25, 0, 208, (void*)DATATBLS_ItemParamLinker },
        { "min5", 2, 0, 212, 0 },
        { "max5", 2, 0, 216, 0 },
        { "prop6", 19, 0, 220, &gTxtLink_0096BCD8 },
        { "par6", 25, 0, 224, (void*)DATATBLS_ItemParamLinker },
        { "min6", 2, 0, 228, 0 },
        { "max6", 2, 0, 232, 0 },
        { "prop7", 19, 0, 236, &gTxtLink_0096BCD8 },
        { "par7", 25, 0, 240, (void*)DATATBLS_ItemParamLinker },
        { "min7", 2, 0, 244, 0 },
        { "max7", 2, 0, 248, 0 },
        { "prop8", 19, 0, 252, &gTxtLink_0096BCD8 },
        { "par8", 25, 0, 256, (void*)DATATBLS_ItemParamLinker },
        { "min8", 2, 0, 260, 0 },
        { "max8", 2, 0, 264, 0 },
        { "prop9", 19, 0, 268, &gTxtLink_0096BCD8 },
        { "par9", 25, 0, 272, (void*)DATATBLS_ItemParamLinker },
        { "min9", 2, 0, 276, 0 },
        { "max9", 2, 0, 280, 0 },
        { "prop10", 19, 0, 284, &gTxtLink_0096BCD8 },
        { "par10", 25, 0, 288, (void*)DATATBLS_ItemParamLinker },
        { "min10", 2, 0, 292, 0 },
        { "max10", 2, 0, 296, 0 },
        { "prop11", 19, 0, 300, &gTxtLink_0096BCD8 },
        { "par11", 25, 0, 304, (void*)DATATBLS_ItemParamLinker },
        { "min11", 2, 0, 308, 0 },
        { "max11", 2, 0, 312, 0 },
        { "prop12", 19, 0, 316, &gTxtLink_0096BCD8 },
        { "par12", 25, 0, 320, (void*)DATATBLS_ItemParamLinker },
        { "min12", 2, 0, 324, 0 },
        { "max12", 2, 0, 328, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpUniqueitemsLinker = FOG_AllocLinker(".\\DATATBLS\\ItemTbls.cpp", 890);
    gpUniqueitemsTxt = (D2UniqueItemsTxt*)DATATBLS_CompileTxt(hArchive, "uniqueitems", pTbl, &gnUniqueitemsTxtRecordCount, 332);
    TBL_ASSERT(gnUniqueitemsTxtRecordCount < 32767, 892);

    for (int i = 0; i < gnUniqueitemsTxtRecordCount; ++i)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = &gpUniqueitemsTxt[i];
        pUniqueItemsTxtRecord->wId = i;
        FOG_10216_AddRecordToLinkingTable(gpUniqueitemsLinker, pUniqueItemsTxtRecord->szName);
        void* pUnicode = 0;
        pUniqueItemsTxtRecord->wTblIndex = D2LANG_GetTblIndex(pUniqueItemsTxtRecord->szName, &pUnicode);
        if (!pUniqueItemsTxtRecord->wTblIndex)
        {
            pUniqueItemsTxtRecord->wTblIndex = 5383;
        }
    }
}

// 0x00634D90
void __fastcall DATATBLS_UnloadUniqueItemsTxt()
{
    FOG_FreeLinker(gpUniqueItemsLinker);
    DATATBLS_UnloadBin(gpUniqueItemsTxt);
    gnUniqueitemsTxtRecordCount = 0;
}

// 0x00633730
void __fastcall DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(void* hArchive)
{
    D2MagicAffixTxt* pMagicSuffix;
    D2MagicAffixTxt* pMagicPrefix;
    D2MagicAffixTxt* pAutoMagic;

    int nSuffixRecords;
    int nPrefixRecords;
    int nAutoMagicRecords;

    D2BinFieldStrc pTbl[] =
    {
        { "name", TXTFIELD_ASCII, 31, 0, 0 },
        { "spawnable", TXTFIELD_BYTE, 0, 84, 0 },
        { "level", TXTFIELD_DWORD, 0, 88, 0 },
        { "group", TXTFIELD_DWORD, 0, 92, 0 },
        { gszTxtField_version, TXTFIELD_WORD, 0, 34, 0 },
        { "divide", TXTFIELD_DWORD, 0, 132, 0 },
        { "multiply", TXTFIELD_DWORD, 0, 136, 0 },
        { "add", TXTFIELD_DWORD, 0, 140, 0 },
        { "rare", TXTFIELD_BYTE, 0, 100, 0 },
        { "maxlevel", TXTFIELD_DWORD, 0, 96, 0 },
        { "levelreq", TXTFIELD_BYTE, 0, 101, 0 },
        { "classspecific", TXTFIELD_CODETOBYTE, 0, 102, &sgtDataTables.pPlayerClassLinker },
        { "class", TXTFIELD_CODETOBYTE, 0, 103, &sgtDataTables.pPlayerClassLinker },
        { "classlevelreq", TXTFIELD_BYTE, 0, 104, 0 },
        { "itype1", TXTFIELD_CODETOWORD, 0, 106, &sgtDataTables.pItemTypesLinker },
        { "itype2", TXTFIELD_CODETOWORD, 0, 108, &sgtDataTables.pItemTypesLinker },
        { "itype3", TXTFIELD_CODETOWORD, 0, 110, &sgtDataTables.pItemTypesLinker },
        { "itype4", TXTFIELD_CODETOWORD, 0, 112, &sgtDataTables.pItemTypesLinker },
        { "itype5", TXTFIELD_CODETOWORD, 0, 114, &sgtDataTables.pItemTypesLinker },
        { "itype6", TXTFIELD_CODETOWORD, 0, 116, &sgtDataTables.pItemTypesLinker },
        { "itype7", TXTFIELD_CODETOWORD, 0, 118, &sgtDataTables.pItemTypesLinker },
        { "etype1", TXTFIELD_CODETOWORD, 0, 120, &sgtDataTables.pItemTypesLinker },
        { "etype2", TXTFIELD_CODETOWORD, 0, 122, &sgtDataTables.pItemTypesLinker },
        { "etype3", TXTFIELD_CODETOWORD, 0, 124, &sgtDataTables.pItemTypesLinker },
        { "etype4", TXTFIELD_CODETOWORD, 0, 126, &sgtDataTables.pItemTypesLinker },
        { "etype5", TXTFIELD_CODETOWORD, 0, 128, &sgtDataTables.pItemTypesLinker },
        { "transformcolor", TXTFIELD_CODETOBYTE, 0, 86, &sgtDataTables.pColorsLinker },
        { "frequency", TXTFIELD_BYTE, 0, 130, 0 },
        { "mod1code", TXTFIELD_NAMETODWORD, 0, 36, &sgtDataTables.pPropertiesLinker },
        { "mod1param", TXTFIELD_CALCTODWORD, 0, 40, (void*)DATATBLS_ItemParamLinker },
        { "mod1min", TXTFIELD_DWORD, 0, 44, 0 },
        { "mod1max", TXTFIELD_DWORD, 0, 48, 0 },
        { "mod2code", TXTFIELD_NAMETODWORD, 0, 52, &sgtDataTables.pPropertiesLinker },
        { "mod2param", TXTFIELD_CALCTODWORD, 0, 56, (void*)DATATBLS_ItemParamLinker },
        { "mod2min", TXTFIELD_DWORD, 0, 60, 0 },
        { "mod2max", TXTFIELD_DWORD, 0, 64, 0 },
        { "mod3code", TXTFIELD_NAMETODWORD, 0, 68, &sgtDataTables.pPropertiesLinker },
        { "mod3param", TXTFIELD_CALCTODWORD, 0, 72, (void*)DATATBLS_ItemParamLinker },
        { "mod3min", TXTFIELD_DWORD, 0, 76, 0 },
        { "mod3max", TXTFIELD_DWORD, 0, 80, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    pMagicSuffix = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "magicsuffix", pTbl, &nSuffixRecords, sizeof(D2MagicAffixTxt));
    pMagicPrefix = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "magicprefix", pTbl, &nPrefixRecords, sizeof(D2MagicAffixTxt));
    pAutoMagic = (D2MagicAffixTxt*)DATATBLS_CompileTxt(hArchive, "automagic", pTbl, &nAutoMagicRecords, sizeof(D2MagicAffixTxt));

    sgtMagicItemModsDataTblDesc.nMagicAffixTxtRecordCount = nSuffixRecords + nPrefixRecords + nAutoMagicRecords;
    sgtMagicItemModsDataTblDesc.pMagicAffixTxt = (D2MagicAffixTxt*)FOG_AllocPool(0, sizeof(D2MagicAffixTxt) * sgtMagicItemModsDataTblDesc.nMagicAffixTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 663, 0);

    sgtMagicItemModsDataTblDesc.pMagicSuffix = sgtMagicItemModsDataTblDesc.pMagicAffixTxt;
    memcpy(sgtMagicItemModsDataTblDesc.pMagicAffixTxt, pMagicSuffix, sizeof(D2MagicAffixTxt) * nSuffixRecords);
    memcpy(sgtMagicItemModsDataTblDesc.pMagicPrefix = &sgtMagicItemModsDataTblDesc.pMagicSuffix[nSuffixRecords], pMagicPrefix, sizeof(D2MagicAffixTxt) * nPrefixRecords);
    memcpy(sgtMagicItemModsDataTblDesc.pAutoMagic = &sgtMagicItemModsDataTblDesc.pMagicPrefix[nPrefixRecords], pAutoMagic, sizeof(D2MagicAffixTxt) * nAutoMagicRecords);

    DATATBLS_UnloadBin(pMagicSuffix);
    DATATBLS_UnloadBin(pMagicPrefix);
    DATATBLS_UnloadBin(pAutoMagic);

    void* pUnicode = 0;
    for (int i = 0; i < sgtMagicItemModsDataTblDesc.nMagicAffixTxtRecordCount; ++i)
    {
        sgtMagicItemModsDataTblDesc.pMagicAffixTxt[i].wTblIndex = D2LANG_GetTblIndex(sgtMagicItemModsDataTblDesc.pMagicAffixTxt[i].szName, &pUnicode);
    }
}

struct D2SetsTxt
{
    unsigned short wSetId;
    unsigned short wStringId;
    unsigned short wVersion;
    unsigned short unk0x06;
    int unk0x08;
    int nSetItems;
    char unk0x10[0x110 - 0x10];
    D2SetItemsTxt* pSetItem[6];
};

extern "C" const char gszTxtField_name[];                                                           // 0x006E7C68
extern "C" const char gszTxtField_item[];                                                           // 0x006E9E2C
extern "C" const char gszTxtField_set[];                                                            // 0x006D5BCC
extern "C" const char gszTxtField_lvl[];                                                            // 0x006E9CB8
extern "C" const char gszTxtField_lvl_req[];                                                        // 0x006E9CB0
extern "C" const char gszTxtField_rarity[];                                                         // 0x006E9908
extern "C" const char gszTxtField_cost_mult[];                                                      // 0x006E6860
extern "C" const char gszTxtField_cost_add[];                                                       // 0x006E6854
extern "C" const char gszTxtField_chrtransform[];                                                   // 0x006E9C90
extern "C" const char gszTxtField_invtransform[];                                                   // 0x006E9C80
extern "C" const char gszTxtField_flippyfile[];                                                     // 0x006E9830
extern "C" const char gszTxtField_invfile[];                                                        // 0x006E9828
extern "C" const char gszTxtField_dropsound[];                                                      // 0x006E9770
extern "C" const char gszTxtField_dropsfxframe[];                                                   // 0x006E9760
extern "C" const char gszTxtField_usesound[];                                                       // 0x006E9754
extern "C" const char gszTxtField_add_func[];                                                       // 0x006E9E20
extern "C" const char gszTxtField_prop1[];                                                          // 0x006E9C78
extern "C" const char gszTxtField_par1[];                                                           // 0x006E9C70
extern "C" const char gszTxtField_min1[];                                                           // 0x006E9C68
extern "C" const char gszTxtField_max1[];                                                           // 0x006E9C60
extern "C" const char gszTxtField_prop2[];                                                          // 0x006E9C58
extern "C" const char gszTxtField_par2[];                                                           // 0x006E9C50
extern "C" const char gszTxtField_min2[];                                                           // 0x006E9C48
extern "C" const char gszTxtField_max2[];                                                           // 0x006E9C40
extern "C" const char gszTxtField_prop3[];                                                          // 0x006E9C38
extern "C" const char gszTxtField_par3[];                                                           // 0x006E9C30
extern "C" const char gszTxtField_min3[];                                                           // 0x006E9C28
extern "C" const char gszTxtField_max3[];                                                           // 0x006E9C20
extern "C" const char gszTxtField_prop4[];                                                          // 0x006E9C18
extern "C" const char gszTxtField_par4[];                                                           // 0x006E9C10
extern "C" const char gszTxtField_min4[];                                                           // 0x006E9C08
extern "C" const char gszTxtField_max4[];                                                           // 0x006E9C00
extern "C" const char gszTxtField_prop5[];                                                          // 0x006E9BF8
extern "C" const char gszTxtField_par5[];                                                           // 0x006E9BF0
extern "C" const char gszTxtField_min5[];                                                           // 0x006E9BE8
extern "C" const char gszTxtField_max5[];                                                           // 0x006E9BE0
extern "C" const char gszTxtField_prop6[];                                                          // 0x006E9BD8
extern "C" const char gszTxtField_par6[];                                                           // 0x006E9BD0
extern "C" const char gszTxtField_min6[];                                                           // 0x006E9BC8
extern "C" const char gszTxtField_max6[];                                                           // 0x006E9BC0
extern "C" const char gszTxtField_prop7[];                                                          // 0x006E9BB8
extern "C" const char gszTxtField_par7[];                                                           // 0x006E9BB0
extern "C" const char gszTxtField_min7[];                                                           // 0x006E9BA8
extern "C" const char gszTxtField_max7[];                                                           // 0x006E9BA0
extern "C" const char gszTxtField_prop8[];                                                          // 0x006E9B98
extern "C" const char gszTxtField_par8[];                                                           // 0x006E9B90
extern "C" const char gszTxtField_min8[];                                                           // 0x006E9B88
extern "C" const char gszTxtField_max8[];                                                           // 0x006E9B80
extern "C" const char gszTxtField_prop9[];                                                          // 0x006E9B78
extern "C" const char gszTxtField_par9[];                                                           // 0x006E9B70
extern "C" const char gszTxtField_min9[];                                                           // 0x006E9B68
extern "C" const char gszTxtField_max9[];                                                           // 0x006E9B60
extern "C" const char gszTxtField_aprop1a[];                                                        // 0x006E9E18
extern "C" const char gszTxtField_apar1a[];                                                         // 0x006E9E10
extern "C" const char gszTxtField_amin1a[];                                                         // 0x006E9E08
extern "C" const char gszTxtField_amax1a[];                                                         // 0x006E9E00
extern "C" const char gszTxtField_aprop1b[];                                                        // 0x006E9DF8
extern "C" const char gszTxtField_apar1b[];                                                         // 0x006E9DF0
extern "C" const char gszTxtField_amin1b[];                                                         // 0x006E9DE8
extern "C" const char gszTxtField_amax1b[];                                                         // 0x006E9DE0
extern "C" const char gszTxtField_aprop2a[];                                                        // 0x006E9DD8
extern "C" const char gszTxtField_apar2a[];                                                         // 0x006E9DD0
extern "C" const char gszTxtField_amin2a[];                                                         // 0x006E9DC8
extern "C" const char gszTxtField_amax2a[];                                                         // 0x006E9DC0
extern "C" const char gszTxtField_aprop2b[];                                                        // 0x006E9DB8
extern "C" const char gszTxtField_apar2b[];                                                         // 0x006E9DB0
extern "C" const char gszTxtField_amin2b[];                                                         // 0x006E9DA8
extern "C" const char gszTxtField_amax2b[];                                                         // 0x006E9DA0
extern "C" const char gszTxtField_aprop3a[];                                                        // 0x006E9D98
extern "C" const char gszTxtField_apar3a[];                                                         // 0x006E9D90
extern "C" const char gszTxtField_amin3a[];                                                         // 0x006E9D88
extern "C" const char gszTxtField_amax3a[];                                                         // 0x006E9D80
extern "C" const char gszTxtField_aprop3b[];                                                        // 0x006E9D78
extern "C" const char gszTxtField_apar3b[];                                                         // 0x006E9D70
extern "C" const char gszTxtField_amin3b[];                                                         // 0x006E9D68
extern "C" const char gszTxtField_amax3b[];                                                         // 0x006E9D60
extern "C" const char gszTxtField_aprop4a[];                                                        // 0x006E9D58
extern "C" const char gszTxtField_apar4a[];                                                         // 0x006E9D50
extern "C" const char gszTxtField_amin4a[];                                                         // 0x006E9D48
extern "C" const char gszTxtField_amax4a[];                                                         // 0x006E9D40
extern "C" const char gszTxtField_aprop4b[];                                                        // 0x006E9D38
extern "C" const char gszTxtField_apar4b[];                                                         // 0x006E9D30
extern "C" const char gszTxtField_amin4b[];                                                         // 0x006E9D28
extern "C" const char gszTxtField_amax4b[];                                                         // 0x006E9D20
extern "C" const char gszTxtField_aprop5a[];                                                        // 0x006E9D18
extern "C" const char gszTxtField_apar5a[];                                                         // 0x006E9D10
extern "C" const char gszTxtField_amin5a[];                                                         // 0x006E9D08
extern "C" const char gszTxtField_amax5a[];                                                         // 0x006E9D00
extern "C" const char gszTxtField_aprop5b[];                                                        // 0x006E9CF8
extern "C" const char gszTxtField_apar5b[];                                                         // 0x006E9CF0
extern "C" const char gszTxtField_amin5b[];                                                         // 0x006E9CE8
extern "C" const char gszTxtField_amax5b[];                                                         // 0x006E9CE0
extern "C" const char gszTxtName_setitems[];                                                        // 0x006E9CD4
D2TxtLinkStrc* __stdcall sub_006BD040_AllocBlock(const char* szFile, int nLine);                    // 0x006BD040

// 0x00634DC0
void __fastcall DATATBLS_LoadSets_SetItemsTxt(void* hArchive)
{
    D2BinFieldStrc pSetsTbl[] =
    {
        { gszTxtField_index, 17, 0, 0, &sgtDataTables.pSetsLinker },
        { gszTxtField_name, 22, 0, 2, (void*)DATATBLS_GetStringIdFromReferenceString },
        { gszTxtField_version, 3, 0, 4, 0 },
        { "pcode2a", 19, 0, 16, &sgtDataTables.pPropertiesLinker },
        { "pparam2a", 25, 0, 20, (void*)DATATBLS_ItemParamLinker },
        { "pmin2a", 2, 0, 24, 0 },
        { "pmax2a", 2, 0, 28, 0 },
        { "pcode2b", 19, 0, 32, &sgtDataTables.pPropertiesLinker },
        { "pparam2b", 25, 0, 36, (void*)DATATBLS_ItemParamLinker },
        { "pmin2b", 2, 0, 40, 0 },
        { "pmax2b", 2, 0, 44, 0 },
        { "pcode3a", 19, 0, 48, &sgtDataTables.pPropertiesLinker },
        { "pparam3a", 25, 0, 52, (void*)DATATBLS_ItemParamLinker },
        { "pmin3a", 2, 0, 56, 0 },
        { "pmax3a", 2, 0, 60, 0 },
        { "pcode3b", 19, 0, 64, &sgtDataTables.pPropertiesLinker },
        { "pparam3b", 25, 0, 68, (void*)DATATBLS_ItemParamLinker },
        { "pmin3b", 2, 0, 72, 0 },
        { "pmax3b", 2, 0, 76, 0 },
        { "pcode4a", 19, 0, 80, &sgtDataTables.pPropertiesLinker },
        { "pparam4a", 25, 0, 84, (void*)DATATBLS_ItemParamLinker },
        { "pmin4a", 2, 0, 88, 0 },
        { "pmax4a", 2, 0, 92, 0 },
        { "pcode4b", 19, 0, 96, &sgtDataTables.pPropertiesLinker },
        { "pparam4b", 25, 0, 100, (void*)DATATBLS_ItemParamLinker },
        { "pmin4b", 2, 0, 104, 0 },
        { "pmax4b", 2, 0, 108, 0 },
        { "pcode5a", 19, 0, 112, &sgtDataTables.pPropertiesLinker },
        { "pparam5a", 25, 0, 116, (void*)DATATBLS_ItemParamLinker },
        { "pmin5a", 2, 0, 120, 0 },
        { "pmax5a", 2, 0, 124, 0 },
        { "pcode5b", 19, 0, 128, &sgtDataTables.pPropertiesLinker },
        { "pparam5b", 25, 0, 132, (void*)DATATBLS_ItemParamLinker },
        { "pmin5b", 2, 0, 136, 0 },
        { "pmax5b", 2, 0, 140, 0 },
        { "fcode1", 19, 0, 144, &sgtDataTables.pPropertiesLinker },
        { "fparam1", 25, 0, 148, (void*)DATATBLS_ItemParamLinker },
        { "fmin1", 2, 0, 152, 0 },
        { "fmax1", 2, 0, 156, 0 },
        { "fcode2", 19, 0, 160, &sgtDataTables.pPropertiesLinker },
        { "fparam2", 25, 0, 164, (void*)DATATBLS_ItemParamLinker },
        { "fmin2", 2, 0, 168, 0 },
        { "fmax2", 2, 0, 172, 0 },
        { "fcode3", 19, 0, 176, &sgtDataTables.pPropertiesLinker },
        { "fparam3", 25, 0, 180, (void*)DATATBLS_ItemParamLinker },
        { "fmin3", 2, 0, 184, 0 },
        { "fmax3", 2, 0, 188, 0 },
        { "fcode4", 19, 0, 192, &sgtDataTables.pPropertiesLinker },
        { "fparam4", 25, 0, 196, (void*)DATATBLS_ItemParamLinker },
        { "fmin4", 2, 0, 200, 0 },
        { "fmax4", 2, 0, 204, 0 },
        { "fcode5", 19, 0, 208, &sgtDataTables.pPropertiesLinker },
        { "fparam5", 25, 0, 212, (void*)DATATBLS_ItemParamLinker },
        { "fmin5", 2, 0, 216, 0 },
        { "fmax5", 2, 0, 220, 0 },
        { "fcode6", 19, 0, 224, &sgtDataTables.pPropertiesLinker },
        { "fparam6", 25, 0, 228, (void*)DATATBLS_ItemParamLinker },
        { "fmin6", 2, 0, 232, 0 },
        { "fmax6", 2, 0, 236, 0 },
        { "fcode7", 19, 0, 240, &sgtDataTables.pPropertiesLinker },
        { "fparam7", 25, 0, 244, (void*)DATATBLS_ItemParamLinker },
        { "fmin7", 2, 0, 248, 0 },
        { "fmax7", 2, 0, 252, 0 },
        { "fcode8", 19, 0, 256, &sgtDataTables.pPropertiesLinker },
        { "fparam8", 25, 0, 260, (void*)DATATBLS_ItemParamLinker },
        { "fmin8", 2, 0, 264, 0 },
        { "fmax8", 2, 0, 268, 0 },
        { "end", 0, 0, 0, 0 },
    };

    sgtDataTables.pSetsLinker = sub_006BD040_AllocBlock(gszItemsTblsSourceFile, 1010);
    sgtDataTables.pSetsTxt = (D2SetsTxt*)DATATBLS_CompileTxt(hArchive, "sets", pSetsTbl, &sgtDataTables.nSetsTxtRecordCount, sizeof(D2SetsTxt));
    ITEM_ASSERT(sgtDataTables.nSetsTxtRecordCount < 32767, 1012);

    D2BinFieldStrc pSetItemsTbl[] =
    {
        { gszTxtField_index, 1, 31, 2, 0 },
        { gszTxtField_item, 9, 0, 40, 0 },
        { gszTxtField_set, 20, 0, 44, &sgtDataTables.pSetsLinker },
        { gszTxtField_lvl, 3, 0, 48, 0 },
        { gszTxtField_lvl_req, 3, 0, 50, 0 },
        { gszTxtField_rarity, 2, 0, 52, 0 },
        { gszTxtField_cost_mult, 2, 0, 56, 0 },
        { gszTxtField_cost_add, 2, 0, 60, 0 },
        { gszTxtField_chrtransform, 13, 0, 64, &sgtDataTables.pColorsLinker },
        { gszTxtField_invtransform, 13, 0, 65, &sgtDataTables.pColorsLinker },
        { gszTxtField_flippyfile, 1, 31, 66, 0 },
        { gszTxtField_invfile, 1, 31, 98, 0 },
        { gszTxtField_dropsound, 20, 0, 130, &sgtDataTables.pSoundsLinker },
        { gszTxtField_dropsfxframe, 4, 0, 134, 0 },
        { gszTxtField_usesound, 20, 0, 132, &sgtDataTables.pSoundsLinker },
        { gszTxtField_add_func, 4, 0, 135, 0 },
        { gszTxtField_prop1, 19, 0, 136, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par1, 25, 0, 140, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min1, 2, 0, 144, 0 },
        { gszTxtField_max1, 2, 0, 148, 0 },
        { gszTxtField_prop2, 19, 0, 152, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par2, 25, 0, 156, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min2, 2, 0, 160, 0 },
        { gszTxtField_max2, 2, 0, 164, 0 },
        { gszTxtField_prop3, 19, 0, 168, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par3, 25, 0, 172, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min3, 2, 0, 176, 0 },
        { gszTxtField_max3, 2, 0, 180, 0 },
        { gszTxtField_prop4, 19, 0, 184, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par4, 25, 0, 188, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min4, 2, 0, 192, 0 },
        { gszTxtField_max4, 2, 0, 196, 0 },
        { gszTxtField_prop5, 19, 0, 200, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par5, 25, 0, 204, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min5, 2, 0, 208, 0 },
        { gszTxtField_max5, 2, 0, 212, 0 },
        { gszTxtField_prop6, 19, 0, 216, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par6, 25, 0, 220, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min6, 2, 0, 224, 0 },
        { gszTxtField_max6, 2, 0, 228, 0 },
        { gszTxtField_prop7, 19, 0, 232, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par7, 25, 0, 236, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min7, 2, 0, 240, 0 },
        { gszTxtField_max7, 2, 0, 244, 0 },
        { gszTxtField_prop8, 19, 0, 248, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par8, 25, 0, 252, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min8, 2, 0, 256, 0 },
        { gszTxtField_max8, 2, 0, 260, 0 },
        { gszTxtField_prop9, 19, 0, 264, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_par9, 25, 0, 268, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_min9, 2, 0, 272, 0 },
        { gszTxtField_max9, 2, 0, 276, 0 },
        { gszTxtField_aprop1a, 19, 0, 280, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar1a, 25, 0, 284, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin1a, 2, 0, 288, 0 },
        { gszTxtField_amax1a, 2, 0, 292, 0 },
        { gszTxtField_aprop1b, 19, 0, 296, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar1b, 25, 0, 300, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin1b, 2, 0, 304, 0 },
        { gszTxtField_amax1b, 2, 0, 308, 0 },
        { gszTxtField_aprop2a, 19, 0, 312, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar2a, 25, 0, 316, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin2a, 2, 0, 320, 0 },
        { gszTxtField_amax2a, 2, 0, 324, 0 },
        { gszTxtField_aprop2b, 19, 0, 328, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar2b, 25, 0, 332, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin2b, 2, 0, 336, 0 },
        { gszTxtField_amax2b, 2, 0, 340, 0 },
        { gszTxtField_aprop3a, 19, 0, 344, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar3a, 25, 0, 348, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin3a, 2, 0, 352, 0 },
        { gszTxtField_amax3a, 2, 0, 356, 0 },
        { gszTxtField_aprop3b, 19, 0, 360, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar3b, 25, 0, 364, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin3b, 2, 0, 368, 0 },
        { gszTxtField_amax3b, 2, 0, 372, 0 },
        { gszTxtField_aprop4a, 19, 0, 376, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar4a, 25, 0, 380, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin4a, 2, 0, 384, 0 },
        { gszTxtField_amax4a, 2, 0, 388, 0 },
        { gszTxtField_aprop4b, 19, 0, 392, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar4b, 25, 0, 396, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin4b, 2, 0, 400, 0 },
        { gszTxtField_amax4b, 2, 0, 404, 0 },
        { gszTxtField_aprop5a, 19, 0, 408, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar5a, 25, 0, 412, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin5a, 2, 0, 416, 0 },
        { gszTxtField_amax5a, 2, 0, 420, 0 },
        { gszTxtField_aprop5b, 19, 0, 424, &sgtDataTables.pPropertiesLinker },
        { gszTxtField_apar5b, 25, 0, 428, (void*)DATATBLS_ItemParamLinker },
        { gszTxtField_amin5b, 2, 0, 432, 0 },
        { gszTxtField_amax5b, 2, 0, 436, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgtDataTables.pSetItemsLinker = sub_006BD040_AllocBlock(gszItemsTblsSourceFile, 1117);
    sgtDataTables.pSetItemsTxt = (D2SetItemsTxt*)DATATBLS_CompileTxt(hArchive, gszTxtName_setitems, pSetItemsTbl, &sgtDataTables.nSetItemsTxtRecordCount, sizeof(D2SetItemsTxt));
    ITEM_ASSERT(sgtDataTables.nSetItemsTxtRecordCount < 32767, 1119);

    for (int i = 0; i < sgtDataTables.nSetItemsTxtRecordCount; ++i)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = &sgtDataTables.pSetItemsTxt[i];
        pSetItemsTxtRecord->wSetItemId = i;
        FOG_10216_AddRecordToLinkingTable(sgtDataTables.pSetItemsLinker, pSetItemsTxtRecord->szName);
        void* pUnicode = 0;
        pSetItemsTxtRecord->wTblIndex = D2LANG_GetTblIndex(pSetItemsTxtRecord->szName, &pUnicode);
        if (!pSetItemsTxtRecord->wTblIndex)
        {
            pSetItemsTxtRecord->wTblIndex = 5383;
        }

        if (pSetItemsTxtRecord->nSetId >= 0 && pSetItemsTxtRecord->nSetId < sgtDataTables.nSetsTxtRecordCount)
        {
            D2SetsTxt* pSetsTxtRecord = &sgtDataTables.pSetsTxt[pSetItemsTxtRecord->nSetId];
            if (pSetsTxtRecord->nSetItems < 6)
            {
                pSetItemsTxtRecord->wVersion = pSetsTxtRecord->wVersion;
                pSetItemsTxtRecord->nSetItems = pSetsTxtRecord->nSetItems;
                pSetsTxtRecord->pSetItem[pSetItemsTxtRecord->nSetItems] = pSetItemsTxtRecord;
                ++pSetsTxtRecord->nSetItems;
            }
        }
    }
}

// 0x00636730
void __fastcall DATATBLS_UnloadSets_SetItemsTxt()
{
    FOG_FreeLinker(gpSetsLinker);
    FOG_FreeLinker(gpSetItemsLinker);
    DATATBLS_UnloadBin(gpSetItemsTxt);
    DATATBLS_UnloadBin(gpSetsTxt);
    gnSetsTxtRecordCount = 0;
    gnSetItemsTxtRecordCount = 0;
}

// 0x00636770
void __fastcall DATATBLS_LoadQualityItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "nummods", 4, 0, 10, 0 },
        { "mod1code", 19, 0, 12, &gTxtLink_0096BCD8 },
        { "mod2code", 19, 0, 28, &gTxtLink_0096BCD8 },
        { "mod1param", 2, 0, 16, 0 },
        { "mod1min", 2, 0, 20, 0 },
        { "mod1max", 2, 0, 24, 0 },
        { "mod2param", 2, 0, 32, 0 },
        { "mod2min", 2, 0, 36, 0 },
        { "mod2max", 2, 0, 40, 0 },
        { "effect1", 1, 31, 44, 0 },
        { "effect2", 1, 31, 76, 0 },
        { "armor", 4, 0, 0, 0 },
        { "weapon", 4, 0, 1, 0 },
        { "shield", 4, 0, 2, 0 },
        { "scepter", 4, 0, 3, 0 },
        { "wand", 4, 0, 4, 0 },
        { "staff", 4, 0, 5, 0 },
        { "bow", 4, 0, 6, 0 },
        { "boots", 4, 0, 7, 0 },
        { "gloves", 4, 0, 8, 0 },
        { "belt", 4, 0, 9, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpQualityitemsTxt = (D2QualityItemsTxt*)DATATBLS_CompileTxt(hArchive, "qualityitems", pTbl, &gnQualityitemsTxtRecordCount, 112);

    void* pUnicode = 0;
    for (int i = 0; i < gnQualityitemsTxtRecordCount; ++i)
    {
        if (gpQualityitemsTxt[i].szEffect1[0])
        {
            gpQualityitemsTxt[i].wEffect1TblId = D2LANG_GetTblIndex(gpQualityitemsTxt[i].szEffect1, &pUnicode);
        }

        if (gpQualityitemsTxt[i].szEffect2[0])
        {
            gpQualityitemsTxt[i].wEffect2TblId = D2LANG_GetTblIndex(gpQualityitemsTxt[i].szEffect2, &pUnicode);
        }
    }
}

// 0x00636B00
void __fastcall DATATBLS_UnloadQualityItemsTxt()
{
    DATATBLS_UnloadBin(gQualityItemDataTables.pQualityItemsTxt);
}

// 0x00636B10
D2QualityItemDataTbl* __fastcall DATATBLS_GetQualityItemDataTables()
{
    return &gQualityItemDataTables;
}

// 0x00636B20
D2QualityItemsTxt* __stdcall DATATBLS_GetQualityItemsTxtRecord(int nIndex)
{
    if (nIndex >= gQualityItemDataTables.nQualityItemsTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gQualityItemDataTables.pQualityItemsTxt, 1266);
        ITEM_ASSERT(&gQualityItemDataTables.pQualityItemsTxt[nIndex], 1266 + 1);
        return &gQualityItemDataTables.pQualityItemsTxt[nIndex];
    }
}

// 0x00636B70
void __fastcall DATATBLS_LoadGemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "letter", 1, 5, 32, 0 },
        { gszTxtField_code, 11, 0, 40, &gpItemsLinker_0096BCC4 },
        { "transform", 4, 0, 47, 0 },
        { "nummods", 4, 0, 46, 0 },
        { "weaponmod1code", 19, 0, 48, &gTxtLink_0096BCD8 },
        { "weaponmod1param", 25, 0, 52, (void*)DATATBLS_ItemParamLinker },
        { "weaponmod1min", 2, 0, 56, 0 },
        { "weaponmod1max", 2, 0, 60, 0 },
        { "weaponmod2code", 19, 0, 64, &gTxtLink_0096BCD8 },
        { "weaponmod2param", 25, 0, 68, (void*)DATATBLS_ItemParamLinker },
        { "weaponmod2min", 2, 0, 72, 0 },
        { "weaponmod2max", 2, 0, 76, 0 },
        { "weaponmod3code", 19, 0, 80, &gTxtLink_0096BCD8 },
        { "weaponmod3param", 25, 0, 84, (void*)DATATBLS_ItemParamLinker },
        { "weaponmod3min", 2, 0, 88, 0 },
        { "weaponmod3max", 2, 0, 92, 0 },
        { "helmmod1code", 19, 0, 96, &gTxtLink_0096BCD8 },
        { "helmmod1param", 25, 0, 100, (void*)DATATBLS_ItemParamLinker },
        { "helmmod1min", 2, 0, 104, 0 },
        { "helmmod1max", 2, 0, 108, 0 },
        { "helmmod2code", 19, 0, 112, &gTxtLink_0096BCD8 },
        { "helmmod2param", 25, 0, 116, (void*)DATATBLS_ItemParamLinker },
        { "helmmod2min", 2, 0, 120, 0 },
        { "helmmod2max", 2, 0, 124, 0 },
        { "helmmod3code", 19, 0, 128, &gTxtLink_0096BCD8 },
        { "helmmod3param", 25, 0, 132, (void*)DATATBLS_ItemParamLinker },
        { "helmmod3min", 2, 0, 136, 0 },
        { "helmmod3max", 2, 0, 140, 0 },
        { "shieldmod1code", 19, 0, 144, &gTxtLink_0096BCD8 },
        { "shieldmod1param", 25, 0, 148, (void*)DATATBLS_ItemParamLinker },
        { "shieldmod1min", 2, 0, 152, 0 },
        { "shieldmod1max", 2, 0, 156, 0 },
        { "shieldmod2code", 19, 0, 160, &gTxtLink_0096BCD8 },
        { "shieldmod2param", 25, 0, 164, (void*)DATATBLS_ItemParamLinker },
        { "shieldmod2min", 2, 0, 168, 0 },
        { "shieldmod2max", 2, 0, 172, 0 },
        { "shieldmod3code", 19, 0, 176, &gTxtLink_0096BCD8 },
        { "shieldmod3param", 25, 0, 180, (void*)DATATBLS_ItemParamLinker },
        { "shieldmod3min", 2, 0, 184, 0 },
        { "shieldmod3max", 2, 0, 188, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpGemsTxt = (D2GemsTxt*)DATATBLS_CompileTxt(hArchive, "gems", pTbl, &gnGemsTxtRecordCount, 192);

    char szReference[4];
    void* pUnicode = 0;
    for (int i = 0; i < gnGemsTxtRecordCount; ++i)
    {
        szReference[0] = (gpGemsTxt[i].szItemCode[0] == ' ') ? 0 : gpGemsTxt[i].szItemCode[0];
        szReference[1] = (gpGemsTxt[i].szItemCode[1] == ' ') ? 0 : gpGemsTxt[i].szItemCode[1];
        szReference[2] = (gpGemsTxt[i].szItemCode[2] == ' ') ? 0 : gpGemsTxt[i].szItemCode[2];
        szReference[3] = 0;

        gpGemsTxt[i].wStringId = D2LANG_GetTblIndex(szReference, &pUnicode);
    }

    for (int i = 0; i < gnGemsTxtRecordCount; ++i)
    {
        gpItemsTxt_0096CA5C[i].dwGemOffset = -1;
        int nItemCode = gpGemsTxt[i].dwItemCode;
        if (nItemCode >= 0)
        {
            gpItemsTxt_0096CA5C[nItemCode].dwGemOffset = i;
        }
    }
}

// 0x006372A0
void __fastcall DATATBLS_UnloadGemsTxt()
{
    DATATBLS_UnloadBin(gGemDataTables.pGemsTxt);
}

// 0x006372B0
D2GemDataTbl* __fastcall DATATBLS_GetGemDataTables()
{
    return &gGemDataTables;
}

// 0x006372C0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nIndex)
{
    if (nIndex >= gGemDataTables.nGemsTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gGemDataTables.pGemsTxt, 1379);
        ITEM_ASSERT(&gGemDataTables.pGemsTxt[nIndex], 1379 + 1);
        return &gGemDataTables.pGemsTxt[nIndex];
    }
}

// 0x00637320
void __fastcall DATATBLS_LoadBooksTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 22, 0, 0, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "scrollspellcode", 9, 0, 24, 0 },
        { "bookspellcode", 9, 0, 28, 0 },
        { "pSpell", 2, 0, 4, 0 },
        { "scrollskill", 19, 0, 8, &gTxtLink_0096C7CC },
        { "bookskill", 19, 0, 12, &gTxtLink_0096C7CC },
        { "spellicon", 4, 0, 2, 0 },
        { "basecost", 2, 0, 16, 0 },
        { "costpercharge", 2, 0, 20, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpBooksTxt = DATATBLS_CompileTxt(hArchive, "books", pTbl, &gnBooksTxtRecordCount, 32);
}

// 0x00637490
void __fastcall DATATBLS_UnloadBooksTxt()
{
    DATATBLS_UnloadBin(gBookDataTables.pBooksTxt);
}

// 0x006374A0
D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables()
{
    return &gBookDataTables;
}

// 0x006374B0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex)
{
    if (nIndex >= gBookDataTables.nBooksTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gBookDataTables.pBooksTxt, 1436);
        ITEM_ASSERT(&gBookDataTables.pBooksTxt[nIndex], 1436 + 1);
        return &gBookDataTables.pBooksTxt[nIndex];
    }
}

// 0x00637500
void __fastcall DATATBLS_LoadLowQualityItemsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Name", 1, 31, 0, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpLowqualityitemsTxt = (D2LowQualityItemsTxt*)DATATBLS_CompileTxt(hArchive, "lowqualityitems", pTbl, &gnLowqualityitemsTxtRecordCount, 34);

    void* pUnicode = 0;
    for (int i = 0; i < gnLowqualityitemsTxtRecordCount; ++i)
    {
        gpLowqualityitemsTxt[i].wTblId = D2LANG_GetTblIndex(gpLowqualityitemsTxt[i].szName, &pUnicode);
    }
}

// 0x006375A0
void __fastcall DATATBLS_UnloadLowQualityItemsTxt()
{
    DATATBLS_UnloadBin(gLowQualityItemDataTables.pLowQualityItemsTxt);
}

// 0x006375B0
D2LowQualityItemDataTbl* __fastcall DATATBLS_GetLowQualityItemDataTables()
{
    return &gLowQualityItemDataTables;
}

// 0x006375C0
D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nIndex)
{
    if (nIndex >= gLowQualityItemDataTables.nLowQualityItemsTxtRecordCount || nIndex == -1)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gLowQualityItemDataTables.pLowQualityItemsTxt, 1488);
        ITEM_ASSERT(&gLowQualityItemDataTables.pLowQualityItemsTxt[nIndex], 1488 + 1);
        return &gLowQualityItemDataTables.pLowQualityItemsTxt[nIndex];
    }
}

// 0x00637620
void __fastcall DATATBLS_LoadItemRatioTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Version", 3, 0, 64, 0 },
        { "Uber", 4, 0, 66, 0 },
        { "Class Specific", 4, 0, 67, 0 },
        { "Unique", 2, 0, 0, 0 },
        { "UniqueDivisor", 2, 0, 4, 0 },
        { "UniqueMin", 2, 0, 8, 0 },
        { "Rare", 2, 0, 12, 0 },
        { "RareDivisor", 2, 0, 16, 0 },
        { "RareMin", 2, 0, 20, 0 },
        { "Set", 2, 0, 24, 0 },
        { "SetDivisor", 2, 0, 28, 0 },
        { "SetMin", 2, 0, 32, 0 },
        { "Magic", 2, 0, 36, 0 },
        { "MagicDivisor", 2, 0, 40, 0 },
        { "MagicMin", 2, 0, 44, 0 },
        { "HiQuality", 2, 0, 48, 0 },
        { "HiQualityDivisor", 2, 0, 52, 0 },
        { "Normal", 2, 0, 56, 0 },
        { "NormalDivisor", 2, 0, 60, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpItemratioTxt = DATATBLS_CompileTxt(hArchive, "itemratio", pTbl, &gnItemratioTxtRecordCount, 68);
}

// 0x006378F0
void __fastcall DATATBLS_UnloadItemRatioTxt()
{
    DATATBLS_UnloadBin(gItemRatioDataTables.pItemRatioTxt);
}

// 0x00637900
D2ItemRatioDataTbl* __fastcall DATATBLS_GetItemRatioDataTables()
{
    return &gItemRatioDataTables;
}

// 0x00637910
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int nItemId, unsigned char nDifficulty, unsigned short wVersion)
{
    int nId = -1;
    int nLastVersion = -1;

    const int nClass = ITEMS_IsClassValidByItemId(nItemId);
    const int nQuest = ITEMS_GetQuestFromItemId(nItemId);

    D2_ASSERT(wVersion == 0 || wVersion == 100, 1565);

    for (int i = 0; i < gItemRatioDataTables.nItemRatioTxtRecordCount; ++i)
    {
        if (nClass == gItemRatioDataTables.pItemRatioTxt[i].nClassSpecific
            && nQuest == gItemRatioDataTables.pItemRatioTxt[i].nUber
            && gItemRatioDataTables.pItemRatioTxt[i].wVersion <= wVersion
            && gItemRatioDataTables.pItemRatioTxt[i].wVersion >= nLastVersion)
        {
            nLastVersion = gItemRatioDataTables.pItemRatioTxt[i].wVersion;
            nId = i;
        }
    }

    if (nId < 0)
    {
        return 0;
    }

    return &gItemRatioDataTables.pItemRatioTxt[nId];
}

// 0x006379D0
int __cdecl DATATBLS_CompareItemStatCostDescs(const void* pRecord1, const void* pRecord2)
{
    D2ItemStatCostDescStrc* pElem1 = (D2ItemStatCostDescStrc*)pRecord1;
    D2ItemStatCostDescStrc* pElem2 = (D2ItemStatCostDescStrc*)pRecord2;

    if (pElem1->nDescPriority < pElem2->nDescPriority)
    {
        return -1;
    }

    return pElem1->nDescPriority != pElem2->nDescPriority;
}

static __forceinline void STATFLAG_SET(unsigned char* pFlags, int nBit)
{
    pFlags[nBit >> 3] |= (unsigned char)gdwBitMasks[nBit & 7];
}

// 0x00637A00
void __fastcall DATATBLS_LoadItemStatCostTxt(void* hArchive)
{
    D2ItemStatCostDescStrc pStatsWithDescFunc[511];
    D2BinFieldStrc pTbl[] =
    {
        { "stat", 17, 0, 0, &gpItemStatCostLinker },
        { "send bits", 4, 0, 8, 0 },
        { "send param bits", 4, 0, 9, 0 },
        { "divide", 2, 0, 12, 0 },
        { "multiply", 2, 0, 16, 0 },
        { "add", 2, 0, 20, 0 },
        { "valshift", 4, 0, 24, 0 },
        { "minaccr", 2, 0, 44, 0 },
        { "save bits", 4, 0, 25, 0 },
        { "save add", 2, 0, 28, 0 },
        { "save param bits", 2, 0, 36, 0 },
        { "1.09-save bits", 4, 0, 26, 0 },
        { "1.09-save add", 2, 0, 32, 0 },
        { "encode", 4, 0, 48, 0 },
        { "send other", 26, 0, 4, 0 },
        { "signed", 26, 1, 4, 0 },
        { "updateanimrate", 26, 9, 4, 0 },
        { "fmin", 26, 10, 4, 0 },
        { "damagerelated", 26, 2, 4, 0 },
        { "itemspecific", 26, 3, 4, 0 },
        { "direct", 26, 4, 4, 0 },
        { "fcallback", 26, 11, 4, 0 },
        { "saved", 26, 12, 4, 0 },
        { "csvsigned", 26, 13, 4, 0 },
        { "csvbits", 4, 0, 10, 0 },
        { "csvparam", 4, 0, 11, 0 },
        { "maxstat", 20, 0, 50, &gpItemStatCostLinker },
        { "itemevent1", 20, 0, 72, &gpEventsLinker_0096BCA8 },
        { "itemeventfunc1", 3, 0, 76, 0 },
        { "itemevent2", 20, 0, 74, &gpEventsLinker_0096BCA8 },
        { "itemeventfunc2", 3, 0, 78, 0 },
        { "descpriority", 3, 0, 52, 0 },
        { "descfunc", 4, 0, 54, 0 },
        { "descval", 4, 0, 55, 0 },
        { "descstrpos", 22, 0, 56, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "descstrneg", 22, 0, 58, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "descstr2", 22, 0, 60, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dgrp", 3, 0, 62, 0 },
        { "dgrpfunc", 4, 0, 64, 0 },
        { "dgrpval", 4, 0, 65, 0 },
        { "dgrpstrpos", 22, 0, 66, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dgrpstrneg", 22, 0, 68, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "dgrpstr2", 22, 0, 70, (void*)DATATBLS_GetStringIdFromReferenceString },
        { "keepzero", 4, 0, 80, 0 },
        { "op", 4, 0, 84, 0 },
        { "op base", 20, 0, 86, &gpItemStatCostLinker },
        { "op param", 4, 0, 85, 0 },
        { "op stat1", 20, 0, 88, &gpItemStatCostLinker },
        { "op stat2", 20, 0, 90, &gpItemStatCostLinker },
        { "op stat3", 20, 0, 92, &gpItemStatCostLinker },
        { "stuff", 2, 0, 320, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpItemStatCostLinker = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 1716);
    gpItemStatCostTxt = (D2ItemStatCostTxt*)DATATBLS_CompileTxt(hArchive, "itemstatcost", pTbl, &gnItemStatCostTxtRecordCount, sizeof(D2ItemStatCostTxt));

    ITEM_ASSERT(gnItemStatCostTxtRecordCount <= 511, 1718);

    gnItemStatCostStuff_0096C89C = gpItemStatCostTxt->nStuff;
    if (gnItemStatCostStuff_0096C89C <= 0 || gnItemStatCostStuff_0096C89C > 8)
    {
        gnItemStatCostStuff_0096C89C = 6;
    }
    gnItemStatCostStuffMask_0096C8A0 = (1 << gnItemStatCostStuff_0096C89C) - 1;

    D2ItemStatCostTxt* pTxt = gpItemStatCostTxt;
    for (int i = 0; i < gnItemStatCostTxtRecordCount; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            pTxt[i].wStatsAffected[j] = 0xFFFF;
        }
    }

    D2ItemStatCostTxt* pItemStatCostTxt = gpItemStatCostTxt;
    for (int i = 0; i < gnItemStatCostTxtRecordCount; ++i)
    {
        if (pItemStatCostTxt->nOp > 0 && pItemStatCostTxt->nOp < 14)
        {
            if (pItemStatCostTxt->wOpBase < gnItemStatCostTxtRecordCount)
            {
                D2ItemStatCostTxt* pOpBase = &gpItemStatCostTxt[pItemStatCostTxt->wOpBase];
                int j = 0;
                pOpBase->bIsBaseOfOtherStatOp = 1;
                for (j = 0; j < 64; ++j)
                {
                    if (pOpBase->wStatsAffected[j] >= gnItemStatCostTxtRecordCount)
                    {
                        break;
                    }
                }

                if (j < 64)
                {
                    pOpBase->wStatsAffected[j] = i;
                }

                if (pItemStatCostTxt->nOp == 4 || pItemStatCostTxt->nOp == 5)
                {
                    pItemStatCostTxt->bHasOpApplyingToItem = 1;
                }
            }

            for (int k = 0; k < 3; ++k)
            {
                int nStatId = pItemStatCostTxt->wOpStat[k];
                if (nStatId >= gnItemStatCostTxtRecordCount)
                {
                    break;
                }

                pItemStatCostTxt->bIsBaseOfOtherStatOp = 1;

                int j = 0;
                for (j = 0; j < 16; ++j)
                {
                    if (!gpItemStatCostTxt[nStatId].pOpStatData[j].nOp)
                    {
                        break;
                    }
                }

                if (j < 16)
                {
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nStat = i;
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nOp = pItemStatCostTxt->nOp;
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nOpBase = pItemStatCostTxt->wOpBase;
                    gpItemStatCostTxt[nStatId].pOpStatData[j].nOpParam = pItemStatCostTxt->nOpParam;
                    gpItemStatCostTxt[nStatId].bHasOpStatData = 1;

                    if (i == 7 || nStatId == 7)
                    {
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 6);
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 5);
                    }
                    else if (i == 9 || nStatId == 9)
                    {
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 7);
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 5);
                    }
                    else if (i == 11 || nStatId == 11)
                    {
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 8);
                        STATFLAG_SET(gpItemStatCostTxt[i].nItemStatFlags, 5);
                    }
                }
            }

            ++pItemStatCostTxt;
        }
        else
        {
            pItemStatCostTxt->nOp = 0;
            ++pItemStatCostTxt;
        }
    }

    gnStatsWithDescFunc = 0;
    for (int i = 0; i < gnItemStatCostTxtRecordCount; ++i)
    {
        if (gpItemStatCostTxt[i].nDescFunc)
        {
            pStatsWithDescFunc[gnStatsWithDescFunc].wStatId = i;
            pStatsWithDescFunc[gnStatsWithDescFunc].nDescPriority = gpItemStatCostTxt[i].nDescPriority;
            ++gnStatsWithDescFunc;
        }
    }

    qsort(pStatsWithDescFunc, gnStatsWithDescFunc, sizeof(D2ItemStatCostDescStrc), DATATBLS_CompareItemStatCostDescs);

    gpStatsWithDescFunc = (unsigned short*)FOG_AllocPool(0, sizeof(unsigned short) * gnStatsWithDescFunc, ".\\DATATBLS\\ItemTbls.cpp", 1864, 0);
    for (int i = 0; i < gnStatsWithDescFunc; ++i)
    {
        gpStatsWithDescFunc[i] = pStatsWithDescFunc[i].wStatId;
    }
}

// 0x006385D0
void __fastcall DATATBLS_UnloadItemStatCostTxt()
{
    if (gpItemStatCostTxt)
    {
        DATATBLS_UnloadBin(gpItemStatCostTxt);
    }
    gpItemStatCostTxt = 0;

    if (gpItemStatCostLinker)
    {
        FOG_FreeLinker(gpItemStatCostLinker);
    }
    gpItemStatCostLinker = 0;
    gnItemStatCostTxtRecordCount = 0;

    if (gpStatsWithDescFunc)
    {
        sub_0040B480(0, gpStatsWithDescFunc, ".\\DATATBLS\\ItemTbls.cpp", 1891, 0);
    }
    gnStatsWithDescFunc = 0;
}

// 0x00638630
void __fastcall DATATBLS_LoadPropertiesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 17, 0, 0, &gTxtLink_0096BCD8 },
        { "set1", 4, 0, 2, 0 },
        { "val1", 3, 0, 10, 0 },
        { "func1", 4, 0, 24, 0 },
        { "stat1", 20, 0, 32, &gTxtLink_0096C800 },
        { "set2", 4, 0, 3, 0 },
        { "val2", 3, 0, 12, 0 },
        { "func2", 4, 0, 25, 0 },
        { "stat2", 20, 0, 34, &gTxtLink_0096C800 },
        { "set3", 4, 0, 4, 0 },
        { "val3", 3, 0, 14, 0 },
        { "func3", 4, 0, 26, 0 },
        { "stat3", 20, 0, 36, &gTxtLink_0096C800 },
        { "set4", 4, 0, 5, 0 },
        { "val4", 3, 0, 16, 0 },
        { "func4", 4, 0, 27, 0 },
        { "stat4", 20, 0, 38, &gTxtLink_0096C800 },
        { "set5", 4, 0, 6, 0 },
        { "val5", 3, 0, 18, 0 },
        { "func5", 4, 0, 28, 0 },
        { "stat5", 20, 0, 40, &gTxtLink_0096C800 },
        { "set6", 4, 0, 7, 0 },
        { "val6", 3, 0, 20, 0 },
        { "func6", 4, 0, 29, 0 },
        { "stat6", 20, 0, 42, &gTxtLink_0096C800 },
        { "set7", 4, 0, 8, 0 },
        { "val7", 3, 0, 22, 0 },
        { "func7", 4, 0, 30, 0 },
        { "stat7", 20, 0, 44, &gTxtLink_0096C800 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096BCD8 = FOG_AllocLinker(".\\DATATBLS\\ItemTbls.cpp", 1942);
    gpPropertiesTxt = DATATBLS_CompileTxt(hArchive, "properties", pTbl, &gnPropertiesTxtRecordCount, 46);
}

// 0x00638AA0
void __fastcall DATATBLS_UnloadPropertiesTxt()
{
    DATATBLS_UnloadBin(gpPropertiesTxt);
    FOG_FreeLinker(gTxtLink_0096BCD8);
}

// 0x00638AC0
int __cdecl DATATBLS_CompareGambleTxtRecords(const void* pRecord1, const void* pRecord2)
{
    unsigned int nLevel1 = ((const D2GambleTxt*)pRecord1)->nLevel;
    unsigned int nLevel2 = ((const D2GambleTxt*)pRecord2)->nLevel;

    if (nLevel1 > nLevel2)
    {
        return 1;
    }

    if (nLevel1 < nLevel2)
    {
        return -1;
    }

    return 0;
}

// 0x00638AE0
void __fastcall DATATBLS_LoadGambleTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_code, 9, 0, 0, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2GambleTxt* pGambleTxt = (D2GambleTxt*)DATATBLS_CompileTxt(hArchive, "gamble", pTbl, &sgtDataTables.pGambleDataTables.nGambleTxtRecordCount, sizeof(D2GambleTxt));

    if (sgtDataTables.pGambleDataTables.nGambleTxtRecordCount)
    {
        sgtDataTables.pGambleDataTables.pGambleSelection = (int*)FOG_AllocPool(0, sizeof(unsigned int) * sgtDataTables.pGambleDataTables.nGambleTxtRecordCount, ".\\DATATBLS\\ItemTbls.cpp", 0x7DB, 0);
        for (int i = 0; i < sgtDataTables.pGambleDataTables.nGambleTxtRecordCount; ++i)
        {
            const unsigned int dwItemCode = pGambleTxt[i].dwItemCode;
            const int nItemId = FOG_GetLinkIndex(sgtDataTables.pItemsLinker, dwItemCode, 0);
            D2ItemsTxt* pItemsTxtRecord;
            D2_ASSERT(nItemId >= 0 && (pItemsTxtRecord = &sgtDataTables.pItemsTxt[nItemId]) != 0, 0x7E0);
            pGambleTxt[i].nLevel = pItemsTxtRecord->nLevel;
            pGambleTxt[i].nItemId = nItemId;
        }
        qsort(pGambleTxt, sgtDataTables.pGambleDataTables.nGambleTxtRecordCount, sizeof(D2GambleTxt), DATATBLS_CompareGambleTxtRecords);
    }
    else
    {
        sgtDataTables.pGambleDataTables.pGambleSelection = 0;
    }

    for (int i = 0; i < sgtDataTables.pGambleDataTables.nGambleTxtRecordCount; ++i)
    {
        sgtDataTables.pGambleDataTables.pGambleSelection[i] = pGambleTxt[i].nItemId;
    }

    sgtDataTables.pGambleDataTables.pGambleChooseLimit[0] = 2;

    for (int i = 1; i < 100; ++i)
    {
        sgtDataTables.pGambleDataTables.pGambleChooseLimit[i] = sgtDataTables.pGambleDataTables.nGambleTxtRecordCount;

        for (int nCounter = 0; nCounter < sgtDataTables.pGambleDataTables.nGambleTxtRecordCount; ++nCounter)
        {
            if (i < pGambleTxt[nCounter].nLevel)
            {
                sgtDataTables.pGambleDataTables.pGambleChooseLimit[i] = nCounter;
                break;
            }
        }
    }

    DATATBLS_UnloadBin(pGambleTxt);
}

// 0x00638C80
void __fastcall DATATBLS_UnloadGambleTxt()
{
    if (gGambleDataTables.pGambleSelection)
    {
        sub_0040B480(0, gGambleDataTables.pGambleSelection, ".\\DATATBLS\\ItemTbls.cpp", 2061, 0);
        gGambleDataTables.pGambleSelection = 0;
        gGambleDataTables.nGambleTxtRecordCount = 0;
    }
}

// 0x00638CC0
D2GambleDataTbl* __fastcall DATATBLS_GetGambleDataTables()
{
    return &gGambleDataTables;
}

// 0x006393E0
void __fastcall DATATBLS_UnloadItemTypesTxt()
{
    sub_0040B480(0, gpItemTypesEquivalenceLUTs, ".\\DATATBLS\\ItemTbls.cpp", 2215, 0);
    DATATBLS_UnloadBin(gp_0096C828);
    FOG_FreeLinker(gpItemTypesLinker);
}

// 0x00639420
static int __stdcall sub_00639420(HD2ARCHIVE hArchive, const char* szFileName, const char* szExtension)
{
    char szPath[260];
    HSFILE hFile;

    wsprintfA(szPath, "%s\\%s%s", "DATA\\GLOBAL\\EXCEL", szFileName, szExtension);
    if (!sub_00516E46_OpenFile(hArchive, szPath, &hFile, 1))
    {
        return 0;
    }

    sub_00516E84_CloseFile(hArchive, hFile);
    return 1;
}

// 0x006394A0
void __fastcall DATATBLS_LoadRunesTxt(HD2ARCHIVE hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", TXTFIELD_ASCII, 63, 0, NULL },
        { "rune name", TXTFIELD_ASCII, 63, 0x40, NULL },
        { "complete", TXTFIELD_BYTE, 0, 0x80, NULL },
        { "server", TXTFIELD_BYTE, 0, 0x81, NULL },
        { "itype1", TXTFIELD_CODETOWORD, 0, 0x86, &sgtDataTables.pItemTypesLinker },
        { "itype2", TXTFIELD_CODETOWORD, 0, 0x88, &sgtDataTables.pItemTypesLinker },
        { "itype3", TXTFIELD_CODETOWORD, 0, 0x8a, &sgtDataTables.pItemTypesLinker },
        { "itype4", TXTFIELD_CODETOWORD, 0, 0x8c, &sgtDataTables.pItemTypesLinker },
        { "itype5", TXTFIELD_CODETOWORD, 0, 0x8e, &sgtDataTables.pItemTypesLinker },
        { "itype6", TXTFIELD_CODETOWORD, 0, 0x90, &sgtDataTables.pItemTypesLinker },
        { "etype1", TXTFIELD_CODETOWORD, 0, 0x92, &sgtDataTables.pItemTypesLinker },
        { "etype2", TXTFIELD_CODETOWORD, 0, 0x94, &sgtDataTables.pItemTypesLinker },
        { "etype3", TXTFIELD_CODETOWORD, 0, 0x96, &sgtDataTables.pItemTypesLinker },
        { "rune1", TXTFIELD_UNKNOWN3, 0, 0x98, &sgtDataTables.pItemsLinker },
        { "rune2", TXTFIELD_UNKNOWN3, 0, 0x9c, &sgtDataTables.pItemsLinker },
        { "rune3", TXTFIELD_UNKNOWN3, 0, 0xa0, &sgtDataTables.pItemsLinker },
        { "rune4", TXTFIELD_UNKNOWN3, 0, 0xa4, &sgtDataTables.pItemsLinker },
        { "rune5", TXTFIELD_UNKNOWN3, 0, 0xa8, &sgtDataTables.pItemsLinker },
        { "rune6", TXTFIELD_UNKNOWN3, 0, 0xac, &sgtDataTables.pItemsLinker },
        { "t1code1", TXTFIELD_NAMETODWORD, 0, 0xb0, &sgtDataTables.pPropertiesLinker },
        { "t1param1", TXTFIELD_CALCTODWORD, 0, 0xb4, DATATBLS_ItemParamLinker },
        { "t1min1", TXTFIELD_DWORD, 0, 0xb8, NULL },
        { "t1max1", TXTFIELD_DWORD, 0, 0xbc, NULL },
        { "t1code2", TXTFIELD_NAMETODWORD, 0, 0xc0, &sgtDataTables.pPropertiesLinker },
        { "t1param2", TXTFIELD_CALCTODWORD, 0, 0xc4, DATATBLS_ItemParamLinker },
        { "t1min2", TXTFIELD_DWORD, 0, 0xc8, NULL },
        { "t1max2", TXTFIELD_DWORD, 0, 0xcc, NULL },
        { "t1code3", TXTFIELD_NAMETODWORD, 0, 0xd0, &sgtDataTables.pPropertiesLinker },
        { "t1param3", TXTFIELD_CALCTODWORD, 0, 0xd4, DATATBLS_ItemParamLinker },
        { "t1min3", TXTFIELD_DWORD, 0, 0xd8, NULL },
        { "t1max3", TXTFIELD_DWORD, 0, 0xdc, NULL },
        { "t1code4", TXTFIELD_NAMETODWORD, 0, 0xe0, &sgtDataTables.pPropertiesLinker },
        { "t1param4", TXTFIELD_CALCTODWORD, 0, 0xe4, DATATBLS_ItemParamLinker },
        { "t1min4", TXTFIELD_DWORD, 0, 0xe8, NULL },
        { "t1max4", TXTFIELD_DWORD, 0, 0xec, NULL },
        { "t1code5", TXTFIELD_NAMETODWORD, 0, 0xf0, &sgtDataTables.pPropertiesLinker },
        { "t1param5", TXTFIELD_CALCTODWORD, 0, 0xf4, DATATBLS_ItemParamLinker },
        { "t1min5", TXTFIELD_DWORD, 0, 0xf8, NULL },
        { "t1max5", TXTFIELD_DWORD, 0, 0xfc, NULL },
        { "t1code6", TXTFIELD_NAMETODWORD, 0, 0x100, &sgtDataTables.pPropertiesLinker },
        { "t1param6", TXTFIELD_CALCTODWORD, 0, 0x104, DATATBLS_ItemParamLinker },
        { "t1min6", TXTFIELD_DWORD, 0, 0x108, NULL },
        { "t1max6", TXTFIELD_DWORD, 0, 0x10c, NULL },
        { "t1code7", TXTFIELD_NAMETODWORD, 0, 0x110, &sgtDataTables.pPropertiesLinker },
        { "t1param7", TXTFIELD_CALCTODWORD, 0, 0x114, DATATBLS_ItemParamLinker },
        { "t1min7", TXTFIELD_DWORD, 0, 0x118, NULL },
        { "t1max7", TXTFIELD_DWORD, 0, 0x11c, NULL },
        { "end", TXTFIELD_NONE, 0, 0, NULL },
    };

    sgtDataTables.pRunesLinker = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 2303);

    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".txt"), 2308);
    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".bin"), 2312);
    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".xls"), 2316);

    sgtDataTables.pRuneDataTables.pRunesTxt = (D2RunesTxt*)DATATBLS_CompileTxt(hArchive, "runes", pTbl, &sgtDataTables.pRuneDataTables.nRunesTxtRecordCount, sizeof(D2RunesTxt));

    const Unicode* pUnicode = NULL;
    int i = 0;
    if (i < sgtDataTables.pRuneDataTables.nRunesTxtRecordCount)
    {
        hArchive = NULL;
        do
        {
            ((D2RunesTxt*)((char*)sgtDataTables.pRuneDataTables.pRunesTxt + (int)hArchive))->wStringId = sub_00524D30_FindString(((D2RunesTxt*)((char*)sgtDataTables.pRuneDataTables.pRunesTxt + (int)hArchive))->szName, &pUnicode);
            hArchive = (char*)hArchive + sizeof(D2RunesTxt);
            ++i;
        }
        while (i < sgtDataTables.pRuneDataTables.nRunesTxtRecordCount);
    }
}

// 0x00639C90
void __fastcall DATATBLS_UnloadRunesTxt()
{
    DATATBLS_UnloadBin(sgtRuneWordsTblDesc.pRunesTxt);
    FOG_FreeLinker(gpRunesLinker);
}

// 0x00639CB0
D2RuneDataTbl* __fastcall DATATBLS_GetRuneDataTables()
{
    return &sgtRuneWordsTblDesc;
}

#include "gen/data/Source/D2Common/DATATBLS/ItemTbls.inc"
