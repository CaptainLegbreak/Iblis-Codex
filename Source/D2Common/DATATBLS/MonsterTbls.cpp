#include "D2Common.h"

#pragma function(memset)
#define MONSTATSFLAGINDEX_NORATIO 2
#define ITEMTYPES_RECORD(i) (((i) >= 0 && (i) < sgptDataTables->nItemTypesTxtRecordCount) ? &sgptDataTables->pItemTypesTxt[(i)] : 0)

struct D2ObjectsTxt;
struct D2ShrinesTxt;
struct D2SuperUniquesTxt;
struct D2MonStats2Txt;
struct D2BinFieldStrc;
struct D2MonStatsTxt;
struct D2MonLvlTxt;
struct D2MonStatsInitStrc;
struct D2SeedStrc;
struct Unicode;
struct D2UniqueNameTxt;
struct D2TCExInfoStrc;
struct D2TCExShortStrc;
struct TableRow;
struct D2ItemsTxt;
struct D2ItemDataTbl;
struct D2TreasureClassExTxt;
struct D2UniqueItemsTxt;
struct D2SetItemsTxt;
struct D2HirelingTxt;
struct D2MonPresetTxt;
struct D2TxtLinkStrc;
struct D2DataTablesStrc;
struct D2UnitStrc;
struct D2AnimSeqTxt;
struct D2AnimSeqRecordStrc;

void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
void __fastcall sub_006562B0(); // 0x006562B0
void __fastcall sub_00659AF0(); // 0x00659AF0
void __fastcall sub_00659DE0(); // 0x00659DE0
void __fastcall sub_00654D50(); // 0x00654D50
void __cdecl sub_00653E20(); // 0x00653E20
extern int gnObjgroupTxtRecordCount; // 0x0096D47C
extern void* gpNpcTxt; // 0x0096C5D8

struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique;
    unsigned short wNameStr;
    unsigned int dwClass;
    int dwHcIdx;
    char unk0x0C[0x34 - 0x0C];
};

extern D2SuperUniquesTxt* gpSuperUniquesTxt; // 0x0096C704
extern int gnSuperUniquesTxtRecordCount; // 0x0096C70C
extern int gnMonumodTxtRecordCount; // 0x0096C884
extern void* gpMonstatsTxt; // 0x0096C6A8
extern D2TxtLinkStrc* gTxtLink_0096C6AC; // 0x0096C6AC
extern D2TxtLinkStrc* gTxtLink_0096C85C; // 0x0096C85C
extern void* gpMonsoundsTxt; // 0x0096C6B4
extern D2TxtLinkStrc* gTxtLink_0096C6B8; // 0x0096C6B8
extern int gnMonsoundsTxtRecordCount; // 0x0096C6BC

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

void __fastcall sub_006117B0(); // 0x006117B0
extern D2TxtLinkStrc* gTxtLink_0096C6C4; // 0x0096C6C4
extern D2TxtLinkStrc* gTxtLink_0096C868; // 0x0096C868
extern D2TxtLinkStrc* gTxtLink_0096BCBC; // 0x0096BCBC
extern D2TxtLinkStrc* gTxtLink_0096C798; // 0x0096C798
extern D2TxtLinkStrc* gTxtLink_0096BC4C; // 0x0096BC4C
void __fastcall sub_00651150(); // 0x00651150
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall sub_00651040(); // 0x00651040
void __stdcall sub_00650F00(int nRecordCount); // 0x00650F00

struct D2MonStatsTxt
{
    char unk0x000[0x00C];
    unsigned char nMonStatsFlags[4];
    char unk0x010[0x0A0];
    short nMinHP[3];
    short nMaxHP[3];
    short nAC[3];
    short nA1TH[3];
    short nA2TH[3];
    short nS1TH[3];
    short nExp[3];
    short nA1MinD[3];
    short nA1MaxD[3];
    short nA2MinD[3];
    short nA2MaxD[3];
    short nS1MinD[3];
    short nS1MaxD[3];
    char unk0x0FE[0x010];
    short nElMinD[3][3];
    short nElMaxD[3][3];
    short nElDur[3][3];
    char unk0x144[0x064];
};

struct D2MonLvlTxt
{
    unsigned int dwAC[2][3];
    unsigned int dwTH[2][3];
    unsigned int dwHP[2][3];
    unsigned int dwDM[2][3];
    unsigned int dwXP[2][3];
};

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};

struct D2DataTablesStrc
{
    char unk0x000[0x02C];
    D2TxtLinkStrc* pMonModeLinker;
    unsigned char unk_30[0x988];
    D2TxtLinkStrc* pTreasureClassExLinker;
    unsigned char unk_9BC[0xBC];
    D2MonStatsTxt* pMonStatsTxt;
    D2TxtLinkStrc* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    unsigned char unk_A84[0x4];
    D2TxtLinkStrc* pMonSoundsLinker;
    unsigned char unk_A8C[0x4];
    D2MonStats2Txt* pMonStats2Txt;
    D2TxtLinkStrc* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
    unsigned char unk_A9C[0x38];
    D2SuperUniquesTxt* pSuperUniquesTxt;
    D2TxtLinkStrc* pSuperUniquesLinker;
    int nSuperUniquesTxtRecordCount;
    unsigned short nSuperUniqueIds[66];
    unsigned char unk_B64[0xC];
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
    unsigned char unk_B78[0x24];
    D2TxtLinkStrc* pSkillsLinker;
    unsigned char unk_BA0[0x58];
    TableRow* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x1C];
    D2SeedStrc pSeed;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2UniqueNameTxt
{
    unsigned short wStringId;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern D2UniqueNameTxt* gpUniqueNameTxtTables_0096D488[4]; // 0x0096D488
extern int gnUniqueNameTxtRecordCounts_0096D498[4]; // 0x0096D498
extern Unicode gwszDataTablesDefault; // 0x0096D4B4

struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    short nItemId;
    short nTxtRow;
    unsigned char nFlags;
    char unk0x0D;
    short nMagic;
    short nRare;
    short nSet;
    short nUnique;
    short nSuperior;
    short nNormal;
    char unk0x1A[2];
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    int nNoDrop;
    char unk0x18[2];
    short nQuality[6];
    char unk0x26[2];
    D2TCExInfoStrc* pInfo;
};

struct TableRow
{
    char unk0x00[0x1D];
    unsigned char nTreasureClass;
    unsigned char nRarity;
    char unk0x1F[0xE4 - 0x1F];
};

struct D2ItemsTxt
{
    char unk0x00[0xF6];
    unsigned short wVersion;
    char unk0xF8[0xFD - 0xF8];
    unsigned char nLevel;
    char unk0xFE[0x11E - 0xFE];
    short wType[2];
    char unk0x122[0x12A - 0x122];
    unsigned char nQuest;
    char unk0x12B[0x133 - 0x12B];
    unsigned char nSpawnable;
    char unk0x134[0x1A8 - 0x134];
};

struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };

typedef char check_TableRow_size[sizeof(TableRow) == 0xE4 ? 1 : -1];

typedef char check_D2ItemsTxt_size[sizeof(D2ItemsTxt) == 0x1A8 ? 1 : -1];

typedef char check_D2TCExInfoStrc_size[sizeof(D2TCExInfoStrc) == 0x1C ? 1 : -1];

typedef char check_D2TCExShortStrc_size[sizeof(D2TCExShortStrc) == 0x2C ? 1 : -1];

extern unsigned short gwTreasureClassItemTypes; // 0x0096D4B0
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* pLinker, int nIndex, char* szString); // 0x006BD180
extern "C" TableRow* __fastcall sub_00555C90_GetTableRow(int index); // 0x00555C90
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType); // 0x00629A90
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2TCExShortStrc* __fastcall DATATBLS_NewTreasureClassEx(const char* szTreasureClass); // 0x00653F90
D2TCExInfoStrc* __fastcall sub_00654080(D2TCExShortStrc* pTCExShort); // 0x00654080
void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion); // 0x006540C0
extern "C" char* __cdecl strchr(const char* szString, int nChar); // 0x00687740

struct D2TreasureClassExTxt
{
    char szTreasureClass[32];
    int nPicks;
    unsigned short nGroup;
    short nLevel;
    unsigned short nQuality[6];
    int nNoDrop;
    char szItem[10][64];
    int nProb[10];
};

struct D2UniqueItemsTxt { char unk0x00[0x28]; unsigned int dwBaseItemCode; char unk0x2C[0x14C - 0x2C]; };

struct D2SetItemsTxt { char unk0x00[0x28]; unsigned int dwItemCode; char unk0x2C[0x1B8 - 0x2C]; };

typedef char check_D2TreasureClassExTxt_size[sizeof(D2TreasureClassExTxt) == 0x2E0 ? 1 : -1];

typedef char check_D2UniqueItemsTxt_size[sizeof(D2UniqueItemsTxt) == 0x14C ? 1 : -1];

typedef char check_D2SetItemsTxt_size[sizeof(D2SetItemsTxt) == 0x1B8 ? 1 : -1];

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" unsigned int __cdecl strlen(const char* sz);
extern D2TCExShortStrc* gpTreasureClassEx; // 0x0096C5EC
extern "C" const char gszTxtField_magic_006DCFBC[]; // 0x006DCFBC
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, const char* szKey, int bLogError);
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
static __declspec(noinline) int __stdcall DATATBLS_ParseTreasureClassItem(D2TCExShortStrc* pTCExTxtRecord, int nProb, char* szText); // 0x00654440
extern D2TxtLinkStrc* gTxtLink_0096C87C; // 0x0096C87C
extern void* gpMonumodTxt; // 0x0096C880
extern D2DataTablesStrc gtDataTables_0096BC30; // 0x0096BC30

struct D2HirelingTxt
{
    unsigned short wVersion;
    unsigned short pad0x02;
    int nId;
    int dwClass;
    int dwAct;
    int dwDifficulty;
    char unk0x14[0x1C - 0x14];
    int nHirelingLevel;
    char unk0x20[0x118 - 0x20];
};

extern D2HirelingTxt* gpHirelingTxt; // 0x0096BDD0
extern D2TxtLinkStrc* gTxtLink_0096BC5C; // 0x0096BC5C

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_ASCIITOCODE = 9,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_NAMETOINDEX = 17,
    TXTFIELD_NAMETOWORD = 20,
    TXTFIELD_CUSTOMLINK = 23,
    TXTFIELD_BIT = 26,
};

