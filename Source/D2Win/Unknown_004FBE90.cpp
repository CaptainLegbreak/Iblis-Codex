#include "D2Win.h"
#include "D2WinControls.h"
#include "D2Unicode.h"
#include "D2ClientTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CelFileStrc;
struct Unicode;
struct D2WinTextBoxLineStrc;
struct D2WinTextBoxStrc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0
int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps); // 0x00507F20
int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep); // 0x00507F60
int __fastcall sub_004FCDA0_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern int gdwGlobal_00841B70; // 0x00841B70
int __stdcall D2Win_10125(); // 0x00501A40
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
void __fastcall sub_005025C0_DrawFramedText(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int eDrawMode, int nTextColor); // 0x005025C0
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __fastcall sub_00501FE0_DrawTickerText(const Unicode* wszText, int nX, int nY, int nColor, int nScroll, int nWidth); // 0x00501FE0

// 0x004FBE90
static __declspec(noinline) int sub_004FBE90_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox)
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

static __forceinline int sub_B03_AddLineRecord(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int nColor, char bIsWrapped, int nIndent)
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

int __fastcall D2Win_10051(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent)
{
    D2_ASSERT(pTextBox, 0x132);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x133);

    Unicode wszBuffer[0x400];
    sub_005267E0(wszBuffer, wszText);

    const Unicode* pText = wszBuffer;
    while (pText->wChar)
    {
        if (pText->wChar >= 0x100 || !isspace(pText->wChar))
            break;

        ++pText;
    }

    sub_00502EF0(pTextBox->eFont);

    if (!(pTextBox->dwTextBoxFlags & 0x20))
    {
        int nMaxWidth = pTextBox->controlHeader.nWidth - 2 * pTextBox->unk0x40;
        if (nIndent == 2)
        {
            Unicode wszSpaces[6];
            wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
            wszSpaces[5].wChar = 0;
            nMaxWidth -= sub_00501820(wszSpaces);
        }

        if (D2Win_10122(pText, 0xFF) >= nMaxWidth)
            return sub_004FCDA0_AddWrappedText(pTextBox, pText, nColor, nIndent);
    }

    return sub_B03_AddLineRecord(pTextBox, pText, nColor, bIsWrapped, nIndent);
}

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

    Unicode* pCopy = (Unicode*)SMemAlloc(0x800, ".\\Src\\D2WinTextBox.cpp", 0x497, 0);
    Unicode* pCopyToFree = pCopy;
    sub_005267E0(pCopy, wszText);

    int nSplit = 0;
    const int nLength = sub_00526800(pCopy);
    Unicode* pRest = pCopy;
    Unicode* pSpace = 0;
    for (Unicode* pScan = pCopy; nSplit < nLength; pScan = pRest)
    {
        if (pScan->wChar == 0x20)
            pSpace = pScan;

        const int nNext = nSplit + 1;
        if (D2Win_10122(wszText, nNext) >= nMaxWidth)
        {
            if (pSpace)
            {
                nSplit = pSpace - pCopy;
                pRest = pSpace;
            }
            break;
        }

        ++pRest;
        nSplit = nNext;
    }

    Unicode* pFirst = (Unicode*)SMemAlloc(0x800, ".\\Src\\D2WinTextBox.cpp", 0x4B7, 0);
    Unicode* pSecond = (Unicode*)SMemAlloc(0x800, ".\\Src\\D2WinTextBox.cpp", 0x4B8, 0);
    sub_00526790(pFirst, pCopyToFree, nSplit);
    pFirst[nSplit].wChar = 0;
    const int nRest = nLength - nSplit;
    sub_00526790(pSecond, pRest, nRest);
    pSecond[nRest].wChar = 0;
    SMemFree(pCopyToFree, ".\\Src\\D2WinTextBox.cpp", 0x4BF, 0);

    D2Win_10051(pTextBox, pFirst, nColor, 1, nIndent);
    if (nIndent == 1)
        nIndent = 2;
    D2Win_10051(pTextBox, pSecond, nColor, 0, nIndent);

    SMemFree(pFirst, ".\\Src\\D2WinTextBox.cpp", 0x4C4, 0);
    SMemFree(pSecond, ".\\Src\\D2WinTextBox.cpp", 0x4C5, 0);
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
