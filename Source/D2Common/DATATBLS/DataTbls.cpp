#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
struct D2SkillListStrc;
struct D2InventoryStrc;
struct D2PropertyStrc;
struct D2BinFieldStrc;
struct D2BinFileStrc;
struct D2StatesTxt;
struct D2ExperienceTxt;
struct D2ExperienceDataTbl;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2DifficultyLevelsTxt;
struct D2ObjectsTxt;
struct D2RunesTxt;
struct D2RuneDataTbl;
struct PlayerRecord;
struct MonsterRecord;
struct ItemRecord;
struct ObjectRecord;
struct DataTables;
struct UnitHeader;

struct D2StatesTxt
{
    unsigned short wState;
    char unk0x02[0xE];
    unsigned char nStateFlags[8];
    char unk0x18[0x24];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText); // 0x00524D30
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
extern "C" const char gszFileModeWb_006D69E0[]; // 0x006D69E0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2StatesTxt* gpStatesTxt; // 0x0096BCEC

struct D2ExperienceTxt
{
    unsigned int dwClass[7];
    unsigned int dwExpRatio;
};

struct D2ExperienceDataTbl
{
    D2ExperienceTxt tMax;
    D2ExperienceTxt aLevels[1];
};

extern D2ExperienceDataTbl* gpExperienceTxt; // 0x0096C8A8
extern char* gpSkillsCode_0096BC70; // 0x0096BC70
extern int gnSkillsCodeSize_0096BC74; // 0x0096BC74
extern int gnSkillsCodeSizeEx_0096BC78; // 0x0096BC78
extern char* gpSkillDescCode_0096BC7C; // 0x0096BC7C
extern int gnSkillDescCodeSize_0096BC80; // 0x0096BC80
extern int gnSkillDescCodeSizeEx_0096BC84; // 0x0096BC84
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0
int __fastcall DATATBLS_MapSkillsTxtKeywordToNumber(char* szKey); // 0x00611930
int __fastcall sub_006119E0_SkillsCalcParamCount(int nValue); // 0x006119E0
int __fastcall sub_006119F0_SkillsCalcLinkParse(char* szText, int* a2, int a3, int nKeywordNumber); // 0x006119F0
int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__fastcall* pfnGetParameterCount)(int), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0
extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC
extern D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798
extern D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130



struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
};



struct D2DataTablesStrc
{
    void* pPlayerClassTxt;
    D2TxtLinkStrc* pPlayerClassLinker;
    void* pBodyLocsTxt;
    D2TxtLinkStrc* pBodyLocsLinker;
    void* pStorePageTxt;
    D2TxtLinkStrc* pStorePageLinker;
    void* pElemTypesTxt;
    D2TxtLinkStrc* pElemTypesLinker;
    void* pHitClassTxt;
    D2TxtLinkStrc* pHitClassLinker;
    void* pMonModeTxtStub;
    D2TxtLinkStrc* pMonModeLinker;
    void* pPlrModeTxtStub;
    D2TxtLinkStrc* pPlrModeLinker;
    void* pSkillCalcTxt;
    D2TxtLinkStrc* pSkillCalcLinker;
    char unk0x040[0x018];
    void* pMissileCalcTxt;
    D2TxtLinkStrc* pMissileCalcLinker;
    char unk0x060[0x00C];
    void* pSkillCode;
    D2TxtLinkStrc* iSkillCode;
    void* pEventsTxt;
    D2TxtLinkStrc* pEventsLinker;
    void* pCompCodeTxt;
    D2TxtLinkStrc* pCompCodeLinker;
    int nCompCodeTxtRecordCount;
    void* pMonAiTxt;
    D2TxtLinkStrc* pMonAiLinker;
    int nMonAiTxtRecordCount;
    char unk0x094[0x020];
    void* pHireDescTxt;
    D2TxtLinkStrc* pHireDescLinker;
    D2StatesTxt* pStatesTxt;
    D2TxtLinkStrc* pStatesLinker;
    int nStatesTxtRecordCount;
    unsigned int* pStateMasks;
    unsigned int* fStateMasks[40];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x172[0x002];
    short* pCurseStates;
    short nCurseStates;
    char unk0x17A[0x002];
    short* pTransformStates;
    short nTransformStates;
    char unk0x182[0x002];
    short* pActionStates;
    short nActionStates;
    char unk0x18A[0x002];
    short* pColourStates;
    short nColourStates;
    char unk0x192[0x002];
    char unk0x194[0x004];
    D2TxtLinkStrc* pSoundsLinker;
    unsigned char unk_19C[0x814];
    void* pColorsTxt;
    D2TxtLinkStrc* pColorsLinker;
    char unk0x9B8[0x0E4];
    void* pMonPlaceTxt;
    D2TxtLinkStrc* pMonPlaceLinker;
    int nMonPlaceTxtRecordCount;
    unsigned char unk_AA8[0xC0];
    D2TxtLinkStrc* pMissilesLinker;
    unsigned char unk_B6C[0x2C];
    D2SkillsTxt* pSkillsTxt;
    unsigned char unk_B9C[0x4];
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x14];
    D2TxtLinkStrc* pOverlayLinker;
    char unk0xBBC[0x014];
    D2TxtLinkStrc* pItemStatCostLinker;
    char unk0xBD4[0x020];
    D2TxtLinkStrc* pItemTypesLinker;
    unsigned char unk_BF8[0x7C];
    void* pAnimData;
    char unk0xC78[0x00C];
    int bCompileTxt;
};

struct D2DifficultyLevelsTxt
{
    char unk0x00[0x58];
};


struct D2RunesTxt
{
    char unk0x000[0x120];
};

struct D2RuneDataTbl
{
    int nRunesTxtRecordCount;
    D2RunesTxt* pRunesTxt;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gnDifficultylevelsTxtRecordCount; // 0x0096C8B0
extern D2ObjectsTxt* gpObjectsTxt; // 0x0096D470
unsigned int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625350
int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625420
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2ActiveRoomStrc* __stdcall PATH_GetRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648A80
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9); // 0x0064F5B0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem); // 0x0065E4D0
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
void* __fastcall sub_00612280_ReadExcelFile(void* hArchive, const char* szName, const char* szExtension, int* pSize, const char* szFile, int nLine); // 0x00612280
extern "C" const char szBinExtension_006DCC68[]; // 0x006DCC68
extern int gbCompileTxt; // 0x0096C8B4
extern D2TxtLinkStrc* gpStatesLinker_0096BCF0; // 0x0096BCF0
extern int gnStatesTxtRecordCount; // 0x0096BCF4
extern void* gpSkillDescTxt_0096C7BC; // 0x0096C7BC
extern D2TxtLinkStrc* gpSkillDescLinker_0096C7C0; // 0x0096C7C0
extern int gnSkillDescTxtRecordCount_0096C7C4; // 0x0096C7C4
extern void* gpSkillsTxt_0096C7C8; // 0x0096C7C8
extern int gnSkillsTxtRecordCount_0096C7D0; // 0x0096C7D0
extern short* gpClassSkillCount_0096C7D4; // 0x0096C7D4
extern int gnHighestClassSkillCount_0096C7D8; // 0x0096C7D8
extern short* gpClassSkillList_0096C7DC; // 0x0096C7DC
extern int gnPassiveSkills_0096C7E0; // 0x0096C7E0
extern short* gpPassiveSkills_0096C7E4; // 0x0096C7E4

typedef unsigned short Unicode;

struct PlayerRecord
{
    char pad0[32];
    char name[164];
};

struct MonsterRecord
{
    char pad0[6];
    unsigned short nameIndex;
    char padTail[416];
};

struct ItemRecord
{
    char pad0[244];
    unsigned short nameIndex;
};

struct ObjectRecord
{
    char name[1];
};

struct DataTables
{
    char pad0[2680];
    MonsterRecord* monsters;
    char padMonsterCount[4];
    int monsterCount;
    char padPlayers[320];
    PlayerRecord* players;
    int playerCount;
};

struct UnitHeader
{
    unsigned int type;
    int classId;
};

