#include "D2Client.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GemsTxt;
struct D2InvRectStrc;
struct D2InvCompGridStrc;
struct D2InventoryGridInfoStrc;
struct Unicode;
struct D2CharStatsTxt;
struct D2UnitInvView;
struct D2SpeedNameStrc;
struct D2ItemTypeNameStrc;
struct D2DifficultyLevelsTxt;
struct D2MercStatLineStrc;
struct D2ElemDamageStrc;
struct D2SetItemsTxt;
struct D2SetsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
};

struct D2InvRectStrc { int nLeft,nRight,nTop,nBottom; };

struct D2InvCompGridStrc { D2InvRectStrc rect; unsigned char nWidth,nHeight; unsigned short pad; };

struct D2InventoryGridInfoStrc { unsigned char nGridX,nGridY; unsigned short pad; int nGridLeft,nGridRight,nGridTop,nGridBottom; unsigned char nGridBoxWidth,nGridBoxHeight; unsigned short pad2; };

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4
extern int gnGlobal_007BCC20; // 0x007BCC20
extern int gnGlobal_007BCC4C; // 0x007BCC4C
extern D2InvCompGridStrc gaCompGrids_007BCC58[11]; // 0x007BCC58
extern "C" const char szCmnItemsH_006D9B90[]; // 0x006D9B90
extern "C" const char szInvCpp_006D9BC0[]; // 0x006D9BC0
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc*,int,int); // 0x0046EE80
void __fastcall sub_0046EFD0_DrawFramedBox(int,int,unsigned char,unsigned char,unsigned char,int); // 0x0046EFD0
void __cdecl sub_004835B0_LoadUiRecords(); // 0x004835B0
void __stdcall sub_00483E40(D2UnitStrc*,D2InventoryGridInfoStrc*,int,int); // 0x00483E40
int __fastcall sub_004C2240(D2UnitStrc*); // 0x004C2240
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc*,int,int); // 0x00621050
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0
void __stdcall ITEMS_GetDimensions(D2UnitStrc*,unsigned char*,unsigned char*,const char*,int); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc*); // 0x00629900
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc*); // 0x0062A4E0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc*); // 0x0062BC20
int __stdcall sub_0062BEB0(D2UnitStrc*); // 0x0062BEB0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740
int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc*,int); // 0x0062ED50
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc*); // 0x0063C1E0
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc*); // 0x0063CD60
int __stdcall INVENTORY_GetWieldType(D2UnitStrc*,D2InventoryStrc*); // 0x0063D340

struct Unicode
{
    unsigned short wChar;
    Unicode() : wChar(0)
    {
    }
};

struct D2ItemsTxt
{
    char unk0x00[0xF0];
    int nGemOffset;
    unsigned short wNameStr;
    char unk0xF6[0x08];
    unsigned char nMinDam;
    unsigned char nMaxDam;
    char unk0x100[0x0A];
    unsigned short wReqStr;
    unsigned short wReqDex;
    char unk0x10E[0x03];
    unsigned char nBlock;
};

struct D2GemsTxt
{
    char unk0x00[0x20];
    char szLetter[6];
};

struct D2CharStatsTxt
{
    char unk0x00[0x49];
    unsigned char nBlockFactor;
    char unk0x4A[0x7A];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
    char unk0xBCC[0x4C];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
};

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

extern "C" const char gszEmptyAssertText; // 0x006CC837
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit(); // 0x00463DE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall sub_00625560(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625560
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
void* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, void* pSkill, int bBonus); // 0x006442A0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
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

struct D2DifficultyLevelsTxt
{
    int dwResistPenalty;
};

struct D2MercStatLineStrc
{
    int nLeft;
    int nRight;
    int nY;
    int nMaxWidth;
    int nStatId;
};

struct D2ElemDamageStrc
{
    int nMinStat;
    int f_4;
    int nColor;
};

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_00479080_GetPetLife(int nUnitId); // 0x00479080
void __stdcall sub_0048A7D0_DrawUnitName(D2UnitStrc* pUnit); // 0x0048A7D0
void __cdecl sub_0048A890_DrawPanelLabels(); // 0x0048A890
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
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
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
extern D2MercStatLineStrc gaMercStatLines_007221A8[12]; // 0x007221A8
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
static void sub_0048A990_DrawMercStats(D2UnitStrc* pUnit); // 0x0048A990

struct D2SetItemsTxt
{
    short wSetItemId;
    char unk0x02[0x22];
    unsigned short wStrName;
    char unk0x26[0x06];
    short nSetId;
    char unk0x2E[0x18A];
};

