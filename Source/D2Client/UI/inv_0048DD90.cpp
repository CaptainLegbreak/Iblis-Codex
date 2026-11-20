#include "D2Structs.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

struct Unicode
{
    unsigned short wChar;
};

struct D2InventoryStrc;


struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x1A];
    short nStat;
    char unk0xA0[0x04];
    unsigned int nCalc;
    char unk0xA8[0x0C];
    unsigned char nDescType;
    char unk0xB5;
    unsigned short wStringId;
    char unk0xB8[0x38];
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
    char unk0x112[0x18];
    unsigned char nQuest;
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

struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2InvCompGridStrc
{
    D2InvRectStrc rect;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned short pad0x12;
};

struct UBuf
{
    unsigned int d;

    UBuf() : d(0)
    {
    }
};

struct UNum10
{
    unsigned short w0, w1, w2, w3, w4, w5, w6, w7, w8, w9;

    UNum10() : w0(0), w1(0), w2(0), w3(0), w4(0), w5(0), w6(0), w7(0), w8(0), w9(0)
    {
    }
};

#define W(x) ((Unicode*)(x))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
void __stdcall sub_00403040_VectorCtor(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040
void __fastcall sub_0042F530_UnicodeCtor(void* pThis);                                                      // 0x0042F530
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __cdecl sub_00468830();                                                                                 // 0x00468830
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB);                                         // 0x0046A530
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
void __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText);                                // 0x00485410
void __stdcall sub_00485EE0_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText);            // 0x00485EE0
void __fastcall sub_0048C060(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x0048C060
void __cdecl sub_0048CFF0_DrawStackTooltip();                                                               // 0x0048CFF0
void __fastcall sub_0048D1D0_DrawSetItemTooltip(D2UnitStrc* pUnit);                                         // 0x0048D1D0
void __cdecl sub_0048DB80_DrawBaseItemTooltip();                                                            // 0x0048DB80
int __cdecl sub_004979E0();                                                                                 // 0x004979E0
int __cdecl sub_004B34A0();                                                                                 // 0x004B34A0
int __cdecl sub_004B3500();                                                                                 // 0x004B3500
int __fastcall sub_004B2AD0(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength);        // 0x004B2AD0
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410
void __fastcall sub_004E6850(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x004E6850
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
unsigned int __fastcall sub_00526800(const Unicode* pString);                                             // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall sub_00625560(D2UnitStrc* pUnit, int nStatId, int nLayer);                                     // 0x00625560
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625E60
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625EF0
int __stdcall sub_00626020_GetUnitDefense(D2UnitStrc* pUnit);                                               // 0x00626020
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc);       // 0x00627C20
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);                                                // 0x006299B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062A0A0(D2UnitStrc* pItem);                                                              // 0x0062A0A0
int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue);                              // 0x0062A5D0
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue);                              // 0x0062A620
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem);                             // 0x0062A710
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall sub_0062BA60_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit);                       // 0x0062BA60
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall sub_0062C060_IsClassItem(D2UnitStrc* pItem);                                                  // 0x0062C060
int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem);                                             // 0x0062C0B0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);   // 0x0063AD50
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
void* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);                // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, void* pSkill, int bBonus);                            // 0x006442A0
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId);                    // 0x00645C10
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00

extern "C" const char szFmtLong_006D9BE8[];                                                                 // 0x006D9BE8
extern "C" const char szFmtInt_006D6454[];                                                                  // 0x006D6454
extern "C" const char szQuote_006D9BF4[];                                                                   // 0x006D9BF4
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_00721E38;                                                                               // 0x00721E38
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern D2SpeedNameStrc gaSpeedNames_00721E88[6];                                                            // 0x00721E88
extern D2ItemTypeNameStrc gaItemTypeNames_00721EB0[15];                                                     // 0x00721EB0
extern int gaSpeedTable_00721F10[][5];                                                                      // 0x00721F10
extern int gaClassSpeedOffsets_00722078[][2];                                                               // 0x00722078
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int gdwGlobal_007BCBE4;                                                                                     // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
D2UnitStrc* gdwGlobal_007BCBF4;                                                                             // 0x007BCBF4
extern D2InvCompGridStrc gaCompGrids_007BCC58[11];                                                          // 0x007BCC58