extern DataTables* gVar_00744304; // 0x00744304
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int); // 0x00687330
extern "C" int __cdecl _snprintf(char*, unsigned int, const char*, ...); // 0x006831DB
extern "C" char* __cdecl sub_006883F8_Copy(char*, const char*); // 0x006883F8
const Unicode* __fastcall sub_00524A30_String(unsigned short); // 0x00524A30
char* __fastcall sub_00526F70_Narrow(char*, const Unicode*, int); // 0x00526F70
ObjectRecord* __stdcall sub_00640E90_Object(int); // 0x00640E90
ItemRecord* __stdcall sub_006335F0_Item(int); // 0x006335F0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __stdcall DATATBLS_WriteBinFile(char* szFileName, void* pWriteBuffer, unsigned int nBufferSize, int nRecordCount); // 0x006121F0
D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize); // 0x006BD640
int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780
void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0
extern "C" const char gszHitclassTxtName[]; // 0x006DCF50
extern D2DataTablesStrc gD2DataTables; // 0x0096BC30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void __fastcall DATATBLS_LoadItemTypesTxt(void* hArchive); // 0x00638D80
void __fastcall DATATBLS_LoadMonTypeTxt(void* hArchive); // 0x00658520
void __fastcall DATATBLS_LoadSoundsTxt(void* hArchive); // 0x00659BB0
void __fastcall DATATBLS_LoadPetTypeTxt(void* hArchive); // 0x00618D90
void __fastcall DATATBLS_LoadOverlayTxt(void* hArchive); // 0x00664150
void __fastcall DATATBLS_LoadItemStatCostTxt(void* hArchive); // 0x00637A00
void __fastcall DATATBLS_LoadPropertiesTxt(void* hArchive); // 0x00638630
void __fastcall DATATBLS_LoadMissilesTxt(void* hArchive); // 0x00661B20
void __fastcall DATATBLS_LoadStatesTxt(void* hArchive); // 0x00618100
void __stdcall DATATBLS_LoadSkills_SkillDescTxt(void* hArchive); // 0x00613F80
void __stdcall DATATBLS_LoadCharStatsTxt(void* hArchive); // 0x00613260
void __fastcall DATATBLS_LoadArenaTxt(void* hArchive); // 0x006649B0
void __fastcall DATATBLS_LoadCharTemplateTxt(void* hArchive); // 0x00664B80
void __fastcall DATATBLS_LoadItemsTxt(void* hArchive); // 0x006315D0
void __fastcall DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(void* hArchive); // 0x00633730
void __fastcall DATATBLS_LoadRareSuffix_PrefixTxt(void* hArchive); // 0x00633F40
void __fastcall DATATBLS_LoadUniqueItemsTxt(void* hArchive); // 0x006342B0
void __fastcall DATATBLS_LoadSets_SetItemsTxt(void* hArchive); // 0x00634DC0
void __fastcall DATATBLS_LoadGemsTxt(void* hArchive); // 0x00636B70
void __fastcall DATATBLS_LoadBooksTxt(void* hArchive); // 0x00637320
void __fastcall DATATBLS_LoadQualityItemsTxt(void* hArchive); // 0x00636770
void __fastcall DATATBLS_LoadLowQualityItemsTxt(void* hArchive); // 0x00637500
void __fastcall DATATBLS_LoadRunesTxt(void* hArchive); // 0x006394A0
void __fastcall DATATBLS_LoadItemRatioTxt(void* hArchive); // 0x00637620
void __fastcall DATATBLS_LoadGambleTxt(void* hArchive); // 0x00638AE0
void __fastcall DATATBLS_LoadPlrType_ModeTxt(void* hArchive); // 0x0065ADC0
void __fastcall DATATBLS_LoadMonModeTxt(void* hArchive); // 0x0065AEF0
void __fastcall DATATBLS_LoadObjType_ModeTxt(void* hArchive); // 0x0065B1B0
void __fastcall DATATBLS_LoadCompositTxt(void* hArchive); // 0x0065B2E0
void __fastcall DATATBLS_LoadArmTypeTxt(void* hArchive); // 0x0065B350
void __stdcall sub_00613D30(void* hArchive); // 0x00613D30
void* __fastcall DATATBLS_LoadAnimDataD2(void* hArchive); // 0x0066A770
void __fastcall DATATBLS_LoadSomeMonsterTxts(void* hArchive); // 0x0065A400
void __fastcall DATATBLS_LoadLevelsTxt(void* hArchive); // 0x0061C540
void __fastcall DATATBLS_LoadLevelDefsBin(void* hArchive); // 0x0061DE00
void __fastcall sub_0061E520(void* hArchive); // 0x0061E520
void __fastcall DATATBLS_AllocGlobalTileLibraryHash(void* hArchive); // 0x0061FAE0
void __fastcall DATATBLS_LoadLvlWarpTxt(void* hArchive); // 0x0061F130
void __fastcall DATATBLS_LoadLvlMazeTxt(void* hArchive); // 0x0061F380
void __fastcall DATATBLS_LoadAutomapTxt(void* hArchive); // 0x0061FCF0
void __fastcall DATATBLS_LoadObjectsTxt(void* hArchive); // 0x0063F690
void __fastcall DATATBLS_LoadObjGroupTxt(void* hArchive); // 0x00640F20
void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive); // 0x00641320
void __fastcall DATATBLS_LoadInventoryTxt(void* hArchive); // 0x0065B660
int __fastcall DATATBLS_LoadExpFieldD2(void* hArchive); // 0x0066A700
void __fastcall DATATBLS_LoadBeltsTxt(void* hArchive); // 0x00660290
void __fastcall DATATBLS_LoadMonItemPercentTxt(void* hArchive); // 0x00654F20
void __fastcall sub_0066A270(void* hArchive); // 0x0066A270
void __fastcall DATATBLS_LoadCubeMainTxt(void* hArchive); // 0x00669130
void __stdcall DATATBLS_LoadDifficultyLevelsTxt(void* hArchive); // 0x00617D90
void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles); // 0x0061EBB0
void __fastcall DATATBLS_LoadLvlSubTxt(void* hArchive, int a2, int a3); // 0x0061F500
void __fastcall sub_00659C30(); // 0x00659C30
extern D2TxtLinkStrc* gpCompCodeLinker_0096BCB0; // 0x0096BCB0
extern D2TxtLinkStrc* gpPlayerClassLinker_0096BC34; // 0x0096BC34
extern D2TxtLinkStrc* gpElemTypesLinker_0096BC4C; // 0x0096BC4C
extern D2TxtLinkStrc* gpHitClassLinker_0096BC54; // 0x0096BC54
extern D2TxtLinkStrc* gpHireDescLinker_0096BCE8; // 0x0096BCE8
extern D2TxtLinkStrc* gpPlrModeLinker_0096BC64; // 0x0096BC64
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C
extern D2TxtLinkStrc* gpEventsLinker_0096BCA8; // 0x0096BCA8
extern "C" const char gszTxtField_int[]; // 0x006E67EC
void __fastcall sub_006117B0(); // 0x006117B0
extern D2TxtLinkStrc* gpBodyLocsLinker_0096BC3C; // 0x0096BC3C
void __fastcall sub_00612600(void* pTable, int nRecordCount, int nRecordSize, int nNameOffset, int a5, int nNameLength); // 0x00612600

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETOINDEX = 17,
    TXTFIELD_NAMETOWORD = 20,
    TXTFIELD_BIT = 26,
};

extern "C" const char gszTxtField_exp[]; // 0x006E7B3C
void __fastcall sub_00611D60_BuildStateMask(unsigned int* pMask, int nFlag); // 0x00611D60
void __fastcall sub_00611DC0_BuildStateListByFlag(short** ppList, short* pnCount, int nFlag); // 0x00611DC0
void __fastcall sub_00611E60_BuildStateListByField(short** ppList, short* pnCount, int nFieldOffset); // 0x00611E60

int gnStatesTxtRecordCount; // 0x0096BCF4

// 0x006117B0
unsigned short __fastcall DATATBLS_GetStringIdFromReferenceString(char* szReference)
{
    const wchar_t* pUnicode;
    unsigned short nIndex = sub_00524D30_FindString(szReference, &pUnicode);
    if (!nIndex)
        nIndex = 5382;
    return nIndex;
}

// 0x006118B0
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize)
{
    while (*pSize + nBufferSize >= *pSizeEx)
    {
        *pSizeEx += 1024;
        if (*pSizeEx >= 0x7FFFFFFF)
            return 0;
        *ppCodes = (char*)FOG_ReallocPool(0, *ppCodes, *pSizeEx, ".\\DATATBLS\\DataTbls.cpp", 658, 0);
    }
    int nResult = *pSize;
    memcpy(*ppCodes + nResult, pBuffer, nBufferSize);
    *pSize += nBufferSize;
    return nResult;
}

// 0x00611DC0
void __fastcall sub_00611DC0_BuildStateListByFlag(short** ppList, short* pnCount, int nFlag)
{
    *ppList = (short*)FOG_AllocPool(0, sizeof(short) * gnStatesTxtRecordCount, ".\\DATATBLS\\DataTbls.cpp", 1611, 0);
    memset(*ppList, 0, sizeof(short) * gnStatesTxtRecordCount);
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    *pnCount = 0;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (pStatesTxt[i].nStateFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7])
        {
            (*ppList)[*pnCount] = i;
            ++*pnCount;
        }
    }
}

