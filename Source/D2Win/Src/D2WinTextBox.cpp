#include "D2Win.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2WinControls.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2WinTypes.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define gnMouseY_007D55A8 (gMousePosition_6F8FE234.y)

struct D2CelFileStrc;

struct D2WinControlStrc;

struct D2WinTextBoxStrc;

struct D2WinListEntry004FBB30Strc;

struct D2WinControl004FBB30Strc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0

void __fastcall sub_004F9740(D2WinControlStrc* pControl, int bSet); // 0x004F9740

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern tagPOINT gMousePosition_6F8FE234; // 0x007D55A4

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

int __stdcall D2Win_10125(); // 0x00501A40

int __stdcall CONTROL_AppendToList(D2WinTextBoxStrc* pControl); // 0x004F9210

D2WinScrollBarStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6); // 0x005084F0

int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox); // 0x00507FD0

extern "C" void __fastcall sub_005080C0_SetScrollBarField50(D2WinScrollBarStrc* pScrollBar, int nValue); // 0x005080C0

int __fastcall TEXTBOX_Draw(D2WinTextBoxStrc* pTextBox); // 0x004FBF30

int __stdcall TEXTBOX_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg); // 0x004FC3F0

int __stdcall TEXTBOX_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);

struct D2WinListEntry004FBB30Strc
{
    void* pData;
    unsigned char f_4[0x18];
    D2WinListEntry004FBB30Strc* pNext1C;
};

struct D2WinControl004FBB30Strc
{
    int eType;
    unsigned char f_4[0x44];
    D2WinListEntry004FBB30Strc* pFirstEntry48;
    unsigned char unk_4C[0x10];
    unsigned int dwFlags5C;
    int nSelected60;
};

int gdwGlobal_00841B70; // 0x00841B70

tagPALETTEENTRY gaPalette_0081E668[256]; // 0x0081E668

struct D2WinTextBoxLineStrc;

struct Unicode;

struct D2WinImageClickRectStrc;

struct D2WinImageStrc;

struct D2CropRectStrc;

struct D2GfxDataStrc;

struct D2CharStrc;

struct D2FontStrc;

struct D2FontCacheStrc;

struct D2GemsTxt;

struct D2UnitStrc;

struct D2ItemsTxt;

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

enum D2WinControlType
{
    D2WIN_TEXTBOX = 4,
};

enum TextBoxFlags
{
    TEXTBOXFLAG_NO_WORD_WRAP = 0x20,
};

int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps); // 0x00507F20

int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep); // 0x00507F60

extern "C" int __fastcall sub_00507FA0_GetScrollBarField4C(D2WinScrollBarStrc* pScrollBar); // 0x00507FA0

int __fastcall sub_00508000_SetScrollCallback(D2WinScrollBarStrc* pScrollBar, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x00508000

extern "C" int __fastcall sub_005080F0_GetScrollBarField50(D2WinScrollBarStrc* pScrollBar); // 0x005080F0

typedef int (__stdcall* D2WinMsgHandler)(struct SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
};

enum DrawMode
{
    DRAWMODE_NORMAL = 5,
};

void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510

int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn); // 0x004FB790

int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern D2FontCacheStrc gFontCache_00841DA8[]; // 0x00841DA8

void __fastcall sub_004E6720_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720

void __fastcall sub_004E67D0_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0

int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName); // 0x004FB1E0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

extern tagPALETTEENTRY gRGBAPalette_0081E668[]; // 0x0081E668

extern "C" const char szD2WinTextBoxCpp_006DC840[]; // 0x006DC840

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0

int __fastcall D2Win_10051(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

int __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

struct D2WinScrollBarStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" int __fastcall sub_00507EF0_GetScrollBarField48(D2WinScrollBarStrc* ptScrollbarData); // 0x00507EF0

extern "C" int __cdecl isspace(int c);                                                                      // 0x00687006

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

int __fastcall sub_004FCDA0_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent); // 0x004FCDA0

static int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox);

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0

void __fastcall sub_00507EE0(void* pArg);                                                                   // 0x00507EE0

void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

void __fastcall sub_005025C0_DrawFramedText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int eDrawMode, int nTextColor); // 0x005025C0

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

void __fastcall sub_00501FE0_DrawTickerText(const Unicode* wszText, int nX, int nY, int nColor, int nScroll, int nWidth); // 0x00501FE0

static void sub_004FB5A0_SetTextBoxLineGap(int nFont);