struct D2SetsTxt
{
    char unk0x00[0x02];
    unsigned short wStrName;
    char unk0x04[0x08];
    int nSetItems;
    char unk0x10[0x100];
    D2SetItemsTxt* pSetItems[6];
};

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
Unicode* __fastcall sub_00452170(Unicode* pText); // 0x00452170
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId); // 0x00483410
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex); // 0x00483440
int __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText); // 0x00485410
void __stdcall sub_00485EE0_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText); // 0x00485EE0
void __cdecl sub_0048BE80_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...); // 0x0048BE80
void __fastcall sub_0048C060(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410
void __fastcall sub_004E6560_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6560
void __fastcall sub_004E6680_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6680
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625E60
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625EF0
int __stdcall sub_00626020_ArmorValue(D2UnitStrc* pUnit); // 0x00626020
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062BA60
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem); // 0x0062C060
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem); // 0x0062C0B0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
extern int gnGlobal_00721E38; // 0x00721E38
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gdwGlobal_007BCBE4; // 0x007BCBE4
extern D2UnitStrc* gpHoverItem_007BCBF4; // 0x007BCBF4

// 0x00483A70
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

// 0x004843E0
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
    if (!sub_0062BEB0(pSocketable))
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
static void sub_004844A0_DrawBodyLocPlacement(D2InventoryStrc* pInventory)
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
    if (ITEMS_CheckBodyLocation(pCursorItem, gnGlobal_007BCC20) && ITEMS_CheckRequirements(pCursorItem, sub_00463DD0(), 0, 0, 0, 0))
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
void __cdecl sub_004845A0_DrawEquippedItems()
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
    D2UnitStrc* pPlayer=sub_00463DD0();
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    UNITS_GetInventoryRecordId(pPlayer,0,sub_0044DCC0());
    sub_004835B0_LoadUiRecords();
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
                sub_0046EE80_DrawCursorItem(pItem,gaCompGrids_007BCC58[4].rect.nLeft+((gaCompGrids_007BCC58[5].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids_007BCC58[4].rect.nTop+((gaCompGrids_007BCC58[5].nHeight-gGrid_007BCB88.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids_007BCC58[4]);
            }
            break;
        case 4:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,5);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                sub_0046EE80_DrawCursorItem(pItem,gaCompGrids_007BCC58[5].rect.nLeft+((gaCompGrids_007BCC58[4].nWidth-gGrid_007BCB88.nGridBoxWidth*nWidth)>>1)+nOffsetX,
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
        if(pItem==gdwGlobal_007BCBF4 && gdwGlobal_007BCBE8)
        {
            if(sub_00468830()==8)sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],0);
            else sub_00483A70_DrawSlotFrame(&gaCompGrids_007BCC58[nBodyLoc],1);
            sub_0046EE80_DrawCursorItem(pItem,nX,nY);
            if(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem)>0 && ITEMS_CheckItemFlag(pItem,0x800,0x673,szInvCpp_006D9BC0))
                sub_00483E40(pItem,&gGrid_007BCB88,nX,nY);
        }
        else
        {
            if (pOther || (!ITEMS_GetAmmoType(pItem) && !ITEMS_GetQuiverType(pItem)))
            {
                if (ITEMS_CheckRequirements(pItem,pPlayer,0,0,0,0) && !sub_004C2240(pItem) && sub_0062A4E0_TestItem(pItem))
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
            sub_0046EE80_DrawCursorItem(pItem,nX,nY);
        }
    }
    sub_004844A0_DrawBodyLocPlacement(pInventory);
}

// 0x00484B10
static void __stdcall sub_00484B10_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText)
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
static void __stdcall sub_00484DB0_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf(szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, 0x46, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
    }
}

// 0x00484E90
static void __stdcall sub_00484E90_AppendDurability(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (ITEMS_HasDurability(pItem) && STATLIST_GetMaxDurabilityFromUnit(pItem) > 0 && !ITEMS_CheckIfThrowable(pItem))
    {
        int bBonus = 0;
        if (sub_00625560(pItem, 0x4B, 0))
        {
            bBonus = 1;
        }
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD81));
        SStrPrintf(szNumber, 10, szFmtInt_006D6454, STATLIST_UnitGetStatValue(pItem, 0x48, 0));
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
            sub_004521C0_PrefixLevelText(wszNumber, 3);
        }
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484FF0
static void __stdcall sub_00484FF0_AppendNumberLine(int nValue, Unicode* pText)
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
static void __stdcall sub_004850A0_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
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
static void __stdcall sub_00485170_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
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