extern "C" const char gszTxtField_Id[]; // 0x006E6850
extern "C" const char gszTxtField_Height[]; // 0x006EAA88
extern "C" const char gszTxtField_overlayHeight[]; // 0x006ED120
extern "C" const char gszTxtField_pixHeight[]; // 0x006ED114
extern "C" const char gszTxtField_SizeX[]; // 0x006E8654
extern "C" const char gszTxtField_SizeY[]; // 0x006E864C
extern "C" const char gszTxtField_spawnCol[]; // 0x006ED108
extern "C" const char gszTxtField_MeleeRng[]; // 0x006ED0FC
extern "C" const char gszTxtField_BaseW[]; // 0x006ED0F4
extern "C" const char gszTxtField_HitClass[]; // 0x006E6D10
extern "C" const char gszTxtField_HDv[]; // 0x006ED0F0
extern "C" const char gszTxtField_TRv[]; // 0x006ED0EC
extern "C" const char gszTxtField_LGv[]; // 0x006ED0E8
extern "C" const char gszTxtField_Rav[]; // 0x006ED0E4
extern "C" const char gszTxtField_Lav[]; // 0x006ED0E0
extern "C" const char gszTxtField_RHv[]; // 0x006ED0DC
extern "C" const char gszTxtField_LHv[]; // 0x006ED0D8
extern "C" const char gszTxtField_SHv[]; // 0x006ED0D4
extern "C" const char gszTxtField_S1v[]; // 0x006ED0D0
extern "C" const char gszTxtField_S2v[]; // 0x006ED0CC
extern "C" const char gszTxtField_S3v[]; // 0x006ED0C8
extern "C" const char gszTxtField_S4v[]; // 0x006ED0C4
extern "C" const char gszTxtField_S5v[]; // 0x006ED0C0
extern "C" const char gszTxtField_S6v[]; // 0x006ED0BC
extern "C" const char gszTxtField_S7v[]; // 0x006ED0B8
extern "C" const char gszTxtField_S8v[]; // 0x006ED0B4
extern "C" const char gszTxtField_HD[]; // 0x006EABFC
extern "C" const char gszTxtField_TR[]; // 0x006EABF8
extern "C" const char gszTxtField_LG[]; // 0x006EABF4
extern "C" const char gszTxtField_RA[]; // 0x006EABF0
extern "C" const char gszTxtField_LA[]; // 0x006EABEC
extern "C" const char gszTxtField_RH[]; // 0x006EABE8
extern "C" const char gszTxtField_LH[]; // 0x006EABE4
extern "C" const char gszTxtField_SH[]; // 0x006EABE0
extern "C" const char gszTxtField_S1[]; // 0x006EABDC
extern "C" const char gszTxtField_S2[]; // 0x006EABD8
extern "C" const char gszTxtField_S3[]; // 0x006EABD4
extern "C" const char gszTxtField_S4[]; // 0x006EABD0
extern "C" const char gszTxtField_S5[]; // 0x006EABCC
extern "C" const char gszTxtField_S6[]; // 0x006EABC8
extern "C" const char gszTxtField_S7[]; // 0x006EABC4
extern "C" const char gszTxtField_S8[]; // 0x006EABC0
extern "C" const char gszTxtField_TotalPieces[]; // 0x006EABB4
extern "C" const char gszTxtField_mDT[]; // 0x006ED0B0
extern "C" const char gszTxtField_mNU[]; // 0x006ED0AC
extern "C" const char gszTxtField_mWL[]; // 0x006ED0A8
extern "C" const char gszTxtField_mGH[]; // 0x006ED0A4
extern "C" const char gszTxtField_mA1[]; // 0x006ED0A0
extern "C" const char gszTxtField_mA2[]; // 0x006ED09C
extern "C" const char gszTxtField_mBL[]; // 0x006ED098
extern "C" const char gszTxtField_mSC[]; // 0x006ED094
extern "C" const char gszTxtField_mS1[]; // 0x006ED090
extern "C" const char gszTxtField_mS2[]; // 0x006ED08C
extern "C" const char gszTxtField_mS3[]; // 0x006ED088
extern "C" const char gszTxtField_mS4[]; // 0x006ED084
extern "C" const char gszTxtField_mDD[]; // 0x006ED080
extern "C" const char gszTxtField_mKB[]; // 0x006ED07C
extern "C" const char gszTxtField_mSQ[]; // 0x006ED078
extern "C" const char gszTxtField_mRN[]; // 0x006ED074
extern "C" const char gszTxtField_dDT[]; // 0x006ED070
extern "C" const char gszTxtField_dNU[]; // 0x006ED06C
extern "C" const char gszTxtField_dWL[]; // 0x006ED068
extern "C" const char gszTxtField_dGH[]; // 0x006ED064
extern "C" const char gszTxtField_dA1[]; // 0x006ED060
extern "C" const char gszTxtField_dA2[]; // 0x006ED05C
extern "C" const char gszTxtField_dBL[]; // 0x006ED058
extern "C" const char gszTxtField_dSC[]; // 0x006ED054
extern "C" const char gszTxtField_dS1[]; // 0x006ED050
extern "C" const char gszTxtField_dS2[]; // 0x006ED04C
extern "C" const char gszTxtField_dS3[]; // 0x006ED048
extern "C" const char gszTxtField_dS4[]; // 0x006ED044
extern "C" const char gszTxtField_dDD[]; // 0x006ED040
extern "C" const char gszTxtField_dKB[]; // 0x006ED03C
extern "C" const char gszTxtField_dSQ[]; // 0x006ED038
extern "C" const char gszTxtField_dRN[]; // 0x006ED034
extern "C" const char gszTxtField_A1mv[]; // 0x006ED02C
extern "C" const char gszTxtField_A2mv[]; // 0x006ED024
extern "C" const char gszTxtField_SCmv[]; // 0x006ED01C
extern "C" const char gszTxtField_S1mv[]; // 0x006ED014
extern "C" const char gszTxtField_S2mv[]; // 0x006ED00C
extern "C" const char gszTxtField_S3mv[]; // 0x006ED004
extern "C" const char gszTxtField_S4mv[]; // 0x006ECFFC
extern "C" const char gszTxtField_noGfxHitTest[]; // 0x006ECFEC
extern "C" const char gszTxtField_htTop[]; // 0x006ECFE4
extern "C" const char gszTxtField_htLeft[]; // 0x006ECFDC
extern "C" const char gszTxtField_htWidth[]; // 0x006ECFD4
extern "C" const char gszTxtField_htHeight[]; // 0x006ECFC8
extern "C" const char gszTxtField_restore[]; // 0x006ECFC0
extern "C" const char gszTxtField_automapCel[]; // 0x006ECFB4
extern "C" const char gszTxtField_noMap[]; // 0x006ECFAC
extern "C" const char gszTxtField_noOvly[]; // 0x006ECFA4
extern "C" const char gszTxtField_isSel[]; // 0x006ECF9C
extern "C" const char gszTxtField_alSel[]; // 0x006ECF94
extern "C" const char gszTxtField_noSel[]; // 0x006ECF8C
extern "C" const char gszTxtField_shiftSel[]; // 0x006ECF80
extern "C" const char gszTxtField_corpseSel[]; // 0x006ECF74
extern "C" const char gszTxtField_revive[]; // 0x006ECF6C
extern "C" const char gszTxtField_isAtt[]; // 0x006ECF64
extern "C" const char gszTxtField_large[]; // 0x006ECF5C
extern "C" const char gszTxtField_small[]; // 0x006ECF54
extern "C" const char gszTxtField_soft[]; // 0x006ECF4C
extern "C" const char gszTxtField_critter[]; // 0x006ECF44
extern "C" const char gszTxtField_inert[]; // 0x006ECF3C
extern "C" const char gszTxtField_objCol[]; // 0x006ECF34
extern "C" const char gszTxtField_deadCol[]; // 0x006ECF2C
extern "C" const char gszTxtField_unflatDead[]; // 0x006ECF20
extern "C" const char gszTxtField_shadow[]; // 0x006ECF18
extern "C" const char gszTxtField_noUniqueShift[]; // 0x006ECF08
extern "C" const char gszTxtField_compositeDeath[]; // 0x006ECEF8
extern "C" const char gszTxtField_localBlood[]; // 0x006ECEEC
extern "C" const char gszTxtField_bleed[]; // 0x006ECEE4
extern "C" const char gszTxtField_light[]; // 0x006ECEDC
extern "C" const char gszTxtField_light_r[]; // 0x006E7A7C
extern "C" const char gszTxtField_light_g[]; // 0x006E7A74
extern "C" const char gszTxtField_light_b[]; // 0x006E7A6C
extern "C" const char gszTxtField_Utrans[]; // 0x006EC9A8
extern "C" const char gszTxtField_Utrans_N_[]; // 0x006EC99C
extern "C" const char gszTxtField_Utrans_H_[]; // 0x006EC990
extern "C" const char gszTxtField_Heart[]; // 0x006ECED4
extern "C" const char gszTxtField_BodyPart[]; // 0x006ECEC8
extern "C" const char gszTxtField_InfernoLen[]; // 0x006ECEBC
extern "C" const char gszTxtField_InfernoAnim[]; // 0x006ECEB0
extern "C" const char gszTxtField_InfernoRollback[]; // 0x006ECEA0
extern "C" const char gszTxtField_ResurrectMode[]; // 0x006ECE90
extern "C" const char gszTxtField_ResurrectSkill[]; // 0x006ECE80
extern "C" const char gszMonStats2TxtName[]; // 0x006ECE74
void __fastcall sub_00657010(); // 0x00657010
extern D2TxtLinkStrc* gTxtLink_0096BCD8; // 0x0096BCD8
extern void* gpMonpropTxt; // 0x0096C860
extern int gnMonpropTxtRecordCount; // 0x0096C864
extern void* gpMonlvlTxt; // 0x0096C7A0
extern int gnMonlvlTxtRecordCount; // 0x0096C7A4

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nType;
    unsigned short nPlace;
};

extern D2MonPresetTxt* gpMonPresetTxtActSections[5]; // 0x0096C6DC
extern int gnMonPresetTxtActRecordCounts[5]; // 0x0096C6F0
void __fastcall DATATBLS_MonPresetPlaceLinker(char* pSrc, void* pRecord, int nOffset, int nValue, int nTxtRow, int nTxtColumn); // 0x00659990
extern D2TxtLinkStrc* gpSoundsLinker; // 0x0096BDC8
extern int gnSoundsGuard; // 0x0096C8B4

struct D2AnimSeqTxt
{
    short wSequence;
    unsigned char nMode;
    unsigned char nFrame;
    unsigned char nDir;
    unsigned char nEvent;
};

struct D2AnimSeqRecordStrc
{
    D2AnimSeqTxt* pAnimSeqTxtRecord;
    int nSeqFramesCount;
    int nFramesCount;
};
extern D2TxtLinkStrc* gTxtLink_0096C7AC; // 0x0096C7AC
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2ObjectsTxt* gpObjectsTxt; // 0x0096D470

void* gpObjgroupTxt; // 0x0096D478

D2ShrinesTxt* gpShrinesTxt; // 0x0096D468

void* gpMonTable_96C810; // 0x0096C810

int gnMonTable_96C814; // 0x0096C814

D2TxtLinkStrc* gpSuperUniquesLinker; // 0x0096C708

D2TxtLinkStrc* gTxtLink_0096C87C; // 0x0096C87C

void* gpMonumodTxt; // 0x0096C880

void* gpMonTypeTxt; // 0x0096C6C0

D2TxtLinkStrc* gTxtLink_0096C6C4; // 0x0096C6C4

void* gpMonpropTxt; // 0x0096C860

int gnMonpropTxtRecordCount; // 0x0096C864

void* gpMonlvlTxt; // 0x0096C7A0

int gnMonlvlTxtRecordCount; // 0x0096C7A4

// 0x00640EE0
void __fastcall DATATBLS_UnloadObjectsTxt()
{
    DATATBLS_UnloadBin(gpObjectsTxt);
    gpObjectsTxt = 0;
    gnObjectsTxtRecordCount = 0;
}

// 0x00640F00
void __fastcall DATATBLS_UnloadObjGroupTxt()
{
    DATATBLS_UnloadBin(gpObjgroupTxt);
    gpObjgroupTxt = 0;
    gnObjgroupTxtRecordCount = 0;
}

// 0x00641510
void __fastcall DATATBLS_UnloadShrinesTxt()
{
    DATATBLS_UnloadBin(gpShrinesTxt);
    gpShrinesTxt = 0;
    gnShrinesTxtRecordCount = 0;
}

D2TxtLinkStrc* gTxtLink_0096C6AC; // 0x0096C6AC

D2TxtLinkStrc* gTxtLink_0096BC5C; // 0x0096BC5C

D2TxtLinkStrc* gTxtLink_0096C5E8; // 0x0096C5E8

int gnMonstatsTxtRecordCount; // 0x0096C6B0