static void __stdcall sub_00484B10_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText);              // 0x00484B10
static void __stdcall sub_00484DB0_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText); // 0x00484DB0
static void __stdcall sub_00484E90_AppendDurability(D2UnitStrc* pItem, Unicode* pText);                    // 0x00484E90
static void __stdcall sub_00484FF0_AppendNumberLine(int nValue, Unicode* pText);                           // 0x00484FF0
static void __stdcall sub_004850A0_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText);        // 0x004850A0
static void __stdcall sub_00485170_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText);        // 0x00485170
static void __stdcall sub_00485BE0_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem); // 0x00485BE0
static void __stdcall sub_00485D40_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText); // 0x00485D40
static void __stdcall sub_00486100_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText);                 // 0x00486100
static void __stdcall sub_004861D0_AppendAttackSpeed(Unicode* pText, D2UnitStrc* pItem);                   // 0x004861D0
static void __stdcall sub_00486370_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemsTxt* pRecord, Unicode* pBuffer); // 0x00486370
static void sub_004865D0_AppendBookCharges(Unicode* pText);                                                 // 0x004865D0
static void __stdcall sub_00486670_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem);            // 0x00486670
static int sub_00486860_IsOverWeaponSwapTab(int nX, int nY);                                                // 0x00486860
static void __stdcall sub_0048CEA0_AppendItemSetName(const Unicode* pSource, Unicode* pText);              // 0x0048CEA0

// 0x00484B10
static __declspec(noinline) void __stdcall sub_00484B10_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText)
{
    int bEthereal = 0;
    unsigned int wszLabel[8];
    memset(wszLabel, 0, sizeof(wszLabel));
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_00526F20(W(wszLabel), &gszEmptyAssertText, 15);
    sub_005267E0(pText, W(wszLabel));
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x6C1, ".\\UI\\inv.cpp"))
    {
        sub_00526F20(W(wszLabel), "Ethereal", 15);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x58D9));
        bEthereal = 1;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x800, 0x6C9, ".\\UI\\inv.cpp"))
    {
        if (bEthereal)
        {
            sub_00526F20(W(wszLabel), ", ", 15);
            sub_00526700(pText, W(wszLabel));
        }
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD7D));
        UNum10 wszNumber;
        unsigned int szNumber[3];
        const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
        SStrPrintf((char*)szNumber, 10, "(%i)", ITEMS_GetSockets(pItem));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
        return;
    }
    if (bEthereal)
    {
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484DB0
static __declspec(noinline) void __stdcall sub_00484DB0_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf((char*)szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, 0x46, 0));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
    }
}

// 0x00484E90
static __declspec(noinline) void __stdcall sub_00484E90_AppendDurability(D2UnitStrc* pItem, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
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
        SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, STATLIST_UnitGetStatValue(pItem, 0x48, 0));
        sub_00526700(pText, pColorStart);
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD87));
        sub_00526700(pText, pColorStart);
        SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, STATLIST_GetMaxDurabilityFromUnit(pItem));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        if (bBonus)
        {
            sub_004521C0_PrefixLevelText(W(&wszNumber), 3);
        }
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484FF0
static __declspec(noinline) void __stdcall sub_00484FF0_AppendNumberLine(int nValue, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD8D));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

// 0x004850A0
static __declspec(noinline) void __stdcall sub_004850A0_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqStr + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD82));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

// 0x00485170
static __declspec(noinline) void __stdcall sub_00485170_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqDex + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD83));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

// 0x00485D40
static __declspec(noinline) void __stdcall sub_00485D40_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
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
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nMin);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD88));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nMax);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