// 0x00485D40
static void __stdcall sub_00485D40_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    int nMin = pItemsTxt->nMinDam;
    int nMax = pItemsTxt->nMaxDam;
    int nStringId;
    if (ITEMS_CheckItemTypeId(pItem, 0x33))
    {
        nStringId = 0xD8C;
        D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0x75);
        if (pSkill && STATES_CheckState(pUnit, 0x65))
        {
            const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            nMin += SKILLS_GetMinPhysDamage(pUnit, 0x75, nLevel, 1) >> 8;
            nMax += SKILLS_GetMaxPhysDamage(pUnit, 0x75, nLevel, 1) >> 8;
        }
    }
    else
    {
        if (!ITEMS_CheckItemTypeId(pItem, 0xF))
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
    if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf(szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, 0x46, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00485BE0
static void __stdcall sub_00485BE0_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem)
{
    int nBlock = STATLIST_UnitGetStatValue(pItem, 0x14, 0);
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        const int nClass = pPlayer->dwClassId;
        D2CharStatsTxt* pCharStats = (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClass] : 0;
        nBlock += pCharStats->nBlockFactor;
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, 0x75);
        if (pSkill && STATES_CheckState(pPlayer, 0x65))
        {
            const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            nBlock += D2COMMON_11036_GetMonCurseResistanceSubtraction(nLevel, 0x75);
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
        sub_004521C0_PrefixLevelText(wszBlock, 3);
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x2B0A));
    sub_004521C0_PrefixLevelText(wszText, 0);
    sub_005267E0(pText, wszText);
    sub_00526700(pText, wszBlock);
}

// 0x004861D0
static void __stdcall sub_004861D0_AppendAttackSpeed(Unicode* pText, D2UnitStrc* pItem)
{
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pColorAlt = D2LANG_GetStringFromTblIndex(0xF9C);
    D2UnitStrc* pStoredUnit = sub_00463DE0_GetStoredUnit();
    const int nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pStoredUnit, pItem);
    int bBonus = 0;
    if (sub_00625560(pItem, 0x5D, 0))
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
        D2UnitStrc* pUnit = sub_00463DE0_GetStoredUnit();
        const int bMissile = (ITEMS_CheckItemTypeId(pItem, 0x23) || ITEMS_CheckItemTypeId(pItem, 0x1B)) ? 1 : 0;
        const int nClass = !pUnit ? -1 : pUnit->dwClassId;
        nSpeed = gaSpeedTable_00721F10[nAttackSpeed - 10][gaClassSpeedOffsets_00722078[nClass][bMissile]];
    }
    int nFound = -1;
    for (int i = 0; i < 15; ++i)
    {
        if (ITEMS_CheckItemTypeId(pItem, gaItemTypeNames_00721EB0[i].nItemType))
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
        sub_004521C0_PrefixLevelText(wszText, 3);
    }
    sub_00526700(pText, wszText);
    sub_00526700(pText, pColorEnd);
}

// build: context sub_E05_Emit_Tooltip
void __stdcall sub_E05_Emit_Tooltip(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, int nValue, Unicode* pText)
{
    sub_00484B10_AppendEtherealSocketed(pItem, pText);
    sub_00484DB0_AppendQuantity(pItemsTxt, pItem, pText + 0x100);
    sub_00484E90_AppendDurability(pItem, pText + 0x200);
    sub_00484FF0_AppendNumberLine(nValue, pText + 0x300);
    sub_004850A0_AppendReqStr(pItemsTxt, nValue, pText + 0x400);
    sub_00485170_AppendReqDex(pItemsTxt, nValue, pText + 0x500);
    sub_00485D40_AppendThrowDamage(pItem, pItemsTxt, pText + 0x600);
    sub_00486100_AppendStackQuantity(pItem, pText + 0x700);
    sub_00485BE0_AppendBlockChance(pText + 0x800, pItemsTxt, pItem);
    sub_004861D0_AppendAttackSpeed(pText + 0x900, pItem);
}

#include "gen/data/Source/D2Client/UI/inv_004844A0.inc"