// 0x00651210
void __fastcall DATATBLS_LoadMonStatsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 17, 0, 0, &gTxtLink_0096C6AC },
        { "BaseId", 20, 0, 2, &gTxtLink_0096C6AC },
        { "NextInClass", 20, 0, 4, &gTxtLink_0096C6AC },
        { "NameStr", 22, 0, 6, (void*)sub_006117B0 },
        { "DescStr", 22, 0, 8, (void*)sub_006117B0 },
        { "Code", 9, 0, 16, 0 },
        { "TransLvl", 4, 0, 77, 0 },
        { "MonSound", 20, 0, 20, &gTxtLink_0096C6B8 },
        { "UMonSound", 20, 0, 22, &gTxtLink_0096C6B8 },
        { "MonStatsEx", 20, 0, 24, &gTxtLink_0096C6C4 },
        { "MonType", 20, 0, 28, &gTxtLink_0096C868 },
        { "MonProp", 20, 0, 26, &gTxtLink_0096C85C },
        { "AI", 20, 0, 30, &gTxtLink_0096BCBC },
        { "spawn", 20, 0, 32, &gTxtLink_0096C6AC },
        { "spawnx", 4, 0, 34, 0 },
        { "spawny", 4, 0, 35, 0 },
        { "spawnmode", 13, 0, 36, &gTxtLink_0096BC5C },
        { "minion1", 20, 0, 38, &gTxtLink_0096C6AC },
        { "minion2", 20, 0, 40, &gTxtLink_0096C6AC },
        { "PartyMin", 4, 0, 44, 0 },
        { "PartyMax", 4, 0, 45, 0 },
        { "Rarity", 4, 0, 46, 0 },
        { "MinGrp", 4, 0, 47, 0 },
        { "MaxGrp", 4, 0, 48, 0 },
        { "sparsePopulate", 4, 0, 49, 0 },
        { "Velocity", 3, 0, 50, 0 },
        { "Run", 3, 0, 52, 0 },
        { "Align", 4, 0, 76, 0 },
        { "enabled", 26, 25, 12, 0 },
        { "rangedtype", 26, 28, 12, 0 },
        { "placespawn", 26, 23, 12, 0 },
        { "isSpawn", 26, 0, 12, 0 },
        { "isMelee", 26, 1, 12, 0 },
        { "noRatio", 26, 2, 12, 0 },
        { "SetBoss", 26, 4, 12, 0 },
        { "BossXfer", 26, 5, 12, 0 },
        { "boss", 26, 6, 12, 0 },
        { "primeevil", 26, 7, 12, 0 },
        { "opendoors", 26, 3, 12, 0 },
        { "npc", 26, 8, 12, 0 },
        { "interact", 26, 9, 12, 0 },
        { "inventory", 26, 24, 12, 0 },
        { "inTown", 26, 10, 12, 0 },
        { "lUndead", 26, 11, 12, 0 },
        { "hUndead", 26, 12, 12, 0 },
        { "demon", 26, 13, 12, 0 },
        { "flying", 26, 14, 12, 0 },
        { "killable", 26, 15, 12, 0 },
        { "switchai", 26, 16, 12, 0 },
        { "noaura", 26, 27, 12, 0 },
        { "nomultishot", 26, 17, 12, 0 },
        { "neverCount", 26, 18, 12, 0 },
        { "petIgnore", 26, 19, 12, 0 },
        { "deathDmg", 26, 20, 12, 0 },
        { "genericSpawn", 26, 21, 12, 0 },
        { "zoo", 26, 22, 12, 0 },
        { "MissA1", 20, 0, 58, &gTxtLink_0096C798 },
        { "MissA2", 20, 0, 60, &gTxtLink_0096C798 },
        { "MissS1", 20, 0, 62, &gTxtLink_0096C798 },
        { "MissS2", 20, 0, 64, &gTxtLink_0096C798 },
        { "MissS3", 20, 0, 66, &gTxtLink_0096C798 },
        { "MissS4", 20, 0, 68, &gTxtLink_0096C798 },
        { "MissC", 20, 0, 70, &gTxtLink_0096C798 },
        { "MissSQ", 20, 0, 72, &gTxtLink_0096C798 },
        { "TreasureClass1", 20, 0, 134, &gTxtLink_0096C5E8 },
        { "TreasureClass2", 20, 0, 136, &gTxtLink_0096C5E8 },
        { "TreasureClass3", 20, 0, 138, &gTxtLink_0096C5E8 },
        { "TreasureClass4", 20, 0, 140, &gTxtLink_0096C5E8 },
        { "TreasureClass1(N)", 20, 0, 142, &gTxtLink_0096C5E8 },
        { "TreasureClass2(N)", 20, 0, 144, &gTxtLink_0096C5E8 },
        { "TreasureClass3(N)", 20, 0, 146, &gTxtLink_0096C5E8 },
        { "TreasureClass4(N)", 20, 0, 148, &gTxtLink_0096C5E8 },
        { "TreasureClass1(H)", 20, 0, 150, &gTxtLink_0096C5E8 },
        { "TreasureClass2(H)", 20, 0, 152, &gTxtLink_0096C5E8 },
        { "TreasureClass3(H)", 20, 0, 154, &gTxtLink_0096C5E8 },
        { "TreasureClass4(H)", 20, 0, 156, &gTxtLink_0096C5E8 },
        { "TCQuestId", 4, 0, 158, 0 },
        { "TCQuestCP", 4, 0, 159, 0 },
        { "threat", 4, 0, 78, 0 },
        { "aidel", 4, 0, 79, 0 },
        { "aidel(N)", 4, 0, 80, 0 },
        { "aidel(H)", 4, 0, 81, 0 },
        { "aidist", 4, 0, 82, 0 },
        { "aidist(N)", 4, 0, 83, 0 },
        { "aidist(H)", 4, 0, 84, 0 },
        { "aip1", 3, 0, 86, 0 },
        { "aip1(N)", 3, 0, 88, 0 },
        { "aip1(H)", 3, 0, 90, 0 },
        { "aip2", 3, 0, 92, 0 },
        { "aip2(N)", 3, 0, 94, 0 },
        { "aip2(H)", 3, 0, 96, 0 },
        { "aip3", 3, 0, 98, 0 },
        { "aip3(N)", 3, 0, 100, 0 },
        { "aip3(H)", 3, 0, 102, 0 },
        { "aip4", 3, 0, 104, 0 },
        { "aip4(N)", 3, 0, 106, 0 },
        { "aip4(H)", 3, 0, 108, 0 },
        { "aip5", 3, 0, 110, 0 },
        { "aip5(N)", 3, 0, 112, 0 },
        { "aip5(H)", 3, 0, 114, 0 },
        { "aip6", 3, 0, 116, 0 },
        { "aip6(N)", 3, 0, 118, 0 },
        { "aip6(H)", 3, 0, 120, 0 },
        { "aip7", 3, 0, 122, 0 },
        { "aip7(N)", 3, 0, 124, 0 },
        { "aip7(H)", 3, 0, 126, 0 },
        { "aip8", 3, 0, 128, 0 },
        { "aip8(N)", 3, 0, 130, 0 },
        { "aip8(H)", 3, 0, 132, 0 },
        { "Level", 3, 0, 170, 0 },
        { "Level(N)", 3, 0, 172, 0 },
        { "Level(H)", 3, 0, 174, 0 },
        { "SkillDamage", 20, 0, 168, &gTxtLink_0096C7CC },
        { "NoShldBlock", 26, 26, 12, 0 },
        { "Drain", 4, 0, 160, 0 },
        { "Drain(N)", 4, 0, 161, 0 },
        { "Drain(H)", 4, 0, 162, 0 },
        { "ToBlock", 4, 0, 163, 0 },
        { "ToBlock(N)", 4, 0, 164, 0 },
        { "ToBlock(H)", 4, 0, 165, 0 },
        { "Crit", 4, 0, 166, 0 },
        { "MinHP", 3, 0, 176, 0 },
        { "MinHP(N)", 3, 0, 178, 0 },
        { "MinHP(H)", 3, 0, 180, 0 },
        { "MaxHP", 3, 0, 182, 0 },
        { "MaxHP(N)", 3, 0, 184, 0 },
        { "MaxHP(H)", 3, 0, 186, 0 },
        { "AC", 3, 0, 188, 0 },
        { "AC(N)", 3, 0, 190, 0 },
        { "AC(H)", 3, 0, 192, 0 },
        { "Exp", 3, 0, 212, 0 },
        { "Exp(N)", 3, 0, 214, 0 },
        { "Exp(H)", 3, 0, 216, 0 },
        { "A1TH", 3, 0, 194, 0 },
        { "A1TH(N)", 3, 0, 196, 0 },
        { "A1TH(H)", 3, 0, 198, 0 },
        { "A1MinD", 3, 0, 218, 0 },
        { "A1MinD(N)", 3, 0, 220, 0 },
        { "A1MinD(H)", 3, 0, 222, 0 },
        { "A1MaxD", 3, 0, 224, 0 },
        { "A1MaxD(N)", 3, 0, 226, 0 },
        { "A1MaxD(H)", 3, 0, 228, 0 },
        { "A2TH", 3, 0, 200, 0 },
        { "A2TH(N)", 3, 0, 202, 0 },
        { "A2TH(H)", 3, 0, 204, 0 },
        { "A2MinD", 3, 0, 230, 0 },
        { "A2MinD(N)", 3, 0, 232, 0 },
        { "A2MinD(H)", 3, 0, 234, 0 },
        { "A2MaxD", 3, 0, 236, 0 },
        { "A2MaxD(N)", 3, 0, 238, 0 },
        { "A2MaxD(H)", 3, 0, 240, 0 },
        { "S1TH", 3, 0, 206, 0 },
        { "S1TH(N)", 3, 0, 208, 0 },
        { "S1TH(H)", 3, 0, 210, 0 },
        { "S1MinD", 3, 0, 242, 0 },
        { "S1MinD(N)", 3, 0, 244, 0 },
        { "S1MinD(H)", 3, 0, 246, 0 },
        { "S1MaxD", 3, 0, 248, 0 },
        { "S1MaxD(N)", 3, 0, 250, 0 },
        { "S1MaxD(H)", 3, 0, 252, 0 },
        { "El1Mode", 13, 0, 254, &gTxtLink_0096BC5C },
        { "El1Type", 13, 0, 257, &gTxtLink_0096BC4C },
        { "El1Pct", 4, 0, 260, 0 },
        { "El1Pct(N)", 4, 0, 261, 0 },
        { "El1Pct(H)", 4, 0, 262, 0 },
        { "El1MinD", 3, 0, 270, 0 },
        { "El1MinD(N)", 3, 0, 272, 0 },
        { "El1MinD(H)", 3, 0, 274, 0 },
        { "El1MaxD", 3, 0, 288, 0 },
        { "El1MaxD(N)", 3, 0, 290, 0 },
        { "El1MaxD(H)", 3, 0, 292, 0 },
        { "El1Dur", 3, 0, 306, 0 },
        { "El1Dur(N)", 3, 0, 308, 0 },
        { "El1Dur(H)", 3, 0, 310, 0 },
        { "El2Mode", 13, 0, 255, &gTxtLink_0096BC5C },
        { "El2Type", 13, 0, 258, &gTxtLink_0096BC4C },
        { "El2Pct", 4, 0, 263, 0 },
        { "El2Pct(N)", 4, 0, 264, 0 },
        { "El2Pct(H)", 4, 0, 265, 0 },
        { "El2MinD", 3, 0, 276, 0 },
        { "El2MinD(N)", 3, 0, 278, 0 },
        { "El2MinD(H)", 3, 0, 280, 0 },
        { "El2MaxD", 3, 0, 294, 0 },
        { "El2MaxD(N)", 3, 0, 296, 0 },
        { "El2MaxD(H)", 3, 0, 298, 0 },
        { "El2Dur", 3, 0, 312, 0 },
        { "El2Dur(N)", 3, 0, 314, 0 },
        { "El2Dur(H)", 3, 0, 316, 0 },
        { "El3Mode", 13, 0, 256, &gTxtLink_0096BC5C },
        { "El3Type", 13, 0, 259, &gTxtLink_0096BC4C },
        { "El3Pct", 4, 0, 266, 0 },
        { "El3Pct(N)", 4, 0, 267, 0 },
        { "El3Pct(H)", 4, 0, 268, 0 },
        { "El3MinD", 3, 0, 282, 0 },
        { "El3MinD(N)", 3, 0, 284, 0 },
        { "El3MinD(H)", 3, 0, 286, 0 },
        { "El3MaxD", 3, 0, 300, 0 },
        { "El3MaxD(N)", 3, 0, 302, 0 },
        { "El3MaxD(H)", 3, 0, 304, 0 },
        { "El3Dur", 3, 0, 318, 0 },
        { "El3Dur(N)", 3, 0, 320, 0 },
        { "El3Dur(H)", 3, 0, 322, 0 },
        { "ColdEffect", 4, 0, 360, 0 },
        { "ColdEffect(N)", 4, 0, 361, 0 },
        { "ColdEffect(H)", 4, 0, 362, 0 },
        { "ResDm", 3, 0, 324, 0 },
        { "ResDm(N)", 3, 0, 326, 0 },
        { "ResDm(H)", 3, 0, 328, 0 },
        { "ResMa", 3, 0, 330, 0 },
        { "ResMa(N)", 3, 0, 332, 0 },
        { "ResMa(H)", 3, 0, 334, 0 },
        { "ResFi", 3, 0, 336, 0 },
        { "ResFi(N)", 3, 0, 338, 0 },
        { "ResFi(H)", 3, 0, 340, 0 },
        { "ResLi", 3, 0, 342, 0 },
        { "ResLi(N)", 3, 0, 344, 0 },
        { "ResLi(H)", 3, 0, 346, 0 },
        { "ResCo", 3, 0, 348, 0 },
        { "ResCo(N)", 3, 0, 350, 0 },
        { "ResCo(H)", 3, 0, 352, 0 },
        { "ResPo", 3, 0, 354, 0 },
        { "ResPo(N)", 3, 0, 356, 0 },
        { "ResPo(H)", 3, 0, 358, 0 },
        { "SendSkills", 8, 0, 364, 0 },
        { "Skill1", 20, 0, 368, &gTxtLink_0096C7CC },
        { "Sk1mode", 23, 0, 0, (void*)sub_00651150 },
        { "Sk1lvl", 4, 0, 408, 0 },
        { "Skill2", 20, 0, 370, &gTxtLink_0096C7CC },
        { "Sk2mode", 23, 0, 1, (void*)sub_00651150 },
        { "Sk2lvl", 4, 0, 409, 0 },
        { "Skill3", 20, 0, 372, &gTxtLink_0096C7CC },
        { "Sk3mode", 23, 0, 2, (void*)sub_00651150 },
        { "Sk3lvl", 4, 0, 410, 0 },
        { "Skill4", 20, 0, 374, &gTxtLink_0096C7CC },
        { "Sk4mode", 23, 0, 3, (void*)sub_00651150 },
        { "Sk4lvl", 4, 0, 411, 0 },
        { "Skill5", 20, 0, 376, &gTxtLink_0096C7CC },
        { "Sk5mode", 23, 0, 4, (void*)sub_00651150 },
        { "Sk5lvl", 4, 0, 412, 0 },
        { "Skill6", 20, 0, 378, &gTxtLink_0096C7CC },
        { "Sk6mode", 23, 0, 5, (void*)sub_00651150 },
        { "Sk6lvl", 4, 0, 413, 0 },
        { "Skill7", 20, 0, 380, &gTxtLink_0096C7CC },
        { "Sk7mode", 23, 0, 6, (void*)sub_00651150 },
        { "Sk7lvl", 4, 0, 414, 0 },
        { "Skill8", 20, 0, 382, &gTxtLink_0096C7CC },
        { "Sk8mode", 23, 0, 7, (void*)sub_00651150 },
        { "Sk8lvl", 4, 0, 415, 0 },
        { "DamageRegen", 2, 0, 416, 0 },
        { "SplEndDeath", 4, 0, 420, 0 },
        { "SplGetModeChart", 4, 0, 421, 0 },
        { "SplEndGeneric", 4, 0, 422, 0 },
        { "SplClientEnd", 4, 0, 423, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C6AC = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 521);
    gpMonstatsTxt = DATATBLS_CompileTxt(hArchive, "monstats", pTbl, &gnMonstatsTxtRecordCount, 424);
    TBL_ASSERT(gnMonstatsTxtRecordCount < 32767, 540);
    sub_00651040();
    sub_00650F00(gnMonstatsTxtRecordCount);
}