// 0x004FB1B0
void __cdecl sub_004FB1B0_ApplyPalette()
{
    D2GFX_SetPalette(gaPalette_0081E668);
}

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pBuffer, int nSize)
{
    Unicode wszTemp[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszTemp[i].wChar = 0;

    D2_ASSERT(ITEMSIsA(pItem, 0x35), 0x21A);
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0x21C);
    pBuffer[0].wChar = 0;

    if (ITEMSIsA(pItem, 0x14))
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
    else if (ITEMSIsA(pItem, 0x4A))
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

// 0x004FB5A0
static void sub_004FB5A0_SetTextBoxLineGap(int nFont)
{
    if (sub_00525150() == 7)
    {
        const int nOldFont = sub_00502EF0(nFont);
        if (D2Win_10125() > 13)
        {
            gnTextBoxLineGap_0072DE90 = 8;
        }
        else
        {
            gnTextBoxLineGap_0072DE90 = (D2Win_10125() > 7) + 6;
        }
        sub_00502EF0(nOldFont);
    }
    else if (sub_00525150() == 9)
    {
        const int nOldFont = sub_00502EF0(nFont);
        if (D2Win_10125() > 13)
        {
            gnTextBoxLineGap_0072DE90 = 8;
        }
        else
        {
            gnTextBoxLineGap_0072DE90 = (D2Win_10125() > 7) + 6;
        }
        if (gdwGlobal_00841B70)
        {
            gnTextBoxLineGap_0072DE90 = 3;
        }
        sub_00502EF0(nOldFont);
    }
    else if (sub_00525150() == 6)
    {
        gnTextBoxLineGap_0072DE90 = gdwGlobal_00841B70 != 0 ? 0 : 4;
    }
    else if (sub_00525150() == 10)
    {
        gnTextBoxLineGap_0072DE90 = gdwGlobal_00841B70 != 0 ? 0 : 4;
    }
    else
    {
        gnTextBoxLineGap_0072DE90 = 4;
    }
}

// 0x004FB6A0
int __fastcall D2Win_10047(D2WinTextBoxStrc* ptTextData)
{
    if (!ptTextData)
        return 0;

    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0xDE);

    D2WinTextBoxLineStrc* pNext = 0;
    for (D2WinTextBoxLineStrc* pLine = ptTextData->pFirstLine; pLine; pLine = pNext)
    {
        pNext = pLine->pNext;
        for (int i = 0; i < 5; ++i)
        {
            if (pLine->pColumns[i])
                FOG_Free(pLine->pColumns[i], ".\\Src\\D2WinTextBox.cpp", 0xE7, 0);
        }
        FOG_Free(pLine, ".\\Src\\D2WinTextBox.cpp", 0xE9, 0);
    }

    ptTextData->pCurrentLine = 0;
    ptTextData->pFirstLine = 0;
    ptTextData->pLastLine = 0;
    ptTextData->nNumLines = 0;
    ptTextData->nLine = 0;
    return 1;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FB790
int __fastcall sub_004FB790(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int a3, int nColumn)
{
    D2_ASSERT(pTextBox, 0x1F9);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x1FA);
    D2_ASSERT(pTextBox->nNumColumns > nColumn, 0x1FB);

    Unicode wszText[1024];
    sub_005267E0(wszText, pText);

    D2WinTextBoxLineStrc* ptLine = pTextBox->pFirstLine;
    for (int i = 0; i < a3; ++i)
    {
        if (!ptLine)
            return 1;

        ptLine = ptLine->pNext;
    }

    if (ptLine)
    {
        D2_ASSERT(ptLine->pColumns[nColumn] == 0, 0x20F);
        ptLine->pColumns[nColumn] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(wszText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x210, 0);
        sub_005267E0(ptLine->pColumns[nColumn], wszText);
    }

    return 1;
}

// 0x004FB870
void __fastcall D2Win_10197(D2WinTextBoxStrc* pTextBox, int nLineNum)
{
    D2_ASSERT(pTextBox, 0x21D);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x21E);
    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x21F);

    D2WinTextBoxLineStrc* ptLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!ptLine->pNext)
        {
            break;
        }
        ptLine = ptLine->pNext;
        ++i;
    }

    D2_ASSERT(ptLine, 0x229);
    D2_ASSERT(i == nLineNum, 0x22A);

    for (int j = 0; j < 5; ++j)
    {
        if (ptLine->pColumns[j])
        {
            FOG_Free(ptLine->pColumns[j], ".\\Src\\D2WinTextBox.cpp", 0x231, 0);
            ptLine->pColumns[j] = 0;
        }
    }
}

// 0x004FB910
int __fastcall D2Win_10052_TEXTBOX_GetNumLines(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x23E);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x23F);

    return ptTextData->nNumLines;
}

// 0x004FB950
int __fastcall D2Win_10054(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x24A);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x24B);

    return ptTextData->nLine;
}

// 0x004FB990
int __fastcall D2Win_10049(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x256);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x257);

    return ptTextData->nCurrentLine;
}

// 0x004FB9D0
void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* ptTextData, int nLine)
{
    D2_ASSERT(ptTextData, 0x262);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x263);

    ptTextData->nCurrentLine = D2_MIN(D2_MAX(nLine, -1), ptTextData->nNumLines - 1);
}

// 0x004FBA30
int __fastcall D2Win_10053(D2WinTextBoxStrc* ptTextData, int nLine)
{
    D2_ASSERT(ptTextData, 0x271);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x272);

    nLine = nLine < ptTextData->nNumLines ? nLine : ptTextData->nNumLines;

    D2WinTextBoxLineStrc* pLine = ptTextData->pFirstLine;
    for (int i = 0; i < nLine; ++i)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
    }

    if (pLine)
    {
        ptTextData->pCurrentLine = pLine;
        ptTextData->nLine = nLine;
    }

    if (ptTextData->pScrollBar)
    {
        SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nLine);
    }

    return 1;
}

// 0x004FBAB0
int __fastcall D2Win_10055(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x290);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x291);

    sub_00502EF0(ptTextData->eFont);
    const int nHeight = ptTextData->controlHeader.nHeight - 2 * ptTextData->unk0x44;
    sub_004FB5A0_SetTextBoxLineGap(ptTextData->eFont);
    const int nLineHeight = D2Win_10125() + ptTextData->unk0xA8;
    return (nHeight - nLineHeight) / (nLineHeight + ptTextData->unk0xA4) + 1;
}