// 0x00611E60
void __fastcall sub_00611E60_BuildStateListByField(short** ppList, short* pnCount, int nFieldOffset)
{
    *ppList = (short*)FOG_AllocPool(0, sizeof(short) * gnStatesTxtRecordCount, ".\\DATATBLS\\DataTbls.cpp", 1634, 0);
    memset(*ppList, 0, sizeof(short) * gnStatesTxtRecordCount);
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    *pnCount = 0;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (*(short*)((char*)&pStatesTxt[i] + nFieldOffset) > 0)
        {
            (*ppList)[*pnCount] = i;
            ++*pnCount;
        }
    }
}

// 0x006121F0
void __stdcall DATATBLS_WriteBinFile(char* szFileName, void* pWriteBuffer, unsigned int nBufferSize, int nRecordCount)
{
    char szFilePath[260];
    wsprintfA(szFilePath, gszPathFormat_006D4124, gszExcelDirectory_006D8ED4, szFileName);
    _iobuf* pFile = fopen(szFilePath, gszFileModeWb_006D69E0);
    if (pFile)
    {
        fwrite(&nRecordCount, sizeof(nRecordCount), 1, pFile);
        fwrite(pWriteBuffer, nBufferSize, 1, pFile);
        fclose(pFile);
    }
}

static int DATATBLS_GetMaxLevelFromTable(D2ExperienceDataTbl* pExperienceTxt, int nClass)
{
    if (nClass < 0 || nClass >= 7)
    {
        nClass = 0;
    }

    return pExperienceTxt->tMax.dwClass[nClass];
}

// 0x00611860
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience)
{
    if (nClass < 0 || nClass >= 7)
    {
        nClass = 0;
    }

    D2ExperienceDataTbl* pExperienceTxt = gpExperienceTxt;
    int nMaxLevel = DATATBLS_GetMaxLevelFromTable(pExperienceTxt, nClass);
    int nLevel = 0;
    while (dwExperience >= pExperienceTxt->aLevels[nLevel].dwClass[nClass] && nLevel < nMaxLevel)
    {
        ++nLevel;
    }

    return nLevel;
}

// 0x00611BD0
void __fastcall DATATBLS_SkillCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char pBuffer[1024];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapSkillsTxtKeywordToNumber, sub_006119E0_SkillsCalcParamCount, sub_006119F0_SkillsCalcLinkParse);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpSkillsCode_0096BC70, &gnSkillsCodeSize_0096BC74, &gnSkillsCodeSizeEx_0096BC78, pBuffer, nBufferSize);
}

// 0x00611C70
void __fastcall DATATBLS_SkillDescCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char pBuffer[1024];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapSkillsTxtKeywordToNumber, sub_006119E0_SkillsCalcParamCount, sub_006119F0_SkillsCalcLinkParse);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpSkillDescCode_0096BC7C, &gnSkillDescCodeSize_0096BC80, &gnSkillDescCodeSizeEx_0096BC84, pBuffer, nBufferSize);
}

// 0x00611930
int __fastcall DATATBLS_MapSkillsTxtKeywordToNumber(char* szKey)
{
    if (0 == SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (0 == SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (0 == SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (0 == SStrCmpI(szKey, "skill", 32))
    {
        return 3;
    }
    else if (0 == SStrCmpI(szKey, "miss", 32))
    {
        return 4;
    }
    else if (0 == SStrCmpI(szKey, "stat", 32))
    {
        return 5;
    }
    else if (0 == SStrCmpI(szKey, "sklvl", 32))
    {
        return 6;
    }
    else
    {
        return -1;
    }
}

// 0x006119E0
int __fastcall sub_006119E0_SkillsCalcParamCount(int nValue)
{
    return (nValue == 6) + 2;
}

D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C

// 0x00611760
static void sub_00611760_MakeCalcCode(const char* szText, char* szCode)
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

// 0x006119F0
int __fastcall sub_006119F0_SkillsCalcParamCallback(char* szText, int* pResult, int nType, int nKeywordNumber)
{
    char szCode[4];
    if (nType == 1)
    {
        switch (nKeywordNumber)
        {
        case 3:
        {
            if (gpSkillsLinker_0096C7CC)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            sub_00611760_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        case 4:
        {
            if (gpMissilesLinker_0096C798)
            {
                const int nRow = FOG_GetRowFromTxt(gpMissilesLinker_0096C798, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            sub_00611760_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpMissileCalcLinker_0096BC8C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        case 5:
        {
            if (gpItemStatCostLinker)
            {
                const int nRow = FOG_GetRowFromTxt(gpItemStatCostLinker, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            if (!SStrCmpI(szText, "base", 32))
            {
                *pResult = 0;
                return 1;
            }
            if (!SStrCmpI(szText, "mod", 32))
            {
                *pResult = 0;
                return 2;
            }
            SStrCmpI(szText, "accr", 32);
            *pResult = 0;
            return 0;
        }
        case 6:
        {
            if (gpSkillsLinker_0096C7CC)
            {
                const int nRow = FOG_GetRowFromTxt(gpSkillsLinker_0096C7CC, szText, 0);
                if (nRow >= 0)
                {
                    *pResult = 1;
                    return nRow;
                }
            }
            sub_00611760_MakeCalcCode(szText, szCode);
            const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
            *pResult = 0;
            return nIndex;
        }
        }
    }
    sub_00611760_MakeCalcCode(szText, szCode);
    const int nIndex = FOG_GetLinkIndex(gpSkillCalcLinker_0096BC6C, *(unsigned int*)szCode, 1);
    *pResult = 0;
    return nIndex;
}

D2DifficultyLevelsTxt* gpDifficultylevelsTxt; // 0x0096C8AC

D2RuneDataTbl gRuneDataTables; // 0x0096CA98

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00611D30
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty)
{
    nDifficulty = nDifficulty > 0 ? nDifficulty : 0;
    if (nDifficulty >= gnDifficultylevelsTxtRecordCount - 1)
    {
        nDifficulty = gnDifficultylevelsTxtRecordCount - 1;
    }
    return &gpDifficultylevelsTxt[nDifficulty];
}

// 0x00620BB0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2198);

    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->pRoom;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetRoom(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00621780
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed)
{
    nSpeed = nSpeed > 0 ? nSpeed : 0;
    pUnit->wAnimSpeed = nSpeed < 0x7FFF ? nSpeed : 0x7FFF;
}

// 0x006219F0
D2SkillStrc* __stdcall UNITS_GetSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    D2_ASSERT(pSkillsTxtRecord, 3579);
    D2_ASSERT(pUnit, 1592);

    for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills); pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt == pSkillsTxtRecord)
        {
            return pSkill;
        }
    }
    return 0;
}

// 0x006254F0
int __stdcall sub_006254F0_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer);
}

// 0x00625500
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetTotalStatValue(pUnit->pStatListEx, nStatId, nLayer);
}

// 0x00625520
int __stdcall sub_00625520_GetStatBonus(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    if (!pStatList)
    {
        return 0;
    }

    return STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer) - sub_00625350(pStatList, nStatId, nLayer);
}

// 0x00625560
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit->pStatListEx)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    int nValue = STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer);
    return nValue - sub_00625350(pStatList, nStatId, nLayer);
}

// 0x00625A50
int __stdcall STATLIST_GetTotalStatValue_Layer0(D2StatListStrc* pStatListEx, int nStatId)
{
    return STATLIST_GetTotalStatValue(pStatListEx, nStatId, 0);
}

// 0x006260D0
void __stdcall STATLIST_SetSkillId(D2StatListStrc* pStatList, int nSkillId)
{
    pStatList->dwSkillNo = nSkillId;
}

// 0x006260F0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc* pStatList, int nSkillLevel)
{
    pStatList->dwSLvl = nSkillLevel;
}