__forceinline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

__forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x006538A0
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord(nLevel < sgptDataTables->nMonLvlTxtRecordCount - 1 ? nLevel : sgptDataTables->nMonLvlTxtRecordCount - 1);
    if (!pMonLvlTxtRecord)
    {
        return 0;
    }

    nDifficulty = nDifficulty > 0 ? nDifficulty : 0;
    if (nDifficulty >= 2)
    {
        nDifficulty = 2;
    }

    const int bExpansion = nGameType != 0;

    if (nFlags & 1)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nMinHP = pMonStatsTxtRecord->nMinHP[nDifficulty];
            pMonStatsInit->nMaxHP = pMonStatsTxtRecord->nMaxHP[nDifficulty];
        }
        else
        {
            pMonStatsInit->nMinHP = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwHP[bExpansion][nDifficulty], pMonStatsTxtRecord->nMinHP[nDifficulty], 0x64);
            pMonStatsInit->nMaxHP = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwHP[bExpansion][nDifficulty], pMonStatsTxtRecord->nMaxHP[nDifficulty], 0x64);
        }
    }

    if (nFlags & 2)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nAC = pMonStatsTxtRecord->nAC[nDifficulty];
        }
        else
        {
            pMonStatsInit->nAC = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwAC[bExpansion][nDifficulty], pMonStatsTxtRecord->nAC[nDifficulty], 0x64);
        }
    }

    if (nFlags & 4)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nExp = pMonStatsTxtRecord->nExp[nDifficulty];
        }
        else
        {
            pMonStatsInit->nExp = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwXP[bExpansion][nDifficulty], pMonStatsTxtRecord->nExp[nDifficulty], 0x64);
        }
    }

    if (nFlags & 8)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nA1TH[nDifficulty];
            pMonStatsInit->nA1MinD = pMonStatsTxtRecord->nA1MinD[nDifficulty];
            pMonStatsInit->nA1MaxD = pMonStatsTxtRecord->nA1MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1TH[nDifficulty], 0x64);
            pMonStatsInit->nA1MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1MinD[nDifficulty], 0x64);
            pMonStatsInit->nA1MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x10)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nA2TH[nDifficulty];
            pMonStatsInit->nA2MinD = pMonStatsTxtRecord->nA2MinD[nDifficulty];
            pMonStatsInit->nA2MaxD = pMonStatsTxtRecord->nA2MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2TH[nDifficulty], 0x64);
            pMonStatsInit->nA2MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2MinD[nDifficulty], 0x64);
            pMonStatsInit->nA2MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x20)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nS1TH[nDifficulty];
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nS1MinD[nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nS1MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1TH[nDifficulty], 0x64);
            pMonStatsInit->nS1MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1MinD[nDifficulty], 0x64);
            pMonStatsInit->nS1MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x40)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[0][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[0][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[0][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[0][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[0][nDifficulty];
    }

    if (nFlags & 0x80)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[1][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[1][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[1][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[1][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[1][nDifficulty];
    }

    if (nFlags & 0x100)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[2][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[2][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[2][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[2][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[2][nDifficulty];
    }

    return 1;
}

#include "gen/data/Source/D2Common/DATATBLS/MonsterTbls.inc"

// 0x00653E50
const Unicode* __fastcall sub_00653E50_RollRandomUniqueNameString(D2UnitStrc* pUnit, int nTable)
{
    if (pUnit && gnUniqueNameTxtRecordCounts_0096D498[nTable] > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueNameTxtRecordCounts_0096D498[nTable]);
        if (gpUniqueNameTxtTables_0096D488[nTable][nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueNameTxtTables_0096D488[nTable][nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653E90
const Unicode* __fastcall DATATBLS_RollRandomUniqueTitleString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueNameTxtRecordCounts_0096D498[0] > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueNameTxtRecordCounts_0096D498[0]);
        if (gpUniqueNameTxtTables_0096D488[0][nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueNameTxtTables_0096D488[0][nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x006540C0
void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion)
{
    int nIndex = pTCExInfo - pTCExShort->pInfo;
    int nCurrent;

    if (nIndex == pTCExShort->nTypes - 1)
    {
        nCurrent = pTCExShort->nProb - pTCExInfo->nProb;
    }
    else
    {
        nCurrent = pTCExShort->pInfo[nIndex + 1].nProb - pTCExInfo->nProb;
    }

    if (nCurrent != nProbability)
    {
        int nDiff = nProbability - nCurrent;
        pTCExShort->nProb += nDiff;
        for (int i = nIndex + 1; i < pTCExShort->nTypes; ++i)
        {
            pTCExShort->pInfo[i].nProb += nDiff;
        }
    }

    if (!bExpansion)
    {
        if (nIndex == pTCExShort->nTypes - 1)
        {
            nCurrent = pTCExShort->nClassic - pTCExInfo->nClassic;
        }
        else
        {
            nCurrent = pTCExShort->pInfo[nIndex + 1].nClassic - pTCExInfo->nClassic;
        }

        if (nCurrent != nProbability)
        {
            int nDiff = nProbability - nCurrent;
            pTCExShort->nClassic += nDiff;
            for (int i = nIndex + 1; i < pTCExShort->nTypes; ++i)
            {
                pTCExShort->pInfo[i].nClassic += nDiff;
            }
        }
    }
}

// 0x006541C0
void __cdecl DATATBLS_CreateItemTypeTreasureClasses()
{
    char szName[32];
    char szCode[8];

    DATATBLS_NewTreasureClassEx(&gszEmptyAssertText);
    D2ItemDataTbl* pItemDataTables = DATATBLS_GetItemDataTables();

    for (int i = 0; i < sgptDataTables->nItemTypesTxtRecordCount; ++i)
    {
        TableRow* pItemTypesTxtRecord = ITEMTYPES_RECORD(i);
        if (!pItemTypesTxtRecord)
        {
            break;
        }

        if (pItemTypesTxtRecord->nTreasureClass)
        {
            ++gwTreasureClassItemTypes;

            int nLevel = 3;
            do
            {
                if (FOG_GetStringFromLinkIndex(gpItemTypesLinker, i, szCode))
                {
                    SStrPrintf(szName, sizeof(szName), "%s%d", szCode, nLevel);
                    D2TCExShortStrc* pTCExTxtRecord = DATATBLS_NewTreasureClassEx(szName);
                    if (pTCExTxtRecord)
                    {
                        pTCExTxtRecord->nPicks = 1;
                        pTCExTxtRecord->nGroup = 0;
                        pTCExTxtRecord->nLevel = nLevel - 3;

                        for (int j = 0; j < pItemDataTables->nItemsTxtRecordCount; ++j)
                        {
                            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(j);
                            if (pItemsTxtRecord && !pItemsTxtRecord->nQuest && pItemsTxtRecord->nSpawnable && ITEMS_CheckItemTypeIdByItemId(j, i)
                                && (i == 38 || !ITEMS_CheckItemTypeIdByItemId(j, 38))
                                && pItemsTxtRecord->nLevel > nLevel - 3 && pItemsTxtRecord->nLevel <= nLevel)
                            {
                                TableRow* pTypeRecord = sub_00555C90_GetTableRow(pItemsTxtRecord->wType[0]);
                                if (pTypeRecord)
                                {
                                    const int nProbability = pTypeRecord->nRarity > 1 ? pTypeRecord->nRarity : 1;
                                    D2TCExInfoStrc* pTCExInfo = sub_00654080(pTCExTxtRecord);
                                    pTCExInfo->nItemId = j;
                                    if (pItemsTxtRecord->wVersion >= 100)
                                    {
                                        pTCExInfo->nFlags |= 0x10;
                                    }
                                    DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProbability, pItemsTxtRecord->wVersion >= 100);
                                }
                            }
                        }
                    }
                }
                nLevel += 3;
            }
            while (nLevel <= 96);
        }
    }
}

// 0x006543C0
static char* sub_006543C0_StripQuotes(char* szText)
{
    if (*szText == '"')
        ++szText;
    for (char* p = szText; *p; ++p)
    {
        if (*p == '"')
            *p = 0;
    }
    return szText;
}

// 0x006543F0
static char* sub_006543F0_NextStrToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return szToken;
}

// 0x00654410
static int sub_00654410_NextIntToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return atoi(szToken);
}

int __stdcall sub_A10_Emit_00654410(char* szText, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
    {
        nSum += sub_00654410_NextIntToken(&szText, ',');
    }
    return nSum;
}

int gnTreasureClassItemTypes; // 0x0096D4B0

static __declspec(noinline) void sub_00650EB0_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// build: context DATATBLS_ParseTreasureClassItem
static __declspec(noinline) int __stdcall DATATBLS_ParseTreasureClassItem(D2TCExShortStrc* pTCExTxtRecord, int nProb, char* szText)
{
    if (nProb <= 0)
    {
        return 0;
    }

    char* szItem = szText;
    if (szItem[0] == '"')
    {
        ++szItem;
    }

    for (char* szTmp = szItem; *szTmp; ++szTmp)
    {
        if (*szTmp == '"')
        {
            *szTmp = 0;
        }
    }

    char* szNext = strchr(szItem, ',');
    if (szNext)
    {
        *szNext = 0;
        ++szNext;
    }

    D2TCExInfoStrc* pTCExInfo;
    if (strlen(szItem) <= 4)
    {
        int nItemId;
        sub_00650EB0_MakeCode(szItem, (char*)&nItemId);
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(nItemId, &nItemId);
        if (pItemsTxtRecord)
        {
            pTCExInfo = sub_00654080(pTCExTxtRecord);
            pTCExInfo->nItemId = nItemId;
            if (pItemsTxtRecord->wVersion >= 100)
            {
                pTCExInfo->nFlags |= 0x10;
            }
            DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProb, pItemsTxtRecord->wVersion >= 100);
            goto MODIFIERS;
        }
    }

    {
        int nIndex = FOG_GetLinkIndex(gpTreasureClassExLinker, szItem, 0);
        if (nIndex > 0)
        {
            pTCExInfo = sub_00654080(pTCExTxtRecord);
            pTCExInfo->nFlags |= 4;
            pTCExInfo->nItemId = nIndex;
            if (!gpTreasureClassEx[nIndex].nClassic)
            {
                pTCExInfo->nFlags |= 0x10;
            }
            DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProb, gpTreasureClassEx[nIndex].nClassic == 0);
        }
        else if (gpUniqueItemsLinker && (nIndex = FOG_GetLinkIndex(gpUniqueItemsLinker, szItem, 0)) > 0)
        {
            pTCExInfo = sub_00654080(pTCExTxtRecord);
            int nUniqueItemId;
            DATATBLS_GetItemRecordFromItemCode(((D2UniqueItemsTxt*)gpUniqueItemsTxt)[nIndex].dwBaseItemCode, &nUniqueItemId);
            pTCExInfo->nFlags |= 0x11;
            pTCExInfo->nItemId = nUniqueItemId;
            pTCExInfo->nTxtRow = nIndex;
            DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProb, 1);
        }
        else
        {
            if (!gpSetItemsLinker)
            {
                return 0;
            }
            nIndex = FOG_GetLinkIndex(gpSetItemsLinker, szItem, 0);
            if (nIndex < 0)
            {
                return 0;
            }
            pTCExInfo = sub_00654080(pTCExTxtRecord);
            int nSetItemId;
            DATATBLS_GetItemRecordFromItemCode(((D2SetItemsTxt*)gpSetItemsTxt)[nIndex].dwItemCode, &nSetItemId);
            pTCExInfo->nFlags |= 0x12;
            pTCExInfo->nItemId = nSetItemId;
            pTCExInfo->nTxtRow = nIndex;
            DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProb, 1);
        }
    }

MODIFIERS:
    while (szNext)
    {
        char* szKey = szNext;
        char* szArg = strchr(szNext, '=');
        if (!szArg)
        {
            break;
        }
        *szArg = 0;
        ++szArg;
        if (!szArg)
        {
            break;
        }

        if (!strcmp(szKey, "mul"))
        {
            szNext = strchr(szArg, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nTxtRow = atoi(szArg);
        }
        else if (!strcmp(szKey, "cu"))
        {
            szNext = strchr(szArg, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nUnique = atoi(szArg);
        }
        else if (!strcmp(szKey, "cs"))
        {
            szNext = strchr(szArg, ',');
            if (szNext)
            {
                *szNext = 0;
                ++szNext;
            }
            pTCExInfo->nSet = atoi(szArg);
        }
        else if (!strcmp(szKey, "cr"))
        {
            pTCExInfo->nRare = sub_00654410_NextIntToken(&szArg, ',');
            szNext = szArg;
        }
        else if (!strcmp(szKey, "cm"))
        {
            pTCExInfo->nMagic = sub_00654410_NextIntToken(&szArg, ',');
            szNext = szArg;
        }
        else if (!strcmp(szKey, "ce"))
        {
            pTCExInfo->nSuperior = sub_00654410_NextIntToken(&szArg, ',');
            szNext = szArg;
        }
        else if (!strcmp(szKey, "cg"))
        {
            pTCExInfo->nNormal = sub_00654410_NextIntToken(&szArg, ',');
            szNext = szArg;
        }
        else if (!strcmp(szKey, "ma") || !strcmp(szKey, "mg"))
        {
            pTCExInfo->nTxtRow = sub_00654410_NextIntToken(&szArg, ',');
            szNext = szArg;
        }
        else
        {
            break;
        }
    }

    return 1;
}

// 0x006547D0
void __stdcall sub_006547D0(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "treasure class", 1, 32, 0, 0 },
        { "group", 3, 0, 36, 0 },
        { "level", 3, 0, 38, 0 },
        { "picks", 2, 0, 32, 0 },
        { "unique", 3, 0, 46, 0 },
        { "set", 3, 0, 44, 0 },
        { "rare", 3, 0, 42, 0 },
        { gszTxtField_magic_006DCFBC, 3, 0, 40, 0 },
        { "nodrop", 2, 0, 52, 0 },
        { "item1", 1, 64, 56, 0 },
        { "prob1", 2, 0, 696, 0 },
        { "item2", 1, 64, 120, 0 },
        { "prob2", 2, 0, 700, 0 },
        { "item3", 1, 64, 184, 0 },
        { "prob3", 2, 0, 704, 0 },
        { "item4", 1, 64, 248, 0 },
        { "prob4", 2, 0, 708, 0 },
        { "item5", 1, 64, 312, 0 },
        { "prob5", 2, 0, 712, 0 },
        { "item6", 1, 64, 376, 0 },
        { "prob6", 2, 0, 716, 0 },
        { "item7", 1, 64, 440, 0 },
        { "prob7", 2, 0, 720, 0 },
        { "item8", 1, 64, 504, 0 },
        { "prob8", 2, 0, 724, 0 },
        { "item9", 1, 64, 568, 0 },
        { "prob9", 2, 0, 728, 0 },
        { "item10", 1, 64, 632, 0 },
        { "prob10", 2, 0, 732, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    int nRecordCount;
    D2TreasureClassExTxt* pTreasureClassExTxt = (D2TreasureClassExTxt*)DATATBLS_CompileTxt(hArchive, "treasureclassex", pTbl, &nRecordCount, sizeof(D2TreasureClassExTxt));

    for (int i = 0; i < nRecordCount; ++i)
    {
        if (!pTreasureClassExTxt[i].szTreasureClass[0])
        {
            break;
        }

        D2TCExShortStrc* pTCExTxtRecord = DATATBLS_NewTreasureClassEx(pTreasureClassExTxt[i].szTreasureClass);
        if (pTCExTxtRecord)
        {
            if (pTreasureClassExTxt[i].nGroup)
            {
                pTCExTxtRecord->nGroup = pTreasureClassExTxt[i].nGroup + gnTreasureClassItemTypes;
            }
            pTCExTxtRecord->nLevel = pTreasureClassExTxt[i].nLevel;
            pTCExTxtRecord->nPicks = pTreasureClassExTxt[i].nPicks;
            if (!pTCExTxtRecord->nPicks)
            {
                pTCExTxtRecord->nPicks = 1;
            }
            pTCExTxtRecord->nNoDrop = pTreasureClassExTxt[i].nNoDrop;
            for (int nQuality = 0; nQuality < 6; ++nQuality)
            {
                pTCExTxtRecord->nQuality[nQuality] = pTreasureClassExTxt[i].nQuality[nQuality];
            }

            for (int nItem = 0; nItem < 10; ++nItem)
            {
                if (!pTreasureClassExTxt[i].szItem[nItem][0])
                {
                    break;
                }
                DATATBLS_ParseTreasureClassItem(pTCExTxtRecord, pTreasureClassExTxt[i].nProb[nItem], pTreasureClassExTxt[i].szItem[nItem]);
            }
        }
    }

    DATATBLS_UnloadBin(pTreasureClassExTxt);
}

char* __stdcall sub_M116_Emit_006543C0(char* szText, char** ppOut)
{
    ppOut[0] = sub_006543C0_StripQuotes(sub_006543F0_NextStrToken(&szText, ','));
    ppOut[1] = sub_006543F0_NextStrToken(&szText, ',');
    return szText;
}

// 0x00654EF0
void __fastcall sub_00654EF0_UnloadTCEx()
{
    sub_00654D50();
}

// 0x00654F00
void __cdecl sub_00654F00_AssertFail()
{
    D2_ASSERT(0, 0x6AE);
}

void* gpMonitempercentTxt; // 0x0096D484

int gnMonitempercentTxtRecordCount; // 0x0096D480

// 0x00654F20
void __fastcall DATATBLS_LoadMonItemPercentTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "HeartPercent", 4, 0, 0, 0 },
        { "BodyPartPercent", 4, 0, 1, 0 },
        { "TreasureClassPercent", 4, 0, 2, 0 },
        { "ComponentPercent", 4, 0, 3, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonitempercentTxt = DATATBLS_CompileTxt(hArchive, "monitempercent", pTbl, &gnMonitempercentTxtRecordCount, 4);
}

int gnMonumodTxtRecordCount; // 0x0096C884

// 0x00655030
void __fastcall DATATBLS_LoadMonUModTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "uniquemod", 17, 0, 0, &gTxtLink_0096C87C },
        { gszTxtField_version, 3, 0, 4, 0 },
        { "enabled", 4, 0, 6, 0 },
        { "xfer", 4, 0, 7, 0 },
        { "champion", 4, 0, 8, 0 },
        { "fpick", 4, 0, 9, 0 },
        { "exclude1", 20, 0, 10, &gTxtLink_0096C868 },
        { "exclude2", 20, 0, 12, &gTxtLink_0096C868 },
        { "cpick", 3, 0, 14, 0 },
        { "cpick (N)", 3, 0, 16, 0 },
        { "cpick (H)", 3, 0, 18, 0 },
        { "upick", 3, 0, 20, 0 },
        { "upick (N)", 3, 0, 22, 0 },
        { "upick (H)", 3, 0, 24, 0 },
        { "constants", 2, 0, 28, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C87C = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 1791);
    gpMonumodTxt = DATATBLS_CompileTxt(hArchive, "monumod", pTbl, &gnMonumodTxtRecordCount, 32);
    if (gnMonumodTxtRecordCount > 256)
    {
        gnMonumodTxtRecordCount = 256;
    }
}

// 0x006552E0
void __fastcall DATATBLS_LoadSuperUniquesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Superunique", 17, 0, 0, &gtDataTables_0096BC30.pSuperUniquesLinker },
        { "Name", 22, 0, 2, (void*)sub_006117B0 },
        { "Class", 19, 0, 4, &gtDataTables_0096BC30.pMonStatsLinker },
        { "hcIdx", 2, 0, 8, 0 },
        { "MonSound", 19, 0, 24, &gtDataTables_0096BC30.pMonSoundsLinker },
        { "Mod1", 2, 0, 12, 0 },
        { "Mod2", 2, 0, 16, 0 },
        { "Mod3", 2, 0, 20, 0 },
        { "MinGrp", 2, 0, 28, 0 },
        { "MaxGrp", 2, 0, 32, 0 },
        { "AutoPos", 4, 0, 36, 0 },
        { "EClass", 4, 0, 37, 0 },
        { "Stacks", 4, 0, 38, 0 },
        { "Replaceable", 4, 0, 39, 0 },
        { "Utrans", 4, 0, 40, 0 },
        { "Utrans(N)", 4, 0, 41, 0 },
        { "Utrans(H)", 4, 0, 42, 0 },
        { "TC", 20, 0, 44, &gtDataTables_0096BC30.pTreasureClassExLinker },
        { "TC(N)", 20, 0, 46, &gtDataTables_0096BC30.pTreasureClassExLinker },
        { "TC(H)", 20, 0, 48, &gtDataTables_0096BC30.pTreasureClassExLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gtDataTables_0096BC30.pSuperUniquesLinker = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 0x744);
    gtDataTables_0096BC30.pSuperUniquesTxt = (D2SuperUniquesTxt*)DATATBLS_CompileTxt(hArchive, "superuniques", pTbl, &gtDataTables_0096BC30.nSuperUniquesTxtRecordCount, sizeof(D2SuperUniquesTxt));
    if (gtDataTables_0096BC30.nSuperUniquesTxtRecordCount >= 512)
    {
        gtDataTables_0096BC30.nSuperUniquesTxtRecordCount = 512;
    }

    for (int i = 0; i < 66; ++i)
    {
        gtDataTables_0096BC30.nSuperUniqueIds[i] = 0xFFFF;
    }

    for (int i = 0; i < gtDataTables_0096BC30.nSuperUniquesTxtRecordCount; ++i)
    {
        const int nId = gtDataTables_0096BC30.pSuperUniquesTxt[i].dwHcIdx;
        if (nId >= 0 && nId < 66 && gtDataTables_0096BC30.nSuperUniqueIds[nId] == 0xFFFF)
        {
            gtDataTables_0096BC30.nSuperUniqueIds[nId] = (unsigned short)i;
        }
    }

    for (int i = 0; i < 66; ++i)
    {
        D2_ASSERT(gtDataTables_0096BC30.nSuperUniqueIds[i] != 0xFFFF, 0x782);
    }
}

// 0x00656440
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromClassId(int bExpansion, int nClass, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].dwClass == nClass && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}

// 0x00656580
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord)
{
    ++nAct;
    ++nDifficulty;

    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;
    int nLevel = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
        nLevel = pOldRecord->nHirelingLevel;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        pHirelingTxtRecord = &gpHirelingTxt[i];
        if (pHirelingTxtRecord->dwAct == nAct && pHirelingTxtRecord->dwDifficulty == nDifficulty && pHirelingTxtRecord->wVersion == nVersion && (!nLevel || pHirelingTxtRecord->nHirelingLevel == nLevel))
        {
            return pHirelingTxtRecord;
        }
    }

    return 0;
}

int gnNpcTxtRecordCount; // 0x0096C5DC

// 0x00656620
void __fastcall DATATBLS_LoadNpcTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "npc", 19, 0, 0, &gTxtLink_0096C6AC },
        { "sell mult", 2, 0, 4, 0 },
        { "buy mult", 2, 0, 8, 0 },
        { "rep mult", 2, 0, 12, 0 },
        { "questflag A", 2, 0, 16, 0 },
        { "questflag B", 2, 0, 20, 0 },
        { "questflag C", 2, 0, 24, 0 },
        { "questsellmult A", 2, 0, 28, 0 },
        { "questsellmult B", 2, 0, 32, 0 },
        { "questsellmult C", 2, 0, 36, 0 },
        { "questbuymult A", 2, 0, 40, 0 },
        { "questbuymult B", 2, 0, 44, 0 },
        { "questbuymult C", 2, 0, 48, 0 },
        { "questrepmult A", 2, 0, 52, 0 },
        { "questrepmult B", 2, 0, 56, 0 },
        { "questrepmult C", 2, 0, 60, 0 },
        { "max buy", 2, 0, 64, 0 },
        { "max buy (N)", 2, 0, 68, 0 },
        { "max buy (H)", 2, 0, 72, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpNpcTxt = DATATBLS_CompileTxt(hArchive, "npc", pTbl, &gnNpcTxtRecordCount, 76);
}