// 0x004FBB30
void* __fastcall sub_004FBB30_GetSelectedData(D2WinControl004FBB30Strc* pControl)
{
    D2_ASSERT(pControl, 0x2A6);
    D2_ASSERT(pControl->eType == 4, 0x2A7);
    if (pControl->nSelected60 != -1 && (pControl->dwFlags5C & 1))
    {
        D2WinListEntry004FBB30Strc* pEntry;
        int nIndex;
        for (pEntry = pControl->pFirstEntry48, nIndex = 0; pEntry; pEntry = pEntry->pNext1C, ++nIndex)
        {
            if (pControl->nSelected60 == nIndex)
            {
                return pEntry->pData;
            }
        }
    }
    return 0;
}

// 0x004FBC20
void __fastcall D2Win_10056(D2WinTextBoxStrc* pTextBox, int nNumColumns)
{
    D2_ASSERT(pTextBox, 0x2DD);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x2DE);
    D2_ASSERT((nNumColumns > 0) && (nNumColumns <= 5), 0x2E0);
    D2_ASSERT(pTextBox->nNumColumns <= nNumColumns, 0x2E2);

    pTextBox->nNumColumns = nNumColumns;

    if (nNumColumns > 1)
    {
        pTextBox->dwTextBoxFlags |= TEXTBOXFLAG_NO_WORD_WRAP;
    }
}

// 0x004FBC80
void __fastcall D2Win_10059(D2WinTextBoxStrc* pTextBox, int nColumn, int a3)
{
    D2_ASSERT(pTextBox, 0x2EF);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x2F0);
    D2_ASSERT((nColumn >= 0) && (nColumn < pTextBox->nNumColumns), 0x2F2);
    pTextBox->unk0x68[nColumn] = a3;
}

// 0x004FBCD0
void __fastcall D2Win_10060(D2WinTextBoxStrc* ptTextData, int nColumn, int a3)
{
    D2_ASSERT(ptTextData, 0x2FC);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x2FD);
    D2_ASSERT(nColumn >= 0, 0x2FF);
    ptTextData->unk0x7C[nColumn] = a3;
}

// 0x004FBD20
int __fastcall D2Win_10061(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x309);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x30A);

    int nLineCount = 0;
    for (D2WinTextBoxLineStrc* pLine = ptTextData->pFirstLine; pLine; pLine = pLine->pNext)
    {
        if (!pLine->pNext)
        {
            break;
        }

        ++nLineCount;
    }

    return nLineCount;
}

// 0x004FBD70
void __fastcall sub_004FBD70_SetControlStateWithChild(D2WinControlStrc* pControl, int bSet)
{
    sub_004F9740(pControl, bSet);
    D2_ASSERT(pControl, 0x320);
    D2_ASSERT(pControl->eType == 4, 0x321);
    D2WinScrollBarStrc* pScrollBar = ((D2WinTextBoxStrc*)pControl)->pScrollBar;
    if (pScrollBar)
    {
        sub_004F9740((D2WinControlStrc*)pScrollBar, bSet);
    }
}

// 0x004FBDC0
void __cdecl sub_004FBDC0_Unsupported()
{
    D2_ASSERT(0, 0x32E);
}

// 0x004FBE90
static int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x393);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x394);

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCount = 0;
    while (pLine)
    {
        pLine = pLine->pNext;
        ++nCount;
    }

    return nCount;
}

static inline int sub_B03_AddLineRecord(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int nColor, char bIsWrapped, int nIndent)
{
    D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), ".\\Src\\D2WinTextBox.cpp", 0x15D, 0);
    Unicode* pDest;
    if (nIndent == 2)
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 6), ".\\Src\\D2WinTextBox.cpp", 0x161, 0);
        pLine->pColumns[0][4].wChar = 0x20;
        pLine->pColumns[0][3].wChar = pLine->pColumns[0][4].wChar;
        pLine->pColumns[0][2].wChar = pLine->pColumns[0][3].wChar;
        pLine->pColumns[0][1].wChar = pLine->pColumns[0][2].wChar;
        pLine->pColumns[0][0].wChar = pLine->pColumns[0][1].wChar;
        pDest = pLine->pColumns[0] + 5;
    }
    else
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x167, 0);
        pDest = pLine->pColumns[0];
    }
    sub_005267E0(pDest, pText);

    pLine->pColumns[1] = 0;
    pLine->pColumns[2] = 0;
    pLine->pColumns[3] = 0;
    pLine->pColumns[4] = 0;
    pLine->unk0x14 = nColor;
    pLine->unk0x18 = bIsWrapped;
    pLine->pNext = 0;

    int bScrolled = 0;
    if (!pTextBox->pFirstLine)
    {
        ++pTextBox->nNumLines;
        pTextBox->pFirstLine = pLine;
        pTextBox->pLastLine = pLine;
        pTextBox->pCurrentLine = pLine;
    }
    else
    {
        pTextBox->pLastLine->pNext = pLine;
        ++pTextBox->nNumLines;
        pTextBox->pLastLine = pLine;

        const int nVisible = D2Win_10055(pTextBox);
        if (sub_004FBE90_CountLinesFromCurrent(pTextBox) > nVisible)
        {
            D2WinScrollBarStrc* pScrollBar = pTextBox->pScrollBar;
            if (!pScrollBar || SCROLLBAR_GetMaxSteps(pScrollBar) == SCROLLBAR_GetCurrentStep(pScrollBar))
            {
                bScrolled = 1;
                pTextBox->pCurrentLine = pTextBox->pCurrentLine->pNext;
                ++pTextBox->nLine;
            }
        }
    }

    if (pTextBox->pScrollBar)
    {
        const int nStep = SCROLLBAR_GetCurrentStep(pTextBox->pScrollBar);
        SCROLLBAR_SetMaxSteps(pTextBox->pScrollBar, pTextBox->nNumLines - D2Win_10055(pTextBox));
        if (bScrolled)
            SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, pTextBox->nLine);
        else
            SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, nStep);
    }

    return 1;
}

