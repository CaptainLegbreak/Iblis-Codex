#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2Unicode.h"
struct UnicodeChar : Unicode
{
    UnicodeChar();
    UnicodeChar(unsigned short ch) : Unicode(ch) {}
};

struct D2InventoryStrc;



struct D2LowQualityItemsTxt
{
    char szName[0x20];
    unsigned short wTblId;
};



struct D2RareAffixTxt
{
    char unk0x00[0x0C];
    unsigned short wStringId;
    char unk0x0E[0x18];
    char szName[0x20];
};



extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
#pragma intrinsic(memset, strcpy, strcat, strlen)

#pragma pack(push, 1)
struct D2LevelTextStrc
{
    char c00;
    int n01;
    int n05;
    int n09;
    int n0D;
    char c11;
};
#pragma pack(pop)

#define WSZ(a) ((Unicode*)(a))
#define SZ(a) ((char*)(a))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall sub_00403040_ConstructVector(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040
void __fastcall sub_0042F530_ClearUnicode(void* pChar);                                                     // 0x0042F530
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nSize, const char* szFormat, ...);             // 0x00413A40
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit);                               // 0x004521C0
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470
const Unicode* __fastcall sub_004834A0_SkipBracketTag(const Unicode* pString); // 0x004834A0
void __cdecl sub_0048BE80_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_00526F20(Unicode* pDest, const char* szSource, int nCount);                  // 0x00526F20
void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefix);                                 // 0x00627EC0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffix);                                 // 0x00627F80
unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0
unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                     // 0x00633EE0
D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId);                                          // 0x00634260
D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nId);                              // 0x006375C0
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                          // 0x0063CD60

static const Unicode* sub_00484A70_GetClassNameText(unsigned int nClass);                                   // 0x00484A70
static int sub_00484C90_FormatEarName(D2UnitStrc* pItem, Unicode* pText);                                   // 0x00484C90
static int __stdcall sub_00484D30_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat); // 0x00484D30

static __declspec(noinline) const Unicode* sub_00484A70_GetClassNameText(unsigned int nClass)
{
    if (nClass < 7)
    {
        switch (nClass)
        {
        case 0:
            return D2LANG_GetStringFromTblIndex(0xFAB);
        case 1:
            return D2LANG_GetStringFromTblIndex(0xFAA);
        case 2:
            return D2LANG_GetStringFromTblIndex(0xFA9);
        case 3:
            return D2LANG_GetStringFromTblIndex(0xFA8);
        case 4:
            return D2LANG_GetStringFromTblIndex(0xFA7);
        case 5:
            return D2LANG_GetStringFromTblIndex(0x2771);
        case 6:
            return D2LANG_GetStringFromTblIndex(0x2772);
        }

        return 0;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x69C);
    exit(-1);
}

static __declspec(noinline) int sub_00484C90_FormatEarName(D2UnitStrc* pItem, Unicode* pText)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x6EA, ".\\UI\\inv.cpp"))
    {
        const int nQuality = ITEMS_GetItemQuality(pItem);
        if (nQuality >= 5 && nQuality <= 9)
        {
            return 0;
        }

        int aName[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aName[i] = 0;
        }
        int aFormatted[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aFormatted[i] = 0;
        }
        sub_00526F20(WSZ(aName), ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(WSZ(aFormatted), WSZ(aName), pText, 0x200, STRTABLE_GetLanguage());
        sub_005267E0(pText, WSZ(aFormatted));
        return 1;
    }

    return 0;
}

static __declspec(noinline) int __stdcall sub_00484D30_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x70B, ".\\UI\\inv.cpp"))
    {
        int aName[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aName[i] = 0;
        }
        sub_00526F20(WSZ(aName), ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(pOut, WSZ(aName), pFormat, 0x200, STRTABLE_GetLanguage());
        return 1;
    }

    return 0;
}