D2TxtLinkStrc* gTxtLink_0096C6B8; // 0x0096C6B8

// 0x00656930
void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 17, 0, 0, &gTxtLink_0096C6B8 },
        { "Attack1", 19, 0, 4, &gTxtLink_0096BDC8 },
        { "Att1Del", 2, 0, 8, 0 },
        { "Att1Prb", 2, 0, 12, 0 },
        { "Attack2", 19, 0, 28, &gTxtLink_0096BDC8 },
        { "Att2Del", 2, 0, 32, 0 },
        { "Att2Prb", 2, 0, 36, 0 },
        { "Weapon1", 19, 0, 16, &gTxtLink_0096BDC8 },
        { "Wea1Del", 2, 0, 20, 0 },
        { "Wea1Vol", 2, 0, 24, 0 },
        { "Weapon2", 19, 0, 40, &gTxtLink_0096BDC8 },
        { "Wea2Del", 2, 0, 44, 0 },
        { "Wea2Vol", 2, 0, 48, 0 },
        { "HitSound", 19, 0, 52, &gTxtLink_0096BDC8 },
        { "HitDelay", 2, 0, 56, 0 },
        { "DeathSound", 19, 0, 60, &gTxtLink_0096BDC8 },
        { "DeaDelay", 2, 0, 64, 0 },
        { "Skill1", 19, 0, 68, &gTxtLink_0096BDC8 },
        { "Skill2", 19, 0, 72, &gTxtLink_0096BDC8 },
        { "Skill3", 19, 0, 76, &gTxtLink_0096BDC8 },
        { "Skill4", 19, 0, 80, &gTxtLink_0096BDC8 },
        { "Footstep", 19, 0, 84, &gTxtLink_0096BDC8 },
        { "FootstepLayer", 19, 0, 88, &gTxtLink_0096BDC8 },
        { "FsCnt", 2, 0, 92, 0 },
        { "FsOff", 2, 0, 96, 0 },
        { "FsPrb", 2, 0, 100, 0 },
        { "Neutral", 19, 0, 104, &gTxtLink_0096BDC8 },
        { "NeuTime", 2, 0, 108, 0 },
        { "Init", 19, 0, 112, &gTxtLink_0096BDC8 },
        { "Taunt", 19, 0, 116, &gTxtLink_0096BDC8 },
        { "Flee", 19, 0, 120, &gTxtLink_0096BDC8 },
        { "CvtMo1", 13, 0, 124, &gTxtLink_0096BC5C },
        { "CvtMo2", 13, 0, 132, &gTxtLink_0096BC5C },
        { "CvtMo3", 13, 0, 140, &gTxtLink_0096BC5C },
        { "CvtSk1", 19, 0, 128, &gTxtLink_0096C7CC },
        { "CvtSk2", 19, 0, 136, &gTxtLink_0096C7CC },
        { "CvtSk3", 19, 0, 144, &gTxtLink_0096C7CC },
        { "CvtTgt1", 13, 0, 125, &gTxtLink_0096BC5C },
        { "CvtTgt2", 13, 0, 133, &gTxtLink_0096BC5C },
        { "CvtTgt3", 13, 0, 141, &gTxtLink_0096BC5C },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C6B8 = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2415);
    gpMonsoundsTxt = DATATBLS_CompileTxt(hArchive, "monsounds", pTbl, &gnMonsoundsTxtRecordCount, 148);
}

