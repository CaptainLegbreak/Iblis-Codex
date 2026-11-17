#include "D2Win.h"

struct Unicode
{
    unsigned short wChar;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ItemsTxt
{
    char unk0x00[0xF0];
    unsigned int dwGemOffset;
};

struct D2GemsTxt;
struct D2WinControlStrc;
struct T004F51E0;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_004E6720_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720
void __fastcall sub_004E67D0_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette);                                              // 0x004F63D0
int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName);          // 0x004FB1E0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);              // 0x00526E40
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0
extern T004F51E0 gRGBAPalette_0081E668[];                                                          // 0x0081E668

// 0x004E6850
void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pBuffer, int nSize)
{
    Unicode wszTemp[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszTemp[i].wChar = 0;

    D2_ASSERT(ITEMS_CheckItemTypeId(pItem, 0x35), 0x21A);
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0x21C);
    pBuffer[0].wChar = 0;

    if (ITEMS_CheckItemTypeId(pItem, 0x14))
    {
        D2GemsTxt* pGemsTxt = DATATBLS_GetGemsTxtRecord(pItemsTxt->dwGemOffset);
        D2_ASSERT(pGemsTxt, 0x223);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B42));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E67D0_BuildItemPropText(pItem, (int)pGemsTxt, 2, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B41));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E67D0_BuildItemPropText(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B44));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E67D0_BuildItemPropText(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B43));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E67D0_BuildItemPropText(pItem, (int)pGemsTxt, 0, pBuffer, nSize, (int)wszTemp);
    }
    else if (ITEMS_CheckItemTypeId(pItem, 0x4A))
    {
        D2GemsTxt* pGemsTxt = DATATBLS_GetGemsTxtRecord(pItemsTxt->dwGemOffset);
        D2_ASSERT(pGemsTxt, 0x245);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B42));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E6720_BuildItemPropTextB(pItem, (int)pGemsTxt, 2, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B41));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E6720_BuildItemPropTextB(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B44));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E6720_BuildItemPropTextB(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B43));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_004E6720_BuildItemPropTextB(pItem, (int)pGemsTxt, 0, pBuffer, nSize, (int)wszTemp);
    }
    else
    {
        return;
    }

    sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
}

// 0x004FB480
int __fastcall D2Win_10177(unsigned char nAct)
{
    int nActNo = nAct + 1;
    if (nActNo < 1 || nActNo > 5)
        nActNo = 1;

    char szPL2Filename[260];
    char szDatFilename[260];
    sprintf(szDatFilename, "%s\\palette\\act%d\\%s", szDataGlobal_006D4118, nActNo, "pal.dat");
    sprintf(szPL2Filename, "%s\\palette\\act%d\\%s", szDataGlobal_006D4118, nActNo, "pal.pl2");
    const int nResult = sub_004FB1E0_LoadPaletteFiles(szDatFilename, szPL2Filename);
    D2GFX_SetPalette(gRGBAPalette_0081E668);
    return nResult;
}

// 0x004FCFF0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int a3)
{
    Unicode wszText[1024];
    for (int i = 0; i < 1024; ++i)
        wszText[i].wChar = 0;

    D2_ASSERT(pTextBox, 0x11E);
    sub_00526E40_Utf8ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pTextBox, wszText, a3, 0, 0);
}