// 0x00639CC0
void __stdcall DATATBLS_AddOrChangeRunesTxtRecord(int nRecordId, D2RunesTxt* pRecord)
{
    D2RunesTxt* pRunesTxt = 0;
    D2RunesTxt* pTmp = 0;
    int nSize = 0;

    if (gRuneDataTables.nRunesTxtRecordCount <= nRecordId)
    {
        pRunesTxt = gRuneDataTables.pRunesTxt;
        nSize = sizeof(D2RunesTxt) * (nRecordId + 1);

        if (DATATBLS_LoadFromBin)
        {
            pRunesTxt = (D2RunesTxt*)((char*)gRuneDataTables.pRunesTxt - 4);
            nSize += 4;
        }

        pTmp = (D2RunesTxt*)FOG_ReallocPool(0, pRunesTxt, nSize, ".\\DATATBLS\\ItemTbls.cpp", 2395, 0);

        if (DATATBLS_LoadFromBin)
        {
            *(int*)pTmp = nRecordId + 1;
            pTmp = (D2RunesTxt*)((char*)pTmp + 4);
        }
        gRuneDataTables.pRunesTxt = pTmp;

        memset(&pTmp[gRuneDataTables.nRunesTxtRecordCount], 0, sizeof(D2RunesTxt) * (nRecordId - gRuneDataTables.nRunesTxtRecordCount));
        gRuneDataTables.nRunesTxtRecordCount = nRecordId + 1;
    }

    gRuneDataTables.pRunesTxt[nRecordId] = *pRecord;
}

// 0x00640E90
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId)
{
    D2_ASSERT(nObjectId < gnObjectsTxtRecordCount, 221);
    D2_ASSERT(nObjectId >= 0, 222);
    return &gpObjectsTxt[nObjectId];
}

// 0x0064FA00
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* pUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int a5, D2InventoryStrc* pInventory, int nAnimMode)
{
    int nClass;
    int nType;
    int nMode;

    D2_ASSERT(pUnit, 262);

    nType = pUnit->dwUnitType;
    nClass = pUnit->dwClassId;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);

    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\COMPOSIT\\Composit.cpp", 268);

    if (nAnimMode == -1)
    {
        nAnimMode = nMode;
    }

    D2Common_10884_COMPOSIT_unk(pUnit, nClass, nAnimMode, nType, pInventory, szPath, pWeaponClassCode, bAddPathPrefix, a5);
}

// 0x0065FD20
int __fastcall ITEMMODS_PropertyFunc23(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (pProperty && pItem && pItem->dwUnitType == 4 && !ITEMS_IsEthereal(pItem) && ITEMS_HasDurability(pItem))
    {
        ITEMMODS_ApplyEthereality(pItem);
        return 1;
    }

    return 0;
}

D2StatesTxt* gpStatesTxt; // 0x0096BCEC

unsigned int* gpStateMasks_0096BCF8; // 0x0096BCF8

unsigned int* gfStateMasks_0096BCFC[40]; // 0x0096BCFC

short* gpProgressiveStates_0096BD9C; // 0x0096BD9C

short* gpCurseStates_0096BDA4; // 0x0096BDA4

short* gpTransformStates_0096BDAC; // 0x0096BDAC

short* gpActionStates_0096BDB4; // 0x0096BDB4

char* gpSkillsCode_0096BC70; // 0x0096BC70

char* gpSkillDescCode_0096BC7C; // 0x0096BC7C

static void DATATBLS_UnloadBinInline(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00611D60
void __fastcall sub_00611D60_BuildStateMask(unsigned int* pMask, int nFlag)
{
    D2StatesTxt* pStatesTxt = gpStatesTxt;
    for (int i = 0; i < gnStatesTxtRecordCount; ++i)
    {
        if (pStatesTxt[i].nStateFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7])
            pMask[i >> 5] |= gdwBitMasks[i & 0x1F];
    }
}

// 0x00613E90
void __fastcall DATATBLS_GetBinFileHandle(void* hArchive, const char* szFile, void** ppFileHandle, int* pSize, int* pSizeEx)
{
    int nSize;
    char szFilePath[0x104];
    if (gbCompileTxt && *ppFileHandle)
    {
        wsprintfA(szFilePath, "%s\\%s.bin", gszExcelDirectory_006D8ED4, szFile);
        _iobuf* pFile = fopen(szFilePath, gszFileModeWb_006D69E0);
        if (pFile)
        {
            fwrite(*ppFileHandle, *pSize, 1, pFile);
            fclose(pFile);
        }
        FOG_FreePool(0, *ppFileHandle, ".\\DATATBLS\\DataTbls.cpp", 0x275, 0);
    }
    *ppFileHandle = sub_00612280_ReadExcelFile(hArchive, szFile, szBinExtension_006DCC68, &nSize, ".\\DATATBLS\\DataTbls.cpp", 0x27A);
    *pSizeEx = nSize;
    *pSize = nSize;
}

// 0x00617C30
void __fastcall DATATBLS_UnloadSkills_SkillDescTxt()
{
    if (gpClassSkillCount_0096C7D4)
    {
        FOG_FreePool(0, gpClassSkillCount_0096C7D4, ".\\DATATBLS\\DataTbls.cpp", 0x5B8, 0);
        gpClassSkillCount_0096C7D4 = 0;
    }
    if (gpClassSkillList_0096C7DC)
    {
        FOG_FreePool(0, gpClassSkillList_0096C7DC, ".\\DATATBLS\\DataTbls.cpp", 0x5BE, 0);
        gpClassSkillList_0096C7DC = 0;
    }
    gnHighestClassSkillCount_0096C7D8 = 0;
    if (gpPassiveSkills_0096C7E4)
    {
        FOG_FreePool(0, gpPassiveSkills_0096C7E4, ".\\DATATBLS\\DataTbls.cpp", 0x5C5, 0);
        gpPassiveSkills_0096C7E4 = 0;
    }
    gnPassiveSkills_0096C7E0 = 0;
    if (gpSkillsCode_0096BC70)
    {
        FOG_FreePool(0, gpSkillsCode_0096BC70, ".\\DATATBLS\\DataTbls.cpp", 0x5CC, 0);
        gpSkillsCode_0096BC70 = 0;
    }
    gnSkillsCodeSize_0096BC74 = 0;
    gnSkillsCodeSizeEx_0096BC78 = 0;
    if (gpSkillDescCode_0096BC7C)
    {
        FOG_FreePool(0, gpSkillDescCode_0096BC7C, ".\\DATATBLS\\DataTbls.cpp", 0x5D4, 0);
        gpSkillDescCode_0096BC7C = 0;
    }
    gnSkillDescCodeSize_0096BC80 = 0;
    gnSkillDescCodeSizeEx_0096BC84 = 0;
    DATATBLS_UnloadBinInline(gpSkillsTxt_0096C7C8);
    FOG_FreeLinker(gpSkillsLinker_0096C7CC);
    gnSkillsTxtRecordCount_0096C7D0 = 0;
    DATATBLS_UnloadBinInline(gpSkillDescTxt_0096C7BC);
    FOG_FreeLinker(gpSkillDescLinker_0096C7C0);
    gnSkillDescTxtRecordCount_0096C7C4 = 0;
}

// 0x00618C90
void __fastcall DATATBLS_UnloadStatesTxt()
{
    if (gpStateMasks_0096BCF8)
    {
        FOG_FreePool(0, gpStateMasks_0096BCF8, ".\\DATATBLS\\DataTbls.cpp", 0x6E8, 0);
        gpStateMasks_0096BCF8 = 0;
    }
    if (gpProgressiveStates_0096BD9C)
    {
        FOG_FreePool(0, gpProgressiveStates_0096BD9C, ".\\DATATBLS\\DataTbls.cpp", 0x6ED, 0);
        gpProgressiveStates_0096BD9C = 0;
    }
    if (gpCurseStates_0096BDA4)
    {
        FOG_FreePool(0, gpCurseStates_0096BDA4, ".\\DATATBLS\\DataTbls.cpp", 0x6F2, 0);
        gpCurseStates_0096BDA4 = 0;
    }
    if (gpTransformStates_0096BDAC)
    {
        FOG_FreePool(0, gpTransformStates_0096BDAC, ".\\DATATBLS\\DataTbls.cpp", 0x6F7, 0);
        gpTransformStates_0096BDAC = 0;
    }
    if (gpActionStates_0096BDB4)
    {
        FOG_FreePool(0, gpActionStates_0096BDB4, ".\\DATATBLS\\DataTbls.cpp", 0x6FC, 0);
        gpActionStates_0096BDB4 = 0;
    }
    memset(gfStateMasks_0096BCFC, 0, sizeof(gfStateMasks_0096BCFC));
    DATATBLS_UnloadBinInline(gpStatesTxt);
    FOG_FreeLinker(gpStatesLinker_0096BCF0);
}

// 0x00611EE0
static __declspec(noinline) void sub_00611EE0_PlayerName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    if (id >= 0 && id < gVar_00744304->playerCount)
    {
        PlayerRecord* record = &gVar_00744304->players[id];
        if (record && record->name[0])
        {
            strncpy(buffer, record->name, length);
            buffer[length - 1] = 0;
            return;
        }
    }
    _snprintf(buffer, length, "player %d", id);
    buffer[length - 1] = 0;
}

