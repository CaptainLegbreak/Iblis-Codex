#include "D2Common.h"
#include "D2DataTbls.h"
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

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    unsigned char unk_84[0x6C];
    int dwGemOffset;
    unsigned char unk_F4[0x2];
    unsigned short wVersion;
    unsigned char unk_F8[0x5];
    unsigned char nLevel;
    char unk0x0FE[0xAA];
};

extern D2TxtLinkStrc* gpItemTypesLinker_0096C824; // 0x0096C824
extern D2TxtLinkStrc* gpSoundsLinker_0096BDC8; // 0x0096BDC8
extern D2TxtLinkStrc* gpStatesLinker_0096BCF0; // 0x0096BCF0
extern D2TxtLinkStrc* gpItemStatCostLinker_0096C800; // 0x0096C800
extern int gbCompileTxt; // 0x0096C8B4
void __fastcall DATATBLS_GetStringIdFromReferenceString(); // 0x006117B0
void __fastcall DATATBLS_ItemCalcLinker(); // 0x00631530
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx); // 0x00613E90
void __stdcall sub_006BD230_AddLinkCode(D2TxtLinkStrc* pLinker, unsigned int dwCode); // 0x006BD230

struct D2MagicAffixTxt { char unk[0x90]; };

struct D2RareAffixTxt { char unk[0x48]; };

struct D2QualityItemsTxt
{
    char unk0x00[0x2C];
    char szEffect1[32];
    char szEffect2[32];
    unsigned short wEffect1TblId;
    unsigned short wEffect2TblId;
};

struct D2GemsTxt
{
    char unk0x00[0x28];
    union
    {
        unsigned char szItemCode[4];
        int dwItemCode;
    };
    unsigned short wStringId;
    char unk0x2E[0x92];
};

struct D2BooksTxt { char unk[0x20]; };

struct D2LowQualityItemsTxt
{
    char szName[32];
    unsigned short wTblId;
};

struct D2ItemStatCostDescStrc
{
    char unk0x00[0x2];
    short nDescPriority;
    char unk[0x8 - 0x2 - 2];
};

struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };


struct D2RareAffixDataTbl { int nRareAffixTxtRecordCount; D2RareAffixTxt* pRareAffixTxt; };

struct D2QualityItemDataTbl { int nQualityItemsTxtRecordCount; D2QualityItemsTxt* pQualityItemsTxt; };

struct D2GemDataTbl { int nGemsTxtRecordCount; D2GemsTxt* pGemsTxt; };

struct D2BookDataTbl { int nBooksTxtRecordCount; D2BooksTxt* pBooksTxt; };

struct D2LowQualityItemDataTbl { int nLowQualityItemsTxtRecordCount; D2LowQualityItemsTxt* pLowQualityItemsTxt; };

struct D2ItemRatioDataTbl { int nItemRatioTxtRecordCount; D2ItemRatioTxt* pItemRatioTxt; };



extern D2TxtLinkStrc* gpItemsLinker_0096BCC4; // 0x0096BCC4
extern D2TxtLinkStrc* gTxtLink_0096BCD8; // 0x0096BCD8
extern void* gpItemStatCostTxt; // 0x0096C7FC
extern int gnItemStatCostTxtRecordCount; // 0x0096C804
extern void* gpStatsWithDescFunc; // 0x0096C808
extern int gnStatsWithDescFunc; // 0x0096C80C
extern void* gp_0096C828; // 0x0096C828
extern int gnUniqueitemsTxtRecordCount; // 0x0096C858
extern D2ItemDataTbl gItemDataTables; // 0x0096CA58
extern unsigned short* gpIndexOldToCurrent_0096CA78; // 0x0096CA78
extern D2GemDataTbl gGemDataTables; // 0x0096CA90
extern D2RuneDataTbl gRuneDataTables; // 0x0096CA98
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

