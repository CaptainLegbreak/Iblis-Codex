#include "D2Win.h"
#include "D2CelContext.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define EDITBOX_MIN(a, b) ((a) < (b) ? (a) : (b))
#define EDITBOX_MAX(a, b) ((a) > (b) ? (a) : (b))
struct Unicode;
struct UnicodeChar;
struct D2CelContextStrc;
struct D2WinEditBoxStrc;

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};


struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2WinEditBoxStrc
{
    int eType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    char pad1C[0x24];
    int nTextInsetX;
    int nTextInsetY;
    int nMaxLength;
    int nFirstVisibleChar;
    int nLastVisibleChar;
    int nSelectionStart;
    int nSelectionEnd;
    Unicode wszText[256];
    int nCaretPosition;
    unsigned int dwEditBoxFlags;
    char pad264[0x0C];
    int eFont;
    int nTextColor;
    char pad278[0x08];
    int bMouseSelecting;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0
int __stdcall D2Win_10125(); // 0x00501A40
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __stdcall sub_004FFBF0_EditBoxMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x004FFBF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall D2Win_10133(const Unicode* wszText, int nX, int nY, int nColor, int nDrawMode, int nTextColor); // 0x00502480

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FDC70
static int sub_004FDC70_HasSelection(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x198);
    D2_ASSERT(pEditBox->eType == 1, 0x19A);
    if (pEditBox->nSelectionStart != -1 && pEditBox->nSelectionStart != pEditBox->nSelectionEnd)
        return 1;
    return 0;
}