// 0x00611F40
static __declspec(noinline) void sub_00611F40_MonsterName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    if (id >= 0 && id < gVar_00744304->monsterCount)
    {
        MonsterRecord* record = &gVar_00744304->monsters[id];
        if (record && record->nameIndex != 0x1506)
        {
            const Unicode* name = sub_00524A30_String(record->nameIndex);
            sub_00526F70_Narrow(buffer, name, length);
            return;
        }
    }
    _snprintf(buffer, length, "monster %d", id);
    buffer[length - 1] = 0;
}

// 0x00611FA0
static __declspec(noinline) void sub_00611FA0_CopyObjectLabel(char* buffer, int length, int id)
{
    if (length <= 0) return;
    ObjectRecord* record = sub_00640E90_Object(id);
    if (record && record->name[0])
    {
        strncpy(buffer, record->name, length);
        buffer[length - 1] = 0;
        return;
    }
    _snprintf(buffer, length, "object %d", id);
    buffer[length - 1] = 0;
}

// 0x00611FE0
static __declspec(noinline) void sub_00611FE0_ItemName(char* buffer, int length, int id)
{
    ItemRecord* record = sub_006335F0_Item(id);
    if (record && record->nameIndex != 0x1506)
    {
        const Unicode* name = sub_00524A30_String(record->nameIndex);
            sub_00526F70_Narrow(buffer, name, length);
        return;
    }
    if (length > 0)
    {
        _snprintf(buffer, length, "item %d", id);
        buffer[length - 1] = 0;
    }
}

// 0x00612030
static __declspec(noinline) void sub_00612030_MissileName(char* buffer, int length, int id)
{
    if (length > 0)
    {
        _snprintf(buffer, length, "missile %d", id);
        buffer[length - 1] = 0;
    }
}

// 0x00612050
char* __stdcall sub_00612050_UnitName(UnitHeader* unit, char* buffer, int length)
{
    buffer[0] = 0;
    if (!unit)
    {
        sub_006883F8_Copy(buffer, "NULL Unit");
        return buffer;
    }
    switch (unit->type)
    {
    case 0: sub_00611EE0_PlayerName(buffer, length, unit->classId); break;
    case 1: sub_00611F40_MonsterName(buffer, length, unit->classId); break;
    case 2: sub_00611FA0_CopyObjectLabel(buffer, length, unit->classId); break;
    case 3: sub_00612030_MissileName(buffer, length, unit->classId); break;
    case 4: sub_00611FE0_ItemName(buffer, length, unit->classId); break;
    default: sub_006883F8_Copy(buffer, "Invalid Unit"); break;
    }
    return buffer;
}

// 0x00612120
char* __stdcall sub_00612120_TypedName(unsigned int type, short id, char* buffer, int length)
{
    buffer[0] = 0;
    switch (type)
    {
    case 0: sub_00611EE0_PlayerName(buffer, length, id); break;
    case 1: sub_00611F40_MonsterName(buffer, length, id); break;
    case 2: sub_00611FA0_CopyObjectLabel(buffer, length, id); break;
    case 3:
        if (length > 0)
        {
            _snprintf(buffer, length, "missile %d", id);
            buffer[length - 1] = 0;
        }
        break;
    case 4: sub_00611FE0_ItemName(buffer, length, id); break;
    default: sub_006883F8_Copy(buffer, "Invalid Unit Type"); break;
    }
    return buffer;
}

// 0x006122F0
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize)
{
    int nDataSize = 0;
    void* pData;
    void* pTxt;
    int nRecordCount;
    char szPath[256];

    if (gbCompileTxt)
    {
        if (!_stricmp(szName, "leveldefs"))
        {
            pData = sub_00612280_ReadExcelFile(hArchive, "levels", ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2233);
        }
        else
        {
            pData = sub_00612280_ReadExcelFile(hArchive, szName, ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2240);
        }
        D2_ASSERT(pData, 2242);

        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nDataSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        pTxt = FOG_AllocPool(0, nRecordSize * nRecordCount, ".\\DATATBLS\\DataTbls.cpp", 2249, 0);
        memset(pTxt, 0, nRecordSize * nRecordCount);
        FOG_10207(pBinFile, pTbl, pTxt, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);

        strcpy(szPath, szName);
        strcat(szPath, ".bin");
        DATATBLS_WriteBinFile(szPath, pTxt, nRecordSize * nRecordCount, nRecordCount);
        sub_0040B480(0, pTxt, ".\\DATATBLS\\DataTbls.cpp", 2262, 0);
    }

    if (DATATBLS_LoadFromBin)
    {
        pData = sub_00612280_ReadExcelFile(hArchive, szName, ".bin", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2270);
    }
    else
    {
        if (!_stricmp(szName, "leveldefs"))
            pData = sub_00612280_ReadExcelFile(hArchive, "levels", ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2274);
        else
            pData = sub_00612280_ReadExcelFile(hArchive, szName, ".txt", &nDataSize, ".\\DATATBLS\\DataTbls.cpp", 2276);
    }
    D2_ASSERT(pData, 2279);

    if (DATATBLS_LoadFromBin)
    {
        nRecordCount = *(int*)pData;
        pTxt = (char*)pData + 4;
    }
    else
    {
        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pData, nDataSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        pTxt = FOG_AllocPool(0, nRecordSize * nRecordCount, ".\\DATATBLS\\DataTbls.cpp", 2308, 0);
        memset(pTxt, 0, nRecordSize * nRecordCount);
        FOG_10207(pBinFile, pTbl, pTxt, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);
    }

    if (pRecordCount)
    {
        *pRecordCount = nRecordCount;
    }

    return pTxt;
}

// 0x00612750
static void DATATBLS_LoadSomeTxts(void* hArchive)
{
    int nRecordCount;

    D2BinFieldStrc pCompCodeTbl[] =
    {
        { gszTxtField_code, 10, 0, 0, &gD2DataTables.pCompCodeLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    gD2DataTables.pCompCodeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 115);
    gD2DataTables.pCompCodeTxt = DATATBLS_CompileTxt(hArchive, "compcode", pCompCodeTbl, &gD2DataTables.nCompCodeTxtRecordCount, 4);

    if (gD2DataTables.bCompileTxt)
    {
        D2BinFieldStrc pPlayerClassTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pPlayerClassLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pPlayerClassLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 132);
        gD2DataTables.pPlayerClassTxt = DATATBLS_CompileTxt(hArchive, "playerclass", pPlayerClassTbl, &nRecordCount, 4);

        D2BinFieldStrc pBodyLocsTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pBodyLocsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pBodyLocsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 144);
        gD2DataTables.pBodyLocsTxt = DATATBLS_CompileTxt(hArchive, "bodylocs", pBodyLocsTbl, &nRecordCount, 4);

        D2BinFieldStrc pStorePageTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pStorePageLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pStorePageLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 156);
        gD2DataTables.pStorePageTxt = DATATBLS_CompileTxt(hArchive, "storepage", pStorePageTbl, &nRecordCount, 4);

        D2BinFieldStrc pElemTypesTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pElemTypesLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pElemTypesLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 168);
        gD2DataTables.pElemTypesTxt = DATATBLS_CompileTxt(hArchive, "elemtypes", pElemTypesTbl, &nRecordCount, 4);

        D2BinFieldStrc pHitClassTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pHitClassLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pHitClassLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 184);
        gD2DataTables.pHitClassTxt = DATATBLS_CompileTxt(hArchive, gszHitclassTxtName, pHitClassTbl, &nRecordCount, 4);

        D2BinFieldStrc pColorsTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pColorsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pColorsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 196);
        gD2DataTables.pColorsTxt = DATATBLS_CompileTxt(hArchive, "colors", pColorsTbl, &nRecordCount, 4);

        D2BinFieldStrc pHireDescTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pHireDescLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pHireDescLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 208);
        gD2DataTables.pHireDescTxt = DATATBLS_CompileTxt(hArchive, "hiredesc", pHireDescTbl, &nRecordCount, 4);

        D2BinFieldStrc pMonModeTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pMonModeLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonModeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 220);
        gD2DataTables.pMonModeTxtStub = DATATBLS_CompileTxt(hArchive, "monmode", pMonModeTbl, &nRecordCount, 4);

        D2BinFieldStrc pPlrModeTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pPlrModeLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pPlrModeLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 232);
        gD2DataTables.pPlrModeTxtStub = DATATBLS_CompileTxt(hArchive, "plrmode", pPlrModeTbl, &nRecordCount, 4);

        D2BinFieldStrc pMonAiTbl[] =
        {
            { "AI", 17, 0, 0, &gD2DataTables.pMonAiLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonAiLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 244);
        gD2DataTables.pMonAiTxt = DATATBLS_CompileTxt(hArchive, "monai", pMonAiTbl, &gD2DataTables.nMonAiTxtRecordCount, 2);

        D2BinFieldStrc pMonPlaceTbl[] =
        {
            { gszTxtField_code, 17, 0, 0, &gD2DataTables.pMonPlaceLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMonPlaceLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 256);
        gD2DataTables.pMonPlaceTxt = DATATBLS_CompileTxt(hArchive, "monplace", pMonPlaceTbl, &gD2DataTables.nMonPlaceTxtRecordCount, 2);

        D2BinFieldStrc pSkillCalcTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pSkillCalcLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pSkillCalcLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 268);
        gD2DataTables.pSkillCalcTxt = DATATBLS_CompileTxt(hArchive, "skillcalc", pSkillCalcTbl, &nRecordCount, 4);

        D2BinFieldStrc pMissileCalcTbl[] =
        {
            { gszTxtField_code, 10, 0, 0, &gD2DataTables.pMissileCalcLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pMissileCalcLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 280);
        gD2DataTables.pMissileCalcTxt = DATATBLS_CompileTxt(hArchive, "misscalc", pMissileCalcTbl, &nRecordCount, 4);

        D2BinFieldStrc pSkillCodeTbl[] =
        {
            { "skill", 17, 0, 0, &gD2DataTables.iSkillCode },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.iSkillCode = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 291);
        gD2DataTables.pSkillCode = DATATBLS_CompileTxt(hArchive, "skills", pSkillCodeTbl, &nRecordCount, 2);

        D2BinFieldStrc pEventsTbl[] =
        {
            { "event", 17, 0, 0, &gD2DataTables.pEventsLinker },
            { gszTxtField_end, 0, 0, 0, 0 },
        };
        gD2DataTables.pEventsLinker = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 303);
        gD2DataTables.pEventsTxt = DATATBLS_CompileTxt(hArchive, "events", pEventsTbl, &nRecordCount, 2);
    }
}

