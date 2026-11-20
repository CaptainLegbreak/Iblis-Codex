#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct UnicodeChar;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch)
    {
    }
};

struct UnicodeChar
{
    unsigned short wChar;

    UnicodeChar();                                                                                          // 0x0042F530
    UnicodeChar(unsigned short ch) : wChar(ch)
    {
    }
};



extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char gszFmtInt_006D6454[]; // 0x006D6454
extern "C" const char gszUiCpp_006D6458[]; // 0x006D6458
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
void __fastcall sub_0048C060_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
int __cdecl sub_0047A980_IsNumberDisplayEnabled(); // 0x0047A980
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __fastcall sub_00479B80_GetRecordValue(D2StoredUnitRecordStrc* pRecord); // 0x00479B80
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004527D0
void __fastcall sub_004527D0_BuildItemHoverName(D2UnitStrc* pUnit, Unicode* pOut, int nMaxLength)
{
    gnHoverY_0070F858 -= 0x10;
    if (!pUnit)
        return;

    const Unicode* pName = sub_00464A60_GetUnitName(pUnit);
    int nColor = 0;
    switch (ITEMS_GetItemQuality(pUnit))
    {
    case 6:
        nColor = 9;
        break;
    case 8:
        nColor = 8;
        break;
    case 9:
        nColor = 10;
        break;
    case 4:
        nColor = 3;
        break;
    case 5:
        nColor = 2;
        break;
    case 7:
        nColor = 4;
        break;
    default:
        if (ITEMS_CheckItemFlag(pUnit, 0x800, 0x5AA, gszUiCpp_006D6458))
            nColor = 5;
        else if (ITEMS_CheckItemFlag(pUnit, 0x400000, 0x5AE, gszUiCpp_006D6458))
            nColor = 5;
        break;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    if (pItemsTxtRecord->nQuest && pItemsTxtRecord->dwCode != 0x2067656C)
        nColor = 4;

    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    if (dwCode == 0x20686563 || dwCode == 0x20746562 || dwCode == 0x20736574 || dwCode == 0x20646566
        || dwCode == 0x20616F74 || dwCode == 0x206E6864 || dwCode == 0x20796562 || dwCode == 0x2072626D
        || dwCode == 0x20316B70 || dwCode == 0x20326B70 || dwCode == 0x20336B70 || ITEMSIsA(pUnit, 0x4A))
        nColor = 8;

    Unicode wszText[0x80] = { 0 };
    if (ITEMS_GetItemType(pUnit) == 4)
    {
        char szGold[10];
        const int nGold = STATLIST_UnitGetStatValue(pUnit, 0xE, 0);
        Unicode wszGold[10];
        wsprintfA(szGold, gszFmtInt_006D6454, nGold);
        sub_00526F20(wszGold, szGold, 9);
        sub_005267E0(wszText, wszGold);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, pName);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText(wszText, gnHoverX_0070F854, gnHoverY_0070F858, nColor, 1);
            return;
        }

        sub_004521C0_PrefixLevelText(wszText, nColor);
        D2_ASSERT(sub_00526800(wszText) < nMaxLength, 0x5E0);
        sub_005267E0(pOut, wszText);
        return;
    }
    else if (pUnit)
    {
        UnicodeChar wszItem[0x80] = { 0 };
        sub_0048C060_BuildItemName(pUnit, (Unicode*)wszItem, 0x100);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText((Unicode*)wszItem, gnHoverX_0070F854, gnHoverY_0070F858, nColor, 1);
            return;
        }

        sub_004521C0_PrefixLevelText((Unicode*)wszItem, nColor);
        D2_ASSERT(sub_00526800((Unicode*)wszItem) < nMaxLength, 0x5EB);
        sub_005267E0(pOut, (Unicode*)wszItem);
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00453B30
void __cdecl sub_00453B30_DrawStoredUnitNumber()
{
    if (!sub_0047A980_IsNumberDisplayEnabled())
    {
        return;
    }

    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    if (!pUnit)
    {
        return;
    }

    D2StoredUnitRecordStrc* pRecord = sub_00479BB0_FindRecord(pUnit->dwUnitId);
    if (!pRecord)
    {
        return;
    }

    const int nValue = sub_00479B80_GetRecordValue(pRecord);
    char szText[12];
    Unicode wszText[12];
    wsprintfA(szText, gszFormatD_006D57BC, nValue);
    sub_00526F20_ToUnicode(wszText, szText, 12);
    sub_00502320(wszText, 600, 25, 4, 0);
}