// 0x0048A990
static void sub_0048A990_DrawMercStats(D2UnitStrc* pUnit)
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
            if ((STATLIST_GetUnitBaseStat(pUnit, 7, 0) >> 8) < nMaxLife)
            {
                nColor = 3;
            }
            break;
        }
        case 0x15:
        {
            D2UnitStrc* pWeapon = 0;
            int nFlat = 0;
            int nPercent = STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
            const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
            const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
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

            int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
            if (pWeapon)
            {
                if (ITEMS_CheckWeaponIfTwoHanded(pWeapon))
                {
                    nValue -= STATLIST_UnitGetStatValue(pWeapon, 0x15, 0);
                    nMaxDamage -= STATLIST_UnitGetStatValue(pWeapon, 0x16, 0);
                    nValue += STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
                    nMaxDamage += STATLIST_UnitGetStatValue(pUnit, 0x18, 0);
                }

                nFlat = ITEMS_GetStrengthBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFlat / 100;
                }

                nFlat = ITEMS_GetDexBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFlat / 100;
                }

                nPercent += SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, 0, 1);
                nFlat = STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x6F, 0);
            }
            else
            {
                if (sub_00451F60_UnitClassId(pUnit) == 0x10F)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 2, 0);
                }
                else
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 0, 0);
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

            nValue = STATLIST_UnitGetStatValue(pUnit, 0x39, 0);
            nFlat = STATLIST_UnitGetStatValue(pUnit, 0x3A, 0);
            if (nValue || nFlat)
            {
                int nLength = STATLIST_UnitGetStatValue(pUnit, 0x65, 0);
                if (nLength <= 0)
                {
                    int nCount = STATLIST_UnitGetStatValue(pUnit, 0x146, 0);
                    if (nCount < 1)
                    {
                        nCount = 1;
                    }
                    nLength = STATLIST_UnitGetStatValue(pUnit, 0x3B, 0) / nCount;
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
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x28, 0);
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
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x2A, 0);
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
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x2C, 0);
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
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x2E, 0);
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
            sub_004A7080(nLeft, nY, nRight, wszText, nColor);
        }
    }
    sub_00502EF0(nOldFont);
}

void __cdecl sub_19F4_Emit_0048A990(D2UnitStrc* pUnit)
{
    sub_0048A7D0_DrawUnitName(pUnit);
    sub_0048A890_DrawPanelLabels();
    sub_0048A990_DrawMercStats(pUnit);
    sub_0048B0A0(pUnit);
}