// 0x00486100
static __declspec(noinline) void __stdcall sub_00486100_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, 0x46, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf((char*)szNumber, 10, szFmtLong_006D9BE8, STATLIST_UnitGetStatValue(pItem, 0x46, 0));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00485BE0
static __declspec(noinline) void __stdcall sub_00485BE0_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem)
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
    UBuf wszBlock[16];
    unsigned int szBlock[8];
    UBuf wszText[128];
    SStrPrintf((char*)szBlock, 32, "%d%%\n", nBlock);
    sub_00526F20(W(wszBlock), (char*)szBlock, 32);
    if (nBlock > pItemsTxt->nBlock)
    {
        sub_004521C0_PrefixLevelText(W(wszBlock), 3);
    }
    sub_005267E0(W(wszText), D2LANG_GetStringFromTblIndex(0x2B0A));
    sub_004521C0_PrefixLevelText(W(wszText), 0);
    sub_005267E0(pText, W(wszText));
    sub_00526700(pText, W(wszBlock));
}

// 0x004861D0
static __declspec(noinline) void __stdcall sub_004861D0_AppendAttackSpeed(Unicode* pText, D2UnitStrc* pItem)
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
    UBuf wszText[128];
    sub_005267E0(W(wszText), D2LANG_GetStringFromTblIndex(gaSpeedNames_00721E88[nSpeed].f_0));
    if (bBonus)
    {
        sub_004521C0_PrefixLevelText(W(wszText), 3);
    }
    sub_00526700(pText, W(wszText));
    sub_00526700(pText, pColorEnd);
}