struct D2UniqueItemsTxt
{
    unsigned short wId;
    char szName[32];
    unsigned short wTblIndex;
    char unk0x24[296];
};

extern "C" const char gszTxtField_index[]; // 0x006E9CCC
extern D2TxtLinkStrc* gTxtLink_0096C5E4; // 0x0096C5E4
void __fastcall sub_006336A0(); // 0x006336A0
void __stdcall FOG_10216_AddRecordToLinkingTable(D2TxtLinkStrc* pLinker, const char* szName); // 0x006BD500
unsigned short __stdcall D2LANG_GetTblIndex(const char* szReference, void** ppUnicode); // 0x00524D30
extern D2ItemsTxt* gpItemsTxt_0096CA5C; // 0x0096CA5C

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
extern void* gpPropertiesTxt; // 0x0096BCD4

struct D2GambleTxt
{
    unsigned int dwItemCode;
    int nLevel;
    int nItemId;
};

extern "C" const char gszGambleTxtName[]; // 0x006EA750
extern "C" const char gszItemsTblsSourceFile[]; // 0x006E90E4
extern D2GambleDataTbl gGambleDataTables; // 0x0096CAB0

typedef void* HD2ARCHIVE;

typedef void* HSFILE;

enum D2C_TxtFieldTypes
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_BYTE = 4,
    TXTFIELD_UNKNOWN3 = 11,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETODWORD = 19,
    TXTFIELD_CALCTODWORD = 25,
};

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2RunesTxt
{
    char szName[64];
    char szRuneName[64];
    unsigned char nComplete;
    unsigned char nServer;
    unsigned short wStringId;
    unsigned short pad0x84;
    unsigned short wIType[6];
    unsigned short wEType[3];
    int nRune[6];
    D2PropertyStrc pProperties[7];
};

extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
int __fastcall ARCHIVE_OpenFile(HD2ARCHIVE hArchive, const char* szFilePath, HSFILE* phFile, int bQuiet); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(HD2ARCHIVE hArchive, HSFILE hFile); // 0x00516E84
short __stdcall sub_00524D30_FindString(const char* szReference, const Unicode** ppUnicode); // 0x00524D30
void __fastcall DATATBLS_ItemParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn); // 0x006336A0


extern D2DataTablesStrc gD2DataTables; // 0x0096BC30

D2TxtLinkStrc* gpItemsLinker_0096BCC4; // 0x0096BCC4

D2TxtLinkStrc* gpHitClassLinker_0096BC54; // 0x0096BC54

void* gpItemsCode_0096BCC8; // 0x0096BCC8

int gnItemsCodeSize_0096BCCC; // 0x0096BCCC

int gnItemsCodeSizeEx_0096BCD0; // 0x0096BCD0

int gnItemsTxtRecordCount_0096CA58; // 0x0096CA58

D2ItemsTxt* gpItemsTxt_0096CA5C; // 0x0096CA5C

D2ItemsTxt* gpWeaponsTxt_0096CA60; // 0x0096CA60

int gnWeaponsTxtRecordCount_0096CA64; // 0x0096CA64

D2ItemsTxt* gpArmorTxt_0096CA68; // 0x0096CA68

int gnArmorTxtRecordCount_0096CA6C; // 0x0096CA6C

D2ItemsTxt* gpMiscTxt_0096CA70; // 0x0096CA70

int gnMiscTxtRecordCount_0096CA74; // 0x0096CA74

unsigned short* gpIndexOldToCurrent_0096CA78; // 0x0096CA78

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

void* gpPropertiesTxt; // 0x0096BCD4

D2TxtLinkStrc* gpRunesLinker; // 0x0096BCE0

void* gpItemTypesEquivalenceLUTs; // 0x0096C834

D2TxtLinkStrc* gpSetsLinker; // 0x0096C838

void* gpSetsTxt; // 0x0096C83C

int gnSetsTxtRecordCount; // 0x0096C840

