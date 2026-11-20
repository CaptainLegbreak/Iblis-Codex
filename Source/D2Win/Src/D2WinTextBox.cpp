#include "D2Win.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2WinTypes.h"
#include "D2WinTypes.h"
#include "D2WinControls.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinTextBoxLineStrc;
struct Unicode;
struct D2WinControlStrc;
struct D2WinImageClickRectStrc;
struct D2WinTextBoxStrc;
struct D2WinImageStrc;
struct D2CropRectStrc;
struct D2GfxDataStrc;
struct D2CharStrc;
struct D2FontStrc;
struct D2FontCacheStrc;
struct D2GemsTxt;
struct T004F51E0;
struct D2UnitStrc;
struct D2ItemsTxt;

struct Unicode
{
    unsigned short wChar;
    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
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
int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox); // 0x00507FD0
int __fastcall sub_00508000_SetScrollCallback(D2WinScrollBarStrc* pScrollBar, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x00508000
extern "C" void __fastcall sub_005080C0_SetScrollBarField50(D2WinScrollBarStrc* pScrollBar, int nValue); // 0x005080C0
extern "C" int __fastcall sub_005080F0_GetScrollBarField50(D2WinScrollBarStrc* pScrollBar); // 0x005080F0

typedef int (__stdcall* D2WinMsgHandler)(struct SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinImageStrc
{
    D2WinControlStrc controlHeader;
    int nFrame;
    int eDrawMode;
    D2WinImageClickRectStrc* pClickRect;
    int field_4C;
    int field_50;
};

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
};

enum DrawMode
{
    DRAWMODE_NORMAL = 5,
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510
int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int a3, int nColumn); // 0x004FB790

int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern D2FontCacheStrc gFontCache_00841DA8[]; // 0x00841DA8

void __fastcall sub_004E6720_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720
void __fastcall sub_004E67D0_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette); // 0x004F63D0
int __stdcall sub_004FB1E0_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName); // 0x004FB1E0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
extern T004F51E0 gRGBAPalette_0081E668[]; // 0x0081E668
extern "C" const char szD2WinTextBoxCpp_006DC840[]; // 0x006DC840
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0
int __fastcall D2Win_10051(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
int __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

// 0x004E6850
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