// 0x004FBEE0
static int __stdcall sub_004FBEE0(int nWidth, Unicode* wszText)
{
    int i = 0;
    const int nLength = sub_00526800(wszText);
    while (i < nLength)
    {
        if (D2Win_10122(wszText, i + 1) >= nWidth)
        {
            break;
        }
        ++i;
    }

    wszText[i].wChar = 0;
    return i;
}

// 0x004FBF30
int __fastcall TEXTBOX_Draw(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x3BC);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x3BD);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0x40, 0x40, 0x40);

    D2CelFileStrc* pCellFile = pTextBox->controlHeader.pCellFile;
    if (pCellFile)
    {
        D2GfxDataStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCellFile = pCellFile;
        tGfxData.nDirection = 0;
        tGfxData.nFrame = 0;
        TEXTURE_CelDraw(&tGfxData, pTextBox->controlHeader.nImageX, pTextBox->controlHeader.nImageY - 1, -1, 5, 0);
    }

    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
    sub_00502EF0(pTextBox->eFont);

    const int v51 = pTextBox->controlHeader.nImageX + pTextBox->unk0x40;
    int nY = D2Win_10125() + (pTextBox->controlHeader.nImageY - pTextBox->controlHeader.nHeight) + pTextBox->unk0x44;

    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);

    const int v8 = D2Win_10125() + pTextBox->unk0xA8;
    int v49 = pTextBox->controlHeader.nHeight - 2 * pTextBox->unk0x44;
    const int nBoxWidth = pTextBox->controlHeader.nWidth - 2 * pTextBox->unk0x40;

    if (pTextBox->dwTextBoxFlags & 0x40)
    {
        D2WinTextBoxLineStrc* pCurrentLine = pTextBox->pCurrentLine;
        if (pCurrentLine)
        {
            pTextBox->unk0x9C -= 2;
            if (pTextBox->unk0x9C < -sub_00501820(pCurrentLine->pColumns[0]))
            {
                pTextBox->unk0x9C = nBoxWidth;
            }
        }
    }

    if (pTextBox->dwTextBoxFlags & 0x80)
    {
        D2WinTextBoxLineStrc* pCurrentLine = pTextBox->pCurrentLine;
        if (pCurrentLine)
        {
            pTextBox->unk0x9C -= 2;
            if (pTextBox->unk0x9C < -v8)
            {
                pTextBox->unk0x9C = 0;
                pTextBox->pCurrentLine = pCurrentLine->pNext;
            }
        }
    }

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCounter = 0;
    if (pLine)
    {
        do
        {
            for (int i = 0; i < pTextBox->nNumColumns; ++i)
            {
                const Unicode* wszColumn = pLine->pColumns[i];
                if (!wszColumn)
                {
                    break;
                }

                int v48 = pTextBox->controlHeader.nWidth;
                if (i < pTextBox->nNumColumns - 1)
                {
                    v48 = pTextBox->unk0x68[i + 1];
                }

                const int v16 = pTextBox->unk0x68[i];
                int nX;
                if (v16)
                {
                    nX = v16 + v51;

                    int v18;
                    if (i + 1 < pTextBox->nNumColumns)
                    {
                        v18 = pTextBox->unk0x68[i + 1] - v16;
                        v48 = v18;
                    }
                    else
                    {
                        v48 = pTextBox->controlHeader.nWidth - v16;
                        v18 = v48;
                    }

                    if (pTextBox->unk0x7C[i] & 2)
                    {
                        // the original keeps the column pointer in a stack slot and reloads it here; a plain read is taken again from pLine->pColumns[i]
                        int nOffset = (v18 - sub_00501820(*(const Unicode* volatile*)&wszColumn)) / 2;
                        if (nOffset < 0)
                        {
                            nOffset = 0;
                        }
                        nX += nOffset;
                    }
                    else if (pTextBox->unk0x7C[i] & 0x10)
                    {
                        int nTextWidth = sub_00501820(wszColumn);
                        if (nTextWidth < 0)
                        {
                            nTextWidth = 0;
                        }
                        nX += v48 - nTextWidth;
                    }
                }
                else if (pTextBox->dwTextBoxFlags & 2)
                {
                    int nOffset = (pTextBox->controlHeader.nWidth - sub_00501820(pLine->pColumns[0])) / 2;
                    if (nOffset < 0)
                    {
                        nOffset = 0;
                    }
                    nX = pTextBox->controlHeader.nImageX + nOffset;
                }
                else if (pTextBox->dwTextBoxFlags & 0x10)
                {
                    int nTextWidth = sub_00501820(pLine->pColumns[0]);
                    if (nTextWidth < 0)
                    {
                        nTextWidth = 0;
                    }
                    nX = pTextBox->controlHeader.nImageX - nTextWidth;
                }
                else
                {
                    nX = v51;
                }

                Unicode wszText[1024];
                for (int j = 0; j < 1024; ++j)
                {
                    wszText[j].wChar = 0;
                }
                sub_005267E0(wszText, pLine->pColumns[i]);
                sub_004FBEE0(v48, wszText);

                if (pTextBox->nCurrentLine == nCounter + pTextBox->nLine && (pTextBox->dwTextBoxFlags & 1))
                {
                    const int nLineColor = pLine->unk0x14 != 4 ? pLine->unk0x14 : 0;
                    if (!i)
                    {
                        sub_005025C0_DrawFramedText(wszText, nX, nY, nBoxWidth, nColor, 5, nLineColor);
                    }
                    else
                    {
                        sub_00502320(wszText, nX, nY, nLineColor, 0);
                    }
                }
                else if (pTextBox->dwTextBoxFlags & 0x40)
                {
                    sub_00501FE0_DrawTickerText(pLine->pColumns[i], nX, nY, pLine->unk0x14, pTextBox->unk0x9C, nBoxWidth);
                }
                else if (pTextBox->dwTextBoxFlags & 0x80)
                {
                    sub_00502320(wszText, nX, nY + pTextBox->unk0x9C, pLine->unk0x14, 0);
                }
                else
                {
                    sub_00502320(wszText, nX, nY, pLine->unk0x14, 0);
                }
            }

            const int v34 = (!pLine->unk0x18 ? pTextBox->unk0xA4 : pTextBox->unk0xA0) + v8;
            ++nCounter;
            nY += v34;
            v49 -= v34;
            pLine = pLine->pNext;
        }
        while (pLine && v49 >= (!pLine->unk0x18 ? pTextBox->unk0xA4 : pTextBox->unk0xA0) + v8);
    }

    sub_00502EF0(1);
    return 1;
}