// 0x006571A0
D2MonStats2Txt* __fastcall DATATBLS_LoadMonStats2Txt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { gszTxtField_Id, TXTFIELD_NAMETOINDEX, 0, 0, &gtDataTables_0096BC30.pMonStats2Linker },
        { gszTxtField_Height, TXTFIELD_BYTE, 0, 11, 0 },
        { gszTxtField_overlayHeight, TXTFIELD_BYTE, 0, 12, 0 },
        { gszTxtField_pixHeight, TXTFIELD_BYTE, 0, 13, 0 },
        { gszTxtField_SizeX, TXTFIELD_BYTE, 0, 8, 0 },
        { gszTxtField_SizeY, TXTFIELD_BYTE, 0, 9, 0 },
        { gszTxtField_spawnCol, TXTFIELD_BYTE, 0, 10, 0 },
        { gszTxtField_MeleeRng, TXTFIELD_BYTE, 0, 14, 0 },
        { gszTxtField_BaseW, TXTFIELD_ASCIITOCODE, 0, 16, 0 },
        { gszTxtField_HitClass, TXTFIELD_BYTE, 0, 20, 0 },
        { gszTxtField_HDv, TXTFIELD_CUSTOMLINK, 0, 0, (void*)sub_00657010 },
        { gszTxtField_TRv, TXTFIELD_CUSTOMLINK, 0, 1, (void*)sub_00657010 },
        { gszTxtField_LGv, TXTFIELD_CUSTOMLINK, 0, 2, (void*)sub_00657010 },
        { gszTxtField_Rav, TXTFIELD_CUSTOMLINK, 0, 3, (void*)sub_00657010 },
        { gszTxtField_Lav, TXTFIELD_CUSTOMLINK, 0, 4, (void*)sub_00657010 },
        { gszTxtField_RHv, TXTFIELD_CUSTOMLINK, 0, 5, (void*)sub_00657010 },
        { gszTxtField_LHv, TXTFIELD_CUSTOMLINK, 0, 6, (void*)sub_00657010 },
        { gszTxtField_SHv, TXTFIELD_CUSTOMLINK, 0, 7, (void*)sub_00657010 },
        { gszTxtField_S1v, TXTFIELD_CUSTOMLINK, 0, 8, (void*)sub_00657010 },
        { gszTxtField_S2v, TXTFIELD_CUSTOMLINK, 0, 9, (void*)sub_00657010 },
        { gszTxtField_S3v, TXTFIELD_CUSTOMLINK, 0, 10, (void*)sub_00657010 },
        { gszTxtField_S4v, TXTFIELD_CUSTOMLINK, 0, 11, (void*)sub_00657010 },
        { gszTxtField_S5v, TXTFIELD_CUSTOMLINK, 0, 12, (void*)sub_00657010 },
        { gszTxtField_S6v, TXTFIELD_CUSTOMLINK, 0, 13, (void*)sub_00657010 },
        { gszTxtField_S7v, TXTFIELD_CUSTOMLINK, 0, 14, (void*)sub_00657010 },
        { gszTxtField_S8v, TXTFIELD_CUSTOMLINK, 0, 15, (void*)sub_00657010 },
        { gszTxtField_HD, TXTFIELD_BIT, 0, 232, 0 },
        { gszTxtField_TR, TXTFIELD_BIT, 1, 232, 0 },
        { gszTxtField_LG, TXTFIELD_BIT, 2, 232, 0 },
        { gszTxtField_RA, TXTFIELD_BIT, 3, 232, 0 },
        { gszTxtField_LA, TXTFIELD_BIT, 4, 232, 0 },
        { gszTxtField_RH, TXTFIELD_BIT, 5, 232, 0 },
        { gszTxtField_LH, TXTFIELD_BIT, 6, 232, 0 },
        { gszTxtField_SH, TXTFIELD_BIT, 7, 232, 0 },
        { gszTxtField_S1, TXTFIELD_BIT, 8, 232, 0 },
        { gszTxtField_S2, TXTFIELD_BIT, 9, 232, 0 },
        { gszTxtField_S3, TXTFIELD_BIT, 10, 232, 0 },
        { gszTxtField_S4, TXTFIELD_BIT, 11, 232, 0 },
        { gszTxtField_S5, TXTFIELD_BIT, 12, 232, 0 },
        { gszTxtField_S6, TXTFIELD_BIT, 13, 232, 0 },
        { gszTxtField_S7, TXTFIELD_BIT, 14, 232, 0 },
        { gszTxtField_S8, TXTFIELD_BIT, 15, 232, 0 },
        { gszTxtField_TotalPieces, TXTFIELD_BYTE, 0, 236, 0 },
        { gszTxtField_mDT, TXTFIELD_BIT, 0, 240, 0 },
        { gszTxtField_mNU, TXTFIELD_BIT, 1, 240, 0 },
        { gszTxtField_mWL, TXTFIELD_BIT, 2, 240, 0 },
        { gszTxtField_mGH, TXTFIELD_BIT, 3, 240, 0 },
        { gszTxtField_mA1, TXTFIELD_BIT, 4, 240, 0 },
        { gszTxtField_mA2, TXTFIELD_BIT, 5, 240, 0 },
        { gszTxtField_mBL, TXTFIELD_BIT, 6, 240, 0 },
        { gszTxtField_mSC, TXTFIELD_BIT, 7, 240, 0 },
        { gszTxtField_mS1, TXTFIELD_BIT, 8, 240, 0 },
        { gszTxtField_mS2, TXTFIELD_BIT, 9, 240, 0 },
        { gszTxtField_mS3, TXTFIELD_BIT, 10, 240, 0 },
        { gszTxtField_mS4, TXTFIELD_BIT, 11, 240, 0 },
        { gszTxtField_mDD, TXTFIELD_BIT, 12, 240, 0 },
        { gszTxtField_mKB, TXTFIELD_BIT, 13, 240, 0 },
        { gszTxtField_mSQ, TXTFIELD_BIT, 14, 240, 0 },
        { gszTxtField_mRN, TXTFIELD_BIT, 15, 240, 0 },
        { gszTxtField_dDT, TXTFIELD_BYTE, 0, 244, 0 },
        { gszTxtField_dNU, TXTFIELD_BYTE, 0, 245, 0 },
        { gszTxtField_dWL, TXTFIELD_BYTE, 0, 246, 0 },
        { gszTxtField_dGH, TXTFIELD_BYTE, 0, 247, 0 },
        { gszTxtField_dA1, TXTFIELD_BYTE, 0, 248, 0 },
        { gszTxtField_dA2, TXTFIELD_BYTE, 0, 249, 0 },
        { gszTxtField_dBL, TXTFIELD_BYTE, 0, 250, 0 },
        { gszTxtField_dSC, TXTFIELD_BYTE, 0, 251, 0 },
        { gszTxtField_dS1, TXTFIELD_BYTE, 0, 252, 0 },
        { gszTxtField_dS2, TXTFIELD_BYTE, 0, 253, 0 },
        { gszTxtField_dS3, TXTFIELD_BYTE, 0, 254, 0 },
        { gszTxtField_dS4, TXTFIELD_BYTE, 0, 255, 0 },
        { gszTxtField_dDD, TXTFIELD_BYTE, 0, 256, 0 },
        { gszTxtField_dKB, TXTFIELD_BYTE, 0, 257, 0 },
        { gszTxtField_dSQ, TXTFIELD_BYTE, 0, 258, 0 },
        { gszTxtField_dRN, TXTFIELD_BYTE, 0, 259, 0 },
        { gszTxtField_A1mv, TXTFIELD_BIT, 4, 260, 0 },
        { gszTxtField_A2mv, TXTFIELD_BIT, 5, 260, 0 },
        { gszTxtField_SCmv, TXTFIELD_BIT, 7, 260, 0 },
        { gszTxtField_S1mv, TXTFIELD_BIT, 8, 260, 0 },
        { gszTxtField_S2mv, TXTFIELD_BIT, 9, 260, 0 },
        { gszTxtField_S3mv, TXTFIELD_BIT, 10, 260, 0 },
        { gszTxtField_S4mv, TXTFIELD_BIT, 11, 260, 0 },
        { gszTxtField_noGfxHitTest, TXTFIELD_BIT, 0, 4, 0 },
        { gszTxtField_htTop, TXTFIELD_WORD, 0, 270, 0 },
        { gszTxtField_htLeft, TXTFIELD_WORD, 0, 272, 0 },
        { gszTxtField_htWidth, TXTFIELD_WORD, 0, 274, 0 },
        { gszTxtField_htHeight, TXTFIELD_WORD, 0, 276, 0 },
        { gszTxtField_restore, TXTFIELD_BYTE, 0, 304, 0 },
        { gszTxtField_automapCel, TXTFIELD_DWORD, 0, 280, 0 },
        { gszTxtField_noMap, TXTFIELD_BIT, 1, 4, 0 },
        { gszTxtField_noOvly, TXTFIELD_BIT, 2, 4, 0 },
        { gszTxtField_isSel, TXTFIELD_BIT, 3, 4, 0 },
        { gszTxtField_alSel, TXTFIELD_BIT, 4, 4, 0 },
        { gszTxtField_noSel, TXTFIELD_BIT, 5, 4, 0 },
        { gszTxtField_shiftSel, TXTFIELD_BIT, 6, 4, 0 },
        { gszTxtField_corpseSel, TXTFIELD_BIT, 7, 4, 0 },
        { gszTxtField_revive, TXTFIELD_BIT, 8, 4, 0 },
        { gszTxtField_isAtt, TXTFIELD_BIT, 9, 4, 0 },
        { gszTxtField_large, TXTFIELD_BIT, 11, 4, 0 },
        { gszTxtField_small, TXTFIELD_BIT, 10, 4, 0 },
        { gszTxtField_soft, TXTFIELD_BIT, 12, 4, 0 },
        { gszTxtField_critter, TXTFIELD_BIT, 13, 4, 0 },
        { gszTxtField_inert, TXTFIELD_BIT, 17, 4, 0 },
        { gszTxtField_objCol, TXTFIELD_BIT, 18, 4, 0 },
        { gszTxtField_deadCol, TXTFIELD_BIT, 19, 4, 0 },
        { gszTxtField_unflatDead, TXTFIELD_BIT, 20, 4, 0 },
        { gszTxtField_shadow, TXTFIELD_BIT, 14, 4, 0 },
        { gszTxtField_noUniqueShift, TXTFIELD_BIT, 15, 4, 0 },
        { gszTxtField_compositeDeath, TXTFIELD_BIT, 16, 4, 0 },
        { gszTxtField_localBlood, TXTFIELD_BYTE, 0, 284, 0 },
        { gszTxtField_bleed, TXTFIELD_BYTE, 0, 285, 0 },
        { gszTxtField_light, TXTFIELD_BYTE, 0, 286, 0 },
        { gszTxtField_light_r, TXTFIELD_BYTE, 0, 287, 0 },
        { gszTxtField_light_g, TXTFIELD_BYTE, 0, 288, 0 },
        { gszTxtField_light_b, TXTFIELD_BYTE, 0, 289, 0 },
        { gszTxtField_Utrans, TXTFIELD_BYTE, 0, 290, 0 },
        { gszTxtField_Utrans_N_, TXTFIELD_BYTE, 0, 291, 0 },
        { gszTxtField_Utrans_H_, TXTFIELD_BYTE, 0, 292, 0 },
        { gszTxtField_Heart, TXTFIELD_ASCIITOCODE, 0, 296, 0 },
        { gszTxtField_BodyPart, TXTFIELD_ASCIITOCODE, 0, 300, 0 },
        { gszTxtField_InfernoLen, TXTFIELD_BYTE, 0, 264, 0 },
        { gszTxtField_InfernoAnim, TXTFIELD_BYTE, 0, 265, 0 },
        { gszTxtField_InfernoRollback, TXTFIELD_BYTE, 0, 266, 0 },
        { gszTxtField_ResurrectMode, TXTFIELD_CODETOBYTE, 0, 267, &gtDataTables_0096BC30.pMonModeLinker },
        { gszTxtField_ResurrectSkill, TXTFIELD_NAMETOWORD, 0, 268, &gtDataTables_0096BC30.pSkillsLinker },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    gtDataTables_0096BC30.pMonStats2Linker = FOG_AllocLinker(gszMonsterTblsSourceFile, 2705);
    return gtDataTables_0096BC30.pMonStats2Txt = (D2MonStats2Txt*)DATATBLS_CompileTxt(hArchive, gszMonStats2TxtName, pTbl, &gtDataTables_0096BC30.nMonStats2TxtRecordCount, 308);
}