// 0x00619300
void __stdcall DATATBLS_LoadAllTxts(void* hArchive, int a2, int a3)
{
    DATATBLS_LoadSomeTxts(hArchive);
    DATATBLS_LoadItemTypesTxt(hArchive);
    DATATBLS_LoadMonTypeTxt(hArchive);
    DATATBLS_LoadSoundsTxt(hArchive);
    DATATBLS_LoadPetTypeTxt(hArchive);
    DATATBLS_LoadOverlayTxt(hArchive);
    DATATBLS_LoadItemStatCostTxt(hArchive);
    DATATBLS_LoadPropertiesTxt(hArchive);
    DATATBLS_LoadMissilesTxt(hArchive);
    DATATBLS_LoadStatesTxt(hArchive);
    DATATBLS_LoadSkills_SkillDescTxt(hArchive);
    DATATBLS_LoadCharStatsTxt(hArchive);
    DATATBLS_LoadArenaTxt(hArchive);
    DATATBLS_LoadCharTemplateTxt(hArchive);
    DATATBLS_LoadItemsTxt(hArchive);
    DATATBLS_LoadMagicSuffix_Prefix_AutomagicTxt(hArchive);
    DATATBLS_LoadRareSuffix_PrefixTxt(hArchive);
    DATATBLS_LoadUniqueItemsTxt(hArchive);
    DATATBLS_LoadSets_SetItemsTxt(hArchive);
    DATATBLS_LoadGemsTxt(hArchive);
    DATATBLS_LoadBooksTxt(hArchive);
    DATATBLS_LoadQualityItemsTxt(hArchive);
    DATATBLS_LoadLowQualityItemsTxt(hArchive);
    DATATBLS_LoadRunesTxt(hArchive);
    DATATBLS_LoadItemRatioTxt(hArchive);
    DATATBLS_LoadGambleTxt(hArchive);
    DATATBLS_LoadPlrType_ModeTxt(hArchive);
    DATATBLS_LoadMonModeTxt(hArchive);
    DATATBLS_LoadObjType_ModeTxt(hArchive);
    DATATBLS_LoadCompositTxt(hArchive);
    DATATBLS_LoadArmTypeTxt(hArchive);
    sub_00613D30(hArchive);
    gD2DataTables.pAnimData = DATATBLS_LoadAnimDataD2(hArchive);
    DATATBLS_LoadSomeMonsterTxts(hArchive);
    DATATBLS_LoadLevelsTxt(hArchive);
    DATATBLS_LoadLevelDefsBin(hArchive);
    sub_0061E520(hArchive);
    if (a2)
    {
        DATATBLS_AllocGlobalTileLibraryHash(hArchive);
    }
    DATATBLS_LoadLvlPrestTxt(hArchive, a2);
    DATATBLS_LoadLvlWarpTxt(hArchive);
    DATATBLS_LoadLvlMazeTxt(hArchive);
    DATATBLS_LoadLvlSubTxt(hArchive, a2, a3);
    DATATBLS_LoadAutomapTxt(hArchive);
    DATATBLS_LoadObjectsTxt(hArchive);
    DATATBLS_LoadObjGroupTxt(hArchive);
    DATATBLS_LoadShrinesTxt(hArchive);
    DATATBLS_LoadInventoryTxt(hArchive);
    DATATBLS_LoadExpFieldD2(hArchive);
    DATATBLS_LoadBeltsTxt(hArchive);
    DATATBLS_LoadMonItemPercentTxt(hArchive);
    sub_0066A270(hArchive);
    DATATBLS_LoadCubeMainTxt(hArchive);
    DATATBLS_LoadDifficultyLevelsTxt(hArchive);
    sub_00659C30();
}

void* gpCompCodeTxt_0096BCAC; // 0x0096BCAC

void* gpPlayerClassTxt_0096BC30; // 0x0096BC30

void* gpBodyLocsTxt_0096BC38; // 0x0096BC38

D2TxtLinkStrc* gpBodyLocsLinker_0096BC3C; // 0x0096BC3C

void* gpStorePageTxt_0096BC40; // 0x0096BC40

D2TxtLinkStrc* gpStorePageLinker_0096BC44; // 0x0096BC44

void* gpElemTypesTxt_0096BC48; // 0x0096BC48

void* gpHitClassTxt_0096BC50; // 0x0096BC50

void* gpColorsTxt_0096C5E0; // 0x0096C5E0

D2TxtLinkStrc* gpColorsLinker_0096C5E4; // 0x0096C5E4

void* gpHireDescTxt_0096BCE4; // 0x0096BCE4

void* gpMonModeTxt_0096BC58; // 0x0096BC58

void* gpPlrModeTxt_0096BC60; // 0x0096BC60

void* gpMonAiTxt_0096BCB8; // 0x0096BCB8

D2TxtLinkStrc* gpMonAiLinker_0096BCBC; // 0x0096BCBC

void* gpMonPlaceTxt_0096C6CC; // 0x0096C6CC

D2TxtLinkStrc* gpMonPlaceLinker_0096C6D0; // 0x0096C6D0

void* gpSkillCalcTxt_0096BC68; // 0x0096BC68

void* gpMissileCalcTxt_0096BC88; // 0x0096BC88

void* gpSkillCodeTxt_0096BC9C; // 0x0096BC9C

D2TxtLinkStrc* gpSkillCodeLinker_0096BCA0; // 0x0096BCA0

void* gpEventsTxt_0096BCA4; // 0x0096BCA4