// 0x004FC2F0
int __stdcall TEXTBOX_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)pMsg->hWnd;
    D2_ASSERT(pTextBox, 0x4D0);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x4D1);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0]) || pTextBox->nNumLines < 1)
    {
        return 0;
    }

    if (pTextBox->dwTextBoxFlags & 1)
    {
        const int nY = pTextBox->controlHeader.nHeight - pTextBox->controlHeader.nImageY + gnMouseY_007D55A8;
        sub_00502EF0(pTextBox->eFont);
        sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
        pTextBox->nCurrentLine = pTextBox->nLine + (nY - pTextBox->unk0x44) / (D2Win_10125() + pTextBox->unk0xA8);
        if (pTextBox->dwTextBoxFlags & 8)
        {
            pTextBox->nCurrentLine = D2_MIN(D2_MAX(pTextBox->nCurrentLine, 0), pTextBox->nNumLines - 1);
        }
        else if (pTextBox->nCurrentLine < 0 || pTextBox->nCurrentLine >= pTextBox->nNumLines)
        {
            pTextBox->nCurrentLine = -1;
        }
    }

    if (pTextBox->controlHeader.field_34)
    {
        return pTextBox->controlHeader.field_34(pMsg);
    }
    return 0;
}

// 0x004FC5A0
extern "C" int __fastcall sub_004FC5A0_GetMaxSteps(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x578);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x579);
    return sub_00507EF0_GetScrollBarField48(ptTextData->pScrollBar);
}

// 0x004FC5E0
int __fastcall D2Win_10191(D2WinTextBoxStrc* ptTextData, int nMaxSteps)
{
    D2_ASSERT(ptTextData, 0x582);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x583);

    return SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, nMaxSteps);
}

// 0x004FC620
int __fastcall D2Win_10192(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x58C);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x58D);

    return sub_00507FA0_GetScrollBarField4C(ptTextData->pScrollBar);
}

// 0x004FC660
int __fastcall D2Win_10193(D2WinTextBoxStrc* ptTextData, int nCurrentStep)
{
    D2_ASSERT(ptTextData, 0x596);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x597);

    return SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nCurrentStep);
}

// 0x004FC6A0
int __fastcall D2Win_10194(D2WinTextBoxStrc* ptTextData, D2WinTextBoxStrc* pLinkedTextBox)
{
    D2_ASSERT(ptTextData, 0x5A0);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x5A1);

    return SCROLLBAR_SetTextBox(ptTextData->pScrollBar, pLinkedTextBox);
}

// 0x004FC6E0
int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*))
{
    D2_ASSERT(pTextBox, 0x5AA);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x5AB);

    return sub_00508000_SetScrollCallback(pTextBox->pScrollBar, pfScrollCallback);
}

// 0x004FC720
void __fastcall D2Win_10204(D2WinTextBoxStrc* ptTextData, int nPosition)
{
    D2_ASSERT(ptTextData, 0x5B4);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x5B5);

    sub_005080C0_SetScrollBarField50(ptTextData->pScrollBar, nPosition);
}

// 0x004FC760
int __fastcall D2Win_10203_TEXTBOX(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x5BE);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x5BF);

    return sub_005080F0_GetScrollBarField50(pTextBox->pScrollBar);
}