D2TxtLinkStrc* gTxtLink_0096C85C; // 0x0096C85C

// 0x00658720
void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 18, 0, 0, &gTxtLink_0096C85C },
        { "prop1", 19, 0, 4, &gTxtLink_0096BCD8 },
        { "par1", 2, 0, 8, 0 },
        { "chance1", 4, 0, 292, 0 },
        { "min1", 2, 0, 12, 0 },
        { "max1", 2, 0, 16, 0 },
        { "prop2", 19, 0, 20, &gTxtLink_0096BCD8 },
        { "chance2", 4, 0, 293, 0 },
        { "par2", 2, 0, 24, 0 },
        { "min2", 2, 0, 28, 0 },
        { "max2", 2, 0, 32, 0 },
        { "prop3", 19, 0, 36, &gTxtLink_0096BCD8 },
        { "chance3", 4, 0, 294, 0 },
        { "par3", 2, 0, 40, 0 },
        { "min3", 2, 0, 44, 0 },
        { "max3", 2, 0, 48, 0 },
        { "prop4", 19, 0, 52, &gTxtLink_0096BCD8 },
        { "chance4", 4, 0, 295, 0 },
        { "par4", 2, 0, 56, 0 },
        { "min4", 2, 0, 60, 0 },
        { "max4", 2, 0, 64, 0 },
        { "prop5", 19, 0, 68, &gTxtLink_0096BCD8 },
        { "chance5", 4, 0, 296, 0 },
        { "par5", 2, 0, 72, 0 },
        { "min5", 2, 0, 76, 0 },
        { "max5", 2, 0, 80, 0 },
        { "prop6", 19, 0, 84, &gTxtLink_0096BCD8 },
        { "chance6", 4, 0, 297, 0 },
        { "par6", 2, 0, 88, 0 },
        { "min6", 2, 0, 92, 0 },
        { "max6", 2, 0, 96, 0 },
        { "prop1 (N)", 19, 0, 100, &gTxtLink_0096BCD8 },
        { "chance1 (N)", 4, 0, 298, 0 },
        { "par1 (N)", 2, 0, 104, 0 },
        { "min1 (N)", 2, 0, 108, 0 },
        { "max1 (N)", 2, 0, 112, 0 },
        { "prop2 (N)", 19, 0, 116, &gTxtLink_0096BCD8 },
        { "chance2 (N)", 4, 0, 299, 0 },
        { "par2 (N)", 2, 0, 120, 0 },
        { "min2 (N)", 2, 0, 124, 0 },
        { "max2 (N)", 2, 0, 128, 0 },
        { "prop3 (N)", 19, 0, 132, &gTxtLink_0096BCD8 },
        { "chance3 (N)", 4, 0, 300, 0 },
        { "par3 (N)", 2, 0, 136, 0 },
        { "min3 (N)", 2, 0, 140, 0 },
        { "max3 (N)", 2, 0, 144, 0 },
        { "prop4 (N)", 19, 0, 148, &gTxtLink_0096BCD8 },
        { "chance4 (N)", 4, 0, 301, 0 },
        { "par4 (N)", 2, 0, 152, 0 },
        { "min4 (N)", 2, 0, 156, 0 },
        { "max4 (N)", 2, 0, 160, 0 },
        { "prop5 (N)", 19, 0, 164, &gTxtLink_0096BCD8 },
        { "chance5 (N)", 4, 0, 302, 0 },
        { "par5 (N)", 2, 0, 168, 0 },
        { "min5 (N)", 2, 0, 172, 0 },
        { "max5 (N)", 2, 0, 176, 0 },
        { "prop6 (N)", 19, 0, 180, &gTxtLink_0096BCD8 },
        { "chance6 (N)", 4, 0, 303, 0 },
        { "par6 (N)", 2, 0, 184, 0 },
        { "min6 (N)", 2, 0, 188, 0 },
        { "max6 (N)", 2, 0, 192, 0 },
        { "prop1 (H)", 19, 0, 196, &gTxtLink_0096BCD8 },
        { "chance1 (H)", 4, 0, 304, 0 },
        { "par1 (H)", 2, 0, 200, 0 },
        { "min1 (H)", 2, 0, 204, 0 },
        { "max1 (H)", 2, 0, 208, 0 },
        { "prop2 (H)", 19, 0, 212, &gTxtLink_0096BCD8 },
        { "chance2 (H)", 4, 0, 305, 0 },
        { "par2 (H)", 2, 0, 216, 0 },
        { "min2 (H)", 2, 0, 220, 0 },
        { "max2 (H)", 2, 0, 224, 0 },
        { "prop3 (H)", 19, 0, 228, &gTxtLink_0096BCD8 },
        { "chance3 (H)", 4, 0, 306, 0 },
        { "par3 (H)", 2, 0, 232, 0 },
        { "min3 (H)", 2, 0, 236, 0 },
        { "max3 (H)", 2, 0, 240, 0 },
        { "prop4 (H)", 19, 0, 244, &gTxtLink_0096BCD8 },
        { "chance4 (H)", 4, 0, 307, 0 },
        { "par4 (H)", 2, 0, 248, 0 },
        { "min4 (H)", 2, 0, 252, 0 },
        { "max4 (H)", 2, 0, 256, 0 },
        { "prop5 (H)", 19, 0, 260, &gTxtLink_0096BCD8 },
        { "chance5 (H)", 4, 0, 308, 0 },
        { "par5 (H)", 2, 0, 264, 0 },
        { "min5 (H)", 2, 0, 268, 0 },
        { "max5 (H)", 2, 0, 272, 0 },
        { "prop6 (H)", 19, 0, 276, &gTxtLink_0096BCD8 },
        { "chance6 (H)", 4, 0, 309, 0 },
        { "par6 (H)", 2, 0, 280, 0 },
        { "min6 (H)", 2, 0, 284, 0 },
        { "max6 (H)", 2, 0, 288, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C85C = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2953);
    gpMonpropTxt = DATATBLS_CompileTxt(hArchive, "monprop", pTbl, &gnMonpropTxtRecordCount, 312);
}