int gnSetItemsTxtRecordCount; // 0x0096C84C

D2MagicAffixDataTbl gMagicAffixDataTables; // 0x0096CA7C

D2RareAffixDataTbl gRareAffixDataTables; // 0x0096CAA0

D2GambleDataTbl gGambleDataTables; // 0x0096CAB0

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
    if (gMagicAffixDataTables.pMagicAffixTxt)
    {
        sub_0040B480(0, gMagicAffixDataTables.pMagicAffixTxt, ".\\DATATBLS\\ItemTbls.cpp", 695, 0);
    }
    gMagicAffixDataTables.pMagicAffixTxt = 0;
}

// 0x00633ED0
D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables()
{
    return &gMagicAffixDataTables;
}

// 0x00633EE0
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex)
{
    ITEM_ASSERT(gMagicAffixDataTables.pMagicAffixTxt, 712);
    if (nIndex > gMagicAffixDataTables.nMagicAffixTxtRecordCount || nIndex <= 0)
    {
        return 0;
    }
    else
    {
        return &gMagicAffixDataTables.pMagicAffixTxt[nIndex - 1];
    }
}

// 0x00634220
void __fastcall DATATBLS_UnloadRareSuffix_PrefixTxt()
{
    if (gRareAffixDataTables.pRareAffixTxt)
    {
        sub_0040B480(0, gRareAffixDataTables.pRareAffixTxt, ".\\DATATBLS\\ItemTbls.cpp", 779, 0);
    }
    gRareAffixDataTables.pRareAffixTxt = 0;
}

// 0x00634250
D2RareAffixDataTbl* __fastcall DATATBLS_GetRareAffixDataTables()
{
    return &gRareAffixDataTables;
}

// 0x00634260
D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId)
{
    if (nId > gRareAffixDataTables.nRareAffixTxtRecordCount || nId <= 0)
    {
        return 0;
    }
    else
    {
        ITEM_ASSERT(gRareAffixDataTables.pRareAffixTxt, 799);
        return &gRareAffixDataTables.pRareAffixTxt[nId - 1];
    }
}

D2UniqueItemsTxt* gpUniqueitemsTxt; // 0x0096C854

int gnUniqueitemsTxtRecordCount; // 0x0096C858

D2TxtLinkStrc* gpUniqueitemsLinker; // 0x0096C850

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
        { "par1", 25, 0, 144, (void*)sub_006336A0 },
        { "min1", 2, 0, 148, 0 },
        { "max1", 2, 0, 152, 0 },
        { "prop2", 19, 0, 156, &gTxtLink_0096BCD8 },
        { "par2", 25, 0, 160, (void*)sub_006336A0 },
        { "min2", 2, 0, 164, 0 },
        { "max2", 2, 0, 168, 0 },
        { "prop3", 19, 0, 172, &gTxtLink_0096BCD8 },
        { "par3", 25, 0, 176, (void*)sub_006336A0 },
        { "min3", 2, 0, 180, 0 },
        { "max3", 2, 0, 184, 0 },
        { "prop4", 19, 0, 188, &gTxtLink_0096BCD8 },
        { "par4", 25, 0, 192, (void*)sub_006336A0 },
        { "min4", 2, 0, 196, 0 },
        { "max4", 2, 0, 200, 0 },
        { "prop5", 19, 0, 204, &gTxtLink_0096BCD8 },
        { "par5", 25, 0, 208, (void*)sub_006336A0 },
        { "min5", 2, 0, 212, 0 },
        { "max5", 2, 0, 216, 0 },
        { "prop6", 19, 0, 220, &gTxtLink_0096BCD8 },
        { "par6", 25, 0, 224, (void*)sub_006336A0 },
        { "min6", 2, 0, 228, 0 },
        { "max6", 2, 0, 232, 0 },
        { "prop7", 19, 0, 236, &gTxtLink_0096BCD8 },
        { "par7", 25, 0, 240, (void*)sub_006336A0 },
        { "min7", 2, 0, 244, 0 },
        { "max7", 2, 0, 248, 0 },
        { "prop8", 19, 0, 252, &gTxtLink_0096BCD8 },
        { "par8", 25, 0, 256, (void*)sub_006336A0 },
        { "min8", 2, 0, 260, 0 },
        { "max8", 2, 0, 264, 0 },
        { "prop9", 19, 0, 268, &gTxtLink_0096BCD8 },
        { "par9", 25, 0, 272, (void*)sub_006336A0 },
        { "min9", 2, 0, 276, 0 },
        { "max9", 2, 0, 280, 0 },
        { "prop10", 19, 0, 284, &gTxtLink_0096BCD8 },
        { "par10", 25, 0, 288, (void*)sub_006336A0 },
        { "min10", 2, 0, 292, 0 },
        { "max10", 2, 0, 296, 0 },
        { "prop11", 19, 0, 300, &gTxtLink_0096BCD8 },
        { "par11", 25, 0, 304, (void*)sub_006336A0 },
        { "min11", 2, 0, 308, 0 },
        { "max11", 2, 0, 312, 0 },
        { "prop12", 19, 0, 316, &gTxtLink_0096BCD8 },
        { "par12", 25, 0, 320, (void*)sub_006336A0 },
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