// 0x00612EA0
void __stdcall sub_00612EA0_UnloadCompCodeAndCompileBins()
{
    DATATBLS_UnloadBinInline(gpCompCodeTxt_0096BCAC);
    FOG_FreeLinker(gpCompCodeLinker_0096BCB0);

    if (gbCompileTxt)
    {
        DATATBLS_UnloadBinInline(gpPlayerClassTxt_0096BC30);
        FOG_FreeLinker(gpPlayerClassLinker_0096BC34);
        DATATBLS_UnloadBinInline(gpBodyLocsTxt_0096BC38);
        FOG_FreeLinker(gpBodyLocsLinker_0096BC3C);
        DATATBLS_UnloadBinInline(gpStorePageTxt_0096BC40);
        FOG_FreeLinker(gpStorePageLinker_0096BC44);
        DATATBLS_UnloadBinInline(gpElemTypesTxt_0096BC48);
        FOG_FreeLinker(gpElemTypesLinker_0096BC4C);
        DATATBLS_UnloadBinInline(gpHitClassTxt_0096BC50);
        FOG_FreeLinker(gpHitClassLinker_0096BC54);
        DATATBLS_UnloadBinInline(gpColorsTxt_0096C5E0);
        FOG_FreeLinker(gpColorsLinker_0096C5E4);
        DATATBLS_UnloadBinInline(gpHireDescTxt_0096BCE4);
        FOG_FreeLinker(gpHireDescLinker_0096BCE8);
        DATATBLS_UnloadBinInline(gpMonModeTxt_0096BC58);
        FOG_FreeLinker(gpMonModeLinker_0096BC5C);
        DATATBLS_UnloadBinInline(gpPlrModeTxt_0096BC60);
        FOG_FreeLinker(gpPlrModeLinker_0096BC64);
        DATATBLS_UnloadBinInline(gpMonAiTxt_0096BCB8);
        FOG_FreeLinker(gpMonAiLinker_0096BCBC);
        DATATBLS_UnloadBinInline(gpMonPlaceTxt_0096C6CC);
        FOG_FreeLinker(gpMonPlaceLinker_0096C6D0);
        DATATBLS_UnloadBinInline(gpSkillCalcTxt_0096BC68);
        FOG_FreeLinker(gpSkillCalcLinker_0096BC6C);
        DATATBLS_UnloadBinInline(gpMissileCalcTxt_0096BC88);
        FOG_FreeLinker(gpMissileCalcLinker_0096BC8C);
        DATATBLS_UnloadBinInline(gpSkillCodeTxt_0096BC9C);
        FOG_FreeLinker(gpSkillCodeLinker_0096BCA0);
        DATATBLS_UnloadBinInline(gpEventsTxt_0096BCA4);
        FOG_FreeLinker(gpEventsLinker_0096BCA8);
    }
}

#include "gen/data/Source/D2Common/DATATBLS/DataTbls.inc"

int gnCharstatsTxtRecordCount; // 0x0096C7F8

// 0x00613260
void __stdcall DATATBLS_LoadCharStatsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "class", 1, 15, 32, 0 },
        { "str", 4, 0, 48, 0 },
        { "dex", 4, 0, 49, 0 },
        { "vit", 4, 0, 51, 0 },
        { gszTxtField_int, 4, 0, 50, 0 },
        { "stamina", 4, 0, 52, 0 },
        { "hpadd", 4, 0, 53, 0 },
        { "PercentStr", 4, 0, 54, 0 },
        { "PercentDex", 4, 0, 56, 0 },
        { "PercentVit", 4, 0, 57, 0 },
        { "PercentInt", 4, 0, 55, 0 },
        { "ManaRegen", 4, 0, 58, 0 },
        { "ToHitFactor", 2, 0, 60, 0 },
        { "WalkVelocity", 4, 0, 64, 0 },
        { "RunVelocity", 4, 0, 65, 0 },
        { "RunDrain", 4, 0, 66, 0 },
        { "LifePerLevel", 4, 0, 67, 0 },
        { "StaminaPerLevel", 4, 0, 68, 0 },
        { "ManaPerLevel", 4, 0, 69, 0 },
        { "LifePerVitality", 4, 0, 70, 0 },
        { "StaminaPerVitality", 4, 0, 71, 0 },
        { "ManaPerMagic", 4, 0, 72, 0 },
        { "BlockFactor", 4, 0, 73, 0 },
        { "basewclass", 9, 0, 76, 0 },
        { "StrAllSkills", 22, 0, 82, (void*)sub_006117B0 },
        { "StrSkillTab1", 22, 0, 84, (void*)sub_006117B0 },
        { "StrSkillTab2", 22, 0, 86, (void*)sub_006117B0 },
        { "StrSkillTab3", 22, 0, 88, (void*)sub_006117B0 },
        { "StrClassOnly", 22, 0, 90, (void*)sub_006117B0 },
        { "StartSkill", 20, 0, 172, &gTxtLink_0096C7CC },
        { "Skill 1", 20, 0, 174, &gTxtLink_0096C7CC },
        { "Skill 2", 20, 0, 176, &gTxtLink_0096C7CC },
        { "Skill 3", 20, 0, 178, &gTxtLink_0096C7CC },
        { "Skill 4", 20, 0, 180, &gTxtLink_0096C7CC },
        { "Skill 5", 20, 0, 182, &gTxtLink_0096C7CC },
        { "Skill 6", 20, 0, 184, &gTxtLink_0096C7CC },
        { "Skill 7", 20, 0, 186, &gTxtLink_0096C7CC },
        { "Skill 8", 20, 0, 188, &gTxtLink_0096C7CC },
        { "Skill 9", 20, 0, 190, &gTxtLink_0096C7CC },
        { "Skill 10", 20, 0, 192, &gTxtLink_0096C7CC },
        { "StatPerLevel", 4, 0, 80, 0 },
        { "item1loc", 13, 0, 96, &gpBodyLocsLinker_0096BC3C },
        { "item2loc", 13, 0, 104, &gpBodyLocsLinker_0096BC3C },
        { "item3loc", 13, 0, 112, &gpBodyLocsLinker_0096BC3C },
        { "item4loc", 13, 0, 120, &gpBodyLocsLinker_0096BC3C },
        { "item5loc", 13, 0, 128, &gpBodyLocsLinker_0096BC3C },
        { "item6loc", 13, 0, 136, &gpBodyLocsLinker_0096BC3C },
        { "item7loc", 13, 0, 144, &gpBodyLocsLinker_0096BC3C },
        { "item8loc", 13, 0, 152, &gpBodyLocsLinker_0096BC3C },
        { "item9loc", 13, 0, 160, &gpBodyLocsLinker_0096BC3C },
        { "item10loc", 13, 0, 168, &gpBodyLocsLinker_0096BC3C },
        { "item1", 9, 0, 92, 0 },
        { "item1count", 4, 0, 97, 0 },
        { "item2", 9, 0, 100, 0 },
        { "item2count", 4, 0, 105, 0 },
        { "item3", 9, 0, 108, 0 },
        { "item3count", 4, 0, 113, 0 },
        { "item4", 9, 0, 116, 0 },
        { "item4count", 4, 0, 121, 0 },
        { "item5", 9, 0, 124, 0 },
        { "item5count", 4, 0, 129, 0 },
        { "item6", 9, 0, 132, 0 },
        { "item6count", 4, 0, 137, 0 },
        { "item7", 9, 0, 140, 0 },
        { "item7count", 4, 0, 145, 0 },
        { "item8", 9, 0, 148, 0 },
        { "item8count", 4, 0, 153, 0 },
        { "item9", 9, 0, 156, 0 },
        { "item9count", 4, 0, 161, 0 },
        { "item10", 9, 0, 164, 0 },
        { "item10count", 4, 0, 169, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCharstatsTxt = DATATBLS_CompileTxt(hArchive, "charstats", pTbl, &gnCharstatsTxtRecordCount, 196);
    sub_00612600(gpCharstatsTxt, gnCharstatsTxtRecordCount, 196, 32, 0, 16);
}

// 0x00617C20
void __fastcall sub_00617C20_LoadSkills(void* hArchive) {
#ifdef MOVED_TEST
 DATATBLS_LoadSkills_SkillDescTxt((char*)hArchive+4);
#else
 DATATBLS_LoadSkills_SkillDescTxt(hArchive);
#endif
}