static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    return pUnit->dwClassId;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048C060
void __fastcall sub_0048C060_BuildItemName(D2UnitStrc* pItem, Unicode* pOut, int nMaxLen)
{
    if (pItem)
    {
        D2ItemsTxt* pItemsTxt;
        const Unicode* pStrF9B;
        const Unicode* pNewLine;
        int nItemType;
        int nLen;

        Unicode aPrefix[0x200];
        Unicode aSuffix[0x200];
        Unicode aLine[0x200];

        pStrF9B = D2LANG_GetStringFromTblIndex(0xF9B);
        pNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
        nLen = 0;
        pItemsTxt = DATATBLS_GetItemsTxtRecord(sub_00623C60(pItem));
        D2_ASSERT(pItemsTxt, 0x732);

        nItemType = ITEMS_GetItemType(pItem);
        if (ITEMS_CheckItemFlag(pItem, 0x4000000, 0x735, ".\\UI\\inv.cpp"))
        {
            UnicodeChar aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(WSZ(aPrefix), sub_004834A0_SkipBracketTag(WSZ(aName)));
            sub_00526700(WSZ(aPrefix), pNewLine);
            const Unicode* pRuneName = D2LANG_GetStringFromTblIndex(ITEMS_GetPrefixId(pItem, 0));
            if (pRuneName)
            {
                sub_005267E0(WSZ(aSuffix), pRuneName);
            }
            else
            {
                sub_005267E0(WSZ(aSuffix), pStrF9B);
            }
            sub_00526700(WSZ(aLine), WSZ(aSuffix));
            sub_004521C0_PrefixLevelText(WSZ(aLine), 4);
            sub_00526700(pOut, WSZ(aPrefix));
            sub_00526700(pOut, WSZ(aLine));
        }
        else if (ITEMS_CheckItemFlag(pItem, 0x10, 0x748, ".\\UI\\inv.cpp"))
        {
            switch (ITEMS_GetItemQuality(pItem))
            {
            case 1:
            {
                D2LowQualityItemsTxt* pLowQuality = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pLowQuality)
                {
                    sub_0048BE80_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B0), D2LANG_GetStringFromTblIndex(pLowQuality->wTblId), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                }
                break;
            }
            case 2:
            {
                if (!ITEMSIsA(pItem, 0x16) && !ITEMSIsA(pItem, 0x12))
                {
                    if (ITEMSIsA(pItem, 7))
                    {
                        char szLevel[18] = { 0 };
                        UnicodeChar aEarName[0x100];
                        UnicodeChar aLevelText[3];
                        SStrPrintf(szLevel, 3, "%d", ITEMS_GetEarLevel(pItem));
                        sub_00526F20(WSZ(aLevelText), szLevel, 3);
                        UnicodeChar aUnused[0x100];
                        char aName[20];
                        strcpy(SZ(aName), ITEMS_GetEarName(pItem));
                        sub_00526F20(WSZ(aEarName), SZ(aName), 0x100);
                        if (ITEMS_CheckItemFlag(pItem, 0x8000, 0x775, ".\\UI\\inv.cpp"))
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x1406));
                            sub_00526700(pOut, pNewLine);
                            sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        else
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        sub_00526700(pOut, WSZ(aLevelText));
                        sub_00526700(pOut, pNewLine);
                        sub_00526700(pOut, sub_00484A70_GetClassNameText(ITEMS_GetFileIndex(pItem)));
                        sub_00526700(pOut, pNewLine);
                        UnicodeChar aText[100] = { 0 };
                        UnicodeChar aFormat[0x200];
                        sub_005267E0(WSZ(aFormat), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                        sub_005272B0_FormatText(WSZ(aText), WSZ(aEarName), WSZ(aFormat), 100, STRTABLE_GetLanguage());
                        sub_00526700(pOut, WSZ(aText));
                    }
                    else if (ITEMSIsA(pItem, 0x28))
                    {
                        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(ITEMS_GetFileIndex(pItem));
                        sub_0048BE80_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B4), D2LANG_GetStringFromTblIndex(pMonStatsTxt->wNameStr), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                    }
                    else
                    {
                        D2InventoryStrc* pInventory = pItem->pInventory;
                        if (ITEMS_CheckItemFlag(pItem, 0x800, 0x799, ".\\UI\\inv.cpp") && pInventory && INVENTORY_GetItemCount(pInventory))
                        {
                            sub_0048BE80_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B3), D2LANG_GetStringFromTblIndex(0x6C0), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                        }
                        else
                        {
                            UnicodeChar aName[0x200];
                            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                            sub_005267E0(pOut, sub_004834A0_SkipBracketTag(WSZ(aName)));
                        }
                    }
                }
                else
                {
                    switch (ITEMS_GetSuffixId(pItem, 0))
                    {
                    case 0:
                    {
                        int nString = 0x897;
                        if (nItemType != 0x12)
                        {
                            nString = 0x898;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    case 1:
                    {
                        int nString = 0x899;
                        if (nItemType != 0x12)
                        {
                            nString = 0x89A;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    }
                }
                break;
            }
            case 3:
                sub_0048BE80_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6AF), D2LANG_GetStringFromTblIndex(0x6BF), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                break;
            case 6:
            case 8:
            case 9:
            {
                D2RareAffixTxt* pRarePrefix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRarePrefixId(pItem));
                D2RareAffixTxt* pRareSuffix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRareSuffixId(pItem));
                if (pRarePrefix)
                {
                    if (pRarePrefix->wStringId)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRarePrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pRareSuffix)
                {
                    if (pRareSuffix->wStringId)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                    }
                    else
                    {
                        UnicodeChar aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRareSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        nLen += sub_00526800(WSZ(aTemp));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), WSZ(aTemp));
                        }
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x822);
                D2_ASSERT(nLen < nMaxLen, 0x822);

                UnicodeChar aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                sub_005267E0(WSZ(aLine), sub_004834A0_SkipBracketTag(WSZ(aName)));
                sub_00526700(WSZ(aLine), pNewLine);
                UnicodeChar aFormat[200] = { 0 };
                sub_0048BE80_FormatArgs(WSZ(aFormat), D2LANG_GetStringFromTblIndex(0x6B6), WSZ(aPrefix), WSZ(aSuffix), 0);
                UnicodeChar aEar[0x200];
                if (sub_00484D30_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aFormat)))
                {
                    sub_00526700(WSZ(aLine), WSZ(aEar));
                }
                else
                {
                    sub_00526700(WSZ(aLine), WSZ(aFormat));
                }
                sub_00526700(pOut, WSZ(aLine));
                break;
            }
            case 7:
            {
                UnicodeChar aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                if (ITEMS_GetFileIndex(pItem) < 0)
                {
                    sub_005267E0(pOut, sub_004834A0_SkipBracketTag(WSZ(aName)));
                    break;
                }
                D2UniqueItemsTxt* pUniqueItemsTxt = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (!pUniqueItemsTxt)
                {
                    sub_005267E0(pOut, sub_004834A0_SkipBracketTag(WSZ(aName)));
                    break;
                }
                if (!pItemsTxt->nSkipName)
                {
                    sub_005267E0(pOut, sub_004834A0_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                }
                UnicodeChar aEar[0x200];
                if (sub_00484D30_FormatEarNameTo(pItem, WSZ(aEar), sub_004834A0_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex))))
                {
                    sub_00526700(pOut, WSZ(aEar));
                }
                else
                {
                    sub_00526700(pOut, sub_004834A0_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex)));
                }
                break;
            }
            case 5:
            {
                D2SetItemsTxt* pSetItemsTxt = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pSetItemsTxt)
                {
                    UnicodeChar aName[0x200];
                    sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                    sub_005267E0(pOut, sub_004834A0_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                    if (pSetItemsTxt->wTblIndex)
                    {
                        UnicodeChar aEar[0x200];
                        UnicodeChar aSetName[0x200];
                        sub_005267E0(WSZ(aSetName), D2LANG_GetStringFromTblIndex(pSetItemsTxt->wTblIndex));
                        if (sub_00484D30_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aSetName)))
                        {
                            sub_00526700(pOut, WSZ(aEar));
                        }
                        else
                        {
                            UnicodeChar aText[100] = { 0 };
                            sub_0048BE80_FormatArgs(WSZ(aText), D2LANG_GetStringFromTblIndex(0x2769), WSZ(aSetName), 0);
                            sub_00526700(pOut, WSZ(aText));
                        }
                    }
                }
                break;
            }
            case 4:
            {
                D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
                D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
                if (pPrefix)
                {
                    if (pPrefix->wTblIndex)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pPrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pSuffix)
                {
                    if (pSuffix->wTblIndex)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                        sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                    }
                    else
                    {
                        UnicodeChar aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen += strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                sub_0048BE80_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B2), WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), WSZ(aSuffix), 0);
                break;
            }
            default:
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x8CE);
                exit(-1);
            }
        }
        else
        {
            UnicodeChar aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(pOut, sub_004834A0_SkipBracketTag(WSZ(aName)));
        }

        sub_00484C90_FormatEarName(pItem, pOut);
        sub_00452170(pOut);
        if (pItemsTxt->nQuest)
        {
            if (pItemsTxt->nQuestDiffCheck && STATLIST_UnitGetStatValue(pItem, 0x164, 0) < sub_0044DCD0_GetDifficulty())
            {
                sub_004521C0_PrefixLevelText(pOut, 1);
            }
            else if (pItemsTxt->dwCode != 0x2067656C)
            {
                sub_004521C0_PrefixLevelText(pOut, 4);
            }
        }
    }
}