// 0x004FC7A0
D2WinTextBoxStrc* __fastcall D2Win_10042_TEXTBOX_Create(int nX, int nY, int nWidth, int nHeight, int nInsetX, int nInsetY, D2CelFileStrc* pCellFile, int (__stdcall* pfCallback)(SMSGHANDLER_PARAMS*), unsigned int dwTextBoxFlags, int* pFontInfo, int* pScrollBarRect)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)FOG_Alloc(0xAC, ".\\Src\\D2WinTextBox.cpp", 0x63, 0);
    memset(pTextBox, 0, 0xAC);

    if ((dwTextBoxFlags & 4) && !pScrollBarRect)
    {
        nWidth -= 0x1A;
    }
    if (dwTextBoxFlags & 1)
    {
        dwTextBoxFlags |= 0x20;
    }

    pTextBox->controlHeader.eType = 4;
    pTextBox->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pTextBox->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pTextBox->controlHeader.pCellFile = pCellFile;
    pTextBox->controlHeader.nImageX = nX;
    pTextBox->controlHeader.nImageY = nY;
    pTextBox->controlHeader.nWidth = nWidth;
    pTextBox->controlHeader.nHeight = nHeight;
    pTextBox->dwTextBoxFlags = dwTextBoxFlags;
    pTextBox->unk0x40 = nInsetX;
    pTextBox->unk0x44 = nInsetY;
    pTextBox->controlHeader.pfDraw = (D2WinControlFn)TEXTBOX_Draw;
    pTextBox->controlHeader.pfHandleMouseDown = TEXTBOX_HandleMouseDown;
    pTextBox->controlHeader.pfHandleMouseUp = 0;
    pTextBox->controlHeader.pfHandleCharInput = 0;
    const bool bVirtualKey = (dwTextBoxFlags & 1) != 0;
    pTextBox->controlHeader.pfHandleVirtualKeyInput = bVirtualKey ? TEXTBOX_HandleVirtualKeyInput : 0;
    pTextBox->controlHeader.field_34 = pfCallback;
    pTextBox->nCurrentLine = -1;
    pTextBox->controlHeader.pNext = 0;
    pTextBox->pCurrentLine = 0;
    pTextBox->pFirstLine = 0;
    pTextBox->pLastLine = 0;
    pTextBox->nNumLines = 0;
    pTextBox->nLine = 0;
    pTextBox->nNumColumns = 1;

    if (pFontInfo)
    {
        pTextBox->eFont = pFontInfo[0];
        pTextBox->unk0x98 = pFontInfo[1];
    }
    else
    {
        pTextBox->eFont = 1;
        pTextBox->unk0x98 = 0;
    }

    sub_004FB5A0_SetTextBoxLineGap(pTextBox->eFont);
    pTextBox->unk0xA8 = gnTextBoxLineGap_0072DE90;

    if (dwTextBoxFlags & 4)
    {
        pTextBox->controlHeader.pCellFile = 0;
        int nScrollX;
        if (pScrollBarRect)
        {
            nScrollX = pScrollBarRect[0];
            nY = pScrollBarRect[1];
            nHeight = pScrollBarRect[2];
        }
        else
        {
            nScrollX = nX + nWidth + 8;
            nY -= 2;
            nHeight -= 0x10;
        }
        pTextBox->pScrollBar = SCROLLBAR_Create(nScrollX, nY, 10, nHeight, pCellFile, 0);
        SCROLLBAR_SetTextBox(pTextBox->pScrollBar, pTextBox);
        int nPosition = D2Win_10055(pTextBox) - 1;
        if (nPosition <= 0)
        {
            nPosition = 1;
        }
        sub_005080C0_SetScrollBarField50(pTextBox->pScrollBar, nPosition);
    }
    else
    {
        pTextBox->pScrollBar = 0;
    }

    CONTROL_AppendToList(pTextBox);
    return pTextBox;
}

// 0x004FC960
int __fastcall D2Win_10043_TEXTBOX_Destroy(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0xCB);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0xCC);
    if (ptTextData->pScrollBar)
        sub_00507EE0(ptTextData->pScrollBar);
    sub_004FB6A0_ClearText(&ptTextData->controlHeader);
    return CONTROL_RemoveFromList(&ptTextData->controlHeader);
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FC9B0
int __fastcall D2Win_10051(D2WinTextBoxStrc* ptTextData, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent)
{
    D2_ASSERT(ptTextData, 0x132);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x133);

    Unicode wszBuffer[0x400];
    sub_005267E0(wszBuffer, wszText);

    const Unicode* pText = wszBuffer;
    while (pText->wChar)
    {
        if (pText->wChar >= 0x100 || !isspace(pText->wChar))
            break;

        ++pText;
    }

    sub_00502EF0(ptTextData->eFont);

    if (!(ptTextData->dwTextBoxFlags & 0x20))
    {
        int nMaxWidth = ptTextData->controlHeader.nWidth - 2 * ptTextData->unk0x40;
        if (nIndent == 2)
        {
            Unicode wszSpaces[6];
            wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
            wszSpaces[5].wChar = 0;
            nMaxWidth -= sub_00501820(wszSpaces);
        }

        if (D2Win_10122(pText, 0xFF) >= nMaxWidth)
            return sub_004FCDA0_AddWrappedText(ptTextData, pText, nColor, nIndent);
    }

    D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), szD2WinTextBoxCpp_006DC840, 0x15D, 0);
    if (nIndent == 2)
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 6), szD2WinTextBoxCpp_006DC840, 0x161, 0);
        pLine->pColumns[0][4].wChar = 0x20;
        pLine->pColumns[0][3].wChar = pLine->pColumns[0][4].wChar;
        pLine->pColumns[0][2].wChar = pLine->pColumns[0][3].wChar;
        pLine->pColumns[0][1].wChar = pLine->pColumns[0][2].wChar;
        pLine->pColumns[0][0].wChar = pLine->pColumns[0][1].wChar;
        sub_005267E0(pLine->pColumns[0] + 5, pText);
    }
    else
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 1), szD2WinTextBoxCpp_006DC840, 0x167, 0);
        sub_005267E0(pLine->pColumns[0], pText);
    }

    pLine->pColumns[1] = 0;
    pLine->pColumns[2] = 0;
    pLine->pColumns[3] = 0;
    pLine->pColumns[4] = 0;
    pLine->unk0x14 = nColor;
    pLine->unk0x18 = bIsWrapped;
    pLine->pNext = 0;
    int bScrolled = 0;

    if (!ptTextData->pFirstLine)
    {
        ++ptTextData->nNumLines;
        ptTextData->pFirstLine = pLine;
        ptTextData->pLastLine = pLine;
        ptTextData->pCurrentLine = pLine;
    }
    else
    {
        ptTextData->pLastLine->pNext = pLine;
        ++ptTextData->nNumLines;
        ptTextData->pLastLine = pLine;

        const int nVisible = D2Win_10055(ptTextData);
        if (sub_004FBE90_CountLinesFromCurrent(ptTextData) > nVisible)
        {
            D2WinScrollBarStrc* pScrollBar = ptTextData->pScrollBar;
            if (!pScrollBar || sub_00507FA0_GetScrollBarField4C(pScrollBar) == sub_00507EF0_GetScrollBarField48(ptTextData->pScrollBar))
            {
                bScrolled = 1;
                ptTextData->pCurrentLine = ptTextData->pCurrentLine->pNext;
                ++ptTextData->nLine;
            }
        }
    }

    if (ptTextData->pScrollBar)
    {
        const int nStep = sub_00507FA0_GetScrollBarField4C(ptTextData->pScrollBar);
        SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, ptTextData->nNumLines - D2Win_10055(ptTextData));
        if (bScrolled)
            SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, ptTextData->nLine);
        else
            SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nStep);
    }

    return 1;
}