static D2UnitStrc* sub_00486770_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == 5 && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, ".\\UI\\inv.cpp"))
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
void __fastcall sub_0048D1D0_DrawSetItemTooltip(D2UnitStrc* pUnit)
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
    if (pUnit && pUnit->dwUnitType == 1 && !MONSTERS_GetHirelingTypeId(pUnit))
        pPlayer = sub_00463DD0();

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

    sub_00484E90_AppendDurability(gpHoverItem_007BCBF4, wszDurability);

    const int nLevelReq = ITEMS_GetLevelRequirement(gpHoverItem_007BCBF4, pPlayer);
    if (nLevelReq > 1)
    {
        if (!bLevel)
            bLevelRed = 1;
        sub_00484FF0_AppendNumberLine(nLevelReq, wszLevelReq);
    }

    if (ITEMS_CheckItemTypeId(gpHoverItem_007BCBF4, 0x2D) || ITEMS_CheckItemTypeId(gpHoverItem_007BCBF4, 0x32))
    {
        int nStrBonus = 0;
        int nDexBonus = 0;
        const int nPercent = STATLIST_UnitGetItemStatOrSkillStatValue(gpHoverItem_007BCBF4, 0x5B, 0);
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
            sub_004850A0_AppendReqStr(pItemsTxt, nStrBonus, wszStrReq);
        }

        if (pItemsTxt->wReqDex > 0)
        {
            if (!bDexterity)
                bDexRed = 1;
            sub_00485170_AppendReqDex(pItemsTxt, nDexBonus, wszDexReq);
        }
    }

    sub_005267E0(wszStats, sub_004521C0_PrefixLevelText(wszLevelReq, bLevelRed));
    sub_00526700(wszStats, sub_004521C0_PrefixLevelText(wszStrReq, bStrRed));
    sub_00526700(wszStats, sub_004521C0_PrefixLevelText(wszDexReq, bDexRed));

    const int nClass = ITEMS_GetClassOfClassSpecificItem(gpHoverItem_007BCBF4);
    if (nClass != 7)
    {
        sub_00526700(wszClass, D2LANG_GetStringFromTblIndex(nClass + 0x2AA5));
        sub_00526700(wszClass, pNewline);
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->dwClassId != nClass)
            bClassRed = 1;
        sub_00526700(wszStats, sub_004521C0_PrefixLevelText(wszClass, bClassRed));
    }

    sub_00526700(wszStats, sub_004521C0_PrefixLevelText(wszDurability, 0));

    if (ITEMS_CheckItemTypeId(gpHoverItem_007BCBF4, 0x2D))
    {
        sub_004861D0_AppendAttackSpeed(wszSpeed, gpHoverItem_007BCBF4);
        sub_004521C0_PrefixLevelText(wszSpeed, 0);
        sub_00526700(wszStats, wszSpeed);

        if (STATLIST_GetMinDamageFromUnit(gpHoverItem_007BCBF4, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(gpHoverItem_007BCBF4, 0) >= 0)
        {
            sub_00485410_AppendDamage(gpHoverItem_007BCBF4, wszDamage);
            sub_004521C0_PrefixLevelText(wszDamage, 0);
            sub_00526700(wszStats, wszDamage);
        }
    }

    if (ITEMS_CheckItemTypeId(gpHoverItem_007BCBF4, 0x33))
    {
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            const int nPlayerClass = pPlayer->dwClassId;
            if (nPlayerClass == 3 && (!ITEMS_IsClassValid(gpHoverItem_007BCBF4) || ITEMS_GetClassOfClassSpecificItem(gpHoverItem_007BCBF4) == nPlayerClass))
            {
                sub_00485D40_AppendThrowDamage(gpHoverItem_007BCBF4, pItemsTxt, wszThrow);
                sub_004521C0_PrefixLevelText(wszThrow, 0);
                sub_00526700(wszStats, wszThrow);
            }
        }

        sub_00485BE0_AppendBlockChance(wszBlock, pItemsTxt, gpHoverItem_007BCBF4);
        sub_004521C0_PrefixLevelText(wszBlock, 0);
        sub_00526700(wszStats, wszBlock);
    }

    if (ITEMS_CheckItemTypeId(gpHoverItem_007BCBF4, 0x32) && sub_00626020_ArmorValue(gpHoverItem_007BCBF4) > 0)
    {
        sub_00485EE0_AppendDefense(pPlayer, gpHoverItem_007BCBF4, wszDefense);
        sub_004521C0_PrefixLevelText(wszDefense, 0);
        sub_00526700(wszStats, wszDefense);
    }

    sub_0048C060(gpHoverItem_007BCBF4, wszName, 0x100);
    if (ITEMS_CheckItemFlag(gpHoverItem_007BCBF4, 0x100, 0xDDB, ".\\UI\\inv.cpp"))
    {
        sub_004521C0_PrefixLevelText(wszName, 1);
    }
    else
    {
        sub_004521C0_PrefixLevelText(wszName, 2);
    }
    sub_00526700(wszStats, wszName);

    wszProps[0].wChar = 0;
    if (ITEMS_CheckItemFlag(gpHoverItem_007BCBF4, 0x800, 0xDE4, ".\\UI\\inv.cpp"))
    {
        Unicode wszSockets[300];
        sub_00484B10_AppendEtherealSocketed(gpHoverItem_007BCBF4, wszSockets);
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
        if (pSetItem->wStrName)
        {
            sub_0048BE80_FormatArgs(wszText, D2LANG_GetStringFromTblIndex(0x2769), D2LANG_GetStringFromTblIndex(pSetItem->wStrName), 0);
            sub_00526700(wszText, pNewline);
        }

        if (pFound)
            sub_004521C0_PrefixLevelText(wszText, 2);
        else
            sub_004521C0_PrefixLevelText(wszText, 1);
        sub_00526700(wszSetItems, wszText);
    }

    sub_005267E0(wszText, sub_004521C0_PrefixLevelText(wszSetItems, 2));
    sub_00526700(wszText, sub_004521C0_PrefixLevelText(wszSetName, 4));
    if (wszStateProps[0].wChar)
    {
        sub_00526700(wszText, pNewline);
        sub_00526700(wszText, sub_004521C0_PrefixLevelText(wszStateProps, 4));
    }
    sub_00526700(wszText, pNewline);
    if (wszSetProps[0].wChar)
        sub_00526700(wszText, sub_004521C0_PrefixLevelText(wszSetProps, 2));
    sub_00526700(wszText, sub_004521C0_PrefixLevelText(wszProps, 3));
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
            if (sub_004B2AD0_GetTradeCostText(gpHoverItem_007BCBF4, gnGlobal_00721E38, &nCost, wszCost, 0x40))
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
                    sub_00526700(wszPopup, sub_004521C0_PrefixLevelText(wszNote, 1));
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