// 0x004FF620
int __fastcall sub_004FF620_EditBoxDrawAlt(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x510);
    D2_ASSERT(pEditBox->eType == 1, 0x512);

    if (pEditBox->dwFlags & gdwBitMasks[2] && pEditBox->dwFlags & gdwBitMasks[0])
    {
        if (!sub_004FA460())
        {
            pEditBox->bMouseSelecting = 0;
        }

        if (pEditBox->bMouseSelecting)
        {
            SMSGHANDLER_PARAMS tMsg;
            tMsg.hWnd = pEditBox;
            tMsg.uMessage = 0x201;
            sub_004FE710_EditBoxMouseDownAlt(&tMsg);
        }

        UnicodeChar wszText[300];
        sub_00502EF0(pEditBox->eFont);
        const int nX = pEditBox->nImageX + pEditBox->nTextInsetX;
        const int nYStart = D2Win_10125() + pEditBox->nImageY - pEditBox->nHeight + pEditBox->nTextInsetY;
        sub_005267E0(wszText, pEditBox->wszText);
        int nY = nYStart;
        const unsigned char nShade = D2Win_10034_MixRGB(0x40, 0x40, 0x40);

        char szCaret[] = "_";
        UnicodeChar wszCaret[2];
        sub_00526F20_ToUnicode(wszCaret, szCaret, 2);
        const int nCaretWidth = D2Win_10122(wszCaret, 2);

        int bBlink;
        if (sub_004F9200() == (int)pEditBox && GetTickCount() / 250 & 1)
            bBlink = 1;
        else
            bBlink = 0;

        int bCaretDrawn = 0;
        UnicodeChar wszLine[256];
        char szText[256];
        sub_00526F70(szText, pEditBox->wszText, 256);
        char* pLineStart = szText;
        char* pCur = szText;
        const int nLineHeight = D2Win_10125();
        const int nMaxWidth = pEditBox->nWidth - 2 * pEditBox->nTextInsetX;
        const int nMaxHeight = pEditBox->nHeight - 2 * pEditBox->nTextInsetY;

        if (!szText[0] && bBlink)
        {
            sub_00502320(wszCaret, nX, nYStart, pEditBox->nTextColor, 0);
            bCaretDrawn = 1;
        }

        while (*pCur)
        {
            if (nY - nYStart >= nMaxHeight)
                break;

            int nLen = pCur - pLineStart;
            char szLine[256];
            int bWrap = 0;
            memset(szLine, 0, sizeof(szLine));
            while (*pCur && *pCur != '\r' && *pCur != '\n')
            {
                szLine[nLen] = *pCur;
                sub_00526F20_ToUnicode(wszLine, szLine, 256);
                if (D2Win_10122(wszLine, nLen) + nCaretWidth > nMaxWidth)
                {
                    bWrap = 1;
                    break;
                }
                ++nLen;
                ++pCur;
            }

            if (sub_004FDC70_HasSelection(pEditBox))
            {
                int nSelMin = pEditBox->nSelectionStart < pEditBox->nSelectionEnd ? pEditBox->nSelectionStart : pEditBox->nSelectionEnd;
                int nSelMax = pEditBox->nSelectionStart > pEditBox->nSelectionEnd ? pEditBox->nSelectionStart : pEditBox->nSelectionEnd;
                const int nLineBegin = pLineStart - szText;
                const int nLineEnd = pCur - szText;
                int nDrawX = nX;
                int nWidth;
                int nHeight;
                if (nSelMin < nLineBegin && nSelMax >= nLineEnd)
                {
                    strncpy(szLine, pLineStart, nLen);
                    szLine[pCur - pLineStart] = 0;
                    sub_00526F20_ToUnicode(wszLine, szLine, 256);
                    D2Win_10131_GetTextDimensions(wszLine, &nWidth, &nHeight);
                    D2GFX_DrawBox(nDrawX, nY - nLineHeight, nDrawX + nWidth, nY, nShade, 5);
                }
                else if (nSelMin >= nLineBegin && nSelMin < nLineEnd || nSelMax >= nLineBegin && nSelMax < nLineEnd)
                {
                    const int nFrom = nSelMin > nLineBegin ? nSelMin : nLineBegin;
                    const int nTo = nSelMax < nLineEnd ? nSelMax : nLineEnd;
                    const int nSkip = nFrom - nLineBegin;
                    if (nSkip)
                    {
                        strncpy(szLine, pLineStart, nSkip);
                        szLine[nSkip] = 0;
                        sub_00526F20_ToUnicode(wszLine, szLine, 256);
                        D2Win_10131_GetTextDimensions(wszLine, &nWidth, &nHeight);
                        nDrawX = nWidth + nX;
                    }
                    const int nCount = nTo - nFrom;
                    strncpy(szLine, pLineStart + nSkip, nCount);
                    szLine[nCount] = 0;
                    sub_00526F20_ToUnicode(wszLine, szLine, 256);
                    D2Win_10131_GetTextDimensions(wszLine, &nWidth, &nHeight);
                    D2GFX_DrawBox(nDrawX, nY - nLineHeight, nDrawX + nWidth, nY, nShade, 5);
                }
            }

            strncpy(szLine, pLineStart, nLen);
            szLine[pCur - pLineStart] = 0;
            sub_00526F20_ToUnicode(wszLine, szLine, 256);
            sub_00502320(wszLine, nX, nY, pEditBox->nTextColor, 0);

            if (bBlink && !bCaretDrawn)
            {
                const int nCaretOffset = pEditBox->nCaretPosition - (pLineStart - szText);
                if (nCaretOffset >= 0 && nCaretOffset <= nLen)
                {
                    int nCaretX = nX;
                    if (nCaretOffset)
                        nCaretX = D2Win_10122(wszLine, nCaretOffset) + nX;
                    sub_00502320(wszCaret, nCaretX, nY, pEditBox->nTextColor, 0);
                    bCaretDrawn = 1;
                }
            }

            if (bWrap)
                nY += nLineHeight;

            if (*pCur == '\r')
            {
                if (pCur[1] == '\n')
                {
                    while (*pCur == '\r' && pCur[1] == '\n')
                    {
                        pCur += 2;
                        nY += nLineHeight;
                        if (bBlink && !bCaretDrawn && pEditBox->nCaretPosition == pCur - szText && nY - nYStart < nMaxHeight)
                            sub_00502320(wszCaret, nX, nY, pEditBox->nTextColor, 0);
                    }
                }
                else
                {
                    while (*pCur == '\r')
                    {
                        ++pCur;
                        nY += nLineHeight;
                        if (bBlink && !bCaretDrawn && pEditBox->nCaretPosition == pCur - szText && nY - nYStart < nMaxHeight)
                            sub_00502320(wszCaret, nX, nY, pEditBox->nTextColor, 0);
                    }
                }
            }

            pLineStart = pCur;
        }
    }

    return 1;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FFE50