D2QualityItemsTxt* gpQualityitemsTxt; // 0x0096CC54

int gnQualityitemsTxtRecordCount; // 0x0096CC50

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

D2GemsTxt* gpGemsTxt; // 0x0096CA94

int gnGemsTxtRecordCount; // 0x0096CA90

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
        { "weaponmod1param", 25, 0, 52, (void*)sub_006336A0 },
        { "weaponmod1min", 2, 0, 56, 0 },
        { "weaponmod1max", 2, 0, 60, 0 },
        { "weaponmod2code", 19, 0, 64, &gTxtLink_0096BCD8 },
        { "weaponmod2param", 25, 0, 68, (void*)sub_006336A0 },
        { "weaponmod2min", 2, 0, 72, 0 },
        { "weaponmod2max", 2, 0, 76, 0 },
        { "weaponmod3code", 19, 0, 80, &gTxtLink_0096BCD8 },
        { "weaponmod3param", 25, 0, 84, (void*)sub_006336A0 },
        { "weaponmod3min", 2, 0, 88, 0 },
        { "weaponmod3max", 2, 0, 92, 0 },
        { "helmmod1code", 19, 0, 96, &gTxtLink_0096BCD8 },
        { "helmmod1param", 25, 0, 100, (void*)sub_006336A0 },
        { "helmmod1min", 2, 0, 104, 0 },
        { "helmmod1max", 2, 0, 108, 0 },
        { "helmmod2code", 19, 0, 112, &gTxtLink_0096BCD8 },
        { "helmmod2param", 25, 0, 116, (void*)sub_006336A0 },
        { "helmmod2min", 2, 0, 120, 0 },
        { "helmmod2max", 2, 0, 124, 0 },
        { "helmmod3code", 19, 0, 128, &gTxtLink_0096BCD8 },
        { "helmmod3param", 25, 0, 132, (void*)sub_006336A0 },
        { "helmmod3min", 2, 0, 136, 0 },
        { "helmmod3max", 2, 0, 140, 0 },
        { "shieldmod1code", 19, 0, 144, &gTxtLink_0096BCD8 },
        { "shieldmod1param", 25, 0, 148, (void*)sub_006336A0 },
        { "shieldmod1min", 2, 0, 152, 0 },
        { "shieldmod1max", 2, 0, 156, 0 },
        { "shieldmod2code", 19, 0, 160, &gTxtLink_0096BCD8 },
        { "shieldmod2param", 25, 0, 164, (void*)sub_006336A0 },
        { "shieldmod2min", 2, 0, 168, 0 },
        { "shieldmod2max", 2, 0, 172, 0 },
        { "shieldmod3code", 19, 0, 176, &gTxtLink_0096BCD8 },
        { "shieldmod3param", 25, 0, 180, (void*)sub_006336A0 },
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