// 0x00618100
void __fastcall DATATBLS_LoadStatesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "state", TXTFIELD_NAMETOINDEX, 0, 0, &gD2DataTables.pStatesLinker },
        { "group", TXTFIELD_WORD, 0, 30, 0 },
        { "nosend", TXTFIELD_BIT, 0, 16, 0 },
        { "hide", TXTFIELD_BIT, 2, 16, 0 },
        { "transform", TXTFIELD_BIT, 3, 16, 0 },
        { "aura", TXTFIELD_BIT, 1, 16, 0 },
        { "pgsv", TXTFIELD_BIT, 4, 16, 0 },
        { "active", TXTFIELD_BIT, 5, 16, 0 },
        { "remhit", TXTFIELD_BIT, 6, 16, 0 },
        { "damblue", TXTFIELD_BIT, 7, 16, 0 },
        { "damred", TXTFIELD_BIT, 8, 16, 0 },
        { "attblue", TXTFIELD_BIT, 9, 16, 0 },
        { "attred", TXTFIELD_BIT, 10, 16, 0 },
        { "curse", TXTFIELD_BIT, 11, 16, 0 },
        { "curable", TXTFIELD_BIT, 12, 16, 0 },
        { "plrstaydeath", TXTFIELD_BIT, 13, 16, 0 },
        { "monstaydeath", TXTFIELD_BIT, 14, 16, 0 },
        { "bossstaydeath", TXTFIELD_BIT, 15, 16, 0 },
        { "disguise", TXTFIELD_BIT, 16, 16, 0 },
        { "bossinv", TXTFIELD_BIT, 37, 16, 0 },
        { "meleeonly", TXTFIELD_BIT, 38, 16, 0 },
        { "restrict", TXTFIELD_BIT, 17, 16, 0 },
        { "blue", TXTFIELD_BIT, 18, 16, 0 },
        { "armblue", TXTFIELD_BIT, 19, 16, 0 },
        { "rfblue", TXTFIELD_BIT, 20, 16, 0 },
        { "rcblue", TXTFIELD_BIT, 21, 16, 0 },
        { "rlblue", TXTFIELD_BIT, 22, 16, 0 },
        { "rpblue", TXTFIELD_BIT, 23, 16, 0 },
        { "stambarblue", TXTFIELD_BIT, 24, 16, 0 },
        { "armred", TXTFIELD_BIT, 25, 16, 0 },
        { "rfred", TXTFIELD_BIT, 26, 16, 0 },
        { "rcred", TXTFIELD_BIT, 27, 16, 0 },
        { "rlred", TXTFIELD_BIT, 28, 16, 0 },
        { "rpred", TXTFIELD_BIT, 29, 16, 0 },
        { gszTxtField_exp, TXTFIELD_BIT, 30, 16, 0 },
        { "shatter", TXTFIELD_BIT, 31, 16, 0 },
        { "life", TXTFIELD_BIT, 32, 16, 0 },
        { "udead", TXTFIELD_BIT, 33, 16, 0 },
        { "green", TXTFIELD_BIT, 34, 16, 0 },
        { "nooverlays", TXTFIELD_BIT, 35, 16, 0 },
        { "notondead", TXTFIELD_BIT, 39, 16, 0 },
        { "noclear", TXTFIELD_BIT, 36, 16, 0 },
        { "overlay1", TXTFIELD_NAMETOWORD, 0, 2, &gD2DataTables.pOverlayLinker },
        { "overlay2", TXTFIELD_NAMETOWORD, 0, 4, &gD2DataTables.pOverlayLinker },
        { "overlay3", TXTFIELD_NAMETOWORD, 0, 6, &gD2DataTables.pOverlayLinker },
        { "overlay4", TXTFIELD_NAMETOWORD, 0, 8, &gD2DataTables.pOverlayLinker },
        { "pgsvoverlay", TXTFIELD_NAMETOWORD, 0, 14, &gD2DataTables.pOverlayLinker },
        { "castoverlay", TXTFIELD_NAMETOWORD, 0, 10, &gD2DataTables.pOverlayLinker },
        { "removerlay", TXTFIELD_NAMETOWORD, 0, 12, &gD2DataTables.pOverlayLinker },
        { "stat", TXTFIELD_NAMETOWORD, 0, 24, &gD2DataTables.pItemStatCostLinker },
        { "setfunc", TXTFIELD_WORD, 0, 26, 0 },
        { "remfunc", TXTFIELD_WORD, 0, 28, 0 },
        { "missile", TXTFIELD_NAMETOWORD, 0, 58, &gD2DataTables.pMissilesLinker },
        { "skill", TXTFIELD_NAMETOWORD, 0, 56, &gD2DataTables.iSkillCode },
        { "colorpri", TXTFIELD_BYTE, 0, 32, 0 },
        { "colorshift", TXTFIELD_BYTE, 0, 33, 0 },
        { "light-r", TXTFIELD_BYTE, 0, 34, 0 },
        { "light-g", TXTFIELD_BYTE, 0, 35, 0 },
        { "light-b", TXTFIELD_BYTE, 0, 36, 0 },
        { "onsound", TXTFIELD_NAMETOWORD, 0, 38, &gD2DataTables.pSoundsLinker },
        { "offsound", TXTFIELD_NAMETOWORD, 0, 40, &gD2DataTables.pSoundsLinker },
        { "itemtype", TXTFIELD_CODETOWORD, 0, 42, &gD2DataTables.pItemTypesLinker },
        { "itemtrans", TXTFIELD_CODETOBYTE, 0, 44, &gD2DataTables.pColorsLinker },
        { "gfxtype", TXTFIELD_BYTE, 0, 45, 0 },
        { "gfxclass", TXTFIELD_WORD, 0, 46, 0 },
        { "cltevent", TXTFIELD_NAMETOWORD, 0, 48, &gD2DataTables.pEventsLinker },
        { "clteventfunc", TXTFIELD_WORD, 0, 50, 0 },
        { "cltactivefunc", TXTFIELD_WORD, 0, 52, 0 },
        { "srvactivefunc", TXTFIELD_WORD, 0, 54, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    gD2DataTables.pStatesLinker = sub_006BD040(".\\DATATBLS\\DataTbls.cpp", 1735);
    gD2DataTables.pStatesTxt = (D2StatesTxt*)DATATBLS_CompileTxt(hArchive, "states", pTbl, &gD2DataTables.nStatesTxtRecordCount, sizeof(D2StatesTxt));

    D2_ASSERT(gD2DataTables.nStatesTxtRecordCount < 256, 1737);

    unsigned int nMaskSize = sizeof(unsigned int) * ((gD2DataTables.nStatesTxtRecordCount + 32 - 1) / 32);
    unsigned int nSize = 40 * nMaskSize;
    gD2DataTables.pStateMasks = (unsigned int*)FOG_AllocPool(0, nSize, ".\\DATATBLS\\DataTbls.cpp", 1742, 0);
    memset(gD2DataTables.pStateMasks, 0, nSize);

    for (int i = 0; i < 40; ++i)
    {
        gD2DataTables.fStateMasks[i] = &gD2DataTables.pStateMasks[i * (nMaskSize / sizeof(unsigned int))];
        sub_00611D60_BuildStateMask(gD2DataTables.fStateMasks[i], i);
    }

    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pProgressiveStates, &gD2DataTables.nProgressiveStates, 4);
    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pCurseStates, &gD2DataTables.nCurseStates, 11);
    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pTransformStates, &gD2DataTables.nTransformStates, 16);
    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pActionStates, &gD2DataTables.nActionStates, 5);
    sub_00611E60_BuildStateListByField(&gD2DataTables.pColourStates, &gD2DataTables.nColourStates, 42);
}

D2TxtLinkStrc* gTxtLink_0096C81C; // 0x0096C81C

int gnPettypeTxtRecordCount; // 0x0096C820

// 0x00618D90
void __fastcall DATATBLS_LoadPetTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "pet type", 18, 0, 0, &gTxtLink_0096C81C },
        { "group", 3, 0, 8, 0 },
        { "basemax", 3, 0, 10, 0 },
        { "warp", 26, 0, 4, 0 },
        { "range", 26, 1, 4, 0 },
        { "partysend", 26, 2, 4, 0 },
        { "unsummon", 26, 3, 4, 0 },
        { "automap", 26, 4, 4, 0 },
        { "drawhp", 26, 5, 4, 0 },
        { "icontype", 4, 0, 14, 0 },
        { "baseicon", 1, 32, 15, 0 },
        { "mclass1", 3, 0, 178, 0 },
        { "micon1", 1, 32, 47, 0 },
        { "mclass2", 3, 0, 180, 0 },
        { "micon2", 1, 32, 79, 0 },
        { "mclass3", 3, 0, 182, 0 },
        { "micon3", 1, 32, 111, 0 },
        { "mclass4", 3, 0, 184, 0 },
        { "micon4", 1, 32, 143, 0 },
        { "name", 22, 0, 12, (void*)sub_006117B0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C81C = FOG_AllocLinker(".\\DATATBLS\\DataTbls.cpp", 1833);
    gpPettypeTxt = DATATBLS_CompileTxt(hArchive, "pettype", pTbl, &gnPettypeTxtRecordCount, 224);
    TBL_ASSERT(gnPettypeTxtRecordCount < 256, 1835);
    gnPettypeTxtRecordCount = gnPettypeTxtRecordCount <= 0 ? 0 : gnPettypeTxtRecordCount;
    if (gnPettypeTxtRecordCount >= 256)
    {
        gnPettypeTxtRecordCount = 256;
    }
}

// 0x00619100
void __fastcall sub_00619100_UnloadPetTypeTxt()
{
    DATATBLS_UnloadBinInline(gpPettypeTxt);
    FOG_FreeLinker(gpPettypeLinker);
}