// 0x00659500
void __fastcall DATATBLS_LoadMonLvlTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "AC", 2, 0, 0, 0 },
        { "AC(N)", 2, 0, 4, 0 },
        { "AC(H)", 2, 0, 8, 0 },
        { "TH", 2, 0, 24, 0 },
        { "TH(N)", 2, 0, 28, 0 },
        { "TH(H)", 2, 0, 32, 0 },
        { "HP", 2, 0, 48, 0 },
        { "HP(N)", 2, 0, 52, 0 },
        { "HP(H)", 2, 0, 56, 0 },
        { "DM", 2, 0, 72, 0 },
        { "DM(N)", 2, 0, 76, 0 },
        { "DM(H)", 2, 0, 80, 0 },
        { "XP", 2, 0, 96, 0 },
        { "XP(N)", 2, 0, 100, 0 },
        { "XP(H)", 2, 0, 104, 0 },
        { "L-AC", 2, 0, 12, 0 },
        { "L-AC(N)", 2, 0, 16, 0 },
        { "L-AC(H)", 2, 0, 20, 0 },
        { "L-TH", 2, 0, 36, 0 },
        { "L-TH(N)", 2, 0, 40, 0 },
        { "L-TH(H)", 2, 0, 44, 0 },
        { "L-HP", 2, 0, 60, 0 },
        { "L-HP(N)", 2, 0, 64, 0 },
        { "L-HP(H)", 2, 0, 68, 0 },
        { "L-DM", 2, 0, 84, 0 },
        { "L-DM(N)", 2, 0, 88, 0 },
        { "L-DM(H)", 2, 0, 92, 0 },
        { "L-XP", 2, 0, 108, 0 },
        { "L-XP(N)", 2, 0, 112, 0 },
        { "L-XP(H)", 2, 0, 116, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonlvlTxt = DATATBLS_CompileTxt(hArchive, "monlvl", pTbl, &gnMonlvlTxtRecordCount, 120);
}

D2MonPresetTxt* gpMonPresetTxt; // 0x0096C6D8

// 0x00659A10
void __fastcall DATATBLS_LoadMonPresetTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Act", 4, 0, 0, 0 },
        { "Place", 0x17, 0, 0, (void*)DATATBLS_MonPresetPlaceLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    int nRecordCount = 0;

    D2MonPresetTxt* pMonPresetTxt = (D2MonPresetTxt*)DATATBLS_CompileTxt(hArchive, "monpreset", pTbl, &nRecordCount, sizeof(D2MonPresetTxt));

    gpMonPresetTxt = pMonPresetTxt;
    D2MonPresetTxt* pRecord = pMonPresetTxt;
    gpMonPresetTxtActSections[0] = pMonPresetTxt;

    int nAct = 0;
    int nActRecords = 0;
    for (int i = 0; i < nRecordCount; ++i, ++pRecord)
    {
        while (pRecord->nAct > nAct + 1)
        {
            gnMonPresetTxtActRecordCounts[nAct] = nActRecords;
            ++nAct;
            nActRecords = 0;
            gpMonPresetTxtActSections[nAct] = pRecord;
        }

        ++nActRecords;
    }

    gnMonPresetTxtActRecordCounts[nAct] = nActRecords;
}

void* gpSoundsTxt; // 0x0096BDC4

int gnSoundsTxtRecordCount; // 0x0096BDCC

// 0x00659BB0
void __fastcall DATATBLS_LoadSoundsTxt(void* hArchive)
{
    if (gnSoundsGuard)
    {
        D2BinFieldStrc pTbl[] =
        {
            { "Sound", 17, 0, 0, &gTxtLink_0096BDC8 },
            { gszTxtField_end, 0, 0, 0, 0 },
        };

        gTxtLink_0096BDC8 = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 3225);
        gpSoundsTxt = DATATBLS_CompileTxt(hArchive, "sounds", pTbl, &gnSoundsTxtRecordCount, 2);
    }
}

D2TxtLinkStrc* gTxtLink_0096C7AC; // 0x0096C7AC

D2AnimSeqTxt* gpMonseqTxt; // 0x0096C7A8

int gnMonseqTxtRecordCount; // 0x0096C7B0

D2AnimSeqRecordStrc* gpMonSeqTable; // 0x0096C7B4

int gnMonSeqTableRecordCount; // 0x0096C7B8

// 0x00659C60
void __fastcall DATATBLS_LoadMonSeqTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "sequence", 17, 0, 0, &gTxtLink_0096C7AC },
        { "mode", 13, 0, 2, &gTxtLink_0096BC5C },
        { "frame", 4, 0, 3, 0 },
        { "dir", 4, 0, 4, 0 },
        { "event", 4, 0, 5, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C7AC = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 3267);
    gpMonseqTxt = (D2AnimSeqTxt*)DATATBLS_CompileTxt(hArchive, "monseq", pTbl, &gnMonseqTxtRecordCount, 6);

    if (gnMonseqTxtRecordCount > 0)
    {
        gnMonSeqTableRecordCount = gpMonseqTxt[gnMonseqTxtRecordCount - 1].wSequence + 1;
        gpMonSeqTable = (D2AnimSeqRecordStrc*)FOG_AllocPool(0, sizeof(D2AnimSeqRecordStrc) * gnMonSeqTableRecordCount, ".\\DATATBLS\\MonsterTbls.cpp", 3276, 0);
        memset(gpMonSeqTable, 0, sizeof(D2AnimSeqRecordStrc) * gnMonSeqTableRecordCount);

        for (int i = 0; i < gnMonseqTxtRecordCount; ++i)
        {
            int nSequence = gpMonseqTxt[i].wSequence;
            if (!gpMonSeqTable[nSequence].pAnimSeqTxtRecord)
            {
                gpMonSeqTable[nSequence].pAnimSeqTxtRecord = &gpMonseqTxt[i];
            }

            ++gpMonSeqTable[nSequence].nSeqFramesCount;
            ++gpMonSeqTable[nSequence].nFramesCount;
        }
    }
}

// 0x0065A190
void __fastcall DATATBLS_UnloadSomeMonsterTxts()
{
    if (gpMonTable_96C810)
    {
        DATATBLS_UnloadBin(gpMonTable_96C810);
        gnMonTable_96C814 = 0;
    }

    DATATBLS_UnloadBin(gpNpcTxt);

    sub_006562B0();
    sub_00659AF0();

    if (gpSuperUniquesLinker)
    {
        FOG_FreeLinker(gpSuperUniquesLinker);
    }
    if (gpSuperUniquesTxt)
    {
        DATATBLS_UnloadBin(gpSuperUniquesTxt);
        gpSuperUniquesTxt = 0;
    }
    gnSuperUniquesTxtRecordCount = 0;

    if (gTxtLink_0096C87C)
    {
        FOG_FreeLinker(gTxtLink_0096C87C);
        gTxtLink_0096C87C = 0;
    }
    if (gpMonumodTxt)
    {
        DATATBLS_UnloadBin(gpMonumodTxt);
        gpMonumodTxt = 0;
    }
    gnMonumodTxtRecordCount = 0;

    if (gpMonstatsTxt)
    {
        DATATBLS_UnloadBin(gpMonstatsTxt);
        FOG_FreeLinker(gTxtLink_0096C6AC);
    }
    gpMonstatsTxt = 0;

    if (gpMonTypeTxt)
    {
        DATATBLS_UnloadBin(gpMonTypeTxt);
        FOG_FreeLinker(gTxtLink_0096C6C4);
    }

    if (gpMonpropTxt)
    {
        DATATBLS_UnloadBin(gpMonpropTxt);
        FOG_FreeLinker(gTxtLink_0096C85C);
    }
    gnMonpropTxtRecordCount = 0;

    if (gpMonsoundsTxt)
    {
        DATATBLS_UnloadBin(gpMonsoundsTxt);
        FOG_FreeLinker(gTxtLink_0096C6B8);
        gnMonsoundsTxtRecordCount = 0;
    }

    sub_00659DE0();
    sub_00654D50();

    if (gpMonlvlTxt)
    {
        DATATBLS_UnloadBin(gpMonlvlTxt);
        gnMonlvlTxtRecordCount = 0;
    }

    sub_00653E20();
}