void* gpBooksTxt; // 0x0096CC64

int gnBooksTxtRecordCount; // 0x0096CC60

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

D2LowQualityItemsTxt* gpLowqualityitemsTxt; // 0x0096CC5C

int gnLowqualityitemsTxtRecordCount; // 0x0096CC58

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

void* gpItemratioTxt; // 0x0096CC4C

int gnItemratioTxtRecordCount; // 0x0096CC48

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

D2TxtLinkStrc* gTxtLink_0096BCD8; // 0x0096BCD8

int gnPropertiesTxtRecordCount; // 0x0096BCDC

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
    if (!ARCHIVE_OpenFile(hArchive, szPath, &hFile, 1))
    {
        return 0;
    }

    ARCHIVE_CloseFile(hArchive, hFile);
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
        { "itype1", TXTFIELD_CODETOWORD, 0, 0x86, &gD2DataTables.pItemTypesLinker },
        { "itype2", TXTFIELD_CODETOWORD, 0, 0x88, &gD2DataTables.pItemTypesLinker },
        { "itype3", TXTFIELD_CODETOWORD, 0, 0x8a, &gD2DataTables.pItemTypesLinker },
        { "itype4", TXTFIELD_CODETOWORD, 0, 0x8c, &gD2DataTables.pItemTypesLinker },
        { "itype5", TXTFIELD_CODETOWORD, 0, 0x8e, &gD2DataTables.pItemTypesLinker },
        { "itype6", TXTFIELD_CODETOWORD, 0, 0x90, &gD2DataTables.pItemTypesLinker },
        { "etype1", TXTFIELD_CODETOWORD, 0, 0x92, &gD2DataTables.pItemTypesLinker },
        { "etype2", TXTFIELD_CODETOWORD, 0, 0x94, &gD2DataTables.pItemTypesLinker },
        { "etype3", TXTFIELD_CODETOWORD, 0, 0x96, &gD2DataTables.pItemTypesLinker },
        { "rune1", TXTFIELD_UNKNOWN3, 0, 0x98, &gD2DataTables.pItemsLinker },
        { "rune2", TXTFIELD_UNKNOWN3, 0, 0x9c, &gD2DataTables.pItemsLinker },
        { "rune3", TXTFIELD_UNKNOWN3, 0, 0xa0, &gD2DataTables.pItemsLinker },
        { "rune4", TXTFIELD_UNKNOWN3, 0, 0xa4, &gD2DataTables.pItemsLinker },
        { "rune5", TXTFIELD_UNKNOWN3, 0, 0xa8, &gD2DataTables.pItemsLinker },
        { "rune6", TXTFIELD_UNKNOWN3, 0, 0xac, &gD2DataTables.pItemsLinker },
        { "t1code1", TXTFIELD_NAMETODWORD, 0, 0xb0, &gD2DataTables.pPropertiesLinker },
        { "t1param1", TXTFIELD_CALCTODWORD, 0, 0xb4, DATATBLS_ItemParamLinker },
        { "t1min1", TXTFIELD_DWORD, 0, 0xb8, NULL },
        { "t1max1", TXTFIELD_DWORD, 0, 0xbc, NULL },
        { "t1code2", TXTFIELD_NAMETODWORD, 0, 0xc0, &gD2DataTables.pPropertiesLinker },
        { "t1param2", TXTFIELD_CALCTODWORD, 0, 0xc4, DATATBLS_ItemParamLinker },
        { "t1min2", TXTFIELD_DWORD, 0, 0xc8, NULL },
        { "t1max2", TXTFIELD_DWORD, 0, 0xcc, NULL },
        { "t1code3", TXTFIELD_NAMETODWORD, 0, 0xd0, &gD2DataTables.pPropertiesLinker },
        { "t1param3", TXTFIELD_CALCTODWORD, 0, 0xd4, DATATBLS_ItemParamLinker },
        { "t1min3", TXTFIELD_DWORD, 0, 0xd8, NULL },
        { "t1max3", TXTFIELD_DWORD, 0, 0xdc, NULL },
        { "t1code4", TXTFIELD_NAMETODWORD, 0, 0xe0, &gD2DataTables.pPropertiesLinker },
        { "t1param4", TXTFIELD_CALCTODWORD, 0, 0xe4, DATATBLS_ItemParamLinker },
        { "t1min4", TXTFIELD_DWORD, 0, 0xe8, NULL },
        { "t1max4", TXTFIELD_DWORD, 0, 0xec, NULL },
        { "t1code5", TXTFIELD_NAMETODWORD, 0, 0xf0, &gD2DataTables.pPropertiesLinker },
        { "t1param5", TXTFIELD_CALCTODWORD, 0, 0xf4, DATATBLS_ItemParamLinker },
        { "t1min5", TXTFIELD_DWORD, 0, 0xf8, NULL },
        { "t1max5", TXTFIELD_DWORD, 0, 0xfc, NULL },
        { "t1code6", TXTFIELD_NAMETODWORD, 0, 0x100, &gD2DataTables.pPropertiesLinker },
        { "t1param6", TXTFIELD_CALCTODWORD, 0, 0x104, DATATBLS_ItemParamLinker },
        { "t1min6", TXTFIELD_DWORD, 0, 0x108, NULL },
        { "t1max6", TXTFIELD_DWORD, 0, 0x10c, NULL },
        { "t1code7", TXTFIELD_NAMETODWORD, 0, 0x110, &gD2DataTables.pPropertiesLinker },
        { "t1param7", TXTFIELD_CALCTODWORD, 0, 0x114, DATATBLS_ItemParamLinker },
        { "t1min7", TXTFIELD_DWORD, 0, 0x118, NULL },
        { "t1max7", TXTFIELD_DWORD, 0, 0x11c, NULL },
        { "end", TXTFIELD_NONE, 0, 0, NULL },
    };

    gD2DataTables.pRunesLinker = sub_006BD040_AllocBlock(".\\DATATBLS\\ItemTbls.cpp", 2303);

    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".txt"), 2308);
    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".bin"), 2312);
    D2_ASSERT(!sub_00639420(hArchive, "runessrv", ".xls"), 2316);

    gD2DataTables.pRuneDataTables.pRunesTxt = (D2RunesTxt*)DATATBLS_CompileTxt(hArchive, "runes", pTbl, &gD2DataTables.pRuneDataTables.nRunesTxtRecordCount, sizeof(D2RunesTxt));

    const Unicode* pUnicode = NULL;
    int i = 0;
    if (i < gD2DataTables.pRuneDataTables.nRunesTxtRecordCount)
    {
        hArchive = NULL;
        do
        {
            ((D2RunesTxt*)((char*)gD2DataTables.pRuneDataTables.pRunesTxt + (int)hArchive))->wStringId = sub_00524D30_FindString(((D2RunesTxt*)((char*)gD2DataTables.pRuneDataTables.pRunesTxt + (int)hArchive))->szName, &pUnicode);
            hArchive = (char*)hArchive + sizeof(D2RunesTxt);
            ++i;
        }
        while (i < gD2DataTables.pRuneDataTables.nRunesTxtRecordCount);
    }
}

// 0x00639C90
void __fastcall DATATBLS_UnloadRunesTxt()
{
    DATATBLS_UnloadBin(gRuneDataTables.pRunesTxt);
    FOG_FreeLinker(gpRunesLinker);
}

// 0x00639CB0
D2RuneDataTbl* __fastcall DATATBLS_GetRuneDataTables()
{
    return &gRuneDataTables;
}