// 0x004FCC40
int __fastcall D2Win_10198(D2WinTextBoxStrc* ptTextData, const Unicode* pText, int nCount, int nValue, char nFlag)
{
    D2_ASSERT(ptTextData, 0x1A7);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x1A8);

    const int nSize = sizeof(Unicode) * (sub_00526800(pText) + 1);
    for (int i = 0; i < nCount; ++i)
    {
        D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), ".\\Src\\D2WinTextBox.cpp", 0x1AF, 0);
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(nSize, ".\\Src\\D2WinTextBox.cpp", 0x1B0, 0);
        sub_005267E0(pLine->pColumns[0], pText);
        for (int j = 1; j < 5; ++j)
        {
            pLine->pColumns[j] = 0;
        }

        pLine->unk0x14 = nValue;
        pLine->unk0x18 = nFlag;
        pLine->pNext = 0;

        if (!ptTextData->pFirstLine)
        {
            ptTextData->pFirstLine = pLine;
        }
        else
        {
            ptTextData->pLastLine->pNext = pLine;
        }

        ptTextData->pLastLine = pLine;
        ++ptTextData->nNumLines;
    }

    if (ptTextData->pScrollBar)
    {
        SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, ptTextData->nNumLines - D2Win_10055(ptTextData));
    }

    return 1;
}

// 0x004FCD40
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int a3, int a4)
{
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    return D2Win_10058_0(pControl, wszText, a3, a4);
}

// 0x004FCD90
int __fastcall sub_004FCD90_D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn)
{
    return D2Win_10058_0(pControl, pText, a3, nColumn);
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FCDA0
int __fastcall sub_004FCDA0_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent)
{
    D2_ASSERT(pTextBox, 0x482);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x483);

    int nMaxWidth = pTextBox->controlHeader.nWidth - 2 * pTextBox->unk0x40;
    if (nIndent == 2)
    {
        Unicode wszSpaces[6];
        wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
        wszSpaces[5].wChar = 0;
        nMaxWidth -= sub_00501820(wszSpaces);
    }

    Unicode* pBuffer = (Unicode*)SMemAlloc(0x800, szD2WinTextBoxCpp_006DC840, 0x497, 0);
    Unicode* pText = pBuffer;
    sub_005267E0(pText, wszText);

    int nSplit = 0;
    const int nLength = sub_00526800(pText);
    Unicode* pChar = pText;
    Unicode* pSpace = 0;
    while (nSplit < nLength)
    {
        if (pChar->wChar == 0x20)
            pSpace = pChar;

        const int nNext = nSplit + 1;
        if (D2Win_10122(wszText, nNext) >= nMaxWidth)
        {
            if (pSpace)
            {
                nSplit = pSpace - pText;
                pChar = pSpace;
            }
            break;
        }

        ++pChar;
        ++nSplit;
    }

    Unicode* pFirst = (Unicode*)SMemAlloc(0x800, szD2WinTextBoxCpp_006DC840, 0x4B7, 0);
    pText = (Unicode*)SMemAlloc(0x800, szD2WinTextBoxCpp_006DC840, 0x4B8, 0);
    sub_00526790(pFirst, pBuffer, nSplit);
    pFirst[nSplit].wChar = 0;
    sub_00526790(pText, pChar, nLength - nSplit);
    pText[nLength - nSplit].wChar = 0;
    SMemFree(pBuffer, szD2WinTextBoxCpp_006DC840, 0x4BF, 0);

    D2Win_10051(pTextBox, pFirst, nColor, 1, nIndent);
    D2Win_10051(pTextBox, pText, nColor, 0, nIndent == 1 ? 2 : nIndent);

    SMemFree(pFirst, szD2WinTextBoxCpp_006DC840, 0x4C4, 0);
    SMemFree(pText, szD2WinTextBoxCpp_006DC840, 0x4C5, 0);
    return 1;
}

// 0x004FCF80
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText)
{
    D2_ASSERT(pControl, 0x109);
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pControl, wszText, 4, 0, 0);
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

// 0x004FD060
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText)
{
    sub_004FC9B0_SetText(pControl, pText, 4, 0, 0);
}

