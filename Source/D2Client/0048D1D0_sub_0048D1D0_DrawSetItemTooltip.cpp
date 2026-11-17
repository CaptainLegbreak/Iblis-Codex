struct D2StatListStrc;
struct D2GemsTxt;
struct D2InventoryStrc;

struct Unicode
{
    unsigned short wChar;

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
    Unicode() : wChar(0)
    {
    }
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
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

struct D2CharStatsTxt
{
    char unk0x00[0x49];
    unsigned char nBlockFactor;
    char unk0x4A[0x7A];
};

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

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
    char unk0xBCC[0x4C];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall sub_00625560(D2UnitStrc* pUnit, int nStatId, int nLayer);                                     // 0x00625560
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930
unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem);                                                // 0x006299B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
void* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);                // 0x006439F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, void* pSkill, int bBonus);                            // 0x006442A0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem);                             // 0x0062A710
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId);                    // 0x00645C10

extern "C" const char szFmtLong_006D9BE8[];                                                                 // 0x006D9BE8
extern "C" const char szFmtInt_006D6454[];                                                                  // 0x006D6454
extern "C" const char szQuote_006D9BF4[];                                                                   // 0x006D9BF4
extern D2SpeedNameStrc gaSpeedNames_00721E88[6];                                                            // 0x00721E88
extern D2ItemTypeNameStrc gaItemTypeNames_00721EB0[15];                                                     // 0x00721EB0
extern int gaSpeedTable_00721F10[][5];                                                                      // 0x00721F10
extern int gaClassSpeedOffsets_00722078[][2];                                                               // 0x00722078

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2SetsTxt* __fastcall sub_00483410_GetSetsTxtRecord(int nSetId);                                            // 0x00483410
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
int __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText);                                 // 0x00485410
void __stdcall sub_00485EE0_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText);           // 0x00485EE0
void __cdecl sub_0048BE80_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80
void __fastcall sub_0048C060(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x0048C060
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410
void __fastcall sub_004E6560_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6560
void __fastcall sub_004E6680_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6680
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);  // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625E60
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625EF0
int __stdcall sub_00626020_ArmorValue(D2UnitStrc* pUnit);                                                   // 0x00626020
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit);                              // 0x0062BA60
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem);                                                        // 0x0062C060
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem);                                         // 0x0062C0B0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem);                                                 // 0x0063E020
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90

extern int gnGlobal_00721E38;                                                                               // 0x00721E38
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern D2UnitStrc* gpHoverItem_007BCBF4;                                                                    // 0x007BCBF4

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
