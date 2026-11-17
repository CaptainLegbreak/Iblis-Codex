struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch)
    {
    }
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ItemsTxt
{
    char unk0x00[0xC8];
    unsigned int dwTransmogrifyType;
    char unk0xCC[0x28];
    unsigned short wNameStr;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
extern "C" const char szFmtLong_006D9BE8[];                                                                 // 0x006D9BE8
Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
void __fastcall sub_0048C060(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x0048C060
int __fastcall sub_004B2AD0(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength);        // 0x004B2AD0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall sub_0062A0A0(D2UnitStrc* pItem);                                                              // 0x0062A0A0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
extern int gnGlobal_00721E38;                                                                               // 0x00721E38
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4

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

static void __stdcall sub_0048CEA0_AppendItemSetName(const Unicode* pSource, Unicode* pText)
{
    Unicode wszName[0x40] = { 0 };
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gdwGlobal_007BCBF0 == 4 && ITEMS_CheckItemFlag(gdwGlobal_007BCBF4, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        Unicode wszLabel[0x80];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, sub_004521C0_PrefixLevelText(wszLabel, 1));
    }

    int nSetIndex;
    if (sub_004B2AD0(gdwGlobal_007BCBF4, gnGlobal_00721E38, &nSetIndex, wszName, 0x40))
    {
        if (wszName[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, wszName);
        return;
    }

    if (gdwGlobal_007BCBF0 != 4)
    {
        Unicode wszLabel[0x40];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, sub_004521C0_PrefixLevelText(wszLabel, 1));
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048CFF0
void __cdecl sub_0048CFF0_DrawStackTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(gdwGlobal_007BCBF4 && ITEMS_GetItemType(gdwGlobal_007BCBF4) == 0x12, 0xCF1);
    D2_ASSERT(DATATBLS_GetItemsTxtRecord(!gdwGlobal_007BCBF4 ? -1 : gdwGlobal_007BCBF4->dwClassId), 0xCF5);

    sub_00486100_AppendStackQuantity(gdwGlobal_007BCBF4, wszText);
    if (gdwGlobal_007BCBF0 == 0)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89B));
        sub_00526700(wszText, pColorEnd);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89E));
        sub_00526700(wszText, pColorEnd);
    }

    Unicode wszLine[0x80];
    sub_0048C060(gdwGlobal_007BCBF4, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400];
    if (gdwGlobal_007BCBF0 >= 1 && gdwGlobal_007BCBF0 <= 9)
    {
        sub_0048CEA0_AppendItemSetName(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnGlobal_00721E40 - nHeight > 0)
    {
        sub_00502280_SetPopUpText(wszTooltip, gnGlobal_00721E3C, gnGlobal_00721E40, 0, 0);
    }
    else
    {
        sub_00502280_SetPopUpText(wszTooltip, gnGlobal_00721E44, gnGlobal_00721E48 + nHeight, 0, 0);
    }
}