// build: context sub_004FD340_ImageDrawTiled
static void __stdcall sub_004FD340_ImageDrawTiled(const D2CropRectStrc* pDst, const D2CropRectStrc* pSrc, D2GfxDataStrc* pGfxData)
{
    const int nSrcWidth = pSrc->nX1 - pSrc->nX0;
    const int nDstWidth = pDst->nX1 - pDst->nX0;
    const int nSrcHeight = pSrc->nY1 - pSrc->nY0;
    const int nDstHeight = pDst->nY1 - pDst->nY0;
    if (nSrcWidth == nDstWidth && nSrcHeight == nDstHeight)
    {
        TEXTURE_CelDrawClipped(pGfxData, pDst->nX0 - pSrc->nX0, pDst->nY1 - pSrc->nY1 + 256, (void*)pDst, DRAWMODE_NORMAL);
        return;
    }

    const int nColumns = (nDstWidth + nSrcWidth - 1) / nSrcWidth;
    const int nRows = (nDstHeight + nSrcHeight - 1) / nSrcHeight;
    int nY = pDst->nY0 - pSrc->nY0 + 256;
    D2CropRectStrc tRect;
    for (int j = 0; j < nRows; ++j, nY += nSrcHeight)
    {
        for (int i = 0, nX = pDst->nX0 - pSrc->nX0; i < nColumns; ++i, nX += nSrcWidth)
        {
            tRect.nX0 = pDst->nX0 > pSrc->nX0 + nX ? pDst->nX0 : pSrc->nX0 + nX;
            tRect.nX1 = pDst->nX1;
            if (tRect.nX1 >= tRect.nX0 + nSrcWidth)
                tRect.nX1 = tRect.nX0 + nSrcWidth;
            tRect.nY0 = pDst->nY0 > pSrc->nY0 + nY - 256 ? pDst->nY0 : pSrc->nY0 + nY - 256;
            tRect.nY1 = pDst->nY1;
            if (tRect.nY1 >= tRect.nY0 + nSrcHeight)
                tRect.nY1 = tRect.nY0 + nSrcHeight;
            TEXTURE_CelDrawClipped(pGfxData, nX, nY, &tRect, DRAWMODE_NORMAL);
        }
    }
}

// 0x004FD470
int __fastcall IMAGE_Draw(D2WinControlStrc* pControl)
{
    D2WinImageStrc* pImage = (D2WinImageStrc*)pControl;

    D2_ASSERT(pImage->controlHeader.eType == D2WIN_IMAGE, 0x10F);

    const int nBorderX = pImage->field_4C;
    const int nBorderY = pImage->field_50;
    D2GfxDataStrc tGfxData;
    memset(&tGfxData, 0, sizeof(tGfxData));
    tGfxData.pCellFile = pImage->controlHeader.pCellFile;
    tGfxData.nDirection = 0;
    tGfxData.nFrame = 0;

    int nX[4];
    int nY[4];
    int nSrcY[4];
    int nSrcX[4];
    nSrcX[0] = 0;
    nSrcX[1] = nBorderX;
    nSrcX[2] = 256 - nBorderX;
    nSrcX[3] = 256;
    nSrcY[0] = 0;
    nSrcY[1] = nBorderY;
    nSrcY[2] = 256 - nBorderY;
    nSrcY[3] = 256;
    nX[0] = pImage->controlHeader.nImageX;
    nX[1] = pImage->controlHeader.nImageX + nBorderX;
    nX[2] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth - nBorderX;
    nX[3] = pImage->controlHeader.nImageX + pImage->controlHeader.nWidth;
    nY[0] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight;
    nY[1] = pImage->controlHeader.nImageY - pImage->controlHeader.nHeight + nBorderY;
    nY[2] = pImage->controlHeader.nImageY - nBorderY;
    nY[3] = pImage->controlHeader.nImageY;
    D2CropRectStrc tDst;
    D2CropRectStrc tSrc;
    for (int j = 0; j < 3; ++j)
    {
        tSrc.nY0 = nSrcY[j];
        tSrc.nY1 = nSrcY[j + 1];
        for (int i = 0; i < 3; ++i)
        {
            tDst.nX0 = nX[i];
            tDst.nX1 = nX[i + 1];
            tDst.nY0 = nY[j];
            tDst.nY1 = nY[j + 1];
            tSrc.nX0 = nSrcX[i];
            tSrc.nX1 = nSrcX[i + 1];
            sub_004FD340_ImageDrawTiled(&tDst, &tSrc, &tGfxData);
        }
    }

    return 1;
}

// 0x004FFE10
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText)
{
    Unicode wszText[256];
    sub_00526F20_ToUnicode(wszText, szText, 256);
    return sub_004FF5A0_SetEditText(pControl, wszText);
}

// 0x00501690
D2CharStrc* __fastcall sub_6F8AA140(unsigned short wChar)
{
    int nIterations = 0;
    int nMin = 0;
    D2FontCacheStrc* pFontCache = &gFontCache_00841DA8[gnCurrentFont_0072DFFC];
    int nMax = pFontCache->pFontInfo[1]->nCharCount - 1;
    if (nMax >= 0)
    {
        D2CharStrc* pCharInfo = pFontCache->pCharInfo;
        do
        {
            const int nMid = (nMin + nMax) / 2;
            ++nIterations;
            if (wChar == pCharInfo[nMid].wChar)
            {
                return &pCharInfo[nMid];
            }

            if (wChar < pCharInfo[nMid].wChar)
            {
                nMax = nMid - 1;
            }
            else
            {
                nMin = nMid + 1;
            }

            if (nIterations > 1000)
            {
                break;
            }
        }
        while (nMax >= nMin);
    }

    return pFontCache->pCharInfo + 31;
}

#include "gen/data/Source/D2Win/Src/D2WinTextBox.inc"