int __fastcall sub_004FFE50_EditBoxDraw(D2WinEditBoxStrc* pEditBox)
{
    D2_ASSERT(pEditBox, 0x49C);
    D2_ASSERT(pEditBox->eType == 1, 0x49E);

    if (pEditBox->dwFlags & gdwBitMasks[2] && pEditBox->dwFlags & gdwBitMasks[0])
    {
        if (!sub_004FA460())
        {
            pEditBox->bMouseSelecting = 0;
        }

        if (pEditBox->bMouseSelecting)
        {
            SMSGHANDLER_PARAMS tMsg;
            tMsg.hWnd = pEditBox;
            tMsg.uMessage = 0x201;
            sub_004FFBF0_EditBoxMouseDown(&tMsg);
        }

        UnicodeChar wszText[300];
        if (pEditBox->pCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = pEditBox->pCellFile;
            tContext.nDirection = 0;
            tContext.nFrame = 0;
            sub_004F6480(&tContext, pEditBox->nImageX, pEditBox->nImageY - 1, -1, 5, 0);
        }

        sub_00502EF0(pEditBox->eFont);
        int nX = pEditBox->nTextInsetX + pEditBox->nImageX;
        const int nY = pEditBox->nTextInsetY - pEditBox->nHeight + pEditBox->nImageY + 16;
        sub_00526790(wszText, &pEditBox->wszText[pEditBox->nFirstVisibleChar], pEditBox->nLastVisibleChar - pEditBox->nFirstVisibleChar + 1);
        const int nLength = sub_00526800(wszText);
        if (pEditBox->dwEditBoxFlags & 1)
        {
            char szStar[] = "*";
            UnicodeChar wszStar[2];
            sub_00526F20_ToUnicode(wszStar, szStar, 2);
            if (nLength > 0)
            {
                for (int i = 0; i < nLength; ++i)
                {
                    wszText[i] = wszStar[0];
                }
            }
        }

        if (sub_004FDC70_HasSelection(pEditBox))
        {
            const unsigned char nShade = D2Win_10034_MixRGB(0x40, 0x40, 0x40);
            UnicodeChar wszHead[256];
            UnicodeChar wszSelected[256];
            UnicodeChar wszTail[256];
            const int nStart = EDITBOX_MAX(0, EDITBOX_MIN(pEditBox->nSelectionStart, pEditBox->nSelectionEnd) - pEditBox->nFirstVisibleChar);
            const int nCount = EDITBOX_MAX(0, EDITBOX_MAX(pEditBox->nSelectionStart, pEditBox->nSelectionEnd) - pEditBox->nFirstVisibleChar - nStart);
            sub_00526790(wszHead, wszText, nStart);
            sub_00526790(wszSelected, &wszText[nStart], nCount);
            sub_005267E0(wszTail, &wszText[nStart + nCount]);
            int nWidth1;
            int nWidth2;
            int nHeight;
            D2Win_10131_GetTextDimensions(wszHead, &nWidth1, &nHeight);
            D2Win_10131_GetTextDimensions(wszSelected, &nWidth2, &nHeight);
            nWidth1 += nX;
            const int nTailX = nWidth1 + nWidth2;
            sub_00502320(wszHead, nX, nY, pEditBox->nTextColor, 0);
            D2Win_10133(wszSelected, nWidth1, nY, nShade, 5, pEditBox->nTextColor);
            sub_00502320(wszTail, nTailX, nY, pEditBox->nTextColor, 0);
        }
        else
        {
            sub_00502320(wszText, nX, nY, pEditBox->nTextColor, 0);
        }

        if (sub_004F9200() == (int)pEditBox && GetTickCount() / 250 & 1)
        {
            char szCaret[] = "_";
            UnicodeChar wszCaret[2];
            sub_00526F20_ToUnicode(wszCaret, szCaret, 2);
            const int nCaretOffset = pEditBox->nCaretPosition - pEditBox->nFirstVisibleChar;
            if (nCaretOffset)
            {
                nX += D2Win_10122(wszText, nCaretOffset);
            }
            sub_00502320(wszCaret, nX, nY, pEditBox->nTextColor, 0);
        }
    }

    return 1;
}