// build: context sub_00486370_AppendItemFormulaText
static __declspec(noinline) void __stdcall sub_00486370_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemsTxt* pRecord, Unicode* pBuffer)
{
    if (!pItem || !pRecord || !pRecord->nDescType)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || pRecord->wStringId == 0x1506)
    {
        return;
    }

    const Unicode* pSeparator = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pLineEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    switch (pRecord->nDescType)
    {
    case 1:
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        sub_00526700(pBuffer, pLineEnd);
        break;

    case 2:
    {
        unsigned int szValue[3];
        unsigned int wszValue[5];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        switch (pRecord->nStat)
        {
        case 6:
        case 74:
            nValue = ITEMS_GetBonusLifeBasedOnClass(pPlayer, nValue);
            break;
        case 8:
        case 26:
            nValue = ITEMS_GetBonusManaBasedOnClass(pPlayer, nValue);
            break;
        }
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf((char*)szValue, 10, szFmtLong_006D9BE8, nValue);
        sub_00526F20(W(wszValue), (char*)szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, W(wszValue));
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 3:
    {
        unsigned int szValue[3];
        unsigned int wszValue[5];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf((char*)szValue, 10, szFmtLong_006D9BE8, nValue);
        sub_00526F20(W(wszValue), (char*)szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, W(wszValue));
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 4:
    {
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        unsigned int wszText[0x100];
        sub_005269D0(0x200, W(wszText), D2LANG_GetStringFromTblIndex(pRecord->wStringId), nValue);
        sub_00526700(pBuffer, W(wszText));
        sub_00526700(pBuffer, pLineEnd);
        break;
    }
    }
}

// 0x004865D0
static __declspec(noinline) void sub_004865D0_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x35), 0xC43);
    sub_004E6850(gdwGlobal_007BCBF4, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

// build: context sub_00486670_AppendSocketedGemLetters
static __declspec(noinline) void __stdcall sub_00486670_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return;
    }
    unsigned int wszLetter[3];
    int bAny = 0;
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pGem = INVENTORY_UnitIsItem(pNode);
        if (!pGem)
        {
            break;
        }
        if (ITEMS_CheckItemTypeId(pGem, 0x4A))
        {
            const int nClassId = pGem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            const int nGemOffset = pItemsTxtRecord->nGemOffset;
            if (nGemOffset > 0)
            {
                D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(nGemOffset);
                if (pGemsTxtRecord)
                {
                    if (!bAny)
                    {
                        bAny = 1;
                        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x501A));
                    }
                    sub_00526320_ToUnicode(W(wszLetter), pGemsTxtRecord->szLetter, 6);
                    sub_00526700(pText, W(wszLetter));
                }
            }
        }
    }
    if (bAny)
    {
        sub_00526320_ToUnicode(W(wszLetter), szQuote_006D9BF4, 5);
        sub_00526700(pText, W(wszLetter));
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00486820
static int __stdcall sub_00486820_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

// 0x00486860
static __declspec(noinline) int sub_00486860_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids_007BCC58[5].rect.nLeft && nX <= gaCompGrids_007BCC58[5].rect.nRight && nY >= gaCompGrids_007BCC58[5].rect.nTop - 0x18 && nY < gaCompGrids_007BCC58[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids_007BCC58[4].rect.nLeft && nX <= gaCompGrids_007BCC58[4].rect.nRight && nY >= gaCompGrids_007BCC58[4].rect.nTop - 0x18 && nY < gaCompGrids_007BCC58[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

// build: context sub_0048CEA0_AppendItemSetName
static __declspec(noinline) void __stdcall sub_0048CEA0_AppendItemSetName(const Unicode* pSource, Unicode* pText)
{
    unsigned int wszName[0x20];
    memset(wszName, 0, sizeof(wszName));
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gdwGlobal_007BCBF0 == 4 && ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        unsigned int wszLabel[0x40];
        sub_005267E0(W(wszLabel), D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, sub_004521C0_PrefixLevelText(W(wszLabel), 1));
    }

    int nSetIndex;
    if (sub_004B2AD0(gdwGlobal_007BCBF4, gnGlobal_00721E38, &nSetIndex, W(wszName), 0x40))
    {
        if (W(wszName)[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, W(wszName));
        return;
    }

    if (gdwGlobal_007BCBF0 != 4)
    {
        unsigned int wszLabel[0x20];
        sub_005267E0(W(wszLabel), D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, sub_004521C0_PrefixLevelText(W(wszLabel), 1));
    }
}

static int sub_00623C60(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x0048DD90
void __stdcall sub_0048DD90_DrawItemTooltip(D2UnitStrc* pUnit, int nFlag)
{
    UBuf wszText[0x200];
    UBuf wszTooltip[0x200];
    UBuf wszBookCharges[0x100];
    UBuf wszMisc[0x80];
    UBuf wszGems[0x80];
    UBuf wszDurability[0x80];
    UBuf wszLevelReq[0x80];
    UBuf wszReqStr[0x80];
    UBuf wszReqDex[0x80];
    UBuf wszDamage[0x80];
    UBuf wszBlock[0x80];
    UBuf wszThrowDamage[0x80];
    UBuf wszDefense[0x80];
    UBuf wszUnidentified[0x80];
    UBuf wszClassReq[0x80];
    UBuf wszEthSock[0x80];
    UBuf wszFormula[0x80];
    UBuf wszAttackSpeed[0x200];
    int nPopupArg = 0;
    UBuf wszName[0x200];
    UBuf wszProps[0x800];
    int nColor = 0;
    int bRedLevel = 0;
    int bRedStr = 0;
    int bRedDex = 0;
    int bRedClass = 0;
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2UnitStrc* pPlayer = pUnit;
    if (nFlag && sub_00463DD0())
    {
        pPlayer = sub_00463DD0();
    }

    const int bHoverBlocked = sub_004979E0();
    if (!bHoverBlocked)
    {
        if (sub_004538D0(0x24))
        {
            if (sub_00486820_IsMouseInBox(gnGlobal_007A2858 + 0x110, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x20, 0x20))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_007A2858 + 0x11F, gnGlobal_007A285C + gnGlobal_00711470 - 0x62, 0, 1);
            }
        }

        if (sub_004538D0(1) || sub_004538D0(0x17) || sub_004538D0(0x19) || sub_004538D0(0xC) || sub_004538D0(0xE) || sub_004538D0(0x1A))
        {
            if (sub_00486820_IsMouseInBox(gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E, gnGlobal_00711470 + gnGlobal_007A285C - 0x40, 0x20, 0x20))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0x11F, gnGlobal_00711470 + (gnGlobal_007A285C - 0x63), 0, 1);
            }

            if (sub_00486820_IsMouseInBox(gnGlobal_0071146C - gnGlobal_007A2858 - 0xED, gnGlobal_007A285C + gnGlobal_00711470 - 0x45, 0x14, 0x12) && !sub_004B34A0())
            {
                int nStr = 0x101D;
                switch (gdwGlobal_007BCBF0)
                {
                case 1:
                    nStr = 0x1003;
                    break;
                case 12:
                case 13:
                case 15:
                    nStr = 0x101E;
                    break;
                case 11:
                    nStr = 0x1021;
                    break;
                }
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(nStr), gnGlobal_0071146C - gnGlobal_007A2858 - 0xDE, gnGlobal_00711470 + (gnGlobal_007A285C - 0x59), 0, 1);
            }

            if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0() && sub_00486860_IsOverWeaponSwapTab(sub_00468730(), sub_00468740()))
            {
                unsigned int wszSwap[0x100];
                sub_00403040_VectorCtor(wszSwap, 2, 0x200, sub_0042F530_UnicodeCtor);
                sub_005267E0(W(wszSwap), D2LANG_GetStringFromTblIndex(0x58C6));
                if (sub_00469AA0(0x2C, 1) != 0xFFFF)
                {
                    sub_00526700(W(wszSwap), D2LANG_GetStringFromTblIndex(0xF9D));
                    sub_00526700(W(wszSwap), sub_0046A530_GetKeyName(0x2C, 1));
                }
                else if (sub_00469AA0(0x2C, 0) != 0xFFFF)
                {
                    sub_00526700(W(wszSwap), D2LANG_GetStringFromTblIndex(0xF9D));
                    sub_00526700(W(wszSwap), sub_0046A530_GetKeyName(0x2C, 0));
                }
                int nOffset = 0x170;
                if (sub_00468730() > gnGlobal_007A2858 + 0x1F4)
                {
                    nOffset = 0x258;
                }
                sub_00502280_SetPopUpText(W(wszSwap), nOffset + gnGlobal_007A2858, 0x15 - gnGlobal_007A285C, 0, 1);
            }
        }
    }

    if ((gdwGlobal_007BCBE8 || gdwGlobal_007BCBE4) && gdwGlobal_007BCBF4)
    {
        if (pUnit->pInventory && !INVENTORY_GetCursorItem(pUnit->pInventory))
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!sub_004538D0(0x17) && pInventory && gdwGlobal_007BCBF4 && !INVENTORY_CompareWithItemsParentInventory(pInventory, gdwGlobal_007BCBF4))
            {
                return;
            }

            int nWidth;
            int nHeight;
            if (gdwGlobal_007BCBE4 && !gnGlobal_00721E38 && sub_004B3500() && (unsigned int)(gdwGlobal_007BCBF0 - 1) <= 8)
            {
                sub_0048C060(gdwGlobal_007BCBF4, W(wszName), 0x80);
                sub_005267E0(W(wszUnidentified), D2LANG_GetStringFromTblIndex(0xD7F));
                sub_00526700(W(wszUnidentified), pColorEnd);
                sub_00526700(W(wszText), W(wszUnidentified));
                switch (ITEMS_GetItemType(gdwGlobal_007BCBF4))
                {
                case 0x3C:
                case 0x55:
                case 0x56:
                case 0x57:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA5));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x3D:
                case 0x47:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA9));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x3E:
                case 0x45:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA7));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x3F:
                case 0x46:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA8));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x40:
                case 0x44:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA6));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x41:
                case 0x43:
                case 0x58:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AAB));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x42:
                case 0x48:
                case 0x49:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AAA));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                }
                sub_00526700(W(wszText), W(wszName));
                sub_004521C0_PrefixLevelText(W(wszText), 0);
                sub_0048CEA0_AppendItemSetName(W(wszText), W(wszTooltip));
                D2Win_10131_GetTextDimensions(W(wszTooltip), &nWidth, &nHeight);
                if (gnGlobal_00721E40 - nHeight > 0)
                {
                    sub_00502280_SetPopUpText(W(wszTooltip), gnGlobal_00721E3C, gnGlobal_00721E40, 0, 1);
                }
                else
                {
                    sub_00502280_SetPopUpText(W(wszTooltip), gnGlobal_00721E44, gnGlobal_00721E48 + nHeight, 0, 1);
                }
                return;
            }

            const int nQuality = ITEMS_GetItemQuality(gdwGlobal_007BCBF4);
            if (sub_00468830() == 8 || sub_0062A0A0(gdwGlobal_007BCBF4))
            {
                sub_0048DB80_DrawBaseItemTooltip();
                return;
            }
            if (nQuality == 5 && ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x10, 0xF9F, ".\\UI\\inv.cpp"))
            {
                sub_0048D1D0_DrawSetItemTooltip(pUnit);
                return;
            }
            if (ITEMS_GetItemType(gdwGlobal_007BCBF4) == 0x12)
            {
                sub_0048CFF0_DrawStackTooltip();
                return;
            }

            const int nClass = sub_0062C0B0_GetItemTypeClass(gdwGlobal_007BCBF4);
            if (nClass != 7)
            {
                sub_00526700(W(wszClassReq), D2LANG_GetStringFromTblIndex(nClass + 0x2AA5));
                sub_00526700(W(wszClassReq), pColorEnd);
                if (sub_00623C60(pPlayer) != nClass)
                {
                    bRedClass = 1;
                }
            }

            D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gdwGlobal_007BCBF4 ? -1 : gdwGlobal_007BCBF4->dwClassId);
            D2_ASSERT(pItemsTxt, 0xFC2);

            if (ITEMS_GetQuiverType(gdwGlobal_007BCBF4))
            {
                sub_00484DB0_AppendQuantity(pItemsTxt, gdwGlobal_007BCBF4, W(wszText));
            }
            else
            {
                sub_00484E90_AppendDurability(gdwGlobal_007BCBF4, W(wszDurability));
            }

            int bStr;
            int bDex;
            ITEMS_CheckRequirements(gdwGlobal_007BCBF4, pPlayer, 0, &bStr, &bDex, &nFlag);
            if (ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x10, 0xFD6, ".\\UI\\inv.cpp"))
            {
                const int nLevelReq = sub_0062BA60_GetLevelRequirement(gdwGlobal_007BCBF4, pPlayer);
                if (nLevelReq > 1)
                {
                    if (!nFlag)
                    {
                        bRedLevel = 1;
                    }
                    sub_00484FF0_AppendNumberLine(nLevelReq, W(wszLevelReq));
                }
            }
            if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x35))
            {
                sub_004865D0_AppendBookCharges(W(wszBookCharges));
            }
            if (ITEMS_CheckIfSocketable(gdwGlobal_007BCBF4))
            {
                sub_00486670_AppendSocketedGemLetters(W(wszGems), gdwGlobal_007BCBF4);
            }
            if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0xD))
            {
                const Unicode* pColorEnd2 = D2LANG_GetStringFromTblIndex(0xF9E);
                sub_00526700(W(wszMisc), D2LANG_GetStringFromTblIndex(0x4FD6));
                sub_00526700(W(wszMisc), pColorEnd2);
            }

            if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x2D) || ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x32))
            {
                sub_00484B10_AppendEtherealSocketed(gdwGlobal_007BCBF4, W(wszEthSock));
                int nStrBonus = 0;
                int nDexBonus = 0;
                const int nPercent = STATLIST_UnitGetItemStatOrSkillStatValue(gdwGlobal_007BCBF4, 0x5B, 0);
                if (nPercent)
                {
                    nStrBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqStr, nPercent, 100);
                    nDexBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqDex, nPercent, 100);
                }
                if (ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x400000, 0xFFA, ".\\UI\\inv.cpp"))
                {
                    nStrBonus -= 10;
                    nDexBonus -= 10;
                }
                if (pItemsTxt->wReqDex > 0)
                {
                    if (!bDex)
                    {
                        bRedDex = 1;
                    }
                    sub_00485170_AppendReqDex(pItemsTxt, nDexBonus, W(wszReqDex));
                }
                if (pItemsTxt->wReqStr > 0)
                {
                    if (!bStr)
                    {
                        bRedStr = 1;
                    }
                    sub_004850A0_AppendReqStr(pItemsTxt, nStrBonus, W(wszReqStr));
                }
                if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x2D))
                {
                    if (STATLIST_GetMinDamageFromUnit(gdwGlobal_007BCBF4, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(gdwGlobal_007BCBF4, 0) >= 0)
                    {
                        sub_00485410_AppendDamage(gdwGlobal_007BCBF4, W(wszDamage));
                    }
                    sub_004861D0_AppendAttackSpeed(W(wszAttackSpeed), gdwGlobal_007BCBF4);
                }
                if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x33))
                {
                    if (pPlayer && pPlayer->dwClassId == 3 && (!sub_0062C060_IsClassItem(gdwGlobal_007BCBF4) || sub_0062C0B0_GetItemTypeClass(gdwGlobal_007BCBF4) == 3))
                    {
                        sub_00485D40_AppendThrowDamage(gdwGlobal_007BCBF4, pItemsTxt, W(wszThrowDamage));
                    }
                    sub_00485BE0_AppendBlockChance(W(wszBlock), pItemsTxt, gdwGlobal_007BCBF4);
                }
                else if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0xF) && pPlayer && pPlayer->dwClassId == 6)
                {
                    sub_00485D40_AppendThrowDamage(gdwGlobal_007BCBF4, pItemsTxt, W(wszThrowDamage));
                }
                if (ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x32) && sub_00626020_GetUnitDefense(gdwGlobal_007BCBF4) > 0)
                {
                    sub_00485EE0_AppendDefense(pPlayer, gdwGlobal_007BCBF4, W(wszDefense));
                }
            }

            switch (nQuality)
            {
            case 7:
                nColor = 4;
                break;
            case 4:
                nColor = 3;
                break;
            case 6:
                nColor = 9;
                break;
            case 8:
                nColor = 8;
                break;
            case 9:
                nColor = 10;
                break;
            case 5:
                nColor = 2;
                break;
            default:
                if (ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x800, 0x1050, ".\\UI\\inv.cpp"))
                {
                    nColor = 5;
                }
                else if (ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x400000, 0x1054, ".\\UI\\inv.cpp"))
                {
                    nColor = 5;
                }
                break;
            }

            if (!ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x10, 0x105D, ".\\UI\\inv.cpp") && (unsigned int)(gdwGlobal_007BCBF0 - 1) <= 8 && !gnGlobal_00721E38)
            {
                nColor = 0;
            }

            if (ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x10, 0x1069, ".\\UI\\inv.cpp"))
            {
                if (!ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x800, 0x106C, ".\\UI\\inv.cpp"))
                {
                    sub_00486100_AppendStackQuantity(gdwGlobal_007BCBF4, W(wszFormula));
                }
                sub_004E6410_BuildPropText(gdwGlobal_007BCBF4, W(wszProps), 0x1000, 1, 0);
            }
            else
            {
                sub_005267E0(W(wszUnidentified), D2LANG_GetStringFromTblIndex(0xD7F));
                sub_00526700(W(wszUnidentified), pColorEnd);
            }
            sub_00486370_AppendItemFormulaText(gdwGlobal_007BCBF4, pItemsTxt, W(wszFormula));
            sub_0048C060(gdwGlobal_007BCBF4, W(wszName), 0x100);
            sub_005267E0(W(wszText), sub_004521C0_PrefixLevelText(W(wszEthSock), 3));

            const unsigned int dwCode = pItemsTxt->dwCode;
            if (dwCode == 0x20686563 || dwCode == 0x20746562 || dwCode == 0x20736574 || dwCode == 0x20646566
                || dwCode == 0x20616F74 || dwCode == 0x206E6864 || dwCode == 0x20796562 || dwCode == 0x2072626D
                || dwCode == 0x20316B70 || dwCode == 0x20326B70 || dwCode == 0x20336B70
                || ITEMS_CheckItemTypeId(gdwGlobal_007BCBF4, 0x4A))
            {
                nColor = 8;
            }

            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszProps), 3));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszUnidentified), 1));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszAttackSpeed), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszLevelReq), bRedLevel));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszReqStr), bRedStr));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszReqDex), bRedDex));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszClassReq), bRedClass));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszDurability), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszBookCharges), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszMisc), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszFormula), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszDamage), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszThrowDamage), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszBlock), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszDefense), 0));
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszGems), 4));
            if (ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x100, 0x10A7, ".\\UI\\inv.cpp"))
            {
                nColor = 1;
            }
            sub_00526700(W(wszText), sub_004521C0_PrefixLevelText(W(wszName), nColor));

            if (gdwGlobal_007BCBF0 && (unsigned int)(gdwGlobal_007BCBF0 - 1) <= 8)
            {
                sub_0048CEA0_AppendItemSetName(W(wszText), W(wszTooltip));
            }
            else
            {
                sub_005267E0(W(wszTooltip), W(wszText));
            }

            if (pItemsTxt->nQuest && pItemsTxt->dwCode != 0x2067656C)
            {
                if (!gdwGlobal_007BCBF0 && (!gdwGlobal_007BCBF4 || !gdwGlobal_007BCBF4->dwAnimMode))
                {
                    if (pItemsTxt->dwCode == 0x20646B62)
                    {
                        sub_005267E0(W(wszText), W(wszTooltip));
                        sub_005267E0(W(wszTooltip), D2LANG_GetStringFromTblIndex(0x89D));
                        sub_00526700(W(wszTooltip), pColorEnd);
                        sub_00526700(W(wszTooltip), W(wszText));
                    }
                    else if (pItemsTxt->dwCode == 0x20786F62)
                    {
                        sub_005267E0(W(wszText), W(wszTooltip));
                        sub_005267E0(W(wszTooltip), D2LANG_GetStringFromTblIndex(0x89C));
                        sub_00526700(W(wszTooltip), pColorEnd);
                        sub_00526700(W(wszTooltip), W(wszText));
                    }
                }
                nPopupArg = 4;
                sub_004521C0_PrefixLevelText(W(wszTooltip), nPopupArg);
            }
            sub_00452170(W(wszTooltip));
            if (sub_00526800(W(wszTooltip)) >= 0x3FF)
            {
                W(wszTooltip)[0x3FF].wChar = 0;
            }
            D2Win_10131_GetTextDimensions(W(wszTooltip), &nWidth, &nHeight);
            if (gnGlobal_00721E40 - nHeight > 0)
            {
                sub_00502280_SetPopUpText(W(wszTooltip), gnGlobal_00721E3C, gnGlobal_00721E40, nPopupArg, 1);
            }
            else
            {
                sub_00502280_SetPopUpText(W(wszTooltip), gnGlobal_00721E44, gnGlobal_00721E48 + nHeight, nPopupArg, 1);
            }
        }
    }
}
